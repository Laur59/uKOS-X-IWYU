/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Environment for the host tests that compile the REAL kernel.
 */

#include    "ukos_fakes_kernenv.h"

#include    <stdbool.h>
#include    <stdint.h>

#include    <stdlib.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "macros_soc.h"
#include    "memo/memo.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"
#include    "ukos_test.h"

// The stub port headers must win over the real ones, which are also on the
// include path (OS/Lib_kernels pulls kern.h, and kern.h reaches macros_soc.h
// through privileges.h). Same canary as ukos_fakes_kern.c.

#if !defined(UKOS_PORT_STUB_MACROS_SOC_H)
#error  "the real macros_soc.h was resolved; port/ must come first on the include path"
#endif

ukos_kernenv_t  g_kernenv;

// Defined here rather than by processes.c - see the header.

proc_t  *vKern_runProc[KNB_CORES];

// The ready list. semaphores.c and mutexes.c move a woken process onto it, so
// a suite that compiles either of them needs it to exist and to be a real,
// walkable list - lists.c is linked for real alongside.

list_t  vKern_listExec[KNB_CORES];

// The process table. signals.c derives a process's index from its OFFSET into
// this array - (toProcess - &vKern_proc[core][0]) / sizeof(proc_t) - and uses
// it to subscript sign_t.oSynchro[]. A test process that is not inside the
// array therefore produces a garbage index and an out-of-bounds write, so a
// signals suite must take its processes from here rather than from its own
// statics.

proc_t  vKern_proc[KNB_CORES][KKERN_NB_PROCESSES];

/*
 * \brief Enter an INTERRUPTION_OFF scope
 *
 * - Returns the depth this scope must unwind back to, which
 *   ukos_fake_intRestore() checks. On the target the returned value is the
 *   saved BASEPRI; here it is a token, because what is worth asserting on a
 *   host is the pairing and the order, not the register value.
 *
 */
uint32_t    ukos_fake_intOff(void) {
    uint32_t    token;

    token = g_kernenv.oDepth;
    g_kernenv.oDepth++;
    g_kernenv.oNbOff++;

    if (g_kernenv.oDepth > g_kernenv.oMaxDepth) {
        g_kernenv.oMaxDepth = g_kernenv.oDepth;
    }
    return token;
}

/*
 * \brief Leave an INTERRUPTION_OFF scope
 *
 * \param[in]   token   The value INTERRUPTION_OFF stored in saveBASEPRI
 *
 */
void    ukos_fake_intRestore(uint32_t token) {

    g_kernenv.oNbRestore++;

// A restore with nothing open. On the target this writes a stale BASEPRI and
// silently re-enables interrupts the caller never masked.

    if (g_kernenv.oDepth == 0U) {
        g_kernenv.oUnbalanced = true;
        if (g_kernenv.oReason == nullptr) {
            g_kernenv.oReason = "INTERRUPTION_RESTORE with no INTERRUPTION_OFF open";
        }
        return;
    }

    g_kernenv.oDepth--;

// Out of order. The real macro restores a saved mask, so overlapping scopes
// re-enable interrupts early - which is why the order is checked and not just
// the count.

    if (token != g_kernenv.oDepth) {
        g_kernenv.oUnbalanced = true;
        if (g_kernenv.oReason == nullptr) {
            g_kernenv.oReason = "INTERRUPTION_RESTORE out of order (scopes do not unwind LIFO)";
        }
    }
}

/*
 * \brief Are the interrupt scopes balanced?
 *
 */
bool    ukos_fake_interruptsBalanced(void) {

    if ((g_kernenv.oDepth != 0U) && (g_kernenv.oReason == nullptr)) {
        g_kernenv.oReason = "returned with INTERRUPTION_OFF still open";
    }
    return ((g_kernenv.oDepth == 0U) && (!g_kernenv.oUnbalanced));
}

/*
 * \brief kern_setPrivilegeMode
 *
 * - What PRIVILEGE_ELEVATE and PRIVILEGE_RESTORE expand to. The real one
 *   (privileges.c:88) issues an SVC and flips CONTROL.nPRIV; nothing of that is
 *   reproducible on a host, so this records the transition and the test asserts
 *   the sequence.
 *
 */
