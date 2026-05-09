# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# uKOS-X build system
# Builds MicroPython library for RV32IMAC

cmake_minimum_required(VERSION 3.26)

# Include common MicroPython RISC-V build setup
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common-setup-rv32.cmake)

project(MicroPython_RV32IMAC
    DESCRIPTION "MicroPython static library for RV32IMAC"
    LANGUAGES C ASM
)

# Settings for RV32IMAC cores

add_library(core_flags INTERFACE)

target_compile_definitions(core_flags INTERFACE
    RV32IMAC_S
)

target_compile_options(core_flags INTERFACE
    -march=rv32imac
    -mabi=ilp32
    $<$<C_COMPILER_ID:Clang>:--target=riscv32-unknown-elf>
    -mcmodel=medlow
)

# Override architecture-specific files before including common-build.cmake
set(MICROPY_NLR_FILE  ${MICROPY_DIR}/py/nlrrv32.c)
set(MICROPY_GC_HELPER ${MICROPY_DIR}/shared/runtime/gchelper_rv32i.s)

# Single-precision libm math library (software implementation, no HW FPU).

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
