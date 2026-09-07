/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Test doubles for the kernel-side services reached through the port stubs.
 */

#include    "ukos_fakes_kern.h"

#include    <stdbool.h>
#include    <stdint.h>
#include    <stdlib.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "kern/mailboxes.h"
#include    "led/led.h"
#include    "serial/serial.h"
#include    "system/system.h"
#include    "os_errors.h"
#include    "kern/private/private_mailboxes.h"
#include    "kern/private/private_mutexes.h"
#include    "kern/private/private_preciseSignals.h"
#include    "kern/private/private_processes.h"
#include    "kern/private/private_semaphores.h"
#include    "kern/private/private_signals.h"
#include    "kern/private/private_softwareTimer.h"
#include    "memo/memo.h"
#include    "record/private/private_record.h"
#include    "record/record.h"
#include    "kern/processes.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "ukos_test.h"
#include    "ukos_test_priv.h"

// The port stubs must win over the real per-core / per-SoC headers. They are not
// resolvable on the tier-1 include path at all, so this can only fire if the
// include order is ever rearranged - in which case it is a build error rather
// than a suite that silently tests the wrong thing.

#if !defined(UKOS_PORT_STUB_MACROS_CORE_H) || !defined(UKOS_PORT_STUB_MACROS_SOC_H)
#error "the real macros_core.h / macros_soc.h was resolved; port/ must come first"
#endif

ukos_fakesKern_t    g_kern;

// The kernel object tables the CLI modules walk. On a target these live in the
// kernel's bss and are filled by kern_createObject(); here a test seeds exactly
// the entries it wants to see rendered.

mutx_t              vKern_mutx[KNB_CORES][KKERN_NB_MUTEXES];
sema_t              vKern_sema[KNB_CORES][KKERN_NB_SEMAPHORES];
proc_t              vKern_proc[KNB_CORES][KKERN_NB_PROCESSES];
mbox_t              vKern_mbox[KNB_CORES][KKERN_NB_MAILBOXES];
sign_t              vKern_sign[KNB_CORES][KKERN_NB_SIGNALS];

#if (KKERN_NB_SOFTWARE_TIMERS > 0)
stim_t              vKern_stim[KNB_CORES][KKERN_NB_SOFTWARE_TIMERS];
#endif

#if (KKERN_NB_PRECISE_SIGNALS > 0)
prcs_t              vKern_prcs[KNB_CORES][KKERN_NB_PRECISE_SIGNALS];
#endif

// The in-use and high-water counters. object prints these directly, so a test
// assigns them rather than going through a helper - they are plain arrays and
// the private headers already declare them.

uint16_t            vKern_nbProc[KNB_CORES],  vKern_nbMaxProc[KNB_CORES];
uint16_t            vKern_nbSema[KNB_CORES],  vKern_nbMaxSema[KNB_CORES];
uint16_t            vKern_nbMutx[KNB_CORES],  vKern_nbMaxMutx[KNB_CORES];
uint16_t            vKern_nbMbox[KNB_CORES],  vKern_nbMaxMbox[KNB_CORES];
uint16_t            vKern_nbSign[KNB_CORES],  vKern_nbMaxSign[KNB_CORES];
uint16_t            vKern_nbStim[KNB_CORES],  vKern_nbMaxStim[KNB_CORES];
uint16_t            vKern_nbPrcs[KNB_CORES],  vKern_nbMaxPrcs[KNB_CORES];

// The record buffers. dumplog and dumptrace copy these under a critical section
// before rendering, so the test seeds the source and the module works on its own
// snapshot - exactly as on a target.

recordLogging_t     vRecord_logBuffer[KNB_CORES][KRECORD_SZ_LOG_BUF];
uint32_t            vRecord_NbLogWrites[KNB_CORES];

recordTracing_t     vRecord_traceFifo[KNB_CORES][KRECORD_SZ_TRACE_FIFO];
recordTracing_t     *vRecord_RTraceFifo[KNB_CORES];
recordTracing_t     *vRecord_WTraceFifo[KNB_CORES];
uint32_t            vRecord_NbTraceWrites[KNB_CORES];

static  proc_t      vProcPool[KUKOS_FAKE_MAX_PROC];
static  unsigned    vNbProc;

proc_t *ukos_fake_addProcess(const char_t *identifier) {
    proc_t  *process;

    if (vNbProc >= KUKOS_FAKE_MAX_PROC) {
        return NULL;
    }

    process = &vProcPool[vNbProc];
    vNbProc++;

    process->oSpecification.oIdentifier = identifier;
    process->oObject.oForward           = NULL;
    return process;
}

