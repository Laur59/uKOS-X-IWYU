/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     startUp process; execute some important initialisations
 *           before jumping to the selected function.
 */

#include    "startUp/startUp.h"

#include    <inttypes.h>
#include    <stdio.h>

#include    "ip.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "serial/serial.h"
#include    "serial_common.h"
#include    "system/system.h"
#include    "types.h"

extern  bool    TinyUSB_cdc_isConnected(uint8_t itf);

// Bootstrap function table
// ------------------------

typedef struct  boot    boot_t;

struct  boot {
        const   char_t              *oFunction;         // Ptr on the function
                serialManager_t     oSerialManager;     // Default Serial Communication Manager
        const   char_t              **oArgV;            // Ptr on the arguments
                uint8_t             oSW;                // Switch value
                uint8_t             oBaudrate;          // Baudrate
                uint8_t             oArgC;              // Number of arguments
        };

#if (CONFIG_DIFFERENT_SERIAL_PER_CORE_S == true)

// Core 0 & 1 use different communication channels
// -----------------------------------------------

static  const   char_t  *argv_cnsCdc0_C0[] = { "console", "cdc0" };
static  const   char_t  *argv_cnsUrt0_C1[] = { "console", "urt0" };

static  const   boot_t  aFunction_C0[] = {
                            { .oSW=0x00U, .oFunction="console", .oBaudrate=KSERIAL_BAUDRATE_460800, .oSerialManager=KCDC0, .oArgC=2U, .oArgV=argv_cnsCdc0_C0 },
                        };
static  const   boot_t  aFunction_C1[] = {
                            { .oSW=0x00U, .oFunction="console", .oBaudrate=KSERIAL_BAUDRATE_460800, .oSerialManager=KURT0, .oArgC=2U, .oArgV=argv_cnsUrt0_C1 },
                        };

#define KDEF_COMM_C0        KCDC0
#define KDEF_COMM_C1        KURT0
#define KNB_FUNCTIONS_C0    (sizeof(aFunction_C0) / sizeof(boot_t))
#define KNB_FUNCTIONS_C1    (sizeof(aFunction_C1) / sizeof(boot_t))

// NOLINTNEXTLINE(misc-use-internal-linkage): Global constant declared in startUp.h
STRG_GLB_CONST(aStartUp_StrHelp[]) = "StartUp process\n"
                                     "================\n\n"

                                     "StartUp switch action. The default settings are:\n"
                                     "460800-bit/s, 8-bits, 2-stop-bits, no parity.\n\n"

                                     "   SW1\n"
                                     "    0   KCDC0, console (460800-bit/s) for core 0\n"
                                     "    0   KURT0, console (460800-bit/s) for core 1\n\n";

#else

// Core 0 & 1 use the same communication channel
// ---------------------------------------------

static  const   char_t  *argv_cnsUrt0_Cx[] = { "console", "urt0" };

static  const   boot_t  aFunction_Cx[] = {
                            { .oSW=0x00U, .oFunction="console", .oBaudrate=KSERIAL_BAUDRATE_460800, .oSerialManager=KURT0, .oArgC=2U, .oArgV=argv_cnsUrt0_Cx },
                        };

#define KDEF_COMM_Cx        KURT0
#define KNB_FUNCTIONS_Cx    (sizeof(aFunction_Cx) / sizeof(boot_t))

// NOLINTNEXTLINE(misc-use-internal-linkage): Global constant declared in startUp.h
STRG_GLB_CONST(aStartUp_StrHelp[]) = "StartUp process\n"
                                     "================\n\n"

                                     "StartUp switch action. The default settings are:\n"
                                     "460800-bit/s, 8-bits, 2-stop-bits, no parity.\n\n"

                                     "   SW1\n"
                                     "    0   KURT0, console (460800-bit/s) for core 0 & 1\n\n";
#endif

// Module strings

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
            urtxCnf_t       configureCDCx;
            proc_t          *process;
    const   boot_t          *functions;
    const   uKOS_module_t   *module;
    const   char_t          *identifier, *signature;

