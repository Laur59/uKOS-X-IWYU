/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_nvmc equates.
 */

#pragma once

#include    <stdint.h>

// NVMC address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[256];
    volatile    uint32_t    READY;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    READYNEXT;
    volatile    uint32_t    RESERVED2[62];
    volatile    uint32_t    CONFIG;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    ERASEALL;
    volatile    uint32_t    RESERVED4[3];
    volatile    uint32_t    ERASEPAGEPARTIALCFG;
    volatile    uint32_t    RESERVED5[8];
    volatile    uint32_t    ICACHECNF;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    IHIT;
    volatile    uint32_t    IMISS;
} NVMC_TypeDef;

#ifdef __cplusplus
#define NVMC_NS reinterpret_cast<NVMC_TypeDef *>(0x41080000U)

#else
#define NVMC_NS ((NVMC_TypeDef *)0x41080000U)
#endif

// READY Configuration

#define NVMC_READY_READY                    (0x1U<<0)
#define NVMC_READY_READY_BUSY               (0x0U<<0)
#define NVMC_READY_READY_READY              (0x1U<<0)

// READYNEXT Configuration

#define NVMC_READYNEXT_READYNEXT            (0x1U<<0)
#define NVMC_READYNEXT_READYNEXT_BUSY       (0x0U<<0)
#define NVMC_READYNEXT_READYNEXT_READY      (0x1U<<0)

// CONFIG Configuration

#define NVMC_CONFIG_WEN                     (0x7U<<0)
#define NVMC_CONFIG_WEN_0                   (0x1U<<0)
#define NVMC_CONFIG_WEN_REN                 (0x0U<<0)
#define NVMC_CONFIG_WEN_WEN                 (0x1U<<0)
#define NVMC_CONFIG_WEN_EEN                 (0x2U<<0)
#define NVMC_CONFIG_WEN_PEEN                (0x4U<<0)

// ERASEALL Configuration

#define NVMC_ERASEALL_ERASEALL              (0x1U<<0)
#define NVMC_ERASEALL_ERASEALL_NOOPERATION  (0x0U<<0)
#define NVMC_ERASEALL_ERASEALL_ERASE        (0x1U<<0)

// ERASEPAGEPARTIALCFG Configuration

#define NVMC_ERASEPAGEPARTIALCFG_DURATION   (0x7FU<<0)
#define NVMC_ERASEPAGEPARTIALCFG_DURATION_0 (0x1U<<0)

// ICACHECNF Configuration

#define NVMC_ICACHECNF_CACHEPROFEN          (0x1U<<8)
#define NVMC_ICACHECNF_CACHEEN              (0x1U<<0)
#define NVMC_ICACHECNF_CACHEPROFEN_DISABLED (0x0U<<8)
#define NVMC_ICACHECNF_CACHEPROFEN_ENABLED  (0x1U<<8)
#define NVMC_ICACHECNF_CACHEEN_DISABLED     (0x0U<<0)
#define NVMC_ICACHECNF_CACHEEN_ENABLED      (0x1U<<0)

// IHIT Configuration

#define NVMC_IHIT_HITS                      (0xFFFFFFFFU<<0)
#define NVMC_IHIT_HITS_0                    (0x1U<<0)

// IMISS Configuration

#define NVMC_IMISS_MISSES                   (0xFFFFFFFFU<<0)
#define NVMC_IMISS_MISSES_0                 (0x1U<<0)
