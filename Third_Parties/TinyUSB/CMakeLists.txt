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
#   Umbrella CMake build definition for producing TinyUSB static libraries.
#
# Build description:
#   This top-level CMakeLists.txt drives the build of all TinyUSB static
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
#   cd Third_Parties/TinyUSB
#   cmake -S . -B build -GNinja
#   cmake --build build
#
# Build outputs:
#   - Family/*/SOC/profile/libTinyUSB_FS.a
#   - Family/*/SOC/profile/libTinyUSB_HS.a
#
# Supported SoCs and profiles are defined in core.list.
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

project(TinyUSB_Package
    VERSION 0.20.0
    DESCRIPTION "TinyUSB library package for all supported SOCs"
    LANGUAGES NONE
)

# Include FetchContent module for downloading upstream TinyUSB
include(FetchContent)
# Include ExternalProject module for building libraries
include(ExternalProject)

message("╔════════════════════════════════════════════════════════════╗")
message("║           TinyUSB Package Build System                     ║")
message("║    Fetching upstream + Building all SOCs and profiles      ║")
message("╚════════════════════════════════════════════════════════════╝")
message("")

#------------------------------------------------------------------------
# Step 1: Fetch upstream TinyUSB repository
#------------------------------------------------------------------------

# Package version and commit hash (matching build_with_cmake.sh)
set(TINYUSB_VERSION "0.20.0")
set(TINYUSB_HASH "3eafddb")

message(STATUS "Fetching TinyUSB version ${TINYUSB_VERSION} (commit ${TINYUSB_HASH})")

FetchContent_Declare(
    TinyUSB_Upstream
    GIT_REPOSITORY https://github.com/hathach/tinyusb
    GIT_TAG        ${TINYUSB_HASH}
    SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current
    GIT_SHALLOW    OFF  # We need full history to checkout specific commit
    GIT_PROGRESS   TRUE
)

# Make the content available
FetchContent_MakeAvailable(TinyUSB_Upstream)

message(STATUS "TinyUSB source fetched to: ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current")

# Initialize and update submodules (TinyUSB requires lib submodules)
message(STATUS "Updating TinyUSB submodules...")
execute_process(
    COMMAND git submodule update --init lib
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current
    RESULT_VARIABLE SUBMODULE_RESULT
    OUTPUT_VARIABLE SUBMODULE_OUTPUT
    ERROR_VARIABLE SUBMODULE_ERROR
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_STRIP_TRAILING_WHITESPACE
)

if(NOT SUBMODULE_RESULT EQUAL 0)
    message(WARNING "Failed to update TinyUSB submodules: ${SUBMODULE_ERROR}")
else()
    message(STATUS "TinyUSB submodules updated successfully")
endif()

# Fetch additional dependencies required by some SOCs
# Nordic nRF5340 requires nrfx driver
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/hw/mcu/nordic/nrfx/README.md")
    message(STATUS "Fetching Nordic nrfx driver...")

    FetchContent_Declare(
        nrfx_upstream
        GIT_REPOSITORY https://github.com/NordicSemiconductor/nrfx.git
        GIT_TAG        7c47cc0a56ce44658e6da2458e86cd8783ccc4a2
        SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/hw/mcu/nordic/nrfx
        GIT_SHALLOW    OFF
        GIT_PROGRESS   TRUE
        UPDATE_DISCONNECTED TRUE
    )
    FetchContent_MakeAvailable(nrfx_upstream)
    message(STATUS "Nordic nrfx driver fetched successfully")
else()
    message(STATUS "Nordic nrfx driver already present")
endif()

# Nordic nRF5340 also requires CMSIS_5
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/lib/CMSIS_5/README.md")
    message(STATUS "Fetching CMSIS_5...")

    FetchContent_Declare(
        cmsis5_upstream
        GIT_REPOSITORY https://github.com/ARM-software/CMSIS_5.git
        GIT_TAG        2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
        SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/lib/CMSIS_5
        GIT_SHALLOW    OFF
        GIT_PROGRESS   TRUE
        UPDATE_DISCONNECTED TRUE
    )
    FetchContent_MakeAvailable(cmsis5_upstream)
    message(STATUS "CMSIS_5 fetched successfully")
