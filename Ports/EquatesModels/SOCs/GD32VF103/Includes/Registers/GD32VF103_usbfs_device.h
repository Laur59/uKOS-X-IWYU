/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_usbfs_device equates.
 */

#pragma once

#include    <stdint.h>

// USBFS_DEVICE address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    DCFG;
    volatile    uint32_t    DCTL;
    volatile    uint32_t    DSTAT;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    DIEPINTEN;
    volatile    uint32_t    DOEPINTEN;
    volatile    uint32_t    DAEPINT;
    volatile    uint32_t    DAEPINTEN;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    DVBUSDT;
    volatile    uint32_t    DVBUSPT;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    DIEPFEINTEN;
    volatile    uint32_t    RESERVED3[50];
    volatile    uint32_t    DIEP0CTL;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    DIEP0INTF;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    DIEP0LEN;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    DIEP0TFSTAT;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    DIEP1CTL;
    volatile    uint32_t    RESERVED8;
    volatile    uint32_t    DIEP1INTF;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    DIEP1LEN;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    DIEP1TFSTAT;
    volatile    uint32_t    RESERVED11;
    volatile    uint32_t    DIEP2CTL;
    volatile    uint32_t    RESERVED12;
    volatile    uint32_t    DIEP2INTF;
    volatile    uint32_t    RESERVED13;
    volatile    uint32_t    DIEP2LEN;
    volatile    uint32_t    RESERVED14;
    volatile    uint32_t    DIEP2TFSTAT;
    volatile    uint32_t    RESERVED15;
    volatile    uint32_t    DIEP3CTL;
    volatile    uint32_t    RESERVED16;
    volatile    uint32_t    DIEP3INTF;
    volatile    uint32_t    RESERVED17;
    volatile    uint32_t    DIEP3LEN;
    volatile    uint32_t    RESERVED18;
    volatile    uint32_t    DIEP3TFSTAT;
    volatile    uint32_t    RESERVED19[97];
    volatile    uint32_t    DOEP0CTL;
    volatile    uint32_t    RESERVED20;
    volatile    uint32_t    DOEP0INTF;
    volatile    uint32_t    RESERVED21;
    volatile    uint32_t    DOEP0LEN;
    volatile    uint32_t    RESERVED22[3];
    volatile    uint32_t    DOEP1CTL;
    volatile    uint32_t    RESERVED23;
    volatile    uint32_t    DOEP1INTF;
    volatile    uint32_t    RESERVED24;
    volatile    uint32_t    DOEP1LEN;
    volatile    uint32_t    RESERVED25[3];
    volatile    uint32_t    DOEP2CTL;
    volatile    uint32_t    RESERVED26;
    volatile    uint32_t    DOEP2INTF;
    volatile    uint32_t    RESERVED27;
    volatile    uint32_t    DOEP2LEN;
    volatile    uint32_t    RESERVED28[3];
    volatile    uint32_t    DOEP3CTL;
    volatile    uint32_t    RESERVED29;
    volatile    uint32_t    DOEP3INTF;
    volatile    uint32_t    RESERVED30;
    volatile    uint32_t    DOEP3LEN;
} USBFS_DEVICE_TypeDef;

#ifdef __cplusplus
#define USBFS_DEVICE    reinterpret_cast<USBFS_DEVICE_TypeDef *>(0x50000800U)

#else
#define USBFS_DEVICE    ((USBFS_DEVICE_TypeDef *)0x50000800U)
#endif

// DCFG Configuration

#define USBFS_DEVICE_DCFG_EOPFT                 (0x3U<<11U)
#define USBFS_DEVICE_DCFG_EOPFT_0               (0x1U<<11U)
#define USBFS_DEVICE_DCFG_DAR                   (0x7FU<<4U)
#define USBFS_DEVICE_DCFG_DAR_0                 (0x1U<<4U)
#define USBFS_DEVICE_DCFG_NZLSOH                (0x1U<<2U)
#define USBFS_DEVICE_DCFG_DS                    (0x3U<<0U)
#define USBFS_DEVICE_DCFG_DS_0                  (0x1U<<0U)

// DCTL Configuration

