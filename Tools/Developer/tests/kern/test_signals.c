/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_kernels/kern/signals.c.
 *
 * Tier 3. Ten entry points, zero static functions, and almost nothing but
 * 32-bit mask arithmetic over a per-process synchro table - which makes it the
 * module in this directory where a host test comes closest to testing the real
 * thing. There is no allocation, no copying, and only one call out to the
 * scheduler.
 *
 * Two structural facts drive the whole file:
 *
 *   - a process's slot in sign_t.oSynchro[] is its OFFSET into vKern_proc,
 *     computed by pointer subtraction (signals.c:291, :393, :531). A process
 *     that is not inside that array yields a garbage index and an out-of-bounds
 *     write, so every process here comes from vKern_proc[0][] and never from a
 *     local. Under -s a mistake is a reported overflow rather than a quiet one.
 *   - waking a waiter needs THREE conditions at once: the process is suspended
 *     on a signal, the signalled bits intersect the ones it asked to be woken
 *     for, and its recorded sender matches. Two of those are easy to test by
 *     accident and the third - the sender filter - is the one worth aiming at.
 *
 * Read the GOTO_KERN_I warning in port/macros_core_stackFrame.h before trusting
 * anything asserted about blocking.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_kern.h"
#include    "kern/private/private_lists.h"
#include    "kern/private/private_processes.h"
#include    "kern/private/private_signals.h"
#include    "os_errors.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

#define KPRIO_HIGH          KKERN_PRIORITY_HIGH_04
#define KPRIO_RUNNING       KKERN_PRIORITY_HIGH_08
#define KPRIO_LOW           KKERN_PRIORITY_HIGH_11

#define KRUN                0U                          // vKern_proc slots this suite uses
#define KTARGET             1U
#define KOTHER              2U

#define KSIG_A              (1U << 0)
#define KSIG_B              (1U << 1)
#define KSIG_C              (1U << 2)

/*
 * \brief Fixture
 *
 * - The running process is slot 0 of the real process table, because signals.c
 *   indexes oSynchro[] by offset into it.
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    vKern_proc[0][KRUN].oInternal.oState             = (uint16_t)(1U << BPROC_INSTALLED);
    vKern_proc[0][KRUN].oInternal.oDynamicPriority   = KPRIO_RUNNING;
    ukos_fake_setRunningProcess(&vKern_proc[0][KRUN]);

    signals_init();
}

/*
 * \brief Make a process installed and, optionally, waiting for signals
 *
 * - Reproduces what the scheduler leaves behind after GOTO_KERN_I: the process
 *   is off the run list, marked BPROC_SUSP_SIGN, and parked on vKern_listSign.
 *   The fake trap does none of that, so a test that wants a waiter builds one.
 *
 */
static  proc_t  *local_waiter(uint16_t slot, sign_t *handle, uint32_t wantedBits,
                              proc_t *fromProcess, priority_t priority) {
    proc_t  *process;

    process = &vKern_proc[0][slot];

    process->oInternal.oState           = (uint16_t)((1U << BPROC_INSTALLED) | (1U << BPROC_SUSP_SIGN));
    process->oInternal.oDynamicPriority = priority;

    handle->oSynchro[slot].oSignalBitGenerate  = wantedBits;
    handle->oSynchro[slot].oSignalFromProcess  = fromProcess;

    lists_connect(&vKern_listSign[0], process);
    return process;
}

/*
 * \brief A created signal group
 *
 */
static  sign_t  *local_group(const char_t *identifier) {
    sign_t  *handle = nullptr;

    EXPECT_EQ_I(kern_createSignalGroup(identifier, &handle), KERR_KERN_NOERR);
    return handle;
}

// Creation
// ========

