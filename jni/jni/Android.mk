# 由 Tomato sauce 移植
# 由 Tomato sauce 移植
# 由 Tomato sauce 移植

LOCAL_PATH := $(call my-dir)
# LOCAL_CFLAGS += -DDEBUG_MODE # Uncomment to enable logs
include $(CLEAR_VARS)
LOCAL_MODULE := R7wzry.sh
LOCAL_CPPFLAGS := -w -std=c++17

LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/Android_draw
# LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/Android_read  # 目录不存在
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/Android_shm
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/Android_touch
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/ImGui
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/native_surface
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/native_surface/aosp_10
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/native_surface/aosp_11
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/include/native_surface/aosp_12
# 新增模块目录的 include 路径
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/src
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/src/game
LOCAL_C_INCLUDES +=$(LOCAL_PATH)/src/Android_draw
LOCAL_C_INCLUDES += $(LOCAL_C_INCLUDES:$(LOCAL_PATH)/%:=%)

FILE_LIST += $(wildcard $(LOCAL_PATH)/src/*.cpp) $(wildcard $(LOCAL_PATH)/src/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/Android_draw/*.cpp) $(wildcard $(LOCAL_PATH)/src/Android_draw/*.c)
# FILE_LIST += $(wildcard $(LOCAL_PATH)/src/Android_read/*.cpp)  # 目录不存在
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/Android_shm/*.cpp) $(wildcard $(LOCAL_PATH)/src/Android_shm/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/Android_touch/*.cpp) $(wildcard $(LOCAL_PATH)/src/Android_touch/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/ImGui/*.cpp) $(wildcard $(LOCAL_PATH)/src/ImGui/*.c)
# FILE_LIST += $(wildcard $(LOCAL_PATH)/src/native_surface/*.cpp)  # 目录不存在
# 新增模块目录
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/common/*.cpp) $(wildcard $(LOCAL_PATH)/src/common/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/utils/*.cpp) $(wildcard $(LOCAL_PATH)/src/utils/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/math/*.cpp) $(wildcard $(LOCAL_PATH)/src/math/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/network/*.cpp) $(wildcard $(LOCAL_PATH)/src/network/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/config/*.cpp) $(wildcard $(LOCAL_PATH)/src/config/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/game/*.cpp) $(wildcard $(LOCAL_PATH)/src/game/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/memory/*.cpp) $(wildcard $(LOCAL_PATH)/src/memory/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/render/*.cpp) $(wildcard $(LOCAL_PATH)/src/render/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/ui/*.cpp) $(wildcard $(LOCAL_PATH)/src/ui/*.c)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_LDFLAGS += -lEGL -lGLESv2 -lGLESv3 -landroid -llog
include $(BUILD_EXECUTABLE)
