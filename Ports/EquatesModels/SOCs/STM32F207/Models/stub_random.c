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
#include    "macros_soc.h"
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

    RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN;

    INTERRUPT_VECTOR(HASH_RNG_C0_IRQn, local_RNG_IRQHandler);
    NVIC_SetPriority(HASH_RNG_C0_IRQn, KINT_LEVEL_PERIPHERALS);
    NVIC_EnableIRQ(HASH_RNG_C0_IRQn);
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
// The RNG delivers a new random number every 40 x (1 / 48-MHz) = 333-ns
// Configuration proposed by ST to comply with NIST SP800-90B

    vTerminated = false;
    RNG->CR |= (RNG_CR_RNGEN | RNG_CR_IE);

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

    if (((RNG->SR & RNG_SR_DRDY) != 0U) && ((RNG->SR & RNG_SR_SEIS) == 0U) && ((RNG->SR & RNG_SR_CEIS) == 0U)) {
        *vNumber = RNG->DR & KRAND_MAX;
        vTerminated = true;
        RNG->CR &= ~(RNG_CR_RNGEN | RNG_CR_IE);
        return;
    }

// Seed error
// Read 1 time to clear seed error

    if ((RNG->SR & RNG_SR_SEIS) == RNG_SR_SEIS) {
        RNG->SR &= (uint32_t)~RNG_SR_SEIS;
        RNG->DR;
    }

// Clock error
// !!! Wrong clock configurtion, please fix your code

    if ((RNG->SR & RNG_SR_CEIS) == RNG_SR_CEIS) {
        RNG->SR &= (uint32_t)~RNG_SR_CEIS;
    }
}
