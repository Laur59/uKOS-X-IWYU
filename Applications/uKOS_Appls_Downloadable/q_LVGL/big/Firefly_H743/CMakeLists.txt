# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal: CMake file to set up the building for uKOS-X system.

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(
    big
    VERSION 1.0
    LANGUAGES C
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
add_compile_options(
    -g3 # include extra information for debugger
    -Os # optimisation
    -Wno-sign-conversion
)

set(PATH_INCLUDES
    ${PATH_LVGL}/Library/${DISPLAY}
    ${PATH_LVGL}/Library/${DISPLAY}/${CORE}
    ${PATH_LVGL}/LVGL-current
    ${PATH_LVGL}/LVGL-current/src
)

set(OBJ
    ${PROJECT_SOURCE_DIR}/../lvgl.c
    ${PROJECT_SOURCE_DIR}/../ui.c
    ${PROJECT_SOURCE_DIR}/stub.c
)

include(common)
