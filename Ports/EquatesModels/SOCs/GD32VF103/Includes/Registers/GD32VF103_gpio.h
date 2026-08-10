/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_gpio equates.
 */

#pragma once

#include    <stdint.h>

// GPIO address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CTL0;
    volatile    uint32_t    CTL1;
    volatile    uint32_t    ISTAT;
    volatile    uint32_t    OCTL;
    volatile    uint32_t    BOP;
    volatile    uint32_t    BC;
    volatile    uint32_t    LOCK;
} GPIO_TypeDef;

#ifdef __cplusplus
#define GPIOA   reinterpret_cast<GPIO_TypeDef *>(0x40010800U)
#define GPIOB   reinterpret_cast<GPIO_TypeDef *>(0x40010C00U)
#define GPIOC   reinterpret_cast<GPIO_TypeDef *>(0x40011000U)
#define GPIOD   reinterpret_cast<GPIO_TypeDef *>(0x40011400U)
#define GPIOE   reinterpret_cast<GPIO_TypeDef *>(0x40011800U)

#else
#define GPIOA   ((GPIO_TypeDef *)0x40010800U)
#define GPIOB   ((GPIO_TypeDef *)0x40010C00U)
#define GPIOC   ((GPIO_TypeDef *)0x40011000U)
#define GPIOD   ((GPIO_TypeDef *)0x40011400U)
#define GPIOE   ((GPIO_TypeDef *)0x40011800U)
#endif

// CTL0 Configuration

#define GPIO_CTL0_MD0       (0x3U<<0U)
#define GPIO_CTL0_MD0_0     (0x1U<<0U)
#define GPIO_CTL0_CTL0      (0x3U<<2U)
#define GPIO_CTL0_CTL0_0    (0x1U<<2U)
#define GPIO_CTL0_MD1       (0x3U<<4U)
#define GPIO_CTL0_MD1_0     (0x1U<<4U)
#define GPIO_CTL0_CTL1      (0x3U<<6U)
#define GPIO_CTL0_CTL1_0    (0x1U<<6U)
#define GPIO_CTL0_MD2       (0x3U<<8U)
#define GPIO_CTL0_MD2_0     (0x1U<<8U)
#define GPIO_CTL0_CTL2      (0x3U<<10U)
#define GPIO_CTL0_CTL2_0    (0x1U<<10U)
#define GPIO_CTL0_MD3       (0x3U<<12U)
#define GPIO_CTL0_MD3_0     (0x1U<<12U)
#define GPIO_CTL0_CTL3      (0x3U<<14U)
#define GPIO_CTL0_CTL3_0    (0x1U<<14U)
#define GPIO_CTL0_MD4       (0x3U<<16U)
#define GPIO_CTL0_MD4_0     (0x1U<<16U)
#define GPIO_CTL0_CTL4      (0x3U<<18U)
#define GPIO_CTL0_CTL4_0    (0x1U<<18U)
#define GPIO_CTL0_MD5       (0x3U<<20U)
#define GPIO_CTL0_MD5_0     (0x1U<<20U)
#define GPIO_CTL0_CTL5      (0x3U<<22U)
#define GPIO_CTL0_CTL5_0    (0x1U<<22U)
#define GPIO_CTL0_MD6       (0x3U<<24U)
#define GPIO_CTL0_MD6_0     (0x1U<<24U)
#define GPIO_CTL0_CTL6      (0x3U<<26U)
#define GPIO_CTL0_CTL6_0    (0x1U<<26U)
#define GPIO_CTL0_MD7       (0x3U<<28U)
#define GPIO_CTL0_MD7_0     (0x1U<<28U)
#define GPIO_CTL0_CTL7      (0x3U<<30U)
#define GPIO_CTL0_CTL7_0    (0x1U<<30U)

// CTL1 Configuration

