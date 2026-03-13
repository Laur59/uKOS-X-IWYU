/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_gpio.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_gpio equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
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

#define GPIO_CTL0_MD0       (0x3U<<0)
#define GPIO_CTL0_MD0_0     (0x1U<<0)
#define GPIO_CTL0_CTL0      (0x3U<<2)
#define GPIO_CTL0_CTL0_0    (0x1U<<2)
#define GPIO_CTL0_MD1       (0x3U<<4)
#define GPIO_CTL0_MD1_0     (0x1U<<4)
#define GPIO_CTL0_CTL1      (0x3U<<6)
#define GPIO_CTL0_CTL1_0    (0x1U<<6)
#define GPIO_CTL0_MD2       (0x3U<<8)
#define GPIO_CTL0_MD2_0     (0x1U<<8)
#define GPIO_CTL0_CTL2      (0x3U<<10)
#define GPIO_CTL0_CTL2_0    (0x1U<<10)
#define GPIO_CTL0_MD3       (0x3U<<12)
#define GPIO_CTL0_MD3_0     (0x1U<<12)
#define GPIO_CTL0_CTL3      (0x3U<<14)
#define GPIO_CTL0_CTL3_0    (0x1U<<14)
#define GPIO_CTL0_MD4       (0x3U<<16)
#define GPIO_CTL0_MD4_0     (0x1U<<16)
#define GPIO_CTL0_CTL4      (0x3U<<18)
#define GPIO_CTL0_CTL4_0    (0x1U<<18)
#define GPIO_CTL0_MD5       (0x3U<<20)
#define GPIO_CTL0_MD5_0     (0x1U<<20)
#define GPIO_CTL0_CTL5      (0x3U<<22)
#define GPIO_CTL0_CTL5_0    (0x1U<<22)
#define GPIO_CTL0_MD6       (0x3U<<24)
#define GPIO_CTL0_MD6_0     (0x1U<<24)
#define GPIO_CTL0_CTL6      (0x3U<<26)
#define GPIO_CTL0_CTL6_0    (0x1U<<26)
#define GPIO_CTL0_MD7       (0x3U<<28)
#define GPIO_CTL0_MD7_0     (0x1U<<28)
#define GPIO_CTL0_CTL7      (0x3U<<30)
#define GPIO_CTL0_CTL7_0    (0x1U<<30)

// CTL1 Configuration

#define GPIO_CTL1_MD8       (0x3U<<0)
#define GPIO_CTL1_MD8_0     (0x1U<<0)
#define GPIO_CTL1_CTL8      (0x3U<<2)
#define GPIO_CTL1_CTL8_0    (0x1U<<2)
#define GPIO_CTL1_MD9       (0x3U<<4)
#define GPIO_CTL1_MD9_0     (0x1U<<4)
#define GPIO_CTL1_CTL9      (0x3U<<6)
#define GPIO_CTL1_CTL9_0    (0x1U<<6)
#define GPIO_CTL1_MD10      (0x3U<<8)
#define GPIO_CTL1_MD10_0    (0x1U<<8)
#define GPIO_CTL1_CTL10     (0x3U<<10)
#define GPIO_CTL1_CTL10_0   (0x1U<<10)
#define GPIO_CTL1_MD11      (0x3U<<12)
#define GPIO_CTL1_MD11_0    (0x1U<<12)
#define GPIO_CTL1_CTL11     (0x3U<<14)
#define GPIO_CTL1_CTL11_0   (0x1U<<14)
#define GPIO_CTL1_MD12      (0x3U<<16)
#define GPIO_CTL1_MD12_0    (0x1U<<16)
#define GPIO_CTL1_CTL12     (0x3U<<18)
#define GPIO_CTL1_CTL12_0   (0x1U<<18)
#define GPIO_CTL1_MD13      (0x3U<<20)
#define GPIO_CTL1_MD13_0    (0x1U<<20)
#define GPIO_CTL1_CTL13     (0x3U<<22)
#define GPIO_CTL1_CTL13_0   (0x1U<<22)
#define GPIO_CTL1_MD14      (0x3U<<24)
#define GPIO_CTL1_MD14_0    (0x1U<<24)
#define GPIO_CTL1_CTL14     (0x3U<<26)
#define GPIO_CTL1_CTL14_0   (0x1U<<26)
#define GPIO_CTL1_MD15      (0x3U<<28)
#define GPIO_CTL1_MD15_0    (0x1U<<28)
#define GPIO_CTL1_CTL15     (0x3U<<30)
#define GPIO_CTL1_CTL15_0   (0x1U<<30)

// ISTAT Configuration

#define GPIO_ISTAT_ISTAT0   (0x1U<<0)
#define GPIO_ISTAT_ISTAT1   (0x1U<<1)
#define GPIO_ISTAT_ISTAT2   (0x1U<<2)
#define GPIO_ISTAT_ISTAT3   (0x1U<<3)
#define GPIO_ISTAT_ISTAT4   (0x1U<<4)
#define GPIO_ISTAT_ISTAT5   (0x1U<<5)
#define GPIO_ISTAT_ISTAT6   (0x1U<<6)
#define GPIO_ISTAT_ISTAT7   (0x1U<<7)
#define GPIO_ISTAT_ISTAT8   (0x1U<<8)
#define GPIO_ISTAT_ISTAT9   (0x1U<<9)
#define GPIO_ISTAT_ISTAT10  (0x1U<<10)
#define GPIO_ISTAT_ISTAT11  (0x1U<<11)
#define GPIO_ISTAT_ISTAT12  (0x1U<<12)
#define GPIO_ISTAT_ISTAT13  (0x1U<<13)
#define GPIO_ISTAT_ISTAT14  (0x1U<<14)
#define GPIO_ISTAT_ISTAT15  (0x1U<<15)

