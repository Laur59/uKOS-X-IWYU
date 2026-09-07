/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Semaphore doubles, for the kern suites that do NOT compile semaphores.c.
 *
 * Kept out of ukos_kern_support on purpose. pools.c is built on semaphores - a
 * pool owns a release semaphore - but the semaphore suite compiles the real
 * semaphores.c, which defines these same four functions. Putting the doubles in
 * the shared library would make those two suites mutually exclusive by link
 * error; a separate file, added per suite through FAKE_SOURCES, lets each suite
 * say which it wants.
 *
 * A suite that links this file must not also link semaphores.c.
 */

#include    <stdint.h>

#include    "kern/kern.h"
#include    "macros_soc.h"
#include    "os_errors.h"
#include    "types.h"
#include    "ukos_fakes_kernenv.h"
#include    "ukos_test.h"

// Semaphores
// ==========
//
// pools.c owns a release semaphore per pool and calls four functions on it.
// semaphores.c is not linked into a pools suite - it would bring GOTO_KERN_M
// with it - so these are doubles. What they must reproduce is only what pools.c
// depends on: create hands back a distinct non-null handle, and the rest report
// a status.

// sema_t is opaque outside private_semaphores.h, and pools.c never dereferences
// the handle - it stores it and hands it back to the four calls below. So the
// fake deals in distinct, suitably aligned tokens rather than pulling the
// private header in for a struct nothing here reads.

static  uintptr_t   vFakeSema[KKERN_NB_POOLS + 1U];
static  uint32_t    vNbFakeSema;

/*
 * \brief kern_createSemaphore
 *
 */
int32_t     kern_createSemaphore([[maybe_unused]] const char_t *identifier,
                                 [[maybe_unused]] int32_t iniCounter,
                                 [[maybe_unused]] int32_t maxCounter, sema_t **handle) {

    g_kernenv.oNbSemaCreate++;

    if (g_kernenv.oRcSemaCreate != KERR_KERN_NOERR) {
        *handle = nullptr;
        return g_kernenv.oRcSemaCreate;
    }

    if (vNbFakeSema >= (uint32_t)(sizeof(vFakeSema) / sizeof(vFakeSema[0]))) {
        *handle = nullptr;
        return KERR_KERN_SEFUL;
    }

    *handle = (sema_t *)&vFakeSema[vNbFakeSema];
    vNbFakeSema++;
    return KERR_KERN_NOERR;
}

/*
 * \brief kern_waitSemaphore
 *
 */
int32_t     kern_waitSemaphore([[maybe_unused]] sema_t *handle, [[maybe_unused]] uint32_t timeout) {

    g_kernenv.oNbSemaWait++;
    return g_kernenv.oRcSemaWait;
}

/*
 * \brief kern_signalSemaphore
 *
 */
int32_t     kern_signalSemaphore([[maybe_unused]] sema_t *handle) {

    g_kernenv.oNbSemaSignal++;
    return KERR_KERN_NOERR;
}

/*
 * \brief kern_killSemaphore
 *
 */
int32_t     kern_killSemaphore([[maybe_unused]] sema_t *handle) {

    g_kernenv.oNbSemaKill++;
    return KERR_KERN_NOERR;
}

/*
 * \brief Hand back every fake semaphore between tests
 *
 */
static  void    local_reset(void) {

    vNbFakeSema = 0U;
}

/*
 * \brief Register the reset
 *
 */
[[gnu::constructor]]
static  void    local_install(void) {

    ukos_t_addResetHook(local_reset);
}
