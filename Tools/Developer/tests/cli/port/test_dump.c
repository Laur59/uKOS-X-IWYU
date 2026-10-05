/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/dump/dump.c.
 *
 * Tier 2: runs against the stub port layer, which supplies PRIVILEGE_ELEVATE /
 * PRIVILEGE_RESTORE only. Addresses are handed to the module as hex text, so a
 * host buffer is dumped exactly the way board memory would be.
 *
 * One thing is deliberately NOT asserted, a host artefact rather than module
 * behaviour: the ASCII column for bytes above 0x7F, whose char signedness
 * differs. The address column is asserted: it used to be formatted with
 * 0x%016X, which truncated a pointer on this 64-bit host.
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

extern  const uKOS_module_t     aDump_Specifications;

#define KBANNER             "Memory dump.\n"
#define KPROTO              "Protocol error.\n\n"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

// dump reads whole 16-byte lines, so a range that is not a multiple of 16 is
// read up to the end of its last line; the pad keeps that inside vFixture. It
// used to walk (nbBytes + 16) / 16 lines - one too many - and the test that
// dumps the last line of the fixture is what catches that under ASan.

#define KFIXTURE_USED       64U
#define KFIXTURE_PAD        64U

static  uint8_t     vFixture[KFIXTURE_USED + KFIXTURE_PAD];
static  char_t      vStart[24], vEnd[24];

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aDump_Specifications.oExecution(argc, argv);
}

// Fill the fixture with a recognisable ramp and render the two addresses the
// module will parse back out of its argv.

static void local_fixture(uint32_t offset, uint32_t length) {

    ukos_t_begin("UTC0");

    for (size_t i = 0U; i < sizeof vFixture; i++) {
        vFixture[i] = (uint8_t)(0x40U + (i & 0x0FU));        // '@'..'O', all printable
    }

    (void)snprintf(&vStart[0], sizeof vStart, "%" PRIXPTR, (uintptr_t)&vFixture[offset]);
    (void)snprintf(&vEnd[0],   sizeof vEnd,   "%" PRIXPTR, (uintptr_t)&vFixture[offset + length]);
}

// Count rendered lines by their fixed shape rather than by the address text.

static unsigned local_countLines(void) {
    unsigned    nb = 0U;
    const char  *at = &g_fakes.out[0];

    while ((at = strstr(at, ": ")) != NULL) {
        nb++;
        at += 2U;
    }
    return nb;
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(dump_module_metadata) {

    local_fixture(0U, 16U);

    EXPECT_EQ_U(aDump_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_DUMP << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aDump_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_TRUE(aDump_Specifications.oExecution != NULL);
}

// ============================================================================
// argc == 3  -  user access
// ============================================================================

TEST(dump_renders_the_requested_bytes) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };
    int32_t         status;

    local_fixture(0U, 16U);
    status = local_run(3U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);

// The ramp is '@'..'O', so both the hex and the ASCII column are predictable.

    EXPECT_OUT_HAS("40,41,42,43,44,45,46,47,48,49,4A,4B,4C,4D,4E,4F  @ABCDEFGHIJKLMNO\n");
}

TEST(dump_address_column_is_the_whole_pointer) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };
    char            expect[40];

    local_fixture(0U, 16U);
    (void)snprintf(&expect[0], sizeof expect, "0x%016" PRIXPTR ": ", (uintptr_t)&vFixture[0]);

// PRIXPTR prints the full uintptr_t; %X printed an unsigned int, which dropped
// the upper half of every 64-bit host address.

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_OUT_HAS(&expect[0]);
}

TEST(dump_sixteen_bytes_are_one_line) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };

    local_fixture(0U, 16U);
    (void)local_run(3U, argv);

// The end address is excluded: 16 bytes are exactly one line. The old
// (nbBytes + 16) / 16 printed two, reading 16 bytes beyond the range.

    EXPECT_EQ_U(local_countLines(), 1U);
}

TEST(dump_zero_length_prints_no_line) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };

    local_fixture(0U, 0U);

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_U(local_countLines(), 0U);
}

TEST(dump_a_partial_line_is_rounded_up) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };

    local_fixture(0U, 17U);

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_U(local_countLines(), 2U);                     // 16 + 1 bytes
}

