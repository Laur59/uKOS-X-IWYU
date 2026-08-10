/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_adc3 equates.
 */

#pragma once

#include    <stdint.h>

// ADC3 address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    SR;
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    SMPR1;
    volatile    uint32_t    SMPR2;
    volatile    uint32_t    JOFR1;
    volatile    uint32_t    JOFR2;
    volatile    uint32_t    JOFR3;
    volatile    uint32_t    JOFR4;
    volatile    uint32_t    HTR;
    volatile    uint32_t    LTR;
    volatile    uint32_t    SQR1;
    volatile    uint32_t    SQR2;
    volatile    uint32_t    SQR3;
    volatile    uint32_t    JSQR;
    volatile    uint32_t    JDR1;
    volatile    uint32_t    JDR2;
    volatile    uint32_t    JDR3;
    volatile    uint32_t    JDR4;
    volatile    uint32_t    DR;
} ADC3_TypeDef;

#ifdef __cplusplus
#define ADC3    reinterpret_cast<ADC3_TypeDef *>(0x40012200U)

#else
#define ADC3    ((ADC3_TypeDef *)0x40012200U)
#endif

// SR Configuration

#define ADC3_SR_AWD             (0x1U<<0U)
#define ADC3_SR_EOC             (0x1U<<1U)
#define ADC3_SR_JEOC            (0x1U<<2U)
#define ADC3_SR_JSTRT           (0x1U<<3U)
#define ADC3_SR_STRT            (0x1U<<4U)
#define ADC3_SR_OVR             (0x1U<<5U)

// CR1 Configuration

#define ADC3_CR1_AWDCH          (0x1FU<<0U)
#define ADC3_CR1_AWDCH_0        (0x1U<<0U)
#define ADC3_CR1_EOCIE          (0x1U<<5U)
#define ADC3_CR1_AWDIE          (0x1U<<6U)
#define ADC3_CR1_JEOCIE         (0x1U<<7U)
#define ADC3_CR1_SCAN           (0x1U<<8U)
#define ADC3_CR1_AWDSGL         (0x1U<<9U)
#define ADC3_CR1_JAUTO          (0x1U<<10U)
#define ADC3_CR1_DISCEN         (0x1U<<11U)
#define ADC3_CR1_JDISCEN        (0x1U<<12U)
#define ADC3_CR1_DISCNUM        (0x7U<<13U)
#define ADC3_CR1_DISCNUM_0      (0x1U<<13U)
#define ADC3_CR1_JAWDEN         (0x1U<<22U)
#define ADC3_CR1_AWDEN          (0x1U<<23U)
#define ADC3_CR1_RES            (0x3U<<24U)
#define ADC3_CR1_RES_0          (0x1U<<24U)
#define ADC3_CR1_OVRIE          (0x1U<<26U)

// CR2 Configuration

#define ADC3_CR2_ADON           (0x1U<<0U)
#define ADC3_CR2_CONT           (0x1U<<1U)
#define ADC3_CR2_DMA            (0x1U<<8U)
#define ADC3_CR2_DDS            (0x1U<<9U)
#define ADC3_CR2_EOCS           (0x1U<<10U)
#define ADC3_CR2_ALIGN          (0x1U<<11U)
#define ADC3_CR2_JEXTSEL        (0xFU<<16U)
#define ADC3_CR2_JEXTSEL_0      (0x1U<<16U)
#define ADC3_CR2_JEXTEN         (0x3U<<20U)
#define ADC3_CR2_JEXTEN_0       (0x1U<<20U)
#define ADC3_CR2_JSWSTART       (0x1U<<22U)
#define ADC3_CR2_EXTSEL         (0xFU<<24U)
#define ADC3_CR2_EXTSEL_0       (0x1U<<24U)
#define ADC3_CR2_EXTEN          (0x3U<<28U)
#define ADC3_CR2_EXTEN_0        (0x1U<<28U)
#define ADC3_CR2_SWSTART        (0x1U<<30U)

// SMPR1 Configuration

