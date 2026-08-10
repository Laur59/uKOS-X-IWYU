/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_adc3_common equates.
 */

#pragma once

#include    <stdint.h>

// ADC3_COMMON address definitions
// -------------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CCR;
    volatile    uint32_t    CDR;
    volatile    uint32_t    CDR2;
} ADC3_COMMON_TypeDef;

#ifdef __cplusplus
#define ADC3_COMMON reinterpret_cast<ADC3_COMMON_TypeDef *>(0x58026300U)

#else
#define ADC3_COMMON ((ADC3_COMMON_TypeDef *)0x58026300U)
#endif

// CSR Configuration

#define ADC3_COMMON_CSR_JQOVF_SLV       (0x1U<<26U)
#define ADC3_COMMON_CSR_AWD3_SLV        (0x1U<<25U)
#define ADC3_COMMON_CSR_AWD2_SLV        (0x1U<<24U)
#define ADC3_COMMON_CSR_AWD1_SLV        (0x1U<<23U)
#define ADC3_COMMON_CSR_JEOS_SLV        (0x1U<<22U)
#define ADC3_COMMON_CSR_JEOC_SLV        (0x1U<<21U)
#define ADC3_COMMON_CSR_OVR_SLV         (0x1U<<20U)
#define ADC3_COMMON_CSR_EOS_SLV         (0x1U<<19U)
#define ADC3_COMMON_CSR_EOC_SLV         (0x1U<<18U)
#define ADC3_COMMON_CSR_EOSMP_SLV       (0x1U<<17U)
#define ADC3_COMMON_CSR_ADRDY_SLV       (0x1U<<16U)
#define ADC3_COMMON_CSR_JQOVF_MST       (0x1U<<10U)
#define ADC3_COMMON_CSR_AWD3_MST        (0x1U<<9U)
#define ADC3_COMMON_CSR_AWD2_MST        (0x1U<<8U)
#define ADC3_COMMON_CSR_AWD1_MST        (0x1U<<7U)
#define ADC3_COMMON_CSR_JEOS_MST        (0x1U<<6U)
#define ADC3_COMMON_CSR_JEOC_MST        (0x1U<<5U)
#define ADC3_COMMON_CSR_OVR_MST         (0x1U<<4U)
#define ADC3_COMMON_CSR_EOS_MST         (0x1U<<3U)
#define ADC3_COMMON_CSR_EOC_MST         (0x1U<<2U)
#define ADC3_COMMON_CSR_EOSMP_MST       (0x1U<<1U)
#define ADC3_COMMON_CSR_ADRDY_MST       (0x1U<<0U)

// CCR Configuration

#define ADC3_COMMON_CCR_VBATEN          (0x1U<<24U)
#define ADC3_COMMON_CCR_VSENSEEN        (0x1U<<23U)
#define ADC3_COMMON_CCR_VREFEN          (0x1U<<22U)
#define ADC3_COMMON_CCR_PRESC           (0xFU<<18U)
#define ADC3_COMMON_CCR_PRESC_0         (0x1U<<18U)
#define ADC3_COMMON_CCR_CKMODE          (0x3U<<16U)
#define ADC3_COMMON_CCR_CKMODE_0        (0x1U<<16U)
#define ADC3_COMMON_CCR_DAMDF           (0x3U<<14U)
#define ADC3_COMMON_CCR_DAMDF_0         (0x1U<<14U)
#define ADC3_COMMON_CCR_DELAY           (0xFU<<8U)
#define ADC3_COMMON_CCR_DELAY_0         (0x1U<<8U)
#define ADC3_COMMON_CCR_DUAL            (0x1FU<<0U)
#define ADC3_COMMON_CCR_DUAL_0          (0x1U<<0U)

// CDR Configuration

#define ADC3_COMMON_CDR_RDATA_MST       (0xFFFFU<<0U)
#define ADC3_COMMON_CDR_RDATA_MST_0     (0x1U<<0U)
#define ADC3_COMMON_CDR_RDATA_SLV       (0xFFFFU<<16U)
#define ADC3_COMMON_CDR_RDATA_SLV_0     (0x1U<<16U)

// CDR2 Configuration

#define ADC3_COMMON_CDR2_RDATA_ALT      (0xFFFFFFFFU<<0U)
#define ADC3_COMMON_CDR2_RDATA_ALT_0    (0x1U<<0U)
