/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_usbfs_global.
; =======================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_usbfs_global equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// USBFS_GLOBAL address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    GOTGCS;
    volatile    uint32_t    GOTGINTF;
    volatile    uint32_t    GAHBCS;
    volatile    uint32_t    GUSBCS;
    volatile    uint32_t    GRSTCTL;
    volatile    uint32_t    GINTF;
    volatile    uint32_t    GINTEN;
    volatile    uint32_t    GRSTATR;
    volatile    uint32_t    GRSTATP;
    volatile    uint32_t    GRFLEN;
        union {
    volatile    uint32_t    HNPTFLEN;
    volatile    uint32_t    DIEP0TFLEN;
        };
    volatile    uint32_t    HNPTFQSTAT;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    GCCFG;
    volatile    uint32_t    CID;
    volatile    uint32_t    RESERVED1[48];
    volatile    uint32_t    HPTFLEN;
    volatile    uint32_t    DIEP1TFLEN;
    volatile    uint32_t    DIEP2TFLEN;
    volatile    uint32_t    DIEP3TFLEN;
} USBFS_GLOBAL_TypeDef;

#ifdef __cplusplus
#define USBFS_GLOBAL    reinterpret_cast<USBFS_GLOBAL_TypeDef *>(0x50000000U)

#else
#define USBFS_GLOBAL    ((USBFS_GLOBAL_TypeDef *)0x50000000U)
#endif

// GOTGCS Configuration

#define USBFS_GLOBAL_GOTGCS_BSV                 (0x1U<<19)
#define USBFS_GLOBAL_GOTGCS_ASV                 (0x1U<<18)
#define USBFS_GLOBAL_GOTGCS_DI                  (0x1U<<17)
#define USBFS_GLOBAL_GOTGCS_IDPS                (0x1U<<16)
#define USBFS_GLOBAL_GOTGCS_DHNPEN              (0x1U<<11)
#define USBFS_GLOBAL_GOTGCS_HHNPEN              (0x1U<<10)
#define USBFS_GLOBAL_GOTGCS_HNPREQ              (0x1U<<9)
#define USBFS_GLOBAL_GOTGCS_HNPS                (0x1U<<8)
#define USBFS_GLOBAL_GOTGCS_SRPREQ              (0x1U<<1)
#define USBFS_GLOBAL_GOTGCS_SRPS                (0x1U<<0)

// GOTGINTF Configuration

#define USBFS_GLOBAL_GOTGINTF_DF                (0x1U<<19)
#define USBFS_GLOBAL_GOTGINTF_ADTO              (0x1U<<18)
#define USBFS_GLOBAL_GOTGINTF_HNPDET            (0x1U<<17)
#define USBFS_GLOBAL_GOTGINTF_HNPEND            (0x1U<<9)
#define USBFS_GLOBAL_GOTGINTF_SRPEND            (0x1U<<8)
#define USBFS_GLOBAL_GOTGINTF_SESEND            (0x1U<<2)

// GAHBCS Configuration

#define USBFS_GLOBAL_GAHBCS_PTXFTH              (0x1U<<8)
#define USBFS_GLOBAL_GAHBCS_TXFTH               (0x1U<<7)
#define USBFS_GLOBAL_GAHBCS_GINTEN              (0x1U<<0)

// GUSBCS Configuration

#define USBFS_GLOBAL_GUSBCS_FDM                 (0x1U<<30)
#define USBFS_GLOBAL_GUSBCS_FHM                 (0x1U<<29)
#define USBFS_GLOBAL_GUSBCS_UTT                 (0xFU<<10)
#define USBFS_GLOBAL_GUSBCS_UTT_0               (0x1U<<10)
#define USBFS_GLOBAL_GUSBCS_HNPCEN              (0x1U<<9)
#define USBFS_GLOBAL_GUSBCS_SRPCEN              (0x1U<<8)
#define USBFS_GLOBAL_GUSBCS_TOC                 (0x7U<<0)
#define USBFS_GLOBAL_GUSBCS_TOC_0               (0x1U<<0)

