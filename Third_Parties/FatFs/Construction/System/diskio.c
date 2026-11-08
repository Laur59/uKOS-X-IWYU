/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     uKOS diskio interface to the uKOS-X devices
 */

#include    "types.h"
#include    "os_errors.h"
#include    "ff.h"
#include    "diskio.h"
#include    "storage/storage.h"
#include    "sdcard/sdcard.h"
#include    "flash/flash.h"
#include    "macros.h"
#include    <time.h>

#define KWAIT_INFINITY  ((uint32_t)(-1))        // Waiting forever

[[maybe_unused]]
static  sdcard_specification_t  vSdCard;

enum {
        DEV_SDCARD = 0U,                        // Map sdcard to physical drive 0
        DEV_FLASH                               // Map flash to physical drive 1
};

/*
 * \brief disk_status
 *
 * - Get the status (is present)
 *
 */
DSTATUS     disk_status(BYTE pdrv) {
    int32_t     status;
    DSTATUS     fatFsStatus = STA_NOINIT;

    switch (pdrv) {
        #ifdef SDCARD_S
        case DEV_SDCARD: {
            RESERVE(SDCARD, KMODE_READ_WRITE);
            status = storage_isPresent(KSDCARD);
            RELEASE(SDCARD, KMODE_READ_WRITE);

            fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NODISK);
            return (fatFsStatus);
        }
        #endif

        #ifdef FLASH_S
        case DEV_FLASH: {
            RESERVE(FLASH, KMODE_READ_WRITE);
            status = storage_isPresent(KFLASH);
            RELEASE(FLASH, KMODE_READ_WRITE);

            fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NODISK);
            return (fatFsStatus);
        }
        #endif

        default: {
            return (fatFsStatus);
        }

    }
}

/*
 * \brief disk_initialize
 *
 * - Initialise the disk
 *
 */
DSTATUS     disk_initialize(BYTE pdrv) {
    int32_t     status;
    DSTATUS     fatFsStatus = STA_NOINIT;

    switch (pdrv) {
        #ifdef SDCARD_S
        case DEV_SDCARD: {
            RESERVE(SDCARD, KMODE_READ_WRITE);
            status = storage_initialise(KSDCARD, &vSdCard);
            RELEASE(SDCARD, KMODE_READ_WRITE);

            fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NOINIT);
            return (fatFsStatus);
        }
        #endif

        #ifdef FLASH_S
        case DEV_FLASH: {
            RESERVE(FLASH, KMODE_READ_WRITE);
            status = storage_initialise(KFLASH, nullptr);
            RELEASE(FLASH, KMODE_READ_WRITE);

            fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NOINIT);
            return (fatFsStatus);
        }
        #endif

        default: {
            return (fatFsStatus);
        }

    }
}

/*
 * \brief disk_read
 *
 * - Read sectors
 *
 */
DRESULT     disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count) {
    int32_t     status;
    uint16_t    szSector;
    DRESULT     fatFsResult = RES_PARERR;

    switch (pdrv) {
        #ifdef SDCARD_S
        case DEV_SDCARD: {
            RESERVE(SDCARD, KMODE_READ_WRITE);
            storage_ioctl(KSDCARD, KGET_SECTOR_SIZE, (void *)&szSector);
            status = storage_read(KSDCARD, (uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
            RELEASE(SDCARD, KMODE_READ_WRITE);

            fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
            return (fatFsResult);
        }
        #endif

        #ifdef FLASH_S
        case DEV_FLASH: {
            RESERVE(FLASH, KMODE_READ_WRITE);
            storage_ioctl(KFLASH, KGET_SECTOR_SIZE, (void *)&szSector);
            status = storage_read(KFLASH, (uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
            RELEASE(FLASH, KMODE_READ_WRITE);

            fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
            return (fatFsResult);
        }
        #endif

        default: {
            return (fatFsResult);
        }

    }
}

/*
 * \brief disk_write
 *
 * - Write sectors
 *
 */
DRESULT     disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count) {
    int32_t     status;
    uint16_t    szSector;
    DRESULT     fatFsResult = RES_PARERR;

    switch (pdrv) {
        #ifdef SDCARD_S
        case DEV_SDCARD: {
            RESERVE(SDCARD, KMODE_READ_WRITE);
            storage_ioctl(KSDCARD, KGET_SECTOR_SIZE, (void *)&szSector);
            status = storage_write(KSDCARD, (const uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
            RELEASE(SDCARD, KMODE_READ_WRITE);

            fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
            return (fatFsResult);
        }
        #endif

        #ifdef FLASH_S
        case DEV_FLASH: {
            RESERVE(FLASH, KMODE_READ_WRITE);
            storage_ioctl(KFLASH, KGET_SECTOR_SIZE, (void *)&szSector);
            status = storage_write(KFLASH, (const uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
            RELEASE(FLASH, KMODE_READ_WRITE);

            fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
            return (fatFsResult);
        }
        #endif

        default: {
            return (fatFsResult);
        }

    }
}

/*
 * \brief disk_ioctl
 *
 * - Misc functions
 *
 */
DRESULT     disk_ioctl(BYTE pdrv, BYTE cmd, void *buff) {
    int32_t     status;
    DRESULT     fatFsResult = RES_PARERR;

    switch (pdrv) {
        #ifdef SDCARD_S
        case DEV_SDCARD: {
            RESERVE(SDCARD, KMODE_READ_WRITE);
            status = storage_ioctl(KSDCARD, (storageIoctl_t)cmd, buff);
            RELEASE(SDCARD, KMODE_READ_WRITE);

            fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_PARERR);
            return (fatFsResult);
        }
        #endif

        #ifdef FLASH_S
        case DEV_FLASH: {
            RESERVE(FLASH, KMODE_READ_WRITE);
            status = storage_ioctl(KFLASH, (storageIoctl_t)cmd, buff);
            RELEASE(FLASH, KMODE_READ_WRITE);

            fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_PARERR);
            return (fatFsResult);
        }
        #endif

        default: {
            return (fatFsResult);
        }

    }
}

/*
 * \brief get_fattime
 *
 * - Read the local time
 *
 */
DWORD   get_fattime (void) {
    time_t      now;
    tm_t        localTime;

    now = time(nullptr);
    localtime_r(&now, &localTime);

    return ( ((DWORD)localTime.tm_mday<<16U) | ((DWORD)(localTime.tm_mon + 1)<<21U) | ((DWORD)(localTime.tm_year - 80)<<25U)
           | ((DWORD)localTime.tm_hour<<11U) | ((DWORD)localTime.tm_min<<5U)        | ((DWORD)localTime.tm_sec>>1U));


}
