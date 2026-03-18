/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_xip_ctrl equates.
 */

#pragma once

#include    <stdint.h>

// XIP_CTRL address definitions
// ----------------------------

typedef struct {
    volatile    uint32_t    CTRL;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    STAT;
    volatile    uint32_t    CTR_HIT;
    volatile    uint32_t    CTR_ACC;
    volatile    uint32_t    STREAM_ADDR;
    volatile    uint32_t    STREAM_CTR;
    volatile    uint32_t    STREAM_FIFO;
} XIP_CTRL_TypeDef;

#ifdef __cplusplus
#define XIP_CTRL_NS reinterpret_cast<XIP_CTRL_TypeDef *>(0x400C8000U)
#define XIP_CTRL_S  reinterpret_cast<XIP_CTRL_TypeDef *>(0x400C8000U)
#else
#define XIP_CTRL_NS ((XIP_CTRL_TypeDef *)0x400C8000U)
#define XIP_CTRL_S  ((XIP_CTRL_TypeDef *)0x400C8000U)
#endif

// CTRL Configuration

#define XIP_CTRL_CTRL_EN_SECURE                 (0x1U<<0)
#define XIP_CTRL_CTRL_EN_NONSECURE              (0x1U<<1)
#define XIP_CTRL_CTRL_POWER_DOWN                (0x1U<<3)
#define XIP_CTRL_CTRL_NO_UNCACHED_SEC           (0x1U<<4)
#define XIP_CTRL_CTRL_NO_UNCACHED_NONSEC        (0x1U<<5)
#define XIP_CTRL_CTRL_NO_UNTRANSLATED_SEC       (0x1U<<6)
#define XIP_CTRL_CTRL_NO_UNTRANSLATED_NONSEC    (0x1U<<7)
#define XIP_CTRL_CTRL_MAINT_NONSEC              (0x1U<<8)
#define XIP_CTRL_CTRL_SPLIT_WAYS                (0x1U<<9)
#define XIP_CTRL_CTRL_WRITABLE_M0               (0x1U<<10)
#define XIP_CTRL_CTRL_WRITABLE_M1               (0x1U<<11)

// STAT Configuration

#define XIP_CTRL_STAT_FIFO_EMPTY                (0x1U<<1)
#define XIP_CTRL_STAT_FIFO_FULL                 (0x1U<<2)

// CTR_HIT Configuration

#define XIP_CTRL_CTR_HIT_CTR_HIT                (0xFFFFFFFFU<<0)
#define XIP_CTRL_CTR_HIT_CTR_HIT_0              (0x1U<<0)

// CTR_ACC Configuration

#define XIP_CTRL_CTR_ACC_CTR_ACC                (0xFFFFFFFFU<<0)
#define XIP_CTRL_CTR_ACC_CTR_ACC_0              (0x1U<<0)

// STREAM_ADDR Configuration

#define XIP_CTRL_STREAM_ADDR_STREAM_ADDR        (0x3FFFFFFFU<<2)
#define XIP_CTRL_STREAM_ADDR_STREAM_ADDR_0      (0x1U<<2)

// STREAM_CTR Configuration

#define XIP_CTRL_STREAM_CTR_STREAM_CTR          (0x3FFFFFU<<0)
#define XIP_CTRL_STREAM_CTR_STREAM_CTR_0        (0x1U<<0)

// STREAM_FIFO Configuration

#define XIP_CTRL_STREAM_FIFO_STREAM_FIFO        (0xFFFFFFFFU<<0)
#define XIP_CTRL_STREAM_FIFO_STREAM_FIFO_0      (0x1U<<0)
