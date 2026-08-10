/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_ramecc3 equates.
 */

#pragma once

#include    <stdint.h>

// RAMECC3 address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    IER;
    volatile    uint32_t    RESERVED0[7];
    volatile    uint32_t    M1CR;
    volatile    uint32_t    M1SR;
    volatile    uint32_t    M1FAR;
    volatile    uint32_t    M1FDRL;
    volatile    uint32_t    M1FDRH;
    volatile    uint32_t    M1FECR;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    M2CR;
    volatile    uint32_t    M2SR;
    volatile    uint32_t    M2FAR;
    volatile    uint32_t    M2FDRL;
    volatile    uint32_t    M2FDRH;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    M2FECR;
} RAMECC3_TypeDef;

#ifdef __cplusplus
#define RAMECC3 reinterpret_cast<RAMECC3_TypeDef *>(0x58027000U)

#else
#define RAMECC3 ((RAMECC3_TypeDef *)0x58027000U)
#endif

// IER Configuration

#define RAMECC3_IER_GECCDEBWIE  (0x1U<<3U)
#define RAMECC3_IER_GECCDEIE    (0x1U<<2U)
#define RAMECC3_IER_GECCSEIE_   (0x1U<<1U)
#define RAMECC3_IER_GIE         (0x1U<<0U)

// M1CR Configuration

#define RAMECC3_M1CR_ECCELEN    (0x1U<<5U)
#define RAMECC3_M1CR_ECCDEBWIE  (0x1U<<4U)
#define RAMECC3_M1CR_ECCDEIE    (0x1U<<3U)
#define RAMECC3_M1CR_ECCSEIE    (0x1U<<2U)

// M1SR Configuration

#define RAMECC3_M1SR_DEBWDF     (0x1U<<2U)
#define RAMECC3_M1SR_DEDF       (0x1U<<1U)
#define RAMECC3_M1SR_SEDCF      (0x1U<<0U)

// M1FAR Configuration

#define RAMECC3_M1FAR_FADD      (0xFFFFFFFFU<<0U)
#define RAMECC3_M1FAR_FADD_0    (0x1U<<0U)

// M1FDRL Configuration

#define RAMECC3_M1FDRL_FDATAL   (0xFFFFFFFFU<<0U)
#define RAMECC3_M1FDRL_FDATAL_0 (0x1U<<0U)

// M1FDRH Configuration

#define RAMECC3_M1FDRH_FDATAH   (0xFFFFFFFFU<<0U)
#define RAMECC3_M1FDRH_FDATAH_0 (0x1U<<0U)

// M1FECR Configuration

#define RAMECC3_M1FECR_FEC      (0xFFFFFFFFU<<0U)
#define RAMECC3_M1FECR_FEC_0    (0x1U<<0U)

// M2CR Configuration

#define RAMECC3_M2CR_ECCELEN    (0x1U<<5U)
#define RAMECC3_M2CR_ECCDEBWIE  (0x1U<<4U)
#define RAMECC3_M2CR_ECCDEIE    (0x1U<<3U)
#define RAMECC3_M2CR_ECCSEIE    (0x1U<<2U)

// M2SR Configuration

#define RAMECC3_M2SR_DEBWDF     (0x1U<<2U)
#define RAMECC3_M2SR_DEDF       (0x1U<<1U)
#define RAMECC3_M2SR_SEDCF      (0x1U<<0U)

// M2FAR Configuration

#define RAMECC3_M2FAR_FADD      (0xFFFFFFFFU<<0U)
#define RAMECC3_M2FAR_FADD_0    (0x1U<<0U)

// M2FDRL Configuration

#define RAMECC3_M2FDRL_FDATAL   (0xFFFFFFFFU<<0U)
#define RAMECC3_M2FDRL_FDATAL_0 (0x1U<<0U)

// M2FDRH Configuration

#define RAMECC3_M2FDRH_FDATAH   (0xFFFFFFFFU<<0U)
#define RAMECC3_M2FDRH_FDATAH_0 (0x1U<<0U)

// M2FECR Configuration

#define RAMECC3_M2FECR_FEC      (0xFFFFFFFFU<<0U)
#define RAMECC3_M2FECR_FEC_0    (0x1U<<0U)
