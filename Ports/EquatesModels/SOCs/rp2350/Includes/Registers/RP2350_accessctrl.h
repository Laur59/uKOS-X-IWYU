/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_accessctrl equates.
 */

#pragma once

#include    <stdint.h>

// ACCESSCTRL address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    LOCK;
    volatile    uint32_t    FORCE_CORE_NS;
    volatile    uint32_t    CFGRESET;
    volatile    uint32_t    GPIO_NSMASK0;
    volatile    uint32_t    GPIO_NSMASK1;
    volatile    uint32_t    ROM;
    volatile    uint32_t    XIP_MAIN;
    volatile    uint32_t    SRAM0;
    volatile    uint32_t    SRAM1;
    volatile    uint32_t    SRAM2;
    volatile    uint32_t    SRAM3;
    volatile    uint32_t    SRAM4;
    volatile    uint32_t    SRAM5;
    volatile    uint32_t    SRAM6;
    volatile    uint32_t    SRAM7;
    volatile    uint32_t    SRAM8;
    volatile    uint32_t    SRAM9;
    volatile    uint32_t    DMA;
    volatile    uint32_t    USBCTRL;
    volatile    uint32_t    PIO0;
    volatile    uint32_t    PIO1;
    volatile    uint32_t    PIO2;
    volatile    uint32_t    CORESIGHT_TRACE;
    volatile    uint32_t    CORESIGHT_PERIPH;
    volatile    uint32_t    SYSINFO;
    volatile    uint32_t    RESETS;
    volatile    uint32_t    IO_BANK0;
    volatile    uint32_t    IO_BANK1;
    volatile    uint32_t    PADS_BANK0;
    volatile    uint32_t    PADS_QSPI;
    volatile    uint32_t    BUSCTRL;
    volatile    uint32_t    ADC0;
    volatile    uint32_t    HSTX;
    volatile    uint32_t    I2C0;
    volatile    uint32_t    I2C1;
    volatile    uint32_t    PWM;
    volatile    uint32_t    SPI0;
    volatile    uint32_t    SPI1;
    volatile    uint32_t    TIMER0;
    volatile    uint32_t    TIMER1;
    volatile    uint32_t    UART0;
    volatile    uint32_t    UART1;
    volatile    uint32_t    OTP;
    volatile    uint32_t    TBMAN;
    volatile    uint32_t    POWMAN;
    volatile    uint32_t    TRNG;
    volatile    uint32_t    SHA256;
    volatile    uint32_t    SYSCFG;
    volatile    uint32_t    CLOCKS;
    volatile    uint32_t    XOSC;
    volatile    uint32_t    ROSC;
    volatile    uint32_t    PLL_SYS;
    volatile    uint32_t    PLL_USB;
    volatile    uint32_t    TICKS;
    volatile    uint32_t    WATCHDOG;
    volatile    uint32_t    RSM;
    volatile    uint32_t    XIP_CTRL;
    volatile    uint32_t    XIP_QMI;
    volatile    uint32_t    XIP_AUX;
} ACCESSCTRL_TypeDef;

#ifdef __cplusplus
#define ACCESSCTRL_NS   reinterpret_cast<ACCESSCTRL_TypeDef *>(0x40060000U)
#define ACCESSCTRL_S    reinterpret_cast<ACCESSCTRL_TypeDef *>(0x40060000U)
#else
#define ACCESSCTRL_NS   ((ACCESSCTRL_TypeDef *)0x40060000U)
#define ACCESSCTRL_S    ((ACCESSCTRL_TypeDef *)0x40060000U)
#endif

// LOCK Configuration

#define ACCESSCTRL_LOCK_CORE0                   (0x1U<<0U)
#define ACCESSCTRL_LOCK_CORE1                   (0x1U<<1U)
#define ACCESSCTRL_LOCK_DMA                     (0x1U<<2U)
#define ACCESSCTRL_LOCK_DEBUG                   (0x1U<<3U)

// FORCE_CORE_NS Configuration

#define ACCESSCTRL_FORCE_CORE_NS_CORE1          (0x1U<<1U)

// CFGRESET Configuration

#define ACCESSCTRL_CFGRESET_CFGRESET            (0x1U<<0U)

// GPIO_NSMASK0 Configuration

#define ACCESSCTRL_GPIO_NSMASK0_GPIO_NSMASK0    (0xFFFFFFFFU<<0U)
#define ACCESSCTRL_GPIO_NSMASK0_GPIO_NSMASK0_0  (0x1U<<0U)

// GPIO_NSMASK1 Configuration

