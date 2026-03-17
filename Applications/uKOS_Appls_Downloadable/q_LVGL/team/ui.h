/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; ui.
; ===

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Demo of a C application.
;           Simple UI for the team demo.

;-----
;------------------------------------------------------------------------
*/

#pragma once

// Display size

#define KLCD_BUF_LINES      10U                                                                 // Limited buffer (10 * KLCD_WIDTH * 2) to force partial rendering
#define KLCD_WIDTH          320U                                                                // LCD width
#define KLCD_HEIGHT         240U                                                                // LCD height

// Bars

#define KBAR_MAX_VALUE      2000U                                                               // Max value
#define KBAR_MIN_VALUE      0U                                                                  // Min value
#define KBAR_POS_Y          15U                                                                 // Y = 15 for all the bars
#define KBAR_POS_X_1        140U                                                                // X = 140 for all the bars 1
#define KBAR_POS_X_2        170U                                                                // X = 170 for all the bars 2
#define KBAR_POS_X_3        200U                                                                // X = 200 for all the bars 3
#define KBAR_GAP_Y          6U                                                                  // Bar gap
#define KBAR_LABEL_WIDTH    80U                                                                 // Bar label max width
#define KBAR_HEIGHT         20U                                                                 // Bar height
#define KBAR_WIDTH          (KLCD_WIDTH - (2 * KBAR_POS_Y) - KBAR_LABEL_WIDTH - KBAR_GAP_Y)     // Bar width