#define GPIO_CTL1_MD8       (0x3U<<0U)
#define GPIO_CTL1_MD8_0     (0x1U<<0U)
#define GPIO_CTL1_CTL8      (0x3U<<2U)
#define GPIO_CTL1_CTL8_0    (0x1U<<2U)
#define GPIO_CTL1_MD9       (0x3U<<4U)
#define GPIO_CTL1_MD9_0     (0x1U<<4U)
#define GPIO_CTL1_CTL9      (0x3U<<6U)
#define GPIO_CTL1_CTL9_0    (0x1U<<6U)
#define GPIO_CTL1_MD10      (0x3U<<8U)
#define GPIO_CTL1_MD10_0    (0x1U<<8U)
#define GPIO_CTL1_CTL10     (0x3U<<10U)
#define GPIO_CTL1_CTL10_0   (0x1U<<10U)
#define GPIO_CTL1_MD11      (0x3U<<12U)
#define GPIO_CTL1_MD11_0    (0x1U<<12U)
#define GPIO_CTL1_CTL11     (0x3U<<14U)
#define GPIO_CTL1_CTL11_0   (0x1U<<14U)
#define GPIO_CTL1_MD12      (0x3U<<16U)
#define GPIO_CTL1_MD12_0    (0x1U<<16U)
#define GPIO_CTL1_CTL12     (0x3U<<18U)
#define GPIO_CTL1_CTL12_0   (0x1U<<18U)
#define GPIO_CTL1_MD13      (0x3U<<20U)
#define GPIO_CTL1_MD13_0    (0x1U<<20U)
#define GPIO_CTL1_CTL13     (0x3U<<22U)
#define GPIO_CTL1_CTL13_0   (0x1U<<22U)
#define GPIO_CTL1_MD14      (0x3U<<24U)
#define GPIO_CTL1_MD14_0    (0x1U<<24U)
#define GPIO_CTL1_CTL14     (0x3U<<26U)
#define GPIO_CTL1_CTL14_0   (0x1U<<26U)
#define GPIO_CTL1_MD15      (0x3U<<28U)
#define GPIO_CTL1_MD15_0    (0x1U<<28U)
#define GPIO_CTL1_CTL15     (0x3U<<30U)
#define GPIO_CTL1_CTL15_0   (0x1U<<30U)

// ISTAT Configuration

#define GPIO_ISTAT_ISTAT0   (0x1U<<0U)
#define GPIO_ISTAT_ISTAT1   (0x1U<<1U)
#define GPIO_ISTAT_ISTAT2   (0x1U<<2U)
#define GPIO_ISTAT_ISTAT3   (0x1U<<3U)
#define GPIO_ISTAT_ISTAT4   (0x1U<<4U)
#define GPIO_ISTAT_ISTAT5   (0x1U<<5U)
#define GPIO_ISTAT_ISTAT6   (0x1U<<6U)
#define GPIO_ISTAT_ISTAT7   (0x1U<<7U)
#define GPIO_ISTAT_ISTAT8   (0x1U<<8U)
#define GPIO_ISTAT_ISTAT9   (0x1U<<9U)
#define GPIO_ISTAT_ISTAT10  (0x1U<<10U)
#define GPIO_ISTAT_ISTAT11  (0x1U<<11U)
#define GPIO_ISTAT_ISTAT12  (0x1U<<12U)
#define GPIO_ISTAT_ISTAT13  (0x1U<<13U)
#define GPIO_ISTAT_ISTAT14  (0x1U<<14U)
#define GPIO_ISTAT_ISTAT15  (0x1U<<15U)

// OCTL Configuration

#define GPIO_OCTL_OCTL0     (0x1U<<0U)
#define GPIO_OCTL_OCTL1     (0x1U<<1U)
#define GPIO_OCTL_OCTL2     (0x1U<<2U)
#define GPIO_OCTL_OCTL3     (0x1U<<3U)
#define GPIO_OCTL_OCTL4     (0x1U<<4U)
#define GPIO_OCTL_OCTL5     (0x1U<<5U)
#define GPIO_OCTL_OCTL6     (0x1U<<6U)
#define GPIO_OCTL_OCTL7     (0x1U<<7U)
#define GPIO_OCTL_OCTL8     (0x1U<<8U)
#define GPIO_OCTL_OCTL9     (0x1U<<9U)
#define GPIO_OCTL_OCTL10    (0x1U<<10U)
#define GPIO_OCTL_OCTL11    (0x1U<<11U)
#define GPIO_OCTL_OCTL12    (0x1U<<12U)
#define GPIO_OCTL_OCTL13    (0x1U<<13U)
#define GPIO_OCTL_OCTL14    (0x1U<<14U)
#define GPIO_OCTL_OCTL15    (0x1U<<15U)

// BOP Configuration

