/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_xspim equates.
 */
#pragma once

#include    <stdint.h>

// XSPIM address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR;
} XSPIM_TypeDef;

#if (defined(__cplusplus))
#define XSPIM_NS    reinterpret_cast<XSPIM_TypeDef *>(0x4802B400u)
#define XSPIM_S     reinterpret_cast<XSPIM_TypeDef *>(0x5802B400u)

#else
#define XSPIM_NS    ((XSPIM_TypeDef *)0x4802B400u)
#define XSPIM_S     ((XSPIM_TypeDef *)0x5802B400u)
#endif

// CR Configuration

#define XSPIM_CR_REQ2ACK_TIME       (0xFFu<<16)
#define XSPIM_CR_REQ2ACK_TIME_0     (0x1u<<16)
#define XSPIM_CR_CSSEL_OVR_O2       (0x1u<<6)
#define XSPIM_CR_CSSEL_OVR_O1       (0x1u<<5)
#define XSPIM_CR_CSSEL_OVR_EN       (0x1u<<4)
#define XSPIM_CR_MODE               (0x1u<<1)
#define XSPIM_CR_MUXEN              (0x1u<<0)

#define XSPIM_CR_CSSEL_OVR_O2_B_0X0 (0x0u<<6)
#define XSPIM_CR_CSSEL_OVR_O2_B_0X1 (0x1u<<6)
#define XSPIM_CR_CSSEL_OVR_O1_B_0X0 (0x0u<<5)
#define XSPIM_CR_CSSEL_OVR_O1_B_0X1 (0x1u<<5)
#define XSPIM_CR_CSSEL_OVR_EN_B_0X0 (0x0u<<4)
#define XSPIM_CR_CSSEL_OVR_EN_B_0X1 (0x1u<<4)
#define XSPIM_CR_MODE_B_0X0         (0x0u<<1)
#define XSPIM_CR_MODE_B_0X1         (0x1u<<1)
#define XSPIM_CR_MUXEN_B_0X0        (0x0u<<0)
#define XSPIM_CR_MUXEN_B_0X1        (0x1u<<0)
