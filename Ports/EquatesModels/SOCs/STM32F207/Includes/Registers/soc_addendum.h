/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     addendum equates.
 */

#pragma once

// Unique device ID register base address
// --------------------------------------

#define UID_BASE                        0x1FFF7A10U

// USART generic
// -------------

// SR Configuration

#define USART_SR_PE                     (0x1U<<0U)
#define USART_SR_FE                     (0x1U<<1U)
#define USART_SR_NF                     (0x1U<<2U)
#define USART_SR_ORE                    (0x1U<<3U)
#define USART_SR_IDLE                   (0x1U<<4U)
#define USART_SR_RXNE                   (0x1U<<5U)
#define USART_SR_TC                     (0x1U<<6U)
#define USART_SR_TXE                    (0x1U<<7U)
#define USART_SR_LBD                    (0x1U<<8U)
#define USART_SR_CTS                    (0x1U<<9U)

// CR1 Configuration

#define USART_CR1_SBK                   (0x1U<<0U)
#define USART_CR1_RWU                   (0x1U<<1U)
#define USART_CR1_RE                    (0x1U<<2U)
#define USART_CR1_TE                    (0x1U<<3U)
#define USART_CR1_IDLEIE                (0x1U<<4U)
#define USART_CR1_RXNEIE                (0x1U<<5U)
#define USART_CR1_TCIE                  (0x1U<<6U)
#define USART_CR1_TXEIE                 (0x1U<<7U)
#define USART_CR1_PEIE                  (0x1U<<8U)
#define USART_CR1_PS                    (0x1U<<9U)
#define USART_CR1_PCE                   (0x1U<<10U)
#define USART_CR1_WAKE                  (0x1U<<11U)
#define USART_CR1_M                     (0x1U<<12U)
#define USART_CR1_UE                    (0x1U<<13U)
#define USART_CR1_OVER8                 (0x1U<<15U)

// CR2 Configuration

#define USART_CR2_ADD                   (0xFU<<0U)
#define USART_CR2_ADD_0                 (0x1U<<0U)
#define USART_CR2_LBDL                  (0x1U<<5U)
#define USART_CR2_LBDIE                 (0x1U<<6U)
#define USART_CR2_LBCL                  (0x1U<<8U)
#define USART_CR2_CPHA                  (0x1U<<9U)
#define USART_CR2_CPOL                  (0x1U<<10U)
#define USART_CR2_CLKEN                 (0x1U<<11U)
#define USART_CR2_STOP                  (0x3U<<12U)
#define USART_CR2_STOP_0                (0x1U<<12U)
#define USART_CR2_LINEN                 (0x1U<<14U)

// mpu additional definitions
// --------------------------

#define PERIPH_BASE                     0x40000000U

// iwdg additional definitions
// ---------------------------

// KR Configuration

#define IWDG_KR_DISABLE                 0x5555U
#define IWDG_KR_START                   0xCCCCU
#define IWDG_KR_RELOAD                  0xAAAAU

// PR Configuration

#define IWDG_PR_1_4                     0x0000U
#define IWDG_PR_1_8                     0x0001U
#define IWDG_PR_1_16                    0x0002U
#define IWDG_PR_1_32                    0x0003U
#define IWDG_PR_1_64                    0x0004U
#define IWDG_PR_1_128                   0x0005U
#define IWDG_PR_1_256                   0x0006U

// otg additional definitions
// --------------------------

#define OTG_FS_GLOBAL_FS_GCCFG_VBDEN    (0x1U<<21U)

#define USB_OTG_FS_PERIPH_BASE          0x50000000U
#define USB_OTG_GLOBAL_BASE             0x00000000U
#define USB_OTG_DEVICE_BASE             0x00000800U
#define USB_OTG_IN_ENDPOINT_BASE        0x00000900U
#define USB_OTG_OUT_ENDPOINT_BASE       0x00000B00U
#define USB_OTG_EP_REG_SIZE             0x00000020U
#define USB_OTG_HOST_BASE               0x00000400U
#define USB_OTG_HOST_PORT_BASE          0x00000440U
#define USB_OTG_HOST_CHANNEL_BASE       0x00000500U
#define USB_OTG_HOST_CHANNEL_SIZE       0x00000020U
#define USB_OTG_PCGCCTL_BASE            0x00000E00U
#define USB_OTG_FIFO_BASE               0x00001000U
#define USB_OTG_FIFO_SIZE               0x00001000U

#define USB_OTG_FS_MAX_IN_ENDPOINTS     4U
#define USB_OTG_FS_TOTAL_FIFO_SIZE      1280U

