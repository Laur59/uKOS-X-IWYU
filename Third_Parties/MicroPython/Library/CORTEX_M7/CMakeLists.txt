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

project(MicroPython_CORTEX_M7
    DESCRIPTION "MicroPython static library for Cortex_M7"
    LANGUAGES C
)

# Settings for cortex M7 cores

add_library(core_flags INTERFACE)

target_compile_definitions(core_flags INTERFACE
    CORTEX_M7_S
)

target_compile_options(core_flags INTERFACE
    -mthumb
    -mtune=cortex-m7
    -mcpu=cortex-m7
    $<$<C_COMPILER_ID:Clang>:--target=thumbv7em-unknown-none-eabihf>
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
)

# Double-precision libm math library.

set(MICROPY_SOURCE_LIB_LIBM
    ${MICROPY_DIR}/lib/libm_dbl/__cos.c
    ${MICROPY_DIR}/lib/libm_dbl/__expo2.c
    ${MICROPY_DIR}/lib/libm_dbl/__fpclassify.c
    ${MICROPY_DIR}/lib/libm_dbl/__rem_pio2_large.c
    ${MICROPY_DIR}/lib/libm_dbl/__rem_pio2.c
    ${MICROPY_DIR}/lib/libm_dbl/__signbit.c
    ${MICROPY_DIR}/lib/libm_dbl/__sin.c
    ${MICROPY_DIR}/lib/libm_dbl/__tan.c
    ${MICROPY_DIR}/lib/libm_dbl/acos.c
    ${MICROPY_DIR}/lib/libm_dbl/acosh.c
    ${MICROPY_DIR}/lib/libm_dbl/asin.c
    ${MICROPY_DIR}/lib/libm_dbl/asinh.c
    ${MICROPY_DIR}/lib/libm_dbl/atan.c
    ${MICROPY_DIR}/lib/libm_dbl/atan2.c
    ${MICROPY_DIR}/lib/libm_dbl/atanh.c
    ${MICROPY_DIR}/lib/libm_dbl/ceil.c
    ${MICROPY_DIR}/lib/libm_dbl/copysign.c
    ${MICROPY_DIR}/lib/libm_dbl/cos.c
    ${MICROPY_DIR}/lib/libm_dbl/cosh.c
    ${MICROPY_DIR}/lib/libm_dbl/erf.c
    ${MICROPY_DIR}/lib/libm_dbl/exp.c
    ${MICROPY_DIR}/lib/libm_dbl/expm1.c
    ${MICROPY_DIR}/lib/libm_dbl/floor.c
    ${MICROPY_DIR}/lib/libm_dbl/fmod.c
    ${MICROPY_DIR}/lib/libm_dbl/frexp.c
    ${MICROPY_DIR}/lib/libm_dbl/ldexp.c
    ${MICROPY_DIR}/lib/libm_dbl/lgamma.c
    ${MICROPY_DIR}/lib/libm_dbl/log.c
    ${MICROPY_DIR}/lib/libm_dbl/log1p.c
    ${MICROPY_DIR}/lib/libm_dbl/log10.c
    ${MICROPY_DIR}/lib/libm_dbl/modf.c
    ${MICROPY_DIR}/lib/libm_dbl/nearbyint.c
    ${MICROPY_DIR}/lib/libm_dbl/pow.c
    ${MICROPY_DIR}/lib/libm_dbl/rint.c
    ${MICROPY_DIR}/lib/libm_dbl/round.c
    ${MICROPY_DIR}/lib/libm_dbl/scalbn.c
    ${MICROPY_DIR}/lib/libm_dbl/sin.c
    ${MICROPY_DIR}/lib/libm_dbl/sinh.c
    ${MICROPY_DIR}/lib/libm_dbl/sqrt.c
    ${MICROPY_DIR}/lib/libm_dbl/tan.c
    ${MICROPY_DIR}/lib/libm_dbl/tanh.c
    ${MICROPY_DIR}/lib/libm_dbl/tgamma.c
    ${MICROPY_DIR}/lib/libm_dbl/trunc.c
)

# Include the shared template with all build logic
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-build.cmake)
