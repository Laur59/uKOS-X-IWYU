# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-10-08
# Modifs:
#
# Project:  uKOS-X
# Goal:     CMake file to build MicroPython library for uKOS-X.
#
# Description:
#           An alternative way using cmake is proposed to build the
#           MicroPython library for a given core.
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

cmake_minimum_required(VERSION 3.26)

# Include common MicroPython build setup
include(${CMAKE_CURRENT_LIST_DIR}/../Mkfiles/common-setup.cmake)

project(MicroPython_CORTEX_M7
    DESCRIPTION "MicroPython static library for Cortex_M7"
    LANGUAGES C
)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_LIST_DIR}/../Mkfiles/common-build.cmake)
