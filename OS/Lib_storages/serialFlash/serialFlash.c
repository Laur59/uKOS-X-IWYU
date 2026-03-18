/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     serialFlash manager.
 */

#include    "serialFlash.h"

#include    <stdint.h>
#include    <stdlib.h>

#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "storage/storage.h"
#include    "types.h"

#ifdef CONFIG_MAN_SERIAL_FLASH_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "serialFlash  serialFlash manager.                      (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "serialFlash manager\n"
                                    "===================\n\n"

                                    "This manager ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    SerialFlash,                    // Module name (the first letter has to be upper case)
    KID_FAM_STORAGE,                // Family (defined in the module.h)
    KNUM_SERIAL_FLASH,              // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);

// Library specific
// ================

static  mutx_t      *vMutex_Reserve[KNB_CORES];

// Prototypes

static  int32_t     local_init(void);

/*
 * \brief Reserve the serialFlash manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = serialFlash_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    serialFlash_xyz();
 *    ....
 *    status = serialFlash_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode         Any mode
 * \param[in]   timeout             Timeout (1-ms of resolution)
 * \param[in]   -                   KWAIT_INFINITY, waiting forever
 * \param[in]   -                   KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return      KERR_STORAGE_NOERR  The manager is reserved
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_CHBSY  The manager is busy
 *
 */
int32_t serialFlash_reserve(reserveMode_t reserveMode, uint32_t timeout) {
    int32_t     status;
    uint32_t    core;

    UNUSED(reserveMode);

    core = GET_RUNNING_CORE;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = kern_lockMutex(vMutex_Reserve[core], timeout);
    if (status != KERR_KERN_NOERR) {
        PRIVILEGE_RESTORE;
        return KERR_STORAGE_CHBSY;
    }

    PRIVILEGE_RESTORE;
    return KERR_STORAGE_NOERR;
}

/*
 * \brief Release the serialFlash manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = serialFlash_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode         Any mode
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_CAREL  Cannot release the manager
 *
 */
int32_t serialFlash_release(reserveMode_t reserveMode) {
    int32_t     status;
    uint32_t    core;

    UNUSED(reserveMode);

    core = GET_RUNNING_CORE;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = kern_unlockMutex(vMutex_Reserve[core]);
    if (status != KERR_KERN_NOERR) {
        PRIVILEGE_RESTORE;
        return KERR_STORAGE_CAREL;
    }

    PRIVILEGE_RESTORE;
    return KERR_STORAGE_NOERR;
}

/*
 * \brief Initialise the serialFlash
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = serialFlash_initialise();
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]   -
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 *
 */
int32_t serialFlash_initialise(void) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_serialFlash_initialise();
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Read the status of the serialFlash
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = serialFlash_readStatus();
 * \endcode
 *
 * \param[in]   -
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_NODEV  No serialFlash
 *
 */
int32_t serialFlash_readStatus(void) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_serialFlash_readStatus();
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Read 1 or more sectors from the serialFlash
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 * int32_t    status;
 * int8_t     readBuffer[KNB_BYTES];
 *
 *    status = serialFlash_read(&readBuffer[], KNB_BYTES, 5);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]   *buffer             Ptr on the buffer
 * \param[in]   size                Number of bytes to read
 * \param[in]   sector              Start sector
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_LNBU0  The number of sectors is = 0
 *
 */
int32_t serialFlash_read(uint8_t *buffer, uint32_t size, uint32_t sector) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_serialFlash_read(buffer, size, sector);
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Write 1 or more sectors to the serialFlash
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 *          int32_t    status;
 * const    int8_t     writeBuffer[KNB_BYTES];
 *
 *    status = serialFlash_write(&writeBuffer[], KNB_BYTES, 5);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]   *buffer             Ptr on the buffer
 * \param[in]   size                Number of bytes to write
 * \param[in]   sector              Start sector
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_LNBU0  The number of sectors is = 0
 *
 */
int32_t serialFlash_write(const uint8_t *buffer, uint32_t size, uint32_t sector) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_serialFlash_write(buffer, size, sector);
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Get some storage parameters by ioctl
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t    buffer[10];
 *
 * int32_t    status;
 *
 *    status = serialFlash_ioctl(KGET_BLOCK_SIZE, buffer);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]   command             Command
 * \param[in]   *buffer             Ptr on the buffer
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 *
 */
int32_t serialFlash_ioctl(storageIoctl_t command, void *buffer) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_serialFlash_ioctl(command, buffer);
    PRIVILEGE_RESTORE;
    return status;
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static  int32_t local_init(void) {
            int32_t     status = KERR_STORAGE_NOERR;
            uint32_t    core;
    static  bool        vInit[KNB_CORES] = MCSET(false);

    core = GET_RUNNING_CORE;

    INTERRUPTION_OFF;
    if (!vInit[core]) {
        vInit[core] = true;

        if (kern_createMutex(KSERIAL_FLASH_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "serialFlash: create mutx"); exit(EXIT_OS_PANIC); }

        status = stub_serialFlash_init();
    }
    RETURN_INT_RESTORE(status);
}

#endif
