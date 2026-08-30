# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose:
#   Common CMake file to build decnumber library for uKOS-X.
#
# Build description:
#   Shared template to build decnumber static library for a given core
#   Requires: CORE_NAME to be defined before including this file
#
# Reproducibility:
#   This build definition is intended to be deterministic and reproducible.
#   Given identical source inputs, build configuration, toolchain versions,
#   and build environment, the produced static libraries are expected to be
#   bit-for-bit identical.
#
#   The build does not embed wall-clock timestamps. Where applicable,
#   SOURCE_DATE_EPOCH is expected to be honored by all toolchain components.

# Extract core name from project name with strict validation
# Use PROJECT_NAME (current subproject) not CMAKE_PROJECT_NAME (top-level project)
if(PROJECT_NAME MATCHES "^DecNumber_(.+)$")
    set(CORE_NAME ${CMAKE_MATCH_1})
    message("Building decnumber for core: ${CORE_NAME}")
else()
    message(FATAL_ERROR "Project name '${PROJECT_NAME}' does not follow expected naming convention.\n"
                        "Expected format: DecNumber_<CORE_NAME> (e.g., DecNumber_CORTEX_M4)")
endif()
set(VALID_CORE_NAMES CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55 CORTEX_M85 RV32IMAC RV64IMAFDC)

# Default install prefix (set here, after project(), so CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT
# is reliable). Allows 'cmake --install <build>' without an explicit --prefix.
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PATH_DECNUMBER}" CACHE PATH "Install prefix" FORCE)
endif()

# Deterministic archives and a git-derived SOURCE_DATE_EPOCH
include(${PATH_UKOS}/Ports/cmake/reproducible.cmake)
ukos_reproducible_build()

# Define the path to the decnumber source
set(DECNUMBER_SRC_DIR ${PATH_DECNUMBER}/decnumber-current/src)
message(STATUS "Using decnumber source at ${DECNUMBER_SRC_DIR}")

# Collect all .c files recursively
file(GLOB_RECURSE DECNUMBER_SOURCES "${DECNUMBER_SRC_DIR}/bid/*.c")
# Make CMake reconfigure automatically if source directory contents change
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${DECNUMBER_SRC_DIR}")

# Create unique target name for CMake (to avoid conflicts when building all cores)
# But keep output filename as libdecnumber.a
set(TARGET_LIB DecNumber_${CORE_NAME})
add_library(${TARGET_LIB} STATIC
    ${PATH_DECNUMBER}/Construction/System/headerdecnumber.c
    ${DECNUMBER_SRC_DIR}/decNumber.c
    ${DECNUMBER_SRC_DIR}/decContext.c
    ${DECNUMBER_SOURCES}
)

target_include_directories(${TARGET_LIB} PRIVATE
    ${PATH_UKOS}/OS/Includes
    ${PATH_DECNUMBER}/Construction/Interface/Patches
    ${DECNUMBER_SRC_DIR}
    ${PATH_DECNUMBER}/decnumber-current/include
)

# Build OPTS_UKOS as a proper list
list(APPEND OPTS_UKOS
    -std=c23
    ${CPU_SPEC}
    ${FLAGS_FP}
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
    OUTPUT_NAME "decnumber"
)

# Installation (deployed by 'cmake --install')
install(TARGETS ${TARGET_LIB} ARCHIVE DESTINATION "Library/${CORE_NAME}")

# Strip unnecessary symbols after build
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
    COMMAND ${CMAKE_STRIP} -D --strip-unneeded $<TARGET_FILE:${TARGET_LIB}>
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