TEST(signals_init_empties_the_table) {
    local_setup();

    EXPECT_EQ_U(vKern_nbSign[0], 0U);
    EXPECT_EQ_U(vKern_nbMaxSign[0], 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(signals_create_installs_a_group_with_no_bits_taken) {
    sign_t  *handle;

    local_setup();

    handle = local_group("Group");

    EXPECT_EQ_U(handle->oState & (1U << BSIGN_INSTALLED), (1U << BSIGN_INSTALLED));
    EXPECT_EQ_U(handle->oUsedBit, 0U);
    EXPECT_EQ_U(vKern_nbSign[0], 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(signals_a_duplicate_identifier_returns_the_existing_handle) {
    sign_t  *first;
    sign_t  *again = nullptr;

    local_setup();

    first = local_group("Group");
    EXPECT_EQ_I(kern_createSignalGroup("Group", &again), KERR_KERN_IDSIO);

    EXPECT_EQ_PTR(again, first);
    EXPECT_EQ_U(vKern_nbSign[0], 1U);
}

// Bit allocation
// ==============

TEST(signals_bits_are_handed_out_lowest_first) {
    sign_t  *handle;
    uint8_t bit = 0xFFU;

    local_setup();

    handle = local_group("Group");

    EXPECT_EQ_I(kern_createBitSignal(handle, &bit), KERR_KERN_NOERR);
    EXPECT_EQ_U(bit, 0U);
    EXPECT_EQ_U(handle->oUsedBit, KSIG_A);

    EXPECT_EQ_I(kern_createBitSignal(handle, &bit), KERR_KERN_NOERR);
    EXPECT_EQ_U(bit, 1U);
    EXPECT_EQ_U(handle->oUsedBit, KSIG_A | KSIG_B);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(signals_a_freed_bit_is_reused) {
    sign_t  *handle;
    uint8_t bit = 0xFFU;

    local_setup();

    handle = local_group("Group");

    EXPECT_EQ_I(kern_createBitSignal(handle, &bit), KERR_KERN_NOERR);    // bit 0
    EXPECT_EQ_I(kern_createBitSignal(handle, &bit), KERR_KERN_NOERR);    // bit 1
    EXPECT_EQ_I(kern_killBitSignal(handle, 0U), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oUsedBit, KSIG_B);

// Lowest free wins, so the released bit comes back before bit 2.

    EXPECT_EQ_I(kern_createBitSignal(handle, &bit), KERR_KERN_NOERR);
    EXPECT_EQ_U(bit, 0U);
}

TEST(signals_all_thirty_two_bits_are_available_then_exhausted) {
    sign_t      *handle;
    uint8_t     bit = 0xFFU;
    uint32_t    i;

    local_setup();

    handle = local_group("Group");

    for (i = 0U; i < KSIGN_NB_SIGNALS_PER_GROUP; i++) {
        EXPECT_EQ_I(kern_createBitSignal(handle, &bit), KERR_KERN_NOERR);
        EXPECT_EQ_U(bit, (uint8_t)i);
    }

// The mask is a uint32_t and the loop bound is 32, so the last bit really is
// bit 31 - one short and bit 31 would be unreachable, one long and the shift
// would be undefined.

    EXPECT_EQ_U(handle->oUsedBit, 0xFFFFFFFFU);

    bit = 0xFFU;
    EXPECT_EQ_I(kern_createBitSignal(handle, &bit), KERR_KERN_NOSIG);
    EXPECT_EQ_U(bit, 0U);                               // cleared on failure
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(signals_bit_allocation_refuses_an_unknown_group) {
    sign_t  sign;
    uint8_t bit = 0xFFU;

    local_setup();

    (void)memset(&sign, 0, sizeof(sign));

    EXPECT_EQ_I(kern_createBitSignal(nullptr, &bit), KERR_KERN_NOGRO);
    EXPECT_EQ_I(kern_createBitSignal(&sign,   &bit), KERR_KERN_NOGRO);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Signalling and waiting - the non-blocking path
// ==============================================

TEST(signals_a_pending_signal_is_taken_without_blocking) {
    sign_t      *handle;
    uint32_t    wanted;

    local_setup();

    handle = local_group("Group");

// Signal ourselves, then collect. The bit is pending, so kern_waitSignal
// consumes it and returns immediately.

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, &vKern_proc[0][KRUN],
                                  KSIGN_SIGNALE_WITHOUT_CONTEXT_SWITCH), KERR_KERN_NOERR);
    EXPECT_EQ_U(handle->oSynchro[KRUN].oSignalBitPending, KSIG_A);

    wanted = KSIG_A;
    EXPECT_EQ_I(kern_waitSignal(handle, &wanted, &vKern_proc[0][KRUN], 0U), KERR_KERN_NOERR);

    EXPECT_EQ_U(wanted, KSIG_A);                        // which bits actually arrived
    EXPECT_EQ_U(handle->oSynchro[KRUN].oSignalBitPending, 0U);   // and they are consumed
    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(signals_wait_returns_only_the_bits_it_asked_for) {
    sign_t      *handle;
    uint32_t    wanted;

    local_setup();

    handle = local_group("Group");

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A | KSIG_C, &vKern_proc[0][KRUN],
                                  KSIGN_SIGNALE_WITHOUT_CONTEXT_SWITCH), KERR_KERN_NOERR);

    wanted = KSIG_A | KSIG_B;
    EXPECT_EQ_I(kern_waitSignal(handle, &wanted, &vKern_proc[0][KRUN], 0U), KERR_KERN_NOERR);

// The intersection, and only the intersection: A was wanted and pending, B was
// wanted and absent, C was pending and unwanted.

    EXPECT_EQ_U(wanted, KSIG_A);
    EXPECT_EQ_U(handle->oSynchro[KRUN].oSignalBitPending, KSIG_C);   // C is still there
}

TEST(signals_waiting_for_nothing_returns_immediately_and_untouched) {
    sign_t      *handle;
    uint32_t    wanted = 0U;
    uint32_t    nbOff, nbElevate;

    local_setup();

    handle = local_group("Group");

// The *signals == 0 guard sits BEFORE PRIVILEGE_ELEVATE (signals.c:376), so
// this path takes neither the mask nor the privilege - the one entry point in
// the module that returns without doing either.

// Deltas, not absolutes: creating the group already took the mask once.

    nbOff     = g_kernenv.oNbOff;
    nbElevate = g_kernenv.oNbElevate;

    EXPECT_EQ_I(kern_waitSignal(handle, &wanted, &vKern_proc[0][KRUN], 1000U), KERR_KERN_NOERR);

    EXPECT_EQ_U(g_kernenv.oNbOff, nbOff);
    EXPECT_EQ_U(g_kernenv.oNbElevate, nbElevate);
    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);
}

TEST(signals_wait_with_no_timeout_reports_nothing_arrived) {
    sign_t      *handle;
    uint32_t    wanted;

    local_setup();

    handle = local_group("Group");

    wanted = KSIG_A;
    EXPECT_EQ_I(kern_waitSignal(handle, &wanted, &vKern_proc[0][KRUN], 0U), KERR_KERN_TIMEO);

    EXPECT_EQ_U(wanted, 0U);                            // cleared, so a caller cannot misread it
    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);
}

TEST(signals_wait_refuses_an_unknown_group_or_sender) {
    sign_t      *handle;
    sign_t      sign;
    uint32_t    wanted;

    local_setup();

    handle = local_group("Group");
    (void)memset(&sign, 0, sizeof(sign));

    wanted = KSIG_A;
    EXPECT_EQ_I(kern_waitSignal(nullptr, &wanted, &vKern_proc[0][KRUN], 0U), KERR_KERN_NOGRO);
    wanted = KSIG_A;
    EXPECT_EQ_I(kern_waitSignal(&sign, &wanted, &vKern_proc[0][KRUN], 0U), KERR_KERN_NOGRO);
    wanted = KSIG_A;
    EXPECT_EQ_I(kern_waitSignal(handle, &wanted, nullptr, 0U), KERR_KERN_NOPRO);

    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
}

// Blocking
// ========

TEST(signals_wait_asks_the_kernel_to_block_and_records_what_it_wants) {
    sign_t      *handle;
    uint32_t    wanted;

    local_setup();

    handle = local_group("Group");

    vKern_proc[0][KRUN].oInternal.oStatus = KERR_KERN_TIMEO;
    wanted = KSIG_A | KSIG_B;

    EXPECT_EQ_I(kern_waitSignal(handle, &wanted, &vKern_proc[0][KRUN], 1000U), KERR_KERN_TIMEO);

// GOTO_KERN_I here, not _M, and the message carries no object index: a signal
// wait is parked on the single vKern_listSign rather than on a per-object list.

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 1U);
    EXPECT_EQ_U(g_kernenv.oLastKernMessage, KKERN_MSG_WAIT_SIGN);

// The sender filter and the wanted mask are recorded before the trap - that is
// what kern_signalSignal consults to decide whether to wake this process.

    EXPECT_EQ_PTR(handle->oSynchro[KRUN].oSignalFromProcess, &vKern_proc[0][KRUN]);
    EXPECT_EQ_U(wanted, 0U);                            // nothing arrived
}

TEST(signals_the_on_waiting_callback_starts_unset) {
    sign_t      *handle;
    uint32_t    wanted;

    local_setup();

    handle = local_group("Group");

// oCbOnWaiting is the hook a driver installs to start the hardware that will
// eventually raise the signal; it runs just before the process is suspended
// (signals.c:411), or nothing would ever wake it.
//
// The call itself is NOT exercised. A fake callback would only assert against
// itself, and no in-tree caller installs one. What is asserted is that create
// leaves the pointer null - so the guard in front of the call is what runs, and
// a future test that does install one starts from a known state.

    EXPECT_EQ_PTR((const void *)handle->oCbOnWaiting, nullptr);

    vKern_proc[0][KRUN].oInternal.oStatus = KERR_KERN_TIMEO;
    wanted = KSIG_A;
    (void)kern_waitSignal(handle, &wanted, &vKern_proc[0][KRUN], 1000U);

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 1U);             // and it trapped anyway
}

