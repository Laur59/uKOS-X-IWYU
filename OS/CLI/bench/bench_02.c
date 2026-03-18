/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Bench 02:   Searching for the min / max of a small square array
 *                       (1000 uint32_t) elements.
 *                       The data is located in the CPU internal memory.
 *                       1000 iteractions.
 *
 *           Target used: Nucleo_H743 @ 480-MHz
 *           Target used: Nucleo_N657 @ 600-MHz
 *           Target used: MAiXDUiNO_K210 @ 400-MHz
 *           Target used: Discovery_U5G9 @ 160-MHz
 *
 *           Bench results in [us]:
 *
 *                                       _minMax
 *           Nucleo_H743 @ 480-MHz       1131
 *           Nucleo_N657 @ 600-MHz       857
 *           MAiXDUiNO_K210 @ 400-MHz    574
 *           Discovery_U5G9 @ 160-MHz    2052
 */

#include    "bench.h"

#include    <stdio.h>
#include    <stdint.h>

#include    "kern/kern.h"
#ifdef __arm__
#include    "macros_core.h" // ARM: INTERRUPTION_OFF in core
#endif
#ifdef __riscv
#include    "macros_soc.h"  // RISC-V: INTERRUPTION_OFF in soc
#endif
#include    "memo/memo.h"
#include    "random/random.h"
#include    "serial/serial.h"

#define KNB_TESTS       1000U
#define KNB_ELEMENTS    1000U

// CLI tool specific
// =================

static  void    local_minMax(const uint32_t *array, uint64_t *time, uint32_t *min, uint32_t *max);

/*
 * \brief bench_02
 *
 * - min / max of an small array
 *
 */
bool    bench_02(void) {
    uint64_t    time, sumTime = 0;
    uint32_t    i, j, *array, value, min, max;

    array = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, (KNB_ELEMENTS * sizeof(uint32_t)), "bench"); if (array == nullptr) { return false; }

// Initialise the array with a random value

    for (j = 0U; j < KNB_TESTS; j++) {
        for (i = 0U; i < KNB_ELEMENTS; i++) {
            random_read(KRANDOM_SOFT, &value, 1U);
            *(array + i) = value;
        }
        local_minMax(array, &time, &min, &max);
        sumTime += time;
    }

    memo_free(array);

// Results
//                        Bench xy: Descriptions, comments, ....                 Execution time
// -----------------------|---------|--------------------------------------------|-----------------|
//
    (void)dprintf(KSYST, "Bench 02: Fill a small 1D array (1000) elements in\n"
                         "          the internal memory with a random pattern.\n"
                         "          Then, compute the min / max values.\n"
                         "          Number of tests                              n = %6d [-]\n"
                         "          Min / Max                                    t = %6lld [us]\n\n", KNB_TESTS, sumTime);
    return true;
}

// Local routines
// ==============

/*
 * \brief local_minMax
 *
 * - Compute the min / max of an array
 *
 */
static  void    local_minMax(const uint32_t *array, uint64_t *time, uint32_t *min, uint32_t *max) {
    uint64_t    tStamp[2];
    uint32_t    i;

    kern_readTickCount(&tStamp[0]);

    INTERRUPTION_OFF_HARD;
    *min = UINT32_MAX; *max = 0U;
    for (i = 0U; i < KNB_ELEMENTS; i++) {
        if (*(array + i) < *min) { *min = *(array + i); }
        if (*(array + i) > *max) { *max = *(array + i); }
    }
    INTERRUPTION_ON_HARD;

    kern_readTickCount(&tStamp[1]);
    *time = tStamp[1] - tStamp[0];
}
