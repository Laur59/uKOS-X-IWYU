/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_otg_fs_global equates.
 */

#pragma once

#include    <stdint.h>

// OTG_FS_GLOBAL address definitions
// ---------------------------------

typedef struct {
    volatile    uint32_t    FS_GOTGCTL;
    volatile    uint32_t    FS_GOTGINT;
    volatile    uint32_t    FS_GAHBCFG;
    volatile    uint32_t    FS_GUSBCFG;
    volatile    uint32_t    FS_GRSTCTL;
    volatile    uint32_t    FS_GINTSTS;
    volatile    uint32_t    FS_GINTMSK;
    volatile    uint32_t    FS_GRXSTSR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    FS_GRXFSIZ;
    volatile    uint32_t    FS_GNPTXFSIZ;
    volatile    uint32_t    FS_GNPTXSTS;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    FS_GCCFG;
    volatile    uint32_t    FS_CID;
    volatile    uint32_t    RESERVED2[48];
    volatile    uint32_t    FS_HPTXFSIZ;
    volatile    uint32_t    FS_DIEPTXF1;
    volatile    uint32_t    FS_DIEPTXF2;
    volatile    uint32_t    FS_DIEPTXF3;
} OTG_FS_GLOBAL_TypeDef;

#ifdef __cplusplus
#define OTG_FS_GLOBAL   reinterpret_cast<OTG_FS_GLOBAL_TypeDef *>(0x50000000U)

#else
#define OTG_FS_GLOBAL   ((OTG_FS_GLOBAL_TypeDef *)0x50000000U)
#endif

// FS_GOTGCTL Configuration

#define OTG_FS_GLOBAL_FS_GOTGCTL_BSVLD              (0x1U<<19U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_ASVLD              (0x1U<<18U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_DBCT               (0x1U<<17U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_CIDSTS             (0x1U<<16U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_DHNPEN             (0x1U<<11U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_HSHNPEN            (0x1U<<10U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_HNPRQ              (0x1U<<9U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_HNGSCS             (0x1U<<8U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_SRQ                (0x1U<<1U)
#define OTG_FS_GLOBAL_FS_GOTGCTL_SRQSCS             (0x1U<<0U)

// FS_GOTGINT Configuration

#define OTG_FS_GLOBAL_FS_GOTGINT_DBCDNE             (0x1U<<19U)
#define OTG_FS_GLOBAL_FS_GOTGINT_ADTOCHG            (0x1U<<18U)
#define OTG_FS_GLOBAL_FS_GOTGINT_HNGDET             (0x1U<<17U)
#define OTG_FS_GLOBAL_FS_GOTGINT_HNSSCHG            (0x1U<<9U)
#define OTG_FS_GLOBAL_FS_GOTGINT_SRSSCHG            (0x1U<<8U)
#define OTG_FS_GLOBAL_FS_GOTGINT_SEDET              (0x1U<<2U)

// FS_GAHBCFG Configuration

#define OTG_FS_GLOBAL_FS_GAHBCFG_PTXFELVL           (0x1U<<8U)
#define OTG_FS_GLOBAL_FS_GAHBCFG_TXFELVL            (0x1U<<7U)
#define OTG_FS_GLOBAL_FS_GAHBCFG_GINT               (0x1U<<0U)

// FS_GUSBCFG Configuration

#define OTG_FS_GLOBAL_FS_GUSBCFG_CTXPKT             (0x1U<<31U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_FDMOD              (0x1U<<30U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_FHMOD              (0x1U<<29U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_TRDT               (0xFU<<10U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_TRDT_0             (0x1U<<10U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_HNPCAP             (0x1U<<9U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_SRPCAP             (0x1U<<8U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_PHYSEL             (0x1U<<6U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_TOCAL              (0x7U<<0U)
#define OTG_FS_GLOBAL_FS_GUSBCFG_TOCAL_0            (0x1U<<0U)

// FS_GRSTCTL Configuration

