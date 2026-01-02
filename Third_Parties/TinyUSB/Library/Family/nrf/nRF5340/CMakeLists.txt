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
#   nRF5340 - Cortex-M33
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.15)

# Include common TinyUSB setup
include(${CMAKE_CURRENT_LIST_DIR}/../../Mkfiles/common-setup.cmake)

project(TinyUSB_nRF5340 C)

# Microcontroller description (mandatory variables)
set(SOC nRF5340)
set(CORE CORTEX_M33)

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
    FAMILY "nrf"
    CPU_SPEC "-mcpu=cortex-m33"
    FLAGS_FP "-mfloat-abi=hard -mfpu=fpv5-sp-d16"
    DEFS_UKOS_EXTRA "-DCORTEX_M33_S -DNRF5340_XXAA -DNRF5340_XXAA_APPLICATION -DCPU_APPLICATION_S -DSECURE_S"
    PROFILES_LIST ${PROFILES_TO_BUILD}
    PROVIDER "nordic"
)
