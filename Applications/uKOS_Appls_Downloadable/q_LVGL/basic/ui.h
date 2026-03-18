/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Demo of a C application.
 *           Simple UI for the basic demo.
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
