/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_kernels/kern/statistics.c.
 *
 * Tier 3. One function, called from scheduler.c on every context switch, whose
 * whole content is unsigned arithmetic over three durations: the process time,
 * the uKernel time and the exception time. It feeds the per-process figures the
 * `process` CLI prints, so a defect here is invisible until somebody trusts a
 * number.
 *
 * Nothing here is timing-dependent: the five arguments ARE the clock, so the
 * host runs the same arithmetic the target does.
 *
 * Two behaviours are pinned as QUIRKs rather than asserted as correct, both
 * documented at statistics.c:80-84 or evident from the code:
 *
 *   - a sample above 65535 becomes 0, not 65535. Deliberate ("to avoid wrong
 *     max"), but it means one long sample resets the minimum rather than being
 *     ignored.
 *   - the clamp applies to Min/Max only. Avg and Cum are fed the full unclamped
 *     32-bit value, so an over-long sample that shows as 0 in the min/max
 *     columns still moves the average.
 *
 * The whole file is compiled out unless KKERN_WITH_STATISTICS_S, which defaults
 * to true (kern_types.h:76). There is nothing to test in the other arm - the
 * translation unit is then empty - so this suite is built once.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

#define KNMEAN              3U
#define KAVG_WEIGHT         ((1U << KNMEAN) - 1U)               // 7

static  proc_t      vBackward;
static  proc_t      vRunning;

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    (void)memset(&vBackward, 0, sizeof(vBackward));
    (void)memset(&vRunning,  0, sizeof(vRunning));

    ukos_fake_setRunningProcess(&vRunning);
}

/*
 * \brief One switch, expressed the way the scheduler expresses it
 *
 * - timeP = stop - lastStart, timeK = start - stop, timeE given directly.
 *   Building the arguments from the durations keeps the tests readable and
 *   makes the subtraction under test explicit rather than implied.
 *
 */
static  void    local_switch(uint32_t timeP, uint32_t timeK, uint32_t timeE) {
    uint32_t    lastStart, stop, start;

    lastStart = 1000U;
    stop      = lastStart + timeP;
    start     = stop + timeK;

    statistics_statistic(&vBackward, start, stop, lastStart, timeE);
}

// The seeding call
// ================

TEST(statistics_first_sample_seeds_min_max_and_average) {
    local_setup();

    local_switch(100U, 20U, 0U);

    EXPECT_EQ_U(vBackward.oStatistic.oTimePMin, 100U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimePMax, 100U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimeKMin, 20U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimeKMax, 20U);

// The average is seeded to the sample and THEN immediately run through the
// filter, so even the first call is not simply the sample: (100*7 + 100)/8.

    EXPECT_EQ_U(vBackward.oStatistic.oTimePAvg, ((100U * KAVG_WEIGHT) + 100U) >> KNMEAN);
    EXPECT_EQ_U(vBackward.oStatistic.oTimeKAvg, ((20U  * KAVG_WEIGHT) + 20U)  >> KNMEAN);
}

// Min and max tracking
// ====================

TEST(statistics_max_rises_and_min_falls) {
    local_setup();

    local_switch(100U, 10U, 0U);
    local_switch(300U, 30U, 0U);
    local_switch(50U,  5U,  0U);

    EXPECT_EQ_U(vBackward.oStatistic.oTimePMin, 50U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimePMax, 300U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimeKMin, 5U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimeKMax, 30U);
}

TEST(statistics_a_zero_minimum_is_not_sticky) {
    local_setup();

    local_switch(100U, 10U, 0U);
    local_switch(0U,   10U, 0U);                                // a genuine zero-length slice

// oTimePMin == 0 is the "never set" sentinel, so a real zero cannot be stored:
// the next sample overwrites it whatever its value. The minimum therefore
// tracks the last sample rather than the smallest, once a zero has been seen.

    EXPECT_EQ_U(vBackward.oStatistic.oTimePMin, 0U);

    local_switch(900U, 10U, 0U);
    QUIRK("statistics-zero-min-sentinel", (vBackward.oStatistic.oTimePMin == 900U));
}

// The 16-bit guard
// ================

TEST(statistics_a_sample_above_65535_is_recorded_as_zero) {
    local_setup();

    local_switch(70000U, 10U, 0U);

// Not saturated to 65535 - deliberately zeroed (statistics.c:80-84), because
// the first switch after boot produces a meaningless huge value and a saturating
// clamp would pin the maximum at 65535 forever.

    EXPECT_EQ_U(vBackward.oStatistic.oTimePMax, 0U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimePMin, 0U);
}

