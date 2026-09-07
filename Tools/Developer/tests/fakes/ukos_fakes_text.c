/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * text_checkAsciiBuffer, in a translation unit of its own.
 *
 * It lives alone here for a linker reason, not a tidiness one. One suite -
 * ukos_tests_port_text - compiles the real OS/Lib_generics/text/text.c, which
 * defines this function too. While the copy sat in ukos_fakes.c that was a
 * guaranteed duplicate symbol: ukos_t_begin() memsets g_fakes, which lives in
 * that file, so the object is pulled from the archive by every executable.
 *
 * A conditional #define could not fix it either - ukos_fakes.c is compiled once
 * into ukos_test_support, so a per-target definition never reaches it.
 *
 * Alone in its own object the problem disappears on its own terms: an archive
 * member is pulled only when a symbol it defines is still needed, and the text
 * suite already has this one from text.c. Every other suite pulls it exactly as
 * before.
 */

#include    <stdbool.h>

#include    "types.h"
#include    "ukos_fakes.h"

// text - verbatim copy of the production function
// ===============================================
//
// Guarded because ONE suite compiles the real OS/Lib_generics/text/text.c and
// would otherwise link two definitions of this function. That collision is not
// avoidable by luck: ukos_t_begin() memsets g_fakes, which lives in this
// translation unit, so this object is pulled from the archive by every single
// test executable.
//
// The guard is off by default, so the other suites are untouched and keep using
// the copy. run-tests.sh still drift-checks it either way - its extractor is
// textual and does not preprocess.
//
// OS/Lib_generics/text/text.c cannot be compiled on the host (it needs kern
// and serial), but text_checkAsciiBuffer() itself is pure. The body below is a
// byte-for-byte copy of OS/Lib_generics/text/text.c:243-275; run-tests.sh
// diffs the two and fails the run if they ever drift apart.
//
// Its semantics are load bearing for date.c and quirky: it compares until ' '
// or '\0' in ascii1, then requires ascii2's next character to be one of
// ',', ' ', '\n', '\r', '\0'. So "-rtc extra" matches "-rtc", but "-rtcx" and
// "-rt" do not.

#define KERR_TEXT_NOERR     0

int32_t text_checkAsciiBuffer(const char_t *ascii1, const char_t *ascii2, bool *equals) {
    const   char_t  *wkAscii1 = ascii1;
    const   char_t  *wkAscii2 = ascii2;

    do {
        if (*wkAscii1 != *wkAscii2) {
            *equals = false;
            return KERR_TEXT_NOERR;
        }

        wkAscii1++;
        wkAscii2++;
    } while ((*wkAscii1 != ' ') && (*wkAscii1 != '\0'));

    switch (*wkAscii2) {
        case ',':
        case ' ':
        case '\n':
        case '\r':
        case '\0': {
            *equals = true;
            return KERR_TEXT_NOERR;
        }
        default: {

// Make MISRA happy :-)

            break;
        }
    }
    *equals = false;
    return KERR_TEXT_NOERR;
}
