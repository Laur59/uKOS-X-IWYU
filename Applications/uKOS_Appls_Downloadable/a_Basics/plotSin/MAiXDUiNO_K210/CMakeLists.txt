# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.31)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)

project(
    plotSin
    VERSION 1.0
    LANGUAGES C
)

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
)

include(common)