// Waking a waiter - the three conditions
// ======================================

TEST(signals_a_selective_signal_wakes_a_matching_waiter) {
    sign_t  *handle;
    proc_t  *waiter;

    local_setup();

    handle = local_group("Group");
    waiter = local_waiter(KTARGET, handle, KSIG_A, &vKern_proc[0][KRUN], KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, waiter,
                                  KSIGN_SIGNALE_WITH_CONTEXT_SWITCH), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oSynchro[KTARGET].oSignalBitPending, KSIG_A);
    EXPECT_EQ_U(waiter->oInternal.oState & (1U << BPROC_SUSP_SIGN), 0U);
    EXPECT_EQ_I(waiter->oInternal.oStatus, KERR_KERN_NOERR);
    EXPECT_EQ_U(vKern_listSign[0].oNbElements, 0U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 1U);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 0U);           // lower priority
}

TEST(signals_a_waiter_wanting_other_bits_stays_asleep) {
    sign_t  *handle;
    proc_t  *waiter;

    local_setup();

    handle = local_group("Group");
    waiter = local_waiter(KTARGET, handle, KSIG_B, &vKern_proc[0][KRUN], KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, waiter,
                                  KSIGN_SIGNALE_WITH_CONTEXT_SWITCH), KERR_KERN_NOERR);

