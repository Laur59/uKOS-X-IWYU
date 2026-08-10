/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_dma1 equates.
 */

#pragma once

#include    <stdint.h>

// DMA1 address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    INTF;
    volatile    uint32_t    INTC;
    volatile    uint32_t    CH0CTL;
    volatile    uint32_t    CH0CNT;
    volatile    uint32_t    CH0PADDR;
    volatile    uint32_t    CH0MADDR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CH1CTL;
    volatile    uint32_t    CH1CNT;
    volatile    uint32_t    CH1PADDR;
    volatile    uint32_t    CH1MADDR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    CH2CTL;
    volatile    uint32_t    CH2CNT;
    volatile    uint32_t    CH2PADDR;
    volatile    uint32_t    CH2MADDR;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    CH3CTL;
    volatile    uint32_t    CH3CNT;
    volatile    uint32_t    CH3PADDR;
    volatile    uint32_t    CH3MADDR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    CH4CTL;
    volatile    uint32_t    CH4CNT;
    volatile    uint32_t    CH4PADDR;
    volatile    uint32_t    CH4MADDR;
} DMA1_TypeDef;

#ifdef __cplusplus
#define DMA1    reinterpret_cast<DMA1_TypeDef *>(0x40020000U)

#else
#define DMA1    ((DMA1_TypeDef *)0x40020000U)
#endif

// INTF Configuration

#define DMA1_INTF_ERRIF4        (0x1U<<19U)
#define DMA1_INTF_HTFIF4        (0x1U<<18U)
#define DMA1_INTF_FTFIF4        (0x1U<<17U)
#define DMA1_INTF_GIF4          (0x1U<<16U)
#define DMA1_INTF_ERRIF3        (0x1U<<15U)
#define DMA1_INTF_HTFIF3        (0x1U<<14U)
#define DMA1_INTF_FTFIF3        (0x1U<<13U)
#define DMA1_INTF_GIF3          (0x1U<<12U)
#define DMA1_INTF_ERRIF2        (0x1U<<11U)
#define DMA1_INTF_HTFIF2        (0x1U<<10U)
#define DMA1_INTF_FTFIF2        (0x1U<<9U)
#define DMA1_INTF_GIF2          (0x1U<<8U)
#define DMA1_INTF_ERRIF1        (0x1U<<7U)
#define DMA1_INTF_HTFIF1        (0x1U<<6U)
#define DMA1_INTF_FTFIF1        (0x1U<<5U)
#define DMA1_INTF_GIF1          (0x1U<<4U)
#define DMA1_INTF_ERRIF0        (0x1U<<3U)
#define DMA1_INTF_HTFIF0        (0x1U<<2U)
#define DMA1_INTF_FTFIF0        (0x1U<<1U)
#define DMA1_INTF_GIF0          (0x1U<<0U)

// INTC Configuration

#define DMA1_INTC_ERRIFC4       (0x1U<<19U)
#define DMA1_INTC_HTFIFC4       (0x1U<<18U)
#define DMA1_INTC_FTFIFC4       (0x1U<<17U)
#define DMA1_INTC_GIFC4         (0x1U<<16U)
#define DMA1_INTC_ERRIFC3       (0x1U<<15U)
#define DMA1_INTC_HTFIFC3       (0x1U<<14U)
#define DMA1_INTC_FTFIFC3       (0x1U<<13U)
#define DMA1_INTC_GIFC3         (0x1U<<12U)
#define DMA1_INTC_ERRIFC2       (0x1U<<11U)
#define DMA1_INTC_HTFIFC2       (0x1U<<10U)
#define DMA1_INTC_FTFIFC2       (0x1U<<9U)
#define DMA1_INTC_GIFC2         (0x1U<<8U)
#define DMA1_INTC_ERRIFC1       (0x1U<<7U)
#define DMA1_INTC_HTFIFC1       (0x1U<<6U)
#define DMA1_INTC_FTFIFC1       (0x1U<<5U)
#define DMA1_INTC_GIFC1         (0x1U<<4U)
#define DMA1_INTC_ERRIFC0       (0x1U<<3U)
#define DMA1_INTC_HTFIFC0       (0x1U<<2U)
#define DMA1_INTC_FTFIFC0       (0x1U<<1U)
#define DMA1_INTC_GIFC0         (0x1U<<0U)

