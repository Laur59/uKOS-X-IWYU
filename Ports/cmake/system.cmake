# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

# system.
# =======

#------------------------------------------------------------------------
# Project:  uKOS-X
# Goal:     CMake for uKOS-X systems (generic part).
#
#------------------------------------------------------------------------

# Versioning Detection
if(NOT DEFINED VERSIONING)
    find_package(Git QUIET)
    if(GIT_FOUND)
        execute_process(
            COMMAND ${GIT_EXECUTABLE} rev-parse --git-dir
            OUTPUT_VARIABLE GIT_DIR
            OUTPUT_STRIP_TRAILING_WHITESPACE
            ERROR_QUIET
        )
        if(GIT_DIR)
            set(VERSIONING "git")
        else()
            set(VERSIONING "none")
        endif()
    else()
        set(VERSIONING "none")
    endif()
else()
    string(TOLOWER "${VERSIONING}" VERSIONING)
endif()

# Target Names
set(LOCAL_TARGET "FLASH" CACHE STRING "Name of the elf file.")
set(TARGET_ELF ${LOCAL_TARGET}.elf)
set(TARGET_NOSIG_ELF ${LOCAL_TARGET}.nosig.elf)

# Compiler Flags - Modern Interface Library Approach
add_library(system_compiler_flags INTERFACE)
target_link_libraries(system_compiler_flags INTERFACE core_compiler_flags)

# Standards
if(NOT DEFINED CSTANDARD)
    set(CSTANDARD "c23")
endif()
if(NOT DEFINED CXXSTANDARD)
    set(CXXSTANDARD "c++23")
endif()

# Compile definitions
target_compile_definitions(system_compiler_flags INTERFACE
    UKOS_S
    ${SOC}_S
    ${CORE}_S
    ROMABLE_S
    "$<$<BOOL:${KERNEL_OPT}>:${KERNEL_OPT}_S>"
)

# C library specific compile definitions
if(C_LIBRARY STREQUAL "picolibc")
    target_compile_definitions(system_compiler_flags INTERFACE
        CONFIG_MAN_PICOLIBC_S
        _GNU_SOURCE
        _REENT_GLOBAL_ERRNO
    )
    message(STATUS "C library compile definitions: CONFIG_MAN_PICOLIBC_S, _GNU_SOURCE, _REENT_GLOBAL_ERRNO")
else()
    # newlib (default)
    target_compile_definitions(system_compiler_flags INTERFACE
        CONFIG_MAN_NEWLIB_S
        __DYNAMIC_REENT__
        _POSIX_C_SOURCE=200809L
    )
    message(STATUS "C library compile definitions: CONFIG_MAN_NEWLIB_S, __DYNAMIC_REENT__, _POSIX_C_SOURCE=200809L")
endif()

# C library specific specs for GCC (compiler and linker)
# Note: Clang/LLVM uses picolibc by default, no specs needed
if(COMPILER_FAMILY STREQUAL "gcc")
    if(C_LIBRARY STREQUAL "picolibc")
        # GCC with picolibc: Use specs for both compilation and linking
        # The picolibc.specs file provides:
        # - Include paths to picolibc headers
        # - Library paths to picolibc libraries
        # - Automatic --gc-sections for linker (reduces binary size)
        # - Default picolibc.ld linker script (overridden by our -T flag)
        # Note: Our custom linker scripts override picolibc's default via -T flag
        target_compile_options(system_compiler_flags INTERFACE
            -specs=picolibc.specs
        )
        target_link_options(system_compiler_flags INTERFACE
            -specs=picolibc.specs
        )
        message(STATUS "C library specs (GCC): -specs=picolibc.specs for compilation and linking")
    else()
        # GCC with newlib (default)
        # Note: -specs=nano.specs is typically added in target-specific CMakeLists.txt
        message(STATUS "C library specs (GCC): newlib (no additional specs at system level)")
    endif()
endif()

