/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_psm equates.
 */

#pragma once

#include    <stdint.h>

// PSM address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    FRCE_ON;
    volatile    uint32_t    FRCE_OFF;
    volatile    uint32_t    WDSEL;
    volatile    uint32_t    DONE;
} PSM_TypeDef;

#ifdef __cplusplus
#define PSM_NS  reinterpret_cast<PSM_TypeDef *>(0x40018000U)
#define PSM_S   reinterpret_cast<PSM_TypeDef *>(0x40018000U)
#else
#define PSM_NS  ((PSM_TypeDef *)0x40018000U)
#define PSM_S   ((PSM_TypeDef *)0x40018000U)
#endif

// FRCE_ON Configuration

#define PSM_FRCE_ON_PROC_COLD   (0x1U<<0)
#define PSM_FRCE_ON_OTP         (0x1U<<1)
#define PSM_FRCE_ON_ROSC        (0x1U<<2)
#define PSM_FRCE_ON_XOSC        (0x1U<<3)
#define PSM_FRCE_ON_RESETS      (0x1U<<4)
#define PSM_FRCE_ON_CLOCKS      (0x1U<<5)
#define PSM_FRCE_ON_PSM_READY   (0x1U<<6)
#define PSM_FRCE_ON_BUSFABRIC   (0x1U<<7)
#define PSM_FRCE_ON_ROM         (0x1U<<8)
#define PSM_FRCE_ON_BOOTRAM     (0x1U<<9)
#define PSM_FRCE_ON_SRAM0       (0x1U<<10)
#define PSM_FRCE_ON_SRAM1       (0x1U<<11)
#define PSM_FRCE_ON_SRAM2       (0x1U<<12)
#define PSM_FRCE_ON_SRAM3       (0x1U<<13)
#define PSM_FRCE_ON_SRAM4       (0x1U<<14)
#define PSM_FRCE_ON_SRAM5       (0x1U<<15)
#define PSM_FRCE_ON_SRAM6       (0x1U<<16)
#define PSM_FRCE_ON_SRAM7       (0x1U<<17)
#define PSM_FRCE_ON_SRAM8       (0x1U<<18)
#define PSM_FRCE_ON_SRAM9       (0x1U<<19)
#define PSM_FRCE_ON_XIP         (0x1U<<20)
#define PSM_FRCE_ON_SIO         (0x1U<<21)
#define PSM_FRCE_ON_ACCESSCTRL  (0x1U<<22)
#define PSM_FRCE_ON_PROC0       (0x1U<<23)
#define PSM_FRCE_ON_PROC1       (0x1U<<24)

// FRCE_OFF Configuration

#define PSM_FRCE_OFF_PROC_COLD  (0x1U<<0)
#define PSM_FRCE_OFF_OTP        (0x1U<<1)
#define PSM_FRCE_OFF_ROSC       (0x1U<<2)
#define PSM_FRCE_OFF_XOSC       (0x1U<<3)
#define PSM_FRCE_OFF_RESETS     (0x1U<<4)
#define PSM_FRCE_OFF_CLOCKS     (0x1U<<5)
#define PSM_FRCE_OFF_PSM_READY  (0x1U<<6)
#define PSM_FRCE_OFF_BUSFABRIC  (0x1U<<7)
#define PSM_FRCE_OFF_ROM        (0x1U<<8)
#define PSM_FRCE_OFF_BOOTRAM    (0x1U<<9)
#define PSM_FRCE_OFF_SRAM0      (0x1U<<10)
#define PSM_FRCE_OFF_SRAM1      (0x1U<<11)
#define PSM_FRCE_OFF_SRAM2      (0x1U<<12)
#define PSM_FRCE_OFF_SRAM3      (0x1U<<13)
#define PSM_FRCE_OFF_SRAM4      (0x1U<<14)
#define PSM_FRCE_OFF_SRAM5      (0x1U<<15)
#define PSM_FRCE_OFF_SRAM6      (0x1U<<16)
#define PSM_FRCE_OFF_SRAM7      (0x1U<<17)
#define PSM_FRCE_OFF_SRAM8      (0x1U<<18)
#define PSM_FRCE_OFF_SRAM9      (0x1U<<19)
#define PSM_FRCE_OFF_XIP        (0x1U<<20)
#define PSM_FRCE_OFF_SIO        (0x1U<<21)
#define PSM_FRCE_OFF_ACCESSCTRL (0x1U<<22)
#define PSM_FRCE_OFF_PROC0      (0x1U<<23)
#define PSM_FRCE_OFF_PROC1      (0x1U<<24)

