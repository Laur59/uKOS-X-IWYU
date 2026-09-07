/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Test doubles for the uKOS-X services a CLI module links against.
 */

#include    "ukos_fakes.h"

#include    <stdarg.h>
#include    <stdbool.h>
#include    <stddef.h>
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>
#include    <time.h>

#include    "calendar/calendar.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "random/random.h"
#include    "system/system.h"
#include    "text/text.h"
#include    "types.h"

ukos_fakes_t    g_fakes;

// calendar - recorded, never touching hardware
// ============================================
//
// The real implementation (OS/Lib_generics/calendar/calendar.c) is not host
// buildable: every entry point is bracketed by GET_RUNNING_CORE (an MMIO read)
// and PRIVILEGE_ELEVATE / PRIVILEGE_RESTORE, and it pulls macros_core.h and
// macros_soc.h.

int32_t calendar_readUnixTime(calendarFromTimer_t fromTimer, uint64_t *unixTime) {

    g_fakes.read.calls++;
    g_fakes.read.lastFrom = fromTimer;

    if (g_fakes.read.writeOut) {
        *unixTime = g_fakes.read.value;
    }
    return g_fakes.read.rc;
}

int32_t calendar_writeUnixTime(uint64_t unixTime) {

    g_fakes.write.calls++;
    g_fakes.write.lastValue = unixTime;
    return g_fakes.write.rc;
}

int32_t calendar_setUTCLocation(const char_t *utcLocation) {

    g_fakes.setUTC.calls++;
    g_fakes.setUTC.lastPtr = utcLocation;

    (void)snprintf(&g_fakes.setUTC.lastCopy[0], sizeof g_fakes.setUTC.lastCopy, "%s", utcLocation);
    return g_fakes.setUTC.rc;
}

// system - a synthetic module directory
// =====================================
//
// system_getModuleFamily() cannot be compiled on the host: system.c reaches
// the directory through the linker symbol linker_stDirectory and brackets
// every entry point with PRIVILEGE_ELEVATE / PRIVILEGE_RESTORE.
//
// The scan below mirrors OS/Lib_generics/system/system.c: starting at *index,
// walk forward to the first entry whose family matches - or any entry when the
// family is KID_FAM_ALL_FAMILIES - leaving *index on the match. Unlike
// text_checkAsciiBuffer this cannot be a verbatim copy, because the original
// is wrapped in privilege macros, so it is not covered by a drift check;
// list_fake_directory_contract pins the behaviour instead.

void ukos_fake_addModule(uint32_t idModule, const char_t *revision,
                         const char_t *application, uint8_t flag) {

    ukos_fake_addModuleWithHelp(idModule, revision, application, "", flag);
}

void ukos_fake_addModuleWithHelp(uint32_t idModule, const char_t *revision,
                                 const char_t *application, const char_t *help,
                                 uint8_t flag) {
    uint16_t    slot;

    if (g_fakes.system.nbModules >= KUKOS_FAKE_MAX_MODULES) {
        return;
    }

    slot = g_fakes.system.nbModules;

    g_fakes.system.storage[slot].oIdModule       = idModule;
    g_fakes.system.storage[slot].oStrRevision    = revision;
    g_fakes.system.storage[slot].oStrApplication = application;
    g_fakes.system.storage[slot].oStrHelp        = help;
    g_fakes.system.storage[slot].oFlag           = flag;

    g_fakes.system.directory[slot].oModuleLocation = KBUILD_IN;
    g_fakes.system.directory[slot].oModule         = &g_fakes.system.storage[slot];

    g_fakes.system.nbModules = (uint16_t)(slot + 1U);

// directory[nbModules] stays zeroed, and KNO_MODULE == 0, so the table is
// always terminated

}

void ukos_fake_setLastClean(int32_t (*clean)(uint32_t argc, const char_t *argv[])) {

    if (g_fakes.system.nbModules != 0U) {
        g_fakes.system.storage[g_fakes.system.nbModules - 1U].oClean = clean;
    }
}

