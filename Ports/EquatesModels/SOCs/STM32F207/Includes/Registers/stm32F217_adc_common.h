/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_adc_common equates.
 */

#pragma once

#include    <stdint.h>

// ADC_COMMON address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    CCR;
    volatile    uint32_t    CDR;
} ADC_COMMON_TypeDef;

#ifdef __cplusplus
#define ADC_COMMON  reinterpret_cast<ADC_COMMON_TypeDef *>(0x40012300U)

#else
#define ADC_COMMON  ((ADC_COMMON_TypeDef *)0x40012300U)
#endif

// CSR Configuration

#define ADC_COMMON_CSR_AWD1     (0x1U<<0U)
#define ADC_COMMON_CSR_EOC1     (0x1U<<1U)
#define ADC_COMMON_CSR_JEOC1    (0x1U<<2U)
#define ADC_COMMON_CSR_JSTRT1   (0x1U<<3U)
#define ADC_COMMON_CSR_STRT1    (0x1U<<4U)
#define ADC_COMMON_CSR_OVR1     (0x1U<<5U)
#define ADC_COMMON_CSR_AWD2     (0x1U<<8U)
#define ADC_COMMON_CSR_EOC2     (0x1U<<9U)
#define ADC_COMMON_CSR_JEOC2    (0x1U<<10U)
#define ADC_COMMON_CSR_JSTRT2   (0x1U<<11U)
#define ADC_COMMON_CSR_STRT2    (0x1U<<12U)
#define ADC_COMMON_CSR_OVR2     (0x1U<<13U)
#define ADC_COMMON_CSR_AWD3     (0x1U<<16U)
#define ADC_COMMON_CSR_EOC3     (0x1U<<17U)
#define ADC_COMMON_CSR_JEOC3    (0x1U<<18U)
#define ADC_COMMON_CSR_JSTRT3   (0x1U<<19U)
#define ADC_COMMON_CSR_STRT3    (0x1U<<20U)
#define ADC_COMMON_CSR_OVR3     (0x1U<<21U)

// CCR Configuration

#define ADC_COMMON_CCR_MULT     (0x1FU<<0U)
#define ADC_COMMON_CCR_MULT_0   (0x1U<<0U)
#define ADC_COMMON_CCR_DELAY    (0xFU<<8U)
#define ADC_COMMON_CCR_DELAY_0  (0x1U<<8U)
#define ADC_COMMON_CCR_DDS      (0x1U<<13U)
#define ADC_COMMON_CCR_DMA      (0x3U<<14U)
#define ADC_COMMON_CCR_DMA_0    (0x1U<<14U)
#define ADC_COMMON_CCR_ADCPRE   (0x3U<<16U)
#define ADC_COMMON_CCR_ADCPRE_0 (0x1U<<16U)
#define ADC_COMMON_CCR_VBATE    (0x1U<<22U)
#define ADC_COMMON_CCR_TSVREFE  (0x1U<<23U)

// CDR Configuration

#define ADC_COMMON_CDR_DATA1    (0xFFFFU<<0U)
#define ADC_COMMON_CDR_DATA1_0  (0x1U<<0U)
#define ADC_COMMON_CDR_DATA2    (0xFFFFU<<16U)
#define ADC_COMMON_CDR_DATA2_0  (0x1U<<16U)
