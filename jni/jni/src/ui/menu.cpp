// ============================================================
// menu.cpp - ImGui 菜单模块 (tick 函数)
// ============================================================
#include "globals.h"
#include "../config/Paths.h"
#include "obfuscate.h"
#include "oxorany.h"
#include "memory/driver.h"
#include "memory/driver.h"
#include "config/offsets.h"
#include "game/GameManager.h"

static bool 一键开关 = false;
static int style_idx = 1;
static int 录屏时长 = 20;
static std::atomic<bool> isRecording(false);
static std::atomic<int> recordingTimeElapsed(0);
static float FOVT;
static float FOVTB;
static bool active = false;
static char s[64];

// ---- tick ----
void tick() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(init_screen_x,init_screen_y);
    ImGui::NewFrame();
    Colors::Text = ImColor(100,103,108,255);
    Colors::TextActive = ImColor(41,44,49,255);
    Colors::TextActiveNew = ImColor(255,255,255);
    Colors::TextNew = ImColor(255,255,255);
    Colors::FrameHovered = ImColor(255,255,255,255);
    Colors::FrameOpened = ImColor(255,255,255,255);
    static int 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 = 1;
    static int 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕 = 1;
    ImGui::SetNextWindowSize(ImVec2(500,560));
    ImGuiStyle& style = ImGui::GetStyle();
    if (FloatingBall)
  {
 /*   ImGui::SetNextWindowSize({120, 120});
    
    style.Colors[ImGuiCol_WindowBg].w = 0;
    if (ImGui::Begin("悬浮图片", &FloatingBall, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
    {
    
        
         
     
      if (WindowState) {
        ImGui::SetWindowPos(Pos);
        WindowState = false;
      }
      Pos = ImGui::GetWindowPos();
      ImDrawList* Draw = ImGui::GetWindowDrawList();

      DrawLogo(Pos.x + 62, Pos.y + 52, 60.f);


      static bool isDragging = false;
      if (ImGui::IsMouseDragging(0) && ImGui::IsWindowHovered())
      {
        isDragging = true;
      }
      if (ImGui::IsMouseReleased(0) && !ImGui::IsMouseDragging(0) && !isDragging && ImGui::IsWindowHovered())
      {
        FloatingBall = false;
        FloatingWindow = true;
        WindowState = true;
      }
      if (!ImGui::IsMouseDragging(0))
      {
        isDragging = false;
      }
      
    }
    ImGui::End();*/
  }
  style.Colors[ImGuiCol_WindowBg].w = 1;
 // style.Alpha = 1.f;
               /* if (ImGui::Begin(OBFUSCATE("IMGUI_GOD LOGIN" ), nullptr,ImGuiWindowFlags_AlwaysAutoResize |  ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings)) {
                static bool isLogin = false;
                if (!isLogin) {
                const ImVec2 pos = ImGui::GetWindowPos();
                ImDrawList* draw = ImGui::GetWindowDrawList();
                draw->AddRectFilled(ImVec2(pos.x + 8, pos.y + 8), ImVec2(pos.x + 492, pos.y + 552), ImColor(0, 0, 0,255), 10.f,ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight | ImDrawFlags_RoundCornersTopRight);
                draw->AddRectFilled(ImVec2(pos.x + 13, pos.y + 13), ImVec2(pos.x + 487, pos.y + 547), ImColor(40, 40, 40, 255), 8.5f,ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight | ImDrawFlags_RoundCornersTopRight);
                draw->AddRectFilled(ImVec2(pos.x + 30, pos.y + 160), ImVec2(pos.x + 470, pos.y + 220), ImColor(0, 0, 0, 255), 10.f,ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight | ImDrawFlags_RoundCornersTopRight);
                draw->AddText(F50, 40.f, ImVec2(pos.x + 55, pos.y + 50), ImColor(255, 255, 255, 255), oxorany("WIDGETS EXPERT"));    
                ImGui::SetCursorPos(ImVec2(70, 174));
                ImGui::InputTextWithHint("##key","YOUR KEY.........", s, sizeof s);
                ImGui::SetCursorPos(ImVec2(30, 235));
                if(ImGui::OptButton1("     PASTE YOUR KEY   ", ImVec2(440, 60), false)){
                }           
                ImGui::SetCursorPos(ImVec2(100, 315));
                static std::string err;
                if (ImGui::OptButton1(" LOGIN", ImVec2(300, 60), false)) {
                isLogin = true;
                }
                } else{*/
					
