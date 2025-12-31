# common-build.
# =============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-12-22
# Modifs:
#
# Project:	uKOS-X
# Goal:		Common CMake file to build IntelRDFPMath library for uKOS-X.
#
# Description:
#			Shared template to build IntelRDFPMath static library for a given core
#			Requires: CORE_NAME to be defined before including this file
#
#	Copyright 2025-2026, Laurent von Allmen
#	---------------------------------------
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
if(PROJECT_NAME MATCHES "^IntelRDFPMath_(.+)$")
	set(CORE_NAME ${CMAKE_MATCH_1})
	message("Building Intel RDFP Math for core: ${CORE_NAME}")
else()
	message(FATAL_ERROR "Project name '${PROJECT_NAME}' does not follow expected naming convention.\n"
	                    "Expected format: IntelRDFPMath_<CORE_NAME> (e.g., IntelRDFPMath_CORTEX_M4)")
endif()
set(VALID_CORE_NAMES CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55)

# Define the path to IntelRDFPMath source
set(INTELRDFPMATH_SRC_DIR ${PATH_INTELRDFPMATH}/IntelRDFPMath-current/LIBRARY/src)
message(STATUS "Using IntelRDFPMath source at ${INTELRDFPMATH_SRC_DIR}")

# Collect all .c files recursively
file(GLOB_RECURSE INTELRDFPMATH_SOURCES APPEND
    "${INTELRDFPMATH_SRC_DIR}/bid32_*.c"
    "${INTELRDFPMATH_SRC_DIR}/bid64_*.c"
    "${INTELRDFPMATH_SRC_DIR}/bid_*.c"
)
# Make CMake reconfigure automatically if source directory contents change
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${INTELRDFPMATH_SRC_DIR}")

# Create unique target name for CMake (to avoid conflicts when building all cores)
# But keep output filename as libIntelRDFPMath.a
set(TARGET_LIB IntelRDFPMath_${CORE_NAME})
add_library(${TARGET_LIB} STATIC
    ${PATH_INTELRDFPMATH}/uKOS_System/headerIntelRDFPMath.c
    ${INTELRDFPMATH_SOURCES}
    "${INTELRDFPMATH_SRC_DIR}/bid128_2_str_tables.c"
    "${INTELRDFPMATH_SRC_DIR}/strtod32.c"
    "${INTELRDFPMATH_SRC_DIR}/strtod64.c"
    "${INTELRDFPMATH_SRC_DIR}/wcstod32.c"
    "${INTELRDFPMATH_SRC_DIR}/wcstod64.c"
)

target_include_directories(${TARGET_LIB} PRIVATE
    ${PATH_UKOS}/OS/Includes
    ${PATH_INTELRDFPMATH}/IntelRDFPMath-current/source
    ${PATH_INTELRDFPMATH}/uKOS_System
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
    -Wno-pedantic
    $<$<C_COMPILER_ID:GNU>:-Wlogical-op>
    -Wno-error=undef
    -Wno-error=unused-parameter
    -Wno-error=cast-align
    -Wno-error=cast-qual
    -Wno-error=redundant-decls
    -Wno-error=strict-prototypes
    -Wno-missing-braces
    -Wno-misleading-indentation
    -Wno-overflow
    -Wno-unused-variable
    -Wno-unused-but-set-variable
    -Wno-uninitialized
    -Wno-char-subscripts
    $<$<C_COMPILER_ID:GNU>:-fsingle-precision-constant>
    $<$<C_COMPILER_ID:Clang>:-cl-single-precision-constant>
)
if(CORE_NAME IN_LIST VALID_CORE_NAMES)
    target_compile_options(${TARGET_LIB} PRIVATE
        $<$<C_COMPILER_ID:GNU>:-mpoke-function-name>
    )
endif()

set_target_properties(${TARGET_LIB} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    OUTPUT_NAME "IntelRDFPMath"
)

# Strip unnecessary symbols after build
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
    COMMAND ${CMAKE_STRIP} --strip-unneeded ${CMAKE_CURRENT_SOURCE_DIR}/libIntelRDFPMath.a
)

# Post-build notification
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
    COMMAND ${CMAKE_COMMAND} -E echo "🎉 Build Complete: ${PROJECT_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "📦 Output: libIntelRDFPMath.a"
    COMMAND ${CMAKE_COMMAND} -E echo "🔧 Core: ${CORE_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
)