TEST(dump_multiple_lines) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };

    local_fixture(0U, 32U);

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_U(local_countLines(), 2U);                     // 32 bytes
}

TEST(dump_the_last_line_reads_nothing_past_the_range) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };

// The last 16 bytes of vFixture: one line, and not a byte past the array. The
// old extra line read the 16 bytes after vFixture - a global-buffer-overflow
// under "run-tests -s", and one line too many here.

    local_fixture((uint32_t)(sizeof vFixture - 16U), 16U);

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_U(local_countLines(), 1U);
}

TEST(dump_reversed_range_is_read_as_a_length) {
    const char_t    *argv[] = { "dump", &vStart[0], "10" };

    local_fixture(0U, 0U);

// dump.c:96 adds startAdd when end < start, so a small second argument is a
// LENGTH, not an address. This is deliberate, not the fill.c defect - see the
// "Not defects" section of DEFECTS.md.

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_U(local_countLines(), 1U);                     // 0x10 bytes -> one line
}

TEST(dump_non_printable_bytes_become_dots) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };

    local_fixture(0U, 16U);
    (void)memset(&vFixture[0], 0x01, 16U);                   // below ' '

    (void)local_run(3U, argv);

    EXPECT_OUT_HAS("01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01  ................\n");
}

TEST(dump_user_access_does_not_elevate) {
    const char_t    *argv[] = { "dump", &vStart[0], &vEnd[0] };

    local_fixture(0U, 16U);
    (void)local_run(3U, argv);

// The three-argument form is the unprivileged one.

    EXPECT_EQ_U(g_kern.elevates, 0U);
    EXPECT_EQ_U(g_kern.calls, 0U);
}

// ============================================================================
// argc == 4  -  the -S privileged form
// ============================================================================

TEST(dump_supervisor_form_renders_the_same_bytes) {
    const char_t    *argv[] = { "dump", "-S", &vStart[0], &vEnd[0] };
    int32_t         status;

    local_fixture(0U, 16U);
    status = local_run(4U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_HAS("40,41,42,43,44,45,46,47,48,49,4A,4B,4C,4D,4E,4F  @ABCDEFGHIJKLMNO\n");
}

TEST(dump_supervisor_form_elevates_and_restores) {
    const char_t    *argv[] = { "dump", "-S", &vStart[0], &vEnd[0] };

    local_fixture(0U, 16U);
    (void)local_run(4U, argv);

// Pairing and order, which is all the stub can prove - it says nothing about
// whether elevation has any effect. See port/README.md.

#ifdef PRIVILEGED_USER_S
    EXPECT_EQ_U(g_kern.elevates, 1U);
    EXPECT_EQ_U(g_kern.restores, 1U);
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
#else
    EXPECT_EQ_U(g_kern.calls, 0U);                           // macros compile away
#endif
}

TEST(dump_supervisor_flag_is_space_terminated) {
    const char_t    *argv[] = { "dump", "-S junk", &vStart[0], &vEnd[0] };

    local_fixture(0U, 16U);

    EXPECT_EQ_I(local_run(4U, argv), KOK);
}

TEST(dump_unknown_flag_is_rejected) {
    const char_t    *argv[] = { "dump", "-X", &vStart[0], &vEnd[0] };
    int32_t         status;

    local_fixture(0U, 16U);
    status = local_run(4U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
    EXPECT_EQ_U(g_kern.elevates, 0U);
}

// ============================================================================
// Argument count
// ============================================================================

TEST(dump_too_few_arguments) {
    const char_t    *argv[] = { "dump", &vStart[0] };

    local_fixture(0U, 16U);

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
}

TEST(dump_no_arguments) {
    const char_t    *argv[] = { "dump" };

    local_fixture(0U, 16U);

    EXPECT_EQ_I(local_run(1U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
}

TEST(dump_too_many_arguments) {
    const char_t    *argv[] = { "dump", "-S", &vStart[0], &vEnd[0], "junk" };

    local_fixture(0U, 16U);

// Unlike list, man and rnd, dump bounds argc on both sides.

    EXPECT_EQ_I(local_run(5U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER KPROTO);
}
