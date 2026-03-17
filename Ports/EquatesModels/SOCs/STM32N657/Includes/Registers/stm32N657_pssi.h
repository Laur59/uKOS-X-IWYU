/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_pssi.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_pssi equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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
#define PSSI_NS reinterpret_cast<PSSI_TypeDef *>(0x48026400U)
#define PSSI_S  reinterpret_cast<PSSI_TypeDef *>(0x58026400U)

#else
#define PSSI_NS ((PSSI_TypeDef *)0x48026400U)
#define PSSI_S  ((PSSI_TypeDef *)0x58026400U)
#endif

// CR Configuration

#define PSSI_CR_OUTEN               (0x1U<<31)
#define PSSI_CR_DMAEN               (0x1U<<30)
#define PSSI_CR_CKSRC               (0x1U<<29)
#define PSSI_CR_DERDYCFG            (0x7U<<18)
#define PSSI_CR_DERDYCFG_0          (0x1U<<18)
#define PSSI_CR_ENABLE              (0x1U<<14)
#define PSSI_CR_EDM                 (0x3U<<10)
#define PSSI_CR_EDM_0               (0x1U<<10)
#define PSSI_CR_RDYPOL              (0x1U<<8)
#define PSSI_CR_DEPOL               (0x1U<<6)
#define PSSI_CR_CKPOL               (0x1U<<5)

#define PSSI_CR_OUTEN_B_0X0         (0x0U<<31)
#define PSSI_CR_OUTEN_B_0X1         (0x1U<<31)
#define PSSI_CR_DMAEN_B_0X0         (0x0U<<30)
#define PSSI_CR_DMAEN_B_0X1         (0x1U<<30)
#define PSSI_CR_CKSRC_B_0X0         (0x0U<<29)
#define PSSI_CR_CKSRC_B_0X1         (0x1U<<29)
#define PSSI_CR_DERDYCFG_B_0X0      (0x0U<<18)
#define PSSI_CR_DERDYCFG_B_0X1      (0x1U<<18)
#define PSSI_CR_DERDYCFG_B_0X2      (0x2U<<18)
#define PSSI_CR_DERDYCFG_B_0X3      (0x3U<<18)
#define PSSI_CR_DERDYCFG_B_0X4      (0x4U<<18)
#define PSSI_CR_DERDYCFG_B_0X5      (0x5U<<18)
#define PSSI_CR_DERDYCFG_B_0X6      (0x6U<<18)
#define PSSI_CR_DERDYCFG_B_0X7      (0x7U<<18)
#define PSSI_CR_ENABLE_B_0X0        (0x0U<<14)
#define PSSI_CR_ENABLE_B_0X1        (0x1U<<14)
#define PSSI_CR_EDM_B_0X0           (0x0U<<10)
#define PSSI_CR_EDM_B_0X3           (0x3U<<10)
#define PSSI_CR_RDYPOL_B_0X0        (0x0U<<8)
#define PSSI_CR_RDYPOL_B_0X1        (0x1U<<8)
#define PSSI_CR_DEPOL_B_0X0         (0x0U<<6)
#define PSSI_CR_DEPOL_B_0X1         (0x1U<<6)
#define PSSI_CR_CKPOL_B_0X0         (0x0U<<5)
#define PSSI_CR_CKPOL_B_0X1         (0x1U<<5)

// SR Configuration

#define PSSI_SR_RTT1B               (0x1U<<3)
#define PSSI_SR_RTT4B               (0x1U<<2)

#define PSSI_SR_RTT1B_B_0X1         (0x1U<<3)
#define PSSI_SR_RTT1B_B_0X0         (0x0U<<3)
#define PSSI_SR_RTT4B_B_0X1         (0x1U<<2)
#define PSSI_SR_RTT4B_B_0X0         (0x0U<<2)

// RIS Configuration

#define PSSI_RIS_OVR_RIS            (0x1U<<1)

#define PSSI_RIS_OVR_RIS_B_0X0      (0x0U<<1)
#define PSSI_RIS_OVR_RIS_B_0X1      (0x1U<<1)

// IER Configuration

#define PSSI_IER_OVR_IE             (0x1U<<1)

#define PSSI_IER_OVR_IE_B_0X0       (0x0U<<1)
#define PSSI_IER_OVR_IE_B_0X1       (0x1U<<1)

// MIS Configuration

#define PSSI_MIS_OVR_MIS            (0x1U<<1)

#define PSSI_MIS_OVR_MIS_B_0X0      (0x0U<<1)
#define PSSI_MIS_OVR_MIS_B_0X1      (0x1U<<1)

// ICR Configuration

#define PSSI_ICR_OVR_ISC            (0x1U<<1)

// DR Configuration

#define PSSI_DR_BYTE3               (0xFFU<<24)
#define PSSI_DR_BYTE3_0             (0x1U<<24)
#define PSSI_DR_BYTE2               (0xFFU<<16)
#define PSSI_DR_BYTE2_0             (0x1U<<16)
#define PSSI_DR_BYTE1               (0xFFU<<8)
#define PSSI_DR_BYTE1_0             (0x1U<<8)
#define PSSI_DR_BYTE0               (0xFFU<<0)
#define PSSI_DR_BYTE0_0             (0x1U<<0)
