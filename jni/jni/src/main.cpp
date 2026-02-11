//微验网络验证//
//如果是AIDE编译jni，请将原main.cpp删除，将此注入好的文件改成main.cpp

// 电报@aadaili
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <iostream>
#include <fstream>
#include "res/weiyan.h"
#include "res/cJSON.h"
#include "res/cJSON.c"
#include "res/Encrypt.h"
#include<iostream>
#include<ctime>
using namespace std;

//微验网络验证//
//如果是AIDE编译jni，请将原main.cpp删除，将此注入好的文件改成main.cpp
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <iostream>
#include <fstream>
#include<iostream>
#include<ctime>
#include <main.h>
//由Tomatosauce移植
//由Tomatosauce移植
//由Tomatosauce移植	

int main(){
    /*const static char *_wyHost = "wy.llua.cn";
	const static char *_wyAppid = "56615";	
	const static char *_wyAppkey = "a1c4a7ec322dfcd27e7c2db";
	const static char *_wyRc4key = "v7534e65581d69d35bd5f30f00f55e8a8f251";
	// 以上信息勿动
	
	const static char *_kmPath = "/sdcard/km";
	// 卡密路径

	const static char *_imeiPath = "/sdcard/imei";
	// 机器码路径
	
	const static bool _ggSwitch = false;
	// 公告开关

	printf("\033[35;1m");		// 粉红色
	printf("欢迎使用Best算法解密内核\n");
	printf("\033[32;1m");		// 绿色
	printf("\n官方更新频道 @BingYiBest666\n\n");
	printf("\033[33;1m");		// 黄色

	if (_ggSwitch){
	    char _ggUrl[1024];
	    sprintf(_ggUrl, "app=%s",_wyAppid);
    	char *_ggData = httppost(_wyHost,"api/?id=notice",_ggUrl);
    	char* _deggData=Decrypt(_ggData, _wyRc4key);
    	cJSON *_ggJson = cJSON_Parse(_deggData);
    	int _ggCode = cJSON_GetObjectItem(_ggJson, "code")->valueint;
    	if (_ggCode == 200){
    		cJSON *_ggMsg = cJSON_GetObjectItem(_ggJson, "msg");
            char *_appgg = cJSON_GetObjectItem(_ggMsg, "app_gg")->valuestring;
    	    printf("\n\n公告:%s\n\n",_appgg);
    	}
	}
	
	home_main:
	char _Kami[40];
	if (fopen(_kmPath, "r") == NULL)
	{
		printf("\033[31;1m");
		printf("请输入卡密:");
        char _inputKm[] = "";
	    scanf("%s",&_inputKm);
        FILE *fp = fopen(_kmPath, "w");
        if (fp != NULL) {
            fprintf(fp, "%s", _inputKm);
		    fclose(fp);
        }
        std::cout << "写入成功！正在重新验证卡密" << std::endl;
	}
	fscanf(fopen(_kmPath, "r"), "%s", &_Kami);
	char _Imei[40];
	if (fopen(_imeiPath, "r") == NULL)
	{
		printf("\033[31;1m");
		printf("设备码获取失败\n");
		srand(time(NULL));
        char* _Str = (char*)malloc((20 + 1) * sizeof(char));
        for (int i = 0; i < 20; i++) {
            int _randomNum = rand() % 26;
            _Str[i] = 'a' + _randomNum;
        }
        _Str[20] = '\0';
    
        FILE *fp = fopen(_imeiPath, "w");
        if (fp == NULL) {
            printf("文件创建失败");
            return 0;
        }
        fprintf(fp, "%s", _Str);
        fclose(fp);
        std::cout << "设备码已重新获取！正在重新验证卡密" << std::endl;
	}
	fscanf(fopen(_imeiPath, "r"), "%s", &_Imei);
	printf("卡密： %s\n设备码： %s\n\n", _Kami, _Imei);
	if (_Kami == "" or _Imei == "")
	{
		printf("\033[31;1m");
		printf("无设备码或者卡密");
		return 0;
	}
	time_t _Timet = time(NULL);
	int _Time = time(&_Timet);
    srand(time(NULL));
	char _Value[1024];
	char _Sign[1024];
	char _Data[1024];
	sprintf(_Value, "%d%d", _Time,rand());
	sprintf(_Sign, "kami=%s&markcode=%s&t=%d&%s", _Kami, _Imei, _Time, _wyAppkey);
	unsigned char *_SignData = (unsigned char *)_Sign;
	MD5_CTX md5c;
	MD5Init(&md5c);
	unsigned char _Decrypt[16];
	MD5Update(&md5c, _SignData, strlen((char *)_SignData));
	MD5Final(&md5c, _Decrypt);
	char _SignMd5[33] = { 0 };
	for (int i = 0; i < 16; i++)
	{
		sprintf(&_SignMd5[i * 2], "%02x", _Decrypt[i]);
	}
	sprintf(_Data, "kami=%s&markcode=%s&t=%d&sign=%s&value=%s", _Kami, _Imei, _Time, _SignMd5, _Value);
    char *_enData=Encrypt(_Data, _wyRc4key);
	char _deData[1024];
	sprintf(_deData, "&data=%s", _enData);
	char _deUrl[1024];
	sprintf(_deUrl, "api/?id=kmlogin&app=%s",_wyAppid);
	char *_loginData = httppost(_wyHost,_deUrl,_deData);
	char* _deloginData=Decrypt(_loginData, _wyRc4key);
	cJSON *_loginJson = cJSON_Parse(_deloginData);
	int _loginCode = cJSON_GetObjectItem(_loginJson, "r856e1732df7fa7d779edc43e71dc82c6")->valueint;
	int _loginTime = cJSON_GetObjectItem(_loginJson, "xb57f5c608284e1db7bdcd28d217773c4")->valueint;
	char *_loginMsg = cJSON_GetObjectItem(_loginJson, "rd4f31fd4fa1fcf69fa3b4ab59531f8d8")->valuestring;
	char *_loginCheck = cJSON_GetObjectItem(_loginJson, "fb94908a199fabfc650170d999276c486")->valuestring;
	if (_loginCode == 411)
	{
		cJSON *_loginMsgs = cJSON_GetObjectItem(_loginJson, "rd4f31fd4fa1fcf69fa3b4ab59531f8d8");
	    char *_checkCode = cJSON_GetObjectItem(_loginMsgs, "w06b1658c3bb836e01dcfcfaa9eb8b680")->valuestring;
		long _loginVip = cJSON_GetObjectItem(_loginMsgs, "cde4a376cfaf2766fc3e1b7c4adf8a68c")->valuedouble;
		long _loginId = cJSON_GetObjectItem(_loginMsgs, "w598e7a1e74c1c7ea45df7d46173ce61d")->valuedouble;
		char _deCheck[1024];
		sprintf(_deCheck, "%d%s%s",_loginTime,_wyAppkey,_Value);
		unsigned char *_deCheckData = (unsigned char *)_deCheck;
		MD5_CTX md5c;
		MD5Init(&md5c);
		unsigned char _Decrypt[16];
		MD5Update(&md5c, _deCheckData, strlen((char *)_deCheckData));
		MD5Final(&md5c, _Decrypt);
		char _checkMd5[33] = { 0 };
		for (int i = 0; i < 16; i++)
		{
			sprintf(&_checkMd5[i * 2], "%02x", _Decrypt[i]);
		}
		if ((string)_checkCode != "e3662c051a7eea3b64be417b5b850704"){
		    return 0;
		}
		if ((string)_checkMd5 == _loginCheck)
		{
			printf("\033[32;1m");	// 绿色
			printf("登录成功\n");
			if (_loginVip)
			{
				char _vipTime[11];
				sprintf(_vipTime, "%ld", _loginVip);
				time_t _timeStamp = std::atoll(_vipTime);
				std::tm * _timeInfo = std::localtime(&_timeStamp);
				char _buffer[80];
				std::strftime(_buffer, sizeof(_buffer), "%Y-%m-%d %H:%M:%S", _timeInfo);
				std::cout << "到期时间：" << _buffer << std::endl;
				//到期自动退出
				signal(SIGALRM, _exit); 
                alarm(_loginVip-_Time); 
			}
		}
		else
		{
			printf("校验失败\n");
			remove(_kmPath);
		    goto home_main;
		    return 0;
		}
	}
	else
	{
		printf("\033[35;1m");	// 粉红色
		cout << _loginMsg << endl;
		remove(_kmPath);
		goto home_main;
		return 0;
	}*/






 system("rm -r /data/data/com.tencent.tmgp.sgame/files/ano_tmp/*  >/dev/null 2>&1");


    
    screen_config();
    init_screen_x = screen_x + screen_y;
    init_screen_y = screen_y + screen_x;
    if(!init_egl(init_screen_x,init_screen_y)){
        exit(0);
    }
    ImGui_init();
    Init_touch_config();
    /*for (;;) {
        drawBegin();
        tick();
        drawEnd();
    }*/
    while (1)
    {     
    
        tick();
    }
    shutdown();
    return 0;
}

//由Tomatosauce移植
//由Tomatosauce移植
//由Tomatosauce移植	
