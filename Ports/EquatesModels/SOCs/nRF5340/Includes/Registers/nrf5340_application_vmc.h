/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_vmc equates.
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
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    RAM4_POWER;
    volatile    uint32_t    RAM4_POWERSET;
    volatile    uint32_t    RAM4_POWERCLR;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    RAM5_POWER;
    volatile    uint32_t    RAM5_POWERSET;
    volatile    uint32_t    RAM5_POWERCLR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    RAM6_POWER;
    volatile    uint32_t    RAM6_POWERSET;
    volatile    uint32_t    RAM6_POWERCLR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    RAM7_POWER;
    volatile    uint32_t    RAM7_POWERSET;
    volatile    uint32_t    RAM7_POWERCLR;
} VMC_TypeDef;

#ifdef __cplusplus
#define VMC_NS  reinterpret_cast<VMC_TypeDef *>(0x40081000U)
#define VMC_S   reinterpret_cast<VMC_TypeDef *>(0x50081000U)

#else
#define VMC_NS  ((VMC_TypeDef *)0x40081000U)
#define VMC_S   ((VMC_TypeDef *)0x50081000U)
#endif

// POWER Configuration

#define VMC_RAM_POWER_S15RETENTION          (0x1U<<31U)
#define VMC_RAM_POWER_S14RETENTION          (0x1U<<30U)
#define VMC_RAM_POWER_S13RETENTION          (0x1U<<29U)
#define VMC_RAM_POWER_S12RETENTION          (0x1U<<28U)
#define VMC_RAM_POWER_S11RETENTION          (0x1U<<27U)
#define VMC_RAM_POWER_S10RETENTION          (0x1U<<26U)
#define VMC_RAM_POWER_S9RETENTION           (0x1U<<25U)
#define VMC_RAM_POWER_S8RETENTION           (0x1U<<24U)
#define VMC_RAM_POWER_S7RETENTION           (0x1U<<23U)
#define VMC_RAM_POWER_S6RETENTION           (0x1U<<22U)
#define VMC_RAM_POWER_S5RETENTION           (0x1U<<21U)
#define VMC_RAM_POWER_S4RETENTION           (0x1U<<20U)
#define VMC_RAM_POWER_S3RETENTION           (0x1U<<19U)
#define VMC_RAM_POWER_S2RETENTION           (0x1U<<18U)
#define VMC_RAM_POWER_S1RETENTION           (0x1U<<17U)
#define VMC_RAM_POWER_S0RETENTION           (0x1U<<16U)
#define VMC_RAM_POWER_S15POWER              (0x1U<<15U)
#define VMC_RAM_POWER_S14POWER              (0x1U<<14U)
#define VMC_RAM_POWER_S13POWER              (0x1U<<13U)
#define VMC_RAM_POWER_S12POWER              (0x1U<<12U)
#define VMC_RAM_POWER_S11POWER              (0x1U<<11U)
#define VMC_RAM_POWER_S10POWER              (0x1U<<10U)
#define VMC_RAM_POWER_S9POWER               (0x1U<<9U)
#define VMC_RAM_POWER_S8POWER               (0x1U<<8U)
#define VMC_RAM_POWER_S7POWER               (0x1U<<7U)
#define VMC_RAM_POWER_S6POWER               (0x1U<<6U)
#define VMC_RAM_POWER_S5POWER               (0x1U<<5U)
#define VMC_RAM_POWER_S4POWER               (0x1U<<4U)
#define VMC_RAM_POWER_S3POWER               (0x1U<<3U)
#define VMC_RAM_POWER_S2POWER               (0x1U<<2U)
#define VMC_RAM_POWER_S1POWER               (0x1U<<1U)
#define VMC_RAM_POWER_S0POWER               (0x1U<<0U)
#define VMC_RAM_POWER_S15RETENTION_OFF      (0x0U<<31U)
#define VMC_RAM_POWER_S15RETENTION_ON       (0x1U<<31U)
#define VMC_RAM_POWER_S14RETENTION_OFF      (0x0U<<30U)
#define VMC_RAM_POWER_S14RETENTION_ON       (0x1U<<30U)
#define VMC_RAM_POWER_S13RETENTION_OFF      (0x0U<<29U)
#define VMC_RAM_POWER_S13RETENTION_ON       (0x1U<<29U)
#define VMC_RAM_POWER_S12RETENTION_OFF      (0x0U<<28U)
#define VMC_RAM_POWER_S12RETENTION_ON       (0x1U<<28U)
#define VMC_RAM_POWER_S11RETENTION_OFF      (0x0U<<27U)
#define VMC_RAM_POWER_S11RETENTION_ON       (0x1U<<27U)
#define VMC_RAM_POWER_S10RETENTION_OFF      (0x0U<<26U)
#define VMC_RAM_POWER_S10RETENTION_ON       (0x1U<<26U)
#define VMC_RAM_POWER_S9RETENTION_OFF       (0x0U<<25U)
#define VMC_RAM_POWER_S9RETENTION_ON        (0x1U<<25U)
#define VMC_RAM_POWER_S8RETENTION_OFF       (0x0U<<24U)
#define VMC_RAM_POWER_S8RETENTION_ON        (0x1U<<24U)
#define VMC_RAM_POWER_S7RETENTION_OFF       (0x0U<<23U)
#define VMC_RAM_POWER_S7RETENTION_ON        (0x1U<<23U)
#define VMC_RAM_POWER_S6RETENTION_OFF       (0x0U<<22U)
#define VMC_RAM_POWER_S6RETENTION_ON        (0x1U<<22U)
#define VMC_RAM_POWER_S5RETENTION_OFF       (0x0U<<21U)
#define VMC_RAM_POWER_S5RETENTION_ON        (0x1U<<21U)
#define VMC_RAM_POWER_S4RETENTION_OFF       (0x0U<<20U)
#define VMC_RAM_POWER_S4RETENTION_ON        (0x1U<<20U)
#define VMC_RAM_POWER_S3RETENTION_OFF       (0x0U<<19U)
#define VMC_RAM_POWER_S3RETENTION_ON        (0x1U<<19U)
#define VMC_RAM_POWER_S2RETENTION_OFF       (0x0U<<18U)
#define VMC_RAM_POWER_S2RETENTION_ON        (0x1U<<18U)
#define VMC_RAM_POWER_S1RETENTION_OFF       (0x0U<<17U)
#define VMC_RAM_POWER_S1RETENTION_ON        (0x1U<<17U)
#define VMC_RAM_POWER_S0RETENTION_OFF       (0x0U<<16U)
#define VMC_RAM_POWER_S0RETENTION_ON        (0x1U<<16U)
#define VMC_RAM_POWER_S15POWER_OFF          (0x0U<<15U)
#define VMC_RAM_POWER_S15POWER_ON           (0x1U<<15U)
#define VMC_RAM_POWER_S14POWER_OFF          (0x0U<<14U)
#define VMC_RAM_POWER_S14POWER_ON           (0x1U<<14U)
#define VMC_RAM_POWER_S13POWER_OFF          (0x0U<<13U)
#define VMC_RAM_POWER_S13POWER_ON           (0x1U<<13U)
#define VMC_RAM_POWER_S12POWER_OFF          (0x0U<<12U)
#define VMC_RAM_POWER_S12POWER_ON           (0x1U<<12U)
#define VMC_RAM_POWER_S11POWER_OFF          (0x0U<<11U)
#define VMC_RAM_POWER_S11POWER_ON           (0x1U<<11U)
#define VMC_RAM_POWER_S10POWER_OFF          (0x0U<<10U)
#define VMC_RAM_POWER_S10POWER_ON           (0x1U<<10U)
#define VMC_RAM_POWER_S9POWER_OFF           (0x0U<<9U)
#define VMC_RAM_POWER_S9POWER_ON            (0x1U<<9U)
#define VMC_RAM_POWER_S8POWER_OFF           (0x0U<<8U)
#define VMC_RAM_POWER_S8POWER_ON            (0x1U<<8U)
#define VMC_RAM_POWER_S7POWER_OFF           (0x0U<<7U)
#define VMC_RAM_POWER_S7POWER_ON            (0x1U<<7U)
#define VMC_RAM_POWER_S6POWER_OFF           (0x0U<<6U)
#define VMC_RAM_POWER_S6POWER_ON            (0x1U<<6U)
#define VMC_RAM_POWER_S5POWER_OFF           (0x0U<<5U)
#define VMC_RAM_POWER_S5POWER_ON            (0x1U<<5U)
#define VMC_RAM_POWER_S4POWER_OFF           (0x0U<<4U)
#define VMC_RAM_POWER_S4POWER_ON            (0x1U<<4U)
#define VMC_RAM_POWER_S3POWER_OFF           (0x0U<<3U)
#define VMC_RAM_POWER_S3POWER_ON            (0x1U<<3U)
#define VMC_RAM_POWER_S2POWER_OFF           (0x0U<<2U)
#define VMC_RAM_POWER_S2POWER_ON            (0x1U<<2U)
#define VMC_RAM_POWER_S1POWER_OFF           (0x0U<<1U)
#define VMC_RAM_POWER_S1POWER_ON            (0x1U<<1U)
#define VMC_RAM_POWER_S0POWER_OFF           (0x0U<<0U)
#define VMC_RAM_POWER_S0POWER_ON            (0x1U<<0U)

