/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Hazard3 Xh3irq custom CSR definitions (RP2350).
 */

#pragma once

// Hazard3 external-interrupt controller CSR addresses (Xh3irq extension)

#define HAZARD3_CSR_MEIEA       0xBE0U  // External Interrupt Enable Array
#define HAZARD3_CSR_MEIPA       0xBE1U  // External Interrupt Pending Array
#define HAZARD3_CSR_MEIFA       0xBE2U  // External Interrupt Force Array
#define HAZARD3_CSR_MEIPRA      0xBE3U  // External Interrupt Priority Array
#define HAZARD3_CSR_MEINEXT     0xBE4U  // Next external interrupt (read-to-claim)
#define HAZARD3_CSR_MEICONTEXT  0xBE5U  // Interrupt preemption context

// meinext bit fields

#define MEINEXT_NOIRQ           0x1U    // Bit 0: set when no interrupt is pending
#define MEINEXT_IRQ_MASK        0x3FCU  // Bits [9:2]: interrupt source number
#define MEINEXT_IRQ_SHIFT       2U      // Right-shift to extract the IRQ index
