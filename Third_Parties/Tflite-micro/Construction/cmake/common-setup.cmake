# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Purpose:
#   Common CMake setup for all Tflite-micro core builds.
#
# Build description:
#   Shared configuration used by all per-core CMakeLists.txt files.
#   This file establishes PATH_UKOS and PATH_TFLITE; the per-core file then
#   includes the toolchain (USE_LLVM, default ON, selects Clang or GNU gcc).
#
# Reproducibility:
#   This build definition is intended to be deterministic and reproducible.
#   Given identical source inputs, build configuration, toolchain versions,
#   and build environment, the produced static libraries are expected to be
#   bit-for-bit identical.

# Compute PATH_UKOS from directory structure
# CMAKE_CURRENT_LIST_DIR points to the directory containing this file (Construction/cmake/)
get_filename_component(PATH_UKOS "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE)
set(PATH_TFLITE "${PATH_UKOS}/Third_Parties/Tflite-micro")

# Verify PATH_UKOS points to a valid uKOS-X root directory
if(NOT EXISTS "${PATH_UKOS}/OS/Includes")
    message(FATAL_ERROR "Invalid PATH_UKOS: ${PATH_UKOS}\n"
                        "Expected uKOS-X root directory with OS/Includes subdirectory.")
endif()
