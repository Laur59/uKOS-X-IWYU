/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Layout and colour constants for the debris demo UI.
 */

#pragma once

// Display size

#define KLCD_BUF_LINES      10u                     // Limited buffer (10 * KLCD_WIDTH * 4) to force partial rendering
#define KLCD_WIDTH          800                     // LCD width
#define KLCD_HEIGHT         480                     // LCD height

// Used colors

#define KMASK_24_BITS       0x00FFFFFFu             // Mask
#define KRED                0x00FF0000u             // Red
#define KGREEN              0x0000FF00u             // Green
#define KBLUE               0x000000FFu             // Blue
#define KWHITE              0x00FFFFFFu             // White
#define KBLACK              0x00000000u             // Black

// Small image

#define SRC_W               80u                     // Size W of the widglet
#define SRC_H               80                      // Size H of the widglet
#define DST_W               120                     // Size W of the zoomed widglet
#define DST_H               120                     // Size H of the zoomed widglet
#define KIMAGE_POS_X        82                      // Text X, small image
#define KIMAGE_POS_Y        249                     // Text Y, small image

// Arc diameter & positions

#define KARC_DIAMETER       87                      // Arc diameter
#define KARC_MARGIN         20                      // Arc margin
#define KARC_POS_X          693                     // X Arc
#define KARC_POS_Y          340                     // Y Arc

// Text positions

#define KTEXT_POS_X_1       482                     // Text X, probability
#define KTEXT_POS_Y_1       275                     // Text Y, probability
#define KTEXT_POS_X_2       482                     // Text X, class
#define KTEXT_POS_Y_2       320                     // Text Y, class
#define KTEXT_POS_X_3       255                     // Text X, execution TensorFlow
#define KTEXT_POS_Y_3       365                     // Text Y, execution TensorFlow
#define KTEXT_POS_X_4       255                     // Text X, execution mlpn
#define KTEXT_POS_Y_4       385                     // Text Y, execution mlpn

// Window positions

#define KWINDOW_POS_X       482                     // Window X, class
#define KWINDOW_POS_Y       325                     // Window Y, class
