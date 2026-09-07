/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Internals shared between the harness and its generic main().
 */

#ifndef UKOS_TEST_PRIV_H
#define UKOS_TEST_PRIV_H

#include    <stdbool.h>

#include    "ukos_test.h"

#define KUKOS_T_MAX_CASES   256U
#define KUKOS_T_MAX_HOOKS   16U
#define KUKOS_T_MAX_TAGS    64U

typedef struct {
    const char      *oName;
    ukos_testFn_t   oFn;
} ukos_testCase_t;

typedef struct {
    unsigned    oChecks;
    unsigned    oFailedChecks;
    unsigned    oXfail;
    unsigned    oXpass;
} ukos_counters_t;

// One entry per distinct known-bug / quirk id, so the run can end with a tally
// instead of a flat list of repeated tags.

typedef struct {
    const char  *oId;
    const char  *oKind;
    unsigned    oHits;
    bool        oFixed;
} ukos_tag_t;

extern  ukos_testCase_t g_cases[KUKOS_T_MAX_CASES];
extern  unsigned        g_nbCases;
extern  ukos_counters_t g_counters;
extern  ukos_tag_t      g_tags[KUKOS_T_MAX_TAGS];
extern  unsigned        g_nbTags;

extern  void    ukos_t_initColours(bool enable);
extern  bool    ukos_t_runOne(const ukos_testCase_t *test, bool verbose);
extern  void    ukos_t_summary(unsigned passed, unsigned failed);

#endif
