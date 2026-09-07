/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_kernels/kern/mailboxes.c.
 *
 * Tier 3, and the largest module in the kernel at 818 lines. A real ring buffer
 * with TWO wait lists - one for readers blocked on empty, one for writers
 * blocked on full - and two transfer modes that behave differently enough to be
 * worth treating as separate features:
 *
 *   - reference mode (oDataEntrySize == 0): the FIFO stores the caller's
 *     pointer. Nothing is copied and the sender must keep the buffer alive.
 *   - copy mode (oDataEntrySize > 0): the message is memcpy'd into a second
 *     allocation, and BOTH the pack ring and the data ring wrap independently.
 *
 * The ring wrap lives in the static helpers local_write() and local_read(), but
 * this suite does NOT #include the .c to reach them: both are called from the
 * public entry points on every transfer, so writing and reading past the end of
 * the FIFO exercises the wrap through kern_writeMailbox / kern_readMailbox
 * exactly as production does. The escape hatch stays unused here.
 *
 * Under -s the allocator is calloc-backed, so the data ring has asan guards on
 * both ends: an off-by-one in the wrap arithmetic is a reported
 * heap-buffer-overflow, not a quiet write into the neighbouring pack.
 *
 * Read the GOTO_KERN_M warning in port/macros_core_stackFrame.h before trusting
 * anything asserted about blocking.
 */

#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/private/private_kern.h"
#include    "kern/private/private_lists.h"
#include    "kern/private/private_mailboxes.h"
#include    "kern/private/private_processes.h"
#include    "os_errors.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

#define KPRIO_HIGH          KKERN_PRIORITY_HIGH_04
#define KPRIO_RUNNING       KKERN_PRIORITY_HIGH_08
#define KPRIO_LOW           KKERN_PRIORITY_HIGH_11

#define KNB_PACKS           3U                          // small, so the wrap is quick to reach
#define KENTRY_SIZE         8U

static  proc_t      vRunning;
static  proc_t      vWaiter[2];

/*
 * \brief Fixture
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    (void)memset(&vRunning,   0, sizeof(vRunning));
    (void)memset(&vWaiter[0], 0, sizeof(vWaiter));

    vRunning.oInternal.oDynamicPriority = KPRIO_RUNNING;
    ukos_fake_setRunningProcess(&vRunning);

    mailboxes_init();
}

/*
 * \brief A configured mailbox
 *
 * - entrySize 0 selects reference mode, anything else copy mode.
 *
 */
static  mbox_t  *local_mailbox(const char_t *identifier, uint32_t nbPacks, uint32_t entrySize) {
    mbox_t  *handle = nullptr;
    mcnf_t  configure;

    EXPECT_EQ_I(kern_createMailbox(identifier, &handle), KERR_KERN_NOERR);

    configure.oNbMaxPacks    = nbPacks;
    configure.oDataEntrySize = entrySize;
    EXPECT_EQ_I(kern_setMailbox(handle, &configure), KERR_KERN_NOERR);

    return handle;
}

/*
 * \brief Park a process on one of the two wait lists, as the scheduler would
 *
 */
static  void    local_addWaiter(list_t *list, proc_t *process, priority_t priority, uint8_t stateBit) {

    process->oInternal.oDynamicPriority = priority;
    process->oInternal.oState          |= (uint16_t)(1U << stateBit);
    lists_connect(list, process);
}

// Creation and configuration
// ==========================

