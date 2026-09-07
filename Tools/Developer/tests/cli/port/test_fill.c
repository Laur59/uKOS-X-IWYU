/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/fill/fill.c.
 *
 * Tier 2, same shape as the dump suite: the module is handed hex addresses of a
 * host buffer and the buffer is inspected afterwards.
 *
 * SAFETY: fill.c:85 computes (uint32_t)(endAdd - startAdd) with NO reversed
 * range handling - unlike dump.c:96, which reinterprets it as a length. A
 * reversed range therefore underflows and writes roughly four gigabytes. No
 * test here may pass one; see DEFECTS.md.
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aFill_Specifications;

#define KBANNER             "Memory fill.\n"
#define KPROTO              "Protocol error.\n\n"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

#define KFIXTURE            64U
#define KGUARD              0xC3U                            // must survive every test

static  uint8_t     vFixture[KFIXTURE];
static  char_t      vStart[24], vEnd[24];

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aFill_Specifications.oExecution(argc, argv);
}

static void local_fixture(uint32_t offset, uint32_t length) {

    ukos_t_begin("UTC0");
    (void)memset(&vFixture[0], KGUARD, sizeof vFixture);

    (void)snprintf(&vStart[0], sizeof vStart, "%" PRIXPTR, (uintptr_t)&vFixture[offset]);
    (void)snprintf(&vEnd[0],   sizeof vEnd,   "%" PRIXPTR, (uintptr_t)&vFixture[offset + length]);
}

// Every byte outside [from, to) must still hold the guard value.

static bool local_untouchedOutside(uint32_t from, uint32_t to) {

    for (uint32_t i = 0U; i < KFIXTURE; i++) {
        if (((i < from) || (i >= to)) && (vFixture[i] != KGUARD)) {
            return false;
        }
    }
    return true;
}

static bool local_filledWith(uint32_t from, uint32_t to, uint8_t value) {

    for (uint32_t i = from; i < to; i++) {
        if (vFixture[i] != value) {
            return false;
        }
    }
    return true;
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(fill_module_metadata) {

    local_fixture(0U, 16U);

    EXPECT_EQ_U(aFill_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_FILL << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aFill_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
}

// ============================================================================
// argc == 4  -  user access
// ============================================================================

TEST(fill_writes_the_requested_range) {
    const char_t    *argv[] = { "fill", &vStart[0], &vEnd[0], "5A" };
    int32_t         status;

    local_fixture(8U, 16U);
    status = local_run(4U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER "\n");
    EXPECT_TRUE(local_filledWith(8U, 24U, 0x5AU));
    EXPECT_TRUE(local_untouchedOutside(8U, 24U));
}

TEST(fill_value_is_parsed_as_hex) {
    const char_t    *argv[] = { "fill", &vStart[0], &vEnd[0], "10" };

    local_fixture(0U, 4U);

// "10" is sixteen, not ten - the value shares the base-16 parse of the
// addresses.

    EXPECT_EQ_I(local_run(4U, argv), KOK);
    EXPECT_TRUE(local_filledWith(0U, 4U, 0x10U));
}

TEST(fill_value_is_truncated_to_a_byte) {
    const char_t    *argv[] = { "fill", &vStart[0], &vEnd[0], "1234" };

    local_fixture(0U, 4U);

// The value is parsed into an int32_t and stored through (uint8_t).

    EXPECT_EQ_I(local_run(4U, argv), KOK);
    EXPECT_TRUE(local_filledWith(0U, 4U, 0x34U));
}

TEST(fill_empty_range_writes_nothing) {
    const char_t    *argv[] = { "fill", &vStart[0], &vEnd[0], "5A" };

    local_fixture(8U, 0U);

    EXPECT_EQ_I(local_run(4U, argv), KOK);
    EXPECT_TRUE(local_untouchedOutside(0U, 0U));             // the whole buffer is intact
}

TEST(fill_single_byte) {
    const char_t    *argv[] = { "fill", &vStart[0], &vEnd[0], "FF" };

    local_fixture(31U, 1U);

    EXPECT_EQ_I(local_run(4U, argv), KOK);
    EXPECT_TRUE(local_filledWith(31U, 32U, 0xFFU));
    EXPECT_TRUE(local_untouchedOutside(31U, 32U));
}

TEST(fill_non_numeric_value_is_zero) {
    const char_t    *argv[] = { "fill", &vStart[0], &vEnd[0], "zz" };

    local_fixture(0U, 4U);

// strtoul yields 0 and the end pointer is never inspected, so a bad value
// silently becomes 0x00 rather than an error.

    EXPECT_EQ_I(local_run(4U, argv), KOK);
    EXPECT_TRUE(local_filledWith(0U, 4U, 0x00U));
}

TEST(fill_user_access_does_not_elevate) {
    const char_t    *argv[] = { "fill", &vStart[0], &vEnd[0], "5A" };

    local_fixture(0U, 4U);
    (void)local_run(4U, argv);

    EXPECT_EQ_U(g_kern.calls, 0U);
}

// ============================================================================
// argc == 5  -  the -S privileged form
// ============================================================================

TEST(fill_supervisor_form_writes_the_range) {
    const char_t    *argv[] = { "fill", "-S", &vStart[0], &vEnd[0], "77" };
    int32_t         status;

    local_fixture(4U, 8U);
    status = local_run(5U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_TRUE(local_filledWith(4U, 12U, 0x77U));
    EXPECT_TRUE(local_untouchedOutside(4U, 12U));
}

TEST(fill_supervisor_form_elevates_and_restores) {
    const char_t    *argv[] = { "fill", "-S", &vStart[0], &vEnd[0], "77" };

    local_fixture(0U, 4U);
    (void)local_run(5U, argv);

#ifdef PRIVILEGED_USER_S
    EXPECT_EQ_U(g_kern.elevates, 1U);
    EXPECT_EQ_U(g_kern.restores, 1U);
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
#else
    EXPECT_EQ_U(g_kern.calls, 0U);
#endif
}

TEST(fill_unknown_flag_is_rejected_and_writes_nothing) {
    const char_t    *argv[] = { "fill", "-X", &vStart[0], &vEnd[0], "77" };
    int32_t         status;

    local_fixture(0U, 16U);
    status = local_run(5U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
    EXPECT_TRUE(local_untouchedOutside(0U, 0U));
    EXPECT_EQ_U(g_kern.elevates, 0U);
}

// ============================================================================
// Argument count  -  nothing may be written on any of these paths
// ============================================================================

TEST(fill_too_few_arguments) {
    const char_t    *argv[] = { "fill", &vStart[0], &vEnd[0] };

    local_fixture(0U, 16U);

    EXPECT_EQ_I(local_run(3U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
    EXPECT_TRUE(local_untouchedOutside(0U, 0U));
}

TEST(fill_no_arguments) {
    const char_t    *argv[] = { "fill" };

    local_fixture(0U, 16U);

    EXPECT_EQ_I(local_run(1U, argv), KFAIL);
    EXPECT_TRUE(local_untouchedOutside(0U, 0U));
}

TEST(fill_too_many_arguments) {
    const char_t    *argv[] = { "fill", "-S", &vStart[0], &vEnd[0], "77", "junk" };

    local_fixture(0U, 16U);

    EXPECT_EQ_I(local_run(6U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
    EXPECT_TRUE(local_untouchedOutside(0U, 0U));
}
