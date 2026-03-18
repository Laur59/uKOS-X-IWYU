/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_timer6 equates.
 */

#pragma once

#include    <stdint.h>

// TIMER6 address definitions
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
} TIMER6_TypeDef;

#ifdef __cplusplus
#define TIMER6  reinterpret_cast<TIMER6_TypeDef *>(0x40001400U)

#else
#define TIMER6  ((TIMER6_TypeDef *)0x40001400U)
#endif

// CTL0 Configuration

#define TIMER6_CTL0_CEN         (0x1U<<0)
#define TIMER6_CTL0_UPDIS       (0x1U<<1)
#define TIMER6_CTL0_UPS         (0x1U<<2)
#define TIMER6_CTL0_SPM         (0x1U<<3)
#define TIMER6_CTL0_ARSE        (0x1U<<7)

// CTL1 Configuration

#define TIMER6_CTL1_MMC         (0x7U<<4)
#define TIMER6_CTL1_MMC_0       (0x1U<<4)

// DMAINTEN Configuration

#define TIMER6_DMAINTEN_UPIE    (0x1U<<0)
#define TIMER6_DMAINTEN_UPDEN   (0x1U<<8)

// INTF Configuration

#define TIMER6_INTF_UPIF        (0x1U<<0)

// SWEVG Configuration

#define TIMER6_SWEVG_UPG        (0x1U<<0)

// CNT Configuration

#define TIMER6_CNT_CNT          (0xFFFFU<<0)
#define TIMER6_CNT_CNT_0        (0x1U<<0)

// PSC Configuration

#define TIMER6_PSC_PSC          (0xFFFFU<<0)
#define TIMER6_PSC_PSC_0        (0x1U<<0)

// CAR Configuration

#define TIMER6_CAR_CARL         (0xFFFFU<<0)
#define TIMER6_CAR_CARL_0       (0x1U<<0)
