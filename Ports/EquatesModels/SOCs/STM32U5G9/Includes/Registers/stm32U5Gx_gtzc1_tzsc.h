/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_gtzc1_tzsc equates.
 */

#pragma once

#include    <stdint.h>

// GTZC1_TZSC address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0[3];
    volatile    uint32_t    SECCFGR1;
    volatile    uint32_t    SECCFGR2;
    volatile    uint32_t    SECCFGR3;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    PRIVCFGR1;
    volatile    uint32_t    PRIVCFGR2;
    volatile    uint32_t    PRIVCFGR3;
    volatile    uint32_t    RESERVED2[5];
    volatile    uint32_t    MPCWM1ACFGR;
    volatile    uint32_t    MPCWM1AR;
    volatile    uint32_t    MPCWM1BCFGR;
    volatile    uint32_t    MPCWM1BR;
    volatile    uint32_t    MPCWM2ACFGR;
    volatile    uint32_t    MPCWM2AR;
    volatile    uint32_t    MPCWM2BCFGR;
    volatile    uint32_t    MPCWM2BR;
    volatile    uint32_t    MPCWM3ACFGR;
    volatile    uint32_t    MPCWM3AR;
    volatile    uint32_t    RESERVED3[2];
    volatile    uint32_t    MPCWM4ACFGR;
    volatile    uint32_t    MPCWM4AR;
    volatile    uint32_t    RESERVED4[2];
    volatile    uint32_t    MPCWM5ACFGR;
    volatile    uint32_t    MPCWM5AR;
    volatile    uint32_t    MPCWM5BCFGR;
    volatile    uint32_t    MPCWM5BR;
    volatile    uint32_t    MPCWM6ACFGR;
    volatile    uint32_t    MPCWM6AR;
    volatile    uint32_t    MPCWM6BCFGR;
    volatile    uint32_t    MPCWM6BR;
} GTZC1_TZSC_TypeDef;

#ifdef __cplusplus
#define GTZC1_TZSC_NS   reinterpret_cast<GTZC1_TZSC_TypeDef *>(0x40032400U)
#define GTZC1_TZSC_S    reinterpret_cast<GTZC1_TZSC_TypeDef *>(0x50032400U)

#else
#define GTZC1_TZSC_NS   ((GTZC1_TZSC_TypeDef *)0x40032400U)
#define GTZC1_TZSC_S    ((GTZC1_TZSC_TypeDef *)0x50032400U)
#endif

// CR Configuration

#define GTZC1_TZSC_CR_LCK                       (0x1U<<0U)

// SECCFGR1 Configuration

#define GTZC1_TZSC_SECCFGR1_I2C6SEC             (0x1U<<23U)
#define GTZC1_TZSC_SECCFGR1_I2C5SEC             (0x1U<<22U)
#define GTZC1_TZSC_SECCFGR1_USART6SEC           (0x1U<<21U)
#define GTZC1_TZSC_SECCFGR1_UCPD1SEC            (0x1U<<19U)
#define GTZC1_TZSC_SECCFGR1_FDCAN1SEC           (0x1U<<18U)
#define GTZC1_TZSC_SECCFGR1_LPTIM2SEC           (0x1U<<17U)
#define GTZC1_TZSC_SECCFGR1_I2C4SEC             (0x1U<<16U)
#define GTZC1_TZSC_SECCFGR1_CRSSEC              (0x1U<<15U)
#define GTZC1_TZSC_SECCFGR1_I2C2SEC             (0x1U<<14U)
#define GTZC1_TZSC_SECCFGR1_I2C1SEC             (0x1U<<13U)
#define GTZC1_TZSC_SECCFGR1_UART5SEC            (0x1U<<12U)
#define GTZC1_TZSC_SECCFGR1_UART4SEC            (0x1U<<11U)
#define GTZC1_TZSC_SECCFGR1_USART3SEC           (0x1U<<10U)
#define GTZC1_TZSC_SECCFGR1_USART2SEC           (0x1U<<9U)
#define GTZC1_TZSC_SECCFGR1_SPI2SEC             (0x1U<<8U)
#define GTZC1_TZSC_SECCFGR1_IWDGSEC             (0x1U<<7U)
#define GTZC1_TZSC_SECCFGR1_WWDGSEC             (0x1U<<6U)
#define GTZC1_TZSC_SECCFGR1_TIM7SEC             (0x1U<<5U)
#define GTZC1_TZSC_SECCFGR1_TIM6SEC             (0x1U<<4U)
#define GTZC1_TZSC_SECCFGR1_TIM5SEC             (0x1U<<3U)
#define GTZC1_TZSC_SECCFGR1_TIM4SEC             (0x1U<<2U)
#define GTZC1_TZSC_SECCFGR1_TIM3SEC             (0x1U<<1U)
#define GTZC1_TZSC_SECCFGR1_TIM2SEC             (0x1U<<0U)

