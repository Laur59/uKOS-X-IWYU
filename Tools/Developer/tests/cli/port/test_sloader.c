/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/sloader/sloader.c.
 *
 * Tier 2, sharing hexloader's serial seam unchanged. The transport around the
 * two modules is nearly identical, so this suite concentrates on what is NOT
 * shared - and that is more than it looks:
 *
 *   - the checksum is a ONE's complement of the sum, where Intel-HEX uses the
 *     two's complement;
 *   - the address width is carried by the record letter, 2 bytes for S1/S9,
 *     3 for S2/S8, 4 for S3/S7;
 *   - an address outside the download window is either rebased onto it or
 *     rejected outright, which hexloader has no equivalent of;
 *   - S7, S8 and S9 all terminate.
 *
 * As in the hexloader suite the -run path is not exercised, because it jumps
 * into freshly decoded data.
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "linker.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aSloader_Specifications;

#define KBANNER     "S format Motorola loader mode; waiting for the code.\n"
#define KDONE       "\nS: download terminated.\n\n"

#define KOK         EXIT_OS_SUCCESS_CLI
#define KFAIL       EXIT_OS_FAILURE

#define KUMEMO      256U
static  uint8_t     vUMemo[KUMEMO];

// Records built from the S-record definition, not copied from the module.

#define KS1_AT0     "S1070000DEADBEEFC0"        // 4 bytes, 16-bit address 0x0000
#define KS1_AT10    "S10500100102E7"            // 2 bytes, 16-bit address 0x0010
#define KS2_AT0     "S206000000AABB94"          // 2 bytes, 24-bit address
#define KS3_AT0     "S30700000000CCDD4F"        // 2 bytes, 32-bit address
#define KS9         "S9030000FC"                // 16-bit terminator
#define KS7         "S70500000000FA"            // 32-bit terminator
#define KS8         "S804000000FB"              // 24-bit terminator

static int32_t local_run(const char *stream) {
    const char_t    *argv[] = { "sloader", "-norun" };

    ukos_fake_feedSerialText(stream);
    return aSloader_Specifications.oExecution(2U, argv);
}

static void local_begin(void) {

    ukos_t_begin("UTC0");
    (void)memset(&vUMemo[0], 0xCD, sizeof vUMemo);
    ukos_fake_setUserMemory(&vUMemo[0], sizeof vUMemo);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(sloader_module_metadata) {

    local_begin();

    EXPECT_EQ_U(aSloader_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_S_LOADER << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_TRUE(aSloader_Specifications.oExecution != NULL);
}

// ============================================================================
// The decoder
// ============================================================================

TEST(sloader_decodes_an_s1_record) {
    int32_t     status;

    local_begin();
    status = local_run(KS1_AT0 KS9);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_HAS(KDONE);

    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[1], 0xADU);
    EXPECT_EQ_U(vUMemo[2], 0xBEU);
    EXPECT_EQ_U(vUMemo[3], 0xEFU);
    EXPECT_EQ_U(vUMemo[4], 0xCDU);
}

TEST(sloader_honours_the_record_address) {

    local_begin();

    EXPECT_EQ_I(local_run(KS1_AT10 KS9), KOK);

    EXPECT_EQ_U(vUMemo[0x10], 0x01U);
    EXPECT_EQ_U(vUMemo[0x11], 0x02U);
    EXPECT_EQ_U(vUMemo[0x0F], 0xCDU);
}

TEST(sloader_accepts_several_records) {

    local_begin();

    EXPECT_EQ_I(local_run(KS1_AT0 KS1_AT10 KS9), KOK);

    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[0x10], 0x01U);
}

TEST(sloader_ignores_noise_before_a_record) {

    local_begin();

    EXPECT_EQ_I(local_run("garbage\r\n" KS1_AT0 KS9), KOK);
    EXPECT_EQ_U(vUMemo[0], 0xDEU);
}

// ============================================================================
// Address widths  -  carried by the record letter
// ============================================================================

TEST(sloader_s2_uses_a_24_bit_address) {

    local_begin();

    EXPECT_EQ_I(local_run(KS2_AT0 KS9), KOK);

// Three address bytes rather than two; getting the width wrong would shift the
// data and wreck the checksum.

    EXPECT_EQ_U(vUMemo[0], 0xAAU);
    EXPECT_EQ_U(vUMemo[1], 0xBBU);
}

