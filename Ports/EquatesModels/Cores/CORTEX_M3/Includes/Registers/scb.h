/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; scb.
; ====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     SCB equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// SCB address definitions
// -----------------------

typedef struct {
    volatile    const   uint32_t    CPUID;
    volatile            uint32_t    ICSR;
    volatile            uint32_t    VTOR;
    volatile            uint32_t    AIRCR;
    volatile            uint32_t    SCR;
    volatile            uint32_t    CCR;
    volatile            uint8_t     SHP[12];
    volatile            uint32_t    SHCSR;
    volatile            uint32_t    CFSR;
    volatile            uint32_t    HFSR;
    volatile            uint32_t    DFSR;
    volatile            uint32_t    MMFAR;
    volatile            uint32_t    BFAR;
    volatile            uint32_t    AFSR;
    volatile    const   uint32_t    PFR[2];
    volatile    const   uint32_t    DFR;
    volatile    const   uint32_t    ADR;
    volatile    const   uint32_t    MMFR[4];
    volatile    const   uint32_t    ISAR[5];
} SCB_TypeDef;

#ifdef __cplusplus
#define SCB     reinterpret_cast<SCB_TypeDef *>(0xE000ED00U)

#else
#define SCB     ((SCB_TypeDef *)0xE000ED00U)
#endif

// AIRCR register

#define SCB_AIRCR_VECTKEY_MASK          0x05FA0000U
#define SCB_AIRCR_SYSRESETREQ           0x00000004U
