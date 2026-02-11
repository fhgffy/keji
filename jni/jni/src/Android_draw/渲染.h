#include <配置.h>
#include "结构体.h"
//#include "自瞄.h"
#include "封装绘图.h"
#include "offsets.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ctime>


int pid = 0;
uintptr_t 基址头;
uintptr_t 人物坐标;
char extra[32];
void threadFunction();
char imei[100] = "";//leixin666
int 人物=12, 坐标 =880;
int 自身视野=0;
int 视野 = 0;
/*===== 坐标解密功能 - 已注释 =====
bool 坐标解密1=false;
bool 坐标解密2=false;
bool 坐标解密3 = false;
bool 坐标解密4 = false;
*/
int 静态数据();
/*===== 坐标解密变量 - 已注释 =====
long cooroffest = 0;
long coorpage = 0;
*/
long 真实坐标, 坐标模块, 真实坐标第一层, 真实坐标第二层;
/*===== 坐标解密函数 getcoor() - 已注释 =====
long getcoor(long addr)
{
if(坐标解密1){

	long 人物坐标=Driver->读取整数(Driver->读取整数(Driver->读取整数(Driver->读取整数(addr + 0x240) + 0x10)) + 0x10);
    long encrypt = 人物坐标&(~(4096 - 1));
  //  ImGui::GetForegroundDrawList()->AddText(ImVec2(0, 1080-30), Paint_green, "      当前坐标未加密");

if (encrypt == 人物坐标)
    {
            if (encrypt != coorpage && encrypt != 0 && cooroffest == 0){
            for (int i = 1; i <= 4096 * 2000; i++){
            long start = encrypt - 4096 * i;
            //long pointerValue= Driver->读取指针(start+0x55B8);

           if (Driver->读取整数(start + 0xF688) == encrypt){
                     long coor = start + 0xF690;
                     cooroffest = Driver->读取整数(coor) - encrypt + Driver->读取整数(coor +0x8);
                    // coorpage = encrypt;
                     break;
            }

            if (Driver->读取整数(start + 0x55B8) == encrypt){
                     long coor = start + 0x55C0;
                     cooroffest = Driver->读取整数(coor) - encrypt + Driver->读取整数(coor +0x8);
                    // coorpage = encrypt;
                     break;
            }
       }
             coorpage=encrypt;
    }

}



    if (encrypt == coorpage)
    {
        人物坐标=人物坐标+cooroffest;
        ImGui::GetForegroundDrawList()->AddText(ImVec2(0, 1080-30), Paint_red, "      当前坐标已被加密(方案一)");
    }else{


 ImGui::GetForegroundDrawList()->AddText(ImVec2(0, 1080-30), Paint_green, "      当前坐标未加密(方案一)");

 }
   // printf("%p\n", (void*)(Driver->read<unsigned char>(人物坐标 + 0xD)));

    return 人物坐标;
	}
	return 人物坐标;
}
===== 坐标解密函数 getcoor() 结束 =====*/


void DrawInit(){
       int pid = Driver->获取进程ID("com.tencent.tmgp.sgame");
       
       Driver-> initialize(pid);
       if (pid == 0 || pid == -1) {
        puts("[+] 先打开游戏");
        exit(1);
         }
       lil2cpp_base = 获取基址头(pid,"libil2cpp.so:bss");
       lil2cpp_basebss = getbss(pid, "libil2cpp.so");
       libGame_basebss = getbss(pid, "libGameCore.so"); 
       yxpx = screen_x;
       yxpy = screen_y;
     
       
       静态数据();

       
       }



      
int 静态数据(){
  
    坐标模块 = Driver->read<uint64_t>(libGame_basebss + OFF_坐标模块);

    真实坐标 = Driver->read<uint64_t>(libGame_basebss + OFF_真实坐标);

    真实坐标第一层 = Driver->read<uint64_t>(真实坐标 + OFF_真实坐标_一层);
    真实坐标第二层 = Driver->read<uint64_t>(真实坐标第一层 + OFF_真实坐标_二层);
    
    return 0;
}




