/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_oscillators equates.
 */

#pragma once

#include    <stdint.h>

// OSCILLATORS address definitions
// -------------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[369];
    volatile    uint32_t    XOSC32MCAPS;
    volatile    uint32_t    RESERVED1[62];
    volatile    uint32_t    XOSC32KI_BYPASS;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    XOSC32KI_INTCAP;
} OSCILLATORS_TypeDef;

#ifdef __cplusplus
#define OSCILLATORS_NS  reinterpret_cast<OSCILLATORS_TypeDef *>(0x40004000U)
#define OSCILLATORS_S   reinterpret_cast<OSCILLATORS_TypeDef *>(0x50004000U)

#else
#define OSCILLATORS_NS  ((OSCILLATORS_TypeDef *)0x40004000U)
#define OSCILLATORS_S   ((OSCILLATORS_TypeDef *)0x50004000U)
#endif

// XOSC32MCAPS Configuration

#define OSCILLATORS_XOSC32MCAPS_ENABLE                  (0x1U<<8U)
#define OSCILLATORS_XOSC32MCAPS_CAPVALUE                (0x1FU<<0U)
#define OSCILLATORS_XOSC32MCAPS_CAPVALUE_0              (0x1U<<0U)
#define OSCILLATORS_XOSC32MCAPS_ENABLE_DISABLED         (0x0U<<8U)
#define OSCILLATORS_XOSC32MCAPS_ENABLE_ENABLED          (0x1U<<8U)

// BYPASS Configuration

#define OSCILLATORS_XOSC32KI_BYPASS_BYPASS              (0x1U<<0U)
#define OSCILLATORS_XOSC32KI_BYPASS_BYPASS_DISABLED     (0x0U<<0U)
#define OSCILLATORS_XOSC32KI_BYPASS_BYPASS_ENABLED      (0x1U<<0U)

// INTCAP Configuration

#define OSCILLATORS_XOSC32KI_INTCAP_INTCAP              (0x3U<<0U)
#define OSCILLATORS_XOSC32KI_INTCAP_INTCAP_0            (0x1U<<0U)
#define OSCILLATORS_XOSC32KI_INTCAP_INTCAP_EXTERNAL     (0x0U<<0U)
#define OSCILLATORS_XOSC32KI_INTCAP_INTCAP_C6PF         (0x1U<<0U)
#define OSCILLATORS_XOSC32KI_INTCAP_INTCAP_C7PF         (0x2U<<0U)
#define OSCILLATORS_XOSC32KI_INTCAP_INTCAP_C9PF         (0x3U<<0U)
