/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_kernels/kern/pools.c.
 *
 * Tier 3. A fixed-block allocator over a flat array: oUsedBlocks[] is a void*
 * occupancy vector, nullptr meaning free, and an allocation hands back
 * oBlockArray + i * oBlockSize. Every function is externally visible, so the
 * whole module is reachable through its public API.
 *
 * This is the suite the counting interrupt fake was built for. pools.c has 26
 * INTERRUPTION_RESTORE sites across six functions, most of them on early error
 * returns, and one missed on a target masks interrupts for good. Every test here
 * ends by asserting the mask came back.
 *
 * The allocator is calloc-backed rather than a static arena, so asan guards both
 * ends of each block array and an off-by-one in the block arithmetic is a
 * reported heap-buffer-overflow instead of a quiet write into a neighbour. Run
 * this suite under -s.
 *
 * Faked, not linked: the four kern_*Semaphore calls. A pool owns a release
 * semaphore, but linking semaphores.c would bring GOTO_KERN_M - an SVC trap that
 * does not return until the scheduler reschedules - into a tier that has no
 * scheduler. The blocking retry in kern_allocateBlock is therefore driven
 * through the fake's return code rather than by really waiting.
 *
 * Deliberately NOT tested: nullptr for the OUT parameters (`handle` of
 * kern_createPool, `address` of kern_allocateBlock) and for `configure`. The
 * module checks the object handle but dereferences its out-params and its
 * configuration struct unconditionally - a consistent convention across the
 * kernel, not a defect, and a death test would prove nothing about it.
 */

#include    <stdbool.h>
#include    <stddef.h>
#include    <stdint.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_pools.h"
#include    "kern/private/private_processes.h"
#include    "os_errors.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

#define KNB_BLOCKS          4U
#define KBLOCK_SIZE         32U

static  proc_t      vRunning;

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    (void)memset(&vRunning, 0, sizeof(vRunning));
    ukos_fake_setRunningProcess(&vRunning);

    pools_init();
}

/*
 * \brief A configured pool, ready to allocate from
 *
 */
static  pool_t  *local_configuredPool(const char_t *identifier, uint32_t nbBlocks, uint32_t blockSize) {
    pool_t  *handle = nullptr;
    pcnf_t  configure;

    EXPECT_EQ_I(kern_createPool(identifier, &handle), KERR_KERN_NOERR);

    configure.oNbBlocks  = nbBlocks;
    configure.oBlockSize = blockSize;
    EXPECT_EQ_I(kern_setPool(handle, &configure), KERR_KERN_NOERR);

    return handle;
}

// Creation
// ========

