/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_rng equates.
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
    volatile    uint32_t    HTCR0;
    volatile    uint32_t    HTCR1;
    volatile    uint32_t    HTCR2;
    volatile    uint32_t    HTCR3;
} RNG_TypeDef;

#if (defined(__cplusplus))
#define RNG_NS  reinterpret_cast<RNG_TypeDef *>(0x44020800u)
#define RNG_S   reinterpret_cast<RNG_TypeDef *>(0x54020800u)

#else
#define RNG_NS  ((RNG_TypeDef *)0x44020800u)
#define RNG_S   ((RNG_TypeDef *)0x54020800u)
#endif

// CR Configuration

#define RNG_CR_CONFIGLOCK       (0x1u<<31)
#define RNG_CR_CONDRST          (0x1u<<30)
#define RNG_CR_RNG_CONFIG1      (0x3Fu<<20)
#define RNG_CR_RNG_CONFIG1_0    (0x1u<<20)
#define RNG_CR_CLKDIV           (0xFu<<16)
#define RNG_CR_CLKDIV_0         (0x1u<<16)
#define RNG_CR_RNG_CONFIG2      (0x7u<<13)
#define RNG_CR_RNG_CONFIG2_0    (0x1u<<13)
#define RNG_CR_NISTC            (0x1u<<12)
#define RNG_CR_RNG_CONFIG3      (0xFu<<8)
#define RNG_CR_RNG_CONFIG3_0    (0x1u<<8)
#define RNG_CR_ARDIS            (0x1u<<7)
#define RNG_CR_CED              (0x1u<<5)
#define RNG_CR_IE               (0x1u<<3)
#define RNG_CR_RNGEN            (0x1u<<2)

#define RNG_CR_CONFIGLOCK_B_0X0 (0x0u<<31)
#define RNG_CR_CONFIGLOCK_B_0X1 (0x1u<<31)
#define RNG_CR_CLKDIV_B_0X0     (0x0u<<16)
#define RNG_CR_CLKDIV_B_0X1     (0x1u<<16)
#define RNG_CR_CLKDIV_B_0X2     (0x2u<<16)
#define RNG_CR_CLKDIV_B_0XF     (0xFu<<16)
#define RNG_CR_NISTC_B_0X0      (0x0u<<12)
#define RNG_CR_NISTC_B_0X1      (0x1u<<12)
#define RNG_CR_ARDIS_B_0X0      (0x0u<<7)
#define RNG_CR_ARDIS_B_0X1      (0x1u<<7)
#define RNG_CR_CED_B_0X0        (0x0u<<5)
#define RNG_CR_CED_B_0X1        (0x1u<<5)
#define RNG_CR_IE_B_0X0         (0x0u<<3)
#define RNG_CR_IE_B_0X1         (0x1u<<3)
#define RNG_CR_RNGEN_B_0X0      (0x0u<<2)
#define RNG_CR_RNGEN_B_0X1      (0x1u<<2)

// SR Configuration

#define RNG_SR_SEIS             (0x1u<<6)
#define RNG_SR_CEIS             (0x1u<<5)
#define RNG_SR_BUSY             (0x1u<<4)
#define RNG_SR_SECS             (0x1u<<2)
#define RNG_SR_CECS             (0x1u<<1)
#define RNG_SR_DRDY             (0x1u<<0)

#define RNG_SR_SEIS_B_0X0       (0x0u<<6)
#define RNG_SR_SEIS_B_0X1       (0x1u<<6)
#define RNG_SR_CEIS_B_0X0       (0x0u<<5)
#define RNG_SR_CEIS_B_0X1       (0x1u<<5)
#define RNG_SR_BUSY_B_0X0       (0x0u<<4)
#define RNG_SR_BUSY_B_0X1       (0x1u<<4)
#define RNG_SR_SECS_B_0X0       (0x0u<<2)
#define RNG_SR_SECS_B_0X1       (0x1u<<2)
#define RNG_SR_CECS_B_0X0       (0x0u<<1)
#define RNG_SR_CECS_B_0X1       (0x1u<<1)
#define RNG_SR_DRDY_B_0X0       (0x0u<<0)
#define RNG_SR_DRDY_B_0X1       (0x1u<<0)

// DR Configuration

#define RNG_DR_RNDATA           (0xFFFFFFFFu<<0)
#define RNG_DR_RNDATA_0         (0x1u<<0)

// NSCR Configuration

#define RNG_NSCR_EN_OSC3        (0x7u<<6)
#define RNG_NSCR_EN_OSC3_0      (0x1u<<6)
#define RNG_NSCR_EN_OSC2        (0x7u<<3)
#define RNG_NSCR_EN_OSC2_0      (0x1u<<3)
#define RNG_NSCR_EN_OSC1        (0x7u<<0)
#define RNG_NSCR_EN_OSC1_0      (0x1u<<0)

// HTCR0 Configuration

#define RNG_HTCR0_HTCFG         (0xFFFFFFFFu<<0)
#define RNG_HTCR0_HTCFG_0       (0x1u<<0)

// HTCR1 Configuration

#define RNG_HTCR1_HTCFG         (0xFFFFFFFFu<<0)
#define RNG_HTCR1_HTCFG_0       (0x1u<<0)

// HTCR2 Configuration

#define RNG_HTCR2_HTCFG         (0xFFFFFFFFu<<0)
#define RNG_HTCR2_HTCFG_0       (0x1u<<0)

// HTCR3 Configuration

#define RNG_HTCR3_HTCFG         (0xFFFFFFFFu<<0)
#define RNG_HTCR3_HTCFG_0       (0x1u<<0)
