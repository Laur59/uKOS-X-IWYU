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
#   CMake file to build MicroPython library for uKOS-X.
#
# Build description:
#   Alternative way to build MicroPython static library for a given core.
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

# Include common MicroPython build setup
include(${CMAKE_CURRENT_LIST_DIR}/../Mkfiles/common-setup.cmake)

project(MicroPython_CORTEX_M33
    DESCRIPTION "MicroPython static library for Cortex_M33"
    LANGUAGES C
)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_LIST_DIR}/../Mkfiles/common-build.cmake)
