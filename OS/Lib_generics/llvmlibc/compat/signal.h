/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * <signal.h> compatibility header for the LLVM libc build.
 *
 * Baremetal LLVM libc ships no <signal.h> at all. uKOS-X has no signal
 * delivery either -- a Cortex-M exception or a RISC-V trap is handled by the
 * kernel, never turned into a POSIX signal -- so this header deliberately
 * declares NO function: signal(), raise() and sigaction() are not offered
 * here, and new code calling them must fail to compile.
 *
 * It exists so that third-party headers including <signal.h> still compile.
 * Third_Parties/decnumber's decContext.h is the case in point: it includes the
 * header "for traps" and uses nothing from it, although the prebuilt
 * libdecnumber.a does call raise(SIGFPE) when a decNumber trap is enabled --
 * llvmlibc.c supplies a raise() stub for that link, among the other
 * newlib-compatibility symbols.
 *
 * Only sig_atomic_t is provided, since that type is meaningful without any
 * signal machinery (it is what an interrupt handler and a task may share).
 *
 * If a future LLVM libc starts shipping a real <signal.h>, this header would
 * shadow it -- the compat/ directory precedes the toolchain include paths.
 * Delete this file at that point.
 */

#ifndef LLVMLIBC_COMPAT_SIGNAL_H_
#define LLVMLIBC_COMPAT_SIGNAL_H_

#ifndef CONFIG_MAN_LLVMLIBC_S
#error "LLVM libc compatibility <signal.h> reached from a non-llvmlibc build"
#endif

typedef int     sig_atomic_t;

#endif  // LLVMLIBC_COMPAT_SIGNAL_H_