TEST(mailboxes_init_empties_the_table) {
    local_setup();

    EXPECT_EQ_U(vKern_nbMbox[0], 0U);
    EXPECT_EQ_U(vKern_nbMaxMbox[0], 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mailboxes_create_starts_installed_and_empty) {
    mbox_t  *handle = nullptr;

    local_setup();

    EXPECT_EQ_I(kern_createMailbox("Queue", &handle), KERR_KERN_NOERR);

// EMPTY is set at CREATE, not at configure (mailboxes.c:145). It has to be: the
// read path tests that flag rather than oNbUsedPacks, so a mailbox that started
// with it clear would hand out a pack that was never written.

    EXPECT_EQ_U(handle->oState & (1U << BMBOX_INSTALLED), (1U << BMBOX_INSTALLED));
    EXPECT_EQ_U(handle->oState & (1U << BMBOX_EMPTY),     (1U << BMBOX_EMPTY));
    EXPECT_EQ_U(handle->oState & (1U << BMBOX_CONFIGURED), 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mailboxes_reference_mode_allocates_only_the_pack_ring) {
    mbox_t  *handle;

    local_setup();

    handle = local_mailbox("Ref", KNB_PACKS, 0U);

    EXPECT_EQ_U(handle->oState & (1U << BMBOX_BY_COPY), 0U);
    EXPECT_EQ_PTR(handle->oDataBuffer, nullptr);
    EXPECT_EQ_U(g_kernenv.oNbMalloc, 1U);
    EXPECT_EQ_U(handle->oNbMaxPacks, KNB_PACKS);
}

TEST(mailboxes_copy_mode_allocates_a_second_buffer) {
    mbox_t  *handle;

    local_setup();

    handle = local_mailbox("Copy", KNB_PACKS, KENTRY_SIZE);

    EXPECT_EQ_U(handle->oState & (1U << BMBOX_BY_COPY), (1U << BMBOX_BY_COPY));
    EXPECT_NE_PTR(handle->oDataBuffer, nullptr);
    EXPECT_EQ_PTR(handle->oDataWrite, handle->oDataBuffer);
    EXPECT_EQ_U(g_kernenv.oNbMalloc, 2U);
    EXPECT_EQ_U(g_kernenv.oLastMallocSize, KNB_PACKS * KENTRY_SIZE);
}

TEST(mailboxes_set_refuses_a_degenerate_or_repeated_configuration) {
    mbox_t  *handle = nullptr;
    mcnf_t  configure;

    local_setup();

    configure.oNbMaxPacks    = 0U;
    configure.oDataEntrySize = 0U;

    EXPECT_EQ_I(kern_setMailbox(nullptr, &configure), KERR_KERN_NOMBO);

    EXPECT_EQ_I(kern_createMailbox("Bad", &handle), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_setMailbox(handle, &configure), KERR_KERN_MBCNF);   // zero packs
    EXPECT_EQ_U(g_kernenv.oNbMalloc, 0U);

    configure.oNbMaxPacks = KNB_PACKS;
    EXPECT_EQ_I(kern_setMailbox(handle, &configure), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_setMailbox(handle, &configure), KERR_KERN_MBCNF);   // twice
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mailboxes_a_failed_data_buffer_frees_the_pack_ring) {
    mbox_t  *handle = nullptr;
    mcnf_t  configure;

    local_setup();

    EXPECT_EQ_I(kern_createMailbox("NoMem", &handle), KERR_KERN_NOERR);

    configure.oNbMaxPacks    = KNB_PACKS;
    configure.oDataEntrySize = KENTRY_SIZE;
    g_kernenv.oFailMallocOnCall = 2U;                   // the data buffer, not the ring

    EXPECT_EQ_I(kern_setMailbox(handle, &configure), KERR_KERN_MBCNF);

    EXPECT_EQ_U(g_kernenv.oNbMalloc, 2U);
    EXPECT_EQ_U(g_kernenv.oNbFree,   1U);               // the ring came back
    EXPECT_EQ_U(handle->oState & (1U << BMBOX_CONFIGURED), 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

// Reference mode
// ==============

TEST(mailboxes_reference_mode_passes_the_pointer_through) {
    mbox_t      *handle;
    uint8_t     payload[4] = { 1U, 2U, 3U, 4U };
    void        *received  = nullptr;
    uint32_t    size       = 0U;

    local_setup();

    handle = local_mailbox("Ref", KNB_PACKS, 0U);

    EXPECT_EQ_I(kern_writeMailbox(handle, &payload[0], sizeof(payload), 0U), KERR_KERN_NOERR);
    EXPECT_EQ_U(handle->oNbUsedPacks, 1U);
    EXPECT_EQ_U(handle->oState & (1U << BMBOX_EMPTY), 0U);

    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);

// The very same address, not a copy: nothing was allocated for the payload and
// the sender still owns it.

    EXPECT_EQ_PTR(received, &payload[0]);
    EXPECT_EQ_U(size, sizeof(payload));
    EXPECT_EQ_U(handle->oNbUsedPacks, 0U);
    EXPECT_EQ_U(handle->oState & (1U << BMBOX_EMPTY), (1U << BMBOX_EMPTY));
}

TEST(mailboxes_messages_come_back_in_order) {
    mbox_t      *handle;
    uint8_t     payload[KNB_PACKS];
    void        *received;
    uint32_t    size, i;

    local_setup();

    handle = local_mailbox("Ref", KNB_PACKS, 0U);

    for (i = 0U; i < KNB_PACKS; i++) {
        payload[i] = (uint8_t)i;
        EXPECT_EQ_I(kern_writeMailbox(handle, &payload[i], 1U, 0U), KERR_KERN_NOERR);
    }

    for (i = 0U; i < KNB_PACKS; i++) {
        received = nullptr;
        size     = 0U;
        EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);
        EXPECT_EQ_PTR(received, &payload[i]);           // FIFO, not LIFO
    }
}

// The ring
// ========

TEST(mailboxes_the_pack_ring_wraps) {
    mbox_t      *handle;
    uint8_t     payload[8];
    void        *received;
    uint32_t    size, i;

    local_setup();

    handle = local_mailbox("Ring", KNB_PACKS, 0U);

// Two full laps plus one, so oWrite and oRead each cross the end of the FIFO
// more than once. The wrap is the last statement of local_write / local_read
// and is only reachable this way from outside the module.

    for (i = 0U; i < (2U * KNB_PACKS) + 1U; i++) {
        payload[i] = (uint8_t)i;

        EXPECT_EQ_I(kern_writeMailbox(handle, &payload[i], 1U, 0U), KERR_KERN_NOERR);

        received = nullptr;
        size     = 0U;
        EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);
        EXPECT_EQ_PTR(received, &payload[i]);
    }

// Back where it started, and consistent: both pointers inside the array and the
// mailbox reporting empty.

    EXPECT_EQ_U(handle->oNbUsedPacks, 0U);
    EXPECT_EQ_PTR(handle->oRead, handle->oWrite);
    EXPECT_EQ_U(handle->oState & (1U << BMBOX_EMPTY), (1U << BMBOX_EMPTY));
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mailboxes_a_full_ring_is_reported_full) {
    mbox_t      *handle;
    uint8_t     payload[KNB_PACKS + 1U];
    uint32_t    i;

    local_setup();

    handle = local_mailbox("Ring", KNB_PACKS, 0U);

    for (i = 0U; i < KNB_PACKS; i++) {
        EXPECT_EQ_I(kern_writeMailbox(handle, &payload[i], 1U, 0U), KERR_KERN_NOERR);
    }

// oWrite has caught up with oRead. That is ambiguous by itself - it is also the
// empty condition - which is why the module carries explicit FULL and EMPTY
// flags instead of comparing the two pointers.

    EXPECT_EQ_U(handle->oState & (1U << BMBOX_FULL), (1U << BMBOX_FULL));
    EXPECT_EQ_U(handle->oState & (1U << BMBOX_EMPTY), 0U);
    EXPECT_EQ_PTR(handle->oRead, handle->oWrite);
    EXPECT_EQ_U(handle->oNbUsedPacks, KNB_PACKS);

    EXPECT_EQ_I(kern_writeMailbox(handle, &payload[KNB_PACKS], 1U, 0U), KERR_KERN_TIMEO);
    EXPECT_EQ_U(handle->oNbUsedPacks, KNB_PACKS);       // and nothing was overwritten
}

TEST(mailboxes_the_high_water_mark_does_not_fall) {
    mbox_t      *handle;
    uint8_t     payload[KNB_PACKS];
    void        *received;
    uint32_t    size, i;

    local_setup();

    handle = local_mailbox("Ring", KNB_PACKS, 0U);

    for (i = 0U; i < KNB_PACKS; i++) {
        EXPECT_EQ_I(kern_writeMailbox(handle, &payload[i], 1U, 0U), KERR_KERN_NOERR);
    }
    EXPECT_EQ_U(handle->oNbMaxUsedPacks, KNB_PACKS);

    for (i = 0U; i < KNB_PACKS; i++) {
        received = nullptr;
        size     = 0U;
        (void)kern_readMailbox(handle, &received, &size, 0U);
    }

    EXPECT_EQ_U(handle->oNbUsedPacks, 0U);
    EXPECT_EQ_U(handle->oNbMaxUsedPacks, KNB_PACKS);    // a record, not a count
}

TEST(mailboxes_reading_an_empty_mailbox_times_out) {
    mbox_t      *handle;
    void        *received = nullptr;
    uint32_t    size      = 0U;

    local_setup();

    handle = local_mailbox("Ref", KNB_PACKS, 0U);

    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_TIMEO);
    EXPECT_EQ_PTR(received, nullptr);
    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 0U);             // timeout 0 never asks to block
}

