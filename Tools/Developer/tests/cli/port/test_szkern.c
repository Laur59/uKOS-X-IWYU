/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/szkern/szkern.c.
 *
 * Tier 2. The module takes no arguments and prints a fixed table, so what is
 * worth proving is the arithmetic, the #if arms and the labels - not the
 * numbers, most of which are host figures.
 *
 * Deliberately NOT asserted:
 *   - every sizeof(). proc_t and friends carry 64-bit pointers here, so the
 *     object sizes are host sizes and asserting them would pin the host.
 *   - the bss figure in isolation. It folds in the daemon stacks, whose size is
 *     nbDeamons * KKERN_SZ_STACK_SS * sizeof(uintptr_t) - eight bytes here,
 *     four on the target. The test computes it rather than hardcoding it.
 *   - the [KBytes] float column beyond one representative case.
 *
 * The section addresses ARE assertable, because the stub places them: that is
 * the whole point of declaring the linker symbols as pointers.
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "kern/kern.h"
#include    "linker.h"
#include    "macros_core_stackFrame.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aSzkern_Specifications;

#define KBANNER             "uKernel memory footprint information.\n"
#define KOK                 EXIT_OS_SUCCESS_CLI

// A recognisable, entirely synthetic kernel image.

#define KTEXT_AT            ((uintptr_t)0x08000000U)
#define KTEXT_LN            0x1000U                          // 4 KiB exactly
#define KRODATA_AT          ((uintptr_t)0x08001000U)
#define KRODATA_LN          0x800U
#define KDATA_AT            ((uintptr_t)0x20000000U)
#define KDATA_LN            0x400U
#define KBSS_AT             ((uintptr_t)0x20000400U)
#define KBSS_LN             0x200U

#if (KKERN_WITH_STATISTICS_S == true)
#define KNB_DAEMONS         3U
#else
#define KNB_DAEMONS         2U
#endif

static int32_t local_run(void) {
    const char_t    *argv[] = { "szkern" };

    return aSzkern_Specifications.oExecution(1U, argv);
}

