/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/hexloader/hexloader.c.
 *
 * Tier 2, and the reason the serial seam exists. The module is an Intel-HEX
 * decoder wrapped in a few lines of transport: it reaches the kernel only
 * through local_getByte(), whose sole outward call is serial_read(). Feeding
 * that a byte array turns roughly 500 lines of record parsing, checksum
 * arithmetic and address bookkeeping into an ordinary host-testable parser.
 *
 * The decoded bytes land in a buffer the TEST owns, so ASan guards every store
 * the module makes - which is the whole reason this tier is worth the stub
 * layer.
 *
 * NOT exercised: the -run path. On success with run == KRUN the module calls
 * (*code)(argc, argv), jumping into whatever was just decoded. A host cannot
 * safely jump into data, so every test that reaches the end of a download uses
 * -norun. Note that KRUN is the DEFAULT, so this is not the common invocation.
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

extern  const uKOS_module_t     aHexloader_Specifications;

#define KBANNER     "Hex format Intel loader mode; waiting for the code.\n"
#define KDONE       "\nHex: download terminated.\n\n"

#define KOK         EXIT_OS_SUCCESS_CLI
#define KFAIL       EXIT_OS_FAILURE

// The decode target. Over-sized and owned here, so a stray write is an ASan
// report rather than silent corruption of something else.

#define KUMEMO      256U
static  uint8_t     vUMemo[KUMEMO];

static int32_t local_run(const char *stream) {
    const char_t    *argv[] = { "hexloader", "-norun" };

    ukos_fake_feedSerialText(stream);
    return aHexloader_Specifications.oExecution(2U, argv);
}

static void local_begin(void) {

    ukos_t_begin("UTC0");
    (void)memset(&vUMemo[0], 0xCD, sizeof vUMemo);       // a recognisable "untouched"
    ukos_fake_setUserMemory(&vUMemo[0], sizeof vUMemo);
}

// Records generated from the Intel-HEX definition, not copied from the module.

#define KREC_DATA4      ":04000000DEADBEEFC4"        // 4 bytes at offset 0
#define KREC_DATA_AT10  ":020010000102EB"            // 2 bytes at offset 0x10
#define KREC_EXT0       ":020000040000FA"            // extended address 0x0000
#define KREC_EOF        ":00000001FF"

// ============================================================================
// Module metadata
// ============================================================================

TEST(hexloader_module_metadata) {

    local_begin();

    EXPECT_EQ_U(aHexloader_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_HEX_LOADER << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_TRUE(aHexloader_Specifications.oExecution != NULL);
}

// ============================================================================
// The decoder
// ============================================================================

TEST(hexloader_decodes_a_data_record) {
    int32_t     status;

    local_begin();
    status = local_run(KREC_EXT0 KREC_DATA4 KREC_EOF);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_HAS(KDONE);

// The four payload bytes land at the base of the user memory, and nothing
// beyond them is touched.

    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[1], 0xADU);
    EXPECT_EQ_U(vUMemo[2], 0xBEU);
    EXPECT_EQ_U(vUMemo[3], 0xEFU);
    EXPECT_EQ_U(vUMemo[4], 0xCDU);
}

TEST(hexloader_honours_the_record_offset) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA_AT10 KREC_EOF), KOK);

    EXPECT_EQ_U(vUMemo[0x10], 0x01U);
    EXPECT_EQ_U(vUMemo[0x11], 0x02U);
    EXPECT_EQ_U(vUMemo[0x0F], 0xCDU);
    EXPECT_EQ_U(vUMemo[0x12], 0xCDU);
}

TEST(hexloader_accepts_several_data_records) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 KREC_DATA_AT10 KREC_EOF), KOK);

    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[0x10], 0x01U);
}

TEST(hexloader_ignores_noise_before_a_record) {

    local_begin();

// The reader spins until it sees ':', so anything before a record is skipped -
// which is what makes a terminal paste work.

    EXPECT_EQ_I(local_run("garbage\r\n" KREC_EXT0 KREC_DATA4 KREC_EOF), KOK);
    EXPECT_EQ_U(vUMemo[0], 0xDEU);
}

TEST(hexloader_stops_at_the_end_record) {

    local_begin();

// Anything after the EOF record must not be decoded.

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 KREC_EOF KREC_DATA_AT10), KOK);

    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[0x10], 0xCDU);
}

