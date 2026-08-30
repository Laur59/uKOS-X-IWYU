/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Some common routines used in many modules.
 */

#pragma once

#include    <stdint.h>

#include    "types.h"

#ifdef __cplusplus
extern  "C" {
#endif

/*
 * \brief cmns_init
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
extern  void    cmns_init(void);

/*
 * \brief cmns_send
 *
 * \param[in]   serialManager   Serial Communication Manager
 * \param[in]   *ascii          Ptr on the ascii buffer
 *
 * \note This function does not return a value (None).
 *
 */
extern  void    cmns_send(serialManager_t serialManager, const char_t *ascii);

/*
 * \brief cmns_receive
 *
 * \param[out]  *data       Data received
 *
 * \note This function does not return a value (None).
 *
 */
extern  void    cmns_receive(serialManager_t serialManager, char_t *data);

/*
 * \brief cmns_wait
 *
 * \param[in]   us      Delay in us
 *
 * \note This function does not return a value (None).
 *
 */
extern  void    cmns_wait(uint32_t us);

#ifdef __cplusplus
}
#endif
