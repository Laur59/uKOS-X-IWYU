/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_adc equates.
 */

#pragma once

#include    <stdint.h>

// ADC address definitions
// -----------------------

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
    volatile    uint32_t    OFCFGR1;
    volatile    uint32_t    OFCFGR2;
    volatile    uint32_t    OFCFGR3;
    volatile    uint32_t    OFCFGR4;
    volatile    uint32_t    OFR1;
    volatile    uint32_t    OFR2;
    volatile    uint32_t    OFR3;
    volatile    uint32_t    OFR4;
    volatile    uint32_t    GCOMP;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    JDR1;
    volatile    uint32_t    JDR2;
    volatile    uint32_t    JDR3;
    volatile    uint32_t    JDR4;
    volatile    uint32_t    RESERVED3[4];
    volatile    uint32_t    AWD2CR;
    volatile    uint32_t    AWD3CR;
    volatile    uint32_t    AWD1LTR;
    volatile    uint32_t    AWD1HTR;
    volatile    uint32_t    AWD2LTR;
    volatile    uint32_t    AWD2HTR;
    volatile    uint32_t    AWD3LTR;
    volatile    uint32_t    AWD3HTR;
    volatile    uint32_t    DIFSEL;
    volatile    uint32_t    CALFACT;
    volatile    uint32_t    RESERVED4[2];
    volatile    uint32_t    OR;
} ADC_TypeDef;

#ifdef __cplusplus
#define ADC1_NS reinterpret_cast<ADC_TypeDef *>(0x40022000U)
#define ADC1_S  reinterpret_cast<ADC_TypeDef *>(0x50022000U)
#define ADC2_NS reinterpret_cast<ADC_TypeDef *>(0x40022100U)
#define ADC2_S  reinterpret_cast<ADC_TypeDef *>(0x50022100U)

#else
#define ADC1_NS ((ADC_TypeDef *)0x40022000U)
#define ADC1_S  ((ADC_TypeDef *)0x50022000U)
#define ADC2_NS ((ADC_TypeDef *)0x40022100U)
#define ADC2_S  ((ADC_TypeDef *)0x50022100U)
#endif

// ISR Configuration

#define ADC_ISR_JQOVF                   (0x1U<<10U)
#define ADC_ISR_AWD3                    (0x1U<<9U)
#define ADC_ISR_AWD2                    (0x1U<<8U)
#define ADC_ISR_AWD1                    (0x1U<<7U)
#define ADC_ISR_JEOS                    (0x1U<<6U)
#define ADC_ISR_JEOC                    (0x1U<<5U)
#define ADC_ISR_OVR                     (0x1U<<4U)
#define ADC_ISR_EOS                     (0x1U<<3U)
#define ADC_ISR_EOC                     (0x1U<<2U)
#define ADC_ISR_EOSMP                   (0x1U<<1U)
#define ADC_ISR_ADRDY                   (0x1U<<0U)

#define ADC_ISR_JQOVF_B_0X0             (0x0U<<10U)
#define ADC_ISR_JQOVF_B_0X1             (0x1U<<10U)
#define ADC_ISR_AWD3_B_0X0              (0x0U<<9U)
#define ADC_ISR_AWD3_B_0X1              (0x1U<<9U)
#define ADC_ISR_AWD2_B_0X0              (0x0U<<8U)
#define ADC_ISR_AWD2_B_0X1              (0x1U<<8U)
#define ADC_ISR_AWD1_B_0X0              (0x0U<<7U)
#define ADC_ISR_AWD1_B_0X1              (0x1U<<7U)
#define ADC_ISR_JEOS_B_0X0              (0x0U<<6U)
#define ADC_ISR_JEOS_B_0X1              (0x1U<<6U)
#define ADC_ISR_JEOC_B_0X0              (0x0U<<5U)
#define ADC_ISR_JEOC_B_0X1              (0x1U<<5U)
#define ADC_ISR_OVR_B_0X0               (0x0U<<4U)
#define ADC_ISR_OVR_B_0X1               (0x1U<<4U)
#define ADC_ISR_EOS_B_0X0               (0x0U<<3U)
#define ADC_ISR_EOS_B_0X1               (0x1U<<3U)
#define ADC_ISR_EOC_B_0X0               (0x0U<<2U)
#define ADC_ISR_EOC_B_0X1               (0x1U<<2U)
#define ADC_ISR_EOSMP_B_0X0             (0x0U<<1U)
#define ADC_ISR_EOSMP_B_0X1             (0x1U<<1U)
#define ADC_ISR_ADRDY_B_0X0             (0x0U<<0U)
#define ADC_ISR_ADRDY_B_0X1             (0x1U<<0U)

// IER Configuration

#define ADC_IER_JQOVFIE                 (0x1U<<10U)
#define ADC_IER_AWD3IE                  (0x1U<<9U)
#define ADC_IER_AWD2IE                  (0x1U<<8U)
#define ADC_IER_AWD1IE                  (0x1U<<7U)
#define ADC_IER_JEOSIE                  (0x1U<<6U)
#define ADC_IER_JEOCIE                  (0x1U<<5U)
#define ADC_IER_OVRIE                   (0x1U<<4U)
#define ADC_IER_EOSIE                   (0x1U<<3U)
#define ADC_IER_EOCIE                   (0x1U<<2U)
#define ADC_IER_EOSMPIE                 (0x1U<<1U)
#define ADC_IER_ADRDYIE                 (0x1U<<0U)

#define ADC_IER_JQOVFIE_B_0X0           (0x0U<<10U)
#define ADC_IER_JQOVFIE_B_0X1           (0x1U<<10U)
#define ADC_IER_AWD3IE_B_0X0            (0x0U<<9U)
#define ADC_IER_AWD3IE_B_0X1            (0x1U<<9U)
#define ADC_IER_AWD2IE_B_0X0            (0x0U<<8U)
#define ADC_IER_AWD2IE_B_0X1            (0x1U<<8U)
#define ADC_IER_AWD1IE_B_0X0            (0x0U<<7U)
#define ADC_IER_AWD1IE_B_0X1            (0x1U<<7U)
#define ADC_IER_JEOSIE_B_0X0            (0x0U<<6U)
#define ADC_IER_JEOSIE_B_0X1            (0x1U<<6U)
#define ADC_IER_JEOCIE_B_0X0            (0x0U<<5U)
#define ADC_IER_JEOCIE_B_0X1            (0x1U<<5U)
#define ADC_IER_OVRIE_B_0X0             (0x0U<<4U)
#define ADC_IER_OVRIE_B_0X1             (0x1U<<4U)
#define ADC_IER_EOSIE_B_0X0             (0x0U<<3U)
#define ADC_IER_EOSIE_B_0X1             (0x1U<<3U)
#define ADC_IER_EOCIE_B_0X0             (0x0U<<2U)
#define ADC_IER_EOCIE_B_0X1             (0x1U<<2U)
#define ADC_IER_EOSMPIE_B_0X0           (0x0U<<1U)
#define ADC_IER_EOSMPIE_B_0X1           (0x1U<<1U)
#define ADC_IER_ADRDYIE_B_0X0           (0x0U<<0U)
#define ADC_IER_ADRDYIE_B_0X1           (0x1U<<0U)

