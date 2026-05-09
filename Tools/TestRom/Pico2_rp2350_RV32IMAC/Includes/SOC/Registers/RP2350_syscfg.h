/*
 * SPDX-License-Identifier: MIT
 * Generated using the .svd description The 2025-01-01
 *
 * Goal:        RP2350_syscfg equates.
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

#define SYSCFG_PROC_CONFIG_PROC0_HALTED         (0x1U<<0)
#define SYSCFG_PROC_CONFIG_PROC1_HALTED         (0x1U<<1)

// PROC_IN_SYNC_BYPASS Configuration

#define SYSCFG_PROC_IN_SYNC_BYPASS_GPIO         (0xFFFFFFFFU<<0)
#define SYSCFG_PROC_IN_SYNC_BYPASS_GPIO_0       (0x1U<<0)

// PROC_IN_SYNC_BYPASS_HI Configuration

#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_GPIO      (0xFFFFU<<0)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_GPIO_0    (0x1U<<0)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_USB_DP    (0x1U<<24)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_USB_DM    (0x1U<<25)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SCK  (0x1U<<26)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_CSN  (0x1U<<27)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SD   (0xFU<<28)
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SD_0 (0x1U<<28)

// DBGFORCE Configuration

#define SYSCFG_DBGFORCE_SWDO                    (0x1U<<0)
#define SYSCFG_DBGFORCE_SWDI                    (0x1U<<1)
#define SYSCFG_DBGFORCE_SWCLK                   (0x1U<<2)
#define SYSCFG_DBGFORCE_ATTACH                  (0x1U<<3)

// MEMPOWERDOWN Configuration

#define SYSCFG_MEMPOWERDOWN_SRAM0               (0x1U<<0)
#define SYSCFG_MEMPOWERDOWN_SRAM1               (0x1U<<1)
#define SYSCFG_MEMPOWERDOWN_SRAM2               (0x1U<<2)
#define SYSCFG_MEMPOWERDOWN_SRAM3               (0x1U<<3)
#define SYSCFG_MEMPOWERDOWN_SRAM4               (0x1U<<4)
#define SYSCFG_MEMPOWERDOWN_SRAM5               (0x1U<<5)
#define SYSCFG_MEMPOWERDOWN_SRAM6               (0x1U<<6)
#define SYSCFG_MEMPOWERDOWN_SRAM7               (0x1U<<7)
#define SYSCFG_MEMPOWERDOWN_SRAM8               (0x1U<<8)
#define SYSCFG_MEMPOWERDOWN_SRAM9               (0x1U<<9)
#define SYSCFG_MEMPOWERDOWN_USB                 (0x1U<<10)
#define SYSCFG_MEMPOWERDOWN_ROM                 (0x1U<<11)
#define SYSCFG_MEMPOWERDOWN_BOOTRAM             (0x1U<<12)

// AUXCTRL Configuration

#define SYSCFG_AUXCTRL_AUXCTRL                  (0xFFU<<0)
#define SYSCFG_AUXCTRL_AUXCTRL_0                (0x1U<<0)
