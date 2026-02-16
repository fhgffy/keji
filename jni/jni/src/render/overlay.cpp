// ============================================================
// overlay.cpp - EGL窗口初始化 / 覆盖层模块
// ============================================================
#include "utils/ErrorHandler.h"
#include "TextureUtils.h"
#include "common/GlobalVars.h"
#include "common/Functions.h"
#include "config/settings.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"
#include "imgui.h"
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "obfuscate.h"
#include "oxorany.h"
#include "FONTS/Font.h"
#include "imgui/font/Font.h"
#include "FONTS/Social.h"
#include "FONTS/F47.h"
#include "FONTS/F48.h"
#include "FONTS/F19.h"
#include "FONTS/F50.h"
#include "FONTS/F68.h"
#include "FONTS/F86.h"
#include "FONTS/LoginLogo.h"
#include "memory/driver.h"
#include "config/offsets.h"

#include <linux/input.h>

// ---- exec ----
string exec(string command) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "popen failed!";
    }
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr){
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

// ---- EGL 初始化 ----
int init_egl(int _screen_x, int _screen_y, bool log)
{
    // [AntiCheat] Removed noisy system/popen calls for stealth
    // settings put system/global/secure block_untrusted_touches 0
    // This should be done manually or via a cleaner method if needed.
    LOGD("[+] Skipped block_untrusted_touches setting for stealth\n");

    bool sgfop;
    string sfflp;
    // cout << "[+] 是否开启防录屏 1[开启] 2[关闭]: "; // [AntiCheat] Silence input
    // cin >> sfflp;
    sfflp = "2"; // Default to OFF for automation/stealth, or let user config. For now default off to avoid blocking.
    if (sfflp == "1")
        sgfop = true;
    else
        sgfop = false;

    if (sgfop) {
        LOGD("[+] 防录屏开启\n");
        // [AntiCheat] Randomize window title
        srand(time(NULL));
        string randomTitle = "";
        const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        for (int i = 0; i < 10; i++) randomTitle += charset[rand() % (sizeof(charset) - 1)];
        ::native_window = android::ANativeWindowCreator::Create(randomTitle.c_str(), _screen_x, _screen_y, true);
    }

    if (!sgfop) {
        LOGD("[+] 防录屏关闭\n");
        // [AntiCheat] Randomize window title
        srand(time(NULL));
        string randomTitle = "";
        const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        for (int i = 0; i < 10; i++) randomTitle += charset[rand() % (sizeof(charset) - 1)];
        native_window = android::ANativeWindowCreator::Create(randomTitle.c_str(), _screen_x, _screen_y, false);
    }

    ANativeWindow_acquire(native_window);
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (display == EGL_NO_DISPLAY) {
        LOGD("获取显示设备失败，错误码：%u\n", glGetError());
        return -1;
    }
    if (log) LOGD("获取显示设备成功\n");

    if (eglInitialize(display, 0, 0) != EGL_TRUE) {
        LOGD("初始化EGL失败，错误码：%u\n", glGetError());
        return -1;
    }
    if (log) LOGD("初始化EGL成功\n");

    EGLint num_config = 0;
    const EGLint attribList[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_BLUE_SIZE, 5,
        EGL_GREEN_SIZE, 6,
        EGL_RED_SIZE, 5,
        EGL_BUFFER_SIZE, 32,
        EGL_DEPTH_SIZE, 16,
        EGL_STENCIL_SIZE, 8,
        EGL_NONE};
    if (eglChooseConfig(display, attribList, nullptr, 0, &num_config) != EGL_TRUE) {
        LOGD("选择配置失败，错误码：%u\n", glGetError());
        return -1;
    }
    if (log) LOGD("配置数量：%d\n", num_config);

    if (!eglChooseConfig(display, attribList, &config, 1, &num_config)) {
        LOGD("选择配置失败，错误码：%u\n", glGetError());
        return -1;
    }
    if (log) LOGD("选择配置成功\n");

    EGLint egl_format;
    eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &egl_format);
    ANativeWindow_setBuffersGeometry(native_window, 0, 0, egl_format);
    const EGLint attrib_list[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
    context = eglCreateContext(display, config, EGL_NO_CONTEXT, attrib_list);
    if (context == EGL_NO_CONTEXT) {
        LOGD("创建上下文失败，错误码：%u\n", glGetError());
        return -1;
    }
    if (log) LOGD("创建上下文成功\n");

    surface = eglCreateWindowSurface(display, config, native_window, nullptr);
    if (surface == EGL_NO_SURFACE) {
        LOGD("创建表面失败，错误码：%u\n", glGetError());
        return -1;
    }
    if (log) LOGD("创建表面成功\n");

    if (!eglMakeCurrent(display, surface, surface, context)) {
        LOGD("设置当前上下文失败，错误码：%u\n", glGetError());
        return -1;
    }
    if (log) LOGD("设置当前上下文成功\n");

    return 1;
}

// ---- 屏幕配置 ----
void screen_config(){
    std::string window_size = exec("wm size");
    sscanf(window_size.c_str(),"Physical size: %dx%d",&screen_x,&screen_y);
    full_screen.ScreenX = screen_x;
    full_screen.ScreenY = screen_y;
    LOGD("[+] 分辨率: %dx%d\n", screen_x, screen_y);

    std::thread *orithread = new std::thread([&] {
        while(true){
            Orientation = atoi(exec("dumpsys display | grep 'mCurrentOrientation' | cut -d'=' -f2").c_str());
            if(Orientation == 0 || Orientation == 2){
                std::lock_guard<std::mutex> lock(ScreenMutex); // [ThreadSafety] Lock
                screen_x = full_screen.ScreenX;
                screen_y = full_screen.ScreenY;
            }
            if(Orientation == 1 || Orientation == 3){
                std::lock_guard<std::mutex> lock(ScreenMutex); // [ThreadSafety] Lock
                screen_x = full_screen.ScreenY;
                screen_y = full_screen.ScreenX;
            } else {
                std::string tempstr = exec("dumpsys input |grep orientation | tail -n 1 | awk '{print $6}'");
                int tempx = atoi(tempstr.substr(12,1).c_str());
                if(tempx == 0 || tempx ==1 || tempx == 2 || tempx==3 ){
                    Orientation = tempx;
                    std::lock_guard<std::mutex> lock(ScreenMutex); // [ThreadSafety] Lock
                    if(Orientation == 1 || Orientation == 3){
                        screen_x = full_screen.ScreenY;
                        screen_y = full_screen.ScreenX;
                    }else{
                        screen_x = full_screen.ScreenX;
                        screen_y = full_screen.ScreenY;
                    }
                }
            }
            std::this_thread::sleep_for(2.0s); // [AntiCheat] Increased interval from 0.5s to 2.0s
        }
    });
    orithread->detach();
}

// ---- ImGui 菜单样式 ----
static void ImGuiMenustyle(){
}

// ---- 音量键检测 ----
static int GetEventCount3()
{
    DIR *dir = opendir("/dev/input/");
    dirent *ptr = NULL;
    int count = 0;
    while ((ptr = readdir(dir)) != NULL) {
        if (strstr(ptr->d_name, "event"))
            count++;
    }
    return count ? count : -1;
}

static bool kang = true;

static int VolumeControl()
{
    int EventCount = GetEventCount3();
    if (EventCount < 0) {
        LOGD("未找到输入设备\n");
        return -1;
    }

    int *fdArray = (int *)malloc(EventCount * sizeof(int));

    for (int i = 0; i < EventCount; i++) {
        char temp[128];
        sprintf(temp, "/dev/input/event%d", i);
        fdArray[i] = open(temp, O_RDWR | O_NONBLOCK);
    }

    input_event ev;

    while (g_Running) {
        for (int i = 0; i < EventCount; i++) {
            memset(&ev, 0, sizeof(ev));
            read(fdArray[i], &ev, sizeof(ev));
            if (ev.type == EV_KEY && ev.code == KEY_VOLUMEUP && ev.value == 1 && kang == true) {
                FloatingWindow = true;
                WindowState = true;
            }
            else if (ev.type == EV_KEY && ev.code == KEY_VOLUMEDOWN && ev.value == 1 && kang == true) {
                FloatingWindow = false;
                WindowState = true;
            }
        }
        usleep(3000);
    }

    return 0;
}

// ---- 六角星绘制 ----
void drawHexagonStar(float x, float y, float size, float rotation, ImDrawList* drawList, ImU32 color){
    const int numPoints = 6;
    ImVec2 center(x, y);
    ImVec2 points[numPoints];
    for (int i = 0; i < numPoints; i++) {
        float angle = rotation + 2 * PI * i / numPoints;
        points[i] = ImVec2(center.x + size * cos(angle), center.y + size * sin(angle));
    }
    drawList->AddLine(points[0], points[2], color, 3.0f);
    drawList->AddLine(points[2], points[4], color, 3.0f);
    drawList->AddLine(points[4], points[0], color, 3.0f);
    drawList->AddLine(points[1], points[3], color, 3.0f);
    drawList->AddLine(points[3], points[5], color, 3.0f);
    drawList->AddLine(points[5], points[1], color, 3.0f);
}

// ---- 悬浮窗Logo绘制 ----
void DrawLogo(float x, float y, float size){
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    draw_list->AddImage(LogoImage,{x - size /1,y - size / 1},{x + size / 1,y + size / 1});
}

// ---- 上帝视距 ----
void GodFunction()
{
    pid = Driver->GetPID((char*)"com.tencent.tmgp.sgame");
    Driver->initialize(pid);
    lil2cpp_base = Driver->GetModuleBase((char*)"libil2cpp.so");
    long int xtemp = lil2cpp_base + 0x8BE1000;
    long int god_address = Driver->ReadPointer(Driver->ReadPointer(xtemp + 0x4220) + 0xA0) + 0x24;
    Driver->write<float>(god_address, godvalue);
}

// ---- ImGui 初始化 ----
void ImGui_init(){
    if (g_Initialized){
        return;
    }
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiStyle* style = &ImGui::GetStyle();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = NULL;
    io.ConfigWindowsMoveFromTitleBarOnly = true;
    io.IniFilename = NULL;
    static ImFontConfig font_cfg;
    font_cfg.SizePixels = 22.0f;
    io.Fonts->AddFontFromMemoryTTF((void *) OPPOSanss_H, OPPOSanss_H_size, 32.0f, &font_cfg, io.Fonts->GetGlyphRangesChineseFull());

    ImGui::StyleColorsDark();
    ImGui_ImplAndroid_Init(native_window);
    ImGui_ImplOpenGL3_Init("#version 300 es");
    io.ConfigWindowsMoveFromTitleBarOnly = true;
    io.IniFilename = NULL;
    style->Colors[ImGuiCol_WindowBg]  = ImColor(0, 0, 0, 0);
    style->WindowBorderSize = 0.0f;
    io.AnimationSpeed = 1;
    static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
    ImFontConfig icons_config;
    ImFontConfig CustomFont;
    CustomFont.FontDataOwnedByAtlas = false;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 2.5;
    icons_config.OversampleV = 2.5;
    ImFontConfig cfg;
    ImFontConfig font_config;
    font_config.PixelSnapH = false;
    font_config.OversampleH = 5;
    font_config.OversampleV = 5;
    font_config.RasterizerMultiply = 1.2f;
    static const ImWchar ranges[] ={ 0x0020, 0x00FF,  0x0400, 0x052F,  0x2DE0, 0x2DFF,  0xA640, 0xA69F,  0xE000, 0xE226,  0x2010, 0x205E,  0x0600, 0x06FF,  0xFE00, 0xFEFF,  0, };
    font_config.GlyphRanges = ranges;
    io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom3), sizeof(Custom3), 25.f, &CustomFont);
    CLOSE = io.Fonts->AddFontFromMemoryTTF(Loginc, sizeof(Loginc), 30.0f, &font_config, ranges);
    F48 = io.Fonts->AddFontFromMemoryTTF((void *)F48_data, F48_size, 30.0f, NULL, io.Fonts->GetGlyphRangesDefault());
    COLOR = io.Fonts->AddFontFromMemoryTTF((void *)F19_data, F19_size, 38.0f, NULL, io.Fonts->GetGlyphRangesDefault());
    F50 = io.Fonts->AddFontFromMemoryTTF((void *)F50_data, F50_size, 30.0f, NULL, io.Fonts->GetGlyphRangesDefault());
    F68 = io.Fonts->AddFontFromMemoryTTF((void *)F68_data, F68_size, 54.0f, NULL, io.Fonts->GetGlyphRangesDefault());
    SR = io.Fonts->AddFontFromMemoryTTF((void *)F48_data, F48_size, 30.0f, NULL, io.Fonts->GetGlyphRangesDefault());
    LOGIN = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom3), sizeof(Custom3), 20.f, &CustomFont);
    Subtab = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom3), sizeof(Custom3), 35.f, &CustomFont);
    F86 = io.Fonts->AddFontFromMemoryTTF((void *)F86_data, F86_size, 30.0f, NULL, io.Fonts->GetGlyphRangesDefault());
    Social = io.Fonts->AddFontFromMemoryTTF((void *)Social_data, Social_size, 30.0f, NULL, io.Fonts->GetGlyphRangesDefault());

    Config.ColorsESP.BotVisLine = CREATE_COLOR(255, 255, 255, 255);
    Config.ColorsESP.BotHideLine = CREATE_COLOR(255, 255, 255, 255);
    Config.ColorsESP.PlayerVisLine = CREATE_COLOR(0, 255, 0, 255);
    Config.ColorsESP.PlayerHideLine = CREATE_COLOR(255, 0, 0, 255);
    Config.ColorsESP.BotVisBox = CREATE_COLOR(255, 255, 255, 255);
    Config.ColorsESP.BotHideBox = CREATE_COLOR(255, 255, 0, 255);
    Config.ColorsESP.PlayerVisBox = CREATE_COLOR(0, 0, 0, 255);
    Config.ColorsESP.PlayerHideBox = CREATE_COLOR(255, 0, 0, 255);
    Config.ColorsESP.BotVisSkeleton = CREATE_COLOR(255, 255, 255, 255);
    Config.ColorsESP.BotHideSkeleton = CREATE_COLOR(200, 200, 0, 255);
    Config.ColorsESP.PlayerVisSkeleton = CREATE_COLOR(0, 0, 255, 255);
    Config.ColorsESP.PlayerHideSkeleton = CREATE_COLOR(255, 0, 0, 255);
    Config.ColorsESP.BotRadar = CREATE_COLOR(255, 255, 255, 255);
    Config.ColorsESP.PlayerRadar = CREATE_COLOR(0, 255, 0, 255);
    Config.ColorsESP.BotAlert = CREATE_COLOR(255, 255, 0, 255);
    Config.ColorsESP.PlayerAlert = CREATE_COLOR(0, 255, 0, 255);
    Config.ColorsESP.Fov = CREATE_COLOR(255, 255, 255, 255);
    Config.ColorsESP.Fova = CREATE_COLOR(0, 0, 255, 255);
    Config.IpadS = 87.0f;
    Config.SilentAim.Cross  = 350.0f;
    Config.AimBot.Cross  = 400.0f;
    Config.SilentAim.Meter  = 200.0f;
    Config.AimBot.Meter  = 300.0f;
    Config.AimBot.Recc  = 1.01f;
    Config.RadarX = 2.3f;
    Config.RadarY = 100.0f;
    Config.Line = 3.0f;
    Config.Skeleton = 2.0f;
    Config.Loot = 99.0f;
    g_Initialized = true;

    ImGui::StyleColorsClassic();
    LoadImages();
    GetAvatar2();
    GetIcons();
    std::thread(VolumeControl).detach();
    savesettings();
}

// ---- 关闭清理 ----
void shutdown(){
    if (!g_Initialized){
        return;
    }
    g_Running = false;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();
    ImGui::DestroyContext();
    if (display != EGL_NO_DISPLAY){
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        if (context != EGL_NO_CONTEXT){
            eglDestroyContext(display, context);
        }
        if (surface != EGL_NO_SURFACE){
            eglDestroySurface(display, surface);
        }
        eglTerminate(display);
    }
    display = EGL_NO_DISPLAY;
    context = EGL_NO_CONTEXT;
    surface = EGL_NO_SURFACE;
    ANativeWindow_release(native_window);
}
