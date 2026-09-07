/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host stub for Ports/EquatesModels/Cores/<CORE>/Includes/macros_core.h.
 *
 * The real header exists in nine per-core variants and is almost entirely
 * inline assembly - privilege transitions, interrupt masking, context-switch
 * frames, exception vectors. None of that is reachable from a CLI module, and
 * none of it can run on a host.
 *
 * This stub therefore defines the ONLY two macros the CLI modules use, copied
 * verbatim from the CORTEX_M7 header. run-tests.sh diffs the copy against that
 * original and aborts on divergence.
 *
 * What it buys and what it does not: the copy makes PRIVILEGE_ELEVATE and
 * PRIVILEGE_RESTORE call the real kern_setPrivilegeMode(), so a test can assert
 * that a module elevates before touching a kernel table and restores on EVERY
 * return path. It asserts pairing and count, never effect - nothing here says
 * CONTROL.nPRIV changes, that the SVC dispatch works, or that an unelevated
 * access faults. Those belong to the board.
 *
 * Everything else the real header defines is deliberately absent, so a module
 * that needs one fails to build instead of silently testing a fiction.
 */

#ifndef UKOS_PORT_STUB_MACROS_CORE_H
#define UKOS_PORT_STUB_MACROS_CORE_H    1


#include    <stdbool.h>
#include    "kern/kern.h"
#include    "macros_soc.h"

// --- BEGIN drift-checked copy: Cores/CORTEX_M7/Includes/macros_core.h

#ifndef PRIVILEGE_ELEVATE
#ifdef PRIVILEGED_USER_S
#define PRIVILEGE_ELEVATE       kern_setPrivilegeMode(KPROC_PRIVILEGED)

#else
#define PRIVILEGE_ELEVATE
#endif
#endif

#ifndef PRIVILEGE_RESTORE
#ifdef PRIVILEGED_USER_S
#define PRIVILEGE_RESTORE       kern_setPrivilegeMode(KPROC_USER)

#else
#define PRIVILEGE_RESTORE
#endif
#endif

// --- END drift-checked copy

// Execution context
// =================
//
// IS_EXCEPTION is (SCB->ICSR & 0x1FF) != 0 on a Cortex-M - "am I inside an
// interrupt handler?". A settable flag here, which is a gain rather than a
// loss: it is the ONLY way to reach the KERR_KERN_FRISR arms of the
// synchronisation primitives, which on a target need a real ISR to enter.
//
// Outside the drift-checked block on purpose - this is an invention, not a copy
// of an override-sanctioned definition, so it is pinned by test_kernenv.c
// instead.

#ifndef IS_EXCEPTION
#define IS_EXCEPTION            ukos_fake_isException()
#endif

// PREEMPTION pends PendSV and executes an sev plus three barriers, so the
// scheduler runs the moment the mask lifts. Nothing of that exists here, so the
// fake counts requests: a test asserts that the kernel DECIDED a preemption was
// due - after waking a higher-priority process - never that a switch happened.

#ifndef PREEMPTION
#define PREEMPTION              ukos_fake_preemption()
#endif

extern  bool        ukos_fake_isException(void);
extern  void        ukos_fake_preemption(void);

#endif
