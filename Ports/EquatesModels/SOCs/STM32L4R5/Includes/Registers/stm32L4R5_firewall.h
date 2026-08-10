/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_firewall equates.
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

#define FIREWALL_CSSA_ADD       (0xFFFFU<<8U)
#define FIREWALL_CSSA_ADD_0     (0x1U<<8U)

// CSL Configuration

#define FIREWALL_CSL_LENG       (0x3FFFU<<8U)
#define FIREWALL_CSL_LENG_0     (0x1U<<8U)

// NVDSSA Configuration

#define FIREWALL_NVDSSA_ADD     (0xFFFFU<<8U)
#define FIREWALL_NVDSSA_ADD_0   (0x1U<<8U)

// NVDSL Configuration

#define FIREWALL_NVDSL_LENG     (0x3FFFU<<8U)
#define FIREWALL_NVDSL_LENG_0   (0x1U<<8U)

// VDSSA Configuration

#define FIREWALL_VDSSA_ADD      (0x3FFU<<6U)
#define FIREWALL_VDSSA_ADD_0    (0x1U<<6U)

// VDSL Configuration

#define FIREWALL_VDSL_LENG      (0x3FFU<<6U)
#define FIREWALL_VDSL_LENG_0    (0x1U<<6U)

// CR Configuration

#define FIREWALL_CR_FPA         (0x1U<<0U)
#define FIREWALL_CR_VDS         (0x1U<<1U)
#define FIREWALL_CR_VDE         (0x1U<<2U)