// POWERSET Configuration

#define VMC_RAM_POWERSET_S15RETENTION       (0x1U<<31U)
#define VMC_RAM_POWERSET_S14RETENTION       (0x1U<<30U)
#define VMC_RAM_POWERSET_S13RETENTION       (0x1U<<29U)
#define VMC_RAM_POWERSET_S12RETENTION       (0x1U<<28U)
#define VMC_RAM_POWERSET_S11RETENTION       (0x1U<<27U)
#define VMC_RAM_POWERSET_S10RETENTION       (0x1U<<26U)
#define VMC_RAM_POWERSET_S9RETENTION        (0x1U<<25U)
#define VMC_RAM_POWERSET_S8RETENTION        (0x1U<<24U)
#define VMC_RAM_POWERSET_S7RETENTION        (0x1U<<23U)
#define VMC_RAM_POWERSET_S6RETENTION        (0x1U<<22U)
#define VMC_RAM_POWERSET_S5RETENTION        (0x1U<<21U)
#define VMC_RAM_POWERSET_S4RETENTION        (0x1U<<20U)
#define VMC_RAM_POWERSET_S3RETENTION        (0x1U<<19U)
#define VMC_RAM_POWERSET_S2RETENTION        (0x1U<<18U)
#define VMC_RAM_POWERSET_S1RETENTION        (0x1U<<17U)
#define VMC_RAM_POWERSET_S0RETENTION        (0x1U<<16U)
#define VMC_RAM_POWERSET_S15POWER           (0x1U<<15U)
#define VMC_RAM_POWERSET_S14POWER           (0x1U<<14U)
#define VMC_RAM_POWERSET_S13POWER           (0x1U<<13U)
#define VMC_RAM_POWERSET_S12POWER           (0x1U<<12U)
#define VMC_RAM_POWERSET_S11POWER           (0x1U<<11U)
#define VMC_RAM_POWERSET_S10POWER           (0x1U<<10U)
#define VMC_RAM_POWERSET_S9POWER            (0x1U<<9U)
#define VMC_RAM_POWERSET_S8POWER            (0x1U<<8U)
#define VMC_RAM_POWERSET_S7POWER            (0x1U<<7U)
#define VMC_RAM_POWERSET_S6POWER            (0x1U<<6U)
#define VMC_RAM_POWERSET_S5POWER            (0x1U<<5U)
#define VMC_RAM_POWERSET_S4POWER            (0x1U<<4U)
#define VMC_RAM_POWERSET_S3POWER            (0x1U<<3U)
#define VMC_RAM_POWERSET_S2POWER            (0x1U<<2U)
#define VMC_RAM_POWERSET_S1POWER            (0x1U<<1U)
#define VMC_RAM_POWERSET_S0POWER            (0x1U<<0U)
#define VMC_RAM_POWERSET_S15RETENTION_ON    (0x1U<<31U)
#define VMC_RAM_POWERSET_S14RETENTION_ON    (0x1U<<30U)
#define VMC_RAM_POWERSET_S13RETENTION_ON    (0x1U<<29U)
#define VMC_RAM_POWERSET_S12RETENTION_ON    (0x1U<<28U)
#define VMC_RAM_POWERSET_S11RETENTION_ON    (0x1U<<27U)
#define VMC_RAM_POWERSET_S10RETENTION_ON    (0x1U<<26U)
#define VMC_RAM_POWERSET_S9RETENTION_ON     (0x1U<<25U)
#define VMC_RAM_POWERSET_S8RETENTION_ON     (0x1U<<24U)
#define VMC_RAM_POWERSET_S7RETENTION_ON     (0x1U<<23U)
#define VMC_RAM_POWERSET_S6RETENTION_ON     (0x1U<<22U)
#define VMC_RAM_POWERSET_S5RETENTION_ON     (0x1U<<21U)
#define VMC_RAM_POWERSET_S4RETENTION_ON     (0x1U<<20U)
#define VMC_RAM_POWERSET_S3RETENTION_ON     (0x1U<<19U)
#define VMC_RAM_POWERSET_S2RETENTION_ON     (0x1U<<18U)
#define VMC_RAM_POWERSET_S1RETENTION_ON     (0x1U<<17U)
#define VMC_RAM_POWERSET_S0RETENTION_ON     (0x1U<<16U)
#define VMC_RAM_POWERSET_S15POWER_ON        (0x1U<<15U)
#define VMC_RAM_POWERSET_S14POWER_ON        (0x1U<<14U)
#define VMC_RAM_POWERSET_S13POWER_ON        (0x1U<<13U)
#define VMC_RAM_POWERSET_S12POWER_ON        (0x1U<<12U)
#define VMC_RAM_POWERSET_S11POWER_ON        (0x1U<<11U)
#define VMC_RAM_POWERSET_S10POWER_ON        (0x1U<<10U)
#define VMC_RAM_POWERSET_S9POWER_ON         (0x1U<<9U)
#define VMC_RAM_POWERSET_S8POWER_ON         (0x1U<<8U)
#define VMC_RAM_POWERSET_S7POWER_ON         (0x1U<<7U)
#define VMC_RAM_POWERSET_S6POWER_ON         (0x1U<<6U)
#define VMC_RAM_POWERSET_S5POWER_ON         (0x1U<<5U)
#define VMC_RAM_POWERSET_S4POWER_ON         (0x1U<<4U)
#define VMC_RAM_POWERSET_S3POWER_ON         (0x1U<<3U)
#define VMC_RAM_POWERSET_S2POWER_ON         (0x1U<<2U)
#define VMC_RAM_POWERSET_S1POWER_ON         (0x1U<<1U)
#define VMC_RAM_POWERSET_S0POWER_ON         (0x1U<<0U)

