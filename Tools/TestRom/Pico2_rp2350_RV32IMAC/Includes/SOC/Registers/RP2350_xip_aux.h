/*
 * SPDX-License-Identifier: MIT
 * Generated using the .svd description The 2025-01-01
 *
 * Goal:        RP2350_xip_aux equates.
 */

#pragma once

#include    <stdint.h>

// XIP_AUX address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    STREAM;
    volatile    uint32_t    QMI_DIRECT_TX;
    volatile    uint32_t    QMI_DIRECT_RX;
} XIP_AUX_TypeDef;

#ifdef __cplusplus
#define XIP_AUX_NS  reinterpret_cast<XIP_AUX_TypeDef *>(0x50500000U)
#define XIP_AUX_S   reinterpret_cast<XIP_AUX_TypeDef *>(0x50500000U)
#else
#define XIP_AUX_NS  ((XIP_AUX_TypeDef *)0x50500000U)
#define XIP_AUX_S   ((XIP_AUX_TypeDef *)0x50500000U)
#endif

// STREAM Configuration

#define XIP_AUX_STREAM_STREAM                   (0xFFFFFFFFU<<0)
#define XIP_AUX_STREAM_STREAM_0                 (0x1U<<0)

// QMI_DIRECT_TX Configuration

#define XIP_AUX_QMI_DIRECT_TX_DATA              (0xFFFFU<<0)
#define XIP_AUX_QMI_DIRECT_TX_DATA_0            (0x1U<<0)
#define XIP_AUX_QMI_DIRECT_TX_IWIDTH            (0x3U<<16)
#define XIP_AUX_QMI_DIRECT_TX_IWIDTH_0          (0x1U<<16)
#define XIP_AUX_QMI_DIRECT_TX_DWIDTH            (0x1U<<18)
#define XIP_AUX_QMI_DIRECT_TX_OE                (0x1U<<19)
#define XIP_AUX_QMI_DIRECT_TX_NOPUSH            (0x1U<<20)
#define XIP_AUX_QMI_DIRECT_TX_IWIDTH_S          (0x0U<<16)
#define XIP_AUX_QMI_DIRECT_TX_IWIDTH_D          (0x1U<<16)
#define XIP_AUX_QMI_DIRECT_TX_IWIDTH_Q          (0x2U<<16)

// QMI_DIRECT_RX Configuration

#define XIP_AUX_QMI_DIRECT_RX_QMI_DIRECT_RX     (0xFFFFU<<0)
#define XIP_AUX_QMI_DIRECT_RX_QMI_DIRECT_RX_0   (0x1U<<0)
