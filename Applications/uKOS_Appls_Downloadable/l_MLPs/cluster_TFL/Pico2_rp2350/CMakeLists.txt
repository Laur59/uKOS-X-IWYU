# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.31)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

# Core selection: the Pico2_rp2350 is dual-arch (ARM Cortex-M33 + RISC-V rv32imac).
# Default to the ARM core; select the RISC-V core with -DCORE=RV32IMAC.
set(CORE "CORTEX_M33" CACHE STRING "Target core selection")
set_property(CACHE CORE PROPERTY STRINGS CORTEX_M33 RV32IMAC)

if(CORE STREQUAL "CORTEX_M33")
    include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)
else()
    # The prebuilt RV32IMAC libTFLite.a is GCC-built. GNU ld resolves its
    # linker-relaxation relocations, but ld.lld (Clang) rejects them
    # (R_RISCV_PCREL_LO12 without a paired R_RISCV_PCREL_HI20), so force GCC here.
    # This lets -DCORE=RV32IMAC build without also needing -DUSE_LLVM=OFF.
    set(USE_LLVM OFF)
    message(STATUS "cluster_TFL RV32IMAC: forcing GCC toolchain (GCC-built libTFLite.a)")
    include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)
endif()

project(
    cluster_TFL
    VERSION 1.0
    LANGUAGES CXX C
)

# Microcontroller description (mandatory variables)
set(SOC rp2350)

# Target
set(BOARD Pico2_rp2350)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(-g3 # includes extra information for debugger
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    -Os # optimisation
)

# Architecture define (CORTEX vs RISCV) and the matching TFLite generic header tree.
# The RISC-V generic headers are ISA-independent and shared by rv32 and rv64.
if(CORE STREQUAL "CORTEX_M33")
    add_compile_definitions(
        $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_STATIC_MEMORY=1>
        $<$<COMPILE_LANGUAGE:CXX>:CORTEX>
    )
    set(TFLITE_GENERIC CORTEX_M_generic)
else()
    add_compile_definitions(
        $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_STATIC_MEMORY=1>
        $<$<COMPILE_LANGUAGE:CXX>:RISCV>
        # The RV32IMAC libTFLite.a is built size-optimised (release) to fit the Pico2's
        # small ~116 KB app region; that strips error strings (no MicroPrintf symbol).
        # The app must strip too, otherwise its op-resolver references MicroPrintf.
        $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_STRIP_ERROR_STRINGS>
        $<$<COMPILE_LANGUAGE:CXX>:NDEBUG>
    )
    set(TFLITE_GENERIC RISCV64_generic)
endif()

set(PATH_INCLUDES
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/${TFLITE_GENERIC}
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/${TFLITE_GENERIC}/third_party/flatbuffers/include
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/${TFLITE_GENERIC}/third_party/gemmlowp
)
find_library(MYLIB TFLite ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE})

include(common)
