# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# CMake common file for the all the application.

# Apply project settings
include(${CMAKE_CURRENT_LIST_DIR}/proj_config.cmake)

# Project path configuration
# - PATH_UKOS   --> Main uKOS-X folder                  --> kernel_os
# - PATH_BASE   --> MyProjects Root Base folders        --> MyProjects/Ports/Targets/xyz/Base
# - PATH_VARI   --> MyProjects Root Variant_xx folders  --> MyProjects/Ports/Targets/xyz/Variant_xx

cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH PATH_MYPR)
if(NOT DEFINED BOARD)
    message( FATAL_ERROR "Variable BOARD is not defined." )
endif()
if(DEFINED BASE)
    set(PATH_BASE ${PATH_UKOS}/Ports/Targets/${BOARD}/${BASE})
else()
    set(PATH_BASE ${PATH_UKOS}/Ports/Targets/${BOARD}/Base)
endif()
if(NOT DEFINED VARIANT)
    message( FATAL_ERROR "Variable VARIANT is not defined." )
endif()
set(PATH_VARI ${PATH_UKOS}/Ports/Targets/${BOARD}/${VARIANT})

# System files location configuration
# ------------------------------------
# Applications require FLASH.cnf, FLASH.ck, and FLASH.elf from the system build.
# Two modes are supported:
#   1. Source tree mode (default): Files are located in ${PATH_VARI}/System/
#   2. Installed system mode: Files are located in a directory specified by SYSTEM_INSTALL_DIR
#
# To use an installed system, pass -DSYSTEM_INSTALL_DIR=/path/to/install when configuring:
#   cmake -S . -B build -DSYSTEM_INSTALL_DIR=/path/to/l4r5

if(DEFINED SYSTEM_INSTALL_DIR)
    # Normalize to absolute path (required for compiler @file syntax)
    # Relative paths are resolved from the shell's current working directory ($ENV{PWD})
    # This allows paths like: -DSYSTEM_INSTALL_DIR=l4r5 (relative to where cmake was invoked)
    if(NOT IS_ABSOLUTE "${SYSTEM_INSTALL_DIR}")
        cmake_path(ABSOLUTE_PATH SYSTEM_INSTALL_DIR BASE_DIRECTORY "$ENV{PWD}" NORMALIZE OUTPUT_VARIABLE SYSTEM_INSTALL_DIR_ABS)
    else()
        set(SYSTEM_INSTALL_DIR_ABS "${SYSTEM_INSTALL_DIR}")
    endif()

    # Validate that the install directory exists
    if(NOT EXISTS "${SYSTEM_INSTALL_DIR_ABS}")
        message(FATAL_ERROR
            "SYSTEM_INSTALL_DIR is set to '${SYSTEM_INSTALL_DIR}' "
            "(resolved to '${SYSTEM_INSTALL_DIR_ABS}') but this directory does not exist.\n"
            "Please ensure you have installed the system using: cmake --install build --prefix <path>")
    endif()

    # Define required system files (using absolute path)
    set(REQUIRED_SYSTEM_FILES
        "${SYSTEM_INSTALL_DIR_ABS}/FLASH.cnf"
        "${SYSTEM_INSTALL_DIR_ABS}/FLASH.ck"
        "${SYSTEM_INSTALL_DIR_ABS}/firmware/FLASH.elf"
    )

    # Validate that all required files exist
    set(MISSING_FILES "")
    foreach(file ${REQUIRED_SYSTEM_FILES})
        if(NOT EXISTS "${file}")
            list(APPEND MISSING_FILES "  - ${file}")
        endif()
    endforeach()

    if(MISSING_FILES)
        message(FATAL_ERROR
            "SYSTEM_INSTALL_DIR is set to '${SYSTEM_INSTALL_DIR}' "
            "(resolved to '${SYSTEM_INSTALL_DIR_ABS}') but the following required files are missing:\n"
            "${MISSING_FILES}\n"
            "Please ensure you have installed the system using: cmake --install build --prefix <path>")
    endif()

    # Use installed system paths (absolute)
    set(SYSTEM_CNF_PATH "${SYSTEM_INSTALL_DIR_ABS}/FLASH.cnf")
    set(SYSTEM_CK_PATH "${SYSTEM_INSTALL_DIR_ABS}/FLASH.ck")
    set(SYSTEM_ELF_PATH "${SYSTEM_INSTALL_DIR_ABS}/firmware/FLASH.elf")
    set(SYSTEM_INCLUDE_DIR "${SYSTEM_INSTALL_DIR_ABS}")

    message(STATUS "Using installed system from: ${SYSTEM_INSTALL_DIR_ABS}")
