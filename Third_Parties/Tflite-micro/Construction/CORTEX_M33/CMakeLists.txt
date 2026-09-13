# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# uKOS-X build system
# Builds the Tflite-micro library for Cortex-M33

cmake_minimum_required(VERSION 3.31)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)
set(CMAKE_C_COMPILER_TARGET thumbv8m.main-unknown-none-eabihf)     # Clang only; ignored by GCC
set(CMAKE_CXX_COMPILER_TARGET thumbv8m.main-unknown-none-eabihf)

project(TFLite_CORTEX_M33
    DESCRIPTION "Tflite-micro static library for Cortex_M33"
    LANGUAGES C CXX
)

set(TFLITE_TREE CORTEX_M_generic)
set(TFLITE_BUILD_TYPE debug)
set(CPU_SPEC -mcpu=cortex-m33 -mfloat-abi=hard)
set(CMSIS_DEVICE ARMCM33)
set(TFLITE_DEFS CPU_M33=1)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
