/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_nvmc equates.
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
    volatile    uint32_t    RESERVED5[25];
    volatile    uint32_t    CONFIGNS;
    volatile    uint32_t    WRITEUICRNS;
} NVMC_TypeDef;

#ifdef __cplusplus
#define NVMC_NS reinterpret_cast<NVMC_TypeDef *>(0x40039000U)
#define NVMC_S  reinterpret_cast<NVMC_TypeDef *>(0x50039000U)

#else
#define NVMC_NS ((NVMC_TypeDef *)0x40039000U)
#define NVMC_S  ((NVMC_TypeDef *)0x50039000U)
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

// CONFIGNS Configuration

#define NVMC_CONFIGNS_WEN                   (0x3U<<0)
#define NVMC_CONFIGNS_WEN_0                 (0x1U<<0)
#define NVMC_CONFIGNS_WEN_REN               (0x0U<<0)
#define NVMC_CONFIGNS_WEN_WEN               (0x1U<<0)
#define NVMC_CONFIGNS_WEN_EEN               (0x2U<<0)

// WRITEUICRNS Configuration

#define NVMC_WRITEUICRNS_KEY                (0xFFFFFFFU<<4)
#define NVMC_WRITEUICRNS_KEY_0              (0x1U<<4)
#define NVMC_WRITEUICRNS_SET                (0x1U<<0)
#define NVMC_WRITEUICRNS_KEY_KEYVALID       (0xAFBE5A7U<<4)
#define NVMC_WRITEUICRNS_SET_SET            (0x1U<<0)
