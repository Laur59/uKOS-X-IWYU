/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/dumptrace/dumptrace.c.
 *
 * Tier 2, sharing dumplog's allocator seam. Where dumplog sorts, dumptrace
 * replays a ring in write order: it snapshots the fifo, rebases the read
 * pointer into the copy by pointer DIFFERENCE, and walks it nbTraceWrites times.
 * The rebase and the walk are the substance.
 *
 * ONE PATH IS DELIBERATELY NOT EXERCISED. The wrap test at dumptrace.c:135
 * compares the read pointer against &traceFifo[KRECORD_SZ_TRACE_FIFO], which is
 * one PAST the end, so a walk that runs off the end reads that element before
 * wrapping. Every test here keeps the walk inside the buffer, because provoking
 * the wrap means provoking a heap overflow that ASan would - correctly - abort
 * on, and "run-tests -s" has to stay green. The defect is recorded in
 * DEFECTS.md instead; the corrected comparison is against [SZ - 1].
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "kern/processes.h"
#include    "modules.h"
#include    "record/private/private_record.h"
#include    "record/record.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aDumptrace_Specifications;

#define KBANNER     "Trace dump.\n"
#define KCORE0      "Trace provided by the core 0\n\n"
#define KHEADER     "      Time [us]   Parameter            Process or ISR identifier          Information\n\n"

#define KOK         EXIT_OS_SUCCESS_CLI
#define KFAIL       EXIT_OS_FAILURE

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aDumptrace_Specifications.oExecution(argc, argv);
}

static int32_t local_runBare(void) {
    const char_t    *argv[] = { "dumptrace" };

    return local_run(1U, argv);
}

static bool local_before(const char *first, const char *second) {
    const char  *a = strstr(&g_fakes.out[0], first);
    const char  *b = strstr(&g_fakes.out[0], second);

    return (a != NULL) && (b != NULL) && (a < b);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(dumptrace_module_metadata) {

    ukos_t_begin("UTC0");

    EXPECT_EQ_U(aDumptrace_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_DUMP_TRACE << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aDumptrace_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
}

// ============================================================================
// The allocation
// ============================================================================

TEST(dumptrace_allocates_a_snapshot_and_frees_it) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1000U, 0xDEADU, NULL, "enter");
    ukos_fake_setTraceRead(0U, 0U, 1U);

    EXPECT_EQ_I(local_runBare(), KOK);

    EXPECT_EQ_U(g_kern.mallocCalls, 1U);
    EXPECT_EQ_U(g_kern.lastMallocSize, (uint32_t)(KRECORD_SZ_TRACE_FIFO * sizeof(recordTracing_t)));
    EXPECT_EQ_STR(g_kern.lastMallocId, "dumptrace");
    EXPECT_EQ_U(g_kern.freeCalls, 1U);
}

TEST(dumptrace_reports_an_allocation_failure) {
    int32_t     status;

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1000U, 0U, NULL, "enter");
    ukos_fake_setTraceRead(0U, 0U, 1U);
    g_kern.failNextMalloc = true;

    status = local_runBare();

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Not enough memory.\n");
    EXPECT_EQ_U(g_kern.freeCalls, 0U);
    EXPECT_OUT_LACKS("enter");
}

TEST(dumptrace_restores_privilege_after_an_allocation_failure) {

    ukos_t_begin("UTC0");
    g_kern.failNextMalloc = true;

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
// An empty ring
// ============================================================================

TEST(dumptrace_empty_ring_prints_only_the_headers) {
    int32_t     status;

    ukos_t_begin("UTC0");
    status = local_runBare();

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);

// nbTraceWrites is zero, so the walk body never runs - but unlike dumplog the
// trailing blank line is emitted unconditionally.

    EXPECT_OUT_IS(KBANNER KCORE0 KHEADER "\n");
}

// ============================================================================
// Rendering
// ============================================================================

TEST(dumptrace_single_record_golden_output) {
    proc_t      *console;

    ukos_t_begin("UTC0");
    console = ukos_fake_addProcess("console");
    ukos_fake_addTrace(0U, 0U, 1000U, 0xDEADU, console, "enter");
    ukos_fake_setTraceRead(0U, 0U, 1U);

    EXPECT_EQ_I(local_runBare(), KOK);

// The identifier is padded to 33 characters; the parameter is a full-width
// pointer-sized hex field.

    EXPECT_OUT_IS(KBANNER KCORE0 KHEADER
                  "        1000-us   0x000000000000DEAD   console                            enter\n"
                  "\n");
}

TEST(dumptrace_isr_records_have_no_process) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 2000U, 0U, NULL, "irq");
    ukos_fake_setTraceRead(0U, 0U, 1U);

// A null process means the trace was written from an interrupt, so the module
// must substitute a name rather than dereference.

    EXPECT_EQ_I(local_runBare(), KOK);
    EXPECT_OUT_HAS("        2000-us   0x0000000000000000   From ISR                           irq\n");
}

TEST(dumptrace_parameter_is_rendered_full_width) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1U, (uintptr_t)0x1234ABCDU, NULL, "m");
    ukos_fake_setTraceRead(0U, 0U, 1U);

    (void)local_runBare();

    EXPECT_OUT_HAS("0x000000001234ABCD");
}

// ============================================================================
// The walk  -  write order, not timestamp order
// ============================================================================

TEST(dumptrace_records_are_replayed_in_ring_order) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 300U, 0U, NULL, "first");
    ukos_fake_addTrace(0U, 1U, 100U, 0U, NULL, "second");
    ukos_fake_addTrace(0U, 2U, 200U, 0U, NULL, "third");
    ukos_fake_setTraceRead(0U, 0U, 3U);

