/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_icache equates.
 */

#pragma once

#include    <stdint.h>

// ICACHE address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    IER;
    volatile    uint32_t    FCR;
    volatile    uint32_t    HMONR;
    volatile    uint32_t    MMONR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    CRR0;
    volatile    uint32_t    CRR1;
    volatile    uint32_t    CRR2;
    volatile    uint32_t    CRR3;
} ICACHE_TypeDef;

#ifdef __cplusplus
#define ICACHE_NS   reinterpret_cast<ICACHE_TypeDef *>(0x40030400U)
#define ICACHE_S    reinterpret_cast<ICACHE_TypeDef *>(0x50030400U)

#else
#define ICACHE_NS   ((ICACHE_TypeDef *)0x40030400U)
#define ICACHE_S    ((ICACHE_TypeDef *)0x50030400U)
#endif

// CR Configuration

#define ICACHE_CR_MISSMRST      (0x1U<<19U)
#define ICACHE_CR_HITMRST       (0x1U<<18U)
#define ICACHE_CR_MISSMEN       (0x1U<<17U)
#define ICACHE_CR_HITMEN        (0x1U<<16U)
#define ICACHE_CR_WAYSEL        (0x1U<<2U)
#define ICACHE_CR_CACHEINV      (0x1U<<1U)
#define ICACHE_CR_EN            (0x1U<<0U)

// SR Configuration

#define ICACHE_SR_ERRF          (0x1U<<2U)
#define ICACHE_SR_BSYENDF       (0x1U<<1U)
#define ICACHE_SR_BUSYF         (0x1U<<0U)

// IER Configuration

#define ICACHE_IER_ERRIE        (0x1U<<2U)
#define ICACHE_IER_BSYENDIE     (0x1U<<1U)

// FCR Configuration

#define ICACHE_FCR_CERRF        (0x1U<<2U)
#define ICACHE_FCR_CBSYENDF     (0x1U<<1U)

// HMONR Configuration

#define ICACHE_HMONR_HITMON     (0xFFFFFFFFU<<0U)
#define ICACHE_HMONR_HITMON_0   (0x1U<<0U)

// MMONR Configuration

#define ICACHE_MMONR_MISSMON    (0xFFFFU<<0U)
#define ICACHE_MMONR_MISSMON_0  (0x1U<<0U)

// CRR0 Configuration

#define ICACHE_CRR0_HBURST      (0x1U<<31U)
#define ICACHE_CRR0_MSTSEL      (0x1U<<28U)
#define ICACHE_CRR0_REMAPADDR   (0x7FFU<<16U)
#define ICACHE_CRR0_REMAPADDR_0 (0x1U<<16U)
#define ICACHE_CRR0_REN         (0x1U<<15U)
#define ICACHE_CRR0_RSIZE       (0x7U<<9U)
#define ICACHE_CRR0_RSIZE_0     (0x1U<<9U)
#define ICACHE_CRR0_BASEADDR    (0xFFU<<0U)
#define ICACHE_CRR0_BASEADDR_0  (0x1U<<0U)

// CRR1 Configuration

#define ICACHE_CRR1_HBURST      (0x1U<<31U)
#define ICACHE_CRR1_MSTSEL      (0x1U<<28U)
#define ICACHE_CRR1_REMAPADDR   (0x7FFU<<16U)
#define ICACHE_CRR1_REMAPADDR_0 (0x1U<<16U)
#define ICACHE_CRR1_REN         (0x1U<<15U)
#define ICACHE_CRR1_RSIZE       (0x7U<<9U)
#define ICACHE_CRR1_RSIZE_0     (0x1U<<9U)
#define ICACHE_CRR1_BASEADDR    (0xFFU<<0U)
#define ICACHE_CRR1_BASEADDR_0  (0x1U<<0U)

// CRR2 Configuration

#define ICACHE_CRR2_HBURST      (0x1U<<31U)
#define ICACHE_CRR2_MSTSEL      (0x1U<<28U)
#define ICACHE_CRR2_REMAPADDR   (0x7FFU<<16U)
#define ICACHE_CRR2_REMAPADDR_0 (0x1U<<16U)
#define ICACHE_CRR2_REN         (0x1U<<15U)
#define ICACHE_CRR2_RSIZE       (0x7U<<9U)
#define ICACHE_CRR2_RSIZE_0     (0x1U<<9U)
#define ICACHE_CRR2_BASEADDR    (0xFFU<<0U)
#define ICACHE_CRR2_BASEADDR_0  (0x1U<<0U)

// CRR3 Configuration

#define ICACHE_CRR3_HBURST      (0x1U<<31U)
#define ICACHE_CRR3_MSTSEL      (0x1U<<28U)
#define ICACHE_CRR3_REMAPADDR   (0x7FFU<<16U)
#define ICACHE_CRR3_REMAPADDR_0 (0x1U<<16U)
#define ICACHE_CRR3_REN         (0x1U<<15U)
#define ICACHE_CRR3_RSIZE       (0x7U<<9U)
#define ICACHE_CRR3_RSIZE_0     (0x1U<<9U)
#define ICACHE_CRR3_BASEADDR    (0xFFU<<0U)
#define ICACHE_CRR3_BASEADDR_0  (0x1U<<0U)