// SECCFGR2 Configuration

#define GTZC1_TZSC_SECCFGR2_DSISEC              (0x1U<<10U)
#define GTZC1_TZSC_SECCFGR2_LTDCSEC             (0x1U<<9U)
#define GTZC1_TZSC_SECCFGR2_SAI2SEC             (0x1U<<8U)
#define GTZC1_TZSC_SECCFGR2_SAI1SEC             (0x1U<<7U)
#define GTZC1_TZSC_SECCFGR2_TIM17SEC            (0x1U<<6U)
#define GTZC1_TZSC_SECCFGR2_TIM16SEC            (0x1U<<5U)
#define GTZC1_TZSC_SECCFGR2_TIM15SEC            (0x1U<<4U)
#define GTZC1_TZSC_SECCFGR2_USART1SEC           (0x1U<<3U)
#define GTZC1_TZSC_SECCFGR2_TIM8SEC             (0x1U<<2U)
#define GTZC1_TZSC_SECCFGR2_SPI1SEC             (0x1U<<1U)
#define GTZC1_TZSC_SECCFGR2_TIM1SEC             (0x1U<<0U)

// SECCFGR3 Configuration

#define GTZC1_TZSC_SECCFGR3_DCACHE2_REGSEC      (0x1U<<27U)
#define GTZC1_TZSC_SECCFGR3_HSPI1_REGSEC        (0x1U<<26U)
#define GTZC1_TZSC_SECCFGR3_GFXMMU_REGSEC       (0x1U<<25U)
#define GTZC1_TZSC_SECCFGR3_GFXMMUSEC           (0x1U<<24U)
#define GTZC1_TZSC_SECCFGR3_GPU2DSEC            (0x1U<<23U)
#define GTZC1_TZSC_SECCFGR3_RAMCFGSEC           (0x1U<<22U)
#define GTZC1_TZSC_SECCFGR3_OCTOSPI2_REGSEC     (0x1U<<21U)
#define GTZC1_TZSC_SECCFGR3_OCTOSPI1_REGSEC     (0x1U<<20U)
#define GTZC1_TZSC_SECCFGR3_FSMC_REGSEC         (0x1U<<19U)
#define GTZC1_TZSC_SECCFGR3_SDMMC2SEC           (0x1U<<18U)
#define GTZC1_TZSC_SECCFGR3_SDMMC1SEC           (0x1U<<17U)
#define GTZC1_TZSC_SECCFGR3_OCTOSPIMSEC         (0x1U<<16U)
#define GTZC1_TZSC_SECCFGR3_SAESSEC             (0x1U<<15U)
#define GTZC1_TZSC_SECCFGR3_PKASEC              (0x1U<<14U)
#define GTZC1_TZSC_SECCFGR3_RNGSEC              (0x1U<<13U)
#define GTZC1_TZSC_SECCFGR3_HASHSEC             (0x1U<<12U)
#define GTZC1_TZSC_SECCFGR3_AESSEC              (0x1U<<11U)
#define GTZC1_TZSC_SECCFGR3_OTGFSSEC            (0x1U<<10U)
#define GTZC1_TZSC_SECCFGR3_DCMISEC             (0x1U<<9U)
#define GTZC1_TZSC_SECCFGR3_ADC1SEC             (0x1U<<8U)
#define GTZC1_TZSC_SECCFGR3_DCACHE1_REGSEC      (0x1U<<7U)
#define GTZC1_TZSC_SECCFGR3_ICACHE_REGSEC       (0x1U<<6U)
#define GTZC1_TZSC_SECCFGR3_DMA2DSEC            (0x1U<<5U)
#define GTZC1_TZSC_SECCFGR3_TSCSEC              (0x1U<<4U)
#define GTZC1_TZSC_SECCFGR3_CRCSEC              (0x1U<<3U)
#define GTZC1_TZSC_SECCFGR3_FMACSEC             (0x1U<<2U)
#define GTZC1_TZSC_SECCFGR3_CORDICSEC           (0x1U<<1U)
#define GTZC1_TZSC_SECCFGR3_MDF1SEC             (0x1U<<0U)

