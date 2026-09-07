/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host stub for Ports/EquatesModels/Cores/<CORE>/Runtime/syscallDispatcher.h.
 *
 * Every synchronisation primitive in kern/ includes this header and then uses
 * NOTHING from it - each include is marked "IWYU pragma: keep", and a grep for
 * syscall(), KKERN_MESSAGE or kernel_message_C0 across the whole directory
 * finds only the include lines themselves. The dependency is vestigial.
 *
 * It is stubbed rather than put on the include path because the real one lives
 * per core under Ports/EquatesModels/Cores/, which this tier does not add, and
 * because syscall() is [[noreturn]] and kernel_message_C0 is a naked SVC
 * handler - neither has a host meaning.
 *
 * The two svc numbers are copied verbatim; they are plain constants.
 */

#ifndef UKOS_PORT_STUB_SYSCALLDISPATCHER_H
#define UKOS_PORT_STUB_SYSCALLDISPATCHER_H  1

#include    <stdint.h>

#define KKERN_MESSAGE           0               // uKernel (messages passing)
#define KPRIV_ELEVATION         1               // priv (privilege elevation)

// Declared, never defined: nothing in kern/ calls either, and a suite that
// somehow did would fail to link rather than run against a fiction.

extern  void    syscall(const uintptr_t *arg);
extern  void    kernel_message_C0(void);

#endif
