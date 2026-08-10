/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_dlyb equates.
 */

#pragma once

#include    <stdint.h>

// DLYB address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    CFGR;
} DLYB_TypeDef;

#ifdef __cplusplus
#define DELAY_BLOCK_SDMMC1  reinterpret_cast<DLYB_TypeDef *>(0x52008000U)
#define DELAY_BLOCK_QUADSPI reinterpret_cast<DLYB_TypeDef *>(0x52006000U)
#define DELAY_BLOCK_SDMMC2  reinterpret_cast<DLYB_TypeDef *>(0x48022800U)

#else
#define DELAY_BLOCK_SDMMC1  ((DLYB_TypeDef *)0x52008000U)
#define DELAY_BLOCK_QUADSPI ((DLYB_TypeDef *)0x52006000U)
#define DELAY_BLOCK_SDMMC2  ((DLYB_TypeDef *)0x48022800U)
#endif

// CR Configuration

#define DLYB_CR_SEN         (0x1U<<1U)
#define DLYB_CR_DEN         (0x1U<<0U)

// CFGR Configuration

#define DLYB_CFGR_LNGF      (0x1U<<31U)
#define DLYB_CFGR_LNG       (0xFFFU<<16U)
#define DLYB_CFGR_LNG_0     (0x1U<<16U)
#define DLYB_CFGR_UNIT      (0x7FU<<8U)
#define DLYB_CFGR_UNIT_0    (0x1U<<8U)
#define DLYB_CFGR_SEL       (0xFU<<0U)
#define DLYB_CFGR_SEL_0     (0x1U<<0U)
