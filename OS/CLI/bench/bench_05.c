/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Bench 05:   Compute a simple loop. 1000000 iterations.
 *
 *           Target used: Nucleo_H743 @ 480-MHz
 *           Target used: Nucleo_N657 @ 600-MHz
 *           Target used: MAiXDUiNO_K210 @ 400-MHz
 *           Target used: Discovery_U5G9 @ 160-MHz
 *
 *           Bench results in [us]:
 *
 *                                       _loop
 *           Nucleo_H743 @ 480-MHz       10400
 *           Nucleo_N657 @ 600-MHz       13240
 *           MAiXDUiNO_K210 @ 400-MHz    -
 *           Discovery_U5G9 @ 160-MHz    -
 */

#include    "bench.h"

#include    <stdio.h>

#include    "board.h"       // IWYU pragma: keep (for board_S)
#include    "serial/serial.h"

// CLI tool specific
// =================

#define KNB_TESTS   1000000u

/*
 * \brief bench_05
 *
 * - loop
 *
 */
#if (!defined(Nucleo_H743_S) && !defined(Nucleo_N657_S))

bool    bench_05(void) {

    (void)dprintf(KSYST, "Bench 05: not available for this target\n");
    return true;
}

#else

#include    "kern/kern.h"
#include    "macros_core.h"

static  void     local_loop(uint32_t nb);

bool    bench_05(void) {

    (void)dprintf(KSYST, "Bench 05: For scope tests!\n");

    kern_suspendProcess(1000U);

    INTERRUPTION_OFF_HARD;
    while (true) {

        ANALYSER_TOGGLE;
        local_loop(KNB_TESTS);
    }

    return true;
}

// Local routines
// ==============

/*
 * \brief local_loop
 *
 * - Execute the nop
 *
 */
static  void local_loop(uint32_t nb) {
    volatile    uint32_t    i;

    for (i = 0U; i < nb; i++) {
        NOP;
    }
}

#endif
