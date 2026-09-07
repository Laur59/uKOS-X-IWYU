/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/object/object.c.
 *
 * Tier 2, and the widest dispatch in the group: seven object flags across two
 * argument forms, plus a core selector. That matrix is what this suite is for -
 * the individual printers are straight field dumps, so one is covered in detail
 * to prove core/number routing and the rest by which heading they produce.
 *
 * The counters are plain arrays declared by the private headers, so tests
 * assign them directly rather than through a helper.
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "kern/kern.h"
#include    "kern/private/private_mailboxes.h"
#include    "kern/private/private_mutexes.h"
#include    "kern/private/private_processes.h"
#include    "kern/private/private_semaphores.h"
#include    "kern/private/private_signals.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aObject_Specifications;

#define KBANNER     "uKOS-X object information.\n\n"
#define KNOOBJECT   "The object does not exist.\n\n"
#define KNOCORE     "The core does not exist.\n\n"

#define KOK         EXIT_OS_SUCCESS_CLI
#define KFAIL       EXIT_OS_FAILURE

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aObject_Specifications.oExecution(argc, argv);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(object_module_metadata) {

    ukos_t_begin("UTC0");

    EXPECT_EQ_U(aObject_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_OBJECT << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aObject_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
}

// ============================================================================
// argc == 1  -  the summary
// ============================================================================

TEST(object_summary_reports_the_counters) {
    const char_t    *argv[] = { "object" };
    int32_t         status;

    ukos_t_begin("UTC0");
    vKern_nbProc[0]    = 7U;    vKern_nbMaxProc[0] = 9U;
    vKern_nbSema[0]    = 3U;    vKern_nbMaxSema[0] = 4U;
    vKern_nbMutx[0]    = 1U;    vKern_nbMaxMutx[0] = 2U;

    status = local_run(1U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);

// Three columns per line: the compile-time capacity, the high-water mark, then
// the current usage.

    EXPECT_OUT_HAS("Objects used by the core 0\n\n");
    EXPECT_OUT_HAS("Available processes      =  48, max. used processes      =   9, used processes      =   7\n");
    EXPECT_OUT_HAS("Available semaphores     =  48, max. used semaphores     =   4, used semaphores     =   3\n");
    EXPECT_OUT_HAS("Available mutex          =  48, max. used mutex          =   2, used mutex          =   1\n");
}

TEST(object_summary_lists_every_kind) {
    const char_t    *argv[] = { "object" };

    ukos_t_begin("UTC0");
    (void)local_run(1U, argv);

    EXPECT_OUT_HAS("Available mailboxes ");
    EXPECT_OUT_HAS("Available signal groups ");

#if (KKERN_NB_SOFTWARE_TIMERS > 0)
    EXPECT_OUT_HAS("Available soft-timers ");
#else
    EXPECT_OUT_HAS("No soft-timer in the system\n");
#endif
#if (KKERN_NB_PRECISE_SIGNALS > 0)
    EXPECT_OUT_HAS("Available precise signal ");
#else
    EXPECT_OUT_HAS("No precise signal in the system\n\n");
#endif
}

TEST(object_two_arguments_fall_through_to_the_summary) {
    const char_t    *argv[] = { "object", "-proc" };

    ukos_t_begin("UTC0");

// Only argc 3 and 4 select an object; the default arm precedes case 1U and
// falls into it, so an incomplete request silently prints the summary instead
// of reporting a bad argument.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("Objects used by the core 0\n\n");
}

TEST(object_five_arguments_fall_through_to_the_summary) {
    const char_t    *argv[] = { "object", "0", "-proc", "5", "junk" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(5U, argv), KOK);
    EXPECT_OUT_HAS("Objects used by the core 0\n\n");
}

// ============================================================================
// argc == 3  -  the short form, core implied
// ============================================================================

TEST(object_short_form_selects_each_kind) {
    const char_t    *argvProc[] = { "object", "-proc", "0" };
    const char_t    *argvSema[] = { "object", "-sema", "0" };
    const char_t    *argvMutx[] = { "object", "-mutx", "0" };
    const char_t    *argvMbox[] = { "object", "-mbox", "0" };
    const char_t    *argvSign[] = { "object", "-sign", "0" };

    ukos_t_begin("UTC0"); (void)local_run(3U, argvProc); EXPECT_OUT_HAS("Process 00:");
    ukos_t_begin("UTC0"); (void)local_run(3U, argvSema); EXPECT_OUT_HAS("Semaphore 00:");
    ukos_t_begin("UTC0"); (void)local_run(3U, argvMutx); EXPECT_OUT_HAS("Mutex 00:");
    ukos_t_begin("UTC0"); (void)local_run(3U, argvMbox); EXPECT_OUT_HAS("Mailbox 00:");
    ukos_t_begin("UTC0"); (void)local_run(3U, argvSign); EXPECT_OUT_HAS("Signal group 00:");
}

TEST(object_short_form_mutx_works) {
    const char_t    *argv[] = { "object", "-mutx", "2" };
    int32_t         status;

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 2U, "Mutx_test", 5, NULL);

// The three-argument form tests argv[1] for every flag, so -mutx behaves like
// its siblings here. The four-argument form does not - see below.

    status = local_run(3U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_HAS("Mutex 02:\n");
    EXPECT_OUT_HAS("   Identifier:           Mutx_test\n");
    EXPECT_OUT_HAS("   Counter:              5\n");
}

TEST(object_short_form_unknown_flag) {
    const char_t    *argv[] = { "object", "-xyz", "0" };
    int32_t         status;

    ukos_t_begin("UTC0");
    status = local_run(3U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KNOOBJECT);
}

// ============================================================================
// argc == 4  -  the long form, core explicit
// ============================================================================

TEST(object_long_form_selects_each_kind) {
    const char_t    *argvProc[] = { "object", "0", "-proc", "0" };
    const char_t    *argvSema[] = { "object", "0", "-sema", "0" };
    const char_t    *argvMbox[] = { "object", "0", "-mbox", "0" };
    const char_t    *argvSign[] = { "object", "0", "-sign", "0" };

    ukos_t_begin("UTC0"); (void)local_run(4U, argvProc); EXPECT_OUT_HAS("Process 00:");
    ukos_t_begin("UTC0"); (void)local_run(4U, argvSema); EXPECT_OUT_HAS("Semaphore 00:");
    ukos_t_begin("UTC0"); (void)local_run(4U, argvMbox); EXPECT_OUT_HAS("Mailbox 00:");
    ukos_t_begin("UTC0"); (void)local_run(4U, argvSign); EXPECT_OUT_HAS("Signal group 00:");
}

TEST(object_long_form_mutx_is_rejected) {
    const char_t    *argv[] = { "object", "0", "-mutx", "2" };
    int32_t         status;

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 2U, "Mutx_test", 5, NULL);

// DEFECT (DEFECTS.md): object.c:138 tests argv[1] for "-mutx" inside the
// argc == 4 arm, where all six sibling lines test argv[2]. argv[1] is the core
// number here, so the flag never matches and a perfectly well-formed request is
// refused. Pinned as CURRENT behaviour; correcting the module turns this red.

    status = local_run(4U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KNOOBJECT);
    EXPECT_OUT_LACKS("Mutx_test");
}

