#ifndef 结构体
#define 结构体
#include <string>
#include <iostream>
#include <string.h>
#include <cstdio>
#include <malloc.h>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <sys/system_properties.h>
#define PI 3.14159265358979323846
long  int code_sock = -64649191801064646;
char mm[128];
std::string km;
float 范围=250;
ImFont *imFont;
float WorldDistance;
static int 方向 = 0;
static int AimCount = 0;
float 平滑力度 = 15;
float 压枪系数 = 18;
float 绘图宽,绘图高;

float shangdi=0.1f;//上帝高度

float NumIo[50];
bool DrawIo[50];
//王者荣耀
//
bool 进程与模块 = false;

//
int yxpx, yxpy, fenblxx = 0;
uintptr_t libbase;
long int libbase3;
long int libbase2;
#include "IsCharacter.h"
#define BYTE4 0x00000004
#define BYTE8 0x00000008
#define BYTE16 0x00000010
#define BYTE10 0x000000A
#define BYTE64 0x00000040
#define BYTE1024 0x00000400
uintptr_t unity;
uintptr_t unitybss;
uintptr_t GameCore;
uintptr_t GameCorebss;
uintptr_t il2cpp;
uintptr_t il2cppbss;
static uint64_t lil2cpp_base = 0;
static uint64_t libGame_base = 0;
static uint64_t libunity_base = 0;
static uint64_t lil2cpp_basebss = 0;
static uint64_t libGame_basebss = 0;
static uint64_t libunity_basebss = 0;
static uint64_t libtersafe_base = 0;
uint64_t MatrixAddress = 0;//初始化矩阵地址
float isGames;//储存矩阵的值
int foeComp;//敌方阵营
int rientation = 0;//对局方向
int AroundNumbers = 0;//人头数量

float hp1;
float aa;//计算和判断血量
float pos_y;//初始化裁剪坐标
float pos_x;
float myx, myy;//临时坐标
//绘制米数
char meter1[1000];
float meter;
//实时获取裁剪坐标
float my_pos_y;
float my_pos_x;
//int 视野;
int huitu=0;//绘图启动
//人物绘制
 bool 血量 = false;
 bool 地图 = false;
// bool 特权 = false;
 bool 方框 = false;
 bool 自瞄 = false;
 bool 射线 = false;
 bool 距离 = false;
 bool 野怪 = false;
 bool 兵线 = false;
 bool 方框技能 = false;
 bool 顶上技能 = false;
 bool 上帝 = false;
 bool 眼位 = false;
 bool 龙触摸 = false;
 bool buff触摸 = false;
 bool 野血 = false;
 bool 框技 = false;
 bool 回城 = false;
 bool 框头 = false;
 bool 技陷 = false;
 bool 斩杀 = false;
 bool 惩戒 = false;
 bool 解密 = false;
 bool 自身判断 = false;
 /*地图参数调试
 地图小地图
 小地图参数*/
 int touxiangdaxiao = 0;//头像大小
 int xiaodituxue = 7;//小地图血量大小 k60那个血圈大小
 int jiange = -1;//小地图间隔
 int SmallMapX = 75;
 int SmallMapY = 2; //小地图头像位置
 int BuffMapX = 0; //buff
 int BuffMapY = 0;
 int SmallSoldiX = 0; //兵线
 int SmallSoldiY = 0;
 int SmallHPX = 9;
 int SmallHPY = 34; //小地图血条位置
 int jinenglanz = 0;//技能栏左右
 int jinenglanzX = 0;//技能栏左右
 int jinenglanzY = 0;//技能栏左右

 /*开始王者结构体定义
 结构体
 王者 
 最下面是结构体*/

//王者共享内容

//共享菜单全部   
int pxx = 0, pyy = 0; double WwrShare = 0.0;//临时分辨率
bool 初始化 = false;
bool Touchinit = true;
int Screen_X, Screen_Y;
int xytable[10][10];
int hist1[10][10];
int me1 = 0;
//float ax, ay;
int prex1, prey1;
long a, objarrayaddr, libGameCore1, libil2cpp1, 兵线基址, 人物数组, 野怪数组, 兵线数组, 矩阵;
int 阵营1 = 0, fx1 = 0;


