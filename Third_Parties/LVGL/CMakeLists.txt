# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds all LVGL libraries
#
# Build description:
#   This top-level CMakeLists.txt drives the build of all LVGL static
#   libraries for supported SoCs and profiles using CMake ExternalProject.
#       1. Fetches the upstream LVGL repository from GitHub
#       2. Builds all LVGL static libraries for supported architectures
#
#   It is functionally equivalent to build.sh and provides
#   a single, declarative CMake-based build entry point.
#
# Reproducibility:
#   This build is reproducible: given the same source code, build environment,
#   and build instructions, any party can recreate bit-by-bit identical copies
#   of the output artifacts.
#
#   The build does not embed timestamps. SOURCE_DATE_EPOCH is honoured by all
#   toolchain components.
#
# Usage:
#   cd Third_Parties/LVGL
#   cmake -S . -B build
#   cmake --build build
#
# Build outputs:
#   - Library/*/*/libLVGL.a

cmake_minimum_required(VERSION 3.26)

project(LVGL_Package
    VERSION 9.5.0
    DESCRIPTION "LVGL package with upstream source fetch"
    LANGUAGES NONE
)

# Include ExternalProject module for downloading and building
include(ExternalProject)

message("╔════════════════════════════════════════════════════════════╗")
message("║               LVGL Package Build System                    ║")
message("║      Fetching upstream + Building all architectures        ║")
message("╚════════════════════════════════════════════════════════════╝")
message("")

#------------------------------------------------------------------------
# Step 1: Fetch upstream LVGL repository using ExternalProject
#------------------------------------------------------------------------

# Package version and commit hash (matching build.sh)
set(LVGL_VERSION "9.5.0")
set(LVGL_HASH "v9.5.0")

message(STATUS "Fetching LVGL version ${LVGL_VERSION} (commit ${LVGL_HASH})")

# Use ExternalProject to download LVGL source (without building it)
ExternalProject_Add(LVGL_Download
    PREFIX            "${CMAKE_CURRENT_BINARY_DIR}/lvgl-download"
    GIT_REPOSITORY    https://github.com/lvgl/lvgl.git
    GIT_TAG           ${LVGL_HASH}
    GIT_SHALLOW       OFF
    GIT_PROGRESS      TRUE
    SOURCE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/LVGL-current"

    # Skip configure, build, and install steps - we only want the source
    CONFIGURE_COMMAND ""
    BUILD_COMMAND     ""
    INSTALL_COMMAND   ""

    # Log output
    LOG_DOWNLOAD      ON
    LOG_OUTPUT_ON_FAILURE ON
)

message(STATUS "LVGL source will be fetched to: ${CMAKE_CURRENT_SOURCE_DIR}/LVGL-current")

#------------------------------------------------------------------------
# Step 2: Build all LVGL libraries for supported architectures
#------------------------------------------------------------------------

message("")
message("──────────────────────────────────────────────────────────────")
message("Building LVGL libraries for all architectures...")
message("──────────────────────────────────────────────────────────────")

# List of all supported cores
set(SUPPORTED_CORES
    CORTEX_M55
    RV64IMAFDC
    CORTEX_M85
    CORTEX_M7
)
# and their display
set(CORE_DISPLAY
    WaveShare_2_Inches
    TFT_2_4_Inches
    RK050HR18_5_Inches
    WKS43WV067_5_Inches
)

# Determine build type to pass to ExternalProjects
# Default to MinSizeRel for optimal firmware size (adds -Os -DNDEBUG)
if(CMAKE_BUILD_TYPE)
    set(SUBPROJECT_BUILD_TYPE ${CMAKE_BUILD_TYPE})
else()
    set(SUBPROJECT_BUILD_TYPE "MinSizeRel")
endif()

# Create an ExternalProject for each core
list(LENGTH SUPPORTED_CORES NUM_CORES)
math(EXPR LAST_INDEX "${NUM_CORES} - 1")
foreach(CORE_INDEX RANGE 0 ${LAST_INDEX})
    list(GET SUPPORTED_CORES ${CORE_INDEX} CORE)
    list(GET CORE_DISPLAY ${CORE_INDEX} DISPLAY)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Construction/${DISPLAY}/${CORE}/CMakeLists.txt")
        message(STATUS "Configuring build for core: ${CORE} and display ${DISPLAY}")

        ExternalProject_Add(LVGL_${CORE}
            # Prefix - this sets up unique directories for each external project
            PREFIX            "${CMAKE_CURRENT_BINARY_DIR}/ep-${CORE}"

            # Dependency - wait for LVGL source to be downloaded
            DEPENDS           LVGL_Download

            # Source configuration
            SOURCE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/Construction/${DISPLAY}/${CORE}"
            BINARY_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/Construction/${DISPLAY}/${CORE}/build"

            # Configure step - pass build type explicitly for optimization
            CMAKE_ARGS        -DCMAKE_BUILD_TYPE=${SUBPROJECT_BUILD_TYPE}
                              -G ${CMAKE_GENERATOR}
                              -DUSE_LLVM=OFF
            CMAKE_CACHE_ARGS  ""

            # Build step
            BUILD_COMMAND     ${CMAKE_COMMAND} --build <BINARY_DIR>
            BUILD_ALWAYS      OFF
            BUILD_BYPRODUCTS  "${CMAKE_CURRENT_SOURCE_DIR}/Library/${DISPLAY}/${CORE}/libLVGL.a"

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

        list(APPEND ALL_CORE_PROJECTS LVGL_${CORE})
    else()
        message(WARNING "Skipping ${CORE}: CMakeLists.txt not found at Construction/${DISPLAY}/${CORE}")
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 3: Create convenience targets
#------------------------------------------------------------------------

# Create a custom target that depends on all external projects
add_custom_target(build_all_lvgl ALL
    DEPENDS ${ALL_CORE_PROJECTS}
    COMMENT "Building LVGL for all architectures"
)

#------------------------------------------------------------------------
# Summary
#------------------------------------------------------------------------

message("")
message("══════════════════════════════════════════════════════════════")
message("Configuration complete.")
message("")
message("LVGL version:    ${LVGL_VERSION}")
message("Git commit:      ${LVGL_HASH}")
message("Source location: ${CMAKE_CURRENT_SOURCE_DIR}/LVGL-current")
message("Display:         ${DISPLAY}")
message("")
message("To build all LVGL libraries, run:")
message("  cmake --build build")
message("")
message("Individual architecture targets:")
foreach(CORE ${SUPPORTED_CORES})
    message("  - LVGL_${CORE}")
endforeach()
message("")
message("Output libraries will be in:")
message("  Library/<DISPLAY>/<CORE>/libLVGL.a")
message("══════════════════════════════════════════════════════════════")
