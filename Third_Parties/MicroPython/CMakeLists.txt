# CMakeLists.
# ===========

#------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Project: uKOS-X
#
# Purpose:
#   Umbrella CMake file to build all MicroPython libraries.
#
# Build description:
#   This top-level CMakeLists.txt drives the build of all MicroPython static
#   libraries for supported SoCs and profiles using CMake ExternalProject.
#
#   It is functionally equivalent to build_with_cmake.sh and provides
#   a single, declarative CMake-based build entry point.
#
# Reproducibility:
#   This build definition is intended to be deterministic and reproducible.
#   Given identical source inputs, build configuration, toolchain versions,
#   and build environment, the produced static libraries are expected to be
#   bit-for-bit identical.
#
#   The build does not embed wall-clock timestamps. Where applicable,
#   SOURCE_DATE_EPOCH is expected to be honored by all toolchain components.
#
# Usage:
#   cd Third_Parties/MicroPython
#   cmake -S . -B build -GNinja
#   cmake --build build
#
# Build outputs:
#   - Library/*/libMicroPython.a
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

project(MicroPython_Package
    VERSION 1.27.0
    DESCRIPTION "MicroPython library package for all supported Cortex-M cores"
    LANGUAGES NONE
)

# Include FetchContent module for downloading upstream MicroPython
include(FetchContent)
# Include ExternalProject module for building libraries
include(ExternalProject)

message("╔════════════════════════════════════════════════════════════╗")
message("║          MicroPython Package Build System                  ║")
message("║    Fetching upstream + Building all Cortex-M cores         ║")
message("╚════════════════════════════════════════════════════════════╝")
message("")

#------------------------------------------------------------------------
# Step 1: Fetch upstream MicroPython repository
#------------------------------------------------------------------------

# Package version and tag (matching build_with_cmake.sh default)
set(MICROPYTHON_VERSION "1.27.0")
set(MICROPYTHON_TAG "v${MICROPYTHON_VERSION}")

message(STATUS "Fetching MicroPython version ${MICROPYTHON_VERSION} (tag ${MICROPYTHON_TAG})")

FetchContent_Declare(
    MicroPython_Upstream
    GIT_REPOSITORY https://github.com/micropython/micropython.git
    GIT_TAG        ${MICROPYTHON_TAG}
    SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/MicroPython-current
    GIT_SHALLOW    OFF  # We need full history to checkout specific tag
    GIT_PROGRESS   TRUE
)

# Make the content available
FetchContent_MakeAvailable(MicroPython_Upstream)

message(STATUS "MicroPython source fetched to: ${CMAKE_CURRENT_SOURCE_DIR}/MicroPython-current")

# Create a custom target to track MicroPython fetch completion
add_custom_target(MicroPython_Fetch_Complete
    COMMENT "MicroPython upstream source fetched and ready"
)

#------------------------------------------------------------------------
# Step 2: Configuration - Cortex-M cores
#------------------------------------------------------------------------

# Define the supported Cortex-M cores
set(SUPPORTED_CORES
    CORTEX_M4
    CORTEX_M7
    CORTEX_M33
    CORTEX_M55
)

#------------------------------------------------------------------------
# Step 3: Build all cores using ExternalProject
#------------------------------------------------------------------------

message("")
message("──────────────────────────────────────────────────────────────")
message("Configuring builds for all Cortex-M cores...")
message("──────────────────────────────────────────────────────────────")

set(ALL_CORE_PROJECTS "")

foreach(CORE ${SUPPORTED_CORES})
    # Path to core CMakeLists.txt
    set(CORE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}")

    if(EXISTS "${CORE_SOURCE_DIR}/CMakeLists.txt")
        message(STATUS "Configuring: ${CORE}")

        # Create unique project name
        set(PROJECT_NAME "MicroPython_${CORE}")

        # Determine build type to pass to ExternalProject
        # Default to MinSizeRel for optimal firmware size (adds -Os -DNDEBUG)
        if(CMAKE_BUILD_TYPE)
            set(SUBPROJECT_BUILD_TYPE ${CMAKE_BUILD_TYPE})
        else()
            set(SUBPROJECT_BUILD_TYPE "MinSizeRel")
        endif()

        ExternalProject_Add(${PROJECT_NAME}
            # Prefix - unique directories for each external project
            PREFIX            "${CMAKE_CURRENT_BINARY_DIR}/ep-${CORE}"

            # Source configuration
            SOURCE_DIR        "${CORE_SOURCE_DIR}"
            BINARY_DIR        "${CORE_SOURCE_DIR}/build"

            # Configure step
            # Pass build type explicitly to ensure optimisation
            CMAKE_ARGS        -DCMAKE_BUILD_TYPE=${SUBPROJECT_BUILD_TYPE}
                              -G ${CMAKE_GENERATOR}
            CMAKE_CACHE_ARGS  ""

            # Build step
            BUILD_COMMAND     ${CMAKE_COMMAND} --build <BINARY_DIR> --parallel
            BUILD_ALWAYS      OFF

            # Install step - installs libMicroPython.a in ${CORE_SOURCE_DIR}
            INSTALL_COMMAND   ${CMAKE_COMMAND} --install <BINARY_DIR>

            # Download/Update steps - we use local source
            DOWNLOAD_COMMAND  ""
            UPDATE_COMMAND    ""

            # Logging
            LOG_CONFIGURE     ON
            LOG_BUILD         ON
            LOG_INSTALL       ON
            LOG_OUTPUT_ON_FAILURE ON

            # Use terminal for better output
            USES_TERMINAL_BUILD ON
        )

        # Add dependency to ensure MicroPython is fetched before building
        add_dependencies(${PROJECT_NAME} MicroPython_Fetch_Complete)

        list(APPEND ALL_CORE_PROJECTS ${PROJECT_NAME})
    else()
        message(WARNING "Skipping ${CORE}: CMakeLists.txt not found at ${CORE_SOURCE_DIR}")
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 4: Create convenience targets
#------------------------------------------------------------------------

# Create a custom target that depends on all external projects
add_custom_target(build_all_micropython ALL
    DEPENDS ${ALL_CORE_PROJECTS}
    COMMENT "Building MicroPython for all Cortex-M cores"
)

# Add dependency to ensure MicroPython is fetched before building
add_dependencies(build_all_micropython MicroPython_Fetch_Complete)

#------------------------------------------------------------------------
# Summary
#------------------------------------------------------------------------

message("")
message("══════════════════════════════════════════════════════════════")
message("Configuration complete.")
message("")
message("MicroPython version:  ${MICROPYTHON_VERSION}")
message("Git tag:              ${MICROPYTHON_TAG}")
message("Source location:      ${CMAKE_CURRENT_SOURCE_DIR}/MicroPython-current")
message("")
message("To build all MicroPython libraries, run:")
message("  cmake --build build")
message("")
message("Individual core targets:")
foreach(CORE ${SUPPORTED_CORES})
    message("  - MicroPython_${CORE}")
endforeach()
message("")
message("Output libraries will be in:")
message("  Library/<CORE>/libMicroPython.a")
message("══════════════════════════════════════════════════════════════")
