/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_syscfg equates.
 */

#pragma once

#include    <stdint.h>

// SYSCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    PROC_CONFIG;
    volatile    uint32_t    PROC_IN_SYNC_BYPASS;
    volatile    uint32_t    PROC_IN_SYNC_BYPASS_HI;
    volatile    uint32_t    DBGFORCE;
    volatile    uint32_t    MEMPOWERDOWN;
    volatile    uint32_t    AUXCTRL;
} SYSCFG_TypeDef;

#ifdef __cplusplus
#define SYSCFG_NS   reinterpret_cast<SYSCFG_TypeDef *>(0x40008000U)
#define SYSCFG_S    reinterpret_cast<SYSCFG_TypeDef *>(0x40008000U)
#else
#define SYSCFG_NS   ((SYSCFG_TypeDef *)0x40008000U)
#define SYSCFG_S    ((SYSCFG_TypeDef *)0x40008000U)
#endif

// PROC_CONFIG Configuration

#define SYSCFG_PROC_CONFIG_PROC0_HALTED         (0x1U<<0U)
#define SYSCFG_PROC_CONFIG_PROC1_HALTED         (0x1U<<1U)

// PROC_IN_SYNC_BYPASS Configuration

#define SYSCFG_PROC_IN_SYNC_BYPASS_GPIO         (0xFFFFFFFFU<<0U)
#define SYSCFG_PROC_IN_SYNC_BYPASS_GPIO_0       (0x1U<<0U)

// PROC_IN_SYNC_BYPASS_HI Configuration

#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_GPIO      (0xFFFFU<<0U)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_GPIO_0    (0x1U<<0U)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_USB_DP    (0x1U<<24U)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_USB_DM    (0x1U<<25U)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SCK  (0x1U<<26U)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_CSN  (0x1U<<27U)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SD   (0xFU<<28U)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SD_0 (0x1U<<28U)

// DBGFORCE Configuration

#define SYSCFG_DBGFORCE_SWDO                    (0x1U<<0U)
#define SYSCFG_DBGFORCE_SWDI                    (0x1U<<1U)
#define SYSCFG_DBGFORCE_SWCLK                   (0x1U<<2U)
#define SYSCFG_DBGFORCE_ATTACH                  (0x1U<<3U)

// MEMPOWERDOWN Configuration

#define SYSCFG_MEMPOWERDOWN_SRAM0               (0x1U<<0U)
#define SYSCFG_MEMPOWERDOWN_SRAM1               (0x1U<<1U)
#define SYSCFG_MEMPOWERDOWN_SRAM2               (0x1U<<2U)
#define SYSCFG_MEMPOWERDOWN_SRAM3               (0x1U<<3U)
#define SYSCFG_MEMPOWERDOWN_SRAM4               (0x1U<<4U)
#define SYSCFG_MEMPOWERDOWN_SRAM5               (0x1U<<5U)
#define SYSCFG_MEMPOWERDOWN_SRAM6               (0x1U<<6U)
#define SYSCFG_MEMPOWERDOWN_SRAM7               (0x1U<<7U)
#define SYSCFG_MEMPOWERDOWN_SRAM8               (0x1U<<8U)
#define SYSCFG_MEMPOWERDOWN_SRAM9               (0x1U<<9U)
#define SYSCFG_MEMPOWERDOWN_USB                 (0x1U<<10U)
#define SYSCFG_MEMPOWERDOWN_ROM                 (0x1U<<11U)
#define SYSCFG_MEMPOWERDOWN_BOOTRAM             (0x1U<<12U)

// AUXCTRL Configuration

#define SYSCFG_AUXCTRL_AUXCTRL                  (0xFFU<<0U)
#define SYSCFG_AUXCTRL_AUXCTRL_0                (0x1U<<0U)
