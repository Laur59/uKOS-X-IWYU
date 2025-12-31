# common-build.
# =============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-10-12
# Modifs:
#
# Project:	uKOS-X
# Goal:		Common CMake file to build FatFs library for uKOS-X.
#
# Description:
#			Shared template to build FatFs static library for a given core
#			Requires: CORE_NAME to be defined before including this file
#
#	© 2025-2026, Laurent von Allmen
#	-------------------------------
#											   __ ______  _____
#	Edo. Franzi							__	__/ //_/ __ \/ ___/
#	5-Route de Cheseaux				   / / / / ,< / / / /\__ \
#	CH 1400 Cheseaux-Noréaz			  / /_/ / /| / /_/ /___/ /
#									  \__,_/_/ |_\____//____/
#	edo.franzi@ukos.ch
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

# Extract core name from project name with strict validation
# Use PROJECT_NAME (current subproject) not CMAKE_PROJECT_NAME (top-level project)
if(PROJECT_NAME MATCHES "^DecNumber_(.+)$")
	set(CORE_NAME ${CMAKE_MATCH_1})
	message("Building decnumber for core: ${CORE_NAME}")
else()
	message(FATAL_ERROR "Project name '${PROJECT_NAME}' does not follow expected naming convention.\n"
	                    "Expected format: DecNUMBER_<CORE_NAME> (e.g., FatFs_CORTEX_M4)")
endif()
set(VALID_CORE_NAMES CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55 RV32IMAC RV64IMAFDC)

# Define the path to FatFs source
set(DECNUMBER_SRC_DIR ${PATH_DECNUMBER}/decnumber-current/src)
message(STATUS "Using decnumber source at ${DECNUMBER_SRC_DIR}")

# Collect all .c files recursively
file(GLOB_RECURSE DECNUMBER_SOURCES "${DECNUMBER_SRC_DIR}/bid/*.c")
# Make CMake reconfigure automatically if source directory contents change
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${DECNUMBER_SRC_DIR}")

# Create unique target name for CMake (to avoid conflicts when building all cores)
# But keep output filename as libFatFs.a
set(TARGET_LIB DecNumber_${CORE_NAME})
add_library(${TARGET_LIB} STATIC
    ${PATH_DECNUMBER}/uKOS_System/headerdecnumber.c
    ${DECNUMBER_SRC_DIR}/decNumber.c
    ${DECNUMBER_SRC_DIR}/decContext.c
    ${DECNUMBER_SOURCES}
)

target_include_directories(${TARGET_LIB} PRIVATE
    ${PATH_UKOS}/OS/Includes
    ${PATH_DECNUMBER}/uKOS_Interface/Patches
    ${DECNUMBER_SRC_DIR}
    ${PATH_DECNUMBER}/decnumber-current/include
    ${PATH_DECNUMBER}/decnumber-current/include/decnumber
    ${PATH_DECNUMBER}/decnumber-current/include/decnumber/bid
)

# Build OPTS_UKOS as a proper list
list(APPEND OPTS_UKOS
    -std=c23
    ${CPU_SPEC}
    ${FLAGS_FP}
    -g3
)

target_compile_definitions(${TARGET_LIB} PRIVATE
    THIRD_PARTY_S
    ${FLAGS_UKOS}
)

target_compile_options(${TARGET_LIB} PRIVATE
    ${OPTS_UKOS}
    -Wall
    -Wextra
    -Wno-pedantic
    -ffunction-sections
    -fdata-sections
    -fno-strict-aliasing
    -fno-builtin
)

set(SUPPORTED_CORES CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55)
if(CORE_NAME IN_LIST SUPPORTED_CORES)
    target_compile_options(${TARGET_LIB} PRIVATE
        $<$<C_COMPILER_ID:GNU>:-mpoke-function-name>
    )
endif()

set_target_properties(${TARGET_LIB} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    OUTPUT_NAME "decnumber"
)

# Strip unnecessary symbols after build
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
    COMMAND ${CMAKE_STRIP} --strip-unneeded ${CMAKE_CURRENT_SOURCE_DIR}/libdecnumber.a
)

# Post-build notification
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
    COMMAND ${CMAKE_COMMAND} -E echo "🎉 Build Complete: ${PROJECT_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "📦 Output: libdecnumber.a"
    COMMAND ${CMAKE_COMMAND} -E echo "🔧 Core: ${CORE_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
)
