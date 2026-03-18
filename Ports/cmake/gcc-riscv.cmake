# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Toolchain file for configuring Cmake to build cross-compiling
# projects based on RISC-V core.

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR RISCV)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(PATH_TOOLCHAIN_PREFIX ${PATH_GCC_RVXX}/bin/riscv64-unknown-elf-)

# Validate that all required toolchain utilities exist
foreach(tool IN ITEMS gcc g++ ar ld objcopy objdump ranlib strip size)
    set(tool_path "${PATH_TOOLCHAIN_PREFIX}${tool}")
    if(NOT EXISTS "${tool_path}")
        message(FATAL_ERROR "Toolchain utility not found: ${tool_path}\n"
                            "Please verify PATH_GCC_RVXX is set correctly: ${PATH_GCC_RVXX}")
    endif()
endforeach()

set(CMAKE_C_COMPILER "${PATH_TOOLCHAIN_PREFIX}gcc")
set(CMAKE_CXX_COMPILER "${PATH_TOOLCHAIN_PREFIX}g++")
set(CMAKE_AR "${PATH_TOOLCHAIN_PREFIX}ar")
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_LINKER "${PATH_TOOLCHAIN_PREFIX}ld")
set(CMAKE_OBJCOPY "${PATH_TOOLCHAIN_PREFIX}objcopy")
set(CMAKE_OBJDUMP "${PATH_TOOLCHAIN_PREFIX}objdump")
set(CMAKE_RANLIB "${PATH_TOOLCHAIN_PREFIX}ranlib")
set(CMAKE_STRIP "${PATH_TOOLCHAIN_PREFIX}strip")
set(CMAKE_SIZE "${PATH_TOOLCHAIN_PREFIX}size")

set(GENERATE_LST ${PATH_TOOLCHAIN_PREFIX}objdump -f -p -D -d -h -t -s)
set(GENERATE_DIS ${PATH_TOOLCHAIN_PREFIX}objdump -S)

# Common flags for RISC-V bare-metal

set(CMAKE_CXX_FLAGS_INIT "-fno-rtti -fno-exceptions")
