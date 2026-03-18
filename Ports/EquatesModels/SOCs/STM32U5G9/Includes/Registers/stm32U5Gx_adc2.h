/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_adc2 equates.
 */

#pragma once

#include    <stdint.h>

// ADC2 address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    ISR;
    volatile    uint32_t    IER;
    volatile    uint32_t    CR;
    volatile    uint32_t    CFGR1;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    SMPR1;
    volatile    uint32_t    SMPR2;
    volatile    uint32_t    PCSEL;
    volatile    uint32_t    RESERVED0[4];
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
    volatile    uint32_t    GCOMP;
    volatile    uint32_t    RESERVED3[3];
    volatile    uint32_t    JDR1;
    volatile    uint32_t    JDR2;
    volatile    uint32_t    JDR3;
    volatile    uint32_t    JDR4;
    volatile    uint32_t    RESERVED4[4];
    volatile    uint32_t    AWD2CR;
    volatile    uint32_t    AWD3CR;
    volatile    uint32_t    LTR1;
    volatile    uint32_t    HTR1;
    volatile    uint32_t    LTR2;
    volatile    uint32_t    HTR2;
    volatile    uint32_t    LTR3;
    volatile    uint32_t    HTR3;
    volatile    uint32_t    DIFSEL;
    volatile    uint32_t    CALFACT;
    volatile    uint32_t    CALFACT2;
} ADC2_TypeDef;

#ifdef __cplusplus
#define ADC2_NS reinterpret_cast<ADC2_TypeDef *>(0x42028100U)
#define ADC2_S  reinterpret_cast<ADC2_TypeDef *>(0x52028100U)

#else
#define ADC2_NS ((ADC2_TypeDef *)0x42028100U)
#define ADC2_S  ((ADC2_TypeDef *)0x52028100U)
#endif

// ISR Configuration

#define ADC2_ISR_ADRDY              (0x1U<<0)
#define ADC2_ISR_EOSMP              (0x1U<<1)
#define ADC2_ISR_EOC                (0x1U<<2)
#define ADC2_ISR_EOS                (0x1U<<3)
#define ADC2_ISR_OVR                (0x1U<<4)
#define ADC2_ISR_JEOC               (0x1U<<5)
#define ADC2_ISR_JEOS               (0x1U<<6)
#define ADC2_ISR_AWD1               (0x1U<<7)
#define ADC2_ISR_AWD2               (0x1U<<8)
#define ADC2_ISR_AWD3               (0x1U<<9)
#define ADC2_ISR_LDORDY             (0x1U<<12)

// IER Configuration

#define ADC2_IER_ADRDYIE            (0x1U<<0)
#define ADC2_IER_EOSMPIE            (0x1U<<1)
#define ADC2_IER_EOCIE              (0x1U<<2)
#define ADC2_IER_EOSIE              (0x1U<<3)
#define ADC2_IER_OVRIE              (0x1U<<4)
#define ADC2_IER_JEOCIE             (0x1U<<5)
#define ADC2_IER_JEOSIE             (0x1U<<6)
#define ADC2_IER_AWD1IE             (0x1U<<7)
#define ADC2_IER_AWD2IE             (0x1U<<8)
#define ADC2_IER_AWD3IE             (0x1U<<9)

// CR Configuration

#define ADC2_CR_ADEN                (0x1U<<0)
#define ADC2_CR_ADDIS               (0x1U<<1)
#define ADC2_CR_ADSTART             (0x1U<<2)
#define ADC2_CR_JADSTART            (0x1U<<3)
#define ADC2_CR_ADSTP               (0x1U<<4)
#define ADC2_CR_JADSTP              (0x1U<<5)
#define ADC2_CR_ADCALLIN            (0x1U<<16)
#define ADC2_CR_CALINDEX            (0xFU<<24)
#define ADC2_CR_CALINDEX_0          (0x1U<<24)
#define ADC2_CR_ADVREGEN            (0x1U<<28)
#define ADC2_CR_DEEPPWD             (0x1U<<29)
#define ADC2_CR_ADCAL               (0x1U<<31)

// CFGR1 Configuration

