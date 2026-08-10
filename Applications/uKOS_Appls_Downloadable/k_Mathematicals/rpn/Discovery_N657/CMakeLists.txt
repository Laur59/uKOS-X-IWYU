# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.31)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(
    rpn
    VERSION 1.0
    LANGUAGES C
)

set(PATH_DECNUMBER ${PATH_UKOS}/Third_Parties/decnumber)

# Microcontroller description (mandatory variables)
set(SOC STM32N657)
set(CORE CORTEX_M55)

# Target
set(BOARD Discovery_N657)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(
    -g3 # include extra information for debugger
    -Os # optimisation
)

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    set(CFLAGS_APPEND -Wno-c++-keyword)
endif()

set(PATH_INCLUDES
    ${PATH_DECNUMBER}/decnumber-current/include
    ${PATH_DECNUMBER}/decnumber-current/include/libdecnumber
)
find_library(MYLIB decnumber ${PATH_DECNUMBER}/Library/${CORE})

include(common)
