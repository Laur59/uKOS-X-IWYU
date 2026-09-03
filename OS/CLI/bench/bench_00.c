/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Bench 00:   Compute the X-Y projection and the histogram of
 *                       a small square array (50 x 50 uint8_t) elements.
 *                       The data is located in the CPU internal memory
 *
 *           Target used: Nucleo_H743 @ 480-MHz
 *           Target used: Nucleo_N657 @ 600-MHz
 *           Target used: MAiXDUiNO_K210 @ 400-MHz
 *           Target used: Discovery_U5G9 @ 160-MHz
 *
 *           Bench results in [us]:
 *
 *                                       _fill   _projX  _projY  _histo
 *           Nucleo_H743 @ 480-MHz       12      41      18      30
 *           Nucleo_N657 @ 600-MHz       22      34      26      44
 *           MAiXDUiNO_K210 @ 400-MHz    34      39      46      71
 *           Discovery_U5G9 @ 160-MHz    97      114     97      147
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
#include    "serial/serial.h"

// CLI tool specific
// =================

#define KNB_X       50U
#define KNB_Y       50U
#define KMAX_BIT    256U

// Prototypes

static  void    local_fill(uint8_t *array, uint64_t *time);
static  void    local_prjX(const uint8_t *array, uint64_t *time, uint32_t *x);
static  void    local_prjY(const uint8_t *array, uint64_t *time, uint32_t *y);
static  void    local_hist(const uint8_t *array, uint64_t *time, uint32_t *h);

/*
 * \brief bench_00
 *
 * - X-Y projection and histogram of an small array
 *
 */
bool    bench_00(void) {
    uint64_t    time[4];
    uint8_t     *array;
    uint32_t    *x, *y, *h;

    array = (uint8_t  *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KNB_X * (size_t)KNB_Y * sizeof(uint8_t)),  "bench"); if (array == nullptr) {                                               return false; }
    x     = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KNB_X *                 sizeof(uint32_t)), "bench"); if (x == nullptr)     { memo_free(array);                             return false; }
    y     = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KNB_Y *                 sizeof(uint32_t)), "bench"); if (y == nullptr)     { memo_free(array); memo_free(x);               return false; }
    h     = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KMAX_BIT *              sizeof(uint32_t)), "bench"); if (h == nullptr)     { memo_free(array); memo_free(x); memo_free(y); return false; }

    local_fill(array, &time[0]);
    local_prjX(array, &time[1], x);
    local_prjY(array, &time[2], y);
    local_hist(array, &time[3], h);

    memo_free(h);
    memo_free(y);
    memo_free(x);
    memo_free(array);

// Results
//                        Bench xy: Descriptions, comments, ....                 Execution time
// -----------------------|---------|--------------------------------------------|-----------------|
//
    (void)dprintf(KSYST, "Bench 00: Fill a small 2D array (50 x 50) elements in\n"
                         "          the internal memory. Then, compute the\n"
                         "          X-Y projections and the histogram.\n"
                         "          Fill the array                               t = %6lld [us]\n"
                         "          X projection                                 t = %6lld [us]\n"
                         "          Y projection                                 t = %6lld [us]\n"
                         "          Histogram                                    t = %6lld [us]\n\n", time[0], time[1], time[2], time[3]);
    return true;
}

// Local routines
// ==============

/*
 * \brief local_fill
 *
 * - Fill the array with a random number
 *
 */
static  void    local_fill(uint8_t *array, uint64_t *time) {
                uint64_t    tStamp[2];
    register    uint32_t    i, j;

    PRIVILEGE_ELEVATE;      // INTERRUPTION_OFF_HARD writes the interrupt mask: privileged
    kern_readTickCount(&tStamp[0]);

    INTERRUPTION_OFF_HARD;
    for (i = 0U; i < KNB_X; i++) {
        for (j = 0U; j < KNB_Y; j++) {
            *(array + ((size_t)i * (size_t)KNB_Y) + (size_t)j) = (uint8_t)j;
        }
    }
    INTERRUPTION_ON_HARD;

    kern_readTickCount(&tStamp[1]);
    PRIVILEGE_RESTORE;
    *time = tStamp[1] - tStamp[0];
}

/*
 * \brief local_prjX
 *
 * - Compute the X projections
 *
 */
static  void    local_prjX(const uint8_t *array, uint64_t *time, uint32_t *x) {
                uint64_t    tStamp[2];
    register    uint32_t    *p, i, j;

    PRIVILEGE_ELEVATE;      // INTERRUPTION_OFF_HARD writes the interrupt mask: privileged
    kern_readTickCount(&tStamp[0]);

    INTERRUPTION_OFF_HARD;
    for (i = 0U; i < KNB_X; i++) {
        *(x + i) = 0U;
        for (j = 0U; j < KNB_Y; j++) {
            p = (x + i);
            *p += (uint32_t)*(array + ((size_t)j * (size_t)KNB_X) + (size_t)i);
        }
    }
    INTERRUPTION_ON_HARD;

    kern_readTickCount(&tStamp[1]);
    PRIVILEGE_RESTORE;
    *time = tStamp[1] - tStamp[0];
}

/*
 * \brief local_prjY
 *
 * - Compute the Y projections
 *
 */
static  void    local_prjY(const uint8_t *array, uint64_t *time, uint32_t *y) {
                uint64_t    tStamp[2];
    register    uint32_t    *p, i, j, k;

    PRIVILEGE_ELEVATE;      // INTERRUPTION_OFF_HARD writes the interrupt mask: privileged
    kern_readTickCount(&tStamp[0]);

    INTERRUPTION_OFF_HARD;
    for (j = 0U; j < KNB_Y; j++) {
        *(y + j) = 0U;
        k = j * KNB_X;
        for (i = 0U; i < KNB_X; i++) {
            p = (y + j);
            *p += (uint32_t)*(array + k + i);
        }
    }
    INTERRUPTION_ON_HARD;

    kern_readTickCount(&tStamp[1]);
    PRIVILEGE_RESTORE;
    *time = tStamp[1] - tStamp[0];
}

/*
 * \brief local_hist
 *
 * - Compute the histogram
 *
 */
static  void    local_hist(const uint8_t *array, uint64_t *time, uint32_t *h) {
                uint64_t    tStamp[2];
    register    uint32_t    *p, i;

    PRIVILEGE_ELEVATE;      // INTERRUPTION_OFF_HARD writes the interrupt mask: privileged
    kern_readTickCount(&tStamp[0]);

    INTERRUPTION_OFF_HARD;
    p = h;
    for (i = 0U; i < KMAX_BIT; i++) {
        *p = 0U;
        p++;
    }

    for (i = 0U; i < (KNB_X * KNB_Y); i++) {
        p = (uint32_t *)((uintptr_t)h + (*(array + i) * sizeof(uint32_t)));
        *p += 1U;
    }
    INTERRUPTION_ON_HARD;

    kern_readTickCount(&tStamp[1]);
    PRIVILEGE_RESTORE;
    *time = tStamp[1] - tStamp[0];
}