// CR Configuration

#define ADC_CR_ADCAL                    (0x1U<<31U)
#define ADC_CR_ADCALDIF                 (0x1U<<30U)
#define ADC_CR_DEEPPWD                  (0x1U<<29U)
#define ADC_CR_JADSTP                   (0x1U<<5U)
#define ADC_CR_ADSTP                    (0x1U<<4U)
#define ADC_CR_JADSTART                 (0x1U<<3U)
#define ADC_CR_ADSTART                  (0x1U<<2U)
#define ADC_CR_ADDIS                    (0x1U<<1U)
#define ADC_CR_ADEN                     (0x1U<<0U)

#define ADC_CR_ADCAL_B_0X0              (0x0U<<31U)
#define ADC_CR_ADCAL_B_0X1              (0x1U<<31U)
#define ADC_CR_ADCALDIF_B_0X0           (0x0U<<30U)
#define ADC_CR_ADCALDIF_B_0X1           (0x1U<<30U)
#define ADC_CR_DEEPPWD_B_0X0            (0x0U<<29U)
#define ADC_CR_DEEPPWD_B_0X1            (0x1U<<29U)
#define ADC_CR_JADSTP_B_0X0             (0x0U<<5U)
#define ADC_CR_JADSTP_B_0X1             (0x1U<<5U)
#define ADC_CR_ADSTP_B_0X0              (0x0U<<4U)
#define ADC_CR_ADSTP_B_0X1              (0x1U<<4U)
#define ADC_CR_JADSTART_B_0X0           (0x0U<<3U)
#define ADC_CR_JADSTART_B_0X1           (0x1U<<3U)
#define ADC_CR_ADSTART_B_0X0            (0x0U<<2U)
#define ADC_CR_ADSTART_B_0X1            (0x1U<<2U)
#define ADC_CR_ADDIS_B_0X0              (0x0U<<1U)
#define ADC_CR_ADDIS_B_0X1              (0x1U<<1U)
#define ADC_CR_ADEN_B_0X0               (0x0U<<0U)
#define ADC_CR_ADEN_B_0X1               (0x1U<<0U)

// CFGR1 Configuration

#define ADC_CFGR1_JQDIS                 (0x1U<<31U)
#define ADC_CFGR1_AWD1CH                (0x1FU<<26U)
#define ADC_CFGR1_AWD1CH_0              (0x1U<<26U)
#define ADC_CFGR1_JAUTO                 (0x1U<<25U)
#define ADC_CFGR1_JAWD1EN               (0x1U<<24U)
#define ADC_CFGR1_AWD1EN                (0x1U<<23U)
#define ADC_CFGR1_AWD1SGL               (0x1U<<22U)
#define ADC_CFGR1_JQM                   (0x1U<<21U)
#define ADC_CFGR1_JDISCEN               (0x1U<<20U)
#define ADC_CFGR1_DISCNUM               (0x7U<<17U)
#define ADC_CFGR1_DISCNUM_0             (0x1U<<17U)
#define ADC_CFGR1_DISCEN                (0x1U<<16U)
#define ADC_CFGR1_AUTDLY                (0x1U<<14U)
#define ADC_CFGR1_CONT                  (0x1U<<13U)
#define ADC_CFGR1_OVRMOD                (0x1U<<12U)
#define ADC_CFGR1_EXTEN                 (0x3U<<10U)
#define ADC_CFGR1_EXTEN_0               (0x1U<<10U)
#define ADC_CFGR1_EXTSEL                (0x1FU<<5U)
#define ADC_CFGR1_EXTSEL_0              (0x1U<<5U)
#define ADC_CFGR1_RES                   (0x3U<<2U)
#define ADC_CFGR1_RES_0                 (0x1U<<2U)
#define ADC_CFGR1_DMNGT                 (0x3U<<0U)
#define ADC_CFGR1_DMNGT_0               (0x1U<<0U)