#define ACCESSCTRL_GPIO_NSMASK1_GPIO            (0xFFFFU<<0U)
#define ACCESSCTRL_GPIO_NSMASK1_GPIO_0          (0x1U<<0U)
#define ACCESSCTRL_GPIO_NSMASK1_USB_DP          (0x1U<<24U)
#define ACCESSCTRL_GPIO_NSMASK1_USB_DM          (0x1U<<25U)
#define ACCESSCTRL_GPIO_NSMASK1_QSPI_SCK        (0x1U<<26U)
#define ACCESSCTRL_GPIO_NSMASK1_QSPI_CSN        (0x1U<<27U)
#define ACCESSCTRL_GPIO_NSMASK1_QSPI_SD         (0xFU<<28U)
#define ACCESSCTRL_GPIO_NSMASK1_QSPI_SD_0       (0x1U<<28U)

// ROM Configuration

#define ACCESSCTRL_ROM_NSU                      (0x1U<<0U)
#define ACCESSCTRL_ROM_NSP                      (0x1U<<1U)
#define ACCESSCTRL_ROM_SU                       (0x1U<<2U)
#define ACCESSCTRL_ROM_SP                       (0x1U<<3U)
#define ACCESSCTRL_ROM_CORE0                    (0x1U<<4U)
#define ACCESSCTRL_ROM_CORE1                    (0x1U<<5U)
#define ACCESSCTRL_ROM_DMA                      (0x1U<<6U)
#define ACCESSCTRL_ROM_DBG                      (0x1U<<7U)

// XIP_MAIN Configuration

#define ACCESSCTRL_XIP_MAIN_NSU                 (0x1U<<0U)
#define ACCESSCTRL_XIP_MAIN_NSP                 (0x1U<<1U)
#define ACCESSCTRL_XIP_MAIN_SU                  (0x1U<<2U)
#define ACCESSCTRL_XIP_MAIN_SP                  (0x1U<<3U)
#define ACCESSCTRL_XIP_MAIN_CORE0               (0x1U<<4U)
#define ACCESSCTRL_XIP_MAIN_CORE1               (0x1U<<5U)
#define ACCESSCTRL_XIP_MAIN_DMA                 (0x1U<<6U)
#define ACCESSCTRL_XIP_MAIN_DBG                 (0x1U<<7U)

// SRAM0 Configuration

#define ACCESSCTRL_SRAM0_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM0_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM0_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM0_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM0_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM0_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM0_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM0_DBG                    (0x1U<<7U)

// SRAM1 Configuration

#define ACCESSCTRL_SRAM1_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM1_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM1_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM1_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM1_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM1_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM1_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM1_DBG                    (0x1U<<7U)

// SRAM2 Configuration

#define ACCESSCTRL_SRAM2_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM2_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM2_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM2_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM2_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM2_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM2_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM2_DBG                    (0x1U<<7U)

// SRAM3 Configuration

#define ACCESSCTRL_SRAM3_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM3_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM3_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM3_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM3_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM3_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM3_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM3_DBG                    (0x1U<<7U)

// SRAM4 Configuration

#define ACCESSCTRL_SRAM4_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM4_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM4_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM4_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM4_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM4_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM4_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM4_DBG                    (0x1U<<7U)

// SRAM5 Configuration

#define ACCESSCTRL_SRAM5_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM5_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM5_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM5_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM5_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM5_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM5_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM5_DBG                    (0x1U<<7U)

// SRAM6 Configuration

#define ACCESSCTRL_SRAM6_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM6_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM6_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM6_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM6_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM6_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM6_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM6_DBG                    (0x1U<<7U)

// SRAM7 Configuration

#define ACCESSCTRL_SRAM7_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM7_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM7_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM7_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM7_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM7_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM7_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM7_DBG                    (0x1U<<7U)

// SRAM8 Configuration

#define ACCESSCTRL_SRAM8_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM8_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM8_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM8_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM8_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM8_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM8_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM8_DBG                    (0x1U<<7U)

// SRAM9 Configuration

#define ACCESSCTRL_SRAM9_NSU                    (0x1U<<0U)
#define ACCESSCTRL_SRAM9_NSP                    (0x1U<<1U)
#define ACCESSCTRL_SRAM9_SU                     (0x1U<<2U)
#define ACCESSCTRL_SRAM9_SP                     (0x1U<<3U)
#define ACCESSCTRL_SRAM9_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_SRAM9_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_SRAM9_DMA                    (0x1U<<6U)
#define ACCESSCTRL_SRAM9_DBG                    (0x1U<<7U)

// DMA Configuration

