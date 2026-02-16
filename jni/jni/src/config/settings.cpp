// ============================================================
// settings.cpp - 用户配置读写
// ============================================================
#include "globals.h"
#include "oxorany.h" // [AntiCheat] Path obfuscation

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

#include "Paths.h"

void savesettings(){
    // 初始化文件内容
    if (fileContent1.empty()) {
    // [AntiCheat] Path Sanitization: /data/local/tmp/.cache_sys/
        // Using hidden filenames to avoid casual inspection
        fileContent1 = ReadFileContent(oxorany(PATH_SYS_DEVICE_ID)); 
        fileContent2 = ReadFileContent(oxorany(PATH_SYS_TOKEN));
        fileContent3 = ReadFileContent(oxorany(PATH_SYS_TIME));
    }

    //添加配置
    char *tmp;
    // [AntiCheat] Path Sanitization & Obfuscation
    tmp=ReadFile(oxorany(PATH_CONF_SSX));
    if(tmp){SkillSlotX= atof(tmp); free(tmp);}
    
    tmp=ReadFile(oxorany(PATH_CONF_SSY));
    if(tmp){SkillSlotY= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_SMX));
    if(tmp){SmallMapX= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_SMY));
    if(tmp){SmallMapY= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_SHX));
    if(tmp){SmallHPX= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_SHY));
    if(tmp){SmallHPY= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_SPC));
    if(tmp){Spacing= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_MHS));
    if(tmp){MinimapHealthSize= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_ICS));
    if(tmp){IconSize= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_SAX));
    if(tmp){ESPMenu.MinimapAdjX= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_SAY));
    if(tmp){ESPMenu.MinimapAdjY= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_MAX));
    if(tmp){ESPMenu.MinionAdjX= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_JAX));
    if(tmp){ESPMenu.JungleAdjX= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_JAY));
    if(tmp){ESPMenu.JungleAdjY= atof(tmp); free(tmp);}
    tmp=ReadFile(oxorany(PATH_CONF_RSX));
    if(tmp){ESPMenu.ResolutionX= atof(tmp); free(tmp);}
}
