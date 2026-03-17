/*
; viewer_uvc0.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Laurent von Allmen      The 2026-02-04
; Modifs:
;
; Project:  uKOS-X
; Goal:     Image viewer.
;           This tool allows to send a simulated image via the uvc0 manager.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

#include    "types.h"

extern  const   char_t      aStrApplication[];
extern  const   char_t      aStrHelp[];

/*
 * \brief viewer_uvc0
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int32_t viewer_uvc0(uint32_t argc, const char_t *argv[]);

/*
 * \brief viewer_uvc0_clean
 *
 * - Try to clean the ressources
 *      - Free all the ressources
 *
 */
int32_t viewer_uvc0_clean(uint32_t argc, const char_t *argv[]);
