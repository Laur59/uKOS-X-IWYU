/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – startUp process: launch console on UART0.
 */

#include    "startUp/startUp.h"

#include    <inttypes.h>
#include    <stdio.h>

#include    "ip.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "serial/serial.h"
#include    "serial_common.h"
#include    "system/system.h"
#include    "types.h"

// Bootstrap function table
// ------------------------

typedef struct  boot    boot_t;

struct  boot {
        const   char_t              *oFunction;         // Ptr on the function
                serialManager_t     oSerialManager;     // Default Serial Communication Manager
        const   char_t              **oArgV;            // Ptr on the arguments
                uint8_t             oArgC;              // Number of arguments
                uint8_t             oSW;                // Switch value
                uint8_t             oBaudrate;          // Baudrate
        };

static  const   char_t  *argv_cnsUrt0_Cx[] = { "console", "urt0" };

static  const   boot_t  aFunction_Cx[] = {
                    { "console", KURT0, argv_cnsUrt0_Cx, 2U, 0x00U, KSERIAL_BAUDRATE_460800 }
                };

#define KDEF_COMM_Cx        KURT0
#define KNB_FUNCTIONS_Cx    (sizeof(aFunction_Cx) / sizeof(boot_t))

// NOLINTNEXTLINE(misc-use-internal-linkage): Global constant declared in startUp.h
STRG_GLB_CONST(aStartUp_StrHelp[]) = "StartUp process\n"
                                     "================\n\n"
                                     "Launches the uKOS-X CLI console on UART0 at 460800 baud.\n\n";

STRG_LOC_CONST(aStrLogo[]) = STRG_LOGO;

/*
 * \brief stub_startUp_launch
 *
 */
void    stub_startUp_launch(void) {
            uint8_t         i, nbFunctions;
            uint16_t        index;
            uint32_t        mode;
            bool            error = false;
            urtxCnf_t       configureURTx;
            proc_t          *process;
    const   boot_t          *functions;
    const   uKOS_module_t   *module;
    const   char_t          *identifier, *signature;

    mode        = 0U;
    nbFunctions = (uint8_t)KNB_FUNCTIONS_Cx;
    functions   = &aFunction_Cx[0];

    serial_setDefSerialManager(KDEF_COMM_Cx);
    kern_suspendProcess(500U);

    configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
    configureURTx.oStopBits = KSERIAL_STOPBITS_1;
    configureURTx.oParity   = KSERIAL_PARITY_NONE;
    configureURTx.oBaudRate = functions[mode].oBaudrate;
    configureURTx.oKernSync = ((uint32_t)1U << (uint32_t)BSERIAL_SEMAPHORE_RX);
    serial_configure(KURT0, &configureURTx);

    kern_getProcessRun(&process);
    kern_setSerialForProcess(process, functions[mode].oSerialManager);

    system_getSystemId(&identifier);
    system_getSystemSignature(&signature);

    (void)dprintf(KSYST, "%s", aStrLogo);
    (void)dprintf(KSYST, "Signature:\n%s\n\n", signature);
    (void)dprintf(KSYST, "%ssw = %"PRIX32"\n", identifier, mode);

    kern_suspendProcess(500U);

    for (i = 0U; i < nbFunctions; i++) {
        if (functions[i].oSW == mode) {
            index = 0U;
            if (system_getModuleName(functions[i].oFunction, &index, &module) != KERR_SYSTEM_NOERR) {
                error = true;
            }

            if (error) {
                (void)dprintf(KSYST, "Module not found or user memory busy by a running application.\n\n");
                while (true) { kern_suspendProcess(1U); }
            }
            else {
                switch (module->oExecution(functions[i].oArgC, functions[i].oArgV)) {
                    case EXIT_OS_FAILURE_CRT0: {
                        (void)dprintf(KSYST, "Incompatible OS!!!\nReload the latest OS inside the target.\n");
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
    }
}
