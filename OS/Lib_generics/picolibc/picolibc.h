/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:     picolibc interface for modern C compilers (GCC 14+, Clang 21+).
 *
 *           See: https://github.com/picolibc/picolibc
 *
 *           Fully or partially supported functions to support
 *
 *           Open - close - read - write functions (non-reentrant)
 *           _open
 *           _close
 *           _write
 *           _read
 *
 *           time/calendar functions
 *           _gettimeofday
 *           _times
 *
 *           Generic functions
 *           _isatty
 *           _exit
 *           _fstat
 *           _lseek
 *           _getpid
 *           _kill
 *
 *           Allocator functions (wrapped via linker)
 *           __wrap_malloc
 *           __wrap_free
 *           __wrap_realloc
 *           __wrap_calloc
 *
 *           Custom errno function
 *           __ukos_get_errno
 *
 *           Supported devices controlled by open - close - read - write functions
 *           urt0 - urt4: UART serial devices
 *           cdc0 - cdc1: USB CDC devices
 *           wfi0: WiFi device
 *           syst: System device
 *           def0: Default device
 *           stdin, stdout, stderr: Standard I/O streams
 */

#ifndef PICOLIBC_H_
#define PICOLIBC_H_

#ifdef CONFIG_MAN_PICOLIBC_S

/*
 * CRITICAL: Define custom errno function BEFORE including ANY C library headers
 *
 * This enables picolibc's custom errno mechanism, allowing uKOS-X to provide
 * per-process errno storage without Thread-Local Storage (TLS) overhead.
 *
 * The __ukos_get_errno() function returns a pointer to the current process's
 * errno variable, which is updated automatically by the kernel on process
 * context switches.
 */
#define __PICOLIBC_ERRNO_FUNCTION __ukos_get_errno
int *__ukos_get_errno(void);

#endif  // CONFIG_MAN_PICOLIBC_S

/*
 * Standard file descriptor constants (matching newlib.h)
 *
 * These are defined after the errno function because they require
 * <unistd.h> which needs the errno function to be defined first.
 */
#include    <unistd.h>        // for STDERR_FILENO, STDIN_FILENO, STDOUT_FILENO
#include    <stdio.h>         // for dprintf declaration (if available)

// Integer equivalence of stdin, stdout, stderr

#define KSTDIN      STDIN_FILENO
#define KSTDOUT     STDOUT_FILENO
#define KSTDERR     STDERR_FILENO

#endif  // PICOLIBC_H_
