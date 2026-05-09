/*
 * SPDX-License-Identifier: MIT
 * Generated using the .svd description The 2025-01-01
 *
 * Goal:        RP2350_eppb equates.
 */

#pragma once

#include    <stdint.h>

// EPPB address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    NMI_MASK0;
    volatile    uint32_t    NMI_MASK1;
    volatile    uint32_t    SLEEPCTRL;
} EPPB_TypeDef;

#ifdef __cplusplus
#define EPPB_NS reinterpret_cast<EPPB_TypeDef *>(0xE0080000U)
#define EPPB_S  reinterpret_cast<EPPB_TypeDef *>(0xE0080000U)
#else
#define EPPB_NS ((EPPB_TypeDef *)0xE0080000U)
#define EPPB_S  ((EPPB_TypeDef *)0xE0080000U)
#endif

// NMI_MASK0 Configuration

#define EPPB_NMI_MASK0_NMI_MASK0    (0xFFFFFFFFU<<0)
#define EPPB_NMI_MASK0_NMI_MASK0_0  (0x1U<<0)

// NMI_MASK1 Configuration

#define EPPB_NMI_MASK1_NMI_MASK1    (0xFFFFFU<<0)
#define EPPB_NMI_MASK1_NMI_MASK1_0  (0x1U<<0)

// SLEEPCTRL Configuration

#define EPPB_SLEEPCTRL_LIGHT_SLEEP  (0x1U<<0)
#define EPPB_SLEEPCTRL_WICENREQ     (0x1U<<1)
#define EPPB_SLEEPCTRL_WICENACK     (0x1U<<2)
