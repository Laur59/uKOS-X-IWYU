# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose:
#   Common CMake file to build FatFs library for uKOS-X.
#
# Build description:
#   Shared template to build FatFs static library for a given core
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
if(PROJECT_NAME MATCHES "^FatFs_(.+)$")
    set(CORE_NAME ${CMAKE_MATCH_1})
    message("Building FatFs for core: ${CORE_NAME}")
else()
    message(FATAL_ERROR "Project name '${PROJECT_NAME}' does not follow expected naming convention.\n"
                        "Expected format: FatFs_<CORE_NAME> (e.g., FatFs_CORTEX_M4)")
endif()
set(VALID_CORE_NAMES CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55 CORTEX_M85)

# Define the path to FatFs source
set(FATFS_SRC_DIR ${PATH_FATFS}/FatFs-current/source)
message(STATUS "Using FatFs source at ${FATFS_SRC_DIR}")

# Collect all .c files recursively
file(GLOB_RECURSE FATFS_SOURCES "${FATFS_SRC_DIR}/*.c")
# Make CMake reconfigure automatically if source directory contents change
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${FATFS_SRC_DIR}")

# Build OPTS_UKOS as a proper list
list(APPEND OPTS_UKOS
    -std=c23
    ${CPU_SPEC}
    ${FLAGS_FP}
)

# Library variants to build.
# Each core may request several variants, each with its own output
# subdirectory and compile definitions, using the format "subdir|DEF1 DEF2 ...".
# When FATFS_VARIANTS is not set, build a single library directly in
# Library/<core>/ using FLAGS_UKOS (the behaviour shared by the other cores).
if(NOT DEFINED FATFS_VARIANTS)
    set(FATFS_VARIANTS "|${FLAGS_UKOS}")
endif()

foreach(VARIANT_ENTRY ${FATFS_VARIANTS})
    # Parse "subdir|definitions"
    string(REPLACE "|" ";" VARIANT_PARTS "${VARIANT_ENTRY}")
    list(GET VARIANT_PARTS 0 VARIANT_SUBDIR)
    list(GET VARIANT_PARTS 1 VARIANT_DEFS_STR)
    separate_arguments(VARIANT_DEFS UNIX_COMMAND "${VARIANT_DEFS_STR}")

    # Create unique target name for CMake (to avoid conflicts), keep output
    # filename as libFatFs.a. An empty subdir builds into Library/<core>/.
    if(VARIANT_SUBDIR STREQUAL "")
set(TARGET_LIB FatFs_${CORE_NAME})
        set(VARIANT_OUTDIR "${PATH_FATFS}/Library/${CORE_NAME}")
    else()
        set(TARGET_LIB FatFs_${CORE_NAME}_${VARIANT_SUBDIR})
        set(VARIANT_OUTDIR "${PATH_FATFS}/Library/${CORE_NAME}/${VARIANT_SUBDIR}")
    endif()

add_library(${TARGET_LIB} STATIC
    ${PATH_FATFS}/Construction/System/headerFatFs.c
    ${PATH_FATFS}/Construction/System/diskio.c
    ${FATFS_SOURCES}
)

target_include_directories(${TARGET_LIB} PRIVATE
    ${PATH_UKOS}/OS/Includes
    ${PATH_UKOS}/OS/Lib_storages
    ${PATH_UKOS}/OS/Lib_storages/sdcard
    ${PATH_UKOS}/OS/Lib_storages/serialFlash
    ${PATH_UKOS}/Ports/EquatesModels/Devices
    ${FATFS_SRC_DIR}
    ${PATH_FATFS}/Construction/System
)

target_compile_definitions(${TARGET_LIB} PRIVATE
    THIRD_PARTY_S
        ${VARIANT_DEFS}
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

    file(MAKE_DIRECTORY "${VARIANT_OUTDIR}")

set_target_properties(${TARGET_LIB} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${VARIANT_OUTDIR}"
    OUTPUT_NAME "FatFs"
)

# Strip unnecessary symbols after build
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
        COMMAND ${CMAKE_STRIP} --strip-unneeded ${VARIANT_OUTDIR}/libFatFs.a
)

# Post-build notification
add_custom_command(TARGET ${TARGET_LIB}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
        COMMAND ${CMAKE_COMMAND} -E echo "🎉 Build Complete: ${PROJECT_NAME} ${VARIANT_SUBDIR}"
        COMMAND ${CMAKE_COMMAND} -E echo "📦 Output: ${VARIANT_OUTDIR}/libFatFs.a"
    COMMAND ${CMAKE_COMMAND} -E echo "🔧 Core: ${CORE_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo "──────────────────────────────────────────"
)
endforeach()
