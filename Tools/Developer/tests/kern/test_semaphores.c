/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_kernels/kern/semaphores.c.
 *
 * Tier 3, and the first suite to reach a blocking primitive. Read the warning in
 * port/macros_core_stackFrame.h first: GOTO_KERN_M does not return on a target,
 * and here it does. What that buys and what it costs:
 *
 *   - the counter arithmetic on BOTH sides of the trap is real, including the
 *     restore-on-timeout that runs after resumption;
 *   - the message code the kernel chose is recorded and asserted;
 *   - the suspension itself is not modelled. A test that needs a process
 *     waiting on a semaphore puts it on the object's list itself, with the real
 *     lists_connect(). Nothing here proves the scheduler would put it there.
 *
 * IS_EXCEPTION being settable is a genuine gain over the target: the
 * KERR_KERN_FRISR arm needs a real interrupt handler to enter on hardware and is
 * simply unreachable from a board test.
 *
 * Linked for real alongside: lists.c and identifier.c. The semaphore doubles in
 * fakes/ukos_fakes_semaphores.c must NOT be linked here - they define the same
 * four functions.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_kern.h"
#include    "kern/private/private_lists.h"
#include    "kern/private/private_processes.h"
#include    "kern/private/private_semaphores.h"
#include    "os_errors.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

// oDynamicPriority is a priority_t enum, and lower means MORE urgent
// (KKERN_PRIORITY_HIGH_Reserved == 0). Three real enumerators rather than plain
// numbers, so -Wimplicit-int-enum-cast stays satisfied and the ordering is the
// kernel's own.

#define KPRIO_HIGH          KKERN_PRIORITY_HIGH_04
#define KPRIO_RUNNING       KKERN_PRIORITY_HIGH_08
#define KPRIO_LOW           KKERN_PRIORITY_HIGH_11

static  proc_t      vRunning;
static  proc_t      vWaiter[3];

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    (void)memset(&vRunning,   0, sizeof(vRunning));
    (void)memset(&vWaiter[0], 0, sizeof(vWaiter));

    vRunning.oInternal.oDynamicPriority = KPRIO_RUNNING;
    ukos_fake_setRunningProcess(&vRunning);

    semaphores_init();
}

/*
 * \brief Park a process on a semaphore's wait list, as the scheduler would
 *
 * - The scheduler does this from scheduler_callBackTrap after GOTO_KERN_M; the
 *   fake trap does not, so a test that needs a waiter arranges one. lists.c is
 *   linked for real, so the list this builds is the one the module will walk.
 *
 */
static  void    local_addWaiter(sema_t *handle, proc_t *process, priority_t priority) {

    process->oInternal.oDynamicPriority = priority;
    process->oInternal.oState          |= (uint16_t)(1U << BPROC_SUSP_SEMA);
    lists_connect(&handle->oList, process);
}

/*
 * \brief A created semaphore
 *
 */
static  sema_t  *local_semaphore(const char_t *identifier, int32_t ini, int32_t max) {
    sema_t  *handle = nullptr;

    EXPECT_EQ_I(kern_createSemaphore(identifier, ini, max, &handle), KERR_KERN_NOERR);
    return handle;
}

// Creation
// ========

TEST(semaphores_init_empties_the_table) {
    local_setup();

    EXPECT_EQ_U(vKern_nbSema[0], 0U);
    EXPECT_EQ_U(vKern_nbMaxSema[0], 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_create_sets_both_counters) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 2, 5);

    EXPECT_EQ_U(handle->oState & (1U << BSEMA_INSTALLED), (1U << BSEMA_INSTALLED));
    EXPECT_EQ_I(handle->oCounter,    2);
    EXPECT_EQ_I(handle->oMaxCounter, 5);
    EXPECT_EQ_PTR(handle->oOwner, nullptr);
    EXPECT_EQ_U(vKern_nbSema[0], 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_an_anonymous_semaphore_takes_the_shared_identifier) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore(nullptr, 0, 1);
    EXPECT_EQ_STR(handle->oIdentifier, KSEMA_ANONYMOUS_ID);
}

