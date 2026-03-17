# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

# CMakeLists.
# ===========

#------------------------------------------------------------------------
# Project:  uKOS-X
# Goal:     CMake file to set up the building for uKOS-X system.
#
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)

project(
    basic
    VERSION 1.0
    LANGUAGES C
)

set(DISPLAY TFT_2_4_Inches)
set(PATH_LVGL ${PATH_UKOS}/Third_Parties/LVGL)

# Microcontroller description (mandatory variables)
set(SOC K210)
set(CORE RV64IMAFDC)

# Target
set(BOARD MAiXDUiNO_K210)
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
