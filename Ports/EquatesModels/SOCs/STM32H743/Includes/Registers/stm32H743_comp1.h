/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_comp1 equates.
 */

#pragma once

#include    <stdint.h>

// COMP1 address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    SR;
    volatile    uint32_t    ICFR;
    volatile    uint32_t    OR;
    volatile    uint32_t    CFGR1;
    volatile    uint32_t    CFGR2;
} COMP1_TypeDef;

#ifdef __cplusplus
#define COMP1s  reinterpret_cast<COMP1_TypeDef *>(0x58003800U)

#else
#define COMP1s  ((COMP1_TypeDef *)0x58003800U)
#endif

// SR Configuration

#define COMP1_SR_C2IF           (0x1U<<17U)
#define COMP1_SR_C1IF           (0x1U<<16U)
#define COMP1_SR_C2VAL          (0x1U<<1U)
#define COMP1_SR_C1VAL          (0x1U<<0U)

// ICFR Configuration

#define COMP1_ICFR_CC2IF        (0x1U<<17U)
#define COMP1_ICFR_CC1IF        (0x1U<<16U)

// OR Configuration

#define COMP1_OR_OR             (0x1FFFFFU<<11U)
#define COMP1_OR_OR_0           (0x1U<<11U)
#define COMP1_OR_AFOP           (0x7FFU<<0U)
#define COMP1_OR_AFOP_0         (0x1U<<0U)

// CFGR1 Configuration

#define COMP1_CFGR1_LOCK        (0x1U<<31U)
#define COMP1_CFGR1_BLANKING    (0xFU<<24U)
#define COMP1_CFGR1_BLANKING_0  (0x1U<<24U)
#define COMP1_CFGR1_INPSEL      (0x1U<<20U)
#define COMP1_CFGR1_INMSEL      (0x7U<<16U)
#define COMP1_CFGR1_INMSEL_0    (0x1U<<16U)
#define COMP1_CFGR1_PWRMODE     (0x3U<<12U)
#define COMP1_CFGR1_PWRMODE_0   (0x1U<<12U)
#define COMP1_CFGR1_HYST        (0x3U<<8U)
#define COMP1_CFGR1_HYST_0      (0x1U<<8U)
#define COMP1_CFGR1_ITEN        (0x1U<<6U)
#define COMP1_CFGR1_POLARITY    (0x1U<<3U)
#define COMP1_CFGR1_SCALEN      (0x1U<<2U)
#define COMP1_CFGR1_BRGEN       (0x1U<<1U)
#define COMP1_CFGR1_EN          (0x1U<<0U)

// CFGR2 Configuration

#define COMP1_CFGR2_LOCK        (0x1U<<31U)
#define COMP1_CFGR2_BLANKING    (0xFU<<24U)
#define COMP1_CFGR2_BLANKING_0  (0x1U<<24U)
#define COMP1_CFGR2_INPSEL      (0x1U<<20U)
#define COMP1_CFGR2_INMSEL      (0x7U<<16U)
#define COMP1_CFGR2_INMSEL_0    (0x1U<<16U)
#define COMP1_CFGR2_PWRMODE     (0x3U<<12U)
#define COMP1_CFGR2_PWRMODE_0   (0x1U<<12U)
#define COMP1_CFGR2_HYST        (0x3U<<8U)
#define COMP1_CFGR2_HYST_0      (0x1U<<8U)
#define COMP1_CFGR2_ITEN        (0x1U<<6U)
#define COMP1_CFGR2_WINMODE     (0x1U<<4U)
#define COMP1_CFGR2_POLARITY    (0x1U<<3U)
#define COMP1_CFGR2_SCALEN      (0x1U<<2U)
#define COMP1_CFGR2_BRGEN       (0x1U<<1U)
#define COMP1_CFGR2_EN          (0x1U<<0U)
