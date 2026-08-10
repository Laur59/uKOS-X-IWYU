/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_gpioc equates.
 */

#pragma once

#include    <stdint.h>

// GPIOC address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    MODER;
    volatile    uint32_t    OTYPER;
    volatile    uint32_t    OSPEEDR;
    volatile    uint32_t    PUPDR;
    volatile    uint32_t    IDR;
    volatile    uint32_t    ODR;
    volatile    uint32_t    BSRR;
    volatile    uint32_t    LCKR;
    volatile    uint32_t    AFRL;
    volatile    uint32_t    AFRH;
    volatile    uint32_t    BRR;
    volatile    uint32_t    ASCR;
} GPIOC_TypeDef;

#ifdef __cplusplus
#define GPIOC   reinterpret_cast<GPIOC_TypeDef *>(0x48000800U)

#else
#define GPIOC   ((GPIOC_TypeDef *)0x48000800U)
#endif

// MODER Configuration

#define GPIOC_MODER_MODER0          (0x3U<<0U)
#define GPIOC_MODER_MODER0_0        (0x1U<<0U)
#define GPIOC_MODER_MODER1          (0x3U<<2U)
#define GPIOC_MODER_MODER1_0        (0x1U<<2U)
#define GPIOC_MODER_MODER2          (0x3U<<4U)
#define GPIOC_MODER_MODER2_0        (0x1U<<4U)
#define GPIOC_MODER_MODER3          (0x3U<<6U)
#define GPIOC_MODER_MODER3_0        (0x1U<<6U)
#define GPIOC_MODER_MODER4          (0x3U<<8U)
#define GPIOC_MODER_MODER4_0        (0x1U<<8U)
#define GPIOC_MODER_MODER5          (0x3U<<10U)
#define GPIOC_MODER_MODER5_0        (0x1U<<10U)
#define GPIOC_MODER_MODER6          (0x3U<<12U)
#define GPIOC_MODER_MODER6_0        (0x1U<<12U)
#define GPIOC_MODER_MODER7          (0x3U<<14U)
#define GPIOC_MODER_MODER7_0        (0x1U<<14U)
#define GPIOC_MODER_MODER8          (0x3U<<16U)
#define GPIOC_MODER_MODER8_0        (0x1U<<16U)
#define GPIOC_MODER_MODER9          (0x3U<<18U)
#define GPIOC_MODER_MODER9_0        (0x1U<<18U)
#define GPIOC_MODER_MODER10         (0x3U<<20U)
#define GPIOC_MODER_MODER10_0       (0x1U<<20U)
#define GPIOC_MODER_MODER11         (0x3U<<22U)
#define GPIOC_MODER_MODER11_0       (0x1U<<22U)
#define GPIOC_MODER_MODER12         (0x3U<<24U)
#define GPIOC_MODER_MODER12_0       (0x1U<<24U)
#define GPIOC_MODER_MODER13         (0x3U<<26U)
#define GPIOC_MODER_MODER13_0       (0x1U<<26U)
#define GPIOC_MODER_MODER14         (0x3U<<28U)
#define GPIOC_MODER_MODER14_0       (0x1U<<28U)
#define GPIOC_MODER_MODER15         (0x3U<<30U)
#define GPIOC_MODER_MODER15_0       (0x1U<<30U)

// OTYPER Configuration

#define GPIOC_OTYPER_OT0            (0x1U<<0U)
#define GPIOC_OTYPER_OT1            (0x1U<<1U)
#define GPIOC_OTYPER_OT2            (0x1U<<2U)
#define GPIOC_OTYPER_OT3            (0x1U<<3U)
#define GPIOC_OTYPER_OT4            (0x1U<<4U)
#define GPIOC_OTYPER_OT5            (0x1U<<5U)
#define GPIOC_OTYPER_OT6            (0x1U<<6U)
#define GPIOC_OTYPER_OT7            (0x1U<<7U)
#define GPIOC_OTYPER_OT8            (0x1U<<8U)
#define GPIOC_OTYPER_OT9            (0x1U<<9U)
#define GPIOC_OTYPER_OT10           (0x1U<<10U)
#define GPIOC_OTYPER_OT11           (0x1U<<11U)
#define GPIOC_OTYPER_OT12           (0x1U<<12U)
#define GPIOC_OTYPER_OT13           (0x1U<<13U)
#define GPIOC_OTYPER_OT14           (0x1U<<14U)
#define GPIOC_OTYPER_OT15           (0x1U<<15U)