// Copy mode
// =========

TEST(mailboxes_copy_mode_copies_the_payload) {
    mbox_t      *handle;
    uint8_t     sent[KENTRY_SIZE];
    uint8_t     got[KENTRY_SIZE];
    void        *received = &got[0];
    uint32_t    size      = sizeof(got);
    uint32_t    i;

    local_setup();

    handle = local_mailbox("Copy", KNB_PACKS, KENTRY_SIZE);

    for (i = 0U; i < KENTRY_SIZE; i++) { sent[i] = (uint8_t)(0xA0U + i); }
    (void)memset(&got[0], 0, sizeof(got));

    EXPECT_EQ_I(kern_writeMailbox(handle, &sent[0], KENTRY_SIZE, 0U), KERR_KERN_NOERR);

// The sender's buffer is now free to change - the message is in the mailbox's
// own storage. Overwrite it to prove the copy really happened.

    (void)memset(&sent[0], 0xFF, sizeof(sent));

    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);

    EXPECT_EQ_U(size, KENTRY_SIZE);
    EXPECT_EQ_PTR(received, &got[0]);                   // the caller's buffer, unchanged
    for (i = 0U; i < KENTRY_SIZE; i++) {
        EXPECT_EQ_U(got[i], (uint8_t)(0xA0U + i));
    }
}

