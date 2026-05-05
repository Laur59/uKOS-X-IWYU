/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_adcc3 equates.
 */
#pragma once

#include    <stdint.h>

// ADCC3 address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[192];
    volatile    uint32_t    ADC12_CSR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    ADC12_CCR;
    volatile    uint32_t    ADC12_CDR;
    volatile    uint32_t    ADC12_CDR2;
} ADCC3_TypeDef;

#if (defined(__cplusplus))
#define ADCC3_S reinterpret_cast<ADCC3_TypeDef *>(0x50022700u)

#else
#define ADCC3_S ((ADCC3_TypeDef *)0x50022700u)
#endif

// ADC12_CSR Configuration

#define ADCC3_ADC12_CSR_LDORDY_SLV      (0x1u<<28)
#define ADCC3_ADC12_CSR_JQOVF_SLV       (0x1u<<26)
#define ADCC3_ADC12_CSR_AWD3_SLV        (0x1u<<25)
#define ADCC3_ADC12_CSR_AWD2_SLV        (0x1u<<24)
#define ADCC3_ADC12_CSR_AWD1_SLV        (0x1u<<23)
#define ADCC3_ADC12_CSR_JEOS_SLV        (0x1u<<22)
#define ADCC3_ADC12_CSR_JEOC_SLV        (0x1u<<21)
#define ADCC3_ADC12_CSR_OVR_SLV         (0x1u<<20)
#define ADCC3_ADC12_CSR_EOS_SLV         (0x1u<<19)
#define ADCC3_ADC12_CSR_EOC_SLV         (0x1u<<18)
#define ADCC3_ADC12_CSR_EOSMP_SLV       (0x1u<<17)
#define ADCC3_ADC12_CSR_ADRDY_SLV       (0x1u<<16)
#define ADCC3_ADC12_CSR_LDORDY_MST      (0x1u<<12)
#define ADCC3_ADC12_CSR_JQOVF_MST       (0x1u<<10)
#define ADCC3_ADC12_CSR_AWD3_MST        (0x1u<<9)
#define ADCC3_ADC12_CSR_AWD2_MST        (0x1u<<8)
#define ADCC3_ADC12_CSR_AWD1_MST        (0x1u<<7)
#define ADCC3_ADC12_CSR_JEOS_MST        (0x1u<<6)
#define ADCC3_ADC12_CSR_JEOC_MST        (0x1u<<5)
#define ADCC3_ADC12_CSR_OVR_MST         (0x1u<<4)
#define ADCC3_ADC12_CSR_EOS_MST         (0x1u<<3)
#define ADCC3_ADC12_CSR_EOC_MST         (0x1u<<2)
#define ADCC3_ADC12_CSR_EOSMP_MST       (0x1u<<1)
#define ADCC3_ADC12_CSR_ADRDY_MST       (0x1u<<0)

// ADC12_CCR Configuration

#define ADCC3_ADC12_CCR_VBATEN          (0x1u<<24)
#define ADCC3_ADC12_CCR_TSEN            (0x1u<<23)
#define ADCC3_ADC12_CCR_VREFEN          (0x1u<<22)
#define ADCC3_ADC12_CCR_DAMDF           (0x3u<<14)
#define ADCC3_ADC12_CCR_DAMDF_0         (0x1u<<14)
#define ADCC3_ADC12_CCR_DELAY           (0xFu<<8)
#define ADCC3_ADC12_CCR_DELAY_0         (0x1u<<8)
#define ADCC3_ADC12_CCR_DUAL            (0x1Fu<<0)
#define ADCC3_ADC12_CCR_DUAL_0          (0x1u<<0)

#define ADCC3_ADC12_CCR_VBATEN_B_0X0    (0x0u<<24)
#define ADCC3_ADC12_CCR_VBATEN_B_0X1    (0x1u<<24)
#define ADCC3_ADC12_CCR_TSEN_B_0X0      (0x0u<<23)
#define ADCC3_ADC12_CCR_TSEN_B_0X1      (0x1u<<23)
#define ADCC3_ADC12_CCR_VREFEN_B_0X0    (0x0u<<22)
#define ADCC3_ADC12_CCR_VREFEN_B_0X1    (0x1u<<22)
#define ADCC3_ADC12_CCR_DAMDF_B_0X0     (0x0u<<14)
#define ADCC3_ADC12_CCR_DAMDF_B_0X2     (0x2u<<14)
#define ADCC3_ADC12_CCR_DAMDF_B_0X3     (0x3u<<14)
#define ADCC3_ADC12_CCR_DUAL_B_0X0      (0x0u<<0)
#define ADCC3_ADC12_CCR_DUAL_B_0X1      (0x1u<<0)
#define ADCC3_ADC12_CCR_DUAL_B_0X2      (0x2u<<0)
#define ADCC3_ADC12_CCR_DUAL_B_0X3      (0x3u<<0)
#define ADCC3_ADC12_CCR_DUAL_B_0X5      (0x5u<<0)
#define ADCC3_ADC12_CCR_DUAL_B_0X6      (0x6u<<0)
#define ADCC3_ADC12_CCR_DUAL_B_0X7      (0x7u<<0)
#define ADCC3_ADC12_CCR_DUAL_B_0X9      (0x9u<<0)

// ADC12_CDR Configuration

#define ADCC3_ADC12_CDR_RDATA_SLV       (0xFFFFu<<16)
#define ADCC3_ADC12_CDR_RDATA_SLV_0     (0x1u<<16)
#define ADCC3_ADC12_CDR_RDATA_MST       (0xFFFFu<<0)
#define ADCC3_ADC12_CDR_RDATA_MST_0     (0x1u<<0)

// ADC12_CDR2 Configuration

#define ADCC3_ADC12_CDR2_RDATA_ALT      (0xFFFFFFFFu<<0)
#define ADCC3_ADC12_CDR2_RDATA_ALT_0    (0x1u<<0)
