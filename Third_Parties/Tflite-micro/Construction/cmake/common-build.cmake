# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Purpose:
#   Common CMake file to build the Tflite-micro library (libTFLite.a) for uKOS-X.
#
# Build description:
#   Compiles the standalone source tree that create_tflm_tree.py exports into
#   Library/Generic/<TFLITE_TREE> (build.sh), with the flags of the upstream
#   "microlite" make target, so no toolchain downloaded by upstream is used.
#   Requires, set by the per-core CMakeLists.txt:
#     TFLITE_TREE        CORTEX_M_generic or RISCV64_generic
#     CPU_SPEC           -mcpu/-mfloat-abi (Arm) or -march/-mabi (RISC-V)
#     TFLITE_BUILD_TYPE  debug (-g, TFLite error strings kept) or release
#     CMSIS_DEVICE       Arm only: CMSIS device (e.g. ARMCM7)
#     TFLITE_DEFS        per-core definitions (e.g. CPU_M7=1)
#
# Reproducibility:
#   This build definition is intended to be deterministic and reproducible.
#   Given identical source inputs, build configuration, toolchain versions,
#   and build environment, the produced static libraries are expected to be
#   bit-for-bit identical.

# Extract core name from project name with strict validation
if(PROJECT_NAME MATCHES "^TFLite_(.+)$")
    set(CORE_NAME ${CMAKE_MATCH_1})
    message("Building Tflite-micro for core: ${CORE_NAME}")
else()
    message(FATAL_ERROR "Project name '${PROJECT_NAME}' does not follow expected naming convention.\n"
                        "Expected format: TFLite_<CORE_NAME> (e.g., TFLite_CORTEX_M7)")
endif()

# Default install prefix (set here, after project(), so CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT
# is reliable). Allows 'cmake --install <build>' without an explicit --prefix.
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PATH_TFLITE}" CACHE PATH "Install prefix" FORCE)
endif()

# Deterministic archives and a git-derived SOURCE_DATE_EPOCH
include(${PATH_UKOS}/Ports/cmake/reproducible.cmake)
ukos_reproducible_build()

# The exported source tree (build.sh runs create_tflm_tree.py)
set(TREE "${PATH_TFLITE}/Library/Generic/${TFLITE_TREE}")
set(DOWNLOADS "${PATH_TFLITE}/Tflite-micro-current/tensorflow/lite/micro/tools/make/downloads")
if(NOT EXISTS "${TREE}/tensorflow/lite/micro")
    message(FATAL_ERROR "Tflite-micro source tree not found: ${TREE}\n"
                        "Run Third_Parties/Tflite-micro/build.sh first.")
endif()

# Every exported source, minus those upstream does not compile: kissfft is
# #included by signal/src/kiss_fft_wrappers/*.cc, and reference/comparisons.cc
# is a leftover of an older export that no longer exists upstream (build.sh now
# clears the tree before exporting it).
file(GLOB_RECURSE TFLITE_SOURCES CONFIGURE_DEPENDS "${TREE}/*.cc" "${TREE}/*.c")
list(REMOVE_ITEM TFLITE_SOURCES
    "${TREE}/tensorflow/lite/kernels/internal/reference/comparisons.cc"
    "${TREE}/third_party/kissfft/kiss_fft.c"
    "${TREE}/third_party/kissfft/tools/kiss_fftr.c"
)

# Upstream optimises the kernels for speed and the rest for size
set(TFLITE_KERNEL_OPT "-O2" CACHE STRING "Optimisation level of the TFLite kernels (upstream: -O2)")
foreach(SRC ${TFLITE_SOURCES})
    file(RELATIVE_PATH REL "${TREE}" "${SRC}")
    if(REL MATCHES "^(signal/|tensorflow/lite/micro/kernels/|third_party/cmsis_nn/)")
        set_source_files_properties("${SRC}" PROPERTIES COMPILE_OPTIONS "${TFLITE_KERNEL_OPT}")
    else()
        set_source_files_properties("${SRC}" PROPERTIES COMPILE_OPTIONS "-Os")
    endif()
endforeach()

set(TARGET_LIB TFLite_${CORE_NAME})
add_library(${TARGET_LIB} STATIC
    ${TFLITE_SOURCES}
    # uKOS-X addition: see the file header
    "${PATH_TFLITE}/Construction/System/cxa_pure_virtual.cc"
)
set_source_files_properties("${PATH_TFLITE}/Construction/System/cxa_pure_virtual.cc"
    PROPERTIES COMPILE_OPTIONS "-Os")
set_target_properties(${TARGET_LIB} PROPERTIES OUTPUT_NAME "TFLite")

# Include directories, in upstream order (its downloads/ is the tree's third_party/)
target_include_directories(${TARGET_LIB} PRIVATE
    "${TREE}"
    "${TREE}/third_party"
    "${TREE}/third_party/gemmlowp"
    "${TREE}/third_party/flatbuffers/include"
    "${TREE}/third_party/kissfft"
    "${TREE}/third_party/ruy"
)
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM")
    # CMSIS comes from upstream's downloads/, as in its build: the tree only
    # carries the CMSIS headers project generation needs, while micro_time.cc
    # includes the device header and, through it, all of CMSIS Core.
    target_include_directories(${TARGET_LIB} PRIVATE
        "${DOWNLOADS}/cmsis/Cortex_DFP/Device/${CMSIS_DEVICE}/Include"
        "${DOWNLOADS}/cmsis/CMSIS/Core/Include"
        "${DOWNLOADS}/cmsis"
        "${TREE}/third_party/cmsis_nn"
        "${TREE}/third_party/cmsis_nn/Include"
    )