TEST(mailboxes_copy_mode_refuses_an_oversized_message) {
    mbox_t      *handle;
    uint8_t     sent[KENTRY_SIZE + 1U];

    local_setup();

    handle = local_mailbox("Copy", KNB_PACKS, KENTRY_SIZE);

// Guarded, and it must be: local_write memcpy's `size` bytes into a slot of
// exactly oDataEntrySize. Without this the write would run into the next slot.

    EXPECT_EQ_I(kern_writeMailbox(handle, &sent[0], KENTRY_SIZE + 1U, 0U), KERR_KERN_MBSIZ);
    EXPECT_EQ_U(handle->oNbUsedPacks, 0U);

    EXPECT_EQ_I(kern_writeMailbox(handle, &sent[0], KENTRY_SIZE, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_U(handle->oNbUsedPacks, 1U);
}

TEST(mailboxes_the_data_ring_wraps_independently) {
    mbox_t      *handle;
    uint8_t     sent[KENTRY_SIZE];
    uint8_t     got[KENTRY_SIZE];
    void        *received;
    uint32_t    size, i, lap;

    local_setup();

    handle = local_mailbox("Copy", KNB_PACKS, KENTRY_SIZE);

// Two laps of the data buffer. oDataWrite advances by oDataEntrySize and wraps
// on its own arithmetic, separate from the pack ring - under -s an off-by-one
// here is a heap-buffer-overflow on the second allocation.

    for (lap = 0U; lap < (2U * KNB_PACKS) + 1U; lap++) {
        for (i = 0U; i < KENTRY_SIZE; i++) { sent[i] = (uint8_t)(lap + i); }

        EXPECT_EQ_I(kern_writeMailbox(handle, &sent[0], KENTRY_SIZE, 0U), KERR_KERN_NOERR);

        received = &got[0];
        size     = sizeof(got);
        (void)memset(&got[0], 0, sizeof(got));
        EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);

        for (i = 0U; i < KENTRY_SIZE; i++) {
            EXPECT_EQ_U(got[i], (uint8_t)(lap + i));
        }
    }

// And it came back to the start of the buffer rather than walking off it.

    EXPECT_TRUE((handle->oDataWrite >= handle->oDataBuffer) &&
                (handle->oDataWrite <  &handle->oDataBuffer[KNB_PACKS * KENTRY_SIZE]));
}

TEST(mailboxes_copy_mode_truncates_to_the_size_offered) {
    mbox_t      *handle;
    uint8_t     sent[KENTRY_SIZE];
    uint8_t     got[KENTRY_SIZE];
    void        *received;
    uint32_t    size;

    local_setup();

    handle = local_mailbox("Copy", KNB_PACKS, KENTRY_SIZE);
    (void)memset(&sent[0], 0x5AU, sizeof(sent));

    EXPECT_EQ_I(kern_writeMailbox(handle, &sent[0], KENTRY_SIZE, 0U), KERR_KERN_NOERR);

    (void)memset(&got[0], 0, sizeof(got));
    received = &got[0];
    size     = 4U;                                      // a buffer smaller than the message

    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);

// size is in AND out: the caller offers a capacity and is told what was copied.

    EXPECT_EQ_U(size, 4U);
    EXPECT_EQ_U(got[3], 0x5AU);
    EXPECT_EQ_U(got[4], 0U);                            // nothing written past the offer
}

