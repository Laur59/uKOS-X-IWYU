# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/cmake/select-arm-toolchain.cmake)

project(
    cluster_TFL
    VERSION 1.0
    LANGUAGES CXX C
)

# Microcontroller description (mandatory variables)
set(SOC STM32H747)
set(CORE CORTEX_M7)

# Target
set(BOARD Asmodee_H747)
set(VARIANT Variant_Test_CM7)
set(BASE Base_CM7)

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
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/flatbuffers/include
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/gemmlowp
)
find_library(MYLIB TFLite ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE})

include(common)
