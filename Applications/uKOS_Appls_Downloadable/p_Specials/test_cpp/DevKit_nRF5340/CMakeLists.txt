# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.31)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(
    test_cpp
    VERSION 1.0
    LANGUAGES C CXX
)

# Microcontroller description (mandatory variables)
set(SOC nRF5340)
set(CORE CORTEX_M33)
set(BASE Base_App)

# Target
set(BOARD DevKit_nRF5340)
set(VARIANT Variant_Test_App)

# Extra compilation options
add_compile_options(-g3 # includes extra information for debugger
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++23>
    $<$<COMPILE_LANGUAGE:C>:-std=c23> # STANDARD
    -Os # optimisation
)

set(OBJ
    ${APP_DIR}/demo_class.cpp
)

include(common)