// WDSEL Configuration

#define PSM_WDSEL_PROC_COLD     (0x1U<<0)
#define PSM_WDSEL_OTP           (0x1U<<1)
#define PSM_WDSEL_ROSC          (0x1U<<2)
#define PSM_WDSEL_XOSC          (0x1U<<3)
#define PSM_WDSEL_RESETS        (0x1U<<4)
#define PSM_WDSEL_CLOCKS        (0x1U<<5)
#define PSM_WDSEL_PSM_READY     (0x1U<<6)
#define PSM_WDSEL_BUSFABRIC     (0x1U<<7)
#define PSM_WDSEL_ROM           (0x1U<<8)
#define PSM_WDSEL_BOOTRAM       (0x1U<<9)
#define PSM_WDSEL_SRAM0         (0x1U<<10)
#define PSM_WDSEL_SRAM1         (0x1U<<11)
#define PSM_WDSEL_SRAM2         (0x1U<<12)
#define PSM_WDSEL_SRAM3         (0x1U<<13)
#define PSM_WDSEL_SRAM4         (0x1U<<14)
#define PSM_WDSEL_SRAM5         (0x1U<<15)
#define PSM_WDSEL_SRAM6         (0x1U<<16)
#define PSM_WDSEL_SRAM7         (0x1U<<17)
#define PSM_WDSEL_SRAM8         (0x1U<<18)
#define PSM_WDSEL_SRAM9         (0x1U<<19)
#define PSM_WDSEL_XIP           (0x1U<<20)
#define PSM_WDSEL_SIO           (0x1U<<21)
#define PSM_WDSEL_ACCESSCTRL    (0x1U<<22)
#define PSM_WDSEL_PROC0         (0x1U<<23)
#define PSM_WDSEL_PROC1         (0x1U<<24)

// DONE Configuration

#define PSM_DONE_PROC_COLD      (0x1U<<0)
#define PSM_DONE_OTP            (0x1U<<1)
#define PSM_DONE_ROSC           (0x1U<<2)
#define PSM_DONE_XOSC           (0x1U<<3)
#define PSM_DONE_RESETS         (0x1U<<4)
#define PSM_DONE_CLOCKS         (0x1U<<5)
#define PSM_DONE_PSM_READY      (0x1U<<6)
#define PSM_DONE_BUSFABRIC      (0x1U<<7)
#define PSM_DONE_ROM            (0x1U<<8)
#define PSM_DONE_BOOTRAM        (0x1U<<9)
#define PSM_DONE_SRAM0          (0x1U<<10)
#define PSM_DONE_SRAM1          (0x1U<<11)
#define PSM_DONE_SRAM2          (0x1U<<12)
#define PSM_DONE_SRAM3          (0x1U<<13)
#define PSM_DONE_SRAM4          (0x1U<<14)
#define PSM_DONE_SRAM5          (0x1U<<15)
#define PSM_DONE_SRAM6          (0x1U<<16)
#define PSM_DONE_SRAM7          (0x1U<<17)
#define PSM_DONE_SRAM8          (0x1U<<18)
#define PSM_DONE_SRAM9          (0x1U<<19)
#define PSM_DONE_XIP            (0x1U<<20)
#define PSM_DONE_SIO            (0x1U<<21)
#define PSM_DONE_ACCESSCTRL     (0x1U<<22)
#define PSM_DONE_PROC0          (0x1U<<23)
#define PSM_DONE_PROC1          (0x1U<<24)