struct sESPMenu {
    bool 绘制调试 = false;
    bool 全部关闭;
    bool 是否开启共享;
    bool 全部开启;
    bool 显示头像;
    bool 保存调试配置到云端;
    bool 技能计时;
    bool 野怪计时;
    bool 显示兵线;
    bool 回城判断;
    bool 敌人视野;
    int 分辨率Y = 2456;//2712  
    int 分辨率X = 2456;//1220  2846

    int 小地图左右调整 = -7;//我的配置87   -3
    int 小地图上下调整 = -4;//   -4
    int 兵线左右调整 = 9;//我的配置6
    int 兵线上下调整 = -27;//31
    int 野怪左右调整 = -9;//我的配置-6
    int 野怪上下调整 = -5;//-1
    int FPS帧率 = 144;

};
sESPMenu ESPMenu;


//--------按钮颜色
ImU32 c_透明=IM_COL32(0, 0, 0, 0);
ImU32 c_黑色透明50=IM_COL32(0, 0, 0, 50);
ImU32 c_黑色透明100=IM_COL32(0, 0, 0, 100);
ImU32 c_黑色透明128=IM_COL32(0, 0, 0, 128);
ImU32 c_白色透明50=IM_COL32(255, 255, 255, 50);
ImU32 c_白色透明128=IM_COL32(255, 255, 255, 128);
ImU32 c_白色透明150=IM_COL32(255, 255, 255, 150);
ImU32 c_fafafa=IM_COL32(250, 250, 250, 255);
ImU32 c_cccccc=IM_COL32(204, 204, 204, 255);
ImU32 c_c2c2c2 = IM_COL32(194, 194, 194, 255);
ImU32 c_23292e=IM_COL32(35, 41, 46, 255);
ImU32 c_4023292e=IM_COL32(35, 41, 46, 125);
ImU32 c_2f363c=IM_COL32(47, 54, 60, 255);
ImU32 c_402f363c=IM_COL32(47, 54, 60, 125);
ImU32 c_DAB123 = IM_COL32(218, 177, 35, 255);
ImU32 c_DCD4CA = IM_COL32(220, 212, 202, 255);
ImU32 c_2C88E2 = IM_COL32(44, 136, 226, 255);
ImU32 c_2C88E240 = IM_COL32(44, 136, 226, 128);
ImU32 c_545D6D = IM_COL32(84, 93, 109, 255);
ImU32 c_545D6D40 = IM_COL32(84, 93, 109, 128);
ImU32 c_81A4DC = IM_COL32(0x81, 0xa4, 0xdc, 255);
ImU32 c_FFD49F = IM_COL32(255, 212, 159, 255);
ImU32 c_FFD49F80 = IM_COL32(255, 212, 159, 128);
ImU32 c_16b777 = IM_COL32(0x16, 0xB7, 0x77, 255);
ImU32 c_16b77780 = IM_COL32(0x16, 0xB7, 0x77, 128);
ImU32 c_16b77710 = IM_COL32(0x16, 0xB7, 0x77, 50);
ImU32 c_11243B = IM_COL32(0x11, 0x24, 0x3B, 255);
ImU32 c_11243B80 = IM_COL32(0x11, 0x24, 0x3B, 128);
ImU32 c_558FFD = IM_COL32(0x55, 0x8F, 0xFD, 255);
ImU32 c_9A88FE = IM_COL32(0x9a, 0x88, 0xFe, 255);
ImU32 c_ffb800 = IM_COL32(0xff, 0xb8, 0x00, 255);
ImU32 c_ffb80080 = IM_COL32(0xff, 0xb8, 0x00, 128);
ImU32 c_ff5722 = IM_COL32(0xff, 0x57, 0x22, 255);
ImU32 c_ff572280 = IM_COL32(0xff, 0x57, 0x22, 128);
ImU32 c_ff572210 = IM_COL32(0xff, 0x57, 0x22, 50);
ImVec4 透明ImVec4 = ImVec4(0, 0, 0, 0);
ImVec4 白色ImVec4 = ImVec4(1,1,1,1);
ImVec4 黑色ImVec4 = ImVec4(0, 0, 0, 1.0f);
ImVec4 灰色ImVec4 = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
ImVec4 灰色ImVec440 = ImVec4(0.1f, 0.1f, 0.1f, 0.5f);
ImVec4 灰色ImVec480 = ImVec4(0.1f, 0.1f, 0.1f, 0.75f);
ImVec4 亮灰色ImVec4 = ImVec4(0.5, 0.5, 0.5, 1);
ImVec4 亮黄色ImVec4 = ImVec4(1.0f, 0.831f, 0.623f, 1.0f);
ImVec4 半透明黑色ImVec4 = ImVec4(0.184314f, 0.211765f, 0.235294f, 0.5f);
ImVec4 半透明黑色ImVec480 = ImVec4(0.184314f, 0.211765f, 0.235294f, 0.75f);
ImVec4 ImVec423292e = ImVec4(0.137255f, 0.160784f, 0.180392f, 1.0f);
ImVec4 ImVec80423292e = ImVec4(0.137255f, 0.160784f, 0.180392f, 0.75f);
ImVec4 ImVec40423292e = ImVec4(0.137255f, 0.160784f, 0.180392f, 0.5f);
ImVec4 ImVec416b777 = ImVec4(0x16 / 255.0f, 0xB7 / 255.0f, 0x77 / 255.0f, 1.0f);
ImVec4 ImVec416b77780 = ImVec4(0x16 / 255.0f, 0xB7 / 255.0f, 0x77 / 255.0f, 0.75f);
ImVec4 ImVec416b77740 = ImVec4(0x16 / 255.0f, 0xB7 / 255.0f, 0x77 / 255.0f, 0.5f);
ImVec4 ImVec4c2c2c2 = ImVec4(0xC2 / 255.0f, 0xC2 / 255.0f, 0xC2 / 255.0f, 1.0f);
ImVec4 ImVec42C88E2 = ImVec4(0x2C / 255.0f, 0x88 / 255.0f, 0xE2 / 255.0f, 1.0f);
ImVec4 ImVec411243B = ImVec4(0x11 / 255.0f, 0x24 / 255.0f, 0x3B / 255.0f, 1.0f);
ImVec4 ImVec411243B80 = ImVec4(0x11 / 255.0f, 0x24 / 255.0f, 0x3B / 255.0f, 0.75f);
ImVec4 ImVec411243B40 = ImVec4(0x11 / 255.0f, 0x24 / 255.0f, 0x3B / 255.0f, 0.5f);
ImVec4 ImVec4f3c258 = ImVec4(0xf3 / 255.0f, 0xc2 / 255.0f, 0x58 / 255.0f, 1.0f);
ImVec4 ImVec4333B48 = ImVec4(0x33 / 255.0f, 0x3b / 255.0f, 0x48 / 255.0f, 1.0f);
ImVec4 ImVec4fafafa = ImVec4(0xfa / 255.0f, 0xfa / 255.0f, 0xfa / 255.0f, 1.0f);
ImVec4 ImVec49A88FE = ImVec4(0x9a / 255.0f, 0x88 / 255.0f, 0xfe / 255.0f, 1.0f);
ImVec4 ImVec45D6373 = ImVec4(0x5d / 255.0f, 0x63 / 255.0f, 0x73 / 255.0f, 1.0f);
ImVec4 ImVec4ff5722 = ImVec4(0xff / 255.0f, 0x57 / 255.0f, 0x22 / 255.0f, 1.0f);
ImVec4 ImVec4ffb800 = ImVec4(0xff / 255.0f, 0xb8 / 255.0f, 0x00 / 255.0f, 1.0f);
ImVec4 ImVec4ffb80040 = ImVec4(0xff / 255.0f, 0xb8 / 255.0f, 0x00 / 255.0f, 0.5f);
ImVec4 ImVec4E39B32 = ImVec4(0xe3 / 255.0f, 0x9b / 255.0f, 0x32 / 255.0f, 1.0f);
ImVec4 ImVec4E39B3220 = ImVec4(0xe3 / 255.0f, 0x9b / 255.0f, 0x32 / 255.0f, 0.2f);
ImVec4 ImVec40062B3 = ImVec4(0x00 / 255.0f, 0x62 / 255.0f, 0xb3 / 255.0f, 1.0f);
ImVec4 ImVec423ade5 = ImVec4(0x23 / 255.0f, 0xad / 255.0f, 0xe5 / 255.0f, 1.0f);
ImVec4 ImVec423ade520 = ImVec4(0x23 / 255.0f, 0xad / 255.0f, 0xe5 / 255.0f, 0.2f);
ImVec4 ImVec4E39B3250 = ImVec4(0xe3 / 255.0f, 0x9b / 255.0f, 0x32 / 255.0f, 0.5f);
ImVec4 ImVec423ade550 = ImVec4(0x23 / 255.0f, 0xad / 255.0f, 0xe5 / 255.0f, 0.5f);
void CustomNewLine(float lineHeight = -1.0f) {
    if (lineHeight < 0.0f) {
        // 使用默认的行高
        ImGui::NewLine();
    } else {
        // 设置自定义行高
        ImGui::Dummy(ImVec2(0.0f, lineHeight));
    }
}
void CustomText(const char* text, ImVec2 size, int padding = 5, int alignment = 0,float fontSize=1.5f,bool showShadow=false, ImVec4 bgColor = ImVec4(0.0f, 0.0f, 0.0f, 0.5f), ImVec4 textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec4 shadowColor = ImVec4(0.0f, 0.0f, 0.0f, 0.5f)) {
    ImGui::SetWindowFontScale(fontSize);
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return;
    const ImGuiStyle& style = ImGui::GetStyle();
    const ImGuiID id = window->GetID(text);
    const ImVec2 contentMin = window->DC.CursorPos;
    const ImVec2 contentMax = ImVec2(contentMin.x + size.x, contentMin.y + size.y);
    if(showShadow){
        ImDrawList* drawList = ImGui::GetWindowDrawList();
        ImU32 shadowColor2 = IM_COL32(0, 0, 0, 128);
        float shadowStartY = contentMin.y + size.y - 3;
        float shadowEndY = shadowStartY + 10;
        for (float alpha = 0.5f; alpha >= 0.0f; alpha -= 0.075f) {
            shadowColor2 = IM_COL32(0, 0, 0, static_cast<int>(128 * alpha));
            drawList->AddRectFilledMultiColor(
                ImVec2(contentMin.x, shadowStartY),
                ImVec2(contentMin.x+size.x, shadowEndY),
                shadowColor2, shadowColor2, shadowColor2, shadowColor2
            );
            shadowStartY += 5;
            shadowEndY += 5;
        }
    }
    if (bgColor.w > 0.0f) {
        window->DrawList->AddRectFilled(contentMin, contentMax, ImGui::GetColorU32(bgColor));
    }
    ImVec2 textSize = ImGui::CalcTextSize(text);
    ImVec2 textPos;
    switch (alignment) {
        case 1:
            textPos = ImVec2(contentMax.x - textSize.x - padding, contentMin.y + (size.y - textSize.y) * 0.5f);
            break;
        case 2:
            textPos = ImVec2(contentMin.x + (size.x - textSize.x) * 0.5f, contentMin.y + (size.y - textSize.y) * 0.5f);
            break;
        default:
            textPos = ImVec2(contentMin.x + padding, contentMin.y + (size.y - textSize.y) * 0.5f);
            break;
    }
    window->DrawList->AddText(textPos, ImGui::GetColorU32(textColor), text);
    float textHeightWithPadding = textSize.y + padding * 2;
    ImGui::ItemSize(ImVec2(size.x, textHeightWithPadding), style.FramePadding.y);
    if (!ImGui::ItemAdd(ImRect(contentMin, ImVec2(contentMax.x, contentMin.y + textHeightWithPadding)), id))
        return;
    ImGui::SetWindowFontScale(1.0f);
}
struct ToggleButtonState {
    float t = 0.0f;
    std::string label;
};
static std::vector<ToggleButtonState> toggleButtonStates;
bool ToggleButton(const char* label, bool* pToggle, float width, bool showText=false, float borderThickness = 5.0f) {
    static std::map<std::string, ToggleButtonState> toggleButtonStates;
    if (toggleButtonStates.find(label) == toggleButtonStates.end()) {
        toggleButtonStates[label] = {0.0f};
    }
    ToggleButtonState& toggleButtonState = toggleButtonStates[label];
    const float Multiplier = 1.05f;
    const float CornerRadius = 50.0f;
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;
    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImVec2 pos = window->DC.CursorPos;
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    const float height = label_size.y / Multiplier + style.FramePadding.y * Multiplier;
    const float adjustedWidth = width * Multiplier;
    const float adjustedHeight = width / 2;
    const float knobWidth = adjustedWidth / 2.0f;
    const ImGuiID id = window->GetID(label);
    const ImU32 shadowColor = IM_COL32(0, 0, 0, 64);
    const ImVec2 shadowOffset(3.0f, 3.0f);
    const ImVec2 shadowStartPos = ImVec2(pos.x + shadowOffset.x, pos.y + shadowOffset.y);
    const ImVec2 shadowEndPos = ImVec2(shadowStartPos.x + adjustedWidth, shadowStartPos.y + adjustedHeight);
    ImGui::GetWindowDrawList()->AddRectFilled(shadowStartPos, shadowEndPos, shadowColor, CornerRadius);
    const ImVec2 borderStartPos(pos.x - borderThickness, pos.y - borderThickness);
    const ImVec2 borderEndPos(pos.x + adjustedWidth + borderThickness, pos.y + adjustedHeight + borderThickness);
    const ImU32 borderColor = IM_COL32(250, 250, 250, 255);
    window->DrawList->AddRect(borderStartPos, borderEndPos, borderColor, CornerRadius, 15, borderThickness);

    const ImVec2 text_pos(pos.x + style.FramePadding.x, pos.y + style.FramePadding.y);
    ImGui::InvisibleButton(label, ImVec2(adjustedWidth, adjustedHeight));
    if (ImGui::IsItemClicked())
        *pToggle = !*pToggle;

    ImU32 bg_color = ImGui::GetColorU32(*pToggle ? c_16b777 : c_545D6D);
    const ImU32 slider_color = IM_COL32(255, 255, 255, 255);
    const ImU32 slider_hovered_color = IM_COL32(255, 255, 255, 255);
    const ImU32 slider_active_color = IM_COL32(255, 255, 255, 200);
    float i=0;
    for (float alpha = 1.0f; alpha >= 0.0f; alpha -= 0.1f) {
        bg_color = *pToggle?IM_COL32(0x16, 0xb7, 0x77, static_cast<int>(100 * alpha)):IM_COL32(0x54, 0x5D, 0x6D, static_cast<int>(100 * alpha));
        window->DrawList->AddRectFilled(ImVec2(pos.x+i,pos.y+i), ImVec2(pos.x + adjustedWidth-i, pos.y + adjustedHeight-i), bg_color, CornerRadius);
        window->DrawList->AddRect(ImVec2(borderStartPos.x+i,borderStartPos.y+i), ImVec2(borderEndPos.x-i,borderEndPos.y-i), bg_color, CornerRadius, 15, borderThickness);
        i+=1.5;
    }
    float t = 0.1;
    if(*pToggle&&1>toggleButtonState.t){
        toggleButtonState.t+=t;
    }else if(!*pToggle&&t<toggleButtonState.t){
        toggleButtonState.t-=t;
    }
    ImVec2 knob_pos = ImVec2(pos.x + toggleButtonState.t * (adjustedWidth - knobWidth), pos.y);
    window->DrawList->AddRectFilled(knob_pos, ImVec2(knob_pos.x + knobWidth, knob_pos.y + adjustedHeight), ImGui::IsItemActive() ? slider_active_color : (ImGui::IsItemHovered() ? slider_hovered_color : slider_color), CornerRadius);
    ImVec2 text_size_on = ImGui::CalcTextSize("开");
    ImVec2 text_size_off = ImGui::CalcTextSize("关");
    ImVec2 text_center_on(pos.x + adjustedWidth * 0.25f - text_size_on.x * 0.5f, pos.y + adjustedHeight * 0.5f - text_size_on.y * 0.5f);
    ImVec2 text_center_off(pos.x + adjustedWidth * 0.75f - text_size_off.x * 0.5f, pos.y + adjustedHeight * 0.5f - text_size_off.y * 0.5f);
    ImU32 text_color_on = *pToggle ? IM_COL32(255, 255, 255, 255) : IM_COL32(0, 0, 0, 255);
    ImU32 text_color_off = *pToggle ? IM_COL32(0, 0, 0, 255) : IM_COL32(255, 255, 255, 255);
    if(showText){
        if(!*pToggle){
            ImGui::SetCursorPos(text_center_on);
            ImGui::PushStyleColor(ImGuiCol_Text, text_color_on);
            ImGui::Text("关");
            ImGui::PopStyleColor();
        }else{
            ImGui::SetCursorPos(text_center_off);
            ImGui::PushStyleColor(ImGuiCol_Text, text_color_off);
            ImGui::Text("开");
            ImGui::PopStyleColor();
        }
    }
    return ImGui::IsItemActive();
}

