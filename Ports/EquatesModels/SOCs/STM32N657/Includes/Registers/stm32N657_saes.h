/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_saes equates.
 */

#pragma once

#include    <stdint.h>

// SAES address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    DINR;
    volatile    uint32_t    DOUTR;
    volatile    uint32_t    KEYR0;
    volatile    uint32_t    KEYR1;
    volatile    uint32_t    KEYR2;
    volatile    uint32_t    KEYR3;
    volatile    uint32_t    IVR0;
    volatile    uint32_t    IVR1;
    volatile    uint32_t    IVR2;
    volatile    uint32_t    IVR3;
    volatile    uint32_t    KEYR4;
    volatile    uint32_t    KEYR5;
    volatile    uint32_t    KEYR6;
    volatile    uint32_t    KEYR7;
    volatile    uint32_t    SUSPR0;
    volatile    uint32_t    SUSPR1;
    volatile    uint32_t    SUSPR2;
    volatile    uint32_t    SUSPR3;
    volatile    uint32_t    SUSPR4;
    volatile    uint32_t    SUSPR5;
    volatile    uint32_t    SUSPR6;
    volatile    uint32_t    SUSPR7;
    volatile    uint32_t    RESERVED0[168];
    volatile    uint32_t    IER;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
} SAES_TypeDef;

#ifdef __cplusplus
#define SAES_NS reinterpret_cast<SAES_TypeDef *>(0x44021000U)
#define SAES_S  reinterpret_cast<SAES_TypeDef *>(0x54021000U)

#else
#define SAES_NS ((SAES_TypeDef *)0x44021000U)
#define SAES_S  ((SAES_TypeDef *)0x54021000U)
#endif

// CR Configuration

#define SAES_CR_IPRST               (0x1U<<31U)
#define SAES_CR_KEYSEL              (0x7U<<28U)
#define SAES_CR_KEYSEL_0            (0x1U<<28U)
#define SAES_CR_KSHAREID            (0x3U<<26U)
#define SAES_CR_KSHAREID_0          (0x1U<<26U)
#define SAES_CR_KMOD                (0x3U<<24U)
#define SAES_CR_KMOD_0              (0x1U<<24U)
#define SAES_CR_NPBLB               (0xFU<<20U)
#define SAES_CR_NPBLB_0             (0x1U<<20U)
#define SAES_CR_KEYPROT             (0x1U<<19U)
#define SAES_CR_KEYSIZE             (0x1U<<18U)
#define SAES_CR_CHMOD_1             (0x1U<<16U)
#define SAES_CR_GCMPH               (0x3U<<13U)
#define SAES_CR_GCMPH_0             (0x1U<<13U)
#define SAES_CR_DMAOUTEN            (0x1U<<12U)
#define SAES_CR_DMAINEN             (0x1U<<11U)
#define SAES_CR_CHMOD               (0x3U<<5U)
#define SAES_CR_CHMOD_0             (0x1U<<5U)
#define SAES_CR_MODE                (0x3U<<3U)
#define SAES_CR_MODE_0              (0x1U<<3U)
#define SAES_CR_DATATYPE            (0x3U<<1U)
#define SAES_CR_DATATYPE_0          (0x1U<<1U)
#define SAES_CR_EN                  (0x1U<<0U)

