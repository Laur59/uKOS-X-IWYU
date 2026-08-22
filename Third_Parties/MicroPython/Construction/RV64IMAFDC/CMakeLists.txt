# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds MicroPython library for RV64IMAFDC (e.g. K210)

cmake_minimum_required(VERSION 3.31)

# Include common MicroPython RISC-V build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup-rv32.cmake)

project(MicroPython_RV64IMAFDC
    DESCRIPTION "MicroPython static library for RV64IMAFDC"
    LANGUAGES C ASM
)

# Settings for RV64IMAFDC cores (e.g. Kendryte K210)

add_library(core_flags INTERFACE)

target_compile_definitions(core_flags INTERFACE
    RV64IMAFDC_S
)

target_compile_options(core_flags INTERFACE
    -march=rv64imafdc
    -mabi=lp64d
    $<$<C_COMPILER_ID:Clang>:--target=riscv64-unknown-elf>
    -mcmodel=medany
)

# Override architecture-specific files before including common-build.cmake
set(MICROPY_NLR_FILE  ${MICROPY_DIR}/py/nlrrv64.c)
set(MICROPY_GC_HELPER ${MICROPY_DIR}/shared/runtime/gchelper_rv64i.s)

# Single-precision libm math library (hardware FPU available via 'F' and 'D' extensions;
# MicroPython is configured for single-precision float — libm files are software implementations
# that the compiler may lower to hardware instructions).

set(MICROPY_SOURCE_LIB_LIBM
    ${MICROPY_DIR}/lib/libm/atanhf.c
    ${MICROPY_DIR}/lib/libm/acoshf.c
    ${MICROPY_DIR}/lib/libm/asinfacosf.c
    ${MICROPY_DIR}/lib/libm/asinhf.c
    ${MICROPY_DIR}/lib/libm/atan2f.c
    ${MICROPY_DIR}/lib/libm/atanf.c
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
