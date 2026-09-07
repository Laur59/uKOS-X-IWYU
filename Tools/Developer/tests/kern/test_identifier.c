/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_kernels/kern/identifier.c.
 *
 * Tier 3, and the smallest possible one on purpose: identifier.c is the only
 * translation unit in the kernel with ZERO port coupling - no macros_core.h, no
 * macros_soc.h, no privilege or interrupt macros - so a failure here is
 * unambiguously the harness rather than a stub.
 *
 * One function, but not a trivial one to get right. identifiers_cmpStrings() is
 * a BOUNDED compare: it stops after KKERN_OBJECT_SZ_ID characters, and that
 * bound is the object-name buffer size INCLUDING the terminator (kern_types.h:144),
 * so it covers a full-length name and its '\0' exactly. Every kernel object is
 * looked up through it - kern_getMutexById, kern_getSemaphoreById,
 * kern_getMailboxById, kern_getPoolById, kern_getProcessById,
 * kern_getSoftwareTimerById - so a wrong answer here is a wrong handle there.
 */

#include    <stdbool.h>
#include    <stddef.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_identifiers.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

// The bound is the buffer size including '\0', so the longest name that can
// round-trip is one character shorter.

#define KMAX_NAME           (KKERN_OBJECT_SZ_ID - 1U)          // 30 characters

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");
}

/*
 * \brief Build a string of `len` copies of `fill`, then a terminator
 *
 */
static  void    local_fill(char_t *buffer, size_t len, char_t fill) {

    (void)memset(&buffer[0], fill, len);
    buffer[len] = '\0';
}

// Null handling
// =============

TEST(identifier_null_arguments_never_match) {
    local_setup();

    EXPECT_FALSE(identifiers_cmpStrings(nullptr, nullptr));
    EXPECT_FALSE(identifiers_cmpStrings(nullptr, "abc"));
    EXPECT_FALSE(identifiers_cmpStrings("abc", nullptr));

// Two null identifiers are NOT equal. That matters: an uninstalled object slot
// carries oIdentifier == nullptr (mutexes.c:60 and friends clear it), so a
// lookup for a null name must not match every free slot in the table.

    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Ordinary comparison
// ===================

TEST(identifier_equal_strings_match) {
    local_setup();

    EXPECT_TRUE(identifiers_cmpStrings("mutex", "mutex"));
    EXPECT_TRUE(identifiers_cmpStrings("", ""));
    EXPECT_TRUE(identifiers_cmpStrings("a", "a"));
}

TEST(identifier_different_strings_do_not_match) {
    local_setup();

    EXPECT_FALSE(identifiers_cmpStrings("mutex", "mutey"));     // differs at the last character
    EXPECT_FALSE(identifiers_cmpStrings("mutex", "nutex"));     // differs at the first
    EXPECT_FALSE(identifiers_cmpStrings("a", "b"));
}

TEST(identifier_comparison_is_case_sensitive) {
    local_setup();

    EXPECT_FALSE(identifiers_cmpStrings("Mutex", "mutex"));
    EXPECT_FALSE(identifiers_cmpStrings("MUTEX", "mutex"));
}

TEST(identifier_a_prefix_is_not_a_match) {
    local_setup();

// The loop returns (string_1[i] == string_2[i]) at the first terminator, so a
// prefix fails on '\0' vs 'd' rather than falling through to true.

    EXPECT_FALSE(identifiers_cmpStrings("abc", "abcd"));
    EXPECT_FALSE(identifiers_cmpStrings("abcd", "abc"));
    EXPECT_FALSE(identifiers_cmpStrings("", "a"));
    EXPECT_FALSE(identifiers_cmpStrings("a", ""));
}

// The bound
// =========

TEST(identifier_full_length_names_compare_completely) {
    char_t  a[KKERN_OBJECT_SZ_ID + 1];
    char_t  b[KKERN_OBJECT_SZ_ID + 1];

    local_setup();

    local_fill(&a[0], KMAX_NAME, 'x');
    local_fill(&b[0], KMAX_NAME, 'x');
    EXPECT_TRUE(identifiers_cmpStrings(&a[0], &b[0]));

// Differ in the very last character of the longest legal name: the bound must
// not stop one short of it.

    b[KMAX_NAME - 1U] = 'y';
    EXPECT_FALSE(identifiers_cmpStrings(&a[0], &b[0]));
}

TEST(identifier_names_differing_only_past_the_bound_collide) {
    char_t  a[64];
    char_t  b[64];

    local_setup();

// Over-long names - longer than the documented maximum. The compare stops after
// KKERN_OBJECT_SZ_ID characters, so these two are reported EQUAL although they
// differ. Reachable only by passing a name longer than the object-name buffer
// is meant to hold, which is a caller error rather than a kernel one; pinned
// because the consequence is silent (kern_getXxxById returns the wrong handle)
// rather than a rejected name. See DEFECTS.md.

    local_fill(&a[0], 40U, 'x');
    local_fill(&b[0], 40U, 'x');
    b[KKERN_OBJECT_SZ_ID] = 'y';                    // first character past the bound

    QUIRK("identifier-bounded-compare", identifiers_cmpStrings(&a[0], &b[0]));

// One character earlier - the last character the compare does look at - and
// they are correctly distinguished.

    b[KKERN_OBJECT_SZ_ID]      = 'x';
    b[KKERN_OBJECT_SZ_ID - 1U] = 'y';
    EXPECT_FALSE(identifiers_cmpStrings(&a[0], &b[0]));
}

TEST(identifier_reads_no_further_than_the_bound) {
    char_t  a[KKERN_OBJECT_SZ_ID];
    char_t  b[KKERN_OBJECT_SZ_ID];

    local_setup();

// Exactly KKERN_OBJECT_SZ_ID bytes, no terminator at all. The loop must stop on
// the count, not run off the end looking for a '\0'. Under -s this is the case
// that would report a stack-buffer-overflow if the bound were wrong.

    (void)memset(&a[0], 'z', sizeof(a));
    (void)memset(&b[0], 'z', sizeof(b));

    EXPECT_TRUE(identifiers_cmpStrings(&a[0], &b[0]));
}

// Symmetry
// ========

TEST(identifier_comparison_is_symmetric) {
    local_setup();

// Worth its own case because the function returns early on string_1's
// terminator, so the two arguments are not treated identically by the code even
// though the result must be.

    EXPECT_EQ_I(identifiers_cmpStrings("abc", "abcd"), identifiers_cmpStrings("abcd", "abc"));
    EXPECT_EQ_I(identifiers_cmpStrings("abc", "abc"),  identifiers_cmpStrings("abc", "abc"));
    EXPECT_EQ_I(identifiers_cmpStrings("", "a"),       identifiers_cmpStrings("a", ""));
}

// The tier itself
// ===============

TEST(identifier_takes_no_interrupt_mask) {
    local_setup();

// identifier.c is the one kernel file with no port coupling at all. Asserting
// it here means the counting fake is proven inert for this suite, so a later
// failure in another kern suite is that module's doing and not the fake's.

    EXPECT_TRUE(identifiers_cmpStrings("x", "x"));
    EXPECT_EQ_U(g_kernenv.oNbOff, 0U);
    EXPECT_EQ_U(g_kernenv.oNbRestore, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}
