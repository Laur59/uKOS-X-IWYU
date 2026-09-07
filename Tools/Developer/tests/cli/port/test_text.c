/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_generics/text/text.c.
 *
 * Four pure functions - no globals, no I/O, no allocation - three of which had
 * no host coverage of any kind, and one of them is the CLI's front door:
 * text_readArgs tokenises every console command on all 15 boards.
 *
 * Tier 2 for a purely LEXICAL reason. Nothing here needs the port layer; the
 * file includes kern/kern.h, which reaches macros_soc.h through privileges.h,
 * and OS/Lib_kernels is only on the tier-2 include path. The functions tested
 * below take nothing from kern at all.
 *
 * text_waitString and the two statics behind it - the blocking line editor - are
 * deliberately NOT tested here. local_waitOrder is a while(true) that exits only
 * on CR or LF, so a test feeding a stream without a terminator would HANG the
 * runner rather than fail it.
 *
 * Not calling them is not enough to avoid their dependencies, though. text.c is
 * one translation unit and the whole object is linked, so the five symbols that
 * path reaches still have to resolve. Mach-O ld does not dead-strip by default.
 * They are therefore stubbed at the bottom of this file - locally, not in the
 * shared tier-2 fakes, because nothing else wants them and a stub that exists
 * only to satisfy the linker should be visible next to the reason it exists.
 *
 * This is also the only suite that compiles the real text_checkAsciiBuffer. Every
 * other one links a drift-checked verbatim copy in fakes/ukos_fakes.c, so the
 * five CLI suites that depend on its quirky prefix semantics are really testing
 * that copy. Pinning the same semantics against the original here is what makes
 * the drift check meaningful rather than self-referential - hence
 * UKOS_TESTS_REAL_TEXT, which switches the copy off for this target alone.
 *
 * DO NOT pass an empty first argument to text_checkAsciiBuffer from any test.
 * See DEFECTS.md: it reads one past the terminator, the copy has the same defect
 * byte for byte, and provoking it would turn `run-tests -s` red for the whole
 * tree.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "modules.h"
#include    "os_errors.h"
#include    "kern/kern.h"
#include    "serial/serial.h"
#include    "text/text.h"
#include    "types.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aText_Specifications;

#define KBUF                64U
#define KMAX_ARGS           16U

static  char_t          vBuffer[KBUF];
static  const char_t    *vArgv[KMAX_ARGS];
static  uint32_t        vArgc;

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    (void)memset(&vBuffer[0], 0, sizeof(vBuffer));
    (void)memset(&vArgv[0],   0, sizeof(vArgv));
    vArgc = 0xFFFFFFFFU;
}

/*
 * \brief Load a command line into the buffer and tokenise it
 *
 * - The buffer is filled with a recognisable pattern first, so a test can see
 *   whether pass 1 really zero-filled past the terminator rather than leaving
 *   whatever was there.
 *
 */
static  void    local_readArgs(const char_t *line) {

    (void)memset(&vBuffer[0], 'Z', sizeof(vBuffer));
    (void)strcpy(&vBuffer[0], line);

    EXPECT_EQ_I(text_readArgs(&vBuffer[0], (uint32_t)sizeof(vBuffer), &vArgv[0], &vArgc), KERR_TEXT_NOERR);
}

// text_readArgs
// =============

TEST(text_an_empty_line_yields_no_arguments) {
    local_setup();

    vBuffer[0] = '\0';
    EXPECT_EQ_I(text_readArgs(&vBuffer[0], (uint32_t)sizeof(vBuffer), &vArgv[0], &vArgc), KERR_TEXT_NOERR);

// The early return happens BEFORE either pass, so argv is left exactly as the
// caller had it - not even argv[0] is written.

    EXPECT_EQ_U(vArgc, 0U);
    EXPECT_EQ_PTR(vArgv[0], nullptr);
}

