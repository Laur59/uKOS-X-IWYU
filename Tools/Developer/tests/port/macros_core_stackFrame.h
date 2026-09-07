/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host stub for Ports/EquatesModels/Cores/<CORE>/Includes/macros_core_stackFrame.h.
 *
 * The real header is the context-switch frame layout - KERN_SAVE_FRAME,
 * KERN_NEW_FRAME, KERN_PREPARE_FRAME - all inline assembly and all meaningless
 * off-target. The only thing a CLI module takes from it is a stack-size
 * constant, so that is all this defines.
 *
 * The value is the CORTEX_M7 one. szkern multiplies it into the reported bss
 * figure; no test asserts that figure, because it is a per-core number and
 * asserting it here would only pin the stub.
 */

#ifndef UKOS_PORT_STUB_MACROS_CORE_STACKFRAME_H
#define UKOS_PORT_STUB_MACROS_CORE_STACKFRAME_H     1


#include    <stdint.h>
#ifndef KKERN_SZ_STACK_SS
#define KKERN_SZ_STACK_SS           200U
#endif

// Blocking into the uKernel
// =========================
//
// THE BIGGEST FIDELITY GAP IN THIS TIER, and the one to read before trusting a
// result from it.
//
// On a target GOTO_KERN_M / GOTO_KERN_I push a message and issue an SVC. The
// call DOES NOT RETURN: the scheduler takes the process off the run list, parks
// it on the object's wait list, runs somebody else, and comes back only when
// the process is rescheduled - at which point the caller reads
// vKern_runProc[core]->oInternal.oStatus to learn why.
//
// Here it records the message and returns immediately. So:
//
//   - tested: that the kernel decided to block, which message code it chose,
//     and the code that runs AFTER resumption - the caller reads the status the
//     test seeded exactly as it would read the one the scheduler set. The
//     counter arithmetic on both sides of the trap is real.
//   - NOT tested: the suspension. The process is not taken off any list and not
//     parked on the object\'s wait list, so a test that needs a waiter must put
//     it there itself with lists_connect(). Nothing here proves the scheduler
//     would do the same.
//
// Deliberately not a silent no-op: it is counted and the message recorded, so a
// test asserts the decision rather than assuming it.

#ifndef GOTO_KERN_M
#define GOTO_KERN_M(msg)        ukos_fake_gotoKern((uint32_t)(msg))
#endif

#ifndef GOTO_KERN_I
#define GOTO_KERN_I(msg)        ukos_fake_gotoKern((uint32_t)(msg))
#endif

extern  void        ukos_fake_gotoKern(uint32_t message);

#endif
