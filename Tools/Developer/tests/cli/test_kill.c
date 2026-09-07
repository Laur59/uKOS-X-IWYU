/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/kill/kill.c.
 *
 * Needs no new test double: the module resolves a name through
 * system_getModuleName() and then dispatches through the descriptor's oClean
 * entry point, both of which the synthetic directory already provides.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aKill_Specifications;

#define KBANNER             "kill a module.\n"
#define KNOTEXIST           "The module does not exist.\n\n"
#define KNOTKILL            "The module cannot be killed.\n\n"
#define KPROTO              "Protocol error.\n\n"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

#define KID(family, d0, d1)  ( ((uint32_t)(family) << 24U)   \
                             | ((uint32_t)(d0)     << 16U)   \
                             | ((uint32_t)(d1)     <<  8U)   \
                             | (uint32_t)(uint8_t)'_' )

#define KAPP_ALIVE          "alive        Keep the system alive.                    (c) EFr-2026"
#define KAPP_DATE           "date         Set / display date and time.              (c) EFr-2026"

// Records that the module under test really reached the descriptor

static  unsigned    vCleanCalls;
static  uint32_t    vCleanArgc;
static  const char_t * volatile vCleanArgv;

static int32_t local_clean(uint32_t argc, const char_t *argv[]) {

    vCleanCalls++;
    vCleanArgc = argc;
    vCleanArgv = (argv != NULL) ? argv[0] : NULL;
    return 0;
}

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aKill_Specifications.oExecution(argc, argv);
}

static void local_begin(void) {

    ukos_t_begin("UTC0");
    vCleanCalls = 0U;
    vCleanArgc  = 0xFFFFFFFFU;
    vCleanArgv  = NULL;
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(kill_module_metadata) {

    local_begin();

    EXPECT_EQ_U(aKill_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_KILL << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aKill_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_EQ_STR(aKill_Specifications.oStrRevision, " 1.0");
    EXPECT_EQ_STR(aKill_Specifications.oStrApplication,
                  "kill         Kill a module.                            (c) EFr-2026");
}

// ============================================================================
// A module that can be killed
// ============================================================================

TEST(kill_calls_the_clean_entry_point) {
    const char_t    *argv[] = { "kill", "alive" };
    int32_t         status;

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER "Module alive killed\n\n");
    EXPECT_EQ_U(vCleanCalls, 1U);
    EXPECT_EQ_U(g_fakes.system.nameCalls, 1U);
}

TEST(kill_passes_no_arguments_to_clean) {
    const char_t    *argv[] = { "kill", "alive" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

    (void)local_run(2U, argv);

// oClean is invoked as (0, nullptr) - the module being killed receives none of
// the kill command's own arguments.

    EXPECT_EQ_U(vCleanCalls, 1U);
    EXPECT_EQ_U(vCleanArgc, 0U);
    EXPECT_TRUE(vCleanArgv == NULL);
}

TEST(kill_reports_the_name_it_was_given) {
    const char_t    *argv[] = { "kill", "date" };

    local_begin();
    ukos_fake_addModule(KID('X', '0', '8'), " 1.1", KAPP_DATE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

// The confirmation echoes argv[1], not the module's application string.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_IS(KBANNER "Module date killed\n\n");
}

TEST(kill_selects_the_named_module) {
    const char_t    *argv[] = { "kill", "date" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);                    // on "alive"
    ukos_fake_addModule(KID('X', '0', '8'), " 1.1", KAPP_DATE, (1U << BSHOW));

// "date" has no oClean, so the wrong module being picked would show up as a
// successful kill instead of a refusal.

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KNOTKILL);
    EXPECT_EQ_U(vCleanCalls, 0U);
}

TEST(kill_succeeds_even_when_clean_reports_an_error) {
    const char_t    *argv[] = { "kill", "alive" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

// kill discards oClean's return value, so a module that fails to clean up is
// still reported as killed.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("Module alive killed\n");
}

// ============================================================================
// A module that cannot be killed
// ============================================================================

TEST(kill_without_clean_is_refused) {
    const char_t    *argv[] = { "kill", "date" };
    int32_t         status;

    local_begin();
    ukos_fake_addModule(KID('X', '0', '8'), " 1.1", KAPP_DATE, (1U << BSHOW));

    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KNOTKILL);
    EXPECT_EQ_U(vCleanCalls, 0U);
}

TEST(kill_a_confidential_module_is_still_possible) {
    const char_t    *argv[] = { "kill", "alive" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BCONFIDENTIAL));
    ukos_fake_setLastClean(local_clean);

// system_getModuleName() applies no flag filter, so a module hidden from list
// and from the man index can still be killed by name.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(vCleanCalls, 1U);
}

// ============================================================================
// A module that does not exist
// ============================================================================

TEST(kill_unknown_module_is_reported) {
    const char_t    *argv[] = { "kill", "nosuch" };
    int32_t         status;

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KNOTEXIST);
    EXPECT_EQ_U(vCleanCalls, 0U);
}

TEST(kill_on_an_empty_directory) {
    const char_t    *argv[] = { "kill", "alive" };

    local_begin();

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KNOTEXIST);
}

TEST(kill_name_prefix_does_not_match) {
    const char_t    *argv[] = { "kill", "ali" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KNOTEXIST);
    EXPECT_EQ_U(vCleanCalls, 0U);
}

TEST(kill_name_superstring_does_not_match) {
    const char_t    *argv[] = { "kill", "alivex" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(kill_name_is_case_sensitive) {
    const char_t    *argv[] = { "kill", "ALIVE" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(kill_name_with_a_trailing_remainder_still_matches) {
    const char_t    *argv[] = { "kill", "alive extra" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

// text_checkAsciiBuffer accepts a space as a terminator, so the remainder is
// ignored and the module is killed.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_EQ_U(vCleanCalls, 1U);
    EXPECT_OUT_HAS("Module alive extra killed\n");
}

// ============================================================================
// Wrong arity
// ============================================================================

TEST(kill_without_a_name_is_a_protocol_error) {
    const char_t    *argv[] = { "kill" };
    int32_t         status;

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

    status = local_run(1U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
    EXPECT_EQ_U(g_fakes.system.nameCalls, 0U);
    EXPECT_EQ_U(vCleanCalls, 0U);
}

TEST(kill_with_extra_arguments_is_a_protocol_error) {
    const char_t    *argv[] = { "kill", "alive", "junk" };

    local_begin();
    ukos_fake_addModule(KID('T', '0', '1'), " 1.0", KAPP_ALIVE, (1U << BSHOW));
    ukos_fake_setLastClean(local_clean);

// Unlike list, man, rnd and uKOS, kill checks the argument count and refuses
// anything but exactly one name.

    EXPECT_EQ_I(local_run(3U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
    EXPECT_EQ_U(vCleanCalls, 0U);
}

TEST(kill_with_zero_arguments_is_a_protocol_error) {
    const char_t    *argv[] = { "kill" };

    local_begin();

    EXPECT_EQ_I(local_run(0U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
}
