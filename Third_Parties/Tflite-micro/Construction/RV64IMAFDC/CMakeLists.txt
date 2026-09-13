# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# uKOS-X build system
# Builds the Tflite-micro library for RV64IMAFDC

cmake_minimum_required(VERSION 3.31)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)
set(CMAKE_C_COMPILER_TARGET riscv64-unknown-elf)     # Clang only; ignored by GCC
set(CMAKE_CXX_COMPILER_TARGET riscv64-unknown-elf)

project(TFLite_RV64IMAFDC
    DESCRIPTION "Tflite-micro static library for RV64IMAFDC"
    LANGUAGES C CXX
)

set(TFLITE_TREE RISCV64_generic)
set(TFLITE_BUILD_TYPE release)
set(CPU_SPEC -march=rv64imafdc -mabi=lp64d)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
