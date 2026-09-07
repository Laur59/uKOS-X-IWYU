/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/CLI/X/X.c.
 *
 * Tier 2. The smallest module covered so far, but the only one that caches
 * kernel state ACROSS invocations: it holds static vInitialised[] and
 * vMailBox[], so the first successful lookup is remembered for the rest of the
 * process. Tests therefore run in a deliberate order-independent way - see
 * local_dropCache() below - rather than assuming a fresh module each time.
 *
 * The module's own comments state the contract it depends on: kern_readMailbox
 * stores nullptr in the message pointer on ANY error, because the memcpy that
 * follows would otherwise read from address 0. x_fake_mailbox_contract pins
 * that, because if the claim is wrong the whole suite is fiction.
 */

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <stdlib.h>
#include    <string.h>

#include    "exit_codes.h"
#include    "kern/kern.h"
#include    "kern/mailboxes.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"
#include    "ukos_fakes.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aX_Specifications;

#define KNB_SAMPLES     128U
#define KOK             EXIT_OS_SUCCESS_CLI
#define KFAIL           EXIT_OS_FAILURE

static int32_t local_run(void) {
    const char_t    *argv[] = { "x" };

    return aX_Specifications.oExecution(1U, argv);
}

// A message the module can consume. It memcpy's the whole buffer and then frees
// it, so each run needs its own allocation.

static void local_offerSamples(uint16_t first) {
    uint16_t    *message = (uint16_t *)calloc(KNB_SAMPLES, sizeof(uint16_t));

    for (uint16_t i = 0U; i < KNB_SAMPLES; i++) {
        message[i] = (uint16_t)(first + i);
    }

    g_kern.mailboxMessage = message;
    g_kern.readMailboxRc  = KERR_KERN_NOERR;
}

// Force the module to forget its cached handle.
//
// vInitialised is cleared by every failure path EXCEPT "not installed", so one
// timed-out read is the cheapest way back to a known state. Without this, a
// test that runs after a successful one would never call kern_getMailboxById
// and its assertions about the lookup would silently pass.

static void local_dropCache(void) {

    ukos_t_begin("UTC0");
    g_kern.getMailboxRc  = KERR_KERN_NOERR;
    g_kern.readMailboxRc = KERR_KERN_TIMEO;
    (void)local_run();
    ukos_t_begin("UTC0");
}

// ============================================================================
// The double's own contract
// ============================================================================

TEST(x_fake_mailbox_contract) {
    void        *message = (void *)(uintptr_t)0xDEADBEEFU;
    uint32_t    size     = 8U;
    mbox_t      *handle  = NULL;

    ukos_t_begin("UTC0");

// On success the caller gets the message it was promised.

    g_kern.mailboxMessage = (void *)(uintptr_t)0x1234U;
    g_kern.readMailboxRc  = KERR_KERN_NOERR;
    EXPECT_EQ_I(kern_readMailbox(handle, &message, &size, 10U), KERR_KERN_NOERR);
    EXPECT_EQ_PTR(message, (void *)(uintptr_t)0x1234U);

// On EVERY error it is nullptr, never stale. This is the claim X.c:117-120
// makes about the kernel and relies on to avoid a memcpy from address 0.

    message = (void *)(uintptr_t)0xDEADBEEFU;
    g_kern.readMailboxRc = KERR_KERN_TIMEO;
    EXPECT_TRUE(kern_readMailbox(handle, &message, &size, 10U) != KERR_KERN_NOERR);
    EXPECT_TRUE(message == NULL);

    message = (void *)(uintptr_t)0xDEADBEEFU;
    g_kern.readMailboxRc = -99;
    EXPECT_TRUE(kern_readMailbox(handle, &message, &size, 10U) != KERR_KERN_NOERR);
    EXPECT_TRUE(message == NULL);
}

// ============================================================================
// Module metadata
// ============================================================================

TEST(x_module_metadata) {

    ukos_t_begin("UTC0");

    EXPECT_EQ_U(aX_Specifications.oIdModule,
                (((uint32_t)KID_FAM_CLI << 24U) | ((uint32_t)KNUM_X << 8U) | (uint32_t)(uint8_t)'_'));
    EXPECT_TRUE(aX_Specifications.oExecution != NULL);
}

// ============================================================================
// The happy path
// ============================================================================

TEST(x_prints_the_samples) {
    int32_t     status;

    local_dropCache();
    local_offerSamples(100U);

    status = local_run();

    EXPECT_EQ_I(status, KOK);

// "x," then every sample comma-separated, the last one terminating the line.

    EXPECT_TRUE(strncmp(&g_fakes.out[0], "x,100,101,102,", 14U) == 0);
    EXPECT_OUT_HAS(",227\n");
    EXPECT_EQ_U(g_fakes.dprintfCalls, KNB_SAMPLES + 1U);
}

TEST(x_frees_the_message) {
    void        *offered;

    local_dropCache();
    local_offerSamples(0U);
    offered = g_kern.mailboxMessage;

    (void)local_run();

// The buffer belongs to the caller once read, so it must be released - and
// released exactly once. ASan would see a double free or a leak.

    EXPECT_EQ_U(g_kern.freeCalls, 1U);
    EXPECT_EQ_PTR(g_kern.lastFreed, offered);
}