//===============================================| 𝗙𝗟𝗢𝗧𝗜𝗡𝗚 𝗟𝗢𝗚𝗢  |======================≠=================//
					/*static bool show;           
        			ImGui::SetNextWindowSize({ 200, 200 });
        			ImGui::Begin("ICON BUTTON", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus);
        			//ImGui::Begin("ICON BUTTON", nullptr, ImGuiWindowFlags_NoDecoration); {
					const ImVec2 pos = ImGui::GetWindowPos();
        			ImDrawList* draw = ImGui::GetWindowDrawList();
					draw->AddRectFilled(ImVec2(pos.x + 50, pos.y + 50), ImVec2(pos.x + 150, pos.y + 150), ImColor(230, 233, 238, 255), 10.f,ImDrawFlags_RoundCornersAll );
					draw->AddText(F50, 35.f, ImVec2(70 + pos.x, 70 + pos.y), ImColor(41, 44, 49, 255), oxorany("GM"));    			 
				    draw->AddText(Subtab, 20.f, ImVec2(46 + pos.x, 106 + pos.y), ImColor(0, 0, 255, 255), oxorany("    GTX"));    			 
				    draw->AddText(Subtab, 20.f, ImVec2(46 + pos.x, 106 + pos.y), ImColor(41, 44, 49, 255), oxorany("              MOD"));
					ImGui::SetCursorPos({ 70, 70});
					if(ImGui::WIDGETS_EXPERT_Open("         ", ImVec2(60, 60), false)){
        			show = true;
					}*/
