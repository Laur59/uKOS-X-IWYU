/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Acquire the temperature every 200 ms and post the last 128 samples to the
 * "Temperature" mailbox, which the X tool reads. The samples come from the
 * temperature manager when the variant builds one, and from a simulated table
 * otherwise.
 *
 *           Process                             Tool
 *           getTemp                             X
 *           while
 *               - malloc of a buffer k
 *               - send the buffer k             - receive the buffer k
 *               - k++                           - copy it
 *                                               - free the buffer k
 */

#include    <stdint.h>
#include    <stdio.h>
#include    <stdlib.h>

#include    "serial/serial.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "macros_soc.h"
#include    "memo/memo.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"

#ifdef CONFIG_MAN_TEMPERATURE_S
#include    <string.h>

#include    "temperature/temperature.h"
#else
#include    "random/random.h"
#endif

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "getTemp      temperature acquisition process           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "temperature process\n"
                                    "===================\n\n"

                                    "Acquisition of the temperature\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// This process has to run on the following cores:

#define KEXECUTION_CORE     (1U<<BCORE_0)

static  int32_t     prgm([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]);
static  int32_t     temperature_clean(uint32_t argc, const char_t *argv[]);

MODULE(
    GetTemp,                        // Module name (the first letter has to be upper case)
    KID_FAM_PROCESSES,              // Family (defined in the module.h)
    KNUM_GET_TEMP,                  // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    prgm,                           // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    temperature_clean,              // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    KEXECUTION_CORE                 // Execution cores
);

// Process specific
// ================

#define KTIME_ACQ           200U    // 200-ms
#define KNB_SAMPLES         128U    // Nb. of samples

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_getTemp";
STRG_LOC_CONST(aStrText[]) = "Process get temp: temp acquisition.       (c) EFr-2026";

static  bool    vKillRequest[KNB_CORES] = MCSET(false);

// Prototypes

static  void    local_process(const void *argument);

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
    uint32_t    core;
    proc_t      *process;

    core = GET_RUNNING_CORE;
    vKillRequest[core] = false;

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        local_process,                      // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_LOW_14               // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "temperature: create proc"); exit(EXIT_OS_PANIC); }

    LOG(KINFO_SYSTEM, "getTemp: process getTemp launched");
    return EXIT_OS_SUCCESS_CLI;
}

/*
 * \brief temperature_clean
 *
 * - Try to clean the ressources
 *      - Free all the ressources
 *
 */
