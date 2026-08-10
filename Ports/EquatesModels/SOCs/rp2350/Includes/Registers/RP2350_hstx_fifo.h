/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_hstx_fifo equates.
 */

#pragma once

#include    <stdint.h>

// HSTX_FIFO address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    STAT;
    volatile    uint32_t    FIFO;
} HSTX_FIFO_TypeDef;

#ifdef __cplusplus
#define HSTX_FIFO_NS    reinterpret_cast<HSTX_FIFO_TypeDef *>(0x50600000U)
#define HSTX_FIFO_S     reinterpret_cast<HSTX_FIFO_TypeDef *>(0x50600000U)
#else
#define HSTX_FIFO_NS    ((HSTX_FIFO_TypeDef *)0x50600000U)
#define HSTX_FIFO_S     ((HSTX_FIFO_TypeDef *)0x50600000U)
#endif

// STAT Configuration

#define HSTX_FIFO_STAT_LEVEL    (0xFFU<<0U)
#define HSTX_FIFO_STAT_LEVEL_0  (0x1U<<0U)
#define HSTX_FIFO_STAT_FULL     (0x1U<<8U)
#define HSTX_FIFO_STAT_EMPTY    (0x1U<<9U)
#define HSTX_FIFO_STAT_WOF      (0x1U<<10U)

// FIFO Configuration

#define HSTX_FIFO_FIFO_FIFO     (0xFFFFFFFFU<<0U)
#define HSTX_FIFO_FIFO_FIFO_0   (0x1U<<0U)