#define USBFS_DEVICE_DCTL_POIF                  (0x1U<<11U)
#define USBFS_DEVICE_DCTL_CGONAK                (0x1U<<10U)
#define USBFS_DEVICE_DCTL_SGONAK                (0x1U<<9U)
#define USBFS_DEVICE_DCTL_CGINAK                (0x1U<<8U)
#define USBFS_DEVICE_DCTL_SGINAK                (0x1U<<7U)
#define USBFS_DEVICE_DCTL_GONS                  (0x1U<<3U)
#define USBFS_DEVICE_DCTL_GINS                  (0x1U<<2U)
#define USBFS_DEVICE_DCTL_SD                    (0x1U<<1U)
#define USBFS_DEVICE_DCTL_RWKUP                 (0x1U<<0U)

// DSTAT Configuration

#define USBFS_DEVICE_DSTAT_FNRSOF               (0x3FFFU<<8U)
#define USBFS_DEVICE_DSTAT_FNRSOF_0             (0x1U<<8U)
#define USBFS_DEVICE_DSTAT_ES                   (0x3U<<1U)
#define USBFS_DEVICE_DSTAT_ES_0                 (0x1U<<1U)
#define USBFS_DEVICE_DSTAT_SPST                 (0x1U<<0U)

// DIEPINTEN Configuration

#define USBFS_DEVICE_DIEPINTEN_IEPNEEN          (0x1U<<6U)
#define USBFS_DEVICE_DIEPINTEN_EPTXFUDEN        (0x1U<<4U)
#define USBFS_DEVICE_DIEPINTEN_CITOEN           (0x1U<<3U)
#define USBFS_DEVICE_DIEPINTEN_EPDISEN          (0x1U<<1U)
#define USBFS_DEVICE_DIEPINTEN_TFEN             (0x1U<<0U)

// DOEPINTEN Configuration

#define USBFS_DEVICE_DOEPINTEN_BTBSTPEN         (0x1U<<6U)
#define USBFS_DEVICE_DOEPINTEN_EPRXFOVREN       (0x1U<<4U)
#define USBFS_DEVICE_DOEPINTEN_STPFEN           (0x1U<<3U)
#define USBFS_DEVICE_DOEPINTEN_EPDISEN          (0x1U<<1U)
#define USBFS_DEVICE_DOEPINTEN_TFEN             (0x1U<<0U)

// DAEPINT Configuration

#define USBFS_DEVICE_DAEPINT_OEPITB             (0xFU<<16U)
#define USBFS_DEVICE_DAEPINT_OEPITB_0           (0x1U<<16U)
#define USBFS_DEVICE_DAEPINT_IEPITB             (0xFU<<0U)
#define USBFS_DEVICE_DAEPINT_IEPITB_0           (0x1U<<0U)

// DAEPINTEN Configuration

#define USBFS_DEVICE_DAEPINTEN_OEPIE            (0xFU<<16U)
#define USBFS_DEVICE_DAEPINTEN_OEPIE_0          (0x1U<<16U)
#define USBFS_DEVICE_DAEPINTEN_IEPIE            (0xFU<<0U)
#define USBFS_DEVICE_DAEPINTEN_IEPIE_0          (0x1U<<0U)

// DVBUSDT Configuration

#define USBFS_DEVICE_DVBUSDT_DVBUSDT            (0xFFFFU<<0U)
#define USBFS_DEVICE_DVBUSDT_DVBUSDT_0          (0x1U<<0U)

// DVBUSPT Configuration

#define USBFS_DEVICE_DVBUSPT_DVBUSPT            (0xFFFU<<0U)
#define USBFS_DEVICE_DVBUSPT_DVBUSPT_0          (0x1U<<0U)

// DIEPFEINTEN Configuration

#define USBFS_DEVICE_DIEPFEINTEN_IEPTXFEIE      (0xFU<<0U)
#define USBFS_DEVICE_DIEPFEINTEN_IEPTXFEIE_0    (0x1U<<0U)

// DIEP0CTL Configuration

#define USBFS_DEVICE_DIEP0CTL_EPEN              (0x1U<<31U)
#define USBFS_DEVICE_DIEP0CTL_EPD               (0x1U<<30U)
#define USBFS_DEVICE_DIEP0CTL_SNAK              (0x1U<<27U)
#define USBFS_DEVICE_DIEP0CTL_CNAK              (0x1U<<26U)
#define USBFS_DEVICE_DIEP0CTL_TXFNUM            (0xFU<<22U)
#define USBFS_DEVICE_DIEP0CTL_TXFNUM_0          (0x1U<<22U)
#define USBFS_DEVICE_DIEP0CTL_STALL             (0x1U<<21U)
#define USBFS_DEVICE_DIEP0CTL_EPTYPE            (0x3U<<18U)
#define USBFS_DEVICE_DIEP0CTL_EPTYPE_0          (0x1U<<18U)
#define USBFS_DEVICE_DIEP0CTL_NAKS              (0x1U<<17U)
#define USBFS_DEVICE_DIEP0CTL_EPACT             (0x1U<<15U)
#define USBFS_DEVICE_DIEP0CTL_MPL               (0x3U<<0U)
#define USBFS_DEVICE_DIEP0CTL_MPL_0             (0x1U<<0U)

