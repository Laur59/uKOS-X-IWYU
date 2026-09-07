/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_kernels/kern/mutexes.c.
 *
 * Tier 3. Structurally the twin of semaphores.c - same six entry points, same
 * wait list, same release loop - so this file concentrates on the four places
 * where a mutex is NOT a counting semaphore, and covers the shared shape more
 * briefly:
 *
 *   1. ownership. A mutex remembers who holds it, and hands that title to the
 *      process it wakes rather than leaving it to whoever runs next.
 *   2. recursion. The current owner may lock again; anybody else blocks on the
 *      same state.
 *   3. the counter is decremented AFTER the availability test, not before, so
 *      there is no restore-on-failure to get wrong - the mirror image of
 *      semaphores.c, and the reason the two files' TIMEO paths differ.
 *   4. the ISR guard has no timeout condition. kern_waitSemaphore lets an ISR
 *      poll with timeout 0; kern_lockMutex refuses an ISR outright, and so does
 *      kern_unlockMutex.
 *   5. only the owner may unlock. kern_signalSemaphore accepts a signal from
 *      anybody by design; kern_unlockMutex returns KERR_KERN_MUNOW.
 *
 * Read the GOTO_KERN_M warning in port/macros_core_stackFrame.h before trusting
 * any assertion about blocking: the trap returns here and does not on a target,
 * so what is tested is the decision to block, never the suspension.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_kern.h"
#include    "kern/private/private_lists.h"
#include    "kern/private/private_mutexes.h"
#include    "kern/private/private_processes.h"
#include    "os_errors.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

#define KPRIO_HIGH          KKERN_PRIORITY_HIGH_04
#define KPRIO_RUNNING       KKERN_PRIORITY_HIGH_08
#define KPRIO_LOW           KKERN_PRIORITY_HIGH_11

static  proc_t      vRunning;
static  proc_t      vOther;
static  proc_t      vWaiter[2];

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    (void)memset(&vRunning,   0, sizeof(vRunning));
    (void)memset(&vOther,     0, sizeof(vOther));
    (void)memset(&vWaiter[0], 0, sizeof(vWaiter));

    vRunning.oInternal.oDynamicPriority = KPRIO_RUNNING;
    ukos_fake_setRunningProcess(&vRunning);

    mutexes_init();
}

/*
 * \brief Park a process on a mutex's wait list, as the scheduler would
 *
 */
static  void    local_addWaiter(mutx_t *handle, proc_t *process, priority_t priority) {

    process->oInternal.oDynamicPriority = priority;
    process->oInternal.oState          |= (uint16_t)(1U << BPROC_SUSP_MUTX);
    lists_connect(&handle->oList, process);
}

/*
 * \brief A created mutex
 *
 */
static  mutx_t  *local_mutex(const char_t *identifier) {
    mutx_t  *handle = nullptr;

    EXPECT_EQ_I(kern_createMutex(identifier, &handle), KERR_KERN_NOERR);
    return handle;
}

// Creation
// ========

TEST(mutexes_init_empties_the_table) {
    local_setup();

    EXPECT_EQ_U(vKern_nbMutx[0], 0U);
    EXPECT_EQ_U(vKern_nbMaxMutx[0], 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mutexes_create_starts_free_and_unowned) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");

// Unlike a semaphore, the caller does not choose the counters: kern_createMutex
// fixes them at 0 and KMUTX_MAX_CPT (mutexes.c:107). 0 means free.

    EXPECT_EQ_U(handle->oState & (1U << BMUTX_INSTALLED), (1U << BMUTX_INSTALLED));
    EXPECT_EQ_I(handle->oCounter, 0);
    EXPECT_EQ_I(handle->oMaxCounter, KMUTX_MAX_CPT);
    EXPECT_EQ_PTR(handle->oOwner, nullptr);
    EXPECT_EQ_U(vKern_nbMutx[0], 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mutexes_an_anonymous_mutex_takes_the_shared_identifier) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex(nullptr);
    EXPECT_EQ_STR(handle->oIdentifier, KMUTX_ANONYMOUS_ID);
}