//===================================| 𝗠𝗔𝗜𝗡 𝗜𝗠𝗚𝗨𝗜 𝗠𝗘𝗡𝗨 |≠=======================//
				if(FloatingWindow){
        		ImGui::SetNextWindowSize( ImVec2(1070 , 690) );
        		ImGui::MainBegin( "WIDGETS_EXPERT MENU", nullptr, ImGuiWindowFlags_::ImGuiWindowFlags_NoDecoration |  ImGuiWindowFlags_NoBackground);
        		{
				ImVec2 P1, P2;
        		ImDrawList* pDrawList;
        		const auto& p = ImGui::GetWindowPos();
        		const auto& pWindowDrawList = ImGui::GetWindowDrawList();
        		const auto& pBackgroundDrawList = ImGui::GetBackgroundDrawList();
        		const auto& pForegroundDrawList = ImGui::GetForegroundDrawList();
        		const ImVec2 pos = ImGui::GetWindowPos();
        		ImDrawList* draw = ImGui::GetWindowDrawList();
                //======𝗠𝗘𝗡𝗨 𝗕𝗔𝗖𝗞𝗚𝗥𝗢𝗨𝗡𝗗
				pBackgroundDrawList->AddRectFilled(ImVec2(5.000f + p.x, 5.000f + p.y), ImVec2(1065 + p.x, 685 + p.y), ImColor(170,173,179,255), 15); 
				draw->AddRectFilled(ImVec2(pos.x + 5, pos.y + 5), ImVec2(pos.x + 320, pos.y + 685), ImColor(220, 223, 228, 255), 15.f,ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight | ImDrawFlags_RoundCornersTopRight);
	  			draw->AddRectFilled(ImVec2(pos.x + 335, pos.y + 25), ImVec2(pos.x + 1048, pos.y + 100), ImColor(220, 223, 228, 255), 10.f,ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight | ImDrawFlags_RoundCornersTopRight);
                //=======𝗧𝗜𝗠𝗘 𝗔𝗡𝗗 𝗗𝗔𝗧𝗘 𝗙𝗨𝗡𝗖𝗧𝗜𝗢𝗡
				time_t lt;
    			struct tm *t_m;
    			lt = time(NULL);
    			t_m = localtime(&lt);
				int time_y = t_m->tm_year;
    			int time_mn = t_m->tm_mon;
    			int time_d = t_m->tm_mday;
	    		int time_h = t_m->tm_hour;
    			int time_m = t_m->tm_min;
    			int time_s = t_m->tm_sec;
				std::string time;
				if (time_h < 10)
                time += "0";
    			time += std::to_string(time_h) + "::";
				if (time_m < 10)
        		time += "0";
    			time += std::to_string(time_m) + "::";
				if (time_s < 10)
        		time += "0";
    			time += std::to_string(time_s);
				draw->AddText(NULL,25.0f,ImVec2(pos.x + 48, pos.y + 493), IM_COL32(41, 44, 49, 255), time.c_str());
				draw->AddText(NULL,25.0f,ImVec2(pos.x + 152, pos.y + 493), IM_COL32(0, 0, 0, 255), "||");
				std::string date;
				date += std::to_string(time_d) + "-";
				date += std::to_string(time_mn + 1) + "-";
				date += std::to_string(1900+time_y) ;
				draw->AddText(NULL,25.0f,ImVec2(pos.x + 180, pos.y + 493), IM_COL32(41, 44, 49, 255), date.c_str());
                //==============𝗟𝗜𝗡𝗞𝗦 𝗢𝗙 𝗧𝗘𝗟𝗘𝗚𝗥𝗔𝗠 𝗬𝗢𝗨𝗧𝗨𝗕𝗘 𝗔𝗡𝗗 𝗗𝗜𝗦𝗖𝗢𝗥𝗗
                 ImGui::SetCursorPos({ 45, 605});
                 /*if(ImGui::WIDGETS_EXPERT_Open(" ", ImVec2(45, 40), true)){
                 //OpenURL("https://t.me/IMGUI_WIDGETS"); }	
                 ImGui::SetCursorPos({ 145, 606});
                 if(ImGui::WIDGETS_EXPERT_Open("             ", ImVec2(40, 40), true)){
                 //OpenURL("https://youtube.com/@NarendraModi"); }	
                 ImGui::SetCursorPos({ 245, 607});
                 if(ImGui::WIDGETS_EXPERT_Open("   ", ImVec2(40, 40), true)){*/
                // OpenURL("https://discord.com/widgetsexpert"); }	
                //===========✍️✍️𝗢𝗧𝗛𝗘𝗥 𝗗𝗥𝗔𝗪𝗜𝗡𝗚 𝗔𝗡𝗗 𝗜𝗖𝗢𝗡𝗦
                //===========🤫🤫𝗗𝗢𝗡𝗧 𝗖𝗛𝗔𝗡𝗚𝗘 𝗣𝗢𝗦𝗜𝗧𝗜𝗢𝗡𝗦 .....𝗢𝗡𝗟𝗬 𝗖𝗛𝗔𝗡𝗚𝗘 𝗖𝗢𝗟𝗢𝗥𝗦 𝗜𝗙 𝗬𝗢𝗨 𝗪𝗔𝗡𝗧
											draw->AddRect( ImVec2(pos.x + 30, pos.y + 485), ImVec2(pos.x + 295, pos.y + 580), ImColor(41,44,49), 10.0f, ImDrawFlags_RoundCornersAll, 5.0f);
											draw->AddRectFilled( ImVec2(pos.x + 31, pos.y + 530), ImVec2(pos.x + 294, pos.y + 535), ImColor(41,44,49), 0.0f);
											draw->AddText(Social,25.0f,ImVec2(pos.x + 40, pos.y + 541), IM_COL32(41, 44, 49, 255), "U");
											draw->AddText(NULL,25.0f,ImVec2(pos.x + 76, pos.y + 545), IM_COL32(41, 44, 49, 255), "@BingYiBest666");
											draw->AddText(F86, 70.f, ImVec2(45 + p.x, 30 + p.y), ImColor(0, 0, 0, 255), oxorany("BYNB\nbest"));    			 
											draw->AddRectFilled( ImVec2(pos.x + 50, pos.y + 177.5), ImVec2(pos.x + 270, pos.y + 182.5), ImColor(41,44,49), 100.0f);
											draw->AddRectFilled( ImVec2(pos.x + 35, pos.y + 595), ImVec2(pos.x + 95, pos.y + 655), ImColor(3,169,245), 100.0f);
											draw->AddRectFilled( ImVec2(pos.x + 135 - 2.5, pos.y + 595), ImVec2(pos.x + 195 - 2.5, pos.y + 655), ImColor(0,0,0), 100.0f);
											draw->AddRectFilled( ImVec2(pos.x + 235 - 5, pos.y + 595), ImVec2(pos.x + 295 - 5, pos.y + 655), ImColor(54,40,169), 100.0f);
											draw->AddText(Social,40.0f,ImVec2(pos.x + 45 - 1.5, pos.y + 605), IM_COL32(255, 255, 255, 255), "V");//=====𝗧𝗘𝗟𝗘𝗚𝗥𝗔𝗠
											draw->AddText(Social,40.0f,ImVec2(pos.x + 145 - 2.5, pos.y + 605), IM_COL32(245, 0, 0, 255), "W");//====𝗬𝗢𝗨𝗧𝗨𝗕𝗘
											draw->AddText(Social,40.0f,ImVec2(pos.x + 245 - 5, pos.y + 605), IM_COL32(255, 255, 255, 255), "F");//===𝗗𝗜𝗦𝗖𝗢𝗥𝗗
				//====================𝗜𝗠𝗚𝗨𝗜 𝗧𝗔𝗕 𝗕𝗨𝗧𝗧𝗢𝗡𝗦
            	ImGui::SetCursorPos(ImVec2(30,200));
            	//ImGui::SetCursorPos(ImVec2(30,200));
            	ImGui::BeginGroup();{ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 0, 9 });
				if (ImGui::WIDGETS_EXPERT_Tab("y","主页菜单", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 != 1)) { 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 = 1; active = true; }
        		if (ImGui::WIDGETS_EXPERT_Tab("D","功能菜单", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 != 2)) { 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 = 2; active = true; }
        		if (ImGui::WIDGETS_EXPERT_Tab("F","配置调节", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 != 3)) { 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 = 3; active = true; }
        		if(ImGui::WIDGETS_EXPERT_Close("i","关闭悬浮窗", ImVec2(80, 80), true)){FloatingBall = true;FloatingWindow = false; WindowState = true;}	
        		ImGui::PopStyleVar();}ImGui::EndGroup( );
