/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_rng equates.
 */

#pragma once

#include    <stdint.h>

// RNG address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    DR;
    volatile    uint32_t    NSCR;
    volatile    uint32_t    HTCR;
} RNG_TypeDef;

#ifdef __cplusplus
#define RNG_NS  reinterpret_cast<RNG_TypeDef *>(0x44020000U)
#define RNG_S   reinterpret_cast<RNG_TypeDef *>(0x54020000U)

#else
#define RNG_NS  ((RNG_TypeDef *)0x44020000U)
#define RNG_S   ((RNG_TypeDef *)0x54020000U)
#endif

// CR Configuration

#define RNG_CR_CONFIGLOCK       (0x1U<<31U)
#define RNG_CR_CONDRST          (0x1U<<30U)
#define RNG_CR_RNG_CONFIG1      (0x3FU<<20U)
#define RNG_CR_RNG_CONFIG1_0    (0x1U<<20U)
#define RNG_CR_CLKDIV           (0xFU<<16U)
#define RNG_CR_CLKDIV_0         (0x1U<<16U)
#define RNG_CR_RNG_CONFIG2      (0x7U<<13U)
#define RNG_CR_RNG_CONFIG2_0    (0x1U<<13U)
#define RNG_CR_NISTC            (0x1U<<12U)
#define RNG_CR_RNG_CONFIG3      (0xFU<<8U)
#define RNG_CR_RNG_CONFIG3_0    (0x1U<<8U)
#define RNG_CR_ARDIS            (0x1U<<7U)
#define RNG_CR_CED              (0x1U<<5U)
#define RNG_CR_IE               (0x1U<<3U)
#define RNG_CR_RNGEN            (0x1U<<2U)

#define RNG_CR_CONFIGLOCK_B_0X0 (0x0U<<31U)
#define RNG_CR_CONFIGLOCK_B_0X1 (0x1U<<31U)
#define RNG_CR_CLKDIV_B_0X0     (0x0U<<16U)
#define RNG_CR_CLKDIV_B_0X1     (0x1U<<16U)
#define RNG_CR_CLKDIV_B_0X2     (0x2U<<16U)
#define RNG_CR_CLKDIV_B_0XF     (0xFU<<16U)
#define RNG_CR_NISTC_B_0X0      (0x0U<<12U)
#define RNG_CR_NISTC_B_0X1      (0x1U<<12U)
#define RNG_CR_ARDIS_B_0X0      (0x0U<<7U)
#define RNG_CR_ARDIS_B_0X1      (0x1U<<7U)
#define RNG_CR_CED_B_0X0        (0x0U<<5U)
#define RNG_CR_CED_B_0X1        (0x1U<<5U)
#define RNG_CR_IE_B_0X0         (0x0U<<3U)
#define RNG_CR_IE_B_0X1         (0x1U<<3U)
#define RNG_CR_RNGEN_B_0X0      (0x0U<<2U)
#define RNG_CR_RNGEN_B_0X1      (0x1U<<2U)

// SR Configuration

#define RNG_SR_SEIS             (0x1U<<6U)
#define RNG_SR_CEIS             (0x1U<<5U)
#define RNG_SR_SECS             (0x1U<<2U)
#define RNG_SR_CECS             (0x1U<<1U)
#define RNG_SR_DRDY             (0x1U<<0U)

#define RNG_SR_SEIS_B_0X0       (0x0U<<6U)
#define RNG_SR_SEIS_B_0X1       (0x1U<<6U)
#define RNG_SR_CEIS_B_0X0       (0x0U<<5U)
#define RNG_SR_CEIS_B_0X1       (0x1U<<5U)
#define RNG_SR_SECS_B_0X0       (0x0U<<2U)
#define RNG_SR_SECS_B_0X1       (0x1U<<2U)
#define RNG_SR_CECS_B_0X0       (0x0U<<1U)
#define RNG_SR_CECS_B_0X1       (0x1U<<1U)
#define RNG_SR_DRDY_B_0X0       (0x0U<<0U)
#define RNG_SR_DRDY_B_0X1       (0x1U<<0U)

// DR Configuration

#define RNG_DR_RNDATA           (0xFFFFFFFFU<<0U)
#define RNG_DR_RNDATA_0         (0x1U<<0U)

// NSCR Configuration

#define RNG_NSCR_EN_OSC6        (0x7U<<15U)
#define RNG_NSCR_EN_OSC6_0      (0x1U<<15U)
#define RNG_NSCR_EN_OSC5        (0x7U<<12U)
#define RNG_NSCR_EN_OSC5_0      (0x1U<<12U)
#define RNG_NSCR_EN_OSC4        (0x7U<<9U)
#define RNG_NSCR_EN_OSC4_0      (0x1U<<9U)
#define RNG_NSCR_EN_OSC3        (0x7U<<6U)
#define RNG_NSCR_EN_OSC3_0      (0x1U<<6U)
#define RNG_NSCR_EN_OSC2        (0x7U<<3U)
#define RNG_NSCR_EN_OSC2_0      (0x1U<<3U)
#define RNG_NSCR_EN_OSC1        (0x7U<<0U)
#define RNG_NSCR_EN_OSC1_0      (0x1U<<0U)

// HTCR Configuration

#define RNG_HTCR_HTCFG          (0xFFFFFFFFU<<0U)
#define RNG_HTCR_HTCFG_0        (0x1U<<0U)
