#pragma once
// ============================================================
// globals.h - 全局类型定义 + extern 变量声明
// 由 Tomato sauce 移植 / 重构
// ============================================================

// ---- 系统头文件 ----
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <thread>
#include <chrono>
#include <vector>
#include <map>
#include <algorithm>
#include <atomic>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <ctype.h>
#include <sys/system_properties.h>

// ---- 网络头文件 ----
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// ---- EGL / OpenGL ES ----
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <GLES/gl.h>
#include <dlfcn.h>
#include <android/native_window.h>

// ---- ImGui ----
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_android.h"
#include "stb_image.h"
#include "ANativeWindowCreator.h"
#include "timer.h"

// ---- 命名空间 ----
using namespace std;
using namespace std::chrono_literals;

// ============================================================
//  宏定义
// ============================================================
#ifndef PI
#define PI 3.14159265358979323846
#endif
#define BYTE4    0x00000004
#define BYTE8    0x00000008
#define BYTE16   0x00000010
#define BYTE10   0x000000A
#define BYTE64   0x00000040
#define BYTE1024 0x00000400
#define MAX_BUFFER_SIZE 1024

// ============================================================
//  结构体 / 类型定义
// ============================================================

struct Screen {
    float ScreenX;
    float ScreenY;
};

struct FVector2D {
    float X = 0;
    float Y = 0;
    FVector2D() : X(0), Y(0) {}
    FVector2D(float x, float y) : X(x), Y(y) {}
};

struct FVector {
    float X = 0;
    float Y = 0;
    float Z = 0;
    FVector() : X(0), Y(0), Z(0) {}
    FVector(float x, float y, float z) : X(x), Y(y), Z(z) {}
};

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
    int 分辨率Y = 2456;
    int 分辨率X = 2456;
    int 小地图左右调整 = -7;
    int 小地图上下调整 = -4;
    int 兵线左右调整 = 9;
    int 兵线上下调整 = -27;
    int 野怪左右调整 = -9;
    int 野怪上下调整 = -5;
    int FPS帧率 = 144;
};

struct 总颜色 {
    ImColor 血量颜色 = ImColor(0, 255, 0, 255);
    ImColor 射线颜色 = ImColor(255, 255, 255, 255);
    ImColor 方框颜色 = ImColor(255, 255, 255, 255);
};

struct stu {
    int id;
    int hp;
};

struct Coord {
    float X;
    float Y;
    float W;
    float H;
};

struct DynamicData {
    struct Coord coord;
};

struct HeroTemp {
    struct Coord coord;
    int Hp;
    int MaxHp;
    int Id;
    int Space;
    int Space1;
    int Space2;
    int Space3;
    int Spaceid;
    int Skill;
    int Skill2;
    int camp;
    int HC;
    int TB;
    int TB1;
    int TB2;
    int TB3;
    int TB4;
    int confound;
};

struct Pve {
    uint64_t X;
    uint64_t Y;
    uint64_t cd;
    uint64_t cc;
    uint64_t id;
    uint64_t hp;
    uint64_t maxcd;
};

struct PveTemp {
    struct Coord coord;
    int cd;
    int id;
    int hp;
    int maxcd;
};

struct Pvc {
    uint64_t X;
    uint64_t Y;
};

struct CeTemp {
    struct Coord coord;
    int cd;
    int hp;
    int maxhp;
};

typedef struct {
    float Matrix[BYTE16];
    struct HeroTemp heroTemp[BYTE16];
    struct DynamicData DynamicData[BYTE16];
    struct Pve pve[BYTE1024];
    struct PveTemp pveTemp[BYTE1024];
    struct CeTemp CeTemp[BYTE1024];
    struct Pvc pvc[BYTE1024];
    int xbsl;
} DataTable;

// 图片纹理结构体
struct TextureInfo {
    ImTextureID textureId;
    int x;
    int y;
    int w;
    int h;
};

struct TextureInfoa {
    uint *textureId;
    int x;
    int y;
    int w;
    int h;
};

struct 全部头像1 {
    TextureInfoa 头像[666];
};

struct 技能图标 {
    TextureInfoa 头像[111111];
};

struct 全部头像 {
    TextureInfo 头像[111111];
};

// ImGui 按钮状态
struct ToggleButtonState {
    float t = 0.0f;
    std::string label;
};

