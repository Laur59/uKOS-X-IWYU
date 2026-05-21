/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "random" manager module.
 */

#include    <stdint.h>

#include    "Registers/nvic.h"
#include    "kern/kern.h"
#include    "macros_core.h"
#include    "macros_soc.h"      // for KINT_LEVEL_PERIPHERALS
#include    "os_errors.h"
#include    "random/random.h"
#include    "soc_reg.h"

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

static              bool        vTerminated = false;
static  volatile    uint32_t    *vNumber;

// Prototypes

static  void    local_RNG_IRQHandler(void);

/*
 * \brief model_random_hard_init
 *
 * - Initialise the hardware
 *
 */
void    model_random_hard_init(void) {

    REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_RNGEN;

    INTERRUPT_VECTOR(RNG_C0_IRQn, local_RNG_IRQHandler);
    NVIC_SetPriority(RNG_C0_IRQn, KINT_LEVEL_PERIPHERALS);
    NVIC_EnableIRQ(RNG_C0_IRQn);
}

/*
 * \brief model_random_hard_read
 *
 * - Get a random number
 *
 */
void    model_random_hard_read(uint32_t *number) {

    vNumber = number;

// Turn on the RNG
// The RNG delivers a new random number every 412 x (1 / 160-MHz) = 2575-ns
// Configuration proposed by ST to comply with NIST SP800-90B

    vTerminated = false;
    REG(RNG)->CR |= (RNG_CR_RNGEN | RNG_CR_IE);

    while (!vTerminated) {
        kern_switchFast();
    }
}

// Local routines
// ==============

/*
 * \brief local_RNG_IRQHandler
 *
 * - Interruption new number
 *
 */
static  void    local_RNG_IRQHandler(void) {

// Is data ready, no seed error, no clock error

    if (((REG(RNG)->SR & RNG_SR_DRDY) != 0U) && ((REG(RNG)->SR & RNG_SR_SEIS) == 0U) && ((REG(RNG)->SR & RNG_SR_CEIS) == 0U)) {
        *vNumber = REG(RNG)->DR & KRAND_MAX;
        vTerminated = true;
        REG(RNG)->CR &= ~(RNG_CR_RNGEN | RNG_CR_IE);
        return;
    }

// Seed error

    if ((REG(RNG)->SR & RNG_SR_SEIS) == RNG_SR_SEIS) {
        REG(RNG)->SR &= (uint32_t)~RNG_SR_SEIS;
        REG(RNG)->CR |=  RNG_CR_CONDRST;
        REG(RNG)->CR &= (uint32_t)~RNG_CR_CONDRST;
    }

// Clock error
// !!! Wrong clock configurtion, please fix your code

    if ((REG(RNG)->SR & RNG_SR_CEIS) == RNG_SR_CEIS) {
        REG(RNG)->SR &= (uint32_t)~RNG_SR_CEIS;
    }
}
