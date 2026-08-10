/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_adc1 equates.
 */

#pragma once

#include    <stdint.h>

// ADC1 address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    STAT;
    volatile    uint32_t    CTL0;
    volatile    uint32_t    CTL1;
    volatile    uint32_t    SAMPT0;
    volatile    uint32_t    SAMPT1;
    volatile    uint32_t    IOFF0;
    volatile    uint32_t    IOFF1;
    volatile    uint32_t    IOFF2;
    volatile    uint32_t    IOFF3;
    volatile    uint32_t    WDHT;
    volatile    uint32_t    WDLT;
    volatile    uint32_t    RSQ0;
    volatile    uint32_t    RSQ1;
    volatile    uint32_t    RSQ2;
    volatile    uint32_t    ISQ;
    volatile    uint32_t    IDATA0;
    volatile    uint32_t    IDATA1;
    volatile    uint32_t    IDATA2;
    volatile    uint32_t    IDATA3;
    volatile    uint32_t    RDATA;
} ADC1_TypeDef;

#ifdef __cplusplus
#define ADC1    reinterpret_cast<ADC1_TypeDef *>(0x40012800U)

#else
#define ADC1    ((ADC1_TypeDef *)0x40012800U)
#endif

// STAT Configuration

#define ADC1_STAT_WDE           (0x1U<<0U)
#define ADC1_STAT_EOC           (0x1U<<1U)
#define ADC1_STAT_EOIC          (0x1U<<2U)
#define ADC1_STAT_STIC          (0x1U<<3U)
#define ADC1_STAT_STRC          (0x1U<<4U)

// CTL0 Configuration

#define ADC1_CTL0_WDCHSEL       (0x1FU<<0U)
#define ADC1_CTL0_WDCHSEL_0     (0x1U<<0U)
#define ADC1_CTL0_EOCIE         (0x1U<<5U)
#define ADC1_CTL0_WDEIE         (0x1U<<6U)
#define ADC1_CTL0_EOICIE        (0x1U<<7U)
#define ADC1_CTL0_SM            (0x1U<<8U)
#define ADC1_CTL0_WDSC          (0x1U<<9U)
#define ADC1_CTL0_ICA           (0x1U<<10U)
#define ADC1_CTL0_DISRC         (0x1U<<11U)
#define ADC1_CTL0_DISIC         (0x1U<<12U)
#define ADC1_CTL0_DISNUM        (0x7U<<13U)
#define ADC1_CTL0_DISNUM_0      (0x1U<<13U)
#define ADC1_CTL0_IWDEN         (0x1U<<22U)
#define ADC1_CTL0_RWDEN         (0x1U<<23U)

// CTL1 Configuration

#define ADC1_CTL1_ADCON         (0x1U<<0U)
#define ADC1_CTL1_CTN           (0x1U<<1U)
#define ADC1_CTL1_CLB           (0x1U<<2U)
#define ADC1_CTL1_RSTCLB        (0x1U<<3U)
#define ADC1_CTL1_DMA           (0x1U<<8U)
#define ADC1_CTL1_DAL           (0x1U<<11U)
#define ADC1_CTL1_ETSIC         (0x7U<<12U)
#define ADC1_CTL1_ETSIC_0       (0x1U<<12U)
#define ADC1_CTL1_ETEIC         (0x1U<<15U)
#define ADC1_CTL1_ETSRC         (0x7U<<17U)
#define ADC1_CTL1_ETSRC_0       (0x1U<<17U)
#define ADC1_CTL1_ETERC         (0x1U<<20U)
#define ADC1_CTL1_SWICST        (0x1U<<21U)
#define ADC1_CTL1_SWRCST        (0x1U<<22U)

// SAMPT0 Configuration