//-------

//glory struct  body   



//王者游戏结构chao

  

struct 总颜色
{
    ImColor 血量颜色 = ImColor(0, 255, 0, 255);//血量颜色
    ImColor 射线颜色 = ImColor(255, 255, 255, 255);
    ImColor 方框颜色 = ImColor(255, 255, 255, 255);
};

总颜色 颜色配置;
static struct Color1
{
    ImColor Red = { 255 / 255.f, 0 / 255.f, 0 / 255.f, 255 / 255.f };
    ImColor Red_ = { 255 / 255.f, 0 / 255.f, 0 / 255.f, 50 / 255.f };
    ImColor Green = { 0 / 255.f, 255 / 255.f, 0 / 255.f, 255 / 255.f };
    ImColor Green_ = { 0 / 255.f, 255 / 255.f, 0 / 255.f, 50 / 255.f };
    ImColor 白色 = { 255 / 255.f, 255 / 255.f, 255 / 255.f, 255.f / 255.f };
    ImColor White_ = { 255 / 255.f, 255 / 255.f, 255 / 255.f, 180.f / 255.f };
    ImColor Black = { 0 / 255.f, 0 / 255.f, 0 / 255.f, 255.f / 255.f };
    ImColor Yellow = { 1.0f, 1.0f, 0.0f, 1.0f };

} Color1;