TEST(mutexes_a_duplicate_identifier_returns_the_existing_handle) {
    mutx_t  *first;
    mutx_t  *again = nullptr;

    local_setup();

    first = local_mutex("Guard");
    EXPECT_EQ_I(kern_createMutex("Guard", &again), KERR_KERN_IDMUT);

    EXPECT_EQ_PTR(again, first);
    EXPECT_EQ_U(vKern_nbMutx[0], 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Locking
// =======

TEST(mutexes_lock_takes_ownership) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");

    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);

// The counter is decremented AFTER the availability test, so a successful lock
// leaves -1 and no restore is ever needed - the opposite arrangement to
// semaphores.c, which decrements first and puts the count back on failure.

    EXPECT_EQ_I(handle->oCounter, -1);
    EXPECT_EQ_PTR(handle->oOwner, &vRunning);
    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mutexes_the_owner_may_lock_again) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");

    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);

// Recursion is what makes this a mutex rather than a binary semaphore: the
// owner is let through on the `oOwner == vKern_runProc[core]` arm even though
// the counter is already negative, and each pass drives it one lower.

    EXPECT_EQ_I(handle->oCounter, -3);
    EXPECT_EQ_PTR(handle->oOwner, &vRunning);
    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);
}

TEST(mutexes_a_different_process_is_kept_out) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);

// Switch which process is running. Same mutex, same state, different caller -
// and now the recursion arm does not apply.

    vOther.oInternal.oDynamicPriority = KPRIO_RUNNING;
    ukos_fake_setRunningProcess(&vOther);

    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_TIMEO);
    EXPECT_EQ_I(handle->oCounter, -1);                  // untouched by the refusal
    EXPECT_EQ_PTR(handle->oOwner, &vRunning);           // and still held by the first
    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);             // timeout 0 never asks to block
}

TEST(mutexes_lock_refuses_an_unknown_mutex) {
    mutx_t  mutx;

    local_setup();

    (void)memset(&mutx, 0, sizeof(mutx));

    EXPECT_EQ_I(kern_lockMutex(nullptr, 0U), KERR_KERN_NOMUT);
    EXPECT_EQ_I(kern_lockMutex(&mutx,   0U), KERR_KERN_NOMUT);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mutexes_an_isr_may_not_lock_at_all) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    ukos_fake_setException(true);

// The difference from kern_waitSemaphore that is easiest to get wrong: there
// the ISR guard is `IS_EXCEPTION && timeout != 0`, so an ISR may poll. Here it
// is IS_EXCEPTION alone (mutexes.c:449), so even timeout 0 is refused - an ISR
// has no process identity to own the mutex with.

    EXPECT_EQ_I(kern_lockMutex(handle, 0U),    KERR_KERN_FRISR);
    EXPECT_EQ_I(kern_lockMutex(handle, 1000U), KERR_KERN_FRISR);

    EXPECT_EQ_I(handle->oCounter, 0);
    EXPECT_EQ_PTR(handle->oOwner, nullptr);

    ukos_fake_setException(false);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mutexes_lock_refuses_a_saturated_counter) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    handle->oCounter = KMUTX_MIN_CPT;

// Recursion has a floor: the counter is signed and the next decrement would
// overflow it.

    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_MUTME);
    EXPECT_EQ_I(handle->oCounter, KMUTX_MIN_CPT);
}

// Blocking
// ========

TEST(mutexes_lock_asks_the_kernel_to_block_with_the_right_message) {
    mutx_t  *first;
    mutx_t  *second;

    local_setup();

    first  = local_mutex("m0");
    second = local_mutex("m1");
    (void)first;

    EXPECT_EQ_I(kern_lockMutex(second, 0U), KERR_KERN_NOERR);   // held by vRunning

    ukos_fake_setRunningProcess(&vOther);
    vOther.oInternal.oDynamicPriority = KPRIO_RUNNING;
    vOther.oInternal.oStatus          = KERR_KERN_NOERR;

    EXPECT_EQ_I(kern_lockMutex(second, 1000U), KERR_KERN_NOERR);

// The message carries the mutex's index in the table, and uses the MUTX base
// rather than the SEMA one - the two share the scheduler's dispatch and would
// park the process on the wrong list if they collided.

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 1U);
    EXPECT_EQ_U(g_kernenv.oLastKernMessage, KKERN_MSG_WAIT_MUTX_SYN + 1U);
}

