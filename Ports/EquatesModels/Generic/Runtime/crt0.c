/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     crt0 for the uKOS-X system.
 *           Privileged only support
 *
 *                       CODE
 * linker_stTEXT         +-----------------+
 *                       |                 |
 *                       | .isr_vector     |
 *                       | .text           |
 *                       | .rodata         |
 * linker_enRODATA       |                 |                   DATA
 *                       +-----------------+ ........... +-----------------+ linker_stDATA
 * linker_stINDATA       |                 |             |                 |
 *                       | .data           |             | .data           |
 *                       |                 |             |                 | linker_enDATA
 *                       +-----------------+ ........... +-----------------+
 * linker_stSignature    |                 |             |                 | linker_stBSS
 *                       +-----------------+             | .bss            |
 *                                                       | COMMON          |
 *                                                       |                 | linker_enBSS
 *                                                       +-----------------+
 */

#include    "crt0.h"

#include    <stdint.h>
#include    <stdlib.h>
#include    <string.h>

#include    "cmns.h"
#include    "exit_codes.h"
#include    "init.h"
#include    "linker.h"
#include    "macros.h"
#include    "macros_core.h"

// crt0 contract
// =============
//
// This translation unit is the C-runtime bootstrap and may only reference
// the following symbols. Anything outside this list is a layering violation
// (kernel APIs, process structs, vKern_* globals belong in crt0_exit.c).
//
//   init_init()              - Low-level pre-init, no statics       (init.h)
//   exce_init()              - Install ISR/exception vectors        (crt0.h)
//   init_relocate() (weak)   - Vector-table relocation hook         (this file)
//   boot()                   - Returns int, called as exit(boot())  (crt0.h)
//   cmns_send(channel, str)  - Project-wide console output          (cmns.h)
//   EXIT_OS_PANIC            - Stack-smash exit code                (exit_codes.h)
//   linker_st*, linker_en*   - Section bounds, __stack_chk_guard    (linker.h)
//   GET_RUNNING_CORE, KCORE_0- Multicore guard                      (macros_soc.h)
//   PRIVILEGE_ELEVATE, INTERRUPTION_OFF                             (macros_core.h)
//
// Runtime specific
// ================

uint32_t    vCrt0_randomSeed;

// For the stack guard, only 32 and 64-bit machines are considered

extern  uintptr_t   __stack_chk_guard;

#if (UINTPTR_MAX == 0xFFFFFFFFU)
#define KSTACK_GUARD_VALUE  0xDeadBeefU

#else
#define KSTACK_GUARD_VALUE  0xDeadBeeffeeBdaeDU
#endif

// Prototypes

[[gnu::weak]]
void    init_relocate(void);      // NOLINT(misc-use-internal-linkage): weak symbol must have external linkage

/*
 * \brief crt0
 *
 * - ONLY for the core 0 !!!
 * - Copy the initialised data from the CODE to the DATA region
 * - Initialise the BSS region
 * - Call the main
 *
 */
void    crt0(void) {
            intptr_t    nbWords;
            uint32_t    core, seed;
    const   uint32_t    *regionSeed;

    core = GET_RUNNING_CORE;

// Initialise the LOW level (!!! No static variables !!!)

    init_init();

    if (core == KCORE_0) {

        init_C0_init();
        cmns_init();

// Before to initialise the system RAM, we use its random content
// @ the power-on for generating a random seed usable for the software
// Random Number Generators
//
// seed = seed[k - 1] + memory[k]

        #ifdef PRIVILEGED_USER_S
        regionSeed = ALIGNED_PTR(const uint32_t, linker_stPrgmData_u);

        nbWords    = (intptr_t)(((uintptr_t)linker_lnPrgmData_u) / 4U);
        seed       = 0U;
        while (nbWords-- > 0) {
            seed += *regionSeed;
            regionSeed++;
        }

// Copy the initialised data from the CODE region to the DATA one
// Initialise the BSS region

        memcpy(linker_stDATA_p, linker_stINDATA_p, (size_t)((uintptr_t)linker_enDATA_p - (uintptr_t)linker_stDATA_p));
        memcpy(linker_stDATA_u, linker_stINDATA_u, (size_t)((uintptr_t)linker_enDATA_u - (uintptr_t)linker_stDATA_u));
        memset(linker_stBSS_p,  0x00U,             (size_t)((uintptr_t)linker_enBSS_p  - (uintptr_t)linker_stBSS_p));
        memset(linker_stBSS_u,  0x00U,             (size_t)((uintptr_t)linker_enBSS_u  - (uintptr_t)linker_stBSS_u));
        #ifdef __clang__
        memset(linker_stTBSS,   0x00U,             (size_t)((uintptr_t)linker_enTBSS   - (uintptr_t)linker_stTBSS));
        #endif

        #else
        regionSeed = ALIGNED_PTR(uint32_t, linker_stPrgmData);

        nbWords    = (intptr_t)(((uintptr_t)linker_lnPrgmData) / 4);
        seed       = 0U;
        while (nbWords-- > 0) {
            seed += *regionSeed;
            regionSeed++;
        }

// Copy the initialised data from the CODE region to the DATA one
// Initialise the BSS region

        memcpy(linker_stDATA, linker_stINDATA, (size_t)((uintptr_t)linker_enDATA - (uintptr_t)linker_stDATA));
        memset(linker_stBSS,  0x00U,           (size_t)((uintptr_t)linker_enBSS  - (uintptr_t)linker_stBSS));
        #ifdef __clang__
        memset(linker_stTBSS, 0x00U,           (size_t)((uintptr_t)linker_enTBSS - (uintptr_t)linker_stTBSS));
        #endif
        #endif

// Initialise the Heap regions

        memset(linker_stHeap, 0x00U, (size_t)linker_lnHeap);

        vCrt0_randomSeed = seed;

        __stack_chk_guard = KSTACK_GUARD_VALUE;
    }

// Initialise the interruption and exception vectors
// Go to the main

    exce_init();
    init_relocate();
    exit(boot());
}

/*
 * \brief init_relocate
 *
 * - If necessary, in the module init.c there is the
 *   vector table relocation
 *
 */
[[gnu::weak]]
void    init_relocate(void) {

}

/*
 * \brief init_relocate
 *
 * - If necessary, dedicated initialsiation for core 0 only
 *
 */
[[gnu::weak]]
void    init_C0_init(void) {

}

/*
 * \brief __wrap___stack_chk_fail
 *
 * - Stack smashing detection
 *   - Stop the system & display a message
 *
 * in the makefile add the following lines
 *
 *   CFLAGS  += -fstack-protector-strong
 *   LDFLAGS += -Wl,--wrap=__stack_chk_fail
 *
 */
[[noreturn]]
void    __wrap___stack_chk_fail(void) {  // NOLINT(misc-use-internal-linkage): linker wrap mechanism requires external linkage

    PRIVILEGE_ELEVATE;
    INTERRUPTION_OFF;
    cmns_send(KSYST, "\nStack smashing!");
    exit(EXIT_OS_PANIC);
}
