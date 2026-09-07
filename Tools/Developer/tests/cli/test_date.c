/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/date/date.c.
 *
 * The module is compiled unmodified and reached through its MODULE()
 * descriptor, so prgm() staying static is not an obstacle. This file is
 * compiled into both the RTC-less and the RTC-enabled executable.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>
#include    <time.h>

#include    "calendar/calendar.h"
#include    "exit_codes.h"
#include    "modules.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_test.h"

// The module under test, reached through the descriptor MODULE() emits.

extern  const uKOS_module_t     aDate_Specifications;

#define KBANNER             "Set/display the date.\n"
#define KTZ_UTC             "UTC0"
#define KTZ_CET             "CET-1CEST,M3.5.0,M10.5.0/3"

#define KOK                 EXIT_OS_SUCCESS_CLI
#define KFAIL               EXIT_OS_FAILURE

// Golden asctime() renderings - the format is fixed by ISO C 7.27.3.1 and is
// locale independent, so these are stable across newlib and Darwin.

#define KASC_T1             "Mon Mar 31 18:00:22 2025\n"        // epoch 1743444022, UTC

static int32_t local_run(uint32_t argc, const char_t *argv[]) {

    return aDate_Specifications.oExecution(argc, argv);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(date_module_metadata) {

    ukos_t_begin(KTZ_UTC);

    EXPECT_EQ_U(aDate_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_DATE << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aDate_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_EQ_U(aDate_Specifications.oExecutionCore, 0U);
    EXPECT_TRUE(aDate_Specifications.oInit      == NULL);
    EXPECT_TRUE(aDate_Specifications.oClean     == NULL);
    EXPECT_TRUE(aDate_Specifications.oExecution != NULL);
    EXPECT_EQ_STR(aDate_Specifications.oStrRevision, " 1.1");
    EXPECT_EQ_STR(aDate_Specifications.oStrApplication,
                  "date         Set / display date and time.              (c) EFr-2026");

// oStrHelp embeds __DATE__ / __TIME__, so only a prefix and a substring can be
// asserted.

    EXPECT_TRUE(strncmp(aDate_Specifications.oStrHelp, "Set/display the date\n====", 25U) == 0);
    EXPECT_TRUE(strstr(aDate_Specifications.oStrHelp, "date -gmt [GMT[+/-n]]") != NULL);
}

// ============================================================================
// argc == 1  -  UTC and local time from the internal counter
// ============================================================================

TEST(date_argc1_golden_utc) {
    const char_t    *argv[] = { "date" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(1U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER
                  "From timer: Epoch = 1743444022204019, UTC time:    " KASC_T1
                  "From timer: Epoch = 1743444022204019, Local time:  " KASC_T1
                  "\n");
    EXPECT_EQ_U(g_fakes.dprintfCalls, 4U);
    EXPECT_EQ_U(g_fakes.read.calls, 1U);
    EXPECT_EQ_I(g_fakes.read.lastFrom, KFROM_TIMER);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
    EXPECT_EQ_U(g_fakes.setUTC.calls, 0U);
}

TEST(date_argc1_single_digit_day_padding) {
    const char_t    *argv[] = { "date" };

    ukos_t_begin(KTZ_UTC);
    g_fakes.read.value = 1743589680000000ULL;                   // Wed Apr  2 10:28:00 2025 UTC

    (void)local_run(1U, argv);

// Two spaces before the 2: asctime() pads the day with %3d.

    EXPECT_OUT_HAS("Wed Apr  2 10:28:00 2025\n");
}

TEST(date_argc1_epoch_zero) {
    const char_t    *argv[] = { "date" };

    ukos_t_begin(KTZ_UTC);
    g_fakes.read.value = 0U;

    (void)local_run(1U, argv);

    EXPECT_OUT_HAS("Epoch = 0, UTC time:    Thu Jan  1 00:00:00 1970\n");
}

TEST(date_argc1_dst_local_differs) {
    const char_t    *argv[] = { "date" };

    ukos_t_begin(KTZ_CET);
    g_fakes.read.value = 1749988800000000ULL;                   // Sun Jun 15 12:00:00 2025 UTC

    (void)local_run(1U, argv);

    EXPECT_OUT_HAS("UTC time:    Sun Jun 15 12:00:00 2025\n");
    EXPECT_OUT_HAS("Local time:  Sun Jun 15 14:00:00 2025\n");  // CEST = UTC+2
}

TEST(date_argc1_dst_boundary) {
    const char_t    *argv[] = { "date" };

    ukos_t_begin(KTZ_CET);

// 31.03.2025 - DST started on the last Sunday of March (the 30th).

    (void)local_run(1U, argv);

    EXPECT_OUT_HAS("UTC time:    " KASC_T1);
    EXPECT_OUT_HAS("Local time:  Mon Mar 31 20:00:22 2025\n");
}

TEST(date_argc1_single_clock) {
    const char_t    *argv[] = { "date" };

    ukos_t_begin(KTZ_UTC);
    g_fakes.read.value = 42U;                                   // 42 us after the epoch

// The printed epoch and the printed date are both derived from the value the
// calendar returned, so they always describe the same instant. time() is never
// consulted.

    (void)local_run(1U, argv);

    EXPECT_OUT_HAS("Epoch = 42, UTC time:    Thu Jan  1 00:00:00 1970\n");
    EXPECT_EQ_U(g_fakes.timeCalls, 0U);
}

TEST(date_argc1_calendar_status_reported) {
    const char_t    *argv[] = { "date" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    g_fakes.read.rc       = -1;                                 // the manager reports an error
    g_fakes.read.writeOut = false;                              // ... and leaves *unixTime alone

    ukos_t_poisonStack();
    status = local_run(1U, argv);

// The failure is reported instead of printing whatever the uninitialised
// unixTime happened to hold.

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_U(g_fakes.read.calls, 1U);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Calendar not available.\n\n");
}

TEST(date_argc1_maximum_epoch_still_renders) {
    const char_t    *argv[] = { "date" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    g_fakes.read.value = UINT64_MAX;

    ukos_t_poisonStack();
    status = local_run(1U, argv);

// The largest value the calendar can return divides down to about year 586524,
// which a 64-bit time_t renders. date.c still checks gmtime_r(), localtime_r()
// and asctime() for NULL: a 32-bit time_t target truncates that division and
// can fail there, which this host cannot reproduce.

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_HAS("Epoch = 18446744073709551615, UTC time:");
}

TEST(date_asctime_format_selfcheck) {
    time_t  now = KUKOS_T_EPOCH;
    tm_t    utc;

    ukos_t_begin(KTZ_UTC);

// If a libc ever renders asctime() differently, this fails and points at the
// libc rather than at date.c.

    EXPECT_TRUE(gmtime_r(&now, &utc) != NULL);
    EXPECT_EQ_STR(asctime(&utc), KASC_T1);
}

// ============================================================================
// argc == 2  -  the -rtc flag
// ============================================================================

#if (KCALENDAR_WITH_HW_RTC_S == false)

TEST(date_argc2_rtc_unavailable) {
    const char_t    *argv[] = { "date", "-rtc" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "RTC not available.\n\n");
    EXPECT_EQ_U(g_fakes.read.calls, 0U);
}

TEST(date_argc2_rtc_space_terminated_match) {
    const char_t    *argv[] = { "date", "-rtc extra" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(2U, argv);

// text_checkAsciiBuffer() stops at the first space in argv[1], so a trailing
// remainder is accepted as a match. That is what lets the CLI compare a flag
// against a buffer still holding the rest of the line.

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "RTC not available.\n\n");
}

#endif

TEST(date_argc2_bad_flag) {
    const char_t    *argv[] = { "date", "-xyz" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect format.\n\n");
    EXPECT_EQ_U(g_fakes.read.calls, 0U);
}

TEST(date_argc2_prefix_only) {
    const char_t    *argv[] = { "date", "-rt" };

    ukos_t_begin(KTZ_UTC);
    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect format.\n\n");
}

TEST(date_argc2_superstring) {
    const char_t    *argv[] = { "date", "-rtcx" };

    ukos_t_begin(KTZ_UTC);
    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect format.\n\n");
}

TEST(date_argc2_empty) {
    const char_t    *argv[] = { "date", "" };

    ukos_t_begin(KTZ_UTC);
    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(date_argc2_case_sensitive) {
    const char_t    *argv[] = { "date", "-RTC" };

    ukos_t_begin(KTZ_UTC);
    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
}

TEST(date_argc2_gmt_flag_wrong_arity) {
    const char_t    *argv[] = { "date", "-gmt" };

    ukos_t_begin(KTZ_UTC);

// argc == 2 only ever compares against "-rtc", so -gmt without its operand is
// a format error and never reaches the calendar.

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.setUTC.calls, 0U);
}

// ============================================================================
// argc == 3  -  the -gmt flag
// ============================================================================

TEST(date_argc3_gmt_passes_the_operand) {
    const char_t    *argv[] = { "date", "-gmt", "GMT+1" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(3U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER "\n");
    EXPECT_EQ_U(g_fakes.setUTC.calls, 1U);

// The operand, never the flag: handing calendar_setUTCLocation() the string
// "-gmt" made it build the timezone "-gm-" instead of "GMT-1".

    EXPECT_EQ_PTR(g_fakes.setUTC.lastPtr, argv[2]);
    EXPECT_EQ_STR(&g_fakes.setUTC.lastCopy[0], "GMT+1");
}

TEST(date_argc3_argv2_is_what_reaches_the_calendar) {
    char_t          operand[] = "GMT-7";
    const char_t    *argv[]   = { "date", "-gmt", operand };

    ukos_t_begin(KTZ_UTC);

// A distinct operand, so a stale "GMT+1" from another case cannot make this
// pass by accident.

    (void)local_run(3U, argv);

    EXPECT_EQ_U(g_fakes.setUTC.calls, 1U);
    EXPECT_EQ_STR(&g_fakes.setUTC.lastCopy[0], "GMT-7");
}

TEST(date_argc3_bad_flag) {
    const char_t    *argv[] = { "date", "-xyz", "GMT+1" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(3U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect format.\n\n");
    EXPECT_EQ_U(g_fakes.setUTC.calls, 0U);
}

TEST(date_argc3_gmt_space_suffix) {
    const char_t    *argv[] = { "date", "-gmt junk", "GMT+1" };

    ukos_t_begin(KTZ_UTC);

// The flag still matches when argv[1] carries a trailing remainder, and it is
// the operand that is forwarded.

    EXPECT_EQ_I(local_run(3U, argv), KOK);
    EXPECT_EQ_U(g_fakes.setUTC.calls, 1U);
    EXPECT_EQ_STR(&g_fakes.setUTC.lastCopy[0], "GMT+1");
}

TEST(date_argc3_location_too_short) {
    const char_t    *argv[] = { "date", "-gmt", "UTC" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(3U, argv);

// calendar_setUTCLocation() overwrites index 3 of its copy, so a 3-character
// location would lose its terminator. Rejected before it gets there.

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect format.\n\n");
    EXPECT_EQ_U(g_fakes.setUTC.calls, 0U);
}

TEST(date_argc3_setUTC_status_reported) {
    const char_t    *argv[] = { "date", "-gmt", "GMT+1" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    g_fakes.setUTC.rc = -1;

    status = local_run(3U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Calendar not available.\n\n");
}

// ============================================================================
// argc == 7  -  set the date
// ============================================================================

TEST(date_argc7_nominal_utc) {
    const char_t    *argv[] = { "date", "31", "3", "2025", "18", "0", "22" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(7U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER "\n");
    EXPECT_EQ_U(g_fakes.write.calls, 1U);
    EXPECT_EQ_U(g_fakes.write.lastValue, 1743444022000000ULL);
    EXPECT_EQ_U(g_fakes.read.calls, 0U);
}

TEST(date_argc7_nominal_dst) {
    const char_t    *argv[] = { "date", "31", "3", "2025", "18", "0", "22" };

    ukos_t_begin(KTZ_CET);

// 18:00:22 CEST is 16:00:22 UTC - proves tm_isdst = -1 is resolved.

    EXPECT_EQ_I(local_run(7U, argv), KOK);
    EXPECT_EQ_U(g_fakes.write.lastValue, 1743436822000000ULL);
}

TEST(date_argc7_epoch_zero_boundary) {
    const char_t    *argv[] = { "date", "1", "1", "1970", "0", "0", "0" };

    ukos_t_begin(KTZ_UTC);

    EXPECT_EQ_I(local_run(7U, argv), KOK);
    EXPECT_EQ_U(g_fakes.write.calls, 1U);
    EXPECT_EQ_U(g_fakes.write.lastValue, 0ULL);
}

TEST(date_argc7_year_below_1970_rejected) {
    const char_t    *argv[] = { "date", "31", "12", "1969", "23", "59", "59" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(7U, argv);

// This instant is exactly epoch -1, which mktime() also uses to report a
// failure. Constraining the year to 1970..9999 removes the ambiguity - and the
// system time is an unsigned microsecond count, so pre-1970 is unrepresentable
// anyway.

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect format.\n\n");
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_year_1960_rejected) {
    const char_t    *argv[] = { "date", "1", "1", "1960", "0", "0", "0" };

    ukos_t_begin(KTZ_UTC);

// A negative epoch used to wrap: now * CLOCKS_PER_SEC was evaluated in the
// common type of time_t (signed) and clock_t (unsigned).

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_non_numeric) {
    const char_t    *argv[] = { "date", "x", "x", "x", "x", "x", "x" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(7U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect format.\n\n");
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_trailing_garbage_rejected) {
    const char_t    *argv[] = { "date", "31abc", "3", "2025", "18", "0", "22" };

    ukos_t_begin(KTZ_UTC);

// strtoul() stopped at 'a' and the end pointer was never inspected, so this
// used to be accepted as the 31st.

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_out_of_range_rejected) {
    const char_t    *argv[] = { "date", "99", "99", "9999", "99", "99", "99" };

    ukos_t_begin(KTZ_UTC);

// mktime() used to normalise this into a real instant and store it.

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_negative_field_rejected) {
    const char_t    *argv[] = { "date", "-5", "3", "2025", "18", "0", "22" };

    ukos_t_begin(KTZ_UTC);

// strtoul("-5") wrapped to ULONG_MAX-4 and the (int32_t) cast brought it back
// to -5, which mktime() then normalised backwards into February.

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_uint32_truncation_rejected) {
    const char_t    *argv[] = { "date", "4294967297", "3", "2025", "18", "0", "22" };

    ukos_t_begin(KTZ_UTC);

// 2^32 + 1 used to truncate to 1 through the (int32_t) cast.

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_empty_strings) {
    const char_t    *argv[] = { "date", "", "", "", "", "", "" };

    ukos_t_begin(KTZ_UTC);

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_impossible_date_rejected) {
    const char_t    *argv[] = { "date", "31", "2", "2025", "12", "0", "0" };

    ukos_t_begin(KTZ_UTC);

// Every field is in range, so only comparing mktime()'s normalised result back
// against the input catches this: 31 February would silently become 3 March.

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_leap_day_accepted) {
    const char_t    *argv[] = { "date", "29", "2", "2024", "12", "0", "0" };

    ukos_t_begin(KTZ_UTC);

// 2024 is a leap year, so the normalisation check must not reject this.

    EXPECT_EQ_I(local_run(7U, argv), KOK);
    EXPECT_EQ_U(g_fakes.write.calls, 1U);
    EXPECT_EQ_U(g_fakes.write.lastValue, 1709208000000000ULL);
}

TEST(date_argc7_leap_day_non_leap_year_rejected) {
    const char_t    *argv[] = { "date", "29", "2", "2025", "12", "0", "0" };

    ukos_t_begin(KTZ_UTC);

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_boundary_fields_accepted) {
    const char_t    *argv[] = { "date", "1", "1", "1970", "0", "0", "0" };

    ukos_t_begin(KTZ_UTC);

    EXPECT_EQ_I(local_run(7U, argv), KOK);
    EXPECT_EQ_U(g_fakes.write.lastValue, 0ULL);
}

TEST(date_argc7_second_60_rejected) {
    const char_t    *argv[] = { "date", "31", "12", "2016", "23", "59", "60" };

    ukos_t_begin(KTZ_UTC);

// Unix time does not represent leap seconds: mktime() folds 23:59:60 into the
// next day - here into the next year - so seconds stop at 59.

    EXPECT_EQ_I(local_run(7U, argv), KFAIL);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
}

TEST(date_argc7_calendar_status_reported) {
    const char_t    *argv[] = { "date", "31", "3", "2025", "18", "0", "22" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    g_fakes.write.rc = -1;

    status = local_run(7U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Calendar not available.\n\n");
}

TEST(date_argc7_tm_fully_initialised) {
    const char_t    *argv[] = { "date", "31", "3", "2025", "18", "0", "22" };
    uint64_t        poisoned;
    uint64_t        clean;

// The tm is cleared before use, so a poisoned stack cannot change the result.

    ukos_t_begin(KTZ_UTC);
    ukos_t_poisonStack();
    (void)local_run(7U, argv);
    poisoned = g_fakes.write.lastValue;

    ukos_t_begin(KTZ_UTC);
    (void)local_run(7U, argv);
    clean = g_fakes.write.lastValue;

    EXPECT_EQ_U(poisoned, clean);
    EXPECT_EQ_U(clean, 1743444022000000ULL);
}

// ============================================================================
// default arm  -  every other argc
// ============================================================================

static void local_expectInvalidArguments(uint32_t argc) {
    const char_t    *argv[] = { "date", "a", "b", "c", "d", "e", "f", "g", "h" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(argc, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect arguments.\n\n");
    EXPECT_EQ_U(g_fakes.read.calls, 0U);
    EXPECT_EQ_U(g_fakes.write.calls, 0U);
    EXPECT_EQ_U(g_fakes.setUTC.calls, 0U);
}

TEST(date_argc0_invalid)   { local_expectInvalidArguments(0U);   }
TEST(date_argc4_invalid)   { local_expectInvalidArguments(4U);   }
TEST(date_argc5_invalid)   { local_expectInvalidArguments(5U);   }
TEST(date_argc6_invalid)   { local_expectInvalidArguments(6U);   }
TEST(date_argc8_invalid)   { local_expectInvalidArguments(8U);   }
TEST(date_argc100_invalid) { local_expectInvalidArguments(100U); }

// ============================================================================
// RTC-enabled build only
// ============================================================================

#if (KCALENDAR_WITH_HW_RTC_S == true)

TEST(date_rtc_argc2_reads_rtc) {
    const char_t    *argv[] = { "date", "-rtc" };
    int32_t         status;

    ukos_t_begin(KTZ_UTC);
    status = local_run(2U, argv);

    ukos_t_commonInvariants(status, KBANNER);
    EXPECT_EQ_I(status, KOK);
    EXPECT_OUT_IS(KBANNER
                  "From RTC: Epoch = 1743444022204019, UTC time:    " KASC_T1
                  "From RTC: Epoch = 1743444022204019, Local time:  " KASC_T1
                  "\n");
    EXPECT_EQ_U(g_fakes.read.calls, 1U);
    EXPECT_EQ_I(g_fakes.read.lastFrom, KFROM_RTC);
}

TEST(date_rtc_argc2_bad_flag) {
    const char_t    *argv[] = { "date", "-xyz" };

    ukos_t_begin(KTZ_UTC);

    EXPECT_EQ_I(local_run(2U, argv), KFAIL);
    EXPECT_OUT_IS(KBANNER "Incorrect format.\n\n");
    EXPECT_EQ_U(g_fakes.read.calls, 0U);
}

TEST(date_rtc_argc1_unchanged) {
    const char_t    *argv[] = { "date" };

    ukos_t_begin(KTZ_UTC);

// Guards against the #if leaking into the argc == 1 arm.

    EXPECT_EQ_I(local_run(1U, argv), KOK);
    EXPECT_OUT_IS(KBANNER
                  "From timer: Epoch = 1743444022204019, UTC time:    " KASC_T1
                  "From timer: Epoch = 1743444022204019, Local time:  " KASC_T1
                  "\n");
    EXPECT_EQ_I(g_fakes.read.lastFrom, KFROM_TIMER);
}

TEST(date_rtc_no_unavailable_string) {
    const char_t    *argv[] = { "date", "-rtc" };

    ukos_t_begin(KTZ_UTC);
    (void)local_run(2U, argv);

    EXPECT_OUT_LACKS("RTC not available.");
}

TEST(date_rtc_metadata_identical) {

    ukos_t_begin(KTZ_UTC);

    EXPECT_EQ_U(aDate_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_DATE << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_EQ_U(aDate_Specifications.oFlag, (1U << BSHOW) | (1U << BEXE_CONSOLE));
    EXPECT_EQ_STR(aDate_Specifications.oStrRevision, " 1.1");
}

#endif