// DIEP0INTF Configuration

#define USBFS_DEVICE_DIEP0INTF_TF               (0x1U<<0U)
#define USBFS_DEVICE_DIEP0INTF_EPDIS            (0x1U<<1U)
#define USBFS_DEVICE_DIEP0INTF_CITO             (0x1U<<3U)
#define USBFS_DEVICE_DIEP0INTF_EPTXFUD          (0x1U<<4U)
#define USBFS_DEVICE_DIEP0INTF_IEPNE            (0x1U<<6U)
#define USBFS_DEVICE_DIEP0INTF_TXFE             (0x1U<<7U)

// DIEP0LEN Configuration

#define USBFS_DEVICE_DIEP0LEN_TLEN              (0x7FU<<0U)
#define USBFS_DEVICE_DIEP0LEN_TLEN_0            (0x1U<<0U)
#define USBFS_DEVICE_DIEP0LEN_PCNT              (0x3U<<19U)
#define USBFS_DEVICE_DIEP0LEN_PCNT_0            (0x1U<<19U)

// DIEP0TFSTAT Configuration

#define USBFS_DEVICE_DIEP0TFSTAT_IEPTFS         (0xFFFFU<<0U)
#define USBFS_DEVICE_DIEP0TFSTAT_IEPTFS_0       (0x1U<<0U)

// DIEP1CTL Configuration

#define USBFS_DEVICE_DIEP1CTL_MPL               (0x7FFU<<0U)
#define USBFS_DEVICE_DIEP1CTL_MPL_0             (0x1U<<0U)
#define USBFS_DEVICE_DIEP1CTL_EPACT             (0x1U<<15U)
#define USBFS_DEVICE_DIEP1CTL_EOFRM_DPID        (0x1U<<16U)
#define USBFS_DEVICE_DIEP1CTL_NAKS              (0x1U<<17U)
#define USBFS_DEVICE_DIEP1CTL_EPTYPE            (0x3U<<18U)
#define USBFS_DEVICE_DIEP1CTL_EPTYPE_0          (0x1U<<18U)
#define USBFS_DEVICE_DIEP1CTL_STALL             (0x1U<<21U)
#define USBFS_DEVICE_DIEP1CTL_TXFNUM            (0xFU<<22U)
#define USBFS_DEVICE_DIEP1CTL_TXFNUM_0          (0x1U<<22U)
#define USBFS_DEVICE_DIEP1CTL_CNAK              (0x1U<<26U)
#define USBFS_DEVICE_DIEP1CTL_SNAK              (0x1U<<27U)
#define USBFS_DEVICE_DIEP1CTL_SD0PID_SEVENFRM   (0x1U<<28U)
#define USBFS_DEVICE_DIEP1CTL_SD1PID_SODDFRM    (0x1U<<29U)
#define USBFS_DEVICE_DIEP1CTL_EPD               (0x1U<<30U)
#define USBFS_DEVICE_DIEP1CTL_EPEN              (0x1U<<31U)

// DIEP1INTF Configuration

#define USBFS_DEVICE_DIEP1INTF_TF               (0x1U<<0U)
#define USBFS_DEVICE_DIEP1INTF_EPDIS            (0x1U<<1U)
#define USBFS_DEVICE_DIEP1INTF_CITO             (0x1U<<3U)
#define USBFS_DEVICE_DIEP1INTF_EPTXFUD          (0x1U<<4U)
#define USBFS_DEVICE_DIEP1INTF_IEPNE            (0x1U<<6U)
#define USBFS_DEVICE_DIEP1INTF_TXFE             (0x1U<<7U)

// DIEP1LEN Configuration

