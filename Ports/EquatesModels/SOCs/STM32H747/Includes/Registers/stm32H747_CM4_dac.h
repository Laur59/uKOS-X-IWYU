/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_dac equates.
 */

#pragma once

#include    <stdint.h>

// DAC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SWTRGR;
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
    volatile    uint32_t    CCR;
    volatile    uint32_t    MCR;
    volatile    uint32_t    SHSR1;
    volatile    uint32_t    SHSR2;
    volatile    uint32_t    SHHR;
    volatile    uint32_t    SHRR;
} DAC_TypeDef;

#ifdef __cplusplus
#define DAC reinterpret_cast<DAC_TypeDef *>(0x40007400U)

#else
#define DAC ((DAC_TypeDef *)0x40007400U)
#endif

// CR Configuration

#define DAC_CR_CEN2             (0x1U<<30U)
#define DAC_CR_DMAUDRIE2        (0x1U<<29U)
#define DAC_CR_DMAEN2           (0x1U<<28U)
#define DAC_CR_MAMP2            (0xFU<<24U)
#define DAC_CR_MAMP2_0          (0x1U<<24U)
#define DAC_CR_WAVE2            (0x3U<<22U)
#define DAC_CR_WAVE2_0          (0x1U<<22U)
#define DAC_CR_TSEL2            (0x7U<<18U)
#define DAC_CR_TSEL2_0          (0x1U<<18U)
#define DAC_CR_TEN2             (0x1U<<17U)
#define DAC_CR_EN2              (0x1U<<16U)
#define DAC_CR_CEN1             (0x1U<<14U)
#define DAC_CR_DMAUDRIE1        (0x1U<<13U)
#define DAC_CR_DMAEN1           (0x1U<<12U)
#define DAC_CR_MAMP1            (0xFU<<8U)
#define DAC_CR_MAMP1_0          (0x1U<<8U)
#define DAC_CR_WAVE1            (0x3U<<6U)
#define DAC_CR_WAVE1_0          (0x1U<<6U)
#define DAC_CR_TSEL1            (0x7U<<2U)
#define DAC_CR_TSEL1_0          (0x1U<<2U)
#define DAC_CR_TEN1             (0x1U<<1U)
#define DAC_CR_EN1              (0x1U<<0U)

// SWTRGR Configuration

#define DAC_SWTRGR_SWTRIG2      (0x1U<<1U)
#define DAC_SWTRGR_SWTRIG1      (0x1U<<0U)

// DHR12R1 Configuration

#define DAC_DHR12R1_DACC1DHR    (0xFFFU<<0U)
#define DAC_DHR12R1_DACC1DHR_0  (0x1U<<0U)

// DHR12L1 Configuration

#define DAC_DHR12L1_DACC1DHR    (0xFFFU<<4U)
#define DAC_DHR12L1_DACC1DHR_0  (0x1U<<4U)

// DHR8R1 Configuration

#define DAC_DHR8R1_DACC1DHR     (0xFFU<<0U)
#define DAC_DHR8R1_DACC1DHR_0   (0x1U<<0U)

// DHR12R2 Configuration

#define DAC_DHR12R2_DACC2DHR    (0xFFFU<<0U)
#define DAC_DHR12R2_DACC2DHR_0  (0x1U<<0U)

// DHR12L2 Configuration

#define DAC_DHR12L2_DACC2DHR    (0xFFFU<<4U)
#define DAC_DHR12L2_DACC2DHR_0  (0x1U<<4U)

// DHR8R2 Configuration

#define DAC_DHR8R2_DACC2DHR     (0xFFU<<0U)
#define DAC_DHR8R2_DACC2DHR_0   (0x1U<<0U)

// DHR12RD Configuration

#define DAC_DHR12RD_DACC2DHR    (0xFFFU<<16U)
#define DAC_DHR12RD_DACC2DHR_0  (0x1U<<16U)
#define DAC_DHR12RD_DACC1DHR    (0xFFFU<<0U)
#define DAC_DHR12RD_DACC1DHR_0  (0x1U<<0U)

// DHR12LD Configuration

#define DAC_DHR12LD_DACC2DHR    (0xFFFU<<20U)
#define DAC_DHR12LD_DACC2DHR_0  (0x1U<<20U)
#define DAC_DHR12LD_DACC1DHR    (0xFFFU<<4U)
#define DAC_DHR12LD_DACC1DHR_0  (0x1U<<4U)

// DHR8RD Configuration

#define DAC_DHR8RD_DACC2DHR     (0xFFU<<8U)
#define DAC_DHR8RD_DACC2DHR_0   (0x1U<<8U)
#define DAC_DHR8RD_DACC1DHR     (0xFFU<<0U)
#define DAC_DHR8RD_DACC1DHR_0   (0x1U<<0U)

// DOR1 Configuration

#define DAC_DOR1_DACC1DOR       (0xFFFU<<0U)
#define DAC_DOR1_DACC1DOR_0     (0x1U<<0U)

// DOR2 Configuration

#define DAC_DOR2_DACC2DOR       (0xFFFU<<0U)
#define DAC_DOR2_DACC2DOR_0     (0x1U<<0U)

// SR Configuration

#define DAC_SR_BWST2            (0x1U<<31U)
#define DAC_SR_CAL_FLAG2        (0x1U<<30U)
#define DAC_SR_DMAUDR2          (0x1U<<29U)
#define DAC_SR_BWST1            (0x1U<<15U)
#define DAC_SR_CAL_FLAG1        (0x1U<<14U)
#define DAC_SR_DMAUDR1          (0x1U<<13U)

// CCR Configuration

#define DAC_CCR_OTRIM2          (0x1FU<<16U)
#define DAC_CCR_OTRIM2_0        (0x1U<<16U)
#define DAC_CCR_OTRIM1          (0x1FU<<0U)
#define DAC_CCR_OTRIM1_0        (0x1U<<0U)

// MCR Configuration

#define DAC_MCR_MODE2           (0x7U<<16U)
#define DAC_MCR_MODE2_0         (0x1U<<16U)
#define DAC_MCR_MODE1           (0x7U<<0U)
#define DAC_MCR_MODE1_0         (0x1U<<0U)

// SHSR1 Configuration

#define DAC_SHSR1_TSAMPLE1      (0x3FFU<<0U)
#define DAC_SHSR1_TSAMPLE1_0    (0x1U<<0U)

// SHSR2 Configuration

#define DAC_SHSR2_TSAMPLE2      (0x3FFU<<0U)
#define DAC_SHSR2_TSAMPLE2_0    (0x1U<<0U)

// SHHR Configuration

#define DAC_SHHR_THOLD2         (0x3FFU<<16U)
#define DAC_SHHR_THOLD2_0       (0x1U<<16U)
#define DAC_SHHR_THOLD1         (0x3FFU<<0U)
#define DAC_SHHR_THOLD1_0       (0x1U<<0U)

// SHRR Configuration

#define DAC_SHRR_TREFRESH2      (0xFFU<<16U)
#define DAC_SHRR_TREFRESH2_0    (0x1U<<16U)
#define DAC_SHRR_TREFRESH1      (0xFFU<<0U)
#define DAC_SHRR_TREFRESH1_0    (0x1U<<0U)
