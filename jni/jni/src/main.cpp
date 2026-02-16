// ============================================================
// main.cpp - 程序入口
// 由 Tomatosauce 移植 / 重构
// ============================================================
#include "common/GlobalVars.h"
#include "common/Functions.h"
#include <thread>
#include <chrono>
#include <sys/prctl.h> // [AntiCheat] Added
#include <sys/ptrace.h> // [AntiCheat] Anti-Debug
#include "utils/Security.h" // [AntiCheat] Phase 10
#include "utils/ErrorHandler.h"

// 触摸模块 (在 Android_touch 中定义)
extern void Init_touch_config();

int main(int argc, char *argv[]){
    // [AntiCheat] Anti-Debug
    ptrace(PTRACE_TRACEME, 0, 0, 0);

    // [AntiCheat] Process Masquerading
    // 1. Hide process name from 'top' / 'ps'
    prctl(PR_SET_NAME, "usap64", 0, 0, 0);
    
    // 2. Hide command line arguments (e.g. process name in ps -ef)
    if (argc > 0 && argv[0]) {
        memset(argv[0], 0, strlen(argv[0]));
        strcpy(argv[0], "usap64");
    }

    // [AntiCheat] Removed risky `rm -r` command
    // system("rm -r /data/data/com.tencent.tmgp.sgame/files/ano_tmp/*  >/dev/null 2>&1");

    screen_config();
    init_screen_x = screen_x + screen_y;
    init_screen_y = screen_y + screen_x;
    if(!init_egl(init_screen_x,init_screen_y)){
        FatalExit(REASON_EGL_INIT_FAILED);
    }
    ImGui_init();
    // [AntiCheat] Phase 10: Integrity & Anti-Frida Loop
    std::thread security_thread([]() {
        // [AntiCheat] Record initial checksum
        uint32_t initial_crc = Security::CheckSelfCRC();
        
        while (g_Running) { // [Refinement] Controlled exit
            // 1. Anti-Debug: Process Tracing
            if (Security::CheckTracerPid()) FatalExit(REASON_SECURITY_VIOLATION);
            
            // 2. Anti-Frida: Ports & Memory Maps
            if (Security::CheckFridaPorts() || Security::CheckFridaMaps()) FatalExit(REASON_SECURITY_VIOLATION);

            // 3. Integrity: Runtime CRC Check
            if (Security::CheckSelfCRC() != initial_crc) FatalExit(REASON_SECURITY_VIOLATION);

            // Add a slight delay to avoid eating CPU in this thread
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });
    security_thread.detach();

    Init_touch_config();
    while (1)
    {
        tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // [Stability] CPU Saver (1ms)
    }
    shutdown();
    return 0;
}
