/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_vref.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_vref equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// VREF address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    CCR;
} VREF_TypeDef;

#ifdef __cplusplus
#define VREFBUF_NS  reinterpret_cast<VREF_TypeDef *>(0x46007400U)
#define VREFBUF_S   reinterpret_cast<VREF_TypeDef *>(0x56007400U)

#else
#define VREFBUF_NS  ((VREF_TypeDef *)0x46007400U)
#define VREFBUF_S   ((VREF_TypeDef *)0x56007400U)
#endif

// CSR Configuration

#define VREF_CSR_VRS    (0x7U<<4)
#define VREF_CSR_VRS_0  (0x1U<<4)
#define VREF_CSR_VRR    (0x1U<<3)
#define VREF_CSR_HIZ    (0x1U<<1)
#define VREF_CSR_ENVR   (0x1U<<0)

// CCR Configuration

#define VREF_CCR_TRIM   (0x3FU<<0)
#define VREF_CCR_TRIM_0 (0x1U<<0)
