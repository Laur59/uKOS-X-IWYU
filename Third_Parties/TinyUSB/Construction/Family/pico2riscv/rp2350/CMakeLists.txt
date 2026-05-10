# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds libTinyUSB.a for RP2350 (Hazard3 RV32IMAC)

cmake_minimum_required(VERSION 3.15)

# Include common TinyUSB setup (selects the RISC-V toolchain)
include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/common-setup-riscv.cmake)

project(TinyUSB_RP2350_RISCV C ASM)

# Microcontroller description (mandatory variables)
set(SOC rp2350)
set(CORE RV32IMAC)

# Include common TinyUSB build module
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/TinyUSB.cmake)

# Options selecting profiles to build
option(BUILD_CDC_CDC "Build profile cdc_cdc" ON)

# Validation build: produce archives that use OPT_OS_PICO instead of the
# uKOS-X custom OSAL, so the libraries can be linked into a Pico SDK app
# for hardware unit-testing without the uKOS-X kernel.
option(BUILD_VALIDATE_PICO "Build validation archives (OPT_OS_PICO)" OFF)

# List of profiles to build
set(PROFILES_TO_BUILD "")
if(BUILD_CDC_CDC)
    list(APPEND PROFILES_TO_BUILD "cdc_cdc")
endif()

# Call function creating TinyUSB libraries
add_tinyusb_libraries(
    FAMILY "pico2riscv"
    CPU_SPEC "-march=rv32imac_zicsr_zifencei -mabi=ilp32"
    FLAGS_FP ""
    DEFS_UKOS_EXTRA "-DPICO_RISCV=1"
    PROFILES_LIST ${PROFILES_TO_BUILD}
    PROVIDER "raspberrypi"
)