// PRIVCFGR1 Configuration

#define GTZC1_TZSC_PRIVCFGR1_I2C6PRIV           (0x1U<<23U)
#define GTZC1_TZSC_PRIVCFGR1_I2C5PRIV           (0x1U<<22U)
#define GTZC1_TZSC_PRIVCFGR1_USART6PRIV         (0x1U<<21U)
#define GTZC1_TZSC_PRIVCFGR1_UCPD1PRIV          (0x1U<<19U)
#define GTZC1_TZSC_PRIVCFGR1_FDCAN1PRIV         (0x1U<<18U)
#define GTZC1_TZSC_PRIVCFGR1_LPTIM2PRIV         (0x1U<<17U)
#define GTZC1_TZSC_PRIVCFGR1_I2C4PRIV           (0x1U<<16U)
#define GTZC1_TZSC_PRIVCFGR1_CRSPRIV            (0x1U<<15U)
#define GTZC1_TZSC_PRIVCFGR1_I2C2PRIV           (0x1U<<14U)
#define GTZC1_TZSC_PRIVCFGR1_I2C1PRIV           (0x1U<<13U)
#define GTZC1_TZSC_PRIVCFGR1_UART5PRIV          (0x1U<<12U)
#define GTZC1_TZSC_PRIVCFGR1_UART4PRIV          (0x1U<<11U)
#define GTZC1_TZSC_PRIVCFGR1_USART3PRIV         (0x1U<<10U)
#define GTZC1_TZSC_PRIVCFGR1_USART2PRIV         (0x1U<<9U)
#define GTZC1_TZSC_PRIVCFGR1_SPI2PRIV           (0x1U<<8U)
#define GTZC1_TZSC_PRIVCFGR1_IWDGPRIV           (0x1U<<7U)
#define GTZC1_TZSC_PRIVCFGR1_WWDGPRIV           (0x1U<<6U)
#define GTZC1_TZSC_PRIVCFGR1_TIM7PRIV           (0x1U<<5U)
#define GTZC1_TZSC_PRIVCFGR1_TIM6PRIV           (0x1U<<4U)
#define GTZC1_TZSC_PRIVCFGR1_TIM5PRIV           (0x1U<<3U)
#define GTZC1_TZSC_PRIVCFGR1_TIM4PRIV           (0x1U<<2U)
#define GTZC1_TZSC_PRIVCFGR1_TIM3PRIV           (0x1U<<1U)
#define GTZC1_TZSC_PRIVCFGR1_TIM2PRIV           (0x1U<<0U)

// PRIVCFGR2 Configuration

#define GTZC1_TZSC_PRIVCFGR2_DSIPRIV            (0x1U<<10U)
#define GTZC1_TZSC_PRIVCFGR2_LTDCPRIV           (0x1U<<9U)
#define GTZC1_TZSC_PRIVCFGR2_SAI2PRIV           (0x1U<<8U)
#define GTZC1_TZSC_PRIVCFGR2_SAI1PRIV           (0x1U<<7U)
#define GTZC1_TZSC_PRIVCFGR2_TIM17PRIV          (0x1U<<6U)
#define GTZC1_TZSC_PRIVCFGR2_TIM16PRIV          (0x1U<<5U)
#define GTZC1_TZSC_PRIVCFGR2_TIM15PRIV          (0x1U<<4U)
#define GTZC1_TZSC_PRIVCFGR2_USART1PRIV         (0x1U<<3U)
#define GTZC1_TZSC_PRIVCFGR2_TIM8PRIV           (0x1U<<2U)
#define GTZC1_TZSC_PRIVCFGR2_SPI1PRIV           (0x1U<<1U)
#define GTZC1_TZSC_PRIVCFGR2_TIM1PRIV           (0x1U<<0U)