// OSPEEDR Configuration

#define GPIOC_OSPEEDR_OSPEEDR0      (0x3U<<0U)
#define GPIOC_OSPEEDR_OSPEEDR0_0    (0x1U<<0U)
#define GPIOC_OSPEEDR_OSPEEDR1      (0x3U<<2U)
#define GPIOC_OSPEEDR_OSPEEDR1_0    (0x1U<<2U)
#define GPIOC_OSPEEDR_OSPEEDR2      (0x3U<<4U)
#define GPIOC_OSPEEDR_OSPEEDR2_0    (0x1U<<4U)
#define GPIOC_OSPEEDR_OSPEEDR3      (0x3U<<6U)
#define GPIOC_OSPEEDR_OSPEEDR3_0    (0x1U<<6U)
#define GPIOC_OSPEEDR_OSPEEDR4      (0x3U<<8U)
#define GPIOC_OSPEEDR_OSPEEDR4_0    (0x1U<<8U)
#define GPIOC_OSPEEDR_OSPEEDR5      (0x3U<<10U)
#define GPIOC_OSPEEDR_OSPEEDR5_0    (0x1U<<10U)
#define GPIOC_OSPEEDR_OSPEEDR6      (0x3U<<12U)
#define GPIOC_OSPEEDR_OSPEEDR6_0    (0x1U<<12U)
#define GPIOC_OSPEEDR_OSPEEDR7      (0x3U<<14U)
#define GPIOC_OSPEEDR_OSPEEDR7_0    (0x1U<<14U)
#define GPIOC_OSPEEDR_OSPEEDR8      (0x3U<<16U)
#define GPIOC_OSPEEDR_OSPEEDR8_0    (0x1U<<16U)
#define GPIOC_OSPEEDR_OSPEEDR9      (0x3U<<18U)
#define GPIOC_OSPEEDR_OSPEEDR9_0    (0x1U<<18U)
#define GPIOC_OSPEEDR_OSPEEDR10     (0x3U<<20U)
#define GPIOC_OSPEEDR_OSPEEDR10_0   (0x1U<<20U)
#define GPIOC_OSPEEDR_OSPEEDR11     (0x3U<<22U)
#define GPIOC_OSPEEDR_OSPEEDR11_0   (0x1U<<22U)
#define GPIOC_OSPEEDR_OSPEEDR12     (0x3U<<24U)
#define GPIOC_OSPEEDR_OSPEEDR12_0   (0x1U<<24U)
#define GPIOC_OSPEEDR_OSPEEDR13     (0x3U<<26U)
#define GPIOC_OSPEEDR_OSPEEDR13_0   (0x1U<<26U)
#define GPIOC_OSPEEDR_OSPEEDR14     (0x3U<<28U)
#define GPIOC_OSPEEDR_OSPEEDR14_0   (0x1U<<28U)
#define GPIOC_OSPEEDR_OSPEEDR15     (0x3U<<30U)
#define GPIOC_OSPEEDR_OSPEEDR15_0   (0x1U<<30U)

// PUPDR Configuration

