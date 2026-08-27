/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Dump of the record trace fifo and log buffer, for the crash and exit paths.
 */

#pragma once

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \addtogroup record
 * @{
 */

/*!
 * \defgroup private_recordDump Private Record Dump
 *
 * \brief Private record dump functions
 *
 * Rendering of the trace fifo and of the log buffer on the default console.
 * Reserved for the exception and exit paths (exce.c, crt0_exit.c); they are
 * not part of the user application interface.
 *
 * @{
 */

#ifdef __cplusplus
extern  "C" {
#endif

/*!
 * \brief Display the user trace
 *
 * Drains the trace fifo of every core on KDEF0. The read pointer is consumed,
 * so a second call displays nothing.
 *
 * \note This function does not return a value (None).
 *
 */
extern  void    record_printTrace(void);

/*!
 * \brief Display the user log
 *
 * Displays the log buffer of every core on KDEF0, oldest entry first. Entries
 * are marked as they are printed, so a second call displays nothing.
 *
 * \note This function does not return a value (None).
 *
 */
extern  void    record_printLog(void);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
/**@}*/
