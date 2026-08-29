# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# CMake for uKOS-X applications (generic part).

# Target Names
set(LOCAL_TARGET ${CMAKE_PROJECT_NAME})
set(TARGET_ELF ${LOCAL_TARGET}.elf)

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
# Identity macros, kept aligned with the APPLICATION make build
# (Applications/Mkfiles/*_application_<CORE>.mk: FLAGS_UKOS = -DUKOS_S
# -D$(BOARD)_S -D$(SOC)_S -D$(CORE)_S). Unlike the system world, the make
# side defines no valued BOARD=/VARIANT=/SOC=/CORE= macros here -- adding
# them changes any source that stringifies one of these names (p_Specials/
# speed prints "Target: "STRG(BOARD), and its documented output is the
# un-expanded "Target: BOARD").
target_compile_definitions(system_compiler_flags INTERFACE
    UKOS_S
    ${BOARD}_S
    ${SOC}_S
    ${CORE}_S
)

# C library specific compile definitions
if(C_LIBRARY STREQUAL "picolibc")
    target_compile_definitions(system_compiler_flags INTERFACE
        CONFIG_MAN_PICOLIBC_S
        _GNU_SOURCE
        _REENT_GLOBAL_ERRNO
    )
    message(STATUS "C library compile definitions: CONFIG_MAN_PICOLIBC_S, _GNU_SOURCE, _REENT_GLOBAL_ERRNO")
elseif(C_LIBRARY STREQUAL "llvmlibc")
    # CLOCKS_PER_SEC is not set here: stock baremetal LLVM libc defaults it to 100
    # on ARM (Arm semihosting counts centiseconds), and the uKOS-X toolchain patch
    # ukos_patches/0006-llvm-libc-use-microsecond-also-for-32-bit-Arm-cores.patch
    # moves 32-bit Arm to the microsecond branch instead. Patching rather than
    # passing -D__CLK_TCK also rebuilds libc.a with the same unit, so the library
    # and the application agree. A static_assert in llvmlibc.c fails the build on
    # an unpatched toolchain.
    target_compile_definitions(system_compiler_flags INTERFACE
        CONFIG_MAN_LLVMLIBC_S
    )
    # LLVM libc has no FILE*-based dprintf; force-include the declaration shim
    # so app code that only includes <stdio.h> still sees a prototype.
    target_compile_options(system_compiler_flags INTERFACE
        "$<$<COMPILE_LANGUAGE:C,CXX>:-include;${PATH_UKOS}/OS/Lib_generics/llvmlibc/llvmlibc_shim.h>"
    )
    # Baremetal LLVM libc ships no POSIX <sys/*> header (it declares struct
    # timeval and gettimeofday() in <time.h>); supply the <sys/time.h> the
    # portable application sources include, so they stay C-library agnostic.
    target_include_directories(system_compiler_flags INTERFACE
        ${PATH_UKOS}/OS/Lib_generics/llvmlibc/compat
    )
    # Overlay installs need --config=llvmlibc.cfg to select LLVM libc; a
    # dedicated LLVM-libc toolchain build does not. Set LLVMLIBC_CONFIG to enable.
    if(LLVMLIBC_CONFIG)
        target_compile_options(system_compiler_flags INTERFACE --config=${LLVMLIBC_CONFIG})
        target_link_options(system_compiler_flags INTERFACE --config=${LLVMLIBC_CONFIG})
    endif()
    message(STATUS "C library compile definitions: CONFIG_MAN_LLVMLIBC_S (dprintf shim force-included, <sys/time.h> compatibility header)")
else()
    # newlib (default)
    target_compile_definitions(system_compiler_flags INTERFACE
        CONFIG_MAN_NEWLIB_S
        _POSIX_C_SOURCE=200809L
    )
    message(STATUS "C library compile definitions: CONFIG_MAN_NEWLIB_S, __DYNAMIC_REENT__, _POSIX_C_SOURCE=200809L")
endif()

