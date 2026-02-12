// ============================================================
// driver.cpp - 内核驱动实例 + 辅助函数
// ============================================================
#include "driver.h"

c_driver *Driver = new c_driver();

uintptr_t getbss(int pid, const char* name) {
    FILE* fp = NULL;
    int cnt = 0;
    long start = 0;
    char tmp[256];
    char fname[128];
    snprintf(fname, sizeof(fname), "/proc/%d/maps", pid);
    fp = fopen(fname, "r");
    if (fp == NULL) { perror("找不到游戏进程"); return 0; }
    while (fgets(tmp, sizeof(tmp), fp)) {
        if (cnt == 1) {
            if (strstr(tmp, "[anon:.bss]") != NULL) {
                sscanf(tmp, "%lx-%*lx", &start);
                break;
            } else { cnt = 0; }
        }
        if (strstr(tmp, name) != NULL) { cnt = 1; }
    }
    fclose(fp);
    return start;
}

uintptr_t 获取基址头(int pid, char* name) {
    char*phgsr;
    char jjjj_N[64];
    long startaddr = 0;
    char path[256],line[1024];
    bool bssOF = false,LastIsSo = false;
    strcpy(jjjj_N,name);
    phgsr = strtok(jjjj_N,":");
    name = phgsr;
    phgsr = strtok(NULL,":");
    if(phgsr) {
        if(strcmp(phgsr,"bss")==0) { bssOF = true; }
    }
    sprintf(path,"/proc/%d/maps",pid);
    FILE*p = fopen(path,"r");
    if(p) {
        while(fgets(line,sizeof(line),p)) {
            if(LastIsSo) {
                if(strstr(line,"[anon:.bss]")!=NULL) {
                    sscanf(line,"%lx-%*lx",&startaddr);
                    break;
                } else { LastIsSo = false; }
            }
            if(strstr(line,name)!=NULL) {
                if(!bssOF) {
                    sscanf(line,"%lx-%*lx",&startaddr);
                    break;
                } else { LastIsSo = true; }
            }
        }
        fclose(p);
    }
    return startaddr;
}
