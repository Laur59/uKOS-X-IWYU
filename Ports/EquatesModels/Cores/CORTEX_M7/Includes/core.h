/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Collection of core routines
 */

#pragma once

#include    <stdint.h>
#include    <stdatomic.h>

#include    "core_reg.h"
#include    "macros_soc.h"

/*
 * \brief core_getBASEPRI
 *
 * - Get the BASEPRI register
 *
 * \return      BASEPRI     The BASEPRI register
 *
 */
__attribute__ ((always_inline)) static  inline  uint32_t    core_getBASEPRI(void) {
    uint32_t    valBASEPRI;

    __asm volatile (
    "mrs        %0,basepri"
    : "=r" (valBASEPRI)
    );

    return valBASEPRI;
}

/*
 * \brief core_setBASEPRI
 *
 * - Set the BASEPRI register
 *
 * \param[in]   BASEPRI     The BASEPRI register
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline)) static  inline  void    core_setBASEPRI(uint32_t valBASEPRI) {

    __asm volatile (
    "msr        basepri,%0"
    :
    : "r" (valBASEPRI)
    );
}

/*
 * \brief core_getPSP
 *
 * - Get the PSP stack
 *
 * \return      stackPSP    The thread stack PSP
 *
 */
__attribute__ ((always_inline)) static  inline  uintptr_t   core_getPSP(void) {
    uintptr_t   stackPSP;

    __asm volatile (
    "mrs        %0,psp"
    : "=r" (stackPSP)
    );

    return stackPSP;
}

/*
 * \brief core_setPSP
 *
 * - Set the PSP stack
 *
 * \param[in]   stackPSP    The thread stack PSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline)) static  inline  void    core_setPSP(uintptr_t stackPSP) {

    __asm volatile (
    "msr        psp,%0"
    :
    : "r" (stackPSP)
    );
}

/*
 * \brief core_getMSP
 *
 * - Get the MSP stack
 *
 * \return      stackMSP    The system stack MSP
 *
 */
__attribute__ ((always_inline)) static  inline  uintptr_t   core_getMSP(void) {
    uintptr_t   stackMSP;

    __asm volatile (
    "mrs        %0,msp"
    : "=r" (stackMSP)
    );

    return stackMSP;
}

/*
 * \brief core_setMSP
 *
 * - Set the MSP stack
 *
 * \param[in]   stackMSP    The system stack MSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline)) static  inline  void    core_setMSP(uintptr_t stackMSP) {

    __asm volatile (
    "msr        msp,%0"
    :
    : "r" (stackMSP)
    );
}

/*
 * \brief core_getCONTROL
 *
 * - Get the CONTROL register
 *
 * \return      CONTROL     The CONTROL register
 *
 */
__attribute__ ((always_inline)) static  inline  uint32_t    core_getCONTROL(void) {
    uint32_t    valCONTROL;

    __asm volatile (
    "mrs        %0,control"
    : "=r" (valCONTROL)
    );

    return valCONTROL;
}

/*
 * \brief core_setCONTROL
 *
 * - Set the core CONTROL register
 *
 * \param[in]   control The system control register
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline)) static  inline  void    core_setCONTROL(uint32_t control) {

    __asm volatile (
    "msr        control,%0"
    :
    : "r" (control)
    );
}

/*
 * \brief core_getLR
 *
 * - Get the LR register
 *
 * \return      LR      The LR register
 *
 */
__attribute__ ((always_inline)) static  inline  uintptr_t   core_getLR(void) {
    uintptr_t   valLR;

    __asm volatile (
    "mov        %0,LR"
    : "=r" (valLR)
    );

    return valLR;
}

/*
 * \brief core_getIPSR
 *
 * - Get the IPSR register
 *
 * \return      IPSR        The IPSR register
 *
 */
__attribute__ ((always_inline)) static  inline  uint32_t    core_getIPSR(void) {
    uint32_t    valIPSR;

    __asm volatile (
    "mrs        %0,ipsr"
    : "=r" (valIPSR)
    );

    return valIPSR;
}