#define ACCESSCTRL_DMA_NSU                      (0x1U<<0U)
#define ACCESSCTRL_DMA_NSP                      (0x1U<<1U)
#define ACCESSCTRL_DMA_SU                       (0x1U<<2U)
#define ACCESSCTRL_DMA_SP                       (0x1U<<3U)
#define ACCESSCTRL_DMA_CORE0                    (0x1U<<4U)
#define ACCESSCTRL_DMA_CORE1                    (0x1U<<5U)
#define ACCESSCTRL_DMA_DMA                      (0x1U<<6U)
#define ACCESSCTRL_DMA_DBG                      (0x1U<<7U)

// USBCTRL Configuration

#define ACCESSCTRL_USBCTRL_NSU                  (0x1U<<0U)
#define ACCESSCTRL_USBCTRL_NSP                  (0x1U<<1U)
#define ACCESSCTRL_USBCTRL_SU                   (0x1U<<2U)
#define ACCESSCTRL_USBCTRL_SP                   (0x1U<<3U)
#define ACCESSCTRL_USBCTRL_CORE0                (0x1U<<4U)
#define ACCESSCTRL_USBCTRL_CORE1                (0x1U<<5U)
#define ACCESSCTRL_USBCTRL_DMA                  (0x1U<<6U)
#define ACCESSCTRL_USBCTRL_DBG                  (0x1U<<7U)

// PIO0 Configuration

#define ACCESSCTRL_PIO0_NSU                     (0x1U<<0U)
#define ACCESSCTRL_PIO0_NSP                     (0x1U<<1U)
#define ACCESSCTRL_PIO0_SU                      (0x1U<<2U)
#define ACCESSCTRL_PIO0_SP                      (0x1U<<3U)
#define ACCESSCTRL_PIO0_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_PIO0_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_PIO0_DMA                     (0x1U<<6U)
#define ACCESSCTRL_PIO0_DBG                     (0x1U<<7U)

// PIO1 Configuration

#define ACCESSCTRL_PIO1_NSU                     (0x1U<<0U)
#define ACCESSCTRL_PIO1_NSP                     (0x1U<<1U)
#define ACCESSCTRL_PIO1_SU                      (0x1U<<2U)
#define ACCESSCTRL_PIO1_SP                      (0x1U<<3U)
#define ACCESSCTRL_PIO1_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_PIO1_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_PIO1_DMA                     (0x1U<<6U)
#define ACCESSCTRL_PIO1_DBG                     (0x1U<<7U)

// PIO2 Configuration

#define ACCESSCTRL_PIO2_NSU                     (0x1U<<0U)
#define ACCESSCTRL_PIO2_NSP                     (0x1U<<1U)
#define ACCESSCTRL_PIO2_SU                      (0x1U<<2U)
#define ACCESSCTRL_PIO2_SP                      (0x1U<<3U)
#define ACCESSCTRL_PIO2_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_PIO2_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_PIO2_DMA                     (0x1U<<6U)
#define ACCESSCTRL_PIO2_DBG                     (0x1U<<7U)

// CORESIGHT_TRACE Configuration

#define ACCESSCTRL_CORESIGHT_TRACE_NSU          (0x1U<<0U)
#define ACCESSCTRL_CORESIGHT_TRACE_NSP          (0x1U<<1U)
#define ACCESSCTRL_CORESIGHT_TRACE_SU           (0x1U<<2U)
#define ACCESSCTRL_CORESIGHT_TRACE_SP           (0x1U<<3U)
#define ACCESSCTRL_CORESIGHT_TRACE_CORE0        (0x1U<<4U)
#define ACCESSCTRL_CORESIGHT_TRACE_CORE1        (0x1U<<5U)
#define ACCESSCTRL_CORESIGHT_TRACE_DMA          (0x1U<<6U)
#define ACCESSCTRL_CORESIGHT_TRACE_DBG          (0x1U<<7U)

// CORESIGHT_PERIPH Configuration

#define ACCESSCTRL_CORESIGHT_PERIPH_NSU         (0x1U<<0U)
#define ACCESSCTRL_CORESIGHT_PERIPH_NSP         (0x1U<<1U)
#define ACCESSCTRL_CORESIGHT_PERIPH_SU          (0x1U<<2U)
#define ACCESSCTRL_CORESIGHT_PERIPH_SP          (0x1U<<3U)
#define ACCESSCTRL_CORESIGHT_PERIPH_CORE0       (0x1U<<4U)
#define ACCESSCTRL_CORESIGHT_PERIPH_CORE1       (0x1U<<5U)
#define ACCESSCTRL_CORESIGHT_PERIPH_DMA         (0x1U<<6U)
#define ACCESSCTRL_CORESIGHT_PERIPH_DBG         (0x1U<<7U)

// SYSINFO Configuration

