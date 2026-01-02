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
#   Umbrella CMake file to fetch upstream decnumber and build all libraries.
#
# Build description:
#   This top-level CMakeLists.txt drives the build of all decnumber static
#   libraries for supported SoCs and profiles using CMake ExternalProject.
#       1. Fetches the upstream decnumber repository from GitHub
#       2. Builds all decnumber static libraries for supported architectures
#
#   It is functionally equivalent to build.sh and provides
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
#   cd Third_Parties/decnumber
#   cmake -S . -B build
#   cmake --build build
#
# Build outputs:
#   - Library/*/libdecnumber.a
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

project(decnumber_Package
    VERSION 3.68
    DESCRIPTION "decnumber filesystem package with upstream source fetch"
    LANGUAGES NONE
)

# Include FetchContent module for downloading upstream decnumber
include(FetchContent)

message("╔════════════════════════════════════════════════════════════╗")
message("║            decnumber Package Build System                  ║")
message("║      Fetching upstream + Building all architectures        ║")
message("╚════════════════════════════════════════════════════════════╝")
message("")

#------------------------------------------------------------------------
# Step 1: Fetch upstream decnumber repository
#------------------------------------------------------------------------

# Package version and commit hash (matching build.sh)
set(DECNUMBER_VERSION "3.68")
set(DECNUMBER_HASH "ace3fa6")

message(STATUS "Fetching decnumber version ${DECNUMBER_VERSION} (commit ${DECNUMBER_HASH})")

FetchContent_Declare(
    decnumber_Upstream
    GIT_REPOSITORY https://github.com/raitechnology/libdecnumber.git
    GIT_TAG        ${DECNUMBER_HASH}
    SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/decnumber-current
    GIT_SHALLOW    OFF  # We need full history to checkout specific commit
    GIT_PROGRESS   TRUE
    EXCLUDE_FROM_ALL TRUE  # Don't add upstream targets to default build
)

# Make the content available (upstream CMakeLists.txt is processed but targets excluded)
FetchContent_MakeAvailable(decnumber_Upstream)

message(STATUS "decnumber source fetched to: ${CMAKE_CURRENT_SOURCE_DIR}/decnumber-current")

# Create a custom target to track decnumber fetch completion
# This allows other targets to depend on the fetch being complete
add_custom_target(decnumber_Fetch_Complete
    COMMENT "decnumber upstream source fetched and ready"
)

#------------------------------------------------------------------------
# Step 2: Build all decnumber libraries for supported architectures
#------------------------------------------------------------------------

# Include ExternalProject module for building libraries
include(ExternalProject)

message("")
message("──────────────────────────────────────────────────────────────")
message("Building decnumber libraries for all architectures...")
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

        ExternalProject_Add(decnumber_${CORE}
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
            BUILD_BYPRODUCTS  "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}/libdecnumber.a"

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

        list(APPEND ALL_CORE_PROJECTS decnumber_${CORE})
    else()
        message(WARNING "Skipping ${CORE}: CMakeLists.txt not found at Library/${CORE}")
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 3: Create convenience targets
#------------------------------------------------------------------------

# Create a custom target that depends on all external projects
add_custom_target(build_all_decnumber ALL
    DEPENDS ${ALL_CORE_PROJECTS}
    COMMENT "Building decnumber for all architectures"
)

# Add dependency to ensure decnumber is fetched before building
add_dependencies(build_all_decnumber decnumber_Fetch_Complete)

#------------------------------------------------------------------------
# Summary
#------------------------------------------------------------------------

message("")
message("══════════════════════════════════════════════════════════════")
message("Configuration complete.")
message("")
message("decnumber version:   ${DECNUMBER_VERSION}")
message("Git commit:      ${DECNUMBER_HASH}")
message("Source location: ${CMAKE_CURRENT_SOURCE_DIR}/decnumber-current")
message("")
message("To build all decnumber libraries, run:")
message("  cmake --build build")
message("")
message("Individual architecture targets:")
foreach(CORE ${SUPPORTED_CORES})
    message("  - decnumber_${CORE}")
endforeach()
message("")
message("Output libraries will be in:")
message("  Library/<CORE>/libdecnumber.a")
message("══════════════════════════════════════════════════════════════")