int32_t     kern_setPrivilegeMode(uint8_t mode) {

    if (mode == KPROC_PRIVILEGED) { g_kernenv.oNbElevate++;     }
    else                          { g_kernenv.oNbRestorePriv++; }

    if (g_kernenv.oPrivTraceLen < (uint32_t)(sizeof(g_kernenv.oPrivTrace) / sizeof(g_kernenv.oPrivTrace[0]))) {
        g_kernenv.oPrivTrace[g_kernenv.oPrivTraceLen] = mode;
        g_kernenv.oPrivTraceLen++;
    }
    return 0;
}

/*
 * \brief Are the privilege transitions balanced?
 *
 */
bool    ukos_fake_privilegeBalanced(void) {
    int32_t     depth = 0;
    uint32_t    i;

    for (i = 0U; i < g_kernenv.oPrivTraceLen; i++) {
        depth += (g_kernenv.oPrivTrace[i] == KPROC_PRIVILEGED) ? 1 : -1;

        if ((depth < 0) || (depth > 1)) {
            return false;                       // restored without elevating, or nested
        }
    }
    return (depth == 0);
}

/*
 * \brief GET_RUNNING_CORE
 *
 */
uint32_t    ukos_fake_runningCore(void) {

    return g_kernenv.oRunningCore;
}

/*
 * \brief Set what GET_RUNNING_CORE returns
 *
 */
void    ukos_fake_setRunningCore(uint32_t core) {

    g_kernenv.oRunningCore = core;
}

/*
 * \brief Point vKern_runProc at a descriptor the test owns
 *
 */
void    ukos_fake_setRunningProcess(proc_t *process) {

    vKern_runProc[g_kernenv.oRunningCore] = process;
}

// Allocator
// =========

/*
 * \brief memo_malloc
 *
 * - Mirror of OS/Lib_generics/memo/memo.c:108. calloc rather than a static
 *   arena on purpose: asan then guards both ends of every pool block array, so
 *   an off-by-one in the block arithmetic is a reported overflow instead of a
 *   quiet neighbouring write.
 *
 */
void    *memo_malloc([[maybe_unused]] memoAlignement_t memoAlignement, uint32_t size,
                     [[maybe_unused]] const char_t *identifier) {

    g_kernenv.oNbMalloc++;
    g_kernenv.oLastMallocSize = size;

    if (g_kernenv.oNbMalloc == g_kernenv.oFailMallocOnCall) {
        return nullptr;
    }
    return calloc((size_t)1, (size_t)size);
}

/*
 * \brief memo_free
 *
 */
void    memo_free(void *address) {

    g_kernenv.oNbFree++;
    free(address);
}

/*
 * \brief IS_EXCEPTION
 *
 */
bool    ukos_fake_isException(void) {

    return g_kernenv.oIsException;
}

/*
 * \brief Pretend to be inside an interrupt handler
 *
 */
void    ukos_fake_setException(bool inException) {

    g_kernenv.oIsException = inException;
}

/*
 * \brief PREEMPTION
 *
 * - The real macro pends PendSV and executes sev plus three barriers. Here it
 *   only counts: a test asserts that the kernel decided a preemption was due,
 *   never that a context switch happened.
 *
 */
void    ukos_fake_preemption(void) {

    g_kernenv.oNbPreemption++;
}

/*
 * \brief GOTO_KERN_M / GOTO_KERN_I
 *
 * - Records the message and RETURNS, which the real macro never does. The
 *   consequences are set out at length in port/macros_core_stackFrame.h; the
 *   short version is that the caller then reads
 *   vKern_runProc[core]->oInternal.oStatus, and a test seeds that field to say
 *   what the scheduler would have reported.
 *
 */
void    ukos_fake_gotoKern(uint32_t message) {

    g_kernenv.oNbGotoKern++;
    g_kernenv.oLastKernMessage = message;
}

/*
 * \brief kern_readTickCount
 *
 * - Mirror of temporal.c:317, reduced to a counter. Advances by one on every
 *   call so successive timestamps differ, which is the only property the
 *   mailbox pack stamps depend on.
 *
 */