TEST(mailboxes_copy_mode_treats_a_zero_size_as_give_me_everything) {
    mbox_t      *handle;
    uint8_t     sent[KENTRY_SIZE];
    uint8_t     got[KENTRY_SIZE];
    void        *received;
    uint32_t    size;

    local_setup();

    handle = local_mailbox("Copy", KNB_PACKS, KENTRY_SIZE);
    (void)memset(&sent[0], 0x5AU, sizeof(sent));

    EXPECT_EQ_I(kern_writeMailbox(handle, &sent[0], KENTRY_SIZE, 0U), KERR_KERN_NOERR);

    (void)memset(&got[0], 0, sizeof(got));
    received = &got[0];
    size     = 0U;

    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);

// Zero does NOT mean "copy nothing": mailboxes.c:780 reads it as "I did not say,
// give me the whole message". A caller passing 0 with a buffer smaller than
// oDataEntrySize gets an overflow of its own making, and nothing in the
// signature warns of it. Pinned rather than reported - the alternative reading
// would break every caller that uses 0 to mean "whatever is there".

    QUIRK("mailbox-zero-size-means-full-message", (size == KENTRY_SIZE));
    EXPECT_EQ_U(got[KENTRY_SIZE - 1U], 0x5AU);
}

TEST(mailboxes_copy_mode_tolerates_a_null_destination) {
    mbox_t      *handle;
    uint8_t     sent[KENTRY_SIZE];
    void        *received = nullptr;
    uint32_t    size      = sizeof(sent);

    local_setup();

    handle = local_mailbox("Copy", KNB_PACKS, KENTRY_SIZE);

    EXPECT_EQ_I(kern_writeMailbox(handle, &sent[0], KENTRY_SIZE, 0U), KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);

// The memcpy is guarded by (*message != nullptr), so a null destination
// consumes the pack and reports its size without copying - a "discard" that
// costs nothing. Worth pinning because it is the difference between this and
// reference mode, where a null destination would be the RESULT rather than an
// instruction.

    EXPECT_EQ_U(size, KENTRY_SIZE);
    EXPECT_EQ_U(handle->oNbUsedPacks, 0U);
}