else()
    message(STATUS "CMSIS_5 already present")
endif()

# Raspberry Pi Pico2 requires pico-sdk
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/lib/pico-sdk/README.md")
    message(STATUS "Fetching Raspberry Pi pico-sdk...")

    FetchContent_Declare(
        pico_sdk_upstream
        GIT_REPOSITORY https://github.com/raspberrypi/pico-sdk.git
        GIT_TAG        2.1.0
        SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/lib/pico-sdk
        GIT_SHALLOW    OFF
        GIT_PROGRESS   TRUE
        UPDATE_DISCONNECTED TRUE
        EXCLUDE_FROM_ALL  # Don't build pico-sdk targets, only fetch sources
    )
    # Use MakeAvailable with EXCLUDE_FROM_ALL - we only need the sources, not to build pico-sdk
    # The pico-sdk source files are compiled directly into TinyUSB libraries by TinyUSB.cmake
    FetchContent_MakeAvailable(pico_sdk_upstream)

    # Initialize pico-sdk submodules (pico-sdk has its own dependencies)
    message(STATUS "Updating pico-sdk submodules...")
    execute_process(
        COMMAND git submodule update --init --recursive
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/lib/pico-sdk
        RESULT_VARIABLE PICOSDK_SUBMODULE_RESULT
        OUTPUT_VARIABLE PICOSDK_SUBMODULE_OUTPUT
        ERROR_VARIABLE PICOSDK_SUBMODULE_ERROR
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_STRIP_TRAILING_WHITESPACE
    )

    if(NOT PICOSDK_SUBMODULE_RESULT EQUAL 0)
        message(WARNING "Failed to update pico-sdk submodules: ${PICOSDK_SUBMODULE_ERROR}")
    else()
        message(STATUS "pico-sdk submodules updated successfully")
    endif()

    message(STATUS "pico-sdk fetched successfully")
else()
    message(STATUS "pico-sdk already present")
endif()

# Create a stamp file that tracks when the source was last fetched
# This helps ExternalProjects know when to rebuild
set(TINYUSB_SOURCE_STAMP "${CMAKE_CURRENT_BINARY_DIR}/tinyusb_source.stamp")

# Create a custom command that generates the stamp file
# The stamp file content changes when the version/hash changes
add_custom_command(
    OUTPUT "${TINYUSB_SOURCE_STAMP}"
    COMMAND ${CMAKE_COMMAND} -E echo "${TINYUSB_VERSION}-${TINYUSB_HASH}" > "${TINYUSB_SOURCE_STAMP}"
    COMMENT "Creating TinyUSB source version stamp"
    VERBATIM
)

# Create a custom target to track TinyUSB fetch completion
add_custom_target(TinyUSB_Fetch_Complete
    DEPENDS "${TINYUSB_SOURCE_STAMP}"
    COMMENT "TinyUSB upstream source fetched and ready"
)

#------------------------------------------------------------------------
# Step 2: Configuration - SOCs and Profiles
#------------------------------------------------------------------------

# Define the SOC configurations matching core.list
# Format: "FAMILY|SOC|PROFILES" where PROFILES is comma-separated
set(SUPPORTED_SOCS
    "nrf|nRF5340|cdc_cdc,cdc_msc"
    "f2|STM32F207|cdc_cdc,cdc_msc"
    "h7|STM32H743|cdc_cdc,cdc_msc"
    "h7|STM32H747|cdc_cdc,cdc_msc,cdc_video"
    "l4|STM32L4R5|cdc_cdc,cdc_msc"
    "u5|STM32U5G9|cdc_cdc,cdc_msc,cdc_video"
    "n6|STM32N657|cdc_cdc,cdc_msc,cdc_video"
    "pico2|rp2350|cdc_cdc"
)

#------------------------------------------------------------------------
# Step 3: Build all SOCs using ExternalProject
#------------------------------------------------------------------------

message("")
message("──────────────────────────────────────────────────────────────")
message("Configuring builds for all SOCs...")
message("──────────────────────────────────────────────────────────────")

set(ALL_SOC_PROJECTS "")

