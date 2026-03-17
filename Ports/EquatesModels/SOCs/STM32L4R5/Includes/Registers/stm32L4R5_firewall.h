/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_firewall.
; ===================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_firewall equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// FIREWALL address definitions
// ----------------------------

typedef struct {
    volatile    uint32_t    CSSA;
    volatile    uint32_t    CSL;
    volatile    uint32_t    NVDSSA;
    volatile    uint32_t    NVDSL;
    volatile    uint32_t    VDSSA;
    volatile    uint32_t    VDSL;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    CR;
} FIREWALL_TypeDef;

#ifdef __cplusplus
#define FIREWALL    reinterpret_cast<FIREWALL_TypeDef *>(0x40011C00U)

#else
#define FIREWALL    ((FIREWALL_TypeDef *)0x40011C00U)
#endif

// CSSA Configuration

#define FIREWALL_CSSA_ADD       (0xFFFFU<<8)
#define FIREWALL_CSSA_ADD_0     (0x1U<<8)

// CSL Configuration

#define FIREWALL_CSL_LENG       (0x3FFFU<<8)
#define FIREWALL_CSL_LENG_0     (0x1U<<8)

// NVDSSA Configuration

#define FIREWALL_NVDSSA_ADD     (0xFFFFU<<8)
#define FIREWALL_NVDSSA_ADD_0   (0x1U<<8)

// NVDSL Configuration

#define FIREWALL_NVDSL_LENG     (0x3FFFU<<8)
#define FIREWALL_NVDSL_LENG_0   (0x1U<<8)

// VDSSA Configuration

#define FIREWALL_VDSSA_ADD      (0x3FFU<<6)
#define FIREWALL_VDSSA_ADD_0    (0x1U<<6)

// VDSL Configuration

#define FIREWALL_VDSL_LENG      (0x3FFU<<6)
#define FIREWALL_VDSL_LENG_0    (0x1U<<6)

// CR Configuration

#define FIREWALL_CR_FPA         (0x1U<<0)
#define FIREWALL_CR_VDS         (0x1U<<1)
#define FIREWALL_CR_VDE         (0x1U<<2)
