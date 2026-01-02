# libm_src.
# =========

#------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Project: uKOS-X
#
# Purpose:
#   Sources to build libm math library.
#   Taken from SRC_LIBM defined in corresponding makefile.
#------------------------------------------------------------------------

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