// GRSTCTL Configuration

#define USBFS_GLOBAL_GRSTCTL_TXFNUM             (0x1FU<<6)
#define USBFS_GLOBAL_GRSTCTL_TXFNUM_0           (0x1U<<6)
#define USBFS_GLOBAL_GRSTCTL_TXFF               (0x1U<<5)
#define USBFS_GLOBAL_GRSTCTL_RXFF               (0x1U<<4)
#define USBFS_GLOBAL_GRSTCTL_HFCRST             (0x1U<<2)
#define USBFS_GLOBAL_GRSTCTL_HCSRST             (0x1U<<1)
#define USBFS_GLOBAL_GRSTCTL_CSRST              (0x1U<<0)

// GINTF Configuration

#define USBFS_GLOBAL_GINTF_WKUPIF               (0x1U<<31)
#define USBFS_GLOBAL_GINTF_SESIF                (0x1U<<30)
#define USBFS_GLOBAL_GINTF_DISCIF               (0x1U<<29)
#define USBFS_GLOBAL_GINTF_IDPSC                (0x1U<<28)
#define USBFS_GLOBAL_GINTF_PTXFEIF              (0x1U<<26)
#define USBFS_GLOBAL_GINTF_HCIF                 (0x1U<<25)
#define USBFS_GLOBAL_GINTF_HPIF                 (0x1U<<24)
#define USBFS_GLOBAL_GINTF_PXNCIF_ISOONCIF      (0x1U<<21)
#define USBFS_GLOBAL_GINTF_ISOINCIF             (0x1U<<20)
#define USBFS_GLOBAL_GINTF_OEPIF                (0x1U<<19)
#define USBFS_GLOBAL_GINTF_IEPIF                (0x1U<<18)
#define USBFS_GLOBAL_GINTF_EOPFIF               (0x1U<<15)
#define USBFS_GLOBAL_GINTF_ISOOPDIF             (0x1U<<14)
#define USBFS_GLOBAL_GINTF_ENUMF                (0x1U<<13)
#define USBFS_GLOBAL_GINTF_RST                  (0x1U<<12)
#define USBFS_GLOBAL_GINTF_SP                   (0x1U<<11)
#define USBFS_GLOBAL_GINTF_ESP                  (0x1U<<10)
#define USBFS_GLOBAL_GINTF_GONAK                (0x1U<<7)
#define USBFS_GLOBAL_GINTF_GNPINAK              (0x1U<<6)
#define USBFS_GLOBAL_GINTF_NPTXFEIF             (0x1U<<5)
#define USBFS_GLOBAL_GINTF_RXFNEIF              (0x1U<<4)
#define USBFS_GLOBAL_GINTF_SOF                  (0x1U<<3)
#define USBFS_GLOBAL_GINTF_OTGIF                (0x1U<<2)
#define USBFS_GLOBAL_GINTF_MFIF                 (0x1U<<1)
#define USBFS_GLOBAL_GINTF_COPM                 (0x1U<<0)

// GINTEN Configuration

