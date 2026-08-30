# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
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

# Extract core name from project name with strict validation
# Use PROJECT_NAME (current subproject) not CMAKE_PROJECT_NAME (top-level project)
if(PROJECT_NAME MATCHES "^LVGL_(.+)$")
    set(CORE_NAME ${CMAKE_MATCH_1})
    message("Building libLVGL for core: ${CORE_NAME}")
else()
    message(FATAL_ERROR "Project name '${PROJECT_NAME}' does not follow expected naming convention.\n"
                        "Expected format: LVGL_<CORE_NAME> (e.g., LVGL_CORTEX_M4)")
endif()

# Display name is the leaf directory of the build folder (e.g. WaveShare_2_Inches)
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PARENT_DIR)
cmake_path(GET PARENT_DIR               FILENAME     DISPLAY_NAME)
set(VALID_CORE_NAMES CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55)

# Default install prefix (set here, after project(), so CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT
# is reliable). Allows 'cmake --install <build>' without an explicit --prefix.
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PATH_LVGL}" CACHE PATH "Install prefix" FORCE)
endif()

# Deterministic archives and a git-derived SOURCE_DATE_EPOCH
include(${PATH_UKOS}/Ports/cmake/reproducible.cmake)
ukos_reproducible_build()

# Define the path to LVGL source
set(LIB_SRC_DIR ${PATH_LVGL}/LVGL-current/src)
message(STATUS "Using LVGL source at ${LIB_SRC_DIR}")

# Collect all .c files recursively
file(GLOB_RECURSE LVGL_SOURCES "${LIB_SRC_DIR}/*.c")
# Make CMake reconfigure automatically if source directory contents change
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${LIB_SRC_DIR}")

# Create unique target name for CMake (to avoid conflicts when building all cores)
# But keep output filename as libLVGL.a
set(TARGET_LIB LVGL_${CORE_NAME})
add_library(${TARGET_LIB} STATIC
    ${PATH_LVGL}/Construction/System/headerLVGL.c
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
    OUTPUT_NAME "LVGL"
)

# Installation (deployed by 'cmake --install').
# The panel headers ship with the archive: the downloadable LVGL applications
# include lcd_display.h and lv_conf.h from Library/.
install(TARGETS ${TARGET_LIB} ARCHIVE DESTINATION "Library/${DISPLAY_NAME}/${CORE_NAME}")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/lv_conf.h"
        DESTINATION "Library/${DISPLAY_NAME}/${CORE_NAME}"
)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../lcd_display.h"
        DESTINATION "Library/${DISPLAY_NAME}"
)

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
    COMMAND ${CMAKE_COMMAND} -E echo "📦 Output: libLVGL.a"
    COMMAND ${CMAKE_COMMAND} -E echo "🔧 Core: ${CORE_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
)