// Config 结构体 (draw.cpp 实际使用版本)
struct sConfig {
    bool Bypass = true;
    bool AutoFiree;
    int Hit;
    int IpadS;
    int Line;
    int Prid;
    int Skeleton;
    int RadarX;
    int RadarY;
    int Loot;
    struct sWIDGETS_EXPERT {
        bool Line;
        bool Box;
        bool AutoFire;
        bool Skeleton;
        bool Health;
        bool LootItem;
        bool Name;
        bool Distance;
        bool Alert;
        bool TeamID;
        bool Radar;
        bool AirDrop;
        bool Weapon;
        bool Gen;
        bool Genn;
        bool ShowVehicle;
        bool ShowVehiclee;
        bool NoBot;
        bool VehicleFuel;
        bool VehicleHP;
        bool FPS;
        bool Loot;
    };
    sWIDGETS_EXPERT WIDGETS_EXPERT;
    struct sHighRisk {
        bool Swim;
        bool Switch;
        bool Scope;
        bool FastMove;
        bool SuperAim;
        bool Unlock;
        bool NoFog;
        bool Shoot;
        bool Fly;
        bool Reload;
        bool HitRGB;
        bool Ipad;
        bool Prone;
        bool Ljump;
        bool Blockspect;
        bool Shake;
        bool Recoil;
        bool Instant;
        bool HitEffect;
    };
    sHighRisk HighRisk{0};
    struct sAimMenu {
        bool Enable;
        int Meter;
        bool Pov;
        bool Pred;
        bool Recoil;
        bool Aimbot;
        int Cross;
        int Position;
        float Recc;
        bool IgnoreKnocked;
        bool VisCheck;
        bool IgnoreBots;
        bool TargetLine;
    };
    sAimMenu SilentAim{0};
    sAimMenu AimBot{0};
    struct sColorsESP {
        float *PlayerVisLine;
        float *PlayerHideLine;
        float *BotVisLine;
        float *BotHideLine;
        float *PlayerVisSkeleton;
        float *PlayerHideSkeleton;
        float *BotVisSkeleton;
        float *BotHideSkeleton;
        float *PlayerVisBox;
        float *PlayerHideBox;
        float *BotVisBox;
        float *BotHideBox;
        float *PlayerRadar;
        float *BotRadar;
        float *PlayerAlert;
        float *BotAlert;
        float *Fov;
        float *Fova;
    };
    sColorsESP ColorsESP{0};
};

#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a}

// ============================================================
//  extern 全局变量声明
// ============================================================

// ---- 进程 / 模块基址 ----
extern int pid;
extern uintptr_t 基址头;
extern uintptr_t 人物坐标;
extern bool 进程与模块;
extern uint64_t lil2cpp_base;
extern uint64_t libGame_base;
extern uint64_t libunity_base;
extern uint64_t lil2cpp_basebss;
extern uint64_t libGame_basebss;
extern uint64_t libunity_basebss;
extern uint64_t libtersafe_base;
extern uintptr_t libbase;
extern long int libbase3;
extern long int libbase2;
extern uintptr_t unity;
extern uintptr_t unitybss;
extern uintptr_t GameCore;
extern uintptr_t GameCorebss;
extern uintptr_t il2cpp;
extern uintptr_t il2cppbss;

// ---- 矩阵 / 游戏状态 ----
extern uint64_t MatrixAddress;
extern float isGames;
extern int foeComp;
extern int rientation;
extern int AroundNumbers;

// ---- 分辨率 / 显示 ----
extern int yxpx, yxpy, fenblxx;
extern int screen_x, screen_y;
extern int init_screen_x, init_screen_y;
extern bool g_Initialized;
extern int Orientation;
extern float zm_x, zm_y;

// ---- 绘制开关 ----
extern int huitu;
extern bool 血量;
extern bool 地图;
extern bool 方框;
extern bool 自瞄;
extern bool 射线;
extern bool 距离;
extern bool 野怪;
extern bool 兵线;
extern bool 方框技能;
extern bool 顶上技能;
extern bool 上帝;
extern bool 眼位;
extern bool 龙触摸;
extern bool buff触摸;
extern bool 野血;
extern bool 框技;
extern bool 回城;
extern bool 框头;
extern bool 技陷;
extern bool 斩杀;
extern bool 惩戒;
extern bool 解密;
extern bool 自身判断;

