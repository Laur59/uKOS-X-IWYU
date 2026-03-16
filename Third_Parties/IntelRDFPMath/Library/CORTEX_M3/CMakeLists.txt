# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds IntelRDFPMath library for Cortex-M3

cmake_minimum_required(VERSION 3.26)

# Include common build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(IntelRDFPMath_CORTEX_M3
    DESCRIPTION "Intel RDFP Math static library for Cortex_M3"
    LANGUAGES C
)

set(FLAGS_FP -mfloat-abi=soft)
set(CPU_SPEC -mcpu=cortex-m3)
set(FLAGS_UKOS SECURE_S)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