#define ADC_CFGR1_JQDIS_B_0X0           (0x0U<<31U)
#define ADC_CFGR1_JQDIS_B_0X1           (0x1U<<31U)
#define ADC_CFGR1_AWD1CH_B_0X0          (0x0U<<26U)
#define ADC_CFGR1_AWD1CH_B_0X1          (0x1U<<26U)
#define ADC_CFGR1_AWD1CH_B_0X13         (0x13U<<26U)
#define ADC_CFGR1_JAUTO_B_0X0           (0x0U<<25U)
#define ADC_CFGR1_JAUTO_B_0X1           (0x1U<<25U)
#define ADC_CFGR1_JAWD1EN_B_0X0         (0x0U<<24U)
#define ADC_CFGR1_JAWD1EN_B_0X1         (0x1U<<24U)
#define ADC_CFGR1_AWD1EN_B_0X0          (0x0U<<23U)
#define ADC_CFGR1_AWD1EN_B_0X1          (0x1U<<23U)
#define ADC_CFGR1_AWD1SGL_B_0X0         (0x0U<<22U)
#define ADC_CFGR1_AWD1SGL_B_0X1         (0x1U<<22U)
#define ADC_CFGR1_JQM_B_0X0             (0x0U<<21U)
#define ADC_CFGR1_JQM_B_0X1             (0x1U<<21U)
#define ADC_CFGR1_JDISCEN_B_0X0         (0x0U<<20U)
#define ADC_CFGR1_JDISCEN_B_0X1         (0x1U<<20U)
#define ADC_CFGR1_DISCNUM_B_0X0         (0x0U<<17U)
#define ADC_CFGR1_DISCNUM_B_0X1         (0x1U<<17U)
#define ADC_CFGR1_DISCNUM_B_0X7         (0x7U<<17U)
#define ADC_CFGR1_DISCEN_B_0X0          (0x0U<<16U)
#define ADC_CFGR1_DISCEN_B_0X1          (0x1U<<16U)
#define ADC_CFGR1_AUTDLY_B_0X0          (0x0U<<14U)
#define ADC_CFGR1_AUTDLY_B_0X1          (0x1U<<14U)
#define ADC_CFGR1_CONT_B_0X0            (0x0U<<13U)
#define ADC_CFGR1_CONT_B_0X1            (0x1U<<13U)
#define ADC_CFGR1_OVRMOD_B_0X0          (0x0U<<12U)
#define ADC_CFGR1_OVRMOD_B_0X1          (0x1U<<12U)
#define ADC_CFGR1_EXTEN_B_0X0           (0x0U<<10U)
#define ADC_CFGR1_EXTEN_B_0X1           (0x1U<<10U)
#define ADC_CFGR1_EXTEN_B_0X2           (0x2U<<10U)
#define ADC_CFGR1_EXTEN_B_0X3           (0x3U<<10U)
#define ADC_CFGR1_EXTSEL_B_0X0          (0x0U<<5U)
#define ADC_CFGR1_EXTSEL_B_0X1          (0x1U<<5U)
#define ADC_CFGR1_EXTSEL_B_0X2          (0x2U<<5U)
#define ADC_CFGR1_EXTSEL_B_0X3          (0x3U<<5U)
#define ADC_CFGR1_EXTSEL_B_0X4          (0x4U<<5U)
#define ADC_CFGR1_EXTSEL_B_0X5          (0x5U<<5U)
#define ADC_CFGR1_EXTSEL_B_0X6          (0x6U<<5U)
#define ADC_CFGR1_EXTSEL_B_0X7          (0x7U<<5U)
#define ADC_CFGR1_EXTSEL_B_0X1F         (0x1FU<<5U)
#define ADC_CFGR1_RES_B_0X0             (0x0U<<2U)
#define ADC_CFGR1_RES_B_0X1             (0x1U<<2U)
#define ADC_CFGR1_RES_B_0X2             (0x2U<<2U)
#define ADC_CFGR1_RES_B_0X3             (0x3U<<2U)
#define ADC_CFGR1_DMNGT_B_0X0           (0x0U<<0U)
#define ADC_CFGR1_DMNGT_B_0X1           (0x1U<<0U)
#define ADC_CFGR1_DMNGT_B_0X2           (0x2U<<0U)
#define ADC_CFGR1_DMNGT_B_0X3           (0x3U<<0U)

// CFGR2 Configuration

#define ADC_CFGR2_LSHIFT                (0xFU<<28U)
#define ADC_CFGR2_LSHIFT_0              (0x1U<<28U)
#define ADC_CFGR2_OSR                   (0x3FFU<<16U)
#define ADC_CFGR2_OSR_0                 (0x1U<<16U)
#define ADC_CFGR2_SMPTRIG               (0x1U<<15U)
#define ADC_CFGR2_SWTRIG                (0x1U<<14U)
#define ADC_CFGR2_BULB                  (0x1U<<13U)
#define ADC_CFGR2_ROVSM                 (0x1U<<10U)
#define ADC_CFGR2_TROVS                 (0x1U<<9U)
#define ADC_CFGR2_OVSS                  (0xFU<<5U)
#define ADC_CFGR2_OVSS_0                (0x1U<<5U)
#define ADC_CFGR2_JOVSE                 (0x1U<<1U)
#define ADC_CFGR2_ROVSE                 (0x1U<<0U)

#define ADC_CFGR2_LSHIFT_B_0X0          (0x0U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X1          (0x1U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X2          (0x2U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X3          (0x3U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X4          (0x4U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X5          (0x5U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X6          (0x6U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X7          (0x7U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X8          (0x8U<<28U)
#define ADC_CFGR2_LSHIFT_B_0X9          (0x9U<<28U)
#define ADC_CFGR2_LSHIFT_B_0XA          (0xAU<<28U)
#define ADC_CFGR2_LSHIFT_B_0XB          (0xBU<<28U)
#define ADC_CFGR2_LSHIFT_B_0XC          (0xCU<<28U)
#define ADC_CFGR2_LSHIFT_B_0XD          (0xDU<<28U)
#define ADC_CFGR2_LSHIFT_B_0XE          (0xEU<<28U)
#define ADC_CFGR2_LSHIFT_B_0XF          (0xFU<<28U)
#define ADC_CFGR2_OSR_B_0X0             (0x0U<<16U)
#define ADC_CFGR2_OSR_B_0X1             (0x1U<<16U)
#define ADC_CFGR2_SMPTRIG_B_0X0         (0x0U<<15U)
#define ADC_CFGR2_SMPTRIG_B_0X1         (0x1U<<15U)
#define ADC_CFGR2_SWTRIG_B_0X0          (0x0U<<14U)
#define ADC_CFGR2_SWTRIG_B_0X1          (0x1U<<14U)
#define ADC_CFGR2_BULB_B_0X0            (0x0U<<13U)
#define ADC_CFGR2_BULB_B_0X1            (0x1U<<13U)
#define ADC_CFGR2_ROVSM_B_0X0           (0x0U<<10U)
#define ADC_CFGR2_ROVSM_B_0X1           (0x1U<<10U)
#define ADC_CFGR2_TROVS_B_0X0           (0x0U<<9U)
#define ADC_CFGR2_TROVS_B_0X1           (0x1U<<9U)
#define ADC_CFGR2_OVSS_B_0X0            (0x0U<<5U)
#define ADC_CFGR2_OVSS_B_0X1            (0x1U<<5U)
#define ADC_CFGR2_OVSS_B_0X2            (0x2U<<5U)
#define ADC_CFGR2_OVSS_B_0X3            (0x3U<<5U)
#define ADC_CFGR2_OVSS_B_0X4            (0x4U<<5U)
#define ADC_CFGR2_OVSS_B_0X5            (0x5U<<5U)
#define ADC_CFGR2_OVSS_B_0X6            (0x6U<<5U)
#define ADC_CFGR2_OVSS_B_0X7            (0x7U<<5U)
#define ADC_CFGR2_OVSS_B_0X8            (0x8U<<5U)
#define ADC_CFGR2_OVSS_B_0X9            (0x9U<<5U)
#define ADC_CFGR2_OVSS_B_0XA            (0xAU<<5U)
#define ADC_CFGR2_JOVSE_B_0X0           (0x0U<<1U)
#define ADC_CFGR2_JOVSE_B_0X1           (0x1U<<1U)
#define ADC_CFGR2_ROVSE_B_0X0           (0x0U<<0U)
#define ADC_CFGR2_ROVSE_B_0X1           (0x1U<<0U)

