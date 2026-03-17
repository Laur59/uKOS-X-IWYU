/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_octospim.
; ===================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_octospim equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// OCTOSPIM address definitions
// ----------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    P1CR;
    volatile    uint32_t    P2CR;
} OCTOSPIM_TypeDef;

#ifdef __cplusplus
#define OCTOSPIM_NS reinterpret_cast<OCTOSPIM_TypeDef *>(0x420C4000U)
#define OCTOSPIM_S  reinterpret_cast<OCTOSPIM_TypeDef *>(0x520C4000U)

#else
#define OCTOSPIM_NS ((OCTOSPIM_TypeDef *)0x420C4000U)
#define OCTOSPIM_S  ((OCTOSPIM_TypeDef *)0x520C4000U)
#endif

// CR Configuration

#define OCTOSPIM_CR_MUXEN           (0x1U<<0)
#define OCTOSPIM_CR_REQ2ACK_TIME    (0xFFU<<16)
#define OCTOSPIM_CR_REQ2ACK_TIME_0  (0x1U<<16)

// P1CR Configuration

#define OCTOSPIM_P1CR_CLKEN         (0x1U<<0)
#define OCTOSPIM_P1CR_CLKSRC        (0x1U<<1)
#define OCTOSPIM_P1CR_DQSEN         (0x1U<<4)
#define OCTOSPIM_P1CR_DQSSRC        (0x1U<<5)
#define OCTOSPIM_P1CR_NCSEN         (0x1U<<8)
#define OCTOSPIM_P1CR_NCSSRC        (0x1U<<9)
#define OCTOSPIM_P1CR_IOLEN         (0x1U<<16)
#define OCTOSPIM_P1CR_IOLSRC        (0x3U<<17)
#define OCTOSPIM_P1CR_IOLSRC_0      (0x1U<<17)
#define OCTOSPIM_P1CR_IOHEN         (0x1U<<24)
#define OCTOSPIM_P1CR_IOHSRC        (0x3U<<25)
#define OCTOSPIM_P1CR_IOHSRC_0      (0x1U<<25)

// P2CR Configuration

#define OCTOSPIM_P2CR_CLKEN         (0x1U<<0)
#define OCTOSPIM_P2CR_CLKSRC        (0x1U<<1)
#define OCTOSPIM_P2CR_DQSEN         (0x1U<<4)
#define OCTOSPIM_P2CR_DQSSRC        (0x1U<<5)
#define OCTOSPIM_P2CR_NCSEN         (0x1U<<8)
#define OCTOSPIM_P2CR_NCSSRC        (0x1U<<9)
#define OCTOSPIM_P2CR_IOLEN         (0x1U<<16)
#define OCTOSPIM_P2CR_IOLSRC        (0x3U<<17)
#define OCTOSPIM_P2CR_IOLSRC_0      (0x1U<<17)
#define OCTOSPIM_P2CR_IOHEN         (0x1U<<24)
#define OCTOSPIM_P2CR_IOHSRC        (0x3U<<25)
#define OCTOSPIM_P2CR_IOHSRC_0      (0x1U<<25)
