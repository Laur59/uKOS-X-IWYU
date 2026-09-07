/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Generic entry point shared by every host test executable.
 */

#include    <stdbool.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>

#include    "ukos_test.h"
#include    "ukos_test_priv.h"

static void local_usage(const char *argv0) {

    (void)printf("usage: %s [--list] [--only <name>] [--filter <substring>] [--verbose]\n", argv0);
}

int main(int argc, char *argv[]) {
    const char  *only    = NULL;
    const char  *filter  = NULL;
    bool        list     = false;
    bool        verbose  = false;
    unsigned    passed   = 0U;
    unsigned    failed   = 0U;
    unsigned    selected = 0U;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--list") == 0) {
            list = true;
        }
        else if (strcmp(argv[i], "--verbose") == 0) {
            verbose = true;
        }
        else if ((strcmp(argv[i], "--only") == 0) && ((i + 1) < argc)) {
            i++;
            only = argv[i];
        }
        else if ((strcmp(argv[i], "--filter") == 0) && ((i + 1) < argc)) {
            i++;
            filter = argv[i];
        }
        else {
            local_usage(argv[0]);
            return 2;
        }
    }

    if (list) {
        for (unsigned i = 0U; i < g_nbCases; i++) {
            (void)printf("%s\n", g_cases[i].oName);
        }
        return 0;
    }

    ukos_t_initColours((isatty(1) == 1) && (getenv("NO_COLOR") == NULL));

// Announce the tier only when this invocation will run something, so a narrow
// --filter does not leave a trail of empty, labelled suites.

    for (unsigned i = 0U; i < g_nbCases; i++) {
        if (((only != NULL) && (strcmp(only, g_cases[i].oName) != 0))
         || ((filter != NULL) && (strstr(g_cases[i].oName, filter) == NULL))) {
            continue;
        }
        if (g_ukos_t_tierNote != NULL) {
            (void)printf("   %s\n", g_ukos_t_tierNote);
        }
        break;
    }

    for (unsigned i = 0U; i < g_nbCases; i++) {
        if ((only != NULL) && (strcmp(only, g_cases[i].oName) != 0)) {
            continue;
        }
        if ((filter != NULL) && (strstr(g_cases[i].oName, filter) == NULL)) {
            continue;
        }
        selected++;

        if (ukos_t_runOne(&g_cases[i], verbose)) {
            passed++;
        }
        else {
            failed++;
        }
    }

    if (selected == 0U) {
        if (filter != NULL) {
            return 0;                                   // this executable simply has no match
        }
        (void)fprintf(stderr, "ukos_test: no test matched\n");
        return 2;
    }

    ukos_t_summary(passed, failed);
    return ((failed != 0U) || (g_counters.oXpass != 0U)) ? 1 : 0;
}
