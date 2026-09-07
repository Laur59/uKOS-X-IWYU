/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_kernels/kern/lists.c.
 *
 * Tier 3. The doubly-linked intrusive process list every kernel object waits on:
 * mutexes, semaphores, mailboxes and signals all own a list_t and connect
 * processes to it, and the scheduler walks vKern_listExec. It is a pure function
 * of its arguments - no globals, no per-core tables, no allocation - which makes
 * it the cleanest thing in the kernel to test and the one with the widest blast
 * radius if it is wrong.
 *
 * The whole behavioural surface is the six-state switch in local_nextAction()
 * (lists.c:100-107): EMPTY and NORMAL on the way in, ALONE / FIRST / MIDDLE /
 * LAST on the way out. That function is static, but every state is reachable
 * through the two public entry points by building lists of one, two and three
 * elements and unlinking from each position, so this suite does not need to
 * #include the .c.
 *
 * Each test asserts twice over: the individual link fields, and then a full walk
 * of the chain from oFirst to the terminator. The walk is the guard that catches
 * a defect leaving the list self-consistent at the ends but broken in between -
 * which is exactly what a wrong MIDDLE arm would do.
 *
 * Deliberately NOT tested: the two nullptr paths (lists.c:151, 211). Both LOG and
 * then exit(EXIT_OS_PANIC), and the harness has no death-test facility - a fork
 * would have to be added for a branch whose whole content is a panic. The fake
 * record_log is in place so they link, and g_kernenv.oNbLog stays zero
 * throughout, which is asserted.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_lists.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

// Four processes is one more than the smallest list that has a genuine MIDDLE.

static  proc_t      vProc[4];
static  list_t      vListA;
static  list_t      vListB;

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    (void)memset(&vProc[0], 0, sizeof(vProc));
    lists_initialise(&vListA);
    lists_initialise(&vListB);
}

/*
 * \brief Assert a list holds exactly `n` processes, in order
 *
 * - Checks the ends, then walks the chain forwards checking both link
 *   directions at every step, then checks the walk terminates after exactly
 *   `n` hops. Interrupt balance is folded in, because every public entry point
 *   of lists.c takes the mask and every one of them must give it back.
 *
 */
static  void    local_expectChain(list_t *list, proc_t * const expected[], uint16_t n) {
            uint16_t    i;
    const   proc_t      *walk;

    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_EQ_U(list->oNbElements, n);

    if (n == 0U) {
        EXPECT_EQ_PTR(list->oFirst, nullptr);
        EXPECT_EQ_PTR(list->oLast,  nullptr);
        return;
    }

    EXPECT_EQ_PTR(list->oFirst, expected[0]);
    EXPECT_EQ_PTR(list->oLast,  expected[n - 1U]);

    walk = list->oFirst;
    for (i = 0U; i < n; i++) {
        EXPECT_EQ_PTR(walk, expected[i]);
        if (walk == nullptr) {
            return;                                     // broken chain; the mismatch above says so
        }

        EXPECT_EQ_PTR(walk->oObject.oList,    list);
        EXPECT_EQ_PTR(walk->oObject.oBack,    (i == 0U)          ? nullptr : expected[i - 1U]);
        EXPECT_EQ_PTR(walk->oObject.oForward, (i == (n - 1U))    ? nullptr : expected[i + 1U]);

        walk = walk->oObject.oForward;
    }
    EXPECT_EQ_PTR(walk, nullptr);                       // exactly n hops, not n+1
}

// Initialisation
// ==============

TEST(lists_initialise_gives_an_empty_list) {
    proc_t  *const none[1] = { nullptr };

    local_setup();

    local_expectChain(&vListA, none, 0U);

// lists_initialise touches no mask - it is the one entry point that does not.

    EXPECT_EQ_U(g_kernenv.oNbOff, 0U);
}

// Connect - the two inbound states
// ================================

TEST(lists_connect_to_an_empty_list) {
    proc_t  *const want[1] = { &vProc[0] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);

    local_expectChain(&vListA, want, 1U);
    EXPECT_EQ_U(g_kernenv.oNbOff, 1U);                  // and it did take the mask
}

TEST(lists_connect_appends_at_the_end) {
    proc_t  *const want[3] = { &vProc[0], &vProc[1], &vProc[2] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);
    lists_connect(&vListA, &vProc[2]);

    local_expectChain(&vListA, want, 3U);
}

// Disconnect - the four outbound states
// =====================================
//
// lists_disconnectConnect dispatches on the HANDLE's own links, not on the
// list it is leaving (lists.c:216-221), so each of these builds the topology
// that selects the arm under test.