// SMPR1 Configuration

#define ADC_SMPR1_SMP9                  (0x7U<<27U)
#define ADC_SMPR1_SMP9_0                (0x1U<<27U)
#define ADC_SMPR1_SMP8                  (0x7U<<24U)
#define ADC_SMPR1_SMP8_0                (0x1U<<24U)
#define ADC_SMPR1_SMP7                  (0x7U<<21U)
#define ADC_SMPR1_SMP7_0                (0x1U<<21U)
#define ADC_SMPR1_SMP6                  (0x7U<<18U)
#define ADC_SMPR1_SMP6_0                (0x1U<<18U)
#define ADC_SMPR1_SMP5                  (0x7U<<15U)
#define ADC_SMPR1_SMP5_0                (0x1U<<15U)
#define ADC_SMPR1_SMP4                  (0x7U<<12U)
#define ADC_SMPR1_SMP4_0                (0x1U<<12U)
#define ADC_SMPR1_SMP3                  (0x7U<<9U)
#define ADC_SMPR1_SMP3_0                (0x1U<<9U)
#define ADC_SMPR1_SMP2                  (0x7U<<6U)
#define ADC_SMPR1_SMP2_0                (0x1U<<6U)
#define ADC_SMPR1_SMP1                  (0x7U<<3U)
#define ADC_SMPR1_SMP1_0                (0x1U<<3U)
#define ADC_SMPR1_SMP0                  (0x7U<<0U)
#define ADC_SMPR1_SMP0_0                (0x1U<<0U)

#define ADC_SMPR1_SMP9_B_0X0            (0x0U<<27U)
#define ADC_SMPR1_SMP9_B_0X1            (0x1U<<27U)
#define ADC_SMPR1_SMP9_B_0X2            (0x2U<<27U)
#define ADC_SMPR1_SMP9_B_0X3            (0x3U<<27U)
#define ADC_SMPR1_SMP9_B_0X4            (0x4U<<27U)
#define ADC_SMPR1_SMP9_B_0X5            (0x5U<<27U)
#define ADC_SMPR1_SMP9_B_0X6            (0x6U<<27U)
#define ADC_SMPR1_SMP9_B_0X7            (0x7U<<27U)
#define ADC_SMPR1_SMP8_B_0X0            (0x0U<<24U)
#define ADC_SMPR1_SMP8_B_0X1            (0x1U<<24U)
#define ADC_SMPR1_SMP8_B_0X2            (0x2U<<24U)
#define ADC_SMPR1_SMP8_B_0X3            (0x3U<<24U)
#define ADC_SMPR1_SMP8_B_0X4            (0x4U<<24U)
#define ADC_SMPR1_SMP8_B_0X5            (0x5U<<24U)
#define ADC_SMPR1_SMP8_B_0X6            (0x6U<<24U)
#define ADC_SMPR1_SMP8_B_0X7            (0x7U<<24U)
#define ADC_SMPR1_SMP7_B_0X0            (0x0U<<21U)
#define ADC_SMPR1_SMP7_B_0X1            (0x1U<<21U)
#define ADC_SMPR1_SMP7_B_0X2            (0x2U<<21U)
#define ADC_SMPR1_SMP7_B_0X3            (0x3U<<21U)
#define ADC_SMPR1_SMP7_B_0X4            (0x4U<<21U)
#define ADC_SMPR1_SMP7_B_0X5            (0x5U<<21U)
#define ADC_SMPR1_SMP7_B_0X6            (0x6U<<21U)
#define ADC_SMPR1_SMP7_B_0X7            (0x7U<<21U)
#define ADC_SMPR1_SMP6_B_0X0            (0x0U<<18U)
#define ADC_SMPR1_SMP6_B_0X1            (0x1U<<18U)
#define ADC_SMPR1_SMP6_B_0X2            (0x2U<<18U)
#define ADC_SMPR1_SMP6_B_0X3            (0x3U<<18U)
#define ADC_SMPR1_SMP6_B_0X4            (0x4U<<18U)
#define ADC_SMPR1_SMP6_B_0X5            (0x5U<<18U)
#define ADC_SMPR1_SMP6_B_0X6            (0x6U<<18U)
#define ADC_SMPR1_SMP6_B_0X7            (0x7U<<18U)
#define ADC_SMPR1_SMP5_B_0X0            (0x0U<<15U)
#define ADC_SMPR1_SMP5_B_0X1            (0x1U<<15U)
#define ADC_SMPR1_SMP5_B_0X2            (0x2U<<15U)
#define ADC_SMPR1_SMP5_B_0X3            (0x3U<<15U)
#define ADC_SMPR1_SMP5_B_0X4            (0x4U<<15U)
#define ADC_SMPR1_SMP5_B_0X5            (0x5U<<15U)
#define ADC_SMPR1_SMP5_B_0X6            (0x6U<<15U)
#define ADC_SMPR1_SMP5_B_0X7            (0x7U<<15U)
#define ADC_SMPR1_SMP4_B_0X0            (0x0U<<12U)
#define ADC_SMPR1_SMP4_B_0X1            (0x1U<<12U)
#define ADC_SMPR1_SMP4_B_0X2            (0x2U<<12U)
#define ADC_SMPR1_SMP4_B_0X3            (0x3U<<12U)
#define ADC_SMPR1_SMP4_B_0X4            (0x4U<<12U)
#define ADC_SMPR1_SMP4_B_0X5            (0x5U<<12U)
#define ADC_SMPR1_SMP4_B_0X6            (0x6U<<12U)
#define ADC_SMPR1_SMP4_B_0X7            (0x7U<<12U)
#define ADC_SMPR1_SMP3_B_0X0            (0x0U<<9U)
#define ADC_SMPR1_SMP3_B_0X1            (0x1U<<9U)
#define ADC_SMPR1_SMP3_B_0X2            (0x2U<<9U)
#define ADC_SMPR1_SMP3_B_0X3            (0x3U<<9U)
#define ADC_SMPR1_SMP3_B_0X4            (0x4U<<9U)
#define ADC_SMPR1_SMP3_B_0X5            (0x5U<<9U)
#define ADC_SMPR1_SMP3_B_0X6            (0x6U<<9U)
#define ADC_SMPR1_SMP3_B_0X7            (0x7U<<9U)
#define ADC_SMPR1_SMP2_B_0X0            (0x0U<<6U)
#define ADC_SMPR1_SMP2_B_0X1            (0x1U<<6U)
#define ADC_SMPR1_SMP2_B_0X2            (0x2U<<6U)
#define ADC_SMPR1_SMP2_B_0X3            (0x3U<<6U)
#define ADC_SMPR1_SMP2_B_0X4            (0x4U<<6U)
#define ADC_SMPR1_SMP2_B_0X5            (0x5U<<6U)
#define ADC_SMPR1_SMP2_B_0X6            (0x6U<<6U)
#define ADC_SMPR1_SMP2_B_0X7            (0x7U<<6U)
#define ADC_SMPR1_SMP1_B_0X0            (0x0U<<3U)
#define ADC_SMPR1_SMP1_B_0X1            (0x1U<<3U)
#define ADC_SMPR1_SMP1_B_0X2            (0x2U<<3U)
#define ADC_SMPR1_SMP1_B_0X3            (0x3U<<3U)
#define ADC_SMPR1_SMP1_B_0X4            (0x4U<<3U)
#define ADC_SMPR1_SMP1_B_0X5            (0x5U<<3U)
#define ADC_SMPR1_SMP1_B_0X6            (0x6U<<3U)
#define ADC_SMPR1_SMP1_B_0X7            (0x7U<<3U)
#define ADC_SMPR1_SMP0_B_0X0            (0x0U<<0U)
#define ADC_SMPR1_SMP0_B_0X1            (0x1U<<0U)
#define ADC_SMPR1_SMP0_B_0X2            (0x2U<<0U)
#define ADC_SMPR1_SMP0_B_0X3            (0x3U<<0U)
#define ADC_SMPR1_SMP0_B_0X4            (0x4U<<0U)
#define ADC_SMPR1_SMP0_B_0X5            (0x5U<<0U)
#define ADC_SMPR1_SMP0_B_0X6            (0x6U<<0U)
#define ADC_SMPR1_SMP0_B_0X7            (0x7U<<0U)

