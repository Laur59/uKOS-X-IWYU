/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; ui.
; ===

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Demo of a C application.
;           Simple UI for the basic demo.
;
;-----
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#pragma once

// Display size

#define KBUF_LINES          10U                                         // Limited buffer (10 * KLCD_WIDTH * 2) to force partial rendering
#define KLCD_WIDTH          320U                                        // LCD width
#define KLCD_HEIGHT         240U                                        // LCD height

// Used colors

#define KMASK_24_BITS       0x00FFFFFFU                                 // Mask
#define KRED                0x00FF0000U                                 // Red
#define KGREEN              0x0000FF00U                                 // Green
#define KBLUE               0x000000FFU                                 // Blue

// Text position (relative to the middle of the display 0, 0)

#define KTEXT_POS_X         0U                                          // X = 0 for all the textes
#define KTEXT_POS_Y_1       20U                                         // Y = 20 for all the text 1
#define KTEXT_POS_Y_2       50U                                         // Y = 50 for all the text 2
#define KTEXT_POS_Y_3       70U                                         // Y = 70 for all the text 2

// Arc diameter & positions

#define KARC_DIAMETER       80U                                         // Arc diameter
#define KARC_MARGIN         20U                                         // Arc margin
#define KARC_POS_X          (KLCD_WIDTH - KARC_DIAMETER - KARC_MARGIN)  // X Arc
#define KARC_POS_Y          KARC_MARGIN                                 // Y Arc

// Square dimension & positions

#define KSQUARES_NB_MAX     20                                          // 20 square
#define KSQUARE_SIZE        30U                                         // Square size
