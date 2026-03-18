# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(
    readIMU
    VERSION 1.0
    LANGUAGES C
)

# Microcontroller description (mandatory variables)
set(SOC STM32H747)
set(CORE CORTEX_M7)

# Target
set(BOARD Asmodee_H747)
set(VARIANT Variant_Test_CM7)
set(BASE Base_CM7)

# Extra compilation options
add_compile_options(
    -g3 # include extra information for debugger
    -Os # optimisation
)
add_compile_definitions(${BOARD}_S)

include(common)