else()
    # Default: use source tree paths
    set(SYSTEM_CNF_PATH "${PATH_VARI}/Artefacts/FLASH.cnf")
    set(SYSTEM_CK_PATH "${PATH_VARI}/Artefacts/FLASH.ck")
    set(SYSTEM_ELF_PATH "${PATH_VARI}/Artefacts/FLASH.elf")
    set(SYSTEM_INCLUDE_DIR "${PATH_VARI}/Artefacts")
endif()

# Sources
# -------

# Runtime components
set(RUNTIME
    ${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime/header.c
    ${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime/crt0_App.c
)

# Project components
# Get the application name from the directory name
cmake_path(GET APP_DIR STEM APP_NAME)
if(EXISTS "${PATH_MYPR}/${APP_NAME}.c")
    set(MAIN_SRC ${PATH_MYPR}/${APP_NAME}.c)
elseif(EXISTS "${PATH_MYPR}/${APP_NAME}.cpp")
    set(MAIN_SRC ${PATH_MYPR}/${APP_NAME}.cpp)
endif()

# Reproduce the link order of the make build. application.mk links
#
#   $(RUNTIME_OBJ) $(APPL_C_OBJ) $(APPL_CPP_OBJ)
#
# where each APPL_* list is built by globbing every directory of APPL_SRC in
# declaration order -- the directories the application makefile adds first,
# then the application directory, then the board directory (appended by
# common.mk) -- with the sources of each directory in alphabetical order.
# The make order is therefore: every C source grouped by directory, then
# every C++ source grouped by the same directory order.
#
# CMake cannot see APPL_SRC; the directory order is recovered from the first
# appearance of each extra directory in OBJ, which the CMakeLists must list
# in the makefile's APPL_SRC order. The main source, when auto-detected,
# joins the application directory at its alphabetical position.
set(OBJ_ABS "")
set(OBJ_DIRS "")
foreach(SRC IN LISTS OBJ)
    cmake_path(ABSOLUTE_PATH SRC BASE_DIRECTORY ${PROJECT_SOURCE_DIR} NORMALIZE OUTPUT_VARIABLE SRC_ABS)
    list(APPEND OBJ_ABS ${SRC_ABS})
    cmake_path(GET SRC_ABS PARENT_PATH SRC_DIR)
    if(NOT SRC_DIR STREQUAL PATH_MYPR AND NOT SRC_DIR STREQUAL PROJECT_SOURCE_DIR)
        list(APPEND OBJ_DIRS ${SRC_DIR})
    endif()
endforeach()
if(DEFINED MAIN_SRC)
    list(APPEND OBJ_ABS ${MAIN_SRC})
endif()
list(REMOVE_DUPLICATES OBJ_DIRS)
list(APPEND OBJ_DIRS ${PATH_MYPR} ${PROJECT_SOURCE_DIR})

set(OBJ_C "")
set(OBJ_CPP "")
foreach(DIR IN LISTS OBJ_DIRS)
    set(DIR_C "")
    set(DIR_CPP "")
    foreach(SRC IN LISTS OBJ_ABS)
        cmake_path(GET SRC PARENT_PATH SRC_DIR)
        if(SRC_DIR STREQUAL DIR)
            cmake_path(GET SRC EXTENSION LAST_ONLY SRC_EXT)
            if(SRC_EXT STREQUAL ".cpp")
                list(APPEND DIR_CPP ${SRC})
            else()
                list(APPEND DIR_C ${SRC})
            endif()
        endif()
    endforeach()
    list(SORT DIR_C)
    list(SORT DIR_CPP)
    list(APPEND OBJ_C ${DIR_C})
    list(APPEND OBJ_CPP ${DIR_CPP})
endforeach()
set(OBJ ${OBJ_C} ${OBJ_CPP})

# Apply application configuration
include(application)