else()
    target_include_directories(${TARGET_LIB} PRIVATE "${TREE}/third_party/eyalroz_printf/src")
endif()

# Definitions of the upstream microlite target
target_compile_definitions(${TARGET_LIB} PRIVATE
    TF_LITE_STATIC_MEMORY
    TF_LITE_DISABLE_X86_NEON
    KERNELS_OPTIMIZED_FOR_SPEED
    TF_LITE_MCU_DEBUG_LOG
    ${TFLITE_DEFS}
)
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM")
    target_compile_definitions(${TARGET_LIB} PRIVATE
        CMSIS_NN
        CMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="${CMSIS_DEVICE}.h"
        ${CMSIS_DEVICE}
        ARM_NN_ENABLE_F16=0
        ARM_NN_ENABLE_F32=0
    )
else()
    target_compile_definitions(${TARGET_LIB} PRIVATE
        TF_LITE_USE_GLOBAL_CMATH_FUNCTIONS
        $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_USE_GLOBAL_MIN>
        $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_USE_GLOBAL_MAX>
    )
endif()

# The Arm cores build upstream's "debug" flavour: -g and the TFLite error
# strings, logged through DebugLogCallback. Both RISC-V cores build "release"
# (-DNDEBUG -DTF_LITE_STRIP_ERROR_STRINGS):
# - rv32imac needs it for size: it targets the Pico2's small RAM-resident
#   downloadable-app region (~116 KB code), and the app strips to match.
# - riscv32_generic/debug_log.cc logs with std::fputs(..., stdout), unlike
#   cortex_m_generic/debug_log.cc. That FILE* use drags newlib's _impure_ptr
#   into debug_log.o, and a uKOS-X application built with C_LIBRARY=llvmlibc
#   then fails to link (undefined symbol: _impure_ptr). Stripping the error
#   strings compiles that body away; TFLite log messages are lost on RISC-V.
if(TFLITE_BUILD_TYPE STREQUAL "release")
    target_compile_definitions(${TARGET_LIB} PRIVATE NDEBUG TF_LITE_STRIP_ERROR_STRINGS)
else()
    target_compile_options(${TARGET_LIB} PRIVATE -g)
endif()

# Flags of the upstream microlite target. -fshort-enums is added: the
# consumers compile with it (Applications/cmake/application.cmake) and the
# TFLite C API passes enums (TfLiteType, TfLiteStatus, ...) across the
# boundary. arm-none-eabi-gcc packs enums implicitly; Clang and RISC-V GCC do not.
target_compile_options(${TARGET_LIB} PRIVATE
    ${CPU_SPEC}
    -ffunction-sections
    -fdata-sections
    -fno-unwind-tables
    -fno-asynchronous-unwind-tables
    -fmessage-length=0
    -funsigned-char
    -fomit-frame-pointer
    -fshort-enums
    $<$<COMPILE_LANGUAGE:C>:-std=c17>
    $<$<COMPILE_LANGUAGE:C>:-Wimplicit-function-declaration>
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
    $<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>
    $<$<COMPILE_LANGUAGE:CXX>:-Wsign-compare>
    $<$<COMPILE_LANGUAGE:CXX>:-Wdouble-promotion>
    $<$<COMPILE_LANGUAGE:CXX>:-Wunused-variable>
    $<$<COMPILE_LANGUAGE:CXX>:-Wunused-function>
    $<$<COMPILE_LANGUAGE:CXX>:-Wswitch>
    $<$<COMPILE_LANGUAGE:CXX>:-Wvla>
    $<$<COMPILE_LANGUAGE:CXX>:-Wall>
    $<$<COMPILE_LANGUAGE:CXX>:-Wextra>
    $<$<COMPILE_LANGUAGE:CXX>:-Wmissing-field-initializers>
    $<$<COMPILE_LANGUAGE:CXX>:-Wstrict-aliasing>
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-unused-parameter>
)
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM")
    # Upstream passes -mfpu=auto, which Clang rejects; Clang without -mfpu
    # enables the same FPU (and Helium on M55/M85) for every core used here.
    target_compile_options(${TARGET_LIB} PRIVATE
        -mthumb
        -mlittle-endian
        -Wno-type-limits
        -Wno-unused-private-field
        $<$<C_COMPILER_ID:GNU>:-mfpu=auto>
    )
else()
    # -mexplicit-relocs and -fpermissive are GCC-only
    target_compile_options(${TARGET_LIB} PRIVATE
        -mcmodel=medany
        -fno-builtin-printf
        -fno-delete-null-pointer-checks
        $<$<C_COMPILER_ID:GNU>:-mexplicit-relocs>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
        $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CXX_COMPILER_ID:GNU>>:-fpermissive>
    )
endif()

# Installation (deployed by 'cmake --install')
install(TARGETS ${TARGET_LIB} ARCHIVE DESTINATION "Library/${CORE_NAME}")
