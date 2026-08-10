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

#define MPU_TYPER_IREGION   (0xFFU<<16U)
#define MPU_TYPER_IREGION_0 (0x1U<<16U)
#define MPU_TYPER_DREGION   (0xFFU<<8U)
#define MPU_TYPER_DREGION_0 (0x1U<<8U)
#define MPU_TYPER_SEPARATE  (0x1U<<0U)

// CTRL Configuration

#define MPU_CTRL_PRIVDEFENA (0x1U<<2U)
#define MPU_CTRL_HFNMIENA   (0x1U<<1U)
#define MPU_CTRL_ENABLE     (0x1U<<0U)

// RNR Configuration

#define MPU_RNR_REGION      (0xFFU<<0U)
#define MPU_RNR_REGION_0    (0x1U<<0U)

// RBAR Configuration

#define MPU_RBAR_ADDR       (0x7FFFFFFU<<5U)
#define MPU_RBAR_ADDR_0     (0x1U<<5U)
#define MPU_RBAR_VALID      (0x1U<<4U)
#define MPU_RBAR_REGION     (0xFU<<0U)
#define MPU_RBAR_REGION_0   (0x1U<<0U)

// RASR Configuration

#define MPU_RASR_XN         (0x1U<<28U)
#define MPU_RASR_AP         (0x7U<<24U)
#define MPU_RASR_AP_0       (0x1U<<24U)
#define MPU_RASR_TEX        (0x7U<<19U)
#define MPU_RASR_TEX_0      (0x1U<<19U)
#define MPU_RASR_S          (0x1U<<18U)
#define MPU_RASR_C          (0x1U<<17U)
#define MPU_RASR_B          (0x1U<<16U)
#define MPU_RASR_SRD        (0xFFU<<8U)
#define MPU_RASR_SRD_0      (0x1U<<8U)
#define MPU_RASR_SIZE       (0x1FU<<1U)
#define MPU_RASR_SIZE_0     (0x1U<<1U)
#define MPU_RASR_ENABLE     (0x1U<<0U)
