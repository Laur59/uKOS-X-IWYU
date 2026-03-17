/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; systick.
; ========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     SYSTICK equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// SYSTICK address definitions
// ---------------------------

typedef struct {
    volatile            uint32_t    CTRL;
    volatile            uint32_t    LOAD;
    volatile            uint32_t    VAL;
    volatile    const   uint32_t    CALIB;
} SysTick_TypeDef;

#ifdef __cplusplus
#define SysTick_S   reinterpret_cast<SysTick_TypeDef *>(0xE000E010U)
#define SysTick_NS  reinterpret_cast<SysTick_TypeDef *>(0xE002E010U)

#else
#define SysTick_S   ((SysTick_TypeDef *)0xE000E010U)
#define SysTick_NS  ((SysTick_TypeDef *)0xE002E010U)
#endif

// SysTick_CTRL register

#define SysTick_CTRL_ENABLE         0x00000001U
#define SysTick_CTRL_TICKINT        0x00000002U
#define SysTick_CTRL_CLKSOURCE      0x00000004U
#define SysTick_CTRL_COUNTFLAG      0x00010000U