// gpio additional definitions
// ---------------------------

// GPIO for MODE configuration
// - Input (reset state)
// - General purpose output
// - Alternate function
// - Analog function

#define KIN                             0x0U
#define KOU                             0x1U
#define KAL                             0x2U
#define KAN                             0x3U

// GPIO for OTYPER configuration
// - Output Push-pull
// - Output Open Drain

#define KPP                             0x0U
#define KOD                             0x1U

// GPIO for OSPEEDR configuration
// - Low speed 2-MHz
// - Medium speed 25-MHz
// - Fast speed 50-MHz
// - High speed 100-MHz

#define K02                             0x0U
#define K25                             0x1U
#define K50                             0x2U
#define K99                             0x3U

// GPIO for PUPDR configuration
// - No pull-up, pull-down
// - Pull-up
// - Pull-down
// - Reserved

#define KNO                             0x0U
#define KPU                             0x1U
#define KPD                             0x2U
#define KRE                             0x3U

// GPIO for AFR[x] configuration

#define A00                             0U
#define A01                             1U
#define A02                             2U
#define A03                             3U
#define A04                             4U
#define A05                             5U
#define A06                             6U
#define A07                             7U
#define A08                             8U
#define A09                             9U
#define A10                             10U
#define A11                             11U
#define A12                             12U
#define A13                             13U
#define A14                             14U
#define A15                             15U

// GPIO configure macro

#define CNFGPIO(port, \
                a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0, \
                b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, \
                c15, c14, c13, c12, c11, c10, c9, c8, c7, c6, c5, c4, c3, c2, c1, c0, \
                d15, d14, d13, d12, d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, \
                e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0, \
                f15, f14, f13, f12, f11, f10, f9, f8, f7, f6, f5, f4, f3, f2, f1, f0) \
                GPIO##port->AFRH =      (d15<<28U) | (d14<<24U) | (d13<<20U) | (d12<<16U) | \
                                        (d11<<12U) | (d10<<8U)  | (d9<<4U)   | (d8<<0U); \
                GPIO##port->AFRL =      (d7<<28U)  | (d6<<24U)  | (d5<<20U)  | (d4<<16U)  | \
                                        (d3<<12U)  | (d2<<8U)   | (d1<<4U)   | (d0<<0U); \
                GPIO##port->OSPEEDR =   (b15<<30U) | (b14<<28U) | (b13<<26U) | (b12<<24U) | \
                                        (b11<<22U) | (b10<<20U) | (b9<<18U)  | (b8<<16U)  | \
                                        (b7<<14U)  | (b6<<12U)  | (b5<<10U)  | (b4<<8U)   | \
                                        (b3<<6U)   | (b2<<4U)   | (b1<<2U)   | (b0<<0U); \
                GPIO##port->OTYPER =    (e15<<15U) | (e14<<14U) | (e13<<13U) | (e12<<12U) | \
                                        (e11<<11U) | (e10<<10U) | (e9<<9U)   | (e8<<8U)   | \
                                        (e7<<7U)   | (e6<<6U)   | (e5<<5U)   | (e4<<4U)   | \
                                        (e3<<3U)   | (e2<<2U)   | (e1<<1U)   | (e0<<0U); \
                GPIO##port->MODER =     (a15<<30U) | (a14<<28U) | (a13<<26U) | (a12<<24U) | \
                                        (a11<<22U) | (a10<<20U) | (a9<<18U)  | (a8<<16U)  | \
                                        (a7<<14U)  | (a6<<12U)  | (a5<<10U)  | (a4<<8U)   | \
                                        (a3<<6U)   | (a2<<4U)   | (a1<<2U)   | (a0<<0U); \
                GPIO##port->PUPDR =     (c15<<30U) | (c14<<28U) | (c13<<26U) | (c12<<24U) | \
                                        (c11<<22U) | (c10<<20U) | (c9<<18U)  | (c8<<16U)  | \
                                        (c7<<14U)  | (c6<<12U)  | (c5<<10U)  | (c4<<8U)   | \
                                        (c3<<6U)   | (c2<<4U)   | (c1<<2U)   | (c0<<0U); \
                GPIO##port->ODR |=      (f15<<15U) | (f14<<14U) | (f13<<13U) | (f12<<12U) | \
                                        (f11<<11U) | (f10<<10U) | (f9<<9U)   | (f8<<8U)   | \
                                        (f7<<7U)   | (f6<<6U)   | (f5<<5U)   | (f4<<4U)   | \
                                        (f3<<3U)   | (f2<<2U)   | (f1<<1U)   | (f0<<0U);
