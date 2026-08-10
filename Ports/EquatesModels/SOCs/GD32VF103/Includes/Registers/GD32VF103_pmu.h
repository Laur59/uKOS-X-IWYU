/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_pmu equates.
 */

#pragma once

#include    <stdint.h>

// PMU address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CTL;
    volatile    uint32_t    CS;
} PMU_TypeDef;

#ifdef __cplusplus
#define PMU reinterpret_cast<PMU_TypeDef *>(0x40007000U)

#else
#define PMU ((PMU_TypeDef *)0x40007000U)
#endif

// CTL Configuration

#define PMU_CTL_LDOLP   (0x1U<<0U)
#define PMU_CTL_STBMOD  (0x1U<<1U)
#define PMU_CTL_WURST   (0x1U<<2U)
#define PMU_CTL_STBRST  (0x1U<<3U)
#define PMU_CTL_LVDEN   (0x1U<<4U)
#define PMU_CTL_LVDT    (0x7U<<5U)
#define PMU_CTL_LVDT_0  (0x1U<<5U)
#define PMU_CTL_BKPWEN  (0x1U<<8U)

// CS Configuration

#define PMU_CS_WUF      (0x1U<<0U)
#define PMU_CS_STBF     (0x1U<<1U)
#define PMU_CS_LVDF     (0x1U<<2U)
#define PMU_CS_WUPEN    (0x1U<<8U)