TEST(semaphores_a_duplicate_identifier_returns_the_existing_handle) {
    sema_t  *first;
    sema_t  *again = nullptr;

    local_setup();

    first = local_semaphore("Sync", 0, 1);
    EXPECT_EQ_I(kern_createSemaphore("Sync", 0, 1, &again), KERR_KERN_IDSEM);

    EXPECT_EQ_PTR(again, first);
    EXPECT_EQ_U(vKern_nbSema[0], 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_a_full_table_is_refused) {
    sema_t          *handle = nullptr;
    uint16_t        i;
    static  const   char_t  *const names[] = {
                        "s00","s01","s02","s03","s04","s05","s06","s07",
                        "s08","s09","s10","s11","s12","s13","s14","s15",
                        "s16","s17","s18","s19","s20","s21","s22","s23",
                        "s24","s25","s26","s27","s28","s29","s30","s31",
                        "s32","s33","s34","s35","s36","s37","s38","s39",
                        "s40","s41","s42","s43","s44","s45","s46","s47",
                    };

    local_setup();

    EXPECT_TRUE(KKERN_NB_SEMAPHORES <= (uint16_t)(sizeof(names) / sizeof(names[0])));

    for (i = 0U; i < KKERN_NB_SEMAPHORES; i++) {
        EXPECT_EQ_I(kern_createSemaphore(names[i], 0, 1, &handle), KERR_KERN_NOERR);
    }

    handle = nullptr;
    EXPECT_EQ_I(kern_createSemaphore("one too many", 0, 1, &handle), KERR_KERN_SEFUL);
    EXPECT_EQ_PTR(handle, nullptr);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
}

// Wait - the non-blocking outcomes
// ================================

TEST(semaphores_wait_takes_an_available_count) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 2, 5);

    EXPECT_EQ_I(kern_waitSemaphore(handle, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_I(handle->oCounter, 1);

    EXPECT_EQ_I(kern_waitSemaphore(handle, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_I(handle->oCounter, 0);

// Nothing blocked, so the kernel was never asked to.

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_wait_with_no_timeout_restores_the_count) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 5);

// The counter is decremented BEFORE the availability test (semaphores.c:462),
// so the no-wait path has to put it back. If it did not, repeated polling would
// drive the count arbitrarily negative.

    EXPECT_EQ_I(kern_waitSemaphore(handle, 0U), KERR_KERN_TIMEO);
    EXPECT_EQ_I(handle->oCounter, 0);

    EXPECT_EQ_I(kern_waitSemaphore(handle, 0U), KERR_KERN_TIMEO);
    EXPECT_EQ_I(handle->oCounter, 0);

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);
}

TEST(semaphores_wait_refuses_an_unknown_semaphore) {
    sema_t  sema;

    local_setup();

    (void)memset(&sema, 0, sizeof(sema));               // not installed

    EXPECT_EQ_I(kern_waitSemaphore(nullptr, 0U), KERR_KERN_NOSEM);
    EXPECT_EQ_I(kern_waitSemaphore(&sema,   0U), KERR_KERN_NOSEM);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_wait_from_an_isr_is_refused_only_when_it_would_block) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 1, 5);

// Unreachable from a board test - it needs a real interrupt handler - and the
// only reason IS_EXCEPTION is a settable flag in this tier.

    ukos_fake_setException(true);

    EXPECT_EQ_I(kern_waitSemaphore(handle, 1000U), KERR_KERN_FRISR);
    EXPECT_EQ_I(handle->oCounter, 1);                   // refused before touching the count

// timeout == 0 cannot block, so an ISR is allowed to poll.

    EXPECT_EQ_I(kern_waitSemaphore(handle, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_I(handle->oCounter, 0);

    ukos_fake_setException(false);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_wait_refuses_a_saturated_counter) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 5);
    handle->oCounter = KSEMA_MIN_CPT;

// Guarded because the next decrement would overflow a signed int32.

    EXPECT_EQ_I(kern_waitSemaphore(handle, 0U), KERR_KERN_SETME);
    EXPECT_EQ_I(handle->oCounter, KSEMA_MIN_CPT);
}

// Wait - the blocking decision
// ============================

TEST(semaphores_wait_asks_the_kernel_to_block_with_the_right_message) {
    sema_t      *first;
    sema_t      *second;
    uint32_t    index;

    local_setup();

    first  = local_semaphore("s0", 0, 5);
    second = local_semaphore("s1", 0, 5);

    vRunning.oInternal.oStatus = KERR_KERN_NOERR;       // what the scheduler would report
    EXPECT_EQ_I(kern_waitSemaphore(second, 1000U), KERR_KERN_NOERR);

// The message carries the semaphore's INDEX in the table, which is how
// scheduler_callBackTrap knows which wait list to park the process on.

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 1U);
    index = (uint32_t)(((uintptr_t)second - (uintptr_t)first) / sizeof(sema_t));
    EXPECT_EQ_U(index, 1U);
    EXPECT_EQ_U(g_kernenv.oLastKernMessage, KKERN_MSG_WAIT_SEMA_SYN + 1U);

// The count stays taken: the caller was given the semaphore.

    EXPECT_EQ_I(second->oCounter, -1);
}

