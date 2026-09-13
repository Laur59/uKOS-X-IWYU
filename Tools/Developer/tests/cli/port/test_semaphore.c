/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/semaphore/semaphore.c.
 *
 * Tier 2. The module is structurally identical to mutex - same table walk, same
 * local_compose() padding, same waiter chain - over vKern_sema instead of
 * vKern_mutx, so the seam built for mutex is reused unchanged.
 *
 * The suite is not a copy of the mutex one. What differs between the two
 * modules is exactly what is asserted here: the banner, the column header, the
 * per-core line and the "Synchro process" wording in place of "Owner process".
 * A copy-paste slip between the two files is the most likely way either breaks,
 * and it is the thing these goldens catch.
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "kern/kern.h"
#include    "kern/private/private_semaphores.h"
#include    "kern/processes.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aSemaphore_Specifications;

#define KBANNER     "List of the system semaphores.\n"
#define KHEADER     " #  Semaphore identifier              Counter  Synchro process identifier        Waiting process\n\n"
#define KCORE0      "Semaphores used by the core 0\n\n"

#define KOK         EXIT_OS_SUCCESS_CLI

static int32_t local_run(void) {
    const char_t    *argv[] = { "semaphore" };

    return aSemaphore_Specifications.oExecution(1U, argv);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(semaphore_module_metadata) {

    ukos_t_begin("UTC0");

// This identifier belongs to this module alone. mutex.c:43 used to declare
// KNUM_SEMAPHORE as well, so both registered as X33_; it now carries KNUM_MUTEX.
// The two being distinct is asserted in the mutex suite, which is the only
// place both descriptors are linked together.

    EXPECT_EQ_U(aSemaphore_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_SEMAPHORE << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aSemaphore_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
}

// ============================================================================
// The headings  -  what actually differs from mutex
// ============================================================================

TEST(semaphore_empty_table_prints_only_the_headers) {
    int32_t     status;

    ukos_t_begin("UTC0");
    status = local_run();

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER KHEADER KCORE0 "\n");
}

TEST(semaphore_headings_are_not_the_mutex_ones) {

    ukos_t_begin("UTC0");
    (void)local_run();

// The two modules are near-identical, so the wording is the only thing that
// says which one ran.

    EXPECT_OUT_HAS("Semaphore identifier");
    EXPECT_OUT_HAS("Synchro process identifier");
    EXPECT_OUT_LACKS("Mutex identifier");
    EXPECT_OUT_LACKS("Owner process identifier");
    EXPECT_OUT_LACKS("Mutexes used by the core");
}

TEST(semaphore_takes_no_arguments) {
    const char_t    *argv[] = { "semaphore", "junk" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(aSemaphore_Specifications.oExecution(2U, argv), KOK);
    EXPECT_OUT_HAS(KHEADER);
}

// ============================================================================
// Rendering entries
// ============================================================================

TEST(semaphore_free_entry_golden_output) {

    ukos_t_begin("UTC0");
    ukos_fake_addSemaphore(0U, 0U, "Sema_test", 1, NULL);

    (void)local_run();

// Same column geometry as mutex: two-wide index, identifier padded to 32, then
// a three-wide counter.

    EXPECT_OUT_IS(KBANNER KHEADER KCORE0
                  " 0  Sema_test                            1     \n"
                  "\n");
}

TEST(semaphore_synchronising_process_is_named) {
    proc_t      *console;

    ukos_t_begin("UTC0");
    console = ukos_fake_addProcess("console");
    ukos_fake_addSemaphore(0U, 3U, "Sema_serial", 0, console);

    (void)local_run();

    EXPECT_OUT_HAS(" 3  Sema_serial                          0     console\n");
}

TEST(semaphore_isr_synchro_is_named_rather_than_dereferenced) {

    ukos_t_begin("UTC0");
    ukos_fake_addSemaphore(0U, 4U, "Sema_isr", 0, KKERN_HANDLE_FROM_ISR);

// A semaphore given from an interrupt is the common case, unlike a mutex owned
// by one, so this path matters more here.

    EXPECT_EQ_I(local_run(), KOK);
    EXPECT_OUT_HAS(" 4  Sema_isr                             0     From ISR\n");
}

TEST(semaphore_negative_counter) {

    ukos_t_begin("UTC0");
    ukos_fake_addSemaphore(0U, 1U, "Sema_memo", -2, NULL);

// A negative count is how many takers are queued, so it is the normal state of
// a contended semaphore rather than an error.

    (void)local_run();

    EXPECT_OUT_HAS(" 1  Sema_memo                           -2     \n");
}

// ============================================================================
// The waiting list  -  the seam built for mutex, reused
// ============================================================================

TEST(semaphore_one_waiter_is_printed_on_the_entry_line) {
    proc_t      *waiters[1];

    ukos_t_begin("UTC0");
    waiters[0] = ukos_fake_addProcess("procA");
    ukos_fake_addSemaphore(0U, 1U, "Sema_memo", -1, KKERN_HANDLE_FROM_ISR);
    ukos_fake_attachWaiters(&vKern_sema[0][1].oList, &waiters[0], 1U);

    (void)local_run();

    EXPECT_OUT_HAS(" 1  Sema_memo                           -1     From ISR"
                   "                          procA\n");
}

TEST(semaphore_further_waiters_go_on_continuation_lines) {
    proc_t      *sync, *waiters[3];

    ukos_t_begin("UTC0");
    sync       = ukos_fake_addProcess("giver1");
    waiters[0] = ukos_fake_addProcess("p1");
    waiters[1] = ukos_fake_addProcess("p2");
    waiters[2] = ukos_fake_addProcess("p3");
    ukos_fake_addSemaphore(0U, 2U, "Sema_x", -3, sync);
    ukos_fake_attachWaiters(&vKern_sema[0][2].oList, &waiters[0], 3U);

    (void)local_run();

    EXPECT_OUT_HAS(" 2  Sema_x                              -3     giver1"
                   "                            p1\n"
                   "                                                                                 p2\n"
                   "                                                                                 p3\n");
}

TEST(semaphore_waiter_chain_is_followed_not_assumed) {
    proc_t      *waiters[3];

    ukos_t_begin("UTC0");
    waiters[0] = ukos_fake_addProcess("p1");
    waiters[1] = ukos_fake_addProcess("p2");
    waiters[2] = ukos_fake_addProcess("p3");
    ukos_fake_addSemaphore(0U, 0U, "Sema_x", 0, NULL);
    ukos_fake_attachWaiters(&vKern_sema[0][0].oList, &waiters[0], 3U);

    vKern_sema[0][0].oList.oNbElements = 2U;

    (void)local_run();

    EXPECT_OUT_HAS("p1\n");
    EXPECT_OUT_HAS("p2\n");
    EXPECT_OUT_LACKS("p3");
}

// ============================================================================
// Several entries
// ============================================================================

TEST(semaphore_entries_appear_in_slot_order) {

    ukos_t_begin("UTC0");
    ukos_fake_addSemaphore(0U, 5U, "Sema_five", 0, NULL);
    ukos_fake_addSemaphore(0U, 1U, "Sema_one",  0, NULL);

    (void)local_run();

    EXPECT_OUT_IS(KBANNER KHEADER KCORE0
                  " 1  Sema_one                             0     \n"
                  " 5  Sema_five                            0     \n"
                  "\n");
}

TEST(semaphore_gaps_are_skipped) {

    ukos_t_begin("UTC0");
    ukos_fake_addSemaphore(0U, 0U, "Sema_a", 0, NULL);
    ukos_fake_addSemaphore(0U, 2U, "Sema_b", 0, NULL);

    (void)local_run();

    EXPECT_OUT_HAS(" 0  Sema_a");
    EXPECT_OUT_HAS(" 2  Sema_b");
    EXPECT_OUT_LACKS(" 1  ");
}

TEST(semaphore_last_slot_is_reached) {

    ukos_t_begin("UTC0");
    ukos_fake_addSemaphore(0U, (uint16_t)(KKERN_NB_SEMAPHORES - 1U), "Sema_last", 0, NULL);

// The loop bound is KKERN_NB_SEMAPHORES, which is a different constant from the
// mutex one - a copy-paste between the two files would show up here.

    EXPECT_EQ_I(local_run(), KOK);
    EXPECT_OUT_HAS("Sema_last");
}

TEST(semaphore_does_not_read_the_mutex_table) {

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 0U, "Mutx_should_not_appear", 0, NULL);
    ukos_fake_addSemaphore(0U, 0U, "Sema_a", 0, NULL);

    (void)local_run();

    EXPECT_OUT_HAS("Sema_a");
    EXPECT_OUT_LACKS("Mutx_should_not_appear");
}

// ============================================================================
// Privilege and critical sections
// ============================================================================

TEST(semaphore_elevates_once_and_restores) {

    ukos_t_begin("UTC0");
    ukos_fake_addSemaphore(0U, 0U, "Sema_test", 0, NULL);

    (void)local_run();

#ifdef PRIVILEGED_USER_S
    EXPECT_EQ_U(g_kern.elevates, 1U);
    EXPECT_EQ_U(g_kern.restores, 1U);
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
#else
    EXPECT_EQ_U(g_kern.calls, 0U);
#endif
}

TEST(semaphore_brackets_each_entry_in_a_critical_section) {

    ukos_t_begin("UTC0");
    ukos_fake_addSemaphore(0U, 0U, "Sema_a", 0, NULL);
    ukos_fake_addSemaphore(0U, 1U, "Sema_b", 0, NULL);

    (void)local_run();

    EXPECT_EQ_U(g_kern.criticalEnters, 2U);
    EXPECT_EQ_U(g_kern.criticalExits, 2U);
    EXPECT_FALSE(g_kern.criticalUnbalanced);
}
