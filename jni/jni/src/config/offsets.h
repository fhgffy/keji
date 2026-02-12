#ifndef OFFSETS_H
#define OFFSETS_H

// ============================================================
// 王者荣耀偏移量集中管理
// 适配新赛季时只需修改此文件中的值
// ============================================================

// ---- 静态数据 (libGameCore.so bss) ----
#define OFF_坐标模块         0x195968
#define OFF_真实坐标         0x13A0F0
#define OFF_真实坐标_一层    0x220
#define OFF_真实坐标_二层    0x78

// ---- 矩阵 (libil2cpp.so bss) ----
#define OFF_矩阵基址         0xC45DD0
#define OFF_矩阵_一层       0xb8
#define OFF_矩阵_二层       0x0
#define OFF_矩阵_三层       0x10
#define OFF_矩阵_数据       0x100

// ---- 游戏状态判断 (libGameCore.so bss) ----
#define OFF_游戏状态         0x20DBC

// ---- 人物数组 (libGameCore.so bss) ----
#define OFF_人物数组         0x383A0
#define OFF_人物数组_啥     0x120
#define OFF_人物数组_步长   0x18
#define OFF_人物数组_哦     0x68
#define OFF_人物数组_48     0x48
#define OFF_人物数组_D8_bx8 0xD8

// ---- 坐标遍历 ----
#define OFF_坐标遍历_步长   0x1
#define OFF_坐标遍历_zuobiao 0x30

// ---- 坐标判断ID ----
#define OFF_判断id1          0xA8   // 负偏移, 使用时 真实坐标第三层 - OFF_判断id1
#define OFF_判断id2          0xA4
#define OFF_判断id3          0xA0

// ---- 英雄属性 (bingxiang6 基址) ----
#define OFF_英雄ID           0x30
#define OFF_英雄阵营         0x3C
#define OFF_英雄V3判断       0x308
#define OFF_英雄血量指针     0x168
#define OFF_当前血量         0x98
#define OFF_最大血量         0xa0

// ---- 英雄坐标 ----
#define OFF_坐标X            0xF8
#define OFF_坐标Y            0x100

// ---- 英雄坐标链 (bingxiang1) ----
#define OFF_坐标模块_bx1     0x1F0

// ---- 技能系统 ----
#define OFF_技能基址         0x148
#define OFF_技能1_一层       0xD8
#define OFF_技能2_一层       0xF0
#define OFF_技能3_一层       0x108
#define OFF_技能_CD二层      0x100
#define OFF_技能_CD值        0xD4
#define OFF_技能_大招DC      0xDC
#define OFF_技能_图标二层    0x60
#define OFF_技能_图标值      0x10
#define OFF_技能_CD除数      8192000

// ---- 回城 ----
#define OFF_回城_一层        0x168
#define OFF_回城_二层        0x118
#define OFF_回城_值          0x20

// ---- 召唤师技能 ----
#define OFF_召唤基址         0x150
#define OFF_召唤_一层        0x150
#define OFF_召唤_二层_CD     0xf8
#define OFF_召唤_CD值        0x3c
#define OFF_召唤_二层_图标   0xC8
#define OFF_召唤_图标值      0x10

// ---- 视野 ----
#define OFF_视野基址         0x260
#define OFF_视野_一层        0x68
#define OFF_视野_己方        0x18
#define OFF_视野_敌方        0x38

// ---- 上帝视角 (libil2cpp.so base) ----
#define OFF_上帝_一层        0xE750
#define OFF_上帝_二层        0xB8
#define OFF_上帝_写入        0x274

// ---- 野怪 (libGameCore.so bss) ----
#define OFF_野怪基址         0x37D10
#define OFF_野怪_一层        0x3B0
#define OFF_野怪_二层        0x88
#define OFF_野怪_三层        0x120
#define OFF_野怪_步长        0x18
#define OFF_野怪_maxcd       0x1e4
#define OFF_野怪_cd          0x240
#define OFF_野怪_id          0xC0
#define OFF_野怪_实体指针    0x398
#define OFF_野怪_坐标一层    0x230
#define OFF_野怪_坐标二层    0xf0
#define OFF_野怪_坐标三层    0x10
#define OFF_野怪_血量指针    0x168
#define OFF_野怪_血量        0x98
#define OFF_野怪_血量最大    0x8
#define OFF_野怪_固定坐标X   0x2b8
#define OFF_野怪_固定坐标Y   0x2C0
#define OFF_野怪_时间        0x238
#define OFF_野怪_传输X       0x2b0
#define OFF_野怪_传输Y       0x2b8

// ---- 兵线 (libGameCore.so bss, 复用坐标模块) ----
#define OFF_兵线_一层        0x138
#define OFF_兵线_二层        0x108
#define OFF_兵线_步长        0x18
#define OFF_兵线_阵营        0x3C
#define OFF_兵线_血量指针    0x168
#define OFF_兵线_血量        0x98
#define OFF_兵线_血量最大    0xA0
#define OFF_兵线_坐标基址    0x2c0
#define OFF_兵线_坐标一层    0x30
#define OFF_兵线_坐标二层    0x10

#endif // OFFSETS_H
