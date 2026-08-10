/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_flash equates.
 */

#pragma once

#include    <stdint.h>

// FLASH address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    ACR;
    volatile    uint32_t    KEYR;
    volatile    uint32_t    OPTKEYR;
    volatile    uint32_t    SR;
    volatile    uint32_t    CR;
    volatile    uint32_t    OPTCR;
} FLASH_TypeDef;

#ifdef __cplusplus
#define FLASH   reinterpret_cast<FLASH_TypeDef *>(0x40023C00U)

#else
#define FLASH   ((FLASH_TypeDef *)0x40023C00U)
#endif

// ACR Configuration

#define FLASH_ACR_DCRST         (0x1U<<12U)
#define FLASH_ACR_ICRST         (0x1U<<11U)
#define FLASH_ACR_DCEN          (0x1U<<10U)
#define FLASH_ACR_ICEN          (0x1U<<9U)
#define FLASH_ACR_PRFTEN        (0x1U<<8U)
#define FLASH_ACR_LATENCY       (0x7U<<0U)
#define FLASH_ACR_LATENCY_0     (0x1U<<0U)

// KEYR Configuration

#define FLASH_KEYR_KEY          (0xFFFFFFFFU<<0U)
#define FLASH_KEYR_KEY_0        (0x1U<<0U)

// OPTKEYR Configuration

#define FLASH_OPTKEYR_OPTKEY    (0xFFFFFFFFU<<0U)
#define FLASH_OPTKEYR_OPTKEY_0  (0x1U<<0U)

// SR Configuration

#define FLASH_SR_BSY            (0x1U<<16U)
#define FLASH_SR_PGSERR         (0x1U<<7U)
#define FLASH_SR_PGPERR         (0x1U<<6U)
#define FLASH_SR_PGAERR         (0x1U<<5U)
#define FLASH_SR_WRPERR         (0x1U<<4U)
#define FLASH_SR_OPERR          (0x1U<<1U)
#define FLASH_SR_EOP            (0x1U<<0U)

// CR Configuration

#define FLASH_CR_LOCK           (0x1U<<31U)
#define FLASH_CR_ERRIE          (0x1U<<25U)
#define FLASH_CR_EOPIE          (0x1U<<24U)
#define FLASH_CR_STRT           (0x1U<<16U)
#define FLASH_CR_PSIZE          (0x3U<<8U)
#define FLASH_CR_PSIZE_0        (0x1U<<8U)
#define FLASH_CR_SNB            (0xFU<<3U)
#define FLASH_CR_SNB_0          (0x1U<<3U)
#define FLASH_CR_MER            (0x1U<<2U)
#define FLASH_CR_SER            (0x1U<<1U)
#define FLASH_CR_PG             (0x1U<<0U)

// OPTCR Configuration

#define FLASH_OPTCR_NWRP        (0xFFFU<<16U)
#define FLASH_OPTCR_NWRP_0      (0x1U<<16U)
#define FLASH_OPTCR_RDP         (0xFFU<<8U)
#define FLASH_OPTCR_RDP_0       (0x1U<<8U)
#define FLASH_OPTCR_NRST_STDBY  (0x1U<<7U)
#define FLASH_OPTCR_NRST_STOP   (0x1U<<6U)
#define FLASH_OPTCR_WDG_SW      (0x1U<<5U)
#define FLASH_OPTCR_BOR_LEV     (0x3U<<2U)
#define FLASH_OPTCR_BOR_LEV_0   (0x1U<<2U)
#define FLASH_OPTCR_OPTSTRT     (0x1U<<1U)
#define FLASH_OPTCR_OPTLOCK     (0x1U<<0U)
