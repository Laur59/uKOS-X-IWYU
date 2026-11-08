/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     storage manager.
 */

#include "storage.h"

#include <stdint.h>

#include "macros.h"
#include "modules.h"
#include "sdcard/sdcard.h"
#include "os_errors.h"
#ifdef CONFIG_MAN_FLASH_S
#include "flash/flash.h"
#endif
#include "types.h"

#ifdef CONFIG_MAN_STORAGE_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "storage      storage manager.                          (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "storage manager\n"
                                    "===============\n\n"

                                    "This manager ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Storage,                        // Module name (the first letter has to be upper case)
    KID_FAM_STORAGE,                // Family (defined in the module.h)
    KNUM_STORAGE,                   // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);

/*
 * \brief Reserve the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = storage_reserve(FLASH, KMODE_READ_WRITE, 1234U);
 *    ....
 *    storage__xyz();
 *    ....
 *    status = storage_release(FLASH, KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   manager             Storage manager
 * \param[in]   reserveMode         Any mode
 * \param[in]   timeout             Timeout (1-ms of resolution)
 *                                  KWAIT_INFINITY, waiting forever
 *                                  KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return      KERR_FLASH_XXXXX    Depends on the "xxxx" device manager
 *
 */
int32_t storage_reserve(storage_manager_t manager, reserveMode_t reserveMode, uint32_t timeout) {

    switch (manager) {

        #ifdef CONFIG_MAN_SDCARD_S
        case KSDCARD: { return sdcard_reserve(reserveMode, timeout); }
        #endif

        #ifdef CONFIG_MAN_FLASH_S
        case KFLASH: { return flash_reserve(reserveMode, timeout);   }
        #endif

        default: { return KERR_STORAGE_NODEV;                                     }
    }

}

/*
 * \brief Release the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = storage_release(FLASH, KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   manager             Storage manager
 * \param[in]   reserveMode         Any mode
 * \return      KERR_STORAGE_XXXXX  Depends on the "xxxx" device manager
 *
 */
int32_t storage_release(storage_manager_t manager, reserveMode_t reserveMode) {

    switch (manager) {

        #ifdef CONFIG_MAN_SDCARD_S
        case KSDCARD: { return sdcard_release(reserveMode); }
        #endif

        #ifdef CONFIG_MAN_FLASH_S
        case KFLASH: { return flash_release(reserveMode);     }
        #endif

        default: { return KERR_STORAGE_NODEV;                            }
    }

}

/*
 * \brief Initialise the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = storage_initialise(FLASH, nullptr);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]   manager             Storage manager
 * \param[in]   *specification      Ptr on the sdcard specification
 * \return      KERR_STORAGE_XXXXX  Depends on the "xxxx" device manager
 *
 */
int32_t storage_initialise(storage_manager_t manager, [[maybe_unused]] void  *specification) {

    switch (manager) {

        #ifdef CONFIG_MAN_SDCARD_S
        case KSDCARD: { return sdcard_initialise((sdcard_specification_t *)specification); }
        #endif

        #ifdef CONFIG_MAN_FLASH_S
        case KFLASH: { return flash_initialise();                                            }
        #endif

        default: { return KERR_STORAGE_NODEV;                                                }
    }

}

/*
 * \brief Is the storage manager present
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = storage_isPresent(FLASH);
 * \endcode
 *
 * \return      KERR_STORAGE_NOERR  OK
 * \return      KERR_STORAGE_GEERR  General error
 * \return      KERR_STORAGE_NODEV  No sdnand
 *
 */
int32_t storage_isPresent(storage_manager_t manager) {

    switch (manager) {

        #ifdef CONFIG_MAN_SDCARD_S
        case KSDCARD: { return sdcard_isPresent(); }
        #endif

        #ifdef CONFIG_MAN_FLASH_S
        case KFLASH: { return flash_isPresent();     }
        #endif

        default: { return KERR_STORAGE_NODEV;                    }
    }

}

/*
 * \brief Read 1 or more sectors from the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 * int32_t    status;
 * int8_t     readBuffer[KNB_BYTES];
 *
 *    status = storage_read(FLASH, &readBuffer[], KNB_BYTES, 5);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]   manager             Storage manager
 * \param[in]   *buffer             Ptr on the buffer
 * \param[in]   size                Number of bytes to read
 * \param[in]   sector              Start sector
 * \return      KERR_STORAGE_XXXXX  Depends on the "xxxx" device manager
 *
 */
int32_t storage_read(storage_manager_t manager, uint8_t *buffer, uint32_t size, uint32_t sector) {

    switch (manager) {

        #ifdef CONFIG_MAN_SDCARD_S
        case KSDCARD: { return sdcard_read(buffer, size, sector); }
        #endif

        #ifdef CONFIG_MAN_FLASH_S
        case KFLASH: { return flash_read(buffer, size, sector); }
        #endif

        default: { return KERR_STORAGE_NODEV;                                  }
    }

}

/*
 * \brief Write 1 or more sectors to the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 *          int32_t    status;
 * const    int8_t     writeBuffer[KNB_BYTES];
 *
 *    status = storage_write(FLASH, &writeBuffer[], KNB_BYTES, 5);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]   manager             Storage manager
 * \param[in]   *buffer             Ptr on the buffer
 * \param[in]   size                Number of bytes to write
 * \param[in]   sector              Start sector
 * \return      KERR_STORAGE_XXXXX  Depends on the "xxxx" device manager
 *
 */
int32_t storage_write(storage_manager_t manager, const uint8_t *buffer, uint32_t size, uint32_t sector) {

    switch (manager) {

        #ifdef CONFIG_MAN_SDCARD_S
        case KSDCARD: { return sdcard_write(buffer, size, sector); }
        #endif

        #ifdef CONFIG_MAN_FLASH_S
        case KFLASH: { return flash_write(buffer, size, sector);     }
        #endif

        default: { return KERR_STORAGE_NODEV;                                   }
    }

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
 *    status = storage_ioctl(FLASH, KGET_BLOCK_SIZE, buffer);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]   manager             Storage manager
 * \param[in]   command             Command
 * \param[in]   *buffer             Ptr on the buffer
 * \return      KERR_STORAGE_XXXXX  Depends on the "xxxx" device manager
 *
 */
int32_t storage_ioctl(storage_manager_t manager, storageIoctl_t command, void *buffer) {

    switch (manager) {

        #ifdef CONFIG_MAN_SDCARD_S
        case KSDCARD: { return sdcard_ioctl(command, buffer); }
        #endif

        #ifdef CONFIG_MAN_FLASH_S
        case KFLASH: { return flash_ioctl(command, buffer); }
        #endif

        default: { return KERR_STORAGE_NODEV;                              }
    }

}

#endif
