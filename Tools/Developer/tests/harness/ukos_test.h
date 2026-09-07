/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Minimal host test harness: self-registering tests, EXPECT_* assertions and
 * known-bug tagging.
 */

#ifndef UKOS_TEST_H
#define UKOS_TEST_H

#include    <stdbool.h>
#include    <stddef.h>
#include    <string.h>

#include    "ukos_fakes.h"

// Registration
// ============
//
// A constructor registers the test at load time, so adding a test - or a whole
// new test file - needs no edit to any central list.

typedef void (*ukos_testFn_t)(void);

extern  void    ukos_t_register(const char *name, ukos_testFn_t fn);

#define TEST(name)                                                          \
    static void name(void);                                                 \
    __attribute__((constructor)) static void ukos_reg_##name(void) {        \
        ukos_t_register(#name, name);                                       \
    }                                                                       \
    static void name(void)

// Fixture
// =======
//
// Every test starts with ukos_t_begin(): it zeroes the fakes, re-seeds the
// defaults and pins the timezone. One entry point means no test can forget
// half of the reset.
//
// tzset() is mandatory, not decorative: POSIX does not require localtime_r()
// to call it, and Darwin does not.

#define KUKOS_T_EPOCH           ((time_t)1743444022)            // Mon Mar 31 18:00:22 2025 UTC
#define KUKOS_T_EPOCH_US        ((uint64_t)1743444022204019ULL)

extern  void    ukos_t_begin(const char *tz);

// Fakes that live outside the core support library register their own reset from
// a constructor, so ukos_t_begin() clears them without the harness having to
// know they exist.

extern  void    ukos_t_addResetHook(void (*fn)(void));

// Printed once under the suite name. Set by a constructor in the port library so
// a run against stub port headers is self-labelling.

extern  const char  *g_ukos_t_tierNote;

// Assertions
// ==========

extern  void    ukos_t_check  (bool ok, const char *file, int line, const char *expr, const char *note);
extern  void    ukos_t_check_i(long long a, long long b, const char *file, int line, const char *expr);
extern  void    ukos_t_check_u(unsigned long long a, unsigned long long b, const char *file, int line, const char *expr);
extern  void    ukos_t_check_p(const void *a, const void *b, const char *file, int line, const char *expr);
extern  void    ukos_t_check_s(const char *a, const char *b, const char *file, int line, const char *expr);

// Floats come in two flavours on purpose, and the pair must NOT be collapsed
// into one epsilon compare.
//
// Short arithmetic - a single activation kernel on one value - is bit-exact and
// reproducible, so it deserves EXPECT_EQ_F32: a last-bit change there means the
// arithmetic changed, which is the regression worth catching.
//
// Two things are NOT bit-reproducible and need a tolerance:
//
//   - anything through the host's libm (tanhf), because newlib's answer and
//     macOS's need not agree in the last bit;
//   - a LONG accumulation. A 74-element dot product gives different last bits
//     under -O0 and -O2, because FMA contraction changes how the sum rounds.
//     Measured, not assumed: the mlpn golden shifted by up to 3.5e-6 relative
//     between the two.
//
// Using EXPECT_NEAR_F32 where EXPECT_EQ_F32 would do throws away the strongest
// assertion available, so every use should say which of the two forced it.

extern  void    ukos_t_check_f(float a, float b, const char *file, int line, const char *expr);
extern  void    ukos_t_check_n(float a, float b, float tol, const char *file, int line, const char *expr);

#define EXPECT_TRUE(c)          ukos_t_check(!!(c), __FILE__, __LINE__, #c, "")
#define EXPECT_FALSE(c)         ukos_t_check(!(c), __FILE__, __LINE__, "!(" #c ")", "")
#define EXPECT_EQ_I(a, b)       ukos_t_check_i((long long)(a), (long long)(b), __FILE__, __LINE__, #a " == " #b)
#define EXPECT_EQ_U(a, b)       ukos_t_check_u((unsigned long long)(a), (unsigned long long)(b), __FILE__, __LINE__, #a " == " #b)
#define EXPECT_EQ_PTR(a, b)     ukos_t_check_p((const void *)(a), (const void *)(b), __FILE__, __LINE__, #a " == " #b)
#define EXPECT_NE_PTR(a, b)     ukos_t_check(((const void *)(a) != (const void *)(b)), __FILE__, __LINE__, #a " != " #b, "")
#define EXPECT_EQ_STR(a, b)     ukos_t_check_s((a), (b), __FILE__, __LINE__, #a " == " #b)
#define EXPECT_EQ_F32(a, b)     ukos_t_check_f((a), (b), __FILE__, __LINE__, #a " == " #b)
#define EXPECT_NEAR_F32(a, b, t) ukos_t_check_n((a), (b), (t), __FILE__, __LINE__, #a " ~= " #b)

#define EXPECT_OUT_IS(s)        ukos_t_check_s(&g_fakes.out[0], (s), __FILE__, __LINE__, "captured output")
#define EXPECT_OUT_HAS(s)       ukos_t_check((strstr(&g_fakes.out[0], (s)) != NULL), __FILE__, __LINE__, "output contains", (s))
#define EXPECT_OUT_LACKS(s)     ukos_t_check((strstr(&g_fakes.out[0], (s)) == NULL), __FILE__, __LINE__, "output does not contain", (s))

// Known bugs
// ==========
//
// cond true  -> the defect is still present: reported as XFAIL, does NOT fail
//               the suite.
// cond false -> the defect has been fixed: reported as XPASS and DOES fail the
//               suite, so whoever fixes it is forced to update the test rather
//               than leaving an assertion that no longer asserts anything.

extern  void    ukos_t_known(bool stillPresent, const char *id, const char *kind,
                             const char *file, int line, const char *expr);

#define KNOWN_BUG(id, cond)     ukos_t_known(!!(cond), (id), "KNOWN BUG", __FILE__, __LINE__, #cond)
#define QUIRK(id, cond)         ukos_t_known(!!(cond), (id), "QUIRK",    __FILE__, __LINE__, #cond)
#define OBSERVATION(id, cond)   ukos_t_known(!!(cond), (id), "NOTE",     __FILE__, __LINE__, #cond)

// Helpers
// =======
//
// poison_stack() fills the stack below the current frame with 0xA5 so that a
// subsequent call reading an uninitialised local sees a recognisable pattern.
// MSan is unavailable on Apple arm64, so this is a heuristic, not a proof.

extern  void    ukos_t_poisonStack(void);

// Invariants asserted on every prgm() call, in one place.

extern  void    ukos_t_commonInvariants(int32_t status, const char *banner);

#endif