TEST(mutexes_a_timeout_after_blocking_leaves_the_counter_alone) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);   // vRunning owns it

    ukos_fake_setRunningProcess(&vOther);
    vOther.oInternal.oDynamicPriority = KPRIO_RUNNING;
    vOther.oInternal.oStatus          = KERR_KERN_TIMEO;

    EXPECT_EQ_I(kern_lockMutex(handle, 1000U), KERR_KERN_TIMEO);

// Nothing to undo: the counter was never decremented on the way in, so unlike
// semaphores.c there is no restore step after the trap and the owner's single
// hold is intact.

    EXPECT_EQ_I(handle->oCounter, -1);
    EXPECT_EQ_PTR(handle->oOwner, &vRunning);
}

// Unlocking
// =========

TEST(mutexes_unlock_releases_an_uncontended_mutex) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);

    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_NOERR);

    EXPECT_EQ_I(handle->oCounter, 0);
    EXPECT_EQ_PTR(handle->oOwner, nullptr);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mutexes_a_recursive_hold_needs_as_many_unlocks) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);

    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_NOERR);
    EXPECT_EQ_I(handle->oCounter, -1);

// Still owned. local_signalMutex returns as soon as the counter is still
// negative (mutexes.c:519), before the release logic - so a partially unwound
// recursive hold keeps its owner, which is what makes the recursion safe: the
// mutex is not up for grabs between the two unlocks.

    EXPECT_EQ_PTR(handle->oOwner, &vRunning);

    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_NOERR);
    EXPECT_EQ_I(handle->oCounter, 0);
    EXPECT_EQ_PTR(handle->oOwner, nullptr);             // released only now
}

TEST(mutexes_unlock_hands_the_mutex_to_the_first_waiter) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);

    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);
    local_addWaiter(handle, &vWaiter[1], KPRIO_LOW);

    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_NOERR);

// This is the part a semaphore does not do: ownership is TRANSFERRED, and the
// counter is forced back to -1 rather than left at whatever the increment
// produced, so the mutex is held by the new owner the instant it becomes
// runnable and no third process can slip in.

    EXPECT_EQ_PTR(handle->oOwner, &vWaiter[0]);
    EXPECT_EQ_I(handle->oCounter, -1);

    EXPECT_EQ_U(handle->oList.oNbElements, 1U);
    EXPECT_EQ_PTR(handle->oList.oFirst, &vWaiter[1]);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 1U);
    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_NOERR);
    EXPECT_EQ_U(vWaiter[0].oInternal.oState & (1U << BPROC_SUSP_MUTX), 0U);
}

TEST(mutexes_unlock_preempts_only_for_a_higher_priority_waiter) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);
    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);

    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_NOERR);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 0U);

    local_setup();
    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);
    local_addWaiter(handle, &vWaiter[0], KPRIO_HIGH);

    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_NOERR);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 1U);
}

TEST(mutexes_unlock_is_refused_to_a_process_that_does_not_own_it) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);   // vRunning owns it

    ukos_fake_setRunningProcess(&vOther);
    vOther.oInternal.oDynamicPriority = KPRIO_RUNNING;

// The guard a semaphore has no equivalent of: only the owner may release.
// kern_signalSemaphore accepts a signal from anybody, by design - a semaphore
// counts events - whereas a mutex protects a critical section and releasing
// somebody else's would defeat it.

    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_MUNOW);
    EXPECT_EQ_I(handle->oCounter, -1);                  // still held
    EXPECT_EQ_PTR(handle->oOwner, &vRunning);

// And the rightful owner still can.

    ukos_fake_setRunningProcess(&vRunning);
    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(handle->oOwner, nullptr);
}

TEST(mutexes_unlock_is_refused_from_an_isr) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);

// Symmetrical with the lock side, and for the same reason: an ISR has no
// process identity, so it can neither take ownership nor prove it holds it.

    ukos_fake_setException(true);
    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_FRISR);
    ukos_fake_setException(false);

    EXPECT_EQ_I(handle->oCounter, -1);
    EXPECT_EQ_PTR(handle->oOwner, &vRunning);
}

