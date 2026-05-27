# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds FatFs library for RISC-V32

cmake_minimum_required(VERSION 3.26)

# Include common build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)

project(FatFs_RV32IMAC
    DESCRIPTION "FatFs static library for RISC-V32"
    LANGUAGES C
)

set(FLAGS_FP -mabi=ilp32)
set(CPU_SPEC -march=rv32imac_zicsr_zifencei)
# Library variants to build, format "subdir|definitions".
# Each entry produces Library/<core>/<subdir>/libFatFs.a.
set(FATFS_VARIANTS
    "flash|SECURE_S FLASH_S"
    "sdcard|SECURE_S SDCARD_S"
    "sdcard_flash|SECURE_S SDCARD_S FLASH_S"
)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
