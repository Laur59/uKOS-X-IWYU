/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_dac equates.
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
    volatile    uint32_t    RESERVED0[6];
    volatile    uint32_t    DOR1;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    SR;
    volatile    uint32_t    CCR;
    volatile    uint32_t    MCR;
    volatile    uint32_t    SHSR1;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    SHHR;
    volatile    uint32_t    SHRR;
    volatile    uint32_t    RESERVED3[2];
    volatile    uint32_t    STR1;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    STMODR;
} DAC_TypeDef;

#if (defined(__cplusplus))
#define DAC_NS  reinterpret_cast<DAC_TypeDef *>(0x40022C00u)
#define DAC_S   reinterpret_cast<DAC_TypeDef *>(0x50022C00u)

#else
#define DAC_NS  ((DAC_TypeDef *)0x40022C00u)
#define DAC_S   ((DAC_TypeDef *)0x50022C00u)
#endif

// CR Configuration

#define DAC_CR_TSEL1_1                      (0x1u<<15)
#define DAC_CR_CEN1                         (0x1u<<14)
#define DAC_CR_DMAUDRIE1                    (0x1u<<13)
#define DAC_CR_DMAEN1                       (0x1u<<12)
#define DAC_CR_MAMP1                        (0xFu<<8)
#define DAC_CR_MAMP1_0                      (0x1u<<8)
#define DAC_CR_WAVE1                        (0x3u<<6)
#define DAC_CR_WAVE1_0                      (0x1u<<6)
#define DAC_CR_TSEL1                        (0xFu<<2)
#define DAC_CR_TSEL1_0                      (0x1u<<2)
#define DAC_CR_TEN1                         (0x1u<<1)
#define DAC_CR_EN1                          (0x1u<<0)

#define DAC_CR_CEN1_B_0X0                   (0x0u<<14)
#define DAC_CR_CEN1_B_0X1                   (0x1u<<14)
#define DAC_CR_DMAUDRIE1_B_0X0              (0x0u<<13)
#define DAC_CR_DMAUDRIE1_B_0X1              (0x1u<<13)
#define DAC_CR_DMAEN1_B_0X0                 (0x0u<<12)
#define DAC_CR_DMAEN1_B_0X1                 (0x1u<<12)
#define DAC_CR_MAMP1_B_0X0                  (0x0u<<8)
#define DAC_CR_MAMP1_B_0X1                  (0x1u<<8)
#define DAC_CR_MAMP1_B_0X2                  (0x2u<<8)
#define DAC_CR_MAMP1_B_0X3                  (0x3u<<8)
#define DAC_CR_MAMP1_B_0X4                  (0x4u<<8)
#define DAC_CR_MAMP1_B_0X5                  (0x5u<<8)
#define DAC_CR_MAMP1_B_0X6                  (0x6u<<8)
#define DAC_CR_MAMP1_B_0X7                  (0x7u<<8)
#define DAC_CR_MAMP1_B_0X8                  (0x8u<<8)
#define DAC_CR_MAMP1_B_0X9                  (0x9u<<8)
#define DAC_CR_MAMP1_B_0XA                  (0xAu<<8)
#define DAC_CR_WAVE1_B_0X0                  (0x0u<<6)
#define DAC_CR_WAVE1_B_0X1                  (0x1u<<6)
#define DAC_CR_WAVE1_B_0X2                  (0x2u<<6)
#define DAC_CR_WAVE1_B_0X3                  (0x3u<<6)
#define DAC_CR_TSEL1_B_0X0                  (0x0u<<2)
#define DAC_CR_TSEL1_B_0X1                  (0x1u<<2)
#define DAC_CR_TSEL1_B_0X2                  (0x2u<<2)
#define DAC_CR_TEN1_B_0X0                   (0x0u<<1)
#define DAC_CR_TEN1_B_0X1                   (0x1u<<1)
#define DAC_CR_EN1_B_0X0                    (0x0u<<0)
#define DAC_CR_EN1_B_0X1                    (0x1u<<0)