#define ACCESSCTRL_SYSINFO_NSU                  (0x1U<<0U)
#define ACCESSCTRL_SYSINFO_NSP                  (0x1U<<1U)
#define ACCESSCTRL_SYSINFO_SU                   (0x1U<<2U)
#define ACCESSCTRL_SYSINFO_SP                   (0x1U<<3U)
#define ACCESSCTRL_SYSINFO_CORE0                (0x1U<<4U)
#define ACCESSCTRL_SYSINFO_CORE1                (0x1U<<5U)
#define ACCESSCTRL_SYSINFO_DMA                  (0x1U<<6U)
#define ACCESSCTRL_SYSINFO_DBG                  (0x1U<<7U)

// RESETS Configuration

#define ACCESSCTRL_RESETS_NSU                   (0x1U<<0U)
#define ACCESSCTRL_RESETS_NSP                   (0x1U<<1U)
#define ACCESSCTRL_RESETS_SU                    (0x1U<<2U)
#define ACCESSCTRL_RESETS_SP                    (0x1U<<3U)
#define ACCESSCTRL_RESETS_CORE0                 (0x1U<<4U)
#define ACCESSCTRL_RESETS_CORE1                 (0x1U<<5U)
#define ACCESSCTRL_RESETS_DMA                   (0x1U<<6U)
#define ACCESSCTRL_RESETS_DBG                   (0x1U<<7U)

// IO_BANK0 Configuration

#define ACCESSCTRL_IO_BANK0_NSU                 (0x1U<<0U)
#define ACCESSCTRL_IO_BANK0_NSP                 (0x1U<<1U)
#define ACCESSCTRL_IO_BANK0_SU                  (0x1U<<2U)
#define ACCESSCTRL_IO_BANK0_SP                  (0x1U<<3U)
#define ACCESSCTRL_IO_BANK0_CORE0               (0x1U<<4U)
#define ACCESSCTRL_IO_BANK0_CORE1               (0x1U<<5U)
#define ACCESSCTRL_IO_BANK0_DMA                 (0x1U<<6U)
#define ACCESSCTRL_IO_BANK0_DBG                 (0x1U<<7U)

// IO_BANK1 Configuration

#define ACCESSCTRL_IO_BANK1_NSU                 (0x1U<<0U)
#define ACCESSCTRL_IO_BANK1_NSP                 (0x1U<<1U)
#define ACCESSCTRL_IO_BANK1_SU                  (0x1U<<2U)
#define ACCESSCTRL_IO_BANK1_SP                  (0x1U<<3U)
#define ACCESSCTRL_IO_BANK1_CORE0               (0x1U<<4U)
#define ACCESSCTRL_IO_BANK1_CORE1               (0x1U<<5U)
#define ACCESSCTRL_IO_BANK1_DMA                 (0x1U<<6U)
#define ACCESSCTRL_IO_BANK1_DBG                 (0x1U<<7U)

// PADS_BANK0 Configuration

#define ACCESSCTRL_PADS_BANK0_NSU               (0x1U<<0U)
#define ACCESSCTRL_PADS_BANK0_NSP               (0x1U<<1U)
#define ACCESSCTRL_PADS_BANK0_SU                (0x1U<<2U)
#define ACCESSCTRL_PADS_BANK0_SP                (0x1U<<3U)
#define ACCESSCTRL_PADS_BANK0_CORE0             (0x1U<<4U)
#define ACCESSCTRL_PADS_BANK0_CORE1             (0x1U<<5U)
#define ACCESSCTRL_PADS_BANK0_DMA               (0x1U<<6U)
#define ACCESSCTRL_PADS_BANK0_DBG               (0x1U<<7U)

// PADS_QSPI Configuration

#define ACCESSCTRL_PADS_QSPI_NSU                (0x1U<<0U)
#define ACCESSCTRL_PADS_QSPI_NSP                (0x1U<<1U)
#define ACCESSCTRL_PADS_QSPI_SU                 (0x1U<<2U)
#define ACCESSCTRL_PADS_QSPI_SP                 (0x1U<<3U)
#define ACCESSCTRL_PADS_QSPI_CORE0              (0x1U<<4U)
#define ACCESSCTRL_PADS_QSPI_CORE1              (0x1U<<5U)
#define ACCESSCTRL_PADS_QSPI_DMA                (0x1U<<6U)
#define ACCESSCTRL_PADS_QSPI_DBG                (0x1U<<7U)

// BUSCTRL Configuration

