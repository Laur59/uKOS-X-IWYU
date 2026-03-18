/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_ticks equates.
 */

#pragma once

#include    <stdint.h>

// TICKS address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    PROC0_CTRL;
    volatile    uint32_t    PROC0_CYCLES;
    volatile    uint32_t    PROC0_COUNT;
    volatile    uint32_t    PROC1_CTRL;
    volatile    uint32_t    PROC1_CYCLES;
    volatile    uint32_t    PROC1_COUNT;
    volatile    uint32_t    TIMER0_CTRL;
    volatile    uint32_t    TIMER0_CYCLES;
    volatile    uint32_t    TIMER0_COUNT;
    volatile    uint32_t    TIMER1_CTRL;
    volatile    uint32_t    TIMER1_CYCLES;
    volatile    uint32_t    TIMER1_COUNT;
    volatile    uint32_t    WATCHDOG_CTRL;
    volatile    uint32_t    WATCHDOG_CYCLES;
    volatile    uint32_t    WATCHDOG_COUNT;
    volatile    uint32_t    RISCV_CTRL;
    volatile    uint32_t    RISCV_CYCLES;
    volatile    uint32_t    RISCV_COUNT;
} TICKS_TypeDef;

#ifdef __cplusplus
#define TICKS_NS    reinterpret_cast<TICKS_TypeDef *>(0x40108000U)
#define TICKS_S     reinterpret_cast<TICKS_TypeDef *>(0x40108000U)
#else
#define TICKS_NS    ((TICKS_TypeDef *)0x40108000U)
#define TICKS_S     ((TICKS_TypeDef *)0x40108000U)
#endif

// PROC0_CTRL Configuration

#define TICKS_PROC0_CTRL_ENABLE                 (0x1U<<0)
#define TICKS_PROC0_CTRL_RUNNING                (0x1U<<1)

// PROC0_CYCLES Configuration

#define TICKS_PROC0_CYCLES_PROC0_CYCLES         (0x1FFU<<0)
#define TICKS_PROC0_CYCLES_PROC0_CYCLES_0       (0x1U<<0)

// PROC0_COUNT Configuration

#define TICKS_PROC0_COUNT_PROC0_COUNT           (0x1FFU<<0)
#define TICKS_PROC0_COUNT_PROC0_COUNT_0         (0x1U<<0)

// PROC1_CTRL Configuration

#define TICKS_PROC1_CTRL_ENABLE                 (0x1U<<0)
#define TICKS_PROC1_CTRL_RUNNING                (0x1U<<1)

// PROC1_CYCLES Configuration

#define TICKS_PROC1_CYCLES_PROC1_CYCLES         (0x1FFU<<0)
#define TICKS_PROC1_CYCLES_PROC1_CYCLES_0       (0x1U<<0)

// PROC1_COUNT Configuration

#define TICKS_PROC1_COUNT_PROC1_COUNT           (0x1FFU<<0)
#define TICKS_PROC1_COUNT_PROC1_COUNT_0         (0x1U<<0)

// TIMER0_CTRL Configuration

#define TICKS_TIMER0_CTRL_ENABLE                (0x1U<<0)
#define TICKS_TIMER0_CTRL_RUNNING               (0x1U<<1)

// TIMER0_CYCLES Configuration

#define TICKS_TIMER0_CYCLES_TIMER0_CYCLES       (0x1FFU<<0)
#define TICKS_TIMER0_CYCLES_TIMER0_CYCLES_0     (0x1U<<0)

// TIMER0_COUNT Configuration

#define TICKS_TIMER0_COUNT_TIMER0_COUNT         (0x1FFU<<0)
#define TICKS_TIMER0_COUNT_TIMER0_COUNT_0       (0x1U<<0)

// TIMER1_CTRL Configuration

#define TICKS_TIMER1_CTRL_ENABLE                (0x1U<<0)
#define TICKS_TIMER1_CTRL_RUNNING               (0x1U<<1)

// TIMER1_CYCLES Configuration

#define TICKS_TIMER1_CYCLES_TIMER1_CYCLES       (0x1FFU<<0)
#define TICKS_TIMER1_CYCLES_TIMER1_CYCLES_0     (0x1U<<0)

// TIMER1_COUNT Configuration

#define TICKS_TIMER1_COUNT_TIMER1_COUNT         (0x1FFU<<0)
#define TICKS_TIMER1_COUNT_TIMER1_COUNT_0       (0x1U<<0)

// WATCHDOG_CTRL Configuration

#define TICKS_WATCHDOG_CTRL_ENABLE              (0x1U<<0)
#define TICKS_WATCHDOG_CTRL_RUNNING             (0x1U<<1)

// WATCHDOG_CYCLES Configuration

#define TICKS_WATCHDOG_CYCLES_WATCHDOG_CYCLES   (0x1FFU<<0)
#define TICKS_WATCHDOG_CYCLES_WATCHDOG_CYCLES_0 (0x1U<<0)

// WATCHDOG_COUNT Configuration

#define TICKS_WATCHDOG_COUNT_WATCHDOG_COUNT     (0x1FFU<<0)
#define TICKS_WATCHDOG_COUNT_WATCHDOG_COUNT_0   (0x1U<<0)

// RISCV_CTRL Configuration

#define TICKS_RISCV_CTRL_ENABLE                 (0x1U<<0)
#define TICKS_RISCV_CTRL_RUNNING                (0x1U<<1)

// RISCV_CYCLES Configuration

#define TICKS_RISCV_CYCLES_RISCV_CYCLES         (0x1FFU<<0)
#define TICKS_RISCV_CYCLES_RISCV_CYCLES_0       (0x1U<<0)

// RISCV_COUNT Configuration

#define TICKS_RISCV_COUNT_RISCV_COUNT           (0x1FFU<<0)
#define TICKS_RISCV_COUNT_RISCV_COUNT_0         (0x1U<<0)