TEST(object_long_form_mutx_works_in_the_wrong_order) {
    const char_t    *argv[] = { "object", "-mutx", "ignored", "2" };

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 2U, "Mutx_test", 5, NULL);

// The mirror image of the defect: because argv[1] is what is compared, putting
// the flag where the core belongs DOES select the mutex. strtoul("-mutx")
// yields 0, which happens to be a valid core, so nothing rejects it.

    EXPECT_EQ_I(local_run(4U, argv), KOK);
    EXPECT_OUT_HAS("Mutex 02:\n");
    EXPECT_OUT_HAS("   Identifier:           Mutx_test\n");
}

TEST(object_long_form_unknown_flag) {
    const char_t    *argv[] = { "object", "0", "-xyz", "0" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(4U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KNOOBJECT);
}

TEST(object_core_out_of_range_is_rejected) {
    const char_t    *argv[] = { "object", "9", "-proc", "0" };
    int32_t         status;

    ukos_t_begin("UTC0");
    status = local_run(4U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KNOCORE);
}

TEST(object_core_is_checked_before_the_flag) {
    const char_t    *argv[] = { "object", "9", "-xyz", "0" };

    ukos_t_begin("UTC0");

// A bad core and a bad flag together must report the core, since that check
// comes first and breaks out.

    EXPECT_EQ_I(local_run(4U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KNOCORE);
}

TEST(object_non_numeric_core_is_zero) {
    const char_t    *argv[] = { "object", "abc", "-proc", "0" };

    ukos_t_begin("UTC0");

// strtoul yields 0 and the end pointer is never inspected, so a nonsense core
// silently becomes core 0 rather than being reported.

    EXPECT_EQ_I(local_run(4U, argv), KOK);
    EXPECT_OUT_HAS("Process 00:");
}

// ============================================================================
// The object number
// ============================================================================

TEST(object_number_out_of_range_is_reported_per_kind) {
    const char_t    *argv[] = { "object", "-mutx", "999" };

    ukos_t_begin("UTC0");

// Each printer bounds its own index and says so rather than reading past the
// table.

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_OUT_HAS("The mutex 999 does not exist\n");
}

TEST(object_number_is_truncated_to_sixteen_bits) {
    const char_t    *argv[] = { "object", "-mutx", "65538" };

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 2U, "Mutx_test", 5, NULL);

// number is parsed into a uint32_t and passed as (uint16_t), so 65536 + 2
// selects slot 2.

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_OUT_HAS("Mutex 02:\n");
    EXPECT_OUT_HAS("Mutx_test");
}

TEST(object_non_numeric_number_is_zero) {
    const char_t    *argv[] = { "object", "-mutx", "abc" };

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 0U, "Mutx_zero", 0, NULL);

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_OUT_HAS("Mutex 00:\n");
    EXPECT_OUT_HAS("Mutx_zero");
}