#define ACCESSCTRL_BUSCTRL_NSU                  (0x1U<<0U)
#define ACCESSCTRL_BUSCTRL_NSP                  (0x1U<<1U)
#define ACCESSCTRL_BUSCTRL_SU                   (0x1U<<2U)
#define ACCESSCTRL_BUSCTRL_SP                   (0x1U<<3U)
#define ACCESSCTRL_BUSCTRL_CORE0                (0x1U<<4U)
#define ACCESSCTRL_BUSCTRL_CORE1                (0x1U<<5U)
#define ACCESSCTRL_BUSCTRL_DMA                  (0x1U<<6U)
#define ACCESSCTRL_BUSCTRL_DBG                  (0x1U<<7U)

// ADC0 Configuration

#define ACCESSCTRL_ADC0_NSU                     (0x1U<<0U)
#define ACCESSCTRL_ADC0_NSP                     (0x1U<<1U)
#define ACCESSCTRL_ADC0_SU                      (0x1U<<2U)
#define ACCESSCTRL_ADC0_SP                      (0x1U<<3U)
#define ACCESSCTRL_ADC0_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_ADC0_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_ADC0_DMA                     (0x1U<<6U)
#define ACCESSCTRL_ADC0_DBG                     (0x1U<<7U)

// HSTX Configuration

#define ACCESSCTRL_HSTX_NSU                     (0x1U<<0U)
#define ACCESSCTRL_HSTX_NSP                     (0x1U<<1U)
#define ACCESSCTRL_HSTX_SU                      (0x1U<<2U)
#define ACCESSCTRL_HSTX_SP                      (0x1U<<3U)
#define ACCESSCTRL_HSTX_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_HSTX_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_HSTX_DMA                     (0x1U<<6U)
#define ACCESSCTRL_HSTX_DBG                     (0x1U<<7U)

// I2C0 Configuration

#define ACCESSCTRL_I2C0_NSU                     (0x1U<<0U)
#define ACCESSCTRL_I2C0_NSP                     (0x1U<<1U)
#define ACCESSCTRL_I2C0_SU                      (0x1U<<2U)
#define ACCESSCTRL_I2C0_SP                      (0x1U<<3U)
#define ACCESSCTRL_I2C0_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_I2C0_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_I2C0_DMA                     (0x1U<<6U)
#define ACCESSCTRL_I2C0_DBG                     (0x1U<<7U)

// I2C1 Configuration

#define ACCESSCTRL_I2C1_NSU                     (0x1U<<0U)
#define ACCESSCTRL_I2C1_NSP                     (0x1U<<1U)
#define ACCESSCTRL_I2C1_SU                      (0x1U<<2U)
#define ACCESSCTRL_I2C1_SP                      (0x1U<<3U)
#define ACCESSCTRL_I2C1_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_I2C1_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_I2C1_DMA                     (0x1U<<6U)
#define ACCESSCTRL_I2C1_DBG                     (0x1U<<7U)

// PWM Configuration

#define ACCESSCTRL_PWM_NSU                      (0x1U<<0U)
#define ACCESSCTRL_PWM_NSP                      (0x1U<<1U)
#define ACCESSCTRL_PWM_SU                       (0x1U<<2U)
#define ACCESSCTRL_PWM_SP                       (0x1U<<3U)
#define ACCESSCTRL_PWM_CORE0                    (0x1U<<4U)
#define ACCESSCTRL_PWM_CORE1                    (0x1U<<5U)
#define ACCESSCTRL_PWM_DMA                      (0x1U<<6U)
#define ACCESSCTRL_PWM_DBG                      (0x1U<<7U)

// SPI0 Configuration

#define ACCESSCTRL_SPI0_NSU                     (0x1U<<0U)
#define ACCESSCTRL_SPI0_NSP                     (0x1U<<1U)
#define ACCESSCTRL_SPI0_SU                      (0x1U<<2U)
#define ACCESSCTRL_SPI0_SP                      (0x1U<<3U)
#define ACCESSCTRL_SPI0_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_SPI0_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_SPI0_DMA                     (0x1U<<6U)
#define ACCESSCTRL_SPI0_DBG                     (0x1U<<7U)

// SPI1 Configuration

#define ACCESSCTRL_SPI1_NSU                     (0x1U<<0U)
#define ACCESSCTRL_SPI1_NSP                     (0x1U<<1U)
#define ACCESSCTRL_SPI1_SU                      (0x1U<<2U)
#define ACCESSCTRL_SPI1_SP                      (0x1U<<3U)
#define ACCESSCTRL_SPI1_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_SPI1_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_SPI1_DMA                     (0x1U<<6U)
#define ACCESSCTRL_SPI1_DBG                     (0x1U<<7U)

// TIMER0 Configuration

