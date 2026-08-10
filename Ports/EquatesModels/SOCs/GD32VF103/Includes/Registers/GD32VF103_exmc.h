/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_exmc equates.
 */

#pragma once

#include    <stdint.h>

// EXMC address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    SNCTL0;
    volatile    uint32_t    SNTCFG0;
    volatile    uint32_t    SNCTL1;
} EXMC_TypeDef;

#ifdef __cplusplus
#define EXMC    reinterpret_cast<EXMC_TypeDef *>(0xA0000000U)

#else
#define EXMC    ((EXMC_TypeDef *)0xA0000000U)
#endif

// SNCTL0 Configuration

#define EXMC_SNCTL0_NRBKEN      (0x1U<<0U)
#define EXMC_SNCTL0_NRMUX       (0x1U<<1U)
#define EXMC_SNCTL0_NRTP        (0x3U<<2U)
#define EXMC_SNCTL0_NRTP_0      (0x1U<<2U)
#define EXMC_SNCTL0_NRW         (0x3U<<4U)
#define EXMC_SNCTL0_NRW_0       (0x1U<<4U)
#define EXMC_SNCTL0_NREN        (0x1U<<6U)
#define EXMC_SNCTL0_NRWTPOL     (0x1U<<9U)
#define EXMC_SNCTL0_WREN        (0x1U<<12U)
#define EXMC_SNCTL0_NRWTEN      (0x1U<<13U)
#define EXMC_SNCTL0_ASYNCWAIT   (0x1U<<15U)

// SNTCFG0 Configuration

#define EXMC_SNTCFG0_ASET       (0xFU<<0U)
#define EXMC_SNTCFG0_ASET_0     (0x1U<<0U)
#define EXMC_SNTCFG0_AHLD       (0xFU<<4U)
#define EXMC_SNTCFG0_AHLD_0     (0x1U<<4U)
#define EXMC_SNTCFG0_DSET       (0xFFU<<8U)
#define EXMC_SNTCFG0_DSET_0     (0x1U<<8U)
#define EXMC_SNTCFG0_BUSLAT     (0xFU<<16U)
#define EXMC_SNTCFG0_BUSLAT_0   (0x1U<<16U)

// SNCTL1 Configuration

#define EXMC_SNCTL1_NRBKEN      (0x1U<<0U)
#define EXMC_SNCTL1_NRMUX       (0x1U<<1U)
#define EXMC_SNCTL1_NRTP        (0x3U<<2U)
#define EXMC_SNCTL1_NRTP_0      (0x1U<<2U)
#define EXMC_SNCTL1_NRW         (0x3U<<4U)
#define EXMC_SNCTL1_NRW_0       (0x1U<<4U)
#define EXMC_SNCTL1_NREN        (0x1U<<6U)
#define EXMC_SNCTL1_NRWTPOL     (0x1U<<9U)
#define EXMC_SNCTL1_WREN        (0x1U<<12U)
#define EXMC_SNCTL1_NRWTEN      (0x1U<<13U)
#define EXMC_SNCTL1_ASYNCWAIT   (0x1U<<15U)
