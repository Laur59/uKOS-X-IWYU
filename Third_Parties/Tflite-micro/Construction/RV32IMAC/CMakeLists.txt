# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# uKOS-X build system
# Builds the Tflite-micro library for RV32IMAC

cmake_minimum_required(VERSION 3.31)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)
set(CMAKE_C_COMPILER_TARGET riscv32-unknown-elf)     # Clang only; ignored by GCC
set(CMAKE_CXX_COMPILER_TARGET riscv32-unknown-elf)

project(TFLite_RV32IMAC
    DESCRIPTION "Tflite-micro static library for RV32IMAC"
    LANGUAGES C CXX
)

set(TFLITE_TREE RISCV64_generic)
set(TFLITE_BUILD_TYPE release)
set(CPU_SPEC -march=rv32imac -mabi=ilp32)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
