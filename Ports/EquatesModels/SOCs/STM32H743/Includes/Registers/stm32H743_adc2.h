/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_adc2 equates.
 */

#pragma once

#include    <stdint.h>

// ADC2 address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    ISR;
    volatile    uint32_t    IER;
    volatile    uint32_t    CR;
    volatile    uint32_t    CFGR;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    SMPR1;
    volatile    uint32_t    SMPR2;
    volatile    uint32_t    PCSEL;
    volatile    uint32_t    LTR1;
    volatile    uint32_t    LHTR1;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    SQR1;
    volatile    uint32_t    SQR2;
    volatile    uint32_t    SQR3;
    volatile    uint32_t    SQR4;
    volatile    uint32_t    DR;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    JSQR;
    volatile    uint32_t    RESERVED2[4];
    volatile    uint32_t    OFR1;
    volatile    uint32_t    OFR2;
    volatile    uint32_t    OFR3;
    volatile    uint32_t    OFR4;
    volatile    uint32_t    RESERVED3[4];
    volatile    uint32_t    JDR1;
    volatile    uint32_t    JDR2;
    volatile    uint32_t    JDR3;
    volatile    uint32_t    JDR4;
    volatile    uint32_t    RESERVED4[4];
    volatile    uint32_t    AWD2CR;
    volatile    uint32_t    AWD3CR;
    volatile    uint32_t    RESERVED5[2];
    volatile    uint32_t    LTR2;
    volatile    uint32_t    HTR2;
    volatile    uint32_t    LTR3;
    volatile    uint32_t    HTR3;
    volatile    uint32_t    DIFSEL;
    volatile    uint32_t    CALFACT;
    volatile    uint32_t    CALFACT2;
} ADC2_TypeDef;

#ifdef __cplusplus
#define ADC2    reinterpret_cast<ADC2_TypeDef *>(0x40022100U)

#else
#define ADC2    ((ADC2_TypeDef *)0x40022100U)
#endif

// ISR Configuration

#define ADC2_ISR_ADRDY              (0x1U<<0U)
#define ADC2_ISR_EOSMP              (0x1U<<1U)
#define ADC2_ISR_EOC                (0x1U<<2U)
#define ADC2_ISR_EOS                (0x1U<<3U)
#define ADC2_ISR_OVR                (0x1U<<4U)
#define ADC2_ISR_JEOC               (0x1U<<5U)
#define ADC2_ISR_JEOS               (0x1U<<6U)
#define ADC2_ISR_AWD1               (0x1U<<7U)
#define ADC2_ISR_AWD2               (0x1U<<8U)
#define ADC2_ISR_AWD3               (0x1U<<9U)
#define ADC2_ISR_JQOVF              (0x1U<<10U)

// IER Configuration

#define ADC2_IER_ADRDYIE            (0x1U<<0U)
#define ADC2_IER_EOSMPIE            (0x1U<<1U)
#define ADC2_IER_EOCIE              (0x1U<<2U)
#define ADC2_IER_EOSIE              (0x1U<<3U)
#define ADC2_IER_OVRIE              (0x1U<<4U)
#define ADC2_IER_JEOCIE             (0x1U<<5U)
#define ADC2_IER_JEOSIE             (0x1U<<6U)
#define ADC2_IER_AWD1IE             (0x1U<<7U)
#define ADC2_IER_AWD2IE             (0x1U<<8U)
#define ADC2_IER_AWD3IE             (0x1U<<9U)
#define ADC2_IER_JQOVFIE            (0x1U<<10U)

// CR Configuration