#define USBFS_DEVICE_DIEP1LEN_TLEN              (0x7FFFFU<<0U)
#define USBFS_DEVICE_DIEP1LEN_TLEN_0            (0x1U<<0U)
#define USBFS_DEVICE_DIEP1LEN_PCNT              (0x3FFU<<19U)
#define USBFS_DEVICE_DIEP1LEN_PCNT_0            (0x1U<<19U)
#define USBFS_DEVICE_DIEP1LEN_MCPF              (0x3U<<29U)
#define USBFS_DEVICE_DIEP1LEN_MCPF_0            (0x1U<<29U)

// DIEP1TFSTAT Configuration

#define USBFS_DEVICE_DIEP1TFSTAT_IEPTFS         (0xFFFFU<<0U)
#define USBFS_DEVICE_DIEP1TFSTAT_IEPTFS_0       (0x1U<<0U)

// DIEP2CTL Configuration

#define USBFS_DEVICE_DIEP2CTL_MPL               (0x7FFU<<0U)
#define USBFS_DEVICE_DIEP2CTL_MPL_0             (0x1U<<0U)
#define USBFS_DEVICE_DIEP2CTL_EPACT             (0x1U<<15U)
#define USBFS_DEVICE_DIEP2CTL_EOFRM_DPID        (0x1U<<16U)
#define USBFS_DEVICE_DIEP2CTL_NAKS              (0x1U<<17U)
#define USBFS_DEVICE_DIEP2CTL_EPTYPE            (0x3U<<18U)
#define USBFS_DEVICE_DIEP2CTL_EPTYPE_0          (0x1U<<18U)
#define USBFS_DEVICE_DIEP2CTL_STALL             (0x1U<<21U)
#define USBFS_DEVICE_DIEP2CTL_TXFNUM            (0xFU<<22U)
#define USBFS_DEVICE_DIEP2CTL_TXFNUM_0          (0x1U<<22U)
#define USBFS_DEVICE_DIEP2CTL_CNAK              (0x1U<<26U)
#define USBFS_DEVICE_DIEP2CTL_SNAK              (0x1U<<27U)
#define USBFS_DEVICE_DIEP2CTL_SD0PID_SEVENFRM   (0x1U<<28U)
#define USBFS_DEVICE_DIEP2CTL_SD1PID_SODDFRM    (0x1U<<29U)
#define USBFS_DEVICE_DIEP2CTL_EPD               (0x1U<<30U)
#define USBFS_DEVICE_DIEP2CTL_EPEN              (0x1U<<31U)

// DIEP2INTF Configuration

#define USBFS_DEVICE_DIEP2INTF_TF               (0x1U<<0U)
#define USBFS_DEVICE_DIEP2INTF_EPDIS            (0x1U<<1U)
#define USBFS_DEVICE_DIEP2INTF_CITO             (0x1U<<3U)
#define USBFS_DEVICE_DIEP2INTF_EPTXFUD          (0x1U<<4U)
#define USBFS_DEVICE_DIEP2INTF_IEPNE            (0x1U<<6U)
#define USBFS_DEVICE_DIEP2INTF_TXFE             (0x1U<<7U)

// DIEP2LEN Configuration

#define USBFS_DEVICE_DIEP2LEN_TLEN              (0x7FFFFU<<0U)
#define USBFS_DEVICE_DIEP2LEN_TLEN_0            (0x1U<<0U)
#define USBFS_DEVICE_DIEP2LEN_PCNT              (0x3FFU<<19U)
#define USBFS_DEVICE_DIEP2LEN_PCNT_0            (0x1U<<19U)
#define USBFS_DEVICE_DIEP2LEN_MCPF              (0x3U<<29U)
#define USBFS_DEVICE_DIEP2LEN_MCPF_0            (0x1U<<29U)

// DIEP2TFSTAT Configuration

#define USBFS_DEVICE_DIEP2TFSTAT_IEPTFS         (0xFFFFU<<0U)
#define USBFS_DEVICE_DIEP2TFSTAT_IEPTFS_0       (0x1U<<0U)

// DIEP3CTL Configuration

