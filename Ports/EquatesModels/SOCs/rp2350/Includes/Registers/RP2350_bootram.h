/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; RP2350_bootram.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     RP2350_bootram equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// BOOTRAM address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[512];
    volatile    uint32_t    WRITE_ONCE0;
    volatile    uint32_t    WRITE_ONCE1;
    volatile    uint32_t    BOOTLOCK_STAT;
    volatile    uint32_t    BOOTLOCK0;
    volatile    uint32_t    BOOTLOCK1;
    volatile    uint32_t    BOOTLOCK2;
    volatile    uint32_t    BOOTLOCK3;
    volatile    uint32_t    BOOTLOCK4;
    volatile    uint32_t    BOOTLOCK5;
    volatile    uint32_t    BOOTLOCK6;
    volatile    uint32_t    BOOTLOCK7;
} BOOTRAM_TypeDef;

#ifdef __cplusplus
#define BOOTRAM_NS  reinterpret_cast<BOOTRAM_TypeDef *>(0x400E0000U)
#define BOOTRAM_S   reinterpret_cast<BOOTRAM_TypeDef *>(0x400E0000U)
#else
#define BOOTRAM_NS  ((BOOTRAM_TypeDef *)0x400E0000U)
#define BOOTRAM_S   ((BOOTRAM_TypeDef *)0x400E0000U)
#endif

// WRITE_ONCE0 Configuration

#define BOOTRAM_WRITE_ONCE0_WRITE_ONCE0         (0xFFFFFFFFU<<0)
#define BOOTRAM_WRITE_ONCE0_WRITE_ONCE0_0       (0x1U<<0)

// WRITE_ONCE1 Configuration

#define BOOTRAM_WRITE_ONCE1_WRITE_ONCE1         (0xFFFFFFFFU<<0)
#define BOOTRAM_WRITE_ONCE1_WRITE_ONCE1_0       (0x1U<<0)

// BOOTLOCK_STAT Configuration

#define BOOTRAM_BOOTLOCK_STAT_BOOTLOCK_STAT     (0xFFU<<0)
#define BOOTRAM_BOOTLOCK_STAT_BOOTLOCK_STAT_0   (0x1U<<0)

// BOOTLOCK0 Configuration

#define BOOTRAM_BOOTLOCK0_BOOTLOCK0             (0xFFFFFFFFU<<0)
#define BOOTRAM_BOOTLOCK0_BOOTLOCK0_0           (0x1U<<0)

// BOOTLOCK1 Configuration

#define BOOTRAM_BOOTLOCK1_BOOTLOCK1             (0xFFFFFFFFU<<0)
#define BOOTRAM_BOOTLOCK1_BOOTLOCK1_0           (0x1U<<0)

// BOOTLOCK2 Configuration

#define BOOTRAM_BOOTLOCK2_BOOTLOCK2             (0xFFFFFFFFU<<0)
#define BOOTRAM_BOOTLOCK2_BOOTLOCK2_0           (0x1U<<0)

// BOOTLOCK3 Configuration

#define BOOTRAM_BOOTLOCK3_BOOTLOCK3             (0xFFFFFFFFU<<0)
#define BOOTRAM_BOOTLOCK3_BOOTLOCK3_0           (0x1U<<0)

// BOOTLOCK4 Configuration

#define BOOTRAM_BOOTLOCK4_BOOTLOCK4             (0xFFFFFFFFU<<0)
#define BOOTRAM_BOOTLOCK4_BOOTLOCK4_0           (0x1U<<0)

// BOOTLOCK5 Configuration

#define BOOTRAM_BOOTLOCK5_BOOTLOCK5             (0xFFFFFFFFU<<0)
#define BOOTRAM_BOOTLOCK5_BOOTLOCK5_0           (0x1U<<0)

// BOOTLOCK6 Configuration

#define BOOTRAM_BOOTLOCK6_BOOTLOCK6             (0xFFFFFFFFU<<0)
#define BOOTRAM_BOOTLOCK6_BOOTLOCK6_0           (0x1U<<0)

// BOOTLOCK7 Configuration

#define BOOTRAM_BOOTLOCK7_BOOTLOCK7             (0xFFFFFFFFU<<0)
#define BOOTRAM_BOOTLOCK7_BOOTLOCK7_0           (0x1U<<0)
