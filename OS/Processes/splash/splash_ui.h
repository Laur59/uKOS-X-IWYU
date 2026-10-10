/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Drawing of the boot banner of the splash process.
 */

#pragma once

#include    "splash.h"

// Logo
// The logo of ip.h is an ASCII art made of '_' and '/', each one drawn
// as a line inside a cell. Further than KLOGO_NB_COLUMNS, its rows hold
// the tag line, which is a text

#define KMARGIN                 20U                                         // Left and right margins
#define KLOGO_NB_COLUMNS        68U                                         // Columns of the ASCII art
#define KLOGO_CELL_WIDTH        ((KLCD_WIDTH - (2U * KMARGIN)) / KLOGO_NB_COLUMNS)  // Cell width
#define KLOGO_CELL_HEIGHT       (2U * KLOGO_CELL_WIDTH)                     // Cell height
#define KLOGO_LINE_WIDTH        2U                                          // Line width
#define KLOGO_NB_TAG_LINES      2U                                          // Max. number of tag lines

// Positions

#define KTITLE_POS_Y            12                                          // Y of the title
#define KLOGO_GAP_Y             10                                          // Gap between the title and the logo
#define KTAG_GAP_Y              4                                           // Tag line shift under the logo
#define KINFO_GAP_Y             14                                          // Gap between the logo and the information

#if (defined(__cplusplus))
extern  "C" {
#endif

extern  void    splash_ui_draw(void);

#if (defined(__cplusplus))
}
#endif
