// ============================================================
// globals.cpp - 全局变量定义
// ============================================================
#include "globals.h"
#include "IsCharacter.h"

// ---- 进程 / 模块基址 ----
int pid = 0;
uintptr_t 基址头;
uintptr_t 人物坐标;
bool 进程与模块 = false;
uint64_t lil2cpp_base = 0;
uint64_t libGame_base = 0;
uint64_t libunity_base = 0;
uint64_t lil2cpp_basebss = 0;
uint64_t libGame_basebss = 0;
uint64_t libunity_basebss = 0;
uint64_t libtersafe_base = 0;
uintptr_t libbase;
long int libbase3;
long int libbase2;
uintptr_t unity;
uintptr_t unitybss;
uintptr_t GameCore;
uintptr_t GameCorebss;
uintptr_t il2cpp;
uintptr_t il2cppbss;

// ---- 矩阵 / 游戏状态 ----
uint64_t MatrixAddress = 0;
float isGames;
int foeComp;
int rientation = 0;
int AroundNumbers = 0;

// ---- 分辨率 / 显示 ----
int yxpx, yxpy, fenblxx = 0;
int screen_x = 0, screen_y = 0;
int init_screen_x = 0, init_screen_y = 0;
bool g_Initialized = false;
int Orientation = 0;
float zm_x = -1, zm_y = -1;

// ---- 绘制开关 ----
int huitu = 0;
bool 血量 = false;
bool 地图 = false;
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

// ---- 地图 / UI 参数 ----
int touxiangdaxiao = 0;
int xiaodituxue = 7;
int jiange = -1;
int SmallMapX = 75;
int SmallMapY = 2;
int BuffMapX = 0;
int BuffMapY = 0;
int SmallSoldiX = 0;
int SmallSoldiY = 0;
int SmallHPX = 9;
int SmallHPY = 34;
int jinenglanz = 0;
int jinenglanzX = 0;
int jinenglanzY = 0;

// ---- 共享 ----
int pxx = 0, pyy = 0;
double WwrShare = 0.0;
sESPMenu ESPMenu;
bool 初始化 = false;
bool Touchinit = true;
int Screen_X, Screen_Y;
int xytable[10][10];
int hist1[10][10];
int me1 = 0;
long a, objarrayaddr, libGameCore1, libil2cpp1, 兵线基址, 人物数组, 野怪数组, 兵线数组, 矩阵;
int 阵营1 = 0, fx1 = 0;

// ---- 游戏数据表 ----
DataTable dataTable;
总颜色 颜色配置;
double Wwra = 0, Wwr2 = 0;
struct Coord map_coord = { 0 };
struct Coord yg_coord = { 0 };
struct Coord map_buff = { 0 };
long int 兵线数组地址;
stu player[10];
int PlayerPosition[10][3];
int hist[10][3];
int me = 0;
double Wwr = 1080 / 10.2f * 1.574074075;
char DrawPlayerCount[100];
int Health;
int PlayerId;
long int CameraAddress;
int SmallMapTeam;

// ---- 渲染.h 全局 ----
char extra[32];
char imei[100] = "";
int 人物 = 12, 坐标 = 880;
int 自身视野 = 0;
int 视野 = 0;
/*===== 坐标解密变量 - 已注释 =====
bool 坐标解密1 = false;
bool 坐标解密2 = false;
bool 坐标解密3 = false;
bool 坐标解密4 = false;
long cooroffest = 0;
long coorpage = 0;
===== 坐标解密变量 结束 =====*/
long 真实坐标, 坐标模块, 真实坐标第一层, 真实坐标第二层;

// ---- EGL / 覆盖层 ----
void *handle;
EGLDisplay display = EGL_NO_DISPLAY;
EGLConfig config;
EGLSurface surface = EGL_NO_SURFACE;
ANativeWindow *native_window;
ANativeWindow *(*createNativeWindow)(const char *surface_name, uint32_t screen_width, uint32_t screen_height);
EGLContext context = EGL_NO_CONTEXT;
Screen full_screen;