// ---- 地图 / UI 参数 ----
extern int touxiangdaxiao;
extern int xiaodituxue;
extern int jiange;
extern int SmallMapX;
extern int SmallMapY;
extern int BuffMapX;
extern int BuffMapY;
extern int SmallSoldiX;
extern int SmallSoldiY;
extern int SmallHPX;
extern int SmallHPY;
extern int jinenglanz;
extern int jinenglanzX;
extern int jinenglanzY;

// ---- 共享 ----
extern int pxx, pyy;
extern double WwrShare;
extern sESPMenu ESPMenu;
extern bool 初始化;
extern bool Touchinit;
extern int Screen_X, Screen_Y;
extern int xytable[10][10];
extern int hist1[10][10];
extern int me1;
extern long a, objarrayaddr, libGameCore1, libil2cpp1, 兵线基址, 人物数组, 野怪数组, 兵线数组, 矩阵;
extern int 阵营1, fx1;

// ---- 游戏数据表 ----
extern DataTable dataTable;
extern 总颜色 颜色配置;
extern double Wwra, Wwr2;
extern struct Coord map_coord;
extern struct Coord yg_coord;
extern struct Coord map_buff;
extern long int 兵线数组地址;
extern stu player[10];
extern int PlayerPosition[10][3];
extern int hist[10][3];
extern int me;
extern double Wwr;
extern char DrawPlayerCount[100];
extern int Health;
extern int PlayerId;
extern long int CameraAddress;
extern int SmallMapTeam;

// ---- 渲染.h 全局 ----
extern char extra[32];
extern char imei[100];
extern int 人物, 坐标;
extern int 自身视野;
extern int 视野;
extern long 真实坐标, 坐标模块, 真实坐标第一层, 真实坐标第二层;
/*===== 坐标解密变量 - 已注释 =====
extern bool 坐标解密1;
extern bool 坐标解密2;
extern bool 坐标解密3;
extern bool 坐标解密4;
extern long cooroffest;
extern long coorpage;
===== 坐标解密变量 结束 =====*/

// ---- EGL / 覆盖层 ----
extern void *handle;
extern EGLDisplay display;
extern EGLConfig config;
extern EGLSurface surface;
extern ANativeWindow *native_window;
extern ANativeWindow *(*createNativeWindow)(const char *surface_name, uint32_t screen_width, uint32_t screen_height);
extern EGLContext context;
extern Screen full_screen;

// ---- draw.cpp 全局 ----
extern bool show;
extern float godvalue;
extern int 共享;
extern bool 悬浮球;
extern bool 悬浮窗;
extern bool 窗口状态;
extern ImVec2 Pos;
extern sConfig Config;
extern std::string fileContent1;
extern std::string fileContent2;
extern std::string fileContent3;

// ---- 封装绘图.h 全局 ----
extern int ret;
extern int socket_fd;
extern struct sockaddr_in serveraddr;
extern char buffer[MAX_BUFFER_SIZE];
extern char homeBuffer[MAX_BUFFER_SIZE];
extern int numBytesReceived, homeBytesReceived;
extern std::string 共享房间ip;
extern bool 是否开启共享;

// ---- 纹理 / 字体 ----
extern ImFont *imFont;
extern ImFont *CLOSE;
extern ImFont *F48;
extern ImFont *COLOR;
extern ImFont *F50;
extern ImFont *F68;
extern ImFont *SR;
extern ImFont *LOGIN;
extern ImFont *Subtab;
extern ImFont *F86;
extern ImFont *Social;
extern ImTextureID LOGO图片;
extern 全部头像1 贴图1;
extern 技能图标 技能贴图;
extern 全部头像 贴图;
extern TextureInfoa djjddjnd[666];
extern ImFont* font;
extern ImDrawList* draw;

// ---- Func.h 全局 ----
extern int FPS;
extern timer FPS限制;
extern float FPF显示;
extern uintptr_t Gmin;
extern float 触摸位置X, 触摸位置Y;

// ---- 内核读写.h 全局 ----
extern long int Gname;
extern float X, Y, W;
extern ImColor 颜色;
extern int 队伍编号, 人机判断, 自身队伍, 动作编码, 开火状态, 死亡判断, 开镜判断;
extern char 人物昵称[100];
extern float top;
extern float MIDDLE;
extern long int lanran;