TEST(sloader_s3_uses_a_32_bit_address) {

    local_begin();

    EXPECT_EQ_I(local_run(KS3_AT0 KS9), KOK);

    EXPECT_EQ_U(vUMemo[0], 0xCCU);
    EXPECT_EQ_U(vUMemo[1], 0xDDU);
}

TEST(sloader_widths_can_be_mixed_in_one_stream) {

    local_begin();

    EXPECT_EQ_I(local_run(KS1_AT10 KS2_AT0 KS9), KOK);

    EXPECT_EQ_U(vUMemo[0x10], 0x01U);
    EXPECT_EQ_U(vUMemo[0], 0xAAU);
}

// ============================================================================
// Terminators
// ============================================================================

TEST(sloader_s9_terminates) {

    local_begin();

    EXPECT_EQ_I(local_run(KS1_AT0 KS9 KS1_AT10), KOK);

// Anything after the terminator must not be decoded.

    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[0x10], 0xCDU);
}

TEST(sloader_s7_terminates_too) {

    local_begin();

// S7 is the 32-bit terminator; S7, S8 and S9 share one arm.

    EXPECT_EQ_I(local_run(KS1_AT0 KS7 KS1_AT10), KOK);

    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[0x10], 0xCDU);
}

TEST(sloader_s8_terminates_too) {

    local_begin();

// S8 is the 24-bit terminator. It shares an arm with S2 for the address width
// and another with S7/S9 for termination, so it is the record most easily left
// uncovered - a mutation breaking only the S8 label passed until this existed.

    EXPECT_EQ_I(local_run(KS1_AT0 KS8 KS1_AT10), KOK);

    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[0x10], 0xCDU);
}

TEST(sloader_unknown_record_letter_is_skipped) {

    local_begin();

// S0 is a header record with no arm here, so it is ignored rather than treated
// as an error - the decode continues.

    EXPECT_EQ_I(local_run("S0030000FC" KS1_AT0 KS9), KOK);
    EXPECT_EQ_U(vUMemo[0], 0xDEU);
}

// ============================================================================
// The checksum  -  one's complement, unlike Intel-HEX
// ============================================================================

TEST(sloader_rejects_a_bad_checksum) {
    int32_t     status;

    local_begin();

    status = local_run("S1070000DEADBEEFC1" KS9);

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("\nS: wrong checksum.\n\n");
    EXPECT_OUT_LACKS("download terminated");
}

TEST(sloader_checksum_is_the_ones_complement) {

    local_begin();

// The two loaders differ here: Intel-HEX checks (uint8_t)(0 - sum), Motorola
// checks ~sum. The record below is correct under one's complement and would
// fail under two's, so a copy of hexloader's test would not pass.

    EXPECT_EQ_I(local_run(KS1_AT0 KS9), KOK);
    EXPECT_OUT_HAS(KDONE);
}

TEST(sloader_rejects_a_bad_terminator_checksum) {

    local_begin();

    EXPECT_EQ_I(local_run(KS1_AT0 "S9030000FD"), KFAIL);
    EXPECT_OUT_HAS("\nS: wrong checksum.\n\n");
}

// ============================================================================
// The download window  -  no hexloader equivalent
// ============================================================================

TEST(sloader_low_addresses_are_rebased_onto_the_window) {

    local_begin();

// An address below the window is treated as an OFFSET into it, which is what
// lets a file linked at 0 land in the download area.

    EXPECT_EQ_I(local_run(KS1_AT10 KS9), KOK);
    EXPECT_EQ_U(vUMemo[0x10], 0x01U);
}

TEST(sloader_rejects_an_address_beyond_the_window) {
    int32_t     status;

    local_begin();

// 0x8000 rebased onto a 256-byte window lands past its end, so the record is
// refused rather than written out of bounds. ASan would see the write if it
// were not.

    status = local_run("S1048000017A" KS9);

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("\nS: Download address out of memory.\n\n");
}

TEST(sloader_absolute_address_path_is_unreachable_here) {

    local_begin();

// local_getAddress keeps an address that already falls inside [stUMemo,
// stUMemo + lnUMemo] and rebases anything else onto stUMemo. On this host the
// buffer lives well above 2^32, so NO S-record - not even a 32-bit S3 - can
// name an address inside the window, and every record therefore takes the
// rebasing branch. The absolute branch is genuinely unreachable on the host
// rather than merely untested, and it is asserted here so the claim is checked
// rather than assumed.

    EXPECT_TRUE((uintptr_t)&vUMemo[0] > 0xFFFFFFFFU);
}

