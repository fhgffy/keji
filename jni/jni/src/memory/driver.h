#pragma once

#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <time.h>
#include <map>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <chrono>
#include <sys/types.h>
#include <fcntl.h>
#include <linux/kdev_t.h>
#include <sys/sysmacros.h>
#include <iostream>

#include "globals.h"

class c_driver {
private:
    int has_upper = 0;
    int has_lower = 0;
    int has_symbol = 0;
    int has_digit = 0;
    int fd;
    pid_t pid;

    typedef struct _COPY_MEMORY {
        pid_t pid;
        uintptr_t addr;
        void* buffer;
        size_t size;
    } COPY_MEMORY, *PCOPY_MEMORY;

    typedef struct _MODULE_BASE {
        pid_t pid;
        char* name;
        uintptr_t base;
    } MODULE_BASE, *PMODULE_BASE;

    enum OPERATIONS {
        OP_INIT_KEY = 0x800,
        OP_READ_MEM = 0x801,
        OP_WRITE_MEM = 0x802,
        OP_MODULE_BASE = 0x803,
    };

    int symbol_file(const char *filename) {
        int length = strlen(filename);
        for (int i = 0; i < length; i++) {
            if (islower(filename[i])) { has_lower = 1; }
            else if (isupper(filename[i])) { has_upper = 1; }
            else if (ispunct(filename[i])) { has_symbol = 1; }
            else if (isdigit(filename[i])) { has_digit = 1; }
        }
        return has_lower && !has_upper && !has_symbol && !has_digit;
    }

    char *driver_path() {
        const char *dev_path = "/dev";
        DIR *dir = opendir(dev_path);
        if (dir == NULL){ printf("无法打开/dev目录\n"); return NULL; }
        char *files[] = { "wanbai", "CheckMe", "Ckanri", "lanran","video188"};
        struct dirent *entry;
        char *file_path = NULL;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) { continue; }
            size_t path_length = strlen(dev_path) + strlen(entry->d_name) + 2;
            file_path = (char *)malloc(path_length);
            snprintf(file_path, path_length, "%s/%s", dev_path, entry->d_name);
            for (int i = 0; i < 5; i++) {
                if (strcmp(entry->d_name, files[i]) == 0) {
                    printf("驱动文件：%s\n", file_path);
                    closedir(dir);
                    return file_path;
                }
            }
            struct stat file_info;
            if (stat(file_path, &file_info) < 0) { free(file_path); file_path = NULL; continue; }
            if (strstr(entry->d_name, "gpiochip") != NULL) { free(file_path); file_path = NULL; continue; }
            if ((S_ISCHR(file_info.st_mode) || S_ISBLK(file_info.st_mode))
                && strchr(entry->d_name, '_') == NULL && strchr(entry->d_name, '-') == NULL && strchr(entry->d_name, ':') == NULL) {
                if (strcmp(entry->d_name, "stdin") == 0 || strcmp(entry->d_name, "stdout") == 0
                    || strcmp(entry->d_name, "stderr") == 0) { free(file_path); file_path = NULL; continue; }
                size_t file_name_length = strlen(entry->d_name);
                time_t current_time;
                time(&current_time);
                int current_year = localtime(&current_time)->tm_year + 1900;
                int file_year = localtime(&file_info.st_ctime)->tm_year + 1900;
                if (file_year <= 1980) { free(file_path); file_path = NULL; continue; }
                time_t atime = file_info.st_atime;
                time_t ctime = file_info.st_ctime;
                if ((atime == ctime)) {
                    if ((file_info.st_mode & S_IFMT) == 8192 && file_info.st_size == 0
                        && file_info.st_gid == 0 && file_info.st_uid == 0 && file_name_length <= 9) {
                        printf("驱动文件：%s\n", file_path);
                        closedir(dir);
                        return file_path;
                    }
                }
            }
            free(file_path);
            file_path = NULL;
        }
        closedir(dir);
        return NULL;
    }

    char *find_driver_path() {
        DIR *dr = opendir("/proc");
        if (!dr) { perror("节点打开失败/proc"); return NULL; }
        struct dirent *de;
        char *driver_path = NULL;
        while ((de = readdir(dr)) != NULL) {
            if (strlen(de->d_name) != 6 || !isdigit(de->d_name[0])) continue;
            char tmp_path[128];
            snprintf(tmp_path, sizeof(tmp_path), "/proc/%s", de->d_name);
            struct stat sb;
            if (stat(tmp_path, &sb) == 0 && S_ISREG(sb.st_mode)) {
                driver_path = strdup(tmp_path);
                break;
            }
        }
        if (!driver_path) { printf("没有在 /proc 目录中找到驱动\n"); }
        return driver_path;
    }

