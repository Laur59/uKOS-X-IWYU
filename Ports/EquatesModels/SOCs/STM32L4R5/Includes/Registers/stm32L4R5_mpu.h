/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_mpu equates.
 */

#pragma once

#include    <stdint.h>

// MPU address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TYPER;
    volatile    uint32_t    CTRL;
    volatile    uint32_t    RNR;
    volatile    uint32_t    RBAR;
    volatile    uint32_t    RASR;
} MPU_TypeDef;

#ifdef __cplusplus
#define MPU reinterpret_cast<MPU_TypeDef *>(0xE000ED90U)

#else
#define MPU ((MPU_TypeDef *)0xE000ED90U)
#endif

// TYPER Configuration

#define MPU_TYPER_IREGION   (0xFFU<<16)
#define MPU_TYPER_IREGION_0 (0x1U<<16)
#define MPU_TYPER_DREGION   (0xFFU<<8)
#define MPU_TYPER_DREGION_0 (0x1U<<8)
#define MPU_TYPER_SEPARATE  (0x1U<<0)

// CTRL Configuration

#define MPU_CTRL_PRIVDEFENA (0x1U<<2)
#define MPU_CTRL_HFNMIENA   (0x1U<<1)
#define MPU_CTRL_ENABLE     (0x1U<<0)

// RNR Configuration

#define MPU_RNR_REGION      (0xFFU<<0)
#define MPU_RNR_REGION_0    (0x1U<<0)

// RBAR Configuration

#define MPU_RBAR_ADDR       (0x7FFFFFFU<<5)
#define MPU_RBAR_ADDR_0     (0x1U<<5)
#define MPU_RBAR_VALID      (0x1U<<4)
#define MPU_RBAR_REGION     (0xFU<<0)
#define MPU_RBAR_REGION_0   (0x1U<<0)

// RASR Configuration

#define MPU_RASR_XN         (0x1U<<28)
#define MPU_RASR_AP         (0x7U<<24)
#define MPU_RASR_AP_0       (0x1U<<24)
#define MPU_RASR_TEX        (0x7U<<19)
#define MPU_RASR_TEX_0      (0x1U<<19)
#define MPU_RASR_S          (0x1U<<18)
#define MPU_RASR_C          (0x1U<<17)
#define MPU_RASR_B          (0x1U<<16)
#define MPU_RASR_SRD        (0xFFU<<8)
#define MPU_RASR_SRD_0      (0x1U<<8)
#define MPU_RASR_SIZE       (0x1FU<<1)
#define MPU_RASR_SIZE_0     (0x1U<<1)
#define MPU_RASR_ENABLE     (0x1U<<0)
