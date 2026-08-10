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
#include    <time.h>

#include    "calendar/calendar.h"
#include    "ip.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "serial/serial.h"
#include    "serial_common.h"
#include    "switch/switch.h"
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

static  const   char_t  *argv_cnsUrt0[] = { "console", "urt0" };
static  const   char_t  *argv_cnsUrt1[] = { "console", "urt1" };
static  const   char_t  *argv_cnsWfi0[] = { "console", "wfi0" };
static  const   char_t  *argv_sloader[] = { "sloader", "-run" };
static  const   char_t  *argv_userApp[] = { "userapp", "1234" };

static  const   boot_t  aFunction[] = {
                            { .oFunction="console", .oSerialManager=KURT0, .oArgV=argv_cnsUrt0, .oArgC=2U, .oSW=0x00U, .oBaudrate=KSERIAL_BAUDRATE_460800 },
                            { .oFunction="sloader", .oSerialManager=KURT0, .oArgV=argv_sloader, .oArgC=2U, .oSW=0x01U, .oBaudrate=KSERIAL_BAUDRATE_460800 },
                            { .oFunction="console", .oSerialManager=KURT1, .oArgV=argv_cnsUrt1, .oArgC=2U, .oSW=0x02U, .oBaudrate=KSERIAL_BAUDRATE_460800 },
                            { .oFunction="sloader", .oSerialManager=KURT1, .oArgV=argv_sloader, .oArgC=2U, .oSW=0x03U, .oBaudrate=KSERIAL_BAUDRATE_460800 },
                            { .oFunction="userapp", .oSerialManager=KURT0, .oArgV=argv_userApp, .oArgC=2U, .oSW=0x04U, .oBaudrate=KSERIAL_BAUDRATE_460800 },
                            { .oFunction="console", .oSerialManager=KWFI0, .oArgV=argv_cnsWfi0, .oArgC=2U, .oSW=0x05U, .oBaudrate=KSERIAL_BAUDRATE_921600 },
                        };

#define KDEF_COMM       KURT0
#define KNB_FUNCTIONS   (sizeof(aFunction) / sizeof(boot_t))

// Module strings

// NOLINTNEXTLINE(misc-use-internal-linkage): Global constant declared in startUp.h
STRG_GLB_CONST(aStartUp_StrHelp[]) = "StartUp process\n"
                                     "===============\n\n"

                                     "StartUp switch action. The default settings are:\n"
                                     "460800-bit/s, 8-bits, 2-stop-bits, no parity.\n\n"

                                     "   SW3\n"
                                     "    0   KURT0, console (460800-bit/s).\n"
                                     "    1   KURT0, sloader (460800-bit/s).\n"
                                     "    2   KURT1, console (460800-bit/s).\n"
                                     "    3   KURT1, sloader (460800-bit/s).\n"
                                     "    4   KURT0, userapp (460800-bit/s).\n"
                                     "    5   KWFI0, console (921600-bit/s).\n\n";

STRG_LOC_CONST(aStrLogo[]) = STRG_LOGO;

/*
 * \brief stub_startUp_launch
 *
 */
void    stub_startUp_launch(void) {
            uint8_t         i;
            uint16_t        index;
            uint32_t        mode;
            uint64_t        unixTime;
            time_t          now;
            tm_t            localTime;
            bool            error = false;
            urtxCnf_t       configureURTx;
            proc_t          *process;
    const   uKOS_module_t   *module;
    const   char_t          *identifier, *signature;

// Configure by default all the Serial Communication Managers
// Set the default communication device (KSYST)

    switch_read(&mode);
    if (mode >= KNB_FUNCTIONS) {
        mode = 0U;
    }

    serial_setDefSerialManager(KDEF_COMM);

    configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
    configureURTx.oStopBits = KSERIAL_STOPBITS_1;
    configureURTx.oParity   = KSERIAL_PARITY_NONE;
    configureURTx.oBaudRate = aFunction[mode].oBaudrate;
    configureURTx.oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX);
    serial_configure(KURT0, &configureURTx);
    serial_configure(KURT1, &configureURTx);
    serial_configure(KURT2, &configureURTx);
    serial_configure(KURT3, &configureURTx);

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

    now = time(nullptr);
    localtime_r(&now, &localTime);

    calendar_readUnixTime(KFROM_TIMER, &unixTime);
    (void)dprintf(KSYST, "Epoch = %"PRIu64", Local time: %s", unixTime, asctime(&localTime));

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
//              case KURT1: { configureURTx.oBaudRate = aFunction[i].oBaudrate; serial_configure(KURT1, &configureURTx); break; }
//              case KURT2: { configureURTx.oBaudRate = aFunction[i].oBaudrate; serial_configure(KURT2, &configureURTx); break; }
//              case KURT3: { configureURTx.oBaudRate = aFunction[i].oBaudrate; serial_configure(KURT3, &configureURTx); break; }
//              case KWFI0: { configureURTx.oBaudRate = aFunction[i].oBaudrate; serial_configure(KWFI0, &configureURTx); break; }
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
