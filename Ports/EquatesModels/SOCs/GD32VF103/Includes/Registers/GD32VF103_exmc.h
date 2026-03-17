/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_exmc.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_exmc equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define EXMC_SNCTL0_NRBKEN      (0x1U<<0)
#define EXMC_SNCTL0_NRMUX       (0x1U<<1)
#define EXMC_SNCTL0_NRTP        (0x3U<<2)
#define EXMC_SNCTL0_NRTP_0      (0x1U<<2)
#define EXMC_SNCTL0_NRW         (0x3U<<4)
#define EXMC_SNCTL0_NRW_0       (0x1U<<4)
#define EXMC_SNCTL0_NREN        (0x1U<<6)
#define EXMC_SNCTL0_NRWTPOL     (0x1U<<9)
#define EXMC_SNCTL0_WREN        (0x1U<<12)
#define EXMC_SNCTL0_NRWTEN      (0x1U<<13)
#define EXMC_SNCTL0_ASYNCWAIT   (0x1U<<15)

// SNTCFG0 Configuration

#define EXMC_SNTCFG0_ASET       (0xFU<<0)
#define EXMC_SNTCFG0_ASET_0     (0x1U<<0)
#define EXMC_SNTCFG0_AHLD       (0xFU<<4)
#define EXMC_SNTCFG0_AHLD_0     (0x1U<<4)
#define EXMC_SNTCFG0_DSET       (0xFFU<<8)
#define EXMC_SNTCFG0_DSET_0     (0x1U<<8)
#define EXMC_SNTCFG0_BUSLAT     (0xFU<<16)
#define EXMC_SNTCFG0_BUSLAT_0   (0x1U<<16)

// SNCTL1 Configuration

#define EXMC_SNCTL1_NRBKEN      (0x1U<<0)
#define EXMC_SNCTL1_NRMUX       (0x1U<<1)
#define EXMC_SNCTL1_NRTP        (0x3U<<2)
#define EXMC_SNCTL1_NRTP_0      (0x1U<<2)
#define EXMC_SNCTL1_NRW         (0x3U<<4)
#define EXMC_SNCTL1_NRW_0       (0x1U<<4)
#define EXMC_SNCTL1_NREN        (0x1U<<6)
#define EXMC_SNCTL1_NRWTPOL     (0x1U<<9)
#define EXMC_SNCTL1_WREN        (0x1U<<12)
#define EXMC_SNCTL1_NRWTEN      (0x1U<<13)
#define EXMC_SNCTL1_ASYNCWAIT   (0x1U<<15)
