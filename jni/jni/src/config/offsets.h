#ifndef OFFSETS_H
#define OFFSETS_H

// ============================================================
// Honor of Kings Offsets Management
// Just modify values here for new seasons
// ============================================================

// ---- Static Data (libGameCore.so bss) ----
#define OFF_CoordModule         0x195968
#define OFF_RealCoord           0x13A0F0
#define OFF_RealCoord_L1        0x220
#define OFF_RealCoord_L2        0x78

// ---- Matrix (libil2cpp.so bss) ----
#define OFF_MatrixBase          0xC45DD0
#define OFF_Matrix_L1           0xb8
#define OFF_Matrix_L2           0x0
#define OFF_Matrix_L3           0x10
#define OFF_Matrix_Data         0x100

// ---- Game State (libGameCore.so bss) ----
#define OFF_GameState           0x20DBC

// ---- Hero Array (libGameCore.so bss) ----
#define OFF_HeroArray           0x383A0
#define OFF_HeroArray_PTR1      0x120
#define OFF_HeroArray_Step      0x18
#define OFF_HeroArray_PTR2      0x68
#define OFF_HeroArray_PTR3      0x48
#define OFF_HeroArray_PTR4      0xD8

// ---- Coordinate Iteration ----
#define OFF_CoordIter_Step      0x1
#define OFF_CoordIter_Coord     0x30

// ---- Coordinate Check ID ----
#define OFF_CheckID1            0xA8   // Negative offset
#define OFF_CheckID2            0xA4
#define OFF_CheckID3            0xA0

// ---- Hero Attributes (bingxiang6 base) ----
#define OFF_HeroID              0x30
#define OFF_HeroCamp            0x3C
#define OFF_HeroV3Check         0x308
#define OFF_HeroHealthPtr       0x168
#define OFF_CurrentHealth       0x98
#define OFF_MaxHealth           0xa0

// ---- Hero Coordinates ----
#define OFF_CoordX              0xF8
#define OFF_CoordY              0x100

// ---- Hero Coordinate Chain (bingxiang1) ----
#define OFF_CoordModule_BX1     0x1F0

// ---- Skill System ----
#define OFF_SkillBase           0x148
#define OFF_Skill1_L1           0xD8
#define OFF_Skill2_L1           0xF0
#define OFF_Skill3_L1           0x108
#define OFF_Skill_CD_L2         0x100
#define OFF_Skill_CD_Value      0xD4
#define OFF_Skill_UltDC         0xDC
#define OFF_Skill_Icon_L2       0x60
#define OFF_Skill_Icon_Value    0x10
#define OFF_Skill_CD_Div        8192000

// ---- Recall ----
#define OFF_Recall_L1           0x168
#define OFF_Recall_L2           0x118
#define OFF_Recall_Value        0x20

// ---- Summoner Skills ----
#define OFF_SummonBase          0x150
#define OFF_Summon_L1           0x150
#define OFF_Summon_L2_CD        0xf8
#define OFF_Summon_CD_Value     0x3c
#define OFF_Summon_L2_Icon      0xC8
#define OFF_Summon_Icon_Value   0x10

// ---- Vision ----
#define OFF_VisionBase          0x260
#define OFF_Vision_L1           0x68
#define OFF_Vision_Self         0x18
#define OFF_Vision_Enemy        0x38

// ---- God View (libil2cpp.so base) ----
#define OFF_God_L1              0xE750
#define OFF_God_L2              0xB8
#define OFF_God_Write           0x274

// ---- Jungle (libGameCore.so bss) ----
#define OFF_JungleBase          0x37D10
#define OFF_Jungle_L1           0x3B0
#define OFF_Jungle_L2           0x88
#define OFF_Jungle_L3           0x120
#define OFF_Jungle_Step         0x18
#define OFF_Jungle_MaxCD        0x1e4
#define OFF_Jungle_CD           0x240
#define OFF_Jungle_ID           0xC0
#define OFF_Jungle_EntityPtr    0x398
#define OFF_Jungle_Coord_L1     0x230
#define OFF_Jungle_Coord_L2     0xf0
#define OFF_Jungle_Coord_L3     0x10
#define OFF_Jungle_HealthPtr    0x168
#define OFF_Jungle_Health       0x98
#define OFF_Jungle_MaxHealth    0x8
#define OFF_Jungle_FixedX       0x2b8
#define OFF_Jungle_FixedY       0x2C0
#define OFF_Jungle_Time         0x238
#define OFF_Jungle_SendX        0x2b0
#define OFF_Jungle_SendY        0x2b8

// ---- Minions (libGameCore.so bss, reuse CoordModule) ----
#define OFF_Minion_L1           0x138
#define OFF_Minion_L2           0x108
#define OFF_Minion_Step         0x18
#define OFF_Minion_Camp         0x3C
#define OFF_Minion_HealthPtr    0x168
#define OFF_Minion_Health       0x98
#define OFF_Minion_MaxHealth    0xA0
#define OFF_Minion_CoordBase    0x2c0
#define OFF_Minion_Coord_L1     0x30
#define OFF_Minion_Coord_L2     0x10

#endif // OFFSETS_H
