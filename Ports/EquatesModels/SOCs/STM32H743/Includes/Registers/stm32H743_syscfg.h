/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_syscfg equates.
 */

#pragma once

#include    <stdint.h>

// SYSCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    PMCR;
    volatile    uint32_t    EXTICR1;
    volatile    uint32_t    EXTICR2;
    volatile    uint32_t    EXTICR3;
    volatile    uint32_t    EXTICR4;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    CCCSR;
    volatile    uint32_t    CCVR;
    volatile    uint32_t    CCCR;
    volatile    uint32_t    PWRCR;
    volatile    uint32_t    RESERVED2[61];
    volatile    uint32_t    PKGR;
    volatile    uint32_t    RESERVED3[118];
    volatile    uint32_t    UR0;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    UR2;
    volatile    uint32_t    UR3;
    volatile    uint32_t    UR4;
    volatile    uint32_t    UR5;
    volatile    uint32_t    UR6;
    volatile    uint32_t    UR7;
    volatile    uint32_t    UR8;
    volatile    uint32_t    UR9;
    volatile    uint32_t    UR10;
    volatile    uint32_t    UR11;
    volatile    uint32_t    UR12;
    volatile    uint32_t    UR13;
    volatile    uint32_t    UR14;
    volatile    uint32_t    UR15;
    volatile    uint32_t    UR16;
    volatile    uint32_t    UR17;
} SYSCFG_TypeDef;

#ifdef __cplusplus
#define SYSCFG  reinterpret_cast<SYSCFG_TypeDef *>(0x58000400U)

#else
#define SYSCFG  ((SYSCFG_TypeDef *)0x58000400U)
#endif

// PMCR Configuration

#define SYSCFG_PMCR_PC3SO       (0x1U<<27U)
#define SYSCFG_PMCR_PC2SO       (0x1U<<26U)
#define SYSCFG_PMCR_PA1SO       (0x1U<<25U)
#define SYSCFG_PMCR_PA0SO       (0x1U<<24U)
#define SYSCFG_PMCR_EPIS        (0x7U<<21U)
#define SYSCFG_PMCR_EPIS_0      (0x1U<<21U)
#define SYSCFG_PMCR_BOOSTVDDSEL (0x1U<<9U)
#define SYSCFG_PMCR_BOOSTE      (0x1U<<8U)
#define SYSCFG_PMCR_PB9FMP      (0x1U<<7U)
#define SYSCFG_PMCR_PB8FMP      (0x1U<<6U)
#define SYSCFG_PMCR_PB7FMP      (0x1U<<5U)
#define SYSCFG_PMCR_PB6FMP      (0x1U<<4U)
#define SYSCFG_PMCR_I2C4FMP     (0x1U<<3U)
#define SYSCFG_PMCR_I2C3FMP     (0x1U<<2U)
#define SYSCFG_PMCR_I2C2FMP     (0x1U<<1U)
#define SYSCFG_PMCR_I2C1FMP     (0x1U<<0U)

// EXTICR1 Configuration

#define SYSCFG_EXTICR1_EXTI0    (0xFU<<0U)
#define SYSCFG_EXTICR1_EXTI0_0  (0x1U<<0U)
#define SYSCFG_EXTICR1_EXTI1    (0xFU<<4U)
#define SYSCFG_EXTICR1_EXTI1_0  (0x1U<<4U)
#define SYSCFG_EXTICR1_EXTI2    (0xFU<<8U)
#define SYSCFG_EXTICR1_EXTI2_0  (0x1U<<8U)
#define SYSCFG_EXTICR1_EXTI3    (0xFU<<12U)
#define SYSCFG_EXTICR1_EXTI3_0  (0x1U<<12U)

// EXTICR2 Configuration

#define SYSCFG_EXTICR2_EXTI4    (0xFU<<0U)
#define SYSCFG_EXTICR2_EXTI4_0  (0x1U<<0U)
#define SYSCFG_EXTICR2_EXTI5    (0xFU<<4U)
#define SYSCFG_EXTICR2_EXTI5_0  (0x1U<<4U)
#define SYSCFG_EXTICR2_EXTI6    (0xFU<<8U)
#define SYSCFG_EXTICR2_EXTI6_0  (0x1U<<8U)
#define SYSCFG_EXTICR2_EXTI7    (0xFU<<12U)
#define SYSCFG_EXTICR2_EXTI7_0  (0x1U<<12U)

// EXTICR3 Configuration

#define SYSCFG_EXTICR3_EXTI8    (0xFU<<0U)
#define SYSCFG_EXTICR3_EXTI8_0  (0x1U<<0U)
#define SYSCFG_EXTICR3_EXTI9    (0xFU<<4U)
#define SYSCFG_EXTICR3_EXTI9_0  (0x1U<<4U)
#define SYSCFG_EXTICR3_EXTI10   (0xFU<<8U)
#define SYSCFG_EXTICR3_EXTI10_0 (0x1U<<8U)
#define SYSCFG_EXTICR3_EXTI11   (0xFU<<12U)
#define SYSCFG_EXTICR3_EXTI11_0 (0x1U<<12U)

// EXTICR4 Configuration

#define SYSCFG_EXTICR4_EXTI12   (0xFU<<0U)
#define SYSCFG_EXTICR4_EXTI12_0 (0x1U<<0U)
#define SYSCFG_EXTICR4_EXTI13   (0xFU<<4U)
#define SYSCFG_EXTICR4_EXTI13_0 (0x1U<<4U)
#define SYSCFG_EXTICR4_EXTI14   (0xFU<<8U)
#define SYSCFG_EXTICR4_EXTI14_0 (0x1U<<8U)
#define SYSCFG_EXTICR4_EXTI15   (0xFU<<12U)
#define SYSCFG_EXTICR4_EXTI15_0 (0x1U<<12U)