#define ADC2_CFGR1_DMNGT            (0x3U<<0)
#define ADC2_CFGR1_DMNGT_0          (0x1U<<0)
#define ADC2_CFGR1_RES              (0x3U<<2)
#define ADC2_CFGR1_RES_0            (0x1U<<2)
#define ADC2_CFGR1_EXTSEL           (0x1FU<<5)
#define ADC2_CFGR1_EXTSEL_0         (0x1U<<5)
#define ADC2_CFGR1_EXTEN            (0x3U<<10)
#define ADC2_CFGR1_EXTEN_0          (0x1U<<10)
#define ADC2_CFGR1_OVRMOD           (0x1U<<12)
#define ADC2_CFGR1_CONT             (0x1U<<13)
#define ADC2_CFGR1_AUTDLY           (0x1U<<14)
#define ADC2_CFGR1_DISCEN           (0x1U<<16)
#define ADC2_CFGR1_DISCNUM          (0x7U<<17)
#define ADC2_CFGR1_DISCNUM_0        (0x1U<<17)
#define ADC2_CFGR1_JDISCEN          (0x1U<<20)
#define ADC2_CFGR1_AWD1SGL          (0x1U<<22)
#define ADC2_CFGR1_AWD1EN           (0x1U<<23)
#define ADC2_CFGR1_JAWD1EN          (0x1U<<24)
#define ADC2_CFGR1_JAUTO            (0x1U<<25)
#define ADC2_CFGR1_AWD1CH           (0x1FU<<26)
#define ADC2_CFGR1_AWD1CH_0         (0x1U<<26)

// CFGR2 Configuration

#define ADC2_CFGR2_ROVSE            (0x1U<<0)
#define ADC2_CFGR2_JOVSE            (0x1U<<1)
#define ADC2_CFGR2_OVSS             (0xFU<<5)
#define ADC2_CFGR2_OVSS_0           (0x1U<<5)
#define ADC2_CFGR2_TROVS            (0x1U<<9)
#define ADC2_CFGR2_ROVSM            (0x1U<<10)
#define ADC2_CFGR2_BULB             (0x1U<<13)
#define ADC2_CFGR2_SWTRIG           (0x1U<<14)
#define ADC2_CFGR2_SMPTRIG          (0x1U<<15)
#define ADC2_CFGR2_OSR              (0x3FFU<<16)
#define ADC2_CFGR2_OSR_0            (0x1U<<16)
#define ADC2_CFGR2_LFTRIG           (0x1U<<27)
#define ADC2_CFGR2_LSHIFT           (0xFU<<28)
#define ADC2_CFGR2_LSHIFT_0         (0x1U<<28)

// SMPR1 Configuration

#define ADC2_SMPR1_SMP0             (0x7U<<0)
#define ADC2_SMPR1_SMP0_0           (0x1U<<0)
#define ADC2_SMPR1_SMP1             (0x7U<<3)
#define ADC2_SMPR1_SMP1_0           (0x1U<<3)
#define ADC2_SMPR1_SMP2             (0x7U<<6)
#define ADC2_SMPR1_SMP2_0           (0x1U<<6)
#define ADC2_SMPR1_SMP3             (0x7U<<9)
#define ADC2_SMPR1_SMP3_0           (0x1U<<9)
#define ADC2_SMPR1_SMP4             (0x7U<<12)
#define ADC2_SMPR1_SMP4_0           (0x1U<<12)
#define ADC2_SMPR1_SMP5             (0x7U<<15)
#define ADC2_SMPR1_SMP5_0           (0x1U<<15)
#define ADC2_SMPR1_SMP6             (0x7U<<18)
#define ADC2_SMPR1_SMP6_0           (0x1U<<18)
#define ADC2_SMPR1_SMP7             (0x7U<<21)
#define ADC2_SMPR1_SMP7_0           (0x1U<<21)
#define ADC2_SMPR1_SMP8             (0x7U<<24)
#define ADC2_SMPR1_SMP8_0           (0x1U<<24)
#define ADC2_SMPR1_SMP9             (0x7U<<27)
#define ADC2_SMPR1_SMP9_0           (0x1U<<27)

// SMPR2 Configuration

