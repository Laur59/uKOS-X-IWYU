# CMakeLists.txt
# ==============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Claude AI       Le 2025-10-11
# Modifs:
#
# Project:  uKOS-X
# Goal:     CMakeLists pour uKOS-X pour construire les modules libTinyUSB.a
#           STM32F207 - Cortex-M3
#
#   Copyright 2025-2026, Laurent von Allmen
#   ---------------------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.15)

# Include common TinyUSB setup
include(${CMAKE_CURRENT_LIST_DIR}/../../Mkfiles/common-setup.cmake)

project(TinyUSB_STM32F207 C)

# Microcontroller description (mandatory variables)
set(SOC STM32F207)
set(CORE CORTEX_M3)

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
    FAMILY "f2"
    CPU_SPEC "-mcpu=cortex-m3"
    FLAGS_FP "-mfloat-abi=soft"
    DEFS_UKOS_EXTRA ""
    PROFILES_LIST ${PROFILES_TO_BUILD}
    PROVIDER "st"
)
