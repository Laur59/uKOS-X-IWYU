/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_dac equates.
 */

#pragma once

#include    <stdint.h>

// DAC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SWTRIGR;
    volatile    uint32_t    DHR12R1;
    volatile    uint32_t    DHR12L1;
    volatile    uint32_t    DHR8R1;
    volatile    uint32_t    DHR12R2;
    volatile    uint32_t    DHR12L2;
    volatile    uint32_t    DHR8R2;
    volatile    uint32_t    DHR12RD;
    volatile    uint32_t    DHR12LD;
    volatile    uint32_t    DHR8RD;
    volatile    uint32_t    DOR1;
    volatile    uint32_t    DOR2;
    volatile    uint32_t    SR;
} DAC_TypeDef;

#ifdef __cplusplus
#define DAC reinterpret_cast<DAC_TypeDef *>(0x40007400U)

#else
#define DAC ((DAC_TypeDef *)0x40007400U)
#endif

// CR Configuration

#define DAC_CR_EN1              (0x1U<<0)
#define DAC_CR_BOFF1            (0x1U<<1)
#define DAC_CR_TEN1             (0x1U<<2)
#define DAC_CR_TSEL1            (0x7U<<3)
#define DAC_CR_TSEL1_0          (0x1U<<3)
#define DAC_CR_WAVE1            (0x3U<<6)
#define DAC_CR_WAVE1_0          (0x1U<<6)
#define DAC_CR_MAMP1            (0xFU<<8)
#define DAC_CR_MAMP1_0          (0x1U<<8)
#define DAC_CR_DMAEN1           (0x1U<<12)
#define DAC_CR_DMAUDRIE1        (0x1U<<13)
#define DAC_CR_EN2              (0x1U<<16)
#define DAC_CR_BOFF2            (0x1U<<17)
#define DAC_CR_TEN2             (0x1U<<18)
#define DAC_CR_TSEL2            (0x7U<<19)
#define DAC_CR_TSEL2_0          (0x1U<<19)
#define DAC_CR_WAVE2            (0x3U<<22)
#define DAC_CR_WAVE2_0          (0x1U<<22)
#define DAC_CR_MAMP2            (0xFU<<24)
#define DAC_CR_MAMP2_0          (0x1U<<24)
#define DAC_CR_DMAEN2           (0x1U<<28)
#define DAC_CR_DMAUDRIE2        (0x1U<<29)

// SWTRIGR Configuration

#define DAC_SWTRIGR_SWTRIG1     (0x1U<<0)
#define DAC_SWTRIGR_SWTRIG2     (0x1U<<1)

// DHR12R1 Configuration

#define DAC_DHR12R1_DACC1DHR    (0xFFFU<<0)
#define DAC_DHR12R1_DACC1DHR_0  (0x1U<<0)

// DHR12L1 Configuration

#define DAC_DHR12L1_DACC1DHR    (0xFFFU<<4)
#define DAC_DHR12L1_DACC1DHR_0  (0x1U<<4)

// DHR8R1 Configuration

#define DAC_DHR8R1_DACC1DHR     (0xFFU<<0)
#define DAC_DHR8R1_DACC1DHR_0   (0x1U<<0)

// DHR12R2 Configuration

#define DAC_DHR12R2_DACC2DHR    (0xFFFU<<0)
#define DAC_DHR12R2_DACC2DHR_0  (0x1U<<0)

// DHR12L2 Configuration

#define DAC_DHR12L2_DACC2DHR    (0xFFFU<<4)
#define DAC_DHR12L2_DACC2DHR_0  (0x1U<<4)

// DHR8R2 Configuration

#define DAC_DHR8R2_DACC2DHR     (0xFFU<<0)
#define DAC_DHR8R2_DACC2DHR_0   (0x1U<<0)

// DHR12RD Configuration

#define DAC_DHR12RD_DACC1DHR    (0xFFFU<<0)
#define DAC_DHR12RD_DACC1DHR_0  (0x1U<<0)
#define DAC_DHR12RD_DACC2DHR    (0xFFFU<<16)
#define DAC_DHR12RD_DACC2DHR_0  (0x1U<<16)

// DHR12LD Configuration

#define DAC_DHR12LD_DACC1DHR    (0xFFFU<<4)
#define DAC_DHR12LD_DACC1DHR_0  (0x1U<<4)
#define DAC_DHR12LD_DACC2DHR    (0xFFFU<<20)
#define DAC_DHR12LD_DACC2DHR_0  (0x1U<<20)

// DHR8RD Configuration

#define DAC_DHR8RD_DACC1DHR     (0xFFU<<0)
#define DAC_DHR8RD_DACC1DHR_0   (0x1U<<0)
#define DAC_DHR8RD_DACC2DHR     (0xFFU<<8)
#define DAC_DHR8RD_DACC2DHR_0   (0x1U<<8)

// DOR1 Configuration

#define DAC_DOR1_DACC1DOR       (0xFFFU<<0)
#define DAC_DOR1_DACC1DOR_0     (0x1U<<0)

// DOR2 Configuration

#define DAC_DOR2_DACC2DOR       (0xFFFU<<0)
#define DAC_DOR2_DACC2DOR_0     (0x1U<<0)

// SR Configuration

#define DAC_SR_DMAUDR1          (0x1U<<13)
#define DAC_SR_DMAUDR2          (0x1U<<29)
