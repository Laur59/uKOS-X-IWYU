/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_timer5 equates.
 */

#pragma once

#include    <stdint.h>

// TIMER5 address definitions
// --------------------------

typedef struct {
    volatile    uint16_t    CTL0;
    volatile    uint16_t    RESERVED0;
    volatile    uint16_t    CTL1;
    volatile    uint16_t    RESERVED1[3];
    volatile    uint16_t    DMAINTEN;
    volatile    uint16_t    RESERVED2;
    volatile    uint16_t    INTF;
    volatile    uint16_t    RESERVED3;
    volatile    uint16_t    SWEVG;
    volatile    uint16_t    RESERVED4[7];
    volatile    uint16_t    CNT;
    volatile    uint16_t    RESERVED5;
    volatile    uint16_t    PSC;
    volatile    uint16_t    RESERVED6;
    volatile    uint16_t    CAR;
} TIMER5_TypeDef;

#ifdef __cplusplus
#define TIMER5  reinterpret_cast<TIMER5_TypeDef *>(0x40001000U)

#else
#define TIMER5  ((TIMER5_TypeDef *)0x40001000U)
#endif

// CTL0 Configuration

#define TIMER5_CTL0_CEN         (0x1U<<0U)
#define TIMER5_CTL0_UPDIS       (0x1U<<1U)
#define TIMER5_CTL0_UPS         (0x1U<<2U)
#define TIMER5_CTL0_SPM         (0x1U<<3U)
#define TIMER5_CTL0_ARSE        (0x1U<<7U)

// CTL1 Configuration

#define TIMER5_CTL1_MMC         (0x7U<<4U)
#define TIMER5_CTL1_MMC_0       (0x1U<<4U)

// DMAINTEN Configuration

#define TIMER5_DMAINTEN_UPIE    (0x1U<<0U)
#define TIMER5_DMAINTEN_UPDEN   (0x1U<<8U)

// INTF Configuration

#define TIMER5_INTF_UPIF        (0x1U<<0U)

// SWEVG Configuration

#define TIMER5_SWEVG_UPG        (0x1U<<0U)

// CNT Configuration

#define TIMER5_CNT_CNT          (0xFFFFU<<0U)
#define TIMER5_CNT_CNT_0        (0x1U<<0U)

// PSC Configuration

#define TIMER5_PSC_PSC          (0xFFFFU<<0U)
#define TIMER5_PSC_PSC_0        (0x1U<<0U)

// CAR Configuration

#define TIMER5_CAR_CARL         (0xFFFFU<<0U)
#define TIMER5_CAR_CARL_0       (0x1U<<0U)
