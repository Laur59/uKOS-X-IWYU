/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; RP2350_watchdog.
; ================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     RP2350_watchdog equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// WATCHDOG address definitions
// ----------------------------

typedef struct {
    volatile    uint32_t    CTRL;
    volatile    uint32_t    LOAD;
    volatile    uint32_t    REASON;
    volatile    uint32_t    SCRATCH0;
    volatile    uint32_t    SCRATCH1;
    volatile    uint32_t    SCRATCH2;
    volatile    uint32_t    SCRATCH3;
    volatile    uint32_t    SCRATCH4;
    volatile    uint32_t    SCRATCH5;
    volatile    uint32_t    SCRATCH6;
    volatile    uint32_t    SCRATCH7;
} WATCHDOG_TypeDef;

#ifdef __cplusplus
#define WATCHDOG_NS reinterpret_cast<WATCHDOG_TypeDef *>(0x400D8000U)
#define WATCHDOG_S  reinterpret_cast<WATCHDOG_TypeDef *>(0x400D8000U)
#else
#define WATCHDOG_NS ((WATCHDOG_TypeDef *)0x400D8000U)
#define WATCHDOG_S  ((WATCHDOG_TypeDef *)0x400D8000U)
#endif

// CTRL Configuration

#define WATCHDOG_CTRL_TIME              (0xFFFFFFU<<0)
#define WATCHDOG_CTRL_TIME_0            (0x1U<<0)
#define WATCHDOG_CTRL_PAUSE_JTAG        (0x1U<<24)
#define WATCHDOG_CTRL_PAUSE_DBG0        (0x1U<<25)
#define WATCHDOG_CTRL_PAUSE_DBG1        (0x1U<<26)
#define WATCHDOG_CTRL_ENABLE            (0x1U<<30)
#define WATCHDOG_CTRL_TRIGGER           (0x1U<<31)

// LOAD Configuration

#define WATCHDOG_LOAD_LOAD              (0xFFFFFFU<<0)
#define WATCHDOG_LOAD_LOAD_0            (0x1U<<0)

// REASON Configuration

#define WATCHDOG_REASON_TIMER           (0x1U<<0)
#define WATCHDOG_REASON_FORCE           (0x1U<<1)

// SCRATCH0 Configuration

#define WATCHDOG_SCRATCH0_SCRATCH0      (0xFFFFFFFFU<<0)
#define WATCHDOG_SCRATCH0_SCRATCH0_0    (0x1U<<0)

// SCRATCH1 Configuration

#define WATCHDOG_SCRATCH1_SCRATCH1      (0xFFFFFFFFU<<0)
#define WATCHDOG_SCRATCH1_SCRATCH1_0    (0x1U<<0)

// SCRATCH2 Configuration

#define WATCHDOG_SCRATCH2_SCRATCH2      (0xFFFFFFFFU<<0)
#define WATCHDOG_SCRATCH2_SCRATCH2_0    (0x1U<<0)

// SCRATCH3 Configuration

#define WATCHDOG_SCRATCH3_SCRATCH3      (0xFFFFFFFFU<<0)
#define WATCHDOG_SCRATCH3_SCRATCH3_0    (0x1U<<0)

// SCRATCH4 Configuration

#define WATCHDOG_SCRATCH4_SCRATCH4      (0xFFFFFFFFU<<0)
#define WATCHDOG_SCRATCH4_SCRATCH4_0    (0x1U<<0)

// SCRATCH5 Configuration

#define WATCHDOG_SCRATCH5_SCRATCH5      (0xFFFFFFFFU<<0)
#define WATCHDOG_SCRATCH5_SCRATCH5_0    (0x1U<<0)

// SCRATCH6 Configuration

#define WATCHDOG_SCRATCH6_SCRATCH6      (0xFFFFFFFFU<<0)
#define WATCHDOG_SCRATCH6_SCRATCH6_0    (0x1U<<0)

// SCRATCH7 Configuration

#define WATCHDOG_SCRATCH7_SCRATCH7      (0xFFFFFFFFU<<0)
#define WATCHDOG_SCRATCH7_SCRATCH7_0    (0x1U<<0)