TEST(pools_init_empties_the_table) {
    local_setup();

    EXPECT_EQ_U(vKern_nbPool[0], 0U);
    EXPECT_EQ_U(vKern_nbMaxPool[0], 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_create_installs_but_does_not_configure) {
    pool_t  *handle = nullptr;

    local_setup();

    EXPECT_EQ_I(kern_createPool("Xfer", &handle), KERR_KERN_NOERR);
    EXPECT_NE_PTR(handle, nullptr);

    EXPECT_EQ_U(handle->oState & (1U << BPOOL_INSTALLED),  (1U << BPOOL_INSTALLED));
    EXPECT_EQ_U(handle->oState & (1U << BPOOL_CONFIGURED), 0U);
    EXPECT_EQ_U(vKern_nbPool[0], 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_an_anonymous_pool_takes_the_shared_identifier) {
    pool_t  *handle = nullptr;

    local_setup();

    EXPECT_EQ_I(kern_createPool(nullptr, &handle), KERR_KERN_NOERR);
    EXPECT_EQ_STR(handle->oIdentifier, KPOOL_ANONYMOUS_ID);
}

TEST(pools_a_duplicate_identifier_returns_the_existing_handle) {
    pool_t  *first = nullptr;
    pool_t  *again = nullptr;

    local_setup();

    EXPECT_EQ_I(kern_createPool("Xfer", &first), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_createPool("Xfer", &again), KERR_KERN_IDPOI);

// The error still yields the handle of the pool that already exists, which the
// header documents and callers rely on. It is NOT a nullptr-on-error contract.

    EXPECT_EQ_PTR(again, first);
    EXPECT_EQ_U(vKern_nbPool[0], 1U);                   // and nothing was consumed
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_a_full_table_is_refused) {
    pool_t          *handle = nullptr;
    uint16_t        i;
    static  const   char_t  *const names[] = {
                        "p0", "p1", "p2", "p3", "p4", "p5", "p6", "p7",
                        "p8", "p9", "pa", "pb", "pc", "pd", "pe", "pf",
                    };

    local_setup();

// Distinct string LITERALS, not one reused buffer. The pool keeps the pointer
// it was given (pools.c:126) rather than copying the text, so filling the table
// from a single buffer makes every slot share one identifier and the second
// create reports IDPOI instead of succeeding. See
// pools_the_identifier_is_kept_by_reference below.

    EXPECT_TRUE(KKERN_NB_POOLS <= (uint16_t)(sizeof(names) / sizeof(names[0])));

    for (i = 0U; i < KKERN_NB_POOLS; i++) {
        EXPECT_EQ_I(kern_createPool(names[i], &handle), KERR_KERN_NOERR);
    }

    EXPECT_EQ_U(vKern_nbPool[0], KKERN_NB_POOLS);

    handle = nullptr;
    EXPECT_EQ_I(kern_createPool("one too many", &handle), KERR_KERN_POFUL);
    EXPECT_EQ_PTR(handle, nullptr);

// The POFUL return is the one error path of kern_createPool that the combined
// mask test below cannot reach - it needs a full table - so it carries its own
// pairing assertions. Without them, dropping either restore from that arm goes
// unnoticed.

    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
}

TEST(pools_the_identifier_is_kept_by_reference) {
    pool_t  *handle = nullptr;
    pool_t  *found  = nullptr;
    char_t  name[8];

    local_setup();

    name[0] = 'A'; name[1] = '\0';
    EXPECT_EQ_I(kern_createPool(&name[0], &handle), KERR_KERN_NOERR);

// The pool stores the caller's pointer, so editing the buffer afterwards
// renames the pool. Worth pinning because it is invisible at the call site and
// it makes a stack-allocated identifier a dangling pointer the moment the
// creating function returns - every in-tree caller passes a literal.

    name[0] = 'B';
    EXPECT_EQ_I(kern_getPoolById("A", &found), KERR_KERN_NOPOI);
    EXPECT_EQ_I(kern_getPoolById("B", &found), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(found, handle);
}

// Configuration
// =============

TEST(pools_set_rounds_the_block_size_up_to_four) {
    pool_t  *handle;

    local_setup();

    handle = local_configuredPool("Odd", 2U, 13U);

// (13 + 3) & ~3 == 16. The size the caller asked for is not what is stored.

    EXPECT_EQ_U(handle->oBlockSize, 16U);
    EXPECT_EQ_U(handle->oNbBlocks,  2U);
}

TEST(pools_the_rounding_is_to_four_not_eight) {
    pool_t  *handle;

    local_setup();

// 12 is already a multiple of 4 and must be left alone. Chosen deliberately:
// every other size in this suite is also a multiple of 8, so none of them can
// tell a round-up-to-4 from a round-up-to-8 and a mutation widening the
// alignment survived until this case existed.

    handle = local_configuredPool("Twelve", 2U, 12U);
    EXPECT_EQ_U(handle->oBlockSize, 12U);

    local_setup();
    handle = local_configuredPool("Twenty", 2U, 20U);
    EXPECT_EQ_U(handle->oBlockSize, 20U);
}

TEST(pools_set_leaves_an_exact_multiple_alone) {
    pool_t  *handle;

    local_setup();

    handle = local_configuredPool("Even", 2U, 16U);
    EXPECT_EQ_U(handle->oBlockSize, 16U);               // not rounded up to 20
}

TEST(pools_set_refuses_a_degenerate_configuration) {
    pool_t  *handle = nullptr;
    pcnf_t  configure;

    local_setup();

    EXPECT_EQ_I(kern_createPool("Bad", &handle), KERR_KERN_NOERR);

    configure.oNbBlocks  = 0U;
    configure.oBlockSize = 16U;
    EXPECT_EQ_I(kern_setPool(handle, &configure), KERR_KERN_POCNF);

    configure.oNbBlocks  = 2U;
    configure.oBlockSize = 0U;
    EXPECT_EQ_I(kern_setPool(handle, &configure), KERR_KERN_POCNF);

// Neither attempt allocated anything, and both gave the mask back.

    EXPECT_EQ_U(g_kernenv.oNbMalloc, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_set_refuses_an_uninstalled_or_reconfigured_pool) {
    pool_t  *handle;
    pcnf_t  configure;

    local_setup();

    configure.oNbBlocks  = KNB_BLOCKS;
    configure.oBlockSize = KBLOCK_SIZE;

    EXPECT_EQ_I(kern_setPool(nullptr, &configure), KERR_KERN_NOPOI);

    handle = local_configuredPool("Twice", KNB_BLOCKS, KBLOCK_SIZE);
    EXPECT_EQ_I(kern_setPool(handle, &configure), KERR_KERN_POCNF);

    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Allocation failure - the interrupt-leak paths
// =============================================

TEST(pools_a_failed_block_array_allocation_is_reported) {
    pool_t  *handle = nullptr;
    pcnf_t  configure;

    local_setup();

    EXPECT_EQ_I(kern_createPool("NoMem", &handle), KERR_KERN_NOERR);

    configure.oNbBlocks  = KNB_BLOCKS;
    configure.oBlockSize = KBLOCK_SIZE;
    g_kernenv.oFailMallocOnCall = 1U;                    // the block array

    EXPECT_EQ_I(kern_setPool(handle, &configure), KERR_KERN_POCNF);

    EXPECT_EQ_U(handle->oState & (1U << BPOOL_CONFIGURED), 0U);
    EXPECT_EQ_U(g_kernenv.oNbFree, 0U);                 // nothing to give back yet
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_a_failed_occupancy_vector_frees_the_block_array) {
    pool_t  *handle = nullptr;
    pcnf_t  configure;

    local_setup();

    EXPECT_EQ_I(kern_createPool("NoMem2", &handle), KERR_KERN_NOERR);

    configure.oNbBlocks  = KNB_BLOCKS;
    configure.oBlockSize = KBLOCK_SIZE;

// The first allocation succeeds and the second fails: the arm that has to
// unwind. Under -s a missing memo_free here is a leak asan reports at exit,
// which is the second, independent guard on this branch.

    g_kernenv.oFailMallocOnCall = 2U;                   // the occupancy vector

    EXPECT_EQ_I(kern_setPool(handle, &configure), KERR_KERN_POCNF);

    EXPECT_EQ_U(g_kernenv.oNbMalloc, 2U);
    EXPECT_EQ_U(g_kernenv.oNbFree,   1U);               // the block array came back
    EXPECT_EQ_U(g_kernenv.oNbSemaCreate, 0U);           // never got as far as the semaphore
    EXPECT_EQ_U(handle->oState & (1U << BPOOL_CONFIGURED), 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_a_failed_semaphore_frees_both_allocations) {
    pool_t  *handle = nullptr;
    pcnf_t  configure;

    local_setup();

    EXPECT_EQ_I(kern_createPool("NoSema", &handle), KERR_KERN_NOERR);

    configure.oNbBlocks  = KNB_BLOCKS;
    configure.oBlockSize = KBLOCK_SIZE;
    g_kernenv.oRcSemaCreate = KERR_KERN_SEFUL;

    EXPECT_EQ_I(kern_setPool(handle, &configure), KERR_KERN_POCNF);

// Both allocations must come back, or a pool that failed to configure has
// leaked its arrays for the lifetime of the system.

    EXPECT_EQ_U(g_kernenv.oNbMalloc, 2U);
    EXPECT_EQ_U(g_kernenv.oNbFree,   2U);
    EXPECT_EQ_U(handle->oState & (1U << BPOOL_CONFIGURED), 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Allocation
// ==========

TEST(pools_allocate_hands_out_distinct_blocks_in_order) {
    pool_t      *handle;
    void        *block[KNB_BLOCKS];
    uint32_t    i;

    local_setup();

    handle = local_configuredPool("Alloc", KNB_BLOCKS, KBLOCK_SIZE);

    for (i = 0U; i < KNB_BLOCKS; i++) {
        block[i] = nullptr;
        EXPECT_EQ_I(kern_allocateBlock(handle, &block[i], 0U), KERR_KERN_NOERR);
        EXPECT_NE_PTR(block[i], nullptr);

// Blocks come out of the array at i * blockSize, in ascending order.

        EXPECT_EQ_PTR(block[i], (void *)((uintptr_t)handle->oBlockArray + (uintptr_t)(i * KBLOCK_SIZE)));
    }

    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_an_exhausted_pool_reports_full_and_yields_no_address) {
    pool_t  *handle;
    void    *block = nullptr;
    uint32_t i;

    local_setup();

    handle = local_configuredPool("Full", KNB_BLOCKS, KBLOCK_SIZE);

    for (i = 0U; i < KNB_BLOCKS; i++) {
        EXPECT_EQ_I(kern_allocateBlock(handle, &block, 0U), KERR_KERN_NOERR);
    }

    block = (void *)&handle;                            // poison, to prove it is cleared
    EXPECT_EQ_I(kern_allocateBlock(handle, &block, 0U), KERR_KERN_BKFUL);
    EXPECT_EQ_PTR(block, nullptr);

// timeout == 0, so the semaphore must not have been waited on.

    EXPECT_EQ_U(g_kernenv.oNbSemaWait, 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_allocate_on_an_unconfigured_pool_is_refused) {
    pool_t  *handle = nullptr;
    void    *block  = nullptr;

    local_setup();

    EXPECT_EQ_I(kern_createPool("Unset", &handle), KERR_KERN_NOERR);

    EXPECT_EQ_I(kern_allocateBlock(handle,  &block, 0U), KERR_KERN_PONCF);
    EXPECT_EQ_I(kern_allocateBlock(nullptr, &block, 0U), KERR_KERN_NOPOI);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// The blocking retry
// ==================

TEST(pools_a_timeout_retries_once_after_the_semaphore) {
    pool_t      *handle;
    void        *block = nullptr;
    uint32_t    i;

    local_setup();

    handle = local_configuredPool("Wait", KNB_BLOCKS, KBLOCK_SIZE);

    for (i = 0U; i < KNB_BLOCKS; i++) {
        EXPECT_EQ_I(kern_allocateBlock(handle, &block, 0U), KERR_KERN_NOERR);
    }

// The pool is full and the wait "succeeds", but nothing was freed meanwhile, so
// the single tail retry finds nothing either and the caller still gets BKFUL.
// This is the arm that proves the retry happens exactly once rather than
// looping: a second retry would wait twice.

    g_kernenv.oRcSemaWait = KERR_KERN_NOERR;
    EXPECT_EQ_I(kern_allocateBlock(handle, &block, 1000U), KERR_KERN_BKFUL);

    EXPECT_EQ_U(g_kernenv.oNbSemaWait, 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_a_failed_wait_does_not_retry) {
    pool_t      *handle;
    void        *block = nullptr;
    uint32_t    i;

    local_setup();

    handle = local_configuredPool("NoWait", KNB_BLOCKS, KBLOCK_SIZE);

    for (i = 0U; i < KNB_BLOCKS; i++) {
        EXPECT_EQ_I(kern_allocateBlock(handle, &block, 0U), KERR_KERN_NOERR);
    }

    g_kernenv.oRcSemaWait = KERR_KERN_TIMEO;
    EXPECT_EQ_I(kern_allocateBlock(handle, &block, 1000U), KERR_KERN_BKFUL);

    EXPECT_EQ_U(g_kernenv.oNbSemaWait, 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Deallocation
// ============

TEST(pools_deallocate_returns_a_block_to_the_pool) {
    pool_t  *handle;
    void    *first  = nullptr;
    void    *again  = nullptr;

    local_setup();

    handle = local_configuredPool("Free", 1U, KBLOCK_SIZE);

    EXPECT_EQ_I(kern_allocateBlock(handle, &first, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_allocateBlock(handle, &again, 0U), KERR_KERN_BKFUL);

    EXPECT_EQ_I(kern_deAllocateBlock(handle, first), KERR_KERN_NOERR);
    EXPECT_EQ_U(g_kernenv.oNbSemaSignal, 1U);           // and it wakes a waiter

    EXPECT_EQ_I(kern_allocateBlock(handle, &again, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(again, first);                        // the same block comes back
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_deallocate_rejects_an_address_that_is_not_a_block) {
    pool_t  *handle;
    void    *block = nullptr;
    uint32_t stranger = 0U;

    local_setup();

    handle = local_configuredPool("Strange", KNB_BLOCKS, KBLOCK_SIZE);

// Every block allocated, on purpose. With free slots the occupancy vector holds
// nullptrs, and a search that compared by range instead of equality would still
// fail to match - so a half-empty pool cannot tell the two apart. Filling it
// puts a higher-addressed block after the probe and makes the difference
// observable.

    for (uint32_t i = 0U; i < KNB_BLOCKS; i++) {
        EXPECT_EQ_I(kern_allocateBlock(handle, &block, 0U), KERR_KERN_NOERR);
    }

    EXPECT_EQ_I(kern_deAllocateBlock(handle, &stranger), KERR_KERN_NOBKI);

// An address inside the array but not on a block boundary is not a block
// either: the vector is searched by exact match, not by range.

    EXPECT_EQ_I(kern_deAllocateBlock(handle, (void *)((uintptr_t)handle->oBlockArray + 4U)), KERR_KERN_NOBKI);

    EXPECT_EQ_U(g_kernenv.oNbSemaSignal, 0U);           // no waiter woken for a bad address
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_deallocating_twice_is_refused_the_second_time) {
    pool_t  *handle;
    void    *block = nullptr;

    local_setup();

    handle = local_configuredPool("Double", KNB_BLOCKS, KBLOCK_SIZE);
    EXPECT_EQ_I(kern_allocateBlock(handle, &block, 0U), KERR_KERN_NOERR);

    EXPECT_EQ_I(kern_deAllocateBlock(handle, block), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_deAllocateBlock(handle, block), KERR_KERN_NOBKI);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Destruction
// ===========

TEST(pools_kill_releases_everything_and_frees_the_slot) {
    pool_t  *handle;
    pool_t  *found = nullptr;

    local_setup();

    handle = local_configuredPool("Doomed", KNB_BLOCKS, KBLOCK_SIZE);
    g_kernenv.oNbFree = 0U;

    EXPECT_EQ_I(kern_killPool(handle), KERR_KERN_NOERR);

    EXPECT_EQ_U(g_kernenv.oNbFree, 2U);                 // block array and occupancy vector
    EXPECT_EQ_U(g_kernenv.oNbSemaKill, 1U);
    EXPECT_EQ_U(handle->oState, 0U);
    EXPECT_EQ_PTR(handle->oBlockArray, nullptr);
    EXPECT_EQ_U(vKern_nbPool[0], 0U);

    EXPECT_EQ_I(kern_getPoolById("Doomed", &found), KERR_KERN_NOPOI);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(pools_killing_an_unconfigured_pool_frees_nothing) {
    pool_t  *handle = nullptr;

    local_setup();

    EXPECT_EQ_I(kern_createPool("Bare", &handle), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_killPool(handle), KERR_KERN_NOERR);

// The BPOOL_CONFIGURED arm is skipped, so no free and no semaphore kill - which
// matters, because those pointers are still nullptr at this point.

    EXPECT_EQ_U(g_kernenv.oNbFree, 0U);
    EXPECT_EQ_U(g_kernenv.oNbSemaKill, 0U);
    EXPECT_EQ_U(vKern_nbPool[0], 0U);
}

TEST(pools_kill_refuses_an_unknown_pool) {
    local_setup();

    EXPECT_EQ_I(kern_killPool(nullptr), KERR_KERN_NOPOI);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Lookup
// ======

TEST(pools_lookup_finds_by_identifier) {
    pool_t  *created;
    pool_t  *found = nullptr;

    local_setup();

    created = local_configuredPool("Wanted", KNB_BLOCKS, KBLOCK_SIZE);

    EXPECT_EQ_I(kern_getPoolById("Wanted", &found), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(found, created);

    found = (pool_t *)&created;                         // poison
    EXPECT_EQ_I(kern_getPoolById("Absent", &found), KERR_KERN_NOPOI);
    EXPECT_EQ_PTR(found, nullptr);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// The accounting
// ==============

TEST(pools_every_entry_point_counts_a_kernel_call) {
    pool_t  *handle = nullptr;
    void    *block  = nullptr;

    local_setup();

    EXPECT_EQ_U(vRunning.oStatistic.oNbKernCalls, 0U);

    (void)kern_createPool("Counted", &handle);
    (void)kern_getPoolById("Counted", &handle);
    (void)kern_allocateBlock(handle, &block, 0U);
    (void)kern_deAllocateBlock(handle, block);
    (void)kern_killPool(handle);

// Five calls, five counts. pools_init is not a system call and must not count.

    EXPECT_EQ_U(vRunning.oStatistic.oNbKernCalls, 5U);
}

TEST(pools_the_high_water_mark_does_not_fall) {
    pool_t  *a = nullptr;
    pool_t  *b = nullptr;

    local_setup();

    (void)kern_createPool("a", &a);
    (void)kern_createPool("b", &b);
    EXPECT_EQ_U(vKern_nbMaxPool[0], 2U);

    (void)kern_killPool(a);
    (void)kern_killPool(b);

    EXPECT_EQ_U(vKern_nbPool[0],    0U);
    EXPECT_EQ_U(vKern_nbMaxPool[0], 2U);                // the maximum is a record, not a count
}

// The mask, counted rather than assumed
// =====================================

TEST(pools_every_error_return_gives_the_mask_back) {
    pool_t  *handle = nullptr;
    void    *block  = nullptr;
    pcnf_t  configure;

    local_setup();

    configure.oNbBlocks  = 0U;
    configure.oBlockSize = 0U;

// Drive one error return of every function that has one, in a single test, and
// assert the depth is zero at the end. Any one of them that returns without its
// INTERRUPTION_RESTORE leaves the depth non-zero and fails here - which is the
// bug class this whole tier's counting fake exists to catch.

    (void)kern_setPool(nullptr, &configure);                    // NOPOI
    (void)kern_allocateBlock(nullptr, &block, 0U);              // NOPOI
    (void)kern_deAllocateBlock(nullptr, block);                 // NOPOI
    (void)kern_killPool(nullptr);                               // NOPOI
    (void)kern_getPoolById("nothing here", &handle);            // NOPOI

    (void)kern_createPool("x", &handle);
    (void)kern_createPool("x", &handle);                        // IDPOI
    (void)kern_setPool(handle, &configure);                     // POCNF, degenerate
    (void)kern_allocateBlock(handle, &block, 0U);               // PONCF, not configured
    (void)kern_deAllocateBlock(handle, block);                  // PONCF

    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
    EXPECT_EQ_U(g_kernenv.oNbOff, g_kernenv.oNbRestore);
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 1U);               // never nested
    EXPECT_TRUE(ukos_fake_interruptsBalanced());

// The privilege pair is the same story one level up, and it is checked here
// rather than everywhere because it is the same ten returns. In a _nouser build
// both macros vanish and this is trivially true, which is why the suite is built
// both ways.

    EXPECT_TRUE(ukos_fake_privilegeBalanced());
    EXPECT_EQ_U(g_kernenv.oNbElevate, g_kernenv.oNbRestorePriv);
}
