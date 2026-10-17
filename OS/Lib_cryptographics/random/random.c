/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Random number manager: mutex-protected pool read, soft LCG generator, and the
 * hardware generator model of the SoC (model_random_hard.c_inc, Generic fallback).
 */

#include    "random.h"

#include    <stdint.h>
#include    <stdlib.h>

#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"

#ifdef CONFIG_MAN_RANDOM_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "random       random manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "random manager\n"
                                    "==============\n\n"

                                    "This manager ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Random,                         // Module name (the first letter has to be upper case)
    KID_FAM_CRYPTOGRAPHICS,         // Family (defined in the module.h)
    KNUM_RANDOM,                    // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);

// Library specific
// ================

STRG_LOC_CONST(aStrIdSRandom[]) = "Critical_random";
static  mutx_t  *vMutex_Reserve_Random[KNB_CORES];

// Prototypes

static  void    local_init(void);
static  void    model_random_soft_init(void);
static  void    model_random_soft_read(uint32_t *number);
static  void    model_random_hard_init(void);
static  void    model_random_hard_read(uint32_t *number);

/*
 * \brief Read a pool of random numbers
 *
 * Call example in C:
 *
 * \code{.c}
 * #define     KNB_NUMBERS    123
 *
 * int32_t     status;
 * uint32_t    number[KNB_NUMBERS];
 *
 *    status = random_read(KRANDOM_SOFT, &number[0], KNB_NUMBERS);
 * \endcode
 *
 * \param[in]   generator           KRANDOM_SOFT, use the software implementation
 *                                  KRANDOM_HARD, use the hardware implementation
 * \param[out]  *number             Ptr on the number
 * \param[in]   nbNumbers           Number of numbers
 * \return      KERR_RANDOM_NOERR   OK
 * \return      KERR_RANDOM_GEERR   General error
 *
 */
int32_t random_read(randomGenerator_t generator, uint32_t *number, uint32_t nbNumbers) {
    uint32_t    core, i, *wkNumber = number;

    core = GET_RUNNING_CORE;

    PRIVILEGE_ELEVATE;
    local_init();

    if ((number == nullptr) || (nbNumbers == 0U) || ((generator != KRANDOM_SOFT) && (generator != KRANDOM_HARD))) {
        PRIVILEGE_RESTORE;
        return KERR_RANDOM_GEERR;
    }

    kern_lockMutex(vMutex_Reserve_Random[core], KWAIT_INFINITY);
    for (i = 0U; i < nbNumbers; i++) {
        if (generator == KRANDOM_SOFT) { model_random_soft_read(wkNumber); }
        else                           { model_random_hard_read(wkNumber); }
        wkNumber++;
    }
    kern_unlockMutex(vMutex_Reserve_Random[core]);
    PRIVILEGE_RESTORE;
    return KERR_RANDOM_NOERR;
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static  void    local_init(void) {
            uint32_t    core;
    static  bool        vInit[KNB_CORES] = MCSET(false);

    core = GET_RUNNING_CORE;

    INTERRUPTION_OFF;
    if (!vInit[core]) {
        vInit[core] = true;

        if (kern_createMutex(aStrIdSRandom, &vMutex_Reserve_Random[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "rand: create mutx"); exit(EXIT_OS_PANIC); }

        model_random_soft_init();
        model_random_hard_init();
    }
    INTERRUPTION_RESTORE;
}

// Soft generator
// ==============

// Linear congruential generator (LCG) with the BSD constants
// X[n + 1] = (Ka * X[n] + Kc) mod Km, X[0] = the crt0 seed
// !!! Only positive constants

#define Ka  1103515245U
#define Kc  12345U
#define Km  KRAND_MAX

extern  uint32_t    vCrt0_randomSeed;
static  uint32_t    vSeed[KNB_CORES] = MCSET(0U);

/*
 * \brief model_random_soft_init
 *
 * - Initialise the seed
 *
 */
static  void    model_random_soft_init(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    vSeed[core] = vCrt0_randomSeed;
}

/*
 * \brief model_random_soft_read
 *
 * - Read a pseudo random number
 *
 */
static  void    model_random_soft_read(uint32_t *number) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    INTERRUPTION_OFF;
    vSeed[core] = ((Ka * vSeed[core]) + Kc) % Km;
    *number = vSeed[core];
    INTERRUPTION_RESTORE;
}

// Hardware generator
// ==================

// The model of the SoC (Ports/EquatesModels/SOCs/<SOC>/Models), or the Generic
// fallback that serves KRANDOM_HARD from the soft generator: the include path
// lists the SoC directory before the Generic one, so the bare name selects it.

#include    "model_random_hard.c_inc"   // IWYU pragma: keep

#endif