//===============================================| 𝗧𝗔𝗕 𝗢𝗡𝗘  |======================≠=================//
											ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 14, 7 });
											if (𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 == 1){
											static int 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  = 4;
											ImGui::SetCursorPos(ImVec2(347.5,37.5));ImGui::BeginGroup();{     
											if (ImGui::WIDGETS_EXPERT_Subtab("Best", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  != 4)) { 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  = 4; active = true; }ImGui::SameLine();
											ImGui::PopStyleVar();}ImGui::EndGroup( );
											
											if (𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  == 4){
											ImGui::SetCursorPos( ImVec2( 335, 155 ) );
                							ImGui::MenuChild( "主页面板", ImVec2(700, 530) );{
                								ImGui::Text("设备分辨率: %dx%d", screen_x, screen_y);
                                            ImGui::Text("ImGui: %0.2fFPS %0.2fms", ImGui::GetIO().Framerate, 1000.0f / ImGui::GetIO().Framerate);
                                            ImGui::Text("更新tg频道@BingYiBest666");
                                            
								        	
											
                                                ImGui::Text("游戏进程: %d", pid);
                                                                         
                                                            if(IsProcModInit)
            {
           // if (ImGui::Button("成功获取进程与模块",{-1,75}))   
            if (ImGui::OptButton1("初始化", ImVec2(-1, 75), false))
            { 
            GM.Init();
            }
            }else{
            //if (ImGui::Button("未获取进程与模块",{-1,75}))   
             if (ImGui::OptButton1("初始化", ImVec2(-1, 75), false))
            {    
            GM.Init();
            IsProcModInit = true;
            }
            }
            
            if (ImGui::OptButton1("退出程序", ImVec2(-1, 75), false))
            {
            exit(0);
            }
  
      
       
               
            
            
                                            
											}//3
											}//2
											}//1
//=============================================| 𝗧𝗔𝗕 𝗧𝗪𝗢 |===================================================================================//





