# libm_src.
# =========

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-02-28
# Modifs:
#
# Project:  uKOS-X
# Goal:     Sources to build libm math library.
#
#   Copyright 2025-2026, Laurent von Allmen
#   ---------------------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Licensed to the Apache Software Foundation (ASF) under one or more
#   contributor license agreements. See the NOTICE file distributed with
#   this work for additional information regarding copyright ownership.
#   The ASF licenses this file to you under the Apache License, Version 2.0
#   (the "License"); you may not use this file except in compliance with
#   the License. You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#------------------------------------------------------------------------

# Single-precision libm math library.

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
