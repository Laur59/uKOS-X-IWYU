/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_gtzc2_tzsc equates.
 */

#pragma once

#include    <stdint.h>

// GTZC2_TZSC address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0[3];
    volatile    uint32_t    SECCFGR1;
    volatile    uint32_t    RESERVED1[3];
    volatile    uint32_t    PRIVCFGR1;
} GTZC2_TZSC_TypeDef;

#ifdef __cplusplus
#define GTZC2_TZSC_NS   reinterpret_cast<GTZC2_TZSC_TypeDef *>(0x46023000U)
#define GTZC2_TZSC_S    reinterpret_cast<GTZC2_TZSC_TypeDef *>(0x56023000U)

#else
#define GTZC2_TZSC_NS   ((GTZC2_TZSC_TypeDef *)0x46023000U)
#define GTZC2_TZSC_S    ((GTZC2_TZSC_TypeDef *)0x56023000U)
#endif

// CR Configuration

#define GTZC2_TZSC_CR_LCK                   (0x1U<<0U)

// SECCFGR1 Configuration

#define GTZC2_TZSC_SECCFGR1_ADF1SEC         (0x1U<<12U)
#define GTZC2_TZSC_SECCFGR1_DAC1SEC         (0x1U<<11U)
#define GTZC2_TZSC_SECCFGR1_VREFBUFSEC      (0x1U<<9U)
#define GTZC2_TZSC_SECCFGR1_ADC2SEC         (0x1U<<8U)
#define GTZC2_TZSC_SECCFGR1_COMPSEC         (0x1U<<7U)
#define GTZC2_TZSC_SECCFGR1_OPAMPSEC        (0x1U<<6U)
#define GTZC2_TZSC_SECCFGR1_LPTIM4SEC       (0x1U<<5U)
#define GTZC2_TZSC_SECCFGR1_LPTIM3SEC       (0x1U<<4U)
#define GTZC2_TZSC_SECCFGR1_LPTIM1SEC       (0x1U<<3U)
#define GTZC2_TZSC_SECCFGR1_I2C3SEC         (0x1U<<2U)
#define GTZC2_TZSC_SECCFGR1_LPUART1SEC      (0x1U<<1U)
#define GTZC2_TZSC_SECCFGR1_SPI3SEC         (0x1U<<0U)

// PRIVCFGR1 Configuration

#define GTZC2_TZSC_PRIVCFGR1_ADF1PRIV       (0x1U<<12U)
#define GTZC2_TZSC_PRIVCFGR1_DAC1PRIV       (0x1U<<11U)
#define GTZC2_TZSC_PRIVCFGR1_VREFBUFPRIV    (0x1U<<9U)
#define GTZC2_TZSC_PRIVCFGR1_ADC2PRIV       (0x1U<<8U)
#define GTZC2_TZSC_PRIVCFGR1_COMPPRIV       (0x1U<<7U)
#define GTZC2_TZSC_PRIVCFGR1_OPAMPPRIV      (0x1U<<6U)
#define GTZC2_TZSC_PRIVCFGR1_LPTIM4PRIV     (0x1U<<5U)
#define GTZC2_TZSC_PRIVCFGR1_LPTIM3PRIV     (0x1U<<4U)
#define GTZC2_TZSC_PRIVCFGR1_LPTIM1PRIV     (0x1U<<3U)
#define GTZC2_TZSC_PRIVCFGR1_I2C3PRIV       (0x1U<<2U)
#define GTZC2_TZSC_PRIVCFGR1_LPUART1PRIV    (0x1U<<1U)
#define GTZC2_TZSC_PRIVCFGR1_SPI3PRIV       (0x1U<<0U)
