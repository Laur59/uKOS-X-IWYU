/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_wwdg equates.
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

#if (defined(__cplusplus))
#define WWDG_NS     reinterpret_cast<WWDG_TypeDef *>(0x40002C00u)
#define WWDG_S      reinterpret_cast<WWDG_TypeDef *>(0x50002C00u)

#else
#define WWDG_NS     ((WWDG_TypeDef *)0x40002C00u)
#define WWDG_S      ((WWDG_TypeDef *)0x50002C00u)
#endif

// CR Configuration

#define WWDG_CR_WDGA            (0x1u<<7)
#define WWDG_CR_T               (0x7Fu<<0)
#define WWDG_CR_T_0             (0x1u<<0)

#define WWDG_CR_WDGA_B_0X0      (0x0u<<7)
#define WWDG_CR_WDGA_B_0X1      (0x1u<<7)

// CFR Configuration

#define WWDG_CFR_WDGTB          (0x7u<<11)
#define WWDG_CFR_WDGTB_0        (0x1u<<11)
#define WWDG_CFR_EWI            (0x1u<<9)
#define WWDG_CFR_W              (0x7Fu<<0)
#define WWDG_CFR_W_0            (0x1u<<0)

#define WWDG_CFR_WDGTB_B_0X0    (0x0u<<11)
#define WWDG_CFR_WDGTB_B_0X1    (0x1u<<11)
#define WWDG_CFR_WDGTB_B_0X2    (0x2u<<11)
#define WWDG_CFR_WDGTB_B_0X3    (0x3u<<11)
#define WWDG_CFR_WDGTB_B_0X4    (0x4u<<11)
#define WWDG_CFR_WDGTB_B_0X5    (0x5u<<11)
#define WWDG_CFR_WDGTB_B_0X6    (0x6u<<11)
#define WWDG_CFR_WDGTB_B_0X7    (0x7u<<11)

// SR Configuration

#define WWDG_SR_EWIF            (0x1u<<0)
