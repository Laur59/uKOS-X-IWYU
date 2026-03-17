/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; core.
; =====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Collection of core routines
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>
#include    <stdatomic.h>

#include    "core_reg.h"
#include    "macros_soc.h"

/*
 * \brief core_getCSR
 *
 * - Get a CSR register value
 *
 * \param[in]   reg         The CSR register
 * \return      value       The register value
 *
 */
__attribute__ ((always_inline)) static  inline  uint32_t    core_getCSR(uint32_t reg) {
    uint32_t    value;

    __asm volatile (
    "csrr       %0,%1"
    : "=r" (value)
    : "i" (reg)
    );

    return (value);
}

/*
 * \brief core_putCSR
 *
 * - Put a value in a CSR register
 *
 * \param[in]   reg         The CSR register
 * \param[in]   value       The register value
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline)) static  inline  void    core_putCSR(uint32_t reg, uint32_t value) {

    if (__builtin_constant_p(value) && ((uint32_t)(value) < 32U)) {
        __asm volatile (
        "csrw       %0,%1"
        :
        : "i" (reg), "i" (value)
        );
    }
    else {
        __asm volatile (
        "csrw       %0,%1"
        :
        : "i" (reg), "r" (value)
        );
    }
}

/*
 * \brief core_setBitCSR
 *
 * - Set a bit in a CSR register
 *
 * \param[in]   reg         The CSR register
 * \param[in]   mask        The mask value
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline)) static  inline  void    core_setBitCSR(uint32_t reg, uint32_t mask) {

    if (__builtin_constant_p(mask) && ((uint32_t)(mask) < 32U)) {
        __asm volatile (
        "csrs       %0,%1"
        :
        : "i" (reg), "i" (mask)
        );
    }
    else {
        __asm volatile (
        "csrs       %0,%1"
        :
        : "i" (reg), "r" (mask)
        );
    }
}

/*
 * \brief core_clrBitCSR
 *
 * - Clear a bit in a CSR register
 *
 * \param[in]   reg         The CSR register
 * \param[in]   mask        The mask value
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline)) static  inline  void    core_clrBitCSR(uint32_t reg, uint32_t mask) {

    if (__builtin_constant_p(mask) && ((uint32_t)(mask) < 32U)) {
        __asm volatile (
        "csrci      %0,%1"
        :
        : "i" (reg), "i" (mask)
        );
    }
    else {
        __asm volatile (
        "csrc       %0,%1"
        :
        : "i" (reg), "r" (mask)
        );
    }
}
