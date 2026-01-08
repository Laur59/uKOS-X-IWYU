# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# common-build.
# =============
#
# Project: uKOS-X
#
# Purpose:
#   Common CMake file to build LVGL library for uKOS-X.
#
# Build description:
#   Shared template to build LVGL static library for a given core
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
#------------------------------------------------------------------------

# Extract core name from project name with strict validation
# Use PROJECT_NAME (current subproject) not CMAKE_PROJECT_NAME (top-level project)
if(PROJECT_NAME MATCHES "^LVGL_(.+)$")
    set(CORE_NAME ${CMAKE_MATCH_1})
    message("Building libLVGL for core: ${CORE_NAME}")
else()
    message(FATAL_ERROR "Project name '${PROJECT_NAME}' does not follow expected naming convention.\n"
                        "Expected format: LVGL_<CORE_NAME> (e.g., LVGL_CORTEX_M4)")
endif()
set(VALID_CORE_NAMES CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55)

# Define the path to LVGL source
set(LIB_SRC_DIR ${PATH_LVGL}/LVGL-current/src)
message(STATUS "Using LVGL source at ${LIB_SRC_DIR}")

# Collect all .c files recursively
file(GLOB_RECURSE LVGL_SOURCES "${LIB_SRC_DIR}/*.c")
# Make CMake reconfigure automatically if source directory contents change
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${LIB_SRC_DIR}")

# Create unique target name for CMake (to avoid conflicts when building all cores)
# But keep output filename as libFatFs.a
set(TARGET_LIB LVGL_${CORE_NAME})
add_library(${TARGET_LIB} STATIC
    ${PATH_LVGL}/uKOS_System/headerLVGL.c
    ${LVGL_SOURCES}
)

target_include_directories(${TARGET_LIB} PRIVATE
    ${PATH_UKOS}/OS/Includes
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LIB_SRC_DIR}
)

# Build OPTS_UKOS as a proper list
list(APPEND OPTS_UKOS
    -std=c23
    ${CPU_SPEC}
    ${FLAGS_FP}
    -g3
)

target_compile_definitions(${TARGET_LIB} PRIVATE
    LV_CONF_INCLUDE_SIMPLE
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
    OUTPUT_NAME "LVGL"
)

# Strip unnecessary symbols after build
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
    COMMAND ${CMAKE_STRIP} --strip-unneeded ${CMAKE_CURRENT_SOURCE_DIR}/libLVGL.a
)

# Post-build notification
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
    COMMAND ${CMAKE_COMMAND} -E echo "🎉 Build Complete: ${PROJECT_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "📦 Output: libLVGL.a"
    COMMAND ${CMAKE_COMMAND} -E echo "🔧 Core: ${CORE_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
)