static  int32_t temperature_clean([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    vKillRequest[core] = true;

    return EXIT_OS_SUCCESS;
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Temperature acquisitions (5-Hz)
 *   In the simulated table a period is represented by 16 samples
 *   200-ms per sample -> 3.2-s -> 1/3.2 = 0.3125-Hz
 *
 * - Each buffer sent belongs to the reader from then on (X frees it). A buffer
 *   the mailbox has not taken yet is still ours.
 *
 */
[[noreturn]]
static void local_process(const void *argument) {
                    mbox_t      *mailBox;
                    uint16_t    *temperature;
                    void        *message;
                    uint32_t    sizeSnd, sizeRec;
                    int32_t     status;
                    mcnf_t      configure = {
                                    .oNbMaxPacks    = 10U,
                                    .oDataEntrySize = 0U,
                                };
            const   bool        *killRequest;

    #ifdef CONFIG_MAN_TEMPERATURE_S
                    uint16_t    i;
                    float64_t   instTemperature;
    static          uint16_t    vHistory[KNB_SAMPLES];
    static          bool        vPrimed = false;

    #else
                    uint16_t    i;
                    int32_t     value;
                    uint32_t    random;
                    float64_t   raw;
    static  const   float64_t   aSimule[KNB_SAMPLES] = {
                                    20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
                                    23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
                                    20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
                                    23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
                                    20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
                                    23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
                                    20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
                                    23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
                                    20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
                                    23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
                                    20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
                                    23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
                                    20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
                                    23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
                                    20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
                                    23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
                                };
    #endif

    killRequest = (const bool *)argument;

// Create the mailbox "Temperature"

    if (kern_createMailbox("Temperature", &mailBox) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "temperature: create Mbox"); exit(EXIT_OS_PANIC);   }
    if (kern_setMailbox(mailBox, &configure)        != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "temperature: set mbox\n");  exit(EXIT_OS_FAILURE); }

    while (!*killRequest) {
        kern_suspendProcess(KTIME_ACQ);

// Request a temperature buffer
// It will be free by the tool X

        temperature = (uint16_t *)memo_malloc(KMEMO_ALIGN_8, (KNB_SAMPLES * sizeof(uint16_t)), "temperature");
        if (temperature == nullptr) {
            LOG(KFATAL_SYSTEM, "temperature: out of memory");
            exit(EXIT_OS_FAILURE);
        }

        #ifdef CONFIG_MAN_TEMPERATURE_S

// Real acquisition, the newest sample first. The history lives here, not in the
// buffer: a fresh buffer holds whatever the heap held, and shifting it moved
// garbage along. The manager answers in kelvin already. A read that fails, or
// a manager kept busy by another user, holds the previous sample.

        if (temperature_reserve(KMODE_READ, KTIME_ACQ) == KERR_TEMPERATURE_NOERR) {
            if (temperature_read(&instTemperature) == KERR_TEMPERATURE_NOERR) {
                if (!vPrimed) {
                    for (i = 0U; i < KNB_SAMPLES; i++) {
                        vHistory[i] = (uint16_t)(instTemperature * 100.0);
                    }
                    vPrimed = true;
                }
                for (i = 0U; i < (KNB_SAMPLES - 1U); i++) {
                    vHistory[KNB_SAMPLES - 1U - i] = vHistory[KNB_SAMPLES - 2U - i];
                }
                vHistory[0] = (uint16_t)(instTemperature * 100.0);
            }
            (void)temperature_release(KMODE_READ);
        }
        memcpy(temperature, vHistory, (KNB_SAMPLES * sizeof(uint16_t)));

        #else

// The temperature acquisition is emulated (see table),
// then, a random noise (0 .. +2.55 degree) is added

        for (i = 0U; i < KNB_SAMPLES; i++) {
            random_read(KRANDOM_SOFT, &random, 1U);
            raw = (aSimule[i] + 273.16) * 100.0;
            value = (int32_t)raw + (int32_t)(random & 0xFFU);
            temperature[i] = (uint16_t)value;
        }
        #endif

// Hand the buffer over. A finite timeout keeps a full mailbox (nobody running
// X) from blocking the process for ever: with KWAIT_INFINITY a kill took effect
// only once a reader had drained a message. On a timeout the sample is dropped.

        sizeSnd = (KNB_SAMPLES * sizeof(uint16_t));
        status  = kern_writeMailbox(mailBox, &temperature[0], sizeSnd, KTIME_ACQ);
        switch (status) {
            case KERR_KERN_NOERR: {
                break;
            }
            case KERR_KERN_TIMEO: {
                memo_free(temperature);
                break;
            }
            default: {
                (void)dprintf(KSYST, "mbox problem\n");
                LOG(KFATAL_USER, "temperature: mbox problem");
                exit(EXIT_OS_FAILURE);
            }
        }
    }

// Free the buffers still queued: kern_killMailbox() releases the FIFO, not the
// buffers its messages point to, and nobody else will read them. Only this
// process writes, so once the mailbox is empty it stays empty; a reader that
// arrives now waits and is woken with KERR_KERN_MBKIL by the kill.
//
// The last buffer sent is not freed here any more: it belongs to the mailbox
// or to the reader, and freeing it was a double free once X had consumed it.

    sizeRec = (KNB_SAMPLES * sizeof(uint16_t));
    while (kern_readMailbox(mailBox, &message, &sizeRec, 0U) == KERR_KERN_NOERR) {
        memo_free(message);
    }

// Kill the process & the ressources

    PRIVILEGE_ELEVATE;      // INTERRUPTION_OFF writes the interrupt mask: privileged
    INTERRUPTION_OFF;
    (void)kern_killMailbox(mailBox);

    exit(EXIT_OS_SUCCESS);
}
