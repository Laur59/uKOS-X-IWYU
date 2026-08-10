/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_syscfg equates.
 */

#pragma once

#include    <stdint.h>

// SYSCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    MEMRM;
    volatile    uint32_t    PMC;
    volatile    uint32_t    EXTICR1;
    volatile    uint32_t    EXTICR2;
    volatile    uint32_t    EXTICR3;
    volatile    uint32_t    EXTICR4;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    CMPCR;
} SYSCFG_TypeDef;

#ifdef __cplusplus
#define SYSCFG  reinterpret_cast<SYSCFG_TypeDef *>(0x40013800U)

#else
#define SYSCFG  ((SYSCFG_TypeDef *)0x40013800U)
#endif

// MEMRM Configuration

#define SYSCFG_MEMRM_MEM_MODE   (0x3U<<0U)
#define SYSCFG_MEMRM_MEM_MODE_0 (0x1U<<0U)

// PMC Configuration

#define SYSCFG_PMC_MII_RMII_SEL (0x1U<<23U)

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

// CMPCR Configuration

#define SYSCFG_CMPCR_CMP_PD     (0x1U<<0U)
#define SYSCFG_CMPCR_READY      (0x1U<<7U)
