# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

# CMakeLists.
# ===========

#------------------------------------------------------------------------
# Project:  uKOS-X
# Goal:     CMake file to set up the building for uKOS-X system.
#
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-riscv-toolchain.cmake)

project(
    class_TFL
    VERSION 1.0
    LANGUAGES CXX C
)

# Microcontroller description (mandatory variables)
set(SOC K210)
set(CORE RV64IMAFDC)

# Target
set(BOARD MAiXDUiNO_K210)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(-g3 # includes extra information for debugger
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    -Os # optimisation
)
add_compile_definitions(
    $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_STATIC_MEMORY=1>
    $<$<COMPILE_LANGUAGE:CXX>:RISCV>
)

set(PATH_INCLUDES
    ${PATH_UKOS}/Third_Parties/Tflite-micro/uKOS_Interface/RISCV64_generic
    ${PATH_UKOS}/Third_Parties/Tflite-micro/uKOS_Interface/RISCV64_generic/third_party/flatbuffers/include
    ${PATH_UKOS}/Third_Parties/Tflite-micro/uKOS_Interface/RISCV64_generic/third_party/gemmlowp
)
find_library(MYLIB TFLite ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE})

include(common)