if (𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗 == 2){
static int 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  = 1;
											ImGui::SetCursorPos(ImVec2(347.5,37.5));ImGui::BeginGroup();{     
											if (ImGui::WIDGETS_EXPERT_Subtab("绘图", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  != 1)) { 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  = 1; active = true; }ImGui::SameLine();
											if (ImGui::WIDGETS_EXPERT_Subtab("共享", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  != 2)) { 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  = 2; active = true; }ImGui::SameLine();
											if (ImGui::WIDGETS_EXPERT_Subtab("卡密与录制", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  != 3)) { 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  = 3; active = true; }ImGui::SameLine();
										//	if (ImGui::WIDGETS_EXPERT_Subtab("退出", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕 != 4)) { exit(0);}
ImGui::PopStyleVar();}ImGui::EndGroup( );


//=====𝗦𝗨𝗕𝗧𝗔𝗕 𝗢𝗡𝗘
if (𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  == 1){
								        	ImGui::SetCursorPos( ImVec2( 335, 155 ) );
                							ImGui::MenuChild( "绘图", ImVec2(350, 355) );{
                							
                							  ImGui::SliderFloat("上帝视角", &GodMode,0,3,"%.2f",1);
                							  ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("视距开关", &GodView);
										
                							          if(IsDrawing==0){
            if (ImGui::OptButton1("一键开启", ImVec2(-1, 75), false))
           {
           
           IsDrawing=1;ShowHealth=1;ShowMap=1;ShowLine=1;ShowBox=1;ShowJungle=1;ShowMinions=1;ShowSkillBox=1;ShowTopSkill=1;ShowJungleHealth=1;BoxSkill=1;ShowHeadBox=1;ShowRecall=1;SkillTrap=1;
           }
          }else{
          if (ImGui::OptButton1("一键关闭", ImVec2(-1, 75), false))
          {
          IsDrawing=0;ShowHealth=0;ShowMap=0;ShowLine=0;ShowBox=0;ShowJungle=0;ShowMinions=0;ShowSkillBox=0;ShowTopSkill=0;ShowJungleHealth=0;BoxSkill=0;ShowHeadBox=0;ShowRecall=0;SkillTrap=0;
          }
          }
          

          
               if (ImGui::OptButton1("截图", ImVec2(-1, 75), false))
          	 {
          	 system("su -c screencap -p /sdcard/截屏.jpg");
          	 }
               
                    
                    
           
                							}ImGui::EndChild( );
                							
ImGui::SetCursorPos( ImVec2( 335, 565 ) );
ImGui::MenuChild( "技能", ImVec2(350, 110) );{
ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("技陷", &SkillTrap);
ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("方框技能", &ShowSkillBox);
	ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("顶上技能", &ShowTopSkill);
}ImGui::EndChild( );

                							ImGui::SetCursorPos( ImVec2( 700, 155 ) );
                							ImGui::MenuChild( "选项", ImVec2( 350, 520) );{
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("血量", &ShowHealth);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
											ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("地图", &ShowMap);
											ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("射线", &ShowLine);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("方框", &ShowBox);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("野怪", &ShowJungle);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("兵线", &ShowMinions);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("眼位", &ShowWards);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("框技", &BoxSkill);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("框头", &ShowHeadBox);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("回城", &ShowRecall);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							
                						
                							
											}ImGui::EndChild( );
										
												
												}
//========𝗦𝗨𝗕𝗧𝗔𝗕 𝗧𝗪𝗢
if (𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  == 2){
												ImGui::SetCursorPos( ImVec2( 335, 155 ) );
                								ImGui::MenuChild( "屏幕", ImVec2(350, 60) );{
												ImGui::Text("设备分辨率: %dx%d", screen_x, screen_y);
												}ImGui::EndChild( );
ImGui::SetCursorPos( ImVec2( 335, 265 ) );
ImGui::MenuChild( "共享", ImVec2(350, 190) );{
          /* if(共享==false){
            if (ImGui::OptButton1("一键开启共享", ImVec2(-1, 75), false))
           {
        ESPMenu.显示头像 = true;
        ESPMenu.野怪计时 = true;
        ESPMenu.显示兵线 = true;
        ESPMenu.是否开启共享 = true;
        共享=true;
           }
          }else{
          if (ImGui::OptButton1("一键关闭共享", ImVec2(-1, 75), false))
          {
          ESPMenu.显示头像 = false;
        ESPMenu.野怪计时 = false;
        ESPMenu.显示兵线 = false;
        ESPMenu.是否开启共享 = false;
        共享=false;
          }
          }*/

}ImGui::EndChild( );
												ImGui::SetCursorPos( ImVec2( 335, 505 ) );
                								ImGui::MenuChild( "共享公告/共享功能暂时关闭", ImVec2(350, 170) );{
                						/*		ImGui::BulletText("您的共享房间号:%s",imei);
                                                ImGui::BulletText("网址网页:38.55.232.191");*/
                								
											//	ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("雷达图", &a);
												//ImGui::SliderInt("雷达.X", &Config.RadarX, 1.7500f, 10.0f);
											//	ImGui::SliderInt("雷达Y", &Config.RadarY, 2.2f, 100.0f);
												}ImGui::EndChild( );
												
												
                                            ImGui::SetCursorPos( ImVec2( 700, 155 ) );
                                            ImGui::MenuChild( "共享选项", ImVec2( 335, 520 ) );{
                                            ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("开启共享", &ESPMenu.IsSharedOpen);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                                            ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("头像显示", &ESPMenu.ShowAvatar);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("野怪计时", &ESPMenu.JungleTimer);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							ImGui::𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗("兵线显示", &ESPMenu.ShowMinions);
                							ImGui::Separator();
                							ImGui::ItemSize(ImVec2(0, 2));
                							
}ImGui::EndChild( );
}

if (𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  == 3){

ImGui::SetCursorPos( ImVec2( 335, 155 ) );
                                                ImGui::MenuChild( "录屏", ImVec2(350, 330) );{
                                                ImGui::SliderInt("自定义录制秒数", &录屏时长, 1, 360);
										if (ImGui::OptButton1("开始录制", ImVec2(-1, 75), false))
											 {
											if (!isRecording.load()) {
											isRecording.store(true);
											recordingTimeElapsed.store(0); // 开始时重置时间
											std::thread([](int 录屏时长) {
											// 非阻塞式开始录制
											std::string command = "screenrecord --time-limit " + std::to_string(录屏时长) + " /sdcard/Best录制.mp4 &";
											system(command.c_str());

											for (int i = 0; i < 录屏时长 && isRecording.load(); ++i) {
											std::this_thread::sleep_for(std::chrono::seconds(1));
											recordingTimeElapsed.fetch_add(1);
											}

											isRecording.store(false);
											}, 录屏时长).detach();
											}
											}
											if ((ImGui::OptButton1("关闭录制", ImVec2(-1, 75), false)) && isRecording.load()) {
											system("pkill -l SIGINT screenrecord");
											isRecording.store(false);
											}
				                       
                                                }ImGui::EndChild( );
                                                
ImGui::SetCursorPos( ImVec2( 700, 155 ) );
ImGui::MenuChild( "卡密配置", ImVec2(350, 230) );{
ImGui::BulletText("卡密: %s", fileContent2.c_str());
ImGui::BulletText("设备码: %s", fileContent1.c_str());
ImGui::BulletText("卡密到期时间: %s", fileContent3.c_str());
}ImGui::EndChild( );
                                                ImGui::SetCursorPos( ImVec2( 335, 535 ) );
                                                ImGui::MenuChild( "2", ImVec2(350, 140) );{
                                               
                                                }ImGui::EndChild( );
ImGui::SetCursorPos( ImVec2( 700, 435) );
ImGui::MenuChild( "3", ImVec2(350, 240) );{

}ImGui::EndChild( );


}ImGui::EndChild( );

}


