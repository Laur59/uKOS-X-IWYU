# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(
    team
    VERSION 1.0
    LANGUAGES C
)

set(DISPLAY WaveShare_2_Inches)
set(PATH_LVGL ${PATH_UKOS}/Third_Parties/LVGL)

# Microcontroller description (mandatory variables)
set(SOC STM32N657)
set(CORE CORTEX_M55)

# SOC has cache
add_compile_definitions(CACHE_D_S)

# Target
set(BOARD Nucleo_N657)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(
    -g3 # include extra information for debugger
    -Os # optimisation
    -Wno-sign-conversion
)

set(PATH_INCLUDES
    ${PATH_LVGL}/Library/${CORE}/${DISPLAY}
    ${PATH_LVGL}/LVGL-current
    ${PATH_LVGL}/LVGL-current/src
)

set(OBJ
    ${PROJECT_SOURCE_DIR}/../ui.c
    ${PROJECT_SOURCE_DIR}/stub.c
)

include(common)
