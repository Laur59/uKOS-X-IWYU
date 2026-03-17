/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_nvic_stir.
; ====================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_nvic_stir equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// NVIC_STIR address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    STIR;
} NVIC_STIR_TypeDef;

#ifdef __cplusplus
#define NVIC_STIR   reinterpret_cast<NVIC_STIR_TypeDef *>(0xE000EF00U)

#else
#define NVIC_STIR   ((NVIC_STIR_TypeDef *)0xE000EF00U)
#endif

// STIR Configuration

#define NVIC_STIR_STIR_INTID    (0x1FFU<<0)
#define NVIC_STIR_STIR_INTID_0  (0x1U<<0)
