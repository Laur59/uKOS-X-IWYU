# micropython.
# ============

#------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Project: uKOS-X
#
# Purpose:
#   CMake file for building the uKOS interface library.
#------------------------------------------------------------------------

# Create an INTERFACE library for our serial module.
add_library(usermod_serial INTERFACE)

# Add our source files to the lib
target_sources(usermod_serial INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/serial.c
)

# Add the current directory as an include directory.
target_include_directories(usermod_serial INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE usermod_serial)