// Unlike dumplog, nothing is sorted: the ring is replayed from the read pointer
// forward, so the timestamps here are deliberately out of order and must stay
// that way in the output.

    (void)local_runBare();

    EXPECT_TRUE(local_before("first",  "second"));
    EXPECT_TRUE(local_before("second", "third"));
}

TEST(dumptrace_walk_length_is_the_write_count) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1U, 0U, NULL, "shown_a");
    ukos_fake_addTrace(0U, 1U, 2U, 0U, NULL, "shown_b");
    ukos_fake_addTrace(0U, 2U, 3U, 0U, NULL, "hidden");
    ukos_fake_setTraceRead(0U, 0U, 2U);

// Only nbTraceWrites records are replayed, whatever else the fifo holds.

    (void)local_runBare();

    EXPECT_OUT_HAS("shown_a");
    EXPECT_OUT_HAS("shown_b");
    EXPECT_OUT_LACKS("hidden");
}

TEST(dumptrace_read_pointer_is_rebased_into_the_snapshot) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1U, 0U, NULL, "before_read_pointer");
    ukos_fake_addTrace(0U, 5U, 2U, 0U, NULL, "at_read_pointer");
    ukos_fake_addTrace(0U, 6U, 3U, 0U, NULL, "after_read_pointer");
    ukos_fake_setTraceRead(0U, 5U, 2U);

// The module rebases vRecord_RTraceFifo into its own copy by pointer
// DIFFERENCE. Getting that wrong would start the walk at the beginning of the
// snapshot rather than at slot 5, so the first record printed is the test.

    (void)local_runBare();

    EXPECT_OUT_HAS("at_read_pointer");
    EXPECT_OUT_HAS("after_read_pointer");
    EXPECT_OUT_LACKS("before_read_pointer");
    EXPECT_TRUE(local_before("at_read_pointer", "after_read_pointer"));
}

TEST(dumptrace_walk_stays_inside_the_buffer) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, (uint16_t)(KRECORD_SZ_TRACE_FIFO - 1U), 1U, 0U, NULL, "last_slot");
    ukos_fake_setTraceRead(0U, (uint16_t)(KRECORD_SZ_TRACE_FIFO - 1U), 1U);

// Reading the final slot is fine; it is the ADVANCE past it that is unsound
// (DEFECTS.md, dumptrace.c:135). One record starting at the last slot reads it
// and stops, so this exercises the boundary without crossing it.

    EXPECT_EQ_I(local_runBare(), KOK);
    EXPECT_OUT_HAS("last_slot");
}

TEST(dumptrace_full_buffer_from_slot_zero) {
    uint16_t    i;

    ukos_t_begin("UTC0");

    for (i = 0U; i < KRECORD_SZ_TRACE_FIFO; i++) {
        ukos_fake_addTrace(0U, i, (uint64_t)(i + 1U), (uintptr_t)i, NULL, "rec");
    }
    ukos_fake_setTraceRead(0U, 0U, KRECORD_SZ_TRACE_FIFO);

// A whole fifo replayed from slot 0 reads every element exactly once and
// finishes with the pointer one past the end WITHOUT dereferencing it - the
// largest walk that is safe under the current comparison.

    EXPECT_EQ_I(local_runBare(), KOK);
    EXPECT_EQ_U(g_fakes.dprintfCalls, (unsigned)(KRECORD_SZ_TRACE_FIFO + 4U));
}

TEST(dumptrace_copies_under_a_critical_section) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1U, 0U, NULL, "m");
    ukos_fake_setTraceRead(0U, 0U, 1U);

    (void)local_runBare();

// One pair around the copy and the pointer rebase; rendering happens outside.

    EXPECT_EQ_U(g_kern.criticalEnters, 1U);
    EXPECT_EQ_U(g_kern.criticalExits, 1U);
    EXPECT_FALSE(g_kern.criticalUnbalanced);
}

TEST(dumptrace_does_not_disturb_the_live_fifo) {

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1U, 0U, NULL, "alpha");
    ukos_fake_setTraceRead(0U, 0U, 1U);

    (void)local_runBare();

// The read pointer and the write count belong to the kernel; the module works
// on its snapshot, so a second dump must show the same thing.

    EXPECT_TRUE(vRecord_RTraceFifo[0] == &vRecord_traceFifo[0][0]);
    EXPECT_EQ_U(vRecord_NbTraceWrites[0], 1U);

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1U, 0U, NULL, "alpha");
    ukos_fake_setTraceRead(0U, 0U, 1U);
    (void)local_runBare();
    EXPECT_OUT_HAS("alpha");
}

// ============================================================================
// The core selector
// ============================================================================

TEST(dumptrace_out_of_range_core_is_clamped_not_rejected) {
    const char_t    *argv[] = { "dumptrace", "9" };

    ukos_t_begin("UTC0");
    ukos_fake_addTrace(0U, 0U, 1U, 0U, NULL, "alpha");
    ukos_fake_setTraceRead(0U, 0U, 1U);

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS(KCORE0);
    EXPECT_OUT_HAS("alpha");
}

TEST(dumptrace_non_numeric_core_is_zero) {
    const char_t    *argv[] = { "dumptrace", "abc" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS(KCORE0);
}

TEST(dumptrace_extra_arguments_fall_through_to_core_zero) {
    const char_t    *argv[] = { "dumptrace", "0", "junk" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_OUT_HAS(KCORE0);
}