# C library specific specs for GCC (compiler and linker)
# Note: Clang/LLVM uses picolibc by default, no specs needed
if(COMPILER_FAMILY STREQUAL "gcc")
    if(C_LIBRARY STREQUAL "picolibc")
        # GCC with picolibc: deliberately NO -specs=picolibc.specs.
        #
        # PATH_GCC_ARMP must point at a GCC whose *default* C library is
        # picolibc, not at a newlib GCC carrying picolibc as an overlay. For a
        # picolibc-native toolchain the specs file is not merely redundant, it
        # is harmful: its *cpp: and *cc1plus: stanzas -isystem-prepend
        # <sysroot>/arm-none-eabi/include so picolibc's headers win over a
        # co-installed newlib. That hoists the C header directory ABOVE the C++
        # ones, and libstdc++'s <cstdlib> reaches <stdlib.h> with
        # #include_next -- which by definition searches only the directories
        # after its own -- so it can never find it. Every C++ translation unit
        # then fails with "fatal error: stdlib.h: No such file or directory",
        # while C compiles fine. See "picolibc with GCC - the toolchain must be
        # picolibc-native" (§2.2) in Documentation/USER_GUIDES/C-library-selection.md.
        #
        # Everything else the specs contributed is already covered: the include
        # and library paths are the toolchain's own defaults, picolibc.ld is
        # overridden by our -T, crt0 by -nostartfiles, the --defsym printf
        # variants need opt-in macros this project never sets, and
        # -mstack-protector-guard=global is already GCC's default for
        # arm-none-eabi (verified: identical __stack_chk_guard code with and
        # without the specs). The one exception is --gc-sections, which the
        # specs used to supply and which is therefore added explicitly here so
        # application images keep their previous size.
        target_link_options(system_compiler_flags INTERFACE
            -Wl,--gc-sections
            # RISC-V GCC only: the driver's *lib stanza (gcc/config/riscv/elf.h)
            # hardcodes -lgloss, newlib's board-support library, which picolibc does
            # not ship; the link dies with "cannot find -lgloss". picolibc.specs
            # replaces that stanza. Applied to the LINK only -- the include-path
            # damage that keeps these specs off the compile line is in *cpp:/*cc1plus:,
            # which the linker never expands. ARM adds no such library and needs none.
            $<$<AND:$<C_COMPILER_ID:GNU>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},RISCV>>:-specs=picolibc.specs>
        )
        message(STATUS "C library specs (GCC): none - picolibc must be the toolchain default; --gc-sections added explicitly")
    else()
        # GCC with newlib (default)
        # Note: -specs=nano.specs is typically added in target-specific CMakeLists.txt
        message(STATUS "C library specs (GCC): newlib (no additional specs at application level)")
    endif()
endif()

# Common flags from *_application_CORTEX_M3.mk, *_application_CORTEX_M4.mk, *_application_CORTEX_M7.mk,
# *_application_CORTEX_M33.mk, *_application_RV32IMAC.mk and *_application_RV64IMAFDC.mk

# Read the system configuration flags from the file
file(STRINGS ${SYSTEM_CNF_PATH} SYSTEM_CNF_RAW)
separate_arguments(SYSTEM_CNF_FLAGS UNIX_COMMAND "${SYSTEM_CNF_RAW}")
list(TRANSFORM SYSTEM_CNF_FLAGS REPLACE "^-D" "")
target_compile_definitions(system_compiler_flags INTERFACE ${SYSTEM_CNF_FLAGS})