#define USBFS_GLOBAL_GINTEN_WKUPIE              (0x1U<<31)
#define USBFS_GLOBAL_GINTEN_SESIE               (0x1U<<30)
#define USBFS_GLOBAL_GINTEN_DISCIE              (0x1U<<29)
#define USBFS_GLOBAL_GINTEN_IDPSCIE             (0x1U<<28)
#define USBFS_GLOBAL_GINTEN_PTXFEIE             (0x1U<<26)
#define USBFS_GLOBAL_GINTEN_HCIE                (0x1U<<25)
#define USBFS_GLOBAL_GINTEN_HPIE                (0x1U<<24)
#define USBFS_GLOBAL_GINTEN_PXNCIE_ISOONCIE     (0x1U<<21)
#define USBFS_GLOBAL_GINTEN_ISOINCIE            (0x1U<<20)
#define USBFS_GLOBAL_GINTEN_OEPIE               (0x1U<<19)
#define USBFS_GLOBAL_GINTEN_IEPIE               (0x1U<<18)
#define USBFS_GLOBAL_GINTEN_EOPFIE              (0x1U<<15)
#define USBFS_GLOBAL_GINTEN_ISOOPDIE            (0x1U<<14)
#define USBFS_GLOBAL_GINTEN_ENUMFIE             (0x1U<<13)
#define USBFS_GLOBAL_GINTEN_RSTIE               (0x1U<<12)
#define USBFS_GLOBAL_GINTEN_SPIE                (0x1U<<11)
#define USBFS_GLOBAL_GINTEN_ESPIE               (0x1U<<10)
#define USBFS_GLOBAL_GINTEN_GONAKIE             (0x1U<<7)
#define USBFS_GLOBAL_GINTEN_GNPINAKIE           (0x1U<<6)
#define USBFS_GLOBAL_GINTEN_NPTXFEIE            (0x1U<<5)
#define USBFS_GLOBAL_GINTEN_RXFNEIE             (0x1U<<4)
#define USBFS_GLOBAL_GINTEN_SOFIE               (0x1U<<3)
#define USBFS_GLOBAL_GINTEN_OTGIE               (0x1U<<2)
#define USBFS_GLOBAL_GINTEN_MFIE                (0x1U<<1)

// GRSTATR Configuration

#define USBFS_GLOBAL_GRSTATR_RPCKST             (0xFU<<17)
#define USBFS_GLOBAL_GRSTATR_RPCKST_0           (0x1U<<17)
#define USBFS_GLOBAL_GRSTATR_DPID               (0x3U<<15)
#define USBFS_GLOBAL_GRSTATR_DPID_0             (0x1U<<15)
#define USBFS_GLOBAL_GRSTATR_BCOUNT             (0x7FFU<<4)
#define USBFS_GLOBAL_GRSTATR_BCOUNT_0           (0x1U<<4)
#define USBFS_GLOBAL_GRSTATR_EPNUM              (0xFU<<0)
#define USBFS_GLOBAL_GRSTATR_EPNUM_0            (0x1U<<0)

// GRSTATP Configuration

#define USBFS_GLOBAL_GRSTATP_RPCKST             (0xFU<<17)
#define USBFS_GLOBAL_GRSTATP_RPCKST_0           (0x1U<<17)
#define USBFS_GLOBAL_GRSTATP_DPID               (0x3U<<15)
#define USBFS_GLOBAL_GRSTATP_DPID_0             (0x1U<<15)
#define USBFS_GLOBAL_GRSTATP_BCOUNT             (0x7FFU<<4)
#define USBFS_GLOBAL_GRSTATP_BCOUNT_0           (0x1U<<4)
#define USBFS_GLOBAL_GRSTATP_EPNUM              (0xFU<<0)
#define USBFS_GLOBAL_GRSTATP_EPNUM_0            (0x1U<<0)

// GRFLEN Configuration

#define USBFS_GLOBAL_GRFLEN_RXFD                (0xFFFFU<<0)
#define USBFS_GLOBAL_GRFLEN_RXFD_0              (0x1U<<0)

// HNPTFLEN Configuration

#define USBFS_GLOBAL_HNPTFLEN_HNPTXFD           (0xFFFFU<<16)
#define USBFS_GLOBAL_HNPTFLEN_HNPTXFD_0         (0x1U<<16)
#define USBFS_GLOBAL_HNPTFLEN_HNPTXRSAR         (0xFFFFU<<0)
#define USBFS_GLOBAL_HNPTFLEN_HNPTXRSAR_0       (0x1U<<0)

// DIEP0TFLEN Configuration

