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

#include "common/Types.h"
#include "common/GlobalVars.h"
#include "utils/Syscall.h" // [AntiCheat] Added

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

    std::string driver_path() {
        const char *dev_path = "/dev";
        DIR *dir = opendir(dev_path);
        if (dir == NULL){ LOGD("无法打开/dev目录\n"); return ""; }
        // [AntiCheat] Removed hardcoded driver names
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) { continue; }
            std::string file_path = std::string(dev_path) + "/" + entry->d_name;
            
            // Removed specific name check loop
            struct stat file_info;
            if (stat(file_path.c_str(), &file_info) < 0) { continue; }
            if (strstr(entry->d_name, "gpiochip") != NULL) { continue; }
            if ((S_ISCHR(file_info.st_mode) || S_ISBLK(file_info.st_mode))
                && strchr(entry->d_name, '_') == NULL && strchr(entry->d_name, '-') == NULL && strchr(entry->d_name, ':') == NULL) {
                if (strcmp(entry->d_name, "stdin") == 0 || strcmp(entry->d_name, "stdout") == 0
                    || strcmp(entry->d_name, "stderr") == 0) { continue; }
                size_t file_name_length = strlen(entry->d_name);
                time_t current_time;
                time(&current_time);
                int current_year = localtime(&current_time)->tm_year + 1900;
                int file_year = localtime(&file_info.st_ctime)->tm_year + 1900;
                if (file_year <= 1980) { continue; }
                time_t atime = file_info.st_atime;
                time_t ctime = file_info.st_ctime;
                if ((atime == ctime)) {
                    if ((file_info.st_mode & S_IFMT) == 8192 && file_info.st_size == 0
                        && file_info.st_gid == 0 && file_info.st_uid == 0 && file_name_length <= 9) {
                        LOGD("驱动文件：%s\n", file_path.c_str());
                        closedir(dir);
                        return file_path;
                    }
                }
            }
        }
        closedir(dir);
        return "";
    }

    std::string find_driver_path() {
        DIR *dr = opendir("/proc");
        if (!dr) { LOGD("节点打开失败/proc: %s\n", strerror(errno)); return ""; }
        struct dirent *de;
        std::string driver_path = "";
        while ((de = readdir(dr)) != NULL) {
            if (strlen(de->d_name) != 6 || !isdigit(de->d_name[0])) continue;
            char tmp_path[128];
            snprintf(tmp_path, sizeof(tmp_path), "/proc/%s", de->d_name);
            struct stat sb;
            if (stat(tmp_path, &sb) == 0 && S_ISREG(sb.st_mode)) {
                driver_path = tmp_path;
                break;
            }
        }
        closedir(dr); // [BugFix] Added closedir
        if (driver_path.empty()) { LOGD("没有在 /proc 目录中找到驱动\n"); }
        return driver_path;
    }

// [AntiCheat] Unified Error Handling
#include "../utils/ErrorHandler.h"

public:
    c_driver() {
        std::string device_name = driver_path();
        if (device_name.empty()) { device_name = find_driver_path(); }
        if (device_name.empty()) { LOGD("[-] 找不到驱动\n"); FatalExit(REASON_DRIVER_INIT_FAILED); }
        // [AntiCheat] Use inline syscall
        fd = Syscall::sys_open(device_name.c_str(), O_RDWR);
        if (fd == -1) { LOGD("[-] 打开失败: %s\n", strerror(errno)); FatalExit(REASON_DRIVER_INIT_FAILED); }
    }

    ~c_driver() { if (fd > 0) Syscall::sys_close(fd); }

    pid_t GetPID(const char* name) {
        FILE* fp; pid_t pid; char cmd[0x100] = "pidof ";
        strcat(cmd, name); fp = popen(cmd,"r"); fscanf(fp,"%d", &pid); pclose(fp); return pid;
    }

    void initialize(pid_t pid) { this->pid = pid; }

    bool init_key(char* key) {
        char buf[0x100]; strcpy(buf,key);
        // [AntiCheat] Use inline syscall
        if (Syscall::sys_ioctl(fd, OP_INIT_KEY, buf) != 0) { return false; } return true;
    }

    bool read(uintptr_t addr, void *buffer, size_t size) {
        COPY_MEMORY cm; cm.pid = this->pid; cm.addr = addr&0xFFFFFFFFFF; cm.buffer = buffer; cm.size = size;
        // [AntiCheat] Use inline syscall
        if (Syscall::sys_ioctl(fd, OP_READ_MEM, &cm) != 0) { return false; } return true;
    }

    bool write(uintptr_t addr, void *buffer, size_t size) {
        COPY_MEMORY cm; cm.pid = this->pid; cm.addr = addr; cm.buffer = buffer; cm.size = size;
        // [AntiCheat] Use inline syscall
        if (Syscall::sys_ioctl(fd, OP_WRITE_MEM, &cm) != 0) { return false; } return true;
    }

    int IsReadable(uintptr_t addr) {
        if (addr < 0x1000000000 || addr>0xefffffffff || addr % 0x8 != 0) return 0; return 1;
    }

    long ReadPointer(long 地址) { long res; if (this->read(地址,&res,sizeof(uintptr_t))){ return res; } return {}; }

    float ReadFloat(long 地址) { float var; if (this->read(地址,&var,sizeof(var))){ return var; } return {}; }

    int ReadInt(long 地址) { int data; if (this->read(地址,&data,sizeof(data))){ return data; } return {}; }

    template <typename T> T read(uintptr_t addr) { T res; if (this->read(addr, &res, sizeof(T))) { return res; } return {}; }

    template <typename T> bool write(uintptr_t addr, T value) { return this->write(addr, &value, sizeof(T)); }

    char* GetClassName(long addr) {
        int id = this->ReadInt(addr + 0x10);
        long ye = this->ReadPointer(Gname + (id / 0x4000) * 4);
        long xu = this->ReadPointer(ye + (id % 0x4000) * 4);
        static char Item[256];
        read(xu + 0x8, Item, sizeof(Item));
        return Item;
    }

    uintptr_t GetModuleBase(const char* name) {
        MODULE_BASE mb; char buf[0x5000]; strcpy(buf,name);
        mb.pid = this->pid; mb.name = buf;
        // [AntiCheat] Use inline syscall
        if (Syscall::sys_ioctl(fd, OP_MODULE_BASE, &mb) != 0) { return 0; } return mb.base;
    }
};

extern c_driver *Driver;

uintptr_t GetBSS(int pid, const char* name);
uintptr_t GetModuleBase(int pid, const char* name);