# Common flags from *_system_CORTEX_M3.mk, *_system_CORTEX_M4.mk,
# *_system_CORTEX_M7.mk, *_system_RV32IMAC.mk and *_system_RV64IMAFDC.mk
# Compile options
target_compile_options(system_compiler_flags BEFORE INTERFACE
    # Standards
    $<$<COMPILE_LANGUAGE:C>:-std=${CSTANDARD}>
    $<$<COMPILE_LANGUAGE:CXX>:-std=${CXXSTANDARD}>
    # Security
    $<$<BOOL:${CANARY}>:-fstack-protector-strong>
    # Basic behaviour
    -fshort-enums
    -fstack-usage
    $<$<AND:$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},ARM>,$<C_COMPILER_ID:GNU>>:-mpoke-function-name>
    # Warnings
    -Wall -Wextra -Wpedantic
    # Exceptions
    -Wno-main
    # Additional checks
    -Wconversion
    -Wshadow
    -Wunreachable-code
    # Recommended for CERT C
    -Wswitch-default
    -Wcast-align
    -Wcast-qual
    # C specific flags
    -Wstrict-prototypes
    -Wc++-compat
    # Additional flags
    ${CFLAGS_APPEND}
)

# Include directories - NOW TARGET-SPECIFIC
target_include_directories(system_compiler_flags INTERFACE
    ${PATH_INCLUDES}
    ${PATH_UKOS}
    ${PATH_UKOS}/OS
    ${PATH_UKOS}/OS/Boots
    ${PATH_UKOS}/OS/Includes
    ${PATH_UKOS}/OS/Lib_serials
    ${PATH_UKOS}/OS/Lib_generics
    ${PATH_UKOS}/OS/Lib_kernels
    ${PATH_UKOS}/OS/Lib_peripherals
    ${PATH_UKOS}/OS/Lib_neurals
    ${PATH_UKOS}/OS/Lib_storages
    ${PATH_UKOS}/OS/Lib_cryptographics
    ${PATH_UKOS}/OS/Processes
    ${PATH_UKOS}/OS/Daemons
    ${PATH_UKOS}/OS/CLI
    ${PATH_VARI}/Shared
    ${PATH_VARI}/Runtime
    ${PATH_BASE}/Runtime
    ${PATH_VARI}/Includes/System
    ${PATH_BASE}/Includes/System
    ${PATH_VARI}/Includes/Board
    ${PATH_BASE}/Includes/Board
    ${PATH_UKOS}/Ports/EquatesModels/Devices
    ${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Models
    ${PATH_UKOS}/Ports/EquatesModels/Generic/Models
    ${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Includes
    ${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Includes
    ${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Runtime
    ${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Runtime
    ${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Models
    ${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PATH_UKOS}/Third_Parties
    ${EXTRA_INCLUDE_DIRECTORIES}
)

# Link options
target_link_options(system_compiler_flags INTERFACE
    -Wall
    $<$<BOOL:${VERBOSE_LINK}>:-v>
)

# Generate version.h at each build as this file contains the git SHA of the
# code used to build the project
# Version Header Generation
if(VERSIONING STREQUAL "git")
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C "${PATH_UKOS}" describe --always --dirty --match=
        OUTPUT_VARIABLE SW_VERSION_VAR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    # Trick to have version.h updated when git status changed
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C "${PATH_UKOS}" rev-parse --git-dir
        OUTPUT_VARIABLE PROJECT_SOURCE_GIT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    string(REGEX REPLACE "\\.git.*" ".git" PROJECT_SOURCE_GIT "${PROJECT_SOURCE_GIT}")
    set_property(GLOBAL APPEND
        PROPERTY CMAKE_CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_GIT}/index"
    )
elseif(VERSIONING STREQUAL "svn")
    execute_process(
        COMMAND svnversion
        OUTPUT_VARIABLE SW_VERSION_VAR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
    set(SW_VERSION_VAR "Unsupported versioning system")
endif()
configure_file(
    "${PATH_UKOS}/OS/Includes/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.h"
)

# Executable Targets

# The really first pcs of code
# Put first.o in an object library
add_library(first_object OBJECT "${FIRST_P}")
target_link_libraries(first_object PUBLIC system_compiler_flags)

# Main executables
add_executable(${TARGET_NOSIG_ELF})
add_executable(${TARGET_ELF})

# Link libraries (without signature)
target_link_libraries(${TARGET_NOSIG_ELF} PRIVATE
    system_compiler_flags
    first_object
    "-Wl,-whole-archive" ${UKOS_COMPONENTS} "-Wl,-no-whole-archive"
    "-lm"
)

# Link libraries for final ELF (with signature inside whole-archive)
target_link_libraries(${TARGET_ELF} PRIVATE
    system_compiler_flags
    first_object
    "-Wl,-whole-archive" ${UKOS_COMPONENTS} sig_object "-Wl,-no-whole-archive"
    "-lm"
)

# Linker Script Selection
if(NOT DEFINED LINKS_LD)
    if(NOT DEFINED PATH_MAPP)
        set(PATH_MAPP "${PATH_BASE}/Runtime")
    endif()
    if(PREFIX STREQUAL "llvm-")
        set(LINKS_LD "${PATH_MAPP}/link${MODE}.lld")
    else()
        set(LINKS_LD "${PATH_MAPP}/link${MODE}.ld")
    endif()
endif()

# Common link options
set(TARGET_COMMON_LINK_OPTIONS
    $<$<BOOL:${CANARY}>:-Wl,--wrap=__stack_chk_fail>
    -L${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Runtime
    -L${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Runtime
    -T${LINKS_LD}
    $<$<C_COMPILER_ID:GNU>:-nostartfiles>
    $<$<AND:$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,20>,$<C_COMPILER_ID:Clang>>:-nostartfiles>
)

# C library specific memory allocator wrapping
if(C_LIBRARY STREQUAL "picolibc")
    # Picolibc uses standard function names (no _r suffix)
    list(APPEND TARGET_COMMON_LINK_OPTIONS
        -Wl,--wrap=malloc
        -Wl,--wrap=free
        -Wl,--wrap=realloc
        -Wl,--wrap=calloc
    )
    # Counteract picolibc.specs' --gc-sections for the system build.
    # picolibc.specs unconditionally adds --gc-sections, which discards .text sections
    # from --whole-archive objects when no symbol in that section is referenced within
    # the system binary. This affects kernel API functions and peripheral drivers
    # (e.g. watchdog_arm) that are only called by downloadable applications.
    list(APPEND TARGET_COMMON_LINK_OPTIONS
        $<$<C_COMPILER_ID:GNU>:-Wl,--no-gc-sections>
    )
    message(STATUS "C library malloc wrapping: --wrap=malloc, --wrap=free, --wrap=realloc, --wrap=calloc")
else()
    # Newlib uses reentrant function names (_r suffix)
    list(APPEND TARGET_COMMON_LINK_OPTIONS
        -Wl,--wrap=_malloc_r
        -Wl,--wrap=_free_r
        -Wl,--wrap=_realloc_r
        -Wl,--wrap=_calloc_r
    )
    message(STATUS "C library malloc wrapping: --wrap=_malloc_r, --wrap=_free_r, --wrap=_realloc_r, --wrap=_calloc_r")
endif()
target_link_options(${TARGET_NOSIG_ELF} PRIVATE ${TARGET_COMMON_LINK_OPTIONS})
target_link_options(${TARGET_ELF} PRIVATE
    ${TARGET_COMMON_LINK_OPTIONS}
    $<$<C_COMPILER_ID:GNU>:-Wl,--no-print-map-discarded>
    -Wl,-Map=${LOCAL_TARGET}.map,--cref,--print-memory-usage
)

# Generate signature at each build
add_custom_command(
    TARGET ${TARGET_NOSIG_ELF}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary --strip-all --remove-section=.signature
        ${TARGET_NOSIG_ELF} NOSIG.bin
    BYPRODUCTS NOSIG.bin
    VERBATIM
)
# Generate signature using portable CMake script (cross-platform)
if(${CONSTANT_SIG})
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.sig.c"
    "const char aFLASH_signature[] __attribute__((section(\".signature\"))) = \"0000000000000000000000000000000000000000000000000000000000000000\";\n"
)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.ck"
    "\n"
)
else()
add_custom_command(
    OUTPUT ${LOCAL_TARGET}.sig.c ${LOCAL_TARGET}.ck
    COMMAND ${CMAKE_COMMAND}
        -DINPUT_FILE=${CMAKE_CURRENT_BINARY_DIR}/NOSIG.bin
        -DOUTPUT_SIG_C=${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.sig.c
        -DOUTPUT_CK=${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.ck
        -P ${CMAKE_CURRENT_LIST_DIR}/generate_signature.cmake
    DEPENDS ${TARGET_NOSIG_ELF} NOSIG.bin
    COMMENT "Generating signature C source file (SHA-256)"
    VERBATIM
)
endif()

add_library(sig_object OBJECT ${LOCAL_TARGET}.sig.c)
target_link_libraries(sig_object PRIVATE system_compiler_flags)

# Add map file, and ck file in the list of files removed by make clean
# Clean files
set_property(TARGET ${TARGET_ELF} APPEND
    PROPERTY ADDITIONAL_CLEAN_FILES
        ${LOCAL_TARGET}.map
        ${LOCAL_TARGET}.ck
        $ENV{PWD}/Artefacts
)

# Post-Build Actions
# ==================
#
# Hybrid Approach: Development Workflow + Modern CMake Install
#
# This section implements a hybrid approach that serves two purposes:
#
# 1. DEVELOPMENT WORKFLOW (automatic, via POST_BUILD):
#    - Artifacts are automatically copied to ARTEFACTS_DIR after each build
#    - Default location: ${CMAKE_SOURCE_DIR}/Artefacts (configurable via cache)
#    - This preserves the existing workflow where burn scripts expect files in Artefacts/
#    - Uses copy_if_different for efficiency (only copies when files change)
#
# 2. DEPLOYMENT/PACKAGING (explicit, via cmake --install):
#    - Modern install() rules enable flexible deployment scenarios
#    - Supports CMAKE_INSTALL_PREFIX for custom installation locations
#    - Component-based installation (runtime, firmware, development)
#    - Usage: cmake --install build --prefix /path/to/install
#
# This design ensures backwards compatibility whilst adding modern CMake capabilities.

# Artifact output directory configuration
set(ARTEFACTS_DIR "$ENV{PWD}/Artefacts" CACHE PATH "Directory for build artifacts")

# Print executable size
add_custom_command(
    TARGET ${TARGET_ELF}
    POST_BUILD
    COMMAND ${CMAKE_STRIP} --strip-debug ${TARGET_ELF} -o stripped${TARGET_ELF}
    COMMAND ${CMAKE_SIZE} -A --radix=16 stripped${TARGET_ELF} | grep -F -v -e .debug -e .ARM.attributes -e .comment
    COMMAND ${CMAKE_COMMAND} -E remove stripped${TARGET_ELF}
    VERBATIM
)

# Generate output formats and copy to artifact directory
# Development workflow: automatic copy to ARTEFACTS_DIR for immediate use
add_custom_command(
    TARGET ${TARGET_ELF}
    POST_BUILD
    COMMENT "Generating output formats and copying to ${ARTEFACTS_DIR}"

    # Generate output formats
    COMMAND ${CMAKE_OBJCOPY} -O ihex --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.bin
    COMMAND ${CMAKE_OBJCOPY} -O srec --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.s3

    # Ensure artifact directory exists
    COMMAND ${CMAKE_COMMAND} -E make_directory ${ARTEFACTS_DIR}

    # Copy artifacts (only when changed)
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TARGET_ELF} ${ARTEFACTS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.map ${ARTEFACTS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.ck ${ARTEFACTS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.hex ${ARTEFACTS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.bin ${ARTEFACTS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.s3 ${ARTEFACTS_DIR}

    BYPRODUCTS
        ${ARTEFACTS_DIR}/${LOCAL_TARGET}.hex
        ${ARTEFACTS_DIR}/${LOCAL_TARGET}.bin
        ${ARTEFACTS_DIR}/${LOCAL_TARGET}.s3
        ${ARTEFACTS_DIR}/${TARGET_ELF}
        ${ARTEFACTS_DIR}/${LOCAL_TARGET}.map
        ${ARTEFACTS_DIR}/${LOCAL_TARGET}.ck
    VERBATIM
)

# Installation rules (modern CMake approach)
# Usage: cmake --install build --prefix /path/to/install
# This enables packaging and deployment scenarios beyond the development workflow
#
# For embedded systems, we use a simplified structure:
#   firmware/        - All firmware files (.elf, .hex, .bin, .s3)
#   <prefix>/        - Development files (.map, .ck, .cnf)

# Install firmware files (including ELF)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_ELF}
    ${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.hex
    ${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.bin
    ${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.s3
    DESTINATION firmware
    COMPONENT firmware
)

# Install development files (map, checksum, and configuration)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.map
    ${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.ck
    ${ARTEFACTS_DIR}/${LOCAL_TARGET}.cnf
    DESTINATION .
    COMPONENT development
)

# Listing files
if(WITH_LISTING)
    # Automatically create listing files
    add_custom_command(
        TARGET ${TARGET_ELF}
        POST_BUILD
        COMMAND ${GENERATE_LST} ${TARGET_ELF} > ${ARTEFACTS_DIR}/${LOCAL_TARGET}.lst
        COMMAND ${GENERATE_DIS} ${TARGET_ELF} > ${ARTEFACTS_DIR}/${LOCAL_TARGET}.dis
        BYPRODUCTS
            ${ARTEFACTS_DIR}/${LOCAL_TARGET}.lst
            ${ARTEFACTS_DIR}/${LOCAL_TARGET}.dis
        VERBATIM
    )
endif()

add_custom_target(listing
    DEPENDS ${TARGET_ELF}
    COMMAND ${GENERATE_LST} ${TARGET_ELF} > ${ARTEFACTS_DIR}/${LOCAL_TARGET}.lst
    COMMAND ${GENERATE_DIS} ${TARGET_ELF} > ${ARTEFACTS_DIR}/${LOCAL_TARGET}.dis
    BYPRODUCTS
        ${ARTEFACTS_DIR}/${LOCAL_TARGET}.lst
        ${ARTEFACTS_DIR}/${LOCAL_TARGET}.dis
    VERBATIM
)

# Utility Targets

# Program the SOC with binary
add_custom_target(burn
    DEPENDS ${TARGET_ELF}
    COMMAND ${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Burn/${BURN}.sh
    VERBATIM
)

# CTags generation
if(NOT DEFINED ENV{CTAGS})
    set(PROJ_CTAGS ctags)
else()
    set(PROJ_CTAGS $ENV{CTAGS})
endif()
set(TAG_FILE "${PATH_UKOS}/tags")
file(GLOB TAG_SRC "${PATH_UKOS}/Lib_*")
list(APPEND TAG_SRC
    "${PATH_UKOS}/OS/Includes"
    "${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}"
    "${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}"
    "${PATH_BASE}"
    "${PATH_VARI}"
)
set(CTAGS_OPTIONS "--excmd=number --tag-relative=always --fields=+a+m+n+S --map-C=+.cm --map-C=+.h --languages=C")
add_custom_target(tags
    COMMAND ${CMAKE_COMMAND} -E remove -f ${TAG_FILE}
    COMMAND ${PROJ_CTAGS} ${CTAGS_OPTIONS} -R -f ${TAG_FILE} ${TAG_SRC}
    VERBATIM
)
