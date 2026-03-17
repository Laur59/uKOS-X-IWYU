/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; lib_storages.
; =============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     lib_storages system call interface module.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \defgroup Lib_storages Library for storage manager
 *
 * \brief Storage manager system calls
 *
 * The Lib_storages library unifies access to memory devices and data stores.
 * It ensures that storage is reliable, efficient, and simple to command.
 *
 * The storage manager offers a common interface. Whether card or flash,
 * it allows programmes to read and write data without caring for details.
 *
 * The sdcard manager controls removable cards. It brings familiar media to
 * embedded systems, where files can be logged, shared, or updated easily.
 *
 * The serialFlash manager governs serial flash memory. It provides fast
 * and persistent space for firmware, assets, and critical information.
 *
 * Together these managers make Lib_storages a safe foundation for data.
 * From portable media to embedded chips, all is handled with equal care.
 *
 * @{
 */

#ifdef CONFIG_MAN_SDCARD_S
#include    "sdcard/sdcard.h"
#endif
#ifdef CONFIG_MAN_SERIAL_FLASH_S
#include    "serialFlash/serialFlash.h"
#endif
#ifdef CONFIG_MAN_STORAGE_S
#include    "storage/storage.h"
#endif

/**!@}*/
