/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Minimal host test harness: registry, assertions, reporting.
 */

#include    "ukos_test.h"

#include    <stdbool.h>
#include    <stdint.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <time.h>

#include    "exit_codes.h"
#include    "serial/serial.h"
#include    "ukos_fakes.h"
#include    "ukos_test_priv.h"

ukos_testCase_t     g_cases[KUKOS_T_MAX_CASES];
unsigned            g_nbCases;
ukos_counters_t     g_counters;
ukos_tag_t          g_tags[KUKOS_T_MAX_TAGS];
unsigned            g_nbTags;

const char          *g_ukos_t_tierNote;

static  void        (*vResetHooks[KUKOS_T_MAX_HOOKS])(void);
static  unsigned    vNbResetHooks;

static  bool        vCurrentFailed;
static  const char  *vCurrentName;
static  bool        vHeaderPrinted;

// Colours, disabled when stdout is not a terminal or NO_COLOR is set.

static  const char  *vRed    = "";
static  const char  *vGreen  = "";
static  const char  *vYellow = "";
static  const char  *vDim    = "";
static  const char  *vBold   = "";
static  const char  *vOff    = "";

void ukos_t_initColours(bool enable) {

    if (enable) {
        vRed = "\033[31m"; vGreen = "\033[32m"; vYellow = "\033[33m";
        vDim = "\033[2m";  vBold  = "\033[1m"; vOff = "\033[0m";
    }
}

void ukos_t_register(const char *name, ukos_testFn_t fn) {

    if (g_nbCases >= KUKOS_T_MAX_CASES) {
        (void)fprintf(stderr, "ukos_test: too many test cases (max %u)\n", (unsigned)KUKOS_T_MAX_CASES);
        exit(EXIT_FAILURE);
    }
    g_cases[g_nbCases].oName = name;
    g_cases[g_nbCases].oFn   = fn;
    g_nbCases++;
}

void ukos_t_addResetHook(void (*fn)(void)) {

    if (vNbResetHooks >= KUKOS_T_MAX_HOOKS) {
        (void)fprintf(stderr, "ukos_test: too many reset hooks\n");
        exit(EXIT_FAILURE);
    }
    vResetHooks[vNbResetHooks] = fn;
    vNbResetHooks++;
}

void ukos_t_begin(const char *tz) {

    (void)memset(&g_fakes, 0, sizeof g_fakes);

    for (unsigned i = 0U; i < vNbResetHooks; i++) {
        vResetHooks[i]();
    }

    g_fakes.read.rc       = 0;
    g_fakes.read.writeOut = true;
    g_fakes.read.value    = KUKOS_T_EPOCH_US;
    g_fakes.write.rc      = 0;
    g_fakes.setUTC.rc     = 0;
    g_fakes.random.rc       = 0;
    g_fakes.random.writeOut = true;
    g_fakes.random.seed     = 1000U;
    g_fakes.random.step     = 1U;
    g_fakes.timeRet       = KUKOS_T_EPOCH;

    if (setenv("TZ", tz, 1) != 0) {
        (void)fprintf(stderr, "ukos_test: setenv(TZ) failed\n");
        exit(EXIT_FAILURE);
    }
    tzset();
}

// Reporting
// =========

// The test name is printed only once, and only when that test has something to
// say. A quiet test stays quiet; a test that reports a known bug or a failure
// gets a header, so a tag is never orphaned from the case that produced it.

static void local_ensureHeader(void) {

    if (!vHeaderPrinted) {
        vHeaderPrinted = true;
        (void)printf("   %s%s%s\n", vDim, (vCurrentName != NULL) ? vCurrentName : "?", vOff);
    }
}

static void local_fail(const char *file, int line, const char *expr) {

    local_ensureHeader();
    vCurrentFailed = true;
    g_counters.oFailedChecks++;
    (void)printf("      %sFAIL%s %s:%d\n           %s\n", vRed, vOff, file, line, expr);
}

// Print a string with the escapes visible, so a multi-line golden mismatch is
// readable instead of scrolling the terminal.