#define GPIOC_PUPDR_PUPDR0          (0x3U<<0U)
#define GPIOC_PUPDR_PUPDR0_0        (0x1U<<0U)
#define GPIOC_PUPDR_PUPDR1          (0x3U<<2U)
#define GPIOC_PUPDR_PUPDR1_0        (0x1U<<2U)
#define GPIOC_PUPDR_PUPDR2          (0x3U<<4U)
#define GPIOC_PUPDR_PUPDR2_0        (0x1U<<4U)
#define GPIOC_PUPDR_PUPDR3          (0x3U<<6U)
#define GPIOC_PUPDR_PUPDR3_0        (0x1U<<6U)
#define GPIOC_PUPDR_PUPDR4          (0x3U<<8U)
#define GPIOC_PUPDR_PUPDR4_0        (0x1U<<8U)
#define GPIOC_PUPDR_PUPDR5          (0x3U<<10U)
#define GPIOC_PUPDR_PUPDR5_0        (0x1U<<10U)
#define GPIOC_PUPDR_PUPDR6          (0x3U<<12U)
#define GPIOC_PUPDR_PUPDR6_0        (0x1U<<12U)
#define GPIOC_PUPDR_PUPDR7          (0x3U<<14U)
#define GPIOC_PUPDR_PUPDR7_0        (0x1U<<14U)
#define GPIOC_PUPDR_PUPDR8          (0x3U<<16U)
#define GPIOC_PUPDR_PUPDR8_0        (0x1U<<16U)
#define GPIOC_PUPDR_PUPDR9          (0x3U<<18U)
#define GPIOC_PUPDR_PUPDR9_0        (0x1U<<18U)
#define GPIOC_PUPDR_PUPDR10         (0x3U<<20U)
#define GPIOC_PUPDR_PUPDR10_0       (0x1U<<20U)
#define GPIOC_PUPDR_PUPDR11         (0x3U<<22U)
#define GPIOC_PUPDR_PUPDR11_0       (0x1U<<22U)
#define GPIOC_PUPDR_PUPDR12         (0x3U<<24U)
#define GPIOC_PUPDR_PUPDR12_0       (0x1U<<24U)
#define GPIOC_PUPDR_PUPDR13         (0x3U<<26U)
#define GPIOC_PUPDR_PUPDR13_0       (0x1U<<26U)
#define GPIOC_PUPDR_PUPDR14         (0x3U<<28U)
#define GPIOC_PUPDR_PUPDR14_0       (0x1U<<28U)
#define GPIOC_PUPDR_PUPDR15         (0x3U<<30U)
#define GPIOC_PUPDR_PUPDR15_0       (0x1U<<30U)

// IDR Configuration

#define GPIOC_IDR_IDR0              (0x1U<<0U)
#define GPIOC_IDR_IDR1              (0x1U<<1U)
#define GPIOC_IDR_IDR2              (0x1U<<2U)
#define GPIOC_IDR_IDR3              (0x1U<<3U)
#define GPIOC_IDR_IDR4              (0x1U<<4U)
#define GPIOC_IDR_IDR5              (0x1U<<5U)
#define GPIOC_IDR_IDR6              (0x1U<<6U)
#define GPIOC_IDR_IDR7              (0x1U<<7U)
#define GPIOC_IDR_IDR8              (0x1U<<8U)
#define GPIOC_IDR_IDR9              (0x1U<<9U)
#define GPIOC_IDR_IDR10             (0x1U<<10U)
#define GPIOC_IDR_IDR11             (0x1U<<11U)
#define GPIOC_IDR_IDR12             (0x1U<<12U)
#define GPIOC_IDR_IDR13             (0x1U<<13U)
#define GPIOC_IDR_IDR14             (0x1U<<14U)
#define GPIOC_IDR_IDR15             (0x1U<<15U)

// ODR Configuration

#define GPIOC_ODR_ODR0              (0x1U<<0U)
#define GPIOC_ODR_ODR1              (0x1U<<1U)
#define GPIOC_ODR_ODR2              (0x1U<<2U)
#define GPIOC_ODR_ODR3              (0x1U<<3U)
#define GPIOC_ODR_ODR4              (0x1U<<4U)
#define GPIOC_ODR_ODR5              (0x1U<<5U)
#define GPIOC_ODR_ODR6              (0x1U<<6U)
#define GPIOC_ODR_ODR7              (0x1U<<7U)
#define GPIOC_ODR_ODR8              (0x1U<<8U)
#define GPIOC_ODR_ODR9              (0x1U<<9U)
#define GPIOC_ODR_ODR10             (0x1U<<10U)
#define GPIOC_ODR_ODR11             (0x1U<<11U)
#define GPIOC_ODR_ODR12             (0x1U<<12U)
#define GPIOC_ODR_ODR13             (0x1U<<13U)
#define GPIOC_ODR_ODR14             (0x1U<<14U)
#define GPIOC_ODR_ODR15             (0x1U<<15U)

// BSRR Configuration

