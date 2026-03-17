/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_saes.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_saes equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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
    volatile    uint32_t    RESERVED0[48];
    volatile    uint32_t    DPACFGR;
    volatile    uint32_t    RESERVED1[127];
    volatile    uint32_t    IER;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
} SAES_TypeDef;

#ifdef __cplusplus
#define SAES_NS reinterpret_cast<SAES_TypeDef *>(0x420C0C00U)
#define SAES_S  reinterpret_cast<SAES_TypeDef *>(0x520C0C00U)

#else
#define SAES_NS ((SAES_TypeDef *)0x420C0C00U)
#define SAES_S  ((SAES_TypeDef *)0x520C0C00U)
#endif

// CR Configuration

#define SAES_CR_EN              (0x1U<<0)
#define SAES_CR_DATATYPE        (0x3U<<1)
#define SAES_CR_DATATYPE_0      (0x1U<<1)
#define SAES_CR_MODE            (0x3U<<3)
#define SAES_CR_MODE_0          (0x1U<<3)
#define SAES_CR_CHMOD           (0x3U<<5)
#define SAES_CR_CHMOD_0         (0x1U<<5)
#define SAES_CR_DMAINEN         (0x1U<<11)
#define SAES_CR_DMAOUTEN        (0x1U<<12)
#define SAES_CR_KEYSIZE         (0x1U<<18)
#define SAES_CR_KEYPROT         (0x1U<<19)
#define SAES_CR_KMOD            (0x3U<<24)
#define SAES_CR_KMOD_0          (0x1U<<24)
#define SAES_CR_KSHAREID        (0x3U<<26)
#define SAES_CR_KSHAREID_0      (0x1U<<26)
#define SAES_CR_KEYSEL          (0x7U<<28)
#define SAES_CR_KEYSEL_0        (0x1U<<28)
#define SAES_CR_IPRST           (0x1U<<31)

// SR Configuration

#define SAES_SR_CCF             (0x1U<<0)
#define SAES_SR_RDERR           (0x1U<<1)
#define SAES_SR_WRERR           (0x1U<<2)
#define SAES_SR_BUSY            (0x1U<<3)
#define SAES_SR_KEYVALID        (0x1U<<7)

// DINR Configuration

#define SAES_DINR_DIN           (0xFFFFFFFFU<<0)
#define SAES_DINR_DIN_0         (0x1U<<0)

// DOUTR Configuration

#define SAES_DOUTR_DOUT         (0xFFFFFFFFU<<0)
#define SAES_DOUTR_DOUT_0       (0x1U<<0)

// KEYR0 Configuration

#define SAES_KEYR0_KEY          (0xFFFFFFFFU<<0)
#define SAES_KEYR0_KEY_0        (0x1U<<0)

// KEYR1 Configuration

#define SAES_KEYR1_KEY          (0xFFFFFFFFU<<0)
#define SAES_KEYR1_KEY_0        (0x1U<<0)

// KEYR2 Configuration

#define SAES_KEYR2_KEYR         (0xFFFFFFFFU<<0)
#define SAES_KEYR2_KEYR_0       (0x1U<<0)

// KEYR3 Configuration

#define SAES_KEYR3_SAES_KEYR3   (0xFFFFFFFFU<<0)
#define SAES_KEYR3_SAES_KEYR3_0 (0x1U<<0)

// IVR0 Configuration

#define SAES_IVR0_IVI           (0xFFFFFFFFU<<0)
#define SAES_IVR0_IVI_0         (0x1U<<0)

// IVR1 Configuration

#define SAES_IVR1_IVI           (0xFFFFFFFFU<<0)
#define SAES_IVR1_IVI_0         (0x1U<<0)

// IVR2 Configuration

#define SAES_IVR2_IVI           (0xFFFFFFFFU<<0)
#define SAES_IVR2_IVI_0         (0x1U<<0)

// IVR3 Configuration

#define SAES_IVR3_IVI           (0xFFFFFFFFU<<0)
#define SAES_IVR3_IVI_0         (0x1U<<0)

// KEYR4 Configuration

#define SAES_KEYR4_KEY          (0xFFFFFFFFU<<0)
#define SAES_KEYR4_KEY_0        (0x1U<<0)

// KEYR5 Configuration

#define SAES_KEYR5_KEY          (0xFFFFFFFFU<<0)
#define SAES_KEYR5_KEY_0        (0x1U<<0)

// KEYR6 Configuration

#define SAES_KEYR6_KEY          (0xFFFFFFFFU<<0)
#define SAES_KEYR6_KEY_0        (0x1U<<0)

// KEYR7 Configuration

#define SAES_KEYR7_KEY          (0xFFFFFFFFU<<0)
#define SAES_KEYR7_KEY_0        (0x1U<<0)

// DPACFGR Configuration

#define SAES_DPACFGR_REDCFG     (0x1U<<1)
#define SAES_DPACFGR_RESEED     (0x1U<<2)
#define SAES_DPACFGR_TRIMCFG    (0x3U<<3)
#define SAES_DPACFGR_TRIMCFG_0  (0x1U<<3)
#define SAES_DPACFGR_CONFIGLOCK (0x1U<<31)

// IER Configuration

#define SAES_IER_CCFIE          (0x1U<<0)
#define SAES_IER_RWEIE          (0x1U<<1)
#define SAES_IER_KEIE           (0x1U<<2)
#define SAES_IER_RNGEIE         (0x1U<<3)

// ISR Configuration

#define SAES_ISR_CCF            (0x1U<<0)
#define SAES_ISR_RWEIF          (0x1U<<1)
#define SAES_ISR_KEIF           (0x1U<<2)
#define SAES_ISR_RNGEIF         (0x1U<<3)

// ICR Configuration

#define SAES_ICR_CCF            (0x1U<<0)
#define SAES_ICR_RWEIF          (0x1U<<1)
#define SAES_ICR_KEIF           (0x1U<<2)
#define SAES_ICR_RNGEIF         (0x1U<<3)
