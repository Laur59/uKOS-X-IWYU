/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_adc_common equates.
 */

#pragma once

#include    <stdint.h>

// ADC_COMMON address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CCR;
    volatile    uint32_t    CDR;
} ADC_COMMON_TypeDef;

#ifdef __cplusplus
#define ADC_COMMON  reinterpret_cast<ADC_COMMON_TypeDef *>(0x50040300U)

#else
#define ADC_COMMON  ((ADC_COMMON_TypeDef *)0x50040300U)
#endif

// CSR Configuration

#define ADC_COMMON_CSR_JQOVF_SLV    (0x1U<<26)
#define ADC_COMMON_CSR_AWD3_SLV     (0x1U<<25)
#define ADC_COMMON_CSR_AWD2_SLV     (0x1U<<24)
#define ADC_COMMON_CSR_AWD1_SLV     (0x1U<<23)
#define ADC_COMMON_CSR_JEOS_SLV     (0x1U<<22)
#define ADC_COMMON_CSR_JEOC_SLV     (0x1U<<21)
#define ADC_COMMON_CSR_OVR_SLV      (0x1U<<20)
#define ADC_COMMON_CSR_EOS_SLV      (0x1U<<19)
#define ADC_COMMON_CSR_EOC_SLV      (0x1U<<18)
#define ADC_COMMON_CSR_EOSMP_SLV    (0x1U<<17)
#define ADC_COMMON_CSR_ADRDY_SLV    (0x1U<<16)
#define ADC_COMMON_CSR_JQOVF_MST    (0x1U<<10)
#define ADC_COMMON_CSR_AWD3_MST     (0x1U<<9)
#define ADC_COMMON_CSR_AWD2_MST     (0x1U<<8)
#define ADC_COMMON_CSR_AWD1_MST     (0x1U<<7)
#define ADC_COMMON_CSR_JEOS_MST     (0x1U<<6)
#define ADC_COMMON_CSR_JEOC_MST     (0x1U<<5)
#define ADC_COMMON_CSR_OVR_MST      (0x1U<<4)
#define ADC_COMMON_CSR_EOS_MST      (0x1U<<3)
#define ADC_COMMON_CSR_EOC_MST      (0x1U<<2)
#define ADC_COMMON_CSR_EOSMP_MST    (0x1U<<1)
#define ADC_COMMON_CSR_ADDRDY_MST   (0x1U<<0)

// CCR Configuration

#define ADC_COMMON_CCR_PRESC        (0xFU<<18)
#define ADC_COMMON_CCR_PRESC_0      (0x1U<<18)
#define ADC_COMMON_CCR_CH18SEL      (0x1U<<24)
#define ADC_COMMON_CCR_CH17SEL      (0x1U<<23)
#define ADC_COMMON_CCR_VREFEN       (0x1U<<22)
#define ADC_COMMON_CCR_CKMODE       (0x3U<<16)
#define ADC_COMMON_CCR_CKMODE_0     (0x1U<<16)
#define ADC_COMMON_CCR_MDMA         (0x3U<<14)
#define ADC_COMMON_CCR_MDMA_0       (0x1U<<14)
#define ADC_COMMON_CCR_DMACFG       (0x1U<<13)
#define ADC_COMMON_CCR_DELAY        (0xFU<<8)
#define ADC_COMMON_CCR_DELAY_0      (0x1U<<8)
#define ADC_COMMON_CCR_DUAL         (0x1FU<<0)
#define ADC_COMMON_CCR_DUAL_0       (0x1U<<0)

// CDR Configuration

#define ADC_COMMON_CDR_RDATA_MST    (0xFFFFU<<0)
#define ADC_COMMON_CDR_RDATA_MST_0  (0x1U<<0)
#define ADC_COMMON_CDR_RDATA_SLV    (0xFFFFU<<16)
#define ADC_COMMON_CDR_RDATA_SLV_0  (0x1U<<16)