TEST(x_asks_for_the_temperature_mailbox) {

    local_dropCache();
    local_offerSamples(0U);

    (void)local_run();

    EXPECT_EQ_U(g_kern.getMailboxCalls, 1U);
    EXPECT_EQ_STR(g_kern.lastMailboxId, "Temperature");
    EXPECT_EQ_U(g_kern.lastMailboxTimeout, 10000U);
}

// ============================================================================
// The cache
// ============================================================================

TEST(x_looks_the_mailbox_up_once) {

    local_dropCache();
    local_offerSamples(0U);
    (void)local_run();
    EXPECT_EQ_U(g_kern.getMailboxCalls, 1U);

// The handle is cached in a static, so a second successful call must not look
// it up again.

    ukos_t_begin("UTC0");
    local_offerSamples(0U);
    (void)local_run();

    EXPECT_EQ_U(g_kern.getMailboxCalls, 0U);
    EXPECT_EQ_U(g_kern.readMailboxCalls, 1U);
}

TEST(x_drops_the_cache_after_a_timeout) {

    local_dropCache();
    local_offerSamples(0U);
    (void)local_run();                                  // caches the handle

    ukos_t_begin("UTC0");
    g_kern.readMailboxRc = KERR_KERN_TIMEO;
    (void)local_run();                                  // clears vInitialised

// The next call must look the mailbox up again rather than reuse a handle to a
// mailbox that may have gone.

    ukos_t_begin("UTC0");
    local_offerSamples(0U);
    (void)local_run();

    EXPECT_EQ_U(g_kern.getMailboxCalls, 1U);
}

TEST(x_drops_the_cache_after_an_unexpected_status) {

    local_dropCache();
    local_offerSamples(0U);
    (void)local_run();

    ukos_t_begin("UTC0");
    g_kern.readMailboxRc = -99;
    (void)local_run();

// Same recovery as the timeout path. Without it the module would answer
// "mbox problem" for ever once the producer had been restarted.

    ukos_t_begin("UTC0");
    local_offerSamples(0U);
    (void)local_run();

// Deliberately no further run here: the module frees the message it was given,
// so calling again without offering a fresh one would be a use-after-free in
// the TEST, not in the module.

    EXPECT_EQ_U(g_kern.getMailboxCalls, 1U);
    EXPECT_OUT_HAS("x,");
}

// ============================================================================
// The failure paths
// ============================================================================

TEST(x_reports_a_missing_producer) {
    int32_t     status;

    local_dropCache();
    g_kern.getMailboxRc = KERR_KERN_NOMBO;

    status = local_run();

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS("Process Temperature not installed!\n");
    EXPECT_EQ_U(g_kern.readMailboxCalls, 0U);
}

TEST(x_retries_the_lookup_after_a_missing_producer) {

    local_dropCache();
    g_kern.getMailboxRc = KERR_KERN_NOMBO;
    (void)local_run();

// vInitialised is never set on this path, so the next call retries rather than
// caching a null handle.

    ukos_t_begin("UTC0");
    local_offerSamples(0U);
    (void)local_run();

    EXPECT_EQ_U(g_kern.getMailboxCalls, 1U);
    EXPECT_OUT_HAS("x,");
}

TEST(x_reports_a_killed_producer) {
    int32_t     status;

    local_dropCache();
    g_kern.readMailboxRc = KERR_KERN_TIMEO;

    status = local_run();

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS("The process Temperature was killed!\n");
    EXPECT_EQ_U(g_kern.freeCalls, 0U);
    EXPECT_EQ_U(g_kern.logCalls, 0U);
}

TEST(x_reports_an_unexpected_status_and_logs_it) {
    int32_t     status;

    local_dropCache();
    g_kern.readMailboxRc = -99;

    status = local_run();

    EXPECT_EQ_I(status, KFAIL);
    EXPECT_OUT_IS("mbox problem\n");

// KERROR rather than KFATAL on purpose: a record above Info makes a post-flash
// health check report the board as failed, and nothing actually dies here.

    EXPECT_EQ_U(g_kern.logCalls, 1U);
    EXPECT_EQ_U(g_kern.lastLogCategory, (uint32_t)KERROR_USER);
    EXPECT_EQ_STR(g_kern.lastLogMessage, "x: mbox problem");
}

TEST(x_never_reads_the_message_on_a_failure) {

    local_dropCache();
    g_kern.readMailboxRc  = KERR_KERN_TIMEO;
    g_kern.mailboxMessage = NULL;

    ukos_t_poisonStack();

// The contract test above proves the fake hands back nullptr on error; this
// proves the module does not reach the memcpy that would dereference it.

    EXPECT_EQ_I(local_run(), KFAIL);
    EXPECT_EQ_U(g_kern.freeCalls, 0U);
    EXPECT_OUT_LACKS("x,");
}

TEST(x_takes_no_arguments) {
    const char_t    *argv[] = { "x", "junk" };

    local_dropCache();
    local_offerSamples(0U);

    EXPECT_EQ_I(aX_Specifications.oExecution(2U, argv), KOK);
    EXPECT_OUT_HAS("x,");
}
