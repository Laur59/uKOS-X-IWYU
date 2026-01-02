# user_modules.
# =============

#------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Project: uKOS-X
#
# Purpose:
#   CMake file for building the uKOS MicroPython modules.
#
#   This top-level micropython.cmake is responsible for listing
#   the individual modules we want to include.
#   Paths are absolute, and ${CMAKE_CURRENT_LIST_DIR} can be
#   used to prefix subdirectories.
#   Map to variable SRC_MOD in makefile of cores.
#------------------------------------------------------------------------

# Add led module.
include(${CMAKE_CURRENT_LIST_DIR}/led/micropython.cmake)

# Add serial module.
include(${CMAKE_CURRENT_LIST_DIR}/serial/micropython.cmake)

# Add switch module.
include(${CMAKE_CURRENT_LIST_DIR}/switch/micropython.cmake)

# Add example module.
include(${CMAKE_CURRENT_LIST_DIR}/example/micropython.cmake)