TEST(text_a_single_token_is_one_argument) {
    local_setup();

    local_readArgs("date");

    EXPECT_EQ_U(vArgc, 1U);
    EXPECT_EQ_STR(vArgv[0], "date");
}

TEST(text_spaces_separate_arguments) {
    local_setup();

    local_readArgs("dump 100 200");

    EXPECT_EQ_U(vArgc, 3U);
    EXPECT_EQ_STR(vArgv[0], "dump");
    EXPECT_EQ_STR(vArgv[1], "100");
    EXPECT_EQ_STR(vArgv[2], "200");
}

TEST(text_runs_of_separators_collapse) {
    local_setup();

// Each separator becomes its own terminator, but the second pass only starts a
// new argument on a NON-null after a null, so a run behaves as one separator.

    local_readArgs("dump    100");

    EXPECT_EQ_U(vArgc, 2U);
    EXPECT_EQ_STR(vArgv[0], "dump");
    EXPECT_EQ_STR(vArgv[1], "100");
}

TEST(text_cr_and_lf_are_separators_too) {
    local_setup();

// The console hands over a line still carrying its terminator, so this is the
// ordinary case rather than an edge one.

    local_readArgs("date\r\n");

    EXPECT_EQ_U(vArgc, 1U);
    EXPECT_EQ_STR(vArgv[0], "date");

    local_setup();
    local_readArgs("dump\r100\n200");

    EXPECT_EQ_U(vArgc, 3U);
    EXPECT_EQ_STR(vArgv[2], "200");
}

TEST(text_a_trailing_separator_adds_no_argument) {
    local_setup();

    local_readArgs("date ");

    EXPECT_EQ_U(vArgc, 1U);
    EXPECT_EQ_STR(vArgv[0], "date");
}

TEST(text_a_leading_separator_produces_an_empty_first_argument) {
    local_setup();

// The early return only fires when the FIRST byte is already a terminator, and
// a leading space is not - it becomes one during pass 1, after the check. So
// argv[0] is set to the buffer unconditionally and ends up pointing at an empty
// string, with the real command in argv[1].
//
// That matters: console.c dispatches on argv[0], so a line the user opened with
// a space is not the command they typed. Pinned as current behaviour; see
// DEFECTS.md.

    local_readArgs(" date");

    QUIRK("text-readArgs-leading-space-empty-argv0", (vArgc == 2U));
    EXPECT_EQ_STR(vArgv[0], "");
    EXPECT_EQ_STR(vArgv[1], "date");
}

TEST(text_quotes_protect_spaces_but_are_not_removed) {
    local_setup();

    local_readArgs("echo \"a b\" c");

// The quote character toggles the protection and STAYS in the buffer, so the
// argument still carries both quotes. A caller wanting the bare text has to
// strip them itself.

    EXPECT_EQ_U(vArgc, 3U);
    EXPECT_EQ_STR(vArgv[0], "echo");
    EXPECT_EQ_STR(vArgv[1], "\"a b\"");
    EXPECT_EQ_STR(vArgv[2], "c");
}

TEST(text_an_unbalanced_quote_protects_the_rest_of_the_line) {
    local_setup();

    local_readArgs("echo \"a b c");

// There is no error for an unclosed quote: the toggle simply never flips back
// and every remaining space is protected.

    EXPECT_EQ_U(vArgc, 2U);
    EXPECT_EQ_STR(vArgv[1], "\"a b c");
}

TEST(text_the_buffer_is_zero_filled_past_the_line) {
    uint32_t    i;

    local_setup();

    local_readArgs("hi");

// Pass 1 walks the WHOLE buffer, not just the line, and blanks everything after
// the first terminator. That is what stops a long previous command showing
// through a short new one - console.c reuses one buffer.

    for (i = 3U; i < (uint32_t)sizeof(vBuffer); i++) {
        EXPECT_EQ_I(vBuffer[i], 0);
    }
}