// Blocking and wake-up
// ====================

TEST(mailboxes_a_full_mailbox_asks_the_kernel_to_block) {
    mbox_t      *first;
    mbox_t      *second;
    uint8_t     payload[KNB_PACKS + 1U];
    uint32_t    i;

    local_setup();

    first  = local_mailbox("m0", KNB_PACKS, 0U);
    second = local_mailbox("m1", KNB_PACKS, 0U);
    (void)first;

    for (i = 0U; i < KNB_PACKS; i++) {
        EXPECT_EQ_I(kern_writeMailbox(second, &payload[i], 1U, 0U), KERR_KERN_NOERR);
    }

    vRunning.oInternal.oStatus = KERR_KERN_TIMEO;
    EXPECT_EQ_I(kern_writeMailbox(second, &payload[KNB_PACKS], 1U, 1000U), KERR_KERN_TIMEO);

// A writer blocked on a FULL mailbox uses the _F message; a reader blocked on an
// empty one uses _E. They are different codes because the scheduler parks them
// on the two different wait lists.

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 1U);
    EXPECT_EQ_U(g_kernenv.oLastKernMessage, KKERN_MSG_WAIT_MBOX_F + 1U);
}

TEST(mailboxes_an_empty_mailbox_asks_the_kernel_to_block) {
    mbox_t      *handle;
    void        *received = nullptr;
    uint32_t    size      = 0U;

    local_setup();

    handle = local_mailbox("m0", KNB_PACKS, 0U);

    vRunning.oInternal.oStatus = KERR_KERN_TIMEO;
    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 1000U), KERR_KERN_TIMEO);

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 1U);
    EXPECT_EQ_U(g_kernenv.oLastKernMessage, KKERN_MSG_WAIT_MBOX_E + 0U);
}

TEST(mailboxes_a_reader_resumed_with_success_completes_the_read) {
    mbox_t      *handle;
    uint8_t     payload = 0x42U;
    void        *received = nullptr;
    uint32_t    size      = 0U;

    local_setup();

    handle = local_mailbox("m0", KNB_PACKS, 0U);

// Model the scheduler's side of the handshake: while the reader was blocked a
// writer filled the mailbox, and the reader is resumed with NOERR. The retry
// after the trap is real code and this is the only way to reach it.

    EXPECT_EQ_I(kern_writeMailbox(handle, &payload, 1U, 0U), KERR_KERN_NOERR);
    handle->oState |= (uint16_t)(1U << BMBOX_EMPTY);    // pretend it was empty at entry
    vRunning.oInternal.oStatus = KERR_KERN_NOERR;

    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 1000U), KERR_KERN_NOERR);

    EXPECT_EQ_U(g_kernenv.oNbGotoKern, 1U);
    EXPECT_EQ_PTR(received, &payload);                  // the read really happened
}

TEST(mailboxes_a_write_wakes_a_blocked_reader) {
    mbox_t      *handle;
    uint8_t     payload = 0x42U;

    local_setup();

    handle = local_mailbox("m0", KNB_PACKS, 0U);
    local_addWaiter(&handle->oListEmpty, &vWaiter[0], KPRIO_LOW, BPROC_SUSP_MBOX_E);

    EXPECT_EQ_I(kern_writeMailbox(handle, &payload, 1U, 0U), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oListEmpty.oNbElements, 0U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 1U);
    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_NOERR);
    EXPECT_EQ_U(vWaiter[0].oInternal.oState & (1U << BPROC_SUSP_MBOX_E), 0U);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 0U);           // lower priority
}

