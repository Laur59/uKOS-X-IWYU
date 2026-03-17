/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_wwdg.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_wwdg equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// WWDG address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    CFR;
    volatile    uint32_t    SR;
} WWDG_TypeDef;

#ifdef __cplusplus
#define WWDG    reinterpret_cast<WWDG_TypeDef *>(0x40002C00U)

#else
#define WWDG    ((WWDG_TypeDef *)0x40002C00U)
#endif

// CR Configuration

#define WWDG_CR_T           (0x7FU<<0)
#define WWDG_CR_T_0         (0x1U<<0)
#define WWDG_CR_WDGA        (0x1U<<7)

// CFR Configuration

#define WWDG_CFR_W          (0x7FU<<0)
#define WWDG_CFR_W_0        (0x1U<<0)
#define WWDG_CFR_WDGTB      (0x3U<<7)
#define WWDG_CFR_WDGTB_0    (0x1U<<7)
#define WWDG_CFR_EWI        (0x1U<<9)

// SR Configuration

#define WWDG_SR_EWIF        (0x1U<<0)
