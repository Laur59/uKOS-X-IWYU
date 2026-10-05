/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Board initial set-up (RP2350 Hazard3 RV32IMAC).
 */

#include    <stdint.h>

[[gnu::weak]]
void __unhandled_user_irq(void) {

  while (1) { __asm volatile("wfi"); }
}

void    busy_wait_us(uint64_t delay_us) {
    volatile    uint64_t    i;

    for (i = 0u; i < (delay_us * 50u); i++) {
        __asm volatile ("nop");
    }
}