#define USBFS_DEVICE_DIEP3CTL_MPL               (0x7FFU<<0U)
#define USBFS_DEVICE_DIEP3CTL_MPL_0             (0x1U<<0U)
#define USBFS_DEVICE_DIEP3CTL_EPACT             (0x1U<<15U)
#define USBFS_DEVICE_DIEP3CTL_EOFRM_DPID        (0x1U<<16U)
#define USBFS_DEVICE_DIEP3CTL_NAKS              (0x1U<<17U)
#define USBFS_DEVICE_DIEP3CTL_EPTYPE            (0x3U<<18U)
#define USBFS_DEVICE_DIEP3CTL_EPTYPE_0          (0x1U<<18U)
#define USBFS_DEVICE_DIEP3CTL_STALL             (0x1U<<21U)
#define USBFS_DEVICE_DIEP3CTL_TXFNUM            (0xFU<<22U)
#define USBFS_DEVICE_DIEP3CTL_TXFNUM_0          (0x1U<<22U)
#define USBFS_DEVICE_DIEP3CTL_CNAK              (0x1U<<26U)
#define USBFS_DEVICE_DIEP3CTL_SNAK              (0x1U<<27U)
#define USBFS_DEVICE_DIEP3CTL_SD0PID_SEVENFRM   (0x1U<<28U)
#define USBFS_DEVICE_DIEP3CTL_SD1PID_SODDFRM    (0x1U<<29U)
#define USBFS_DEVICE_DIEP3CTL_EPD               (0x1U<<30U)
#define USBFS_DEVICE_DIEP3CTL_EPEN              (0x1U<<31U)

// DIEP3INTF Configuration

#define USBFS_DEVICE_DIEP3INTF_TF               (0x1U<<0U)
#define USBFS_DEVICE_DIEP3INTF_EPDIS            (0x1U<<1U)
#define USBFS_DEVICE_DIEP3INTF_CITO             (0x1U<<3U)
#define USBFS_DEVICE_DIEP3INTF_EPTXFUD          (0x1U<<4U)
#define USBFS_DEVICE_DIEP3INTF_IEPNE            (0x1U<<6U)
#define USBFS_DEVICE_DIEP3INTF_TXFE             (0x1U<<7U)

// DIEP3LEN Configuration

#define USBFS_DEVICE_DIEP3LEN_TLEN              (0x7FFFFU<<0U)
#define USBFS_DEVICE_DIEP3LEN_TLEN_0            (0x1U<<0U)
#define USBFS_DEVICE_DIEP3LEN_PCNT              (0x3FFU<<19U)
#define USBFS_DEVICE_DIEP3LEN_PCNT_0            (0x1U<<19U)
#define USBFS_DEVICE_DIEP3LEN_MCPF              (0x3U<<29U)
#define USBFS_DEVICE_DIEP3LEN_MCPF_0            (0x1U<<29U)

// DIEP3TFSTAT Configuration

#define USBFS_DEVICE_DIEP3TFSTAT_IEPTFS         (0xFFFFU<<0U)
#define USBFS_DEVICE_DIEP3TFSTAT_IEPTFS_0       (0x1U<<0U)

// DOEP0CTL Configuration

#define USBFS_DEVICE_DOEP0CTL_MPL               (0x3U<<0U)
#define USBFS_DEVICE_DOEP0CTL_MPL_0             (0x1U<<0U)
#define USBFS_DEVICE_DOEP0CTL_EPACT             (0x1U<<15U)
#define USBFS_DEVICE_DOEP0CTL_NAKS              (0x1U<<17U)
#define USBFS_DEVICE_DOEP0CTL_EPTYPE            (0x3U<<18U)
#define USBFS_DEVICE_DOEP0CTL_EPTYPE_0          (0x1U<<18U)
#define USBFS_DEVICE_DOEP0CTL_SNOOP             (0x1U<<20U)
#define USBFS_DEVICE_DOEP0CTL_STALL             (0x1U<<21U)
#define USBFS_DEVICE_DOEP0CTL_CNAK              (0x1U<<26U)
#define USBFS_DEVICE_DOEP0CTL_SNAK              (0x1U<<27U)
#define USBFS_DEVICE_DOEP0CTL_EPD               (0x1U<<30U)
#define USBFS_DEVICE_DOEP0CTL_EPEN              (0x1U<<31U)

// DOEP0INTF Configuration

#define USBFS_DEVICE_DOEP0INTF_TF               (0x1U<<0U)
#define USBFS_DEVICE_DOEP0INTF_EPDIS            (0x1U<<1U)
#define USBFS_DEVICE_DOEP0INTF_STPF             (0x1U<<3U)
#define USBFS_DEVICE_DOEP0INTF_EPRXFOVR         (0x1U<<4U)
#define USBFS_DEVICE_DOEP0INTF_BTBSTP           (0x1U<<6U)