static void local_printEscaped(const char *label, const char *s) {

    (void)printf("           %s \"", label);

    if (s == NULL) {
        (void)printf("<NULL>\"\n");
        return;
    }

    for (const char *p = s; *p != '\0'; p++) {
        switch (*p) {
            case '\n': { (void)printf("\\n"); break; }
            case '\r': { (void)printf("\\r"); break; }
            case '\t': { (void)printf("\\t"); break; }
            case '"':  { (void)printf("\\\""); break; }
            default:   { (void)putchar(*p);  break; }
        }
    }
    (void)printf("\"\n");
}

void ukos_t_check(bool ok, const char *file, int line, const char *expr, const char *note) {

    g_counters.oChecks++;

    if (!ok) {
        local_fail(file, line, expr);
        if ((note != NULL) && (note[0] != '\0')) {
            local_printEscaped("note:    ", note);
        }
    }
}

void ukos_t_check_i(long long a, long long b, const char *file, int line, const char *expr) {

    g_counters.oChecks++;

    if (a != b) {
        local_fail(file, line, expr);
        (void)printf("           actual:   %lld\n           expected: %lld\n", a, b);
    }
}

void ukos_t_check_u(unsigned long long a, unsigned long long b, const char *file, int line, const char *expr) {

    g_counters.oChecks++;

    if (a != b) {
        local_fail(file, line, expr);
        (void)printf("           actual:   %llu\n           expected: %llu\n", a, b);
    }
}

void ukos_t_check_p(const void *a, const void *b, const char *file, int line, const char *expr) {

    g_counters.oChecks++;

    if (a != b) {
        local_fail(file, line, expr);
        (void)printf("           actual:   %p\n           expected: %p\n", a, b);
    }
}

/*
 * \brief Bit-exact float comparison
 *
 * - Deliberately ==, not an epsilon. See the note in ukos_test.h. NaN never
 *   equals itself, so a NaN on either side fails, which is the right answer
 *   here: mlpn producing a NaN is the defect, not a rounding difference.
 *
 *   Printed with %.9g, the shortest form that round-trips a binary32, so a
 *   last-bit difference is visible in the diagnostic rather than showing two
 *   identical-looking numbers.
 */
void ukos_t_check_f(float a, float b, const char *file, int line, const char *expr) {

    g_counters.oChecks++;

    if (!(a == b)) {
        local_fail(file, line, expr);
        (void)printf("           actual:   %.9g\n           expected: %.9g\n", (double)a, (double)b);
    }
}

/*
 * \brief Float comparison within a tolerance
 *
 * - For values that pass through the host's libm and so need not match the
 *   target's last bit. The tolerance is absolute and explicit at every call
 *   site rather than a global epsilon, because what counts as close depends on
 *   the magnitude of the value under test.
 */
void ukos_t_check_n(float a, float b, float tol, const char *file, int line, const char *expr) {
    float   diff;

    g_counters.oChecks++;

    diff = (a > b) ? (a - b) : (b - a);

    if (!(diff <= tol)) {
        local_fail(file, line, expr);
        (void)printf("           actual:   %.9g\n           expected: %.9g +/- %.9g\n",
                     (double)a, (double)b, (double)tol);
    }
}

void ukos_t_check_s(const char *a, const char *b, const char *file, int line, const char *expr) {

    g_counters.oChecks++;

    if ((a == NULL) || (b == NULL) || (strcmp(a, b) != 0)) {
        local_fail(file, line, expr);
        local_printEscaped("actual:  ", a);
        local_printEscaped("expected:", b);
    }
}

static void local_recordTag(const char *id, const char *kind, bool fixed) {

    for (unsigned i = 0U; i < g_nbTags; i++) {
        if (strcmp(g_tags[i].oId, id) == 0) {
            g_tags[i].oHits++;
            if (fixed) {
                g_tags[i].oFixed = true;
            }
            return;
        }
    }

    if (g_nbTags < KUKOS_T_MAX_TAGS) {
        g_tags[g_nbTags].oId    = id;
        g_tags[g_nbTags].oKind  = kind;
        g_tags[g_nbTags].oHits  = 1U;
        g_tags[g_nbTags].oFixed = fixed;
        g_nbTags++;
    }
}

