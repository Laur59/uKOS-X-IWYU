/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_eppb equates.
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

#define EPPB_NMI_MASK0_NMI_MASK0    (0xFFFFFFFFU<<0U)
#define EPPB_NMI_MASK0_NMI_MASK0_0  (0x1U<<0U)

// NMI_MASK1 Configuration

#define EPPB_NMI_MASK1_NMI_MASK1    (0xFFFFFU<<0U)
#define EPPB_NMI_MASK1_NMI_MASK1_0  (0x1U<<0U)

// SLEEPCTRL Configuration

#define EPPB_SLEEPCTRL_LIGHT_SLEEP  (0x1U<<0U)
#define EPPB_SLEEPCTRL_WICENREQ     (0x1U<<1U)
#define EPPB_SLEEPCTRL_WICENACK     (0x1U<<2U)