#define GPIO_BOP_BOP0       (0x1U<<0U)
#define GPIO_BOP_BOP1       (0x1U<<1U)
#define GPIO_BOP_BOP2       (0x1U<<2U)
#define GPIO_BOP_BOP3       (0x1U<<3U)
#define GPIO_BOP_BOP4       (0x1U<<4U)
#define GPIO_BOP_BOP5       (0x1U<<5U)
#define GPIO_BOP_BOP6       (0x1U<<6U)
#define GPIO_BOP_BOP7       (0x1U<<7U)
#define GPIO_BOP_BOP8       (0x1U<<8U)
#define GPIO_BOP_BOP9       (0x1U<<9U)
#define GPIO_BOP_BOP10      (0x1U<<10U)
#define GPIO_BOP_BOP11      (0x1U<<11U)
#define GPIO_BOP_BOP12      (0x1U<<12U)
#define GPIO_BOP_BOP13      (0x1U<<13U)
#define GPIO_BOP_BOP14      (0x1U<<14U)
#define GPIO_BOP_BOP15      (0x1U<<15U)
#define GPIO_BOP_CR0        (0x1U<<16U)
#define GPIO_BOP_CR1        (0x1U<<17U)
#define GPIO_BOP_CR2        (0x1U<<18U)
#define GPIO_BOP_CR3        (0x1U<<19U)
#define GPIO_BOP_CR4        (0x1U<<20U)
#define GPIO_BOP_CR5        (0x1U<<21U)
#define GPIO_BOP_CR6        (0x1U<<22U)
#define GPIO_BOP_CR7        (0x1U<<23U)
#define GPIO_BOP_CR8        (0x1U<<24U)
#define GPIO_BOP_CR9        (0x1U<<25U)
#define GPIO_BOP_CR10       (0x1U<<26U)
#define GPIO_BOP_CR11       (0x1U<<27U)
#define GPIO_BOP_CR12       (0x1U<<28U)
#define GPIO_BOP_CR13       (0x1U<<29U)
#define GPIO_BOP_CR14       (0x1U<<30U)
#define GPIO_BOP_CR15       (0x1U<<31U)

// BC Configuration

#define GPIO_BC_CR0         (0x1U<<0U)
#define GPIO_BC_CR1         (0x1U<<1U)
#define GPIO_BC_CR2         (0x1U<<2U)
#define GPIO_BC_CR3         (0x1U<<3U)
#define GPIO_BC_CR4         (0x1U<<4U)
#define GPIO_BC_CR5         (0x1U<<5U)
#define GPIO_BC_CR6         (0x1U<<6U)
#define GPIO_BC_CR7         (0x1U<<7U)
#define GPIO_BC_CR8         (0x1U<<8U)
#define GPIO_BC_CR9         (0x1U<<9U)
#define GPIO_BC_CR10        (0x1U<<10U)
#define GPIO_BC_CR11        (0x1U<<11U)
#define GPIO_BC_CR12        (0x1U<<12U)
#define GPIO_BC_CR13        (0x1U<<13U)
#define GPIO_BC_CR14        (0x1U<<14U)
#define GPIO_BC_CR15        (0x1U<<15U)

// LOCK Configuration

#define GPIO_LOCK_LK0       (0x1U<<0U)
#define GPIO_LOCK_LK1       (0x1U<<1U)
#define GPIO_LOCK_LK2       (0x1U<<2U)
#define GPIO_LOCK_LK3       (0x1U<<3U)
#define GPIO_LOCK_LK4       (0x1U<<4U)
#define GPIO_LOCK_LK5       (0x1U<<5U)
#define GPIO_LOCK_LK6       (0x1U<<6U)
#define GPIO_LOCK_LK7       (0x1U<<7U)
#define GPIO_LOCK_LK8       (0x1U<<8U)
#define GPIO_LOCK_LK9       (0x1U<<9U)
#define GPIO_LOCK_LK10      (0x1U<<10U)
#define GPIO_LOCK_LK11      (0x1U<<11U)
#define GPIO_LOCK_LK12      (0x1U<<12U)
#define GPIO_LOCK_LK13      (0x1U<<13U)
#define GPIO_LOCK_LK14      (0x1U<<14U)
#define GPIO_LOCK_LK15      (0x1U<<15U)
#define GPIO_LOCK_LKK       (0x1U<<16U)