// SWTRGR Configuration

#define DAC_SWTRGR_SWTRIGB1                 (0x1u<<16)
#define DAC_SWTRGR_SWTRIG1                  (0x1u<<0)

#define DAC_SWTRGR_SWTRIGB1_B_0X0           (0x0u<<16)
#define DAC_SWTRGR_SWTRIGB1_B_0X1           (0x1u<<16)
#define DAC_SWTRGR_SWTRIG1_B_0X0            (0x0u<<0)
#define DAC_SWTRGR_SWTRIG1_B_0X1            (0x1u<<0)

// DHR12R1 Configuration

#define DAC_DHR12R1_DACC1DHRB               (0xFFFu<<16)
#define DAC_DHR12R1_DACC1DHRB_0             (0x1u<<16)
#define DAC_DHR12R1_DACC1DHR                (0xFFFu<<0)
#define DAC_DHR12R1_DACC1DHR_0              (0x1u<<0)

// DHR12L1 Configuration

#define DAC_DHR12L1_DACC1DHRB               (0xFFFu<<20)
#define DAC_DHR12L1_DACC1DHRB_0             (0x1u<<20)
#define DAC_DHR12L1_DACC1DHR                (0xFFFu<<4)
#define DAC_DHR12L1_DACC1DHR_0              (0x1u<<4)

// DHR8R1 Configuration

#define DAC_DHR8R1_DACC1DHRB                (0xFFu<<8)
#define DAC_DHR8R1_DACC1DHRB_0              (0x1u<<8)
#define DAC_DHR8R1_DACC1DHR                 (0xFFu<<0)
#define DAC_DHR8R1_DACC1DHR_0               (0x1u<<0)

// DOR1 Configuration

#define DAC_DOR1_DACC1DORB                  (0xFFFu<<16)
#define DAC_DOR1_DACC1DORB_0                (0x1u<<16)
#define DAC_DOR1_DACC1DOR                   (0xFFFu<<0)
#define DAC_DOR1_DACC1DOR_0                 (0x1u<<0)

// SR Configuration

#define DAC_SR_BWST1                        (0x1u<<15)
#define DAC_SR_CAL_FLAG1                    (0x1u<<14)
#define DAC_SR_DMAUDR1                      (0x1u<<13)
#define DAC_SR_DORSTAT1                     (0x1u<<12)
#define DAC_SR_DAC1RDY                      (0x1u<<11)

#define DAC_SR_BWST1_B_0X0                  (0x0u<<15)
#define DAC_SR_BWST1_B_0X1                  (0x1u<<15)
#define DAC_SR_CAL_FLAG1_B_0X0              (0x0u<<14)
#define DAC_SR_CAL_FLAG1_B_0X1              (0x1u<<14)
#define DAC_SR_DMAUDR1_B_0X0                (0x0u<<13)
#define DAC_SR_DMAUDR1_B_0X1                (0x1u<<13)
#define DAC_SR_DORSTAT1_B_0X0               (0x0u<<12)
#define DAC_SR_DORSTAT1_B_0X1               (0x1u<<12)
#define DAC_SR_DAC1RDY_B_0X0                (0x0u<<11)
#define DAC_SR_DAC1RDY_B_0X1                (0x1u<<11)

// CCR Configuration

#define DAC_CCR_OTRIM1                      (0x3Fu<<0)
#define DAC_CCR_OTRIM1_0                    (0x1u<<0)

// MCR Configuration

#define DAC_MCR_HFSEL                       (0x7u<<13)
#define DAC_MCR_HFSEL_0                     (0x1u<<13)
#define DAC_MCR_BUFCFG                      (0x1u<<11)
#define DAC_MCR_LEAKCTRL                    (0x1u<<10)
#define DAC_MCR_SINFORMAT1                  (0x1u<<9)
#define DAC_MCR_DMADOUBLE1                  (0x1u<<8)
#define DAC_MCR_MODE1                       (0x7u<<0)
#define DAC_MCR_MODE1_0                     (0x1u<<0)

