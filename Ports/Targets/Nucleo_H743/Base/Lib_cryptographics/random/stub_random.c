/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Nucleo_H743 – Stub for the random manager.
 */

#include    <stdint.h>

#include    "os_errors.h"
#include    "random/random.h"

// Prototypes

static  void    model_random_hard_init(void);
static  void    model_random_hard_read(uint32_t *number);

/*
 * \brief stub_random_init
 *
 * - Initialise some specific CPU parts
 *
 */
int32_t stub_random_init(void) {

    model_random_soft_init();
    model_random_hard_init();
    return KERR_RANDOM_NOERR;
}

/*
 * \brief stub_random_read
 *
 * - Return the random number
 *
 */
int32_t stub_random_read(randomGenerator_t generator, uint32_t *number) {

    if (generator == KRANDOM_SOFT) { model_random_soft_read(number); return KERR_RANDOM_NOERR; }
    if (generator == KRANDOM_HARD) { model_random_hard_read(number); return KERR_RANDOM_NOERR; }
    return KERR_RANDOM_GEERR;
}

// Local routines
// ==============

#include    "model_random_hard.c_inc"       // IWYU pragma: keep
