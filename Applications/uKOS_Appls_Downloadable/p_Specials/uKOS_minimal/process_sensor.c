/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 *     Process: sensor.
 *     - Every 100-ms
 *         Send a new value to the dispatcher
 */

#include    <stdint.h>
#include    <stdlib.h>

#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "memo/memo.h"
#include    "os_errors.h"
#include    "queue.h"
#include    "record/record.h"
#include    "types.h"
#include    "record/record.h"

#define KTIME_SAMPLING_SENSOR   100U

extern  mbox_t  *vQueue_dispatcher;

// Prototypes

static  void    aProcess(const void *argument);

/*
 * \brief Install & launch the process
 *
 */
bool    installaProcess_sensor(void) {
    bool    status;
    proc_t  *process;

// -------------------------------I-----------------------------------------I--------------I

    STRG_LOC_CONST(aStrIden[]) = "User_Process_sensor";
    STRG_LOC_CONST(aStrText[]) = "Process sensor.                           (c) EFr-2026";

// Specifications for the processes

    PROCESS_STACKMALLOC(
        0U,                                 // Index
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess,                           // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_MEDIUM_15            // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    status = (kern_createProcess(&specification, nullptr, &process) == KERR_KERN_NOERR) ? (true) : (false);
    return status;
}

/*
 * \brief aProcess
 *
 * Px: - Every 100-ms
 *       - Send a new value to the dispatcher
 *
 */
[[noreturn]]
static void aProcess(const void *argument) {
    uint8_t     value = 0U;
    uintptr_t   message_sensor;

    UNUSED(argument);

    while (vQueue_dispatcher == nullptr) { kern_suspendProcess(1U); }

    while (true) {
        kern_suspendProcess(KTIME_SAMPLING_SENSOR);

        message_sensor = KID_SENSOR | (uintptr_t)value;
        if (kern_writeQueue(vQueue_dispatcher, message_sensor, KWAIT_INFINITY) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Write queue"); exit(EXIT_OS_FAILURE); }

        value++;
    }
}
