/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_iwdg.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_iwdg equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// IWDG address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    KR;
    volatile    uint32_t    PR;
    volatile    uint32_t    RLR;
    volatile    uint32_t    SR;
    volatile    uint32_t    WINR;
} IWDG_TypeDef;

#ifdef __cplusplus
#define IWDG    reinterpret_cast<IWDG_TypeDef *>(0x40003000U)

#else
#define IWDG    ((IWDG_TypeDef *)0x40003000U)
#endif

// KR Configuration

#define IWDG_KR_KEY     (0xFFFFU<<0)
#define IWDG_KR_KEY_0   (0x1U<<0)

// PR Configuration

#define IWDG_PR_PR      (0x7U<<0)
#define IWDG_PR_PR_0    (0x1U<<0)

// RLR Configuration

#define IWDG_RLR_RL     (0xFFFU<<0)
#define IWDG_RLR_RL_0   (0x1U<<0)

// SR Configuration

#define IWDG_SR_PVU     (0x1U<<0)
#define IWDG_SR_RVU     (0x1U<<1)
#define IWDG_SR_WVU     (0x1U<<2)

// WINR Configuration

#define IWDG_WINR_WIN   (0xFFFU<<0)
#define IWDG_WINR_WIN_0 (0x1U<<0)
