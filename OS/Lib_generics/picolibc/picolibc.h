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
 *           newlib compatibility
 *           __errno
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

/*
 * errno
 *
 * errno is picolibc's ordinary global int, and uKOS-X makes it per-process by
 * saving and restoring it across context switches in xLibrary_update()
 * (OS/Lib_kernels/kern/xLibrary.c). The value lives in proc_t.oErrno while the
 * process is not running.
 *
 * The obvious alternative -- picolibc's __PICOLIBC_ERRNO_FUNCTION hook, which
 * turns errno into (*__ukos_get_errno()) -- is NOT usable here, and was removed
 * after being found broken:
 *
 * - It is a picolibc BUILD-time option (meson -Derrno-function=). The installed
 *   <errno.h> honours the macro, but the shipped libc.a was compiled without it,
 *   so its 89 members that touch errno bind to the global. Defining the macro in
 *   uKOS-X translation units only would split errno in two: picolibc's strtol(),
 *   vfprintf(), vfscanf(), ... would report through the global while uKOS-X read
 *   a per-process slot, and never see each other's values.
 *
 * - The accessor returned a pointer into proc_t. On a privileged/user build
 *   proc_t lives in libkern_p.a data, i.e. the privileged RAM region, so a
 *   user-mode process assigning errno faulted with DACCVIOL.
 *
 * Restoring that hook therefore requires rebuilding picolibc itself with
 * -Derrno-function=, which also makes the toolchain uKOS-X specific. See
 * Documentation/USER_GUIDES/TLS_SUPPORT_ASSESSMENT.md.
 */

/*
 * Standard file descriptor constants (matching newlib.h)
 */
#include    <unistd.h>        // for STDERR_FILENO, STDIN_FILENO, STDOUT_FILENO
#include    <stdio.h>         // for dprintf declaration (if available)

// Integer equivalence of stdin, stdout, stderr

#define KSTDIN      STDIN_FILENO
#define KSTDOUT     STDOUT_FILENO
#define KSTDERR     STDERR_FILENO

#endif  // PICOLIBC_H_
