# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal:     CMake file to set up the building for uKOS-X system.

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../Mkfiles/cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/Mkfiles/cmake/select-arm-toolchain.cmake)

project(
    gan
    VERSION 1.0
    LANGUAGES CXX C
)

set(DISPLAY WKS43WV067_5_Inches)
set(PATH_LVGL ${PATH_UKOS}/Third_Parties/LVGL)

# Microcontroller description (mandatory variables)
set(SOC STM32H743)
set(CORE CORTEX_M7)

# Target
set(BOARD Firefly_H743)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(-g3 # includes extra information for debugger
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    -Os # optimisation
)
add_compile_definitions(
    $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_STATIC_MEMORY=1>
    $<$<COMPILE_LANGUAGE:CXX>:CORTEX>
)

set(PATH_INCLUDES
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/flatbuffers/include
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/gemmlowp
    ${PATH_LVGL}/Library/${DISPLAY}
    ${PATH_LVGL}/Library/${DISPLAY}/${CORE}
    ${PATH_LVGL}/LVGL-current
    ${PATH_LVGL}/LVGL-current/src
    ${APP_DIR}/Classifier
    ${APP_DIR}/Graphics
)
find_library(MYLIB TFLite ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE})

set(OBJ
    ${PROJECT_SOURCE_DIR}/../Classifier/mlpn_classifier.c
    ${PROJECT_SOURCE_DIR}/../Graphics/lvgl.c
    ${PROJECT_SOURCE_DIR}/../Graphics/ui.c
    ${PROJECT_SOURCE_DIR}/stub.c
    ${PROJECT_SOURCE_DIR}/../Classifier/tfl_classifier.cpp
)

include(common)
