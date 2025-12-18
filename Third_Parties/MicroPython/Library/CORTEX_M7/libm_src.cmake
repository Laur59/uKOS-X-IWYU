# libm_src.
# =========

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-02-28
# Modifs:
#
# Project:  uKOS-X
# Goal:     Sources to build libm math library.
#
#   © 2025-2026, Laurent von Allmen
#   -------------------------------
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
