/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Contract tests for the kern tier's own fakes.
 *
 * Tier 3. These assert nothing about uKOS-X; they pin the behaviour that every
 * other kern suite then relies on. The interrupt fake in particular is a MIRROR
 * of Cores/CORTEX_M7/Includes/macros_core.h:166-176 rather than a copy of it, so
 * run-tests.sh cannot drift-check it the way it checks PRIVILEGE_ELEVATE. This
 * file is what keeps it honest instead - the same arrangement as
 * list_fake_directory_contract and x_fake_mailbox_contract in tier 1 and 2.
 *
 * The depth model is tested through ukos_fake_intOff() / ukos_fake_intRestore()
 * directly rather than through the macros, for one reason worth recording:
 * INTERRUPTION_OFF declares a variable called saveBASEPRI, so nesting two of
 * them in one function shadows it and -Wshadow (which this suite is built with,
 * and -Werror on top) rejects it. That is faithful to the target, where nesting
 * the macro would shadow exactly the same way - the kernel never does it. One
 * test below drives the macros as written to prove the shape compiles and pairs;
 * the rest exercise the model underneath.
 */

#include    <stdbool.h>
#include    <stdint.h>

#include    "macros_soc.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");
}

// The macro shape
// ===============

TEST(kern_fake_interrupt_macro_pairs) {
    local_setup();

    EXPECT_TRUE(ukos_fake_interruptsBalanced());

    {
        INTERRUPTION_OFF;
        EXPECT_EQ_U(g_kernenv.oDepth, 1U);
        EXPECT_FALSE(ukos_fake_interruptsBalanced());
        INTERRUPTION_RESTORE;
    }

    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
    EXPECT_EQ_U(g_kernenv.oNbOff, 1U);
    EXPECT_EQ_U(g_kernenv.oNbRestore, 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// The depth model
// ===============

TEST(kern_fake_interrupt_idle_is_balanced) {
    local_setup();

    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 0U);
    EXPECT_FALSE(g_kernenv.oUnbalanced);
    EXPECT_EQ_PTR(g_kernenv.oReason, nullptr);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(kern_fake_interrupt_nested_scopes_balance) {
    uint32_t    outer, inner;

    local_setup();

    outer = ukos_fake_intOff();
    inner = ukos_fake_intOff();

    EXPECT_EQ_U(outer, 0U);
    EXPECT_EQ_U(inner, 1U);
    EXPECT_EQ_U(g_kernenv.oDepth, 2U);
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 2U);

    ukos_fake_intRestore(inner);
    ukos_fake_intRestore(outer);

    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 2U);           // the high-water mark survives the unwind
}

// The three offences
// ==================
//
// Each is a real failure mode on a target: the first leaves interrupts masked
// for good, the second re-enables them from a stale saved mask, the third
// re-enables them early because the scopes overlap.

TEST(kern_fake_interrupt_missing_restore_is_caught) {
    local_setup();

    (void)ukos_fake_intOff();

    EXPECT_FALSE(ukos_fake_interruptsBalanced());
    EXPECT_EQ_U(g_kernenv.oDepth, 1U);
    EXPECT_EQ_STR(g_kernenv.oReason, "returned with INTERRUPTION_OFF still open");
}

TEST(kern_fake_interrupt_extra_restore_is_caught) {
    local_setup();

    ukos_fake_intRestore(0U);

    EXPECT_FALSE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(g_kernenv.oUnbalanced);
    EXPECT_EQ_STR(g_kernenv.oReason, "INTERRUPTION_RESTORE with no INTERRUPTION_OFF open");

// The depth must not go negative-by-wraparound: it is unsigned, and a stray
// restore that decremented it would make the NEXT test's balance check pass
// while one scope was still open.

    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
}

TEST(kern_fake_interrupt_out_of_order_is_caught) {
    uint32_t    outer, inner;

    local_setup();

    outer = ukos_fake_intOff();
    inner = ukos_fake_intOff();

    ukos_fake_intRestore(outer);                    // wrong: the inner scope is still open

    EXPECT_TRUE(g_kernenv.oUnbalanced);
    EXPECT_EQ_STR(g_kernenv.oReason, "INTERRUPTION_RESTORE out of order (scopes do not unwind LIFO)");

// Latched: closing the second scope correctly must not clear the offence.

    ukos_fake_intRestore(inner);
    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
    EXPECT_FALSE(ukos_fake_interruptsBalanced());
}

TEST(kern_fake_interrupt_reason_keeps_the_first_offence) {
    local_setup();

    ukos_fake_intRestore(0U);                       // offence 1
    (void)ukos_fake_intOff();                       // leaves a scope open: offence 2

    EXPECT_EQ_STR(g_kernenv.oReason, "INTERRUPTION_RESTORE with no INTERRUPTION_OFF open");
}

TEST(kern_fake_interrupt_state_is_reset_between_tests) {
    local_setup();

// If the reset hook were not registered, the offence latched by the test above
// would still be set here and every later suite would report a false failure.

    EXPECT_FALSE(g_kernenv.oUnbalanced);
    EXPECT_EQ_PTR(g_kernenv.oReason, nullptr);
    EXPECT_EQ_U(g_kernenv.oNbOff, 0U);
    EXPECT_EQ_U(g_kernenv.oNbRestore, 0U);
}

// The float assertions
// ====================
//
// Shared harness machinery rather than a kern fake, but pinned here because
// this is where the suite's own contracts live and mlpn is the first module to
// depend on them.
//
// Only the PASSING direction is testable: making EXPECT_EQ_F32 fail on purpose
// would fail this suite. The failing direction is proven instead by the mlpn
// mutation runs, where changing an activation constant has to turn the suite
// red - which is a stronger check than a self-test could be anyway.

TEST(kern_fake_float_assertions_compare_as_documented) {
    local_setup();

// Bit-exact: the same value, and a value reconstructed by arithmetic that must
// land on the same bits.

    EXPECT_EQ_F32(1.5F, 1.5F);
    EXPECT_EQ_F32(0.5F + 0.25F, 0.75F);                 // both exact in binary32
    EXPECT_EQ_F32(-0.0F, 0.0F);                         // IEEE says these compare equal

// Tolerance, and symmetric in its arguments - the difference is taken either
// way round, so an implementation that only handled a > b would fail one of
// these two.

    EXPECT_NEAR_F32(1.0F, 1.05F, 0.1F);
    EXPECT_NEAR_F32(1.05F, 1.0F, 0.1F);

// A zero tolerance degenerates to equality rather than always passing.

    EXPECT_NEAR_F32(2.0F, 2.0F, 0.0F);
}

// The running core
// ================

TEST(kern_fake_runningCore_defaults_to_zero_and_is_settable) {
    local_setup();

    EXPECT_EQ_U(GET_RUNNING_CORE, 0U);

    ukos_fake_setRunningCore(1U);
    EXPECT_EQ_U(GET_RUNNING_CORE, 1U);

    ukos_t_begin("UTC0");
    EXPECT_EQ_U(GET_RUNNING_CORE, 0U);              // and the reset puts it back
}