TEST(mailboxes_a_read_wakes_a_blocked_writer) {
    mbox_t      *handle;
    uint8_t     payload[KNB_PACKS];
    void        *received = nullptr;
    uint32_t    size      = 0U;
    uint32_t    i;

    local_setup();

    handle = local_mailbox("m0", KNB_PACKS, 0U);
    for (i = 0U; i < KNB_PACKS; i++) {
        EXPECT_EQ_I(kern_writeMailbox(handle, &payload[i], 1U, 0U), KERR_KERN_NOERR);
    }

    local_addWaiter(&handle->oListFull, &vWaiter[0], KPRIO_HIGH, BPROC_SUSP_MBOX_F);

    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_NOERR);

// The two lists are symmetric: a read frees a slot and releases a writer, a
// write fills one and releases a reader.

    EXPECT_EQ_U(handle->oListFull.oNbElements, 0U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 1U);
    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_NOERR);
    EXPECT_EQ_U(g_kernenv.oNbPreemption, 1U);           // higher priority: yield
}

// The ISR arms
// ============

TEST(mailboxes_an_isr_may_poll_but_not_block) {
    mbox_t      *handle;
    uint8_t     payload  = 0x42U;
    void        *received = nullptr;
    uint32_t    size      = 0U;

    local_setup();

    handle = local_mailbox("m0", KNB_PACKS, 0U);
    ukos_fake_setException(true);

// Same rule as kern_waitSemaphore and unlike kern_lockMutex: an ISR may use a
// mailbox as long as it cannot be suspended.

    EXPECT_EQ_I(kern_writeMailbox(handle, &payload, 1U, 1000U), KERR_KERN_FRISR);
    EXPECT_EQ_I(kern_writeMailbox(handle, &payload, 1U, 0U),    KERR_KERN_NOERR);
    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 1000U), KERR_KERN_FRISR);

    ukos_fake_setException(false);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mailboxes_an_isr_does_not_have_its_timeout_parked) {
    mbox_t      *handle;
    uint8_t     payload = 0x42U;

    local_setup();

    handle = local_mailbox("m0", KNB_PACKS, 0U);
    vRunning.oInternal.oTimeout = 4321U;

    ukos_fake_setException(true);
    EXPECT_EQ_I(kern_writeMailbox(handle, &payload, 1U, 0U), KERR_KERN_NOERR);
    ukos_fake_setException(false);

// mailboxes.c guards the timeout store with !IS_EXCEPTION, because an ISR is
// not a process and vKern_runProc points at whoever it interrupted - writing a
// timeout there would corrupt an unrelated process's wait.

    EXPECT_EQ_U(vRunning.oInternal.oTimeout, 4321U);
}

// The read contract
// =================

TEST(mailboxes_read_clears_the_message_only_in_reference_mode) {
    mbox_t      *handle;
    void        *received;
    uint32_t    size = 0U;
    uint8_t     marker;

    local_setup();

    handle = local_mailbox("Ref", KNB_PACKS, 0U);

// Reference mode: *message is cleared before the transfer is attempted, so a
// TIMEO leaves a null rather than a stale pointer.

    received = &marker;
    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_TIMEO);
    EXPECT_EQ_PTR(received, nullptr);

// But NOT on the guards that precede it. A read against an unconfigured mailbox
// returns with *message exactly as the caller left it.
//
// This matters beyond this file: the tier-2 fake (fakes/ukos_fakes_kern.c)
// promises nullptr on ANY error, and the comment in OS/CLI/X/X.c says the same.
// Production is narrower than both. X.c is safe because it returns on the error
// rather than relying on the pointer - but the stated reason is wrong, and a
// future caller trusting it would not be. See DEFECTS.md.

    handle->oState &= (uint16_t)~(1U << BMBOX_CONFIGURED);
    received = &marker;
    EXPECT_EQ_I(kern_readMailbox(handle, &received, &size, 0U), KERR_KERN_MBNCF);
    QUIRK("mailbox-read-message-not-cleared-on-guards", (received == &marker));
}