// CH0CTL Configuration

#define DMA1_CH0CTL_M2M         (0x1U<<14U)
#define DMA1_CH0CTL_PRIO        (0x3U<<12U)
#define DMA1_CH0CTL_PRIO_0      (0x1U<<12U)
#define DMA1_CH0CTL_MWIDTH      (0x3U<<10U)
#define DMA1_CH0CTL_MWIDTH_0    (0x1U<<10U)
#define DMA1_CH0CTL_PWIDTH      (0x3U<<8U)
#define DMA1_CH0CTL_PWIDTH_0    (0x1U<<8U)
#define DMA1_CH0CTL_MNAGA       (0x1U<<7U)
#define DMA1_CH0CTL_PNAGA       (0x1U<<6U)
#define DMA1_CH0CTL_CMEN        (0x1U<<5U)
#define DMA1_CH0CTL_DIR         (0x1U<<4U)
#define DMA1_CH0CTL_ERRIE       (0x1U<<3U)
#define DMA1_CH0CTL_HTFIE       (0x1U<<2U)
#define DMA1_CH0CTL_FTFIE       (0x1U<<1U)
#define DMA1_CH0CTL_CHEN        (0x1U<<0U)

// CH0CNT Configuration

#define DMA1_CH0CNT_CNT         (0xFFFFU<<0U)
#define DMA1_CH0CNT_CNT_0       (0x1U<<0U)

// CH0PADDR Configuration

#define DMA1_CH0PADDR_PADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH0PADDR_PADDR_0   (0x1U<<0U)

// CH0MADDR Configuration

#define DMA1_CH0MADDR_MADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH0MADDR_MADDR_0   (0x1U<<0U)

// CH1CTL Configuration

#define DMA1_CH1CTL_M2M         (0x1U<<14U)
#define DMA1_CH1CTL_PRIO        (0x3U<<12U)
#define DMA1_CH1CTL_PRIO_0      (0x1U<<12U)
#define DMA1_CH1CTL_MWIDTH      (0x3U<<10U)
#define DMA1_CH1CTL_MWIDTH_0    (0x1U<<10U)
#define DMA1_CH1CTL_PWIDTH      (0x3U<<8U)
#define DMA1_CH1CTL_PWIDTH_0    (0x1U<<8U)
#define DMA1_CH1CTL_MNAGA       (0x1U<<7U)
#define DMA1_CH1CTL_PNAGA       (0x1U<<6U)
#define DMA1_CH1CTL_CMEN        (0x1U<<5U)
#define DMA1_CH1CTL_DIR         (0x1U<<4U)
#define DMA1_CH1CTL_ERRIE       (0x1U<<3U)
#define DMA1_CH1CTL_HTFIE       (0x1U<<2U)
#define DMA1_CH1CTL_FTFIE       (0x1U<<1U)
#define DMA1_CH1CTL_CHEN        (0x1U<<0U)

// CH1CNT Configuration

#define DMA1_CH1CNT_CNT         (0xFFFFU<<0U)
#define DMA1_CH1CNT_CNT_0       (0x1U<<0U)

// CH1PADDR Configuration

#define DMA1_CH1PADDR_PADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH1PADDR_PADDR_0   (0x1U<<0U)

// CH1MADDR Configuration

#define DMA1_CH1MADDR_MADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH1MADDR_MADDR_0   (0x1U<<0U)

// CH2CTL Configuration

#define DMA1_CH2CTL_M2M         (0x1U<<14U)
#define DMA1_CH2CTL_PRIO        (0x3U<<12U)
#define DMA1_CH2CTL_PRIO_0      (0x1U<<12U)
#define DMA1_CH2CTL_MWIDTH      (0x3U<<10U)
#define DMA1_CH2CTL_MWIDTH_0    (0x1U<<10U)
#define DMA1_CH2CTL_PWIDTH      (0x3U<<8U)
#define DMA1_CH2CTL_PWIDTH_0    (0x1U<<8U)
#define DMA1_CH2CTL_MNAGA       (0x1U<<7U)
#define DMA1_CH2CTL_PNAGA       (0x1U<<6U)
#define DMA1_CH2CTL_CMEN        (0x1U<<5U)
#define DMA1_CH2CTL_DIR         (0x1U<<4U)
#define DMA1_CH2CTL_ERRIE       (0x1U<<3U)
#define DMA1_CH2CTL_HTFIE       (0x1U<<2U)
#define DMA1_CH2CTL_FTFIE       (0x1U<<1U)
#define DMA1_CH2CTL_CHEN        (0x1U<<0U)

