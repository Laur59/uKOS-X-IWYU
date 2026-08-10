# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.31)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(
    gan
    VERSION 1.0
    LANGUAGES CXX C
)

set(DISPLAY RK050HR18_5_Inches)
set(PATH_LVGL ${PATH_UKOS}/Third_Parties/LVGL)

# Microcontroller description (mandatory variables)
set(SOC STM32N657)
set(CORE CORTEX_M55)

# Target
set(BOARD Discovery_N657)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(-g3 # includes extra information for debugger
    -Os # optimisation
)
add_compile_definitions(
    USE_NN_HARDWARE
    $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_STATIC_MEMORY=1>
    $<$<COMPILE_LANGUAGE:CXX>:CORTEX>
)

set(PATH_INCLUDES
    ${PATH_LVGL}/Library/${DISPLAY}
    ${PATH_LVGL}/Library/${DISPLAY}/${CORE}
    ${PATH_LVGL}/LVGL-current
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/flatbuffers/include
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/gemmlowp
    ${PATH_UKOS}/Third_Parties/STM32/STM32N6/Library/AI/gan
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Classifier
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Graphics
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Graphics/Widgets
)
find_library(MYLIB0 TFLite ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE})
find_library(MYLIB1 NN_Hardware ${PATH_UKOS}/Third_Parties/STM32/STM32N6/Library/AI/gan)
set(MYLIB ${MYLIB0} ${MYLIB1})

set(OBJ
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Classifier/nnh_classifier.c
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Classifier/tfl_classifier.cpp
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Discovery_N657/stub.c
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Graphics/Widgets/Discovery_N657/background/background.c
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Graphics/lvgl.c
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/Graphics/ui.c
    ${PATH_UKOS}/Applications/uKOS_Demos/gan/gan.cpp
)

include(common)
