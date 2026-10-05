/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2019 Ha Thach
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Board initial set-up.
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
