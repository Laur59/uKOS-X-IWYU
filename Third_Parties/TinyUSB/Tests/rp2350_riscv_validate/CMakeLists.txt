# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Standalone Pico SDK app that links against our prebuilt validation
# archive (libTinyUSB_FS.a built with BUILD_VALIDATE_PICO=ON, OPT_OS_PICO).
#
# Goal: confirm that the prebuilt archive itself is functional outside
# uKOS-X by enumerating as a USB CDC device on real hardware.
#
# Build (from this directory):
#   export PICO_SDK_PATH="/Users/.../Pico2/Using RISC-V/pico-sdk"
#   export PATH=/opt/embedded/cross/gcc-current/riscv/bin:$PATH
#   cmake -S . -B build -DPICO_PLATFORM=rp2350-riscv \
#         -DPICO_GCC_TRIPLE=riscv64-unknown-elf \
#         -DPICO_TOOLCHAIN_PATH=/opt/embedded/cross/gcc-current/riscv
#   cmake --build build -j

cmake_minimum_required(VERSION 3.13)

# Pull in the Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(rp2350_riscv_validate C CXX ASM)

pico_sdk_init()

# Path to our TinyUSB workspace (parent of Tests/)
set(PATH_TINYUSB "${CMAKE_CURRENT_LIST_DIR}/../..")

# Path to the validation archive
set(VALIDATE_LIB_DIR
    "${PATH_TINYUSB}/Library/Family/pico2riscv/rp2350/cdc_cdc/validate")

if(NOT EXISTS "${VALIDATE_LIB_DIR}/libTinyUSB_FS.a")
    message(FATAL_ERROR
        "Validation archive not found: ${VALIDATE_LIB_DIR}/libTinyUSB_FS.a\n"
        "Build it first with:\n"
        "  cd ${PATH_TINYUSB}/Construction/Family/pico2riscv/rp2350\n"
        "  cmake -B build_cmake -G Ninja -DBUILD_VALIDATE_PICO=ON\n"
        "  cmake --build build_cmake -j\n"
        "  cmake --install build_cmake --prefix ${PATH_TINYUSB}")
endif()

# Imported target for the validation archive
add_library(uKOS_validation_TinyUSB STATIC IMPORTED)
set_target_properties(uKOS_validation_TinyUSB PROPERTIES
    IMPORTED_LOCATION "${VALIDATE_LIB_DIR}/libTinyUSB_FS.a"
)

add_executable(rp2350_riscv_validate
    main.c
)

# Tell the lib it's a Full-Speed build (matches how the lib was compiled)
target_compile_definitions(rp2350_riscv_validate PRIVATE
    SYSTEM_TINYUSB_FS_S
)

# Headers: our upstream TinyUSB sources (matching the build of the lib).
# Plus our profile dir for tusb_config.h.
target_include_directories(rp2350_riscv_validate PRIVATE
    ${VALIDATE_LIB_DIR}
    ${PATH_TINYUSB}/TinyUSB-current/src
    ${PATH_TINYUSB}/TinyUSB-current/src/common
    ${PATH_TINYUSB}/TinyUSB-current/src/device
    ${PATH_TINYUSB}/TinyUSB-current/src/class
)

# Tell tusb_config.h to select OPT_OS_PICO (must match the lib's compile)
target_compile_definitions(rp2350_riscv_validate PRIVATE
    TINYUSB_VALIDATE_PICO_S
)

target_link_libraries(rp2350_riscv_validate PRIVATE
    uKOS_validation_TinyUSB
    pico_stdlib
    pico_unique_id
    pico_sync
    hardware_irq
    hardware_resets
    hardware_gpio
    tinyusb_board
)

# Stdio over UART0 so we can see startup logs over the FTDI without
# needing USB CDC up first. uKOS-X on this board wires UART0 to GPIO16/17
# at 460800 baud — match that so the existing /dev/cu.usbserial-AB99DMZN
# wiring works.
target_compile_definitions(rp2350_riscv_validate PRIVATE
    PICO_DEFAULT_UART=0
    PICO_DEFAULT_UART_TX_PIN=16
    PICO_DEFAULT_UART_RX_PIN=17
    PICO_DEFAULT_UART_BAUD_RATE=460800
)
pico_enable_stdio_usb(rp2350_riscv_validate 0)
pico_enable_stdio_uart(rp2350_riscv_validate 1)

pico_add_extra_outputs(rp2350_riscv_validate)
