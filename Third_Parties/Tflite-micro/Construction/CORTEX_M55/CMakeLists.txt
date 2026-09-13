# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# uKOS-X build system
# Builds the Tflite-micro library for Cortex-M55

cmake_minimum_required(VERSION 3.31)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)
set(CMAKE_C_COMPILER_TARGET thumbv8.1m.main-unknown-none-eabihf)     # Clang only; ignored by GCC
set(CMAKE_CXX_COMPILER_TARGET thumbv8.1m.main-unknown-none-eabihf)

project(TFLite_CORTEX_M55
    DESCRIPTION "Tflite-micro static library for Cortex_M55"
    LANGUAGES C CXX
)

set(TFLITE_TREE CORTEX_M_generic)
set(TFLITE_BUILD_TYPE debug)
set(CPU_SPEC -mcpu=cortex-m55 -mfloat-abi=hard)
set(CMSIS_DEVICE ARMCM55)
set(TFLITE_DEFS CPU_M55=1 ARM_MODEL_USE_PMU_COUNTERS)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