# Compile options
target_compile_options(system_compiler_flags BEFORE INTERFACE
    # Standards
    $<$<COMPILE_LANGUAGE:C>:-std=${CSTANDARD}>
    $<$<COMPILE_LANGUAGE:CXX>:-std=${CXXSTANDARD}>
    # Security
    $<$<COMPILE_LANGUAGE:C>:$<$<BOOL:${CANARY}>:-fstack-protector-strong>>
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
    $<$<COMPILE_LANGUAGE:C>:-Wstrict-prototypes>
    $<$<COMPILE_LANGUAGE:C>:-Wc++-compat>
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
    ${SYSTEM_INCLUDE_DIR}
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
    ${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Runtime
    ${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Models
    ${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Runtime
    ${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime
    ${PATH_UKOS}/Third_Parties
    # Application root, so a board stub reaches the shared headers of its own
    # application by name (e.g. "stub.h") instead of by relative path. Kept
    # last so a project header always wins a name clash.
    ${PATH_MYPR}
)

# Link options
target_link_options(system_compiler_flags INTERFACE
    -Wall
    $<$<BOOL:${VERBOSE_LINK}>:-v>
)

# LLVM libc console hooks.
#
# LLVM libc is built with hidden visibility, so the copy linked into FLASH.elf
# contributes only LOCAL HIDDEN symbols and --just-symbols cannot hand them to
# an application. An application calling printf() links its own libc stdio
# objects and has to define the retargeting hooks itself; this shim does that
# and forwards to the system image. See the file for the full rationale.
if(C_LIBRARY STREQUAL "llvmlibc")
    list(APPEND RUNTIME ${PATH_UKOS}/OS/Lib_generics/llvmlibc/llvmlibc_app_stdio.c)
endif()

# Executable Target
add_executable(${TARGET_ELF} ${RUNTIME} ${OBJ})
target_link_libraries(${TARGET_ELF} PUBLIC system_compiler_flags)

# Generated TFLite models (mlp_model.xxd --> mlp_model.c_inc)
# Scan the application folder and the folders of all application sources
# for committed model hex dumps
include(${PATH_UKOS}/Ports/cmake/tflite-model.cmake)

set(MODEL_SCAN_DIRS ${PATH_MYPR})
foreach(SRC IN LISTS OBJ)
    cmake_path(GET SRC PARENT_PATH SRC_DIR)
    list(APPEND MODEL_SCAN_DIRS ${SRC_DIR})
endforeach()
list(REMOVE_DUPLICATES MODEL_SCAN_DIRS)

set(MODEL_XXD_FILES "")
foreach(SCAN_DIR IN LISTS MODEL_SCAN_DIRS)
    file(GLOB DIR_XXD "${SCAN_DIR}/_Training/*.xxd" "${SCAN_DIR}/_Models/*.xxd")
    list(APPEND MODEL_XXD_FILES ${DIR_XXD})
endforeach()
list(REMOVE_DUPLICATES MODEL_XXD_FILES)

ukos_add_tflite_models(${TARGET_ELF} ${MODEL_XXD_FILES})

# Add map file in the list of files removed by make clean
set_property(TARGET ${TARGET_ELF} APPEND
    PROPERTY ADDITIONAL_CLEAN_FILES ${LOCAL_TARGET}.map
)

# Common link libraries
# The matching target_link_libraries() call is deferred to the end of this file
# so that the tail of the link line keeps the same order as the make build.
set(TARGET_COMMON_LIBS
    "-lm"
)

# Linker Script Selection
if(NOT DEFINED LINKS_LD)
    if(NOT DEFINED PATH_MAPP)
        set(PATH_MAPP ${PATH_BASE}/Runtime)
    endif()
    set(LINKS_LD ${PATH_MAPP}/link_App.ld)
endif()

# Link options
set(TARGET_COMMON_LINK_OPTIONS
    $<$<BOOL:${CANARY}>:-Wl,--wrap=__stack_chk_fail>
    $<$<C_COMPILER_ID:Clang>:-Wl,--gc-sections>
    -Wall
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
    message(STATUS "C library malloc wrapping: --wrap=malloc, --wrap=free, --wrap=realloc, --wrap=calloc")
elseif(C_LIBRARY STREQUAL "llvmlibc")
    # LLVM libc uses standard function names (no _r suffix), like picolibc
    list(APPEND TARGET_COMMON_LINK_OPTIONS
        -Wl,--wrap=malloc
        -Wl,--wrap=free
        -Wl,--wrap=realloc
        -Wl,--wrap=calloc
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

target_link_options(${TARGET_ELF} PRIVATE
    ${TARGET_COMMON_LINK_OPTIONS}
    -Wl,-Map=${LOCAL_TARGET}.map,--cref,--print-memory-usage
)

# Tail of the link line, in the same order as the make build:
#   <application objects> ${MYLIB} --just-symbols=FLASH.elf -lc -lstdc++ -lm
# Everything here must follow the application objects:
#   - --just-symbols: a symbol defined by both the application and the system
#     image (e.g. __wrap___stack_chk_fail, provided by crt0_App.o and by
#     FLASH.elf) must resolve to the application copy.
#   - -lc/-lstdc++: a library only resolves references from objects that
#     precede it on the link line.
# target_link_options() emits before the objects, target_link_libraries() after,
# hence the placement here.
target_link_libraries(${TARGET_ELF} PRIVATE
    ${MYLIB}
    -Wl,--just-symbols=${SYSTEM_ELF_PATH}
    $<$<LINK_LANGUAGE:CXX>:-lc>
    $<$<LINK_LANGUAGE:CXX>:-lstdc++>
    ${TARGET_COMMON_LIBS}
)

# Post-Build Actions

# Print executable size
add_custom_command(
    TARGET ${TARGET_ELF}
    POST_BUILD
    COMMAND ${CMAKE_STRIP} --strip-debug ${TARGET_ELF} -o stripped${TARGET_ELF}
    COMMAND ${CMAKE_SIZE} -A --radix=16 stripped${TARGET_ELF} | grep -F -v -e .debug -e .ARM.attributes -e .comment
    COMMAND ${CMAKE_COMMAND} -E remove stripped${TARGET_ELF}
    VERBATIM
)

# Generate output formats hex, bin and srec
add_custom_command(
    TARGET ${TARGET_ELF}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.bin
    COMMAND ${CMAKE_OBJCOPY} -O srec --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.s3
    COMMAND ${CMAKE_COMMAND} -E copy ${TARGET_ELF} ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${LOCAL_TARGET}.map ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${LOCAL_TARGET}.hex ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${LOCAL_TARGET}.bin ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${LOCAL_TARGET}.s3 ${CMAKE_SOURCE_DIR}
    BYPRODUCTS
        ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.hex
        ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.bin
        ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.s3
        ${CMAKE_SOURCE_DIR}/${TARGET_ELF}
        ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.map
    VERBATIM
)

# Listing files
if(WITH_LISTING)
    # Automatically create listing files
    add_custom_command(
        TARGET ${TARGET_ELF}
        POST_BUILD
        COMMAND ${GENERATE_LST} ${TARGET_ELF} > ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.lst
        COMMAND ${GENERATE_DIS} ${TARGET_ELF} > ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.dis
        BYPRODUCTS
            ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.lst
            ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.dis
        VERBATIM
    )
endif()

add_custom_target(listing
    DEPENDS ${TARGET_ELF}
    COMMAND ${GENERATE_LST} ${TARGET_ELF} > ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.lst
    COMMAND ${GENERATE_DIS} ${TARGET_ELF} > ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.dis
    BYPRODUCTS
        ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.lst
        ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.dis
    VERBATIM
)
