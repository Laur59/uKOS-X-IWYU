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
#include    "modules.h"
#include    "os_errors.h"
#include    "serial/serial.h"
#include    "serial_common.h"
#include    "switch/switch.h"
#include    "system/system.h"
#ifdef CONFIG_MAN_TEMPERATURE_S
#include    "temperature/temperature.h"
#endif
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

static  const   char_t  *argv_cnsUrt0[] = { "console", "urt0" };
static  const   char_t  *argv_mpyUrt0[] = { "mpy",     "urt0", "-internal", "100000" };

static  const   boot_t  aFunction[] = {
                            { .oFunction="console", .oSerialManager=KURT0, .oArgV=argv_cnsUrt0, .oArgC=2U, .oSW=0x00U, .oBaudrate=KSERIAL_BAUDRATE_460800 },
                            { .oFunction="mpy",     .oSerialManager=KURT0, .oArgV=argv_mpyUrt0, .oArgC=4U, .oSW=0x01U, .oBaudrate=KSERIAL_BAUDRATE_460800 }
                        };

#define KDEF_COMM       KURT0
#define KNB_FUNCTIONS   (sizeof(aFunction) / sizeof(boot_t))

// Module strings

// NOLINTNEXTLINE(misc-use-internal-linkage): Global constant declared in startUp.h
STRG_GLB_CONST(aStartUp_StrHelp[]) = "StartUp process\n"
                                     "================\n\n"

                                     "StartUp switch action. The default settings are:\n"
                                     "460800-bit/s, 8-bits, 2-stop-bits, no parity.\n\n"

                                     "   SW1\n"
                                     "    0   KURT0, console (460800-bit/s).\n"
                                     "    1   KURT0, mpy     (460800-bit/s).\n\n";

STRG_LOC_CONST(aStrLogo[]) = STRG_LOGO;

/*
 * \brief stub_startUp_launch
 *
 */
void    stub_startUp_launch(void) {
            uint8_t         i;
            uint16_t        index;
            uint32_t        mode;
            bool            error = false;
            urtxCnf_t       configureURTx;
            cdcxCnf_t       configureCDCx;
            proc_t          *process;
    const   uKOS_module_t   *module;
    const   char_t          *identifier, *signature;

// Configure by default all the Serial Communication Managers
// Set the default communication device (KSYST)

    switch_read(&mode);
    if (mode >= KNB_FUNCTIONS) {
        mode = 0;
    }

    serial_setDefSerialManager(KDEF_COMM);

    configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
    configureURTx.oStopBits = KSERIAL_STOPBITS_1;
    configureURTx.oParity   = KSERIAL_PARITY_NONE;
    configureURTx.oBaudRate = aFunction[mode].oBaudrate;
    configureURTx.oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX);
    configureCDCx.oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX);
    serial_configure(KURT0, &configureURTx);
    serial_configure(KCDC0, &configureCDCx);

// Bootstrap ...
// -------------

// Launch all the possible applications
// Determine the "i" index on the function table

    kern_getProcessRun(&process);
    for (i = 0U; i < (uint8_t)KNB_FUNCTIONS; i++) {
        if (aFunction[i].oSW == mode) {
            kern_setSerialForProcess(process, aFunction[i].oSerialManager);
        }
    }

    system_getSystemId(&identifier);
    system_getSystemSignature(&signature);

    (void)dprintf(KSYST, "%s", aStrLogo);
    (void)dprintf(KSYST, "Signature:\n%s\n\n", signature);
    (void)dprintf(KSYST, "%ssw = %"PRIX32"\n", identifier, mode);

    #ifdef CONFIG_MAN_TEMPERATURE_S
    float64_t   temperature;
    temperature_read(&temperature);
    (void)dprintf(KSYST, "System temperature = %5.2f [K]\n\n", temperature);
    #endif

    kern_suspendProcess(500U);

    for (i = 0U; i < (uint8_t)KNB_FUNCTIONS; i++) {
        if (aFunction[i].oSW == mode) {

// The communication

            switch (aFunction[i].oSerialManager) {

// If the serial device is already configured,
// do not reconfigure it again.
// This avoids corrupting ongoing transfers.
//
//              case KURT0: { configureURTx.oBaudRate = aFunction[i].oBaudrate; serial_configure(KURT0, &configureURTx); break; }
                default: {

// Make MISRA happy :-)

                    break;
                }
            }

// The mode exist
// Found a module; execute it or error

            if (system_getModuleName(aFunction[i].oFunction, &index, &module) != KERR_SYSTEM_NOERR) {
                error = true;
            }

            if (error) {
                (void)dprintf(KSYST, "Module not found or user memory busy by a running application.\n\n");
                while (true) { kern_suspendProcess(1U); }
            }
            else {

                switch (module->oExecution(aFunction[i].oArgC, aFunction[i].oArgV)) {
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