// ---- 杂项 ----
extern long int code_sock;
extern char mm[128];
extern std::string km;
extern float 范围;
extern float WorldDistance;
extern float 平滑力度;
extern float 压枪系数;
extern float 绘图宽, 绘图高;
extern float shangdi;
extern float NumIo[50];
extern bool DrawIo[50];
extern float hp1;
extern float aa;
extern float pos_y;
extern float pos_x;
extern float myx, myy;
extern char meter1[1000];
extern float meter;
extern float my_pos_y;
extern float my_pos_x;

// ============================================================
//  Paint 常量 (const 可直接放在 header)
// ============================================================
const static ImColor Paint_touming = ImColor(254, 253, 252);
const static ImColor Paint_purple  = ImColor(255, 0, 255);
const static ImColor Paint_red     = ImColor(255, 0, 0);
const static ImColor Paint_white   = ImColor(255, 255, 255);
const static ImColor Paint_lightblue = ImColor(0, 255, 255);
const static ImColor Paint_yellow  = ImColor(255, 255, 0);
const static ImColor Paint_green   = ImColor(0, 255, 0);

// ============================================================
//  ImU32 / ImVec4 颜色常量 (const 可直接放在 header)
// ============================================================
const static ImU32 c_透明           = IM_COL32(0, 0, 0, 0);
const static ImU32 c_黑色透明50     = IM_COL32(0, 0, 0, 50);
const static ImU32 c_黑色透明100    = IM_COL32(0, 0, 0, 100);
const static ImU32 c_黑色透明128    = IM_COL32(0, 0, 0, 128);
const static ImU32 c_白色透明50     = IM_COL32(255, 255, 255, 50);
const static ImU32 c_白色透明128    = IM_COL32(255, 255, 255, 128);
const static ImU32 c_白色透明150    = IM_COL32(255, 255, 255, 150);
const static ImU32 c_fafafa         = IM_COL32(250, 250, 250, 255);
const static ImU32 c_cccccc         = IM_COL32(204, 204, 204, 255);
const static ImU32 c_c2c2c2         = IM_COL32(194, 194, 194, 255);
const static ImU32 c_23292e         = IM_COL32(35, 41, 46, 255);
const static ImU32 c_4023292e       = IM_COL32(35, 41, 46, 125);
const static ImU32 c_2f363c         = IM_COL32(47, 54, 60, 255);
const static ImU32 c_402f363c       = IM_COL32(47, 54, 60, 125);
const static ImU32 c_DAB123         = IM_COL32(218, 177, 35, 255);
const static ImU32 c_DCD4CA         = IM_COL32(220, 212, 202, 255);
const static ImU32 c_2C88E2         = IM_COL32(44, 136, 226, 255);
const static ImU32 c_2C88E240       = IM_COL32(44, 136, 226, 128);
const static ImU32 c_545D6D         = IM_COL32(84, 93, 109, 255);
const static ImU32 c_545D6D40       = IM_COL32(84, 93, 109, 128);
const static ImU32 c_81A4DC         = IM_COL32(0x81, 0xa4, 0xdc, 255);
const static ImU32 c_FFD49F         = IM_COL32(255, 212, 159, 255);
const static ImU32 c_FFD49F80       = IM_COL32(255, 212, 159, 128);
const static ImU32 c_16b777         = IM_COL32(0x16, 0xB7, 0x77, 255);
const static ImU32 c_16b77780       = IM_COL32(0x16, 0xB7, 0x77, 128);
const static ImU32 c_16b77710       = IM_COL32(0x16, 0xB7, 0x77, 50);
const static ImU32 c_11243B         = IM_COL32(0x11, 0x24, 0x3B, 255);
const static ImU32 c_11243B80       = IM_COL32(0x11, 0x24, 0x3B, 128);
const static ImU32 c_558FFD         = IM_COL32(0x55, 0x8F, 0xFD, 255);
const static ImU32 c_9A88FE         = IM_COL32(0x9a, 0x88, 0xFe, 255);
const static ImU32 c_ffb800         = IM_COL32(0xff, 0xb8, 0x00, 255);
const static ImU32 c_ffb80080       = IM_COL32(0xff, 0xb8, 0x00, 128);
const static ImU32 c_ff5722         = IM_COL32(0xff, 0x57, 0x22, 255);
const static ImU32 c_ff572280       = IM_COL32(0xff, 0x57, 0x22, 128);
const static ImU32 c_ff572210       = IM_COL32(0xff, 0x57, 0x22, 50);