// ============================================================================
// The checksum
// ============================================================================

TEST(hexloader_rejects_a_bad_data_checksum) {
    int32_t     status;

    local_begin();

// Same record as KREC_DATA4 with the last byte off by one.

    status = local_run(KREC_EXT0 ":04000000DEADBEEFC5" KREC_EOF);

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("\nHex: wrong checksum.\n\n");
    EXPECT_OUT_LACKS("download terminated");
}

TEST(hexloader_rejects_a_bad_end_checksum) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 ":00000001FE"), KFAIL);
    EXPECT_OUT_HAS("\nHex: wrong checksum.\n\n");
}

TEST(hexloader_checksum_is_the_twos_complement) {

    local_begin();

// The module computes (uint8_t)(0 - checksum) over count, offset, type and
// data. A record whose bytes sum to zero modulo 256 therefore ends in 00.

    EXPECT_EQ_I(local_run(KREC_EXT0 ":0100000000FF" KREC_EOF), KOK);
    EXPECT_EQ_U(vUMemo[0], 0x00U);
}

// ============================================================================
// Record types
// ============================================================================

TEST(hexloader_extended_address_zero_falls_back_to_the_user_memory) {

    local_begin();

// A type 4 record with page 0 is rewritten to linker_stUMemo, which is what
// makes a file linked at address 0 land in the download window instead of at
// the bottom of the address space.

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 KREC_EOF), KOK);
    EXPECT_EQ_U(vUMemo[0], 0xDEU);
}

TEST(hexloader_unknown_record_type_is_skipped) {

    local_begin();

// Type 3 has no arm, so it is consumed and ignored rather than treated as an
// error - the decode continues with the following records.

    EXPECT_EQ_I(local_run(KREC_EXT0 ":02000003ABCD87" KREC_DATA4 KREC_EOF), KOK);
    EXPECT_EQ_U(vUMemo[0], 0xDEU);
}

TEST(hexloader_start_address_record_is_accepted) {

    local_begin();

// Type 5 carries the entry point; it must parse and checksum like any other.

    EXPECT_EQ_I(local_run(KREC_EXT0 ":0400000500000000F7" KREC_EOF), KOK);
    EXPECT_OUT_HAS(KDONE);
}

// ============================================================================
// Malformed input
// ============================================================================

TEST(hexloader_non_hex_digit_is_rejected) {

    local_begin();

// The final data nibble is 'G', with a checksum computed as if it read 0: the
// byte would be 0xE0 instead of 0xEF. It used to be accepted outright - a
// character that is not a hex digit contributed 0 - so only a checksum that
// happened to disagree caught a corrupt stream. Now the digit itself is refused
// and the byte is never stored.

    EXPECT_EQ_I(local_run(KREC_EXT0 ":04000000DEADBEEGD3" KREC_EOF), KFAIL);

    EXPECT_OUT_HAS("\nHex: not a hex digit.\n\n");
    EXPECT_OUT_LACKS(KDONE);
    EXPECT_EQ_U(vUMemo[3], 0xCDU);
}

TEST(hexloader_non_hex_digit_is_rejected_before_the_checksum) {

    local_begin();

// Even when the checksum would disagree, the digit is what gets reported.

    EXPECT_EQ_I(local_run(KREC_EXT0 ":04000000DEADBEEGC4" KREC_EOF), KFAIL);
    EXPECT_OUT_HAS("\nHex: not a hex digit.\n\n");
    EXPECT_OUT_LACKS("wrong checksum");
}

TEST(hexloader_non_hex_high_nibble_is_rejected) {

    local_begin();

// The first digit of a byte goes through its own branch.

    EXPECT_EQ_I(local_run(KREC_EXT0 ":04000000DEADBEZFC4" KREC_EOF), KFAIL);
    EXPECT_OUT_HAS("\nHex: not a hex digit.\n\n");
}

TEST(hexloader_lower_case_digits_are_accepted) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 ":04000000deadbeefc4" KREC_EOF), KOK);
    EXPECT_EQ_U(vUMemo[3], 0xEFU);
}

TEST(hexloader_reports_a_truncated_stream) {
    int32_t     status;

    local_begin();

// The stream runs out mid-record. The seam returns a framing error on
// exhaustion rather than "no bytes, no error", which is what stops
// local_getByte() spinning forever.

    status = local_run(KREC_EXT0 ":04000000DEAD");

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("\nHex: framing error.\n\n");
}

