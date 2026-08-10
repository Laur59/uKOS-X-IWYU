/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_aes equates.
 */

#pragma once

#include    <stdint.h>

// AES address definitions
// -----------------------

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
    volatile    uint32_t    SUSP0R;
    volatile    uint32_t    SUSP1R;
    volatile    uint32_t    SUSP2R;
    volatile    uint32_t    SUSP3R;
    volatile    uint32_t    SUSP4R;
    volatile    uint32_t    SUSP5R;
    volatile    uint32_t    SUSP6R;
    volatile    uint32_t    SUSP7R;
    volatile    uint32_t    RESERVED0[168];
    volatile    uint32_t    IER;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
} AES_TypeDef;

#ifdef __cplusplus
#define AES_NS  reinterpret_cast<AES_TypeDef *>(0x420C0000U)
#define AES_S   reinterpret_cast<AES_TypeDef *>(0x520C0000U)

#else
#define AES_NS  ((AES_TypeDef *)0x420C0000U)
#define AES_S   ((AES_TypeDef *)0x520C0000U)
#endif

// CR Configuration

#define AES_CR_EN               (0x1U<<0U)
#define AES_CR_DATATYPE         (0x3U<<1U)
#define AES_CR_DATATYPE_0       (0x1U<<1U)
#define AES_CR_MODE             (0x3U<<3U)
#define AES_CR_MODE_0           (0x1U<<3U)
#define AES_CR_CHMOD            (0x3U<<5U)
#define AES_CR_CHMOD_0          (0x1U<<5U)
#define AES_CR_DMAINEN          (0x1U<<11U)
#define AES_CR_DMAOUTEN         (0x1U<<12U)
#define AES_CR_GCMPH            (0x3U<<13U)
#define AES_CR_GCMPH_0          (0x1U<<13U)
#define AES_CR_CHMOD_2          (0x1U<<16U)
#define AES_CR_KEYSIZE          (0x1U<<18U)
#define AES_CR_NPBLB            (0xFU<<20U)
#define AES_CR_NPBLB_0          (0x1U<<20U)
#define AES_CR_KMOD             (0x3U<<24U)
#define AES_CR_KMOD_0           (0x1U<<24U)
#define AES_CR_IPRST            (0x1U<<31U)

// SR Configuration

#define AES_SR_CCF              (0x1U<<0U)
#define AES_SR_RDERR            (0x1U<<1U)
#define AES_SR_WRERR            (0x1U<<2U)
#define AES_SR_BUSY             (0x1U<<3U)
#define AES_SR_KEYVALID         (0x1U<<7U)

// DINR Configuration

#define AES_DINR_DIN            (0xFFFFFFFFU<<0U)
#define AES_DINR_DIN_0          (0x1U<<0U)

// DOUTR Configuration

#define AES_DOUTR_DOUT          (0xFFFFFFFFU<<0U)
#define AES_DOUTR_DOUT_0        (0x1U<<0U)

// KEYR0 Configuration

#define AES_KEYR0_KEY           (0xFFFFFFFFU<<0U)
#define AES_KEYR0_KEY_0         (0x1U<<0U)

// KEYR1 Configuration

#define AES_KEYR1_KEY           (0xFFFFFFFFU<<0U)
#define AES_KEYR1_KEY_0         (0x1U<<0U)

// KEYR2 Configuration

#define AES_KEYR2_KEYR          (0xFFFFFFFFU<<0U)
#define AES_KEYR2_KEYR_0        (0x1U<<0U)

// KEYR3 Configuration

#define AES_KEYR3_AES_KEYR3     (0xFFFFFFFFU<<0U)
#define AES_KEYR3_AES_KEYR3_0   (0x1U<<0U)

// IVR0 Configuration

#define AES_IVR0_IVI            (0xFFFFFFFFU<<0U)
#define AES_IVR0_IVI_0          (0x1U<<0U)

// IVR1 Configuration

#define AES_IVR1_IVI            (0xFFFFFFFFU<<0U)
#define AES_IVR1_IVI_0          (0x1U<<0U)

// IVR2 Configuration

#define AES_IVR2_IVI            (0xFFFFFFFFU<<0U)
#define AES_IVR2_IVI_0          (0x1U<<0U)

// IVR3 Configuration

#define AES_IVR3_IVI            (0xFFFFFFFFU<<0U)
#define AES_IVR3_IVI_0          (0x1U<<0U)

// KEYR4 Configuration

#define AES_KEYR4_KEY           (0xFFFFFFFFU<<0U)
#define AES_KEYR4_KEY_0         (0x1U<<0U)

// KEYR5 Configuration

#define AES_KEYR5_KEY           (0xFFFFFFFFU<<0U)
#define AES_KEYR5_KEY_0         (0x1U<<0U)

// KEYR6 Configuration

#define AES_KEYR6_KEY           (0xFFFFFFFFU<<0U)
#define AES_KEYR6_KEY_0         (0x1U<<0U)

// KEYR7 Configuration

#define AES_KEYR7_KEY           (0xFFFFFFFFU<<0U)
#define AES_KEYR7_KEY_0         (0x1U<<0U)

// SUSP0R Configuration

#define AES_SUSP0R_SUSP0        (0xFFFFFFFFU<<0U)
#define AES_SUSP0R_SUSP0_0      (0x1U<<0U)

// SUSP1R Configuration

#define AES_SUSP1R_SUSP1        (0xFFFFFFFFU<<0U)
#define AES_SUSP1R_SUSP1_0      (0x1U<<0U)

// SUSP2R Configuration

#define AES_SUSP2R_SUSP2        (0xFFFFFFFFU<<0U)
#define AES_SUSP2R_SUSP2_0      (0x1U<<0U)

// SUSP3R Configuration

#define AES_SUSP3R_SUSP3        (0xFFFFFFFFU<<0U)
#define AES_SUSP3R_SUSP3_0      (0x1U<<0U)

// SUSP4R Configuration

#define AES_SUSP4R_SUSP4        (0xFFFFFFFFU<<0U)
#define AES_SUSP4R_SUSP4_0      (0x1U<<0U)

// SUSP5R Configuration

#define AES_SUSP5R_SUSP5        (0xFFFFFFFFU<<0U)
#define AES_SUSP5R_SUSP5_0      (0x1U<<0U)

// SUSP6R Configuration

#define AES_SUSP6R_SUSP6        (0xFFFFFFFFU<<0U)
#define AES_SUSP6R_SUSP6_0      (0x1U<<0U)

// SUSP7R Configuration

#define AES_SUSP7R_SUSP7        (0xFFFFFFFFU<<0U)
#define AES_SUSP7R_SUSP7_0      (0x1U<<0U)

// IER Configuration

#define AES_IER_CCFIE           (0x1U<<0U)
#define AES_IER_RWEIE           (0x1U<<1U)
#define AES_IER_KEIE            (0x1U<<2U)

// ISR Configuration

#define AES_ISR_CCF             (0x1U<<0U)
#define AES_ISR_RWEIF           (0x1U<<1U)
#define AES_ISR_KEIF            (0x1U<<2U)

// ICR Configuration

#define AES_ICR_CCF             (0x1U<<0U)
#define AES_ICR_RWEIF           (0x1U<<1U)
#define AES_ICR_KEIF            (0x1U<<2U)