// system - the downloaded application slot
// ========================================

int32_t system_getDownloadCodeAddress(void **address) {

    g_fakes.download.getCalls++;
    *address = g_fakes.download.address;
    return KERR_SYSTEM_NOERR;
}

int32_t system_setDownloadCodeAddress(void *address) {

    g_fakes.download.setCalls++;
    g_fakes.download.lastSet = address;
    g_fakes.download.address = address;
    return KERR_SYSTEM_NOERR;
}

int32_t system_getModuleFamily(uint8_t family, uint32_t *idModule, uint16_t *index,
                               const uKOS_module_t **module) {

    g_fakes.system.calls++;
    *module = nullptr;

    while (g_fakes.system.directory[*index].oModuleLocation != KNO_MODULE) {
        if (((g_fakes.system.directory[*index].oModule->oIdModule >> 24U) == family)
         || (family == (uint8_t)KID_FAM_ALL_FAMILIES)) {
            *idModule = g_fakes.system.directory[*index].oModule->oIdModule;
            *module   = g_fakes.system.directory[*index].oModule;
            return KERR_SYSTEM_NOERR;
        }

        *index = (uint16_t)(*index + 1U);
    }
    return KERR_SYSTEM_NOFAM;
}

// Mirrors system_getModuleName() in system.c: the directory is rescanned from
// the start - the index is an output here, not a resume point - and a module is
// matched by handing text_checkAsciiBuffer() its application string against the
// requested name. Since that comparison stops at the first space of the
// application string, the module's "name" is its first word.

int32_t system_getModuleName(const char_t *name, uint16_t *index, const uKOS_module_t **module) {
    bool    equals;

    g_fakes.system.nameCalls++;
    *module = nullptr;
    *index  = 0U;

    while (g_fakes.system.directory[*index].oModuleLocation != KNO_MODULE) {
        text_checkAsciiBuffer(g_fakes.system.directory[*index].oModule->oStrApplication, name, &equals);
        if (equals) {
            *module = g_fakes.system.directory[*index].oModule;
            return KERR_SYSTEM_NOERR;
        }

        *index = (uint16_t)(*index + 1U);
    }
    return KERR_SYSTEM_NOMOD;
}


// random
// ======

int32_t random_read(randomGenerator_t generator, uint32_t *number, uint32_t nbNumbers) {

    g_fakes.random.calls++;
    g_fakes.random.lastGenerator = generator;
    g_fakes.random.lastNbNumbers = nbNumbers;

    if (g_fakes.random.writeOut) {
        for (uint32_t i = 0U; i < nbNumbers; i++) {
            number[i] = g_fakes.random.seed + (i * g_fakes.random.step);
        }
    }
    return g_fakes.random.rc;
}

// libc redirections installed by the shim
// =======================================

int ukos_test_dprintf(uint32_t manager, const char *fmt, ...) {
    va_list     ap;
    int         nb;
    size_t      room;

    if (g_fakes.dprintfCalls < KUKOS_FAKE_MAX_CALLS) {
        g_fakes.dprintfManager[g_fakes.dprintfCalls] = manager;
    }
    g_fakes.dprintfCalls++;

    room = (sizeof g_fakes.out) - g_fakes.outLen;

    va_start(ap, fmt);
    nb = vsnprintf(&g_fakes.out[g_fakes.outLen], room, fmt, ap);
    va_end(ap);

    if (nb < 0) {
        g_fakes.outError = true;
        return nb;
    }

    if ((size_t)nb >= room) {
        g_fakes.outTruncated = true;
        g_fakes.outLen       = (sizeof g_fakes.out) - 1U;
    }
    else {
        g_fakes.outLen += (size_t)nb;
    }
    return nb;
}

time_t ukos_test_time(time_t *tloc) {

    g_fakes.timeCalls++;

    if (tloc != NULL) {
        *tloc = g_fakes.timeRet;
    }
    return g_fakes.timeRet;
}