TEST(hexloader_reports_an_empty_stream) {
    int32_t     status;

    local_begin();

// This used to HANG rather than fail: the loop waiting for a record mark
// discarded local_getByte()'s status, and that function sets *byte = 0 before
// returning an error, so 0 never matched ':'. A stream with no record at all is
// the shortest way to reach it.

    status = local_run("");

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("\nHex: framing error.\n\n");
    EXPECT_OUT_LACKS("download terminated");
}

TEST(hexloader_reports_a_stream_with_no_mark) {

    local_begin();

// Same path with the stream non-empty: everything is consumed looking for ':',
// the seam then reports exhaustion, and that status must end the wait.

    EXPECT_EQ_I(local_run("no record mark anywhere in here"), KFAIL);
    EXPECT_OUT_HAS("\nHex: framing error.\n\n");
}

// ============================================================================
// The transport around the decoder
// ============================================================================

TEST(hexloader_refuses_a_busy_user_memory) {
    const char_t    *argv[] = { "hexloader", "-norun" };
    int32_t         status;

    local_begin();
    g_kern.systemReserveRc = -1;

    status = aHexloader_Specifications.oExecution(2U, argv);

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "\nHex: The user memory is busy.\n\n");
    EXPECT_EQ_U(g_kern.serialReserveCalls, 0U);

// The reservation belongs to whoever holds it: releasing it here would hand the
// user memory to a second download while the first one still writes it.

    EXPECT_EQ_U(g_kern.systemReleaseCalls, 0U);
}

// The user memory is reserved for the download and must be given back on every
// path that starts nothing: kept, it refused every later download until a reset.
// The path that starts an application keeps it on purpose - its processes run
// from the user memory - and cannot be reached here (it would execute the blob).

TEST(hexloader_gives_the_user_memory_back_after_a_download) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 KREC_EOF), KOK);
    EXPECT_EQ_U(g_kern.systemReserveCalls, 1U);
    EXPECT_EQ_U(g_kern.systemReleaseCalls, 1U);
}

TEST(hexloader_gives_the_user_memory_back_after_a_bad_checksum) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 ":04000000DEADBEEFC5" KREC_EOF), KFAIL);
    EXPECT_OUT_HAS("\nHex: wrong checksum.\n\n");
    EXPECT_EQ_U(g_kern.systemReleaseCalls, 1U);
}

TEST(hexloader_gives_the_user_memory_back_after_a_failed_signature_check) {
    const char_t    *argv[] = { "hexloader" };

    local_begin();
    g_kern.systemSignature = "no-such-signature-in-the-buffer";
    ukos_fake_feedSerialText(KREC_EXT0 KREC_DATA4 KREC_EOF);

    EXPECT_EQ_I(aHexloader_Specifications.oExecution(1U, argv), KFAIL);
    EXPECT_OUT_HAS("\nHex: failed to find the application signature!\n");
    EXPECT_EQ_U(g_kern.systemReleaseCalls, 1U);
}

TEST(hexloader_reserves_and_releases_the_console) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 KREC_EOF), KOK);

// The port is held for the whole download and given back afterwards, with a
// flush so the tail of the stream is not left buffered.

    EXPECT_EQ_U(g_kern.serialReserveCalls, 1U);
    EXPECT_EQ_U(g_kern.serialReleaseCalls, 1U);
    EXPECT_EQ_U(g_kern.serialFlushCalls, 1U);
    EXPECT_EQ_U(g_kern.ledOffCalls, 1U);
    EXPECT_EQ_U(g_kern.lastSuspend, 500U);
}

TEST(hexloader_publishes_the_download_address) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 KREC_EOF), KOK);

// The decoded entry point is handed to the system so that "run" can find it.

    EXPECT_EQ_U(g_fakes.download.setCalls, 1U);
    EXPECT_TRUE(g_fakes.download.lastSet != NULL);
}

TEST(hexloader_norun_does_not_execute) {

    local_begin();

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 KREC_EOF), KOK);

// -norun stops before local_checkSignature() and the jump, which is the only
// reason this suite can run the success path at all.

    EXPECT_OUT_LACKS("failed to find the application signature");
}

