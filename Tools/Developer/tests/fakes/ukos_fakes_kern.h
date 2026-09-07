/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Test doubles for the kernel-side services reached through the port stubs.
 *
 * Linked only into ukos_port_support, so a tier-1 suite never grows by them.
 */

#ifndef UKOS_FAKES_KERN_H
#define UKOS_FAKES_KERN_H

#include    <stdbool.h>
#include    <stddef.h>
#include    <stdint.h>

#include    "kern/kern.h"
#include    "kern/processes.h"
#include    "types.h"

#define KUKOS_FAKE_MAX_PRIV     64U
#define KUKOS_FAKE_MAX_PROC     16U

// Privilege transitions
//
// PRIVILEGE_ELEVATE / PRIVILEGE_RESTORE expand to kern_setPrivilegeMode() when
// PRIVILEGED_USER_S is defined, so a test can assert that a module elevates
// before touching a kernel table and restores on every return path. The trace
// records the order, which is what catches an unbalanced early return.

typedef struct {
    unsigned    calls;
    unsigned    elevates;
    unsigned    restores;
    uint8_t     trace[KUKOS_FAKE_MAX_PRIV];         // KPROC_PRIVILEGED / KPROC_USER
    unsigned    traceLen;
    uint32_t    core;                               // what GET_RUNNING_CORE returns

// kern_criticalSection()

// memo_malloc() / memo_delayedFree()
//
// failNext is the ONLY route to dumplog's and dumptrace's "Not enough memory."
// branch - unlike the dead error arms in mutex and object, that one is genuinely
// reachable, and only by making the allocator fail.

    unsigned    mallocCalls;
    unsigned    freeCalls;
    bool        failNextMalloc;
    uint32_t    lastMallocSize;
    const char  *lastMallocId;
    void        *lastFreed;

// kern_getMailboxById() / kern_readMailbox()
//
// readOut is deliberately NOT a free choice: the module documents, and relies
// on, kern_readMailbox() storing nullptr in the message pointer on ANY error -
// its memcpy would otherwise read from address 0. The fake reproduces that, and
// x_fake_mailbox_contract pins it.

    unsigned    getMailboxCalls;
    int32_t     getMailboxRc;
    const char  *lastMailboxId;
    unsigned    readMailboxCalls;
    int32_t     readMailboxRc;
    uint32_t    lastMailboxTimeout;
    void        *mailboxMessage;                    // handed back on success

// record_log()

    unsigned    logCalls;
    uint32_t    lastLogCategory;
    const char  *lastLogMessage;

// serial_read() - the seam that turns the loaders into ordinary parsers.
//
// chunk defaults to 1 byte per read, and that is load bearing. local_getByte()
// keeps static vBuffer/vI/vSize that survive across prgm() calls in one
// process; serving exactly one byte per read drives vSize back to zero after
// every byte, so the statics are always clean at a byte boundary and ONE TEST
// CANNOT LEAK BUFFERED INPUT INTO THE NEXT.
//
// rcExhausted defaults to a framing error rather than "no bytes, no error",
// because local_getByte() spins on do/while(vSize == 0) and would hang forever
// on the latter. A test wanting the clean path terminates its stream properly.

    unsigned        serialReadCalls;
    const uint8_t   *serialData;
    uint32_t        serialLen, serialPos, serialChunk;
    int32_t         serialRc, serialRcExhausted;
    unsigned        serialReserveCalls, serialReleaseCalls, serialFlushCalls;

// system_reserve() / system_getSystemSignature()

    unsigned    systemReserveCalls;
    int32_t     systemReserveRc;
    const char  *systemSignature;

// led / scheduler no-ops, counted only

    unsigned    ledOffCalls, ledToggleCalls, suspendCalls, switchFastCalls;
    uint32_t    lastSuspend;

    unsigned    criticalEnters;
    unsigned    criticalExits;
    int         criticalDepth;                      // never negative, never above 1
    bool        criticalUnbalanced;
} ukos_fakesKern_t;

extern  ukos_fakesKern_t    g_kern;

// true when every elevate was matched by a restore, in order and without nesting

extern  bool    ukos_fake_privilegeBalanced(void);

// Place the four kernel sections. They are only differenced and printed, never
// dereferenced, so any address will do - including one that would fault, and
// including an end below its start.

// A pool of processes to hang off object lists. The identifier is all any CLI
// module reads, so nothing else is populated.

extern  proc_t  *ukos_fake_addProcess(const char_t *identifier);

// Seed one mutex slot. A slot whose identifier stays NULL is skipped by the
// module, which is how an empty table is expressed.

extern  void    ukos_fake_addMutex(uint32_t core, uint16_t slot, const char_t *identifier,
                                   int32_t counter, proc_t *owner);

extern  void    ukos_fake_addSemaphore(uint32_t core, uint16_t slot, const char_t *identifier,
                                       int32_t counter, proc_t *owner);

// Hang processes off an object's waiting list.
//
// oFirst, oLast, oNbElements AND the oObject.oForward chain must all agree: the
// modules read oNbElements and then follow oForward exactly that many times, so
// seeding one without the others would only prove the fake wrong.

extern  void    ukos_fake_attachWaiters(list_t *list, proc_t *const *procs, uint16_t nb);

// Seed one log record. A record whose timestamp stays 0 terminates the scan, so
// an empty buffer is expressed by seeding nothing.

extern  void    ukos_fake_addLog(uint32_t core, uint16_t slot, uint32_t category,
                                 uint64_t timeStamp, const char_t *identifier,
                                 const char_t *function, uint32_t line,
                                 const char_t *message);

// Seed one trace record. Unlike the log, the trace is a ring: the read pointer
// and the write count are separate state, and ukos_fake_setTraceRead() must be
// given a real pointer into the fake array because the module rebases it by
// pointer DIFFERENCE, not by index.

extern  void    ukos_fake_addTrace(uint32_t core, uint16_t slot, uint64_t timeStamp,
                                   uintptr_t parameter, proc_t *process,
                                   const char_t *message);

extern  void    ukos_fake_setTraceRead(uint32_t core, uint16_t slot, uint32_t nbWrites);

// Point the downloadable-application window at a buffer the test owns.

extern  void    ukos_fake_setUserMemory(void *base, size_t length);

// Feed the loaders their input stream.

extern  void    ukos_fake_feedSerial(const void *data, uint32_t length);
extern  void    ukos_fake_feedSerialText(const char *stream);

extern  void    ukos_fake_setKernelImage(uintptr_t text,   uint32_t lnText,
                                         uintptr_t rodata, uint32_t lnRodata,
                                         uintptr_t data,   uint32_t lnData,
                                         uintptr_t bss,    uint32_t lnBss);

#endif