// PRIVCFGR3 Configuration

#define GTZC1_TZSC_PRIVCFGR3_DCACHE2_REGPRIV    (0x1U<<27U)
#define GTZC1_TZSC_PRIVCFGR3_HSPI1_REGPRIV      (0x1U<<26U)
#define GTZC1_TZSC_PRIVCFGR3_GFXMMU_REGPRIV     (0x1U<<25U)
#define GTZC1_TZSC_PRIVCFGR3_GFXMMUPRIV         (0x1U<<24U)
#define GTZC1_TZSC_PRIVCFGR3_GPU2DPRIV          (0x1U<<23U)
#define GTZC1_TZSC_PRIVCFGR3_RAMCFGPRIV         (0x1U<<22U)
#define GTZC1_TZSC_PRIVCFGR3_OCTOSPI2_REGPRIV   (0x1U<<21U)
#define GTZC1_TZSC_PRIVCFGR3_OCTOSPI1_REGPRIV   (0x1U<<20U)
#define GTZC1_TZSC_PRIVCFGR3_FSMC_REGPRIV       (0x1U<<19U)
#define GTZC1_TZSC_PRIVCFGR3_SDMMC2PRIV         (0x1U<<18U)
#define GTZC1_TZSC_PRIVCFGR3_SDMMC1PRIV         (0x1U<<17U)
#define GTZC1_TZSC_PRIVCFGR3_OCTOSPIMPRIV       (0x1U<<16U)
#define GTZC1_TZSC_PRIVCFGR3_SAESPRIV           (0x1U<<15U)
#define GTZC1_TZSC_PRIVCFGR3_PKAPRIV            (0x1U<<14U)
#define GTZC1_TZSC_PRIVCFGR3_RNGPRIV            (0x1U<<13U)
#define GTZC1_TZSC_PRIVCFGR3_HASHPRIV           (0x1U<<12U)
#define GTZC1_TZSC_PRIVCFGR3_AESPRIV            (0x1U<<11U)
#define GTZC1_TZSC_PRIVCFGR3_OTGFSPRIV          (0x1U<<10U)
#define GTZC1_TZSC_PRIVCFGR3_DCMIPRIV           (0x1U<<9U)
#define GTZC1_TZSC_PRIVCFGR3_ADC1PRIV           (0x1U<<8U)
#define GTZC1_TZSC_PRIVCFGR3_DCACHE1_REGPRIV    (0x1U<<7U)
#define GTZC1_TZSC_PRIVCFGR3_ICACHE_REGPRIV     (0x1U<<6U)
#define GTZC1_TZSC_PRIVCFGR3_DMA2DPRIV          (0x1U<<5U)
#define GTZC1_TZSC_PRIVCFGR3_TSCPRIV            (0x1U<<4U)
#define GTZC1_TZSC_PRIVCFGR3_CRCPRIV            (0x1U<<3U)
#define GTZC1_TZSC_PRIVCFGR3_FMACPRIV           (0x1U<<2U)
#define GTZC1_TZSC_PRIVCFGR3_CORDICPRIV         (0x1U<<1U)
#define GTZC1_TZSC_PRIVCFGR3_MDF1PRIV           (0x1U<<0U)

// MPCWM1ACFGR Configuration

#define GTZC1_TZSC_MPCWM1ACFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM1ACFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM1ACFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM1ACFGR_SREN             (0x1U<<0U)

// MPCWM1AR Configuration

#define GTZC1_TZSC_MPCWM1AR_SUBA_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM1AR_SUBA_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM1AR_SUBA_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM1AR_SUBA_START_0        (0x1U<<0U)

// MPCWM1BCFGR Configuration

#define GTZC1_TZSC_MPCWM1BCFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM1BCFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM1BCFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM1BCFGR_SREN             (0x1U<<0U)

