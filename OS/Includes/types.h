/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; types.
; ======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Basic predefined types (normally machine independent).
;
;-----
;------------------------------------------------------------------------
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

// uKOS-X misc

#ifndef tm_t
typedef struct  tm          tm_t;
#endif

#ifndef timeval_t
typedef struct timeval      timeval_t;
#endif

#ifndef reserveMode_t
typedef enum {
            KMODE_READ = 0U,
            KMODE_WRITE,
            KMODE_READ_WRITE,
} reserveMode_t;

#define KMODE_ALL   KMODE_READ_WRITE
#endif

// Types defined by gcc (version > than 4.8)

#ifndef char_t
typedef char                char_t;
#endif

#ifndef float32_t
typedef float               float32_t;
#endif

#ifndef float64_t
typedef double              float64_t;
#endif
