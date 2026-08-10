/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_adc equates.
 */

#pragma once

#include    <stdint.h>

// ADC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    ISR;
    volatile    uint32_t    IER;
    volatile    uint32_t    CR;
    volatile    uint32_t    CFGR;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    SMPR1;
    volatile    uint32_t    SMPR2;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    TR1;
    volatile    uint32_t    TR2;
    volatile    uint32_t    TR3;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    SQR1;
    volatile    uint32_t    SQR2;
    volatile    uint32_t    SQR3;
    volatile    uint32_t    SQR4;
    volatile    uint32_t    DR;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    JSQR;
    volatile    uint32_t    RESERVED3[4];
    volatile    uint32_t    OFR1;
    volatile    uint32_t    OFR2;
    volatile    uint32_t    OFR3;
    volatile    uint32_t    OFR4;
    volatile    uint32_t    RESERVED4[4];
    volatile    uint32_t    JDR1;
    volatile    uint32_t    JDR2;
    volatile    uint32_t    JDR3;
    volatile    uint32_t    JDR4;
    volatile    uint32_t    RESERVED5[4];
    volatile    uint32_t    AWD2CR;
    volatile    uint32_t    AWD3CR;
    volatile    uint32_t    RESERVED6[2];
    volatile    uint32_t    DIFSEL;
    volatile    uint32_t    CALFACT;
} ADC_TypeDef;

#ifdef __cplusplus
#define ADC reinterpret_cast<ADC_TypeDef *>(0x50040000U)

#else
#define ADC ((ADC_TypeDef *)0x50040000U)
#endif

// ISR Configuration

#define ADC_ISR_ADRDY               (0x1U<<0U)
#define ADC_ISR_EOSMP               (0x1U<<1U)
#define ADC_ISR_EOC                 (0x1U<<2U)
#define ADC_ISR_EOS                 (0x1U<<3U)
#define ADC_ISR_OVR                 (0x1U<<4U)
#define ADC_ISR_JEOC                (0x1U<<5U)
#define ADC_ISR_JEOS                (0x1U<<6U)
#define ADC_ISR_AWD1                (0x1U<<7U)
#define ADC_ISR_AWD2                (0x1U<<8U)
#define ADC_ISR_AWD3                (0x1U<<9U)
#define ADC_ISR_JQOVF               (0x1U<<10U)

// IER Configuration

#define ADC_IER_ADRDYIE             (0x1U<<0U)
#define ADC_IER_EOSMPIE             (0x1U<<1U)
#define ADC_IER_EOCIE               (0x1U<<2U)
#define ADC_IER_EOSIE               (0x1U<<3U)
#define ADC_IER_OVRIE               (0x1U<<4U)
#define ADC_IER_JEOCIE              (0x1U<<5U)
#define ADC_IER_JEOSIE              (0x1U<<6U)
#define ADC_IER_AWD1IE              (0x1U<<7U)
#define ADC_IER_AWD2IE              (0x1U<<8U)
#define ADC_IER_AWD3IE              (0x1U<<9U)
#define ADC_IER_JQOVFIE             (0x1U<<10U)

// CR Configuration

#define ADC_CR_ADEN                 (0x1U<<0U)
#define ADC_CR_ADDIS                (0x1U<<1U)
#define ADC_CR_ADSTART              (0x1U<<2U)
#define ADC_CR_JADSTART             (0x1U<<3U)
#define ADC_CR_ADSTP                (0x1U<<4U)
#define ADC_CR_JADSTP               (0x1U<<5U)
#define ADC_CR_ADVREGEN             (0x1U<<28U)
#define ADC_CR_DEEPPWD              (0x1U<<29U)
#define ADC_CR_ADCALDIF             (0x1U<<30U)
#define ADC_CR_ADCAL                (0x1U<<31U)

// CFGR Configuration

