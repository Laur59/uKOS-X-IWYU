# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds FatFs library for Cortex-M4

cmake_minimum_required(VERSION 3.31)

# Include common build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)
set(USE_LLVM OFF)
include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(FatFs_CORTEX_M4
    DESCRIPTION "FatFs static library for Cortex_M4"
    LANGUAGES C
)

set(FLAGS_FP -mfloat-abi=hard -mfpu=fpv4-sp-d16)
set(CPU_SPEC -mcpu=cortex-m4)
# Library variants to build, format "subdir|definitions".
# Each entry produces Library/<core>/<subdir>/libFatFs.a.
set(FATFS_VARIANTS
    "flash|SECURE_S FLASH_S"
    "sdcard|SECURE_S SDCARD_S"
    "sdcard_flash|SECURE_S SDCARD_S FLASH_S"
)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/common-build.cmake)