#define USBFS_GLOBAL_DIEP0TFLEN_IEP0TXRSAR      (0xFFFFU<<0)
#define USBFS_GLOBAL_DIEP0TFLEN_IEP0TXRSAR_0    (0x1U<<0)
#define USBFS_GLOBAL_DIEP0TFLEN_IEP0TXFD        (0xFFFFU<<16)
#define USBFS_GLOBAL_DIEP0TFLEN_IEP0TXFD_0      (0x1U<<16)

// HNPTFQSTAT Configuration

#define USBFS_GLOBAL_HNPTFQSTAT_NPTXRQTOP       (0x7FU<<24)
#define USBFS_GLOBAL_HNPTFQSTAT_NPTXRQTOP_0     (0x1U<<24)
#define USBFS_GLOBAL_HNPTFQSTAT_NPTXRQS         (0xFFU<<16)
#define USBFS_GLOBAL_HNPTFQSTAT_NPTXRQS_0       (0x1U<<16)
#define USBFS_GLOBAL_HNPTFQSTAT_NPTXFS          (0xFFFFU<<0)
#define USBFS_GLOBAL_HNPTFQSTAT_NPTXFS_0        (0x1U<<0)

// GCCFG Configuration

#define USBFS_GLOBAL_GCCFG_VBUSIG               (0x1U<<21)
#define USBFS_GLOBAL_GCCFG_SOFOEN               (0x1U<<20)
#define USBFS_GLOBAL_GCCFG_VBUSBCEN             (0x1U<<19)
#define USBFS_GLOBAL_GCCFG_VBUSACEN             (0x1U<<18)
#define USBFS_GLOBAL_GCCFG_PWRON                (0x1U<<16)

// CID Configuration

#define USBFS_GLOBAL_CID_CID                    (0xFFFFFFFFU<<0)
#define USBFS_GLOBAL_CID_CID_0                  (0x1U<<0)

// HPTFLEN Configuration

#define USBFS_GLOBAL_HPTFLEN_HPTXFD             (0xFFFFU<<16)
#define USBFS_GLOBAL_HPTFLEN_HPTXFD_0           (0x1U<<16)
#define USBFS_GLOBAL_HPTFLEN_HPTXFSAR           (0xFFFFU<<0)
#define USBFS_GLOBAL_HPTFLEN_HPTXFSAR_0         (0x1U<<0)

// DIEP1TFLEN Configuration

#define USBFS_GLOBAL_DIEP1TFLEN_IEPTXFD         (0xFFFFU<<16)
#define USBFS_GLOBAL_DIEP1TFLEN_IEPTXFD_0       (0x1U<<16)
#define USBFS_GLOBAL_DIEP1TFLEN_IEPTXRSAR       (0xFFFFU<<0)
#define USBFS_GLOBAL_DIEP1TFLEN_IEPTXRSAR_0     (0x1U<<0)

// DIEP2TFLEN Configuration

#define USBFS_GLOBAL_DIEP2TFLEN_IEPTXFD         (0xFFFFU<<16)
#define USBFS_GLOBAL_DIEP2TFLEN_IEPTXFD_0       (0x1U<<16)
#define USBFS_GLOBAL_DIEP2TFLEN_IEPTXRSAR       (0xFFFFU<<0)
#define USBFS_GLOBAL_DIEP2TFLEN_IEPTXRSAR_0     (0x1U<<0)

// DIEP3TFLEN Configuration

#define USBFS_GLOBAL_DIEP3TFLEN_IEPTXFD         (0xFFFFU<<16)
#define USBFS_GLOBAL_DIEP3TFLEN_IEPTXFD_0       (0x1U<<16)
#define USBFS_GLOBAL_DIEP3TFLEN_IEPTXRSAR       (0xFFFFU<<0)
#define USBFS_GLOBAL_DIEP3TFLEN_IEPTXRSAR_0     (0x1U<<0)