const static ImVec4 透明ImVec4          = ImVec4(0, 0, 0, 0);
const static ImVec4 白色ImVec4          = ImVec4(1,1,1,1);
const static ImVec4 黑色ImVec4          = ImVec4(0, 0, 0, 1.0f);
const static ImVec4 灰色ImVec4          = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
const static ImVec4 灰色ImVec440        = ImVec4(0.1f, 0.1f, 0.1f, 0.5f);
const static ImVec4 灰色ImVec480        = ImVec4(0.1f, 0.1f, 0.1f, 0.75f);
const static ImVec4 亮灰色ImVec4        = ImVec4(0.5, 0.5, 0.5, 1);
const static ImVec4 亮黄色ImVec4        = ImVec4(1.0f, 0.831f, 0.623f, 1.0f);
const static ImVec4 半透明黑色ImVec4    = ImVec4(0.184314f, 0.211765f, 0.235294f, 0.5f);
const static ImVec4 半透明黑色ImVec480  = ImVec4(0.184314f, 0.211765f, 0.235294f, 0.75f);
const static ImVec4 ImVec423292e        = ImVec4(0.137255f, 0.160784f, 0.180392f, 1.0f);
const static ImVec4 ImVec80423292e      = ImVec4(0.137255f, 0.160784f, 0.180392f, 0.75f);
const static ImVec4 ImVec40423292e      = ImVec4(0.137255f, 0.160784f, 0.180392f, 0.5f);
const static ImVec4 ImVec416b777        = ImVec4(0x16/255.0f, 0xB7/255.0f, 0x77/255.0f, 1.0f);
const static ImVec4 ImVec416b77780      = ImVec4(0x16/255.0f, 0xB7/255.0f, 0x77/255.0f, 0.75f);
const static ImVec4 ImVec416b77740      = ImVec4(0x16/255.0f, 0xB7/255.0f, 0x77/255.0f, 0.5f);
const static ImVec4 ImVec4c2c2c2        = ImVec4(0xC2/255.0f, 0xC2/255.0f, 0xC2/255.0f, 1.0f);
const static ImVec4 ImVec42C88E2        = ImVec4(0x2C/255.0f, 0x88/255.0f, 0xE2/255.0f, 1.0f);
const static ImVec4 ImVec411243B        = ImVec4(0x11/255.0f, 0x24/255.0f, 0x3B/255.0f, 1.0f);
const static ImVec4 ImVec411243B80      = ImVec4(0x11/255.0f, 0x24/255.0f, 0x3B/255.0f, 0.75f);
const static ImVec4 ImVec411243B40      = ImVec4(0x11/255.0f, 0x24/255.0f, 0x3B/255.0f, 0.5f);
const static ImVec4 ImVec4f3c258        = ImVec4(0xf3/255.0f, 0xc2/255.0f, 0x58/255.0f, 1.0f);
const static ImVec4 ImVec4333B48        = ImVec4(0x33/255.0f, 0x3b/255.0f, 0x48/255.0f, 1.0f);
const static ImVec4 ImVec4fafafa        = ImVec4(0xfa/255.0f, 0xfa/255.0f, 0xfa/255.0f, 1.0f);
const static ImVec4 ImVec49A88FE        = ImVec4(0x9a/255.0f, 0x88/255.0f, 0xfe/255.0f, 1.0f);
const static ImVec4 ImVec45D6373        = ImVec4(0x5d/255.0f, 0x63/255.0f, 0x73/255.0f, 1.0f);
const static ImVec4 ImVec4ff5722        = ImVec4(0xff/255.0f, 0x57/255.0f, 0x22/255.0f, 1.0f);
const static ImVec4 ImVec4ffb800        = ImVec4(0xff/255.0f, 0xb8/255.0f, 0x00/255.0f, 1.0f);
const static ImVec4 ImVec4ffb80040      = ImVec4(0xff/255.0f, 0xb8/255.0f, 0x00/255.0f, 0.5f);
const static ImVec4 ImVec4E39B32        = ImVec4(0xe3/255.0f, 0x9b/255.0f, 0x32/255.0f, 1.0f);
const static ImVec4 ImVec4E39B3220      = ImVec4(0xe3/255.0f, 0x9b/255.0f, 0x32/255.0f, 0.2f);
const static ImVec4 ImVec40062B3        = ImVec4(0x00/255.0f, 0x62/255.0f, 0xb3/255.0f, 1.0f);
const static ImVec4 ImVec423ade5        = ImVec4(0x23/255.0f, 0xad/255.0f, 0xe5/255.0f, 1.0f);
const static ImVec4 ImVec423ade520      = ImVec4(0x23/255.0f, 0xad/255.0f, 0xe5/255.0f, 0.2f);
const static ImVec4 ImVec4E39B3250      = ImVec4(0xe3/255.0f, 0x9b/255.0f, 0x32/255.0f, 0.5f);
const static ImVec4 ImVec423ade550      = ImVec4(0x23/255.0f, 0xad/255.0f, 0xe5/255.0f, 0.5f);

