# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds FatFs library for Cortex-M3

cmake_minimum_required(VERSION 3.26)

# Include common build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
set(USE_LLVM OFF)
include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(FatFs_CORTEX_M3
    DESCRIPTION "FatFs static library for Cortex_M3"
    LANGUAGES C
)

set(FLAGS_FP -mfloat-abi=soft)
set(CPU_SPEC -mcpu=cortex-m3)

# Library variants to build, format "subdir|definitions".
# Each entry produces Library/CORTEX_M3/<subdir>/libFatFs.a.
set(FATFS_VARIANTS
    "flash|SECURE_S FLASH_S"
    "sdcard|SECURE_S SDCARD_S"
    "sdcard_flash|SECURE_S SDCARD_S FLASH_S"
)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
