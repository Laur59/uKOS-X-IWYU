/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/list/list.c.
 *
 * The module walks the directory only through system_getModuleFamily(), so a
 * synthetic table is enough to describe exactly what it should see.
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

extern  const uKOS_module_t     aList_Specifications;

#define KBANNER             "uKOS-X module list.\n"
#define KNOFAM              "This family does not exist.\n\n"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

// The identifier is rendered from the four bytes of oIdModule, most significant
// first, so 'P' 0 1 '_' prints as "P01_".

#define KID(family, d0, d1)  ( ((uint32_t)(family) << 24U)   \
                             | ((uint32_t)(d0)     << 16U)   \
                             | ((uint32_t)(d1)     <<  8U)   \
                             | (uint32_t)(uint8_t)'_' )

#define KAPP_LED            "led          Manage the LEDs.                          (c) EFr-2026"
#define KAPP_ADC            "adc          Manage the ADCs.                          (c) EFr-2026"
#define KAPP_KERN           "kern         Kernel manager.                           (c) EFr-2026"

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aList_Specifications.oExecution(argc, argv);
}

// Three modules in three different families, at known directory positions

static void local_threeModules(void) {

    ukos_fake_addModule(KID('P', '0', '1'), " 1.0", KAPP_LED,  (1U << BSHOW) | (1U << BEXE_CONSOLE));
    ukos_fake_addModule(KID('K', '0', '2'), " 2.3", KAPP_KERN, (1U << BSHOW));
    ukos_fake_addModule(KID('P', '0', '4'), " 1.7", KAPP_ADC,  (1U << BSHOW) | (1U << BEXE_CONSOLE));
}

// ============================================================================
// The test double's own contract
// ============================================================================