TEST(hexloader_default_is_to_run) {
    const char_t    *argv[] = { "hexloader" };
    int32_t         status;

    local_begin();
    g_kern.systemSignature = "no-such-signature-in-the-buffer";
    ukos_fake_feedSerialText(KREC_EXT0 KREC_DATA4 KREC_EOF);

// Without -norun the module tries to execute. The signature check is what
// stands between a decoded blob and a jump, so a buffer that does not carry the
// signature must be refused rather than called.

    status = aHexloader_Specifications.oExecution(1U, argv);

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_HAS("\nHex: failed to find the application signature!\n");
}

TEST(hexloader_unknown_flag_is_ignored) {

    local_begin();

// argc == 2 only compares against -run and -norun; anything else leaves the
// default in place rather than being reported.

    ukos_fake_feedSerialText(KREC_EXT0 KREC_DATA4 KREC_EOF);
    g_kern.systemSignature = "absent";

    const char_t    *argv[] = { "hexloader", "-xyz" };
    EXPECT_EQ_I(aHexloader_Specifications.oExecution(2U, argv), KFAIL);
    EXPECT_OUT_HAS("failed to find the application signature");
}

// ============================================================================
// The seam's own contract
// ============================================================================

TEST(hexloader_burst_reads_decode_identically) {

    local_begin();

// The default one-byte chunk keeps local_getByte()'s statics clean between
// tests, but the module also has a 32-byte burst path. Both must decode the
// same stream identically; this test consumes its whole fixture so nothing is
// left buffered for the next one.

    g_kern.serialChunk = 32U;

    EXPECT_EQ_I(local_run(KREC_EXT0 KREC_DATA4 KREC_EOF), KOK);
    EXPECT_EQ_U(vUMemo[0], 0xDEU);
    EXPECT_EQ_U(vUMemo[3], 0xEFU);
}

// ============================================================================
// The run path jumps only to an application built for this system
// ============================================================================
//
// Without -norun the module jumps to the download's start address. It used to
// require only the system signature somewhere in the user memory - which SRAM
// keeps across resets - so an end-of-file record alone jumped to a NULL start
// address: a HardFault (IACCVIOL, PC = 0) on Nucleo_H743. Each case below
// would jump on the host too, where a wrong acceptance is a crash.

#define KSIGNATURE      "sig-0123456789abcdef"
#define KSIG_AT         64U

static void local_placeImage(uintptr_t entry, uintptr_t length) {
    uKOS_header_t   header;

    header.oMemLocation   = KMEMU;
    header.oStart         = (int32_t (*)(uint32_t argc, const char_t *argv[]))entry;
    header.oLnApplication = length;
    header.oModule        = NULL;
    (void)memcpy(&vUMemo[0], &header, sizeof header);
    (void)memcpy(&vUMemo[KSIG_AT], KSIGNATURE, sizeof KSIGNATURE);
}

static int32_t local_runDefault(const char *stream) {
    const char_t    *argv[] = { "hexloader" };

    ukos_fake_feedSerialText(stream);
    return aHexloader_Specifications.oExecution(1U, argv);
}

TEST(hexloader_does_not_jump_to_a_null_start_address) {

    local_begin();
    g_kern.systemSignature = KSIGNATURE;
    (void)memcpy(&vUMemo[KSIG_AT], KSIGNATURE, sizeof KSIGNATURE);   // stale, no header

    EXPECT_EQ_I(local_runDefault(KREC_EOF), KFAIL);
    EXPECT_OUT_HAS("\nHex: failed to find the application signature!\n");
}

TEST(hexloader_does_not_jump_to_an_entry_other_than_the_headers) {

    local_begin();
    g_kern.systemSignature = KSIGNATURE;
    local_placeImage(0x24000011U, 128U);

    EXPECT_EQ_I(local_runDefault(":0400000524000021B2" KREC_EOF), KFAIL);
    EXPECT_OUT_HAS("\nHex: failed to find the application signature!\n");
}

TEST(hexloader_ignores_a_signature_beyond_the_application) {

    local_begin();
    g_kern.systemSignature = KSIGNATURE;
    local_placeImage(0x24000011U, KSIG_AT);                   // ends before the signature

    EXPECT_EQ_I(local_runDefault(":0400000524000011C2" KREC_EOF), KFAIL);
    EXPECT_OUT_HAS("\nHex: failed to find the application signature!\n");
}
