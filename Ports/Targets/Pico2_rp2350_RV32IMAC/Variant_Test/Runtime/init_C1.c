/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Core-1 specific initialisation and entry point.
 */

#include    <stdint.h>

#include    "core.h"            // IWYU pragma: keep (core_setBitCSR used via INTERRUPTION_ON_HARD)
#include    "macros_core.h"

extern  int32_t kern_runKernel(void);

/*
 * \brief init_C1_init
 *
 * - Enable machine interrupts so Core 1 can receive ecalls and timer events.
 *
 */
static  void    init_C1_init(void) {
    INTERRUPTION_ON_HARD;
}

/*
 * \brief main_C1
 *
 * - Core 1 entry point (strong override of the weak symbol in first-riscv.c).
 * - Called from Reset_C1_Handler after gp, mtvec, and sp are set up.
 *
 */
// NOLINTNEXTLINE(misc-use-internal-linkage)
void    main_C1(void) {
    init_C1_init();
    kern_runKernel();
}
