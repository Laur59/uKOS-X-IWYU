# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Selecting toolchain to build kernel and os

# Get the parent directory of the current file
cmake_path(GET CMAKE_CURRENT_LIST_FILE PARENT_PATH mkfiles_cmake_path)

# LLVM libc is not yet supported for RISC-V: the Arm Toolchain for Embedded is
# ARM/AArch64 only, and no RISC-V baremetal LLVM-libc toolchain is wired here.
if(DEFINED C_LIBRARY AND C_LIBRARY STREQUAL "llvmlibc")
    message(FATAL_ERROR "C_LIBRARY=llvmlibc is not supported for RISC-V targets (ARM/AArch64 only)")
endif()

option(USE_LLVM "Selection of toolchain" ON)
if(${USE_LLVM})
    set(COMPILER_FAMILY llvm)
    set(PREFIX llvm-)

    if(DEFINED C_LIBRARY AND C_LIBRARY STREQUAL "picolibc")
        if(DEFINED ENV{PATH_LLVM_RVXXP})
            set(PATH_LLVM_RVXX $ENV{PATH_LLVM_RVXXP})
        else()
            message(FATAL_ERROR "Environment variable PATH_LLVM_RVXXP is not defined")
        endif()
    else()
        set(C_LIBRARY "newlib")
        if(DEFINED ENV{PATH_LLVM_RVXX})
            set(PATH_LLVM_RVXX $ENV{PATH_LLVM_RVXX})
        else()
            find_program(CLANG_COMPILER
                NAMES clang
                DOC "Clang compiler"
            )
            if(NOT CLANG_COMPILER)
                message(FATAL_ERROR "Environment variable PATH_LLVM_RVXX is not defined")
            endif()
            # Check for support for RISCV
            execute_process(
                COMMAND ${CLANG_COMPILER} --print-target-triple
                OUTPUT_VARIABLE CLANG_TARGETS
                OUTPUT_STRIP_TRAILING_WHITESPACE
                RESULT_VARIABLE CLANG_CHECK_RESULT
            )
            if(NOT CLANG_CHECK_RESULT EQUAL 0)
                message(FATAL_ERROR "Failed to check Clang targets")
            endif()
            if(NOT CLANG_TARGETS MATCHES "riscv")
                message(FATAL_ERROR "Clang found but does not support RISCV targets")
            endif()
            get_filename_component(CLANG_BIN_DIR ${CLANG_COMPILER} DIRECTORY)
            cmake_path(GET CLANG_BIN_DIR PARENT_PATH PATH_LLVM_RVXX)
        endif()
    endif()

    include(${mkfiles_cmake_path}/llvm-riscv.cmake)
else()
    set(COMPILER_FAMILY gcc)
    set(PREFIX riscv64-unknown-elf-)

    if(DEFINED ENV{PATH_GCC_RVXX})
        set(PATH_GCC_RVXX $ENV{PATH_GCC_RVXX})
    else()
        # Search GCC for RISC-V in PATH
        find_program(RISC_GCC_COMPILER
            NAMES ${PREFIX}gcc
            DOC "RISC-V GCC Compiler"
        )
        if(NOT RISC_GCC_COMPILER)
            message(FATAL_ERROR "Environment variable PATH_GCC_RVXX is not defined")
        else()
            get_filename_component(RISC_GCC_BIN_DIR ${RISC_GCC_COMPILER} DIRECTORY)
            cmake_path(GET RISC_GCC_BIN_DIR PARENT_PATH PATH_GCC_RVXX)
        endif()
    endif()

    include(${mkfiles_cmake_path}/gcc-riscv.cmake)
endif()

unset(mkfiles_cmake_path)