// OCTL Configuration

#define GPIO_OCTL_OCTL0     (0x1U<<0)
#define GPIO_OCTL_OCTL1     (0x1U<<1)
#define GPIO_OCTL_OCTL2     (0x1U<<2)
#define GPIO_OCTL_OCTL3     (0x1U<<3)
#define GPIO_OCTL_OCTL4     (0x1U<<4)
#define GPIO_OCTL_OCTL5     (0x1U<<5)
#define GPIO_OCTL_OCTL6     (0x1U<<6)
#define GPIO_OCTL_OCTL7     (0x1U<<7)
#define GPIO_OCTL_OCTL8     (0x1U<<8)
#define GPIO_OCTL_OCTL9     (0x1U<<9)
#define GPIO_OCTL_OCTL10    (0x1U<<10)
#define GPIO_OCTL_OCTL11    (0x1U<<11)
#define GPIO_OCTL_OCTL12    (0x1U<<12)
#define GPIO_OCTL_OCTL13    (0x1U<<13)
#define GPIO_OCTL_OCTL14    (0x1U<<14)
#define GPIO_OCTL_OCTL15    (0x1U<<15)

// BOP Configuration

#define GPIO_BOP_BOP0       (0x1U<<0)
#define GPIO_BOP_BOP1       (0x1U<<1)
#define GPIO_BOP_BOP2       (0x1U<<2)
#define GPIO_BOP_BOP3       (0x1U<<3)
#define GPIO_BOP_BOP4       (0x1U<<4)
#define GPIO_BOP_BOP5       (0x1U<<5)
#define GPIO_BOP_BOP6       (0x1U<<6)
#define GPIO_BOP_BOP7       (0x1U<<7)
#define GPIO_BOP_BOP8       (0x1U<<8)
#define GPIO_BOP_BOP9       (0x1U<<9)
#define GPIO_BOP_BOP10      (0x1U<<10)
#define GPIO_BOP_BOP11      (0x1U<<11)
#define GPIO_BOP_BOP12      (0x1U<<12)
#define GPIO_BOP_BOP13      (0x1U<<13)
#define GPIO_BOP_BOP14      (0x1U<<14)
#define GPIO_BOP_BOP15      (0x1U<<15)
#define GPIO_BOP_CR0        (0x1U<<16)
#define GPIO_BOP_CR1        (0x1U<<17)
#define GPIO_BOP_CR2        (0x1U<<18)
#define GPIO_BOP_CR3        (0x1U<<19)
#define GPIO_BOP_CR4        (0x1U<<20)
#define GPIO_BOP_CR5        (0x1U<<21)
#define GPIO_BOP_CR6        (0x1U<<22)
#define GPIO_BOP_CR7        (0x1U<<23)
#define GPIO_BOP_CR8        (0x1U<<24)
#define GPIO_BOP_CR9        (0x1U<<25)
#define GPIO_BOP_CR10       (0x1U<<26)
#define GPIO_BOP_CR11       (0x1U<<27)
#define GPIO_BOP_CR12       (0x1U<<28)
#define GPIO_BOP_CR13       (0x1U<<29)
#define GPIO_BOP_CR14       (0x1U<<30)
#define GPIO_BOP_CR15       (0x1U<<31)

// BC Configuration

#define GPIO_BC_CR0         (0x1U<<0)
#define GPIO_BC_CR1         (0x1U<<1)
#define GPIO_BC_CR2         (0x1U<<2)
#define GPIO_BC_CR3         (0x1U<<3)
#define GPIO_BC_CR4         (0x1U<<4)
#define GPIO_BC_CR5         (0x1U<<5)
#define GPIO_BC_CR6         (0x1U<<6)
#define GPIO_BC_CR7         (0x1U<<7)
#define GPIO_BC_CR8         (0x1U<<8)
#define GPIO_BC_CR9         (0x1U<<9)
#define GPIO_BC_CR10        (0x1U<<10)
#define GPIO_BC_CR11        (0x1U<<11)
#define GPIO_BC_CR12        (0x1U<<12)
#define GPIO_BC_CR13        (0x1U<<13)
#define GPIO_BC_CR14        (0x1U<<14)
#define GPIO_BC_CR15        (0x1U<<15)

// LOCK Configuration

#define GPIO_LOCK_LK0       (0x1U<<0)
#define GPIO_LOCK_LK1       (0x1U<<1)
#define GPIO_LOCK_LK2       (0x1U<<2)
#define GPIO_LOCK_LK3       (0x1U<<3)
#define GPIO_LOCK_LK4       (0x1U<<4)
#define GPIO_LOCK_LK5       (0x1U<<5)
#define GPIO_LOCK_LK6       (0x1U<<6)
#define GPIO_LOCK_LK7       (0x1U<<7)
#define GPIO_LOCK_LK8       (0x1U<<8)
#define GPIO_LOCK_LK9       (0x1U<<9)
#define GPIO_LOCK_LK10      (0x1U<<10)
#define GPIO_LOCK_LK11      (0x1U<<11)
#define GPIO_LOCK_LK12      (0x1U<<12)
#define GPIO_LOCK_LK13      (0x1U<<13)
#define GPIO_LOCK_LK14      (0x1U<<14)
#define GPIO_LOCK_LK15      (0x1U<<15)
#define GPIO_LOCK_LKK       (0x1U<<16)
