# common-build.
# =============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-10-07
# Modifs:
#
# Project:  uKOS-X
# Goal:     Common CMake file to build MicroPython library for uKOS-X.
#
# Description:
#           Shared template to build MicroPython static library for a given core
#           Requires: CORE_NAME to be defined before including this file
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

option(BUILD_VERBOSE "Increase build verbosity" OFF)

if((NOT ${BUILD_VERBOSE}) AND (NOT DEFINED ENV{BUILD_VERBOSE}))
    message("Tip: Use -DBUILD_VERBOSE=ON or set BUILD_VERBOSE in your environment to increase build verbosity.")
else()
    set(BUILD_VERBOSE ON)
endif()

# Extract core name from project name with strict validation
if(CMAKE_PROJECT_NAME MATCHES "^MicroPython_(.+)$")
    set(CORE_NAME ${CMAKE_MATCH_1})
    message("Building MicroPython for core: ${CORE_NAME}")
else()
    message(FATAL_ERROR "Project name '${CMAKE_PROJECT_NAME}' does not follow expected naming convention.\n"
                        "Expected format: MicroPython_<CORE_NAME> (e.g., MicroPython_CORTEX_M4)")
endif()

# MicroPython source directory
if(NOT DEFINED MICROPY_DIR)
    set(MICROPY_DIR "${PATH_UKOS}/Third_Parties/MicroPython/MicroPython-current")
endif()

# Check that the directory exists
if(NOT EXISTS ${MICROPY_DIR})
    message(FATAL_ERROR "MicroPython source directory not found: ${MICROPY_DIR}")
endif()

# Check for a core header file to ensure the repo is fully cloned
set(MICROPY_CORE_HEADER ${MICROPY_DIR}/py/mpstate.h)
if(NOT EXISTS ${MICROPY_CORE_HEADER})
    message(FATAL_ERROR "MicroPython source seems incomplete or corrupted.\n"
                        "Expected core file not found: ${MICROPY_CORE_HEADER}\n"
                        "Please clone the repository or verify the path.")
endif()

message(STATUS "Using MicroPython source at ${MICROPY_DIR}")

# Include core source components.
include(${MICROPY_DIR}/py/py.cmake)
list(APPEND MICROPY_SOURCE_PY ${MICROPY_PY_DIR}/nlraarch64.c) # add file present in list of py.mk

# Enable adding user modules
include(${MICROPY_DIR}/py/usermod.cmake)

# List of files to pass to pre-compiler scripts that build required helper and qstring files
set(MICROPY_SOURCE_QSTR
    ${MICROPY_SOURCE_USERMOD}
    ${MICROPY_SOURCE_PY}
    ${MICROPY_DIR}/shared/runtime/stdout_helpers.c
    ${MICROPY_DIR}/shared/runtime/pyexec.c
    ${MICROPY_DIR}/shared/readline/readline.c
)

# Optional libm sources
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libm_src.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/libm_src.cmake)
endif()

# Include per-core configuration
include(${CMAKE_CURRENT_SOURCE_DIR}/core_settings.cmake)

# Build static library libMicroPython.a
set(MICROPY_TARGET MicroPython)
add_library(${MICROPY_TARGET} STATIC)

target_sources(${MICROPY_TARGET} PRIVATE
    ${MICROPY_MPVERSION}
    ${MICROPY_SOURCE_QSTR}
    ${MICROPY_SOURCE_LIB_LIBM}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../uKOS_System/help.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../uKOS_System/headerMicroPython.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../uKOS_System/microPython.c
)

# Super-optimisation flag for performance-critical files (following py.mk line 22)
if(NOT DEFINED CSUPEROPT)
    set(CSUPEROPT "-O3")
endif()

# From lines 273 and 276 of py.mk: apply dedicated flags to some files for better performance
set_source_files_properties(${MICROPY_PY_DIR}/gc.c ${MICROPY_PY_DIR}/vm.c PROPERTIES COMPILE_OPTIONS "${CSUPEROPT}")

target_include_directories(${MICROPY_TARGET} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${MICROPY_DIR}
    ${CMAKE_BINARY_DIR}
    ${PATH_UKOS}
    ${PATH_UKOS}/OS
    ${PATH_UKOS}/OS/Includes
    ${PATH_UKOS}/OS/Lib_generics
    ${PATH_UKOS}/OS/Lib_peripherals
    ${PATH_UKOS}/OS/Lib_serials
    ${PATH_UKOS}/OS/Lib_kernels
    ${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime
    ${PATH_UKOS}/Third_Parties/MicroPython/uKOS_System
)

target_link_libraries(${MICROPY_TARGET} PUBLIC
    core_flags
)

target_compile_definitions(${MICROPY_TARGET} PUBLIC
    THIRD_PARTY_S
    _POSIX_C_SOURCE=200809L
)

target_compile_options(${MICROPY_TARGET} PUBLIC
    -std=c23
    -nostdlib
    -Wall
    -Wno-pedantic
    $<$<C_COMPILER_ID:GNU>:-Wno-dangling-pointer>
    -fshort-enums
    $<$<C_COMPILER_ID:GNU>:-mpoke-function-name>
)

# Include MicroPython mkrules.cmake (after object target exists!)
set(MICROPY_BUILD_TARGET ${MICROPY_TARGET})
include(${MICROPY_DIR}/py/mkrules.cmake)

# Installation
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS ${MICROPY_TARGET} ARCHIVE DESTINATION .)

# Strip unnecessary symbols after build
add_custom_command(TARGET ${MICROPY_TARGET}
    POST_BUILD
    COMMAND ${CMAKE_STRIP} --strip-unneeded lib${MICROPY_TARGET}.a
)

# Post-build notification
add_custom_command(TARGET ${MICROPY_TARGET}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
    COMMAND ${CMAKE_COMMAND} -E echo "🎉 Build Complete: ${PROJECT_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "📦 Output: lib${TARGET_LIB}.a"
    COMMAND ${CMAKE_COMMAND} -E echo "🔧 Core: ${CORE_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
)
