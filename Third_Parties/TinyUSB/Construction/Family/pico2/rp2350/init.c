/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2019 Ha Thach
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Board initial set-up.
 */

__attribute__((weak)) void __unhandled_user_irq(void) {
  while (1) { __asm volatile("wfi"); }
}
