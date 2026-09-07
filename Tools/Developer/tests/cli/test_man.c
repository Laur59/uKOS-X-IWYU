/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/man/man.c.
 *
 * Reuses the synthetic module directory introduced for list, plus
 * system_getModuleName(), which matches a module by the first word of its
 * application string.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "ip.h"
#include    "modules.h"
#include    "system/system.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aMan_Specifications;

#define KBANNER             "Module help.\n"
#define KPROTO              "Protocol error.\n\n"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

#define KID(family, d0, d1)  ( ((uint32_t)(family) << 24U)   \
                             | ((uint32_t)(d0)     << 16U)   \
                             | ((uint32_t)(d1)     <<  8U)   \
                             | (uint32_t)(uint8_t)'_' )

// The production application strings pad the name out with spaces, which is
// exactly what makes the first word the module's name.

#define KAPP_DATE           "date         Set / display date and time.              (c) EFr-2026"
#define KAPP_DUMP           "dump         Dump a memory region.                     (c) EFr-2026"
#define KAPP_LED            "led          Manage the LEDs.                          (c) EFr-2026"

#define KAPP_KILL           "kill         Kill a process.                           (c) EFr-2026"
#define KHELP_DATE          "Set/display the date\n====================\n\n"
#define KHELP_DUMP          "Dump\n====\n\n"

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aMan_Specifications.oExecution(argc, argv);
}

