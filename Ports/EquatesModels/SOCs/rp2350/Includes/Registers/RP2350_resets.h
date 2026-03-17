/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; RP2350_resets.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     RP2350_resets equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// RESETS address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    RESET;
    volatile    uint32_t    WDSEL;
    volatile    uint32_t    RESET_DONE;
} RESETS_TypeDef;

#ifdef __cplusplus
#define RESETS_NS   reinterpret_cast<RESETS_TypeDef *>(0x40020000U)
#define RESETS_S    reinterpret_cast<RESETS_TypeDef *>(0x40020000U)
#else
#define RESETS_NS   ((RESETS_TypeDef *)0x40020000U)
#define RESETS_S    ((RESETS_TypeDef *)0x40020000U)
#endif

// RESET Configuration

#define RESETS_RESET_ADC                (0x1U<<0)
#define RESETS_RESET_BUSCTRL            (0x1U<<1)
#define RESETS_RESET_DMA                (0x1U<<2)
#define RESETS_RESET_HSTX               (0x1U<<3)
#define RESETS_RESET_I2C0               (0x1U<<4)
#define RESETS_RESET_I2C1               (0x1U<<5)
#define RESETS_RESET_IO_BANK0           (0x1U<<6)
#define RESETS_RESET_IO_QSPI            (0x1U<<7)
#define RESETS_RESET_JTAG               (0x1U<<8)
#define RESETS_RESET_PADS_BANK0         (0x1U<<9)
#define RESETS_RESET_PADS_QSPI          (0x1U<<10)
#define RESETS_RESET_PIO0               (0x1U<<11)
#define RESETS_RESET_PIO1               (0x1U<<12)
#define RESETS_RESET_PIO2               (0x1U<<13)
#define RESETS_RESET_PLL_SYS            (0x1U<<14)
#define RESETS_RESET_PLL_USB            (0x1U<<15)
#define RESETS_RESET_PWM                (0x1U<<16)
#define RESETS_RESET_SHA256             (0x1U<<17)
#define RESETS_RESET_SPI0               (0x1U<<18)
#define RESETS_RESET_SPI1               (0x1U<<19)
#define RESETS_RESET_SYSCFG             (0x1U<<20)
#define RESETS_RESET_SYSINFO            (0x1U<<21)
#define RESETS_RESET_TBMAN              (0x1U<<22)
#define RESETS_RESET_TIMER0             (0x1U<<23)
#define RESETS_RESET_TIMER1             (0x1U<<24)
#define RESETS_RESET_TRNG               (0x1U<<25)
#define RESETS_RESET_UART0              (0x1U<<26)
#define RESETS_RESET_UART1              (0x1U<<27)
#define RESETS_RESET_USBCTRL            (0x1U<<28)

// WDSEL Configuration

#define RESETS_WDSEL_ADC                (0x1U<<0)
#define RESETS_WDSEL_BUSCTRL            (0x1U<<1)
#define RESETS_WDSEL_DMA                (0x1U<<2)
#define RESETS_WDSEL_HSTX               (0x1U<<3)
#define RESETS_WDSEL_I2C0               (0x1U<<4)
#define RESETS_WDSEL_I2C1               (0x1U<<5)
#define RESETS_WDSEL_IO_BANK0           (0x1U<<6)
#define RESETS_WDSEL_IO_QSPI            (0x1U<<7)
#define RESETS_WDSEL_JTAG               (0x1U<<8)
#define RESETS_WDSEL_PADS_BANK0         (0x1U<<9)
#define RESETS_WDSEL_PADS_QSPI          (0x1U<<10)
#define RESETS_WDSEL_PIO0               (0x1U<<11)
#define RESETS_WDSEL_PIO1               (0x1U<<12)
#define RESETS_WDSEL_PIO2               (0x1U<<13)
#define RESETS_WDSEL_PLL_SYS            (0x1U<<14)
#define RESETS_WDSEL_PLL_USB            (0x1U<<15)
#define RESETS_WDSEL_PWM                (0x1U<<16)
#define RESETS_WDSEL_SHA256             (0x1U<<17)
#define RESETS_WDSEL_SPI0               (0x1U<<18)
#define RESETS_WDSEL_SPI1               (0x1U<<19)
#define RESETS_WDSEL_SYSCFG             (0x1U<<20)
#define RESETS_WDSEL_SYSINFO            (0x1U<<21)
#define RESETS_WDSEL_TBMAN              (0x1U<<22)
#define RESETS_WDSEL_TIMER0             (0x1U<<23)
#define RESETS_WDSEL_TIMER1             (0x1U<<24)
#define RESETS_WDSEL_TRNG               (0x1U<<25)
#define RESETS_WDSEL_UART0              (0x1U<<26)
#define RESETS_WDSEL_UART1              (0x1U<<27)
#define RESETS_WDSEL_USBCTRL            (0x1U<<28)

// RESET_DONE Configuration

#define RESETS_RESET_DONE_ADC           (0x1U<<0)
#define RESETS_RESET_DONE_BUSCTRL       (0x1U<<1)
#define RESETS_RESET_DONE_DMA           (0x1U<<2)
#define RESETS_RESET_DONE_HSTX          (0x1U<<3)
#define RESETS_RESET_DONE_I2C0          (0x1U<<4)
#define RESETS_RESET_DONE_I2C1          (0x1U<<5)
#define RESETS_RESET_DONE_IO_BANK0      (0x1U<<6)
#define RESETS_RESET_DONE_IO_QSPI       (0x1U<<7)
#define RESETS_RESET_DONE_JTAG          (0x1U<<8)
#define RESETS_RESET_DONE_PADS_BANK0    (0x1U<<9)
#define RESETS_RESET_DONE_PADS_QSPI     (0x1U<<10)
#define RESETS_RESET_DONE_PIO0          (0x1U<<11)
#define RESETS_RESET_DONE_PIO1          (0x1U<<12)
#define RESETS_RESET_DONE_PIO2          (0x1U<<13)
#define RESETS_RESET_DONE_PLL_SYS       (0x1U<<14)
#define RESETS_RESET_DONE_PLL_USB       (0x1U<<15)
#define RESETS_RESET_DONE_PWM           (0x1U<<16)
#define RESETS_RESET_DONE_SHA256        (0x1U<<17)
#define RESETS_RESET_DONE_SPI0          (0x1U<<18)
#define RESETS_RESET_DONE_SPI1          (0x1U<<19)
#define RESETS_RESET_DONE_SYSCFG        (0x1U<<20)
#define RESETS_RESET_DONE_SYSINFO       (0x1U<<21)
#define RESETS_RESET_DONE_TBMAN         (0x1U<<22)
#define RESETS_RESET_DONE_TIMER0        (0x1U<<23)
#define RESETS_RESET_DONE_TIMER1        (0x1U<<24)
#define RESETS_RESET_DONE_TRNG          (0x1U<<25)
#define RESETS_RESET_DONE_UART0         (0x1U<<26)
#define RESETS_RESET_DONE_UART1         (0x1U<<27)
#define RESETS_RESET_DONE_USBCTRL       (0x1U<<28)
