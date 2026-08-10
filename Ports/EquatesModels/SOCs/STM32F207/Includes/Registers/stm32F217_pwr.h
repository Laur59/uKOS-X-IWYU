/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_pwr equates.
 */

#pragma once

#include    <stdint.h>

// PWR address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    CSR;
} PWR_TypeDef;

#ifdef __cplusplus
#define PWR reinterpret_cast<PWR_TypeDef *>(0x40007000U)

#else
#define PWR ((PWR_TypeDef *)0x40007000U)
#endif

// CR Configuration

#define PWR_CR_LPDS     (0x1U<<0U)
#define PWR_CR_PDDS     (0x1U<<1U)
#define PWR_CR_CWUF     (0x1U<<2U)
#define PWR_CR_CSBF     (0x1U<<3U)
#define PWR_CR_PVDE     (0x1U<<4U)
#define PWR_CR_PLS      (0x7U<<5U)
#define PWR_CR_PLS_0    (0x1U<<5U)
#define PWR_CR_DBP      (0x1U<<8U)
#define PWR_CR_FPDS     (0x1U<<9U)

// CSR Configuration

#define PWR_CSR_WUF     (0x1U<<0U)
#define PWR_CSR_SBF     (0x1U<<1U)
#define PWR_CSR_PVDO    (0x1U<<2U)
#define PWR_CSR_BRR     (0x1U<<3U)
#define PWR_CSR_EWUP    (0x1U<<8U)
#define PWR_CSR_BRE     (0x1U<<9U)
