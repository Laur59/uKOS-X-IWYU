/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Test doubles for the uKOS-X services a CLI module links against.
 */

#ifndef UKOS_FAKES_H
#define UKOS_FAKES_H

#include    <stdbool.h>
#include    <stddef.h>
#include    <stdint.h>
#include    <time.h>

#include    "calendar/calendar.h"
#include    "modules.h"
#include    "random/random.h"
#include    "types.h"

#define KUKOS_FAKE_OUT_SIZE     8192U
#define KUKOS_FAKE_MAX_CALLS    32U
#define KUKOS_FAKE_COPY_SIZE    64U
#define KUKOS_FAKE_MAX_MODULES  16U

// Captured state for one test. Zeroed and re-seeded by ukos_t_begin().

typedef struct {

// calendar_readUnixTime()

    struct {
        unsigned            calls;
        int32_t             rc;                             // status handed back
        bool                writeOut;                       // false -> leave *unixTime untouched
        uint64_t            value;                          // value handed back
        calendarFromTimer_t lastFrom;
    } read;

// calendar_writeUnixTime()

    struct {
        unsigned            calls;
        int32_t             rc;
        uint64_t            lastValue;
    } write;

// calendar_setUTCLocation()

    struct {
        unsigned            calls;
        int32_t             rc;
        const char_t        *lastPtr;                       // pointer identity: proves WHICH argv was passed
        char_t              lastCopy[KUKOS_FAKE_COPY_SIZE];
    } setUTC;

// system - a synthetic module directory
//
// On a target the directory is gathered by the linker into the .directory
// section and terminated by a KNO_MODULE entry. Here it is an ordinary array,
// so a test can describe exactly the modules a CLI tool should see - including
// arrangements real hardware cannot easily produce.

    struct {
        unsigned            calls;                          // system_getModuleFamily()
        unsigned            nameCalls;                      // system_getModuleName()
        uint16_t            nbModules;
        uKOS_module_t       storage[KUKOS_FAKE_MAX_MODULES];
        uKOS_directory_t    directory[KUKOS_FAKE_MAX_MODULES + 1U];   // + terminator
    } system;

// system_{get,set}DownloadCodeAddress() - the slot run() dispatches through

    struct {
        unsigned            getCalls;
        unsigned            setCalls;
        void                *address;                       // what get hands back
        void                *lastSet;                       // what set was given
    } download;

// random_read() - hands out a deterministic ramp so the printed numbers can be
// asserted exactly. seed is the first value; each further number adds step.

    struct {
        unsigned            calls;
        int32_t             rc;
        randomGenerator_t   lastGenerator;
        uint32_t            lastNbNumbers;
        uint32_t            seed;
        uint32_t            step;
        bool                writeOut;                       // false -> leave the buffer untouched
    } random;

// time()

    time_t                  timeRet;
    unsigned                timeCalls;

// dprintf() capture

    char                    out[KUKOS_FAKE_OUT_SIZE];
    size_t                  outLen;
    unsigned                dprintfCalls;
    uint32_t                dprintfManager[KUKOS_FAKE_MAX_CALLS];
    bool                    outTruncated;
    bool                    outError;
} ukos_fakes_t;

extern  ukos_fakes_t    g_fakes;

// Append one module to the synthetic directory. The terminator is maintained
// automatically, and ukos_t_begin() clears the table (KNO_MODULE == 0).

extern  void    ukos_fake_addModule(uint32_t idModule, const char_t *revision,
                                    const char_t *application, uint8_t flag);

// As above, with a help text - the string man prints for a named module.

extern  void    ukos_fake_addModuleWithHelp(uint32_t idModule, const char_t *revision,
                                           const char_t *application, const char_t *help,
                                           uint8_t flag);

// Give the module added last an oClean entry point, so a tool that dispatches
// through the descriptor can be observed doing it.

extern  void    ukos_fake_setLastClean(int32_t (*clean)(uint32_t argc, const char_t *argv[]));

#endif