#define ADC2_CR_ADEN                (0x1U<<0U)
#define ADC2_CR_ADDIS               (0x1U<<1U)
#define ADC2_CR_ADSTART             (0x1U<<2U)
#define ADC2_CR_JADSTART            (0x1U<<3U)
#define ADC2_CR_ADSTP               (0x1U<<4U)
#define ADC2_CR_JADSTP              (0x1U<<5U)
#define ADC2_CR_BOOST               (0x1U<<8U)
#define ADC2_CR_ADCALLIN            (0x1U<<16U)
#define ADC2_CR_LINCALRDYW1         (0x1U<<22U)
#define ADC2_CR_LINCALRDYW2         (0x1U<<23U)
#define ADC2_CR_LINCALRDYW3         (0x1U<<24U)
#define ADC2_CR_LINCALRDYW4         (0x1U<<25U)
#define ADC2_CR_LINCALRDYW5         (0x1U<<26U)
#define ADC2_CR_LINCALRDYW6         (0x1U<<27U)
#define ADC2_CR_ADVREGEN            (0x1U<<28U)
#define ADC2_CR_DEEPPWD             (0x1U<<29U)
#define ADC2_CR_ADCALDIF            (0x1U<<30U)
#define ADC2_CR_ADCAL               (0x1U<<31U)

// CFGR Configuration

#define ADC2_CFGR_DMNGT             (0x3U<<0U)
#define ADC2_CFGR_DMNGT_0           (0x1U<<0U)
#define ADC2_CFGR_RES               (0x7U<<2U)
#define ADC2_CFGR_RES_0             (0x1U<<2U)
#define ADC2_CFGR_EXTSEL            (0x1FU<<5U)
#define ADC2_CFGR_EXTSEL_0          (0x1U<<5U)
#define ADC2_CFGR_EXTEN             (0x3U<<10U)
#define ADC2_CFGR_EXTEN_0           (0x1U<<10U)
#define ADC2_CFGR_OVRMOD            (0x1U<<12U)
#define ADC2_CFGR_CONT              (0x1U<<13U)
#define ADC2_CFGR_AUTDLY            (0x1U<<14U)
#define ADC2_CFGR_DISCEN            (0x1U<<16U)
#define ADC2_CFGR_DISCNUM           (0x7U<<17U)
#define ADC2_CFGR_DISCNUM_0         (0x1U<<17U)
#define ADC2_CFGR_JDISCEN           (0x1U<<20U)
#define ADC2_CFGR_JQM               (0x1U<<21U)
#define ADC2_CFGR_AWD1SGL           (0x1U<<22U)
#define ADC2_CFGR_AWD1EN            (0x1U<<23U)
#define ADC2_CFGR_JAWD1EN           (0x1U<<24U)
#define ADC2_CFGR_JAUTO             (0x1U<<25U)
#define ADC2_CFGR_AWDCH1CH          (0x1FU<<26U)
#define ADC2_CFGR_AWDCH1CH_0        (0x1U<<26U)
#define ADC2_CFGR_JQDIS             (0x1U<<31U)

// CFGR2 Configuration

#define ADC2_CFGR2_LSHIFT           (0xFU<<28U)
#define ADC2_CFGR2_LSHIFT_0         (0x1U<<28U)
#define ADC2_CFGR2_OSR              (0x3FFU<<16U)
#define ADC2_CFGR2_OSR_0            (0x1U<<16U)
#define ADC2_CFGR2_RSHIFT4          (0x1U<<14U)
#define ADC2_CFGR2_RSHIFT3          (0x1U<<13U)
#define ADC2_CFGR2_RSHIFT2          (0x1U<<12U)
#define ADC2_CFGR2_RSHIFT1          (0x1U<<11U)
#define ADC2_CFGR2_ROVSM            (0x1U<<10U)
#define ADC2_CFGR2_TROVS            (0x1U<<9U)
#define ADC2_CFGR2_OVSS             (0xFU<<5U)
#define ADC2_CFGR2_OVSS_0           (0x1U<<5U)
#define ADC2_CFGR2_JOVSE            (0x1U<<1U)
#define ADC2_CFGR2_ROVSE            (0x1U<<0U)

// SMPR1 Configuration

