/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/uKOS/uKOS.c.
 *
 * Needs no new test double: the module only formats build-time constants. The
 * target description comes from the BOARD / VARIANT / SOC / CORE macros the
 * system build normally supplies, and the revision from the stub version.h.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "ip.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_test.h"
#include    "version.h"

extern  const uKOS_module_t     aUKOS_Specifications;

#define KINA                "Incorrect arguments.\n\n"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

// The target block, built from the macros the CMakeLists passes to this target

#define KTARGET             "\nTarget:\n"                    \
                            "Board:   Nucleo_H743\n"         \
                            "Variant: Variant_Test\n"        \
                            "SoC:     STM32H743\n"           \
                            "Core:    CORTEX_M7\n\n"         \
                            "VCS#:    " SW_VERSION "\n\n"

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aUKOS_Specifications.oExecution(argc, argv);
}

// How many times the I.P. notice appears in the captured output

static unsigned local_countNotice(void) {
    unsigned    nb  = 0U;
    const char  *at = &g_fakes.out[0];

    while ((at = strstr(at, STRG_STRIP)) != NULL) {
        nb++;
        at += strlen(STRG_STRIP);
    }
    return nb;
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(ukos_module_metadata) {

    ukos_t_begin("UTC0");

    EXPECT_EQ_U(aUKOS_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_UKOS << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aUKOS_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_TRUE(aUKOS_Specifications.oInit      == NULL);
    EXPECT_TRUE(aUKOS_Specifications.oClean     == NULL);
    EXPECT_EQ_STR(aUKOS_Specifications.oStrRevision, " 1.1");
    EXPECT_EQ_STR(aUKOS_Specifications.oStrApplication,
                  "uKOS         The uKOS-X information.                   (c) EFr-2026");
}

// ============================================================================
// No argument  -  the target description
// ============================================================================

TEST(ukos_target_golden_output) {
    const char_t    *argv[] = { "uKOS" };
    int32_t         status;

    ukos_t_begin("UTC0");
    status = local_run(1U, argv);

    ukos_t_commonInvariants(status, "\nTarget:\n");
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KTARGET STRG_STRIP);
}

TEST(ukos_target_reports_the_build_macros) {
    const char_t    *argv[] = { "uKOS" };

    ukos_t_begin("UTC0");
    (void)local_run(1U, argv);

// STRG() stringifies whatever the build passed, so these four lines are the
// only place a mismatched -D would show up.

    EXPECT_OUT_HAS("Board:   Nucleo_H743\n");
    EXPECT_OUT_HAS("Variant: Variant_Test\n");
    EXPECT_OUT_HAS("SoC:     STM32H743\n");
    EXPECT_OUT_HAS("Core:    CORTEX_M7\n");
}

TEST(ukos_target_reports_the_firmware_revision) {
    const char_t    *argv[] = { "uKOS" };

    ukos_t_begin("UTC0");
    (void)local_run(1U, argv);

// The same string ukos-serial verify matches against --expect-sha.

    EXPECT_OUT_HAS("VCS#:    " SW_VERSION "\n");
}

TEST(ukos_target_prints_the_notice_once) {
    const char_t    *argv[] = { "uKOS" };

    ukos_t_begin("UTC0");
    (void)local_run(1U, argv);

    EXPECT_EQ_U(local_countNotice(), 1U);
}

// ============================================================================
// -history
// ============================================================================

TEST(ukos_history_is_displayed) {
    const char_t    *argv[] = { "uKOS", "-history" };
    int32_t         status;

    ukos_t_begin("UTC0");
    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, "uKOS History\n\n");
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_HAS("uKOS History\n\n");
    EXPECT_OUT_HAS("1984 - 1986, uKOS-0\n");
    EXPECT_OUT_HAS("2025 - 20xx, uKOS-X back to the open-source.\n");
    EXPECT_OUT_HAS("Main contributors to uKOS-X:\n");
    EXPECT_OUT_HAS("VCS#: " SW_VERSION "\n\n");
    EXPECT_OUT_LACKS("Target:\n");
}

TEST(ukos_history_prints_the_notice_once) {
    const char_t    *argv[] = { "uKOS", "-history" };

    ukos_t_begin("UTC0");
    (void)local_run(2U, argv);

// local_displayHistory() used to end by printing the I.P. notice, which
// prgm()'s success arm then printed again. Only the success arm does it now,
// which is what the target path always relied on.

    EXPECT_EQ_U(local_countNotice(), 1U);
}

TEST(ukos_history_ends_with_the_notice) {
    const char_t    *argv[] = { "uKOS", "-history" };

    ukos_t_begin("UTC0");
    (void)local_run(2U, argv);

// The notice is still the last thing printed, and it follows the revision line
// that local_displayHistory() ends on.

    EXPECT_OUT_HAS("VCS#: " SW_VERSION "\n\n" STRG_STRIP);
    EXPECT_TRUE(strlen(&g_fakes.out[0]) >= strlen(STRG_STRIP));
    EXPECT_EQ_STR(&g_fakes.out[strlen(&g_fakes.out[0]) - strlen(STRG_STRIP)], STRG_STRIP);
}

TEST(ukos_history_flag_is_space_terminated) {
    const char_t    *argv[] = { "uKOS", "-history extra" };

    ukos_t_begin("UTC0");

// text_checkAsciiBuffer stops at the first space, so a remainder still selects
// the history.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("uKOS History\n\n");
}

TEST(ukos_history_prefix_is_rejected) {
    const char_t    *argv[] = { "uKOS", "-hist" };
    int32_t         status;

    ukos_t_begin("UTC0");
    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KINA);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KINA);
}

TEST(ukos_history_superstring_is_rejected) {
    const char_t    *argv[] = { "uKOS", "-historyx" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KINA);
}

TEST(ukos_history_is_case_sensitive) {
    const char_t    *argv[] = { "uKOS", "-HISTORY" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(ukos_unknown_option_is_rejected) {
    const char_t    *argv[] = { "uKOS", "-xyz" };

    ukos_t_begin("UTC0");

// argc == 2 is the only arm that can fail: neither the target nor the history
// is printed, only the diagnostic.

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KINA);
    EXPECT_EQ_U(local_countNotice(), 0U);
}

TEST(ukos_empty_option_is_rejected) {
    const char_t    *argv[] = { "uKOS", "" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

// ============================================================================
// every other argc  -  the default arm
// ============================================================================

TEST(ukos_extra_arguments_show_the_target) {
    const char_t    *argv[] = { "uKOS", "-history", "junk" };
    int32_t         status;

    ukos_t_begin("UTC0");

// Only argc == 2 inspects argv, so a surplus argument silently falls back to
// the target description rather than being reported.

    status = local_run(3U, argv);

    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KTARGET STRG_STRIP);
}

TEST(ukos_zero_arguments_show_the_target) {
    const char_t    *argv[] = { "uKOS" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(0U, argv), KOK);
    EXPECT_OUT_IS(KTARGET STRG_STRIP);
}