#define ACCESSCTRL_TIMER0_NSU                   (0x1U<<0U)
#define ACCESSCTRL_TIMER0_NSP                   (0x1U<<1U)
#define ACCESSCTRL_TIMER0_SU                    (0x1U<<2U)
#define ACCESSCTRL_TIMER0_SP                    (0x1U<<3U)
#define ACCESSCTRL_TIMER0_CORE0                 (0x1U<<4U)
#define ACCESSCTRL_TIMER0_CORE1                 (0x1U<<5U)
#define ACCESSCTRL_TIMER0_DMA                   (0x1U<<6U)
#define ACCESSCTRL_TIMER0_DBG                   (0x1U<<7U)

// TIMER1 Configuration

#define ACCESSCTRL_TIMER1_NSU                   (0x1U<<0U)
#define ACCESSCTRL_TIMER1_NSP                   (0x1U<<1U)
#define ACCESSCTRL_TIMER1_SU                    (0x1U<<2U)
#define ACCESSCTRL_TIMER1_SP                    (0x1U<<3U)
#define ACCESSCTRL_TIMER1_CORE0                 (0x1U<<4U)
#define ACCESSCTRL_TIMER1_CORE1                 (0x1U<<5U)
#define ACCESSCTRL_TIMER1_DMA                   (0x1U<<6U)
#define ACCESSCTRL_TIMER1_DBG                   (0x1U<<7U)

// UART0 Configuration

#define ACCESSCTRL_UART0_NSU                    (0x1U<<0U)
#define ACCESSCTRL_UART0_NSP                    (0x1U<<1U)
#define ACCESSCTRL_UART0_SU                     (0x1U<<2U)
#define ACCESSCTRL_UART0_SP                     (0x1U<<3U)
#define ACCESSCTRL_UART0_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_UART0_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_UART0_DMA                    (0x1U<<6U)
#define ACCESSCTRL_UART0_DBG                    (0x1U<<7U)

// UART1 Configuration

#define ACCESSCTRL_UART1_NSU                    (0x1U<<0U)
#define ACCESSCTRL_UART1_NSP                    (0x1U<<1U)
#define ACCESSCTRL_UART1_SU                     (0x1U<<2U)
#define ACCESSCTRL_UART1_SP                     (0x1U<<3U)
#define ACCESSCTRL_UART1_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_UART1_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_UART1_DMA                    (0x1U<<6U)
#define ACCESSCTRL_UART1_DBG                    (0x1U<<7U)

// OTP Configuration

#define ACCESSCTRL_OTP_NSU                      (0x1U<<0U)
#define ACCESSCTRL_OTP_NSP                      (0x1U<<1U)
#define ACCESSCTRL_OTP_SU                       (0x1U<<2U)
#define ACCESSCTRL_OTP_SP                       (0x1U<<3U)
#define ACCESSCTRL_OTP_CORE0                    (0x1U<<4U)
#define ACCESSCTRL_OTP_CORE1                    (0x1U<<5U)
#define ACCESSCTRL_OTP_DMA                      (0x1U<<6U)
#define ACCESSCTRL_OTP_DBG                      (0x1U<<7U)

// TBMAN Configuration

#define ACCESSCTRL_TBMAN_NSU                    (0x1U<<0U)
#define ACCESSCTRL_TBMAN_NSP                    (0x1U<<1U)
#define ACCESSCTRL_TBMAN_SU                     (0x1U<<2U)
#define ACCESSCTRL_TBMAN_SP                     (0x1U<<3U)
#define ACCESSCTRL_TBMAN_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_TBMAN_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_TBMAN_DMA                    (0x1U<<6U)
#define ACCESSCTRL_TBMAN_DBG                    (0x1U<<7U)

// POWMAN Configuration

#define ACCESSCTRL_POWMAN_NSU                   (0x1U<<0U)
#define ACCESSCTRL_POWMAN_NSP                   (0x1U<<1U)
#define ACCESSCTRL_POWMAN_SU                    (0x1U<<2U)
#define ACCESSCTRL_POWMAN_SP                    (0x1U<<3U)
#define ACCESSCTRL_POWMAN_CORE0                 (0x1U<<4U)
#define ACCESSCTRL_POWMAN_CORE1                 (0x1U<<5U)
#define ACCESSCTRL_POWMAN_DMA                   (0x1U<<6U)
#define ACCESSCTRL_POWMAN_DBG                   (0x1U<<7U)

// TRNG Configuration

#define ACCESSCTRL_TRNG_NSU                     (0x1U<<0U)
#define ACCESSCTRL_TRNG_NSP                     (0x1U<<1U)
#define ACCESSCTRL_TRNG_SU                      (0x1U<<2U)
#define ACCESSCTRL_TRNG_SP                      (0x1U<<3U)
#define ACCESSCTRL_TRNG_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_TRNG_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_TRNG_DMA                     (0x1U<<6U)
#define ACCESSCTRL_TRNG_DBG                     (0x1U<<7U)