TEST(mutexes_unlock_refuses_a_saturated_counter) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Guard");
    handle->oOwner   = &vRunning;
    handle->oCounter = KMUTX_MAX_CPT;

    EXPECT_EQ_I(kern_unlockMutex(handle), KERR_KERN_MUTME);
    EXPECT_EQ_I(handle->oCounter, KMUTX_MAX_CPT);
}

TEST(mutexes_unlock_refuses_an_unknown_mutex) {
    mutx_t  mutx;

    local_setup();

    (void)memset(&mutx, 0, sizeof(mutx));

    EXPECT_EQ_I(kern_unlockMutex(nullptr), KERR_KERN_NOMUT);
    EXPECT_EQ_I(kern_unlockMutex(&mutx),   KERR_KERN_NOMUT);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Kill, restart, lookup
// =====================

TEST(mutexes_kill_releases_every_waiter) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Doomed");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);
    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);
    local_addWaiter(handle, &vWaiter[1], KPRIO_LOW);

    EXPECT_EQ_I(kern_killMutex(handle), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oList.oNbElements, 0U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 2U);
    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_MUKIL);
    EXPECT_EQ_I(vWaiter[1].oInternal.oStatus, KERR_KERN_MUKIL);

    EXPECT_EQ_U(handle->oState, 0U);
    EXPECT_EQ_PTR(handle->oOwner, nullptr);
    EXPECT_EQ_U(vKern_nbMutx[0], 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mutexes_the_release_loop_only_remembers_the_last_waiter) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Doomed");
    local_addWaiter(handle, &vWaiter[0], KPRIO_HIGH);
    local_addWaiter(handle, &vWaiter[1], KPRIO_LOW);

    EXPECT_EQ_I(kern_killMutex(handle), KERR_KERN_NOERR);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 2U);

// The same defect as semaphores.c, in the same shape, at mutexes.c:251 and
// :308: the loop assigns preemption instead of accumulating it, so only the
// last process released is considered. See DEFECTS.md.

    KNOWN_BUG("kern-release-loop-preemption-overwritten", (g_kernenv.oNbPreemption == 0U));
}

TEST(mutexes_restart_frees_the_mutex_and_keeps_it_installed) {
    mutx_t  *handle;

    local_setup();

    handle = local_mutex("Reset");
    EXPECT_EQ_I(kern_lockMutex(handle, 0U), KERR_KERN_NOERR);
    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);

    EXPECT_EQ_I(kern_restartMutex(handle), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oList.oNbElements, 0U);
    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_NOERR);

    EXPECT_EQ_I(handle->oCounter, 0);
    EXPECT_EQ_PTR(handle->oOwner, nullptr);
    EXPECT_EQ_U(handle->oState & (1U << BMUTX_INSTALLED), (1U << BMUTX_INSTALLED));
    EXPECT_EQ_U(vKern_nbMutx[0], 1U);
}

TEST(mutexes_lookup_finds_by_identifier) {
    mutx_t  *created;
    mutx_t  *found = nullptr;

    local_setup();

    created = local_mutex("Wanted");

    EXPECT_EQ_I(kern_getMutexById("Wanted", &found), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(found, created);

    EXPECT_EQ_I(kern_getMutexById("Absent", &found), KERR_KERN_NOMUT);
    EXPECT_EQ_PTR(found, nullptr);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// The mask and the privilege
// ==========================

TEST(mutexes_every_entry_point_gives_the_mask_and_the_privilege_back) {
    mutx_t  *handle = nullptr;
    mutx_t  mutx;

    local_setup();

    (void)memset(&mutx, 0, sizeof(mutx));

    (void)kern_createMutex("x", &handle);
    (void)kern_createMutex("x", &handle);                        // IDMUT
    (void)kern_lockMutex(&mutx, 0U);                             // NOMUT
    (void)kern_lockMutex(handle, 0U);                            // NOERR
    (void)kern_unlockMutex(&mutx);                               // NOMUT
    (void)kern_unlockMutex(handle);                              // NOERR
    (void)kern_killMutex(&mutx);                                 // NOMUT
    (void)kern_restartMutex(handle);                             // NOERR
    (void)kern_getMutexById("absent", &handle);                  // NOMUT

    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
    EXPECT_EQ_U(g_kernenv.oNbOff, g_kernenv.oNbRestore);
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
}
