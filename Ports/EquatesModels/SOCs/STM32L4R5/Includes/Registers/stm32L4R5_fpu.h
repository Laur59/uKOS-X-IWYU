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

#define FPU_FPCCR_ASPEN     (0x1U<<31)
#define FPU_FPCCR_LSPEN     (0x1U<<30)
#define FPU_FPCCR_MONRDY    (0x1U<<8)
#define FPU_FPCCR_BFRDY     (0x1U<<6)
#define FPU_FPCCR_MMRDY     (0x1U<<5)
#define FPU_FPCCR_HFRDY     (0x1U<<4)
#define FPU_FPCCR_THREAD    (0x1U<<3)
#define FPU_FPCCR_USER      (0x1U<<1)
#define FPU_FPCCR_LSPACT    (0x1U<<0)

// FPCAR Configuration

#define FPU_FPCAR_ADDRESS   (0x1FFFFFFFU<<3)
#define FPU_FPCAR_ADDRESS_0 (0x1U<<3)

// FPSCR Configuration

#define FPU_FPSCR_N         (0x1U<<31)
#define FPU_FPSCR_Z         (0x1U<<30)
#define FPU_FPSCR_C         (0x1U<<29)
#define FPU_FPSCR_V         (0x1U<<28)
#define FPU_FPSCR_AHP       (0x1U<<26)
#define FPU_FPSCR_DN        (0x1U<<25)
#define FPU_FPSCR_FZ        (0x1U<<24)
#define FPU_FPSCR_RMODE     (0x3U<<22)
#define FPU_FPSCR_RMODE_0   (0x1U<<22)
#define FPU_FPSCR_IDC       (0x1U<<7)
#define FPU_FPSCR_IXC       (0x1U<<4)
#define FPU_FPSCR_UFC       (0x1U<<3)
#define FPU_FPSCR_OFC       (0x1U<<2)
#define FPU_FPSCR_DZC       (0x1U<<1)
#define FPU_FPSCR_IOC       (0x1U<<0)
