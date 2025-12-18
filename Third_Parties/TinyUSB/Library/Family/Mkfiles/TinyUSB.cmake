# TinyUSB.
# ========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen      The 2025-10-11
# Modifs:
#
# Project:  uKOS-X
# Goal:     CMake module to build TinyUSB libraries
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

include_guard(GLOBAL)

# Include upstream TinyUSB CMakeLists.txt to access tinyusb_sources_get() function
include(${PATH_TINYUSB}/TinyUSB-current/src/CMakeLists.txt)

# Function to generate TinyUSB libraries for a given SoC
#
# Arguments:
#   FAMILY              - Processor family (e.g. h7)
#   CPU_SPEC            - CPU specification for GCC (e.g. -mcpu=cortex-m7)
#   FLAGS_FP            - Floating-point flags (e.g. -mfloat-abi=hard -mfpu=fpv5-sp-d16)
#   DEFS_UKOS_EXTRA     - Additional uKOS defines (e.g. -DCORE_CM7)
#   PROFILES_LIST       - List of profiles to build (e.g. "cdc_cdc;cdc_msc")
#   PROVIDER            - SoC provider (default: st)
function(add_tinyusb_libraries)
    # Parse arguments
    set(options "")
    set(oneValueArgs FAMILY CPU_SPEC FLAGS_FP DEFS_UKOS_EXTRA PROVIDER)
    set(multiValueArgs PROFILES_LIST)
    cmake_parse_arguments(TINYUSB "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Validate required arguments
    if(NOT DEFINED TINYUSB_FAMILY)
        message(FATAL_ERROR "FAMILY is not defined")
    endif()
    if(NOT DEFINED TINYUSB_PROFILES_LIST)
        message(FATAL_ERROR "PROFILES_LIST is not defined")
    endif()

    # Default value for PROVIDER
    if(NOT DEFINED TINYUSB_PROVIDER)
        set(TINYUSB_PROVIDER "st")
    endif()

    # Remove NDEBUG from build flags for Raspberry Pi to match make build behavior
    # The pico-sdk requires hard_assertion_failure() when NDEBUG is defined,
    # but this library doesn't provide it. The make build uses -Os without -DNDEBUG.
    if(TINYUSB_PROVIDER STREQUAL "raspberrypi")
        string(REPLACE "-DNDEBUG" "" _tmp_flags "${CMAKE_C_FLAGS_MINSIZEREL}")
        set(CMAKE_C_FLAGS_MINSIZEREL "${_tmp_flags}" CACHE STRING "Flags for MinSizeRel build" FORCE)
        string(REPLACE "-DNDEBUG" "" _tmp_flags "${CMAKE_C_FLAGS_RELEASE}")
        set(CMAKE_C_FLAGS_RELEASE "${_tmp_flags}" CACHE STRING "Flags for Release build" FORCE)
        string(REPLACE "-DNDEBUG" "" _tmp_flags "${CMAKE_C_FLAGS_RELWITHDEBINFO}")
        set(CMAKE_C_FLAGS_RELWITHDEBINFO "${_tmp_flags}" CACHE STRING "Flags for RelWithDebInfo build" FORCE)
        unset(_tmp_flags)
    endif()

    # Common include paths (similar to PATH_INCLUDES in TinyUSB.mk)
    set(COMMON_INCLUDES
        ${PATH_UKOS}/OS/Includes
        ${PATH_UKOS}/OS/Lib_kernels
        ${PATH_UKOS}/OS/Lib_kernels/kern
        ${PATH_UKOS}/OS/Lib_kernels/kern/private
        ${PATH_TINYUSB}/uKOS_Interface/OSAL
        ${PATH_TINYUSB}/TinyUSB-current/hw
        ${PATH_TINYUSB}/TinyUSB-current/src
        ${PATH_TINYUSB}/TinyUSB-current/src/common
        ${PATH_TINYUSB}/TinyUSB-current/src/device
        ${PATH_TINYUSB}/TinyUSB-current/src/class
    )

    # Add paths specific to provider ST
    if(TINYUSB_PROVIDER STREQUAL "st")
        list(APPEND COMMON_INCLUDES
        $   {PATH_TINYUSB}/TinyUSB-current/lib/CMSIS_5/CMSIS/Core/Include
            ${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime
            ${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Includes
            ${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Includes
            ${PATH_TINYUSB}/uKOS_Interface/Includes/mcu/st
            # Note: ST CMSIS device headers come from uKOS Ports/EquatesModels above,
            # not from TinyUSB upstream (which doesn't include them)
        )
    endif()

    # Add paths specific to provider Nordic
    if(TINYUSB_PROVIDER STREQUAL "nordic")
        # Automatically fetch Nordic dependencies if not present
        if(NOT EXISTS "${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/README.md")
            message(STATUS "Nordic nrfx driver not found, downloading automatically...")
            include(FetchContent)

            # Fetch nrfx driver
            FetchContent_Declare(
                nrfx
                GIT_REPOSITORY https://github.com/NordicSemiconductor/nrfx.git
                GIT_TAG        7c47cc0a56ce44658e6da2458e86cd8783ccc4a2
                GIT_SHALLOW    TRUE
                GIT_PROGRESS   TRUE
                SOURCE_DIR     ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx
            )
            FetchContent_MakeAvailable(nrfx)
            message(STATUS "Nordic nrfx driver downloaded successfully")
        else()
            message(STATUS "Using existing Nordic nrfx driver")
        endif()

        # Check and fetch CMSIS_5 if needed
        if(NOT EXISTS "${PATH_TINYUSB}/TinyUSB-current/lib/CMSIS_5/README.md")
            message(STATUS "CMSIS_5 not found, downloading automatically...")
            include(FetchContent)

            FetchContent_Declare(
                cmsis5
                GIT_REPOSITORY https://github.com/ARM-software/CMSIS_5.git
                GIT_TAG        2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
                GIT_SHALLOW    TRUE
                GIT_PROGRESS   TRUE
                SOURCE_DIR     ${PATH_TINYUSB}/TinyUSB-current/lib/CMSIS_5
            )
            FetchContent_MakeAvailable(cmsis5)
            message(STATUS "CMSIS_5 downloaded successfully")
        else()
            message(STATUS "Using existing CMSIS_5")
        endif()

        list(APPEND COMMON_INCLUDES
            ${PATH_TINYUSB}/TinyUSB-current/lib/CMSIS_5/CMSIS/Core/Include
            ${PATH_TINYUSB}/TinyUSB-current/hw/bsp/nrf
            ${PATH_TINYUSB}/TinyUSB-current/hw/bsp/nrf/nrfx_config
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/mdk
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/hal
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/templates
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/drivers
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/drivers/include
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/drivers/src
        )
    endif()

    # Add paths specific to provider Raspberry Pi
    if(TINYUSB_PROVIDER STREQUAL "raspberrypi")
        list(APPEND COMMON_INCLUDES
            # Pico-SDK common includes
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/common/pico_base_headers/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_base/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_irq/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_resets/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_sync/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_sync_spin_lock/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_timer/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_claim/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_structs/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_compiler/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_sections/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_panic/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_common/include
            # RP2350-specific includes
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2350/pico_platform/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2350/hardware_structs/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2350/hardware_regs/include
            # Additional pico-sdk includes
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/bazel/include
            # Pico-SDK runtime includes
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_runtime_init/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_runtime/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/common/hardware_claim/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/common/pico_sync/include
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/common/pico_time/include
            # TinyUSB portable driver includes
            ${PATH_TINYUSB}/TinyUSB-current/src/portable/raspberrypi/rp2040
            # uKOS interface includes
            ${PATH_TINYUSB}/uKOS_Interface/Includes/mcu/raspberrypi
        )
    endif()

    # Common sources (similar to SRC in TinyUSB.mk)
    set(COMMON_SOURCES
        ${PATH_TINYUSB}/uKOS_System/headerTusb.c
        ${PATH_TINYUSB}/uKOS_Interface/OSAL/tusb_os_custom.c
    )

    # Use upstream TinyUSB source list (25 curated files instead of GLOB's 74+ files)
    # This ensures we only compile files selected by TinyUSB developers
    tinyusb_sources_get(TINYUSB_SOURCES)
    list(APPEND COMMON_SOURCES ${TINYUSB_SOURCES})
    # Add bth_device.c which is not included in upstream's curated list
    list(APPEND COMMON_SOURCES
        ${PATH_TINYUSB}/TinyUSB-current/src/class/bth/bth_device.c
    )

    # Add provider-specific portable driver sources (DCD/HCD drivers)
    # These are the USB controller drivers essential for each platform
    if(TINYUSB_PROVIDER STREQUAL "st")
        # ST USB drivers (FSdev, Type-C)
        file(GLOB_RECURSE ST_SOURCES "${PATH_TINYUSB}/TinyUSB-current/src/portable/st/*.c")
        # Synopsys DWC2 controllers (used by many ST MCUs)
        file(GLOB_RECURSE SYNOPSYS_SOURCES "${PATH_TINYUSB}/TinyUSB-current/src/portable/synopsys/*.c")
        list(APPEND COMMON_SOURCES ${ST_SOURCES} ${SYNOPSYS_SOURCES})
    elseif(TINYUSB_PROVIDER STREQUAL "nordic")
        # Nordic nRF5x USB drivers
        file(GLOB_RECURSE NORDIC_SOURCES "${PATH_TINYUSB}/TinyUSB-current/src/portable/nordic/*.c")
        list(APPEND COMMON_SOURCES ${NORDIC_SOURCES})
    elseif(TINYUSB_PROVIDER STREQUAL "raspberrypi")
        # Raspberry Pi RP2040/RP2350 USB drivers
        file(GLOB_RECURSE RPI_PORTABLE_SOURCES
            "${PATH_TINYUSB}/TinyUSB-current/src/portable/raspberrypi/pio_usb/*.c"
        )
        list(APPEND COMMON_SOURCES ${RPI_PORTABLE_SOURCES})
        # Use patched DCD driver for uKOS
        list(APPEND COMMON_SOURCES
            ${PATH_TINYUSB}/TinyUSB-current/src/portable/raspberrypi/rp2040/hcd_rp2040.c
            ${PATH_TINYUSB}/TinyUSB-current/src/portable/raspberrypi/rp2040/rp2040_usb.c
            ${PATH_TINYUSB}/uKOS_Interface/Patches/mcu/raspberrypi/${TINYUSB_FAMILY}/dcd_rp2040.c
        )
    endif()

    # Add Nordic-specific sources
    if(TINYUSB_PROVIDER STREQUAL "nordic")
        list(APPEND COMMON_SOURCES
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/drivers/src/nrfx_usbreg.c
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/drivers/src/nrfx_power.c
            ${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/mdk/system_nrf5340_application.c
            ${PATH_TINYUSB}/Library/Family/${TINYUSB_FAMILY}/${SOC}/init.c
        )
    endif()

    # Add Raspberry Pi-specific sources (pico-sdk)
    if(TINYUSB_PROVIDER STREQUAL "raspberrypi")
        list(APPEND COMMON_SOURCES
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/common/hardware_claim/claim.c
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_irq/irq.c
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_panic/panic.c
            ${PATH_TINYUSB}/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_sync_spin_lock/sync_spin_lock.c
            ${PATH_TINYUSB}/Library/Family/${TINYUSB_FAMILY}/${SOC}/init.c
        )
    endif()

    # Base compilation definitions
    list(APPEND DEFS_UKOS
        THIRD_PARTY_S
        ${SOC}_S
        LITTLE_ENDIAN_S
    )

    # Convert string arguments to lists (handles space-separated flags properly)
    if(DEFINED TINYUSB_CPU_SPEC)
        separate_arguments(CPU_SPEC_LIST UNIX_COMMAND "${TINYUSB_CPU_SPEC}")
    endif()
    if(DEFINED TINYUSB_FLAGS_FP)
        separate_arguments(FLAGS_FP_LIST UNIX_COMMAND "${TINYUSB_FLAGS_FP}")
    endif()

    # Merge uKOS base definitions with extra definitions
    if(DEFINED TINYUSB_DEFS_UKOS_EXTRA AND NOT TINYUSB_DEFS_UKOS_EXTRA STREQUAL "")
        separate_arguments(DEFS_UKOS_EXTRA_LIST UNIX_COMMAND "${TINYUSB_DEFS_UKOS_EXTRA}")
        list(APPEND DEFS_UKOS ${DEFS_UKOS_EXTRA_LIST})
    endif()

    # Build OPTS_UKOS as a proper list
    list(APPEND OPTS_UKOS
        ${CPU_SPEC_LIST}
        ${FLAGS_FP_LIST}
        -std=c2x
        -g3 -Wall -Wno-pedantic -Wlogical-op
        -fsingle-precision-constant
        -Wno-error=undef -Wno-error=unused-parameter
        -Wno-error=cast-align -Wno-error=cast-qual
        -Wno-error=redundant-decls -Wno-error=strict-prototypes
        -Wno-missing-braces
        $<$<C_COMPILER_ID:GNU>:-mpoke-function-name>
    )

    # Add provider-specific compile flags
    if(TINYUSB_PROVIDER STREQUAL "raspberrypi")
        # Disable flash macro (code is already in RAM)
        list(APPEND OPTS_UKOS "-D__not_in_flash\(x\)=")
    endif()

    # For each profile, build libraries FS and HS
    foreach(PROFILE ${TINYUSB_PROFILES_LIST})
        set(PROFILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${PROFILE}")

        # Sources specific to profil
        set(PROFILE_SOURCES
            ${COMMON_SOURCES}
            ${PATH_TINYUSB}/uKOS_Interface/Descriptors/${PROFILE}/usb_descriptors.c
        )

        # FS (Full Speed) library
        set(LIB_FS "TinyUSB_${SOC}_${PROFILE}_FS")
        add_library(${LIB_FS} STATIC ${PROFILE_SOURCES})

        target_include_directories(${LIB_FS} PRIVATE
            ${COMMON_INCLUDES}
            ${PATH_TINYUSB}/Library/Family/${TINYUSB_FAMILY}/${SOC}/${PROFILE}
        )

        target_compile_definitions(${LIB_FS} PRIVATE
            SYSTEM_TINYUSB_FS_S
            ${DEFS_UKOS}
        )
        target_compile_options(${LIB_FS} PRIVATE ${OPTS_UKOS})

        set_target_properties(${LIB_FS} PROPERTIES
            OUTPUT_NAME "TinyUSB_FS"
            ARCHIVE_OUTPUT_DIRECTORY "${PROFILE_DIR}"
        )

        # HS (High Speed) library
        set(LIB_HS "TinyUSB_${SOC}_${PROFILE}_HS")
        add_library(${LIB_HS} STATIC ${PROFILE_SOURCES})

        target_include_directories(${LIB_HS} PRIVATE
            ${COMMON_INCLUDES}
            ${PATH_TINYUSB}/Library/Family/${TINYUSB_FAMILY}/${SOC}/${PROFILE}
        )

        target_compile_definitions(${LIB_HS} PRIVATE
            SYSTEM_TINYUSB_HS_S
            ${DEFS_UKOS}
        )
        target_compile_options(${LIB_HS} PRIVATE ${OPTS_UKOS})

        set_target_properties(${LIB_HS} PROPERTIES
            OUTPUT_NAME "TinyUSB_HS"
            ARCHIVE_OUTPUT_DIRECTORY "${PROFILE_DIR}"
        )

        # Strip libraries
        if(CMAKE_STRIP)
            add_custom_command(TARGET ${LIB_FS} POST_BUILD
                COMMAND ${CMAKE_STRIP} --strip-unneeded $<TARGET_FILE:${LIB_FS}>
                COMMENT "Stripping libTinyUSB_FS.a for ${SOC}/${PROFILE}"
            )

            add_custom_command(TARGET ${LIB_HS} POST_BUILD
                COMMAND ${CMAKE_STRIP} --strip-unneeded $<TARGET_FILE:${LIB_HS}>
                COMMENT "Stripping libTinyUSB_HS.a for ${SOC}/${PROFILE}"
            )
        endif()

        # Generate TinyUSBConfig.cmake for this profile
        generate_tinyusb_config(
            PROFILE_DIR "${PROFILE_DIR}"
            SOC "${SOC}"
            PROFILE "${PROFILE}"
            PROVIDER "${TINYUSB_PROVIDER}"
            FAMILY "${TINYUSB_FAMILY}"
        )

        message(STATUS "Configuration du profil TinyUSB: ${SOC}/${PROFILE}")
    endforeach()
endfunction()

# Function to generate TinyUSBConfig.cmake for a profile
#
# This function creates a CMake package configuration file that exports
# the TinyUSB library targets with all required include paths and compile
# definitions. This allows consuming projects to use find_package(TinyUSB)
# without manually specifying include paths.
#
# Arguments:
#   PROFILE_DIR - Directory where the profile's libraries are located
#   SOC         - SoC name (e.g. STM32L4R5)
#   PROFILE     - Profile name (e.g. cdc_cdc)
#   PROVIDER    - SoC provider (e.g. st, nordic)
#   FAMILY      - Processor family (e.g. l4, h7)
function(generate_tinyusb_config)
    # Parse arguments
    set(options "")
    set(oneValueArgs PROFILE_DIR SOC PROFILE PROVIDER FAMILY)
    set(multiValueArgs "")
    cmake_parse_arguments(CFG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Validate required arguments
    if(NOT DEFINED CFG_PROFILE_DIR OR NOT DEFINED CFG_SOC OR
       NOT DEFINED CFG_PROFILE OR NOT DEFINED CFG_PROVIDER OR
       NOT DEFINED CFG_FAMILY)
        message(FATAL_ERROR "generate_tinyusb_config: Missing required arguments")
    endif()

    # Build the list of interface include directories
    # These paths will be exposed to consuming targets
    set(CONFIG_INCLUDES
        "\${PATH_TINYUSB}/uKOS_Interface/OSAL"
        "\${PATH_TINYUSB}/TinyUSB-current/src"
        "\${PATH_TINYUSB}/TinyUSB-current/src/common"
        "\${PATH_TINYUSB}/TinyUSB-current/src/device"
        "\${PATH_TINYUSB}/TinyUSB-current/src/class/hid"
        "\${PATH_TINYUSB}/TinyUSB-current/src/class/cdc"
        "\${PATH_TINYUSB}/TinyUSB-current/src/class/msc"
        "\${CMAKE_CURRENT_LIST_DIR}"
    )

    # Add provider-specific includes
    if(CFG_PROVIDER STREQUAL "st")
        list(APPEND CONFIG_INCLUDES
            "\${PATH_TINYUSB}/uKOS_Interface/Includes/mcu/st"
            "\${PATH_TINYUSB}/TinyUSB-current/hw/mcu/st/cmsis_device_${CFG_FAMILY}/Include"
        )
    elseif(CFG_PROVIDER STREQUAL "nordic")
        list(APPEND CONFIG_INCLUDES
            "\${PATH_TINYUSB}/TinyUSB-current/hw/bsp/nrf"
            "\${PATH_TINYUSB}/TinyUSB-current/hw/bsp/nrf/nrfx_config"
            "\${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx"
            "\${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/mdk"
            "\${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/hal"
        )
    elseif(CFG_PROVIDER STREQUAL "raspberrypi")
        list(APPEND CONFIG_INCLUDES
            "\${PATH_TINYUSB}/uKOS_Interface/Includes/mcu/raspberrypi"
            "\${PATH_TINYUSB}/TinyUSB-current/src/portable/raspberrypi/rp2040"
        )
    endif()

    # Convert list to CMake list format for the config file (semicolon-separated)
    string(REPLACE ";" ";" CONFIG_INCLUDES_STR "${CONFIG_INCLUDES}")

    # Generate the TinyUSBConfig.cmake file
    set(CONFIG_FILE "${CFG_PROFILE_DIR}/TinyUSBConfig.cmake")
    file(WRITE "${CONFIG_FILE}" "\
# TinyUSBConfig.cmake
# ===================
#
# CMake package configuration file for TinyUSB library
# Generated automatically by TinyUSB.cmake
#
# This file defines imported targets for TinyUSB libraries:
#   - TinyUSB::FS - Full Speed USB library
#   - TinyUSB::HS - High Speed USB library
#
# Usage in your CMakeLists.txt:
#   find_package(TinyUSB REQUIRED
#       PATHS \${PATH_TINYUSB}/Library/Family/\${FAMILY}/\${SOC}/\${PROFILE}
#       NO_DEFAULT_PATH
#   )
#   target_link_libraries(your_target PRIVATE TinyUSB::FS)
#
# Configuration:
#   SOC:      ${CFG_SOC}
#   PROFILE:  ${CFG_PROFILE}
#   PROVIDER: ${CFG_PROVIDER}
#   FAMILY:   ${CFG_FAMILY}

# Ensure PATH_TINYUSB is defined
if(NOT DEFINED PATH_TINYUSB)
    get_filename_component(PATH_TINYUSB \"\${CMAKE_CURRENT_LIST_DIR}/../../../../../\" ABSOLUTE)
    message(STATUS \"TinyUSB: PATH_TINYUSB set to \${PATH_TINYUSB}\")
endif()

# Check that library files exist
if(NOT EXISTS \"\${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_FS.a\")
    message(FATAL_ERROR \"TinyUSB FS library not found: \${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_FS.a\")
endif()
if(NOT EXISTS \"\${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_HS.a\")
    message(FATAL_ERROR \"TinyUSB HS library not found: \${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_HS.a\")
endif()

# Build the list of interface include directories
set(TINYUSB_INTERFACE_INCLUDES
    \${PATH_TINYUSB}/uKOS_Interface/OSAL
    \${PATH_TINYUSB}/TinyUSB-current/src
    \${PATH_TINYUSB}/TinyUSB-current/src/common
    \${PATH_TINYUSB}/TinyUSB-current/src/device
    \${PATH_TINYUSB}/TinyUSB-current/src/class
    \${CMAKE_CURRENT_LIST_DIR}
)
")

    # Add provider-specific includes to the generated file
    if(CFG_PROVIDER STREQUAL "st")
        file(APPEND "${CONFIG_FILE}" "\
list(APPEND TINYUSB_INTERFACE_INCLUDES
    \${PATH_TINYUSB}/uKOS_Interface/Includes/mcu/st
)
")
        # Note: ST CMSIS device headers are provided by the uKOS-X Ports/EquatesModels
        # and are not included in TinyUSB upstream, so we don't add them here.
        # They are automatically included via system_compiler_flags interface target.
    elseif(CFG_PROVIDER STREQUAL "nordic")
        file(APPEND "${CONFIG_FILE}" "\
list(APPEND TINYUSB_INTERFACE_INCLUDES
    \${PATH_TINYUSB}/TinyUSB-current/hw/bsp/nrf
    \${PATH_TINYUSB}/TinyUSB-current/hw/bsp/nrf/nrfx_config
    \${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx
    \${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/mdk
    \${PATH_TINYUSB}/TinyUSB-current/hw/mcu/nordic/nrfx/hal
)
")
    elseif(CFG_PROVIDER STREQUAL "raspberrypi")
        file(APPEND "${CONFIG_FILE}" "\
list(APPEND TINYUSB_INTERFACE_INCLUDES
    \${PATH_TINYUSB}/uKOS_Interface/Includes/mcu/raspberrypi
    \${PATH_TINYUSB}/TinyUSB-current/src/portable/raspberrypi/rp2040
)
")
    endif()

    # Continue writing the config file
    file(APPEND "${CONFIG_FILE}" "\

# Define imported target for Full Speed library
if(NOT TARGET TinyUSB::FS)
    add_library(TinyUSB::FS STATIC IMPORTED)
    set_target_properties(TinyUSB::FS PROPERTIES
        IMPORTED_LOCATION \"\${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_FS.a\"
        INTERFACE_INCLUDE_DIRECTORIES \"\${TINYUSB_INTERFACE_INCLUDES}\"
        INTERFACE_COMPILE_DEFINITIONS \"SYSTEM_TINYUSB_FS_S\"
    )
endif()

# Define imported target for High Speed library
if(NOT TARGET TinyUSB::HS)
    add_library(TinyUSB::HS STATIC IMPORTED)
    set_target_properties(TinyUSB::HS PROPERTIES
        IMPORTED_LOCATION \"\${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_HS.a\"
        INTERFACE_INCLUDE_DIRECTORIES \"\${TINYUSB_INTERFACE_INCLUDES}\"
        INTERFACE_COMPILE_DEFINITIONS \"SYSTEM_TINYUSB_HS_S\"
    )
endif()

# Mark package as found
set(TinyUSB_FOUND TRUE)
set(TinyUSB_VERSION \"1.0\")

message(STATUS \"Found TinyUSB: ${CFG_SOC}/${CFG_PROFILE} (Full Speed and High Speed variants)\")
")

    message(STATUS "Generated TinyUSB config: ${CONFIG_FILE}")
endfunction()
