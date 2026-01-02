# CMakeLists.txt
# ==============

#------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Project: uKOS-X
#
# Purpose:
#   CMakeLists for uKOS-X to build library libTinyUSB.a.
#   RP2350 - Cortex-M33 (Raspberry Pi Pico2)
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.15)

# Include common TinyUSB setup
include(${CMAKE_CURRENT_LIST_DIR}/../../Mkfiles/common-setup.cmake)

project(TinyUSB_RP2350 C ASM)

# Microcontroller description (mandatory variables)
set(SOC rp2350)
set(CORE CORTEX_M33)

# Include common TinyUSB build module
include(${CMAKE_CURRENT_SOURCE_DIR}/../../Mkfiles/TinyUSB.cmake)

# Options selecting profiles to build
option(BUILD_CDC_CDC "Build profile cdc_cdc" ON)

# List of profiles to build
set(PROFILES_TO_BUILD "")
if(BUILD_CDC_CDC)
    list(APPEND PROFILES_TO_BUILD "cdc_cdc")
endif()

# Call function creating TinyUSB libraries
add_tinyusb_libraries(
    FAMILY "pico2"
    CPU_SPEC "-mcpu=cortex-m33"
    FLAGS_FP "-mfloat-abi=hard -mfpu=fpv5-sp-d16"
    DEFS_UKOS_EXTRA "-DCORTEX_M33_S"
    PROFILES_LIST ${PROFILES_TO_BUILD}
    PROVIDER "raspberrypi"
)