// 封装绘图.h 颜色
extern ImColor 浅蓝;
extern ImColor 蓝色;
extern ImColor 白色;
extern ImColor 浅粉;
extern ImColor 黑色;
extern ImColor 半黑;
extern ImColor 血色;
extern ImColor 红色;
extern ImColor 绿色;
extern ImColor 黄色;
extern ImColor 橘黄;
extern ImColor 粉红;
extern ImColor 紫色;
extern ImColor 空白;
extern ImColor 颜色1;

// static Color1 结构体 (const-like, header 内定义)
static struct Color1 {
    ImColor Red   = { 255/255.f, 0/255.f, 0/255.f, 255/255.f };
    ImColor Red_  = { 255/255.f, 0/255.f, 0/255.f, 50/255.f };
    ImColor Green = { 0/255.f, 255/255.f, 0/255.f, 255/255.f };
    ImColor Green_= { 0/255.f, 255/255.f, 0/255.f, 50/255.f };
    ImColor 白色  = { 255/255.f, 255/255.f, 255/255.f, 255.f/255.f };
    ImColor White_= { 255/255.f, 255/255.f, 255/255.f, 180.f/255.f };
    ImColor Black = { 0/255.f, 0/255.f, 0/255.f, 255.f/255.f };
    ImColor Yellow= { 1.0f, 1.0f, 0.0f, 1.0f };
} Color1;

// ============================================================
//  工具函数声明
// ============================================================

// 矩阵计算
Coord CalMatrixMem(struct Coord coor, const float Matrix[]);

// ImGui 工具
void CustomNewLine(float lineHeight = -1.0f);
void CustomText(const char* text, ImVec2 size, int padding = 5, int alignment = 0,
                float fontSize = 1.5f, bool showShadow = false,
                ImVec4 bgColor = ImVec4(0.0f, 0.0f, 0.0f, 0.5f),
                ImVec4 textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
                ImVec4 shadowColor = ImVec4(0.0f, 0.0f, 0.0f, 0.5f));
bool ToggleButton(const char* label, bool* pToggle, float width, bool showText = false, float borderThickness = 5.0f);

// 英雄名称
string PlayerCharacter(int id);

// 文件操作
void read_line_without_newline(FILE* stream, char* buffer, size_t size);
void 写出文件(char *aaa, char *bbb);
char *读取文件(char *path);

// 纹理加载
ImTextureID ImAgeHeadFile(const unsigned char *buf, int len);
TextureInfo createTexture1(char* ImagePath);
TextureInfoa createTexturePNGFromMem(const unsigned char *buf, int len);
void 加载图片();
void 获取头像2();
void 获取图标();
TextureInfo 头像贴图(int 值);

// 绘图工具
void 绘制字体描边(float size, ImVec2 坐标, ImVec4 color, const char* str);
void 绘制加粗文本(float size, float x, float y, ImColor color, ImColor color1, const char* str);
void Box4Line(ImDrawList *draw, float thicc, int x, int y, int w, int h, int color);
void DrawStrokeText(int x, int y, ImVec4 color, const char *str);
void drawHexagonStar(float x, float y, float size, float rotation, ImDrawList* drawList, ImU32 color);
void DrawLogo(float x, float y, float size);
bool ButtonTextColored(const ImVec4& col, const char* fmt, ...);

// 网络
void createSocket();

// ============================================================
//  模块接口声明
// ============================================================

// memory/game_data
void DrawInit();
int 静态数据();
void DrawPlayer();
/*===== 坐标解密函数 - 已注释 =====
long getcoor(long addr);
===== 坐标解密函数 结束 =====*/

// render/overlay
string exec(string command);
int init_egl(int _screen_x, int _screen_y, bool log = false);
void screen_config();
void ImGui_init();
void shutdown();
void 上帝god();

// ui/menu
void tick();
void savesettings();
