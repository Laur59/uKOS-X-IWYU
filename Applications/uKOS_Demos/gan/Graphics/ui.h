/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        Demo of a C application.
 *          Simple UI for the debris demo.
 */

#pragma once

// Display size

#define KLCD_BUF_LINES      80u                     // Limited buffer (80 * KLCD_WIDTH * 2) to force partial rendering
#define KLCD_WIDTH          800                     // LCD width
#define KLCD_HEIGHT         480                     // LCD height

// Used colors

#define KMASK_24_BITS       0x00FFFFFFu             // Mask
#define KRED                0x00FF0000u             // Red
#define KGREEN              0x0000FF00u             // Green
#define KBLUE               0x000000FFu             // Blue
#define KWHITE              0x00FFFFFFu             // White
#define KBLACK              0x00000000u             // Black

// Small face

#define KFACE_SRC_W         64                      // Face width
#define KFACE_SRC_H         64                      // Face height
#define KFACE_DST_W         180                     // Size W of the zoomed widglet
#define KFACE_DST_H         180                     // Size H of the zoomed widglet
#define KFACE_POS_X         510                     // Text X, small image
#define KFACE_POS_Y         150                     // Text Y, small image

// Arc diameter & positions

#define KARC_DIAMETER       87                      // Arc diameter
#define KARC_MARGIN         20                      // Arc margin
#define KARC_POS_X          693                     // X Arc
#define KARC_POS_Y          340                     // Y Arc

// Text positions

#define KTEXT_POS_X_1       130                     // Text X, random
#define KTEXT_POS_Y_1       260                     // Text Y, random
#define KTEXT_POS_X_2       270                     // Text X, execution TensorFlow
#define KTEXT_POS_Y_2       300                     // Text Y, execution TensorFlow
