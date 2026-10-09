# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.31)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(
    tfl_vs_ukos
    VERSION 1.0
    LANGUAGES CXX C
)

# Microcontroller description (mandatory variables)
set(SOC STM32N657)
set(CORE CORTEX_M55)

# Target
set(BOARD Discovery_N657)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(-g3 # includes extra information for debugger
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    -Os # optimisation
)
add_compile_definitions(
    $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_STATIC_MEMORY=1>
    $<$<COMPILE_LANGUAGE:CXX>:CORTEX>
)

set(PATH_INCLUDES
    ${PATH_TP_LIBRARY}/Tflite-micro/Generic/CORTEX_M_generic
    ${PATH_TP_LIBRARY}/Tflite-micro/Generic/CORTEX_M_generic/third_party/flatbuffers/include
    ${PATH_TP_LIBRARY}/Tflite-micro/Generic/CORTEX_M_generic/third_party/gemmlowp
)
find_library(MYLIB TFLite ${PATH_TP_LIBRARY}/Tflite-micro/${CORE})

include(common)