#define ADC2_SMPR2_SMP10            (0x7U<<0)
#define ADC2_SMPR2_SMP10_0          (0x1U<<0)
#define ADC2_SMPR2_SMP11            (0x7U<<3)
#define ADC2_SMPR2_SMP11_0          (0x1U<<3)
#define ADC2_SMPR2_SMP12            (0x7U<<6)
#define ADC2_SMPR2_SMP12_0          (0x1U<<6)
#define ADC2_SMPR2_SMP13            (0x7U<<9)
#define ADC2_SMPR2_SMP13_0          (0x1U<<9)
#define ADC2_SMPR2_SMP14            (0x7U<<12)
#define ADC2_SMPR2_SMP14_0          (0x1U<<12)
#define ADC2_SMPR2_SMP15            (0x7U<<15)
#define ADC2_SMPR2_SMP15_0          (0x1U<<15)
#define ADC2_SMPR2_SMP16            (0x7U<<18)
#define ADC2_SMPR2_SMP16_0          (0x1U<<18)
#define ADC2_SMPR2_SMP17            (0x7U<<21)
#define ADC2_SMPR2_SMP17_0          (0x1U<<21)
#define ADC2_SMPR2_SMP18            (0x7U<<24)
#define ADC2_SMPR2_SMP18_0          (0x1U<<24)
#define ADC2_SMPR2_SMP19            (0x7U<<27)
#define ADC2_SMPR2_SMP19_0          (0x1U<<27)

// PCSEL Configuration

#define ADC2_PCSEL_PCSEL0           (0x1U<<0)
#define ADC2_PCSEL_PCSEL1           (0x1U<<1)
#define ADC2_PCSEL_PCSEL2           (0x1U<<2)
#define ADC2_PCSEL_PCSEL3           (0x1U<<3)
#define ADC2_PCSEL_PCSEL4           (0x1U<<4)
#define ADC2_PCSEL_PCSEL5           (0x1U<<5)
#define ADC2_PCSEL_PCSEL6           (0x1U<<6)
#define ADC2_PCSEL_PCSEL7           (0x1U<<7)
#define ADC2_PCSEL_PCSEL8           (0x1U<<8)
#define ADC2_PCSEL_PCSEL9           (0x1U<<9)
#define ADC2_PCSEL_PCSEL10          (0x1U<<10)
#define ADC2_PCSEL_PCSEL11          (0x1U<<11)
#define ADC2_PCSEL_PCSEL12          (0x1U<<12)
#define ADC2_PCSEL_PCSEL13          (0x1U<<13)
#define ADC2_PCSEL_PCSEL14          (0x1U<<14)
#define ADC2_PCSEL_PCSEL15          (0x1U<<15)
#define ADC2_PCSEL_PCSEL16          (0x1U<<16)
#define ADC2_PCSEL_PCSEL17          (0x1U<<17)
#define ADC2_PCSEL_PCSEL18          (0x1U<<18)
#define ADC2_PCSEL_PCSEL19          (0x1U<<19)

// SQR1 Configuration

#define ADC2_SQR1_L                 (0xFU<<0)
#define ADC2_SQR1_L_0               (0x1U<<0)
#define ADC2_SQR1_SQ1               (0x1FU<<6)
#define ADC2_SQR1_SQ1_0             (0x1U<<6)
#define ADC2_SQR1_SQ2               (0x1FU<<12)
#define ADC2_SQR1_SQ2_0             (0x1U<<12)
#define ADC2_SQR1_SQ3               (0x1FU<<18)
#define ADC2_SQR1_SQ3_0             (0x1U<<18)
#define ADC2_SQR1_SQ4               (0x1FU<<24)
#define ADC2_SQR1_SQ4_0             (0x1U<<24)

// SQR2 Configuration

#define ADC2_SQR2_SQ5               (0x1FU<<0)
#define ADC2_SQR2_SQ5_0             (0x1U<<0)
#define ADC2_SQR2_SQ6               (0x1FU<<6)
#define ADC2_SQR2_SQ6_0             (0x1U<<6)
#define ADC2_SQR2_SQ7               (0x1FU<<12)
#define ADC2_SQR2_SQ7_0             (0x1U<<12)
#define ADC2_SQR2_SQ8               (0x1FU<<18)
#define ADC2_SQR2_SQ8_0             (0x1U<<18)
#define ADC2_SQR2_SQ9               (0x1FU<<24)
#define ADC2_SQR2_SQ9_0             (0x1U<<24)