#define ADC1_SAMPT0_SPT17       (0x7U<<21U)
#define ADC1_SAMPT0_SPT17_0     (0x1U<<21U)
#define ADC1_SAMPT0_SPT16       (0x7U<<18U)
#define ADC1_SAMPT0_SPT16_0     (0x1U<<18U)
#define ADC1_SAMPT0_SPT15       (0x7U<<15U)
#define ADC1_SAMPT0_SPT15_0     (0x1U<<15U)
#define ADC1_SAMPT0_SPT14       (0x7U<<12U)
#define ADC1_SAMPT0_SPT14_0     (0x1U<<12U)
#define ADC1_SAMPT0_SPT13       (0x7U<<9U)
#define ADC1_SAMPT0_SPT13_0     (0x1U<<9U)
#define ADC1_SAMPT0_SPT12       (0x7U<<6U)
#define ADC1_SAMPT0_SPT12_0     (0x1U<<6U)
#define ADC1_SAMPT0_SPT11       (0x7U<<3U)
#define ADC1_SAMPT0_SPT11_0     (0x1U<<3U)
#define ADC1_SAMPT0_SPT10       (0x7U<<0U)
#define ADC1_SAMPT0_SPT10_0     (0x1U<<0U)

// SAMPT1 Configuration

#define ADC1_SAMPT1_SPT9        (0x7U<<27U)
#define ADC1_SAMPT1_SPT9_0      (0x1U<<27U)
#define ADC1_SAMPT1_SPT8        (0x7U<<24U)
#define ADC1_SAMPT1_SPT8_0      (0x1U<<24U)
#define ADC1_SAMPT1_SPT7        (0x7U<<21U)
#define ADC1_SAMPT1_SPT7_0      (0x1U<<21U)
#define ADC1_SAMPT1_SPT6        (0x7U<<18U)
#define ADC1_SAMPT1_SPT6_0      (0x1U<<18U)
#define ADC1_SAMPT1_SPT5        (0x7U<<15U)
#define ADC1_SAMPT1_SPT5_0      (0x1U<<15U)
#define ADC1_SAMPT1_SPT4        (0x7U<<12U)
#define ADC1_SAMPT1_SPT4_0      (0x1U<<12U)
#define ADC1_SAMPT1_SPT3        (0x7U<<9U)
#define ADC1_SAMPT1_SPT3_0      (0x1U<<9U)
#define ADC1_SAMPT1_SPT2        (0x7U<<6U)
#define ADC1_SAMPT1_SPT2_0      (0x1U<<6U)
#define ADC1_SAMPT1_SPT1        (0x7U<<3U)
#define ADC1_SAMPT1_SPT1_0      (0x1U<<3U)
#define ADC1_SAMPT1_SPT0        (0x7U<<0U)
#define ADC1_SAMPT1_SPT0_0      (0x1U<<0U)

// IOFF0 Configuration

#define ADC1_IOFF0_IOFF         (0xFFFU<<0U)
#define ADC1_IOFF0_IOFF_0       (0x1U<<0U)

// IOFF1 Configuration

#define ADC1_IOFF1_IOFF         (0xFFFU<<0U)
#define ADC1_IOFF1_IOFF_0       (0x1U<<0U)

// IOFF2 Configuration

#define ADC1_IOFF2_IOFF         (0xFFFU<<0U)
#define ADC1_IOFF2_IOFF_0       (0x1U<<0U)

// IOFF3 Configuration

#define ADC1_IOFF3_IOFF         (0xFFFU<<0U)
#define ADC1_IOFF3_IOFF_0       (0x1U<<0U)

// WDHT Configuration

#define ADC1_WDHT_WDHT          (0xFFFU<<0U)
#define ADC1_WDHT_WDHT_0        (0x1U<<0U)

// WDLT Configuration

#define ADC1_WDLT_WDLT          (0xFFFU<<0U)
#define ADC1_WDLT_WDLT_0        (0x1U<<0U)

// RSQ0 Configuration

#define ADC1_RSQ0_RSQ12         (0x1FU<<0U)
#define ADC1_RSQ0_RSQ12_0       (0x1U<<0U)
#define ADC1_RSQ0_RSQ13         (0x1FU<<5U)
#define ADC1_RSQ0_RSQ13_0       (0x1U<<5U)
#define ADC1_RSQ0_RSQ14         (0x1FU<<10U)
#define ADC1_RSQ0_RSQ14_0       (0x1U<<10U)
#define ADC1_RSQ0_RSQ15         (0x1FU<<15U)
#define ADC1_RSQ0_RSQ15_0       (0x1U<<15U)
#define ADC1_RSQ0_RL            (0xFU<<20U)
#define ADC1_RSQ0_RL_0          (0x1U<<20U)

