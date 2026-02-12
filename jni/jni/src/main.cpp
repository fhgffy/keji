// ============================================================
// main.cpp - 程序入口
// 由 Tomatosauce 移植 / 重构
// ============================================================
#include "globals.h"

// 触摸模块 (在 Android_touch 中定义)
extern void Init_touch_config();

int main(){

    system("rm -r /data/data/com.tencent.tmgp.sgame/files/ano_tmp/*  >/dev/null 2>&1");

    screen_config();
    init_screen_x = screen_x + screen_y;
    init_screen_y = screen_y + screen_x;
    if(!init_egl(init_screen_x,init_screen_y)){
        exit(0);
    }
    ImGui_init();
    Init_touch_config();
    while (1)
    {
        tick();
    }
    shutdown();
    return 0;
}
