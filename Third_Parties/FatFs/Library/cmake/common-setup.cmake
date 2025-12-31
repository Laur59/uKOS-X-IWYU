# common-setup.
# =============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-10-11
# Modifs:
#
# Project:  uKOS-X
# Goal:     Common CMake setup for all FatFs core builds
#
# Description:
#           Shared configuration used by all per-core CMakeLists.txt files.
#           This file establishes PATH_UKOS, includes the toolchain,
#           and sets up default build configuration.
#
#   Copyright 2025-2026, Laurent von Allmen
#   ---------------------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

# Compute PATH_UKOS from directory structure
# CMAKE_CURRENT_LIST_DIR points to the directory containing this file (Library/)
get_filename_component(PATH_UKOS "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE)
set(PATH_FATFS "${PATH_UKOS}/Third_Parties/FatFs")

# Verify PATH_UKOS points to a valid uKOS-X root directory
if(NOT EXISTS "${PATH_UKOS}/OS/Includes")
    message(FATAL_ERROR "Invalid PATH_UKOS: ${PATH_UKOS}\n"
                        "Expected uKOS-X root directory with OS/Includes subdirectory.\n"
                        "Consider setting PATH_UKOS explicitly or check directory structure.")
endif()

# Set build type to reduce firmware size (automatically adds -Os -DNDEBUG)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE MinSizeRel CACHE STRING "Build type")
endif()
