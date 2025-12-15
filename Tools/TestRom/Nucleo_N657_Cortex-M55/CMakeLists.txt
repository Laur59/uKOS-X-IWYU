# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-07-31
# Modifs:
#
# Project:	uKOS-X
# Goal:		Cmake file for building the testROM.
#
#   (c) 2025-20xx, Laurent von Allmen
#   ---------------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Description: Lightweight, real-time multitasking operating
#   system for embedded microcontroller and DSP-based systems.
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

# Add uKOS-X CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../Ports/Mkfiles/cmake")

# Project paths

# - PATH_UKOS	--> Main uKOS-X folder
# - PATH_VARI	--> Projects Root Variant folder
# - PATH_BASE	--> Projects Root Base folder
# - PATH_PORT	--> PATH_UKOS/Ports
include(set-project-paths)
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH PATH_TEST_ROM)

include(select-arm-toolchain)

project(
	Nucleo_N657_Cortex-M55_testROM
	VERSION 1.0
	LANGUAGES C
)

# Microcontroller description. Mandatory variables and include

set(SOC STM32N657)
set(CORE CORTEX_M55)

# Customisation of firmware copyright text

add_compile_definitions(
	"uKOS_NAME="
	"uKOS_OWNER=(c) LvA"
	"SECURE_S"
)

# Selection of script to transfer binary to SOC
set(BURN burn)

# Apply settings
include(proj_config)

# Extra compilation options

add_compile_options(
	-g # includes extra information for debugger
	-Os # OPTIMISATION
)

set(LOCAL_TARGET testROM)
set(TARGET_ELF ${LOCAL_TARGET}.elf)

list(APPEND PATH_INCLUDES
	${PATH_TEST_ROM}/_Commun
	${PATH_TEST_ROM}/_Commun/Includes
	${PATH_TEST_ROM}/_Commun/Runtime
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/Includes
	${CMAKE_SOURCE_DIR}/Includes/SOC
	${CMAKE_SOURCE_DIR}/Includes/Core
	${CMAKE_SOURCE_DIR}/Runtime
)
include_directories(${PATH_INCLUDES})

# Sources
# -------

add_executable(${TARGET_ELF}
    first.c
    init.c
    cmns.c
    tests.c
    ${PATH_TEST_ROM}/_Commun/Runtime/crt0.c
    ${PATH_TEST_ROM}/_Commun/Runtime/debug.c
)

target_link_libraries(${TARGET_ELF} PUBLIC core_compiler_flags)
target_compile_options(${TARGET_ELF} PUBLIC -Wall)

set(LINKS_LD Runtime/link_p.ld)
set(TARGET_COMMON_LINK_OPTIONS
	-T${LINKS_LD} # link script
	-L${CMAKE_SOURCE_DIR}
	$<$<C_COMPILER_ID:GNU>:-nostartfiles>
	$<$<AND:$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,20>,$<C_COMPILER_ID:Clang>>:-nostartfiles>
)
target_link_options(${TARGET_ELF} PRIVATE
	${TARGET_COMMON_LINK_OPTIONS}
	$<$<C_COMPILER_ID:GNU>:-Wl,--no-print-map-discarded>
	-Wl,-Map=${LOCAL_TARGET}.map,--cref,--print-memory-usage
)