// CH2CNT Configuration

#define DMA1_CH2CNT_CNT         (0xFFFFU<<0U)
#define DMA1_CH2CNT_CNT_0       (0x1U<<0U)

// CH2PADDR Configuration

#define DMA1_CH2PADDR_PADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH2PADDR_PADDR_0   (0x1U<<0U)

// CH2MADDR Configuration

#define DMA1_CH2MADDR_MADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH2MADDR_MADDR_0   (0x1U<<0U)

// CH3CTL Configuration

#define DMA1_CH3CTL_M2M         (0x1U<<14U)
#define DMA1_CH3CTL_PRIO        (0x3U<<12U)
#define DMA1_CH3CTL_PRIO_0      (0x1U<<12U)
#define DMA1_CH3CTL_MWIDTH      (0x3U<<10U)
#define DMA1_CH3CTL_MWIDTH_0    (0x1U<<10U)
#define DMA1_CH3CTL_PWIDTH      (0x3U<<8U)
#define DMA1_CH3CTL_PWIDTH_0    (0x1U<<8U)
#define DMA1_CH3CTL_MNAGA       (0x1U<<7U)
#define DMA1_CH3CTL_PNAGA       (0x1U<<6U)
#define DMA1_CH3CTL_CMEN        (0x1U<<5U)
#define DMA1_CH3CTL_DIR         (0x1U<<4U)
#define DMA1_CH3CTL_ERRIE       (0x1U<<3U)
#define DMA1_CH3CTL_HTFIE       (0x1U<<2U)
#define DMA1_CH3CTL_FTFIE       (0x1U<<1U)
#define DMA1_CH3CTL_CHEN        (0x1U<<0U)

// CH3CNT Configuration

#define DMA1_CH3CNT_CNT         (0xFFFFU<<0U)
#define DMA1_CH3CNT_CNT_0       (0x1U<<0U)

// CH3PADDR Configuration

#define DMA1_CH3PADDR_PADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH3PADDR_PADDR_0   (0x1U<<0U)

// CH3MADDR Configuration

#define DMA1_CH3MADDR_MADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH3MADDR_MADDR_0   (0x1U<<0U)

// CH4CTL Configuration

#define DMA1_CH4CTL_M2M         (0x1U<<14U)
#define DMA1_CH4CTL_PRIO        (0x3U<<12U)
#define DMA1_CH4CTL_PRIO_0      (0x1U<<12U)
#define DMA1_CH4CTL_MWIDTH      (0x3U<<10U)
#define DMA1_CH4CTL_MWIDTH_0    (0x1U<<10U)
#define DMA1_CH4CTL_PWIDTH      (0x3U<<8U)
#define DMA1_CH4CTL_PWIDTH_0    (0x1U<<8U)
#define DMA1_CH4CTL_MNAGA       (0x1U<<7U)
#define DMA1_CH4CTL_PNAGA       (0x1U<<6U)
#define DMA1_CH4CTL_CMEN        (0x1U<<5U)
#define DMA1_CH4CTL_DIR         (0x1U<<4U)
#define DMA1_CH4CTL_ERRIE       (0x1U<<3U)
#define DMA1_CH4CTL_HTFIE       (0x1U<<2U)
#define DMA1_CH4CTL_FTFIE       (0x1U<<1U)
#define DMA1_CH4CTL_CHEN        (0x1U<<0U)

// CH4CNT Configuration

#define DMA1_CH4CNT_CNT         (0xFFFFU<<0U)
#define DMA1_CH4CNT_CNT_0       (0x1U<<0U)

// CH4PADDR Configuration

#define DMA1_CH4PADDR_PADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH4PADDR_PADDR_0   (0x1U<<0U)

// CH4MADDR Configuration

#define DMA1_CH4MADDR_MADDR     (0xFFFFFFFFU<<0U)
#define DMA1_CH4MADDR_MADDR_0   (0x1U<<0U)
