/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_pll_sys equates.
 */

#pragma once

#include    <stdint.h>

// PLL_SYS address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    CS;
    volatile    uint32_t    PWR;
    volatile    uint32_t    FBDIV_INT;
    volatile    uint32_t    PRIM;
    volatile    uint32_t    INTR;
    volatile    uint32_t    INTE;
    volatile    uint32_t    INTF;
    volatile    uint32_t    INTS;
} PLL_SYS_TypeDef;

#ifdef __cplusplus
#define PLL_SYS_NS  reinterpret_cast<PLL_SYS_TypeDef *>(0x40050000U)
#define PLL_SYS_S   reinterpret_cast<PLL_SYS_TypeDef *>(0x40050000U)
#define PLL_USB_NS  reinterpret_cast<PLL_SYS_TypeDef *>(0x40058000U)
#define PLL_USB_S   reinterpret_cast<PLL_SYS_TypeDef *>(0x40058000U)
#else
#define PLL_SYS_NS  ((PLL_SYS_TypeDef *)0x40050000U)
#define PLL_SYS_S   ((PLL_SYS_TypeDef *)0x40050000U)
#define PLL_USB_NS  ((PLL_SYS_TypeDef *)0x40058000U)
#define PLL_USB_S   ((PLL_SYS_TypeDef *)0x40058000U)
#endif

// CS Configuration

#define PLL_SYS_CS_REFDIV               (0x3FU<<0U)
#define PLL_SYS_CS_REFDIV_0             (0x1U<<0U)
#define PLL_SYS_CS_BYPASS               (0x1U<<8U)
#define PLL_SYS_CS_LOCK_N               (0x1U<<30U)
#define PLL_SYS_CS_LOCK                 (0x1U<<31U)

// PWR Configuration

#define PLL_SYS_PWR_PD                  (0x1U<<0U)
#define PLL_SYS_PWR_DSMPD               (0x1U<<2U)
#define PLL_SYS_PWR_POSTDIVPD           (0x1U<<3U)
#define PLL_SYS_PWR_VCOPD               (0x1U<<5U)

// FBDIV_INT Configuration

#define PLL_SYS_FBDIV_INT_FBDIV_INT     (0xFFFU<<0U)
#define PLL_SYS_FBDIV_INT_FBDIV_INT_0   (0x1U<<0U)

// PRIM Configuration

#define PLL_SYS_PRIM_POSTDIV2           (0x7U<<12U)
#define PLL_SYS_PRIM_POSTDIV2_0         (0x1U<<12U)
#define PLL_SYS_PRIM_POSTDIV1           (0x7U<<16U)
#define PLL_SYS_PRIM_POSTDIV1_0         (0x1U<<16U)

// INTR Configuration

#define PLL_SYS_INTR_LOCK_N_STICKY      (0x1U<<0U)

// INTE Configuration

#define PLL_SYS_INTE_LOCK_N_STICKY      (0x1U<<0U)

// INTF Configuration

#define PLL_SYS_INTF_LOCK_N_STICKY      (0x1U<<0U)

// INTS Configuration

#define PLL_SYS_INTS_LOCK_N_STICKY      (0x1U<<0U)
