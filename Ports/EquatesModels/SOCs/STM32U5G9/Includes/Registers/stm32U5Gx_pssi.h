/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_pssi equates.
 */

#pragma once

#include    <stdint.h>

// PSSI address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    RIS;
    volatile    uint32_t    IER;
    volatile    uint32_t    MIS;
    volatile    uint32_t    ICR;
    volatile    uint32_t    RESERVED0[4];
    volatile    uint32_t    DR;
} PSSI_TypeDef;

#ifdef __cplusplus
#define PSSI_NS reinterpret_cast<PSSI_TypeDef *>(0x4202C400U)
#define PSSI_S  reinterpret_cast<PSSI_TypeDef *>(0x5202C400U)

#else
#define PSSI_NS ((PSSI_TypeDef *)0x4202C400U)
#define PSSI_S  ((PSSI_TypeDef *)0x5202C400U)
#endif

// CR Configuration

#define PSSI_CR_OUTEN       (0x1U<<31U)
#define PSSI_CR_DMAEN       (0x1U<<30U)
#define PSSI_CR_DERDYCFG    (0x7U<<18U)
#define PSSI_CR_DERDYCFG_0  (0x1U<<18U)
#define PSSI_CR_ENABLE      (0x1U<<14U)
#define PSSI_CR_EDM         (0x3U<<10U)
#define PSSI_CR_EDM_0       (0x1U<<10U)
#define PSSI_CR_RDYPOL      (0x1U<<8U)
#define PSSI_CR_DEPOL       (0x1U<<6U)
#define PSSI_CR_CKPOL       (0x1U<<5U)

// SR Configuration

#define PSSI_SR_RTT1B       (0x1U<<3U)
#define PSSI_SR_RTT4B       (0x1U<<2U)

// RIS Configuration

#define PSSI_RIS_OVR_RIS    (0x1U<<1U)

// IER Configuration

#define PSSI_IER_OVR_IE     (0x1U<<1U)

// MIS Configuration

#define PSSI_MIS_OVR_MIS    (0x1U<<1U)

// ICR Configuration

#define PSSI_ICR_OVR_ISC    (0x1U<<1U)

// DR Configuration

#define PSSI_DR_BYTE3       (0xFFU<<24U)
#define PSSI_DR_BYTE3_0     (0x1U<<24U)
#define PSSI_DR_BYTE2       (0xFFU<<16U)
#define PSSI_DR_BYTE2_0     (0x1U<<16U)
#define PSSI_DR_BYTE1       (0xFFU<<8U)
#define PSSI_DR_BYTE1_0     (0x1U<<8U)
#define PSSI_DR_BYTE0       (0xFFU<<0U)
#define PSSI_DR_BYTE0_0     (0x1U<<0U)