#define ADC_CFGR_JQDIS              (0x1U<<31U)
#define ADC_CFGR_DMAEN              (0x1U<<0U)
#define ADC_CFGR_DMACFG             (0x1U<<1U)
#define ADC_CFGR_RES                (0x3U<<3U)
#define ADC_CFGR_RES_0              (0x1U<<3U)
#define ADC_CFGR_ALIGN              (0x1U<<5U)
#define ADC_CFGR_EXTSEL             (0xFU<<6U)
#define ADC_CFGR_EXTSEL_0           (0x1U<<6U)
#define ADC_CFGR_EXTEN              (0x3U<<10U)
#define ADC_CFGR_EXTEN_0            (0x1U<<10U)
#define ADC_CFGR_OVRMOD             (0x1U<<12U)
#define ADC_CFGR_CONT               (0x1U<<13U)
#define ADC_CFGR_AUTDLY             (0x1U<<14U)
#define ADC_CFGR_DISCEN             (0x1U<<16U)
#define ADC_CFGR_DISCNUM            (0x7U<<17U)
#define ADC_CFGR_DISCNUM_0          (0x1U<<17U)
#define ADC_CFGR_JDISCEN            (0x1U<<20U)
#define ADC_CFGR_JQM                (0x1U<<21U)
#define ADC_CFGR_AWD1SGL            (0x1U<<22U)
#define ADC_CFGR_AWD1EN             (0x1U<<23U)
#define ADC_CFGR_JAWD1EN            (0x1U<<24U)
#define ADC_CFGR_JAUTO              (0x1U<<25U)
#define ADC_CFGR_AWDCH1CH           (0x1FU<<26U)
#define ADC_CFGR_AWDCH1CH_0         (0x1U<<26U)

// CFGR2 Configuration

#define ADC_CFGR2_ROVSE             (0x1U<<0U)
#define ADC_CFGR2_JOVSE             (0x1U<<1U)
#define ADC_CFGR2_OVSR              (0x7U<<2U)
#define ADC_CFGR2_OVSR_0            (0x1U<<2U)
#define ADC_CFGR2_OVSS              (0xFU<<5U)
#define ADC_CFGR2_OVSS_0            (0x1U<<5U)
#define ADC_CFGR2_TROVS             (0x1U<<9U)
#define ADC_CFGR2_ROVSM             (0x1U<<10U)

// SMPR1 Configuration

#define ADC_SMPR1_SMP0              (0x7U<<0U)
#define ADC_SMPR1_SMP0_0            (0x1U<<0U)
#define ADC_SMPR1_SMPPLUS           (0x1U<<31U)
#define ADC_SMPR1_SMP1              (0x7U<<3U)
#define ADC_SMPR1_SMP1_0            (0x1U<<3U)
#define ADC_SMPR1_SMP2              (0x7U<<6U)
#define ADC_SMPR1_SMP2_0            (0x1U<<6U)
#define ADC_SMPR1_SMP3              (0x7U<<9U)
#define ADC_SMPR1_SMP3_0            (0x1U<<9U)
#define ADC_SMPR1_SMP4              (0x7U<<12U)
#define ADC_SMPR1_SMP4_0            (0x1U<<12U)
#define ADC_SMPR1_SMP5              (0x7U<<15U)
#define ADC_SMPR1_SMP5_0            (0x1U<<15U)
#define ADC_SMPR1_SMP6              (0x7U<<18U)
#define ADC_SMPR1_SMP6_0            (0x1U<<18U)
#define ADC_SMPR1_SMP7              (0x7U<<21U)
#define ADC_SMPR1_SMP7_0            (0x1U<<21U)
#define ADC_SMPR1_SMP8              (0x7U<<24U)
#define ADC_SMPR1_SMP8_0            (0x1U<<24U)
#define ADC_SMPR1_SMP9              (0x7U<<27U)
#define ADC_SMPR1_SMP9_0            (0x1U<<27U)

// SMPR2 Configuration

#define ADC_SMPR2_SMP10             (0x7U<<0U)
#define ADC_SMPR2_SMP10_0           (0x1U<<0U)
#define ADC_SMPR2_SMP11             (0x7U<<3U)
#define ADC_SMPR2_SMP11_0           (0x1U<<3U)
#define ADC_SMPR2_SMP12             (0x7U<<6U)
#define ADC_SMPR2_SMP12_0           (0x1U<<6U)
#define ADC_SMPR2_SMP13             (0x7U<<9U)
#define ADC_SMPR2_SMP13_0           (0x1U<<9U)
#define ADC_SMPR2_SMP14             (0x7U<<12U)
#define ADC_SMPR2_SMP14_0           (0x1U<<12U)
#define ADC_SMPR2_SMP15             (0x7U<<15U)
#define ADC_SMPR2_SMP15_0           (0x1U<<15U)
#define ADC_SMPR2_SMP16             (0x7U<<18U)
#define ADC_SMPR2_SMP16_0           (0x1U<<18U)
#define ADC_SMPR2_SMP17             (0x7U<<21U)
#define ADC_SMPR2_SMP17_0           (0x1U<<21U)
#define ADC_SMPR2_SMP18             (0x7U<<24U)
#define ADC_SMPR2_SMP18_0           (0x1U<<24U)