TEST(text_readArgs_does_not_bound_the_argument_vector) {
    uint32_t    i;
    char_t      line[KBUF];

    local_setup();

// Nine tokens into a vector the function was never told the size of. It fits
// here only because this test made it fit: the capacity of argv is not a
// parameter, so text_readArgs cannot check it and does not.
//
// console.c:253 passes a KLN_CMD_LINE_BUF-sized array, so a line with more
// tokens than that overflows the caller's stack. A genuine out-of-bounds write,
// recorded in DEFECTS.md and NOT provoked here - a test that overflowed on
// purpose would turn `run-tests -s` red.

    line[0] = '\0';
    for (i = 0U; i < 9U; i++) { (void)strcat(&line[0], "x "); }

    local_readArgs(&line[0]);

    EXPECT_EQ_U(vArgc, 9U);
    EXPECT_TRUE(vArgc <= KMAX_ARGS);
}

// text_copyAsciiBufferZ / N
// =========================

TEST(text_copyZ_appends_a_terminator) {
    char_t  dest[16];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], "abc"), KERR_TEXT_NOERR);

    EXPECT_EQ_STR(&dest[0], "abc");
    EXPECT_EQ_I(dest[3], 0);
    EXPECT_EQ_I(dest[4], 'Z');                          // and nothing beyond it
}

TEST(text_copyN_does_not_append_a_terminator) {
    char_t  dest[16];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], "abc"), KERR_TEXT_NOERR);

// The whole difference between the two functions. N is for patching text into
// the middle of an existing buffer, so terminating would truncate it.

    EXPECT_EQ_I(dest[0], 'a');
    EXPECT_EQ_I(dest[1], 'b');
    EXPECT_EQ_I(dest[2], 'c');
    EXPECT_EQ_I(dest[3], 'Z');
}

TEST(text_copyZ_leaves_the_destination_untouched_for_an_empty_source) {
    char_t  dest[16];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], ""), KERR_TEXT_NOERR);

// Every other input writes the terminator; this one returns before it. So
// copying an empty string into a dirty buffer leaves the OLD contents, and a
// caller reading dest as a C string gets whatever was there before.
//
// console.c:139 copies argv[2] straight into commandLine, so an empty argument
// leaves the previous command in place. See DEFECTS.md.

    QUIRK("text-copyZ-empty-source-no-terminator", (dest[0] == 'Z'));
}

TEST(text_copyN_is_a_no_op_for_an_empty_source) {
    char_t  dest[16];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], ""), KERR_TEXT_NOERR);

// Consistent for N, because N never writes a terminator anyway.

    EXPECT_EQ_I(dest[0], 'Z');
}

TEST(text_both_copies_handle_a_single_character) {
    char_t  dest[4];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], "x"), KERR_TEXT_NOERR);
    EXPECT_EQ_STR(&dest[0], "x");

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], "x"), KERR_TEXT_NOERR);
    EXPECT_EQ_I(dest[0], 'x');
    EXPECT_EQ_I(dest[1], 'Z');
}

// text_checkAsciiBuffer, against the REAL function
// ================================================

TEST(text_checkAsciiBuffer_matches_a_flag_and_its_trailing_context) {
    bool    equals = false;

    local_setup();

// The semantics five CLI suites depend on, asserted here against the original
// rather than the copy they link. It compares until a space or terminator in
// the FIRST argument, then requires the second's next character to be one of
// ',', ' ', '\n', '\r' or '\0'.

    EXPECT_EQ_I(text_checkAsciiBuffer("-rtc", "-rtc", &equals), KERR_TEXT_NOERR);
    EXPECT_TRUE(equals);

    (void)text_checkAsciiBuffer("-rtc", "-rtc extra", &equals);
    EXPECT_TRUE(equals);                                // a space ends the match

    (void)text_checkAsciiBuffer("-rtc", "-rtc,x", &equals);
    EXPECT_TRUE(equals);                                // so does a comma

    (void)text_checkAsciiBuffer("-rtc", "-rtc\r", &equals);
    EXPECT_TRUE(equals);
}