TEST(list_fake_directory_contract) {
    uint32_t                idModule = 0U;
    uint16_t                index    = 0U;
    const uKOS_module_t     *module  = NULL;

    ukos_t_begin("UTC0");
    local_threeModules();

// The scan resumes from *index and leaves it on the match, which is what makes
// list.c's "index++ then call again" loop enumerate a family.

    EXPECT_EQ_I(system_getModuleFamily('P', &idModule, &index, &module), 0);
    EXPECT_EQ_U(index, 0U);
    EXPECT_EQ_U(idModule, KID('P', '0', '1'));

    index++;
    EXPECT_EQ_I(system_getModuleFamily('P', &idModule, &index, &module), 0);
    EXPECT_EQ_U(index, 2U);                                 // skipped the 'K' at 1

    index++;
    EXPECT_TRUE(system_getModuleFamily('P', &idModule, &index, &module) != 0);
    EXPECT_TRUE(module == NULL);

// 'A' matches every family

    index = 0U;
    EXPECT_EQ_I(system_getModuleFamily((uint8_t)KID_FAM_ALL_FAMILIES, &idModule, &index, &module), 0);
    EXPECT_EQ_U(index, 0U);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(list_module_metadata) {

    ukos_t_begin("UTC0");

    EXPECT_EQ_U(aList_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_LIST << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aList_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_TRUE(aList_Specifications.oInit      == NULL);
    EXPECT_TRUE(aList_Specifications.oClean     == NULL);
    EXPECT_TRUE(aList_Specifications.oExecution != NULL);
    EXPECT_EQ_STR(aList_Specifications.oStrRevision, " 1.0");
    EXPECT_EQ_STR(aList_Specifications.oStrApplication,
                  "list         List the system modules.                  (c) EFr-2026");
    EXPECT_TRUE(strncmp(aList_Specifications.oStrHelp, "List the system modules\n====", 27U) == 0);
}

// ============================================================================
// argc == 2  -  one family
// ============================================================================

TEST(list_family_golden_output) {
    const char_t    *argv[] = { "list", "P" };
    int32_t         status;

    ukos_t_begin("UTC0");
    local_threeModules();

    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);

// "%s %3d  %s  v%s   %s\n" - "FLASH", the directory index, the 4-byte
// identifier, the revision and the application string.

    EXPECT_OUT_IS(KBANNER
                  "FLASH   0  P01_  v 1.0   " KAPP_LED "\n"
                  "FLASH   2  P04_  v 1.7   " KAPP_ADC "\n"
                  "\n");
}

TEST(list_family_index_is_the_directory_position) {
    const char_t    *argv[] = { "list", "K" };

    ukos_t_begin("UTC0");
    local_threeModules();

// The 'K' module sits at directory slot 1, and that is the number printed -
// not its position within the family.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_IS(KBANNER "FLASH   1  K02_  v 2.3   " KAPP_KERN "\n\n");
}

TEST(list_family_index_field_is_three_wide) {
    const char_t    *argv[] = { "list", "P" };

    ukos_t_begin("UTC0");

// Pad the directory so a 'P' module lands at index 10 and the %3d field is
// exercised beyond a single digit.

    for (unsigned i = 0U; i < 10U; i++) {
        ukos_fake_addModule(KID('L', '0', '0'), " 1.0", "filler", (1U << BSHOW));
    }
    ukos_fake_addModule(KID('P', '9', '9'), " 1.0", KAPP_LED, (1U << BSHOW));

    (void)local_run(2U, argv);

    EXPECT_OUT_IS(KBANNER "FLASH  10  P99_  v 1.0   " KAPP_LED "\n\n");
}

TEST(list_family_confidential_is_hidden) {
    const char_t    *argv[] = { "list", "P" };

    ukos_t_begin("UTC0");
    ukos_fake_addModule(KID('P', '0', '1'), " 1.0", KAPP_LED, (1U << BSHOW) | (1U << BCONFIDENTIAL));
    ukos_fake_addModule(KID('P', '0', '4'), " 1.7", KAPP_ADC, (1U << BSHOW));

// The confidential module is skipped but still consumes its directory slot, so
// the visible one keeps index 1.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_IS(KBANNER "FLASH   1  P04_  v 1.7   " KAPP_ADC "\n\n");
    EXPECT_OUT_LACKS(KAPP_LED);
}

TEST(list_family_only_confidential_reports_missing) {
    const char_t    *argv[] = { "list", "P" };
    int32_t         status;

    ukos_t_begin("UTC0");
    ukos_fake_addModule(KID('P', '0', '1'), " 1.0", KAPP_LED, (1U << BCONFIDENTIAL));

// The family exists in the directory, but nothing in it may be shown, so the
// tool reports it as absent rather than printing an empty list.

    status = local_run(2U, argv);

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KNOFAM);
}

TEST(list_family_unknown_reports_missing) {
    const char_t    *argv[] = { "list", "Z" };
    int32_t         status;

    ukos_t_begin("UTC0");
    local_threeModules();

    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KNOFAM);
}

TEST(list_family_empty_directory_reports_missing) {
    const char_t    *argv[] = { "list", "P" };

    ukos_t_begin("UTC0");

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KNOFAM);
}

TEST(list_family_uses_the_first_character_only) {
    const char_t    *argv[] = { "list", "Pxyz" };

    ukos_t_begin("UTC0");
    local_threeModules();

// Only argv[1][0] is read, so any remainder is ignored rather than rejected.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_HAS("P01_");
    EXPECT_OUT_HAS("P04_");
}

TEST(list_family_empty_string_reports_missing) {
    const char_t    *argv[] = { "list", "" };

    ukos_t_begin("UTC0");
    local_threeModules();

// argv[1][0] is '\0', which matches no family.

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KNOFAM);
}

