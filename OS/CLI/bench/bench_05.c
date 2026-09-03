/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:     Bench 05:   Compute a simple loop. 1000000 iterations.
 *
 *                       The analyser output is pulsed for the duration of
 *                       every pass, so the loop time can also be read on a
 *                       scope. The burst is bounded: the bench gives the
 *                       console back when the passes are done.
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

#define KNB_TESTS   1000000U
#define KNB_PASSES  8U

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

#include    <stdint.h>
#include    "kern/kern.h"
#include    "macros_core.h"

static  void     local_loop(uint32_t nb, uint64_t *time);

bool    bench_05(void) {
    uint64_t    time, sumTime = 0U;
    uint32_t    j;

    (void)dprintf(KSYST, "Bench 05: For scope tests!\n");

// Leave the operator the time to arm the scope trigger

    kern_suspendProcess(1000U);

    for (j = 0U; j < KNB_PASSES; j++) {
        local_loop(KNB_TESTS, &time);
        sumTime += time;
    }

// Results
//                        Bench xy: Descriptions, comments, ....                 Execution time
// -----------------------|---------|--------------------------------------------|-----------------|
//
    (void)dprintf(KSYST, "Bench 05: Execute a tight nop loop and pulse the\n"
                         "          analyser output over every pass.\n"
                         "          Iterations per pass                          n = %8d [-]\n"
                         "          Number of passes                             n = %8d [-]\n"
                         "          Loop (mean per pass)                         t = %8lld [us]\n\n", KNB_TESTS, KNB_PASSES, (sumTime / KNB_PASSES));
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
static  void local_loop(uint32_t nb, uint64_t *time) {
                uint64_t    tStamp[2];
    volatile    uint32_t    i;

    PRIVILEGE_ELEVATE;      // INTERRUPTION_OFF_HARD writes the interrupt mask: privileged
    kern_readTickCount(&tStamp[0]);

    INTERRUPTION_OFF_HARD;
    ANALYSER_TOGGLE;
    for (i = 0U; i < nb; i++) {
        NOP;
    }
    ANALYSER_TOGGLE;
    INTERRUPTION_ON_HARD;

    kern_readTickCount(&tStamp[1]);
    PRIVILEGE_RESTORE;
    *time = tStamp[1] - tStamp[0];
}

#endif
