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
#   Umbrella CMake file to fetch upstream IntelRDFPMath and build all libraries.
#
# Build description:
#   This top-level CMakeLists.txt drives the build of all IntelRDFPMath static
#   libraries for supported SoCs and profiles using CMake ExternalProject.
#       1. Fetches the upstream IntelRDFPMath repository from GitHub
#       2. Builds all IntelRDFPMath static libraries for supported architectures
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
#   cd Third_Parties/IntelRDFPMath
#   cmake -S . -B build
#   cmake --build build
#
# Build outputs:
#   - Library/*/libIntelRDFPMath.a
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

project(IntelRDFPMath_Package
    VERSION 2.3
    DESCRIPTION "Intel RDFP Math package with upstream source fetch"
    LANGUAGES NONE
)

# Include FetchContent module for downloading upstream IntelRDFPMath
include(FetchContent)

message("╔════════════════════════════════════════════════════════════╗")
message("║         Intel RDFP Math Package Build System               ║")
message("║      Fetching upstream + Building all architectures        ║")
message("╚════════════════════════════════════════════════════════════╝")
message("")

#------------------------------------------------------------------------
# Step 1: Fetch upstream IntelRDFPMath repository
#------------------------------------------------------------------------

# Package version and commit hash (matching build.sh)
set(INTELRDFPMATH_VERSION "2.3")
set(INTELRDFPMATH_HASH "ffca6d2")

message(STATUS "Fetching IntelRDFPMath version ${INTELRDFPMATH_VERSION} (commit ${INTELRDFPMATH_HASH})")

FetchContent_Declare(
    IntelRDFPMath_Upstream
    GIT_REPOSITORY https://github.com/xmake-mirror/IntelRDFPMathLib
    GIT_TAG        ${INTELRDFPMATH_HASH}
    SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/IntelRDFPMath-current
    GIT_SHALLOW    OFF  # We need full history to checkout specific commit
    GIT_PROGRESS   TRUE
)

# Make the content available
FetchContent_MakeAvailable(IntelRDFPMath_Upstream)

message(STATUS "IntelRDFPMath source fetched to: ${CMAKE_CURRENT_SOURCE_DIR}/IntelRDFPMath-current")

# Create a custom target to track IntelRDFPMath fetch completion
# This allows other targets to depend on the fetch being complete
add_custom_target(IntelRDFPMath_Fetch_Complete
    COMMENT "IntelRDFPMath upstream source fetched and ready"
)

#------------------------------------------------------------------------
# Step 2: Build all IntelRDFPMath libraries for supported architectures
#------------------------------------------------------------------------

# Include ExternalProject module for building libraries
include(ExternalProject)

message("")
message("──────────────────────────────────────────────────────────────")
message("Building IntelRDFPMath libraries for all architectures...")
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

        ExternalProject_Add(IntelRDFPMath_${CORE}
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
            BUILD_BYPRODUCTS  "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}/libIntelRDFPMath.a"

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

        list(APPEND ALL_CORE_PROJECTS IntelRDFPMath_${CORE})
    else()
        message(WARNING "Skipping ${CORE}: CMakeLists.txt not found at Library/${CORE}")
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 3: Create convenience targets
#------------------------------------------------------------------------

# Create a custom target that depends on all external projects
add_custom_target(build_all_intelrdfpmath ALL
    DEPENDS ${ALL_CORE_PROJECTS}
    COMMENT "Building IntelRDFPMath for all architectures"
)

# Add dependency to ensure IntelRDFPMath is fetched before building
add_dependencies(build_all_intelrdfpmath IntelRDFPMath_Fetch_Complete)

#------------------------------------------------------------------------
# Summary
#------------------------------------------------------------------------

message("")
message("══════════════════════════════════════════════════════════════")
message("Configuration complete.")
message("")
message("IntelRDFPMath version:   ${INTELRDFPMATH_VERSION}")
message("Git commit:      ${INTELRDFPMATH_HASH}")
message("Source location: ${CMAKE_CURRENT_SOURCE_DIR}/IntelRDFPMath-current")
message("")
message("To build all IntelRDFPMath libraries, run:")
message("  cmake --build build")
message("")
message("Individual architecture targets:")
foreach(CORE ${SUPPORTED_CORES})
    message("  - IntelRDFPMath_${CORE}")
endforeach()
message("")
message("Output libraries will be in:")
message("  Library/<CORE>/libIntelRDFPMath.a")
message("══════════════════════════════════════════════════════════════")