// Destruction, lookup, accounting
// ===============================

TEST(mailboxes_kill_releases_both_wait_lists) {
    mbox_t  *handle;

    local_setup();

    handle = local_mailbox("Doomed", KNB_PACKS, KENTRY_SIZE);
    local_addWaiter(&handle->oListEmpty, &vWaiter[0], KPRIO_LOW, BPROC_SUSP_MBOX_E);
    local_addWaiter(&handle->oListFull,  &vWaiter[1], KPRIO_LOW, BPROC_SUSP_MBOX_F);

    g_kernenv.oNbFree = 0U;
    EXPECT_EQ_I(kern_killMailbox(handle), KERR_KERN_NOERR);

    EXPECT_EQ_U(handle->oListEmpty.oNbElements, 0U);
    EXPECT_EQ_U(handle->oListFull.oNbElements,  0U);
    EXPECT_EQ_U(vKern_listExec[0].oNbElements, 2U);
    EXPECT_EQ_I(vWaiter[0].oInternal.oStatus, KERR_KERN_MBKIL);
    EXPECT_EQ_I(vWaiter[1].oInternal.oStatus, KERR_KERN_MBKIL);

    EXPECT_EQ_U(g_kernenv.oNbFree, 2U);                 // pack ring and data buffer
    EXPECT_EQ_U(handle->oState, 0U);
    EXPECT_EQ_U(vKern_nbMbox[0], 0U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mailboxes_lookup_finds_by_identifier) {
    mbox_t  *created;
    mbox_t  *found = nullptr;

    local_setup();

    created = local_mailbox("Wanted", KNB_PACKS, 0U);

    EXPECT_EQ_I(kern_getMailboxById("Wanted", &found), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(found, created);

    EXPECT_EQ_I(kern_getMailboxById("Absent", &found), KERR_KERN_NOMBO);
    EXPECT_EQ_PTR(found, nullptr);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
}

TEST(mailboxes_every_entry_point_gives_the_mask_and_the_privilege_back) {
    mbox_t      *handle = nullptr;
    mbox_t      mbox;
    void        *received = nullptr;
    uint32_t    size      = 0U;
    uint8_t     payload   = 0U;
    mcnf_t      configure;

    local_setup();

    (void)memset(&mbox, 0, sizeof(mbox));
    configure.oNbMaxPacks    = 0U;
    configure.oDataEntrySize = 0U;

    (void)kern_createMailbox("x", &handle);
    (void)kern_createMailbox("x", &handle);                      // IDMBO
    (void)kern_setMailbox(&mbox, &configure);                    // NOMBO
    (void)kern_setMailbox(handle, &configure);                   // MBCNF
    (void)kern_writeMailbox(&mbox, &payload, 1U, 0U);            // NOMBO
    (void)kern_writeMailbox(handle, &payload, 1U, 0U);           // MBNCF
    (void)kern_readMailbox(&mbox, &received, &size, 0U);         // NOMBO
    (void)kern_readMailbox(handle, &received, &size, 0U);        // MBNCF
    (void)kern_killMailbox(&mbox);                               // NOMBO
    (void)kern_getMailboxById("absent", &handle);                // NOMBO

    EXPECT_EQ_U(g_kernenv.oDepth, 0U);
    EXPECT_EQ_U(g_kernenv.oNbOff, g_kernenv.oNbRestore);
    EXPECT_EQ_U(g_kernenv.oMaxDepth, 1U);
    EXPECT_TRUE(ukos_fake_interruptsBalanced());
    EXPECT_TRUE(ukos_fake_privilegeBalanced());
}
