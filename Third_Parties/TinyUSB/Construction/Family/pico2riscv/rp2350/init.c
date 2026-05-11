/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Board initial set-up (RP2350 Hazard3 RV32IMAC).
 */

[[gnu::weak]]
void __unhandled_user_irq(void) {
  while (1) { __asm volatile("wfi"); }
}