#define ADC2_SMPR1_SMP1             (0x7U<<3U)
#define ADC2_SMPR1_SMP1_0           (0x1U<<3U)
#define ADC2_SMPR1_SMP2             (0x7U<<6U)
#define ADC2_SMPR1_SMP2_0           (0x1U<<6U)
#define ADC2_SMPR1_SMP3             (0x7U<<9U)
#define ADC2_SMPR1_SMP3_0           (0x1U<<9U)
#define ADC2_SMPR1_SMP4             (0x7U<<12U)
#define ADC2_SMPR1_SMP4_0           (0x1U<<12U)
#define ADC2_SMPR1_SMP5             (0x7U<<15U)
#define ADC2_SMPR1_SMP5_0           (0x1U<<15U)
#define ADC2_SMPR1_SMP6             (0x7U<<18U)
#define ADC2_SMPR1_SMP6_0           (0x1U<<18U)
#define ADC2_SMPR1_SMP7             (0x7U<<21U)
#define ADC2_SMPR1_SMP7_0           (0x1U<<21U)
#define ADC2_SMPR1_SMP8             (0x7U<<24U)
#define ADC2_SMPR1_SMP8_0           (0x1U<<24U)
#define ADC2_SMPR1_SMP9             (0x7U<<27U)
#define ADC2_SMPR1_SMP9_0           (0x1U<<27U)

// SMPR2 Configuration

#define ADC2_SMPR2_SMP10            (0x7U<<0U)
#define ADC2_SMPR2_SMP10_0          (0x1U<<0U)
#define ADC2_SMPR2_SMP11            (0x7U<<3U)
#define ADC2_SMPR2_SMP11_0          (0x1U<<3U)
#define ADC2_SMPR2_SMP12            (0x7U<<6U)
#define ADC2_SMPR2_SMP12_0          (0x1U<<6U)
#define ADC2_SMPR2_SMP13            (0x7U<<9U)
#define ADC2_SMPR2_SMP13_0          (0x1U<<9U)
#define ADC2_SMPR2_SMP14            (0x7U<<12U)
#define ADC2_SMPR2_SMP14_0          (0x1U<<12U)
#define ADC2_SMPR2_SMP15            (0x7U<<15U)
#define ADC2_SMPR2_SMP15_0          (0x1U<<15U)
#define ADC2_SMPR2_SMP16            (0x7U<<18U)
#define ADC2_SMPR2_SMP16_0          (0x1U<<18U)
#define ADC2_SMPR2_SMP17            (0x7U<<21U)
#define ADC2_SMPR2_SMP17_0          (0x1U<<21U)
#define ADC2_SMPR2_SMP18            (0x7U<<24U)
#define ADC2_SMPR2_SMP18_0          (0x1U<<24U)
#define ADC2_SMPR2_SMP19            (0x7U<<27U)
#define ADC2_SMPR2_SMP19_0          (0x1U<<27U)

// PCSEL Configuration

#define ADC2_PCSEL_PCSEL            (0xFFFFFU<<0U)
#define ADC2_PCSEL_PCSEL_0          (0x1U<<0U)

// LTR1 Configuration

#define ADC2_LTR1_LTR1              (0x3FFFFFFU<<0U)
#define ADC2_LTR1_LTR1_0            (0x1U<<0U)

// LHTR1 Configuration

#define ADC2_LHTR1_LHTR1            (0x3FFFFFFU<<0U)
#define ADC2_LHTR1_LHTR1_0          (0x1U<<0U)

// SQR1 Configuration

#define ADC2_SQR1_L3                (0xFU<<0U)
#define ADC2_SQR1_L3_0              (0x1U<<0U)
#define ADC2_SQR1_SQ1               (0x1FU<<6U)
#define ADC2_SQR1_SQ1_0             (0x1U<<6U)
#define ADC2_SQR1_SQ2               (0x1FU<<12U)
#define ADC2_SQR1_SQ2_0             (0x1U<<12U)
#define ADC2_SQR1_SQ3               (0x1FU<<18U)
#define ADC2_SQR1_SQ3_0             (0x1U<<18U)
#define ADC2_SQR1_SQ4               (0x1FU<<24U)
#define ADC2_SQR1_SQ4_0             (0x1U<<24U)

