/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_dlyb equates.
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
#define DLYBOS1_NS  reinterpret_cast<DLYB_TypeDef *>(0x420CF000U)
#define DLYBOS1_S   reinterpret_cast<DLYB_TypeDef *>(0x520CF000U)
#define DLYBOS2_NS  reinterpret_cast<DLYB_TypeDef *>(0x420CF400U)
#define DLYBOS2_S   reinterpret_cast<DLYB_TypeDef *>(0x520CF400U)
#define DLYBSD1_NS  reinterpret_cast<DLYB_TypeDef *>(0x420C8400U)
#define DLYBSD1_S   reinterpret_cast<DLYB_TypeDef *>(0x520C8400U)
#define DLYBSD2_NS  reinterpret_cast<DLYB_TypeDef *>(0x420C8800U)
#define DLYBSD2_S   reinterpret_cast<DLYB_TypeDef *>(0x520C8800U)

#else
#define DLYBOS1_NS  ((DLYB_TypeDef *)0x420CF000U)
#define DLYBOS1_S   ((DLYB_TypeDef *)0x520CF000U)
#define DLYBOS2_NS  ((DLYB_TypeDef *)0x420CF400U)
#define DLYBOS2_S   ((DLYB_TypeDef *)0x520CF400U)
#define DLYBSD1_NS  ((DLYB_TypeDef *)0x420C8400U)
#define DLYBSD1_S   ((DLYB_TypeDef *)0x520C8400U)
#define DLYBSD2_NS  ((DLYB_TypeDef *)0x420C8800U)
#define DLYBSD2_S   ((DLYB_TypeDef *)0x520C8800U)
#endif

// CR Configuration

#define DLYB_CR_SEN         (0x1U<<1)
#define DLYB_CR_DEN         (0x1U<<0)

// CFGR Configuration

#define DLYB_CFGR_LNGF      (0x1U<<31)
#define DLYB_CFGR_LNG       (0xFFFU<<16)
#define DLYB_CFGR_LNG_0     (0x1U<<16)
#define DLYB_CFGR_UNIT      (0x7FU<<8)
#define DLYB_CFGR_UNIT_0    (0x1U<<8)
#define DLYB_CFGR_SEL       (0xFU<<0)
#define DLYB_CFGR_SEL_0     (0x1U<<0)
