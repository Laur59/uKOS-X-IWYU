/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_vmc equates.
 */

#pragma once

#include    <stdint.h>

// VMC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    RESERVED0[384];
    volatile    uint32_t    RAM0_POWER;
    volatile    uint32_t    RAM0_POWERSET;
    volatile    uint32_t    RAM0_POWERCLR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    RAM1_POWER;
    volatile    uint32_t    RAM1_POWERSET;
    volatile    uint32_t    RAM1_POWERCLR;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    RAM2_POWER;
    volatile    uint32_t    RAM2_POWERSET;
    volatile    uint32_t    RAM2_POWERCLR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    RAM3_POWER;
    volatile    uint32_t    RAM3_POWERSET;
    volatile    uint32_t    RAM3_POWERCLR;
} VMC_TypeDef;

#ifdef __cplusplus
#define VMC_NS  reinterpret_cast<VMC_TypeDef *>(0x41081000U)

#else
#define VMC_NS  ((VMC_TypeDef *)0x41081000U)
#endif

// POWER Configuration

#define VMC_RAM_POWER_S3RETENTION           (0x1U<<19)
#define VMC_RAM_POWER_S2RETENTION           (0x1U<<18)
#define VMC_RAM_POWER_S1RETENTION           (0x1U<<17)
#define VMC_RAM_POWER_S0RETENTION           (0x1U<<16)
#define VMC_RAM_POWER_S3POWER               (0x1U<<3)
#define VMC_RAM_POWER_S2POWER               (0x1U<<2)
#define VMC_RAM_POWER_S1POWER               (0x1U<<1)
#define VMC_RAM_POWER_S0POWER               (0x1U<<0)
#define VMC_RAM_POWER_S3RETENTION_OFF       (0x0U<<19)
#define VMC_RAM_POWER_S3RETENTION_ON        (0x1U<<19)
#define VMC_RAM_POWER_S2RETENTION_OFF       (0x0U<<18)
#define VMC_RAM_POWER_S2RETENTION_ON        (0x1U<<18)
#define VMC_RAM_POWER_S1RETENTION_OFF       (0x0U<<17)
#define VMC_RAM_POWER_S1RETENTION_ON        (0x1U<<17)
#define VMC_RAM_POWER_S0RETENTION_OFF       (0x0U<<16)
#define VMC_RAM_POWER_S0RETENTION_ON        (0x1U<<16)
#define VMC_RAM_POWER_S3POWER_OFF           (0x0U<<3)
#define VMC_RAM_POWER_S3POWER_ON            (0x1U<<3)
#define VMC_RAM_POWER_S2POWER_OFF           (0x0U<<2)
#define VMC_RAM_POWER_S2POWER_ON            (0x1U<<2)
#define VMC_RAM_POWER_S1POWER_OFF           (0x0U<<1)
#define VMC_RAM_POWER_S1POWER_ON            (0x1U<<1)
#define VMC_RAM_POWER_S0POWER_OFF           (0x0U<<0)
#define VMC_RAM_POWER_S0POWER_ON            (0x1U<<0)

// POWERSET Configuration

#define VMC_RAM_POWERSET_S3RETENTION        (0x1U<<19)
#define VMC_RAM_POWERSET_S2RETENTION        (0x1U<<18)
#define VMC_RAM_POWERSET_S1RETENTION        (0x1U<<17)
#define VMC_RAM_POWERSET_S0RETENTION        (0x1U<<16)
#define VMC_RAM_POWERSET_S3POWER            (0x1U<<3)
#define VMC_RAM_POWERSET_S2POWER            (0x1U<<2)
#define VMC_RAM_POWERSET_S1POWER            (0x1U<<1)
#define VMC_RAM_POWERSET_S0POWER            (0x1U<<0)
#define VMC_RAM_POWERSET_S3RETENTION_ON     (0x1U<<19)
#define VMC_RAM_POWERSET_S2RETENTION_ON     (0x1U<<18)
#define VMC_RAM_POWERSET_S1RETENTION_ON     (0x1U<<17)
#define VMC_RAM_POWERSET_S0RETENTION_ON     (0x1U<<16)
#define VMC_RAM_POWERSET_S3POWER_ON         (0x1U<<3)
#define VMC_RAM_POWERSET_S2POWER_ON         (0x1U<<2)
#define VMC_RAM_POWERSET_S1POWER_ON         (0x1U<<1)
#define VMC_RAM_POWERSET_S0POWER_ON         (0x1U<<0)

// POWERCLR Configuration

#define VMC_RAM_POWERCLR_S3RETENTION        (0x1U<<19)
#define VMC_RAM_POWERCLR_S2RETENTION        (0x1U<<18)
#define VMC_RAM_POWERCLR_S1RETENTION        (0x1U<<17)
#define VMC_RAM_POWERCLR_S0RETENTION        (0x1U<<16)
#define VMC_RAM_POWERCLR_S3POWER            (0x1U<<3)
#define VMC_RAM_POWERCLR_S2POWER            (0x1U<<2)
#define VMC_RAM_POWERCLR_S1POWER            (0x1U<<1)
#define VMC_RAM_POWERCLR_S0POWER            (0x1U<<0)
#define VMC_RAM_POWERCLR_S3RETENTION_OFF    (0x1U<<19)
#define VMC_RAM_POWERCLR_S2RETENTION_OFF    (0x1U<<18)
#define VMC_RAM_POWERCLR_S1RETENTION_OFF    (0x1U<<17)
#define VMC_RAM_POWERCLR_S0RETENTION_OFF    (0x1U<<16)
#define VMC_RAM_POWERCLR_S3POWER_OFF        (0x1U<<3)
#define VMC_RAM_POWERCLR_S2POWER_OFF        (0x1U<<2)
#define VMC_RAM_POWERCLR_S1POWER_OFF        (0x1U<<1)
#define VMC_RAM_POWERCLR_S0POWER_OFF        (0x1U<<0)