// CCCSR Configuration

#define SYSCFG_CCCSR_HSLV       (0x1U<<16U)
#define SYSCFG_CCCSR_READY      (0x1U<<8U)
#define SYSCFG_CCCSR_CS         (0x1U<<1U)
#define SYSCFG_CCCSR_EN         (0x1U<<0U)

// CCVR Configuration

#define SYSCFG_CCVR_PCV         (0xFU<<4U)
#define SYSCFG_CCVR_PCV_0       (0x1U<<4U)
#define SYSCFG_CCVR_NCV         (0xFU<<0U)
#define SYSCFG_CCVR_NCV_0       (0x1U<<0U)

// CCCR Configuration

#define SYSCFG_CCCR_PCC         (0xFU<<4U)
#define SYSCFG_CCCR_PCC_0       (0x1U<<4U)
#define SYSCFG_CCCR_NCC         (0xFU<<0U)
#define SYSCFG_CCCR_NCC_0       (0x1U<<0U)

// PWRCR Configuration

#define SYSCFG_PWRCR_ODEN       (0xFU<<0U)
#define SYSCFG_PWRCR_ODEN_0     (0x1U<<0U)

// PKGR Configuration

#define SYSCFG_PKGR_PKG         (0xFU<<0U)
#define SYSCFG_PKGR_PKG_0       (0x1U<<0U)

// UR0 Configuration

#define SYSCFG_UR0_RDP          (0xFFU<<16U)
#define SYSCFG_UR0_RDP_0        (0x1U<<16U)
#define SYSCFG_UR0_BKS          (0x1U<<0U)

// UR2 Configuration

#define SYSCFG_UR2_BOOT_ADD0    (0xFFFFU<<16U)
#define SYSCFG_UR2_BOOT_ADD0_0  (0x1U<<16U)
#define SYSCFG_UR2_BORH         (0x3U<<0U)
#define SYSCFG_UR2_BORH_0       (0x1U<<0U)

// UR3 Configuration

#define SYSCFG_UR3_BOOT_ADD1    (0xFFFFU<<16U)
#define SYSCFG_UR3_BOOT_ADD1_0  (0x1U<<16U)

// UR4 Configuration

#define SYSCFG_UR4_MEPAD_1      (0x1U<<16U)

// UR5 Configuration

#define SYSCFG_UR5_WRPN_1       (0xFFU<<16U)
#define SYSCFG_UR5_WRPN_1_0     (0x1U<<16U)
#define SYSCFG_UR5_MESAD_1      (0x1U<<0U)

// UR6 Configuration

#define SYSCFG_UR6_PA_END_1     (0xFFFU<<16U)
#define SYSCFG_UR6_PA_END_1_0   (0x1U<<16U)
#define SYSCFG_UR6_PA_BEG_1     (0xFFFU<<0U)
#define SYSCFG_UR6_PA_BEG_1_0   (0x1U<<0U)

// UR7 Configuration

#define SYSCFG_UR7_SA_END_1     (0xFFFU<<16U)
#define SYSCFG_UR7_SA_END_1_0   (0x1U<<16U)
#define SYSCFG_UR7_SA_BEG_1     (0xFFFU<<0U)
#define SYSCFG_UR7_SA_BEG_1_0   (0x1U<<0U)

// UR8 Configuration

#define SYSCFG_UR8_MESAD_2      (0x1U<<16U)
#define SYSCFG_UR8_MEPAD_2      (0x1U<<0U)

// UR9 Configuration

#define SYSCFG_UR9_PA_BEG_2     (0xFFFU<<16U)
#define SYSCFG_UR9_PA_BEG_2_0   (0x1U<<16U)
#define SYSCFG_UR9_WRPN_2       (0xFFU<<0U)
#define SYSCFG_UR9_WRPN_2_0     (0x1U<<0U)

// UR10 Configuration

#define SYSCFG_UR10_SA_BEG_2    (0xFFFU<<16U)
#define SYSCFG_UR10_SA_BEG_2_0  (0x1U<<16U)
#define SYSCFG_UR10_PA_END_2    (0xFFFU<<0U)
#define SYSCFG_UR10_PA_END_2_0  (0x1U<<0U)

// UR11 Configuration

#define SYSCFG_UR11_IWDG1M      (0x1U<<16U)
#define SYSCFG_UR11_SA_END_2    (0xFFFU<<0U)
#define SYSCFG_UR11_SA_END_2_0  (0x1U<<0U)

// UR12 Configuration

#define SYSCFG_UR12_SECURE      (0x1U<<16U)

// UR13 Configuration

#define SYSCFG_UR13_D1SBRST     (0x1U<<16U)
#define SYSCFG_UR13_SDRS        (0x3U<<0U)
#define SYSCFG_UR13_SDRS_0      (0x1U<<0U)

// UR14 Configuration

#define SYSCFG_UR14_D1STPRST    (0x1U<<0U)

// UR15 Configuration

#define SYSCFG_UR15_FZIWDGSTB   (0x1U<<16U)

// UR16 Configuration

#define SYSCFG_UR16_PKP         (0x1U<<16U)
#define SYSCFG_UR16_FZIWDGSTP   (0x1U<<0U)

// UR17 Configuration

#define SYSCFG_UR17_IO_HSLV     (0x1U<<0U)