// The bit is recorded as pending regardless - a signal is never lost - but the
// process is not woken because it asked for B.

    EXPECT_EQ_U(handle->oSynchro[KTARGET].oSignalBitPending, KSIG_A);
    EXPECT_EQ_U(waiter->oInternal.oState & (1U << BPROC_SUSP_SIGN), (1U << BPROC_SUSP_SIGN));
    EXPECT_EQ_U(vKern_listSign[0].oNbElements, 1U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 0U);
}

TEST(signals_a_waiter_expecting_another_sender_stays_asleep) {
    sign_t  *handle;
    proc_t  *waiter;

    local_setup();

    handle = local_group("Group");

// The third condition, and the one a test reaches only on purpose: the waiter
// wants signal A, A is what is sent, and it still does not wake - because it
// asked to be woken only by KOTHER and the sender is the running process.

    waiter = local_waiter(KTARGET, handle, KSIG_A, &vKern_proc[0][KOTHER], KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, waiter,
                                  KSIGN_SIGNALE_WITH_CONTEXT_SWITCH), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oSynchro[KTARGET].oSignalBitPending, KSIG_A);
    EXPECT_EQ_U(waiter->oInternal.oState & (1U << BPROC_SUSP_SIGN), (1U << BPROC_SUSP_SIGN));
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 0U);
}

