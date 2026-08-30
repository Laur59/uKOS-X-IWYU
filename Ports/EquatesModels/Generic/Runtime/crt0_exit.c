/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Process exit and panic handling for the uKOS-X runtime.
 * Split out of crt0.c so that the C-runtime bootstrap stays kernel-agnostic.
 */

#include    "crt0.h"

#include    <inttypes.h>
#include    <stdio.h>
#include    <stdlib.h>

#include    "cmns.h"
#ifndef RV32IMAC_S
#include    "core.h"  // for core_getMSP, core_getPSP
#endif
#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "record/private/private_recordDump.h"
#include    "serial/serial.h"
#include    "types.h"

// Prototypes

static  void    local_killProcess(void);
static  void    local_panicMallocBroken(void);
static  void    local_panicStackUnderflow(void);
static  void    local_panicNoSystemCall(void);
static  void    local_panicElevation(void);
static  void    local_panicGeneral(void);

/*
 * \brief exit_terminate
 *
 * Same behaviour than exit(EXIT_OS_SUCCESS)
 * This call is used to properly terminate the process execution.
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
[[noreturn]]
void    exit_terminate(void) {

    exit(EXIT_OS_SUCCESS);
}

/*
 * \brief crt0_exit
 *
 * code = EXIT_OS_SUCCESS               --->        Success, commit a suicide
 * code = EXIT_OS_FAILURE               --->        Failure; commit a suicide
 * code = EXIT_OS_PANIC                 --->        Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_MALLOC_BROKEN   --->        Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_STACK_UNDERFLOW --->        Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_NO_SYSCALL      --->        Failure; panic. System is stopped
 * code = default                       --->        Failure; panic. System is stopped
 *
 * \param[in]   number  Exit number
 *
 * \note This function does not return a value (None).
 *
 */
void    crt0_exit(int number) {

    switch (number) {
        case EXIT_OS_SUCCESS:
        case EXIT_OS_SUCCESS_CLI:
        case EXIT_OS_FAILURE:                { local_killProcess();         break; }

        case EXIT_OS_PANIC_MALLOC_BROKEN:    { local_panicMallocBroken();   break; }
        case EXIT_OS_PANIC_STACK_UNDERFLOW:  { local_panicStackUnderflow(); break; }
        case EXIT_OS_PANIC_NO_SYSCALL:       { local_panicNoSystemCall();   break; }
        case EXIT_OS_PANIC_ELEVATION:        { local_panicElevation();      break; }

        case EXIT_OS_PANIC:
        default:                             { local_panicGeneral();        break; }
    }

    cmns_send(KSYST, "\n");
    record_printTrace();
    record_printLog();
}

// Local routines
// ==============

/*
 * \brief local_killProcess
 *
 */
[[gnu::noinline, noreturn]]
static  void    local_killProcess(void) {
    proc_t  *process;

    kern_getProcessRun(&process);
    kern_killProcess(process);

// Important: do not remove the "while (true);"

    while (true) { ; }
}

/*
 * \brief local_panicMallocBroken
 *
 */
[[gnu::noinline]]
static  void    local_panicMallocBroken(void) {
    uint32_t    core;
    const       char_t  *identifier;

    core = GET_RUNNING_CORE;

    PRIVILEGE_ELEVATE;
    INTERRUPTION_OFF;

    cmns_send(KSYST, "\nPanic: memo_malloc descriptor broken!\nCurrent process: ");
    identifier = (vKern_runProc[core]->oSpecification.oIdentifier == nullptr) ? "Anonymous" : vKern_runProc[core]->oSpecification.oIdentifier;
    cmns_send(KSYST, identifier); cmns_send(KSYST, "\n");
}

/*
 * \brief local_panicStackUnderflow
 *
 */
[[gnu::noinline]]
static  void    local_panicStackUnderflow(void) {
            uint32_t    core;
            char_t      string[200 + 1];
    const   char_t      *identifier;

    core = GET_RUNNING_CORE;

    PRIVILEGE_ELEVATE;
    INTERRUPTION_OFF;

    cmns_send(KDEF0, "\nPanic: process stack underflow detected!\n");

    identifier = (vKern_runProc[core]->oSpecification.oIdentifier == nullptr) ? "Anonymous" : vKern_runProc[core]->oSpecification.oIdentifier;
    (void)snprintf(&string[0], 200U, "Current process:    %s\n", identifier);
    cmns_send(KDEF0, &string[0]);

    (void)snprintf(&string[0], 200U, "Process code entry: 0x%016"PRIXPTR"\n", (uintptr_t)vKern_runProc[core]->oSpecification.oCode);
    cmns_send(KDEF0, &string[0]);

    (void)snprintf(&string[0], 200U, "Start of Stack:     0x%016"PRIXPTR"\n", (uintptr_t)vKern_runProc[core]->oSpecification.oStackStart);
    cmns_send(KDEF0, &string[0]);

    #ifndef RV32IMAC_S
    uintptr_t   value;

    value = core_getPSP();
    (void)snprintf(&string[0], 200U, "Current Stack PSP:  0x%016"PRIXPTR"\n", value);
    cmns_send(KDEF0, &string[0]);

    value = core_getMSP();
    (void)snprintf(&string[0], 200U, "Current Stack MSP:  0x%016"PRIXPTR"\n", value);
    cmns_send(KDEF0, &string[0]);
    #endif
}

/*
 * \brief local_panicNoSystemCall
 *
 */
[[gnu::noinline]]
static  void    local_panicNoSystemCall(void) {
            uint32_t    core;
    const   char_t      *identifier;

    core = GET_RUNNING_CORE;

    PRIVILEGE_ELEVATE;
    INTERRUPTION_OFF;

    cmns_send(KSYST, "\nPanic: The system call does not exist!\nCurrent process: ");
    identifier = (vKern_runProc[core]->oSpecification.oIdentifier == nullptr) ? "Anonymous" : vKern_runProc[core]->oSpecification.oIdentifier;
    cmns_send(KSYST, identifier); cmns_send(KSYST, "\n");
}

/*
 * \brief local_panicElevation
 *
 */
[[gnu::noinline]]
static  void    local_panicElevation(void) {

    PRIVILEGE_ELEVATE;
    INTERRUPTION_OFF;

    cmns_send(KSYST, "\nPanic: Elevation not allowed!\n");
}

/*
 * \brief local_panicGeneral
 *
 */
[[gnu::noinline]]
static  void    local_panicGeneral(void) {

    PRIVILEGE_ELEVATE;
    INTERRUPTION_OFF;

    cmns_send(KSYST, "\nPanic: system stopped!\n");
}

