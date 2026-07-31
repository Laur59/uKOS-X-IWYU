# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds all TinyUSB static libraries
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
#   cmake --install build
#
# Build outputs:
#   - Family/*/SOC/profile/libTinyUSB_FS.a
#   - Family/*/SOC/profile/libTinyUSB_HS.a
#
# Supported SoCs and profiles are defined in core.list.

cmake_minimum_required(VERSION 3.26)

project(TinyUSB_Package
    VERSION 0.21.0
    DESCRIPTION "TinyUSB library package for all supported SOCs"
    LANGUAGES NONE
)

# Default build type to MinSizeRel (-Os) for optimal firmware size.
# This must be set here because ExternalProject_Add forwards CMAKE_BUILD_TYPE
# to all sub-projects (see Step 3 below).
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE MinSizeRel CACHE STRING "Build type")
endif()

# Default install prefix: keep Library/ adjacent to Construction/ inside the source tree.
# Override with cmake --install build --prefix /other/path if needed.
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "Install prefix" FORCE)
endif()

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
set(TINYUSB_VERSION "0.21.0")
set(TINYUSB_HASH "eef5af8")

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
        # Pinned to SDK 2.3.0 (was a floating "master", which broke the old
        # hazard3.patch on every upstream move — see removed PATCH_COMMAND).
        GIT_TAG        98a542c1a62fb549ffb5d66a3e5892b06276b670
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

#------------------------------------------------------------------------
# Drift check for shadow copies of upstream sources
#
# Construction/Interface/Patches carries locally modified copies of
# upstream files that are compiled INSTEAD of the originals, so upstream
# fixes to those files would otherwise go unnoticed. Each shadow copy has
# a sidecar <file>.upstream-sha256 recording the hash of the upstream
# original it was last reviewed against.
#------------------------------------------------------------------------

function(check_shadow_copy_drift UPSTREAM_FILE BASELINE_FILE)
    if(NOT EXISTS "${UPSTREAM_FILE}")
        return()
    endif()
    if(NOT EXISTS "${BASELINE_FILE}")
        message(WARNING "Shadow copy baseline missing: ${BASELINE_FILE}\n"
            "Create it with:\n"
            "  shasum -a 256 ${UPSTREAM_FILE} | cut -d' ' -f1 > ${BASELINE_FILE}")
        return()
    endif()
    file(SHA256 "${UPSTREAM_FILE}" UPSTREAM_HASH)
    file(READ "${BASELINE_FILE}" BASELINE_HASH)
    string(STRIP "${BASELINE_HASH}" BASELINE_HASH)
    if(NOT UPSTREAM_HASH STREQUAL BASELINE_HASH)
        message(WARNING "Upstream file changed since its shadow copy was last reviewed:\n"
            "  ${UPSTREAM_FILE}\n"
            "Review the upstream changes and port anything relevant into the shadow copy:\n"
            "  git -C ${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current log -p -- <file>\n"
            "then refresh the baseline:\n"
            "  shasum -a 256 ${UPSTREAM_FILE} | cut -d' ' -f1 > ${BASELINE_FILE}")
    endif()
endfunction()

check_shadow_copy_drift(
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/src/portable/raspberrypi/rp2040/dcd_rp2040.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/Construction/Interface/Patches/mcu/raspberrypi/pico2/dcd_rp2040.c.upstream-sha256"
)

# Stamp file encoding the fetched version/hash. It is regenerated whenever
# TINYUSB_VERSION/TINYUSB_HASH change and is wired as a file-level dependency
# of every SOC's configure step (see Step 3), which is what actually forces
# the libraries to be rebuilt after a version bump.
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

# Install TinyUSB stack headers from src/ only
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/TinyUSB-current/src/"
        DESTINATION "Library/Include/TinyUSB-current/src"
        FILES_MATCHING PATTERN "*.h"
)

# Install uKOS interface files from the three designated subdirectories
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Construction/Interface/Includes/"
        DESTINATION "Library/Include/Interface/Includes"
        FILES_MATCHING PATTERN "*.h"
)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Construction/Interface/Models/"
        DESTINATION "Library/Include/Interface/Models"
        FILES_MATCHING PATTERN "*.c_inc"
)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Construction/Interface/OSAL/"
        DESTINATION "Library/Include/Interface/OSAL"
        FILES_MATCHING PATTERN "*.h"
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
    "pico2m33|rp2350|cdc_cdc"
    "pico2riscv|rp2350|cdc_cdc"
