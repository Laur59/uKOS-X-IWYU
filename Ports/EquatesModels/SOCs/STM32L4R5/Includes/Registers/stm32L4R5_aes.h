/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_aes.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_aes equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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
} AES_TypeDef;

#ifdef __cplusplus
#define AES reinterpret_cast<AES_TypeDef *>(0x50060000U)

#else
#define AES ((AES_TypeDef *)0x50060000U)
#endif

// CR Configuration

#define AES_CR_EN               (0x1U<<0)
#define AES_CR_DATATYPE         (0x3U<<1)
#define AES_CR_DATATYPE_0       (0x1U<<1)
#define AES_CR_MODE             (0x3U<<3)
#define AES_CR_MODE_0           (0x1U<<3)
#define AES_CR_CHMOD            (0x3U<<5)
#define AES_CR_CHMOD_0          (0x1U<<5)
#define AES_CR_CCFC             (0x1U<<7)
#define AES_CR_ERRC             (0x1U<<8)
#define AES_CR_CCFIE            (0x1U<<9)
#define AES_CR_ERRIE            (0x1U<<10)
#define AES_CR_DMAINEN          (0x1U<<11)
#define AES_CR_DMAOUTEN         (0x1U<<12)

// SR Configuration

#define AES_SR_CCF              (0x1U<<0)
#define AES_SR_RDERR            (0x1U<<1)
#define AES_SR_WRERR            (0x1U<<2)

// DINR Configuration

#define AES_DINR_AES_DINR       (0xFFFFFFFFU<<0)
#define AES_DINR_AES_DINR_0     (0x1U<<0)

// DOUTR Configuration

#define AES_DOUTR_AES_DOUTR     (0xFFFFFFFFU<<0)
#define AES_DOUTR_AES_DOUTR_0   (0x1U<<0)

// KEYR0 Configuration

#define AES_KEYR0_AES_KEYR0     (0xFFFFFFFFU<<0)
#define AES_KEYR0_AES_KEYR0_0   (0x1U<<0)

// KEYR1 Configuration

#define AES_KEYR1_AES_KEYR1     (0xFFFFFFFFU<<0)
#define AES_KEYR1_AES_KEYR1_0   (0x1U<<0)

// KEYR2 Configuration

#define AES_KEYR2_AES_KEYR2     (0xFFFFFFFFU<<0)
#define AES_KEYR2_AES_KEYR2_0   (0x1U<<0)

// KEYR3 Configuration

#define AES_KEYR3_AES_KEYR3     (0xFFFFFFFFU<<0)
#define AES_KEYR3_AES_KEYR3_0   (0x1U<<0)

// IVR0 Configuration

#define AES_IVR0_AES_IVR0       (0xFFFFFFFFU<<0)
#define AES_IVR0_AES_IVR0_0     (0x1U<<0)

// IVR1 Configuration

#define AES_IVR1_AES_IVR1       (0xFFFFFFFFU<<0)
#define AES_IVR1_AES_IVR1_0     (0x1U<<0)

// IVR2 Configuration

#define AES_IVR2_AES_IVR2       (0xFFFFFFFFU<<0)
#define AES_IVR2_AES_IVR2_0     (0x1U<<0)

// IVR3 Configuration

#define AES_IVR3_AES_IVR3       (0xFFFFFFFFU<<0)
#define AES_IVR3_AES_IVR3_0     (0x1U<<0)
