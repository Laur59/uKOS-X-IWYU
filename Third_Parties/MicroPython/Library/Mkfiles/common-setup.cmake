# common-setup.
# =============

#------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Project: uKOS-X
#
# Purpose:
#   Common CMake setup for all MicroPython core builds.
#
# Build description:
#   Shared configuration used by all per-core CMakeLists.txt files.
#   This file establishes PATH_UKOS, includes the toolchain,
#   and sets up default build configuration.
#
# Reproducibility:
#   This build definition is intended to be deterministic and reproducible.
#   Given identical source inputs, build configuration, toolchain versions,
#   and build environment, the produced static libraries are expected to be
#   bit-for-bit identical.
#
#   The build does not embed wall-clock timestamps. Where applicable,
#   SOURCE_DATE_EPOCH is expected to be honored by all toolchain components.
#------------------------------------------------------------------------

# Compute PATH_UKOS from directory structure
# CMAKE_CURRENT_LIST_DIR points to the directory containing this file (Library/)
get_filename_component(PATH_UKOS "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE)

# Verify PATH_UKOS points to a valid uKOS-X root directory
if(NOT EXISTS "${PATH_UKOS}/OS/Includes")
    message(FATAL_ERROR "Invalid PATH_UKOS: ${PATH_UKOS}\n"
                        "Expected uKOS-X root directory with OS/Includes subdirectory.\n"
                        "Consider setting PATH_UKOS explicitly or check directory structure.")
endif()

# Include toolchain
include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

# Set build type to reduce firmware size (automatically adds -Os -DNDEBUG)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE MinSizeRel CACHE STRING "Build type")
endif()

# Default user modules include (allow override)
if(NOT DEFINED USER_C_MODULES)
    set(USER_C_MODULES ${PATH_UKOS}/Third_Parties/MicroPython/uKOS_Interface/user_modules.cmake)
endif()