TEST(lists_disconnect_the_only_element) {
    proc_t  *const empty[1] = { nullptr };
    proc_t  *const want[1]  = { &vProc[0] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_disconnectConnect(&vListA, &vListB, &vProc[0]);       // KLIST_ALONE

    local_expectChain(&vListA, empty, 0U);
    local_expectChain(&vListB, want,  1U);
}

TEST(lists_disconnect_the_first) {
    proc_t  *const rest[2] = { &vProc[1], &vProc[2] };
    proc_t  *const moved[1] = { &vProc[0] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);
    lists_connect(&vListA, &vProc[2]);

    lists_disconnectConnect(&vListA, &vListB, &vProc[0]);       // KLIST_FIRST

    local_expectChain(&vListA, rest,  2U);
    local_expectChain(&vListB, moved, 1U);
}

TEST(lists_disconnect_the_middle) {
    proc_t  *const rest[2]  = { &vProc[0], &vProc[2] };
    proc_t  *const moved[1] = { &vProc[1] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);
    lists_connect(&vListA, &vProc[2]);

    lists_disconnectConnect(&vListA, &vListB, &vProc[1]);       // KLIST_MIDDLE

// The ends are untouched by this arm, so the chain walk is what proves it: only
// a correct MIDDLE joins vProc[0] and vProc[2] to each other in BOTH directions.

    local_expectChain(&vListA, rest,  2U);
    local_expectChain(&vListB, moved, 1U);
}

TEST(lists_disconnect_the_last) {
    proc_t  *const rest[2]  = { &vProc[0], &vProc[1] };
    proc_t  *const moved[1] = { &vProc[2] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);
    lists_connect(&vListA, &vProc[2]);

    lists_disconnectConnect(&vListA, &vListB, &vProc[2]);       // KLIST_LAST

    local_expectChain(&vListA, rest,  2U);
    local_expectChain(&vListB, moved, 1U);
}

// Whole-list behaviour
// ====================

TEST(lists_moving_every_element_out_empties_the_source) {
    proc_t  *const empty[1] = { nullptr };
    proc_t  *const want[3]  = { &vProc[1], &vProc[2], &vProc[0] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);
    lists_connect(&vListA, &vProc[2]);

// Out in an order that walks three different arms of the switch: MIDDLE while
// three are linked, LAST once only two are left, then ALONE.

    lists_disconnectConnect(&vListA, &vListB, &vProc[1]);       // MIDDLE
    lists_disconnectConnect(&vListA, &vListB, &vProc[2]);       // LAST of the pair
    lists_disconnectConnect(&vListA, &vListB, &vProc[0]);       // ALONE

    local_expectChain(&vListA, empty, 0U);
    local_expectChain(&vListB, want,  3U);
}

TEST(lists_moving_within_one_list_rotates_to_the_end) {
    proc_t  *const want[3] = { &vProc[1], &vProc[2], &vProc[0] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);
    lists_connect(&vListA, &vProc[2]);

// list_d == list_c. The count is decremented and re-incremented around one
// handle, so it must come out unchanged - and the head must advance.

    lists_disconnectConnect(&vListA, &vListA, &vProc[0]);

    local_expectChain(&vListA, want, 3U);
}

TEST(lists_a_disconnected_handle_carries_no_stale_links) {
    proc_t  *const want[2] = { &vProc[1], &vProc[0] };

    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);

    lists_disconnectConnect(&vListA, &vListB, &vProc[0]);

// Both link fields are cleared before the reconnect (lists.c:226-228), which is
// what lets the next lists_disconnectConnect dispatch correctly: the handle is
// now ALONE in vListB and must be seen as such, not as the FIRST it used to be.

    EXPECT_EQ_PTR(vProc[0].oObject.oBack,    nullptr);
    EXPECT_EQ_PTR(vProc[0].oObject.oForward, nullptr);
    EXPECT_EQ_PTR(vProc[0].oObject.oList,    &vListB);

    lists_disconnectConnect(&vListB, &vListA, &vProc[0]);       // must take ALONE, not FIRST

    EXPECT_EQ_U(vListB.oNbElements, 0U);
    local_expectChain(&vListA, want, 2U);                       // appended, so it is last now
}

TEST(lists_connect_clears_a_stale_forward_link) {
    proc_t  *const one[1] = { &vProc[0] };
    proc_t  *const two[2] = { &vProc[0], &vProc[1] };

    local_setup();

// local_nextAction touches oForward on NEITHER inbound arm: KLIST_EMPTY sets
// only oFirst/oLast/oBack, and KLIST_NORMAL sets the PREVIOUS last's oForward,
// not this handle's. The clear at lists.c:162 is therefore what stops a handle
// carrying a stale forward pointer into a list it has just joined.
//
// Every other test here reaches lists_connect with oForward already nullptr -
// memset by the fixture, or cleared by lists_disconnectConnect - so the clear
// looks like dead code and a mutation removing it survived. This is the case
// that distinguishes it: a descriptor that has never been in a list, holding
// whatever its memory held.

    vProc[0].oObject.oForward = &vProc[3];
    lists_connect(&vListA, &vProc[0]);
    local_expectChain(&vListA, one, 1U);

    vProc[1].oObject.oForward = &vProc[3];
    lists_connect(&vListA, &vProc[1]);
    local_expectChain(&vListA, two, 2U);
}

// The tier
// ========

TEST(lists_never_logs_on_a_valid_path) {
    local_setup();

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);
    lists_disconnectConnect(&vListA, &vListB, &vProc[0]);

// LOG() is reached only from the two nullptr panics, which are not driven here.
// If this ever trips, a valid path has started logging a fatal.

    EXPECT_EQ_U(g_kernenv.oNbLog, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(lists_every_entry_point_gives_the_mask_back) {
    local_setup();

// Both public entry points take INTERRUPTION_OFF and must restore it on their
// single return path. Counted rather than assumed: the pair count has to match
// the number of calls that mask, which is every one of these but the initialise.

    lists_connect(&vListA, &vProc[0]);
    lists_connect(&vListA, &vProc[1]);
    lists_connect(&vListA, &vProc[2]);
    lists_disconnectConnect(&vListA, &vListB, &vProc[1]);
    lists_disconnectConnect(&vListB, &vListA, &vProc[1]);

    EXPECT_EQ_U(g_kernenv.oNbOff, 5U);
    EXPECT_EQ_U(g_kernenv.oNbRestore, 5U);
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 1U);               // never nested
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}