// ---- draw.cpp 全局 ----
bool show = true;
float godvalue = 1.7;
int 共享 = false;
bool 悬浮球 = false;
bool 悬浮窗 = true;
bool 窗口状态 = false;
ImVec2 Pos;
sConfig Config;
float menu[4] = { 0/255.f, 255/255.f, 0/255.f, 1.000f };

std::string fileContent1;
std::string fileContent2;
std::string fileContent3;

// ---- 封装绘图.h 全局 ----
int ret = -1;
int socket_fd;
struct sockaddr_in serveraddr;
char buffer[MAX_BUFFER_SIZE];
char homeBuffer[MAX_BUFFER_SIZE];
int numBytesReceived, homeBytesReceived;
std::string 共享房间ip = "38.55.232.191";
bool 是否开启共享 = true;

// ---- 纹理 / 字体 ----
ImFont *imFont;
ImFont *CLOSE;
ImFont *F48;
ImFont *COLOR;
ImFont *F50;
ImFont *F68;
ImFont *SR;
ImFont *LOGIN;
ImFont *Subtab;
ImFont *F86;
ImFont *Social;
ImTextureID LOGO图片 = nullptr;
全部头像1 贴图1;
技能图标 技能贴图;
全部头像 贴图;
TextureInfoa djjddjnd[666] = {};
ImFont* font = nullptr;
ImDrawList* draw;

// ---- Func.h 全局 ----
int FPS = 60;
timer FPS限制;
float FPF显示 = 0.0f;
uintptr_t Gmin = 0;
float 触摸位置X = 0.0f;
float 触摸位置Y = 0.0f;

// ---- 内核读写.h 全局 ----
long int Gname;
float X, Y, W;
ImColor 颜色;
int 队伍编号, 人机判断, 自身队伍, 动作编码, 开火状态, 死亡判断, 开镜判断;
char 人物昵称[100];
float top;
float MIDDLE;
long int lanran;

// ---- 杂项 ----
long int code_sock = -64649191801064646;
char mm[128];
std::string km;
float 范围 = 250;
float WorldDistance;
float 平滑力度 = 15;
float 压枪系数 = 18;
float 绘图宽, 绘图高;
float shangdi = 0.1f;
float NumIo[50];
bool DrawIo[50];
float hp1;
float aa;
float pos_y;
float pos_x;
float myx, myy;
char meter1[1000];
float meter;
float my_pos_y;
float my_pos_x;

// ---- 封装绘图.h 颜色 ----
ImColor 浅蓝 = ImColor(ImVec4(36/255.f, 249/255.f, 217/255.f, 255/255.f));
ImColor 蓝色 = ImColor(ImVec4(170/255.f, 203/255.f, 244/255.f, 0.95f));
ImColor 白色 = ImColor(ImVec4(255/255.f, 255/255.f, 258/255.f, 0.95f));
ImColor 浅粉 = ImColor(ImVec4(255/255.f, 200/255.f, 250/255.f, 0.95f));
ImColor 黑色 = ImColor(ImVec4(0/255.f, 0/255.f, 0/255.f, 0.7f));
ImColor 半黑 = ImColor(ImVec4(0/255.f, 0/255.f, 0/255.f, 0.18f));
ImColor 血色 = ImColor(ImVec4(0/255.f, 249/255.f, 0/255.f, 0.35f));
ImColor 红色 = ImColor(ImVec4(233/255.f, 55/255.f, 51/255.f, 0.95f));
ImColor 绿色 = ImColor(ImVec4(50/255.f, 222/215.f, 50/255.f, 0.95f));
ImColor 黄色 = ImColor(ImVec4(255/255.f, 255/255.f, 0/255.f, 0.95f));
ImColor 橘黄 = ImColor(ImVec4(255/255.f, 150/255.f, 30/255.f, 0.95f));
ImColor 粉红 = ImColor(ImVec4(220/255.f, 108/255.f, 1202/255.f, 0.95f));
ImColor 紫色 = ImColor(ImVec4(169/255.f, 120/255.f, 223/255.f, 0.95f));
ImColor 空白 = ImColor(ImVec4(1.0/255.f, 1.0/255.f, 1.0/255.f, 0.0f));
ImColor 颜色1;

