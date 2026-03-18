/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_xspim equates.
 */

#pragma once

#include    <stdint.h>

// XSPIM address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR;
} XSPIM_TypeDef;

#ifdef __cplusplus
#define XSPIM_NS    reinterpret_cast<XSPIM_TypeDef *>(0x4802B400U)
#define XSPIM_S     reinterpret_cast<XSPIM_TypeDef *>(0x5802B400U)

#else
#define XSPIM_NS    ((XSPIM_TypeDef *)0x4802B400U)
#define XSPIM_S     ((XSPIM_TypeDef *)0x5802B400U)
#endif

// CR Configuration

#define XSPIM_CR_REQ2ACK_TIME       (0xFFU<<16)
#define XSPIM_CR_REQ2ACK_TIME_0     (0x1U<<16)
#define XSPIM_CR_CSSEL_OVR_O2       (0x1U<<6)
#define XSPIM_CR_CSSEL_OVR_O1       (0x1U<<5)
#define XSPIM_CR_CSSEL_OVR_EN       (0x1U<<4)
#define XSPIM_CR_MODE               (0x1U<<1)
#define XSPIM_CR_MUXEN              (0x1U<<0)

#define XSPIM_CR_CSSEL_OVR_O2_B_0X0 (0x0U<<6)
#define XSPIM_CR_CSSEL_OVR_O2_B_0X1 (0x1U<<6)
#define XSPIM_CR_CSSEL_OVR_O1_B_0X0 (0x0U<<5)
#define XSPIM_CR_CSSEL_OVR_O1_B_0X1 (0x1U<<5)
#define XSPIM_CR_CSSEL_OVR_EN_B_0X0 (0x0U<<4)
#define XSPIM_CR_CSSEL_OVR_EN_B_0X1 (0x1U<<4)
#define XSPIM_CR_MODE_B_0X0         (0x0U<<1)
#define XSPIM_CR_MODE_B_0X1         (0x1U<<1)
#define XSPIM_CR_MUXEN_B_0X0        (0x0U<<0)
#define XSPIM_CR_MUXEN_B_0X1        (0x1U<<0)
