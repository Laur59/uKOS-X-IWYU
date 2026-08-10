/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Syscall dispatcher.
 *               - uKernel messages
 *               - manager system calls
*/

#pragma once

#include    <stdint.h>

// svc numbers
// -----------

#define KKERN_MESSAGE           0               // uKernel (messages passing)
#define KPRIV_ELEVATION         1               // priv (privilege elevation)

[[noreturn]]
void    syscall(const uintptr_t *arg);

extern  void    kernel_message_C0(void);
extern  void    kern_privilegeElevate(void);
