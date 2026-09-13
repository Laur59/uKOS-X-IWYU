# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# uKOS-X build system
# Builds all Tflite-micro libraries
#
# Build description:
#   Compiles libTFLite.a for every supported core from the standalone source
#   trees that build.sh exports with create_tflm_tree.py into Library/Generic/
#   (CORTEX_M_generic with the CMSIS-NN kernels, RISCV64_generic with the
#   reference kernels). It replaces the upstream make build, so none of the
#   compilers that upstream would download is used.
#
# Reproducibility:
#   This build definition is intended to be deterministic and reproducible.
#   Given identical source inputs, build configuration, toolchain versions,
#   and build environment, the produced static libraries are expected to be
#   bit-for-bit identical.
#
# Usage (build.sh runs all of it):
#   cd Third_Parties/Tflite-micro
#   cmake -S . -B build                 # Clang/LLVM (default)
#   cmake -S . -B build -DUSE_LLVM=OFF  # GNU gcc
#   cmake --build build
#   cmake --install build
#
#   The per-core build trees under build/ cache their compiler: run
#   ./very_clean.sh before switching toolchains.
#
# Build outputs:
#   - Library/<CORE>/libTFLite.a

cmake_minimum_required(VERSION 3.31)

project(Tflite_Package
    DESCRIPTION "Tflite-micro libraries for all supported cores"
    LANGUAGES NONE
)

# Default install prefix: keep Library/ adjacent to Construction/ inside the source tree.
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "Install prefix" FORCE)
endif()

# Toolchain used for every per-core archive (forwarded to the ExternalProjects)
option(USE_LLVM "Build the archives with Clang/LLVM (OFF: GNU gcc)" ON)

foreach(TREE CORTEX_M_generic RISCV64_generic)
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Library/Generic/${TREE}/tensorflow/lite/micro")
        message(FATAL_ERROR "Missing Library/Generic/${TREE}: run ./build.sh, which exports it.")
    endif()
endforeach()

include(ExternalProject)

set(SUPPORTED_CORES
    CORTEX_M3
    CORTEX_M4
    CORTEX_M7
    CORTEX_M33
    CORTEX_M55
    CORTEX_M85
    RV32IMAC
    RV64IMAFDC
)

set(ALL_CORE_PROJECTS "")
foreach(CORE ${SUPPORTED_CORES})
    ExternalProject_Add(TFLite_${CORE}
        PREFIX            "${CMAKE_CURRENT_BINARY_DIR}/ep-${CORE}"
        SOURCE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/Construction/${CORE}"
        # Keep the per-core build tree under the umbrella binary dir so that
        # "rm -fr build" fully cleans it.
        BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/build-${CORE}"
        # No CMAKE_BUILD_TYPE: common-build.cmake sets -O per source file, as upstream does
        CMAKE_ARGS        -G ${CMAKE_GENERATOR}
                          -DUSE_LLVM=${USE_LLVM}
        BUILD_COMMAND     ${CMAKE_COMMAND} --build <BINARY_DIR>
        BUILD_ALWAYS      OFF
        BUILD_BYPRODUCTS  "${CMAKE_CURRENT_BINARY_DIR}/build-${CORE}/libTFLite.a"
        INSTALL_COMMAND   ""
        DOWNLOAD_COMMAND  ""
        UPDATE_COMMAND    ""
        LOG_CONFIGURE     ON
        LOG_BUILD         ON
        LOG_OUTPUT_ON_FAILURE ON
        USES_TERMINAL_BUILD ON
    )
    list(APPEND ALL_CORE_PROJECTS TFLite_${CORE})

    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/build-${CORE}/libTFLite.a"
            DESTINATION "Library/${CORE}"
            OPTIONAL
    )
endforeach()

add_custom_target(build_all_tflite ALL
    DEPENDS ${ALL_CORE_PROJECTS}
    COMMENT "Building Tflite-micro for all cores"
)

message("")
message("══════════════════════════════════════════════════════════════")
if(USE_LLVM)
    message("Toolchain:       Clang/LLVM")
else()
    message("Toolchain:       GNU gcc")
endif()
message("Output libraries will be in:")
message("  Library/<CORE>/libTFLite.a")
message("══════════════════════════════════════════════════════════════")