static void local_begin(void) {

    ukos_t_begin("UTC0");
    ukos_fake_setKernelImage(KTEXT_AT,   KTEXT_LN,
                             KRODATA_AT, KRODATA_LN,
                             KDATA_AT,   KDATA_LN,
                             KBSS_AT,    KBSS_LN);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(szkern_module_metadata) {

    local_begin();

    EXPECT_EQ_U(aSzkern_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_SZ_KERN << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aSzkern_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_EQ_STR(aSzkern_Specifications.oStrRevision, " 1.0");
}

// ============================================================================
// The report
// ============================================================================

TEST(szkern_prints_the_banner_and_succeeds) {
    int32_t     status;

    local_begin();
    status = local_run();

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
}

TEST(szkern_takes_no_arguments) {
    const char_t    *argv[] = { "szkern", "junk", "more" };

    local_begin();

// argc and argv are both [[maybe_unused]]: any invocation prints the same
// report rather than reporting a bad argument.

    EXPECT_EQ_I(aSzkern_Specifications.oExecution(3U, argv), KOK);
    EXPECT_OUT_HAS(KBANNER);
}

TEST(szkern_reports_the_statistics_arm) {

    local_begin();
    (void)local_run();

#if (KKERN_WITH_STATISTICS_S == true)
    EXPECT_OUT_HAS("uKernel objects - statistics on\n\n");
    EXPECT_OUT_LACKS("statistics off");
#else
    EXPECT_OUT_HAS("uKernel objects - statistics off\n\n");
    EXPECT_OUT_LACKS("statistics on");
#endif
}

TEST(szkern_daemon_count_follows_the_statistics_arm) {
    char    expected[64];

    local_begin();
    (void)local_run();

// Two daemons, plus one more when statistics are compiled in.

    (void)snprintf(&expected[0], sizeof expected, "Number of daemons          %3d\n", KNB_DAEMONS);
    EXPECT_OUT_HAS(&expected[0]);
}

TEST(szkern_process_count_excludes_the_daemons) {
    char    expected[64];

    local_begin();
    (void)local_run();

    (void)snprintf(&expected[0], sizeof expected, "Number of processes        %3d,",
                   (int)(KKERN_NB_PROCESSES - KNB_DAEMONS));
    EXPECT_OUT_HAS(&expected[0]);
}

TEST(szkern_lists_every_object_kind) {

    local_begin();
    (void)local_run();

    EXPECT_OUT_HAS("Number of mailboxes ");
    EXPECT_OUT_HAS("Number of semaphores ");
    EXPECT_OUT_HAS("Number of mutex ");
    EXPECT_OUT_HAS("Number of signals (x32) ");

// The optional kinds are behind #if guards on their counts.

#if (KKERN_NB_SOFTWARE_TIMERS > 0)
    EXPECT_OUT_HAS("Number of software timers ");
#else
    EXPECT_OUT_LACKS("software timers");
#endif
#if (KKERN_NB_POOLS > 0)
    EXPECT_OUT_HAS("Number of pools ");
#else
    EXPECT_OUT_LACKS("Number of pools");
#endif
#if (KKERN_NB_PRECISE_SIGNALS > 0)
    EXPECT_OUT_HAS("Number of precise signals ");
#else
    EXPECT_OUT_LACKS("precise signals");
#endif
}

// ============================================================================
// The section arithmetic  -  what the pointer-valued linker stub buys
// ============================================================================

TEST(szkern_section_addresses_are_the_placed_ones) {

    local_begin();
    (void)local_run();

    EXPECT_OUT_HAS("Section text:      addr = 0x0000000008000000,");
    EXPECT_OUT_HAS("Section rodata:    addr = 0x0000000008001000,");
    EXPECT_OUT_HAS("Section data:      addr = 0x0000000020000000,");
    EXPECT_OUT_HAS("Section bss:       addr = 0x0000000020000400,");
}

TEST(szkern_section_size_is_end_minus_start) {

    local_begin();
    (void)local_run();

    EXPECT_OUT_HAS("Section text:      addr = 0x0000000008000000, size = 0x00001000  4.00 [KBytes]\n");
    EXPECT_OUT_HAS("Section rodata:    addr = 0x0000000008001000, size = 0x00000800  2.00 [KBytes]\n");
    EXPECT_OUT_HAS("Section data:      addr = 0x0000000020000000, size = 0x00000400  1.00 [KBytes]\n");
}

TEST(szkern_bss_includes_the_daemon_stacks) {
    char        expected[96];
    uint32_t    stacks, total;

    local_begin();
    (void)local_run();

// The stack contribution is pointer-width dependent, so compute it the way the
// module does rather than pinning a host figure.

    stacks = (uint32_t)(KNB_DAEMONS * (KKERN_SZ_STACK_SS * sizeof(uintptr_t)));
    total  = KBSS_LN + stacks;

    (void)snprintf(&expected[0], sizeof expected,
                   "Section bss:       addr = 0x0000000020000400, size = 0x%08" PRIX32, total);
    EXPECT_OUT_HAS(&expected[0]);
    EXPECT_TRUE(total > KBSS_LN);
}

TEST(szkern_zero_length_section) {

    ukos_t_begin("UTC0");
    ukos_fake_setKernelImage(KTEXT_AT, 0U, KRODATA_AT, KRODATA_LN,
                             KDATA_AT, KDATA_LN, KBSS_AT, KBSS_LN);
    (void)local_run();

    EXPECT_OUT_HAS("Section text:      addr = 0x0000000008000000, size = 0x00000000  0.00 [KBytes]\n");
}

TEST(szkern_end_below_start_reports_a_negative_size) {

    ukos_t_begin("UTC0");

// Only a stub can produce this: on a target the linker guarantees en >= st.
// The subtraction is signed and the result is printed through PRIX32, so a
// negative size surfaces as a very large hex value and a negative float. The
// point is that nothing clamps or hides it.

    ukos_fake_setKernelImage(KTEXT_AT, 0U, KRODATA_AT, KRODATA_LN,
                             KDATA_AT, KDATA_LN, KBSS_AT, KBSS_LN);
    linker_enTEXT_KERN_p = (uint8_t *)(KTEXT_AT - 0x10U);

    (void)local_run();

    EXPECT_OUT_HAS("Section text:      addr = 0x0000000008000000, size = 0xFFFFFFF0 -0.02 [KBytes]\n");
}

TEST(szkern_report_order) {
    const char  *banner, *objects, *footprint, *text;

    local_begin();
    (void)local_run();

// The header, the object table and the section table appear in that order.

    banner    = strstr(&g_fakes.out[0], "uKernel memory footprint information.");
    objects   = strstr(&g_fakes.out[0], "Number of daemons");
    footprint = strstr(&g_fakes.out[0], "uKernel memory footprint including the daemons stacks");
    text      = strstr(&g_fakes.out[0], "Section text:");

    EXPECT_TRUE(banner != NULL);
    EXPECT_TRUE((objects   != NULL) && (objects   > banner));
    EXPECT_TRUE((footprint != NULL) && (footprint > objects));
    EXPECT_TRUE((text      != NULL) && (text      > footprint));
}
