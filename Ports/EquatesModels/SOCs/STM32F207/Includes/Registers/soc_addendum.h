/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; soc_addendum.
; =============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     addendum equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// Unique device ID register base address
// --------------------------------------

#define UID_BASE                        0x1FFF7A10U

// USART generic
// -------------

// SR Configuration

#define USART_SR_PE                     (0x1U<<0)
#define USART_SR_FE                     (0x1U<<1)
#define USART_SR_NF                     (0x1U<<2)
#define USART_SR_ORE                    (0x1U<<3)
#define USART_SR_IDLE                   (0x1U<<4)
#define USART_SR_RXNE                   (0x1U<<5)
#define USART_SR_TC                     (0x1U<<6)
#define USART_SR_TXE                    (0x1U<<7)
#define USART_SR_LBD                    (0x1U<<8)
#define USART_SR_CTS                    (0x1U<<9)

// CR1 Configuration

#define USART_CR1_SBK                   (0x1U<<0)
#define USART_CR1_RWU                   (0x1U<<1)
#define USART_CR1_RE                    (0x1U<<2)
#define USART_CR1_TE                    (0x1U<<3)
#define USART_CR1_IDLEIE                (0x1U<<4)
#define USART_CR1_RXNEIE                (0x1U<<5)
#define USART_CR1_TCIE                  (0x1U<<6)
#define USART_CR1_TXEIE                 (0x1U<<7)
#define USART_CR1_PEIE                  (0x1U<<8)
#define USART_CR1_PS                    (0x1U<<9)
#define USART_CR1_PCE                   (0x1U<<10)
#define USART_CR1_WAKE                  (0x1U<<11)
#define USART_CR1_M                     (0x1U<<12)
#define USART_CR1_UE                    (0x1U<<13)
#define USART_CR1_OVER8                 (0x1U<<15)

// CR2 Configuration

#define USART_CR2_ADD                   (0xFU<<0)
#define USART_CR2_ADD_0                 (0x1U<<0)
#define USART_CR2_LBDL                  (0x1U<<5)
#define USART_CR2_LBDIE                 (0x1U<<6)
#define USART_CR2_LBCL                  (0x1U<<8)
#define USART_CR2_CPHA                  (0x1U<<9)
#define USART_CR2_CPOL                  (0x1U<<10)
#define USART_CR2_CLKEN                 (0x1U<<11)
#define USART_CR2_STOP                  (0x3U<<12)
#define USART_CR2_STOP_0                (0x1U<<12)
#define USART_CR2_LINEN                 (0x1U<<14)

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

#define OTG_FS_GLOBAL_FS_GCCFG_VBDEN    (0x1U<<21)

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
                GPIO##port->AFRH =      (d15<<28) | (d14<<24) | (d13<<20) | (d12<<16) | \
                                        (d11<<12) | (d10<<8)  | (d9<<4)   | (d8<<0); \
                GPIO##port->AFRL =      (d7<<28)  | (d6<<24)  | (d5<<20)  | (d4<<16)  | \
                                        (d3<<12)  | (d2<<8)   | (d1<<4)   | (d0<<0); \
                GPIO##port->OSPEEDR =   (b15<<30) | (b14<<28) | (b13<<26) | (b12<<24) | \
                                        (b11<<22) | (b10<<20) | (b9<<18)  | (b8<<16)  | \
                                        (b7<<14)  | (b6<<12)  | (b5<<10)  | (b4<<8)   | \
                                        (b3<<6)   | (b2<<4)   | (b1<<2)   | (b0<<0); \
                GPIO##port->OTYPER =    (e15<<15) | (e14<<14) | (e13<<13) | (e12<<12) | \
                                        (e11<<11) | (e10<<10) | (e9<<9)   | (e8<<8)   | \
                                        (e7<<7)   | (e6<<6)   | (e5<<5)   | (e4<<4)   | \
                                        (e3<<3)   | (e2<<2)   | (e1<<1)   | (e0<<0); \
                GPIO##port->MODER =     (a15<<30) | (a14<<28) | (a13<<26) | (a12<<24) | \
                                        (a11<<22) | (a10<<20) | (a9<<18)  | (a8<<16)  | \
                                        (a7<<14)  | (a6<<12)  | (a5<<10)  | (a4<<8)   | \
                                        (a3<<6)   | (a2<<4)   | (a1<<2)   | (a0<<0); \
                GPIO##port->PUPDR =     (c15<<30) | (c14<<28) | (c13<<26) | (c12<<24) | \
                                        (c11<<22) | (c10<<20) | (c9<<18)  | (c8<<16)  | \
                                        (c7<<14)  | (c6<<12)  | (c5<<10)  | (c4<<8)   | \
                                        (c3<<6)   | (c2<<4)   | (c1<<2)   | (c0<<0); \
                GPIO##port->ODR |=      (f15<<15) | (f14<<14) | (f13<<13) | (f12<<12) | \
                                        (f11<<11) | (f10<<10) | (f9<<9)   | (f8<<8)   | \
                                        (f7<<7)   | (f6<<6)   | (f5<<5)   | (f4<<4)   | \
                                        (f3<<3)   | (f2<<2)   | (f1<<1)   | (f0<<0);