// SQR2 Configuration

#define ADC2_SQR2_SQ5               (0x1FU<<0U)
#define ADC2_SQR2_SQ5_0             (0x1U<<0U)
#define ADC2_SQR2_SQ6               (0x1FU<<6U)
#define ADC2_SQR2_SQ6_0             (0x1U<<6U)
#define ADC2_SQR2_SQ7               (0x1FU<<12U)
#define ADC2_SQR2_SQ7_0             (0x1U<<12U)
#define ADC2_SQR2_SQ8               (0x1FU<<18U)
#define ADC2_SQR2_SQ8_0             (0x1U<<18U)
#define ADC2_SQR2_SQ9               (0x1FU<<24U)
#define ADC2_SQR2_SQ9_0             (0x1U<<24U)

// SQR3 Configuration

#define ADC2_SQR3_SQ10              (0x1FU<<0U)
#define ADC2_SQR3_SQ10_0            (0x1U<<0U)
#define ADC2_SQR3_SQ11              (0x1FU<<6U)
#define ADC2_SQR3_SQ11_0            (0x1U<<6U)
#define ADC2_SQR3_SQ12              (0x1FU<<12U)
#define ADC2_SQR3_SQ12_0            (0x1U<<12U)
#define ADC2_SQR3_SQ13              (0x1FU<<18U)
#define ADC2_SQR3_SQ13_0            (0x1U<<18U)
#define ADC2_SQR3_SQ14              (0x1FU<<24U)
#define ADC2_SQR3_SQ14_0            (0x1U<<24U)

// SQR4 Configuration

#define ADC2_SQR4_SQ15              (0x1FU<<0U)
#define ADC2_SQR4_SQ15_0            (0x1U<<0U)
#define ADC2_SQR4_SQ16              (0x1FU<<6U)
#define ADC2_SQR4_SQ16_0            (0x1U<<6U)

// DR Configuration

#define ADC2_DR_RDATA               (0xFFFFU<<0U)
#define ADC2_DR_RDATA_0             (0x1U<<0U)

// JSQR Configuration

#define ADC2_JSQR_JL                (0x3U<<0U)
#define ADC2_JSQR_JL_0              (0x1U<<0U)
#define ADC2_JSQR_JEXTSEL           (0x1FU<<2U)
#define ADC2_JSQR_JEXTSEL_0         (0x1U<<2U)
#define ADC2_JSQR_JEXTEN            (0x3U<<7U)
#define ADC2_JSQR_JEXTEN_0          (0x1U<<7U)
#define ADC2_JSQR_JSQ1              (0x1FU<<9U)
#define ADC2_JSQR_JSQ1_0            (0x1U<<9U)
#define ADC2_JSQR_JSQ2              (0x1FU<<15U)
#define ADC2_JSQR_JSQ2_0            (0x1U<<15U)
#define ADC2_JSQR_JSQ3              (0x1FU<<21U)
#define ADC2_JSQR_JSQ3_0            (0x1U<<21U)
#define ADC2_JSQR_JSQ4              (0x1FU<<27U)
#define ADC2_JSQR_JSQ4_0            (0x1U<<27U)

// OFR1 Configuration

#define ADC2_OFR1_OFFSET1           (0x3FFFFFFU<<0U)
#define ADC2_OFR1_OFFSET1_0         (0x1U<<0U)
#define ADC2_OFR1_OFFSET1_CH        (0x1FU<<26U)
#define ADC2_OFR1_OFFSET1_CH_0      (0x1U<<26U)
#define ADC2_OFR1_SSATE             (0x1U<<31U)

// OFR2 Configuration

