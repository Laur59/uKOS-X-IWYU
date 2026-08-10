/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_xosc equates.
 */

#pragma once

#include    <stdint.h>

// XOSC address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CTRL;
    volatile    uint32_t    STATUS;
    volatile    uint32_t    DORMANT;
    volatile    uint32_t    STARTUP;
    volatile    uint32_t    COUNT;
} XOSC_TypeDef;

#ifdef __cplusplus
#define XOSC_NS reinterpret_cast<XOSC_TypeDef *>(0x40048000U)
#define XOSC_S  reinterpret_cast<XOSC_TypeDef *>(0x40048000U)
#else
#define XOSC_NS ((XOSC_TypeDef *)0x40048000U)
#define XOSC_S  ((XOSC_TypeDef *)0x40048000U)
#endif

// CTRL Configuration

#define XOSC_CTRL_FREQ_RANGE                (0xFFFU<<0U)
#define XOSC_CTRL_FREQ_RANGE_0              (0x1U<<0U)
#define XOSC_CTRL_ENABLE                    (0xFFFU<<12U)
#define XOSC_CTRL_ENABLE_0                  (0x1U<<12U)
#define XOSC_CTRL_FREQ_RANGE_1_15MHZ        (0xAA0U<<0U)
#define XOSC_CTRL_FREQ_RANGE_10_30MHZ       (0xAA1U<<0U)
#define XOSC_CTRL_FREQ_RANGE_25_60MHZ       (0xAA2U<<0U)
#define XOSC_CTRL_FREQ_RANGE_40_100MHZ      (0xAA3U<<0U)
#define XOSC_CTRL_ENABLE_DISABLE            (0xD1EU<<12U)
#define XOSC_CTRL_ENABLE_ENABLE             (0xFABU<<12U)

// STATUS Configuration

#define XOSC_STATUS_FREQ_RANGE              (0x3U<<0U)
#define XOSC_STATUS_FREQ_RANGE_0            (0x1U<<0U)
#define XOSC_STATUS_ENABLED                 (0x1U<<12U)
#define XOSC_STATUS_BADWRITE                (0x1U<<24U)
#define XOSC_STATUS_STABLE                  (0x1U<<31U)
#define XOSC_STATUS_FREQ_RANGE_1_15MHZ      (0x0U<<0U)
#define XOSC_STATUS_FREQ_RANGE_10_30MHZ     (0x1U<<0U)
#define XOSC_STATUS_FREQ_RANGE_25_60MHZ     (0x2U<<0U)
#define XOSC_STATUS_FREQ_RANGE_40_100MHZ    (0x3U<<0U)

// DORMANT Configuration

#define XOSC_DORMANT_DORMANT                (0xFFFFFFFFU<<0U)
#define XOSC_DORMANT_DORMANT_0              (0x1U<<0U)
#define XOSC_DORMANT_DORMANT_DORMANT        (0x636F6D61U<<0U)
#define XOSC_DORMANT_DORMANT_WAKE           (0x77616B65U<<0U)

// STARTUP Configuration

#define XOSC_STARTUP_DELAY                  (0x3FFFU<<0U)
#define XOSC_STARTUP_DELAY_0                (0x1U<<0U)
#define XOSC_STARTUP_X4                     (0x1U<<20U)

// COUNT Configuration

#define XOSC_COUNT_COUNT                    (0xFFFFU<<0U)
#define XOSC_COUNT_COUNT_0                  (0x1U<<0U)
