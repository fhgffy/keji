#ifndef FUNC_H
#define FUNC_H

// Func.h - Global variable definitions for extern declarations in 配置.h
// These variables are declared as extern in 配置.h and need actual storage.

#include "timer.h"

// FPS related
int FPS = 60;
timer FPS限制;
float FPF显示 = 0.0f;

// Misc
uintptr_t Gmin = 0;

// Touch position
float 触摸位置X = 0.0f;
float 触摸位置Y = 0.0f;

#endif // FUNC_H