void ukos_fake_addMutex(uint32_t core, uint16_t slot, const char_t *identifier,
                        int32_t counter, proc_t *owner) {

    if ((core >= KNB_CORES) || (slot >= KKERN_NB_MUTEXES)) {
        return;
    }

    vKern_mutx[core][slot].oIdentifier = identifier;
    vKern_mutx[core][slot].oCounter    = counter;
    vKern_mutx[core][slot].oOwner      = owner;
}

void ukos_fake_addSemaphore(uint32_t core, uint16_t slot, const char_t *identifier,
                            int32_t counter, proc_t *owner) {

    if ((core >= KNB_CORES) || (slot >= KKERN_NB_SEMAPHORES)) {
        return;
    }

    vKern_sema[core][slot].oIdentifier = identifier;
    vKern_sema[core][slot].oCounter    = counter;
    vKern_sema[core][slot].oOwner      = owner;
}

void ukos_fake_attachWaiters(list_t *list, proc_t *const *procs, uint16_t nb) {

    list->oFirst      = (nb > 0U) ? procs[0]      : NULL;
    list->oLast       = (nb > 0U) ? procs[nb - 1U] : NULL;
    list->oNbElements = nb;

    for (uint16_t i = 0U; i < nb; i++) {
        procs[i]->oObject.oForward = ((i + 1U) < nb) ? procs[i + 1U] : NULL;
    }
}

void ukos_fake_addLog(uint32_t core, uint16_t slot, uint32_t category,
                      uint64_t timeStamp, const char_t *identifier,
                      const char_t *function, uint32_t line, const char_t *message) {

    if ((core >= KNB_CORES) || (slot >= KRECORD_SZ_LOG_BUF)) {
        return;
    }

    vRecord_logBuffer[core][slot].oLogCategory = (recordLogCategory_t)category;
    vRecord_logBuffer[core][slot].oMark        = false;
    vRecord_logBuffer[core][slot].oTimeStamp   = timeStamp;
    vRecord_logBuffer[core][slot].oIdentifier  = identifier;
    vRecord_logBuffer[core][slot].oFunction    = function;
    vRecord_logBuffer[core][slot].oLineNumber  = line;
    vRecord_logBuffer[core][slot].oMessage     = message;
}

void ukos_fake_addTrace(uint32_t core, uint16_t slot, uint64_t timeStamp,
                        uintptr_t parameter, proc_t *process, const char_t *message) {

    if ((core >= KNB_CORES) || (slot >= KRECORD_SZ_TRACE_FIFO)) {
        return;
    }

    vRecord_traceFifo[core][slot].oTimeStamp = timeStamp;
    vRecord_traceFifo[core][slot].oParameter = parameter;
    vRecord_traceFifo[core][slot].oProcess   = process;
    vRecord_traceFifo[core][slot].oMessage   = message;
}

void ukos_fake_setTraceRead(uint32_t core, uint16_t slot, uint32_t nbWrites) {

    if ((core >= KNB_CORES) || (slot >= KRECORD_SZ_TRACE_FIFO)) {
        return;
    }

    vRecord_RTraceFifo[core]    = &vRecord_traceFifo[core][slot];
    vRecord_NbTraceWrites[core] = nbWrites;
}

// calloc-backed rather than a static arena, so ASan guards the module's writes
// into the block and sees a use-after-free if it ever renders after the free.

void *memo_malloc([[maybe_unused]] memoAlignement_t alignement, uint32_t size,
                  const char_t *identifier) {

    g_kern.mallocCalls++;
    g_kern.lastMallocSize = size;
    g_kern.lastMallocId   = identifier;

    if (g_kern.failNextMalloc) {
        g_kern.failNextMalloc = false;
        return NULL;
    }
    return calloc(1U, (size_t)size);
}

void memo_delayedFree(void *address) {

    g_kern.freeCalls++;
    g_kern.lastFreed = address;
    free(address);
}

// A single opaque handle is enough: the module only stores what it is given and
// hands it straight back.

static  mbox_t      vFakeMailbox;

int32_t kern_getMailboxById(const char_t *identifier, mbox_t **handle) {

    g_kern.getMailboxCalls++;
    g_kern.lastMailboxId = identifier;

    if (g_kern.getMailboxRc != 0) {
        *handle = NULL;
        return g_kern.getMailboxRc;
    }

    *handle = &vFakeMailbox;
    return KERR_KERN_NOERR;
}

