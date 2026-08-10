/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_wwdg equates.
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
#define WWDG_NS reinterpret_cast<WWDG_TypeDef *>(0x40002C00U)
#define WWDG_S  reinterpret_cast<WWDG_TypeDef *>(0x50002C00U)

#else
#define WWDG_NS ((WWDG_TypeDef *)0x40002C00U)
#define WWDG_S  ((WWDG_TypeDef *)0x50002C00U)
#endif

// CR Configuration

#define WWDG_CR_WDGA            (0x1U<<7U)
#define WWDG_CR_T               (0x7FU<<0U)
#define WWDG_CR_T_0             (0x1U<<0U)

#define WWDG_CR_WDGA_B_0X0      (0x0U<<7U)
#define WWDG_CR_WDGA_B_0X1      (0x1U<<7U)

// CFR Configuration

#define WWDG_CFR_WDGTB          (0x7U<<11U)
#define WWDG_CFR_WDGTB_0        (0x1U<<11U)
#define WWDG_CFR_EWI            (0x1U<<9U)
#define WWDG_CFR_W              (0x7FU<<0U)
#define WWDG_CFR_W_0            (0x1U<<0U)

#define WWDG_CFR_WDGTB_B_0X0    (0x0U<<11U)
#define WWDG_CFR_WDGTB_B_0X1    (0x1U<<11U)
#define WWDG_CFR_WDGTB_B_0X2    (0x2U<<11U)
#define WWDG_CFR_WDGTB_B_0X3    (0x3U<<11U)
#define WWDG_CFR_WDGTB_B_0X4    (0x4U<<11U)
#define WWDG_CFR_WDGTB_B_0X5    (0x5U<<11U)
#define WWDG_CFR_WDGTB_B_0X6    (0x6U<<11U)
#define WWDG_CFR_WDGTB_B_0X7    (0x7U<<11U)

// SR Configuration

#define WWDG_SR_EWIF            (0x1U<<0U)