#define ADC2_OFR2_OFFSET1           (0x3FFFFFFU<<0U)
#define ADC2_OFR2_OFFSET1_0         (0x1U<<0U)
#define ADC2_OFR2_OFFSET1_CH        (0x1FU<<26U)
#define ADC2_OFR2_OFFSET1_CH_0      (0x1U<<26U)
#define ADC2_OFR2_SSATE             (0x1U<<31U)

// OFR3 Configuration

#define ADC2_OFR3_OFFSET1           (0x3FFFFFFU<<0U)
#define ADC2_OFR3_OFFSET1_0         (0x1U<<0U)
#define ADC2_OFR3_OFFSET1_CH        (0x1FU<<26U)
#define ADC2_OFR3_OFFSET1_CH_0      (0x1U<<26U)
#define ADC2_OFR3_SSATE             (0x1U<<31U)

// OFR4 Configuration

#define ADC2_OFR4_OFFSET1           (0x3FFFFFFU<<0U)
#define ADC2_OFR4_OFFSET1_0         (0x1U<<0U)
#define ADC2_OFR4_OFFSET1_CH        (0x1FU<<26U)
#define ADC2_OFR4_OFFSET1_CH_0      (0x1U<<26U)
#define ADC2_OFR4_SSATE             (0x1U<<31U)

// JDR1 Configuration

#define ADC2_JDR1_JDATA1            (0xFFFFFFFFU<<0U)
#define ADC2_JDR1_JDATA1_0          (0x1U<<0U)

// JDR2 Configuration

#define ADC2_JDR2_JDATA2            (0xFFFFFFFFU<<0U)
#define ADC2_JDR2_JDATA2_0          (0x1U<<0U)

// JDR3 Configuration

#define ADC2_JDR3_JDATA3            (0xFFFFFFFFU<<0U)
#define ADC2_JDR3_JDATA3_0          (0x1U<<0U)

// JDR4 Configuration

#define ADC2_JDR4_JDATA4            (0xFFFFFFFFU<<0U)
#define ADC2_JDR4_JDATA4_0          (0x1U<<0U)

// AWD2CR Configuration

#define ADC2_AWD2CR_AWD2CH          (0xFFFFFU<<0U)
#define ADC2_AWD2CR_AWD2CH_0        (0x1U<<0U)

// AWD3CR Configuration

#define ADC2_AWD3CR_AWD3CH          (0xFFFFFU<<1U)
#define ADC2_AWD3CR_AWD3CH_0        (0x1U<<1U)

// LTR2 Configuration

#define ADC2_LTR2_LTR2              (0x3FFFFFFU<<0U)
#define ADC2_LTR2_LTR2_0            (0x1U<<0U)

// HTR2 Configuration

#define ADC2_HTR2_HTR2              (0x3FFFFFFU<<0U)
#define ADC2_HTR2_HTR2_0            (0x1U<<0U)

// LTR3 Configuration

#define ADC2_LTR3_LTR3              (0x3FFFFFFU<<0U)
#define ADC2_LTR3_LTR3_0            (0x1U<<0U)

// HTR3 Configuration

#define ADC2_HTR3_HTR3              (0x3FFFFFFU<<0U)
#define ADC2_HTR3_HTR3_0            (0x1U<<0U)

// DIFSEL Configuration

#define ADC2_DIFSEL_DIFSEL          (0xFFFFFU<<0U)
#define ADC2_DIFSEL_DIFSEL_0        (0x1U<<0U)

// CALFACT Configuration

#define ADC2_CALFACT_CALFACT_S      (0x7FFU<<0U)
#define ADC2_CALFACT_CALFACT_S_0    (0x1U<<0U)
#define ADC2_CALFACT_CALFACT_D      (0x7FFU<<16U)
#define ADC2_CALFACT_CALFACT_D_0    (0x1U<<16U)

// CALFACT2 Configuration

#define ADC2_CALFACT2_LINCALFACT    (0x3FFFFFFFU<<0U)
#define ADC2_CALFACT2_LINCALFACT_0  (0x1U<<0U)
