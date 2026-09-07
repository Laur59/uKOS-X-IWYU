/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/mutex/mutex.c.
 *
 * Tier 2, and the first module to walk a kernel object table. vKern_mutx is
 * seeded directly, so arrangements a live system would take real contention to
 * produce - three processes queued on one mutex, an ISR owner, a negative
 * counter - are one call each.
 *
 * The golden lines are derived from the module's own format strings and from
 * local_compose(), which pads an identifier to 32 characters. Column alignment
 * is the contract here; it is what a careless edit breaks first.
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "kern/kern.h"
#include    "kern/private/private_mutexes.h"
#include    "kern/processes.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aMutex_Specifications;

#define KBANNER     "List of the system mutexes.\n"
#define KHEADER     " #  Mutex identifier                  Counter  Owner process identifier          Waiting process\n\n"
#define KCORE0      "Mutexes used by the core 0\n\n"

#define KOK         EXIT_OS_SUCCESS_CLI

static int32_t local_run(void) {
    const char_t    *argv[] = { "mutex" };

    return aMutex_Specifications.oExecution(1U, argv);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(mutex_module_metadata) {

    ukos_t_begin("UTC0");

// DEFECT (DEFECTS.md): mutex.c:43 declares KNUM_SEMAPHORE, so this module and
// semaphore both register as X33_ and KNUM_MUTEX is used by nothing. Pinned as
// CURRENT behaviour - correcting the module will turn this red.

    EXPECT_EQ_U(aMutex_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_SEMAPHORE << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_TRUE(KNUM_MUTEX != KNUM_SEMAPHORE);
    EXPECT_EQ_U(aMutex_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
}

// ============================================================================
// An empty table
// ============================================================================

TEST(mutex_empty_table_prints_only_the_headers) {
    int32_t     status;

    ukos_t_begin("UTC0");
    status = local_run();

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);

// Every slot has a NULL identifier, so the module renders nothing between the
// per-core header and its trailing blank line.

    EXPECT_OUT_IS(KBANNER KHEADER KCORE0 "\n");
}

TEST(mutex_takes_no_arguments) {
    const char_t    *argv[] = { "mutex", "junk" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(aMutex_Specifications.oExecution(2U, argv), KOK);
    EXPECT_OUT_HAS(KHEADER);
}

// ============================================================================
// Rendering one entry
// ============================================================================

TEST(mutex_free_entry_golden_output) {
    int32_t     status;

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 0U, "Mutx_test", 1, NULL);

    status = local_run();

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_OUT_IS(KBANNER KHEADER KCORE0
                  " 0  Mutx_test                            1     \n"
                  "\n");
}

TEST(mutex_owned_entry_names_the_owner) {
    proc_t      *console;

    ukos_t_begin("UTC0");
    console = ukos_fake_addProcess("console");
    ukos_fake_addMutex(0U, 3U, "Mutx_serial", 0, console);

    (void)local_run();

// The slot index is the printed number, so an entry at slot 3 reports 3.

    EXPECT_OUT_HAS(" 3  Mutx_serial                          0     console\n");
}

TEST(mutex_isr_owner_is_named_rather_than_dereferenced) {

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 4U, "Mutx_isr", 0, KKERN_HANDLE_FROM_ISR);

// KKERN_HANDLE_FROM_ISR is the sentinel pointer 0x1, so the module must
// recognise it before following oSpecification. Getting this wrong is a null-ish
// dereference, not a formatting slip.

    EXPECT_EQ_I(local_run(), KOK);
    EXPECT_OUT_HAS(" 4  Mutx_isr                             0     From ISR\n");
}

TEST(mutex_negative_counter) {
    proc_t      *console;

    ukos_t_begin("UTC0");
    console = ukos_fake_addProcess("console");
    ukos_fake_addMutex(0U, 1U, "Mutx_memo", -1, console);

    (void)local_run();

    EXPECT_OUT_HAS(" 1  Mutx_memo                           -1     console\n");
}

TEST(mutex_long_identifier_is_not_padded) {
    const char_t    *longId = "Mutex_with_a_very_long_identifier_x";   // 34 > 32

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 0U, longId, 0, NULL);

// local_compose falls back to the full spacer when the identifier does not fit,
// so the column runs over rather than truncating the name.

    EXPECT_EQ_I(local_run(), KOK);
    EXPECT_OUT_HAS(longId);
}

// ============================================================================
// The waiting list
// ============================================================================

TEST(mutex_one_waiter_is_printed_on_the_entry_line) {
    proc_t      *console, *waiters[1];

    ukos_t_begin("UTC0");
    console    = ukos_fake_addProcess("console");
    waiters[0] = ukos_fake_addProcess("procA");
    ukos_fake_addMutex(0U, 1U, "Mutx_memo", -1, console);
    ukos_fake_attachWaiters(&vKern_mutx[0][1].oList, &waiters[0], 1U);

    (void)local_run();

    EXPECT_OUT_HAS(" 1  Mutx_memo                           -1     console"
                   "                           procA\n");
}

