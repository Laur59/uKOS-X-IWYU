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

    EXPECT_EQ_I(text_readArgs(&vBuffer[0], (uint32_t)sizeof(vBuffer), &vArgv[0], KMAX_ARGS, &vArgc), KERR_TEXT_NOERR);
}

// text_readArgs
// =============

TEST(text_an_empty_line_yields_no_arguments) {
    local_setup();

    vBuffer[0] = '\0';
    EXPECT_EQ_I(text_readArgs(&vBuffer[0], (uint32_t)sizeof(vBuffer), &vArgv[0], KMAX_ARGS, &vArgc), KERR_TEXT_NOERR);

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

TEST(text_leading_blanks_are_skipped) {
    local_setup();

// console.c dispatches on argv[0]. It used to be the buffer itself - an empty
// string after a leading blank, with the command in argv[1] - so a line the
// user opened with a space was not the command they typed.

    local_readArgs("   date 5");

    EXPECT_EQ_U(vArgc, 2U);
    EXPECT_EQ_STR(vArgv[0], "date");
    EXPECT_EQ_STR(vArgv[1], "5");
}

TEST(text_a_line_of_blanks_has_no_argument) {
    local_setup();

    local_readArgs("    ");

    EXPECT_EQ_U(vArgc, 0U);
    EXPECT_EQ_PTR(vArgv[0], nullptr);
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

// The capacity of argv is a parameter, and no pointer is ever stored past it.
// Each test below hands text_readArgs FEWER slots than vArgv really has, so a
// write past the capacity lands in vArgv - where the test sees it - instead of
// past the end of an array, where only ASan would.

#define KCAP                4U

static  int32_t local_readArgsCap(const char_t *line, uint32_t capacity) {

    (void)memset(&vBuffer[0], 'Z', sizeof(vBuffer));
    (void)strcpy(&vBuffer[0], line);
    return text_readArgs(&vBuffer[0], (uint32_t)sizeof(vBuffer), &vArgv[0], capacity, &vArgc);
}

TEST(text_readArgs_fills_argv_exactly_to_its_capacity) {
    local_setup();

    EXPECT_EQ_I(local_readArgsCap("a b c d", KCAP), KERR_TEXT_NOERR);
    EXPECT_EQ_U(vArgc, KCAP);
    EXPECT_EQ_STR(vArgv[3], "d");
    EXPECT_EQ_PTR(vArgv[KCAP], nullptr);
}

TEST(text_readArgs_refuses_one_argument_too_many) {
    local_setup();

    EXPECT_EQ_I(local_readArgsCap("a b c d e", KCAP), KERR_TEXT_TMARG);
    EXPECT_EQ_U(vArgc, KCAP);
    EXPECT_EQ_STR(vArgv[3], "d");
    EXPECT_EQ_PTR(vArgv[KCAP], nullptr);                   // "e" was not stored
}

TEST(text_readArgs_refuses_many_arguments_too_many) {
    uint32_t    i;

    local_setup();

    EXPECT_EQ_I(local_readArgsCap("a b c d e f g h i j k l", KCAP), KERR_TEXT_TMARG);
    EXPECT_EQ_U(vArgc, KCAP);
    for (i = KCAP; i < KMAX_ARGS; i++) {
        EXPECT_EQ_PTR(vArgv[i], nullptr);
    }
}

TEST(text_readArgs_leading_blanks_take_no_slot) {
    local_setup();

// Leading blanks are skipped, so they cost no slot of the capacity.

    EXPECT_EQ_I(local_readArgsCap("  a b c d", KCAP), KERR_TEXT_NOERR);
    EXPECT_EQ_U(vArgc, KCAP);
    EXPECT_EQ_STR(vArgv[0], "a");
    EXPECT_EQ_I(local_readArgsCap("  a b c d e", KCAP), KERR_TEXT_TMARG);
    EXPECT_EQ_PTR(vArgv[KCAP], nullptr);
}

TEST(text_readArgs_with_no_capacity_stores_nothing) {
    local_setup();

    EXPECT_EQ_I(local_readArgsCap("date", 0U), KERR_TEXT_TMARG);
    EXPECT_EQ_U(vArgc, 0U);
    EXPECT_EQ_PTR(vArgv[0], nullptr);
}

TEST(text_readArgs_empty_line_needs_no_capacity) {
    local_setup();

    vBuffer[0] = '\0';
    EXPECT_EQ_I(text_readArgs(&vBuffer[0], (uint32_t)sizeof(vBuffer), &vArgv[0], 0U, &vArgc), KERR_TEXT_NOERR);
    EXPECT_EQ_U(vArgc, 0U);
}

// The console's own sizes: a KLN_CMD_LINE_BUF (2048) buffer, of which the line
// editor fills at most 2047 characters, and KNB_PARAMETERS (1024) pointers. The
// densest line it can receive - 1024 one-letter words, blanks between - needs
// exactly 1024 slots, so the console is bounded by construction; the rpn
// application (256 characters, 10 pointers) was not.

#define KCON_LINE           2048U
#define KCON_ARGS           1024U

static  char_t          vConLine[KCON_LINE + 1U];
static  const char_t    *vConArgv[KCON_ARGS + 1U];

TEST(text_readArgs_the_densest_console_line_fits_its_argv) {
    uint32_t    i, argc = 0U;

    local_setup();
    (void)memset(&vConLine[0], 0, sizeof(vConLine));
    (void)memset(&vConArgv[0], 0, sizeof(vConArgv));

    for (i = 0U; i < 1024U; i++) {
        vConLine[2U * i] = 'x';
        if (i < 1023U) {
            vConLine[(2U * i) + 1U] = ' ';
        }
    }
    vConLine[KCON_LINE - 1U] = '\0';                        // 2047 characters, as the editor stores

    EXPECT_EQ_I(text_readArgs(&vConLine[0], KCON_LINE, &vConArgv[0], KCON_ARGS, &argc), KERR_TEXT_NOERR);
    EXPECT_EQ_U(argc, KCON_ARGS);
    EXPECT_EQ_PTR(vConArgv[KCON_ARGS], nullptr);
}

// text_copyAsciiBufferZ / N
// =========================

TEST(text_copyZ_appends_a_terminator) {
    char_t  dest[16];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], sizeof(dest), "abc"), KERR_TEXT_NOERR);

    EXPECT_EQ_STR(&dest[0], "abc");
    EXPECT_EQ_I(dest[3], 0);
    EXPECT_EQ_I(dest[4], 'Z');                          // and nothing beyond it
}