// SMPR2 Configuration

#define ADC_SMPR2_SMP19                 (0x7U<<27U)
#define ADC_SMPR2_SMP19_0               (0x1U<<27U)
#define ADC_SMPR2_SMP18                 (0x7U<<24U)
#define ADC_SMPR2_SMP18_0               (0x1U<<24U)
#define ADC_SMPR2_SMP17                 (0x7U<<21U)
#define ADC_SMPR2_SMP17_0               (0x1U<<21U)
#define ADC_SMPR2_SMP16                 (0x7U<<18U)
#define ADC_SMPR2_SMP16_0               (0x1U<<18U)
#define ADC_SMPR2_SMP15                 (0x7U<<15U)
#define ADC_SMPR2_SMP15_0               (0x1U<<15U)
#define ADC_SMPR2_SMP14                 (0x7U<<12U)
#define ADC_SMPR2_SMP14_0               (0x1U<<12U)
#define ADC_SMPR2_SMP13                 (0x7U<<9U)
#define ADC_SMPR2_SMP13_0               (0x1U<<9U)
#define ADC_SMPR2_SMP12                 (0x7U<<6U)
#define ADC_SMPR2_SMP12_0               (0x1U<<6U)
#define ADC_SMPR2_SMP11                 (0x7U<<3U)
#define ADC_SMPR2_SMP11_0               (0x1U<<3U)
#define ADC_SMPR2_SMP10                 (0x7U<<0U)
#define ADC_SMPR2_SMP10_0               (0x1U<<0U)