static void local_twoCliModules(void) {

    ukos_fake_addModuleWithHelp(KID('X', '0', '8'), " 1.1", KAPP_DATE, KHELP_DATE,
                                (1U << BSHOW) | (1U << BEXE_CONSOLE));
    ukos_fake_addModuleWithHelp(KID('X', '0', '9'), " 1.0", KAPP_DUMP, KHELP_DUMP,
                                (1U << BSHOW) | (1U << BEXE_CONSOLE));
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(man_module_metadata) {

    ukos_t_begin("UTC0");

    EXPECT_EQ_U(aMan_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_MAN << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aMan_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_TRUE(aMan_Specifications.oInit      == NULL);
    EXPECT_TRUE(aMan_Specifications.oClean     == NULL);
    EXPECT_TRUE(aMan_Specifications.oExecution != NULL);
}

// ============================================================================
// argc == 2  -  the help of one named module
// ============================================================================

TEST(man_named_module_prints_help_and_copyright) {
    const char_t    *argv[] = { "man", "date" };
    int32_t         status;

    ukos_t_begin("UTC0");
    local_twoCliModules();

    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER KHELP_DATE STRG_COPYRIGHT_FRANZI "\n");
    EXPECT_EQ_U(g_fakes.system.nameCalls, 1U);
}

TEST(man_selects_the_right_module) {
    const char_t    *argv[] = { "man", "dump" };

    ukos_t_begin("UTC0");
    local_twoCliModules();

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS(KHELP_DUMP);
    EXPECT_OUT_LACKS("Set/display the date");
}

TEST(man_unknown_module_is_a_protocol_error) {
    const char_t    *argv[] = { "man", "nosuch" };
    int32_t         status;

    ukos_t_begin("UTC0");
    local_twoCliModules();

    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
}

TEST(man_empty_directory_is_a_protocol_error) {
    const char_t    *argv[] = { "man", "date" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
}

// --- how a name is matched ---------------------------------------------------

TEST(man_name_is_the_first_word_of_the_application_string) {
    const char_t    *argv[] = { "man", "led" };

    ukos_t_begin("UTC0");
    ukos_fake_addModuleWithHelp(KID('P', '0', '1'), " 1.0", KAPP_LED, "Led\n===\n\n", (1U << BSHOW));

// The comparison stops at the first space of the application string, so "led"
// matches "led          Manage the LEDs. ..." without the caller ever knowing
// about the padding.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("Led\n===\n\n");
}

TEST(man_name_prefix_does_not_match) {
    const char_t    *argv[] = { "man", "dat" };

    ukos_t_begin("UTC0");
    local_twoCliModules();

// "dat" runs out before the application string reaches its space, so the
// comparison fails on 'e' against '\0'.

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
}

TEST(man_name_superstring_does_not_match) {
    const char_t    *argv[] = { "man", "datex" };

    ukos_t_begin("UTC0");
    local_twoCliModules();

// The application string reaches its space after "date", and the requested
// name then has an 'x' where a terminator was required.

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(man_name_is_case_sensitive) {
    const char_t    *argv[] = { "man", "DATE" };

    ukos_t_begin("UTC0");
    local_twoCliModules();

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(man_empty_name_does_not_match) {
    const char_t    *argv[] = { "man", "" };

    ukos_t_begin("UTC0");
    local_twoCliModules();

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(man_trailing_space_still_matches) {
    const char_t    *argv[] = { "man", "date extra" };

    ukos_t_begin("UTC0");
    local_twoCliModules();

// text_checkAsciiBuffer accepts a space as a terminator on either side, so a
// name carrying a remainder still resolves.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS(KHELP_DATE);
}

TEST(man_first_matching_module_wins) {
    const char_t    *argv[] = { "man", "date" };

    ukos_t_begin("UTC0");
    ukos_fake_addModuleWithHelp(KID('X', '0', '8'), " 1.1", KAPP_DATE, "FIRST\n", (1U << BSHOW));
    ukos_fake_addModuleWithHelp(KID('U', '0', '1'), " 9.9", KAPP_DATE, "SECOND\n", (1U << BSHOW));

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("FIRST\n");
    EXPECT_OUT_LACKS("SECOND\n");
}

TEST(man_finds_a_module_of_any_family) {
    const char_t    *argv[] = { "man", "led" };

    ukos_t_begin("UTC0");
    ukos_fake_addModuleWithHelp(KID('P', '0', '1'), " 1.0", KAPP_LED, "Led\n", (1U << BSHOW));

// The lookup is not restricted to the CLI family, unlike the index below.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("Led\n");
}

TEST(man_reveals_a_module_the_index_hides) {
    const char_t    *argv[] = { "man", "date" };
    const char_t    *argvIndex[] = { "man" };

    ukos_t_begin("UTC0");
    ukos_fake_addModuleWithHelp(KID('X', '0', '8'), " 1.1", KAPP_DATE, KHELP_DATE,
                                (1U << BCONFIDENTIAL));

// system_getModuleName() applies no flag filter, so a module kept out of the
// index by its flags still yields its help when named explicitly.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS(KHELP_DATE);

    ukos_t_begin("UTC0");
    ukos_fake_addModuleWithHelp(KID('X', '0', '8'), " 1.1", KAPP_DATE, KHELP_DATE,
                                (1U << BCONFIDENTIAL));

    EXPECT_EQ_I(local_run(1U, argvIndex), KOK);
    EXPECT_OUT_LACKS(KAPP_DATE);
}

// ============================================================================
// argc != 2  -  the logo and the CLI index
// ============================================================================

TEST(man_index_golden_output) {
    const char_t    *argv[] = { "man" };
    int32_t         status;

    ukos_t_begin("UTC0");
    local_twoCliModules();

    status = local_run(1U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER STRG_LOGO "CLI\n\n" KAPP_DATE "\n" KAPP_DUMP "\n" "\n");
}

TEST(man_index_mixed_directory_golden) {
    const char_t    *argv[] = { "man" };

    ukos_t_begin("UTC0");

// One directory exercising every rule the index applies at once: shown CLI,
// a non-CLI module, a CLI module without BSHOW, and a CLI module that is both
// shown and confidential.

    ukos_fake_addModuleWithHelp(KID('X', '0', '8'), " 1.1", KAPP_DATE, KHELP_DATE, (1U << BSHOW));
    ukos_fake_addModuleWithHelp(KID('P', '0', '1'), " 1.0", KAPP_LED,  "Led\n",    (1U << BSHOW));
    ukos_fake_addModuleWithHelp(KID('X', '0', '9'), " 1.0", KAPP_DUMP, KHELP_DUMP, 0U);
    ukos_fake_addModuleWithHelp(KID('X', '1', '0'), " 1.0", KAPP_KILL, "Kill\n",
                                (1U << BSHOW) | (1U << BCONFIDENTIAL));

    (void)local_run(1U, argv);

    EXPECT_OUT_IS(KBANNER STRG_LOGO "CLI\n\n" KAPP_DATE "\n" KAPP_KILL "\n" "\n");
}

TEST(man_index_lists_only_the_cli_family) {
    const char_t    *argv[] = { "man" };

    ukos_t_begin("UTC0");
    local_twoCliModules();
    ukos_fake_addModuleWithHelp(KID('P', '0', '1'), " 1.0", KAPP_LED, "Led\n", (1U << BSHOW));

    (void)local_run(1U, argv);

    EXPECT_OUT_HAS(KAPP_DATE);
    EXPECT_OUT_LACKS(KAPP_LED);
}

TEST(man_index_filters_on_bshow_not_on_confidential) {
    const char_t    *argv[] = { "man" };

    ukos_t_begin("UTC0");

// list hides a module carrying BCONFIDENTIAL; man instead requires BSHOW. A
// module with both set is therefore listed here and hidden there.

    ukos_fake_addModuleWithHelp(KID('X', '0', '8'), " 1.1", KAPP_DATE, KHELP_DATE,
                                (1U << BSHOW) | (1U << BCONFIDENTIAL));
    ukos_fake_addModuleWithHelp(KID('X', '0', '9'), " 1.0", KAPP_DUMP, KHELP_DUMP, 0U);

    (void)local_run(1U, argv);

    EXPECT_OUT_HAS(KAPP_DATE);
    EXPECT_OUT_LACKS(KAPP_DUMP);
}

TEST(man_index_on_empty_directory) {
    const char_t    *argv[] = { "man" };
    int32_t         status;

    ukos_t_begin("UTC0");

    status = local_run(1U, argv);

    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER STRG_LOGO "CLI\n\n" "\n");
}

TEST(man_index_preserves_directory_order) {
    const char_t    *argv[] = { "man" };

    ukos_t_begin("UTC0");
    ukos_fake_addModuleWithHelp(KID('X', '0', '9'), " 1.0", KAPP_DUMP, KHELP_DUMP, (1U << BSHOW));
    ukos_fake_addModuleWithHelp(KID('X', '0', '8'), " 1.1", KAPP_DATE, KHELP_DATE, (1U << BSHOW));

    (void)local_run(1U, argv);

    EXPECT_OUT_IS(KBANNER STRG_LOGO "CLI\n\n" KAPP_DUMP "\n" KAPP_DATE "\n" "\n");
}

TEST(man_extra_arguments_fall_through_to_the_index) {
    const char_t    *argv[] = { "man", "date", "junk" };
    int32_t         status;

    ukos_t_begin("UTC0");
    local_twoCliModules();

// Only argc == 2 names a module; any other count prints the index instead of
// reporting a bad argument.

    status = local_run(3U, argv);

    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_HAS("CLI\n\n");
    EXPECT_EQ_U(g_fakes.system.nameCalls, 0U);
}
