/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Equates for the lcd display
 */

#pragma once

// LCD controller commands

#define KNO_OPERATION               0x00U           //
#define KSOFTWARE_RESET             0x01U           //
#define KREAD_ID                    0x04U           //
#define KREAD_STATUS                0x09U           //
#define KREAD_POWER_MODE            0x0AU           //
#define KREAD_MADCTL                0x0BU           //
#define KREAD_PIXEL_FORMAT          0x0CU           //
#define KREAD_IMAGE_FORMAT          0x0DU           //
#define KREAD_SIGNAL_MODE           0x0EU           //
#define KREAD_SELT_DIAG_RESULT      0x0FU           //
#define KSLEEP_ON                   0x10U           //
#define KSLEEP_OFF                  0x11U           //
#define KPARTIAL_DISPALY_ON         0x12U           //
#define KNORMAL_DISPALY_ON          0x13U           //
#define KINVERSION_DISPALY_OFF      0x20U           //
#define KINVERSION_DISPALY_ON       0x21U           //
#define KGAMMA_SET                  0x26U           //
#define KDISPALY_OFF                0x28U           //
#define KDISPALY_ON                 0x29U           //
#define KHORIZONTAL_ADDRESS_SET     0x2AU           //
#define KVERTICAL_ADDRESS_SET       0x2BU           //
#define KMEMORY_WRITE               0x2CU           //
#define KCOLOR_SET                  0x2DU           //
#define KMEMORY_READ                0x2EU           //
#define KPARTIAL_AREA               0x30U           //
#define KVERTICAL_SCROL_DEFINE      0x33U           //
#define KTEAR_EFFECT_LINE_OFF       0x34U           //
#define KTEAR_EFFECT_LINE_ON        0x35U           //
#define KMEMORY_ACCESS_CTL          0x36U           //
#define KVERTICAL_SCROL_S_ADD       0x37U           //
#define KIDLE_MODE_OFF              0x38U           //
#define KIDLE_MODE_ON               0x39U           //
#define KPIXEL_FORMAT_SET           0x3AU           //
#define KWRITE_MEMORY_CONTINUE      0x3CU           //
#define KREAD_MEMORY_CONTINUE       0x3EU           //
#define KSET_TEAR_SCANLINE          0x44U           //
#define KGET_SCANLINE               0x45U           //
#define KWRITE_BRIGHTNESS           0x51U           //
#define KREAD_BRIGHTNESS            0x52U           //
#define KWRITE_CTRL_DISPALY         0x53U           //
#define KREAD_CTRL_DISPALY          0x54U           //
#define KWRITE_BRIGHTNESS_CTL       0x55U           //
#define KREAD_BRIGHTNESS_CTL        0x56U           //
#define KWRITE_MIN_BRIGHTNESS       0x5EU           //
#define KREAD_MIN_BRIGHTNESS        0x5FU           //
#define KREAD_ID1                   0xDAU           //
#define KREAD_ID2                   0xDBU           //
#define KREAD_ID3                   0xDCU           //
#define KRGB_IF_SIGNAL_CTL          0xB0U           //
#define KNORMAL_FRAME_CTL           0xB1U           //
#define KIDLE_FRAME_CTL             0xB2U           //
#define KPARTIAL_FRAME_CTL          0xB3U           //
#define KINVERSION_CTL              0xB4U           //
#define KBLANK_PORCH_CTL            0xB5U           //
#define KDISPALY_FUNCTION_CTL       0xB6U           //
#define KENTRY_MODE_SET             0xB7U           //
#define KBACKLIGHT_CTL1             0xB8U           //
#define KBACKLIGHT_CTL2             0xB9U           //
#define KBACKLIGHT_CTL3             0xBAU           //
#define KBACKLIGHT_CTL4             0xBBU           //
#define KBACKLIGHT_CTL5             0xBCU           //
#define KBACKLIGHT_CTL7             0xBEU           //
#define KBACKLIGHT_CTL8             0xBFU           //
#define KPOWER_CTL1                 0xC0U           //
#define KPOWER_CTL2                 0xC1U           //
#define KVCOM_CTL1                  0xC5U           //
#define KVCOM_CTL2                  0xC7U           //
#define KNV_MEMORY_WRITE            0xD0U           //
#define KNV_MEMORY_PROTECT_KEY      0xD1U           //
#define KNV_MEMORY_STATUS_READ      0xD2U           //
#define KREAD_ID4                   0xD3U           //
#define KPOSITIVE_GAMMA_CORRECT     0xE0U           //
#define KNEGATIVE_GAMMA_CORRECT     0xE1U           //
#define KDIGITAL_GAMMA_CTL1         0xE2U           //
#define KDIGITAL_GAMMA_CTL2         0xE3U           //
#define KINTERFACE_CTL              0xF6U           //

// LCD directions

#define KDIR_XY_RLUD                0x00U           //
#define KDIR_YX_RLUD                0x20U           //
#define KDIR_XY_LRUD                0x40U           //
#define KDIR_YX_LRUD                0x60U           //
#define KDIR_XY_RLDU                0x80U           //
#define KDIR_YX_RLDU                0xA0U           //
#define KDIR_XY_LRDU                0xC0U           //
#define KDIR_YX_LRDU                0xE0U           //
#define KDIR_XY_MASK                0x20U           //
#define KDIR_MASK                   0xE0U           //
