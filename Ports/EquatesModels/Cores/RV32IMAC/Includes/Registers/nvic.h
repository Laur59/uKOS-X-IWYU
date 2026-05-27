/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Hazard3 Xh3irq interrupt-controller macros.
 *
 * Primary API: h3irq_EnableIRQ / h3irq_DisableIRQ / h3irq_SetPriority /
 *              h3irq_SetPendingIRQ / h3irq_ClearPendingIRQ.
 *
 * NVIC_* aliases are provided so that shared rp2350 model files
 * (model_uart_C0.c_inc etc.) compile on both ARM and RISC-V without change.
 * RISC-V-only code (model_kernel_tim0_ecall_C0.c_inc) uses h3irq_* directly.
 *
 * Hardware notes (Hazard3 Xh3irq):
 *   MEIEA (0xBE0) – enable array, window-addressed:
 *       write: bits[15:0] = window index (selects 16-IRQ group),
 *              bits[31:16] = new enable bits for that group.
 *       read after write: bits[31:16] = current enables for the window.
 *   MEIFA (0xBE2) – force array, same window layout as MEIEA.
 *   MEIPRA (0xBE3) – priority array (window of 4 IRQs × 4 bits each).
 *
 * For enable/disable a single IRQ the sequence is:
 *   1. csrrw (read old enables while writing the window selector with 0 data)
 *   2. Modify the desired bit in the read-back value.
 *   3. csrw to write the modified value back.
 *
 * The two-instruction window causes a brief (≈2-cycle) all-disabled gap for
 * the 16-IRQ group being modified. This is acceptable during kernel init.
 */

#pragma once

#include    <stdint.h>

#include    "Registers/core_addendum.h"

// h3irq_EnableIRQ
// Enable external interrupt `irq` via Hazard3 MEIEA.

static inline void h3irq_EnableIRQ(uint32_t irq) {
    uint32_t window = irq>>4U;
    uint32_t bit    = (irq & 15U) + 16U;
    uint32_t old;

    __asm volatile ("csrrw %0, 0xBE0, %1" : "=r"(old) : "r"(window));
    __asm volatile ("csrw  0xBE0,    %0"  :: "r"((old & 0xFFFF0000U) | (1u<<bit) | window));
}

// h3irq_DisableIRQ
// Disable external interrupt `irq` via Hazard3 MEIEA.

static inline void h3irq_DisableIRQ(uint32_t irq) {
    uint32_t window = irq>>4U;
    uint32_t bit    = (irq & 15U) + 16U;
    uint32_t old;

    __asm volatile ("csrrw %0, 0xBE0, %1" : "=r"(old) : "r"(window));
    __asm volatile ("csrw  0xBE0,    %0"  :: "r"((old & ~(1U<<bit)) | window));
}

// h3irq_SetPriority
// Set 4-bit priority for external interrupt `irq` via Hazard3 MEIPRA.
// Each window covers 4 IRQs (4 bits each → 16 bits of priority in bits[31:16]).

static inline void h3irq_SetPriority(uint32_t irq, uint32_t priority) {
    uint32_t window = irq>>2U;
    uint32_t shift  = ((irq & 3U)<<2U) + 16U;
    uint32_t old;

    __asm volatile ("csrrw %0, 0xBE3, %1" : "=r"(old) : "r"(window));
    __asm volatile ("csrw  0xBE3,    %0"
        :: "r"((old & ~(0xFU<<shift)) | ((priority & 0xFU)<<shift) | window));
}

// h3irq_SetPendingIRQ
// Software-force IRQ `irq` pending via Hazard3 MEIFA.

static inline void h3irq_SetPendingIRQ(uint32_t irq) {
    uint32_t window = irq>>4U;
    uint32_t bit    = (irq & 15U) + 16U;
    uint32_t old;

    __asm volatile ("csrrw %0, 0xBE2, %1" : "=r"(old) : "r"(window));
    __asm volatile ("csrw  0xBE2,    %0"  :: "r"((old & 0xFFFF0000U) | (1U<<bit) | window));
}

// h3irq_ClearPendingIRQ
// Clear the MEIFA force bit for `irq` (hardware-pending bits clear automatically
// when the interrupt is claimed via MEINEXT; this call clears any software-forced
// pending bit set via MEIFA).

static inline void h3irq_ClearPendingIRQ(uint32_t irq) {
    uint32_t window = irq>>4U;
    uint32_t bit    = (irq & 15U) + 16U;
    uint32_t old;

    __asm volatile ("csrrw %0, 0xBE2, %1" : "=r"(old) : "r"(window));
    __asm volatile ("csrw  0xBE2,    %0"  :: "r"((old & ~(1U<<bit)) | window));
}

// Backward-compat aliases for shared rp2350 model files (model_uart_C0.c_inc
// etc.) that also compile against the ARM Cortex-M33 nvic.h.

#define NVIC_EnableIRQ      h3irq_EnableIRQ
#define NVIC_DisableIRQ     h3irq_DisableIRQ
#define NVIC_SetPriority    h3irq_SetPriority
#define NVIC_SetPendingIRQ  h3irq_SetPendingIRQ
#define NVIC_ClearPendingIRQ h3irq_ClearPendingIRQ