struct stu
{
    int id;
    int hp;
};

struct Coord {
    float X;//X轴
    float Y;//Y轴
    float W;
    float H;
};
struct DynamicData {
    struct Coord coord;//获取xy坐标
};

struct HeroTemp {
    struct Coord coord;//获取xy坐标
    int Hp;//当前血量
    int MaxHp;//最大血量
    int Id;//英雄id
    int Space;
    int Space1;//大招cd
    int Space2;
    int Space3;
    int Spaceid;
    int Skill;//召唤师技能cd
    int Skill2;//召唤师技能cd2
    int camp;//阵营id
    int HC;//回城
    int TB;//图标
    int TB1;
    int TB2;//图标
    int TB3;
    int TB4;
    int confound;//坐标混淆
};
/**
 * 获取野怪xy和刷新时间
 */
struct Pve {
    uint64_t X;//X坐标地址
    uint64_t Y;//Y坐标地址
    uint64_t cd;//刷新时间
    uint64_t cc;//刷新时间
    uint64_t id;
    uint64_t hp;
    uint64_t maxcd;
    
};
/**
 * 获取野怪xy和刷新时间
 */

struct PveTemp {
    struct Coord coord;//获取xy坐标
    int cd;//刷新时间
    int id;
    int hp;
    int maxcd;
};


