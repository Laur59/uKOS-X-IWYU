/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_pads_qspi equates.
 */

#pragma once

#include    <stdint.h>

// PADS_QSPI address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    VOLTAGE_SELECT;
    volatile    uint32_t    GPIO_QSPI_SCLK;
    volatile    uint32_t    GPIO_QSPI_SD0;
    volatile    uint32_t    GPIO_QSPI_SD1;
    volatile    uint32_t    GPIO_QSPI_SD2;
    volatile    uint32_t    GPIO_QSPI_SD3;
    volatile    uint32_t    GPIO_QSPI_SS;
} PADS_QSPI_TypeDef;

#ifdef __cplusplus
#define PADS_QSPI_NS    reinterpret_cast<PADS_QSPI_TypeDef *>(0x40040000U)
#define PADS_QSPI_S     reinterpret_cast<PADS_QSPI_TypeDef *>(0x40040000U)
#else
#define PADS_QSPI_NS    ((PADS_QSPI_TypeDef *)0x40040000U)
#define PADS_QSPI_S     ((PADS_QSPI_TypeDef *)0x40040000U)
#endif

// VOLTAGE_SELECT Configuration

#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT     (0x1U<<0)
#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT_3V3 (0x0U<<0)
#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT_1V8 (0x1U<<0)

// GPIO_QSPI_SCLK Configuration

#define PADS_QSPI_GPIO_QSPI_SCLK_SLEWFAST           (0x1U<<0)
#define PADS_QSPI_GPIO_QSPI_SCLK_SCHMITT            (0x1U<<1)
#define PADS_QSPI_GPIO_QSPI_SCLK_PDE                (0x1U<<2)
#define PADS_QSPI_GPIO_QSPI_SCLK_PUE                (0x1U<<3)
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE              (0x3U<<4)
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_0            (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SCLK_IE                 (0x1U<<6)
#define PADS_QSPI_GPIO_QSPI_SCLK_OD                 (0x1U<<7)
#define PADS_QSPI_GPIO_QSPI_SCLK_ISO                (0x1U<<8)
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_2MA          (0x0U<<4)
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_4MA          (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_8MA          (0x2U<<4)
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_12MA         (0x3U<<4)

// GPIO_QSPI_SD0 Configuration

#define PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST            (0x1U<<0)
#define PADS_QSPI_GPIO_QSPI_SD0_SCHMITT             (0x1U<<1)
#define PADS_QSPI_GPIO_QSPI_SD0_PDE                 (0x1U<<2)
#define PADS_QSPI_GPIO_QSPI_SD0_PUE                 (0x1U<<3)
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE               (0x3U<<4)
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_0             (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SD0_IE                  (0x1U<<6)
#define PADS_QSPI_GPIO_QSPI_SD0_OD                  (0x1U<<7)
#define PADS_QSPI_GPIO_QSPI_SD0_ISO                 (0x1U<<8)
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_2MA           (0x0U<<4)
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_4MA           (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_8MA           (0x2U<<4)
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_12MA          (0x3U<<4)

// GPIO_QSPI_SD1 Configuration

#define PADS_QSPI_GPIO_QSPI_SD1_SLEWFAST            (0x1U<<0)
#define PADS_QSPI_GPIO_QSPI_SD1_SCHMITT             (0x1U<<1)
#define PADS_QSPI_GPIO_QSPI_SD1_PDE                 (0x1U<<2)
#define PADS_QSPI_GPIO_QSPI_SD1_PUE                 (0x1U<<3)
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE               (0x3U<<4)
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_0             (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SD1_IE                  (0x1U<<6)
#define PADS_QSPI_GPIO_QSPI_SD1_OD                  (0x1U<<7)
#define PADS_QSPI_GPIO_QSPI_SD1_ISO                 (0x1U<<8)
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_2MA           (0x0U<<4)
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_4MA           (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_8MA           (0x2U<<4)
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_12MA          (0x3U<<4)

// GPIO_QSPI_SD2 Configuration

#define PADS_QSPI_GPIO_QSPI_SD2_SLEWFAST            (0x1U<<0)
#define PADS_QSPI_GPIO_QSPI_SD2_SCHMITT             (0x1U<<1)
#define PADS_QSPI_GPIO_QSPI_SD2_PDE                 (0x1U<<2)
#define PADS_QSPI_GPIO_QSPI_SD2_PUE                 (0x1U<<3)
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE               (0x3U<<4)
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_0             (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SD2_IE                  (0x1U<<6)
#define PADS_QSPI_GPIO_QSPI_SD2_OD                  (0x1U<<7)
#define PADS_QSPI_GPIO_QSPI_SD2_ISO                 (0x1U<<8)
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_2MA           (0x0U<<4)
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_4MA           (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_8MA           (0x2U<<4)
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_12MA          (0x3U<<4)

// GPIO_QSPI_SD3 Configuration

#define PADS_QSPI_GPIO_QSPI_SD3_SLEWFAST            (0x1U<<0)
#define PADS_QSPI_GPIO_QSPI_SD3_SCHMITT             (0x1U<<1)
#define PADS_QSPI_GPIO_QSPI_SD3_PDE                 (0x1U<<2)
#define PADS_QSPI_GPIO_QSPI_SD3_PUE                 (0x1U<<3)
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE               (0x3U<<4)
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_0             (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SD3_IE                  (0x1U<<6)
#define PADS_QSPI_GPIO_QSPI_SD3_OD                  (0x1U<<7)
#define PADS_QSPI_GPIO_QSPI_SD3_ISO                 (0x1U<<8)
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_2MA           (0x0U<<4)
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_4MA           (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_8MA           (0x2U<<4)
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_12MA          (0x3U<<4)

// GPIO_QSPI_SS Configuration

#define PADS_QSPI_GPIO_QSPI_SS_SLEWFAST             (0x1U<<0)
#define PADS_QSPI_GPIO_QSPI_SS_SCHMITT              (0x1U<<1)
#define PADS_QSPI_GPIO_QSPI_SS_PDE                  (0x1U<<2)
#define PADS_QSPI_GPIO_QSPI_SS_PUE                  (0x1U<<3)
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE                (0x3U<<4)
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_0              (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SS_IE                   (0x1U<<6)
#define PADS_QSPI_GPIO_QSPI_SS_OD                   (0x1U<<7)
#define PADS_QSPI_GPIO_QSPI_SS_ISO                  (0x1U<<8)
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_2MA            (0x0U<<4)
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_4MA            (0x1U<<4)
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_8MA            (0x2U<<4)
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_12MA           (0x3U<<4)