#define GPIOC_BSRR_BS0              (0x1U<<0U)
#define GPIOC_BSRR_BS1              (0x1U<<1U)
#define GPIOC_BSRR_BS2              (0x1U<<2U)
#define GPIOC_BSRR_BS3              (0x1U<<3U)
#define GPIOC_BSRR_BS4              (0x1U<<4U)
#define GPIOC_BSRR_BS5              (0x1U<<5U)
#define GPIOC_BSRR_BS6              (0x1U<<6U)
#define GPIOC_BSRR_BS7              (0x1U<<7U)
#define GPIOC_BSRR_BS8              (0x1U<<8U)
#define GPIOC_BSRR_BS9              (0x1U<<9U)
#define GPIOC_BSRR_BS10             (0x1U<<10U)
#define GPIOC_BSRR_BS11             (0x1U<<11U)
#define GPIOC_BSRR_BS12             (0x1U<<12U)
#define GPIOC_BSRR_BS13             (0x1U<<13U)
#define GPIOC_BSRR_BS14             (0x1U<<14U)
#define GPIOC_BSRR_BS15             (0x1U<<15U)
#define GPIOC_BSRR_BR0              (0x1U<<16U)
#define GPIOC_BSRR_BR1              (0x1U<<17U)
#define GPIOC_BSRR_BR2              (0x1U<<18U)
#define GPIOC_BSRR_BR3              (0x1U<<19U)
#define GPIOC_BSRR_BR4              (0x1U<<20U)
#define GPIOC_BSRR_BR5              (0x1U<<21U)
#define GPIOC_BSRR_BR6              (0x1U<<22U)
#define GPIOC_BSRR_BR7              (0x1U<<23U)
#define GPIOC_BSRR_BR8              (0x1U<<24U)
#define GPIOC_BSRR_BR9              (0x1U<<25U)
#define GPIOC_BSRR_BR10             (0x1U<<26U)
#define GPIOC_BSRR_BR11             (0x1U<<27U)
#define GPIOC_BSRR_BR12             (0x1U<<28U)
#define GPIOC_BSRR_BR13             (0x1U<<29U)
#define GPIOC_BSRR_BR14             (0x1U<<30U)
#define GPIOC_BSRR_BR15             (0x1U<<31U)

// LCKR Configuration

#define GPIOC_LCKR_LCK0             (0x1U<<0U)
#define GPIOC_LCKR_LCK1             (0x1U<<1U)
#define GPIOC_LCKR_LCK2             (0x1U<<2U)
#define GPIOC_LCKR_LCK3             (0x1U<<3U)
#define GPIOC_LCKR_LCK4             (0x1U<<4U)
#define GPIOC_LCKR_LCK5             (0x1U<<5U)
#define GPIOC_LCKR_LCK6             (0x1U<<6U)
#define GPIOC_LCKR_LCK7             (0x1U<<7U)
#define GPIOC_LCKR_LCK8             (0x1U<<8U)
#define GPIOC_LCKR_LCK9             (0x1U<<9U)
#define GPIOC_LCKR_LCK10            (0x1U<<10U)
#define GPIOC_LCKR_LCK11            (0x1U<<11U)
#define GPIOC_LCKR_LCK12            (0x1U<<12U)
#define GPIOC_LCKR_LCK13            (0x1U<<13U)
#define GPIOC_LCKR_LCK14            (0x1U<<14U)
#define GPIOC_LCKR_LCK15            (0x1U<<15U)
#define GPIOC_LCKR_LCKK             (0x1U<<16U)

// AFRL Configuration

#define GPIOC_AFRL_AFRL0            (0xFU<<0U)
#define GPIOC_AFRL_AFRL0_0          (0x1U<<0U)
#define GPIOC_AFRL_AFRL1            (0xFU<<4U)
#define GPIOC_AFRL_AFRL1_0          (0x1U<<4U)
#define GPIOC_AFRL_AFRL2            (0xFU<<8U)
#define GPIOC_AFRL_AFRL2_0          (0x1U<<8U)
#define GPIOC_AFRL_AFRL3            (0xFU<<12U)
#define GPIOC_AFRL_AFRL3_0          (0x1U<<12U)
#define GPIOC_AFRL_AFRL4            (0xFU<<16U)
#define GPIOC_AFRL_AFRL4_0          (0x1U<<16U)
#define GPIOC_AFRL_AFRL5            (0xFU<<20U)
#define GPIOC_AFRL_AFRL5_0          (0x1U<<20U)
#define GPIOC_AFRL_AFRL6            (0xFU<<24U)
#define GPIOC_AFRL_AFRL6_0          (0x1U<<24U)
#define GPIOC_AFRL_AFRL7            (0xFU<<28U)
#define GPIOC_AFRL_AFRL7_0          (0x1U<<28U)

