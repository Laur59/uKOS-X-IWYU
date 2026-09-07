/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host stub for Ports/EquatesModels/SOCs/<SOC>/Includes/macros_soc.h.
 *
 * The real header exists in eleven per-SoC variants, but the CLI modules use
 * only the four definitions below; everything else in it is interrupt-priority
 * constants and MMIO. GET_RUNNING_CORE in particular is an MMIO read on a
 * multi-core SoC (the RP2350 reads SIO->CPUID), which is why it becomes a
 * settable function here rather than a constant - the core index still flows
 * through every vXxx[core] subscript exactly as it does on the target.
 *
 * KNB_CORES is 1U because every shipped uKOS-X SoC is single core; STM32H747
 * even #errors above 1. A suite may override it through DEFINES to exercise the
 * per-core loops in mutex / semaphore / object, but that is a DELIBERATE
 * DIVERGENCE from every board and must be commented at the call site.
 */

#ifndef UKOS_PORT_STUB_MACROS_SOC_H
#define UKOS_PORT_STUB_MACROS_SOC_H     1

#include    <stdint.h>

#ifndef KNB_CORES
#define KNB_CORES               1U
#endif

#define KCORE_0                 0U

#ifndef GET_RUNNING_CORE
#define GET_RUNNING_CORE        ukos_fake_runningCore()
#endif

#ifndef MCSET
#if   (KNB_CORES == 1U)
#define MCSET(v)                { (v) }
#elif (KNB_CORES == 2U)
#define MCSET(v)                { (v), (v) }
#else
#error  "*** ukos port stub: unsupported KNB_CORES"
#endif
#endif

extern  uint32_t    ukos_fake_runningCore(void);

// Interrupt mask
// ==============
//
// Used only by the kern tier (tests/kern/), which compiles the real
// OS/Lib_kernels/kern sources. They live here rather than in port/macros_core.h
// because lists.c and scheduler.c guard that include with #ifdef __arm__, which
// is false under Apple clang - so on the host macros_soc.h is the only port
// header they see. Every kern/*.c includes it, so one definition covers both
// paths.
//
// This is NOT a no-op, which port/README.md forbids for a macro that does real
// work. It counts, and it checks LIFO order: an early return that skips its
// INTERRUPTION_RESTORE leaves the depth non-zero and fails the test. That is the
// bug this exists to catch - pools.c alone has 26 restore sites across six
// error-heavy functions, and one missed on a target masks interrupts forever.
//
// What it does NOT do is mask anything. Pairing and nesting order only, never
// effect - the same honesty limit as PRIVILEGE_ELEVATE next door.
//
// Shape copied from Cores/CORTEX_M7/Includes/macros_core.h:166-176, including
// the variable name and its volatile qualifier, so a block that restores out of
// scope or declares the variable twice fails here exactly as it would there.
// It cannot be drift-checked because the body is a mirror rather than a copy;
// kern_fake_interrupt_* in tests/kern/test_kernenv.c pins the contract instead.
//
// Provided by ukos_kern_support. A tier-2 module that reached for these would
// fail to link, which is the intended signal that it belongs to the kern tier.

#ifndef INTERRUPTION_OFF
#define INTERRUPTION_OFF        [[maybe_unused]] volatile   uint32_t    saveBASEPRI;    \
                                                                                        \
                                saveBASEPRI = ukos_fake_intOff();                       \
                                (void)saveBASEPRI
#endif

#ifndef INTERRUPTION_RESTORE
#define INTERRUPTION_RESTORE    ukos_fake_intRestore(saveBASEPRI)
#endif

extern  uint32_t    ukos_fake_intOff(void);
extern  void        ukos_fake_intRestore(uint32_t token);

#endif
