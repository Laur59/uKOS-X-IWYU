/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_sysinfo equates.
 */

#pragma once

#include    <stdint.h>

// SYSINFO address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    CHIP_ID;
    volatile    uint32_t    PACKAGE_SEL;
    volatile    uint32_t    PLATFORM;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    GITREF_RP2350;
} SYSINFO_TypeDef;

#ifdef __cplusplus
#define SYSINFO_NS  reinterpret_cast<SYSINFO_TypeDef *>(0x40000000U)
#define SYSINFO_S   reinterpret_cast<SYSINFO_TypeDef *>(0x40000000U)
#else
#define SYSINFO_NS  ((SYSINFO_TypeDef *)0x40000000U)
#define SYSINFO_S   ((SYSINFO_TypeDef *)0x40000000U)
#endif

// CHIP_ID Configuration

#define SYSINFO_CHIP_ID_STOP_BIT                (0x1U<<0)
#define SYSINFO_CHIP_ID_MANUFACTURER            (0x7FFU<<1)
#define SYSINFO_CHIP_ID_MANUFACTURER_0          (0x1U<<1)
#define SYSINFO_CHIP_ID_PART                    (0xFFFFU<<12)
#define SYSINFO_CHIP_ID_PART_0                  (0x1U<<12)
#define SYSINFO_CHIP_ID_REVISION                (0xFU<<28)
#define SYSINFO_CHIP_ID_REVISION_0              (0x1U<<28)

// PACKAGE_SEL Configuration

#define SYSINFO_PACKAGE_SEL_PACKAGE_SEL         (0x1U<<0)

// PLATFORM Configuration

#define SYSINFO_PLATFORM_FPGA                   (0x1U<<0)
#define SYSINFO_PLATFORM_ASIC                   (0x1U<<1)
#define SYSINFO_PLATFORM_HDLSIM                 (0x1U<<2)
#define SYSINFO_PLATFORM_BATCHSIM               (0x1U<<3)
#define SYSINFO_PLATFORM_GATESIM                (0x1U<<4)

// GITREF_RP2350 Configuration

#define SYSINFO_GITREF_RP2350_GITREF_RP2350     (0xFFFFFFFFU<<0)
#define SYSINFO_GITREF_RP2350_GITREF_RP2350_0   (0x1U<<0)