int32_t kern_readMailbox([[maybe_unused]] mbox_t *handle, void **message,
                         [[maybe_unused]] uint32_t *size, uint32_t timeout) {

    g_kern.readMailboxCalls++;
    g_kern.lastMailboxTimeout = timeout;

// The contract the caller depends on: nullptr on ANY error, never a stale or
// uninitialised pointer.

    if (g_kern.readMailboxRc != KERR_KERN_NOERR) {
        *message = NULL;
        return g_kern.readMailboxRc;
    }

    *message = g_kern.mailboxMessage;
    return KERR_KERN_NOERR;
}

int32_t record_log(recordLogCategory_t category, [[maybe_unused]] uint32_t line,
                   [[maybe_unused]] const char_t *function, const char_t *message) {

    g_kern.logCalls++;
    g_kern.lastLogCategory = (uint32_t)category;
    g_kern.lastLogMessage  = message;
    return 0;
}

void memo_free(void *address) {

    g_kern.freeCalls++;
    g_kern.lastFreed = address;
    free(address);
}

// serial - the loader input seam
// ==============================

void ukos_fake_feedSerial(const void *data, uint32_t length) {

    g_kern.serialData = (const uint8_t *)data;
    g_kern.serialLen  = length;
    g_kern.serialPos  = 0U;
}

void ukos_fake_feedSerialText(const char *stream) {

    ukos_fake_feedSerial(stream, (uint32_t)strlen(stream));
}

int32_t serial_read([[maybe_unused]] serialManager_t manager, uint8_t *buffer, uint32_t *size) {
    uint32_t    wanted, available, served;

    g_kern.serialReadCalls++;

    wanted    = (g_kern.serialChunk < *size) ? g_kern.serialChunk : *size;
    available = g_kern.serialLen - g_kern.serialPos;

    if (available == 0U) {
        *size = 0U;
        return g_kern.serialRcExhausted;
    }

    served = (wanted < available) ? wanted : available;

    for (uint32_t i = 0U; i < served; i++) {
        buffer[i] = g_kern.serialData[g_kern.serialPos + i];
    }

    g_kern.serialPos += served;
    *size = served;
    return g_kern.serialRc;
}

int32_t serial_reserve([[maybe_unused]] serialManager_t manager,
                       [[maybe_unused]] reserveMode_t mode,
                       [[maybe_unused]] uint32_t timeout) {

    g_kern.serialReserveCalls++;
    return KERR_SERIAL_NOERR;
}

int32_t serial_release([[maybe_unused]] serialManager_t manager,
                       [[maybe_unused]] reserveMode_t mode) {

    g_kern.serialReleaseCalls++;
    return KERR_SERIAL_NOERR;
}

int32_t serial_flush([[maybe_unused]] serialManager_t manager) {

    g_kern.serialFlushCalls++;
    return KERR_SERIAL_NOERR;
}

// system / peripheral no-ops
// =========================

int32_t system_reserve([[maybe_unused]] reserveMode_t mode, [[maybe_unused]] uint32_t timeout) {

    g_kern.systemReserveCalls++;
    return g_kern.systemReserveRc;
}

int32_t system_getSystemSignature(const char_t **signature) {

    *signature = g_kern.systemSignature;
    return KERR_SYSTEM_NOERR;
}

int32_t led_off([[maybe_unused]] uint8_t led)    { g_kern.ledOffCalls++;    return 0; }
int32_t led_toggle([[maybe_unused]] uint8_t led) { g_kern.ledToggleCalls++; return 0; }
int32_t kern_switchFast(void)                    { g_kern.switchFastCalls++; return 0; }

int32_t kern_suspendProcess(uint32_t time) {

    g_kern.suspendCalls++;
    g_kern.lastSuspend = time;
    return 0;
}

int32_t kern_criticalSection(uint8_t mode) {

    if (mode == KENTER_CRITICAL) {
        g_kern.criticalEnters++;
        g_kern.criticalDepth++;
    }
    else {
        g_kern.criticalExits++;
        g_kern.criticalDepth--;
    }

    if ((g_kern.criticalDepth < 0) || (g_kern.criticalDepth > 1)) {
        g_kern.criticalUnbalanced = true;
    }
    return 0;
}

uint32_t ukos_fake_runningCore(void) {

    return g_kern.core;
}