TEST(semaphores_a_timeout_after_blocking_gives_the_count_back) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 5);

// The code after the trap is real, and this is the branch it exists for: the
// scheduler resumed the process with TIMEO, so the count it took on the way in
// has to be returned. Seeding oStatus is how a host says "the scheduler
// resumed us like this".

    vRunning.oInternal.oStatus = KERR_KERN_TIMEO;
    EXPECT_EQ_I(kern_waitSemaphore(handle, 1000U), KERR_KERN_TIMEO);

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 1U);
    EXPECT_EQ_I(handle->oCounter, 0);                   // -1, then given back
}

TEST(semaphores_a_kill_while_waiting_does_not_give_the_count_back) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 5);

    vRunning.oInternal.oStatus = KERR_KERN_SEKIL;
    EXPECT_EQ_I(kern_waitSemaphore(handle, 1000U), KERR_KERN_SEKIL);

// Only TIMEO restores. Any other resumption status leaves the count taken,
// which is right for SEKIL because the semaphore no longer exists.

    EXPECT_EQ_I(handle->oCounter, -1);
}

TEST(semaphores_the_timeout_is_converted_and_parked_on_the_process) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 5);
    vRunning.oInternal.oStatus = KERR_KERN_NOERR;

    (void)kern_waitSemaphore(handle, 2000U);
    EXPECT_EQ_U(vRunning.oInternal.oTimeout, 2000U / KKERN_TIC_TIME);

    handle->oCounter = 0;
    (void)kern_waitSemaphore(handle, KWAIT_INFINITY);
    EXPECT_EQ_U(vRunning.oInternal.oTimeout, KWAIT_INFINITY);

// KWAIT_REMAINING_TIMEOUT keeps whatever is already parked, which is how a
// process resumes a wait it was interrupted out of.

    vRunning.oInternal.oTimeout = 1234U;
    handle->oCounter = 0;
    (void)kern_waitSemaphore(handle, KWAIT_REMAINING_TIMEOUT);
    EXPECT_EQ_U(vRunning.oInternal.oTimeout, 1234U);
}

// Signal
// ======

TEST(semaphores_signal_raises_the_count) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 2);

    EXPECT_EQ_I(kern_signalSemaphore(handle), KERR_KERN_NOERR);
    EXPECT_EQ_I(handle->oCounter, 1);

    EXPECT_EQ_I(kern_signalSemaphore(handle), KERR_KERN_NOERR);
    EXPECT_EQ_I(handle->oCounter, 2);

// At the ceiling it is refused rather than silently dropped.

    EXPECT_EQ_I(kern_signalSemaphore(handle), KERR_KERN_SETME);
    EXPECT_EQ_I(handle->oCounter, 2);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_signal_refuses_an_unknown_semaphore) {
    sema_t  sema;

    local_setup();

    (void)memset(&sema, 0, sizeof(sema));

    EXPECT_EQ_I(kern_signalSemaphore(nullptr), KERR_KERN_NOSEM);
    EXPECT_EQ_I(kern_signalSemaphore(&sema),   KERR_KERN_NOSEM);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_signal_wakes_the_first_waiter) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 5);
    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);
    local_addWaiter(handle, &vWaiter[1], KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSemaphore(handle), KERR_KERN_NOERR);

// FIFO: the head of the list goes, the other stays.

    EXPECT_EQ_U(handle->oList.oNbElements, 1U);
    EXPECT_EQ_PTR(handle->oList.oFirst, &vWaiter[1]);

    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 1U);
    EXPECT_EQ_PTR(vKern_listExec[0].oFirst, &vWaiter[0]);

    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_NOERR);
    EXPECT_EQ_U(vWaiter[0].oInternal.oState & (1U << BPROC_SUSP_SEMA), 0U);
    EXPECT_EQ_PTR(handle->oOwner, &vRunning);
}

TEST(semaphores_signal_from_an_isr_records_no_owning_process) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 5);
    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);

    ukos_fake_setException(true);
    EXPECT_EQ_I(kern_signalSemaphore(handle), KERR_KERN_NOERR);
    ukos_fake_setException(false);

// There is no running process to credit inside an ISR, so a sentinel is stored
// instead of vKern_runProc - which the `object` CLI renders as "from ISR".

    EXPECT_EQ_PTR(handle->oOwner, KKERN_HANDLE_FROM_ISR);
}

TEST(semaphores_signal_preempts_only_for_a_higher_priority_waiter) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Sync", 0, 5);
    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSemaphore(handle), KERR_KERN_NOERR);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 0U);           // lower priority: keep running

    handle->oCounter = 0;
    local_addWaiter(handle, &vWaiter[1], KPRIO_HIGH);

    EXPECT_EQ_I(kern_signalSemaphore(handle), KERR_KERN_NOERR);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 1U);           // higher priority: yield to it
}

