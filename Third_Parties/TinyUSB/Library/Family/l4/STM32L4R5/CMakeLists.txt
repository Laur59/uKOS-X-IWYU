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
#   STM32L4R5 - Cortex-M4
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.15)

# Include common TinyUSB setup
include(${CMAKE_CURRENT_LIST_DIR}/../../Mkfiles/common-setup.cmake)

project(TinyUSB_STM32L4R5 C)

# Microcontroller description (mandatory variables)
set(SOC STM32L4R5)
set(CORE CORTEX_M4)

# Include common TinyUSB build module
include(${CMAKE_CURRENT_SOURCE_DIR}/../../Mkfiles/TinyUSB.cmake)

# Options selecting profiles to build
option(BUILD_CDC_CDC "Build profile cdc_cdc" ON)
option(BUILD_CDC_MSC "Build profile cdc_msc" ON)

# List of profiles to build
set(PROFILES_TO_BUILD "")
if(BUILD_CDC_CDC)
    list(APPEND PROFILES_TO_BUILD "cdc_cdc")
endif()
if(BUILD_CDC_MSC)
    list(APPEND PROFILES_TO_BUILD "cdc_msc")
endif()

# Call function creating TinyUSB libraries
add_tinyusb_libraries(
    FAMILY "l4"
    CPU_SPEC "-mcpu=cortex-m4"
    FLAGS_FP "-mfloat-abi=hard -mfpu=fpv4-sp-d16"
    DEFS_UKOS_EXTRA ""
    PROFILES_LIST ${PROFILES_TO_BUILD}
    PROVIDER "st"
)