#define OTG_FS_GLOBAL_FS_GRSTCTL_AHBIDL             (0x1U<<31U)
#define OTG_FS_GLOBAL_FS_GRSTCTL_TXFNUM             (0x1FU<<6U)
#define OTG_FS_GLOBAL_FS_GRSTCTL_TXFNUM_0           (0x1U<<6U)
#define OTG_FS_GLOBAL_FS_GRSTCTL_TXFFLSH            (0x1U<<5U)
#define OTG_FS_GLOBAL_FS_GRSTCTL_RXFFLSH            (0x1U<<4U)
#define OTG_FS_GLOBAL_FS_GRSTCTL_FCRST              (0x1U<<2U)
#define OTG_FS_GLOBAL_FS_GRSTCTL_HSRST              (0x1U<<1U)
#define OTG_FS_GLOBAL_FS_GRSTCTL_CSRST              (0x1U<<0U)

// FS_GINTSTS Configuration

#define OTG_FS_GLOBAL_FS_GINTSTS_WKUPINT            (0x1U<<31U)
#define OTG_FS_GLOBAL_FS_GINTSTS_SRQINT             (0x1U<<30U)
#define OTG_FS_GLOBAL_FS_GINTSTS_DISCINT            (0x1U<<29U)
#define OTG_FS_GLOBAL_FS_GINTSTS_CIDSCHG            (0x1U<<28U)
#define OTG_FS_GLOBAL_FS_GINTSTS_PTXFE              (0x1U<<26U)
#define OTG_FS_GLOBAL_FS_GINTSTS_HCINT              (0x1U<<25U)
#define OTG_FS_GLOBAL_FS_GINTSTS_HPRTINT            (0x1U<<24U)
#define OTG_FS_GLOBAL_FS_GINTSTS_IPXFR_INCOMPISOOUT (0x1U<<21U)
#define OTG_FS_GLOBAL_FS_GINTSTS_IISOIXFR           (0x1U<<20U)
#define OTG_FS_GLOBAL_FS_GINTSTS_OEPINT             (0x1U<<19U)
#define OTG_FS_GLOBAL_FS_GINTSTS_IEPINT             (0x1U<<18U)
#define OTG_FS_GLOBAL_FS_GINTSTS_EOPF               (0x1U<<15U)
#define OTG_FS_GLOBAL_FS_GINTSTS_ISOODRP            (0x1U<<14U)
#define OTG_FS_GLOBAL_FS_GINTSTS_ENUMDNE            (0x1U<<13U)
#define OTG_FS_GLOBAL_FS_GINTSTS_USBRST             (0x1U<<12U)
#define OTG_FS_GLOBAL_FS_GINTSTS_USBSUSP            (0x1U<<11U)
#define OTG_FS_GLOBAL_FS_GINTSTS_ESUSP              (0x1U<<10U)
#define OTG_FS_GLOBAL_FS_GINTSTS_GOUTNAKEFF         (0x1U<<7U)
#define OTG_FS_GLOBAL_FS_GINTSTS_GINAKEFF           (0x1U<<6U)
#define OTG_FS_GLOBAL_FS_GINTSTS_NPTXFE             (0x1U<<5U)
#define OTG_FS_GLOBAL_FS_GINTSTS_RXFLVL             (0x1U<<4U)
#define OTG_FS_GLOBAL_FS_GINTSTS_SOF                (0x1U<<3U)
#define OTG_FS_GLOBAL_FS_GINTSTS_OTGINT             (0x1U<<2U)
#define OTG_FS_GLOBAL_FS_GINTSTS_MMIS               (0x1U<<1U)
#define OTG_FS_GLOBAL_FS_GINTSTS_CMOD               (0x1U<<0U)

// FS_GINTMSK Configuration