int32_t kern_setPrivilegeMode(uint8_t mode) {

    g_kern.calls++;

    if (mode == KPROC_PRIVILEGED) { g_kern.elevates++; }
    else                          { g_kern.restores++; }

    if (g_kern.traceLen < KUKOS_FAKE_MAX_PRIV) {
        g_kern.trace[g_kern.traceLen] = mode;
        g_kern.traceLen++;
    }
    return 0;
}

bool ukos_fake_privilegeBalanced(void) {
    int depth = 0;

    for (unsigned i = 0U; i < g_kern.traceLen; i++) {
        depth += (g_kern.trace[i] == KPROC_PRIVILEGED) ? 1 : -1;

        if ((depth < 0) || (depth > 1)) {
            return false;                           // restored without elevating, or nested
        }
    }
    return (depth == 0);
}

// Registered from a constructor rather than called by ukos_t_begin() directly:
// the harness must not depend on the port library, and a weak symbol across two
// static archives resolves by link order on Mach-O.

static void local_reset(void) {

    (void)memset(&g_kern,      0, sizeof g_kern);

// Defaults that are part of the seam's contract, not arbitrary choices - see
// the comment on serialChunk in the header.

    g_kern.serialChunk       = 1U;
    g_kern.serialRc          = KERR_SERIAL_NOERR;
    g_kern.serialRcExhausted = KERR_SERIAL_ERFRA;
    g_kern.systemSignature   = "uKOS-X-signature";
    (void)memset(&vKern_mutx,  0, sizeof vKern_mutx);
    (void)memset(&vKern_sema,  0, sizeof vKern_sema);
    (void)memset(&vKern_proc,  0, sizeof vKern_proc);
    (void)memset(&vKern_mbox,  0, sizeof vKern_mbox);
    (void)memset(&vKern_sign,  0, sizeof vKern_sign);

    #if (KKERN_NB_SOFTWARE_TIMERS > 0)
    (void)memset(&vKern_stim,  0, sizeof vKern_stim);
    #endif

    #if (KKERN_NB_PRECISE_SIGNALS > 0)
    (void)memset(&vKern_prcs,  0, sizeof vKern_prcs);
    #endif

    (void)memset(&vKern_nbProc, 0, sizeof vKern_nbProc); (void)memset(&vKern_nbMaxProc, 0, sizeof vKern_nbMaxProc);
    (void)memset(&vKern_nbSema, 0, sizeof vKern_nbSema); (void)memset(&vKern_nbMaxSema, 0, sizeof vKern_nbMaxSema);
    (void)memset(&vKern_nbMutx, 0, sizeof vKern_nbMutx); (void)memset(&vKern_nbMaxMutx, 0, sizeof vKern_nbMaxMutx);
    (void)memset(&vKern_nbMbox, 0, sizeof vKern_nbMbox); (void)memset(&vKern_nbMaxMbox, 0, sizeof vKern_nbMaxMbox);
    (void)memset(&vKern_nbSign, 0, sizeof vKern_nbSign); (void)memset(&vKern_nbMaxSign, 0, sizeof vKern_nbMaxSign);
    (void)memset(&vKern_nbStim, 0, sizeof vKern_nbStim); (void)memset(&vKern_nbMaxStim, 0, sizeof vKern_nbMaxStim);
    (void)memset(&vKern_nbPrcs, 0, sizeof vKern_nbPrcs); (void)memset(&vKern_nbMaxPrcs, 0, sizeof vKern_nbMaxPrcs);

    (void)memset(&vRecord_logBuffer,   0, sizeof vRecord_logBuffer);
    (void)memset(&vRecord_NbLogWrites, 0, sizeof vRecord_NbLogWrites);

    (void)memset(&vRecord_traceFifo,     0, sizeof vRecord_traceFifo);
    (void)memset(&vRecord_NbTraceWrites, 0, sizeof vRecord_NbTraceWrites);

    for (uint32_t c = 0U; c < KNB_CORES; c++) {
        vRecord_RTraceFifo[c] = &vRecord_traceFifo[c][0];
        vRecord_WTraceFifo[c] = &vRecord_traceFifo[c][0];
    }
    (void)memset(&vProcPool,   0, sizeof vProcPool);
    vNbProc = 0U;
}

__attribute__((constructor)) static void local_register(void) {

    ukos_t_addResetHook(local_reset);
    g_ukos_t_tierNote = "[port stubs: macros_core macros_soc macros_core_stackFrame linker; kernel tables faked]";
}