foreach(SOC_CONFIG ${SUPPORTED_SOCS})
    # Parse the configuration string: FAMILY|SOC|PROFILES
    string(REPLACE "|" ";" CONFIG_LIST "${SOC_CONFIG}")
    list(GET CONFIG_LIST 0 FAMILY)
    list(GET CONFIG_LIST 1 SOC)
    list(GET CONFIG_LIST 2 PROFILES_STR)

    # Convert comma-separated profiles to list
    string(REPLACE "," ";" PROFILES "${PROFILES_STR}")

    # Convert profiles list to comma-separated string for display
    string(REPLACE ";" ", " PROFILES_DISPLAY "${PROFILES}")

    # Path to SOC CMakeLists.txt
    set(SOC_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Library/Family/${FAMILY}/${SOC}")

    if(EXISTS "${SOC_SOURCE_DIR}/CMakeLists.txt")
        message(STATUS "Configuring: ${SOC} (${FAMILY}) - Profiles: ${PROFILES_DISPLAY}")

        # Create unique project name
        set(PROJECT_NAME "TinyUSB_${SOC}")

        # Determine build type to pass to ExternalProject
        # Default to MinSizeRel for optimal firmware size (adds -Os -DNDEBUG)
        if(CMAKE_BUILD_TYPE)
            set(SUBPROJECT_BUILD_TYPE ${CMAKE_BUILD_TYPE})
        else()
            set(SUBPROJECT_BUILD_TYPE "MinSizeRel")
        endif()

        ExternalProject_Add(${PROJECT_NAME}
            # Prefix - unique directories for each external project
            PREFIX            "${CMAKE_CURRENT_BINARY_DIR}/ep-${SOC}"

            # Source configuration
            SOURCE_DIR        "${SOC_SOURCE_DIR}"
            BINARY_DIR        "${SOC_SOURCE_DIR}/build_cmake"

            # Depend on the fetch completion target - when version changes, this triggers rebuild
            DEPENDS           TinyUSB_Fetch_Complete

            # Configure step
            # Pass build type explicitly to ensure optimization
            CMAKE_ARGS        -DCMAKE_BUILD_TYPE=${SUBPROJECT_BUILD_TYPE}
                              -G ${CMAKE_GENERATOR}
            CMAKE_CACHE_ARGS  ""

            # Build step
            BUILD_COMMAND     ${CMAKE_COMMAND} --build <BINARY_DIR> -j
            BUILD_ALWAYS      OFF

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

        list(APPEND ALL_SOC_PROJECTS ${PROJECT_NAME})
    else()
        message(WARNING "Skipping ${SOC}: CMakeLists.txt not found at ${SOC_SOURCE_DIR}")
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 4: Create convenience targets
#------------------------------------------------------------------------

# Create a custom target that depends on all external projects
add_custom_target(build_all_tinyusb ALL
    DEPENDS ${ALL_SOC_PROJECTS}
    COMMENT "Building TinyUSB for all SOCs and profiles"
)

# Add dependency to ensure TinyUSB is fetched before building
add_dependencies(build_all_tinyusb TinyUSB_Fetch_Complete)

#------------------------------------------------------------------------
# Summary
#------------------------------------------------------------------------

message("")
message("══════════════════════════════════════════════════════════════")
message("Configuration complete.")
message("")
message("TinyUSB version:   ${TINYUSB_VERSION}")
message("Git commit:        ${TINYUSB_HASH}")
message("Source location:   ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current")
message("")
message("To build all TinyUSB libraries, run:")
message("  cmake --build build")
message("")
message("Individual SOC targets:")
foreach(SOC_CONFIG ${SUPPORTED_SOCS})
    string(REPLACE "|" ";" CONFIG_LIST "${SOC_CONFIG}")
    list(GET CONFIG_LIST 1 SOC)
    message("  - TinyUSB_${SOC}")
endforeach()
message("")
message("Output libraries will be in:")
message("  Library/Family/<FAMILY>/<SOC>/<PROFILE>/libTinyUSB_FS.a")
message("  Library/Family/<FAMILY>/<SOC>/<PROFILE>/libTinyUSB_HS.a")
message("══════════════════════════════════════════════════════════════")
