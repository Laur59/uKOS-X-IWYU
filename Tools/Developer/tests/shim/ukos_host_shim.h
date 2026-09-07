/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host test shim - force-included (-include) ahead of an unmodified uKOS-X CLI
 * module so that it compiles and runs natively on macOS.
 */

#ifndef UKOS_HOST_SHIM_H
#define UKOS_HOST_SHIM_H

// 1. Pre-include every system header the modules under test use, so that the
//    dprintf / time macros defined below are never live while a system header
//    is being preprocessed.

#include    <inttypes.h>
#include    <stdint.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <time.h>

// 2. Redirect the two libc entry points the module calls.
//
//    dprintf() is the POSIX dprintf(int fd, ...); uKOS-X passes a serial
//    manager 4CC (KSYST == 0x73797374) where the fd goes and supplies its own
//    _write(). On the host that fd is meaningless, so the call is captured.
//
//    time() is redirected so the tests can pin "now".
//
//    Both macros are FUNCTION-LIKE on purpose: an object-like "#define time X"
//    would rewrite the identifier everywhere downstream and collide with
//    unrelated uses such as "struct ntptimeval { struct timespec time; }".
//
//    The format attribute matters: without it, replacing dprintf silently
//    disables -Wformat on every format string in the module under test, which
//    is exactly the PRIu64/uint64_t checking the target build performs today.

extern  int     ukos_test_dprintf(uint32_t manager, const char *fmt, ...)
                __attribute__((format(printf, 2, 3)));
extern  time_t  ukos_test_time(time_t *tloc);

#define dprintf(...)        ukos_test_dprintf(__VA_ARGS__)
#define time(tloc)          ukos_test_time(tloc)

// 3. Neutralise the one construct Mach-O rejects.
//
//    modules.h places the directory entry in the ".directory" section, which
//    the target linker scripts gather. Mach-O requires a "segment,section"
//    pair, so a bare name is a hard error. The macro below is a byte-for-byte
//    copy of modules.h with that single literal changed; run-tests.sh diffs the
//    two and fails if they ever drift apart.
//
//    aName_Specifications keeps external linkage (C_DECLARE is empty in C), so
//    the test calls the module through aDate_Specifications.oExecution() and
//    never has to #include the .c file.

#include    "modules.h"

#undef  MODULE
#define MODULE(name, family, idModule, init, execution, clean, revision, flag, executionCore)                                                           \
    C_DECLARE   const   uKOS_module_t       a##name##_Specifications /* NOLINT(misc-use-internal-linkage) */ = {                                        \
                                                .oIdModule       = ( ((uint32_t)family<<24U) | ((uint32_t)idModule<<8U) | ((uint32_t)(uint8_t)'_')),    \
                                                .oStrApplication = aStrApplication,                                                                     \
                                                .oStrHelp        = aStrHelp,                                                                            \
                                                .oInit           = (int32_t (*)(uint32_t argc, const char_t *argv[]))init,                            \
                                                .oExecution      = (int32_t (*)(uint32_t argc, const char_t *argv[]))execution,                       \
                                                .oClean          = (int32_t (*)(uint32_t argc, const char_t *argv[]))clean,                           \
                                                .oStrRevision    = revision,                                                                            \
                                                .oFlag           = flag,                                                                                \
                                                .oExecutionCore  = executionCore                                                                        \
                                            };                                                                                                          \
    C_DECLARE   const   uKOS_directory_t    dir##name [[gnu::section("__DATA,__directory")]] = { /* NOLINT(misc-use-internal-linkage) */                \
                                                .oModuleLocation = KBUILD_IN,                                                                           \
                                                .oModule         = (const uKOS_module_t *)&a##name##_Specifications                                     \
                                            }

#endif