// ============================================================
//  工具函数实现
// ============================================================

// 矩阵计算
Coord CalMatrixMem(struct Coord coor, const float Matrix[]) {
    struct Coord points = { 0 };
    float XM = coor.X / 1000.0f;
    float ZM = coor.Y / 1000.0f;
    if (Matrix[11] && Matrix[15] && Matrix[0] && Matrix[12] && Matrix[9] && Matrix[13] && Matrix[1] && Matrix[5] && Matrix[9] && Matrix[13]) {
        float radio = (float)fabs(ZM * Matrix[11] + Matrix[15]);
        points.X = 0.0f; points.Y = 0.0f; points.W = 0.0f; points.H = 0.0f;
        if (radio > 0) {
            points.X = yxpx / 2 + (XM * Matrix[0] + Matrix[12]) / radio * yxpx / 2;
            points.Y = yxpy / 2 - (ZM * Matrix[9] + Matrix[13]) / radio * yxpy / 2;
            points.W = yxpy / 2 - (XM * Matrix[1] + 4.0f * Matrix[5] + ZM * Matrix[9] + Matrix[13]) / radio * yxpy / 2;
            points.H = ((points.Y - points.W) / 2.0f);
        }
        return points;
    }
    return points;
}

// ImGui 工具函数
void CustomNewLine(float lineHeight) {
    if (lineHeight < 0.0f) {
        ImGui::NewLine();
    } else {
        ImGui::Dummy(ImVec2(0.0f, lineHeight));
    }
}

void CustomText(const char* text, ImVec2 size, int padding, int alignment, float fontSize, bool showShadow, ImVec4 bgColor, ImVec4 textColor, ImVec4 shadowColor) {
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

bool ToggleButton(const char* label, bool* pToggle, float width, bool showText, float borderThickness) {
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
        bg_color = *pToggle ? IM_COL32(0x16, 0xb7, 0x77, static_cast<int>(100 * alpha)) : IM_COL32(0x54, 0x5D, 0x6D, static_cast<int>(100 * alpha));
        window->DrawList->AddRectFilled(ImVec2(pos.x+i,pos.y+i), ImVec2(pos.x + adjustedWidth-i, pos.y + adjustedHeight-i), bg_color, CornerRadius);
        window->DrawList->AddRect(ImVec2(borderStartPos.x+i,borderStartPos.y+i), ImVec2(borderEndPos.x-i,borderEndPos.y-i), bg_color, CornerRadius, 15, borderThickness);
        i+=1.5;
    }
    float t = 0.1;
    if(*pToggle && 1 > toggleButtonState.t){
        toggleButtonState.t += t;
    } else if(!*pToggle && t < toggleButtonState.t){
        toggleButtonState.t -= t;
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
        } else {
            ImGui::SetCursorPos(text_center_off);
            ImGui::PushStyleColor(ImGuiCol_Text, text_color_off);
            ImGui::Text("开");
            ImGui::PopStyleColor();
        }
    }
    return ImGui::IsItemActive();
}

// 文件操作
void read_line_without_newline(FILE* stream, char* buffer, size_t size) {
    fgets(buffer, size, stream);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void 写出文件(char *aaa, char *bbb) {
    system("mkdir -p /storage/emulated/0/Best");
    std::ofstream ofs;
    ofs.open(aaa, std::ios::out);
    ofs << bbb;
    ofs.close();
}

char *读取文件(char *path) {
    FILE *fp;
    if ((fp = fopen(path, "r")) == NULL) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    char *str;
    str = (char *)malloc(filesize + 1);
    rewind(fp);
    fread(str, 1, filesize, fp);
    str[filesize] = '\0';
    fclose(fp);
    return str;
}

// ButtonTextColored
bool ButtonTextColored(const ImVec4& col, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImGui::TextColoredV(col, fmt, args);
    va_end(args);
    return ImGui::IsItemClicked();
}
