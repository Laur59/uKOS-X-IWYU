/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_syscfg equates.
 */

#pragma once

#include    <stdint.h>

// SYSCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    MEMRMP;
    volatile    uint32_t    CFGR1;
    volatile    uint32_t    EXTICR1;
    volatile    uint32_t    EXTICR2;
    volatile    uint32_t    EXTICR3;
    volatile    uint32_t    EXTICR4;
    volatile    uint32_t    SCSR;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    SWPR;
    volatile    uint32_t    SKR;
} SYSCFG_TypeDef;

#ifdef __cplusplus
#define SYSCFG  reinterpret_cast<SYSCFG_TypeDef *>(0x40010000U)

#else
#define SYSCFG  ((SYSCFG_TypeDef *)0x40010000U)
#endif

// MEMRMP Configuration

#define SYSCFG_MEMRMP_MEM_MODE      (0x7U<<0)
#define SYSCFG_MEMRMP_MEM_MODE_0    (0x1U<<0)
#define SYSCFG_MEMRMP_QFS           (0x1U<<3)
#define SYSCFG_MEMRMP_FB_MODE       (0x1U<<8)

// CFGR1 Configuration

#define SYSCFG_CFGR1_FWDIS          (0x1U<<0)
#define SYSCFG_CFGR1_BOOSTEN        (0x1U<<8)
#define SYSCFG_CFGR1_I2C_PB6_FMP    (0x1U<<16)
#define SYSCFG_CFGR1_I2C_PB7_FMP    (0x1U<<17)
#define SYSCFG_CFGR1_I2C_PB8_FMP    (0x1U<<18)
#define SYSCFG_CFGR1_I2C_PB9_FMP    (0x1U<<19)
#define SYSCFG_CFGR1_I2C1_FMP       (0x1U<<20)
#define SYSCFG_CFGR1_I2C2_FMP       (0x1U<<21)
#define SYSCFG_CFGR1_I2C3_FMP       (0x1U<<22)
#define SYSCFG_CFGR1_FPU_IE         (0x3FU<<26)
#define SYSCFG_CFGR1_FPU_IE_0       (0x1U<<26)

// EXTICR1 Configuration

#define SYSCFG_EXTICR1_EXTI0        (0x7U<<0)
#define SYSCFG_EXTICR1_EXTI0_0      (0x1U<<0)
#define SYSCFG_EXTICR1_EXTI1        (0x7U<<4)
#define SYSCFG_EXTICR1_EXTI1_0      (0x1U<<4)
#define SYSCFG_EXTICR1_EXTI2        (0x7U<<8)
#define SYSCFG_EXTICR1_EXTI2_0      (0x1U<<8)
#define SYSCFG_EXTICR1_EXTI3        (0x7U<<12)
#define SYSCFG_EXTICR1_EXTI3_0      (0x1U<<12)

// EXTICR2 Configuration

#define SYSCFG_EXTICR2_EXTI4        (0x7U<<0)
#define SYSCFG_EXTICR2_EXTI4_0      (0x1U<<0)
#define SYSCFG_EXTICR2_EXTI5        (0x7U<<4)
#define SYSCFG_EXTICR2_EXTI5_0      (0x1U<<4)
#define SYSCFG_EXTICR2_EXTI6        (0x7U<<8)
#define SYSCFG_EXTICR2_EXTI6_0      (0x1U<<8)
#define SYSCFG_EXTICR2_EXTI7        (0x7U<<12)
#define SYSCFG_EXTICR2_EXTI7_0      (0x1U<<12)

// EXTICR3 Configuration

#define SYSCFG_EXTICR3_EXTI8        (0x7U<<0)
#define SYSCFG_EXTICR3_EXTI8_0      (0x1U<<0)
#define SYSCFG_EXTICR3_EXTI9        (0x7U<<4)
#define SYSCFG_EXTICR3_EXTI9_0      (0x1U<<4)
#define SYSCFG_EXTICR3_EXTI10       (0x7U<<8)
#define SYSCFG_EXTICR3_EXTI10_0     (0x1U<<8)
#define SYSCFG_EXTICR3_EXTI11       (0x7U<<12)
#define SYSCFG_EXTICR3_EXTI11_0     (0x1U<<12)

