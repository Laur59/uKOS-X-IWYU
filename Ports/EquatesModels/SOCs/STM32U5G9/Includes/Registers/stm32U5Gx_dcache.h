/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_dcache equates.
 */

#pragma once

#include    <stdint.h>

// DCACHE address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    IER;
    volatile    uint32_t    FCR;
    volatile    uint32_t    RHMONR;
    volatile    uint32_t    RMMONR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    WHMONR;
    volatile    uint32_t    WMMONR;
    volatile    uint32_t    CMDRSADDRR;
    volatile    uint32_t    CMDREADDRR;
} DCACHE_TypeDef;

#ifdef __cplusplus
#define DCACHE1_NS  reinterpret_cast<DCACHE_TypeDef *>(0x40031400U)
#define DCACHE1_S   reinterpret_cast<DCACHE_TypeDef *>(0x50031400U)
#define DCACHE2_NS  reinterpret_cast<DCACHE_TypeDef *>(0x40031800U)
#define DCACHE2_S   reinterpret_cast<DCACHE_TypeDef *>(0x50031800U)

#else
#define DCACHE1_NS  ((DCACHE_TypeDef *)0x40031400U)
#define DCACHE1_S   ((DCACHE_TypeDef *)0x50031400U)
#define DCACHE2_NS  ((DCACHE_TypeDef *)0x40031800U)
#define DCACHE2_S   ((DCACHE_TypeDef *)0x50031800U)
#endif

// CR Configuration

#define DCACHE_CR_HBURST                    (0x1U<<31U)
#define DCACHE_CR_WMISSMRST                 (0x1U<<23U)
#define DCACHE_CR_WHITMRST                  (0x1U<<22U)
#define DCACHE_CR_WMISSMEN                  (0x1U<<21U)
#define DCACHE_CR_WHITMEN                   (0x1U<<20U)
#define DCACHE_CR_RMISSMRST                 (0x1U<<19U)
#define DCACHE_CR_RHITMRST                  (0x1U<<18U)
#define DCACHE_CR_RMISSMEN                  (0x1U<<17U)
#define DCACHE_CR_RHITMEN                   (0x1U<<16U)
#define DCACHE_CR_STARTCMD                  (0x1U<<11U)
#define DCACHE_CR_CACHECMD                  (0x7U<<8U)
#define DCACHE_CR_CACHECMD_0                (0x1U<<8U)
#define DCACHE_CR_CACHEINV                  (0x1U<<1U)
#define DCACHE_CR_EN                        (0x1U<<0U)

// SR Configuration

#define DCACHE_SR_CMDENDF                   (0x1U<<4U)
#define DCACHE_SR_BUSYCMDF                  (0x1U<<3U)
#define DCACHE_SR_ERRF                      (0x1U<<2U)
#define DCACHE_SR_BSYENDF                   (0x1U<<1U)
#define DCACHE_SR_BUSYF                     (0x1U<<0U)

// IER Configuration

#define DCACHE_IER_CMDENDIE                 (0x1U<<4U)
#define DCACHE_IER_ERRIE                    (0x1U<<2U)
#define DCACHE_IER_BSYENDIE                 (0x1U<<1U)

// FCR Configuration

#define DCACHE_FCR_CCMDENDF                 (0x1U<<4U)
#define DCACHE_FCR_CERRF                    (0x1U<<2U)
#define DCACHE_FCR_CBSYENDF                 (0x1U<<1U)

// RHMONR Configuration

#define DCACHE_RHMONR_RHITMON               (0xFFFFFFFFU<<0U)
#define DCACHE_RHMONR_RHITMON_0             (0x1U<<0U)

// RMMONR Configuration

#define DCACHE_RMMONR_MRISSMON              (0xFFFFU<<0U)
#define DCACHE_RMMONR_MRISSMON_0            (0x1U<<0U)

// WHMONR Configuration

#define DCACHE_WHMONR_WHITMON               (0xFFFFFFFFU<<0U)
#define DCACHE_WHMONR_WHITMON_0             (0x1U<<0U)

// WMMONR Configuration

#define DCACHE_WMMONR_WMISSMON              (0xFFFFU<<0U)
#define DCACHE_WMMONR_WMISSMON_0            (0x1U<<0U)

// CMDRSADDRR Configuration

#define DCACHE_CMDRSADDRR_CMDSTARTADDR      (0xFFFFFFFU<<4U)
#define DCACHE_CMDRSADDRR_CMDSTARTADDR_0    (0x1U<<4U)

// CMDREADDRR Configuration

#define DCACHE_CMDREADDRR_CMDENDADDR        (0xFFFFFFFU<<4U)
#define DCACHE_CMDREADDRR_CMDENDADDR_0      (0x1U<<4U)