//================𝗦𝗨𝗕𝗧𝗔𝗕 𝗧𝗛𝗥𝗘𝗘
//ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 14, 7 });
if (𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗  == 3){
static int 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  = 5;
ImGui::SetCursorPos(ImVec2(347.5,37.5));ImGui::BeginGroup();{     
			if (ImGui::WIDGETS_EXPERT_Subtab("绘图调整", 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  != 5)) { 𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  = 4; active = true; }ImGui::SameLine();
			ImGui::PopStyleVar();}ImGui::EndGroup( );
			if (𝗜𝗠𝗚𝗨𝗜_𝗚𝗢𝗗_𝗦𝗨𝗕𝗧𝗔𝗕  == 5){
											ImGui::SetCursorPos( ImVec2( 335, 155 ) );
											ImGui::MenuChild( "绘图调整", ImVec2(350, 520) );{
										
											
   if(ImGui::SliderInt("头像X", &SmallMapX,-300,300,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", SmallMapX);
        WriteFile(oxorany(PATH_CONF_SMX),urlls);}
        if(ImGui::SliderInt("头像Y", &SmallMapY,-300,300,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", SmallMapY);
        
        WriteFile(oxorany(PATH_CONF_SMY),urlls);}
                      if(ImGui::SliderInt("实体X", &SmallHPX,-300,300,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", SmallHPX);
        
        WriteFile(oxorany(PATH_CONF_SHX),urlls);}
                      if(ImGui::SliderInt("实体Y", &SmallHPY,-300,300,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", SmallHPY);
        
        WriteFile(oxorany(PATH_CONF_SHY),urlls);}
                      
                      
       if(ImGui::SliderInt("技能左右", &SkillSlotX,-2000,2000,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", SkillSlotX);
        
        WriteFile(oxorany(PATH_CONF_SSX),urlls);}
        
        if(ImGui::SliderInt("技能上下", &SkillSlotY,-500,500,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", SkillSlotY);
        
        WriteFile(oxorany(PATH_CONF_SSY),urlls);}
        
        
      if(ImGui::SliderInt("头像大小", &IconSize,-50,50,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", IconSize);
        
        WriteFile(oxorany(PATH_CONF_ICS),urlls);}
      if(ImGui::SliderInt("血量大小", &MinimapHealthSize,-50,50,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", MinimapHealthSize);
        
        WriteFile(oxorany(PATH_CONF_MHS),urlls);}
      if(ImGui::SliderInt("头像间隔", &Spacing,-100,100,"%.0f",2)){char urlls[2560];
        sprintf(urlls, "%d", Spacing);
        
        WriteFile(oxorany(PATH_CONF_SPC),urlls);}
											
											
                							
												}ImGui::EndChild( );
												
												

                                            ImGui::SetCursorPos( ImVec2( 700, 155 ) );
                							ImGui::MenuChild( "共享调整", ImVec2( 350, 520) );{
                								if(ImGui::SliderInt("共享左右调整", &ESPMenu.MinimapAdjX,-150,300)){char urlls[2560];
        sprintf(urlls, "%d", ESPMenu.MinimapAdjX);
        WriteFile(oxorany(PATH_CONF_SAX),urlls);}
        	if(ImGui::SliderInt("共享上下调整", &ESPMenu.MinimapAdjY,-200,200)){char urlls[2560];
        sprintf(urlls, "%d", ESPMenu.MinimapAdjY);
        WriteFile(oxorany(PATH_CONF_SAY),urlls);}
        if(ImGui::SliderInt("共享野怪左右调整", &ESPMenu.JungleAdjX,-200,200)){char urlls[2560];
        sprintf(urlls, "%d", ESPMenu.JungleAdjX);
        WriteFile(oxorany(PATH_CONF_JAX),urlls);}
                if(ImGui::SliderInt("共享野怪上下调整", &ESPMenu.JungleAdjY,-200,200)){char urlls[2560];
        sprintf(urlls, "%d", ESPMenu.JungleAdjY);
        WriteFile(oxorany(PATH_CONF_JAY),urlls);}
                if(ImGui::SliderInt("共享兵线左右调整", &ESPMenu.MinionAdjX,-200,200)){char urlls[2560];
        sprintf(urlls, "%d", ESPMenu.MinionAdjX);
        WriteFile(oxorany(PATH_CONF_MAX),urlls);}
                if(ImGui::SliderInt("共享分辨率x调整", &ESPMenu.ResolutionX,1000,4000)){char urlls[2560];
        sprintf(urlls, "%d", ESPMenu.ResolutionX);
        WriteFile(oxorany(PATH_CONF_RSX),urlls);}
                							
                							
                						
                							
											}ImGui::EndChild( );
												
											
												
												}
												}
												
//=============================================| 𝗧𝗔𝗕 𝗧𝗪𝗢 |===================================================================================//


//=============================================| 𝗧𝗔𝗕 𝗧𝗛𝗥𝗘𝗘 |========================================================================================//

                }
                }
                //}
				//}
                ImGui::End();
                GM.UpdateAndDraw();
                ImGuiIO &io = ImGui::GetIO();
                glViewport(0.0f, 0.0f, (int) io.DisplaySize.x, (int) io.DisplaySize.y);
                glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
                glClear(GL_COLOR_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT
                glFlush();
                if (display == EGL_NO_DISPLAY) {
                    return;
                }
                 
                
                ImGui::Render();
                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
                eglSwapBuffers(display, surface);
                }