// RSQ1 Configuration

#define ADC1_RSQ1_RSQ6          (0x1FU<<0U)
#define ADC1_RSQ1_RSQ6_0        (0x1U<<0U)
#define ADC1_RSQ1_RSQ7          (0x1FU<<5U)
#define ADC1_RSQ1_RSQ7_0        (0x1U<<5U)
#define ADC1_RSQ1_RSQ8          (0x1FU<<10U)
#define ADC1_RSQ1_RSQ8_0        (0x1U<<10U)
#define ADC1_RSQ1_RSQ9          (0x1FU<<15U)
#define ADC1_RSQ1_RSQ9_0        (0x1U<<15U)
#define ADC1_RSQ1_RSQ10         (0x1FU<<20U)
#define ADC1_RSQ1_RSQ10_0       (0x1U<<20U)
#define ADC1_RSQ1_RSQ11         (0x1FU<<25U)
#define ADC1_RSQ1_RSQ11_0       (0x1U<<25U)

// RSQ2 Configuration

#define ADC1_RSQ2_RSQ0          (0x1FU<<0U)
#define ADC1_RSQ2_RSQ0_0        (0x1U<<0U)
#define ADC1_RSQ2_RSQ1          (0x1FU<<5U)
#define ADC1_RSQ2_RSQ1_0        (0x1U<<5U)
#define ADC1_RSQ2_RSQ2          (0x1FU<<10U)
#define ADC1_RSQ2_RSQ2_0        (0x1U<<10U)
#define ADC1_RSQ2_RSQ3          (0x1FU<<15U)
#define ADC1_RSQ2_RSQ3_0        (0x1U<<15U)
#define ADC1_RSQ2_RSQ4          (0x1FU<<20U)
#define ADC1_RSQ2_RSQ4_0        (0x1U<<20U)
#define ADC1_RSQ2_RSQ5          (0x1FU<<25U)
#define ADC1_RSQ2_RSQ5_0        (0x1U<<25U)

// ISQ Configuration

#define ADC1_ISQ_ISQ0           (0x1FU<<0U)
#define ADC1_ISQ_ISQ0_0         (0x1U<<0U)
#define ADC1_ISQ_ISQ1           (0x1FU<<5U)
#define ADC1_ISQ_ISQ1_0         (0x1U<<5U)
#define ADC1_ISQ_ISQ2           (0x1FU<<10U)
#define ADC1_ISQ_ISQ2_0         (0x1U<<10U)
#define ADC1_ISQ_ISQ3           (0x1FU<<15U)
#define ADC1_ISQ_ISQ3_0         (0x1U<<15U)
#define ADC1_ISQ_IL             (0x3U<<20U)
#define ADC1_ISQ_IL_0           (0x1U<<20U)

// IDATA0 Configuration

#define ADC1_IDATA0_IDATAN      (0xFFFFU<<0U)
#define ADC1_IDATA0_IDATAN_0    (0x1U<<0U)

// IDATA1 Configuration

#define ADC1_IDATA1_IDATAN      (0xFFFFU<<0U)
#define ADC1_IDATA1_IDATAN_0    (0x1U<<0U)

// IDATA2 Configuration

#define ADC1_IDATA2_IDATAN      (0xFFFFU<<0U)
#define ADC1_IDATA2_IDATAN_0    (0x1U<<0U)

// IDATA3 Configuration

#define ADC1_IDATA3_IDATAN      (0xFFFFU<<0U)
#define ADC1_IDATA3_IDATAN_0    (0x1U<<0U)

// RDATA Configuration

#define ADC1_RDATA_RDATA        (0xFFFFU<<0U)
#define ADC1_RDATA_RDATA_0      (0x1U<<0U)
