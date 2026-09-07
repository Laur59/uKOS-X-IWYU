/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Environment for the host tests that compile the REAL kernel.
 *
 * Contrast fakes/ukos_fakes_kern.h, which is the opposite arrangement: there the
 * kernel is faked so a CLI module can be tested, and it DEFINES vKern_mutx,
 * vKern_sema, vKern_proc, vKern_mbox, vKern_sign and fourteen counters. Here the
 * kernel sources are real and define those themselves, so the two must never be
 * linked into one executable. The separation is structural - ukos_kern_support
 * does not link ukos_port_support - rather than a naming convention, and a
 * mistake shows up as a duplicate symbol at link rather than as a silent
 * substitution.
 *
 * What is faked here is only what surrounds the kernel: the interrupt mask, the
 * running core, and (from the pools suite onwards) the allocator, the log and
 * the semaphore calls that pools is built on.
 */

#ifndef UKOS_FAKES_KERNENV_H
#define UKOS_FAKES_KERNENV_H    1

#include    <stdbool.h>
#include    <stdint.h>

#include    "kern/kern.h"

// Interrupt mask model
// ====================
//
// INTERRUPTION_OFF / INTERRUPTION_RESTORE (port/macros_soc.h) are a scoped
// save/restore pair on the target, not an on/off pair: OFF declares a local and
// RESTORE reads it. The fake keeps a depth and hands out a token so the order
// is checked too, because the real macro restores a saved BASEPRI and therefore
// only behaves correctly when the pairs unwind LIFO.
//
// oUnbalanced latches; oReason names the first offence, so a test that ends with
// interrupts still masked says which rule was broken rather than only that one
// was.

typedef struct {
            uint32_t    oDepth;             // Currently open INTERRUPTION_OFF scopes
            uint32_t    oMaxDepth;          // High-water mark, per test
            uint32_t    oNbOff;             // Total INTERRUPTION_OFF seen
            uint32_t    oNbRestore;         // Total INTERRUPTION_RESTORE seen
            bool        oUnbalanced;        // Latched: an ordering or pairing offence
    const   char        *oReason;           // First offence, or nullptr

            uint32_t    oRunningCore;       // What GET_RUNNING_CORE returns

// LOG() from the kernel. lists.c reaches it only on its two nullptr panics,
// which end in exit() and so cannot be driven from a test - but the symbol
// still has to link.

            uint32_t    oNbLog;              // record_log() calls
            uint32_t    oLastLogCategory;    // Category of the last one
    const   char        *oLastLogMessage;    // Message of the last one

// Allocator. calloc-backed, so asan sees a real heap block and an overrun of a
// pool's block array is a reported heap-buffer-overflow rather than silence.
//
// oFailMallocOnCall is the 1-based index of the allocation to fail; 0 never
// fails. An index rather than a "fail the next" flag because kern_setPool
// allocates TWICE in a row and its two failure arms unwind differently - the
// second has to free what the first returned - so a test must be able to choose
// which one fails without getting between them.

            uint32_t    oNbMalloc;           // memo_malloc() calls
            uint32_t    oNbFree;             // memo_free() calls
            uint32_t    oLastMallocSize;     // Size requested by the last one
            uint32_t    oFailMallocOnCall;   // Fail the Nth allocation (1-based); 0 = never

// Semaphores. pools.c is built on them - a pool owns a release semaphore - but
// semaphores.c is not linked here, so the four calls it makes are doubles.
// Mirrors of semaphores.c:105/142/188/224; the contract they reproduce is that
// create yields a distinct handle and the rest are status-only.

            uint32_t    oNbSemaCreate;       // kern_createSemaphore() calls
            uint32_t    oNbSemaWait;         // kern_waitSemaphore() calls
            uint32_t    oNbSemaSignal;       // kern_signalSemaphore() calls
            uint32_t    oNbSemaKill;         // kern_killSemaphore() calls
            int32_t     oRcSemaCreate;       // What create returns
            int32_t     oRcSemaWait;         // What wait returns

// Privilege transitions. PRIVILEGE_ELEVATE / PRIVILEGE_RESTORE expand to
// kern_setPrivilegeMode() when PRIVILEGED_USER_S is defined, and privileges.c -
// which defines the real one - is board-only ([[gnu::naked]], SET_PRIVILEGED_MODE,
// an SVC). The trace records the order, which is what catches an early return
// that elevates and never restores. Same model as ukos_fakes_kern.c:368-393, and
// the same honesty limit: order and pairing, never effect.

// Execution context and blocking.
//
// oIsException drives IS_EXCEPTION, which is the only route into the
// KERR_KERN_FRISR "called from an ISR" arms of the primitives.
//
// oNbGotoKern / oLastKernMessage record GOTO_KERN_M and GOTO_KERN_I. Read the
// warning in port/macros_core_stackFrame.h before trusting them: on a target
// that macro does not return, so what these count is the DECISION to block, not
// a suspension.

            bool        oIsException;        // What IS_EXCEPTION returns
            uint32_t    oNbPreemption;       // PREEMPTION requests
            uint32_t    oNbGotoKern;         // GOTO_KERN_M / _I reached
            uint32_t    oLastKernMessage;    // Message code of the last one

// The tick. mailboxes.c timestamps every pack through kern_readTickCount(),
// which lives in temporal.c - not linked here. Monotonic and settable, so a
// test can assert that a write and a read stamped different packs without
// depending on a real clock.

            uint64_t    oTickCount;          // What kern_readTickCount() returns
            uint32_t    oNbReadTick;         // Calls to it

            uint32_t    oNbElevate;          // PRIVILEGE_ELEVATE seen
            uint32_t    oNbRestorePriv;      // PRIVILEGE_RESTORE seen
            uint8_t     oPrivTrace[64];      // KPROC_PRIVILEGED / KPROC_USER, in order
            uint32_t    oPrivTraceLen;
} ukos_kernenv_t;

extern  ukos_kernenv_t  g_kernenv;

// The running process
// ===================
//
// vKern_runProc is normally defined by processes.c, which this tier does not
// link (it needs KERN_PREPARE_FRAME, a synthetic exception frame with no host
// equivalent). Defined here instead, pointing at a descriptor the test owns, so
// modules that only bump a counter through it - statistics.c, pools.c - work
// unchanged.
//
// When processes.c does eventually join a kern suite this definition has to go,
// or it becomes the duplicate symbol the tier separation is designed to make
// loud rather than silent.

extern  void    ukos_fake_setRunningProcess(proc_t *process);

// Pretend the next call happens inside an interrupt handler.

extern  void    ukos_fake_setException(bool inException);

// true when every INTERRUPTION_OFF has been matched, in order, and none was
// restored twice. Assert it after EVERY kernel call - that is the whole point.

extern  bool    ukos_fake_interruptsBalanced(void);

// true when every PRIVILEGE_ELEVATE was matched by a PRIVILEGE_RESTORE, in
// order and without nesting. Always true in a _nouser build, where both macros
// expand to nothing.

extern  bool    ukos_fake_privilegeBalanced(void);

// Set what GET_RUNNING_CORE returns. Only meaningful when a suite raises
// KNB_CORES above 1, which runs on no board and must be commented at the call
// site.

extern  void    ukos_fake_setRunningCore(uint32_t core);

#endif