void ukos_t_known(bool stillPresent, const char *id, const char *kind,
                  const char *file, int line, const char *expr) {

    g_counters.oChecks++;
    local_ensureHeader();
    local_recordTag(id, kind, !stillPresent);

    if (stillPresent) {
        g_counters.oXfail++;
        (void)printf("      %s%s%s %s\n", vYellow, kind, vOff, id);
    }
    else {
        vCurrentFailed = true;
        g_counters.oXpass++;
        (void)printf("      %sFIXED%s %s  (%s:%d)\n", vRed, vOff, id, file, line);
        (void)printf("           %s no longer holds - update or remove this expectation\n", expr);
    }
}

__attribute__((noinline)) void ukos_t_poisonStack(void) {
    volatile unsigned char  buffer[4096];

    for (size_t i = 0U; i < sizeof buffer; i++) {
        buffer[i] = 0xA5U;
    }
}

void ukos_t_commonInvariants(int32_t status, const char *banner) {

    EXPECT_TRUE((status == EXIT_OS_SUCCESS_CLI) || (status == EXIT_OS_FAILURE));
    EXPECT_FALSE(g_fakes.outTruncated);
    EXPECT_FALSE(g_fakes.outError);
    EXPECT_TRUE(strncmp(&g_fakes.out[0], banner, strlen(banner)) == 0);

    for (unsigned i = 0U; (i < g_fakes.dprintfCalls) && (i < KUKOS_FAKE_MAX_CALLS); i++) {
        EXPECT_EQ_U(g_fakes.dprintfManager[i], (uint32_t)KSYST);
    }
}

// Runner
// ======

bool ukos_t_runOne(const ukos_testCase_t *test, bool verbose) {

    vCurrentFailed = false;
    vCurrentName   = test->oName;
    vHeaderPrinted = false;

    if (verbose) {
        local_ensureHeader();
    }

    test->oFn();

    if (vCurrentFailed) {
        (void)printf("   %s^ FAILED%s\n", vRed, vOff);
    }
    else if (verbose && !vHeaderPrinted) {
        (void)printf("   %s%s%s %sok%s\n", vDim, test->oName, vOff, vGreen, vOff);
    }
    else {
        // a passing test with nothing to report stays silent
    }
    return !vCurrentFailed;
}

void ukos_t_summary(unsigned passed, unsigned failed) {

    (void)printf("\n");

    if (g_nbTags != 0U) {
        (void)printf("   %sBehaviour asserted but not desired%s\n", vBold, vOff);

        for (unsigned i = 0U; i < g_nbTags; i++) {
            if (g_tags[i].oFixed) {
                (void)printf("      %sFIXED%s     %-40s %u assertion(s) - update the tests\n",
                             vRed, vOff, g_tags[i].oId, g_tags[i].oHits);
            }
            else {
                (void)printf("      %s%-9s%s %-40s %u assertion(s)\n",
                             vYellow, g_tags[i].oKind, vOff, g_tags[i].oId, g_tags[i].oHits);
            }
        }
        (void)printf("\n");
    }

    if ((failed == 0U) && (g_counters.oXpass == 0U)) {
        (void)printf("   %s%u passed%s", vGreen, passed, vOff);
    }
    else {
        (void)printf("   %u passed", passed);
    }

    if (failed != 0U) {
        (void)printf(", %s%u failed%s", vRed, failed, vOff);
    }
    else {
        (void)printf(", 0 failed");
    }

    (void)printf(", %u assertions", g_counters.oChecks);
    (void)printf(", %s%u known-bug assertion(s) still holding%s", vYellow, g_counters.oXfail, vOff);

    if (g_counters.oXpass != 0U) {
        (void)printf(", %s%u FIXED (update the tests)%s", vRed, g_counters.oXpass, vOff);
    }
    (void)printf("\n");
}