#define ADC3_SMPR1_SMP18        (0x7U<<24U)
#define ADC3_SMPR1_SMP18_0      (0x1U<<24U)
#define ADC3_SMPR1_SMP17        (0x7U<<21U)
#define ADC3_SMPR1_SMP17_0      (0x1U<<21U)
#define ADC3_SMPR1_SMP16        (0x7U<<18U)
#define ADC3_SMPR1_SMP16_0      (0x1U<<18U)
#define ADC3_SMPR1_SMP15        (0x7U<<15U)
#define ADC3_SMPR1_SMP15_0      (0x1U<<15U)
#define ADC3_SMPR1_SMP14        (0x7U<<12U)
#define ADC3_SMPR1_SMP14_0      (0x1U<<12U)
#define ADC3_SMPR1_SMP13        (0x7U<<9U)
#define ADC3_SMPR1_SMP13_0      (0x1U<<9U)
#define ADC3_SMPR1_SMP12        (0x7U<<6U)
#define ADC3_SMPR1_SMP12_0      (0x1U<<6U)
#define ADC3_SMPR1_SMP11        (0x7U<<3U)
#define ADC3_SMPR1_SMP11_0      (0x1U<<3U)
#define ADC3_SMPR1_SMP10        (0x7U<<0U)
#define ADC3_SMPR1_SMP10_0      (0x1U<<0U)

// SMPR2 Configuration

#define ADC3_SMPR2_SMP9         (0x7U<<27U)
#define ADC3_SMPR2_SMP9_0       (0x1U<<27U)
#define ADC3_SMPR2_SMP8         (0x7U<<24U)
#define ADC3_SMPR2_SMP8_0       (0x1U<<24U)
#define ADC3_SMPR2_SMP7         (0x7U<<21U)
#define ADC3_SMPR2_SMP7_0       (0x1U<<21U)
#define ADC3_SMPR2_SMP6         (0x7U<<18U)
#define ADC3_SMPR2_SMP6_0       (0x1U<<18U)
#define ADC3_SMPR2_SMP5         (0x7U<<15U)
#define ADC3_SMPR2_SMP5_0       (0x1U<<15U)
#define ADC3_SMPR2_SMP4         (0x7U<<12U)
#define ADC3_SMPR2_SMP4_0       (0x1U<<12U)
#define ADC3_SMPR2_SMP3         (0x7U<<9U)
#define ADC3_SMPR2_SMP3_0       (0x1U<<9U)
#define ADC3_SMPR2_SMP2         (0x7U<<6U)
#define ADC3_SMPR2_SMP2_0       (0x1U<<6U)
#define ADC3_SMPR2_SMP1         (0x7U<<3U)
#define ADC3_SMPR2_SMP1_0       (0x1U<<3U)
#define ADC3_SMPR2_SMP0         (0x7U<<0U)
#define ADC3_SMPR2_SMP0_0       (0x1U<<0U)

// JOFR1 Configuration

#define ADC3_JOFR1_JOFFSET1     (0xFFFU<<0U)
#define ADC3_JOFR1_JOFFSET1_0   (0x1U<<0U)

// JOFR2 Configuration

#define ADC3_JOFR2_JOFFSET2     (0xFFFU<<0U)
#define ADC3_JOFR2_JOFFSET2_0   (0x1U<<0U)

// JOFR3 Configuration

#define ADC3_JOFR3_JOFFSET3     (0xFFFU<<0U)
#define ADC3_JOFR3_JOFFSET3_0   (0x1U<<0U)

// JOFR4 Configuration

#define ADC3_JOFR4_JOFFSET4     (0xFFFU<<0U)
#define ADC3_JOFR4_JOFFSET4_0   (0x1U<<0U)

// HTR Configuration

#define ADC3_HTR_HT             (0xFFFU<<0U)
#define ADC3_HTR_HT_0           (0x1U<<0U)

// LTR Configuration

#define ADC3_LTR_LT             (0xFFFU<<0U)
#define ADC3_LTR_LT_0           (0x1U<<0U)

// SQR1 Configuration