TEST(text_copyN_does_not_append_a_terminator) {
    char_t  dest[16];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], sizeof(dest), "abc"), KERR_TEXT_NOERR);

// The whole difference between the two functions. N is for patching text into
// the middle of an existing buffer, so terminating would truncate it.

    EXPECT_EQ_I(dest[0], 'a');
    EXPECT_EQ_I(dest[1], 'b');
    EXPECT_EQ_I(dest[2], 'c');
    EXPECT_EQ_I(dest[3], 'Z');
}

TEST(text_copyZ_terminates_an_empty_source) {
    char_t  dest[16];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], sizeof(dest), ""), KERR_TEXT_NOERR);

// An empty source writes its terminator like every other one. It used to return
// before it, so a dirty buffer kept its old contents - console.c copies argv[2]
// straight into commandLine, so an empty argument left the previous command.
// Only the terminator is written: the rest of the buffer is untouched.

    EXPECT_EQ_I(dest[0], '\0');
    EXPECT_EQ_I(dest[1], 'Z');
}

TEST(text_copyN_is_a_no_op_for_an_empty_source) {
    char_t  dest[16];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], sizeof(dest), ""), KERR_TEXT_NOERR);

// Consistent for N, because N never writes a terminator anyway.

    EXPECT_EQ_I(dest[0], 'Z');
}

TEST(text_both_copies_handle_a_single_character) {
    char_t  dest[4];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], sizeof(dest), "x"), KERR_TEXT_NOERR);
    EXPECT_EQ_STR(&dest[0], "x");

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], sizeof(dest), "x"), KERR_TEXT_NOERR);
    EXPECT_EQ_I(dest[0], 'x');
    EXPECT_EQ_I(dest[1], 'Z');
}

// The bound. console.c copies a command of up to KLN_CMD_LINE_BUF characters
// into a KLN_INIT_CMD_LINE_BUF + 1 stack buffer; neither copy took the
// destination size, so a long command overflowed the console's stack. See
// DEFECTS.md.

TEST(text_copyZ_fills_the_destination_exactly) {
    char_t  dest[8];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], 4U, "abc"), KERR_TEXT_NOERR);   // 3 + terminator
    EXPECT_EQ_STR(&dest[0], "abc");
    EXPECT_EQ_I(dest[4], 'Z');
}

TEST(text_copyZ_truncates_and_terminates_a_source_that_does_not_fit) {
    char_t  dest[8];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], 4U, "abcd"), KERR_TEXT_TOLNG);  // one too many
    EXPECT_EQ_STR(&dest[0], "abc");
    EXPECT_EQ_I(dest[4], 'Z');                          // nothing past sizeD

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], 4U, "abcdefghijklmnop"), KERR_TEXT_TOLNG);
    EXPECT_EQ_STR(&dest[0], "abc");
    EXPECT_EQ_I(dest[4], 'Z');
}

TEST(text_copyZ_writes_nothing_into_a_zero_sized_destination) {
    char_t  dest[4];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], 0U, ""), KERR_TEXT_TOLNG);
    EXPECT_EQ_I(dest[0], 'Z');                          // not even the terminator
}

TEST(text_copyZ_a_single_byte_destination_takes_only_the_terminator) {
    char_t  dest[4];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], 1U, ""), KERR_TEXT_NOERR);
    EXPECT_EQ_I(dest[0], '\0');

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferZ(&dest[0], 1U, "x"), KERR_TEXT_TOLNG);
    EXPECT_EQ_I(dest[0], '\0');
    EXPECT_EQ_I(dest[1], 'Z');
}

TEST(text_copyN_fills_the_destination_exactly) {
    char_t  dest[8];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], 3U, "abc"), KERR_TEXT_NOERR);   // no terminator: 3 fit in 3
    EXPECT_EQ_I(dest[2], 'c');
    EXPECT_EQ_I(dest[3], 'Z');
}

TEST(text_copyN_truncates_a_source_that_does_not_fit) {
    char_t  dest[8];

    local_setup();

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], 3U, "abcd"), KERR_TEXT_TOLNG);
    EXPECT_EQ_I(dest[0], 'a');
    EXPECT_EQ_I(dest[2], 'c');
    EXPECT_EQ_I(dest[3], 'Z');                          // nothing past sizeD

    (void)memset(&dest[0], 'Z', sizeof(dest));
    EXPECT_EQ_I(text_copyAsciiBufferN(&dest[0], 0U, "a"), KERR_TEXT_TOLNG);
    EXPECT_EQ_I(dest[0], 'Z');
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