// POWERCLR Configuration

#define VMC_RAM_POWERCLR_S15RETENTION       (0x1U<<31U)
#define VMC_RAM_POWERCLR_S14RETENTION       (0x1U<<30U)
#define VMC_RAM_POWERCLR_S13RETENTION       (0x1U<<29U)
#define VMC_RAM_POWERCLR_S12RETENTION       (0x1U<<28U)
#define VMC_RAM_POWERCLR_S11RETENTION       (0x1U<<27U)
#define VMC_RAM_POWERCLR_S10RETENTION       (0x1U<<26U)
#define VMC_RAM_POWERCLR_S9RETENTION        (0x1U<<25U)
#define VMC_RAM_POWERCLR_S8RETENTION        (0x1U<<24U)
#define VMC_RAM_POWERCLR_S7RETENTION        (0x1U<<23U)
#define VMC_RAM_POWERCLR_S6RETENTION        (0x1U<<22U)
#define VMC_RAM_POWERCLR_S5RETENTION        (0x1U<<21U)
#define VMC_RAM_POWERCLR_S4RETENTION        (0x1U<<20U)
#define VMC_RAM_POWERCLR_S3RETENTION        (0x1U<<19U)
#define VMC_RAM_POWERCLR_S2RETENTION        (0x1U<<18U)
#define VMC_RAM_POWERCLR_S1RETENTION        (0x1U<<17U)
#define VMC_RAM_POWERCLR_S0RETENTION        (0x1U<<16U)
#define VMC_RAM_POWERCLR_S15POWER           (0x1U<<15U)
#define VMC_RAM_POWERCLR_S14POWER           (0x1U<<14U)
#define VMC_RAM_POWERCLR_S13POWER           (0x1U<<13U)
#define VMC_RAM_POWERCLR_S12POWER           (0x1U<<12U)
#define VMC_RAM_POWERCLR_S11POWER           (0x1U<<11U)
#define VMC_RAM_POWERCLR_S10POWER           (0x1U<<10U)
#define VMC_RAM_POWERCLR_S9POWER            (0x1U<<9U)
#define VMC_RAM_POWERCLR_S8POWER            (0x1U<<8U)
#define VMC_RAM_POWERCLR_S7POWER            (0x1U<<7U)
#define VMC_RAM_POWERCLR_S6POWER            (0x1U<<6U)
#define VMC_RAM_POWERCLR_S5POWER            (0x1U<<5U)
#define VMC_RAM_POWERCLR_S4POWER            (0x1U<<4U)
#define VMC_RAM_POWERCLR_S3POWER            (0x1U<<3U)
#define VMC_RAM_POWERCLR_S2POWER            (0x1U<<2U)
#define VMC_RAM_POWERCLR_S1POWER            (0x1U<<1U)
#define VMC_RAM_POWERCLR_S0POWER            (0x1U<<0U)
#define VMC_RAM_POWERCLR_S15RETENTION_OFF   (0x1U<<31U)
#define VMC_RAM_POWERCLR_S14RETENTION_OFF   (0x1U<<30U)
#define VMC_RAM_POWERCLR_S13RETENTION_OFF   (0x1U<<29U)
#define VMC_RAM_POWERCLR_S12RETENTION_OFF   (0x1U<<28U)
#define VMC_RAM_POWERCLR_S11RETENTION_OFF   (0x1U<<27U)
#define VMC_RAM_POWERCLR_S10RETENTION_OFF   (0x1U<<26U)
#define VMC_RAM_POWERCLR_S9RETENTION_OFF    (0x1U<<25U)
#define VMC_RAM_POWERCLR_S8RETENTION_OFF    (0x1U<<24U)
#define VMC_RAM_POWERCLR_S7RETENTION_OFF    (0x1U<<23U)
#define VMC_RAM_POWERCLR_S6RETENTION_OFF    (0x1U<<22U)
#define VMC_RAM_POWERCLR_S5RETENTION_OFF    (0x1U<<21U)
#define VMC_RAM_POWERCLR_S4RETENTION_OFF    (0x1U<<20U)
#define VMC_RAM_POWERCLR_S3RETENTION_OFF    (0x1U<<19U)
#define VMC_RAM_POWERCLR_S2RETENTION_OFF    (0x1U<<18U)
#define VMC_RAM_POWERCLR_S1RETENTION_OFF    (0x1U<<17U)
#define VMC_RAM_POWERCLR_S0RETENTION_OFF    (0x1U<<16U)
#define VMC_RAM_POWERCLR_S15POWER_OFF       (0x1U<<15U)
#define VMC_RAM_POWERCLR_S14POWER_OFF       (0x1U<<14U)
#define VMC_RAM_POWERCLR_S13POWER_OFF       (0x1U<<13U)
#define VMC_RAM_POWERCLR_S12POWER_OFF       (0x1U<<12U)
#define VMC_RAM_POWERCLR_S11POWER_OFF       (0x1U<<11U)
#define VMC_RAM_POWERCLR_S10POWER_OFF       (0x1U<<10U)
#define VMC_RAM_POWERCLR_S9POWER_OFF        (0x1U<<9U)
#define VMC_RAM_POWERCLR_S8POWER_OFF        (0x1U<<8U)
#define VMC_RAM_POWERCLR_S7POWER_OFF        (0x1U<<7U)
#define VMC_RAM_POWERCLR_S6POWER_OFF        (0x1U<<6U)
#define VMC_RAM_POWERCLR_S5POWER_OFF        (0x1U<<5U)
#define VMC_RAM_POWERCLR_S4POWER_OFF        (0x1U<<4U)
#define VMC_RAM_POWERCLR_S3POWER_OFF        (0x1U<<3U)
#define VMC_RAM_POWERCLR_S2POWER_OFF        (0x1U<<2U)
#define VMC_RAM_POWERCLR_S1POWER_OFF        (0x1U<<1U)
#define VMC_RAM_POWERCLR_S0POWER_OFF        (0x1U<<0U)