// SQR3 Configuration

#define ADC2_SQR3_SQ10              (0x1FU<<0)
#define ADC2_SQR3_SQ10_0            (0x1U<<0)
#define ADC2_SQR3_SQ11              (0x1FU<<6)
#define ADC2_SQR3_SQ11_0            (0x1U<<6)
#define ADC2_SQR3_SQ12              (0x1FU<<12)
#define ADC2_SQR3_SQ12_0            (0x1U<<12)
#define ADC2_SQR3_SQ13              (0x1FU<<18)
#define ADC2_SQR3_SQ13_0            (0x1U<<18)
#define ADC2_SQR3_SQ14              (0x1FU<<24)
#define ADC2_SQR3_SQ14_0            (0x1U<<24)

// SQR4 Configuration

#define ADC2_SQR4_SQ15              (0x1FU<<0)
#define ADC2_SQR4_SQ15_0            (0x1U<<0)
#define ADC2_SQR4_SQ16              (0x1FU<<6)
#define ADC2_SQR4_SQ16_0            (0x1U<<6)

// DR Configuration

#define ADC2_DR_RDATA               (0xFFFFFFFFU<<0)
#define ADC2_DR_RDATA_0             (0x1U<<0)

// JSQR Configuration

#define ADC2_JSQR_JL                (0x3U<<0)
#define ADC2_JSQR_JL_0              (0x1U<<0)
#define ADC2_JSQR_JEXTSEL           (0x1FU<<2)
#define ADC2_JSQR_JEXTSEL_0         (0x1U<<2)
#define ADC2_JSQR_JEXTEN            (0x3U<<7)
#define ADC2_JSQR_JEXTEN_0          (0x1U<<7)
#define ADC2_JSQR_JSQ1              (0x1FU<<9)
#define ADC2_JSQR_JSQ1_0            (0x1U<<9)
#define ADC2_JSQR_JSQ2              (0x1FU<<15)
#define ADC2_JSQR_JSQ2_0            (0x1U<<15)
#define ADC2_JSQR_JSQ3              (0x1FU<<21)
#define ADC2_JSQR_JSQ3_0            (0x1U<<21)
#define ADC2_JSQR_JSQ4              (0x1FU<<27)
#define ADC2_JSQR_JSQ4_0            (0x1U<<27)

// OFR1 Configuration

#define ADC2_OFR1_OFFSET            (0xFFFFFFU<<0)
#define ADC2_OFR1_OFFSET_0          (0x1U<<0)
#define ADC2_OFR1_POSOFF            (0x1U<<24)
#define ADC2_OFR1_USAT              (0x1U<<25)
#define ADC2_OFR1_SSAT              (0x1U<<26)
#define ADC2_OFR1_OFFSET_CH         (0x1FU<<27)
#define ADC2_OFR1_OFFSET_CH_0       (0x1U<<27)

// OFR2 Configuration

#define ADC2_OFR2_OFFSET            (0xFFFFFFU<<0)
#define ADC2_OFR2_OFFSET_0          (0x1U<<0)
#define ADC2_OFR2_POSOFF            (0x1U<<24)
#define ADC2_OFR2_USAT              (0x1U<<25)
#define ADC2_OFR2_SSAT              (0x1U<<26)
#define ADC2_OFR2_OFFSET_CH         (0x1FU<<27)
#define ADC2_OFR2_OFFSET_CH_0       (0x1U<<27)

// OFR3 Configuration

#define ADC2_OFR3_OFFSET            (0xFFFFFFU<<0)
#define ADC2_OFR3_OFFSET_0          (0x1U<<0)
#define ADC2_OFR3_POSOFF            (0x1U<<24)
#define ADC2_OFR3_USAT              (0x1U<<25)
#define ADC2_OFR3_SSAT              (0x1U<<26)
#define ADC2_OFR3_OFFSET_CH         (0x1FU<<27)
#define ADC2_OFR3_OFFSET_CH_0       (0x1U<<27)

// OFR4 Configuration