// DOEP0LEN Configuration

#define USBFS_DEVICE_DOEP0LEN_TLEN              (0x7FU<<0U)
#define USBFS_DEVICE_DOEP0LEN_TLEN_0            (0x1U<<0U)
#define USBFS_DEVICE_DOEP0LEN_PCNT              (0x1U<<19U)
#define USBFS_DEVICE_DOEP0LEN_STPCNT            (0x3U<<29U)
#define USBFS_DEVICE_DOEP0LEN_STPCNT_0          (0x1U<<29U)

// DOEP1CTL Configuration

#define USBFS_DEVICE_DOEP1CTL_MPL               (0x7FFU<<0U)
#define USBFS_DEVICE_DOEP1CTL_MPL_0             (0x1U<<0U)
#define USBFS_DEVICE_DOEP1CTL_EPACT             (0x1U<<15U)
#define USBFS_DEVICE_DOEP1CTL_EOFRM_DPID        (0x1U<<16U)
#define USBFS_DEVICE_DOEP1CTL_NAKS              (0x1U<<17U)
#define USBFS_DEVICE_DOEP1CTL_EPTYPE            (0x3U<<18U)
#define USBFS_DEVICE_DOEP1CTL_EPTYPE_0          (0x1U<<18U)
#define USBFS_DEVICE_DOEP1CTL_SNOOP             (0x1U<<20U)
#define USBFS_DEVICE_DOEP1CTL_STALL             (0x1U<<21U)
#define USBFS_DEVICE_DOEP1CTL_CNAK              (0x1U<<26U)
#define USBFS_DEVICE_DOEP1CTL_SNAK              (0x1U<<27U)
#define USBFS_DEVICE_DOEP1CTL_SD0PID_SEVENFRM   (0x1U<<28U)
#define USBFS_DEVICE_DOEP1CTL_SD1PID_SODDFRM    (0x1U<<29U)
#define USBFS_DEVICE_DOEP1CTL_EPD               (0x1U<<30U)
#define USBFS_DEVICE_DOEP1CTL_EPEN              (0x1U<<31U)

// DOEP1INTF Configuration

#define USBFS_DEVICE_DOEP1INTF_TF               (0x1U<<0U)
#define USBFS_DEVICE_DOEP1INTF_EPDIS            (0x1U<<1U)
#define USBFS_DEVICE_DOEP1INTF_STPF             (0x1U<<3U)
#define USBFS_DEVICE_DOEP1INTF_EPRXFOVR         (0x1U<<4U)
#define USBFS_DEVICE_DOEP1INTF_BTBSTP           (0x1U<<6U)

// DOEP1LEN Configuration

#define USBFS_DEVICE_DOEP1LEN_TLEN              (0x7FFFFU<<0U)
#define USBFS_DEVICE_DOEP1LEN_TLEN_0            (0x1U<<0U)
#define USBFS_DEVICE_DOEP1LEN_PCNT              (0x3FFU<<19U)
#define USBFS_DEVICE_DOEP1LEN_PCNT_0            (0x1U<<19U)
#define USBFS_DEVICE_DOEP1LEN_STPCNT_RXDPID     (0x3U<<29U)
#define USBFS_DEVICE_DOEP1LEN_STPCNT_RXDPID_0   (0x1U<<29U)

// DOEP2CTL Configuration

#define USBFS_DEVICE_DOEP2CTL_MPL               (0x7FFU<<0U)
#define USBFS_DEVICE_DOEP2CTL_MPL_0             (0x1U<<0U)
#define USBFS_DEVICE_DOEP2CTL_EPACT             (0x1U<<15U)
#define USBFS_DEVICE_DOEP2CTL_EOFRM_DPID        (0x1U<<16U)
#define USBFS_DEVICE_DOEP2CTL_NAKS              (0x1U<<17U)
#define USBFS_DEVICE_DOEP2CTL_EPTYPE            (0x3U<<18U)
#define USBFS_DEVICE_DOEP2CTL_EPTYPE_0          (0x1U<<18U)
#define USBFS_DEVICE_DOEP2CTL_SNOOP             (0x1U<<20U)
#define USBFS_DEVICE_DOEP2CTL_STALL             (0x1U<<21U)
#define USBFS_DEVICE_DOEP2CTL_CNAK              (0x1U<<26U)
#define USBFS_DEVICE_DOEP2CTL_SNAK              (0x1U<<27U)
#define USBFS_DEVICE_DOEP2CTL_SD0PID_SEVENFRM   (0x1U<<28U)
#define USBFS_DEVICE_DOEP2CTL_SD1PID_SODDFRM    (0x1U<<29U)
#define USBFS_DEVICE_DOEP2CTL_EPD               (0x1U<<30U)
#define USBFS_DEVICE_DOEP2CTL_EPEN              (0x1U<<31U)

