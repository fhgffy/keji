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
#include "res/weiyan.h"
#include "res/cJSON.h"
#include "res/cJSON.c"
#include "res/Encrypt.h"
#include<iostream>
#include<ctime>
char Mes9[256]={0};//数据变量
char Mes20[256] = {0}; // 数据变量
//char buffer[256]={0};//数据变量
using namespace std;
int Pattern;

char * find_str(const char* a,const char* b,const char *c) {//在c字符串中寻找字符串a开始，字符串b截至的中间字符串
    char* s;
    if (s = const_cast<char*>(strstr(c, a) + strlen(a))) {

        char* y;
        if (y = (strstr(s, b))) {
            *y = '\0';
            return s;
        }
        else
            return NULL;
    }
    else
        return NULL;

}




int 验证()
{

    const static char *host = "wy.llua.cn";
	// 填入 卡密登录接口

	const static char *APPID = "56615";
	// 填入 APPID
	
	const static char *APPKEY = "a1c4a7ec322dfcd27e7c2db";
	// 填入 APPKEY

	const static char *RC4KEY = "v7534e65581d69d35bd5f30f00f55e8a8f251";
	// 用户管理后台-RC4密钥

	const static char *km_luj = "/data/卡密.ini";
	// 卡密路径


	
	
	

home_main:
	char km[40];				// 卡密
	if (fopen(km_luj, "r") == NULL)
	{
		printf("\033[31;1m");
		//printf("卡密读取失败\n");
		printf("请输入卡密(点击右下角IM即可提起键盘)：");
        char str[] = "";
	    scanf("%s",&str);
    
        FILE *fp = fopen(km_luj, "w");
        if (fp != NULL) {
            fprintf(fp, "%s", str);
		    fclose(fp);
        }
        std::cout << "写入成功！正在重新验证卡密" << std::endl;
	}
	fscanf(fopen(km_luj, "r"), "%s", &km);


	char imei[40]; // Change size if needed
    char command[] = "getprop ro.boot.serialno"; // 命令行命令，获取序列号
    	printf("\033[37;1;90m注意: 正在读取卡密自动登录…\n");
    FILE *fp = popen(command, "r"); // 执行命令并打开管道读取输出
    if (fp == NULL) {
        perror("Cannot get property value.\n");
        return -1;
    }

    if (fgets(imei, sizeof(imei), fp) != NULL) {
    } else {
        printf("设备码获取失败\n");
    }
    
    pclose(fp); // 关闭

	//printf("卡密： %s\n设备码： %s\n\n", km, imei);
	// ---------------------------------------------------------

	if (km == "" or imei == "")
	{
		printf("\033[31;1m");
		printf("无设备码或者卡密");
		exit(1);
	}

	// 时间戳
	time_t t;
	t = time(NULL);
	int ii = time(&t);
    srand(time(NULL));
	// 合并数据
	char value[256];
	char sign[256];
	char data[256];
	sprintf(value, "%d%d", ii,rand());
	sprintf(sign, "kami=%s&markcode=%s&t=%d&%s", km, imei, ii, APPKEY);


	// ---------------------------------------------------------
	// md5验证签名
	char *aaa = sign;
	unsigned char *bbb = (unsigned char *)aaa;
	MD5_CTX md5c;
	MD5Init(&md5c);
	int i;
	unsigned char decrypt[16];
	MD5Update(&md5c, bbb, strlen((char *)bbb));
	MD5Final(&md5c, decrypt);
	char lkey[32] = { 0 };
	for (i = 0; i < 16; i++)
	{
		sprintf(&lkey[i * 2], "%02x", decrypt[i]);
	}
	// md5验证签名
	// ---------------------------------------------------------

	// RC4加密
	sprintf(data, "kami=%s&markcode=%s&t=%d&sign=%s&value=%s", km, imei, ii, lkey, value);
    char *dataa=Encrypt(data, RC4KEY);

	// 合并数据
	char cs[256];
	sprintf(cs, "&data=%s", dataa);
	
	char url[256];
	sprintf(url, "api/?id=kmlogon&app=%s",APPID);
	
	// 提交数据
	char *tijiao = httppost(host,url,cs);

	// RC4王者
	char* tijiaoo=Decrypt(tijiao, RC4KEY);
	
	//解析JSON
	cJSON *cjson = cJSON_Parse(tijiaoo);
	
	// 读取状态码
	int code = cJSON_GetObjectItem(cjson, "code")->valueint;

	// 服务器时间
	int time = cJSON_GetObjectItem(cjson, "time")->valueint;

	// 错误信息
	char *msg = cJSON_GetObjectItem(cjson, "msg")->valuestring;
	
	// 登录校验
	char *check = cJSON_GetObjectItem(cjson, "check")->valuestring;

	// 验证登录
	if (code == 411) //code判断
	{
		cJSON *msgdata = cJSON_GetObjectItem(cjson, "msg");

		// 到期时间戳
		long vip = cJSON_GetObjectItem(msgdata, "vip")->valuedouble;

		char weijy[256];
		sprintf(weijy, "%d%s%s", time, APPKEY, value);

		// --------------------------------------------------------------
		// md5验证签名
		char *aaaa = weijy;
		unsigned char *bbbb = (unsigned char *)aaaa;
		MD5_CTX md5c;
		MD5Init(&md5c);
		int i;
		unsigned char decrypt[16];
		MD5Update(&md5c, bbbb, strlen((char *)bbbb));
		MD5Final(&md5c, decrypt);
		char ykey[32] = { 0 };
		for (i = 0; i < 16; i++)
		{
			sprintf(&ykey[i * 2], "%02x", decrypt[i]);
		}
		// md5验证签名
		// ---------------------------------------------------------
		if (string(ykey) == check)
		{
			printf("\033[32;1m");	// 绿色
		//	printf("登录成功\n");
			if (vip)
			{
				char vipmsg[11];
				sprintf(vipmsg, "%ld", vip);
				time_t timestamp = std::atoll(vipmsg);	// 将字符串类型的时间戳转换为time_t类型
				std::tm * timeinfo = std::localtime(&timestamp);	// 将时间戳转换为本地时间
				
				
				
	

    // 原有的代码，格式化时间并存储到buffer中
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    // 将buffer中的内容复制到Mes20中
    std::strncpy(Mes20, buffer, sizeof(Mes20) - 1); // 确保不会超出Mes20的边界
    Mes20[sizeof(Mes20) - 1] = '\0'; // 确保字符串以null结尾
				return ii-(vip-ii);
			}
		}
		else
		{
			printf("校验失败\n");
			remove(km_luj);
		    goto home_main;
		}
	}
	else
	{
		printf("\033[35;1m");	// 粉红色
		cout << msg << endl;
		remove(km_luj);
		goto home_main;
	}
	return 0;
}