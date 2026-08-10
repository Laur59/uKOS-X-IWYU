/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     MEMSYS equates.
 */

#pragma once

// MEMSYS address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    MSCR;
    volatile    uint32_t    PFCR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    ITCMCR;
    volatile    uint32_t    DTCMCR;
    volatile    uint32_t    PAHBCR;
    volatile    uint32_t    RESERVED1[313];
    volatile    uint32_t    ITGU_CTRL;
    volatile    uint32_t    ITGU_CFG;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    ITGU_LUT[16];
    volatile    uint32_t    RESERVED3[44];
    volatile    uint32_t    DTGU_CTRL;
    volatile    uint32_t    DTGU_CFG;
    volatile    uint32_t    RESERVED4[2];
    volatile    uint32_t    DTGU_LUT[16];
} MemSysCtrl_TypeDef;

#if (defined(__cplusplus))
#define MEMSYSCTL_S     reinterpret_cast<MemSysCtrl_TypeDef *>(0xE001E000U)
#define MEMSYSCTL_NS    reinterpret_cast<MemSysCtrl_TypeDef *>(0xE001E000U)

#else
#define MEMSYSCTL_S     ((MemSysCtrl_TypeDef *)0xE001E000U)
#define MEMSYSCTL_NS    ((MemSysCtrl_TypeDef *)0xE001E000U)
#endif

// MSCR register

#define MEMSYSCTL_MSCR_CPWRDN               (0x1U<<17U)
#define MEMSYSCTL_MSCR_DCCLEAN              (0x1U<<16U)
#define MEMSYSCTL_MSCR_ICACTIVE             (0x1U<<13U)
#define MEMSYSCTL_MSCR_DCACTIVE             (0x1U<<12U)
#define MEMSYSCTL_MSCR_TECCCHKDIS           (0x1U<<4U)
#define MEMSYSCTL_MSCR_EVECCFAULT           (0x1U<<3U)
#define MEMSYSCTL_MSCR_FORCEWT              (0x1U<<2U)
#define MEMSYSCTL_MSCR_ECCEN                (0x1U<<1U)