#     "v8|STM32V873|cdc_cdc,cdc_msc,cdc_video"
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
    set(SOC_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Construction/Family/${FAMILY}/${SOC}")

    if(EXISTS "${SOC_SOURCE_DIR}/CMakeLists.txt")
        message(STATUS "Configuring: ${SOC} (${FAMILY}) - Profiles: ${PROFILES_DISPLAY}")

        # Create unique project name (include FAMILY so distinct families
        # sharing the same SOC name — e.g. pico2 and pico2riscv on rp2350 —
        # do not collide).
        set(PROJECT_NAME "TinyUSB_${FAMILY}_${SOC}")

        # Determine build type to pass to ExternalProject
        # Default to MinSizeRel for optimal firmware size (adds -Os -DNDEBUG)
        if(CMAKE_BUILD_TYPE)
            set(SUBPROJECT_BUILD_TYPE ${CMAKE_BUILD_TYPE})
        else()
            set(SUBPROJECT_BUILD_TYPE "MinSizeRel")
        endif()

        ExternalProject_Add(${PROJECT_NAME}
            # Prefix - unique directories for each external project
            PREFIX            "${CMAKE_CURRENT_BINARY_DIR}/ep-${FAMILY}-${SOC}"

            # Source configuration
            SOURCE_DIR        "${SOC_SOURCE_DIR}"
            BINARY_DIR        "${SOC_SOURCE_DIR}/build_cmake"

            # Ordering only: ensures the upstream source is fetched first.
            # (A plain custom target here never invalidates this project's
            # stamps — rebuild on version change comes from the
            # ExternalProject_Add_StepDependencies call below.)
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

        # File-level dependency on the version stamp: a TINYUSB_HASH change
        # regenerates the stamp, which invalidates this project's configure
        # step (re-evaluating the source GLOBs) and thus the build step.
        ExternalProject_Add_StepDependencies(${PROJECT_NAME} configure "${TINYUSB_SOURCE_STAMP}")

        list(APPEND ALL_SOC_PROJECTS ${PROJECT_NAME})
    else()
        message(WARNING "Skipping ${SOC}: CMakeLists.txt not found at ${SOC_SOURCE_DIR}")
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 4: Install rules — libraries and config files
#
# cmake --install build gathers .a files and TinyUSBConfig.cmake from the
# per-SOC build trees (build_cmake/) and deploys them to Library/Family/.
# Headers are installed from TinyUSB-current/ to Library/Include/.
#------------------------------------------------------------------------

foreach(SOC_CONFIG ${SUPPORTED_SOCS})
    string(REPLACE "|" ";" CONFIG_LIST "${SOC_CONFIG}")
    list(GET CONFIG_LIST 0 FAMILY)
    list(GET CONFIG_LIST 1 SOC)
    list(GET CONFIG_LIST 2 PROFILES_STR)
    string(REPLACE "," ";" PROFILES "${PROFILES_STR}")

    set(SOC_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Construction/Family/${FAMILY}/${SOC}")
    set(SOC_BUILD_DIR  "${SOC_SOURCE_DIR}/build_cmake")

    if(EXISTS "${SOC_SOURCE_DIR}/CMakeLists.txt")
        foreach(PROFILE ${PROFILES})
            install(FILES
                "${SOC_BUILD_DIR}/${PROFILE}/libTinyUSB_FS.a"
                "${SOC_BUILD_DIR}/${PROFILE}/libTinyUSB_HS.a"
                "${SOC_BUILD_DIR}/${PROFILE}/TinyUSBConfig.cmake"
                "${SOC_SOURCE_DIR}/${PROFILE}/tusb_config.h"
                DESTINATION "Library/Family/${FAMILY}/${SOC}/${PROFILE}"
                OPTIONAL
            )
        endforeach()
    endif()
endforeach()

#------------------------------------------------------------------------
# Step 5: Create convenience targets
#------------------------------------------------------------------------

# Create a custom target that depends on all external projects
add_custom_target(build_all_tinyusb ALL
    DEPENDS ${ALL_SOC_PROJECTS}
    COMMENT "Building TinyUSB for all SOCs and profiles"
)

# Add dependency to ensure TinyUSB is fetched before building
add_dependencies(build_all_tinyusb TinyUSB_Fetch_Complete)

#------------------------------------------------------------------------
# Step 6: Summary
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
message("  cmake --install build")
message("")
message("Individual SOC targets:")
foreach(SOC_CONFIG ${SUPPORTED_SOCS})
    string(REPLACE "|" ";" CONFIG_LIST "${SOC_CONFIG}")
    list(GET CONFIG_LIST 0 FAMILY)
    list(GET CONFIG_LIST 1 SOC)
    message("  - TinyUSB_${FAMILY}_${SOC}")
endforeach()
message("")
message("Output libraries will be in:")
message("  Library/Family/<FAMILY>/<SOC>/<PROFILE>/libTinyUSB_FS.a")
message("  Library/Family/<FAMILY>/<SOC>/<PROFILE>/libTinyUSB_HS.a")
message("══════════════════════════════════════════════════════════════")
