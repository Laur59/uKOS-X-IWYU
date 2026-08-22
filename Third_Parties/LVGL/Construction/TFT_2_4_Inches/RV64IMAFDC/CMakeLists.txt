# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds LVGL library for RV64IMAFDC
# Display TFT 2.4"

cmake_minimum_required(VERSION 3.31)

# Include common build setup
include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/common-setup.cmake)
include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)

project(LVGL_RV64IMAFDC
    DESCRIPTION "LVGL static library for RV64IMAFDC"
    LANGUAGES C
)

set(FLAGS_FP -mabi=lp64d)
set(CPU_SPEC -march=rv64imafdc_zicsr_zifencei -mcmodel=medany)
set(FLAGS_UKOS SECURE_S)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/common-build.cmake)