#define ADC_SMPR2_SMP19_B_0X0           (0x0U<<27U)
#define ADC_SMPR2_SMP19_B_0X1           (0x1U<<27U)
#define ADC_SMPR2_SMP19_B_0X2           (0x2U<<27U)
#define ADC_SMPR2_SMP19_B_0X3           (0x3U<<27U)
#define ADC_SMPR2_SMP19_B_0X4           (0x4U<<27U)
#define ADC_SMPR2_SMP19_B_0X5           (0x5U<<27U)
#define ADC_SMPR2_SMP19_B_0X6           (0x6U<<27U)
#define ADC_SMPR2_SMP19_B_0X7           (0x7U<<27U)
#define ADC_SMPR2_SMP18_B_0X0           (0x0U<<24U)
#define ADC_SMPR2_SMP18_B_0X1           (0x1U<<24U)
#define ADC_SMPR2_SMP18_B_0X2           (0x2U<<24U)
#define ADC_SMPR2_SMP18_B_0X3           (0x3U<<24U)
#define ADC_SMPR2_SMP18_B_0X4           (0x4U<<24U)
#define ADC_SMPR2_SMP18_B_0X5           (0x5U<<24U)
#define ADC_SMPR2_SMP18_B_0X6           (0x6U<<24U)
#define ADC_SMPR2_SMP18_B_0X7           (0x7U<<24U)
#define ADC_SMPR2_SMP17_B_0X0           (0x0U<<21U)
#define ADC_SMPR2_SMP17_B_0X1           (0x1U<<21U)
#define ADC_SMPR2_SMP17_B_0X2           (0x2U<<21U)
#define ADC_SMPR2_SMP17_B_0X3           (0x3U<<21U)
#define ADC_SMPR2_SMP17_B_0X4           (0x4U<<21U)
#define ADC_SMPR2_SMP17_B_0X5           (0x5U<<21U)
#define ADC_SMPR2_SMP17_B_0X6           (0x6U<<21U)
#define ADC_SMPR2_SMP17_B_0X7           (0x7U<<21U)
#define ADC_SMPR2_SMP16_B_0X0           (0x0U<<18U)
#define ADC_SMPR2_SMP16_B_0X1           (0x1U<<18U)
#define ADC_SMPR2_SMP16_B_0X2           (0x2U<<18U)
#define ADC_SMPR2_SMP16_B_0X3           (0x3U<<18U)
#define ADC_SMPR2_SMP16_B_0X4           (0x4U<<18U)
#define ADC_SMPR2_SMP16_B_0X5           (0x5U<<18U)
#define ADC_SMPR2_SMP16_B_0X6           (0x6U<<18U)
#define ADC_SMPR2_SMP16_B_0X7           (0x7U<<18U)
#define ADC_SMPR2_SMP15_B_0X0           (0x0U<<15U)
#define ADC_SMPR2_SMP15_B_0X1           (0x1U<<15U)
#define ADC_SMPR2_SMP15_B_0X2           (0x2U<<15U)
#define ADC_SMPR2_SMP15_B_0X3           (0x3U<<15U)
#define ADC_SMPR2_SMP15_B_0X4           (0x4U<<15U)
#define ADC_SMPR2_SMP15_B_0X5           (0x5U<<15U)
#define ADC_SMPR2_SMP15_B_0X6           (0x6U<<15U)
#define ADC_SMPR2_SMP15_B_0X7           (0x7U<<15U)
#define ADC_SMPR2_SMP14_B_0X0           (0x0U<<12U)
#define ADC_SMPR2_SMP14_B_0X1           (0x1U<<12U)
#define ADC_SMPR2_SMP14_B_0X2           (0x2U<<12U)
#define ADC_SMPR2_SMP14_B_0X3           (0x3U<<12U)
#define ADC_SMPR2_SMP14_B_0X4           (0x4U<<12U)
#define ADC_SMPR2_SMP14_B_0X5           (0x5U<<12U)
#define ADC_SMPR2_SMP14_B_0X6           (0x6U<<12U)
#define ADC_SMPR2_SMP14_B_0X7           (0x7U<<12U)
#define ADC_SMPR2_SMP13_B_0X0           (0x0U<<9U)
#define ADC_SMPR2_SMP13_B_0X1           (0x1U<<9U)
#define ADC_SMPR2_SMP13_B_0X2           (0x2U<<9U)
#define ADC_SMPR2_SMP13_B_0X3           (0x3U<<9U)
#define ADC_SMPR2_SMP13_B_0X4           (0x4U<<9U)
#define ADC_SMPR2_SMP13_B_0X5           (0x5U<<9U)
#define ADC_SMPR2_SMP13_B_0X6           (0x6U<<9U)
#define ADC_SMPR2_SMP13_B_0X7           (0x7U<<9U)
#define ADC_SMPR2_SMP12_B_0X0           (0x0U<<6U)
#define ADC_SMPR2_SMP12_B_0X1           (0x1U<<6U)
#define ADC_SMPR2_SMP12_B_0X2           (0x2U<<6U)
#define ADC_SMPR2_SMP12_B_0X3           (0x3U<<6U)
#define ADC_SMPR2_SMP12_B_0X4           (0x4U<<6U)
#define ADC_SMPR2_SMP12_B_0X5           (0x5U<<6U)
#define ADC_SMPR2_SMP12_B_0X6           (0x6U<<6U)
#define ADC_SMPR2_SMP12_B_0X7           (0x7U<<6U)
#define ADC_SMPR2_SMP11_B_0X0           (0x0U<<3U)
#define ADC_SMPR2_SMP11_B_0X1           (0x1U<<3U)
#define ADC_SMPR2_SMP11_B_0X2           (0x2U<<3U)
#define ADC_SMPR2_SMP11_B_0X3           (0x3U<<3U)
#define ADC_SMPR2_SMP11_B_0X4           (0x4U<<3U)
#define ADC_SMPR2_SMP11_B_0X5           (0x5U<<3U)
#define ADC_SMPR2_SMP11_B_0X6           (0x6U<<3U)
#define ADC_SMPR2_SMP11_B_0X7           (0x7U<<3U)
#define ADC_SMPR2_SMP10_B_0X0           (0x0U<<0U)
#define ADC_SMPR2_SMP10_B_0X1           (0x1U<<0U)
#define ADC_SMPR2_SMP10_B_0X2           (0x2U<<0U)
#define ADC_SMPR2_SMP10_B_0X3           (0x3U<<0U)
#define ADC_SMPR2_SMP10_B_0X4           (0x4U<<0U)
#define ADC_SMPR2_SMP10_B_0X5           (0x5U<<0U)
#define ADC_SMPR2_SMP10_B_0X6           (0x6U<<0U)
#define ADC_SMPR2_SMP10_B_0X7           (0x7U<<0U)

// PCSEL Configuration

#define ADC_PCSEL_PCSEL                 (0xFFFFFU<<0U)
#define ADC_PCSEL_PCSEL_0               (0x1U<<0U)

#define ADC_PCSEL_PCSEL_B_0X0           (0x0U<<0U)
#define ADC_PCSEL_PCSEL_B_0X1           (0x1U<<0U)

// SQR1 Configuration

#define ADC_SQR1_SQ4                    (0x1FU<<24U)
#define ADC_SQR1_SQ4_0                  (0x1U<<24U)
#define ADC_SQR1_SQ3                    (0x1FU<<18U)
#define ADC_SQR1_SQ3_0                  (0x1U<<18U)
#define ADC_SQR1_SQ2                    (0x1FU<<12U)
#define ADC_SQR1_SQ2_0                  (0x1U<<12U)
#define ADC_SQR1_SQ1                    (0x1FU<<6U)
#define ADC_SQR1_SQ1_0                  (0x1U<<6U)
#define ADC_SQR1_L                      (0xFU<<0U)
#define ADC_SQR1_L_0                    (0x1U<<0U)

#define ADC_SQR1_L_B_0X0                (0x0U<<0U)
#define ADC_SQR1_L_B_0X1                (0x1U<<0U)
#define ADC_SQR1_L_B_0XF                (0xFU<<0U)

// SQR2 Configuration

#define ADC_SQR2_SQ9                    (0x1FU<<24U)
#define ADC_SQR2_SQ9_0                  (0x1U<<24U)
#define ADC_SQR2_SQ8                    (0x1FU<<18U)
#define ADC_SQR2_SQ8_0                  (0x1U<<18U)
#define ADC_SQR2_SQ7                    (0x1FU<<12U)
#define ADC_SQR2_SQ7_0                  (0x1U<<12U)
#define ADC_SQR2_SQ6                    (0x1FU<<6U)
#define ADC_SQR2_SQ6_0                  (0x1U<<6U)
#define ADC_SQR2_SQ5                    (0x1FU<<0U)
#define ADC_SQR2_SQ5_0                  (0x1U<<0U)

// SQR3 Configuration

#define ADC_SQR3_SQ14                   (0x1FU<<24U)
#define ADC_SQR3_SQ14_0                 (0x1U<<24U)
#define ADC_SQR3_SQ13                   (0x1FU<<18U)
#define ADC_SQR3_SQ13_0                 (0x1U<<18U)
#define ADC_SQR3_SQ12                   (0x1FU<<12U)
#define ADC_SQR3_SQ12_0                 (0x1U<<12U)
#define ADC_SQR3_SQ11                   (0x1FU<<6U)
#define ADC_SQR3_SQ11_0                 (0x1U<<6U)
#define ADC_SQR3_SQ10                   (0x1FU<<0U)
#define ADC_SQR3_SQ10_0                 (0x1U<<0U)

