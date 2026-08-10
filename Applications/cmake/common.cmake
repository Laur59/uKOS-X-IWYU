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

if(DEFINED MAIN_SRC)
    # Reproduce the source order of the make build, which globs every directory
    # listed in APPL_SRC and links the resulting objects in that order. An
    # application makefile appends its own directories before including
    # common.mk, which is what appends the application and the board directory,
    # so APPL_SRC ends up as:
    #
    #   <directories added by the application> <application> <board>
    #
    # and the sources of each directory are compiled in alphabetical order. The
    # main source therefore belongs at its alphabetical position among the other
    # sources of the application directory, not simply in front of them.
    set(OBJ_EXTRA_DIRS "")
    set(OBJ_APP_DIR "")
    set(OBJ_BOARD_DIR "")
    foreach(SRC IN LISTS OBJ)
        cmake_path(ABSOLUTE_PATH SRC BASE_DIRECTORY ${PROJECT_SOURCE_DIR} NORMALIZE OUTPUT_VARIABLE SRC_ABS)
        cmake_path(GET SRC_ABS PARENT_PATH SRC_DIR)
        if(SRC_DIR STREQUAL PATH_MYPR)
            list(APPEND OBJ_APP_DIR ${SRC_ABS})
        elseif(SRC_DIR STREQUAL PROJECT_SOURCE_DIR)
            list(APPEND OBJ_BOARD_DIR ${SRC_ABS})
        else()
            list(APPEND OBJ_EXTRA_DIRS ${SRC})
        endif()
    endforeach()
    list(APPEND OBJ_APP_DIR ${MAIN_SRC})
    list(SORT OBJ_APP_DIR)
    list(SORT OBJ_BOARD_DIR)
    set(OBJ ${OBJ_EXTRA_DIRS} ${OBJ_APP_DIR} ${OBJ_BOARD_DIR})
endif()

# Apply application configuration
include(application)