#define ADC3_SQR1_SQ13          (0x1FU<<0U)
#define ADC3_SQR1_SQ13_0        (0x1U<<0U)
#define ADC3_SQR1_SQ14          (0x1FU<<5U)
#define ADC3_SQR1_SQ14_0        (0x1U<<5U)
#define ADC3_SQR1_SQ15          (0x1FU<<10U)
#define ADC3_SQR1_SQ15_0        (0x1U<<10U)
#define ADC3_SQR1_SQ16          (0x1FU<<15U)
#define ADC3_SQR1_SQ16_0        (0x1U<<15U)
#define ADC3_SQR1_L             (0xFU<<20U)
#define ADC3_SQR1_L_0           (0x1U<<20U)

// SQR2 Configuration

#define ADC3_SQR2_SQ7           (0x1FU<<0U)
#define ADC3_SQR2_SQ7_0         (0x1U<<0U)
#define ADC3_SQR2_SQ8           (0x1FU<<5U)
#define ADC3_SQR2_SQ8_0         (0x1U<<5U)
#define ADC3_SQR2_SQ9           (0x1FU<<10U)
#define ADC3_SQR2_SQ9_0         (0x1U<<10U)
#define ADC3_SQR2_SQ10          (0x1FU<<15U)
#define ADC3_SQR2_SQ10_0        (0x1U<<15U)
#define ADC3_SQR2_SQ11          (0x1FU<<20U)
#define ADC3_SQR2_SQ11_0        (0x1U<<20U)
#define ADC3_SQR2_SQ12          (0x1FU<<25U)
#define ADC3_SQR2_SQ12_0        (0x1U<<25U)

// SQR3 Configuration

#define ADC3_SQR3_SQ1           (0x1FU<<0U)
#define ADC3_SQR3_SQ1_0         (0x1U<<0U)
#define ADC3_SQR3_SQ2           (0x1FU<<5U)
#define ADC3_SQR3_SQ2_0         (0x1U<<5U)
#define ADC3_SQR3_SQ3           (0x1FU<<10U)
#define ADC3_SQR3_SQ3_0         (0x1U<<10U)
#define ADC3_SQR3_SQ4           (0x1FU<<15U)
#define ADC3_SQR3_SQ4_0         (0x1U<<15U)
#define ADC3_SQR3_SQ5           (0x1FU<<20U)
#define ADC3_SQR3_SQ5_0         (0x1U<<20U)
#define ADC3_SQR3_SQ6           (0x1FU<<25U)
#define ADC3_SQR3_SQ6_0         (0x1U<<25U)

// JSQR Configuration

#define ADC3_JSQR_JSQ1          (0x1FU<<0U)
#define ADC3_JSQR_JSQ1_0        (0x1U<<0U)
#define ADC3_JSQR_JSQ2          (0x1FU<<5U)
#define ADC3_JSQR_JSQ2_0        (0x1U<<5U)
#define ADC3_JSQR_JSQ3          (0x1FU<<10U)
#define ADC3_JSQR_JSQ3_0        (0x1U<<10U)
#define ADC3_JSQR_JSQ4          (0x1FU<<15U)
#define ADC3_JSQR_JSQ4_0        (0x1U<<15U)
#define ADC3_JSQR_JL            (0x3U<<20U)
#define ADC3_JSQR_JL_0          (0x1U<<20U)

// JDR1 Configuration

#define ADC3_JDR1_JDATA         (0xFFFFU<<0U)
#define ADC3_JDR1_JDATA_0       (0x1U<<0U)

// JDR2 Configuration

#define ADC3_JDR2_JDATA         (0xFFFFU<<0U)
#define ADC3_JDR2_JDATA_0       (0x1U<<0U)

// JDR3 Configuration

#define ADC3_JDR3_JDATA         (0xFFFFU<<0U)
#define ADC3_JDR3_JDATA_0       (0x1U<<0U)

// JDR4 Configuration

#define ADC3_JDR4_JDATA         (0xFFFFU<<0U)
#define ADC3_JDR4_JDATA_0       (0x1U<<0U)

// DR Configuration

#define ADC3_DR_DATA            (0xFFFFU<<0U)
#define ADC3_DR_DATA_0          (0x1U<<0U)