// SHA256 Configuration

#define ACCESSCTRL_SHA256_NSU                   (0x1U<<0U)
#define ACCESSCTRL_SHA256_NSP                   (0x1U<<1U)
#define ACCESSCTRL_SHA256_SU                    (0x1U<<2U)
#define ACCESSCTRL_SHA256_SP                    (0x1U<<3U)
#define ACCESSCTRL_SHA256_CORE0                 (0x1U<<4U)
#define ACCESSCTRL_SHA256_CORE1                 (0x1U<<5U)
#define ACCESSCTRL_SHA256_DMA                   (0x1U<<6U)
#define ACCESSCTRL_SHA256_DBG                   (0x1U<<7U)

// SYSCFG Configuration

#define ACCESSCTRL_SYSCFG_NSU                   (0x1U<<0U)
#define ACCESSCTRL_SYSCFG_NSP                   (0x1U<<1U)
#define ACCESSCTRL_SYSCFG_SU                    (0x1U<<2U)
#define ACCESSCTRL_SYSCFG_SP                    (0x1U<<3U)
#define ACCESSCTRL_SYSCFG_CORE0                 (0x1U<<4U)
#define ACCESSCTRL_SYSCFG_CORE1                 (0x1U<<5U)
#define ACCESSCTRL_SYSCFG_DMA                   (0x1U<<6U)
#define ACCESSCTRL_SYSCFG_DBG                   (0x1U<<7U)

// CLOCKS Configuration

#define ACCESSCTRL_CLOCKS_NSU                   (0x1U<<0U)
#define ACCESSCTRL_CLOCKS_NSP                   (0x1U<<1U)
#define ACCESSCTRL_CLOCKS_SU                    (0x1U<<2U)
#define ACCESSCTRL_CLOCKS_SP                    (0x1U<<3U)
#define ACCESSCTRL_CLOCKS_CORE0                 (0x1U<<4U)
#define ACCESSCTRL_CLOCKS_CORE1                 (0x1U<<5U)
#define ACCESSCTRL_CLOCKS_DMA                   (0x1U<<6U)
#define ACCESSCTRL_CLOCKS_DBG                   (0x1U<<7U)

// XOSC Configuration

#define ACCESSCTRL_XOSC_NSU                     (0x1U<<0U)
#define ACCESSCTRL_XOSC_NSP                     (0x1U<<1U)
#define ACCESSCTRL_XOSC_SU                      (0x1U<<2U)
#define ACCESSCTRL_XOSC_SP                      (0x1U<<3U)
#define ACCESSCTRL_XOSC_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_XOSC_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_XOSC_DMA                     (0x1U<<6U)
#define ACCESSCTRL_XOSC_DBG                     (0x1U<<7U)

// ROSC Configuration

#define ACCESSCTRL_ROSC_NSU                     (0x1U<<0U)
#define ACCESSCTRL_ROSC_NSP                     (0x1U<<1U)
#define ACCESSCTRL_ROSC_SU                      (0x1U<<2U)
#define ACCESSCTRL_ROSC_SP                      (0x1U<<3U)
#define ACCESSCTRL_ROSC_CORE0                   (0x1U<<4U)
#define ACCESSCTRL_ROSC_CORE1                   (0x1U<<5U)
#define ACCESSCTRL_ROSC_DMA                     (0x1U<<6U)
#define ACCESSCTRL_ROSC_DBG                     (0x1U<<7U)

// PLL_SYS Configuration

#define ACCESSCTRL_PLL_SYS_NSU                  (0x1U<<0U)
#define ACCESSCTRL_PLL_SYS_NSP                  (0x1U<<1U)
#define ACCESSCTRL_PLL_SYS_SU                   (0x1U<<2U)
#define ACCESSCTRL_PLL_SYS_SP                   (0x1U<<3U)
#define ACCESSCTRL_PLL_SYS_CORE0                (0x1U<<4U)
#define ACCESSCTRL_PLL_SYS_CORE1                (0x1U<<5U)
#define ACCESSCTRL_PLL_SYS_DMA                  (0x1U<<6U)
#define ACCESSCTRL_PLL_SYS_DBG                  (0x1U<<7U)

// PLL_USB Configuration

#define ACCESSCTRL_PLL_USB_NSU                  (0x1U<<0U)
#define ACCESSCTRL_PLL_USB_NSP                  (0x1U<<1U)
#define ACCESSCTRL_PLL_USB_SU                   (0x1U<<2U)
#define ACCESSCTRL_PLL_USB_SP                   (0x1U<<3U)
#define ACCESSCTRL_PLL_USB_CORE0                (0x1U<<4U)
#define ACCESSCTRL_PLL_USB_CORE1                (0x1U<<5U)
#define ACCESSCTRL_PLL_USB_DMA                  (0x1U<<6U)
#define ACCESSCTRL_PLL_USB_DBG                  (0x1U<<7U)

