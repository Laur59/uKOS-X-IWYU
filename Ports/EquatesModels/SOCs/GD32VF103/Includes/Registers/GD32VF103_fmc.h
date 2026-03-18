/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_fmc equates.
 */

#pragma once

#include    <stdint.h>

// FMC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    WS;
    volatile    uint32_t    KEY0;
    volatile    uint32_t    OBKEY;
    volatile    uint32_t    STAT0;
    volatile    uint32_t    CTL0;
    volatile    uint32_t    ADDR0;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    OBSTAT;
    volatile    uint32_t    WP;
    volatile    uint32_t    RESERVED1[55];
    volatile    uint32_t    PID;
} FMC_TypeDef;

#ifdef __cplusplus
#define FMC reinterpret_cast<FMC_TypeDef *>(0x40022000U)

#else
#define FMC ((FMC_TypeDef *)0x40022000U)
#endif

// WS Configuration

#define FMC_WS_WSCNT        (0x7U<<0)
#define FMC_WS_WSCNT_0      (0x1U<<0)

// KEY0 Configuration

#define FMC_KEY0_KEY        (0xFFFFFFFFU<<0)
#define FMC_KEY0_KEY_0      (0x1U<<0)

// OBKEY Configuration

#define FMC_OBKEY_OBKEY     (0xFFFFFFFFU<<0)
#define FMC_OBKEY_OBKEY_0   (0x1U<<0)

// STAT0 Configuration

#define FMC_STAT0_BUSY      (0x1U<<0)
#define FMC_STAT0_PGERR     (0x1U<<2)
#define FMC_STAT0_WPERR     (0x1U<<4)
#define FMC_STAT0_ENDF      (0x1U<<5)

// CTL0 Configuration

#define FMC_CTL0_PG         (0x1U<<0)
#define FMC_CTL0_PER        (0x1U<<1)
#define FMC_CTL0_MER        (0x1U<<2)
#define FMC_CTL0_OBPG       (0x1U<<4)
#define FMC_CTL0_OBER       (0x1U<<5)
#define FMC_CTL0_START      (0x1U<<6)
#define FMC_CTL0_LK         (0x1U<<7)
#define FMC_CTL0_OBWEN      (0x1U<<9)
#define FMC_CTL0_ERRIE      (0x1U<<10)
#define FMC_CTL0_ENDIE      (0x1U<<12)

// ADDR0 Configuration

#define FMC_ADDR0_ADDR      (0xFFFFFFFFU<<0)
#define FMC_ADDR0_ADDR_0    (0x1U<<0)

// OBSTAT Configuration

#define FMC_OBSTAT_DATA     (0xFFFFU<<10)
#define FMC_OBSTAT_DATA_0   (0x1U<<10)
#define FMC_OBSTAT_USER     (0xFFU<<2)
#define FMC_OBSTAT_USER_0   (0x1U<<2)
#define FMC_OBSTAT_SPC      (0x1U<<1)
#define FMC_OBSTAT_OBERR    (0x1U<<0)

// WP Configuration

#define FMC_WP_WP           (0xFFFFFFFFU<<0)
#define FMC_WP_WP_0         (0x1U<<0)

// PID Configuration

#define FMC_PID_PID         (0xFFFFFFFFU<<0)
#define FMC_PID_PID_0       (0x1U<<0)