#define ADC2_OFR4_OFFSET            (0xFFFFFFU<<0)
#define ADC2_OFR4_OFFSET_0          (0x1U<<0)
#define ADC2_OFR4_POSOFF            (0x1U<<24)
#define ADC2_OFR4_USAT              (0x1U<<25)
#define ADC2_OFR4_SSAT              (0x1U<<26)
#define ADC2_OFR4_OFFSET_CH         (0x1FU<<27)
#define ADC2_OFR4_OFFSET_CH_0       (0x1U<<27)

// GCOMP Configuration

#define ADC2_GCOMP_GCOMPCOEFF       (0x3FFFU<<0)
#define ADC2_GCOMP_GCOMPCOEFF_0     (0x1U<<0)
#define ADC2_GCOMP_GCOMP            (0x1U<<31)

// JDR1 Configuration

#define ADC2_JDR1_JDATA             (0xFFFFFFFFU<<0)
#define ADC2_JDR1_JDATA_0           (0x1U<<0)

// JDR2 Configuration

#define ADC2_JDR2_JDATA             (0xFFFFFFFFU<<0)
#define ADC2_JDR2_JDATA_0           (0x1U<<0)

// JDR3 Configuration

#define ADC2_JDR3_JDATA             (0xFFFFFFFFU<<0)
#define ADC2_JDR3_JDATA_0           (0x1U<<0)

// JDR4 Configuration

#define ADC2_JDR4_JDATA             (0xFFFFFFFFU<<0)
#define ADC2_JDR4_JDATA_0           (0x1U<<0)

// AWD2CR Configuration

#define ADC2_AWD2CR_AWD2CH          (0xFFFFFU<<0)
#define ADC2_AWD2CR_AWD2CH_0        (0x1U<<0)

// AWD3CR Configuration

#define ADC2_AWD3CR_AWD3CH          (0xFFFFFU<<0)
#define ADC2_AWD3CR_AWD3CH_0        (0x1U<<0)

// LTR1 Configuration

#define ADC2_LTR1_LTR1              (0x1FFFFFFU<<0)
#define ADC2_LTR1_LTR1_0            (0x1U<<0)

// HTR1 Configuration

#define ADC2_HTR1_HTR1              (0x1FFFFFFU<<0)
#define ADC2_HTR1_HTR1_0            (0x1U<<0)
#define ADC2_HTR1_AWDFILT1          (0x7U<<29)
#define ADC2_HTR1_AWDFILT1_0        (0x1U<<29)

// LTR2 Configuration

#define ADC2_LTR2_LTR2              (0x1FFFFFFU<<0)
#define ADC2_LTR2_LTR2_0            (0x1U<<0)

// HTR2 Configuration

#define ADC2_HTR2_HTR2              (0x1FFFFFFU<<0)
#define ADC2_HTR2_HTR2_0            (0x1U<<0)

// LTR3 Configuration

#define ADC2_LTR3_LTR3              (0x1FFFFFFU<<0)
#define ADC2_LTR3_LTR3_0            (0x1U<<0)

// HTR3 Configuration

#define ADC2_HTR3_HTR3              (0x1FFFFFFU<<0)
#define ADC2_HTR3_HTR3_0            (0x1U<<0)

// DIFSEL Configuration

#define ADC2_DIFSEL_DIFSEL          (0xFFFFFU<<0)
#define ADC2_DIFSEL_DIFSEL_0        (0x1U<<0)

// CALFACT Configuration

#define ADC2_CALFACT_I_APB_ADDR     (0xFFU<<0)
#define ADC2_CALFACT_I_APB_ADDR_0   (0x1U<<0)
#define ADC2_CALFACT_I_APB_DATA     (0xFFU<<8)
#define ADC2_CALFACT_I_APB_DATA_0   (0x1U<<8)
#define ADC2_CALFACT_VALIDITY       (0x1U<<16)
#define ADC2_CALFACT_LATCH_COEF     (0x1U<<24)
#define ADC2_CALFACT_CAPTURE_COEF   (0x1U<<25)

// CALFACT2 Configuration

#define ADC2_CALFACT2_CALFACT       (0xFFFFFFFFU<<0)
#define ADC2_CALFACT2_CALFACT_0     (0x1U<<0)