void DrawPlayer()
{



    int 本人X, 本人Y, 本人CD, 本人ID;
    yxpy = (float)yxpy;
    yxpx = (float)yxpx;
    int fx = 0;
    const float TXdx = yxpy * 0.017534f; //(头像)圈大小(22.5)半径
    const float soldiers_dx = yxpy * (double)0.001851851851851851; //(兵)大小(2.0f)半径
    const float CDjs_X = yxpx * 0.337250f; //绘制cd起
    const float CDjs_Y = yxpy * 0.006481f; //绘制cd起点Y(7)
    const float intervalcdX = yxpx * 0.025200f; //60(cd左右间隔)
    const float intervalcdY = yxpy * 0.032407f; //35(cd上下间隔)
    const float skills_dx = yxpy * (double)0.006481481481481481;
    const float skills_txt_dx = skills_dx * 4.0f;    //技能CD文字大小
    Wwra = yxpy / 10.2f * (1.574074075 + (jiange * 0.01));   // 间隔
    Wwr2 = 2400 / 2 / 11.2f * 1.574074075;




    //共享王者启动传输内容
    //共享绘制房间号imei手机标识符
    
    FILE* fpp = popen("getprop ro.serialno", "r");
    read_line_without_newline(fpp, imei, sizeof(imei));
    pclose(fpp);
    std::string 设备id = imei;
    std::string gameDataStr = "";
    std::string character = "";// "不能动";
    std::string creeps = "";
    std::string soldier = "";
    pxx = ESPMenu.分辨率X / 2;//2712和1220
    pyy = ESPMenu.分辨率Y / 2;
    WwrShare = pxx / 11.2f * 1.574074075;


 


    //矩阵数据
    long temp = Driver->读取指针(lil2cpp_basebss + OFF_矩阵基址);//0x74E30
    //printf("矩阵基址少一层%lx\n",temp);
    MatrixAddress = Driver->读取指针(Driver->读取指针(Driver->读取指针(temp + OFF_矩阵_一层) + OFF_矩阵_二层) + OFF_矩阵_三层) + OFF_矩阵_数据;
    // printf("矩阵基址%lx\n",MatrixAddress);
    isGames = Driver->读取浮点数(MatrixAddress);
    foeComp = isGames > 0 ? 2 : 1;

    rientation = foeComp == 1 ? 1 : -1;
 if (Driver->读取整数(libGame_basebss + OFF_游戏状态) != 0) {
    if (isGames > 0.0f) {

        rientation = 1;
        foeComp = 2;
    }
    else {

        rientation = -1;
        foeComp = 1;
    }



    //十二个英雄
    //共享绘制临时传输
    int heid;
    int hex, hey;
    int realhp;
    int herealx, herealy;
    int zyz, hcc;
    int sp, jn;
    int mytb;
    //共享绘制临时传输
    int 人物大招最大CD;

    for (int i = 0; i < 16; i++)
    {
        dataTable.Matrix[i] = Driver->读取浮点数(MatrixAddress + i * 4);
    }//矩阵

    long bingxiang1 = Driver->read<uint64_t>(坐标模块 + OFF_坐标模块_bx1);


    //人物数组
    long temp1 = Driver->读取指针(libGame_basebss + OFF_人物数组);
    long 啥 = temp1 + OFF_人物数组_啥;
    long bingxiang8 = Driver->读取指针(Driver->读取指针(temp1 + OFF_人物数组_48) + OFF_人物数组_D8_bx8);
  //  long bingxiang1 = temp1 + 0x120;
  //  printf("数组 %p\n", bingxiang1);
    AroundNumbers = 10;
    int opop = 0;
  //  for (int i = 0, j = 0; i < 1024, j < 6024; i++,j++) {
    for (int i = 0, j = 0; i < 人物, j < 坐标; i++,j++) {
    
  //   for (int i = 0, j = 0; i < 人物 && j < 坐标; i++, j++) {
//std::cout << "人物的值为: " << 人物 << std::endl;

 

      long 哦 = Driver->读取指针(Driver->读取指针(啥 + i * OFF_人物数组_步长) + OFF_人物数组_哦);


           long bingxiang6 = Driver->read<uint64_t>(bingxiang1 + (i) * OFF_坐标遍历_步长);
     // std::cout << "bingxiang6 的值为: " << std::hex << bingxiang6 << std::endl;
        long 真实坐标第三层 = Driver->read<uint64_t>(真实坐标第二层 + (j) * OFF_坐标遍历_步长);
      
      
         int 判断id1 = Driver->read<int>(真实坐标第三层 - OFF_判断id1);
	     int 判断id2 = Driver->read<int>(真实坐标第三层 - OFF_判断id2);
	     int 判断id3 = Driver->read<int>(真实坐标第三层 - OFF_判断id3);
	     int v2 = Driver->read<int>(bingxiang6 + OFF_英雄ID);//英雄ID 判断范围
	      
	     
         
	 
	 if (判断id1 == 1000) {
	 
	 	 if (判断id2 == 16777473) {
	 	 	
	 	 		 if (判断id3 == 255) {
	 
	 
	 
	 int v2 = Driver->read<int>(bingxiang6 + OFF_英雄ID);//判断1，2
 	  if (v2 >= 105 && v2 <= 600) {

 	int v3 = Driver->read<int>(bingxiang6 + OFF_英雄V3判断);//判断1，2
 	  	
	 	if (v3 == 57668 || v3 == 54045 || v3 == 53395 || v3 ==56368 || v3 == 55757 || v3 ==-57673 || v3 == -53416 || v3 == -56379 || v3 == -53911 || v3 == -55764) {
     
      
      int v1 = Driver->read<int>(bingxiang6 + OFF_英雄阵营);//敌人
	
	if (v1 == foeComp) {




        int zhengxing = Driver->读取整数(bingxiang6 + OFF_英雄阵营);  //阵营

int 真的 = Driver->读取整数(哦 + OFF_英雄阵营);

        dataTable.heroTemp[i].Id = Driver->读取整数(bingxiang6 + OFF_英雄ID);
        //printf("英雄id %d\n",dataTable.heroTemp[i].Id );
        dataTable.heroTemp[i].Hp = Driver->读取整数(Driver->读取指针(bingxiang6 + OFF_英雄血量指针) + OFF_当前血量);    // 当前血量
       // printf("当前血量 %d\n",dataTable.heroTemp[i].Hp);
        dataTable.heroTemp[i].MaxHp = Driver->读取整数(Driver->读取指针(bingxiang6 + OFF_英雄血量指针) + OFF_最大血量);  //最大血量
        
     
        
                      


     if(自身判断){
	if(自身视野 ==257) {


ImGui::GetForegroundDrawList()->AddText(ImVec2(pos_x, pos_y), Paint_red, "      [暴露]");
}
else{
ImGui::GetForegroundDrawList()->AddText(ImVec2(pos_x, pos_y), Paint_green, "      [安全]");
}

   
   }
        
        long zuobiao = Driver->read<uint64_t>(真实坐标第三层 + OFF_坐标遍历_zuobiao);

				
			//	人物坐标=getcoor(bingxiang6);
				/*
         long zuobiao = Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + 0x248) + 0x10)) + 0x10;
        
        dataTable.heroTemp[i].coord.X= (float)Driver->读取整数(zuobiao+0x0);
        dataTable.heroTemp[i].coord.Y= (float)Driver->读取整数(zuobiao+0x8);
        
        printf("x %f\n", dataTable.heroTemp[i].coord.X);
        printf("y %f\n", dataTable.heroTemp[i].coord.Y);
        */
        dataTable.heroTemp[i].coord.X = (float)Driver->读取整数(zuobiao + OFF_坐标X);    //x坐标
        //0x240) +0x118)+0x10)+0x0)+0x48)+0x0);
        dataTable.heroTemp[i].coord.Y = (float)Driver->读取整数(zuobiao + OFF_坐标Y);  //y坐标
     /*
   printf("x %f\n", dataTable.heroTemp[i].coord.X);
        printf("y %f\n", dataTable.heroTemp[i].coord.Y);
        */
        
        人物大招最大CD = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_技能3_一层) + OFF_技能_CD二层) + OFF_技能_大招DC) / OFF_技能_CD除数;                   //技能
        dataTable.heroTemp[i].HC = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_回城_一层) + OFF_回城_二层) + OFF_回城_值);
        //回城
        dataTable.heroTemp[i].Space1 = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_技能1_一层) + OFF_技能_CD二层) + OFF_技能_CD值) / OFF_技能_CD除数;                  //技能1
        dataTable.heroTemp[i].TB1 = dataTable.heroTemp[i].Id * 100 + 10;
        dataTable.heroTemp[i].Space2 = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_技能2_一层) + OFF_技能_CD二层) + OFF_技能_CD值) / OFF_技能_CD除数;                  //技能2
        dataTable.heroTemp[i].TB2 = dataTable.heroTemp[i].Id * 100 + 20;
        dataTable.heroTemp[i].Space3 = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_技能3_一层) + OFF_技能_CD二层) + OFF_技能_CD值) / OFF_技能_CD除数;                 //技能3
        dataTable.heroTemp[i].TB3 = dataTable.heroTemp[i].Id * 100 + 30;
        dataTable.heroTemp[i].Skill = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_召唤基址) + OFF_召唤_一层) + OFF_召唤_二层_CD) + OFF_召唤_CD值) / OFF_技能_CD除数;                  //召唤师技能
       //
        //回城
      //  float hp2 = dataTable.heroTemp[i].Hp * 100 / dataTable.heroTemp[i].MaxHp;



        dataTable.heroTemp[i].TB4 = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_召唤基址) + OFF_召唤_一层) + OFF_召唤_二层_图标) + OFF_召唤_图标值);  //召唤师技能图标
      //  int 斩杀HP = (int)(dataTable.heroTemp[i].MaxHp-dataTable.heroTemp[i].Hp)*0.155;          

        if (zhengxing == foeComp)
        {//阵营判断
       // int dist =getdistance(本人X, 本人Y, dataTable.heroTemp[i].coord.X, dataTable.heroTemp[i].coord.Y);
            dataTable.DynamicData[i].coord.X = (dataTable.heroTemp[i].coord.X * rientation * Wwra / 50000.0f + Wwra);
            dataTable.DynamicData[i].coord.Y = (dataTable.heroTemp[i].coord.Y * rientation * Wwra / 50000.0f * -1 + Wwra);
            float pos_x = dataTable.DynamicData[i].coord.X + SmallMapX + 94;
            float pos_y = dataTable.DynamicData[i].coord.Y + SmallMapY + 7;
            map_coord = CalMatrixMem(dataTable.heroTemp[i].coord, dataTable.Matrix);
            map_coord.X = map_coord.X + SmallHPX;
            map_coord.Y = map_coord.Y + SmallHPY;
            float hp1 = dataTable.heroTemp[i].Hp * 100 / dataTable.heroTemp[i].MaxHp;
            //补充内容
            dataTable.heroTemp[i].HC = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_回城_一层) + OFF_回城_二层) + OFF_回城_值);
            dataTable.heroTemp[i].Id = Driver->读取整数(bingxiang6 + OFF_英雄ID);
            zyz = Driver->读取整数(bingxiang6 + OFF_英雄阵营);  //阵营           



 

            float aa = hp1 * 3.6;


            float 人物X = (dataTable.heroTemp[i].coord.X * rientation * Wwr2 / 50000 + Wwr2);
            float 人物Y = (dataTable.heroTemp[i].coord.Y * rientation * Wwr2 / 50000 * -1 + Wwr2);


            //启用共享绘制传输变量
            herealx = (int)(dataTable.heroTemp[i].coord.X * rientation * WwrShare / 50000 + WwrShare);
            herealy = (int)(dataTable.heroTemp[i].coord.Y * rientation * WwrShare / 50000 * -1 + WwrShare);
            //heid=dataTable.heroTemp[i].Id;
            //hcc=dataTable.heroTemp[i].HC;
            //realhp=hp1;
            //技能相关传输
            //mytb=dataTable.heroTemp[i].TB;
            //sp=dataTable.heroTemp[i].Space;
            //jn=dataTable.heroTemp[i].Skill;
            //人物数组数据完毕
            character += std::to_string(dataTable.heroTemp[i].Id)
                + "," + std::to_string(dataTable.heroTemp[i].Hp)
                + "," + std::to_string(dataTable.heroTemp[i].MaxHp)
                + "," + std::to_string(dataTable.heroTemp[i].Space3)
                + "," + std::to_string(dataTable.heroTemp[i].Skill)
                + "," + std::to_string(herealx - 20 + ESPMenu.小地图左右调整)//3技能时间
                + "," + std::to_string(herealy - 20 + ESPMenu.小地图上下调整)
                + "," + std::to_string(hp1)
                + "," + std::to_string(zyz)
                + "," + std::to_string(zhengxing)
                + "," + std::to_string(dataTable.heroTemp[i].HC)
                + "," + std::to_string(dataTable.heroTemp[i].TB4)
                + "," + std::to_string(人物大招最大CD)
                + "," + std::to_string(人物大招最大CD)
                + "==";

            ImTextureID handId;
            if (dataTable.heroTemp[i].Id > 100 && dataTable.heroTemp[i].Id < 600) {
                handId = reinterpret_cast<ImTextureID>(贴图1.头像[dataTable.heroTemp[i].Id].textureId);
            }
            else {
                handId = reinterpret_cast<ImTextureID>(贴图1.头像[0].textureId);
            }
            //血量大于0


        /*    if (zhengxing == 1)
            {
                视野 = Driver->读取整数(Driver->读取指针(Driver->读取指针(bingxiang6 + 0x258) + 0x68) + 0x3C);
            }  else {
                视野 = Driver->读取整数(Driver->读取指针(Driver->读取指针(bingxiang6 + 0x258) + 0x68) + 0x1C);
            }*/


   
                       if (真的 == 1) {
            视野 = Driver->读取整数(
                Driver->读取指针(Driver->读取指针(哦 + OFF_视野基址) + OFF_视野_一层) + OFF_视野_己方);
            自身视野 = Driver->读取整数(
                Driver->读取指针(
                    Driver->读取指针(bingxiang8 + OFF_视野基址) + OFF_视野_一层) +
                OFF_视野_敌方);
          } else {
            视野 = Driver->读取整数(
                Driver->读取指针(Driver->读取指针(哦 + OFF_视野基址) + OFF_视野_一层) + OFF_视野_敌方);
            自身视野 = Driver->读取整数(
                Driver->读取指针(
                    Driver->读取指针(bingxiang8 + OFF_视野基址) + OFF_视野_一层) +
                OFF_视野_己方);
          }


            if (aa > 0) {

                人物大招最大CD = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_技能3_一层) + OFF_技能_CD二层) + OFF_技能_大招DC) / OFF_技能_CD除数;                   //技能
                dataTable.heroTemp[i].HC = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_回城_一层) + OFF_回城_二层) + OFF_回城_值);
                //回城
                dataTable.heroTemp[i].Space1 = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_技能1_一层) + OFF_技能_CD二层) + OFF_技能_CD值) / OFF_技能_CD除数;                  //技能
                dataTable.heroTemp[i].TB1 = dataTable.heroTemp[i].Id * 100 + 10;
                dataTable.heroTemp[i].Space2 = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_技能2_一层) + OFF_技能_CD二层) + OFF_技能_CD值) / OFF_技能_CD除数;                  //技能
                dataTable.heroTemp[i].TB2 = dataTable.heroTemp[i].Id * 100 + 20;
                dataTable.heroTemp[i].Space3 = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_技能基址) + OFF_技能3_一层) + OFF_技能_CD二层) + OFF_技能_CD值) / OFF_技能_CD除数;                 //技能
                dataTable.heroTemp[i].TB3 = dataTable.heroTemp[i].Id * 100 + 30;
                dataTable.heroTemp[i].Skill = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_召唤基址) + OFF_召唤_一层) + OFF_召唤_二层_CD) + OFF_召唤_CD值) / OFF_技能_CD除数;                  //技能
                dataTable.heroTemp[i].TB4 = Driver->读取整数(Driver->读取指针(Driver->读取指针(Driver->读取指针(bingxiang6 + OFF_召唤基址) + OFF_召唤_一层) + OFF_召唤_二层_图标) + OFF_召唤_图标值);



                if (dataTable.heroTemp[i].TB4 != 80102 && dataTable.heroTemp[i].TB4 != 80103 &&
                    dataTable.heroTemp[i].TB4 != 80104 && dataTable.heroTemp[i].TB4 != 80105 &&
                    dataTable.heroTemp[i].TB4 != 80107 && dataTable.heroTemp[i].TB4 != 80108 &&
                    dataTable.heroTemp[i].TB4 != 80109 && dataTable.heroTemp[i].TB4 != 80110 &&
                    dataTable.heroTemp[i].TB4 != 80115 && dataTable.heroTemp[i].TB4 != 80121 &&
                    dataTable.heroTemp[i].TB4 != 80116 && dataTable.heroTemp[i].TB4 != 80162 &&
                    dataTable.heroTemp[i].TB4 != 53391 && dataTable.heroTemp[i].TB4 != 53393 && dataTable.heroTemp[i].TB4 != 10023 && dataTable.heroTemp[i].TB4 != 801162
                    ) {
                    dataTable.heroTemp[i].TB4 = 0;
                }


                {
                

                
                
                

          if(地图){
   //小头像
   if(视野==257){
                    ImGui::GetForegroundDrawList()->AddImage( handId!= NULL ?  handId: 0 , {(int)pos_x - TXdx-touxiangdaxiao, (int)pos_y - TXdx-touxiangdaxiao}, {(int)pos_x + TXdx+touxiangdaxiao, (int)pos_y + TXdx+touxiangdaxiao});
                    
                ImGui::GetForegroundDrawList()->AddCircleArc({ pos_x, pos_y }, 21 + xiaodituxue, ImVec2(0, 360), Paint_white, 0, 5.5f);//白底背景
                            ImGui::GetForegroundDrawList()->AddCircleArc({ pos_x, pos_y }, 21 + xiaodituxue, ImVec2(0, aa), Paint_red, 0, 5.5f);//红色血圈                
                    
                   }else{  
                   
      ImGui::GetForegroundDrawList()->AddCircleArc({ pos_x, pos_y }, 21 + xiaodituxue, ImVec2(0, 360), Paint_white, 0, 5.5f);//白底背景
                            ImGui::GetForegroundDrawList()->AddCircleArc({ pos_x, pos_y }, 21 + xiaodituxue, ImVec2(0, aa), Paint_purple, 0, 5.5f);//红色血圈   没有视野情况             
                   
                   
     ImGui::GetForegroundDrawList()->AddImage( handId!= NULL ?  handId: 0 , {(int)pos_x - TXdx-touxiangdaxiao, (int)pos_y - TXdx-touxiangdaxiao}, {(int)pos_x + TXdx+touxiangdaxiao, (int)pos_y + TXdx+touxiangdaxiao});  
     
   auto draw_list = ImGui::GetForegroundDrawList();

// 添加图像
draw_list->AddImage(handId != NULL ? handId : 0, {(int)pos_x - TXdx-touxiangdaxiao, (int)pos_y - TXdx-touxiangdaxiao}, {(int)pos_x + TXdx+touxiangdaxiao, (int)pos_y + TXdx+touxiangdaxiao});

// 计算圆的中心点和半径
ImVec2 center(pos_x, pos_y);
float radius = TXdx + touxiangdaxiao;

// 添加半透明的黑色圆形滤镜 无视野
draw_list->AddCircleFilled(center, radius, IM_COL32(0, 0, 0, 90));      
                 

   }
}
                    
                    




                    if (方框) {
                        //方框
                        ImGui::GetForegroundDrawList()->AddRect(
                            ImVec2((int)map_coord.X - (map_coord.H * 0.5f), (int)map_coord.Y - (map_coord.H * 1.32f)),
                            ImVec2((int)map_coord.X + (map_coord.H * 0.5), (int)map_coord.Y + (map_coord.H * 0.2f)), 颜色配置.方框颜色, 0.0f, 0, 2.0f
                        );

                        //方框里头像
                        ImGui::GetForegroundDrawList()->AddImage(
                            handId != NULL ? handId : 0,
                            { (int)map_coord.X - (map_coord.H * 0.2f), (int)map_coord.Y - (map_coord.H * 0.2f) + (-map_coord.H * 1.0f) },
                            { (int)map_coord.X + (map_coord.H * 0.2f), (int)map_coord.Y + (map_coord.H * 0.2f) + (-map_coord.H * 1.0f) });

                        // 计算圆角矩形的位置坐标
                        ImVec2 rect_mian((int)map_coord.X - (map_coord.H * 0.2f), (int)map_coord.Y - (map_coord.H * 0.2f) + (-map_coord.H * 1.0f));
                        ImVec2 rect_maxn((int)map_coord.X + (map_coord.H * 0.2f), (int)map_coord.Y + (map_coord.H * 0.2f) + (-map_coord.H * 1.0f));
                        float roundin = 5.0f; // 圆角的半径
                        // 绘制圆角矩形边框包裹头像
                        ImGui::GetForegroundDrawList()->AddRect(rect_mian, rect_maxn, 颜色配置.方框颜色, roundin);


                        float max_hp_percentage = 1.0f;
                        float current_hp_percentage = (float)dataTable.heroTemp[i].Hp / (float)dataTable.heroTemp[i].MaxHp;
                        float bar_width = map_coord.H * 0.15f;  //血条宽度
                        float bar_height = map_coord.H * 1.25f;  //血条长度
                        float corner_radius = 5.0f;

                        // 绘制最大血量条边框
                        ImGui::GetForegroundDrawList()->AddRect(
                            ImVec2((int)map_coord.X - bar_width / 2 - (-map_coord.H * 0.65f), (int)map_coord.Y - (map_coord.H * 1.35f)),
                            ImVec2((int)map_coord.X + bar_width / 2 - (-map_coord.H * 0.65f), (int)map_coord.Y + bar_height - (map_coord.H * 1.05f)),
                            Paint_white,
                            corner_radius
                        );

                        // 绘制最大血量条填充
                        ImGui::GetForegroundDrawList()->AddRectFilled(
                            ImVec2((int)map_coord.X - bar_width / 2 + corner_radius - (-map_coord.H * 0.65f), (int)map_coord.Y + corner_radius - (map_coord.H * 1.35f)),
                            ImVec2((int)map_coord.X + bar_width / 2 - corner_radius - (-map_coord.H * 0.65f), (int)map_coord.Y + bar_height - corner_radius - (map_coord.H * 1.05f)),
                            Paint_white,
                            corner_radius
                        );

                        // 计算当前血量条的填充高度和起始位置
                        float current_hp_fill_height = bar_height * current_hp_percentage;
                        float fill_correction_factor = 1.32f;  // 初始修正因子为1.35

                        // 根据敌人剩余血量百分比动态调整修正因子的值
                        if (current_hp_percentage <= 0.85f) {
                            fill_correction_factor = 1.05f;
                        }

                        float current_hp_fill_start_y = (int)map_coord.Y + bar_height - current_hp_fill_height - (map_coord.H * fill_correction_factor);

                        // 绘制当前血量条填充
                        ImGui::GetForegroundDrawList()->AddRectFilled(
                            ImVec2((int)map_coord.X - bar_width / 2 + corner_radius - (-map_coord.H * 0.65f), current_hp_fill_start_y),
                            ImVec2((int)map_coord.X + bar_width / 2 - corner_radius - (-map_coord.H * 0.65f), (int)map_coord.Y + bar_height - (map_coord.H * 1.05f)),
                            颜色配置.血量颜色,
                            corner_radius
                        );

                    }

                    if (射线) {
                        //射线
                    //if ((map_coord.X > -20.0f && map_coord.X < yxpx+20.0f) && (map_coord.Y > -20.0f && map_coord.Y < yxpy+20.0f))
                        if (视野 == 1) {
                            //ImGui::GetForegroundDrawList()->AddLine(ImVec2(yxpx/2, yxpy/2), ImVec2(map_coord.X, map_coord.Y + (-map_coord.H*1.0f)), Paint_purple, 0.5f);//没有射线情况
                        }
                        else {
                            ImGui::GetForegroundDrawList()->AddLine(ImVec2(yxpx / 2, yxpy / 2), ImVec2(map_coord.X, map_coord.Y + (-map_coord.H * 1.0f)), Paint_touming, 0.3f);
                        }
                    }
                    //方框里技能
                    //方框里技能
                    if (框技) {

                        //英雄大招 
                        if (dataTable.heroTemp[i].Space3 > 0) {

                            // 绘制大招
                            ImTextureID tubiaoid;
                            if (dataTable.heroTemp[i].TB3 != 0) {
                                if (dataTable.heroTemp[i].TB3 == 801162) {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB3 - 800000].textureId);
                                }
                                else {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB3 - 0].textureId);
                                }
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            }

                            ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                            //绘制大招图片
                            ImGui::GetForegroundDrawList()->AddImage(
                                tubiaoid != NULL ? tubiaoid : tubiaoid2,
                                ImVec2((float)map_coord.X - (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.16) - (map_coord.H * 0.15)),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y + (map_coord.H * 0.16) - (map_coord.H * 0.15)));


                            //绘制黑色背景
                            float circleRadius = map_coord.H * 0.16f;
                            ImVec2 circleCenter = ImVec2((float)map_coord.X + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.15));
                            ImU32 circleColor = IM_COL32(0, 0, 0, 100);
                            ImGui::GetForegroundDrawList()->AddCircleFilled(circleCenter, circleRadius, circleColor);
    
                            int intvalue = dataTable.heroTemp[i].Space3;
                            string test = std::to_string(intvalue);

                            ImGui::GetForegroundDrawList()->AddText(
                                NULL, (float)((double)(0.25) * map_coord.H),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.6) - (-map_coord.H * 0.25f), (float)map_coord.Y - (map_coord.H * 0.07f) - (map_coord.H * 0.20f)), Paint_white,
                                test.c_str()); //大招计时


                        }
                        else {
                            ImTextureID tubiaoid;
                            if (dataTable.heroTemp[i].TB3 != 0) {
                                if (dataTable.heroTemp[i].TB3 == 801162) {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB3 - 800000].textureId);
                                }
                                else {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB3 - 0].textureId);
                                }
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            }

                            ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                            ImGui::GetForegroundDrawList()->AddImage(
                                tubiaoid != NULL ? tubiaoid : tubiaoid2,
                                ImVec2((float)map_coord.X - (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.16) - (map_coord.H * 0.15)),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y + (map_coord.H * 0.16) - (map_coord.H * 0.15)));
                        }






                        //英雄二技能 
                        if (dataTable.heroTemp[i].Space2 > 0) {

                            ImTextureID tubiaoid;
                            if (dataTable.heroTemp[i].TB2 != 0) {
                                if (dataTable.heroTemp[i].TB2 == 801162) {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB2 - 800000].textureId);
                                }
                                else {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB2 - 0].textureId);
                                }
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            }
                            ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            //绘制二技能图片
                            ImGui::GetForegroundDrawList()->AddImage(
                                tubiaoid != NULL ? tubiaoid : tubiaoid2,
                                ImVec2((float)map_coord.X - (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.16) - (map_coord.H * 0.5)),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y + (map_coord.H * 0.16) - (map_coord.H * 0.5)));

                            //绘制黑色背景
                            float circleRadius = map_coord.H * 0.16f;
                            ImVec2 circleCenter = ImVec2((float)map_coord.X + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.5));
                            ImU32 circleColor = IM_COL32(0, 0, 0, 100);
                            ImGui::GetForegroundDrawList()->AddCircleFilled(circleCenter, circleRadius, circleColor);

                            //二技能倒计时
                            int intvalue = dataTable.heroTemp[i].Space2;
                            string test = std::to_string(intvalue);

                            ImGui::GetForegroundDrawList()->AddText(
                                NULL, (float)((double)(0.25) * map_coord.H),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.6) - (-map_coord.H * 0.25f), (float)map_coord.Y - (map_coord.H * 0.07f) - (map_coord.H * 0.58f)), Paint_white,
                                test.c_str()); //大招计时
                        }
                        else {
                            ImTextureID tubiaoid;
                            if (dataTable.heroTemp[i].TB2 != 0) {
                                if (dataTable.heroTemp[i].TB2 == 801162) {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB2 - 800000].textureId);
                                }
                                else {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB2 - 0].textureId);
                                }
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            }

                            ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                            ImGui::GetForegroundDrawList()->AddImage(
                                tubiaoid != NULL ? tubiaoid : tubiaoid2,
                                ImVec2((float)map_coord.X - (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.16) - (map_coord.H * 0.5)),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y + (map_coord.H * 0.16) - (map_coord.H * 0.5)));
                        }



                        //英雄一技能 
                        if (dataTable.heroTemp[i].Space1 > 0) {
                            ImTextureID tubiaoid;
                            if (dataTable.heroTemp[i].TB1 != 0) {
                                if (dataTable.heroTemp[i].TB1 == 801162) {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB1 - 800000].textureId);
                                }
                                else {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB1 - 0].textureId);
                                }
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            }
                            ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            //绘制技能贴图
                            ImGui::GetForegroundDrawList()->AddImage(
                                tubiaoid != NULL ? tubiaoid : tubiaoid2,
                                ImVec2((float)map_coord.X - (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.16) - (map_coord.H * 0.85)),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y + (map_coord.H * 0.16) - (map_coord.H * 0.85)));

                            //绘制黑色背景
                            float circleRadius = map_coord.H * 0.16f;
                            ImVec2 circleCenter = ImVec2((float)map_coord.X + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.85));
                            ImU32 circleColor = IM_COL32(0, 0, 0, 100);
                            ImGui::GetForegroundDrawList()->AddCircleFilled(circleCenter, circleRadius, circleColor);

                            //一技能倒计时
                            int intvalue = dataTable.heroTemp[i].Space1;
                            string test = std::to_string(intvalue);

                            ImGui::GetForegroundDrawList()->AddText(
                                NULL, (float)((double)(0.25) * map_coord.H),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.6) - (-map_coord.H * 0.25f), (float)map_coord.Y - (map_coord.H * 0.07f) - (map_coord.H * 0.93f)), Paint_white,
                                test.c_str());
                        }
                        else {
                            ImTextureID tubiaoid;
                            if (dataTable.heroTemp[i].TB1 != 0) {
                                if (dataTable.heroTemp[i].TB1 == 801162) {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB1 - 800000].textureId);
                                }
                                else {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB1 - 0].textureId);
                                }
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            }
                            ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            //绘制技能贴图
                            ImGui::GetForegroundDrawList()->AddImage(
                                tubiaoid != NULL ? tubiaoid : tubiaoid2,
                                ImVec2((float)map_coord.X - (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.16) - (map_coord.H * 0.85)),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y + (map_coord.H * 0.16) - (map_coord.H * 0.85)));
                        }


                        //召唤师技能 
                        if (dataTable.heroTemp[i].Skill > 0) {

                            ImTextureID tubiaoid;
                            if (dataTable.heroTemp[i].TB4 != 0) {
                                if (dataTable.heroTemp[i].TB4 == 801162) {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB4 - 800000].textureId);
                                }
                                else {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB4 - 80000].textureId);
                                }
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            }

                            ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                            ImGui::GetForegroundDrawList()->AddImage(
                                tubiaoid != NULL ? tubiaoid : tubiaoid2,
                                ImVec2((float)map_coord.X - (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.16) - (map_coord.H * 1.2)),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y + (map_coord.H * 0.16) - (map_coord.H * 1.2)));


                            //绘制黑色背景
                            float circleRadius = map_coord.H * 0.16f;
                            ImVec2 circleCenter = ImVec2((float)map_coord.X + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 1.2));
                            ImU32 circleColor = IM_COL32(0, 0, 0, 100);
                            ImGui::GetForegroundDrawList()->AddCircleFilled(circleCenter, circleRadius, circleColor);


                            // 召唤师技能cd倒计时
                            int intvalue = dataTable.heroTemp[i].Skill;
                            string test = std::to_string(intvalue);

                            ImGui::GetForegroundDrawList()->AddText(
                                NULL, (float)((double)(0.25) * map_coord.H),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.6) - (-map_coord.H * 0.25f), (float)map_coord.Y - (map_coord.H * 0.07f) - (map_coord.H * 1.23f)), Paint_white,
                                test.c_str());
                        }
                        else {
                            // 召唤师cd完成
                            ImTextureID tubiaoid;
                            if (dataTable.heroTemp[i].TB4 != 0) {
                                if (dataTable.heroTemp[i].TB4 == 801162) {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB4 - 800000].textureId);
                                }
                                else {
                                    tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB4 - 80000].textureId);
                                }
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                            }

                            ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                            ImGui::GetForegroundDrawList()->AddImage(
                                tubiaoid != NULL ? tubiaoid : tubiaoid2,
                                ImVec2((float)map_coord.X - (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y - (map_coord.H * 0.16) - (map_coord.H * 1.2)),
                                ImVec2((float)map_coord.X + (map_coord.H * 0.16) + (map_coord.H * 0.95), (float)map_coord.Y + (map_coord.H * 0.16) - (map_coord.H * 1.2)));
                        }

                    }

                }//血量大于0

   }//血量0吗
                                //TODO：顶上技能

                //顶上技能栏
                if (顶上技能) {
                
                
                    float Theoffset_X = CDjs_X + SmallMapX + jinenglanzX;
                    float Theoffset_Y = CDjs_Y + SmallMapY + jinenglanzY;
                    float CDdrawXY[3][2] = {
                    {(float)(Theoffset_X + intervalcdX * opop), (float)(Theoffset_Y + intervalcdY * 0)},
                    {(float)(Theoffset_X + intervalcdX * opop), (float)(Theoffset_Y + (TXdx / 2) + intervalcdY * 1)},
                    {(float)(Theoffset_X + intervalcdX * opop), (float)(Theoffset_Y + TXdx + intervalcdY * 2)}
                    };


                    CDdrawXY[1][0] = CDdrawXY[1][0] + (TXdx / 14.0f); // x 二次改变偏移
                    CDdrawXY[0][1] = CDdrawXY[0][1] + (TXdx)+(TXdx / 5.0f);
                    CDdrawXY[1][1] = CDdrawXY[1][1] + (TXdx)+(TXdx / 5.0f);//绘制头像
                    CDdrawXY[2][1] = CDdrawXY[2][1] + (TXdx)+(TXdx / 5.0f);

                    ImGui::GetForegroundDrawList()->AddImage(handId != NULL ? handId : 0, { CDdrawXY[1][0] - TXdx - touxiangdaxiao, CDdrawXY[0][1] - TXdx - touxiangdaxiao }, { CDdrawXY[1][0] + TXdx + touxiangdaxiao, CDdrawXY[0][1] + TXdx + touxiangdaxiao });//顶上头像
                    ImGui::GetForegroundDrawList()->AddCircleArc(ImVec2(CDdrawXY[1][0], CDdrawXY[0][1]), 21 + xiaodituxue, ImVec2(0, 360), Paint_white, 0, 5);//白底背景              
                    ImGui::GetForegroundDrawList()->AddCircleArc(ImVec2(CDdrawXY[1][0], CDdrawXY[0][1]), 21 + xiaodituxue, ImVec2(0, aa), 颜色配置.血量颜色, 0, 5); //红色圈边

                    //顶上绘制大招
                    if (dataTable.heroTemp[i].Space3 > 0) {
                        //大招技能图标 
                        ImTextureID tubiaoid;
                        if (dataTable.heroTemp[i].TB3 != 0) {
                            if (dataTable.heroTemp[i].TB3 == 801162) {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB3 - 0].textureId);
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB3 - 0].textureId);
                            }
                        }
                        else {
                            tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                        }

                        //p没读取或者死亡了的问号图标 
                        ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                        //绘制技能图片 
                        ImGui::GetForegroundDrawList()->AddImage(tubiaoid != NULL ? tubiaoid : tubiaoid2, { (float)CDdrawXY[0][0] - TXdx, CDdrawXY[1][1] - TXdx }, { (float)CDdrawXY[0][0] + TXdx, CDdrawXY[1][1] + TXdx });

                        ImVec2 circleCenter = { (CDdrawXY[0][0]), (CDdrawXY[1][1]) };
                        float circleRadius = TXdx;
                        ImU32 black = IM_COL32(0, 0, 0, 100);
                        ImGui::GetForegroundDrawList()->AddCircleFilled(circleCenter, circleRadius, black);


                        //技能倒计时
                        int intvalue = dataTable.heroTemp[i].Space3;
                        string test = std::to_string(intvalue);
                        ImVec2 textPosition = ImVec2(CDdrawXY[0][0] - (TXdx / 10) - ImGui::CalcTextSize(test.c_str()).x / 2, (CDdrawXY[1][1] - (TXdx / 1.4)));
                        ImGui::GetForegroundDrawList()->AddText(NULL, skills_txt_dx, textPosition, Paint_white, test.c_str());
                    }
                    else {

                        //大招技能图标 
                        ImTextureID tubiaoid;
                        if (dataTable.heroTemp[i].TB3 != 0) {
                            if (dataTable.heroTemp[i].TB3 == 801162) {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB3 - 0].textureId);
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB3 - 0].textureId);
                            }
                        }
                        else {
                            tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                        }
                        ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                        //顶上头像 
                        ImGui::GetForegroundDrawList()->AddImage(tubiaoid != NULL ? tubiaoid : tubiaoid2, { (float)CDdrawXY[0][0] - TXdx, CDdrawXY[1][1] - TXdx }, { (float)CDdrawXY[0][0] + TXdx, CDdrawXY[1][1] + TXdx });//顶上头像
                    }






                    //绘制召唤
                    if (dataTable.heroTemp[i].Skill > 0) {
                        ImTextureID tubiaoid;
                        if (dataTable.heroTemp[i].TB4 != 0) {
                            if (dataTable.heroTemp[i].TB4 == 801162) {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB4 - 800000].textureId);
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB4 - 80000].textureId);
                            }
                        }
                        else {
                            tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                        }
                        ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                        //绘制召唤师技能图片
                        ImGui::GetForegroundDrawList()->AddImage(tubiaoid != NULL ? tubiaoid : tubiaoid2, { (float)CDdrawXY[2][0] - TXdx, CDdrawXY[2][1] - TXdx }, { (float)CDdrawXY[2][0] + TXdx, CDdrawXY[2][1] + TXdx });

                        //绘制黑色背景图
                        ImVec2 circleCenter = { (CDdrawXY[2][0]), (CDdrawXY[2][1]) };
                        float circleRadius = TXdx;
                        ImU32 black = IM_COL32(0, 0, 0, 100);
                        ImGui::GetForegroundDrawList()->AddCircleFilled(circleCenter, circleRadius, black);

                        int intvalue = dataTable.heroTemp[i].Skill;
                        string test = std::to_string(intvalue);
                        ImGui::GetForegroundDrawList()->AddText(NULL, skills_txt_dx, ImVec2(CDdrawXY[2][0] - (TXdx / 1.4), (CDdrawXY[2][1] - (TXdx / 1.2))), Paint_white, test.c_str());
                    }
                    else {
                        ImTextureID tubiaoid;
                        if (dataTable.heroTemp[i].TB4 != 0) {
                            if (dataTable.heroTemp[i].TB4 == 801162) {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB4 - 800000].textureId);
                            }
                            else {
                                tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[dataTable.heroTemp[i].TB4 - 80000].textureId);
                            }
                        }
                        else {
                            tubiaoid = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);
                        }
                        ImTextureID tubiaoid2 = reinterpret_cast<ImTextureID>(技能贴图.头像[0].textureId);

                        //绘制召唤师技能图片
                        ImGui::GetForegroundDrawList()->AddImage(tubiaoid != NULL ? tubiaoid : tubiaoid2, { (float)CDdrawXY[2][0] - TXdx, CDdrawXY[2][1] - TXdx }, { (float)CDdrawXY[2][0] + TXdx, CDdrawXY[2][1] + TXdx });
                    }



                    //死亡时候的x 
                    if (hp1 <= 0)
                        ImGui::GetForegroundDrawList()->AddText(NULL, 80, ImVec2(CDdrawXY[1][0] - (TXdx / 1.2) - 7, CDdrawXY[0][1] - (TXdx / 0.45)), Paint_red, "x");
                        
                        
                        
                }

                opop++;
         
        }//阵营判断
    }//人物数组结束了结束了
}
}
}
}
}
}


            if (上帝) {
		         long sdaddr = Driver->读取指针(Driver->读取指针(lil2cpp_base+OFF_上帝_一层)+OFF_上帝_二层)+OFF_上帝_写入;
		         Driver->write<float>(sdaddr,shangdi);//自定义数值
		         }
    uint64_t BuffAddress;//buff数量地址
    uint64_t BxAddress;//兵线数量地址
    uint64_t bxAddress;//兵线属性首位置
    uint64_t Buffsl;//buff坐标数量


