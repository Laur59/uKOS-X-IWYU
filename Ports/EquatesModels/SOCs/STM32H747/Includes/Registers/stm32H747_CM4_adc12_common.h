/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H747_CM4_adc12_common.
; ===========================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H747_CM4_adc12_common equates.
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
    volatile    uint32_t    CSR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CCR;
    volatile    uint32_t    CDR;
    volatile    uint32_t    CDR2;
} ADC12_COMMON_TypeDef;

#ifdef __cplusplus
#define ADC12_COMMON    reinterpret_cast<ADC12_COMMON_TypeDef *>(0x40022300U)

#else
#define ADC12_COMMON    ((ADC12_COMMON_TypeDef *)0x40022300U)
#endif

// CSR Configuration

#define ADC12_COMMON_CSR_JQOVF_SLV      (0x1U<<26)
#define ADC12_COMMON_CSR_AWD3_SLV       (0x1U<<25)
#define ADC12_COMMON_CSR_AWD2_SLV       (0x1U<<24)
#define ADC12_COMMON_CSR_AWD1_SLV       (0x1U<<23)
#define ADC12_COMMON_CSR_JEOS_SLV       (0x1U<<22)
#define ADC12_COMMON_CSR_JEOC_SLV       (0x1U<<21)
#define ADC12_COMMON_CSR_OVR_SLV        (0x1U<<20)
#define ADC12_COMMON_CSR_EOS_SLV        (0x1U<<19)
#define ADC12_COMMON_CSR_EOC_SLV        (0x1U<<18)
#define ADC12_COMMON_CSR_EOSMP_SLV      (0x1U<<17)
#define ADC12_COMMON_CSR_ADRDY_SLV      (0x1U<<16)
#define ADC12_COMMON_CSR_JQOVF_MST      (0x1U<<10)
#define ADC12_COMMON_CSR_AWD3_MST       (0x1U<<9)
#define ADC12_COMMON_CSR_AWD2_MST       (0x1U<<8)
#define ADC12_COMMON_CSR_AWD1_MST       (0x1U<<7)
#define ADC12_COMMON_CSR_JEOS_MST       (0x1U<<6)
#define ADC12_COMMON_CSR_JEOC_MST       (0x1U<<5)
#define ADC12_COMMON_CSR_OVR_MST        (0x1U<<4)
#define ADC12_COMMON_CSR_EOS_MST        (0x1U<<3)
#define ADC12_COMMON_CSR_EOC_MST        (0x1U<<2)
#define ADC12_COMMON_CSR_EOSMP_MST      (0x1U<<1)
#define ADC12_COMMON_CSR_ADRDY_MST      (0x1U<<0)

// CCR Configuration

#define ADC12_COMMON_CCR_VBATEN         (0x1U<<24)
#define ADC12_COMMON_CCR_VSENSEEN       (0x1U<<23)
#define ADC12_COMMON_CCR_VREFEN         (0x1U<<22)
#define ADC12_COMMON_CCR_PRESC          (0xFU<<18)
#define ADC12_COMMON_CCR_PRESC_0        (0x1U<<18)
#define ADC12_COMMON_CCR_CKMODE         (0x3U<<16)
#define ADC12_COMMON_CCR_CKMODE_0       (0x1U<<16)
#define ADC12_COMMON_CCR_DAMDF          (0x3U<<14)
#define ADC12_COMMON_CCR_DAMDF_0        (0x1U<<14)
#define ADC12_COMMON_CCR_DELAY          (0xFU<<8)
#define ADC12_COMMON_CCR_DELAY_0        (0x1U<<8)
#define ADC12_COMMON_CCR_DUAL           (0x1FU<<0)
#define ADC12_COMMON_CCR_DUAL_0         (0x1U<<0)

// CDR Configuration

#define ADC12_COMMON_CDR_RDATA_MST      (0xFFFFU<<0)
#define ADC12_COMMON_CDR_RDATA_MST_0    (0x1U<<0)
#define ADC12_COMMON_CDR_RDATA_SLV      (0xFFFFU<<16)
#define ADC12_COMMON_CDR_RDATA_SLV_0    (0x1U<<16)

// CDR2 Configuration

#define ADC12_COMMON_CDR2_RDATA_ALT     (0xFFFFFFFFU<<0)
#define ADC12_COMMON_CDR2_RDATA_ALT_0   (0x1U<<0)