#define OTG_FS_GLOBAL_FS_GINTMSK_WUIM               (0x1U<<31U)
#define OTG_FS_GLOBAL_FS_GINTMSK_SRQIM              (0x1U<<30U)
#define OTG_FS_GLOBAL_FS_GINTMSK_DISCINT            (0x1U<<29U)
#define OTG_FS_GLOBAL_FS_GINTMSK_CIDSCHGM           (0x1U<<28U)
#define OTG_FS_GLOBAL_FS_GINTMSK_PTXFEM             (0x1U<<26U)
#define OTG_FS_GLOBAL_FS_GINTMSK_HCIM               (0x1U<<25U)
#define OTG_FS_GLOBAL_FS_GINTMSK_PRTIM              (0x1U<<24U)
#define OTG_FS_GLOBAL_FS_GINTMSK_IPXFRM_IISOOXFRM   (0x1U<<21U)
#define OTG_FS_GLOBAL_FS_GINTMSK_IISOIXFRM          (0x1U<<20U)
#define OTG_FS_GLOBAL_FS_GINTMSK_OEPINT             (0x1U<<19U)
#define OTG_FS_GLOBAL_FS_GINTMSK_IEPINT             (0x1U<<18U)
#define OTG_FS_GLOBAL_FS_GINTMSK_EPMISM             (0x1U<<17U)
#define OTG_FS_GLOBAL_FS_GINTMSK_EOPFM              (0x1U<<15U)
#define OTG_FS_GLOBAL_FS_GINTMSK_ISOODRPM           (0x1U<<14U)
#define OTG_FS_GLOBAL_FS_GINTMSK_ENUMDNEM           (0x1U<<13U)
#define OTG_FS_GLOBAL_FS_GINTMSK_USBRST             (0x1U<<12U)
#define OTG_FS_GLOBAL_FS_GINTMSK_USBSUSPM           (0x1U<<11U)
#define OTG_FS_GLOBAL_FS_GINTMSK_ESUSPM             (0x1U<<10U)
#define OTG_FS_GLOBAL_FS_GINTMSK_GONAKEFFM          (0x1U<<7U)
#define OTG_FS_GLOBAL_FS_GINTMSK_GINAKEFFM          (0x1U<<6U)
#define OTG_FS_GLOBAL_FS_GINTMSK_NPTXFEM            (0x1U<<5U)
#define OTG_FS_GLOBAL_FS_GINTMSK_RXFLVLM            (0x1U<<4U)
#define OTG_FS_GLOBAL_FS_GINTMSK_SOFM               (0x1U<<3U)
#define OTG_FS_GLOBAL_FS_GINTMSK_OTGINT             (0x1U<<2U)
#define OTG_FS_GLOBAL_FS_GINTMSK_MMISM              (0x1U<<1U)

// FS_GRXSTSR Configuration

#define OTG_FS_GLOBAL_FS_GRXSTSR_FRMNUM             (0xFU<<21U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_FRMNUM_0           (0x1U<<21U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_PKTSTS             (0xFU<<17U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_PKTSTS_0           (0x1U<<17U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_DPID               (0x3U<<15U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_DPID_0             (0x1U<<15U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_BCNT               (0x7FFU<<4U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_BCNT_0             (0x1U<<4U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_EPNUM              (0xFU<<0U)
#define OTG_FS_GLOBAL_FS_GRXSTSR_EPNUM_0            (0x1U<<0U)

// FS_GRXFSIZ Configuration

#define OTG_FS_GLOBAL_FS_GRXFSIZ_RXFD               (0xFFFFU<<0U)
#define OTG_FS_GLOBAL_FS_GRXFSIZ_RXFD_0             (0x1U<<0U)

// FS_GNPTXFSIZ Configuration

#define OTG_FS_GLOBAL_FS_GNPTXFSIZ_TX0FD            (0xFFFFU<<16U)
#define OTG_FS_GLOBAL_FS_GNPTXFSIZ_TX0FD_0          (0x1U<<16U)
#define OTG_FS_GLOBAL_FS_GNPTXFSIZ_TX0FSA           (0xFFFFU<<0U)
#define OTG_FS_GLOBAL_FS_GNPTXFSIZ_TX0FSA_0         (0x1U<<0U)