// AFRH Configuration

#define GPIOC_AFRH_AFRH8            (0xFU<<0U)
#define GPIOC_AFRH_AFRH8_0          (0x1U<<0U)
#define GPIOC_AFRH_AFRH9            (0xFU<<4U)
#define GPIOC_AFRH_AFRH9_0          (0x1U<<4U)
#define GPIOC_AFRH_AFRH10           (0xFU<<8U)
#define GPIOC_AFRH_AFRH10_0         (0x1U<<8U)
#define GPIOC_AFRH_AFRH11           (0xFU<<12U)
#define GPIOC_AFRH_AFRH11_0         (0x1U<<12U)
#define GPIOC_AFRH_AFRH12           (0xFU<<16U)
#define GPIOC_AFRH_AFRH12_0         (0x1U<<16U)
#define GPIOC_AFRH_AFRH13           (0xFU<<20U)
#define GPIOC_AFRH_AFRH13_0         (0x1U<<20U)
#define GPIOC_AFRH_AFRH14           (0xFU<<24U)
#define GPIOC_AFRH_AFRH14_0         (0x1U<<24U)
#define GPIOC_AFRH_AFRH15           (0xFU<<28U)
#define GPIOC_AFRH_AFRH15_0         (0x1U<<28U)

// BRR Configuration

#define GPIOC_BRR_BR15              (0x1U<<15U)
#define GPIOC_BRR_BR14              (0x1U<<14U)
#define GPIOC_BRR_BR13              (0x1U<<13U)
#define GPIOC_BRR_BR12              (0x1U<<12U)
#define GPIOC_BRR_BR11              (0x1U<<11U)
#define GPIOC_BRR_BR10              (0x1U<<10U)
#define GPIOC_BRR_BR9               (0x1U<<9U)
#define GPIOC_BRR_BR8               (0x1U<<8U)
#define GPIOC_BRR_BR7               (0x1U<<7U)
#define GPIOC_BRR_BR6               (0x1U<<6U)
#define GPIOC_BRR_BR5               (0x1U<<5U)
#define GPIOC_BRR_BR4               (0x1U<<4U)
#define GPIOC_BRR_BR3               (0x1U<<3U)
#define GPIOC_BRR_BR2               (0x1U<<2U)
#define GPIOC_BRR_BR1               (0x1U<<1U)
#define GPIOC_BRR_BR0               (0x1U<<0U)

// ASCR Configuration

#define GPIOC_ASCR_ASC15            (0x1U<<15U)
#define GPIOC_ASCR_ASC14            (0x1U<<14U)
#define GPIOC_ASCR_ASC13            (0x1U<<13U)
#define GPIOC_ASCR_ASC12            (0x1U<<12U)
#define GPIOC_ASCR_ASC11            (0x1U<<11U)
#define GPIOC_ASCR_ASC10            (0x1U<<10U)
#define GPIOC_ASCR_ASC9             (0x1U<<9U)
#define GPIOC_ASCR_ASC8             (0x1U<<8U)
#define GPIOC_ASCR_ASC7             (0x1U<<7U)
#define GPIOC_ASCR_ASC6             (0x1U<<6U)
#define GPIOC_ASCR_ASC5             (0x1U<<5U)
#define GPIOC_ASCR_ASC4             (0x1U<<4U)
#define GPIOC_ASCR_ASC3             (0x1U<<3U)
#define GPIOC_ASCR_ASC2             (0x1U<<2U)
#define GPIOC_ASCR_ASC1             (0x1U<<1U)
#define GPIOC_ASCR_ASC0             (0x1U<<0U)
