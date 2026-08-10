/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_fpu equates.
 */

#pragma once

#include    <stdint.h>

// FPU address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    FPCCR;
    volatile    uint32_t    FPCAR;
    volatile    uint32_t    FPSCR;
} FPU_TypeDef;

#ifdef __cplusplus
#define FPU reinterpret_cast<FPU_TypeDef *>(0xE000EF34U)

#else
#define FPU ((FPU_TypeDef *)0xE000EF34U)
#endif

// FPCCR Configuration

#define FPU_FPCCR_ASPEN     (0x1U<<31U)
#define FPU_FPCCR_LSPEN     (0x1U<<30U)
#define FPU_FPCCR_MONRDY    (0x1U<<8U)
#define FPU_FPCCR_BFRDY     (0x1U<<6U)
#define FPU_FPCCR_MMRDY     (0x1U<<5U)
#define FPU_FPCCR_HFRDY     (0x1U<<4U)
#define FPU_FPCCR_THREAD    (0x1U<<3U)
#define FPU_FPCCR_USER      (0x1U<<1U)
#define FPU_FPCCR_LSPACT    (0x1U<<0U)

// FPCAR Configuration

#define FPU_FPCAR_ADDRESS   (0x1FFFFFFFU<<3U)
#define FPU_FPCAR_ADDRESS_0 (0x1U<<3U)

// FPSCR Configuration

#define FPU_FPSCR_N         (0x1U<<31U)
#define FPU_FPSCR_Z         (0x1U<<30U)
#define FPU_FPSCR_C         (0x1U<<29U)
#define FPU_FPSCR_V         (0x1U<<28U)
#define FPU_FPSCR_AHP       (0x1U<<26U)
#define FPU_FPSCR_DN        (0x1U<<25U)
#define FPU_FPSCR_FZ        (0x1U<<24U)
#define FPU_FPSCR_RMODE     (0x3U<<22U)
#define FPU_FPSCR_RMODE_0   (0x1U<<22U)
#define FPU_FPSCR_IDC       (0x1U<<7U)
#define FPU_FPSCR_IXC       (0x1U<<4U)
#define FPU_FPSCR_UFC       (0x1U<<3U)
#define FPU_FPSCR_OFC       (0x1U<<2U)
#define FPU_FPSCR_DZC       (0x1U<<1U)
#define FPU_FPSCR_IOC       (0x1U<<0U)
