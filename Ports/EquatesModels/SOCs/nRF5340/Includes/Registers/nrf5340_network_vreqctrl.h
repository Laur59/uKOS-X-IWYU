/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_vreqctrl equates.
 */

#pragma once

#include    <stdint.h>

// VREQCTRL address definitions
// ----------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[320];
    volatile    uint32_t    VREGRADIO_VREQH;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    VREGRADIO_VREQHREADY;
} VREQCTRL_TypeDef;

#ifdef __cplusplus
#define VREQCTRL_NS reinterpret_cast<VREQCTRL_TypeDef *>(0x41004000U)

#else
#define VREQCTRL_NS ((VREQCTRL_TypeDef *)0x41004000U)
#endif

// VREQH Configuration

#define VREQCTRL_VREGRADIO_VREQH_VREQH                  (0x1U<<0U)
#define VREQCTRL_VREGRADIO_VREQH_VREQH_DISABLED         (0x0U<<0U)
#define VREQCTRL_VREGRADIO_VREQH_VREQH_ENABLED          (0x1U<<0U)

// VREQHREADY Configuration

#define VREQCTRL_VREGRADIO_VREQHREADY_READY             (0x1U<<0U)
#define VREQCTRL_VREGRADIO_VREQHREADY_READY_NOTREADY    (0x0U<<0U)
#define VREQCTRL_VREGRADIO_VREQHREADY_READY_READY       (0x1U<<0U)