// SQR4 Configuration

#define ADC_SQR4_SQ16                   (0x1FU<<6U)
#define ADC_SQR4_SQ16_0                 (0x1U<<6U)
#define ADC_SQR4_SQ15                   (0x1FU<<0U)
#define ADC_SQR4_SQ15_0                 (0x1U<<0U)

// DR Configuration

#define ADC_DR_RDATA                    (0xFFFFFFFFU<<0U)
#define ADC_DR_RDATA_0                  (0x1U<<0U)

// JSQR Configuration

#define ADC_JSQR_JSQ4                   (0x1FU<<27U)
#define ADC_JSQR_JSQ4_0                 (0x1U<<27U)
#define ADC_JSQR_JSQ3                   (0x1FU<<21U)
#define ADC_JSQR_JSQ3_0                 (0x1U<<21U)
#define ADC_JSQR_JSQ2                   (0x1FU<<15U)
#define ADC_JSQR_JSQ2_0                 (0x1U<<15U)
#define ADC_JSQR_JSQ1                   (0x1FU<<9U)
#define ADC_JSQR_JSQ1_0                 (0x1U<<9U)
#define ADC_JSQR_JEXTEN                 (0x3U<<7U)
#define ADC_JSQR_JEXTEN_0               (0x1U<<7U)
#define ADC_JSQR_JEXTSEL                (0x1FU<<2U)
#define ADC_JSQR_JEXTSEL_0              (0x1U<<2U)
#define ADC_JSQR_JL                     (0x3U<<0U)
#define ADC_JSQR_JL_0                   (0x1U<<0U)

#define ADC_JSQR_JEXTEN_B_0X0           (0x0U<<7U)
#define ADC_JSQR_JEXTEN_B_0X1           (0x1U<<7U)
#define ADC_JSQR_JEXTEN_B_0X2           (0x2U<<7U)
#define ADC_JSQR_JEXTEN_B_0X3           (0x3U<<7U)
#define ADC_JSQR_JEXTSEL_B_0X0          (0x0U<<2U)
#define ADC_JSQR_JEXTSEL_B_0X1          (0x1U<<2U)
#define ADC_JSQR_JEXTSEL_B_0X2          (0x2U<<2U)
#define ADC_JSQR_JEXTSEL_B_0X3          (0x3U<<2U)
#define ADC_JSQR_JEXTSEL_B_0X4          (0x4U<<2U)
#define ADC_JSQR_JEXTSEL_B_0X5          (0x5U<<2U)
#define ADC_JSQR_JEXTSEL_B_0X6          (0x6U<<2U)
#define ADC_JSQR_JEXTSEL_B_0X7          (0x7U<<2U)
#define ADC_JSQR_JEXTSEL_B_0X1F         (0x1FU<<2U)
#define ADC_JSQR_JL_B_0X0               (0x0U<<0U)
#define ADC_JSQR_JL_B_0X1               (0x1U<<0U)
#define ADC_JSQR_JL_B_0X2               (0x2U<<0U)
#define ADC_JSQR_JL_B_0X3               (0x3U<<0U)

// OFCFGR1 Configuration

#define ADC_OFCFGR1_OFFSET_CH           (0x1FU<<27U)
#define ADC_OFCFGR1_OFFSET_CH_0         (0x1U<<27U)
#define ADC_OFCFGR1_SSAT                (0x1U<<26U)
#define ADC_OFCFGR1_USAT                (0x1U<<25U)
#define ADC_OFCFGR1_POSOFF              (0x1U<<24U)

#define ADC_OFCFGR1_SSAT_B_0X0          (0x0U<<26U)
#define ADC_OFCFGR1_SSAT_B_0X1          (0x1U<<26U)
#define ADC_OFCFGR1_USAT_B_0X0          (0x0U<<25U)
#define ADC_OFCFGR1_USAT_B_0X1          (0x1U<<25U)
#define ADC_OFCFGR1_POSOFF_B_0X0        (0x0U<<24U)
#define ADC_OFCFGR1_POSOFF_B_0X1        (0x1U<<24U)

// OFCFGR2 Configuration

#define ADC_OFCFGR2_OFFSET_CH           (0x1FU<<27U)
#define ADC_OFCFGR2_OFFSET_CH_0         (0x1U<<27U)
#define ADC_OFCFGR2_SSAT                (0x1U<<26U)
#define ADC_OFCFGR2_USAT                (0x1U<<25U)
#define ADC_OFCFGR2_POSOFF              (0x1U<<24U)

#define ADC_OFCFGR2_SSAT_B_0X0          (0x0U<<26U)
#define ADC_OFCFGR2_SSAT_B_0X1          (0x1U<<26U)
#define ADC_OFCFGR2_USAT_B_0X0          (0x0U<<25U)
#define ADC_OFCFGR2_USAT_B_0X1          (0x1U<<25U)
#define ADC_OFCFGR2_POSOFF_B_0X0        (0x0U<<24U)
#define ADC_OFCFGR2_POSOFF_B_0X1        (0x1U<<24U)

// OFCFGR3 Configuration

#define ADC_OFCFGR3_OFFSET_CH           (0x1FU<<27U)
#define ADC_OFCFGR3_OFFSET_CH_0         (0x1U<<27U)
#define ADC_OFCFGR3_SSAT                (0x1U<<26U)
#define ADC_OFCFGR3_USAT                (0x1U<<25U)
#define ADC_OFCFGR3_POSOFF              (0x1U<<24U)

#define ADC_OFCFGR3_SSAT_B_0X0          (0x0U<<26U)
#define ADC_OFCFGR3_SSAT_B_0X1          (0x1U<<26U)
#define ADC_OFCFGR3_USAT_B_0X0          (0x0U<<25U)
#define ADC_OFCFGR3_USAT_B_0X1          (0x1U<<25U)
#define ADC_OFCFGR3_POSOFF_B_0X0        (0x0U<<24U)
#define ADC_OFCFGR3_POSOFF_B_0X1        (0x1U<<24U)

// OFCFGR4 Configuration

#define ADC_OFCFGR4_OFFSET_CH           (0x1FU<<27U)
#define ADC_OFCFGR4_OFFSET_CH_0         (0x1U<<27U)
#define ADC_OFCFGR4_SSAT                (0x1U<<26U)
#define ADC_OFCFGR4_USAT                (0x1U<<25U)
#define ADC_OFCFGR4_POSOFF              (0x1U<<24U)

