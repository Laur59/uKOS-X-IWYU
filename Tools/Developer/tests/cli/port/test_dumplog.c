/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/dumplog/dumplog.c.
 *
 * Tier 2, and the first module with a real allocation to fail. Its substance is
 * the selection sort: the log buffer is unordered, and the module repeatedly
 * scans for the oldest unmarked record, prints it and marks it. The ordering,
 * the marking and the scan's stopping conditions are what this suite proves.
 *
 * The memo double is calloc-backed, so ASan guards the module's writes into the
 * snapshot and would see a render after the free.
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "modules.h"
#include    "record/private/private_record.h"
#include    "record/record.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aDumplog_Specifications;

#define KBANNER     "Log dump.\n"
#define KCORE0      "Log provided by the core 0\n\n"
#define KHEADER     "      Time [us]  Category          Process or ISR identifier            Function                              Line   Information\n\n"

#define KOK         EXIT_OS_SUCCESS_CLI
#define KFAIL       EXIT_OS_FAILURE

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aDumplog_Specifications.oExecution(argc, argv);
}

static int32_t local_runBare(void) {
    const char_t    *argv[] = { "dumplog" };

    return local_run(1U, argv);
}

// The order in which identifiers appear in the output.

static bool local_before(const char *first, const char *second) {
    const char  *a = strstr(&g_fakes.out[0], first);
    const char  *b = strstr(&g_fakes.out[0], second);

    return (a != NULL) && (b != NULL) && (a < b);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(dumplog_module_metadata) {

    ukos_t_begin("UTC0");

    EXPECT_EQ_U(aDumplog_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_DUMP_LOG << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aDumplog_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
}

// ============================================================================
// The allocation
// ============================================================================

TEST(dumplog_allocates_a_snapshot_and_frees_it) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 7U, "idle", "main", 1U, "boot");

    EXPECT_EQ_I(local_runBare(), KOK);

// One buffer the size of the whole log, tagged with the module name, and
// released before returning.

    EXPECT_EQ_U(g_kern.mallocCalls, 1U);
    EXPECT_EQ_U(g_kern.lastMallocSize, (uint32_t)(KRECORD_SZ_LOG_BUF * sizeof(recordLogging_t)));
    EXPECT_EQ_STR(g_kern.lastMallocId, "dumplog");
    EXPECT_EQ_U(g_kern.freeCalls, 1U);
}

TEST(dumplog_reports_an_allocation_failure) {
    int32_t     status;

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 7U, "idle", "main", 1U, "boot");
    g_kern.failNextMalloc = true;

// Unlike the dead error arms in mutex and object, this one is genuinely
// reachable - and only by making the allocator fail.

    status = local_runBare();

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Not enough memory.\n");
    EXPECT_EQ_U(g_kern.freeCalls, 0U);
    EXPECT_OUT_LACKS("idle");
}

TEST(dumplog_restores_privilege_after_an_allocation_failure) {

    ukos_t_begin("UTC0");
    g_kern.failNextMalloc = true;

// The early return is the path most likely to leak an elevation.

    (void)local_runBare();

#ifdef PRIVILEGED_USER_S
    EXPECT_EQ_U(g_kern.elevates, 1U);
    EXPECT_EQ_U(g_kern.restores, 1U);
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
#else
    EXPECT_EQ_U(g_kern.calls, 0U);
#endif
}

// ============================================================================
// An empty log
// ============================================================================

TEST(dumplog_empty_buffer_prints_only_the_headers) {
    int32_t     status;

    ukos_t_begin("UTC0");
    status = local_runBare();

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);

// A zero timestamp in the first slot means "nothing recorded", so not even the
// trailing blank line is emitted.

    EXPECT_OUT_IS(KBANNER KCORE0 KHEADER);
}

// ============================================================================
// Rendering
// ============================================================================

TEST(dumplog_single_record_golden_output) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KERROR_KERNEL, 1234U, "console", "local_run", 42U, "mbox problem");

    EXPECT_EQ_I(local_runBare(), KOK);

// Identifier and function are each padded to 33 characters by local_compose.

    EXPECT_OUT_IS(KBANNER KCORE0 KHEADER
                  "        1234-us  Error kernel      console                              "
                  "local_run                               42   mbox problem\n"
                  "\n");
}

TEST(dumplog_category_labels) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KFATAL_SYSTEM,  1U, "a", "f", 1U, "m");
    ukos_fake_addLog(0U, 1U, KERROR_USER,    2U, "b", "f", 1U, "m");
    ukos_fake_addLog(0U, 2U, KWARNING_MANAGER, 3U, "c", "f", 1U, "m");
    ukos_fake_addLog(0U, 3U, KINFO_KERNEL,   4U, "d", "f", 1U, "m");

    (void)local_runBare();

// Every label is padded to the same width so the column cannot drift.

    EXPECT_OUT_HAS("Fatal system    ");
    EXPECT_OUT_HAS("Error user      ");
    EXPECT_OUT_HAS("Warning manager ");
    EXPECT_OUT_HAS("Info kernel     ");
}

TEST(dumplog_unknown_category) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, 0xFFU, 1U, "a", "f", 1U, "m");

    (void)local_runBare();

    EXPECT_OUT_HAS("Unknown         ");
}

// ============================================================================
// The selection sort  -  the substance of the module
// ============================================================================

TEST(dumplog_records_are_printed_oldest_first) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 300U, "third",  "f", 1U, "m");
    ukos_fake_addLog(0U, 1U, KINFO_USER, 100U, "first",  "f", 1U, "m");
    ukos_fake_addLog(0U, 2U, KINFO_USER, 200U, "second", "f", 1U, "m");

    (void)local_runBare();

