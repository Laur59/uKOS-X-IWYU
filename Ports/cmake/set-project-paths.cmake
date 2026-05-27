# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Define directory paths required to build the system

# Project paths

# - PATH_UKOS   --> Main uKOS-X folder
# - PATH_VARI   --> folder holding CMakeLists.txt
# - PATH_BASE   --> Projects Root Base folder
# - PATH_OSYS   --> Projects Root OS folder

# Setup path to project root directory
get_filename_component(PATH_PORT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
get_filename_component(PATH_UKOS "${PATH_PORT}/.." ABSOLUTE)
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH TARGET_DIR)
set(PATH_VARI ${CMAKE_SOURCE_DIR})
set(PATH_OSYS ${PATH_UKOS}/OS)
get_filename_component(VARIANT "${PATH_VARI}" NAME)
get_filename_component(BOARD "${TARGET_DIR}" NAME)

# Assumptions
# For multi-processor board, each processor is labelled with '_procID'
# and have its dedicated folders Base_procID and Variant_Test_procID
# A folder Base_Common can be used for shared code

get_filename_component(DIR_NAME "${CMAKE_SOURCE_DIR}" NAME)
if(DIR_NAME MATCHES "^Variant_Test_(.+)$")
    set(VARIANT_SUFFIX "_${CMAKE_MATCH_1}")
    set(PATH_BASE ${TARGET_DIR}/Base${VARIANT_SUFFIX})
    set(PATH_COMX ${TARGET_DIR}/Base_Common)
else()
    set(PATH_BASE ${TARGET_DIR}/Base)
endif()
