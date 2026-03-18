/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_coresight_trace equates.
 */

#pragma once

#include    <stdint.h>

// CORESIGHT_TRACE address definitions
// -----------------------------------

typedef struct {
    volatile    uint32_t    CTRL_STATUS;
    volatile    uint32_t    CAPTURE_FIFO;
} CORESIGHT_TRACE_TypeDef;

#ifdef __cplusplus
#define CORESIGHT_TRACE_NS  reinterpret_cast<CORESIGHT_TRACE_TypeDef *>(0x50700000U)
#define CORESIGHT_TRACE_S   reinterpret_cast<CORESIGHT_TRACE_TypeDef *>(0x50700000U)
#else
#define CORESIGHT_TRACE_NS  ((CORESIGHT_TRACE_TypeDef *)0x50700000U)
#define CORESIGHT_TRACE_S   ((CORESIGHT_TRACE_TypeDef *)0x50700000U)
#endif

// CTRL_STATUS Configuration

#define CORESIGHT_TRACE_CTRL_STATUS_TRACE_CAPTURE_FIFO_FLUSH    (0x1U<<0)
#define CORESIGHT_TRACE_CTRL_STATUS_TRACE_CAPTURE_FIFO_OVERFLOW (0x1U<<1)

// CAPTURE_FIFO Configuration

#define CORESIGHT_TRACE_CAPTURE_FIFO_RDATA                      (0xFFFFFFFFU<<0)
#define CORESIGHT_TRACE_CAPTURE_FIFO_RDATA_0                    (0x1U<<0)