public:
    c_driver() {
        char *device_name = driver_path();
        if (!device_name) { device_name = find_driver_path(); }
        if (!device_name) { fprintf(stderr, "[-] 找不到驱动\n"); exit(EXIT_FAILURE); }
        fd = open(device_name, O_RDWR);
        free(device_name);
        if (fd == -1) { perror("[-] 打开失败"); exit(EXIT_FAILURE); }
    }

    ~c_driver() { if (fd > 0) close(fd); }

    pid_t 获取进程ID(char* name) {
        FILE* fp; pid_t pid; char cmd[0x100] = "pidof ";
        strcat(cmd, name); fp = popen(cmd,"r"); fscanf(fp,"%d", &pid); pclose(fp); return pid;
    }

    void initialize(pid_t pid) { this->pid = pid; }

    bool init_key(char* key) {
        char buf[0x100]; strcpy(buf,key);
        if (ioctl(fd, OP_INIT_KEY, buf) != 0) { return false; } return true;
    }

    bool read(uintptr_t addr, void *buffer, size_t size) {
        COPY_MEMORY cm; cm.pid = this->pid; cm.addr = addr&0xFFFFFFFFFF; cm.buffer = buffer; cm.size = size;
        if (ioctl(fd, OP_READ_MEM, &cm) != 0) { return false; } return true;
    }

    bool write(uintptr_t addr, void *buffer, size_t size) {
        COPY_MEMORY cm; cm.pid = this->pid; cm.addr = addr; cm.buffer = buffer; cm.size = size;
        if (ioctl(fd, OP_WRITE_MEM, &cm) != 0) { return false; } return true;
    }

    int 是否可读(uintptr_t addr) {
        if (addr < 0x1000000000 || addr>0xefffffffff || addr % 0x8 != 0) return 0; return 1;
    }

    long 读取指针(long 地址) { long res; if (this->read(地址,&res,sizeof(uintptr_t))){ return res; } return {}; }

    float 读取浮点数(long 地址) { float var; if (this->read(地址,&var,sizeof(var))){ return var; } return {}; }

    int 读取整数(long 地址) { int data; if (this->read(地址,&data,sizeof(data))){ return data; } return {}; }

    template <typename T> T read(uintptr_t addr) { T res; if (this->read(addr, &res, sizeof(T))) { return res; } return {}; }

    template <typename T> bool write(uintptr_t addr, T value) { return this->write(addr, &value, sizeof(T)); }

    char* 获取类名(long addr) {
        int id = this->读取整数(addr + 0x10);
        long ye = this->读取指针(Gname + (id / 0x4000) * 4);
        long xu = this->读取指针(ye + (id % 0x4000) * 4);
        static char Item[256];
        read(xu + 0x8, Item, sizeof(Item));
        return Item;
    }

    uintptr_t 获取基址头(char* name) {
        MODULE_BASE mb; char buf[0x5000]; strcpy(buf,name);
        mb.pid = this->pid; mb.name = buf;
        if (ioctl(fd, OP_MODULE_BASE, &mb) != 0) { return 0; } return mb.base;
    }
};

extern c_driver *Driver;

uintptr_t getbss(int pid, const char* name);
uintptr_t 获取基址头(int pid, char* name);
