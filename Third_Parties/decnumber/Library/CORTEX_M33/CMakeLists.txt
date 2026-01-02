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
#   CMake file to build decnumber library for uKOS-X.
#
# Build description:
#   Alternative way to build decnumber static library for a given core.
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

# Include common build setup
include(${CMAKE_CURRENT_LIST_DIR}/../Mkfiles/common-setup.cmake)
include(${PATH_UKOS}/Ports/Mkfiles/cmake/select-arm-toolchain.cmake)

project(DecNumber_CORTEX_M33
    DESCRIPTION "decnumber static library for Cortex_M33"
    LANGUAGES C
)

set(FLAGS_FP -mfloat-abi=hard -mfpu=fpv5-sp-d16)
set(CPU_SPEC -mcpu=cortex-m33 -mthumb)
set(FLAGS_UKOS LITTLE_ENDIAN_S SECURE_S)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/../Mkfiles/common-build.cmake)
