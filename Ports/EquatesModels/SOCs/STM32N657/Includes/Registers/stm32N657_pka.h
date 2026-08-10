/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_pka equates.
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
#define PKA_NS  reinterpret_cast<PKA_TypeDef *>(0x44022000U)
#define PKA_S   reinterpret_cast<PKA_TypeDef *>(0x54022000U)

#else
#define PKA_NS  ((PKA_TypeDef *)0x44022000U)
#define PKA_S   ((PKA_TypeDef *)0x54022000U)
#endif

// CR Configuration

#define PKA_CR_OPERRIE              (0x1U<<21U)
#define PKA_CR_ADDRERRIE            (0x1U<<20U)
#define PKA_CR_RAMERRIE             (0x1U<<19U)
#define PKA_CR_PROCENDIE            (0x1U<<17U)
#define PKA_CR_MODE                 (0x3FU<<8U)
#define PKA_CR_MODE_0               (0x1U<<8U)
#define PKA_CR_START                (0x1U<<1U)
#define PKA_CR_EN                   (0x1U<<0U)

#define PKA_CR_OPERRIE_B_0X0        (0x0U<<21U)
#define PKA_CR_OPERRIE_B_0X1        (0x1U<<21U)
#define PKA_CR_ADDRERRIE_B_0X0      (0x0U<<20U)
#define PKA_CR_ADDRERRIE_B_0X1      (0x1U<<20U)
#define PKA_CR_RAMERRIE_B_0X0       (0x0U<<19U)
#define PKA_CR_RAMERRIE_B_0X1       (0x1U<<19U)
#define PKA_CR_PROCENDIE_B_0X0      (0x0U<<17U)
#define PKA_CR_PROCENDIE_B_0X1      (0x1U<<17U)
#define PKA_CR_MODE_B_0X0           (0x0U<<8U)
#define PKA_CR_MODE_B_0X1           (0x1U<<8U)
#define PKA_CR_MODE_B_0X2           (0x2U<<8U)
#define PKA_CR_MODE_B_0X3           (0x3U<<8U)
#define PKA_CR_MODE_B_0X20          (0x20U<<8U)
#define PKA_CR_MODE_B_0X24          (0x24U<<8U)
#define PKA_CR_MODE_B_0X26          (0x26U<<8U)
#define PKA_CR_MODE_B_0X28          (0x28U<<8U)
#define PKA_CR_MODE_B_0X7           (0x7U<<8U)
#define PKA_CR_MODE_B_0X8           (0x8U<<8U)
#define PKA_CR_MODE_B_0X9           (0x9U<<8U)
#define PKA_CR_MODE_B_0XA           (0xAU<<8U)
#define PKA_CR_MODE_B_0XB           (0xBU<<8U)
#define PKA_CR_MODE_B_0XC           (0xCU<<8U)
#define PKA_CR_MODE_B_0XD           (0xDU<<8U)
#define PKA_CR_MODE_B_0XE           (0xEU<<8U)
#define PKA_CR_MODE_B_0XF           (0xFU<<8U)
#define PKA_CR_MODE_B_0X10          (0x10U<<8U)
#define PKA_CR_MODE_B_0X23          (0x23U<<8U)
#define PKA_CR_MODE_B_0X27          (0x27U<<8U)
#define PKA_CR_MODE_B_0X2F          (0x2FU<<8U)
#define PKA_CR_EN_B_0X0             (0x0U<<0U)
#define PKA_CR_EN_B_0X1             (0x1U<<0U)

// SR Configuration

#define PKA_SR_OPERRF               (0x1U<<21U)
#define PKA_SR_ADDRERRF             (0x1U<<20U)
#define PKA_SR_RAMERRF              (0x1U<<19U)
#define PKA_SR_PROCENDF             (0x1U<<17U)
#define PKA_SR_BUSY                 (0x1U<<16U)
#define PKA_SR_LMF                  (0x1U<<1U)
#define PKA_SR_INITOK               (0x1U<<0U)

#define PKA_SR_OPERRF_B_0X0         (0x0U<<21U)
#define PKA_SR_OPERRF_B_0X1         (0x1U<<21U)
#define PKA_SR_ADDRERRF_B_0X0       (0x0U<<20U)
#define PKA_SR_ADDRERRF_B_0X1       (0x1U<<20U)
#define PKA_SR_RAMERRF_B_0X0        (0x0U<<19U)
#define PKA_SR_RAMERRF_B_0X1        (0x1U<<19U)
#define PKA_SR_PROCENDF_B_0X0       (0x0U<<17U)
#define PKA_SR_PROCENDF_B_0X1       (0x1U<<17U)
#define PKA_SR_BUSY_B_0X0           (0x0U<<16U)
#define PKA_SR_BUSY_B_0X1           (0x1U<<16U)
#define PKA_SR_LMF_B_0X0            (0x0U<<1U)
#define PKA_SR_LMF_B_0X1            (0x1U<<1U)
#define PKA_SR_INITOK_B_0X0         (0x0U<<0U)
#define PKA_SR_INITOK_B_0X1         (0x1U<<0U)

// CLRFR Configuration

#define PKA_CLRFR_OPERRFC           (0x1U<<21U)
#define PKA_CLRFR_ADDRERRFC         (0x1U<<20U)
#define PKA_CLRFR_RAMERRFC          (0x1U<<19U)
#define PKA_CLRFR_PROCENDFC         (0x1U<<17U)

#define PKA_CLRFR_OPERRFC_B_0X0     (0x0U<<21U)
#define PKA_CLRFR_OPERRFC_B_0X1     (0x1U<<21U)
#define PKA_CLRFR_ADDRERRFC_B_0X0   (0x0U<<20U)
#define PKA_CLRFR_ADDRERRFC_B_0X1   (0x1U<<20U)
#define PKA_CLRFR_RAMERRFC_B_0X0    (0x0U<<19U)
#define PKA_CLRFR_RAMERRFC_B_0X1    (0x1U<<19U)
#define PKA_CLRFR_PROCENDFC_B_0X0   (0x0U<<17U)
#define PKA_CLRFR_PROCENDFC_B_0X1   (0x1U<<17U)
