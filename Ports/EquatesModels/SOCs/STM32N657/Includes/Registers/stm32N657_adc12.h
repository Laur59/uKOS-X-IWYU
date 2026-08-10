/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_adc12 equates.
 */

#pragma once

#include    <stdint.h>

// ADC12 address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[192];
    volatile    uint32_t    CSR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    CCR;
    volatile    uint32_t    CDR;
    volatile    uint32_t    CDR2;
} ADC12_TypeDef;

#ifdef __cplusplus
#define ADC12_NS    reinterpret_cast<ADC12_TypeDef *>(0x40022300U)
#define ADC12_S     reinterpret_cast<ADC12_TypeDef *>(0x50022300U)

#else
#define ADC12_NS    ((ADC12_TypeDef *)0x40022300U)
#define ADC12_S     ((ADC12_TypeDef *)0x50022300U)
#endif

// CSR Configuration

#define ADC12_CSR_AWD3_SLV      (0x1U<<25U)
#define ADC12_CSR_AWD2_SLV      (0x1U<<24U)
#define ADC12_CSR_AWD1_SLV      (0x1U<<23U)
#define ADC12_CSR_JEOS_SLV      (0x1U<<22U)
#define ADC12_CSR_JEOC_SLV      (0x1U<<21U)
#define ADC12_CSR_OVR_SLV       (0x1U<<20U)
#define ADC12_CSR_EOS_SLV       (0x1U<<19U)
#define ADC12_CSR_EOC_SLV       (0x1U<<18U)
#define ADC12_CSR_EOSMP_SLV     (0x1U<<17U)
#define ADC12_CSR_ADRDY_SLV     (0x1U<<16U)
#define ADC12_CSR_AWD3_MST      (0x1U<<9U)
#define ADC12_CSR_AWD2_MST      (0x1U<<8U)
#define ADC12_CSR_AWD1_MST      (0x1U<<7U)
#define ADC12_CSR_JEOS_MST      (0x1U<<6U)
#define ADC12_CSR_JEOC_MST      (0x1U<<5U)
#define ADC12_CSR_OVR_MST       (0x1U<<4U)
#define ADC12_CSR_EOS_MST       (0x1U<<3U)
#define ADC12_CSR_EOC_MST       (0x1U<<2U)
#define ADC12_CSR_EOSMP_MST     (0x1U<<1U)
#define ADC12_CSR_ADRDY_MST     (0x1U<<0U)

// CCR Configuration

#define ADC12_CCR_VBATEN        (0x1U<<24U)
#define ADC12_CCR_VREFEN        (0x1U<<22U)
#define ADC12_CCR_DAMDF         (0x3U<<14U)
#define ADC12_CCR_DAMDF_0       (0x1U<<14U)
#define ADC12_CCR_DELAY         (0xFU<<8U)
#define ADC12_CCR_DELAY_0       (0x1U<<8U)
#define ADC12_CCR_DUAL          (0x1FU<<0U)
#define ADC12_CCR_DUAL_0        (0x1U<<0U)

#define ADC12_CCR_VBATEN_B_0X0  (0x0U<<24U)
#define ADC12_CCR_VBATEN_B_0X1  (0x1U<<24U)
#define ADC12_CCR_VREFEN_B_0X0  (0x0U<<22U)
#define ADC12_CCR_VREFEN_B_0X1  (0x1U<<22U)
#define ADC12_CCR_DAMDF_B_0X0   (0x0U<<14U)
#define ADC12_CCR_DAMDF_B_0X2   (0x2U<<14U)
#define ADC12_CCR_DAMDF_B_0X3   (0x3U<<14U)
#define ADC12_CCR_DUAL_B_0X0    (0x0U<<0U)
#define ADC12_CCR_DUAL_B_0X1    (0x1U<<0U)
#define ADC12_CCR_DUAL_B_0X2    (0x2U<<0U)
#define ADC12_CCR_DUAL_B_0X3    (0x3U<<0U)
#define ADC12_CCR_DUAL_B_0X5    (0x5U<<0U)
#define ADC12_CCR_DUAL_B_0X6    (0x6U<<0U)
#define ADC12_CCR_DUAL_B_0X7    (0x7U<<0U)
#define ADC12_CCR_DUAL_B_0X9    (0x9U<<0U)

// CDR Configuration

#define ADC12_CDR_RDATA_SLV     (0xFFFFU<<16U)
#define ADC12_CDR_RDATA_SLV_0   (0x1U<<16U)
#define ADC12_CDR_RDATA_MST     (0xFFFFU<<0U)
#define ADC12_CDR_RDATA_MST_0   (0x1U<<0U)

// CDR2 Configuration

#define ADC12_CDR2_RDATA_ALT    (0xFFFFFFFFU<<0U)
#define ADC12_CDR2_RDATA_ALT_0  (0x1U<<0U)
