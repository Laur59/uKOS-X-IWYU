/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; kernel.
; =======

;------------------------------------------------------------------------
; Project: uKOS-X
;
; Purpose:
;   kernel manager (uKernel core).
;
;   The KERN manager operates on a series of linked lists
;   where the processes are located.
;
;   Service system calls
;   --------------------
;
;   int32_t kern_init(void);
;   int32_t kern_runKernel(void);
;   int32_t kern_criticalSection(uint8_t critical);
;   int32_t kern_setSerialForProcess(proc_t *handle, serialManager_t serialManager);
;   int32_t kern_getSerialForProcess(proc_t *handle, serialManager_t *serialManager);
;   int32_t kern_getState(uint8_t *state);
;   int32_t kern_createProcess(const spec_t *specification, const void *argument, proc_t **handle);
;   int32_t kern_killProcess(proc_t *handle);
;   int32_t kern_setPriority(proc_t *handle, priority_t priority);
;   int32_t kern_getPriority(proc_t *handle, priority_t *priority);
;   int32_t kern_getProcessById(const char_t *identifier, proc_t **handle);
;   int32_t kern_getProcessRun(proc_t **handle);
;   int32_t kern_installCallBack(void (*code)(uint8_t state));
;
;   Temporal system calls
;   ---------------------
;
;   int32_t kern_suspendProcess(uint32_t time);
;   int32_t kern_setNewTimeout(proc_t *handle, uint32_t timeout);
;   int32_t kern_resumeProcessWithTimeout(proc_t *handle);
;   int32_t kern_readRemainingProcessTimeout(uint32_t *timeout);
;   int32_t kern_switchFast(void);
;   int32_t kern_readTickCount(uint64_t *tickCount);
;   int32_t kern_waitAtLeast(uint16_t time);
;   int32_t kern_hasPendingTimeoutProcesses(bool *nonInfTOActive);
;
;   Semaphore system calls
;   ----------------------
;
;   int32_t kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle);
;   int32_t kern_signalSemaphore(sema_t *handle);
;   int32_t kern_waitSemaphore(sema_t *handle, uint32_t timeout);
;   int32_t kern_killSemaphore(sema_t *handle);
;   int32_t kern_restartSemaphore(sema_t *handle);
;   int32_t kern_getSemaphoreById(const char_t identifier, sema_t **handle);
;
;   Mutex system calls
;   ------------------
;
;   int32_t kern_createMutex(const char_t *identifier, mutx_t **handle);
;   int32_t kern_unlockMutex(mutx_t *handle);
;   int32_t kern_lockMutex(mutx_t *handle, uint32_t timeout);
;   int32_t kern_killMutex(mutx_t *handle);
;   int32_t kern_restartMutex(mutx_t *handle);
;   int32_t kern_getMutexById(const char_t identifier, mutx_t **handle);
;
;   Mailbox system calls
;   --------------------
;
;   int32_t kern_createMailbox(const char_t *identifier, mbox_t **handle);
;   int32_t kern_setMailbox(mbox_t *handle, const mcnf_t *configure);
;   int32_t kern_writeMailbox(mbox_t *handle, void *message, uint32_t size, uint32_t timeout);
;   int32_t kern_writeQueue(mbox_t *handle, uintptr_t message, uint32_t timeout);
;   int32_t kern_readMailbox(mbox_t *handle, void **message, uint32_t *size, uint32_t timeout);
;   int32_t kern_readQueue(mbox_t *handle, uintptr_t *message, uint32_t timeout);
;   int32_t kern_killMailbox(mbox_t *handle);
;   int32_t kern_getMailboxById(const char_t *identifier, mbox_t **handle);
;
;   Signal system calls
;   -------------------
;
;   int32_t kern_createSignalGroup(const char_t *identifier, sign_t **handle);
;   int32_t kern_createBitSignal(sign_t *handle, uint8_t *bit);
;   int32_t kern_signalSignal(sign_t *handle, uint32_t signals, proc_t *toProcess, uint32_t mode);
;   int32_t kern_waitSignal(sign_t *handle, uint32_t *signals, proc_t *fromProcess, uint32_t timeout);
;   int32_t kern_getWaitingSignalMask(sign_t *handle, uint32_t *waitingSignals);
;   int32_t kern_clearPendingSignal(sign_t *handle, uint32_t toClearMask);
;   int32_t kern_killSignalGroup(sign_t *handle);
;   int32_t kern_killBitSignal(sign_t *handle, uint8_t bitSignal);
;   int32_t kern_getSignalGroupById(char_t *identifier, sign_t **handle);
;
;   Software timer system calls
;   ---------------------------
;
;   int32_t kern_createSoftwareTimer(const char_t *identifier, stim_t **handle);
;   int32_t kern_setSoftwareTimer(stim_t *handle, const tspc_t *configure);
;   int32_t kern_killSoftwareTimer(stim_t *handle);
;   int32_t kern_getSoftwareTimerById(const char_t *identifier, stim_t **handle);
;
;   Precise signals system calls
;   ----------------------------
;
;   int32_t kern_createPreciseSignal(const char_t *identifier, prcs_t **handle);
;   int32_t kern_setPreciseSignal(prcs_t *handle, sign_t **sigGroup, proc_t *toProcess, uint64_t period, uint8_t mode, uint32_t signal);
;   int32_t kern_killPreciseSignal(prcs_t *handle);
;   int32_t kern_getPreciseSignalById(const char_t *identifier, prcs_t **handle);
;
;   Memory pool system calls
;   ------------------------
;
;   int32_t kern_createPool(const char_t *identifier, pool_t **handle);
;   int32_t kern_setPool(pool_t *handle, pcnf_t *configure);
;   int32_t kern_allocateBlock(pool_t *handle, void **address, uint32_t timeout);
;   int32_t kern_deAllocateBlock(pool_t *handle, const void *address);
;   int32_t kern_killPool(pool_t *handle);
;   int32_t kern_getPoolById(const char_t *identifier, pool_t **handle);
;
;   Software debug system calls
;   ---------------------------
;
;   int32_t kern_stopProcess(proc_t *handle);
;   int32_t kern_reactivateProcess(proc_t *handle);
;
;   Privilege system calls
;   ----------------------
;
;   int32_t kern_setPrivilegeMode(uint8_t mode);
;   void    kern_privilegeElevate(void); !!! Not for user applications
;
;   Name equivalence used by the kernel
;   -----------------------------------
;
;   External module names   Internal suffixes   Exported types
;
;   debug                   DEBG                -
;   identifier              -                   -
;   kern                    KERN                -
;   lists                   -                   list_t
;   mailboxes               MBOX                mbox_t, mcnf_t
;   mutexes                 MUTX                mutx_t
;   pools                   POOL                pool_t
;   preciseSignals          PRCS                prcs_t
;   privileges              -                   -
;   processes               PROC                proc_t, spec_t, work_t, stts
;   scheduler               -                   -
;   semaphores              SEMA                sema_t
;   signals                 SIGN                sign_t
;   softwareTimers          STIM                stim_t, tspc_t
;   statistics              -                   -
;   stub                    -                   -
;   temporal                -                   -
;   xLibrary                -                   -
;
;-----
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup kern Kern
 *
 * \brief Kern
 *
 * Kern management
 *
 * @{
 */

#include    <stdint.h>

#include    "serial/serial.h"
#include    "types.h"       // IWYU pragma: keep

// Include Strategy (Hybrid Approach)
// -----------------------------------
//
// Two valid patterns for including kernel headers:
//
// 1. Convenience (traditional RTOS style):
//    #include "kern/kern.h"
//    - Gets all kernel features with one include
//    - Recommended for application code and prototyping
//    - Faster to write, easier for beginners
//
// 2. Strict IWYU (granular includes):
//    #include "kern/processes.h"    // For process management
//    #include "kern/semaphores.h"   // For semaphore operations
//    - Only include what you actually use
//    - Better for IWYU compliance and documentation
//    - Option for strict dependency tracking
//
// Both patterns are supported. Module headers can be included directly
// or transitively through kern.h.
//
// Note: Type definitions, forward declarations, configuration macros, and
// shared enums are in kern/kern_types.h (included by both kern.h and
// individual module headers).

#include    "kern/kern_types.h" // IWYU pragma: export

// IWYU pragma: begin_exports
#include    "kern/privileges.h"
#include    "kern/processes.h"
#include    "kern/mailboxes.h"
#include    "kern/statistics.h"
#include    "kern/semaphores.h"
#include    "kern/mutexes.h"
#include    "kern/signals.h"
#include    "kern/temporal.h"
#include    "kern/debug_list.h"
#include    "kern/softwareTimers.h"
#include    "kern/pools.h"
#include    "kern/preciseSignals.h"
#include    "kern/stub.h"
// IWYU pragma: end_exports

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

extern  bool    is_exception(void);

/*!
 * \brief Initialise the manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_init();
 *    installMyProcesses();
 *    status = kern_runKernel();
 *
 *    while (true) { ; }
 * \endcode
 *
 * - This function initialises the "kern" manager.
 *   Before using the manager functions, it is necessary to
 *   call this function.
 *
 * \param[in]   -
 * \return      KERR_KERN_NOERR OK
 *
 */
extern  int32_t kern_init(void);

/*!
 * \brief Start the multi-process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_init();
 *    installMyProcesses();
 *    status = kern_runKernel();
 *
 *    while (true) { ; }
 * \endcode
 *
 * - Initialise all the timers (1-ms & 20-ms)
 * - Enable the time sharing and all the interruptions
 *
 * \param[in]   -
 * \return      KERR_KERN_NOERR OK
 *
 */
extern  int32_t kern_runKernel(void);

/*!
 * \brief Management of a critical section
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_criticalSection(KENTER_CRITICAL);
 *    ...
 *    Atomic code
 *    ...
 *    status = kern_criticalSection(KEXIT_CRITICAL);
 * \endcode
 *
 * - This function manages the atomic access to a critical section
 *
 * \param[in]   critical        KENTER_CRITICAL, enter in a critical section
 * \param[in]   -               KEXIT_CRITICAL, exit from a critical section
 * \return      KERR_KERN_NOERR OK
 *
 */
extern  int32_t kern_criticalSection(uint8_t critical);

/*!
 * \brief Set the default communication device for a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_setSerialForProcess(process, KURT1);
 * \endcode
 *
 * - This function sets the default communication device for a process
 *
 * \param[in]   *handle         Ptr on the handle
 * \param[in]   serialManager   Serial Communication Manager
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOPRO The process does not exist
 *
 */
extern  int32_t kern_setSerialForProcess(proc_t *handle, serialManager_t serialManager);

/*!
 * \brief Get the default communication device of a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *            uint32_t    serialManager;
 *
 *    status = kern_getSerialForProcess(process, &serialManager);
 * \endcode
 *
 * - This function gets the default communication device of a process
 *
 * \param[in]   *handle         Ptr on the handle
 * \param[in]   *serialManager  Ptr on the Serial Communication Manager
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOPRO The process does not exist
 *
 */
extern  int32_t kern_getSerialForProcess(proc_t *handle, serialManager_t *serialManager);

/*!
 * \brief Get the uKernel state
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    state;
 *
 *    status = kern_getState(&state);
 *    switch (state) {
 *        case: KKERN_NOT_READY    { … break; }
 *        case: KKERN_INITIALISED  { … break; }
 *        case: KKERN_RUNNING      { … break; }
 * \endcode
 *
 * - This function returns the state of the uKernel
 *
 * \param[out]  *state          Ptr on the uKernel state
 * \return      KERR_KERN_NOERR OK
 *
 */
extern  int32_t kern_getState(uint8_t *state);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