int32_t     kern_readTickCount(uint64_t *tickCount) {

    g_kernenv.oNbReadTick++;
    g_kernenv.oTickCount++;
    *tickCount = g_kernenv.oTickCount;
    return KERR_KERN_NOERR;
}

/*
 * \brief LOG()
 *
 * - Mirror of OS/Lib_generics/record/record.c:142, reduced to what a kernel
 *   test can observe. The real one timestamps into a per-core ring buffer that
 *   this tier has no reason to carry.
 *
 */
int32_t     record_log(recordLogCategory_t category, [[maybe_unused]] uint32_t line,
                       [[maybe_unused]] const char_t *function, const char_t *message) {

    g_kernenv.oNbLog++;
    g_kernenv.oLastLogCategory = (uint32_t)category;
    g_kernenv.oLastLogMessage  = message;
    return 0;
}

// Reset
// =====
//
// Registered from a constructor rather than called by ukos_t_begin() directly:
// the harness must not depend on this library, and a weak symbol across two
// static archives resolves by link order on Mach-O. Same idiom as
// ukos_fakes_kern.c and port/linker_symbols.c.

/*
 * \brief Clear the environment between tests
 *
 */
static  void    local_reset(void) {

    g_kernenv.oDepth      = 0U;
    g_kernenv.oMaxDepth   = 0U;
    g_kernenv.oNbOff      = 0U;
    g_kernenv.oNbRestore  = 0U;
    g_kernenv.oUnbalanced = false;
    g_kernenv.oReason     = nullptr;
    g_kernenv.oRunningCore = 0U;

    g_kernenv.oNbLog           = 0U;
    g_kernenv.oLastLogCategory = 0U;
    g_kernenv.oLastLogMessage  = nullptr;

    g_kernenv.oNbMalloc       = 0U;
    g_kernenv.oNbFree         = 0U;
    g_kernenv.oLastMallocSize = 0U;
    g_kernenv.oFailMallocOnCall = 0U;

// The semaphore counters live in g_kernenv so a pools test can read them, but
// the doubles that write them are in ukos_fakes_semaphores.c, which a suite may
// or may not link. Cleared here because g_kernenv is this file's.

    g_kernenv.oNbSemaCreate = 0U;
    g_kernenv.oNbSemaWait   = 0U;
    g_kernenv.oNbSemaSignal = 0U;
    g_kernenv.oNbSemaKill   = 0U;
    g_kernenv.oRcSemaCreate = KERR_KERN_NOERR;
    g_kernenv.oRcSemaWait   = KERR_KERN_NOERR;

    g_kernenv.oIsException     = false;
    g_kernenv.oNbPreemption    = 0U;
    g_kernenv.oNbGotoKern      = 0U;
    g_kernenv.oLastKernMessage = 0U;

    g_kernenv.oTickCount  = 0U;
    g_kernenv.oNbReadTick = 0U;

    g_kernenv.oNbElevate     = 0U;
    g_kernenv.oNbRestorePriv = 0U;
    g_kernenv.oPrivTraceLen  = 0U;


    for (uint32_t core = 0U; core < KNB_CORES; core++) {
        vKern_runProc[core] = nullptr;

// Cleared by hand rather than through lists_initialise(), which would make
// every kern suite link lists.c - the identifier and kernenv suites do not.
// list_t is three plain fields and an empty list is all-zero, so this is the
// same state, not an approximation.

        vKern_listExec[core].oFirst      = nullptr;
        vKern_listExec[core].oLast       = nullptr;
        vKern_listExec[core].oNbElements = 0U;
    }

    (void)memset(&vKern_proc[0][0], 0, sizeof(vKern_proc));
}

/*
 * \brief Register the reset and label the tier
 *
 */
[[gnu::constructor]]
static  void    local_install(void) {

    ukos_t_addResetHook(local_reset);
    local_reset();

    g_ukos_t_tierNote = "[kern: real OS/Lib_kernels/kern sources; interrupt masks counted, not applied]";
}
