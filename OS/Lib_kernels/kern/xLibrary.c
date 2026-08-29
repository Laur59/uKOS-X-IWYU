/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - C library integration for xlib management.
 *
 *           This module is responsible for C library integration with uKOS-X.
 *           For newlib: creating and swapping the impure data (_impure_ptr).
 *           For picolibc and llvmlibc: saving and restoring the global errno
 *           on every switch.
 */

#include    "kern/private/private_xLibrary.h"

#include    <stdint.h>

#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "macros_soc.h"

#ifdef CONFIG_MAN_NEWLIB_S
#include    <sys/reent.h>
#include    "newlib/newlib.h"

// Per-process reentrancy structures for newlib
reent_t     vKern_impureData[KNB_CORES][KKERN_NB_PROCESSES];

#elif defined(CONFIG_MAN_PICOLIBC_S) || defined(CONFIG_MAN_LLVMLIBC_S)
#include    <errno.h>

// No global storage needed - the parked value of errno for a process that is
// not running lives in proc_t.oErrno

#else
#error "No C library configured (CONFIG_MAN_NEWLIB_S, CONFIG_MAN_PICOLIBC_S or CONFIG_MAN_LLVMLIBC_S required)"
#endif

#ifdef CONFIG_MAN_NEWLIB_S

/*
 * \brief Initialise the impure data of the process (newlib)
 *
 * This function initialises the newlib reentrancy structure for the process
 * and sets the process's oLocal pointer to point to this structure.
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]   *handle     Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 */
void    xLibrary_initialise(proc_t *handle) {
    uint16_t    i;
    uint32_t    core;
    proc_t      *process = handle;

    core = GET_RUNNING_CORE;

    i = (uint16_t)(((uintptr_t)process - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));
    _REENT_INIT_PTR(&vKern_impureData[core][i]);
    process->oInternal.oLocal = &vKern_impureData[core][i];
}

/*
 * \brief update the impure pointer with the impure data of the process (newlib)
 *
 * This function updates the global _impure_ptr to point to the current process's
 * reentrancy structure. Called during context switches.
 *
 * \warning call usable only by the uKernel.
 *
 *
 * \note This function does not return a value (None).
 *
 */
void    xLibrary_update(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (vKern_runProc[core]->oInternal.oLocal != nullptr) {
        _impure_ptr = (reent_t *)vKern_runProc[core]->oInternal.oLocal;
    }
}

#elif defined(CONFIG_MAN_PICOLIBC_S) || defined(CONFIG_MAN_LLVMLIBC_S)

/*
 * \brief Initialise the parked errno of the process (picolibc, llvmlibc)
 *
 * Both libraries expose errno as one ordinary global int shared by the library
 * and by every uKOS-X translation unit. A newly created process starts with
 * errno 0; the value is loaded into the global the first time the process is
 * scheduled.
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]   *handle     Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 */
void    xLibrary_initialise(proc_t *handle) {
    proc_t      *process = handle;

    process->oErrno = 0;
}

/*
 * \brief Save and restore the global errno across a context switch
 *
 * picolibc and LLVM libc both keep errno in a single global that the library
 * itself uses, so neither can be redirected per process from the uKOS-X side:
 *
 * - picolibc's __PICOLIBC_ERRNO_FUNCTION hook is a library BUILD-time option;
 *   the shipped libc.a binds to the global regardless.
 * - LLVM libc reads and writes errno through Errno::operator=/operator int(),
 *   which live in the same libc.a member as __llvm_libc_errno() and address the
 *   same storage, so overriding that entry point is a duplicate symbol, not an
 *   override.
 *
 * What both libraries do guarantee is that uKOS-X code and library code reach
 * the *same* int. Parking the outgoing process's value here and loading the
 * incoming one therefore gives errno per-process semantics for the library, the
 * kernel and downloadable applications at once - the same place the newlib
 * build swaps _impure_ptr.
 *
 * Called from scheduler_changeContext() with interrupts off and in privileged
 * mode, after vKern_runProc has been advanced, so vKern_backwardProc still holds
 * the outgoing process. Nothing between the switch decision and this call can
 * touch errno, so the saved value is the outgoing process's final one.
 *
 * \warning On a multi-core image (K210, rp2350) the cores share the library's
 * \warning single errno, so errno remains racy between cores. That is a property
 * \warning of the libraries, not of this swap, and needs real TLS to fix - see
 * \warning Documentation/,USER_GUIDES/TLS_SUPPORT_ASSESSMENT.md.
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
void    xLibrary_update(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (vKern_backwardProc[core] != vKern_runProc[core]) {
        vKern_backwardProc[core]->oErrno = errno;
        errno = vKern_runProc[core]->oErrno;
    }
}

#endif