TEST(mutex_further_waiters_go_on_continuation_lines) {
    proc_t      *owner, *waiters[3];

    ukos_t_begin("UTC0");
    owner      = ukos_fake_addProcess("owner1");
    waiters[0] = ukos_fake_addProcess("p1");
    waiters[1] = ukos_fake_addProcess("p2");
    waiters[2] = ukos_fake_addProcess("p3");
    ukos_fake_addMutex(0U, 2U, "Mutx_x", 5, owner);
    ukos_fake_attachWaiters(&vKern_mutx[0][2].oList, &waiters[0], 3U);

    (void)local_run();

// The first waiter shares the entry line; the rest are indented under the
// Waiting process column.

    EXPECT_OUT_HAS(" 2  Mutx_x                               5     owner1"
                   "                            p1\n"
                   "                                                                                 p2\n"
                   "                                                                                 p3\n");
}

TEST(mutex_waiter_chain_is_followed_not_assumed) {
    proc_t      *owner, *waiters[3];

    ukos_t_begin("UTC0");
    owner      = ukos_fake_addProcess("owner1");
    waiters[0] = ukos_fake_addProcess("p1");
    waiters[1] = ukos_fake_addProcess("p2");
    waiters[2] = ukos_fake_addProcess("p3");
    ukos_fake_addMutex(0U, 0U, "Mutx_x", 0, owner);
    ukos_fake_attachWaiters(&vKern_mutx[0][0].oList, &waiters[0], 3U);

// oNbElements says how many to print, oForward says which. Shortening the count
// without touching the chain must print exactly the first two.

    vKern_mutx[0][0].oList.oNbElements = 2U;

    (void)local_run();

    EXPECT_OUT_HAS("p1\n");
    EXPECT_OUT_HAS("p2\n");
    EXPECT_OUT_LACKS("p3");
}

TEST(mutex_empty_list_takes_the_no_waiter_branch) {
    proc_t      *console, *stray[1];

    ukos_t_begin("UTC0");
    console  = ukos_fake_addProcess("console");
    stray[0] = ukos_fake_addProcess("procA");
    ukos_fake_addMutex(0U, 0U, "Mutx_memo", 0, console);
    ukos_fake_attachWaiters(&vKern_mutx[0][0].oList, &stray[0], 1U);

// oNbElements is what gates the branch, not oFirst - a stale oFirst must not
// resurrect a waiter.

    vKern_mutx[0][0].oList.oNbElements = 0U;

    (void)local_run();

    EXPECT_OUT_HAS(" 0  Mutx_memo                            0     console\n");
    EXPECT_OUT_LACKS("procA");
}

// ============================================================================
// Several entries
// ============================================================================

TEST(mutex_entries_appear_in_slot_order) {

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 5U, "Mutx_five", 0, NULL);
    ukos_fake_addMutex(0U, 1U, "Mutx_one",  0, NULL);

// The table is walked by index, so the seeding order does not matter.

    (void)local_run();

    EXPECT_OUT_IS(KBANNER KHEADER KCORE0
                  " 1  Mutx_one                             0     \n"
                  " 5  Mutx_five                            0     \n"
                  "\n");
}

TEST(mutex_gaps_are_skipped) {

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 0U, "Mutx_a", 0, NULL);
    ukos_fake_addMutex(0U, 2U, "Mutx_b", 0, NULL);

    (void)local_run();

// Slot 1 has a NULL identifier and produces no line at all - not a blank one.

    EXPECT_OUT_HAS(" 0  Mutx_a");
    EXPECT_OUT_HAS(" 2  Mutx_b");
    EXPECT_OUT_LACKS(" 1  ");
}

TEST(mutex_last_slot_is_reached) {

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, (uint16_t)(KKERN_NB_MUTEXES - 1U), "Mutx_last", 0, NULL);

// The loop bound is KKERN_NB_MUTEXES, so the final slot must render.

    EXPECT_EQ_I(local_run(), KOK);
    EXPECT_OUT_HAS("Mutx_last");
}

// ============================================================================
// Privilege and critical sections
// ============================================================================

TEST(mutex_elevates_once_and_restores) {

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 0U, "Mutx_test", 0, NULL);

    (void)local_run();

#ifdef PRIVILEGED_USER_S
    EXPECT_EQ_U(g_kern.elevates, 1U);
    EXPECT_EQ_U(g_kern.restores, 1U);
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
#else
    EXPECT_EQ_U(g_kern.calls, 0U);
#endif
}

TEST(mutex_brackets_each_entry_in_a_critical_section) {

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 0U, "Mutx_a", 0, NULL);
    ukos_fake_addMutex(0U, 1U, "Mutx_b", 0, NULL);

    (void)local_run();

// One enter/exit pair per rendered entry, never nested and never left open.

    EXPECT_EQ_U(g_kern.criticalEnters, 2U);
    EXPECT_EQ_U(g_kern.criticalExits, 2U);
    EXPECT_FALSE(g_kern.criticalUnbalanced);
    EXPECT_EQ_I(g_kern.criticalDepth, 0);
}

TEST(mutex_empty_table_enters_no_critical_section) {

    ukos_t_begin("UTC0");
    (void)local_run();

    EXPECT_EQ_U(g_kern.criticalEnters, 0U);
}
