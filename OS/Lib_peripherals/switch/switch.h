/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; switch.
; =======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     misc manager.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup switch Switch
 *
 * \brief Switch
 *
 * Switch management
 *
 * @{
 */

#ifdef __cplusplus
extern  "C" {
#endif

extern  int32_t stub_switch_init(void);
extern  int32_t stub_switch_read(uint32_t *mode);

/*!
 * \brief Read the configuration mode
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    mode;
 *
 *    status = switch_read(&mode);
 * \endcode
 *
 * \param[out]  *mode               Ptr on the jumper value
 * \return      KERR_SWITCH_NOERR   OK
 *
 */
extern  int32_t switch_read(uint32_t *mode);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
