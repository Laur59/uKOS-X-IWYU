/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_fwdgt equates.
 */

#pragma once

#include    <stdint.h>

// FWDGT address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CTL;
    volatile    uint32_t    PSC;
    volatile    uint32_t    RLD;
    volatile    uint32_t    STAT;
} FWDGT_TypeDef;

#ifdef __cplusplus
#define FWDGT   reinterpret_cast<FWDGT_TypeDef *>(0x40003000U)

#else
#define FWDGT   ((FWDGT_TypeDef *)0x40003000U)
#endif

// CTL Configuration

#define FWDGT_CTL_CMD   (0xFFFFU<<0)
#define FWDGT_CTL_CMD_0 (0x1U<<0)

// PSC Configuration

#define FWDGT_PSC_PSC   (0x7U<<0)
#define FWDGT_PSC_PSC_0 (0x1U<<0)

// RLD Configuration

#define FWDGT_RLD_RLD   (0xFFFU<<0)
#define FWDGT_RLD_RLD_0 (0x1U<<0)

// STAT Configuration

#define FWDGT_STAT_RUD  (0x1U<<1)
#define FWDGT_STAT_PUD  (0x1U<<0)