// TICKS Configuration

#define ACCESSCTRL_TICKS_NSU                    (0x1U<<0U)
#define ACCESSCTRL_TICKS_NSP                    (0x1U<<1U)
#define ACCESSCTRL_TICKS_SU                     (0x1U<<2U)
#define ACCESSCTRL_TICKS_SP                     (0x1U<<3U)
#define ACCESSCTRL_TICKS_CORE0                  (0x1U<<4U)
#define ACCESSCTRL_TICKS_CORE1                  (0x1U<<5U)
#define ACCESSCTRL_TICKS_DMA                    (0x1U<<6U)
#define ACCESSCTRL_TICKS_DBG                    (0x1U<<7U)

// WATCHDOG Configuration

#define ACCESSCTRL_WATCHDOG_NSU                 (0x1U<<0U)
#define ACCESSCTRL_WATCHDOG_NSP                 (0x1U<<1U)
#define ACCESSCTRL_WATCHDOG_SU                  (0x1U<<2U)
#define ACCESSCTRL_WATCHDOG_SP                  (0x1U<<3U)
#define ACCESSCTRL_WATCHDOG_CORE0               (0x1U<<4U)
#define ACCESSCTRL_WATCHDOG_CORE1               (0x1U<<5U)
#define ACCESSCTRL_WATCHDOG_DMA                 (0x1U<<6U)
#define ACCESSCTRL_WATCHDOG_DBG                 (0x1U<<7U)

// RSM Configuration

#define ACCESSCTRL_RSM_NSU                      (0x1U<<0U)
#define ACCESSCTRL_RSM_NSP                      (0x1U<<1U)
#define ACCESSCTRL_RSM_SU                       (0x1U<<2U)
#define ACCESSCTRL_RSM_SP                       (0x1U<<3U)
#define ACCESSCTRL_RSM_CORE0                    (0x1U<<4U)
#define ACCESSCTRL_RSM_CORE1                    (0x1U<<5U)
#define ACCESSCTRL_RSM_DMA                      (0x1U<<6U)
#define ACCESSCTRL_RSM_DBG                      (0x1U<<7U)

// XIP_CTRL Configuration

#define ACCESSCTRL_XIP_CTRL_NSU                 (0x1U<<0U)
#define ACCESSCTRL_XIP_CTRL_NSP                 (0x1U<<1U)
#define ACCESSCTRL_XIP_CTRL_SU                  (0x1U<<2U)
#define ACCESSCTRL_XIP_CTRL_SP                  (0x1U<<3U)
#define ACCESSCTRL_XIP_CTRL_CORE0               (0x1U<<4U)
#define ACCESSCTRL_XIP_CTRL_CORE1               (0x1U<<5U)
#define ACCESSCTRL_XIP_CTRL_DMA                 (0x1U<<6U)
#define ACCESSCTRL_XIP_CTRL_DBG                 (0x1U<<7U)

// XIP_QMI Configuration

#define ACCESSCTRL_XIP_QMI_NSU                  (0x1U<<0U)
#define ACCESSCTRL_XIP_QMI_NSP                  (0x1U<<1U)
#define ACCESSCTRL_XIP_QMI_SU                   (0x1U<<2U)
#define ACCESSCTRL_XIP_QMI_SP                   (0x1U<<3U)
#define ACCESSCTRL_XIP_QMI_CORE0                (0x1U<<4U)
#define ACCESSCTRL_XIP_QMI_CORE1                (0x1U<<5U)
#define ACCESSCTRL_XIP_QMI_DMA                  (0x1U<<6U)
#define ACCESSCTRL_XIP_QMI_DBG                  (0x1U<<7U)

// XIP_AUX Configuration

#define ACCESSCTRL_XIP_AUX_NSU                  (0x1U<<0U)
#define ACCESSCTRL_XIP_AUX_NSP                  (0x1U<<1U)
#define ACCESSCTRL_XIP_AUX_SU                   (0x1U<<2U)
#define ACCESSCTRL_XIP_AUX_SP                   (0x1U<<3U)
#define ACCESSCTRL_XIP_AUX_CORE0                (0x1U<<4U)
#define ACCESSCTRL_XIP_AUX_CORE1                (0x1U<<5U)
#define ACCESSCTRL_XIP_AUX_DMA                  (0x1U<<6U)
#define ACCESSCTRL_XIP_AUX_DBG                  (0x1U<<7U)
