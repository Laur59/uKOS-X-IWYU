/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     SCB equates.
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
    volatile    const   uint32_t    ID_PFR[2];
    volatile    const   uint32_t    ID_DFR;
    volatile    const   uint32_t    ID_AFR;
    volatile    const   uint32_t    ID_MFR[4];
    volatile    const   uint32_t    ID_ISAR[5];
    volatile            uint32_t    RESERVED0[1];
    volatile    const   uint32_t    CLIDR;
    volatile    const   uint32_t    CTR;
    volatile    const   uint32_t    CCSIDR;
    volatile            uint32_t    CSSELR;
    volatile            uint32_t    CPACR;
    volatile            uint32_t    RESERVED3[93];
    volatile            uint32_t    STIR;
    volatile            uint32_t    RESERVED4[15];
    volatile    const   uint32_t    MVFR0;
    volatile    const   uint32_t    MVFR1;
    volatile    const   uint32_t    MVFR2;
    volatile            uint32_t    RESERVED5[1];
    volatile            uint32_t    ICIALLU;
    volatile            uint32_t    RESERVED6[1];
    volatile            uint32_t    ICIMVAU;
    volatile            uint32_t    DCIMVAC;
    volatile            uint32_t    DCISW;
    volatile            uint32_t    DCCMVAU;
    volatile            uint32_t    DCCMVAC;
    volatile            uint32_t    DCCSW;
    volatile            uint32_t    DCCIMVAC;
    volatile            uint32_t    DCCISW;
    volatile            uint32_t    RESERVED7[6];
    volatile            uint32_t    ITCMCR;
    volatile            uint32_t    DTCMCR;
    volatile            uint32_t    AHBPCR;
    volatile            uint32_t    CACR;
    volatile            uint32_t    AHBSCR;
    volatile            uint32_t    RESERVED8[1];
    volatile            uint32_t    ABFSR;
} SCB_TypeDef;

#ifdef __cplusplus
#define SCB     reinterpret_cast<SCB_TypeDef *>(0xE000ED00U)

#else
#define SCB     ((SCB_TypeDef *)0xE000ED00U)
#endif

// AIRCR register

#define SCB_AIRCR_VECTKEY_MASK          0x05FA0000U
#define SCB_AIRCR_SYSRESETREQ           0x00000004U

// CPACR register

#define SCB_CPACR_CP10                  (0x3U<<20)
#define SCB_CPACR_CP11                  (0x3U<<22)