// ============================================================================
// One printer in detail  -  proves the fields are read from the right slot
// ============================================================================

TEST(object_mutex_detail_reads_the_selected_slot) {
    const char_t    *argv[] = { "object", "-mutx", "3" };
    proc_t          *owner;

    ukos_t_begin("UTC0");
    owner = ukos_fake_addProcess("console");
    ukos_fake_addMutex(0U, 1U, "Mutx_wrong", 11, NULL);
    ukos_fake_addMutex(0U, 3U, "Mutx_right", 22, owner);
    vKern_mutx[0][3].oState      = (uint16_t)(1U << BMUTX_INSTALLED);
    vKern_mutx[0][3].oMaxCounter = 33;

    (void)local_run(3U, argv);

    EXPECT_OUT_HAS("Mutex 03:\n");
    EXPECT_OUT_HAS("   Identifier:           Mutx_right\n");
    EXPECT_OUT_HAS("   Mutex state:          0x0001, Installed mutex\n");
    EXPECT_OUT_HAS("   Counter:              22\n");
    EXPECT_OUT_HAS("   Max. Counter:         33\n");
    EXPECT_OUT_LACKS("Mutx_wrong");
}

TEST(object_mutex_detail_describes_the_owner_kind) {
    const char_t    *argvNone[] = { "object", "-mutx", "0" };
    const char_t    *argvIsr[]  = { "object", "-mutx", "1" };
    const char_t    *argvProc[] = { "object", "-mutx", "2" };
    proc_t          *owner;

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 0U, "Mutx_a", 0, NULL);
    (void)local_run(3U, argvNone);
    EXPECT_OUT_HAS("No owner\n");

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 1U, "Mutx_b", 0, KKERN_HANDLE_FROM_ISR);
    (void)local_run(3U, argvIsr);
    EXPECT_OUT_HAS("ISR owner\n");

    ukos_t_begin("UTC0");
    owner = ukos_fake_addProcess("console");
    ukos_fake_addMutex(0U, 2U, "Mutx_c", 0, owner);
    (void)local_run(3U, argvProc);
    EXPECT_OUT_HAS("Process owner\n");
}

TEST(object_unused_slot_prints_a_null_identifier) {
    const char_t    *argv[] = { "object", "-mutx", "7" };

    ukos_t_begin("UTC0");

// DEFECT (DEFECTS.md): an unused slot has oIdentifier == NULL, and the printer
// hands it straight to dprintf("%s"). Passing NULL to %s is undefined; this
// host prints "(null)" but a target libc need not. Querying an unused object is
// an ordinary thing for a user to do, so this path is reachable in normal use.
// Pinned as CURRENT behaviour, and only by shape - the exact rendering is a
// property of the libc, not of the module.

    ukos_t_poisonStack();

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_OUT_HAS("Mutex 07:\n");
    EXPECT_OUT_HAS("   Identifier:           ");
}

TEST(object_uninstalled_slot_says_so) {
    const char_t    *argv[] = { "object", "-mutx", "4" };

    ukos_t_begin("UTC0");
    ukos_fake_addMutex(0U, 4U, "Mutx_d", 0, NULL);

// oState is left clear, so the BMUTX_INSTALLED bit is absent.

    (void)local_run(3U, argv);

    EXPECT_OUT_HAS("   Mutex state:          0x0000, Not installed\n");
}

// ============================================================================
// Privilege
// ============================================================================

TEST(object_elevates_and_restores_on_every_path) {
    const char_t    *argvOk[]  = { "object", "-mutx", "0" };
    const char_t    *argvBad[] = { "object", "9", "-proc", "0" };

    ukos_t_begin("UTC0");
    (void)local_run(3U, argvOk);
#ifdef PRIVILEGED_USER_S
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
    EXPECT_EQ_U(g_kern.restores, 1U);
#endif

// The error arms return through the same tail, so the bad-core path must
// restore too.

    ukos_t_begin("UTC0");
    (void)local_run(4U, argvBad);
#ifdef PRIVILEGED_USER_S
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
    EXPECT_EQ_U(g_kern.restores, 1U);
#else
    EXPECT_EQ_U(g_kern.calls, 0U);
#endif
}