TEST(signals_a_waiter_accepting_any_sender_is_woken) {
    sign_t  *handle;
    proc_t  *waiter;

    local_setup();

    handle = local_group("Group");

// KKERN_HANDLE_BROADCAST as the EXPECTED sender means "from anyone", and
// KKERN_HANDLE_FROM_ISR is accepted too - the three-way test at signals.c:296.

    waiter = local_waiter(KTARGET, handle, KSIG_A, KKERN_HANDLE_BROADCAST, KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, waiter,
                                  KSIGN_SIGNALE_WITH_CONTEXT_SWITCH), KERR_KERN_NOERR);

    EXPECT_EQ_U(waiter->oInternal.oState & (1U << BPROC_SUSP_SIGN), 0U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 1U);
}

TEST(signals_the_mode_decides_whether_a_wake_preempts) {
    sign_t  *handle;
    proc_t  *waiter;

    local_setup();

    handle = local_group("Group");
    waiter = local_waiter(KTARGET, handle, KSIG_A, &vKern_proc[0][KRUN], KPRIO_HIGH);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, waiter,
                                  KSIGN_SIGNALE_WITHOUT_CONTEXT_SWITCH), KERR_KERN_NOERR);

// Woken, but deliberately not scheduled: a driver signalling from a tight loop
// asks for WITHOUT so the switch happens once at the end rather than per event.

    EXPECT_EQ_U(waiter->oInternal.oState & (1U << BPROC_SUSP_SIGN), 0U);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 0U);

    local_setup();
    handle = local_group("Group");
    waiter = local_waiter(KTARGET, handle, KSIG_A, &vKern_proc[0][KRUN], KPRIO_HIGH);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, waiter,
                                  KSIGN_SIGNALE_WITH_CONTEXT_SWITCH), KERR_KERN_NOERR);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 1U);
}

TEST(signals_signalling_refuses_an_unknown_group_or_process) {
    sign_t      *handle;
    sign_t      sign;
    proc_t      *stranger;

    local_setup();

    handle   = local_group("Group");
    stranger = &vKern_proc[0][KOTHER];                  // installed bit never set
    (void)memset(&sign, 0, sizeof(sign));

    EXPECT_EQ_I(kern_signalSignal(nullptr, KSIG_A, stranger, 0U), KERR_KERN_NOGRO);
    EXPECT_EQ_I(kern_signalSignal(&sign,   KSIG_A, stranger, 0U), KERR_KERN_NOGRO);
    EXPECT_EQ_I(kern_signalSignal(handle,  KSIG_A, nullptr,  0U), KERR_KERN_NOPRO);
    EXPECT_EQ_I(kern_signalSignal(handle,  KSIG_A, stranger, 0U), KERR_KERN_NOPRO);

    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
}

// Broadcast
// =========

TEST(signals_a_broadcast_reaches_every_installed_process_but_the_sender) {
    sign_t  *handle;

    local_setup();

    handle = local_group("Group");
    (void)local_waiter(KTARGET, handle, KSIG_A, KKERN_HANDLE_BROADCAST, KPRIO_LOW);
    (void)local_waiter(KOTHER,  handle, KSIG_A, KKERN_HANDLE_BROADCAST, KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, KKERN_HANDLE_BROADCAST,
                                  KSIGN_SIGNALE_WITH_CONTEXT_SWITCH), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oSynchro[KTARGET].oSignalBitPending, KSIG_A);
    EXPECT_EQ_U(handle->oSynchro[KOTHER].oSignalBitPending,  KSIG_A);

// The sender is skipped explicitly (signals.c:272), so a process broadcasting
// does not signal itself.

    EXPECT_EQ_U(handle->oSynchro[KRUN].oSignalBitPending, 0U);

    EXPECT_EQ_U(vKern_listSign[0].oNbElements, 0U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 2U);
}

