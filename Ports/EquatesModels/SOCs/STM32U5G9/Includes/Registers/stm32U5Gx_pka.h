/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_pka equates.
 */

#pragma once

#include    <stdint.h>

// PKA address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    CLRFR;
} PKA_TypeDef;

#ifdef __cplusplus
#define PKA_NS  reinterpret_cast<PKA_TypeDef *>(0x420C2000U)
#define PKA_S   reinterpret_cast<PKA_TypeDef *>(0x520C2000U)

#else
#define PKA_NS  ((PKA_TypeDef *)0x420C2000U)
#define PKA_S   ((PKA_TypeDef *)0x520C2000U)
#endif

// CR Configuration

#define PKA_CR_EN           (0x1U<<0)
#define PKA_CR_START        (0x1U<<1)
#define PKA_CR_MODE         (0x3FU<<8)
#define PKA_CR_MODE_0       (0x1U<<8)
#define PKA_CR_PROCENDIE    (0x1U<<17)
#define PKA_CR_RAMERRIE     (0x1U<<19)
#define PKA_CR_ADDRERRIE    (0x1U<<20)
#define PKA_CR_OPERRIE      (0x1U<<21)

// SR Configuration

#define PKA_SR_OPERRF       (0x1U<<21)
#define PKA_SR_ADDRERRF     (0x1U<<20)
#define PKA_SR_RAMERRF      (0x1U<<19)
#define PKA_SR_PROCENDF     (0x1U<<17)
#define PKA_SR_BUSY         (0x1U<<16)
#define PKA_SR_INITOK       (0x1U<<0)

// CLRFR Configuration

#define PKA_CLRFR_OPERRFC   (0x1U<<21)
#define PKA_CLRFR_ADDRERRFC (0x1U<<20)
#define PKA_CLRFR_RAMERRFC  (0x1U<<19)
#define PKA_CLRFR_PROCENDFC (0x1U<<17)
