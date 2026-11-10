/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal: sdnand manager.
 */

#include    "sdnand.h"

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

#ifdef CONFIG_MAN_SDNAND_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "sdnand       sdnand manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "sdnand manager\n"
                                    "==============\n\n"

                                    "This manager ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Sdnand,                         // Module name (the first letter has to be upper case)
    KID_FAM_STORAGE,                // Family (defined in the module.h)
    KNUM_SDNAND,                    // Module identifier (defined in the module.h)
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
static  int32_t     local_sdnand_read(const sdnand_specification_t *specification, uint8_t *buffer, uint8_t nbSectors, uint32_t sector);
static  int32_t     local_sdnand_write(const sdnand_specification_t *specification, const uint8_t *buffer, uint8_t nbSectors, uint32_t sector);

/*
 * \brief Reserve the sdnand manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = sdnand_reserve(KMODE_READ_WRITE, 1234u);
 *    ....
 *    sdnand_xyz();
 *    ....
 *    status = sdnand_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode         Any mode
 * \param[in]   timeout             Timeout (1-ms of resolution)
 *                                  KWAIT_INFINITY, waiting forever
 *                                  KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return      KERR_STORAGE_NOERR  The manager is reserved
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_CHBSY  The manager is busy
 *
 */
int32_t sdnand_reserve([[maybe_unused]] reserveMode_t reserveMode, uint32_t timeout) {
    int32_t     status;
    uint32_t    core;

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
 * \brief Release the sdnand manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = sdnand_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode         Any mode
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_CAREL  Cannot release the manager
 *
 */
int32_t sdnand_release([[maybe_unused]] reserveMode_t reserveMode) {
    int32_t     status;
    uint32_t    core;

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
 * \brief Initialise the sdnand
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t                   status;
 * sdnand_specification_t    sdnand;
 *
 *    status = sdnand_initialise(&sdnand);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 *
 *    if (sdnand.oCapacityStatus == KSDNAND_CT_SD1) sdnand = "sdnand V.1";
 *    else                                          sdnand = "sdnand V.2";
 * \endcode
 *
 * \param[in]   *specification      Ptr on the sdnand specification
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_NODEV  No sdnand
 * \return      KERR_STORAGE_CANRE  sdnand not recognised
 *
 */
int32_t sdnand_initialise(sdnand_specification_t *specification) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_sdnand_initialise(specification);
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Is the sdnand present
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = sdnand_isPresent();
 * \endcode
 *
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_NODEV  No sdnand
 *
 */
int32_t sdnand_isPresent(void) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_sdnand_isPresent();
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Read 1 or more sectors from the sdnand
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 * int32_t    status;
 * int8_t     readBuffer[KNB_BYTES];
 *
 *    status = sdnand_read(&readBuffer[], KNB_BYTES, 5);
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
 * \return      KERR_STORAGE_NODEV  No sdnand
 * \return      KERR_STORAGE_CANRE  sdnand not recognised
 * \return      KERR_STORAGE_LNBU0  The number of sectors is = 0
 * \return      KERR_STORAGE_TRANT  Transfer not terminated
 *
 */
int32_t sdnand_read(uint8_t *buffer, uint32_t size, uint32_t sector) {
    int32_t                 status;
    uint8_t                 nbSectorsForThisCall, lastSectorBuffer[KSDNAND_SZ_SECTOR];
    uint32_t                i, nbSectors, nbBytesLastSector, wkSector;
    sdnand_specification_t  sdnand;
    uint8_t                 *memory;
    size_t                  inc;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

// Read the sdnand specifications

    if (sdnand_initialise(&sdnand) != KERR_STORAGE_NOERR) {
        PRIVILEGE_RESTORE;
        return KERR_STORAGE_NODEV;
    }

// Compute the number of sectors to read.
// We need to treat the last sector specially because
// the input buffer may not fill it fully, in which case
// we need to avoid reading beyond the last element in the buffer

    wkSector          = sector;
    nbSectors         = size / KSDNAND_SZ_SECTOR;
    nbBytesLastSector = size % KSDNAND_SZ_SECTOR;
    memory            = buffer;

// Write the sectors in chunks

    while (nbSectors > 0U) {
        nbSectorsForThisCall = (nbSectors > KSDNAND_MAX_SECTORS_PER_CALL) ? KSDNAND_MAX_SECTORS_PER_CALL : (uint8_t)nbSectors;

        if (local_sdnand_read(&sdnand, memory, nbSectorsForThisCall, wkSector) != KERR_STORAGE_NOERR) {
            PRIVILEGE_RESTORE;
            return KERR_STORAGE_TRANT;
        }

        inc       =  (size_t)nbSectorsForThisCall * (size_t)KSDNAND_SZ_SECTOR;
        memory    =  &memory[inc];
        wkSector  += (uint32_t)nbSectorsForThisCall;
        nbSectors -= (uint32_t)nbSectorsForThisCall;
    }

// Read the last sector's data, which may not fill it fully

    if (nbBytesLastSector > 0U) {
        if (local_sdnand_read(&sdnand, lastSectorBuffer, 1u, wkSector) != KERR_STORAGE_NOERR) {
            PRIVILEGE_RESTORE;
            return KERR_STORAGE_TRANT;
        }

        for (i = 0U; i < nbBytesLastSector; i++) {
            *memory = lastSectorBuffer[i];
            memory++;
        }
    }
    PRIVILEGE_RESTORE;
    return KERR_STORAGE_NOERR;
}

/*
 * \brief Write 1 or more sectors to the sdnand
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 *          int32_t    status;
 * const    int8_t     writeBuffer[KNB_BYTES];
 *
 *    status = sdnand_write(&writeBuffer[], KNB_BYTES, 5);
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
 * \return      KERR_STORAGE_NODEV  No sdnand
 * \return      KERR_STORAGE_CANRE  sdnand not recognised
 * \return      KERR_STORAGE_LNBU0  The number of sectors is = 0
 * \return      KERR_STORAGE_TRANT  Transfer not terminated
 *
 */
int32_t sdnand_write(const uint8_t *buffer, uint32_t size, uint32_t sector) {
            int32_t                 status;
            uint8_t                 nbSectorsForThisCall, lastSectorBuffer[KSDNAND_SZ_SECTOR];
            uint32_t                i, nbSectors, nbBytesLastSector, wkSector;
            sdnand_specification_t  sdnand;
            size_t                  inc;
    const   uint8_t                 *memory;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

// Read the sdnand specifications

    if (sdnand_initialise(&sdnand) != KERR_STORAGE_NOERR) {
        PRIVILEGE_RESTORE;
        return KERR_STORAGE_NODEV;
    }

// Compute the number of sectors to write.
// We need to treat the last sector specially because
// the input buffer may not fill it fully, in which case
// we need to avoid writing beyond the last element in the buffer

    wkSector          = sector;
    nbSectors         = size / KSDNAND_SZ_SECTOR;
    nbBytesLastSector = size % KSDNAND_SZ_SECTOR;
    memory            = buffer;

// Write the sectors in chunks.

    while (nbSectors > 0U) {
        nbSectorsForThisCall = (nbSectors > KSDNAND_MAX_SECTORS_PER_CALL) ? KSDNAND_MAX_SECTORS_PER_CALL : (uint8_t)nbSectors;

        if (local_sdnand_write(&sdnand, memory, nbSectorsForThisCall, wkSector) != KERR_STORAGE_NOERR) {
            PRIVILEGE_RESTORE;
            return KERR_STORAGE_TRANT;
        }

        inc       =  (size_t)nbSectorsForThisCall * (size_t)KSDNAND_SZ_SECTOR;
        memory    =  &memory[inc];
        wkSector  += (uint32_t)nbSectorsForThisCall;
        nbSectors -= (uint32_t)nbSectorsForThisCall;
    }

// Write the last sector's data, which may not fill it fully
// Fill the gap with 0x00 (for test)

    if (nbBytesLastSector > 0U) {
        for (i = 0U; i < KSDNAND_SZ_SECTOR; i++) {
            lastSectorBuffer[i] = 0U;
        }
        for (i = 0U; i < nbBytesLastSector; i++) {
            lastSectorBuffer[i] = *memory;
            memory++;
        }
        if (local_sdnand_write(&sdnand, lastSectorBuffer, 1u, wkSector) != KERR_STORAGE_NOERR) {
            PRIVILEGE_RESTORE;
            return KERR_STORAGE_TRANT;
        }

    }
    PRIVILEGE_RESTORE;
    return KERR_STORAGE_NOERR;
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
 *    status = sdnand_ioctl(KGET_BLOCK_SIZE, buffer);
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
int32_t sdnand_ioctl(storageIoctl_t command, void *buffer) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_sdnand_ioctl(command, buffer);
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

        if (kern_createMutex(KSDNAND_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "sdnand: create mutx"); exit(EXIT_OS_PANIC); }

        status = stub_sdnand_init();
    }
    RETURN_INT_RESTORE(status);
}

/*
 * \brief local_sdnand_read
 *
 * - This function reads 1 or more sectors (<= 128)
 *
 */
static  int32_t local_sdnand_read(const sdnand_specification_t *specification, uint8_t *buffer, uint8_t nbSectors, uint32_t sector) {
    int32_t     status;

    status = local_init();
    if (status != KERR_STORAGE_NOERR) { return status; }

    status = stub_sdnand_read(specification, buffer, nbSectors, sector);
    return status;
}

/*
 * \brief local_sdnand_write
 *
 * - This function writes 1 or more sectors (<= 128)
 *
 */
static  int32_t local_sdnand_write(const sdnand_specification_t *specification, const uint8_t *buffer, uint8_t nbSectors, uint32_t sector) {
    int32_t     status;

    status = local_init();
    if (status != KERR_STORAGE_NOERR) { return status; }

    status = stub_sdnand_write(specification, buffer, nbSectors, sector);
    return status;
}

#endif
