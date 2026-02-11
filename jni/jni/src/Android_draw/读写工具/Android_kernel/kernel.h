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
#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <map>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <unistd.h>
#include <chrono>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/kdev_t.h>
#include <sys/sysmacros.h>
#include <iostream>
#define FileCount 4
static const char *files[FileCount] = { "wanbai", "CheckMe", "Ckanri", "lanran" };


class CDriver {
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
		OP_HIDE_PROCESS = 0x804,
	};
	
		int symbol_file(const char *filename){
	int length = strlen(filename);
		for (int i = 0; i < length; i++){
		if (isupper(filename[i])){
				has_upper = 1;
			}
			else if (islower(filename[i])){
				has_lower = 1;
			}
			else if (ispunct(filename[i])){
				has_symbol = 1;
			}
			else if (isdigit(filename[i])){
				has_digit = 1;
			}
		}

		return has_upper && has_lower && !has_symbol && !has_digit;
	}
	bool StrAlpha(const char *str){
	       for(int i = 0;i<6;i++){
	           if(!isalpha(str[i])){
	             return false;
	           }
	       }
	       return true;
	}
	int OpenFd(){
        DIR * dir;
    	struct dirent * ptr;
    	struct stat info;
    	dir = opendir("/proc");
    	ssize_t len;
    	char path[256];
    	char buffer[256];
    	char fd_path[256];
    	char fd_buffer[256];
    	char dev_path[256];
        char data_path[128];
    	int ID;
    	int PPID;
    	auto start = std::chrono::high_resolution_clock::now();  // 获取起始时间
    	while((ptr = readdir(dir)) != NULL){
    	   if(ptr->d_type == DT_DIR){
    	     sprintf(buffer,"/proc/%d/exe",atoi(ptr->d_name));
    		 //printf("文件夹: %s\n  路径: %s",ptr->d_name,buffer);
    	     len = readlink(buffer, path, sizeof(path) - 1);
    	     if (len != -1)   path[len] = '\0';
    	     char* stres = strrchr(path,'(deleted)');
    	     if(stres != NULL){
    	       sscanf(path, "/data/%s", &data_path);
    	       if(StrAlpha(data_path)){
    		     sscanf(buffer,"/proc/%d/exe",&PPID);
    		     printf("[+] 软链: %s  PID: %d\n", path, PPID);
    		     for(int i = 3;i<5;i++){
    		         sprintf(fd_path,"/proc/%d/fd/%d",PPID,i);
    		         len = readlink(fd_path, fd_buffer, sizeof(fd_buffer) - 1);
    		         char* stress = strrchr(fd_buffer,'(deleted)');
    		         if(stress != NULL){
    		            int fd_file = open(fd_path, O_RDONLY);
    		            if (fd_file == -1) {
    		               perror("open");
    		               close(fd_file);
    		               return EXIT_FAILURE;
    		            }
    		            if (fstat(fd_file, &info) == -1) {
    		               perror("fstat");
    		               close(fd_file);
    		               return 0;
    		            }
    		            sscanf(fd_buffer,"%s (deleted)", dev_path);
    		            printf("[*] 设备路径: %s  设备 ID: %lu\n", dev_path, info.st_dev);
    		            printf("[*] 主设备号: %lu\n", major(info.st_rdev));
    		            printf("[*] 次设备号: %lu\n", minor(info.st_rdev));
    		            if(access(dev_path,F_OK) == 0){  //检查文件是否存在
    		               ID = open(dev_path,O_RDWR);
    		               if(ID != -1){
    		                 printf("[+] 驱动识别成功\n");
    		                 if(unlink(dev_path) == 0) {
    		                    printf("[+] 驱动守护中\n");
    		                    auto end = std::chrono::high_resolution_clock::now();  // 获取结束时间
    		                    float elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //获毫秒
    		                    printf("[+] 读取驱动用时: %.f ms\n", elapsed_ns);
    		                    return ID;
    		                    //return 0;
    		                 }
    		               }
    		            }  else { //驱动已经隐藏
    		               printf("[+] 驱动已隐藏创建驱动中\n");
    		               mode_t mode = S_IFCHR | 0666; // 创建一个命名管道，权限为读写
    		               dev_t dev = makedev(major(info.st_rdev), minor(info.st_rdev));
    		               if(mknod(dev_path, mode, dev) != -1){
    		                  printf("[+] mknod : %d 成功\n", major(info.st_rdev));
    		               }
    		               ID = open(dev_path,O_RDWR);
    		               if(ID != -1){
    		                  printf("[+] 驱动识别成功\n");
    		                  if(unlink(dev_path) != -1){
    		                    printf("[+] 驱动守护中\n");
    		                    auto end = std::chrono::high_resolution_clock::now();  // 获取结束时间
    		                    float elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //获毫秒
    		                    printf("[+] 读取驱动用时: %.f ms\n", elapsed_ns);
    		                    return ID;
    		                  }
    		               }
    		            }
    		            close(fd_file);
    		            break;
    		         }
    		     }
    		     break;
    		   }
    		 }
    	   }
    	}
    	closedir(dir);
    	printf("[+] 未识别到QX驱动程序\n");
    	return -1;
   }
  public:
	c_driver(){
		fd = OpenFd();
	}

	~CDriver() {
		//wont be called
		if (fd > 0)
			close(fd);
	}

	void initialize(pid_t pid) {
		this->pid = pid;
	}

	bool init_key(char* key) {
		char buf[0x100];
		strcpy(buf,key);
		if (ioctl(fd, OP_INIT_KEY, buf) != 0) {
			return false;
		}
		return true;
	}

	bool read(uintptr_t addr, void *buffer, size_t size) {
		COPY_MEMORY cm;

		cm.pid = this->pid;
		cm.addr = addr;
		cm.buffer = buffer;
		cm.size = size;

		if (ioctl(fd, OP_READ_MEM, &cm) != 0) {
			return false;
		}
		return true;
	}

	bool write(uintptr_t addr, void *buffer, size_t size) {
		COPY_MEMORY cm;

		cm.pid = this->pid;
		cm.addr = addr;
		cm.buffer = buffer;
		cm.size = size;

		if (ioctl(fd, OP_WRITE_MEM, &cm) != 0) {
			return false;
		}
		return true;
	}

	template <typename T>
	T read(uintptr_t addr) {
		T res;
		if (this->read(addr, &res, sizeof(T)))
			return res;
		return {};
	}

	template <typename T>
	bool write(uintptr_t addr,T value) {
		return this->write(addr, &value, sizeof(T));
	}
	
	template <class T>
    T write2(long int addr, T value) {
        char lj[64];
        long int handle;
        sprintf(lj, "/proc/%d/mem", pid);
        handle = open(lj, O_RDWR | O_SYNC);
        if (handle == -1) {
            perror("open");
        return 0;
        }

       if (pwrite64(handle, &value, sizeof(T), addr) != sizeof(T)) {
            perror("[-]写入内存区域失败");
            close(handle);
            return 0;
       }
       close(handle);
       return 0;
    }
	
	long 读取指针(long 地址){
        unsigned long var = 0;
        var = this->read<long>(地址);
        if (var > 0xffffffffff)
        var=var%0x10000000000;
        return (var);
    }

	
	uintptr_t get_module_base(char* name) {
		MODULE_BASE mb;
		char buf[0x100];
		strcpy(buf,name);
		mb.pid = this->pid;
		mb.name = buf;

		if (ioctl(fd, OP_MODULE_BASE, &mb) != 0) {
			return 0;
		}
		return mb.base;
	}
	
	void getUTF8(char * buf, unsigned long namepy) {
        unsigned short buf16[16] = { 0 };
        read(namepy, buf16, 28);
        unsigned short *pTempUTF16 = buf16;
        char *pTempUTF8 = buf;
        char *pUTF8End = pTempUTF8 + 32;
        while (pTempUTF16 < pTempUTF16 + 28) {
            if (*pTempUTF16 <= 0x007F && pTempUTF8 + 1 < pUTF8End) 
            {
                *pTempUTF8++ = (char) * pTempUTF16;
            } else if (*pTempUTF16 >= 0x0080 && *pTempUTF16 <= 0x07FF && pTempUTF8 + 2 < pUTF8End) {
                *pTempUTF8++ = (*pTempUTF16 >> 6) | 0xC0;
                *pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
            } else if (*pTempUTF16 >= 0x0800 && *pTempUTF16 <= 0xFFFF && pTempUTF8 + 3 < pUTF8End) {
                *pTempUTF8++ = (*pTempUTF16 >> 12) | 0xE0;
                *pTempUTF8++ = ((*pTempUTF16 >> 6) & 0x3F) | 0x80;
                *pTempUTF8++ = (*pTempUTF16 & 0x3F) | 0x80;
            } else {
                break;
            }
            pTempUTF16++;
        }
    }
    
    void hide_process() {
	    ioctl(fd, OP_HIDE_PROCESS);
	}
	
};

extern CDriver *driver;

