/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:        crt0 for the uKOS-X system.
 *          Privileged only support
 *
 *                       CODE
 * linker_stTEXT            +-----------------+
 *                      |                 |
 *                      | .isr_vector     |
 *                      | .text           |
 *                      | .rodata         |
 * linker_enRODATA      |                 |                   DATA
 *                      +-----------------+ ........... +-----------------+ linker_stDATA
 * linker_stINDATA      |                 |             |                 |
 *                      | .data           |             | .data           |
 *                      |                 |             |                 | linker_enDATA
 *                      +-----------------+ ........... +-----------------+
 * linker_stSignature   |                 |             |                 | linker_stBSS
 *                      +-----------------+             | .bss            |
 *                                                      | COMMON          |
 *                                                      |                 | linker_enBSS
 *                                                      +-----------------+
 */

#include    <stdint.h>
#include    <string.h>

#include    "cmns.h"
#include    "init.h"
#include    "linker.h"
#include    "types.h"

// Runtime specific
// ================

uint32_t    vCrt0_randomSeed;

// Prototypes

extern  int     main(int argc, const char_t *argv[]);

/*
 * \brief crt0
 *
 * - Copy the initialised data from the CODE to the DATA region
 * - Initialise the BSS region
 * - Call the main
 *
 */
void    crt0(void) {

    uint32_t    *regionSeed, seed;
    intptr_t    nbWords;

// Initialise the LOW level (!!! No static variables !!!)

    init_init();

    #if (defined(CONFIG_MAN_SERIAL_S))
    cmns_init();
    #endif

// Before to initialise the system RAM, we use its random content
// @ the power-on for generating a random seed usable for the software
// Random Number Generators
//
// seed = seed[k - 1] + memory[k]

    regionSeed = (uint32_t *)linker_stPrgmData;
    nbWords    = (intptr_t)(((uintptr_t)linker_lnPrgmData) / 4);
    seed       = 0u;
    while (nbWords-- > 0) {
        seed += *regionSeed;
        regionSeed++;
    }

// Copy the initialised data from the CODE region to the DATA one
// Initialise the BSS region

    memcpy(linker_stDATA, linker_stINDATA, (size_t)((uintptr_t)linker_enDATA - (uintptr_t)linker_stDATA));
    memset(linker_stBSS,  0x00u,           (size_t)((uintptr_t)linker_enBSS  - (uintptr_t)linker_stBSS));

// Initialise the Heap regions

    memset(linker_stHeap, 0x00u, (size_t)linker_lnHeap);

    vCrt0_randomSeed = seed;

    main(0u, nullptr);
}
