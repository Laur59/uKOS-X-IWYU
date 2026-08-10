/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_flash equates.
 */

#pragma once

#include    <stdint.h>

// FLASH address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    ACR;
    volatile    uint32_t    PDKEYR;
    volatile    uint32_t    KEYR;
    volatile    uint32_t    OPTKEYR;
    volatile    uint32_t    SR;
    volatile    uint32_t    CR;
    volatile    uint32_t    ECCR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    OPTR;
    volatile    uint32_t    PCROP1SR;
    volatile    uint32_t    PCROP1ER;
    volatile    uint32_t    WRP1AR;
    volatile    uint32_t    WRP2AR;
    volatile    uint32_t    RESERVED1[4];
    volatile    uint32_t    PCROP2SR;
    volatile    uint32_t    PCROP2ER;
    volatile    uint32_t    WRP1BR;
    volatile    uint32_t    WRP2BR;
    volatile    uint32_t    RESERVED2[55];
    volatile    uint32_t    CFGR;
} FLASH_TypeDef;

#ifdef __cplusplus
#define FLASH   reinterpret_cast<FLASH_TypeDef *>(0x40022000U)

#else
#define FLASH   ((FLASH_TypeDef *)0x40022000U)
#endif

// ACR Configuration

#define FLASH_ACR_SLEEP_PD              (0x1U<<14U)
#define FLASH_ACR_RUN_PD                (0x1U<<13U)
#define FLASH_ACR_DCRST                 (0x1U<<12U)
#define FLASH_ACR_ICRST                 (0x1U<<11U)
#define FLASH_ACR_DCEN                  (0x1U<<10U)
#define FLASH_ACR_ICEN                  (0x1U<<9U)
#define FLASH_ACR_PRFTEN                (0x1U<<8U)
#define FLASH_ACR_LATENCY               (0xFU<<0U)
#define FLASH_ACR_LATENCY_0             (0x1U<<0U)

// PDKEYR Configuration

#define FLASH_PDKEYR_PDKEYR             (0xFFFFFFFFU<<0U)
#define FLASH_PDKEYR_PDKEYR_0           (0x1U<<0U)

// KEYR Configuration

#define FLASH_KEYR_KEYR                 (0xFFFFFFFFU<<0U)
#define FLASH_KEYR_KEYR_0               (0x1U<<0U)

// OPTKEYR Configuration

#define FLASH_OPTKEYR_OPTKEYR           (0xFFFFFFFFU<<0U)
#define FLASH_OPTKEYR_OPTKEYR_0         (0x1U<<0U)

// SR Configuration

#define FLASH_SR_PEMPTY                 (0x1U<<17U)
#define FLASH_SR_BSY                    (0x1U<<16U)
#define FLASH_SR_OPTVERR                (0x1U<<15U)
#define FLASH_SR_RDERR                  (0x1U<<14U)
#define FLASH_SR_FASTERR                (0x1U<<9U)
#define FLASH_SR_MISERR                 (0x1U<<8U)
#define FLASH_SR_PGSERR                 (0x1U<<7U)
#define FLASH_SR_SIZERR                 (0x1U<<6U)
#define FLASH_SR_PGAERR                 (0x1U<<5U)
#define FLASH_SR_WRPERR                 (0x1U<<4U)
#define FLASH_SR_PROGERR                (0x1U<<3U)
#define FLASH_SR_OPERR                  (0x1U<<1U)
#define FLASH_SR_EOP                    (0x1U<<0U)

// CR Configuration

#define FLASH_CR_LOCK                   (0x1U<<31U)
#define FLASH_CR_OPTLOCK                (0x1U<<30U)
#define FLASH_CR_OBL_LAUNCH             (0x1U<<27U)
#define FLASH_CR_RDERRIE                (0x1U<<26U)
#define FLASH_CR_ERRIE                  (0x1U<<25U)
#define FLASH_CR_EOPIE                  (0x1U<<24U)
#define FLASH_CR_FSTPG                  (0x1U<<18U)
#define FLASH_CR_OPTSTRT                (0x1U<<17U)
#define FLASH_CR_START                  (0x1U<<16U)
#define FLASH_CR_MER2                   (0x1U<<15U)
#define FLASH_CR_BKER                   (0x1U<<11U)
#define FLASH_CR_PNB                    (0xFFU<<3U)
#define FLASH_CR_PNB_0                  (0x1U<<3U)
#define FLASH_CR_MER1                   (0x1U<<2U)
#define FLASH_CR_PER                    (0x1U<<1U)
#define FLASH_CR_PG                     (0x1U<<0U)

// ECCR Configuration

