/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_adc12_common.
; =======================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_adc12_common equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// ADC12_COMMON address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    ADC12_CSR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    ADC12_CCR;
    volatile    uint32_t    ADC12_CDR;
    volatile    uint32_t    ADC12_CDR2;
} ADC12_COMMON_TypeDef;

#ifdef __cplusplus
#define ADC12_COMMON_NS reinterpret_cast<ADC12_COMMON_TypeDef *>(0x42028300U)
#define ADC12_COMMON_S  reinterpret_cast<ADC12_COMMON_TypeDef *>(0x52028300U)

#else
#define ADC12_COMMON_NS ((ADC12_COMMON_TypeDef *)0x42028300U)
#define ADC12_COMMON_S  ((ADC12_COMMON_TypeDef *)0x52028300U)
#endif

// ADC12_CSR Configuration

#define ADC12_COMMON_ADC12_CSR_LDORDY_SLV       (0x1U<<28)
#define ADC12_COMMON_ADC12_CSR_AWD3_SLV         (0x1U<<25)
#define ADC12_COMMON_ADC12_CSR_AWD2_SLV         (0x1U<<24)
#define ADC12_COMMON_ADC12_CSR_AWD1_SLV         (0x1U<<23)
#define ADC12_COMMON_ADC12_CSR_JEOS_SLV         (0x1U<<22)
#define ADC12_COMMON_ADC12_CSR_JEOC_SLV         (0x1U<<21)
#define ADC12_COMMON_ADC12_CSR_OVR_SLV          (0x1U<<20)
#define ADC12_COMMON_ADC12_CSR_EOS_SLV          (0x1U<<19)
#define ADC12_COMMON_ADC12_CSR_EOC_SLV          (0x1U<<18)
#define ADC12_COMMON_ADC12_CSR_EOSMP_SLV        (0x1U<<17)
#define ADC12_COMMON_ADC12_CSR_ADRDY_SLV        (0x1U<<16)
#define ADC12_COMMON_ADC12_CSR_LDORDY_MST       (0x1U<<12)
#define ADC12_COMMON_ADC12_CSR_AWD3_MST         (0x1U<<9)
#define ADC12_COMMON_ADC12_CSR_AWD2_MST         (0x1U<<8)
#define ADC12_COMMON_ADC12_CSR_AWD1_MST         (0x1U<<7)
#define ADC12_COMMON_ADC12_CSR_JEOS_MST         (0x1U<<6)
#define ADC12_COMMON_ADC12_CSR_JEOC_MST         (0x1U<<5)
#define ADC12_COMMON_ADC12_CSR_OVR_MST          (0x1U<<4)
#define ADC12_COMMON_ADC12_CSR_EOS_MST          (0x1U<<3)
#define ADC12_COMMON_ADC12_CSR_EOC_MST          (0x1U<<2)
#define ADC12_COMMON_ADC12_CSR_EOSMP_MST        (0x1U<<1)
#define ADC12_COMMON_ADC12_CSR_ADRDY_MST        (0x1U<<0)

// ADC12_CCR Configuration

#define ADC12_COMMON_ADC12_CCR_VBATEN           (0x1U<<24)
#define ADC12_COMMON_ADC12_CCR_VSENSESEL        (0x1U<<23)
#define ADC12_COMMON_ADC12_CCR_VREFEN           (0x1U<<22)
#define ADC12_COMMON_ADC12_CCR_PRESC            (0xFU<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_0          (0x1U<<18)
#define ADC12_COMMON_ADC12_CCR_DAMDF            (0x3U<<14)
#define ADC12_COMMON_ADC12_CCR_DAMDF_0          (0x1U<<14)
#define ADC12_COMMON_ADC12_CCR_DELAY            (0xFU<<8)
#define ADC12_COMMON_ADC12_CCR_DELAY_0          (0x1U<<8)
#define ADC12_COMMON_ADC12_CCR_DUAL             (0x1FU<<0)
#define ADC12_COMMON_ADC12_CCR_DUAL_0           (0x1U<<0)
#define ADC12_COMMON_ADC12_CCR_VBATEN_B_0X0     (0x0U<<24)
#define ADC12_COMMON_ADC12_CCR_VBATEN_B_0X1     (0x1U<<24)
#define ADC12_COMMON_ADC12_CCR_VSENSESEL_B_0X0  (0x0U<<23)
#define ADC12_COMMON_ADC12_CCR_VSENSESEL_B_0X1  (0x1U<<23)
#define ADC12_COMMON_ADC12_CCR_VREFEN_B_0X0     (0x0U<<22)
#define ADC12_COMMON_ADC12_CCR_VREFEN_B_0X1     (0x1U<<22)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X0      (0x0U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X1      (0x1U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X2      (0x2U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X3      (0x3U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X4      (0x4U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X5      (0x5U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X6      (0x6U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X7      (0x7U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X8      (0x8U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0X9      (0x9U<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0XA      (0xAU<<18)
#define ADC12_COMMON_ADC12_CCR_PRESC_B_0XB      (0xBU<<18)
#define ADC12_COMMON_ADC12_CCR_DAMDF_B_0X0      (0x0U<<14)
#define ADC12_COMMON_ADC12_CCR_DAMDF_B_0X2      (0x2U<<14)
#define ADC12_COMMON_ADC12_CCR_DAMDF_B_0X3      (0x3U<<14)
#define ADC12_COMMON_ADC12_CCR_DUAL_B_0X0       (0x0U<<0)
#define ADC12_COMMON_ADC12_CCR_DUAL_B_0X1       (0x1U<<0)
#define ADC12_COMMON_ADC12_CCR_DUAL_B_0X2       (0x2U<<0)
#define ADC12_COMMON_ADC12_CCR_DUAL_B_0X3       (0x3U<<0)
#define ADC12_COMMON_ADC12_CCR_DUAL_B_0X5       (0x5U<<0)
#define ADC12_COMMON_ADC12_CCR_DUAL_B_0X6       (0x6U<<0)
#define ADC12_COMMON_ADC12_CCR_DUAL_B_0X7       (0x7U<<0)
#define ADC12_COMMON_ADC12_CCR_DUAL_B_0X9       (0x9U<<0)

// ADC12_CDR Configuration

#define ADC12_COMMON_ADC12_CDR_RDATA_SLV        (0xFFFFU<<16)
#define ADC12_COMMON_ADC12_CDR_RDATA_SLV_0      (0x1U<<16)
#define ADC12_COMMON_ADC12_CDR_RDATA_MST        (0xFFFFU<<0)
#define ADC12_COMMON_ADC12_CDR_RDATA_MST_0      (0x1U<<0)

// ADC12_CDR2 Configuration

#define ADC12_COMMON_ADC12_CDR2_RDATA_ALT       (0xFFFFFFFFU<<0)
#define ADC12_COMMON_ADC12_CDR2_RDATA_ALT_0     (0x1U<<0)
