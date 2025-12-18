# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-10-13
# Modifs:
#
# Project:  uKOS-X
# Goal:     Umbrella CMake file to fetch upstream FatFs and build all libraries
#
# Description:
#           This umbrella CMakeLists.txt performs two main tasks:
#           1. Fetches the upstream FatFs repository from GitHub
#           2. Builds all FatFs static libraries for supported architectures
#
#           It replaces the functionality of build.sh lines 79-91 using
#           CMake's FetchContent module to download and prepare the FatFs
#           source code.
#
#           Usage:
#               cd Third_Parties/FatFs
#               cmake -S . -B build
#               cmake --build build
#
#           This will:
#               - Clone/fetch FatFs from https://github.com/abbrev/fatfs
#               - Checkout specific commit hash
#               - Remove ffconf.h and diskio.c (target-specific files)
#               - Build all libraries for supported architectures
#
#   © 2025-2026, Laurent von Allmen
#   -------------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

project(FatFs_Package
    VERSION 0.16
    DESCRIPTION "FatFs filesystem package with upstream source fetch"
    LANGUAGES NONE
)

# Include FetchContent module for downloading upstream FatFs
include(FetchContent)

message("╔════════════════════════════════════════════════════════════╗")
message("║              FatFs Package Build System                    ║")
message("║      Fetching upstream + Building all architectures        ║")
message("╚════════════════════════════════════════════════════════════╝")
message("")

#------------------------------------------------------------------------
# Step 1: Fetch upstream FatFs repository
#------------------------------------------------------------------------

# Package version and commit hash (matching build.sh)
set(FATFS_VERSION "0.16")
set(FATFS_HASH "30ca13c")

message(STATUS "Fetching FatFs version ${FATFS_VERSION} (commit ${FATFS_HASH})")

FetchContent_Declare(
    FatFs_Upstream
    GIT_REPOSITORY https://github.com/abbrev/fatfs
    GIT_TAG        ${FATFS_HASH}
    SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/FatFs-current
    GIT_SHALLOW    OFF  # We need full history to checkout specific commit
    GIT_PROGRESS   TRUE
)

# Make the content available
FetchContent_MakeAvailable(FatFs_Upstream)

message(STATUS "FatFs source fetched to: ${CMAKE_CURRENT_SOURCE_DIR}/FatFs-current")

# Create a custom target to track FatFs fetch completion
# This allows other targets to depend on the fetch being complete
add_custom_target(FatFs_Fetch_Complete
    COMMENT "FatFs upstream source fetched and ready"
)

#------------------------------------------------------------------------
# Step 2: Remove target-specific files
#------------------------------------------------------------------------

# These files must be provided by each target, not by upstream FatFs
set(FILES_TO_REMOVE
    "${CMAKE_CURRENT_SOURCE_DIR}/FatFs-current/source/ffconf.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/FatFs-current/source/diskio.c"
)

foreach(FILE_PATH ${FILES_TO_REMOVE})
    if(EXISTS ${FILE_PATH})
        message(STATUS "Removing target-specific file: ${FILE_PATH}")
        file(REMOVE ${FILE_PATH})
    else()
        message(STATUS "File already removed: ${FILE_PATH}")
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 3: Build all FatFs libraries for supported architectures
#------------------------------------------------------------------------

# Include ExternalProject module for building libraries
include(ExternalProject)

message("")
message("──────────────────────────────────────────────────────────────")
message("Building FatFs libraries for all architectures...")
message("──────────────────────────────────────────────────────────────")

# List of all supported cores
set(SUPPORTED_CORES
    CORTEX_M3
    CORTEX_M33
    CORTEX_M4
    CORTEX_M55
    CORTEX_M7
    RV32IMAC
    RV64IMAFDC
)

# Determine build type to pass to ExternalProjects
# Default to MinSizeRel for optimal firmware size (adds -Os -DNDEBUG)
if(CMAKE_BUILD_TYPE)
    set(SUBPROJECT_BUILD_TYPE ${CMAKE_BUILD_TYPE})
else()
    set(SUBPROJECT_BUILD_TYPE "MinSizeRel")
endif()

# Create an ExternalProject for each core
foreach(CORE ${SUPPORTED_CORES})
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}/CMakeLists.txt")
        message(STATUS "Configuring build for core: ${CORE}")

        ExternalProject_Add(FatFs_${CORE}
            # Prefix - this sets up unique directories for each external project
            PREFIX            "${CMAKE_CURRENT_BINARY_DIR}/ep-${CORE}"

            # Source configuration
            SOURCE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}"
            BINARY_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}/build"

            # Configure step - pass build type explicitly for optimization
            CMAKE_ARGS        -DCMAKE_BUILD_TYPE=${SUBPROJECT_BUILD_TYPE}
                              -G ${CMAKE_GENERATOR}
            CMAKE_CACHE_ARGS  ""

            # Build step
            BUILD_COMMAND     ${CMAKE_COMMAND} --build <BINARY_DIR>
            BUILD_ALWAYS      OFF
            BUILD_BYPRODUCTS  "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}/libFatFs.a"

            # Install step - libraries stay in-place
            INSTALL_COMMAND   ""

            # Download/Update steps - we use local source
            DOWNLOAD_COMMAND  ""
            UPDATE_COMMAND    ""

            # Logging
            LOG_CONFIGURE     ON
            LOG_BUILD         ON
            LOG_OUTPUT_ON_FAILURE ON

            # Use terminal for better output
            USES_TERMINAL_BUILD ON
        )

        list(APPEND ALL_CORE_PROJECTS FatFs_${CORE})
    else()
        message(WARNING "Skipping ${CORE}: CMakeLists.txt not found at Library/${CORE}")
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 4: Create convenience targets
#------------------------------------------------------------------------

# Create a custom target that depends on all external projects
add_custom_target(build_all_fatfs ALL
    DEPENDS ${ALL_CORE_PROJECTS}
    COMMENT "Building FatFs for all architectures"
)

# Add dependency to ensure FatFs is fetched before building
add_dependencies(build_all_fatfs FatFs_Fetch_Complete)

#------------------------------------------------------------------------
# Summary
#------------------------------------------------------------------------

message("")
message("══════════════════════════════════════════════════════════════")
message("Configuration complete.")
message("")
message("FatFs version:   ${FATFS_VERSION}")
message("Git commit:      ${FATFS_HASH}")
message("Source location: ${CMAKE_CURRENT_SOURCE_DIR}/FatFs-current")
message("")
message("To build all FatFs libraries, run:")
message("  cmake --build build")
message("")
message("Individual architecture targets:")
foreach(CORE ${SUPPORTED_CORES})
    message("  - FatFs_${CORE}")
endforeach()
message("")
message("Output libraries will be in:")
message("  Library/<CORE>/libFatFs.a")
message("══════════════════════════════════════════════════════════════")
