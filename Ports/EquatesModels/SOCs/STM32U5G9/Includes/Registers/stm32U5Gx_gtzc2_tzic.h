/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_gtzc2_tzic equates.
 */

#pragma once

#include    <stdint.h>

// GTZC2_TZIC address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    IER1;
    volatile    uint32_t    IER2;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    SR1;
    volatile    uint32_t    SR2;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    FCR1;
    volatile    uint32_t    FCR2;
} GTZC2_TZIC_TypeDef;

#ifdef __cplusplus
#define GTZC2_TZIC_NS   reinterpret_cast<GTZC2_TZIC_TypeDef *>(0x46023400U)
#define GTZC2_TZIC_S    reinterpret_cast<GTZC2_TZIC_TypeDef *>(0x56023400U)

#else
#define GTZC2_TZIC_NS   ((GTZC2_TZIC_TypeDef *)0x46023400U)
#define GTZC2_TZIC_S    ((GTZC2_TZIC_TypeDef *)0x56023400U)
#endif

// IER1 Configuration

#define GTZC2_TZIC_IER1_ADF1IE          (0x1U<<12U)
#define GTZC2_TZIC_IER1_DAC1IE          (0x1U<<11U)
#define GTZC2_TZIC_IER1_VREFBUFIE       (0x1U<<9U)
#define GTZC2_TZIC_IER1_ADC2IE          (0x1U<<8U)
#define GTZC2_TZIC_IER1_COMPIE          (0x1U<<7U)
#define GTZC2_TZIC_IER1_OPAMPIE         (0x1U<<6U)
#define GTZC2_TZIC_IER1_LPTIM4IE        (0x1U<<5U)
#define GTZC2_TZIC_IER1_LPTIM3IE        (0x1U<<4U)
#define GTZC2_TZIC_IER1_LPTIM1IE        (0x1U<<3U)
#define GTZC2_TZIC_IER1_I2C3IE          (0x1U<<2U)
#define GTZC2_TZIC_IER1_LPUART1IE       (0x1U<<1U)
#define GTZC2_TZIC_IER1_SPI3IE          (0x1U<<0U)

// IER2 Configuration

#define GTZC2_TZIC_IER2_MPCBB4_REGIE    (0x1U<<25U)
#define GTZC2_TZIC_IER2_SRAM4IE         (0x1U<<24U)
#define GTZC2_TZIC_IER2_TZIC2IE         (0x1U<<15U)
#define GTZC2_TZIC_IER2_TZSC2IE         (0x1U<<14U)
#define GTZC2_TZIC_IER2_EXTIIE          (0x1U<<6U)
#define GTZC2_TZIC_IER2_LPDMA1IE        (0x1U<<5U)
#define GTZC2_TZIC_IER2_RCCIE           (0x1U<<4U)
#define GTZC2_TZIC_IER2_PWRIE           (0x1U<<3U)
#define GTZC2_TZIC_IER2_TAMPIE          (0x1U<<2U)
#define GTZC2_TZIC_IER2_RTCIE           (0x1U<<1U)
#define GTZC2_TZIC_IER2_SYSCFGIE        (0x1U<<0U)

// SR1 Configuration

#define GTZC2_TZIC_SR1_ADF1F            (0x1U<<12U)
#define GTZC2_TZIC_SR1_DAC1F            (0x1U<<11U)
#define GTZC2_TZIC_SR1_VREFBUFF         (0x1U<<9U)
#define GTZC2_TZIC_SR1_ADC2F            (0x1U<<8U)
#define GTZC2_TZIC_SR1_COMPF            (0x1U<<7U)
#define GTZC2_TZIC_SR1_OPAMPF           (0x1U<<6U)
#define GTZC2_TZIC_SR1_LPTIM4F          (0x1U<<5U)
#define GTZC2_TZIC_SR1_LPTIM3F          (0x1U<<4U)
#define GTZC2_TZIC_SR1_LPTIM1F          (0x1U<<3U)
#define GTZC2_TZIC_SR1_I2C3F            (0x1U<<2U)
#define GTZC2_TZIC_SR1_LPUART1F         (0x1U<<1U)
#define GTZC2_TZIC_SR1_SPI3F            (0x1U<<0U)

// SR2 Configuration

#define GTZC2_TZIC_SR2_MPCBB4_REGF      (0x1U<<25U)
#define GTZC2_TZIC_SR2_SRAM4F           (0x1U<<24U)
#define GTZC2_TZIC_SR2_TZIC2F           (0x1U<<15U)
#define GTZC2_TZIC_SR2_TZSC2F           (0x1U<<14U)
#define GTZC2_TZIC_SR2_EXTIF            (0x1U<<6U)
#define GTZC2_TZIC_SR2_LPDMA1F          (0x1U<<5U)
#define GTZC2_TZIC_SR2_RCCF             (0x1U<<4U)
#define GTZC2_TZIC_SR2_PWRF             (0x1U<<3U)
#define GTZC2_TZIC_SR2_TAMPF            (0x1U<<2U)
#define GTZC2_TZIC_SR2_RTCF             (0x1U<<1U)
#define GTZC2_TZIC_SR2_SYSCFGF          (0x1U<<0U)

// FCR1 Configuration

#define GTZC2_TZIC_FCR1_CADF1F          (0x1U<<12U)
#define GTZC2_TZIC_FCR1_CDAC1F          (0x1U<<11U)
#define GTZC2_TZIC_FCR1_CVREFBUFF       (0x1U<<9U)
#define GTZC2_TZIC_FCR1_CADC2F          (0x1U<<8U)
#define GTZC2_TZIC_FCR1_CCOMPF          (0x1U<<7U)
#define GTZC2_TZIC_FCR1_COPAMPF         (0x1U<<6U)
#define GTZC2_TZIC_FCR1_CLPTIM4F        (0x1U<<5U)
#define GTZC2_TZIC_FCR1_CLPTIM3F        (0x1U<<4U)
#define GTZC2_TZIC_FCR1_CLPTIM1F        (0x1U<<3U)
#define GTZC2_TZIC_FCR1_CI2C3F          (0x1U<<2U)
#define GTZC2_TZIC_FCR1_CLPUART1F       (0x1U<<1U)
#define GTZC2_TZIC_FCR1_CSPI3F          (0x1U<<0U)

// FCR2 Configuration

#define GTZC2_TZIC_FCR2_CMPCBB4_REGF    (0x1U<<25U)
#define GTZC2_TZIC_FCR2_CSRAM4F         (0x1U<<24U)
#define GTZC2_TZIC_FCR2_CTZIC2F         (0x1U<<15U)
#define GTZC2_TZIC_FCR2_CTZSC2F         (0x1U<<14U)
#define GTZC2_TZIC_FCR2_CEXTIF          (0x1U<<6U)
#define GTZC2_TZIC_FCR2_CLPDMA1F        (0x1U<<5U)
#define GTZC2_TZIC_FCR2_CRCCF           (0x1U<<4U)
#define GTZC2_TZIC_FCR2_CPWRF           (0x1U<<3U)
#define GTZC2_TZIC_FCR2_CTAMPF          (0x1U<<2U)
#define GTZC2_TZIC_FCR2_CRTCF           (0x1U<<1U)
#define GTZC2_TZIC_FCR2_CSYSCFGF        (0x1U<<0U)