// DOEP2INTF Configuration

#define USBFS_DEVICE_DOEP2INTF_TF               (0x1U<<0U)
#define USBFS_DEVICE_DOEP2INTF_EPDIS            (0x1U<<1U)
#define USBFS_DEVICE_DOEP2INTF_STPF             (0x1U<<3U)
#define USBFS_DEVICE_DOEP2INTF_EPRXFOVR         (0x1U<<4U)
#define USBFS_DEVICE_DOEP2INTF_BTBSTP           (0x1U<<6U)

// DOEP2LEN Configuration

#define USBFS_DEVICE_DOEP2LEN_TLEN              (0x7FFFFU<<0U)
#define USBFS_DEVICE_DOEP2LEN_TLEN_0            (0x1U<<0U)
#define USBFS_DEVICE_DOEP2LEN_PCNT              (0x3FFU<<19U)
#define USBFS_DEVICE_DOEP2LEN_PCNT_0            (0x1U<<19U)
#define USBFS_DEVICE_DOEP2LEN_STPCNT_RXDPID     (0x3U<<29U)
#define USBFS_DEVICE_DOEP2LEN_STPCNT_RXDPID_0   (0x1U<<29U)

// DOEP3CTL Configuration

#define USBFS_DEVICE_DOEP3CTL_MPL               (0x7FFU<<0U)
#define USBFS_DEVICE_DOEP3CTL_MPL_0             (0x1U<<0U)
#define USBFS_DEVICE_DOEP3CTL_EPACT             (0x1U<<15U)
#define USBFS_DEVICE_DOEP3CTL_EOFRM_DPID        (0x1U<<16U)
#define USBFS_DEVICE_DOEP3CTL_NAKS              (0x1U<<17U)
#define USBFS_DEVICE_DOEP3CTL_EPTYPE            (0x3U<<18U)
#define USBFS_DEVICE_DOEP3CTL_EPTYPE_0          (0x1U<<18U)
#define USBFS_DEVICE_DOEP3CTL_SNOOP             (0x1U<<20U)
#define USBFS_DEVICE_DOEP3CTL_STALL             (0x1U<<21U)
#define USBFS_DEVICE_DOEP3CTL_CNAK              (0x1U<<26U)
#define USBFS_DEVICE_DOEP3CTL_SNAK              (0x1U<<27U)
#define USBFS_DEVICE_DOEP3CTL_SD0PID_SEVENFRM   (0x1U<<28U)
#define USBFS_DEVICE_DOEP3CTL_SD1PID_SODDFRM    (0x1U<<29U)
#define USBFS_DEVICE_DOEP3CTL_EPD               (0x1U<<30U)
#define USBFS_DEVICE_DOEP3CTL_EPEN              (0x1U<<31U)

// DOEP3INTF Configuration

#define USBFS_DEVICE_DOEP3INTF_TF               (0x1U<<0U)
#define USBFS_DEVICE_DOEP3INTF_EPDIS            (0x1U<<1U)
#define USBFS_DEVICE_DOEP3INTF_STPF             (0x1U<<3U)
#define USBFS_DEVICE_DOEP3INTF_EPRXFOVR         (0x1U<<4U)
#define USBFS_DEVICE_DOEP3INTF_BTBSTP           (0x1U<<6U)

// DOEP3LEN Configuration

#define USBFS_DEVICE_DOEP3LEN_TLEN              (0x7FFFFU<<0U)
#define USBFS_DEVICE_DOEP3LEN_TLEN_0            (0x1U<<0U)
#define USBFS_DEVICE_DOEP3LEN_PCNT              (0x3FFU<<19U)
#define USBFS_DEVICE_DOEP3LEN_PCNT_0            (0x1U<<19U)
#define USBFS_DEVICE_DOEP3LEN_STPCNT_RXDPID     (0x3U<<29U)
#define USBFS_DEVICE_DOEP3LEN_STPCNT_RXDPID_0   (0x1U<<29U)