#define SAES_CR_KEYSEL_B_0X0        (0x0U<<28U)
#define SAES_CR_KEYSEL_B_0X1        (0x1U<<28U)
#define SAES_CR_KEYSEL_B_0X2        (0x2U<<28U)
#define SAES_CR_KEYSEL_B_0X4        (0x4U<<28U)
#define SAES_CR_KEYSEL_B_0X7        (0x7U<<28U)
#define SAES_CR_KSHAREID_B_0X0      (0x0U<<26U)
#define SAES_CR_KMOD_B_0X0          (0x0U<<24U)
#define SAES_CR_KMOD_B_0X1          (0x1U<<24U)
#define SAES_CR_KMOD_B_0X2          (0x2U<<24U)
#define SAES_CR_NPBLB_B_0X0         (0x0U<<20U)
#define SAES_CR_NPBLB_B_0X1         (0x1U<<20U)
#define SAES_CR_NPBLB_B_0XF         (0xFU<<20U)
#define SAES_CR_KEYPROT_B_0X0       (0x0U<<19U)
#define SAES_CR_KEYPROT_B_0X1       (0x1U<<19U)
#define SAES_CR_KEYSIZE_B_0X0       (0x0U<<18U)
#define SAES_CR_KEYSIZE_B_0X1       (0x1U<<18U)
#define SAES_CR_GCMPH_B_0X0         (0x0U<<13U)
#define SAES_CR_GCMPH_B_0X1         (0x1U<<13U)
#define SAES_CR_GCMPH_B_0X2         (0x2U<<13U)
#define SAES_CR_GCMPH_B_0X3         (0x3U<<13U)
#define SAES_CR_DMAOUTEN_B_0X0      (0x0U<<12U)
#define SAES_CR_DMAOUTEN_B_0X1      (0x1U<<12U)
#define SAES_CR_DMAINEN_B_0X0       (0x0U<<11U)
#define SAES_CR_DMAINEN_B_0X1       (0x1U<<11U)
#define SAES_CR_CHMOD_B_0X0         (0x0U<<5U)
#define SAES_CR_CHMOD_B_0X1         (0x1U<<5U)
#define SAES_CR_CHMOD_B_0X2         (0x2U<<5U)
#define SAES_CR_CHMOD_B_0X3         (0x3U<<5U)
#define SAES_CR_MODE_B_0X0          (0x0U<<3U)
#define SAES_CR_MODE_B_0X1          (0x1U<<3U)
#define SAES_CR_MODE_B_0X2          (0x2U<<3U)
#define SAES_CR_DATATYPE_B_0X0      (0x0U<<1U)
#define SAES_CR_DATATYPE_B_0X1      (0x1U<<1U)
#define SAES_CR_DATATYPE_B_0X2      (0x2U<<1U)
#define SAES_CR_DATATYPE_B_0X3      (0x3U<<1U)
#define SAES_CR_EN_B_0X0            (0x0U<<0U)
#define SAES_CR_EN_B_0X1            (0x1U<<0U)

// SR Configuration

#define SAES_SR_KEYVALID            (0x1U<<7U)
#define SAES_SR_BUSY                (0x1U<<3U)
#define SAES_SR_WRERRF              (0x1U<<2U)
#define SAES_SR_RDERRF              (0x1U<<1U)

#define SAES_SR_KEYVALID_B_0X0      (0x0U<<7U)
#define SAES_SR_KEYVALID_B_0X1      (0x1U<<7U)
#define SAES_SR_BUSY_B_0X0          (0x0U<<3U)
#define SAES_SR_BUSY_B_0X1          (0x1U<<3U)
#define SAES_SR_WRERRF_B_0X0        (0x0U<<2U)
#define SAES_SR_WRERRF_B_0X1        (0x1U<<2U)
#define SAES_SR_RDERRF_B_0X0        (0x0U<<1U)
#define SAES_SR_RDERRF_B_0X1        (0x1U<<1U)

// DINR Configuration

#define SAES_DINR_DIN               (0xFFFFFFFFU<<0U)
#define SAES_DINR_DIN_0             (0x1U<<0U)

// DOUTR Configuration

#define SAES_DOUTR_DOUT             (0xFFFFFFFFU<<0U)
#define SAES_DOUTR_DOUT_0           (0x1U<<0U)

// KEYR0 Configuration

#define SAES_KEYR0_KEY              (0xFFFFFFFFU<<0U)
#define SAES_KEYR0_KEY_0            (0x1U<<0U)

// KEYR1 Configuration

#define SAES_KEYR1_KEY              (0xFFFFFFFFU<<0U)
#define SAES_KEYR1_KEY_0            (0x1U<<0U)

// KEYR2 Configuration

#define SAES_KEYR2_KEY              (0xFFFFFFFFU<<0U)
#define SAES_KEYR2_KEY_0            (0x1U<<0U)

// KEYR3 Configuration

#define SAES_KEYR3_KEY              (0xFFFFFFFFU<<0U)
#define SAES_KEYR3_KEY_0            (0x1U<<0U)

// IVR0 Configuration

#define SAES_IVR0_IVI               (0xFFFFFFFFU<<0U)
#define SAES_IVR0_IVI_0             (0x1U<<0U)

// IVR1 Configuration

#define SAES_IVR1_IVI               (0xFFFFFFFFU<<0U)
#define SAES_IVR1_IVI_0             (0x1U<<0U)

// IVR2 Configuration

#define SAES_IVR2_IVI               (0xFFFFFFFFU<<0U)
#define SAES_IVR2_IVI_0             (0x1U<<0U)

// IVR3 Configuration

#define SAES_IVR3_IVI               (0xFFFFFFFFU<<0U)
#define SAES_IVR3_IVI_0             (0x1U<<0U)