TEST(text_checkAsciiBuffer_rejects_a_prefix_or_a_superstring) {
    bool    equals = true;

    local_setup();

// The two failures that matter to a CLI: an abbreviation and an extension of a
// flag must both be refused, or "dump -S" and "dump -Save" would be the same
// command.

    (void)text_checkAsciiBuffer("-rtc", "-rt", &equals);
    EXPECT_FALSE(equals);

    (void)text_checkAsciiBuffer("-rtc", "-rtcx", &equals);
    EXPECT_FALSE(equals);

    (void)text_checkAsciiBuffer("-rtc", "-gmt", &equals);
    EXPECT_FALSE(equals);
}

TEST(text_checkAsciiBuffer_stops_at_a_space_in_its_first_argument) {
    bool    equals = false;

    local_setup();

// The quirk the CLI suites tag as text-checkAsciiBuffer-space-terminates: the
// first argument is itself truncated at a space, so "-rtc x" behaves as "-rtc".
// Asserted here against the real function, which is what makes the drift check
// on the copy worth running.

    (void)text_checkAsciiBuffer("-rtc x", "-rtc", &equals);
    EXPECT_TRUE(equals);
}

// The module descriptor
// =====================

TEST(text_module_metadata) {
    local_setup();

// A library, like mlpn: no oExecution, BSHOW without BEXE_CONSOLE. Which is why
// this suite calls the functions directly instead of going through the
// descriptor as the CLI suites do.

    EXPECT_EQ_U(aText_Specifications.oIdModule,
                (((uint32_t)KID_FAM_GENERICS << 24U) | ((uint32_t)KNUM_TEXT << 8U) | (uint32_t)(uint8_t)'_'));

    EXPECT_EQ_PTR((const void *)aText_Specifications.oInit,      nullptr);
    EXPECT_EQ_PTR((const void *)aText_Specifications.oExecution, nullptr);
    EXPECT_EQ_PTR((const void *)aText_Specifications.oClean,     nullptr);

    EXPECT_EQ_STR(aText_Specifications.oStrRevision, " 1.0");
    EXPECT_EQ_U(aText_Specifications.oFlag & (1U << BSHOW),        (1U << BSHOW));
    EXPECT_EQ_U(aText_Specifications.oFlag & (1U << BEXE_CONSOLE), 0U);
}

// Linker-only stubs
// =================
//
// Five symbols reached from text_waitString / local_waitOrder / local_getChar,
// none of which this suite calls. They exist so the translation unit links, and
// they are deliberately useless: each returns an error or a null, so a test that
// started calling the console path would fail loudly rather than run against a
// convincing fiction.
//
// If the blocking path is ever taken on, these are the wrong shape - it needs
// real doubles wired to ukos_fake_feedSerialText(), and a rule that every stream
// ends in CR or LF.

int32_t     kern_getProcessRun(proc_t **handle) {

    *handle = nullptr;
    return KERR_KERN_NOPRO;
}

int32_t     kern_getSerialForProcess([[maybe_unused]] proc_t *handle, serialManager_t *serialManager) {

    *serialManager = KNOTR;
    return KERR_KERN_NOPRO;
}

int32_t     kern_getSemaphoreById([[maybe_unused]] const char_t *identifier, sema_t **handle) {

    *handle = nullptr;
    return KERR_KERN_NOSEM;
}

int32_t     kern_waitSemaphore([[maybe_unused]] sema_t *handle, [[maybe_unused]] uint32_t timeout) {

    return KERR_KERN_NOSEM;
}

int32_t     serial_getIdSemaphore([[maybe_unused]] serialManager_t serialManager,
                                  [[maybe_unused]] uint8_t semaphore, char_t **identifier) {

    *identifier = nullptr;
    return KERR_SERIAL_NODEV;
}
