# CMakeLists.
# ===========

#------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Project: uKOS-X
#
# Purpose:
#   CMake file to build FatFs library for uKOS-X.
#
# Build description:
#   Alternative way to build FatFs static library for a given core.
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

# Include common build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)

project(FatFs_RV64IMAFDC
    DESCRIPTION "FatFs static library for RISC-V64"
    LANGUAGES C
)

set(FLAGS_FP -mabi=lp64d)
set(CPU_SPEC -march=rv64imafdc_zicsr_zifencei -mcmodel=medany)
set(FLAGS_UKOS LITTLE_ENDIAN_S SECURE_S)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