// The buffer is unordered; the output is sorted by timestamp, not by slot.

    EXPECT_TRUE(local_before("first",  "second"));
    EXPECT_TRUE(local_before("second", "third"));
}

TEST(dumplog_every_record_is_printed_once) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 300U, "alpha", "f", 1U, "m");
    ukos_fake_addLog(0U, 1U, KINFO_USER, 100U, "beta",  "f", 1U, "m");
    ukos_fake_addLog(0U, 2U, KINFO_USER, 200U, "gamma", "f", 1U, "m");

    (void)local_runBare();

// oMark is what stops a record being selected twice. Without it the scan would
// loop on the oldest record forever, so counting matters as much as ordering.

    EXPECT_EQ_U(g_fakes.dprintfCalls, 7U);      // banner + core + header + 3 records + trailing
}

TEST(dumplog_equal_timestamps_are_both_printed) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 500U, "alpha", "f", 1U, "m");
    ukos_fake_addLog(0U, 1U, KINFO_USER, 500U, "beta",  "f", 1U, "m");

// The comparison is strictly less-than, so two identical timestamps must not
// make one of them unreachable.

    (void)local_runBare();

    EXPECT_OUT_HAS("alpha");
    EXPECT_OUT_HAS("beta");
}

TEST(dumplog_scan_stops_at_the_first_empty_slot) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 100U, "present", "f", 1U, "m");
    ukos_fake_addLog(0U, 5U, KINFO_USER, 200U, "beyond",  "f", 1U, "m");

// A zero timestamp terminates the inner scan, so a record past a gap is never
// considered. The buffer is written from slot 0 upward on a target, so this is
// the intended behaviour rather than a defect.

    (void)local_runBare();

    EXPECT_OUT_HAS("present");
    EXPECT_OUT_LACKS("beyond");
}

TEST(dumplog_nothing_is_printed_when_the_first_slot_is_empty) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 1U, KINFO_USER, 100U, "hidden", "f", 1U, "m");

// The whole render is gated on the FIRST record's timestamp, so a populated
// buffer with an empty slot 0 shows nothing at all.

    EXPECT_EQ_I(local_runBare(), KOK);
    EXPECT_OUT_IS(KBANNER KCORE0 KHEADER);
}

TEST(dumplog_does_not_mark_the_source_buffer) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 100U, "alpha", "f", 1U, "m");

    (void)local_runBare();

// Marking happens in the snapshot. If the module marked the real buffer, a
// second dumplog would print nothing - which is exactly what this checks.

    EXPECT_FALSE(vRecord_logBuffer[0][0].oMark);

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 100U, "alpha", "f", 1U, "m");
    (void)local_runBare();
    EXPECT_OUT_HAS("alpha");
}

TEST(dumplog_prints_records_the_live_buffer_already_marked) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 100U, "alpha", "f", 1U, "m");
    ukos_fake_addLog(0U, 1U, KINFO_USER, 200U, "beta",  "f", 1U, "m");

// oMark is shared state: record_printLog() walks the LIVE buffer on the
// coredump path and used to leave every record it printed marked. dumplog
// copies that buffer, and a record that arrives marked is never selected - so
// dumplog printed nothing at all after a fault, exactly when the log matters.
// It now clears the marks in its own copy, after the copy.

    vRecord_logBuffer[0][0].oMark = true;
    vRecord_logBuffer[0][1].oMark = true;

    EXPECT_EQ_I(local_runBare(), KOK);
    EXPECT_OUT_HAS("alpha");
    EXPECT_OUT_HAS("beta");
}

TEST(dumplog_clears_the_marks_after_the_copy_not_before) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 100U, "alpha", "f", 1U, "m");
    vRecord_logBuffer[0][0].oMark = true;

    (void)local_runBare();

// Clearing before the memcpy would clear bytes the copy then overwrites, which
// is what the original code did. The record appearing proves the order.

    EXPECT_OUT_HAS("alpha");

// And the live buffer is still the kernel's: dumplog must not clear the marks
// there, only in its snapshot.

    EXPECT_TRUE(vRecord_logBuffer[0][0].oMark);
}

TEST(dumplog_copies_under_a_critical_section) {

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 100U, "alpha", "f", 1U, "m");

    (void)local_runBare();

// One pair around the memcpy, and only that - the rendering happens outside.

    EXPECT_EQ_U(g_kern.criticalEnters, 1U);
    EXPECT_EQ_U(g_kern.criticalExits, 1U);
    EXPECT_FALSE(g_kern.criticalUnbalanced);
}

// ============================================================================
// The core selector
// ============================================================================

TEST(dumplog_core_defaults_to_zero) {
    const char_t    *argv[] = { "dumplog", "0" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("Log provided by the core 0\n\n");
}

TEST(dumplog_out_of_range_core_is_clamped_not_rejected) {
    const char_t    *argv[] = { "dumplog", "9" };

    ukos_t_begin("UTC0");
    ukos_fake_addLog(0U, 0U, KINFO_USER, 100U, "alpha", "f", 1U, "m");

// A core beyond KNB_CORES silently becomes core 0 rather than being reported.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("Log provided by the core 0\n\n");
    EXPECT_OUT_HAS("alpha");
}

TEST(dumplog_non_numeric_core_is_zero) {
    const char_t    *argv[] = { "dumplog", "abc" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("Log provided by the core 0\n\n");
}

TEST(dumplog_extra_arguments_fall_through_to_core_zero) {
    const char_t    *argv[] = { "dumplog", "0", "junk" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_OUT_HAS("Log provided by the core 0\n\n");
}
