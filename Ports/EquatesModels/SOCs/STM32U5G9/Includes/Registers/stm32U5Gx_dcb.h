/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_dcb.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_dcb equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// DCB address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    DSCSR;
} DCB_TypeDef;

#ifdef __cplusplus
#define DCB_NS  reinterpret_cast<DCB_TypeDef *>(0xE000EE08U)

#else
#define DCB_NS  ((DCB_TypeDef *)0xE000EE08U)
#endif

// DSCSR Configuration

#define DCB_DSCSR_CDS   (0x1U<<16)