// TR1 Configuration

#define ADC_TR1_LT1                 (0xFFFU<<0U)
#define ADC_TR1_LT1_0               (0x1U<<0U)
#define ADC_TR1_HT1                 (0xFFFU<<16U)
#define ADC_TR1_HT1_0               (0x1U<<16U)

// TR2 Configuration

#define ADC_TR2_LT2                 (0xFFU<<0U)
#define ADC_TR2_LT2_0               (0x1U<<0U)
#define ADC_TR2_HT2                 (0xFFU<<16U)
#define ADC_TR2_HT2_0               (0x1U<<16U)

// TR3 Configuration

#define ADC_TR3_LT3                 (0xFFU<<0U)
#define ADC_TR3_LT3_0               (0x1U<<0U)
#define ADC_TR3_HT3                 (0xFFU<<16U)
#define ADC_TR3_HT3_0               (0x1U<<16U)

// SQR1 Configuration

#define ADC_SQR1_L                  (0xFU<<0U)
#define ADC_SQR1_L_0                (0x1U<<0U)
#define ADC_SQR1_SQ1                (0x1FU<<6U)
#define ADC_SQR1_SQ1_0              (0x1U<<6U)
#define ADC_SQR1_SQ2                (0x1FU<<12U)
#define ADC_SQR1_SQ2_0              (0x1U<<12U)
#define ADC_SQR1_SQ3                (0x1FU<<18U)
#define ADC_SQR1_SQ3_0              (0x1U<<18U)
#define ADC_SQR1_SQ4                (0x1FU<<24U)
#define ADC_SQR1_SQ4_0              (0x1U<<24U)

// SQR2 Configuration

#define ADC_SQR2_SQ5                (0x1FU<<0U)
#define ADC_SQR2_SQ5_0              (0x1U<<0U)
#define ADC_SQR2_SQ6                (0x1FU<<6U)
#define ADC_SQR2_SQ6_0              (0x1U<<6U)
#define ADC_SQR2_SQ7                (0x1FU<<12U)
#define ADC_SQR2_SQ7_0              (0x1U<<12U)
#define ADC_SQR2_SQ8                (0x1FU<<18U)
#define ADC_SQR2_SQ8_0              (0x1U<<18U)
#define ADC_SQR2_SQ9                (0x1FU<<24U)
#define ADC_SQR2_SQ9_0              (0x1U<<24U)

// SQR3 Configuration

#define ADC_SQR3_SQ10               (0x1FU<<0U)
#define ADC_SQR3_SQ10_0             (0x1U<<0U)
#define ADC_SQR3_SQ11               (0x1FU<<6U)
#define ADC_SQR3_SQ11_0             (0x1U<<6U)
#define ADC_SQR3_SQ12               (0x1FU<<12U)
#define ADC_SQR3_SQ12_0             (0x1U<<12U)
#define ADC_SQR3_SQ13               (0x1FU<<18U)
#define ADC_SQR3_SQ13_0             (0x1U<<18U)
#define ADC_SQR3_SQ14               (0x1FU<<24U)
#define ADC_SQR3_SQ14_0             (0x1U<<24U)

// SQR4 Configuration

#define ADC_SQR4_SQ15               (0x1FU<<0U)
#define ADC_SQR4_SQ15_0             (0x1U<<0U)
#define ADC_SQR4_SQ16               (0x1FU<<6U)
#define ADC_SQR4_SQ16_0             (0x1U<<6U)

// DR Configuration

#define ADC_DR_RDATA                (0xFFFFU<<0U)
#define ADC_DR_RDATA_0              (0x1U<<0U)

// JSQR Configuration

