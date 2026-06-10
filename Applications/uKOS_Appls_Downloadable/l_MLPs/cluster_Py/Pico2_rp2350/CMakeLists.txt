# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

# Microcontroller description (mandatory variables)
set(SOC rp2350)
set(CORE "CORTEX_M33" CACHE STRING "Target core selection")
set_property(CACHE CORE PROPERTY STRINGS
    CORTEX_M33
    RV32IMAC
)

include(set-project-paths)

if(${CORE} STREQUAL "CORTEX_M33")
include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)
else()
    include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)
    set(CPU_FEATURES "zicsr;zifencei;zba;zbb;zbs;zbkb;user_mode")
endif()

project(
    cluster_Py
    VERSION 1.0
    LANGUAGES C
)

# Target
set(BOARD Pico2_rp2350)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(
    -g3 # include extra information for debugger
    -Os # optimisation
)

include(common)
