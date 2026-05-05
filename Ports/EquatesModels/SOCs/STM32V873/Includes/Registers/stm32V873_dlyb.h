/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_dlyb equates.
 */
#pragma once

#include    <stdint.h>

// DLYB address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CFGR;
    volatile    uint32_t    CR;
} DLYB_TypeDef;

#if (defined(__cplusplus))
#define DLYB1_NS    reinterpret_cast<DLYB_TypeDef *>(0x48027400u)
#define DLYB1_S     reinterpret_cast<DLYB_TypeDef *>(0x58027400u)
#define DLYB2_NS    reinterpret_cast<DLYB_TypeDef *>(0x48026C00u)
#define DLYB2_S     reinterpret_cast<DLYB_TypeDef *>(0x58026C00u)

#else
#define DLYB1_NS    ((DLYB_TypeDef *)0x48027400u)
#define DLYB1_S     ((DLYB_TypeDef *)0x58027400u)
#define DLYB2_NS    ((DLYB_TypeDef *)0x48026C00u)
#define DLYB2_S     ((DLYB_TypeDef *)0x58026C00u)
#endif

// CFGR Configuration

#define DLYB_CFGR_SEL       (0x3Fu<<0)
#define DLYB_CFGR_SEL_0     (0x1u<<0)

// CR Configuration

#define DLYB_CR_DEN         (0x1u<<0)

#define DLYB_CR_DEN_B_0X0   (0x0u<<0)
#define DLYB_CR_DEN_B_0X1   (0x1u<<0)
