// ============================================================
// settings.cpp - 用户配置读写
// ============================================================
#include "globals.h"

static std::string ReadFileContent(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::in);
    if (!file.is_open()) {
        return "无法打开文件";
    }
    std::string content((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void savesettings(){
    // 初始化文件内容
    if (fileContent1.empty()) {
        fileContent1 = ReadFileContent("/sdcard/Best/王者小狐狸设备码.c");
        fileContent2 = ReadFileContent("/sdcard/Best/王者小狐狸卡密.c");
        fileContent3 = ReadFileContent("/sdcard/Best/王者小狐狸卡密时间.c");
    }

    //添加配置
    char *tmp;
    tmp=读取文件("/storage/emulated/0/Best/技能栏左右1");
    if(tmp){jinenglanzX= atof(tmp); free(tmp);}

    tmp=读取文件("/storage/emulated/0/Best/技能栏上下1");
    if(tmp){jinenglanzY= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/小x1");
    if(tmp){SmallMapX= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/小y1");
    if(tmp){SmallMapY= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/大x1");
    if(tmp){SmallHPX= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/大y1");
    if(tmp){SmallHPY= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/头像间隔");
    if(tmp){jiange= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/血量大小");
    if(tmp){xiaodituxue= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/头像大小");
    if(tmp){touxiangdaxiao= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/共享左右调整");
    if(tmp){ESPMenu.小地图左右调整= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/共享上下调整");
    if(tmp){ESPMenu.小地图上下调整= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/共享兵线左右调整");
    if(tmp){ESPMenu.兵线左右调整= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/共享野怪左右调整");
    if(tmp){ESPMenu.野怪左右调整= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/共享野怪上下调整");
    if(tmp){ESPMenu.野怪上下调整= atof(tmp); free(tmp);}
    tmp=读取文件("/storage/emulated/0/Best/共享分辨率x调整");
    if(tmp){ESPMenu.分辨率X= atof(tmp); free(tmp);}
}
