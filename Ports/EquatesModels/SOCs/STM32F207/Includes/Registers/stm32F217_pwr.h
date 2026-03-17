/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32F217_pwr.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32F217_pwr equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define PWR_CR_LPDS     (0x1U<<0)
#define PWR_CR_PDDS     (0x1U<<1)
#define PWR_CR_CWUF     (0x1U<<2)
#define PWR_CR_CSBF     (0x1U<<3)
#define PWR_CR_PVDE     (0x1U<<4)
#define PWR_CR_PLS      (0x7U<<5)
#define PWR_CR_PLS_0    (0x1U<<5)
#define PWR_CR_DBP      (0x1U<<8)
#define PWR_CR_FPDS     (0x1U<<9)

// CSR Configuration

#define PWR_CSR_WUF     (0x1U<<0)
#define PWR_CSR_SBF     (0x1U<<1)
#define PWR_CSR_PVDO    (0x1U<<2)
#define PWR_CSR_BRR     (0x1U<<3)
#define PWR_CSR_EWUP    (0x1U<<8)
#define PWR_CSR_BRE     (0x1U<<9)