/**
 * 获取兵线xy
 */
struct Pvc {
    uint64_t X;//X坐标地址
    uint64_t Y;//Y坐标地址
};
/**
 * 单个兵线
 */
struct CeTemp {
    struct Coord coord;//获取xy坐标
    int cd;
    int hp;
    int maxhp;
};

typedef struct {
    float Matrix[BYTE16];//相机矩阵
    struct HeroTemp heroTemp[BYTE16];//储存单个英雄
    struct DynamicData DynamicData[BYTE16];//储存单个英雄大地图
    struct Pve pve[BYTE1024];//储存野怪
    struct PveTemp pveTemp[BYTE1024];//储存野怪
    struct CeTemp CeTemp[BYTE1024];//储存兵线
    struct Pvc pvc[BYTE1024];//储存兵线
    int xbsl;//小兵数量
} DataTable;


DataTable dataTable;//游戏数据表

const static ImColor Paint_touming = ImColor(254, 253, 252);  //透明
const static ImColor Paint_purple = ImColor(255, 0, 255);  //紫色
const static ImColor Paint_red = ImColor(255, 0, 0);       //红色
const static ImColor Paint_white = ImColor(255, 255, 255); //白色
const static ImColor Paint_lightblue = ImColor(0, 255, 255);   //浅蓝色
const static ImColor Paint_yellow = ImColor(255, 255, 0);  //黄色
const static ImColor Paint_green = ImColor(0, 255, 0);  //绿色