// MPCWM1BR Configuration

#define GTZC1_TZSC_MPCWM1BR_SUBB_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM1BR_SUBB_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM1BR_SUBB_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM1BR_SUBB_START_0        (0x1U<<0U)

// MPCWM2ACFGR Configuration

#define GTZC1_TZSC_MPCWM2ACFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM2ACFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM2ACFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM2ACFGR_SREN             (0x1U<<0U)

// MPCWM2AR Configuration

#define GTZC1_TZSC_MPCWM2AR_SUBA_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM2AR_SUBA_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM2AR_SUBA_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM2AR_SUBA_START_0        (0x1U<<0U)

// MPCWM2BCFGR Configuration

#define GTZC1_TZSC_MPCWM2BCFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM2BCFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM2BCFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM2BCFGR_SREN             (0x1U<<0U)

// MPCWM2BR Configuration

#define GTZC1_TZSC_MPCWM2BR_SUBB_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM2BR_SUBB_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM2BR_SUBB_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM2BR_SUBB_START_0        (0x1U<<0U)

// MPCWM3ACFGR Configuration

#define GTZC1_TZSC_MPCWM3ACFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM3ACFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM3ACFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM3ACFGR_SREN             (0x1U<<0U)

// MPCWM3AR Configuration

#define GTZC1_TZSC_MPCWM3AR_SUBA_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM3AR_SUBA_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM3AR_SUBA_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM3AR_SUBA_START_0        (0x1U<<0U)

// MPCWM4ACFGR Configuration

#define GTZC1_TZSC_MPCWM4ACFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM4ACFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM4ACFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM4ACFGR_SREN             (0x1U<<0U)

// MPCWM4AR Configuration

#define GTZC1_TZSC_MPCWM4AR_SUBA_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM4AR_SUBA_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM4AR_SUBA_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM4AR_SUBA_START_0        (0x1U<<0U)

// MPCWM5ACFGR Configuration

#define GTZC1_TZSC_MPCWM5ACFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM5ACFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM5ACFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM5ACFGR_SREN             (0x1U<<0U)

// MPCWM5AR Configuration

#define GTZC1_TZSC_MPCWM5AR_SUBA_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM5AR_SUBA_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM5AR_SUBA_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM5AR_SUBA_START_0        (0x1U<<0U)

// MPCWM5BCFGR Configuration

#define GTZC1_TZSC_MPCWM5BCFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM5BCFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM5BCFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM5BCFGR_SREN             (0x1U<<0U)

// MPCWM5BR Configuration

#define GTZC1_TZSC_MPCWM5BR_SUBB_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM5BR_SUBB_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM5BR_SUBB_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM5BR_SUBB_START_0        (0x1U<<0U)

// MPCWM6ACFGR Configuration

#define GTZC1_TZSC_MPCWM6ACFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM6ACFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM6ACFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM6ACFGR_SREN             (0x1U<<0U)

// MPCWM6AR Configuration

#define GTZC1_TZSC_MPCWM6AR_SUBA_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM6AR_SUBA_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM6AR_SUBA_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM6AR_SUBA_START_0        (0x1U<<0U)

// MPCWM6BCFGR Configuration

#define GTZC1_TZSC_MPCWM6BCFGR_PRIV             (0x1U<<9U)
#define GTZC1_TZSC_MPCWM6BCFGR_SEC              (0x1U<<8U)
#define GTZC1_TZSC_MPCWM6BCFGR_SRLOCK           (0x1U<<1U)
#define GTZC1_TZSC_MPCWM6BCFGR_SREN             (0x1U<<0U)

// MPCWM6BR Configuration

#define GTZC1_TZSC_MPCWM6BR_SUBB_LENGTH         (0xFFFU<<16U)
#define GTZC1_TZSC_MPCWM6BR_SUBB_LENGTH_0       (0x1U<<16U)
#define GTZC1_TZSC_MPCWM6BR_SUBB_START          (0x7FFU<<0U)
#define GTZC1_TZSC_MPCWM6BR_SUBB_START_0        (0x1U<<0U)
