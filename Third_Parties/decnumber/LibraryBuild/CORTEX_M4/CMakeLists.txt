# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds decnumber library for Cortex-M4

cmake_minimum_required(VERSION 3.26)

# Include common build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(DecNumber_CORTEX_M4
    DESCRIPTION "decnumber static library for Cortex_M4"
    LANGUAGES C
)

set(FLAGS_FP -mfloat-abi=hard -mfpu=fpv4-sp-d16)
set(CPU_SPEC -mcpu=cortex-m4)
set(FLAGS_UKOS SECURE_S)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