#define DAC_MCR_HFSEL_B_0X0                 (0x0u<<13)
#define DAC_MCR_HFSEL_B_0X1                 (0x1u<<13)
#define DAC_MCR_HFSEL_B_0X2                 (0x2u<<13)
#define DAC_MCR_HFSEL_B_0X3                 (0x3u<<13)
#define DAC_MCR_HFSEL_B_0X4                 (0x4u<<13)
#define DAC_MCR_BUFCFG_B_0X0                (0x0u<<11)
#define DAC_MCR_BUFCFG_B_0X1                (0x1u<<11)
#define DAC_MCR_LEAKCTRL_B_0X0              (0x0u<<10)
#define DAC_MCR_LEAKCTRL_B_0X1              (0x1u<<10)
#define DAC_MCR_SINFORMAT1_B_0X0            (0x0u<<9)
#define DAC_MCR_SINFORMAT1_B_0X1            (0x1u<<9)
#define DAC_MCR_DMADOUBLE1_B_0X0            (0x0u<<8)
#define DAC_MCR_DMADOUBLE1_B_0X1            (0x1u<<8)
#define DAC_MCR_MODE1_B_0X0                 (0x0u<<0)
#define DAC_MCR_MODE1_B_0X1                 (0x1u<<0)
#define DAC_MCR_MODE1_B_0X2                 (0x2u<<0)
#define DAC_MCR_MODE1_B_0X3                 (0x3u<<0)
#define DAC_MCR_MODE1_B_0X4                 (0x4u<<0)
#define DAC_MCR_MODE1_B_0X5                 (0x5u<<0)
#define DAC_MCR_MODE1_B_0X6                 (0x6u<<0)
#define DAC_MCR_MODE1_B_0X7                 (0x7u<<0)

// SHSR1 Configuration

#define DAC_SHSR1_TSAMPLE1                  (0x3FFu<<0)
#define DAC_SHSR1_TSAMPLE1_0                (0x1u<<0)

// SHHR Configuration

#define DAC_SHHR_THOLD1                     (0x3FFu<<0)
#define DAC_SHHR_THOLD1_0                   (0x1u<<0)

// SHRR Configuration

#define DAC_SHRR_TREFRESH1                  (0xFFu<<0)
#define DAC_SHRR_TREFRESH1_0                (0x1u<<0)

// STR1 Configuration

#define DAC_STR1_STINCDATA1                 (0xFFFFu<<16)
#define DAC_STR1_STINCDATA1_0               (0x1u<<16)
#define DAC_STR1_STDIR1                     (0x1u<<12)
#define DAC_STR1_STRSTDATA1                 (0xFFFu<<0)
#define DAC_STR1_STRSTDATA1_0               (0x1u<<0)

#define DAC_STR1_STDIR1_B_0X0               (0x0u<<12)
#define DAC_STR1_STDIR1_B_0X1               (0x1u<<12)

// STMODR Configuration

#define DAC_STMODR_STINCTRIGSEL1            (0x1Fu<<8)
#define DAC_STMODR_STINCTRIGSEL1_0          (0x1u<<8)
#define DAC_STMODR_STRSTTRIGSEL1            (0x1Fu<<0)
#define DAC_STMODR_STRSTTRIGSEL1_0          (0x1u<<0)

#define DAC_STMODR_STINCTRIGSEL1_B_0X0      (0x0u<<8)
#define DAC_STMODR_STINCTRIGSEL1_B_0X1      (0x1u<<8)
#define DAC_STMODR_STINCTRIGSEL1_B_0X1F     (0x1Fu<<8)
#define DAC_STMODR_STRSTTRIGSEL1_B_0X0      (0x0u<<0)
#define DAC_STMODR_STRSTTRIGSEL1_B_0X1      (0x1u<<0)
#define DAC_STMODR_STRSTTRIGSEL1_B_0X1F     (0x1Fu<<0)
