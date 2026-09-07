/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/run/run.c.
 *
 * The module is pure pointer handling: it fetches the address of a downloaded
 * application, clears the slot, and jumps. Both halves of that slot are
 * replaced by test doubles, and the "application" is an ordinary function.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "modules.h"
#include    "system/system.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aRun_Specifications;

#define KBANNER             "Execute the downloaded application.\n"
#define KNOAPP              "No application in the memory!\n\n"
#define KRUNNING            "Run the downloaded application...\n\n"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

#define KAPP_STATUS         4242                            // what the stand-in application returns

// The stand-in downloaded application

static  unsigned    vAppCalls;
static  uint32_t    vAppArgc;
static  const char_t *vAppArgv0;
static  const char_t *vAppArgv1;
static  void        *vAppSawAddress;

static int32_t local_application(uint32_t argc, const char_t *argv[]) {

    vAppCalls++;
    vAppArgc  = argc;
    vAppArgv0 = ((argv != NULL) && (argc > 0U)) ? argv[0] : NULL;
    vAppArgv1 = ((argv != NULL) && (argc > 1U)) ? argv[1] : NULL;

// What the slot holds while the application is running - run() clears it
// before jumping, so this observes that ordering from the inside.

    vAppSawAddress = g_fakes.download.address;
    return KAPP_STATUS;
}

static int32_t local_failingApplication([[maybe_unused]] uint32_t argc,
                                        [[maybe_unused]] const char_t *argv[]) {

    vAppCalls++;
    return EXIT_OS_FAILURE;
}

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aRun_Specifications.oExecution(argc, argv);
}

static void local_begin(void) {

    ukos_t_begin("UTC0");
    vAppCalls      = 0U;
    vAppArgc       = 0xFFFFFFFFU;
    vAppArgv0      = NULL;
    vAppArgv1      = NULL;
    vAppSawAddress = (void *)(uintptr_t)0xDEADBEEFU;
}

static void local_loadApplication(void) {

    g_fakes.download.address = (void *)local_application;
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(run_module_metadata) {

    local_begin();

    EXPECT_EQ_U(aRun_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_RUN << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aRun_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_EQ_STR(aRun_Specifications.oStrApplication,
                  "run          Run a downloaded code.                    (c) EFr-2026");
}

// ============================================================================
// Nothing downloaded
// ============================================================================

TEST(run_without_an_application_is_reported) {
    const char_t    *argv[] = { "run" };
    int32_t         status;

    local_begin();
    status = local_run(1U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KNOAPP);
    EXPECT_EQ_U(g_fakes.download.getCalls, 1U);
    EXPECT_EQ_U(g_fakes.download.setCalls, 0U);
    EXPECT_EQ_U(vAppCalls, 0U);
}

// ============================================================================
// An application is present
// ============================================================================

TEST(run_jumps_to_the_downloaded_application) {
    const char_t    *argv[] = { "run" };
    int32_t         status;

    local_begin();
    local_loadApplication();

    status = local_run(1U, argv);

    EXPECT_EQ_U(vAppCalls, 1U);
    EXPECT_OUT_IS(KBANNER KRUNNING);

// run returns whatever the application returned, not a status of its own, so
// it is the one CLI module that can hand back a value outside the EXIT_OS_*
// set. ukos_t_commonInvariants() is deliberately not used here for that
// reason - it asserts the standard contract every other module keeps.

    EXPECT_EQ_I(status, KAPP_STATUS);
}

TEST(run_clears_the_slot_before_jumping) {
    const char_t    *argv[] = { "run" };

    local_begin();
    local_loadApplication();

    (void)local_run(1U, argv);

// The slot is emptied first, so the application observes a cleared one and a
// second run finds nothing.

    EXPECT_EQ_U(g_fakes.download.setCalls, 1U);
    EXPECT_TRUE(g_fakes.download.lastSet == NULL);
    EXPECT_TRUE(vAppSawAddress == NULL);
}

TEST(run_is_not_repeatable) {
    const char_t    *argv[] = { "run" };

    local_begin();
    local_loadApplication();

    EXPECT_EQ_I(local_run(1U, argv), KAPP_STATUS);
    EXPECT_EQ_U(vAppCalls, 1U);

// The address was consumed, so running again reports an empty memory rather
// than jumping a second time.

    EXPECT_EQ_I(local_run(1U, argv), KFAIL);
    EXPECT_EQ_U(vAppCalls, 1U);
    EXPECT_OUT_HAS(KNOAPP);
}

// ============================================================================
// What the application receives
// ============================================================================

TEST(run_forwards_its_own_arguments) {
    const char_t    *argv[] = { "run", "-v", "42" };

    local_begin();
    local_loadApplication();

    (void)local_run(3U, argv);

// argc and argv are handed straight through, so the application sees "run" as
// its own argv[0] - the command name is not stripped.

    EXPECT_EQ_U(vAppCalls, 1U);
    EXPECT_EQ_U(vAppArgc, 3U);
    EXPECT_EQ_STR(vAppArgv0, "run");
    EXPECT_EQ_STR(vAppArgv1, "-v");
}

TEST(run_forwards_a_bare_invocation) {
    const char_t    *argv[] = { "run" };

    local_begin();
    local_loadApplication();

    (void)local_run(1U, argv);

    EXPECT_EQ_U(vAppArgc, 1U);
    EXPECT_EQ_STR(vAppArgv0, "run");
}

TEST(run_returns_a_failure_from_the_application) {
    const char_t    *argv[] = { "run" };
    int32_t         status;

    local_begin();
    g_fakes.download.address = (void *)local_failingApplication;

    status = local_run(1U, argv);

// A standard failure code passes through unchanged too, so the pass-through is
// not an artefact of the unusual value used above.

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_U(vAppCalls, 1U);
    EXPECT_EQ_I(status, EXIT_OS_FAILURE);
}

TEST(run_announces_before_it_jumps) {
    const char_t    *argv[] = { "run" };

    local_begin();
    local_loadApplication();

    (void)local_run(1U, argv);

// Both lines are emitted by run itself, before control leaves it - the
// stand-in application prints nothing.

    EXPECT_EQ_U(g_fakes.dprintfCalls, 2U);
    EXPECT_OUT_IS(KBANNER KRUNNING);
}