TEST(list_family_lowercase_reports_missing) {
    const char_t    *argv[] = { "list", "p" };

    ukos_t_begin("UTC0");
    local_threeModules();

// The family byte is compared as-is, so the selector is case sensitive.

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(list_family_wildcard_lists_everything) {
    const char_t    *argv[] = { "list", "A" };

    ukos_t_begin("UTC0");
    local_threeModules();

// KID_FAM_ALL_FAMILIES matches every entry, so the output follows directory
// order rather than the family sweep order.

    EXPECT_EQ_I(local_run(2U, argv), KOK);
    EXPECT_OUT_IS(KBANNER
                  "FLASH   0  P01_  v 1.0   " KAPP_LED "\n"
                  "FLASH   1  K02_  v 2.3   " KAPP_KERN "\n"
                  "FLASH   2  P04_  v 1.7   " KAPP_ADC "\n"
                  "\n");
}

// ============================================================================
// argc != 2  -  the family sweep
// ============================================================================

TEST(list_all_groups_by_family_not_by_directory_order) {
    const char_t    *argv[] = { "list" };
    int32_t         status;

    ukos_t_begin("UTC0");
    local_threeModules();

    status = local_run(1U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);

// The sweep visits the families in a fixed order - kernels before generics
// before peripherals - so 'K' is printed before the two 'P' entries even
// though it sits between them in the directory. Each family that produced
// output is followed by a blank line.

    EXPECT_OUT_IS(KBANNER
                  "FLASH   1  K02_  v 2.3   " KAPP_KERN "\n"
                  "\n"
                  "FLASH   0  P01_  v 1.0   " KAPP_LED "\n"
                  "FLASH   2  P04_  v 1.7   " KAPP_ADC "\n"
                  "\n");
}

TEST(list_all_on_empty_directory_succeeds_quietly) {
    const char_t    *argv[] = { "list" };
    int32_t         status;

    ukos_t_begin("UTC0");

    status = local_run(1U, argv);

// No family is found, yet the sweep never sets the error flag, so an empty
// system prints the banner alone and still succeeds.

    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER);
}

TEST(list_all_skips_the_applications_family) {
    const char_t    *argv[] = { "list" };
    const char_t    *argvU[] = { "list", "U" };

    ukos_t_begin("UTC0");
    ukos_fake_addModule(KID('U', '0', '1'), " 1.0", "downloadable application", (1U << BSHOW));

// The sweep covers fourteen families and 'U' is not among them, so a module of
// the Applications family is invisible to a bare "list" - even though the help
// text documents 'U' and promises that all families are displayed. Reachable
// only by naming it.

    EXPECT_EQ_I(local_run(1U, argv), KOK);
    EXPECT_OUT_IS(KBANNER);
    EXPECT_TRUE(strstr(aList_Specifications.oStrHelp, "'U' for Application family") != NULL);

    ukos_t_begin("UTC0");
    ukos_fake_addModule(KID('U', '0', '1'), " 1.0", "downloadable application", (1U << BSHOW));

    EXPECT_EQ_I(local_run(2U, argvU), KOK);
    EXPECT_OUT_HAS("U01_");
}

TEST(list_all_hides_confidential) {
    const char_t    *argv[] = { "list" };

    ukos_t_begin("UTC0");
    ukos_fake_addModule(KID('P', '0', '1'), " 1.0", KAPP_LED, (1U << BCONFIDENTIAL));
    ukos_fake_addModule(KID('K', '0', '2'), " 2.3", KAPP_KERN, (1U << BSHOW));

    EXPECT_EQ_I(local_run(1U, argv), KOK);
    EXPECT_OUT_IS(KBANNER "FLASH   1  K02_  v 2.3   " KAPP_KERN "\n\n");
}

TEST(list_extra_arguments_sweep_every_family) {
    const char_t    *argv[] = { "list", "P", "junk" };
    int32_t         status;

    ukos_t_begin("UTC0");
    local_threeModules();

// Only argc == 2 selects a family: any other count falls through to the sweep,
// so a surplus argument is neither honoured nor reported.

    status = local_run(3U, argv);

    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_HAS("K02_");
    EXPECT_OUT_HAS("P01_");
}
