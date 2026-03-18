/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_afio equates.
 */

#pragma once

#include    <stdint.h>

// AFIO address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    EC;
    volatile    uint32_t    PCF0;
    volatile    uint32_t    EXTISS0;
    volatile    uint32_t    EXTISS1;
    volatile    uint32_t    EXTISS2;
    volatile    uint32_t    EXTISS3;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    PCF1;
} AFIO_TypeDef;

#ifdef __cplusplus
#define AFIO    reinterpret_cast<AFIO_TypeDef *>(0x40010000U)

#else
#define AFIO    ((AFIO_TypeDef *)0x40010000U)
#endif

// EC Configuration

#define AFIO_EC_PIN                 (0xFU<<0)
#define AFIO_EC_PIN_0               (0x1U<<0)
#define AFIO_EC_PORT                (0x7U<<4)
#define AFIO_EC_PORT_0              (0x1U<<4)
#define AFIO_EC_EOE                 (0x1U<<7)

// PCF0 Configuration

#define AFIO_PCF0_SPI0_REMAP        (0x1U<<0)
#define AFIO_PCF0_I2C0_REMAP        (0x1U<<1)
#define AFIO_PCF0_USART0_REMAP      (0x1U<<2)
#define AFIO_PCF0_USART1_REMAP      (0x1U<<3)
#define AFIO_PCF0_USART2_REMAP      (0x3U<<4)
#define AFIO_PCF0_USART2_REMAP_0    (0x1U<<4)
#define AFIO_PCF0_TIMER0_REMAP      (0x3U<<6)
#define AFIO_PCF0_TIMER0_REMAP_0    (0x1U<<6)
#define AFIO_PCF0_TIMER1_REMAP      (0x3U<<8)
#define AFIO_PCF0_TIMER1_REMAP_0    (0x1U<<8)
#define AFIO_PCF0_TIMER2_REMAP      (0x3U<<10)
#define AFIO_PCF0_TIMER2_REMAP_0    (0x1U<<10)
#define AFIO_PCF0_TIMER3_REMAP      (0x1U<<12)
#define AFIO_PCF0_CAN0_REMAP        (0x3U<<13)
#define AFIO_PCF0_CAN0_REMAP_0      (0x1U<<13)
#define AFIO_PCF0_PD01_REMAP        (0x1U<<15)
#define AFIO_PCF0_TIMER4CH3_IREMAP  (0x1U<<16)
#define AFIO_PCF0_CAN1_REMAP        (0x1U<<22)
#define AFIO_PCF0_SWJ_CFG           (0x7U<<24)
#define AFIO_PCF0_SWJ_CFG_0         (0x1U<<24)
#define AFIO_PCF0_SPI2_REMAP        (0x1U<<28)
#define AFIO_PCF0_TIMER1ITI1_REMAP  (0x1U<<29)

// EXTISS0 Configuration

#define AFIO_EXTISS0_EXTI0_SS       (0xFU<<0)
#define AFIO_EXTISS0_EXTI0_SS_0     (0x1U<<0)
#define AFIO_EXTISS0_EXTI1_SS       (0xFU<<4)
#define AFIO_EXTISS0_EXTI1_SS_0     (0x1U<<4)
#define AFIO_EXTISS0_EXTI2_SS       (0xFU<<8)
#define AFIO_EXTISS0_EXTI2_SS_0     (0x1U<<8)
#define AFIO_EXTISS0_EXTI3_SS       (0xFU<<12)
#define AFIO_EXTISS0_EXTI3_SS_0     (0x1U<<12)

// EXTISS1 Configuration

#define AFIO_EXTISS1_EXTI4_SS       (0xFU<<0)
#define AFIO_EXTISS1_EXTI4_SS_0     (0x1U<<0)
#define AFIO_EXTISS1_EXTI5_SS       (0xFU<<4)
#define AFIO_EXTISS1_EXTI5_SS_0     (0x1U<<4)
#define AFIO_EXTISS1_EXTI6_SS       (0xFU<<8)
#define AFIO_EXTISS1_EXTI6_SS_0     (0x1U<<8)
#define AFIO_EXTISS1_EXTI7_SS       (0xFU<<12)
#define AFIO_EXTISS1_EXTI7_SS_0     (0x1U<<12)

// EXTISS2 Configuration

#define AFIO_EXTISS2_EXTI8_SS       (0xFU<<0)
#define AFIO_EXTISS2_EXTI8_SS_0     (0x1U<<0)
#define AFIO_EXTISS2_EXTI9_SS       (0xFU<<4)
#define AFIO_EXTISS2_EXTI9_SS_0     (0x1U<<4)
#define AFIO_EXTISS2_EXTI10_SS      (0xFU<<8)
#define AFIO_EXTISS2_EXTI10_SS_0    (0x1U<<8)
#define AFIO_EXTISS2_EXTI11_SS      (0xFU<<12)
#define AFIO_EXTISS2_EXTI11_SS_0    (0x1U<<12)

// EXTISS3 Configuration

#define AFIO_EXTISS3_EXTI12_SS      (0xFU<<0)
#define AFIO_EXTISS3_EXTI12_SS_0    (0x1U<<0)
#define AFIO_EXTISS3_EXTI13_SS      (0xFU<<4)
#define AFIO_EXTISS3_EXTI13_SS_0    (0x1U<<4)
#define AFIO_EXTISS3_EXTI14_SS      (0xFU<<8)
#define AFIO_EXTISS3_EXTI14_SS_0    (0x1U<<8)
#define AFIO_EXTISS3_EXTI15_SS      (0xFU<<12)
#define AFIO_EXTISS3_EXTI15_SS_0    (0x1U<<12)

// PCF1 Configuration

#define AFIO_PCF1_EXMC_NADV         (0x1U<<10)