// ============================================================================
// Malformed input
// ============================================================================

TEST(sloader_reports_an_empty_stream) {
    int32_t     status;

    local_begin();

// This used to HANG rather than fail, for the same reason as hexloader: the
// mark-waiting loop discarded local_getByte()'s status and 0 never matched 'S'.

    status = local_run("");

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("\nS: framing error.\n\n");
    EXPECT_OUT_LACKS("download terminated");
}

TEST(sloader_reports_a_stream_with_no_mark) {

    local_begin();

    EXPECT_EQ_I(local_run("no record mark anywhere in here"), KFAIL);
    EXPECT_OUT_HAS("\nS: framing error.\n\n");
}

TEST(sloader_reports_a_truncated_type_byte) {

    local_begin();

// The type byte after 'S' is a second discarded-status site: the stream ends
// right after the mark, so the read of the type fails and must terminate the
// scan rather than falling through the default arm back to waiting.

    EXPECT_EQ_I(local_run("S"), KFAIL);
    EXPECT_OUT_HAS("\nS: framing error.\n\n");
}

TEST(sloader_reports_a_truncated_stream) {
    int32_t     status;

    local_begin();

    status = local_run("S1070000DEAD");

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("\nS: framing error.\n\n");
}

TEST(sloader_non_hex_digit_reads_as_zero) {

    local_begin();

// Same weakness as hexloader (DEFECTS.md): a character that is not a hex digit
// contributes 0 with no error, so only the checksum stands between a corrupt
// stream and a silent bad load.

    EXPECT_EQ_I(local_run("S1070000DEADBEEGC0" KS9), KFAIL);
    EXPECT_OUT_HAS("\nS: wrong checksum.\n\n");
}

// ============================================================================
// The transport
// ============================================================================

TEST(sloader_refuses_a_busy_user_memory) {
    const char_t    *argv[] = { "sloader", "-norun" };
    int32_t         status;

    local_begin();
    g_kern.systemReserveRc = -1;

    status = aSloader_Specifications.oExecution(2U, argv);

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("The user memory is busy");
    EXPECT_EQ_U(g_kern.serialReserveCalls, 0U);
}

TEST(sloader_reserves_and_releases_the_console) {

    local_begin();

    EXPECT_EQ_I(local_run(KS1_AT0 KS9), KOK);

    EXPECT_EQ_U(g_kern.serialReserveCalls, 1U);
    EXPECT_EQ_U(g_kern.serialReleaseCalls, 1U);
    EXPECT_EQ_U(g_kern.serialFlushCalls, 1U);
    EXPECT_EQ_U(g_kern.ledOffCalls, 1U);
    EXPECT_EQ_U(g_kern.lastSuspend, 500U);
}

TEST(sloader_publishes_the_download_address) {

    local_begin();

    EXPECT_EQ_I(local_run(KS1_AT0 KS9), KOK);

    EXPECT_EQ_U(g_fakes.download.setCalls, 1U);
    EXPECT_TRUE(g_fakes.download.lastSet != NULL);
}

TEST(sloader_reports_success_after_a_failed_signature_check) {
    const char_t    *argv[] = { "sloader" };
    int32_t         status;

    local_begin();
    g_kern.systemSignature = "no-such-signature-in-the-buffer";
    ukos_fake_feedSerialText(KS1_AT0 KS9);

// DEFECT (DEFECTS.md): the signature check fails, the module says so - and then
// falls through to "return EXIT_OS_SUCCESS_CLI". hexloader sets
// EXIT_OS_FAILURE on the same path. Pinned as CURRENT behaviour; the two
// loaders disagree and one of them is wrong.

    status = aSloader_Specifications.oExecution(1U, argv);

    EXPECT_OUT_HAS("\nS: failed to find the application signature!\n");
    EXPECT_EQ_I(status, KOK);
}

TEST(sloader_burst_reads_decode_identically) {

    local_begin();
    g_kern.serialChunk = 32U;

    EXPECT_EQ_I(local_run(KS1_AT0 KS9), KOK);
    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[3], 0xEFU);
}
