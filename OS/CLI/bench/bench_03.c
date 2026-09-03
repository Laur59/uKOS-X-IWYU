/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Bench 03:   Searching for the min / max of a big square array
 *                       (50000 uint32_t) elements.
 *                       The data is located in the internal memory.
 *                       100 iteractions.
 *
 *           Target used: Nucleo_H743 @ 480-MHz
 *           Target used: Nucleo_N657 @ 600-MHz
 *           Target used: MAiXDUiNO_K210 @ 400-MHz
 *           Target used: Discovery_U5G9 @ 160-MHz
 *
 *           Bench results in [us]:
 *
 *                                       _minMax
 *           Nucleo_H743 @ 480-MHz       117
 *           Nucleo_N657 @ 600-MHz       85
 *           MAiXDUiNO_K210 @ 400-MHz    62
 *           Discovery_U5G9 @ 160-MHz    203
 */

#include    "bench.h"

#include    <stdint.h>
#include    <stdio.h>

#include    "kern/kern.h"
#include    "macros_core.h" // for PRIVILEGE_ELEVATE / PRIVILEGE_RESTORE, needed on
                            // both architectures; on ARM also INTERRUPTION_OFF_HARD
#ifdef __riscv
#include    "macros_soc.h"  // RISC-V: INTERRUPTION_OFF in soc
#endif
#include    "memo/memo.h"
#include    "random/random.h"
#include    "serial/serial.h"

// CLI tool specific
// =================

#define KNB_TESTS       100U
#define KNB_ELEMENTS    50000U

// Prototypes

static  void    local_minMax(const uint32_t *array, uint64_t *time, uint32_t *min, uint32_t *max);

/*
 * \brief bench_03
 *
 * - min / max of an small array
 *
 */
bool    bench_03(void) {
    uint64_t    time, sumTime = 0U;
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
    (void)dprintf(KSYST, "Bench 03: Fill a big 1D array (50000) elements in\n"
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

    PRIVILEGE_ELEVATE;      // INTERRUPTION_OFF_HARD writes the interrupt mask: privileged
    kern_readTickCount(&tStamp[0]);

    INTERRUPTION_OFF_HARD;
    *min = UINT32_MAX; *max = 0U;
    for (i = 0U; i < KNB_ELEMENTS; i++) {
        if (*(array + i) < *min) { *min = *(array + i); }
        if (*(array + i) > *max) { *max = *(array + i); }
    }
    INTERRUPTION_ON_HARD;

    kern_readTickCount(&tStamp[1]);
    PRIVILEGE_RESTORE;
    *time = tStamp[1] - tStamp[0];
}