// KEYR4 Configuration

#define SAES_KEYR4_KEY              (0xFFFFFFFFU<<0U)
#define SAES_KEYR4_KEY_0            (0x1U<<0U)

// KEYR5 Configuration

#define SAES_KEYR5_KEY              (0xFFFFFFFFU<<0U)
#define SAES_KEYR5_KEY_0            (0x1U<<0U)

// KEYR6 Configuration

#define SAES_KEYR6_KEY              (0xFFFFFFFFU<<0U)
#define SAES_KEYR6_KEY_0            (0x1U<<0U)

// KEYR7 Configuration

#define SAES_KEYR7_KEY              (0xFFFFFFFFU<<0U)
#define SAES_KEYR7_KEY_0            (0x1U<<0U)

// SUSPR0 Configuration

#define SAES_SUSPR0_SUSP            (0xFFFFFFFFU<<0U)
#define SAES_SUSPR0_SUSP_0          (0x1U<<0U)

// SUSPR1 Configuration

#define SAES_SUSPR1_SUSP            (0xFFFFFFFFU<<0U)
#define SAES_SUSPR1_SUSP_0          (0x1U<<0U)

// SUSPR2 Configuration

#define SAES_SUSPR2_SUSP            (0xFFFFFFFFU<<0U)
#define SAES_SUSPR2_SUSP_0          (0x1U<<0U)

// SUSPR3 Configuration

#define SAES_SUSPR3_SUSP            (0xFFFFFFFFU<<0U)
#define SAES_SUSPR3_SUSP_0          (0x1U<<0U)

// SUSPR4 Configuration

#define SAES_SUSPR4_SUSP            (0xFFFFFFFFU<<0U)
#define SAES_SUSPR4_SUSP_0          (0x1U<<0U)

// SUSPR5 Configuration

#define SAES_SUSPR5_SUSP            (0xFFFFFFFFU<<0U)
#define SAES_SUSPR5_SUSP_0          (0x1U<<0U)

// SUSPR6 Configuration

#define SAES_SUSPR6_SUSP            (0xFFFFFFFFU<<0U)
#define SAES_SUSPR6_SUSP_0          (0x1U<<0U)

// SUSPR7 Configuration

#define SAES_SUSPR7_SUSP            (0xFFFFFFFFU<<0U)
#define SAES_SUSPR7_SUSP_0          (0x1U<<0U)

// IER Configuration

#define SAES_IER_RNGEIE             (0x1U<<3U)
#define SAES_IER_KEIE               (0x1U<<2U)
#define SAES_IER_RWEIE              (0x1U<<1U)
#define SAES_IER_CCFIE              (0x1U<<0U)

#define SAES_IER_RNGEIE_B_0X0       (0x0U<<3U)
#define SAES_IER_RNGEIE_B_0X1       (0x1U<<3U)
#define SAES_IER_KEIE_B_0X0         (0x0U<<2U)
#define SAES_IER_KEIE_B_0X1         (0x1U<<2U)
#define SAES_IER_RWEIE_B_0X0        (0x0U<<1U)
#define SAES_IER_RWEIE_B_0X1        (0x1U<<1U)
#define SAES_IER_CCFIE_B_0X0        (0x0U<<0U)
#define SAES_IER_CCFIE_B_0X1        (0x1U<<0U)

// ISR Configuration

#define SAES_ISR_RNGEIF             (0x1U<<3U)
#define SAES_ISR_KEIF               (0x1U<<2U)
#define SAES_ISR_RWEIF              (0x1U<<1U)
#define SAES_ISR_CCF                (0x1U<<0U)

#define SAES_ISR_RNGEIF_B_0X0       (0x0U<<3U)
#define SAES_ISR_RNGEIF_B_0X1       (0x1U<<3U)
#define SAES_ISR_KEIF_B_0X0         (0x0U<<2U)
#define SAES_ISR_KEIF_B_0X1         (0x1U<<2U)
#define SAES_ISR_RWEIF_B_0X0        (0x0U<<1U)
#define SAES_ISR_RWEIF_B_0X1        (0x1U<<1U)
#define SAES_ISR_CCF_B_0X0          (0x0U<<0U)
#define SAES_ISR_CCF_B_0X1          (0x1U<<0U)

// ICR Configuration

#define SAES_ICR_RNGEIF             (0x1U<<3U)
#define SAES_ICR_KEIF               (0x1U<<2U)
#define SAES_ICR_RWEIF              (0x1U<<1U)
#define SAES_ICR_CCF                (0x1U<<0U)
