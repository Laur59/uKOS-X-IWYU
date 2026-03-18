/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_octospim equates.
 */

#pragma once

#include    <stdint.h>

// OCTOSPIM address definitions
// ----------------------------

typedef struct {
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    P1CR;
    volatile    uint32_t    P2CR;
} OCTOSPIM_TypeDef;

#ifdef __cplusplus
#define OCTOSPIM    reinterpret_cast<OCTOSPIM_TypeDef *>(0x50061C00U)

#else
#define OCTOSPIM    ((OCTOSPIM_TypeDef *)0x50061C00U)
#endif

// P1CR Configuration

#define OCTOSPIM_P1CR_IOHSRC    (0x3U<<25)
#define OCTOSPIM_P1CR_IOHSRC_0  (0x1U<<25)
#define OCTOSPIM_P1CR_IOHEN     (0x1U<<24)
#define OCTOSPIM_P1CR_IOLSRC    (0x3U<<17)
#define OCTOSPIM_P1CR_IOLSRC_0  (0x1U<<17)
#define OCTOSPIM_P1CR_IOLEN     (0x1U<<16)
#define OCTOSPIM_P1CR_NCSSRC    (0x1U<<9)
#define OCTOSPIM_P1CR_NCSEN     (0x1U<<8)
#define OCTOSPIM_P1CR_DQSSRC    (0x1U<<5)
#define OCTOSPIM_P1CR_DQSEN     (0x1U<<4)
#define OCTOSPIM_P1CR_CLKSRC    (0x1U<<1)
#define OCTOSPIM_P1CR_CLKEN     (0x1U<<0)

// P2CR Configuration

#define OCTOSPIM_P2CR_IOHSRC    (0x3U<<25)
#define OCTOSPIM_P2CR_IOHSRC_0  (0x1U<<25)
#define OCTOSPIM_P2CR_IOHEN     (0x1U<<24)
#define OCTOSPIM_P2CR_IOLSRC    (0x3U<<17)
#define OCTOSPIM_P2CR_IOLSRC_0  (0x1U<<17)
#define OCTOSPIM_P2CR_IOLEN     (0x1U<<16)
#define OCTOSPIM_P2CR_NCSSRC    (0x1U<<9)
#define OCTOSPIM_P2CR_NCSEN     (0x1U<<8)
#define OCTOSPIM_P2CR_DQSSRC    (0x1U<<5)
#define OCTOSPIM_P2CR_DQSEN     (0x1U<<4)
#define OCTOSPIM_P2CR_CLKSRC    (0x1U<<1)
#define OCTOSPIM_P2CR_CLKEN     (0x1U<<0)