// EXTICR4 Configuration

#define SYSCFG_EXTICR4_EXTI12       (0x7U<<0)
#define SYSCFG_EXTICR4_EXTI12_0     (0x1U<<0)
#define SYSCFG_EXTICR4_EXTI13       (0x7U<<4)
#define SYSCFG_EXTICR4_EXTI13_0     (0x1U<<4)
#define SYSCFG_EXTICR4_EXTI14       (0x7U<<8)
#define SYSCFG_EXTICR4_EXTI14_0     (0x1U<<8)
#define SYSCFG_EXTICR4_EXTI15       (0x7U<<12)
#define SYSCFG_EXTICR4_EXTI15_0     (0x1U<<12)

// SCSR Configuration

#define SYSCFG_SCSR_SRAM2ER         (0x1U<<0)
#define SYSCFG_SCSR_SRAM2BSY        (0x1U<<1)

// CFGR2 Configuration

#define SYSCFG_CFGR2_CLL            (0x1U<<0)
#define SYSCFG_CFGR2_SPL            (0x1U<<1)
#define SYSCFG_CFGR2_PVDL           (0x1U<<2)
#define SYSCFG_CFGR2_ECCL           (0x1U<<3)
#define SYSCFG_CFGR2_SPF            (0x1U<<8)

// SWPR Configuration

#define SYSCFG_SWPR_P0WP            (0x1U<<0)
#define SYSCFG_SWPR_P1WP            (0x1U<<1)
#define SYSCFG_SWPR_P2WP            (0x1U<<2)
#define SYSCFG_SWPR_P3WP            (0x1U<<3)
#define SYSCFG_SWPR_P4WP            (0x1U<<4)
#define SYSCFG_SWPR_P5WP            (0x1U<<5)
#define SYSCFG_SWPR_P6WP            (0x1U<<6)
#define SYSCFG_SWPR_P7WP            (0x1U<<7)
#define SYSCFG_SWPR_P8WP            (0x1U<<8)
#define SYSCFG_SWPR_P9WP            (0x1U<<9)
#define SYSCFG_SWPR_P10WP           (0x1U<<10)
#define SYSCFG_SWPR_P11WP           (0x1U<<11)
#define SYSCFG_SWPR_P12WP           (0x1U<<12)
#define SYSCFG_SWPR_P13WP           (0x1U<<13)
#define SYSCFG_SWPR_P14WP           (0x1U<<14)
#define SYSCFG_SWPR_P15WP           (0x1U<<15)
#define SYSCFG_SWPR_P16WP           (0x1U<<16)
#define SYSCFG_SWPR_P17WP           (0x1U<<17)
#define SYSCFG_SWPR_P18WP           (0x1U<<18)
#define SYSCFG_SWPR_P19WP           (0x1U<<19)
#define SYSCFG_SWPR_P20WP           (0x1U<<20)
#define SYSCFG_SWPR_P21WP           (0x1U<<21)
#define SYSCFG_SWPR_P22WP           (0x1U<<22)
#define SYSCFG_SWPR_P23WP           (0x1U<<23)
#define SYSCFG_SWPR_P24WP           (0x1U<<24)
#define SYSCFG_SWPR_P25WP           (0x1U<<25)
#define SYSCFG_SWPR_P26WP           (0x1U<<26)
#define SYSCFG_SWPR_P27WP           (0x1U<<27)
#define SYSCFG_SWPR_P28WP           (0x1U<<28)
#define SYSCFG_SWPR_P29WP           (0x1U<<29)
#define SYSCFG_SWPR_P30WP           (0x1U<<30)
#define SYSCFG_SWPR_P31WP           (0x1U<<31)

// SKR Configuration

#define SYSCFG_SKR_KEY              (0xFFU<<0)
#define SYSCFG_SKR_KEY_0            (0x1U<<0)
