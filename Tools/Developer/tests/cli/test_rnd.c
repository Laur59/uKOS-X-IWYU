/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/rnd/rnd.c.
 *
 * The generator is replaced by a deterministic ramp, so the printed numbers
 * can be asserted exactly and the interesting behaviour - how the count and
 * the generator are chosen - is what the tests actually exercise.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "modules.h"
#include    "random/random.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aRnd_Specifications;

#define KBANNER             "Give random number(s).\n"
#define KPROTO              "Protocol error.\n\n"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aRnd_Specifications.oExecution(argc, argv);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(rnd_module_metadata) {

    ukos_t_begin("UTC0");

    EXPECT_EQ_U(aRnd_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_RND << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aRnd_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_EQ_STR(aRnd_Specifications.oStrRevision, " 1.0");
    EXPECT_EQ_STR(aRnd_Specifications.oStrApplication,
                  "rnd          Give a random number.                     (c) EFr-2026");
    EXPECT_TRUE(strncmp(aRnd_Specifications.oStrHelp, "Give a random number\n====", 25U) == 0);
}

// ============================================================================
// argc == 1  -  a single number from the software generator
// ============================================================================

TEST(rnd_default_is_one_soft_number) {
    const char_t    *argv[] = { "rnd" };
    int32_t         status;

    ukos_t_begin("UTC0");
    status = local_run(1U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER "1000\n" "\n");
    EXPECT_EQ_U(g_fakes.random.calls, 1U);
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_SOFT);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 1U);
}

TEST(rnd_generator_failure_is_a_protocol_error) {
    const char_t    *argv[] = { "rnd" };
    int32_t         status;

    ukos_t_begin("UTC0");
    g_fakes.random.rc       = -1;
    g_fakes.random.writeOut = false;

    ukos_t_poisonStack();
    status = local_run(1U, argv);

// The buffer is never written, so the failure has to be reported rather than
// printing whatever was on the stack.

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
}

// ============================================================================
// argc == 2  -  a count
// ============================================================================

TEST(rnd_count_is_honoured) {
    const char_t    *argv[] = { "rnd", "4" };
    int32_t         status;

    ukos_t_begin("UTC0");
    g_fakes.random.seed = 7U;
    g_fakes.random.step = 10U;

    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER "7\n" "17\n" "27\n" "37\n" "\n");
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 4U);
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_SOFT);
}

TEST(rnd_count_upper_bound_is_sixteen) {
    const char_t    *argv[] = { "rnd", "16" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 16U);
    EXPECT_OUT_HAS("1015\n");                               // the sixteenth of the ramp
    EXPECT_OUT_LACKS("1016\n");
}

TEST(rnd_mid_range_count_is_honoured) {
    const char_t    *argv[] = { "rnd", "12" };

    ukos_t_begin("UTC0");

// Between the two boundary cases, so narrowing the accepted range is caught
// here as well as at 16.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 12U);
    EXPECT_OUT_HAS("1011\n");
}

TEST(rnd_count_above_the_maximum_falls_back_to_one) {
    const char_t    *argv[] = { "rnd", "17" };

    ukos_t_begin("UTC0");

// Out of range is silently clamped to a single number rather than reported.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 1U);
    EXPECT_OUT_IS(KBANNER "1000\n" "\n");
}

TEST(rnd_count_zero_falls_back_to_one) {
    const char_t    *argv[] = { "rnd", "0" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 1U);
}

TEST(rnd_non_numeric_count_falls_back_to_one) {
    const char_t    *argv[] = { "rnd", "abc" };

    ukos_t_begin("UTC0");

// strtoul yields 0 and the end pointer is never inspected, so a bad count
// becomes a single number instead of an error.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 1U);
}

TEST(rnd_trailing_garbage_in_the_count_is_ignored) {
    const char_t    *argv[] = { "rnd", "4abc" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 4U);
}

TEST(rnd_negative_count_falls_back_to_one) {
    const char_t    *argv[] = { "rnd", "-3" };

    ukos_t_begin("UTC0");

// strtoul wraps "-3" to a huge unsigned value, which is then out of range.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 1U);
}

// ============================================================================
// argc == 3  -  a generator and a count
// ============================================================================

TEST(rnd_hard_selects_the_hardware_generator) {
    const char_t    *argv[] = { "rnd", "-hard", "3" };
    int32_t         status;

    ukos_t_begin("UTC0");
    g_fakes.random.seed = 5U;
    g_fakes.random.step = 0U;

    status = local_run(3U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_HARD);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 3U);
    EXPECT_OUT_IS(KBANNER "5\n" "5\n" "5\n" "\n");
}

TEST(rnd_soft_selects_the_software_generator) {
    const char_t    *argv[] = { "rnd", "-soft", "2" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_SOFT);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 2U);
}

TEST(rnd_unknown_generator_falls_back_to_software) {
    const char_t    *argv[] = { "rnd", "-xyz", "2" };

    ukos_t_begin("UTC0");

// Neither flag matches, so the generator keeps its initial value instead of
// the command being rejected.

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_SOFT);
    EXPECT_EQ_U(g_fakes.random.calls, 1U);
}

TEST(rnd_generator_flag_is_space_terminated) {
    const char_t    *argv[] = { "rnd", "-hard extra", "2" };

    ukos_t_begin("UTC0");

// text_checkAsciiBuffer stops at the first space, so a flag carrying a
// remainder still selects the hardware generator.

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_HARD);
}

TEST(rnd_generator_flag_is_case_sensitive) {
    const char_t    *argv[] = { "rnd", "-HARD", "2" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_SOFT);
}

TEST(rnd_hard_generator_failure_is_reported) {
    const char_t    *argv[] = { "rnd", "-hard", "2" };

    ukos_t_begin("UTC0");
    g_fakes.random.rc       = -1;
    g_fakes.random.writeOut = false;

    ukos_t_poisonStack();

    EXPECT_EQ_I(local_run(3U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_HARD);
}

TEST(rnd_count_is_clamped_with_a_generator_too) {
    const char_t    *argv[] = { "rnd", "-hard", "99" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 1U);
}

// ============================================================================
// every other argc  -  the default arm falls into case 1
// ============================================================================

TEST(rnd_four_arguments_behave_as_no_argument) {
    const char_t    *argv[] = { "rnd", "-hard", "8", "junk" };
    int32_t         status;

    ukos_t_begin("UTC0");

// "default:" precedes "case 1U:" and falls into it, so a surplus argument does
// not report an error - it discards the request and yields one soft number.

    status = local_run(4U, argv);

    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER "1000\n" "\n");
    EXPECT_EQ_I(g_fakes.random.lastGenerator, KRANDOM_SOFT);
    EXPECT_EQ_U(g_fakes.random.lastNbNumbers, 1U);
}

TEST(rnd_zero_arguments_behave_as_no_argument) {
    const char_t    *argv[] = { "rnd" };

    ukos_t_begin("UTC0");

// argc == 0 never dereferences argv.

    EXPECT_EQ_I(local_run(0U, argv), KOK);
    EXPECT_OUT_IS(KBANNER "1000\n" "\n");
}