// Configure by default all the Serial Communication Managers
// Set the default communication device (KSYST)

    mode = 0;

    #if (CONFIG_DIFFERENT_SERIAL_PER_CORE_S == true)
    uint32_t    core;

    core = GET_RUNNING_CORE;

    switch (core) {
        default:
        case KCORE_0: {
            nbFunctions = (uint8_t)KNB_FUNCTIONS_C0;
            functions   = &aFunction_C0[0];

            serial_setDefSerialManager(KDEF_COMM_C0);
            kern_suspendProcess(500U);

            configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
            configureURTx.oStopBits = KSERIAL_STOPBITS_1;
            configureURTx.oParity   = KSERIAL_PARITY_NONE;
            configureURTx.oBaudRate = functions[mode].oBaudrate;
            configureURTx.oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX);
            serial_configure(KURT0, &configureURTx);

            configureCDCx.oNBBits   = KSERIAL_NB_BITS_8;
            configureCDCx.oStopBits = KSERIAL_STOPBITS_1;
            configureCDCx.oParity   = KSERIAL_PARITY_NONE;
            configureCDCx.oBaudRate = functions[mode].oBaudrate;
            configureCDCx.oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX);
            serial_configure(KCDC0, &configureCDCx);
            break;
        }
        case KCORE_1: {
            nbFunctions = (uint8_t)KNB_FUNCTIONS_C1;
            functions   = &aFunction_C1[0];

            serial_setDefSerialManager(KDEF_COMM_C1);
            kern_suspendProcess(500U);

            configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
            configureURTx.oStopBits = KSERIAL_STOPBITS_1;
            configureURTx.oParity   = KSERIAL_PARITY_NONE;
            configureURTx.oBaudRate = functions[mode].oBaudrate;
            configureURTx.oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX);
            serial_configure(KURT0, &configureURTx);
            break;
        }
    }

    #else
    nbFunctions = (uint8_t)KNB_FUNCTIONS_Cx;
    functions   = &aFunction_Cx[0];

    serial_setDefSerialManager(KDEF_COMM_Cx);
    kern_suspendProcess(500U);

    configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
    configureURTx.oStopBits = KSERIAL_STOPBITS_1;
    configureURTx.oParity   = KSERIAL_PARITY_NONE;
    configureURTx.oBaudRate = functions[mode].oBaudrate;
    configureURTx.oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX);
    serial_configure(KURT0, &configureURTx);
    #endif

// Bootstrap ...
// -------------

// Launch all the possible applications
// Determine the "i" index on the function table

    kern_getProcessRun(&process);
    for (i = 0U; i < nbFunctions; i++) {
        if (functions[i].oSW == mode) {
            kern_setSerialForProcess(process, functions[i].oSerialManager);
        }
    }

    system_getSystemId(&identifier);
    system_getSystemSignature(&signature);

    #if (CONFIG_DIFFERENT_SERIAL_PER_CORE_S == true)
    if (core != KCORE_0) {
    #endif

        (void)dprintf(KSYST, "%s", aStrLogo);
        (void)dprintf(KSYST, "Signature:\n%s\n\n", signature);
        (void)dprintf(KSYST, "%ssw = %"PRIX32"\n", identifier, mode);

    #if (CONFIG_DIFFERENT_SERIAL_PER_CORE_S == true)
    }
    #endif

    kern_suspendProcess(500U);

// Waiting for the first CDC0 connection and display the splash screen
// Core 0 uses CDC0 which has no host connected at boot time

    #if (CONFIG_DIFFERENT_SERIAL_PER_CORE_S == true)
    if (core == KCORE_0) {
        while (!TinyUSB_cdc_isConnected(0U)) {
            kern_suspendProcess(10U);
        }
        kern_suspendProcess(100U);
        (void)dprintf(KSYST, "%s", aStrLogo);
        (void)dprintf(KSYST, "Signature:\n%s\n\n", signature);
        (void)dprintf(KSYST, "%ssw = %"PRIX32"\n", identifier, mode);
    }
    #endif

    for (i = 0U; i < nbFunctions; i++) {
        if (functions[i].oSW == mode) {

// The communication

            switch (functions[i].oSerialManager) {

// If the serial device is already configured,
// do not reconfigure it again.
// This avoids corrupting ongoing transfers.
//
//              case KURT0: { configureURTx.oBaudRate = aFunction[i].oBaudrate; serial_configure(KURT0, &configureURTx); break; }
                case KCDC0: { configureCDCx.oBaudRate = functions[i].oBaudrate; serial_configure(KCDC0, &configureCDCx); break; }
                default: {

// Make MISRA happy :-)

                    break;
                }
            }

// The mode exist
// Found a module; execute it or error

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

// Make MISRA happy :-)

                        break;
                    }
                }
            }
        }
    }
}