TEST(statistics_the_65535_boundary_is_inclusive) {
    local_setup();

    local_switch(65535U, 10U, 0U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimePMax, 65535U);        // exactly at the bound: kept

    local_setup();
    local_switch(65536U, 10U, 0U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimePMax, 0U);            // one past it: zeroed

// No test can distinguish `> 65535U` from `> 65536U` here, and none should try:
// the two differ only for timeP32 == 65536, and (uint16_t)65536 is 0 - which is
// exactly what the clamp itself produces. Mutating the bound upwards is a
// provable equivalent mutant, not a coverage gap.
}

TEST(statistics_the_clamp_does_not_reach_the_average_or_the_total) {
    local_setup();

    local_switch(70000U, 10U, 0U);

// Min/Max saw 0, but Avg and Cum are fed timeP32 - the unclamped value. So the
// average moves by 70000/8 = 8750 while the max reads 0, and the two columns of
// the `process` output disagree about the same switch.

    EXPECT_EQ_U(vBackward.oStatistic.oTimePMax, 0U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimePCum, 70000U);
    QUIRK("statistics-clamp-skips-average", (vBackward.oStatistic.oTimePAvg == (70000U >> KNMEAN)));
}

// The exception subtraction
// =========================

TEST(statistics_exception_time_comes_off_the_process_time) {
    local_setup();

    local_switch(100U, 10U, 30U);

    EXPECT_EQ_U(vBackward.oStatistic.oTimePMax, 70U);           // 100 - 30
    EXPECT_EQ_U(vBackward.oStatistic.oTimeEMax, 30U);
}

TEST(statistics_exception_time_longer_than_the_slice_clamps_to_zero) {
    local_setup();

// Reachable: timeE is accumulated by the interrupt handlers over the whole
// slice and is not guaranteed to be smaller than stop - lastStart. Without the
// guard at statistics.c:78 the unsigned subtraction would wrap to ~4 billion
// and land in oTimePCum.

    local_switch(30U, 10U, 100U);

    EXPECT_EQ_U(vBackward.oStatistic.oTimePMax, 0U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimePCum, 0U);
}

// The moving average
// ==================

TEST(statistics_average_is_a_seven_eighths_filter) {
    uint32_t    expected;

    local_setup();

    local_switch(80U, 0U, 0U);
    expected = ((80U * KAVG_WEIGHT) + 80U) >> KNMEAN;           // seeded, then filtered
    EXPECT_EQ_U(vBackward.oStatistic.oTimePAvg, expected);

    local_switch(160U, 0U, 0U);
    expected = ((expected * KAVG_WEIGHT) + 160U) >> KNMEAN;
    EXPECT_EQ_U(vBackward.oStatistic.oTimePAvg, expected);

    local_switch(160U, 0U, 0U);
    expected = ((expected * KAVG_WEIGHT) + 160U) >> KNMEAN;
    EXPECT_EQ_U(vBackward.oStatistic.oTimePAvg, expected);

// It converges towards the input rather than reaching it, which is what makes
// the filter a filter: after three samples of 160 it is still short.

    EXPECT_TRUE(vBackward.oStatistic.oTimePAvg < 160U);
}

// The cumulative totals
// =====================

TEST(statistics_totals_accumulate_unclamped_and_in_64_bits) {
    local_setup();

    local_switch(40000U, 1000U, 0U);
    local_switch(40000U, 1000U, 0U);

// 80000 does not fit in the uint16_t the min/max columns use; the totals are
// uint64_t and must carry it.

    EXPECT_EQ_U(vBackward.oStatistic.oTimePCum, 80000U);
    EXPECT_EQ_U(vBackward.oStatistic.oTimeKCum, 2000U);
}

// Which process is counted
// ========================

TEST(statistics_counts_the_execution_against_the_incoming_process) {
    local_setup();

    local_switch(100U, 10U, 0U);
    local_switch(100U, 10U, 0U);

// Worth its own case because it is asymmetric and easy to misread: every timing
// goes to the OUTGOING process passed as the argument, but oNbExecutions is
// bumped on vKern_runProc - the one that has just been scheduled IN.

    EXPECT_EQ_U(vRunning.oStatistic.oNbExecutions,  2U);
    EXPECT_EQ_U(vBackward.oStatistic.oNbExecutions, 0U);
}

// The tier
// ========

TEST(statistics_takes_no_interrupt_mask) {
    local_setup();

    local_switch(100U, 10U, 0U);

// Called from scheduler.c with interrupts already off, so it takes no mask of
// its own. Asserted so that a future edit adding one is noticed here.

    EXPECT_EQ_U(g_kernenv.oNbOff, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}
