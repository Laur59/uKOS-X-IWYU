/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Core-1 specific initialisation and entry point.
 */

#include    <stdint.h>
#include    <stdlib.h>          // for exit

#include    "core.h"            // IWYU pragma: keep (core_setBitCSR used via INTERRUPTION_ON_HARD)
#include    "crt0.h"            // for exce_init, init_relocate, boot
#include    "macros_core.h"

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
 * - Mirrors core 0's tail of crt0(): per-core exception-vector init, then
 *   into boot() which installs the per-core idle daemon and launcher
 *   process. The launcher then iterates the module table and creates
 *   any process whose oExecutionCore mask includes core 1 (e.g.,
 *   startUp running its core-1 branch on UART0).
 *
 */
// NOLINTNEXTLINE(misc-use-internal-linkage)
extern  void    init_relocate(void);

void    main_C1(void) {
    init_C1_init();
    exce_init();
    init_relocate();
    exit(boot());
}
