/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Demo of a C application.
 *           Simple UI for the big demo.
 */

#pragma once

// Display size

#define KLCD_BUF_LINES      10u                                         // Limited buffer (10 * KLCD_WIDTH * 2) to force partial rendering
#define KLCD_WIDTH          800u                                        // LCD width
#define KLCD_HEIGHT         480u                                        // LCD height

// Used colors

#define KMASK_24_BITS       0x00FFFFFFu                                 // Mask
#define KRED                0x00FF0000u                                 // Red
#define KGREEN              0x0000FF00u                                 // Green
#define KBLUE               0x000000FFu                                 // Blue

// Text position (relative to the middle of the display 0, 0)

#define KTEXT_POS_X         0u                                          // X = 0 for all the textes
#define KTEXT_POS_Y_1       20u                                         // Y = 20 for all the text 1
#define KTEXT_POS_Y_2       50u                                         // Y = 50 for all the text 2
#define KTEXT_POS_Y_3       70u                                         // Y = 70 for all the text 2

// Arc diameter & positions

#define KARC_DIAMETER       200u                                        // Arc diameter
#define KARC_MARGIN         20u                                         // Arc margin
#define KARC_POS_X          (KLCD_WIDTH - KARC_DIAMETER - KARC_MARGIN)  // X Arc
#define KARC_POS_Y          KARC_MARGIN                                 // Y Arc

// Square dimension & positions

#define KSQUARES_NB_MAX     50u                                         // 50 square
#define KSQUARE_SIZE        40u                                         // Square size