//传输变量  野怪传输
    int ygtime;
    int  buffid;
    int  buffx;
    int  buffy;
    long BUFFtemp;  //临时数组
    int 游戏时间;
    int xxx1, yyy1;
    int bui;
    long bbuff1;
//野怪血量
int maxyghp;
        if (野怪) {

    long temp2 = Driver->读取指针(libGame_basebss + OFF_野怪基址);
    BuffAddress = Driver->读取指针(Driver->读取指针(Driver->读取指针(temp2+OFF_野怪_一层) + OFF_野怪_二层) + OFF_野怪_三层);
    野怪数组 = Driver->读取指针(Driver->读取指针(Driver->读取指针(temp2+OFF_野怪_一层) + OFF_野怪_二层) + OFF_野怪_三层);//
    for (int i = 0; i < 23; i++) {
        dataTable.pve[i].maxcd =  Driver->读取指针((u_long)(BuffAddress + i * OFF_野怪_步长)) + OFF_野怪_maxcd;
        dataTable.pve[i].cd = Driver->读取指针((u_long)(BuffAddress + i * OFF_野怪_步长)) + OFF_野怪_cd;
        dataTable.pve[i].cc = Driver->读取指针((u_long)(BuffAddress + i * OFF_野怪_步长));

        dataTable.pve[i].id = dataTable.pve[i].cc + OFF_野怪_id;
        long int 实体指针=Driver->读取指针(dataTable.pve[i].cc+OFF_野怪_实体指针);
        dataTable.pve[i].X = Driver->读取指针(Driver->读取指针(Driver->读取指针(实体指针+OFF_野怪_坐标一层)+OFF_野怪_坐标二层)+OFF_野怪_坐标三层)+0x0;
        dataTable.pve[i].Y = Driver->读取指针(Driver->读取指针(Driver->读取指针(实体指针+OFF_野怪_坐标一层)+OFF_野怪_坐标二层)+OFF_野怪_坐标三层)+0x8;
        dataTable.pve[i].hp = Driver->读取指针(实体指针 + OFF_野怪_血量指针) + OFF_野怪_血量;
        dataTable.pveTemp[i].maxcd = Driver->read<int>(dataTable.pve[i].maxcd) / 1000;
        int 固定坐标X = Driver->read<int>(dataTable.pve[i].cc + OFF_野怪_固定坐标X);
        int 固定坐标Y = Driver->read<int>(dataTable.pve[i].cc + OFF_野怪_固定坐标Y);
        float pvegdX = (float)(固定坐标X * rientation * Wwra / 50000.0f + Wwra);
        float pvegdY = (float)(固定坐标Y * rientation * Wwra / 50000.0f * -1 + Wwra);
        //共享全源数据
        bbuff1 = Driver->读取指针(野怪数组 + i * OFF_野怪_步长);
        buffid = Driver->读取整数(bbuff1 + OFF_野怪_id);
        ygtime = Driver->读取整数(bbuff1 + OFF_野怪_时间) / 1000;
        xxx1 = Driver->读取整数(bbuff1 + OFF_野怪_传输X);
        yyy1 = Driver->读取整数(bbuff1 + OFF_野怪_传输Y);
        buffx = xxx1 * rientation * WwrShare / 50000.0f + WwrShare;
        buffy = yyy1 * rientation * WwrShare / 50000.0f * -1 + WwrShare;
        //传输野怪数据
        creeps += std::to_string(0)
            + "," + std::to_string(ygtime)
            + "," + std::to_string(buffid)
            + "," + std::to_string(buffx + ESPMenu.野怪左右调整)
            + "," + std::to_string(buffy + ESPMenu.野怪上下调整)
            + "==";
        //传输野怪数据完毕

    
    
        dataTable.pveTemp[i].cd = Driver->读取整数(dataTable.pve[i].cd) / 1000;
        dataTable.pveTemp[i].coord.X = (float)Driver->读取整数(dataTable.pve[i].X);
        dataTable.pveTemp[i].coord.Y = (float)Driver->读取整数(dataTable.pve[i].Y);
        yg_coord = CalMatrixMem(dataTable.pveTemp[i].coord, dataTable.Matrix);
        dataTable.pveTemp[i].id = Driver->读取整数(dataTable.pve[i].id);
        dataTable.pveTemp[i].hp = Driver->读取整数(dataTable.pve[i].hp);
        maxyghp=Driver->读取整数(dataTable.pve[i].hp+OFF_野怪_血量最大);      

        //绘制全局野怪血量
        int hpyg=dataTable.pveTemp[i].hp;
        string yggealth=std::to_string(hpyg);
        std::string s1;
				s1 += "[";
				s1 += std::to_string((int)dataTable.pveTemp[i].hp);
				s1 += "/";
				s1 += std::to_string((int)maxyghp);
				s1 += "]";
        if(hpyg>0)
        {
        ImGui::GetForegroundDrawList()->AddRect({yg_coord.X - 63, yg_coord.Y - 29}, {yg_coord.X + 59, yg_coord.Y - 17},ImColor(255, 255, 255, 255),0,0, 1.5f);
		ImGui::GetForegroundDrawList()->AddRectFilled({yg_coord.X - 62, yg_coord.Y - 28}, {yg_coord.X - 62 + (1.2f*hpyg/maxyghp*100), yg_coord.Y - 18},Paint_green, 1);
			
        
        ImGui::GetForegroundDrawList()->AddRect({yg_coord.X, yg_coord.Y}, {yg_coord.X, yg_coord.Y},ImColor(255, 255, 255, 255),0,0, 1.5f);
				
    	ImGui::GetForegroundDrawList()->AddText(NULL, 18.f, {yg_coord.X, yg_coord.Y},ImColor(255,255,0,255), s1.c_str());
        }
          //  ImGui::GetForegroundDrawList()->AddText(NULL, 30.0f, ImVec2((float)(yg_coord.X), (float)(yg_coord.Y)), Paint_green, yggealth.c_str());//野怪血量全局显示文本
            
        dataTable.pveTemp[i].coord.X = (float)(dataTable.pveTemp[i].coord.X * rientation * Wwra / 50000.0f + Wwra);
        dataTable.pveTemp[i].coord.Y = (float)(dataTable.pveTemp[i].coord.Y * rientation * Wwra / 50000.0f * -1 + Wwra);

        int 野怪cd = Driver->读取整数(dataTable.pve[i].cd) / 1000;
        if (野怪cd > 90) { continue; }
        int 野怪屏幕X = ((float)Driver->读取整数(dataTable.pve[i].cc + OFF_野怪_传输X)) * rientation * Wwr2 / 50000 + Wwr2;
        int 野怪屏幕Y = ((float)Driver->读取整数(dataTable.pve[i].cc + OFF_野怪_传输Y)) * rientation * Wwr2 / 50000 * -1 + Wwr2;

        if (dataTable.pveTemp[i].cd == 0 || dataTable.pveTemp[i].cd == dataTable.pveTemp[i].maxcd || dataTable.pveTemp[i].cd > 240 || dataTable.pveTemp[i].id == 166009 || dataTable.pveTemp[i].id == 1010333 || dataTable.pveTemp[i].id == 166018 || dataTable.pveTemp[i].id == 1010335 || dataTable.pveTemp[i].id == 166012 || dataTable.pveTemp[i].id == 1010334 || dataTable.pveTemp[i].id == 166022 || dataTable.pveTemp[i].id == 1010336 || dataTable.pveTemp[i].id == 1660221) {
        //166009/1010333/166018/1010335/166012/1010334/166022/1010336/1660221
               continue;
             } else {
        string text = std::to_string(dataTable.pveTemp[i].cd);//这里是野怪复活时间
		      ImVec2 textSize2 = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize(), FLT_MAX, 0, text.c_str());
		      ImVec2 textPos2 = ImVec2((float)(pvegdX + SmallMapX - 6.0 + 93) - textSize2.x * 0.5f, (float)(pvegdY + SmallMapY - 7.9 + 6) - textSize2.y * 0.25f); // 计算居中位置
              ImGui::GetForegroundDrawList()->AddText(NULL, 31.0f, textPos2,ImColor(255, 255, 255), text.c_str());
              }
    }
    }



    if (兵线) {


    int bingx;
  //  int bingy;//兵线共享变量

    long temp5 = Driver->读取指针(libGame_basebss + OFF_坐标模块);

    BxAddress = Driver->读取指针(Driver->读取指针(temp5 + OFF_兵线_一层) + OFF_兵线_二层);
    long cont = 0;
    for (int l = 0; l < 50; l++) {
      //  bxAddress = Driver->读取指针(BxAddress + (0x60 + l * 0x18));
        bxAddress = Driver->读取指针(BxAddress + (l * OFF_兵线_步长));
        int temp = Driver->读取整数(bxAddress + OFF_兵线_阵营);
        int bxxl = Driver->read<int>(Driver->read<uint64_t>(bxAddress + OFF_兵线_血量指针) + OFF_兵线_血量);
        /*printf("兵线阵营%d\n",temp);
        printf("人物阵营%d\n",foeComp);*/
              if (temp == foeComp) {
                

                dataTable.CeTemp[cont].coord.X = (float)Driver->read<int>(Driver->read<uint64_t>(Driver->read<uint64_t>(Driver->read<uint64_t>(bxAddress + OFF_兵线_坐标基址) + OFF_兵线_坐标一层) + OFF_兵线_坐标二层) + 0x0);
                dataTable.CeTemp[cont].coord.Y = (float)Driver->read<int>(Driver->read<uint64_t>(Driver->read<uint64_t>(Driver->read<uint64_t>(bxAddress + OFF_兵线_坐标基址) + OFF_兵线_坐标一层) + OFF_兵线_坐标二层) + 0x8);


                dataTable.CeTemp[cont].hp =Driver->read<int>(Driver->read<uint64_t>(bxAddress + OFF_兵线_血量指针) + OFF_兵线_血量);
                dataTable.CeTemp[cont].maxhp =Driver->read<int>(Driver->read<uint64_t>(bxAddress + OFF_兵线_血量指针) + OFF_兵线_血量最大);
                
                
                
                  int 兵线X = dataTable.CeTemp[cont].coord.X * rientation * bingxiang1 / 50000 + bingxiang1;
                  int 兵线Y = dataTable.CeTemp[cont].coord.Y * rientation * bingxiang1 / 50000 * -1 + bingxiang1;
                  //定义传输兵线
               // bingx = 兵线X* 0.7;
              //  bingy = 兵线Y* 0.7;
             //   soldier += std::to_string(bingx + ESPMenu.兵线左右调整) +
               //  "," + std::to_string(bingy + ESPMenu.兵线左右调整) + 
               //  "," + std::to_string(temp) + "==";
               
               
			  
			                
                if (dataTable.CeTemp[cont].coord.X == 0 ||
                dataTable.CeTemp[cont].coord.Y == 0) {
                continue;
                }
                
                if (bxxl <= 0) {
                continue;
                }
                
                dataTable.CeTemp[cont].coord.X = dataTable.CeTemp[cont].coord.X * rientation * Wwra / 50000.0f + Wwra;
                dataTable.CeTemp[cont].coord.Y = dataTable.CeTemp[cont].coord.Y * rientation * Wwra / 50000.0f * -1 + Wwra;
                
                cont++;
              }
              }
          

        dataTable.xbsl = cont;
        for (int i = 0; i < dataTable.xbsl; i++) {
            float x = dataTable.CeTemp[i].coord.X + SmallMapX + 94;
            float y = dataTable.CeTemp[i].coord.Y + SmallMapY + 7;
            ImGui::GetForegroundDrawList()->AddRect(ImVec2((float)x - soldiers_dx, (float)y - soldiers_dx), ImVec2((float)x + soldiers_dx, (float)y + soldiers_dx), Paint_red, soldiers_dx, 0, soldiers_dx * 2);
        
    }
    }





    if (ESPMenu.是否开启共享) {
        gameDataStr = "gameData" + 设备id + "[==][==]" + character + "---" + creeps + "---" + soldier;
        char* gameData = (char*)gameDataStr.data();  //设备
        send(socket_fd, gameData, strlen(gameData), 0);
    }

  }else{

    //当前时间戳
    time_t 当前时间;
    time(&当前时间);
		//printf("当前 %ld\t到期 %ld\n", 当前时间, 到期时间);



    // 获取当前时间
                    auto now = std::chrono::system_clock::now();
                    auto now_c = std::chrono::system_clock::to_time_t(now);
                    std::stringstream ss;
                    ss << std::put_time(std::localtime(&now_c), "%m月%d日 %H:%M:%S");
                    
                    // 添加时间信息到文本中
                    std::string text = "Best等待进入对局";
                    text += ss.str();
                    const char* cstr = text.c_str();
    //
    ImVec2 字体尺寸 = ImGui::CalcTextSize(cstr);
    
    绘制字体描边(30.0f + yxpx / 1000,
        ImVec2(0.0375 * yxpx, 0.98 * yxpy - 字体尺寸.y),
        ImColor(0, 0, 255), cstr);
  } 


 
}