TEST(signals_a_broadcast_still_honours_each_waiters_own_mask) {
    sign_t  *handle;
    proc_t  *wantsA;
    proc_t  *wantsB;

    local_setup();

    handle = local_group("Group");
    wantsA = local_waiter(KTARGET, handle, KSIG_A, KKERN_HANDLE_BROADCAST, KPRIO_LOW);
    wantsB = local_waiter(KOTHER,  handle, KSIG_B, KKERN_HANDLE_BROADCAST, KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, KKERN_HANDLE_BROADCAST,
                                  KSIGN_SIGNALE_WITH_CONTEXT_SWITCH), KERR_KERN_NOERR);

// Broadcast means "tell everyone", not "wake everyone": the bit is recorded as
// pending for both, but only the process that asked for A is made runnable.
//
// Added after a mutation survived. Every other broadcast test here gives its
// waiters a mask that matches what is sent, so none could tell
// `oSignalBitGenerate & signals` from `signals` in the broadcast arm - the
// selective arm was covered and the broadcast one only looked like it was.

    EXPECT_EQ_U(handle->oSynchro[KTARGET].oSignalBitPending, KSIG_A);
    EXPECT_EQ_U(handle->oSynchro[KOTHER].oSignalBitPending,  KSIG_A);

    EXPECT_EQ_U(wantsA->oInternal.oState & (1U << BPROC_SUSP_SIGN), 0U);
    EXPECT_EQ_U(wantsB->oInternal.oState & (1U << BPROC_SUSP_SIGN), (1U << BPROC_SUSP_SIGN));

    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 1U);
    EXPECT_EQ_U(vKern_listSign[0].oNbElements, 1U);
}

TEST(signals_the_broadcast_loop_only_remembers_the_last_waiter) {
    sign_t  *handle;

    local_setup();

    handle = local_group("Group");

// A high-priority waiter in a LOWER slot than a low-priority one, so the loop
// visits the urgent process first.

    (void)local_waiter(KTARGET, handle, KSIG_A, KKERN_HANDLE_BROADCAST, KPRIO_HIGH);
    (void)local_waiter(KOTHER,  handle, KSIG_A, KKERN_HANDLE_BROADCAST, KPRIO_LOW);

    EXPECT_EQ_I(kern_signalSignal(handle, KSIG_A, KKERN_HANDLE_BROADCAST,
                                  KSIGN_SIGNALE_WITH_CONTEXT_SWITCH), KERR_KERN_NOERR);

    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 2U);

// Same shape as the release loops in semaphores.c and mutexes.c: preemption is
// ASSIGNED on every pass instead of accumulated (signals.c:280), so the
// high-priority process woken first is forgotten. A fifth site for the same
// defect. See DEFECTS.md.

    KNOWN_BUG("kern-release-loop-preemption-overwritten", (g_kernenv.oNbPreemption == 0U));
}

// The mask accessors
// ==================