// FS_GNPTXSTS Configuration

#define OTG_FS_GLOBAL_FS_GNPTXSTS_NPTXQTOP          (0x7FU<<24U)
#define OTG_FS_GLOBAL_FS_GNPTXSTS_NPTXQTOP_0        (0x1U<<24U)
#define OTG_FS_GLOBAL_FS_GNPTXSTS_NPTQXSAV          (0xFFU<<16U)
#define OTG_FS_GLOBAL_FS_GNPTXSTS_NPTQXSAV_0        (0x1U<<16U)
#define OTG_FS_GLOBAL_FS_GNPTXSTS_NPTXFSAV          (0xFFFFU<<0U)
#define OTG_FS_GLOBAL_FS_GNPTXSTS_NPTXFSAV_0        (0x1U<<0U)

// FS_GCCFG Configuration

#define OTG_FS_GLOBAL_FS_GCCFG_SOFOUTEN             (0x1U<<20U)
#define OTG_FS_GLOBAL_FS_GCCFG_VBUSBSEN             (0x1U<<19U)
#define OTG_FS_GLOBAL_FS_GCCFG_VBUSASEN             (0x1U<<18U)
#define OTG_FS_GLOBAL_FS_GCCFG_PWRDWN               (0x1U<<16U)

// FS_CID Configuration

#define OTG_FS_GLOBAL_FS_CID_PRODUCT_ID             (0xFFFFFFFFU<<0U)
#define OTG_FS_GLOBAL_FS_CID_PRODUCT_ID_0           (0x1U<<0U)

// FS_HPTXFSIZ Configuration

#define OTG_FS_GLOBAL_FS_HPTXFSIZ_PTXFSIZ           (0xFFFFU<<16U)
#define OTG_FS_GLOBAL_FS_HPTXFSIZ_PTXFSIZ_0         (0x1U<<16U)
#define OTG_FS_GLOBAL_FS_HPTXFSIZ_PTXSA             (0xFFFFU<<0U)
#define OTG_FS_GLOBAL_FS_HPTXFSIZ_PTXSA_0           (0x1U<<0U)

// FS_DIEPTXF1 Configuration

#define OTG_FS_GLOBAL_FS_DIEPTXF1_INEPTXFD          (0xFFFFU<<16U)
#define OTG_FS_GLOBAL_FS_DIEPTXF1_INEPTXFD_0        (0x1U<<16U)
#define OTG_FS_GLOBAL_FS_DIEPTXF1_INEPTXSA          (0xFFFFU<<0U)
#define OTG_FS_GLOBAL_FS_DIEPTXF1_INEPTXSA_0        (0x1U<<0U)

// FS_DIEPTXF2 Configuration

#define OTG_FS_GLOBAL_FS_DIEPTXF2_INEPTXFD          (0xFFFFU<<16U)
#define OTG_FS_GLOBAL_FS_DIEPTXF2_INEPTXFD_0        (0x1U<<16U)
#define OTG_FS_GLOBAL_FS_DIEPTXF2_INEPTXSA          (0xFFFFU<<0U)
#define OTG_FS_GLOBAL_FS_DIEPTXF2_INEPTXSA_0        (0x1U<<0U)

// FS_DIEPTXF3 Configuration

#define OTG_FS_GLOBAL_FS_DIEPTXF3_INEPTXFD          (0xFFFFU<<16U)
#define OTG_FS_GLOBAL_FS_DIEPTXF3_INEPTXFD_0        (0x1U<<16U)
#define OTG_FS_GLOBAL_FS_DIEPTXF3_INEPTXSA          (0xFFFFU<<0U)
#define OTG_FS_GLOBAL_FS_DIEPTXF3_INEPTXSA_0        (0x1U<<0U)
