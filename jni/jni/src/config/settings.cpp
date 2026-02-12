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
    char *ndhdh10=读取文件("/storage/emulated/0/Best/技能栏左右1");
    if(ndhdh10){jinenglanzX= atof(ndhdh10);}

    char *ndhdh11=读取文件("/storage/emulated/0/Best/技能栏上下1");
    if(ndhdh11){jinenglanzY= atof(ndhdh11);}
    char *ndhdh=读取文件("/storage/emulated/0/Best/小x1");
    if(ndhdh){SmallMapX= atof(ndhdh);}
    char *ndhdh2=读取文件("/storage/emulated/0/Best/小y1");
    if(ndhdh2){SmallMapY= atof(ndhdh2);}
    char *ndhdh3=读取文件("/storage/emulated/0/Best/大x1");
    if(ndhdh3){SmallHPX= atof(ndhdh3);}
    char *ndhdh5=读取文件("/storage/emulated/0/Best/大y1");
    if(ndhdh5){SmallHPY= atof(ndhdh5);}
    char *ndhdh991=读取文件("/storage/emulated/0/Best/头像间隔");
    if(ndhdh991){jiange= atof(ndhdh991);}
    char *ndhdh992=读取文件("/storage/emulated/0/Best/血量大小");
    if(ndhdh992){xiaodituxue= atof(ndhdh992);}
    char *ndhdh993=读取文件("/storage/emulated/0/Best/头像大小");
    if(ndhdh993){touxiangdaxiao= atof(ndhdh993);}
    char *ndhdh6=读取文件("/storage/emulated/0/Best/共享左右调整");
    if(ndhdh6){ESPMenu.小地图左右调整= atof(ndhdh6);}
    char *ndhdh7=读取文件("/storage/emulated/0/Best/共享上下调整");
    if(ndhdh7){ESPMenu.小地图上下调整= atof(ndhdh7);}
    char *ndhdh8=读取文件("/storage/emulated/0/Best/共享兵线左右调整");
    if(ndhdh8){ESPMenu.兵线左右调整= atof(ndhdh8);}
    char *ndhdh91=读取文件("/storage/emulated/0/Best/共享野怪左右调整");
    if(ndhdh91){ESPMenu.野怪左右调整= atof(ndhdh91);}
    char *ndhdh101=读取文件("/storage/emulated/0/Best/共享野怪上下调整");
    if(ndhdh101){ESPMenu.野怪上下调整= atof(ndhdh101);}
    char *ndhdh111=读取文件("/storage/emulated/0/Best/共享分辨率x调整");
    if(ndhdh111){ESPMenu.分辨率X= atof(ndhdh111);}
}
