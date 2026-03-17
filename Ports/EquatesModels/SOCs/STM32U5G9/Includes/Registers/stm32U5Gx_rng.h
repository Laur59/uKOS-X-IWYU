/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_rng.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_rng equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// RNG address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    DR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    HTCR;
} RNG_TypeDef;

#ifdef __cplusplus
#define RNG_NS  reinterpret_cast<RNG_TypeDef *>(0x420C0800U)
#define RNG_S   reinterpret_cast<RNG_TypeDef *>(0x520C0800U)

#else
#define RNG_NS  ((RNG_TypeDef *)0x420C0800U)
#define RNG_S   ((RNG_TypeDef *)0x520C0800U)
#endif

// CR Configuration

#define RNG_CR_RNGEN            (0x1U<<2)
#define RNG_CR_IE               (0x1U<<3)
#define RNG_CR_CED              (0x1U<<5)
#define RNG_CR_ARDIS            (0x1U<<7)
#define RNG_CR_RNG_CONFIG3      (0xFU<<8)
#define RNG_CR_RNG_CONFIG3_0    (0x1U<<8)
#define RNG_CR_NISTC            (0x1U<<12)
#define RNG_CR_RNG_CONFIG2      (0x7U<<13)
#define RNG_CR_RNG_CONFIG2_0    (0x1U<<13)
#define RNG_CR_CLKDIV           (0xFU<<16)
#define RNG_CR_CLKDIV_0         (0x1U<<16)
#define RNG_CR_RNG_CONFIG1      (0x3FU<<20)
#define RNG_CR_RNG_CONFIG1_0    (0x1U<<20)
#define RNG_CR_CONDRST          (0x1U<<30)
#define RNG_CR_CONFIGLOCK       (0x1U<<31)

// SR Configuration

#define RNG_SR_DRDY             (0x1U<<0)
#define RNG_SR_CECS             (0x1U<<1)
#define RNG_SR_SECS             (0x1U<<2)
#define RNG_SR_CEIS             (0x1U<<5)
#define RNG_SR_SEIS             (0x1U<<6)

// DR Configuration

#define RNG_DR_RNDATA           (0xFFFFFFFFU<<0)
#define RNG_DR_RNDATA_0         (0x1U<<0)

// HTCR Configuration

#define RNG_HTCR_HTCFG          (0xFFFFFFFFU<<0)
#define RNG_HTCR_HTCFG_0        (0x1U<<0)
