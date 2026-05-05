/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * uKOS-X program return / exit codes.
 *
 * Kernel-independent header so that the C-runtime (crt0) can reference
 * EXIT_OS_PANIC without pulling in kernel-side type definitions.
 */

#pragma once

// uKOS-X program returns / exits
//
// return (code)
//         code = EXIT_OS_SUCCESS               --->        Success, kill the console process. Only the running processes
//         code = EXIT_OS_SUCCESS_CLI           --->        Success; return to the OS (console) with the running processes
//         code = EXIT_OS_FAILURE               --->        Failure; return to the OS (console) with an error message
//         code = EXIT_OS_FAILURE_CRT0          --->        Failure; return to the OS (console). Reload the latest OS
//         code = EXIT_OS_PANIC                 --->        Failure; panic. System is stopped
//         code = default                       --->        Failure; panic. System is stopped
//
// exit (code)
//         code = EXIT_OS_SUCCESS               --->        Success, commit a suicide
//         code = EXIT_OS_FAILURE               --->        Failure; commit a suicide
//         code = EXIT_OS_PANIC                 --->        Failure; panic. System is stopped
//         code = EXIT_OS_PANIC_MALLOC_BROKEN   --->        Failure; panic. System is stopped
//         code = EXIT_OS_PANIC_STACK_UNDERFLOW --->        Failure; panic. System is stopped
//         code = EXIT_OS_PANIC_NO_SYSCALL      --->        Failure; panic. System is stopped
//         code = EXIT_OS_PANIC_ELEVATION       --->        Failure; panic. System is stopped
//         code = default                       --->        Failure; panic. System is stopped

#include    <stdint.h>

enum : int32_t {
        EXIT_OS_SUCCESS = 0,
        EXIT_OS_SUCCESS_CLI,
        EXIT_OS_FAILURE,
        EXIT_OS_FAILURE_CRT0,
        EXIT_OS_PANIC,
        EXIT_OS_PANIC_MALLOC_BROKEN,
        EXIT_OS_PANIC_STACK_UNDERFLOW,
        EXIT_OS_PANIC_NO_SYSCALL,
        EXIT_OS_PANIC_ELEVATION
};