#define FLASH_ECCR_ECCD                 (0x1U<<31U)
#define FLASH_ECCR_ECCC                 (0x1U<<30U)
#define FLASH_ECCR_ECCD2                (0x1U<<29U)
#define FLASH_ECCR_ECCC2                (0x1U<<28U)
#define FLASH_ECCR_ECCIE                (0x1U<<24U)
#define FLASH_ECCR_SYSF_ECC             (0x1U<<22U)
#define FLASH_ECCR_BK_ECC               (0x1U<<21U)
#define FLASH_ECCR_ADDR_ECC             (0x1FFFFFU<<0U)
#define FLASH_ECCR_ADDR_ECC_0           (0x1U<<0U)

// OPTR Configuration

#define FLASH_OPTR_NBOOT0               (0x1U<<27U)
#define FLASH_OPTR_NSWBOOT0             (0x1U<<26U)
#define FLASH_OPTR_SRAM2_RST            (0x1U<<25U)
#define FLASH_OPTR_SRAM2_PE             (0x1U<<24U)
#define FLASH_OPTR_NBOOT1               (0x1U<<23U)
#define FLASH_OPTR_DBANK                (0x1U<<22U)
#define FLASH_OPTR_DB1M                 (0x1U<<21U)
#define FLASH_OPTR_BFB2                 (0x1U<<20U)
#define FLASH_OPTR_WWDG_SW              (0x1U<<19U)
#define FLASH_OPTR_IWDG_STDBY           (0x1U<<18U)
#define FLASH_OPTR_IWDG_STOP            (0x1U<<17U)
#define FLASH_OPTR_IWDG_SW              (0x1U<<16U)
#define FLASH_OPTR_NRST_SHDW            (0x1U<<14U)
#define FLASH_OPTR_NRST_STDBY           (0x1U<<13U)
#define FLASH_OPTR_NRST_STOP            (0x1U<<12U)
#define FLASH_OPTR_BOR_LEV              (0x7U<<8U)
#define FLASH_OPTR_BOR_LEV_0            (0x1U<<8U)
#define FLASH_OPTR_RDP                  (0xFFU<<0U)
#define FLASH_OPTR_RDP_0                (0x1U<<0U)

// PCROP1SR Configuration

#define FLASH_PCROP1SR_PCROP1_STRT      (0x1FFFFU<<0U)
#define FLASH_PCROP1SR_PCROP1_STRT_0    (0x1U<<0U)

// PCROP1ER Configuration

#define FLASH_PCROP1ER_PCROP_RDP        (0x1U<<31U)
#define FLASH_PCROP1ER_PCROP1_END       (0x1FFFFU<<0U)
#define FLASH_PCROP1ER_PCROP1_END_0     (0x1U<<0U)

// WRP1AR Configuration

#define FLASH_WRP1AR_WRP1A_END          (0xFFU<<16U)
#define FLASH_WRP1AR_WRP1A_END_0        (0x1U<<16U)
#define FLASH_WRP1AR_WRP1A_STRT         (0xFFU<<0U)
#define FLASH_WRP1AR_WRP1A_STRT_0       (0x1U<<0U)

// WRP2AR Configuration

#define FLASH_WRP2AR_WRP2A_STRT         (0xFFU<<0U)
#define FLASH_WRP2AR_WRP2A_STRT_0       (0x1U<<0U)
#define FLASH_WRP2AR_WRP2A_END          (0xFFU<<16U)
#define FLASH_WRP2AR_WRP2A_END_0        (0x1U<<16U)

// PCROP2SR Configuration

#define FLASH_PCROP2SR_PCROP2_STRT      (0x1FFFFU<<0U)
#define FLASH_PCROP2SR_PCROP2_STRT_0    (0x1U<<0U)

// PCROP2ER Configuration

#define FLASH_PCROP2ER_PCROP2_END       (0x1FFFFU<<0U)
#define FLASH_PCROP2ER_PCROP2_END_0     (0x1U<<0U)

// WRP1BR Configuration

#define FLASH_WRP1BR_WRP1B_END          (0xFFU<<16U)
#define FLASH_WRP1BR_WRP1B_END_0        (0x1U<<16U)
#define FLASH_WRP1BR_WRP1B_STRT         (0xFFU<<0U)
#define FLASH_WRP1BR_WRP1B_STRT_0       (0x1U<<0U)

// WRP2BR Configuration

#define FLASH_WRP2BR_WRP2B_END          (0xFFU<<16U)
#define FLASH_WRP2BR_WRP2B_END_0        (0x1U<<16U)
#define FLASH_WRP2BR_WRP2B_STRT         (0xFFU<<0U)
#define FLASH_WRP2BR_WRP2B_STRT_0       (0x1U<<0U)

// CFGR Configuration

#define FLASH_CFGR_LVEN                 (0x1U<<0U)