#define ADC_OFCFGR4_SSAT_B_0X0          (0x0U<<26U)
#define ADC_OFCFGR4_SSAT_B_0X1          (0x1U<<26U)
#define ADC_OFCFGR4_USAT_B_0X0          (0x0U<<25U)
#define ADC_OFCFGR4_USAT_B_0X1          (0x1U<<25U)
#define ADC_OFCFGR4_POSOFF_B_0X0        (0x0U<<24U)
#define ADC_OFCFGR4_POSOFF_B_0X1        (0x1U<<24U)

// OFR1 Configuration

#define ADC_OFR1_OFFSET                 (0x3FFFFFU<<0U)
#define ADC_OFR1_OFFSET_0               (0x1U<<0U)

// OFR2 Configuration

#define ADC_OFR2_OFFSET                 (0x3FFFFFU<<0U)
#define ADC_OFR2_OFFSET_0               (0x1U<<0U)

// OFR3 Configuration

#define ADC_OFR3_OFFSET                 (0x3FFFFFU<<0U)
#define ADC_OFR3_OFFSET_0               (0x1U<<0U)

// OFR4 Configuration

#define ADC_OFR4_OFFSET                 (0x3FFFFFU<<0U)
#define ADC_OFR4_OFFSET_0               (0x1U<<0U)

// GCOMP Configuration

#define ADC_GCOMP_GCOMP                 (0x1U<<31U)
#define ADC_GCOMP_GCOMPCOEFF            (0x3FFFU<<0U)
#define ADC_GCOMP_GCOMPCOEFF_0          (0x1U<<0U)

#define ADC_GCOMP_GCOMP_B_0X0           (0x0U<<31U)
#define ADC_GCOMP_GCOMP_B_0X1           (0x1U<<31U)
#define ADC_GCOMP_GCOMPCOEFF_B_0X800    (0x800U<<0U)
#define ADC_GCOMP_GCOMPCOEFF_B_0X1000   (0x1000U<<0U)
#define ADC_GCOMP_GCOMPCOEFF_B_0X2000   (0x2000U<<0U)
#define ADC_GCOMP_GCOMPCOEFF_B_0X3000   (0x3000U<<0U)

// JDR1 Configuration

#define ADC_JDR1_JDATA                  (0xFFFFFFFFU<<0U)
#define ADC_JDR1_JDATA_0                (0x1U<<0U)

// JDR2 Configuration

#define ADC_JDR2_JDATA                  (0xFFFFFFFFU<<0U)
#define ADC_JDR2_JDATA_0                (0x1U<<0U)

// JDR3 Configuration

#define ADC_JDR3_JDATA                  (0xFFFFFFFFU<<0U)
#define ADC_JDR3_JDATA_0                (0x1U<<0U)

// JDR4 Configuration

#define ADC_JDR4_JDATA                  (0xFFFFFFFFU<<0U)
#define ADC_JDR4_JDATA_0                (0x1U<<0U)

// AWD2CR Configuration

#define ADC_AWD2CR_AWD2CH               (0xFFFFFU<<0U)
#define ADC_AWD2CR_AWD2CH_0             (0x1U<<0U)

// AWD3CR Configuration

#define ADC_AWD3CR_AWD3CH               (0xFFFFFU<<0U)
#define ADC_AWD3CR_AWD3CH_0             (0x1U<<0U)

// AWD1LTR Configuration

#define ADC_AWD1LTR_LTR                 (0x7FFFFFU<<0U)
#define ADC_AWD1LTR_LTR_0               (0x1U<<0U)

// AWD1HTR Configuration

#define ADC_AWD1HTR_AWDFILT             (0x7U<<29U)
#define ADC_AWD1HTR_AWDFILT_0           (0x1U<<29U)
#define ADC_AWD1HTR_HTR                 (0x7FFFFFU<<0U)
#define ADC_AWD1HTR_HTR_0               (0x1U<<0U)

#define ADC_AWD1HTR_AWDFILT_B_0X0       (0x0U<<29U)
#define ADC_AWD1HTR_AWDFILT_B_0X1       (0x1U<<29U)
#define ADC_AWD1HTR_AWDFILT_B_0X7       (0x7U<<29U)

// AWD2LTR Configuration

#define ADC_AWD2LTR_LTR                 (0x7FFFFFU<<0U)
#define ADC_AWD2LTR_LTR_0               (0x1U<<0U)

// AWD2HTR Configuration

#define ADC_AWD2HTR_HTR                 (0x7FFFFFU<<0U)
#define ADC_AWD2HTR_HTR_0               (0x1U<<0U)

// AWD3LTR Configuration

#define ADC_AWD3LTR_LTR                 (0x7FFFFFU<<0U)
#define ADC_AWD3LTR_LTR_0               (0x1U<<0U)

// AWD3HTR Configuration

#define ADC_AWD3HTR_HTR                 (0x7FFFFFU<<0U)
#define ADC_AWD3HTR_HTR_0               (0x1U<<0U)

// DIFSEL Configuration

#define ADC_DIFSEL_DIFSEL               (0xFFFFFU<<0U)
#define ADC_DIFSEL_DIFSEL_0             (0x1U<<0U)

// CALFACT Configuration

#define ADC_CALFACT_CALADDOS            (0x1U<<31U)
#define ADC_CALFACT_CALFACT_D           (0x1FFU<<16U)
#define ADC_CALFACT_CALFACT_D_0         (0x1U<<16U)
#define ADC_CALFACT_CALFACT_S           (0x1FFU<<0U)
#define ADC_CALFACT_CALFACT_S_0         (0x1U<<0U)

#define ADC_CALFACT_CALADDOS_B_0X0      (0x0U<<31U)
#define ADC_CALFACT_CALADDOS_B_0X1      (0x1U<<31U)

// OR Configuration

#define ADC_OR_VDDCOREEN                (0x1U<<2U)
#define ADC_OR_SELBG                    (0x1U<<1U)
#define ADC_OR_SELREF                   (0x1U<<0U)

#define ADC_OR_VDDCOREEN_B_0X0          (0x0U<<2U)
#define ADC_OR_VDDCOREEN_B_0X1          (0x1U<<2U)
#define ADC_OR_SELBG_B_0X0              (0x0U<<1U)
#define ADC_OR_SELBG_B_0X1              (0x1U<<1U)
#define ADC_OR_SELREF_B_0X0             (0x0U<<0U)
#define ADC_OR_SELREF_B_0X1             (0x1U<<0U)