#define ADC_JSQR_JL                 (0x3U<<0U)
#define ADC_JSQR_JL_0               (0x1U<<0U)
#define ADC_JSQR_JEXTSEL            (0xFU<<2U)
#define ADC_JSQR_JEXTSEL_0          (0x1U<<2U)
#define ADC_JSQR_JEXTEN             (0x3U<<6U)
#define ADC_JSQR_JEXTEN_0           (0x1U<<6U)
#define ADC_JSQR_JSQ1               (0x1FU<<8U)
#define ADC_JSQR_JSQ1_0             (0x1U<<8U)
#define ADC_JSQR_JSQ2               (0x1FU<<14U)
#define ADC_JSQR_JSQ2_0             (0x1U<<14U)
#define ADC_JSQR_JSQ3               (0x1FU<<20U)
#define ADC_JSQR_JSQ3_0             (0x1U<<20U)
#define ADC_JSQR_JSQ4               (0x1FU<<26U)
#define ADC_JSQR_JSQ4_0             (0x1U<<26U)

// OFR1 Configuration

#define ADC_OFR1_OFFSET1            (0xFFFU<<0U)
#define ADC_OFR1_OFFSET1_0          (0x1U<<0U)
#define ADC_OFR1_OFFSET1_CH         (0x1FU<<26U)
#define ADC_OFR1_OFFSET1_CH_0       (0x1U<<26U)
#define ADC_OFR1_OFFSET1_EN         (0x1U<<31U)

// OFR2 Configuration

#define ADC_OFR2_OFFSET2            (0xFFFU<<0U)
#define ADC_OFR2_OFFSET2_0          (0x1U<<0U)
#define ADC_OFR2_OFFSET2_CH         (0x1FU<<26U)
#define ADC_OFR2_OFFSET2_CH_0       (0x1U<<26U)
#define ADC_OFR2_OFFSET2_EN         (0x1U<<31U)

// OFR3 Configuration

#define ADC_OFR3_OFFSET3            (0xFFFU<<0U)
#define ADC_OFR3_OFFSET3_0          (0x1U<<0U)
#define ADC_OFR3_OFFSET3_CH         (0x1FU<<26U)
#define ADC_OFR3_OFFSET3_CH_0       (0x1U<<26U)
#define ADC_OFR3_OFFSET3_EN         (0x1U<<31U)

// OFR4 Configuration

#define ADC_OFR4_OFFSET4            (0xFFFU<<0U)
#define ADC_OFR4_OFFSET4_0          (0x1U<<0U)
#define ADC_OFR4_OFFSET4_CH         (0x1FU<<26U)
#define ADC_OFR4_OFFSET4_CH_0       (0x1U<<26U)
#define ADC_OFR4_OFFSET4_EN         (0x1U<<31U)

// JDR1 Configuration

#define ADC_JDR1_JDATA1             (0xFFFFU<<0U)
#define ADC_JDR1_JDATA1_0           (0x1U<<0U)

// JDR2 Configuration

#define ADC_JDR2_JDATA2             (0xFFFFU<<0U)
#define ADC_JDR2_JDATA2_0           (0x1U<<0U)

// JDR3 Configuration

#define ADC_JDR3_JDATA3             (0xFFFFU<<0U)
#define ADC_JDR3_JDATA3_0           (0x1U<<0U)

// JDR4 Configuration

#define ADC_JDR4_JDATA4             (0xFFFFU<<0U)
#define ADC_JDR4_JDATA4_0           (0x1U<<0U)

// AWD2CR Configuration

#define ADC_AWD2CR_AWD2CH           (0x3FFFFU<<0U)
#define ADC_AWD2CR_AWD2CH_0         (0x1U<<0U)

// AWD3CR Configuration

#define ADC_AWD3CR_AWD3CH           (0x3FFFFU<<0U)
#define ADC_AWD3CR_AWD3CH_0         (0x1U<<0U)

// DIFSEL Configuration

#define ADC_DIFSEL_DIFSEL_16_18     (0x7U<<16U)
#define ADC_DIFSEL_DIFSEL_16_18_0   (0x1U<<16U)
#define ADC_DIFSEL_DIFSEL_1_15      (0x7FFFU<<1U)
#define ADC_DIFSEL_DIFSEL_1_15_0    (0x1U<<1U)

// CALFACT Configuration

#define ADC_CALFACT_CALFACT_S       (0x7FU<<0U)
#define ADC_CALFACT_CALFACT_S_0     (0x1U<<0U)
#define ADC_CALFACT_CALFACT_D       (0x7FU<<16U)
#define ADC_CALFACT_CALFACT_D_0     (0x1U<<16U)