// Kill and restart
// ================

TEST(semaphores_kill_releases_every_waiter) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Doomed", 3, 5);
    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);
    local_addWaiter(handle, &vWaiter[1], KPRIO_LOW);

    EXPECT_EQ_I(kern_killSemaphore(handle), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oList.oNbElements, 0U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 2U);
    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_SEKIL);
    EXPECT_EQ_I(vWaiter[1].oInternal.oStatus, KERR_KERN_SEKIL);

    EXPECT_EQ_U(handle->oState, 0U);
    EXPECT_EQ_I(handle->oCounter, 0);
    EXPECT_EQ_U(vKern_nbSema[0], 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_kill_refuses_an_unknown_semaphore) {
    sema_t  sema;

    local_setup();

    (void)memset(&sema, 0, sizeof(sema));

    EXPECT_EQ_I(kern_killSemaphore(nullptr), KERR_KERN_NOSEM);
    EXPECT_EQ_I(kern_killSemaphore(&sema),   KERR_KERN_NOSEM);
}

TEST(semaphores_restart_releases_the_waiters_and_resets_the_counters) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Reset", 0, 5);
    handle->oOwner = &vRunning;
    local_addWaiter(handle, &vWaiter[0], KPRIO_LOW);

    EXPECT_EQ_I(kern_restartSemaphore(handle), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oList.oNbElements, 0U);
    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_NOERR);

    EXPECT_EQ_I(handle->oCounter, 0);
    EXPECT_EQ_I(handle->oMaxCounter, KSEMA_MAX_CPT);    // not the value it was created with
    EXPECT_EQ_PTR(handle->oOwner, nullptr);

// Still installed - restart is not a kill.

    EXPECT_EQ_U(handle->oState & (1U << BSEMA_INSTALLED), (1U << BSEMA_INSTALLED));
    EXPECT_EQ_U(vKern_nbSema[0], 1U);
}

TEST(semaphores_the_release_loop_only_remembers_the_last_waiter) {
    sema_t  *handle;

    local_setup();

    handle = local_semaphore("Doomed", 0, 5);

// A high-priority process first, a low-priority one behind it. Releasing both
// should preempt - the high-priority one is now runnable and outranks us.

    local_addWaiter(handle, &vWaiter[0], KPRIO_HIGH);
    local_addWaiter(handle, &vWaiter[1], KPRIO_LOW);

    EXPECT_EQ_I(kern_killSemaphore(handle), KERR_KERN_NOERR);

    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 2U);

// It does not. The loop ASSIGNS preemption on each pass instead of accumulating
// it (semaphores.c:248, and identically at :305, mutexes.c:251 and :308), so
// only the last process released has a say. Here the last one is low priority,
// so the high-priority process it just made runnable does not get the CPU until
// something else happens to yield. See DEFECTS.md.

    KNOWN_BUG("kern-release-loop-preemption-overwritten", (g_kernenv.oNbPreemption == 0U));
}

// Lookup and accounting
// =====================

TEST(semaphores_lookup_finds_by_identifier) {
    sema_t  *created;
    sema_t  *found = nullptr;

    local_setup();

    created = local_semaphore("Wanted", 0, 1);

    EXPECT_EQ_I(kern_getSemaphoreById("Wanted", &found), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(found, created);

    EXPECT_EQ_I(kern_getSemaphoreById("Absent", &found), KERR_KERN_NOSEM);
    EXPECT_EQ_PTR(found, nullptr);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(semaphores_every_entry_point_gives_the_mask_and_the_privilege_back) {
    sema_t  *handle = nullptr;
    sema_t  sema;

    local_setup();

    (void)memset(&sema, 0, sizeof(sema));

    (void)kern_createSemaphore("x", 0, 1, &handle);
    (void)kern_createSemaphore("x", 0, 1, &handle);              // IDSEM
    (void)kern_waitSemaphore(&sema, 0U);                         // NOSEM
    (void)kern_waitSemaphore(handle, 0U);                        // TIMEO
    (void)kern_signalSemaphore(&sema);                           // NOSEM
    (void)kern_signalSemaphore(handle);                          // NOERR
    (void)kern_killSemaphore(&sema);                             // NOSEM
    (void)kern_restartSemaphore(handle);                         // NOERR
    (void)kern_getSemaphoreById("absent", &handle);              // NOSEM

    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
    EXPECT_EQ_U(g_kernenv.oNbOff, g_kernenv.oNbRestore);
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
}
