/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_icache equates.
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
} ICACHE_TypeDef;

#ifdef __cplusplus
#define ICACHE_NS   reinterpret_cast<ICACHE_TypeDef *>(0x48035000U)
#define ICACHE_S    reinterpret_cast<ICACHE_TypeDef *>(0x58035000U)

#else
#define ICACHE_NS   ((ICACHE_TypeDef *)0x48035000U)
#define ICACHE_S    ((ICACHE_TypeDef *)0x58035000U)
#endif

// CR Configuration

#define ICACHE_CR_MISSMRST          (0x1U<<19U)
#define ICACHE_CR_HITMRST           (0x1U<<18U)
#define ICACHE_CR_MISSMEN           (0x1U<<17U)
#define ICACHE_CR_HITMEN            (0x1U<<16U)
#define ICACHE_CR_WAYSEL            (0x1U<<2U)
#define ICACHE_CR_CACHEINV          (0x1U<<1U)
#define ICACHE_CR_EN                (0x1U<<0U)

#define ICACHE_CR_MISSMRST_B_0X0    (0x0U<<19U)
#define ICACHE_CR_MISSMRST_B_0X1    (0x1U<<19U)
#define ICACHE_CR_HITMRST_B_0X0     (0x0U<<18U)
#define ICACHE_CR_HITMRST_B_0X1     (0x1U<<18U)
#define ICACHE_CR_MISSMEN_B_0X0     (0x0U<<17U)
#define ICACHE_CR_MISSMEN_B_0X1     (0x1U<<17U)
#define ICACHE_CR_HITMEN_B_0X0      (0x0U<<16U)
#define ICACHE_CR_HITMEN_B_0X1      (0x1U<<16U)
#define ICACHE_CR_WAYSEL_B_0X0      (0x0U<<2U)
#define ICACHE_CR_WAYSEL_B_0X1      (0x1U<<2U)
#define ICACHE_CR_CACHEINV_B_0X0    (0x0U<<1U)
#define ICACHE_CR_CACHEINV_B_0X1    (0x1U<<1U)
#define ICACHE_CR_EN_B_0X0          (0x0U<<0U)
#define ICACHE_CR_EN_B_0X1          (0x1U<<0U)

// SR Configuration

#define ICACHE_SR_ERRF              (0x1U<<2U)
#define ICACHE_SR_BSYENDF           (0x1U<<1U)
#define ICACHE_SR_BUSYF             (0x1U<<0U)

#define ICACHE_SR_ERRF_B_0X0        (0x0U<<2U)
#define ICACHE_SR_ERRF_B_0X1        (0x1U<<2U)
#define ICACHE_SR_BSYENDF_B_0X0     (0x0U<<1U)
#define ICACHE_SR_BSYENDF_B_0X1     (0x1U<<1U)
#define ICACHE_SR_BUSYF_B_0X0       (0x0U<<0U)
#define ICACHE_SR_BUSYF_B_0X1       (0x1U<<0U)

// IER Configuration

#define ICACHE_IER_ERRIE            (0x1U<<2U)
#define ICACHE_IER_BSYENDIE         (0x1U<<1U)

#define ICACHE_IER_ERRIE_B_0X0      (0x0U<<2U)
#define ICACHE_IER_ERRIE_B_0X1      (0x1U<<2U)
#define ICACHE_IER_BSYENDIE_B_0X0   (0x0U<<1U)
#define ICACHE_IER_BSYENDIE_B_0X1   (0x1U<<1U)

// FCR Configuration

#define ICACHE_FCR_CERRF            (0x1U<<2U)
#define ICACHE_FCR_CBSYENDF         (0x1U<<1U)

#define ICACHE_FCR_CERRF_B_0X0      (0x0U<<2U)
#define ICACHE_FCR_CERRF_B_0X1      (0x1U<<2U)
#define ICACHE_FCR_CBSYENDF_B_0X0   (0x0U<<1U)
#define ICACHE_FCR_CBSYENDF_B_0X1   (0x1U<<1U)

// HMONR Configuration

#define ICACHE_HMONR_HITMON         (0xFFFFFFFFU<<0U)
#define ICACHE_HMONR_HITMON_0       (0x1U<<0U)

// MMONR Configuration

#define ICACHE_MMONR_MISSMON        (0xFFFFU<<0U)
#define ICACHE_MMONR_MISSMON_0      (0x1U<<0U)
