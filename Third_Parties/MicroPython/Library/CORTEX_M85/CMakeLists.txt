# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# CMakeLists.
# ===========
#
# Project: uKOS-X
#
# Purpose:
#   CMake file to build MicroPython library for uKOS-X.
#
# Build description:
#   Alternative way to build MicroPython static library for a given core.
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

# Include common MicroPython build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup.cmake)

project(MicroPython_CORTEX_M85
    DESCRIPTION "MicroPython static library for Cortex_M85"
    LANGUAGES C
)

# Settings for cortex M55 cores

add_library(core_flags INTERFACE)

target_compile_definitions(core_flags INTERFACE
    CORTEX_M85_S
)

target_compile_options(core_flags INTERFACE
    -mthumb
    -mtune=cortex-m85
    -mcpu=cortex-m85
    $<$<C_COMPILER_ID:Clang>:--target=thumbv8.1m.main-unknown-none-eabihf>
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
    -Wdouble-promotion
    $<$<C_COMPILER_ID:GNU>:-fsingle-precision-constant>
    $<$<C_COMPILER_ID:Clang>:-cl-single-precision-constant>
)

# Single-precision libm math library.

set(MICROPY_SOURCE_LIB_LIBM
    ${MICROPY_DIR}/lib/libm/acoshf.c
    ${MICROPY_DIR}/lib/libm/asinfacosf.c
    ${MICROPY_DIR}/lib/libm/asinhf.c
    ${MICROPY_DIR}/lib/libm/atan2f.c
    ${MICROPY_DIR}/lib/libm/atanf.c
    ${MICROPY_DIR}/lib/libm/atanhf.c
    ${MICROPY_DIR}/lib/libm/ef_rem_pio2.c
    ${MICROPY_DIR}/lib/libm/ef_sqrt.c
    ${MICROPY_DIR}/lib/libm/erf_lgamma.c
    ${MICROPY_DIR}/lib/libm/fmodf.c
    ${MICROPY_DIR}/lib/libm/kf_cos.c
    ${MICROPY_DIR}/lib/libm/kf_rem_pio2.c
    ${MICROPY_DIR}/lib/libm/kf_sin.c
    ${MICROPY_DIR}/lib/libm/kf_tan.c
    ${MICROPY_DIR}/lib/libm/log1pf.c
    ${MICROPY_DIR}/lib/libm/math.c
    ${MICROPY_DIR}/lib/libm/nearbyintf.c
    ${MICROPY_DIR}/lib/libm/roundf.c
    ${MICROPY_DIR}/lib/libm/sf_cos.c
    ${MICROPY_DIR}/lib/libm/sf_erf.c
    ${MICROPY_DIR}/lib/libm/sf_frexp.c
    ${MICROPY_DIR}/lib/libm/sf_ldexp.c
    ${MICROPY_DIR}/lib/libm/sf_modf.c
    ${MICROPY_DIR}/lib/libm/sf_sin.c
    ${MICROPY_DIR}/lib/libm/sf_tan.c
    ${MICROPY_DIR}/lib/libm/wf_lgamma.c
    ${MICROPY_DIR}/lib/libm/wf_tgamma.c
)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-build.cmake)