TEST(signals_the_waiting_mask_is_the_union_over_suspended_processes) {
    sign_t      *handle;
    uint32_t    mask = 0xFFFFFFFFU;

    local_setup();

    handle = local_group("Group");
    (void)local_waiter(KTARGET, handle, KSIG_A,          &vKern_proc[0][KRUN], KPRIO_LOW);
    (void)local_waiter(KOTHER,  handle, KSIG_B | KSIG_C, &vKern_proc[0][KRUN], KPRIO_LOW);

    EXPECT_EQ_I(kern_getWaitingSignalMask(handle, &mask), KERR_KERN_NOERR);
    EXPECT_EQ_U(mask, KSIG_A | KSIG_B | KSIG_C);

// A process that is installed but NOT suspended contributes nothing, even with
// a generate mask set - the test is on both bits at once (signals.c:472).

    vKern_proc[0][KOTHER].oInternal.oState &= (uint16_t)~(1U << BPROC_SUSP_SIGN);

    EXPECT_EQ_I(kern_getWaitingSignalMask(handle, &mask), KERR_KERN_NOERR);
    EXPECT_EQ_U(mask, KSIG_A);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(signals_clearing_removes_a_bit_from_both_masks) {
    sign_t      *handle;

    local_setup();

    handle = local_group("Group");
    handle->oSynchro[KRUN].oSignalBitPending  = KSIG_A | KSIG_B;
    handle->oSynchro[KRUN].oSignalBitGenerate = KSIG_A | KSIG_C;

    EXPECT_EQ_I(kern_clearPendingSignal(handle, KSIG_A), KERR_KERN_NOERR);

// Both, not just the pending one: leaving the generate bit would make the
// process wakeable by a signal it has just abandoned.

    EXPECT_EQ_U(handle->oSynchro[KRUN].oSignalBitPending,  KSIG_B);
    EXPECT_EQ_U(handle->oSynchro[KRUN].oSignalBitGenerate, KSIG_C);

// It clears the RUNNING process's slot, not a nominated one - there is no
// process argument.

    EXPECT_EQ_U(handle->oSynchro[KTARGET].oSignalBitPending, 0U);
}

TEST(signals_clearing_nothing_returns_before_taking_anything) {
    sign_t      *handle;
    uint32_t    nbOff, nbElevate;

    local_setup();

    handle = local_group("Group");
    handle->oSynchro[KRUN].oSignalBitPending = KSIG_A;

// Like the wait guard, the toClearMask == 0 early return sits before
// PRIVILEGE_ELEVATE (signals.c:511).

    nbOff     = g_kernenv.oNbOff;
    nbElevate = g_kernenv.oNbElevate;

    EXPECT_EQ_I(kern_clearPendingSignal(handle, 0U), KERR_KERN_NOERR);

    EXPECT_EQ_U(g_kernenv.oNbOff, nbOff);
    EXPECT_EQ_U(g_kernenv.oNbElevate, nbElevate);
    EXPECT_EQ_U(handle->oSynchro[KRUN].oSignalBitPending, KSIG_A);
}

// Destruction and lookup
// ======================

TEST(signals_kill_releases_the_group) {
    sign_t  *handle;
    sign_t  *found = nullptr;
    uint8_t bit;

    local_setup();

    handle = local_group("Doomed");
    bit    = 0U;
    (void)kern_createBitSignal(handle, &bit);

    EXPECT_EQ_I(kern_killSignalGroup(handle), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oState, 0U);
    EXPECT_EQ_U(vKern_nbSign[0], 0U);
    EXPECT_EQ_I(kern_getSignalGroupById("Doomed", &found), KERR_KERN_NOGRO);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(signals_lookup_finds_by_identifier) {
    sign_t  *created;
    sign_t  *found = nullptr;

    local_setup();

    created = local_group("Wanted");

    EXPECT_EQ_I(kern_getSignalGroupById("Wanted", &found), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(found, created);

    EXPECT_EQ_I(kern_getSignalGroupById("Absent", &found), KERR_KERN_NOGRO);
    EXPECT_EQ_PTR(found, nullptr);
}

TEST(signals_every_entry_point_gives_the_mask_and_the_privilege_back) {
    sign_t      *handle = nullptr;
    sign_t      sign;
    uint32_t    wanted, mask;
    uint8_t     bit;

    local_setup();

    (void)memset(&sign, 0, sizeof(sign));

    (void)kern_createSignalGroup("x", &handle);
    (void)kern_createSignalGroup("x", &handle);                  // IDGRO
    (void)kern_createBitSignal(&sign, &bit);                     // NOGRO
    (void)kern_createBitSignal(handle, &bit);                    // NOERR
    (void)kern_signalSignal(&sign, KSIG_A, &vKern_proc[0][KRUN], 0U);   // NOGRO
    wanted = KSIG_A;
    (void)kern_waitSignal(&sign, &wanted, &vKern_proc[0][KRUN], 0U);    // NOGRO
    (void)kern_getWaitingSignalMask(&sign, &mask);               // NOGRO
    (void)kern_clearPendingSignal(&sign, KSIG_A);                // NOGRO
    (void)kern_killBitSignal(&sign, 0U);                         // NOGRO
    (void)kern_killSignalGroup(&sign);                           // NOGRO
    (void)kern_getSignalGroupById("absent", &handle);            // NOGRO

    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
    EXPECT_EQ_U(g_kernenv.oNbOff, g_kernenv.oNbRestore);
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
}
