# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

# select-arm-toolchain.
# =====================

#------------------------------------------------------------------------
# Project:  uKOS-X
# Goal:     Selecting toolchain to build kernel and os
#
#------------------------------------------------------------------------

# Get the parent directory of the current file
cmake_path(GET CMAKE_CURRENT_LIST_FILE PARENT_PATH mkfiles_cmake_path)

option(USE_LLVM "Selection of toolchain" ON)
if(${USE_LLVM})
    set(COMPILER_FAMILY llvm)
    set(PREFIX llvm-)

    if(DEFINED C_LIBRARY AND C_LIBRARY STREQUAL "picolibc")
        if(DEFINED ENV{PATH_LLVM_ARMP})
            set(PATH_LLVM_ARM $ENV{PATH_LLVM_ARMP})
        else()
            message(FATAL_ERROR "Environment variable PATH_LLVM_ARMP is not defined")
        endif()
    else()
        set(C_LIBRARY "newlib")
        if(DEFINED ENV{PATH_LLVM_ARM})
            set(PATH_LLVM_ARM $ENV{PATH_LLVM_ARM})
        else()
            find_program(CLANG_COMPILER
                NAMES clang
                DOC "Clang compiler"
            )
            if(NOT CLANG_COMPILER)
                message(FATAL_ERROR "Environment variable PATH_LLVM_ARM is not defined")
            endif()
            # Check for support for ARM
            execute_process(
                COMMAND ${CLANG_COMPILER} --print-target-triple
                OUTPUT_VARIABLE CLANG_TARGETS
                OUTPUT_STRIP_TRAILING_WHITESPACE
                RESULT_VARIABLE CLANG_CHECK_RESULT
            )
            if(NOT CLANG_CHECK_RESULT EQUAL 0)
                message(FATAL_ERROR "Failed to check Clang targets")
            endif()
            if(NOT CLANG_TARGETS MATCHES "arm")
                message(FATAL_ERROR "Clang found but does not support ARM targets")
            endif()
            get_filename_component(CLANG_BIN_DIR ${CLANG_COMPILER} DIRECTORY)
            cmake_path(GET CLANG_BIN_DIR PARENT_PATH PATH_LLVM_ARM)
        endif()
    endif()

    include(${mkfiles_cmake_path}/llvm-arm.cmake)
else()
    set(COMPILER_FAMILY gcc)
    set(PREFIX arm-none-eabi-)

    if(DEFINED ENV{PATH_GCC_ARM})
        set(PATH_GCC_ARM $ENV{PATH_GCC_ARM})
    else()
        # Search GCC for ARM in PATH
        find_program(ARM_GCC_COMPILER
            NAMES ${PREFIX}gcc
            DOC "ARM GCC Compiler"
        )
        if(NOT ARM_GCC_COMPILER)
            message(FATAL_ERROR "Environment variable PATH_GCC_ARM is not defined")
        else()
            get_filename_component(ARM_GCC_BIN_DIR ${ARM_GCC_COMPILER} DIRECTORY)
            cmake_path(GET ARM_GCC_BIN_DIR PARENT_PATH PATH_GCC_ARM)
        endif()
    endif()

    include(${mkfiles_cmake_path}/gcc-arm.cmake)
endif()

unset(mkfiles_cmake_path)