double Wwra = 0, Wwr2 = 0;    //转小地图算法




struct Coord map_coord = { 0 };/*实际地图坐标*/
struct Coord yg_coord = { 0 };/*实际野怪坐标*/
struct Coord map_buff = { 0 };/*实际地图坐标*/
long int 兵线数组地址;
//王者数据开始补充 结构体
//王者数据开始补充
stu player[10];
int PlayerPosition[10][3];//自瞄的玩家坐标 一把游戏10人 坐标xyz
int hist[10][3];
int me = 0;
 
double Wwr = 1080 / 10.2f * 1.574074075;
char DrawPlayerCount[100];
 
int Health;
int PlayerId;
long int CameraAddress;

int SmallMapTeam;




//计算矩阵  王者
//王者矩阵计算
Coord CalMatrixMem(struct Coord coor, const float Matrix[]) {
    struct Coord points = { 0 };
    float XM = coor.X / 1000.0f;
    float ZM = coor.Y / 1000.0f;
    if (Matrix[11] && Matrix[15] && Matrix[0] && Matrix[12] && Matrix[9] && Matrix[13] && Matrix[1] && Matrix[5] && Matrix[9] && Matrix[13]) {
        float radio = (float)fabs(ZM * Matrix[11] + Matrix[15]);
        points.X = 0.0f, points.Y = 0.0f, points.W = 0.0f, points.H = 0.0f;
        if (radio > 0) {
            points.X = yxpx / 2 + (XM * Matrix[0] + Matrix[12]) / radio * yxpx / 2;
            points.Y = yxpy / 2 - (ZM * Matrix[9] + Matrix[13]) / radio * yxpy / 2;
            points.W = yxpy / 2 - (XM * Matrix[1] + 4.0f * Matrix[5] + ZM * Matrix[9] + Matrix[13]) / radio * yxpy / 2;
            points.H = ((points.Y - points.W) / 2.0f);
        }
        return points;
    }
}
//计算矩阵




#endif
