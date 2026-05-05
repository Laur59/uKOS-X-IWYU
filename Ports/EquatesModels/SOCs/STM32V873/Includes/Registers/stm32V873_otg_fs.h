/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_otg_fs equates.
 */
#pragma once

#include    <stdint.h>

// OTG_FS address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    OTG_GOTGCTL;
    volatile    uint32_t    OTG_GOTGINT;
    volatile    uint32_t    OTG_GAHBCFG;
    volatile    uint32_t    OTG_GUSBCFG;
    volatile    uint32_t    OTG_GRSTCTL;
    volatile    uint32_t    OTG_GINTSTS;
    volatile    uint32_t    OTG_GINTMSK;
    volatile    uint32_t    OTG_GRXSTSR;
    volatile    uint32_t    OTG_GRXSTSP;
    volatile    uint32_t    OTG_GRXFSIZ;
        union {
    volatile    uint32_t    OTG_HNPTXFSIZ;
    volatile    uint32_t    OTG_DIEPTXF0;
        };
    volatile    uint32_t    OTG_HNPTXSTS;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    OTG_GCCFG;
    volatile    uint32_t    OTG_CID;
    volatile    uint32_t    RESERVED1[5];
    volatile    uint32_t    OTG_GLPMCFG;
    volatile    uint32_t    RESERVED2[42];
    volatile    uint32_t    OTG_HPTXFSIZ;
    volatile    uint32_t    OTG_DIEPTXF1;
    volatile    uint32_t    OTG_DIEPTXF2;
    volatile    uint32_t    OTG_DIEPTXF3;
    volatile    uint32_t    OTG_DIEPTXF4;
    volatile    uint32_t    OTG_DIEPTXF5;
    volatile    uint32_t    RESERVED3[186];
    volatile    uint32_t    OTG_HCFG;
    volatile    uint32_t    OTG_HFIR;
    volatile    uint32_t    OTG_HFNUM;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    OTG_HPTXSTS;
    volatile    uint32_t    OTG_HAINT;
    volatile    uint32_t    OTG_HAINTMSK;
    volatile    uint32_t    RESERVED5[9];
    volatile    uint32_t    OTG_HPRT;
    volatile    uint32_t    RESERVED6[47];
    volatile    uint32_t    OTG_HCCHAR0;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    OTG_HCINT0;
    volatile    uint32_t    OTG_HCINTMSK0;
    volatile    uint32_t    OTG_HCTSIZ0;
    volatile    uint32_t    RESERVED8[3];
    volatile    uint32_t    OTG_HCCHAR1;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    OTG_HCINT1;
    volatile    uint32_t    OTG_HCINTMSK1;
    volatile    uint32_t    OTG_HCTSIZ1;
    volatile    uint32_t    RESERVED10[3];
    volatile    uint32_t    OTG_HCCHAR2;
    volatile    uint32_t    RESERVED11;
    volatile    uint32_t    OTG_HCINT2;
    volatile    uint32_t    OTG_HCINTMSK2;
    volatile    uint32_t    OTG_HCTSIZ2;
    volatile    uint32_t    RESERVED12[3];
    volatile    uint32_t    OTG_HCCHAR3;
    volatile    uint32_t    RESERVED13;
    volatile    uint32_t    OTG_HCINT3;
    volatile    uint32_t    OTG_HCINTMSK3;
    volatile    uint32_t    OTG_HCTSIZ3;
    volatile    uint32_t    RESERVED14[3];
    volatile    uint32_t    OTG_HCCHAR4;
    volatile    uint32_t    RESERVED15;
    volatile    uint32_t    OTG_HCINT4;
    volatile    uint32_t    OTG_HCINTMSK4;
    volatile    uint32_t    OTG_HCTSIZ4;
    volatile    uint32_t    RESERVED16[3];
    volatile    uint32_t    OTG_HCCHAR5;
    volatile    uint32_t    RESERVED17;
    volatile    uint32_t    OTG_HCINT5;
    volatile    uint32_t    OTG_HCINTMSK5;
    volatile    uint32_t    OTG_HCTSIZ5;
    volatile    uint32_t    RESERVED18[3];
    volatile    uint32_t    OTG_HCCHAR6;
    volatile    uint32_t    RESERVED19;
    volatile    uint32_t    OTG_HCINT6;
    volatile    uint32_t    OTG_HCINTMSK6;
    volatile    uint32_t    OTG_HCTSIZ6;
    volatile    uint32_t    RESERVED20[3];
    volatile    uint32_t    OTG_HCCHAR7;
    volatile    uint32_t    RESERVED21;
    volatile    uint32_t    OTG_HCINT7;
    volatile    uint32_t    OTG_HCINTMSK7;
    volatile    uint32_t    OTG_HCTSIZ7;
    volatile    uint32_t    RESERVED22[3];
    volatile    uint32_t    OTG_HCCHAR8;
    volatile    uint32_t    RESERVED23;
    volatile    uint32_t    OTG_HCINT8;
    volatile    uint32_t    OTG_HCINTMSK8;
    volatile    uint32_t    OTG_HCTSIZ8;
    volatile    uint32_t    RESERVED24[3];
    volatile    uint32_t    OTG_HCCHAR9;
    volatile    uint32_t    RESERVED25;
    volatile    uint32_t    OTG_HCINT9;
    volatile    uint32_t    OTG_HCINTMSK9;
    volatile    uint32_t    OTG_HCTSIZ9;
    volatile    uint32_t    RESERVED26[3];
    volatile    uint32_t    OTG_HCCHAR10;
    volatile    uint32_t    RESERVED27;
    volatile    uint32_t    OTG_HCINT10;
    volatile    uint32_t    OTG_HCINTMSK10;
    volatile    uint32_t    OTG_HCTSIZ10;
    volatile    uint32_t    RESERVED28[3];
    volatile    uint32_t    OTG_HCCHAR11;
    volatile    uint32_t    RESERVED29;
    volatile    uint32_t    OTG_HCINT11;
    volatile    uint32_t    OTG_HCINTMSK11;
    volatile    uint32_t    OTG_HCTSIZ11;
    volatile    uint32_t    RESERVED30[99];
    volatile    uint32_t    OTG_DCFG;
    volatile    uint32_t    OTG_DCTL;
    volatile    uint32_t    OTG_DSTS;
    volatile    uint32_t    RESERVED31;
    volatile    uint32_t    OTG_DIEPMSK;
    volatile    uint32_t    OTG_DOEPMSK;
    volatile    uint32_t    OTG_DAINT;
    volatile    uint32_t    OTG_DAINTMSK;
    volatile    uint32_t    RESERVED32[5];
    volatile    uint32_t    OTG_DIEPEMPMSK;
    volatile    uint32_t    OTG_DEACHINT;
    volatile    uint32_t    OTG_DEACHINTMSK;
    volatile    uint32_t    RESERVED33;
    volatile    uint32_t    OTG_HS_DIEPEACHMSK1;
    volatile    uint32_t    RESERVED34[15];
    volatile    uint32_t    OTG_HS_DOEPEACHMSK1;
    volatile    uint32_t    RESERVED35[30];
    volatile    uint32_t    OTG_DIEPCTL0;
    volatile    uint32_t    RESERVED36;
    volatile    uint32_t    OTG_DIEPINT0;
    volatile    uint32_t    RESERVED37;
    volatile    uint32_t    OTG_DIEPTSIZ0;
    volatile    uint32_t    RESERVED38;
    volatile    uint32_t    OTG_DTXFSTS0;
    volatile    uint32_t    RESERVED39;
        union {
    volatile    uint32_t    OTG_DIEPCTL1;
    volatile    uint32_t    OTG_DIEPCTL1_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED40;
    volatile    uint32_t    OTG_DIEPINT1;
    volatile    uint32_t    RESERVED41;
    volatile    uint32_t    OTG_DIEPTSIZ1;
    volatile    uint32_t    RESERVED42;
    volatile    uint32_t    OTG_DTXFSTS1;
    volatile    uint32_t    RESERVED43;
        union {
    volatile    uint32_t    OTG_DIEPCTL2;
    volatile    uint32_t    OTG_DIEPCTL2_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED44;
    volatile    uint32_t    OTG_DIEPINT2;
    volatile    uint32_t    RESERVED45;
    volatile    uint32_t    OTG_DIEPTSIZ2;
    volatile    uint32_t    RESERVED46;
    volatile    uint32_t    OTG_DTXFSTS2;
    volatile    uint32_t    RESERVED47;
        union {
    volatile    uint32_t    OTG_DIEPCTL3;
    volatile    uint32_t    OTG_DIEPCTL3_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED48;
    volatile    uint32_t    OTG_DIEPINT3;
    volatile    uint32_t    RESERVED49;
    volatile    uint32_t    OTG_DIEPTSIZ3;
    volatile    uint32_t    RESERVED50;
    volatile    uint32_t    OTG_DTXFSTS3;
    volatile    uint32_t    RESERVED51;
        union {
    volatile    uint32_t    OTG_DIEPCTL4;
    volatile    uint32_t    OTG_DIEPCTL4_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED52;
    volatile    uint32_t    OTG_DIEPINT4;
    volatile    uint32_t    RESERVED53;
    volatile    uint32_t    OTG_DIEPTSIZ4;
    volatile    uint32_t    RESERVED54;
    volatile    uint32_t    OTG_DTXFSTS4;
    volatile    uint32_t    RESERVED55;
        union {
    volatile    uint32_t    OTG_DIEPCTL5;
    volatile    uint32_t    OTG_DIEPCTL5_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED56;
    volatile    uint32_t    OTG_DIEPINT5;
    volatile    uint32_t    RESERVED57;
    volatile    uint32_t    OTG_DIEPTSIZ5;
    volatile    uint32_t    RESERVED58;
    volatile    uint32_t    OTG_DTXFSTS5;
    volatile    uint32_t    RESERVED59[81];
    volatile    uint32_t    OTG_DOEPCTL0;
    volatile    uint32_t    RESERVED60;
    volatile    uint32_t    OTG_DOEPINT0;
    volatile    uint32_t    RESERVED61;
    volatile    uint32_t    OTG_DOEPTSIZ0;
    volatile    uint32_t    RESERVED62[3];
        union {
    volatile    uint32_t    OTG_DOEPCTL1;
    volatile    uint32_t    OTG_DOEPCTL1_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED63;
    volatile    uint32_t    OTG_DOEPINT1;
    volatile    uint32_t    RESERVED64;
    volatile    uint32_t    OTG_DOEPTSIZ1;
    volatile    uint32_t    RESERVED65[3];
        union {
    volatile    uint32_t    OTG_DOEPCTL2;
    volatile    uint32_t    OTG_DOEPCTL2_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED66;
    volatile    uint32_t    OTG_DOEPINT2;
    volatile    uint32_t    RESERVED67;
    volatile    uint32_t    OTG_DOEPTSIZ2;
    volatile    uint32_t    RESERVED68[3];
        union {
    volatile    uint32_t    OTG_DOEPCTL3;
    volatile    uint32_t    OTG_DOEPCTL3_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED69;
    volatile    uint32_t    OTG_DOEPINT3;
    volatile    uint32_t    RESERVED70;
    volatile    uint32_t    OTG_DOEPTSIZ3;
    volatile    uint32_t    RESERVED71[3];
        union {
    volatile    uint32_t    OTG_DOEPCTL4;
    volatile    uint32_t    OTG_DOEPCTL4_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED72;
    volatile    uint32_t    OTG_DOEPINT4;
    volatile    uint32_t    RESERVED73;
    volatile    uint32_t    OTG_DOEPTSIZ4;
    volatile    uint32_t    RESERVED74[3];
        union {
    volatile    uint32_t    OTG_DOEPCTL5;
    volatile    uint32_t    OTG_DOEPCTL5_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED75;
    volatile    uint32_t    OTG_DOEPINT5;
    volatile    uint32_t    RESERVED76;
    volatile    uint32_t    OTG_DOEPTSIZ5;
    volatile    uint32_t    RESERVED77[147];
    volatile    uint32_t    OTG_PCGCCTL;
    volatile    uint32_t    OTG_PCGCCTL1;
} OTG_FS_TypeDef;

#if (defined(__cplusplus))
#define OTG_FS_NS   reinterpret_cast<OTG_FS_TypeDef *>(0x40080000u)
#define OTG_FS_S    reinterpret_cast<OTG_FS_TypeDef *>(0x50080000u)

#else
#define OTG_FS_NS   ((OTG_FS_TypeDef *)0x40080000u)
#define OTG_FS_S    ((OTG_FS_TypeDef *)0x50080000u)
#endif

// OTG_GOTGCTL Configuration

#define OTG_FS_OTG_GOTGCTL_CURMOD                                       (0x1u<<21)
#define OTG_FS_OTG_GOTGCTL_OTGVER                                       (0x1u<<20)
#define OTG_FS_OTG_GOTGCTL_BSVLD                                        (0x1u<<19)
#define OTG_FS_OTG_GOTGCTL_ASVLD                                        (0x1u<<18)
#define OTG_FS_OTG_GOTGCTL_DBCT                                         (0x1u<<17)
#define OTG_FS_OTG_GOTGCTL_CIDSTS                                       (0x1u<<16)
#define OTG_FS_OTG_GOTGCTL_EHEN                                         (0x1u<<12)
#define OTG_FS_OTG_GOTGCTL_BVALOVAL                                     (0x1u<<7)
#define OTG_FS_OTG_GOTGCTL_BVALOEN                                      (0x1u<<6)
#define OTG_FS_OTG_GOTGCTL_AVALOVAL                                     (0x1u<<5)
#define OTG_FS_OTG_GOTGCTL_AVALOEN                                      (0x1u<<4)
#define OTG_FS_OTG_GOTGCTL_VBVALOVAL                                    (0x1u<<3)
#define OTG_FS_OTG_GOTGCTL_VBVALOEN                                     (0x1u<<2)

#define OTG_FS_OTG_GOTGCTL_CURMOD_B_0X0                                 (0x0u<<21)
#define OTG_FS_OTG_GOTGCTL_CURMOD_B_0X1                                 (0x1u<<21)
#define OTG_FS_OTG_GOTGCTL_OTGVER_B_0X0                                 (0x0u<<20)
#define OTG_FS_OTG_GOTGCTL_OTGVER_B_0X1                                 (0x1u<<20)
#define OTG_FS_OTG_GOTGCTL_BSVLD_B_0X0                                  (0x0u<<19)
#define OTG_FS_OTG_GOTGCTL_BSVLD_B_0X1                                  (0x1u<<19)
#define OTG_FS_OTG_GOTGCTL_ASVLD_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_GOTGCTL_ASVLD_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_GOTGCTL_DBCT_B_0X0                                   (0x0u<<17)
#define OTG_FS_OTG_GOTGCTL_DBCT_B_0X1                                   (0x1u<<17)
#define OTG_FS_OTG_GOTGCTL_CIDSTS_B_0X0                                 (0x0u<<16)
#define OTG_FS_OTG_GOTGCTL_CIDSTS_B_0X1                                 (0x1u<<16)
#define OTG_FS_OTG_GOTGCTL_EHEN_B_0X0                                   (0x0u<<12)
#define OTG_FS_OTG_GOTGCTL_EHEN_B_0X1                                   (0x1u<<12)
#define OTG_FS_OTG_GOTGCTL_BVALOVAL_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_GOTGCTL_BVALOVAL_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_GOTGCTL_BVALOEN_B_0X0                                (0x0u<<6)
#define OTG_FS_OTG_GOTGCTL_BVALOEN_B_0X1                                (0x1u<<6)
#define OTG_FS_OTG_GOTGCTL_AVALOVAL_B_0X0                               (0x0u<<5)
#define OTG_FS_OTG_GOTGCTL_AVALOVAL_B_0X1                               (0x1u<<5)
#define OTG_FS_OTG_GOTGCTL_AVALOEN_B_0X0                                (0x0u<<4)
#define OTG_FS_OTG_GOTGCTL_AVALOEN_B_0X1                                (0x1u<<4)
#define OTG_FS_OTG_GOTGCTL_VBVALOVAL_B_0X0                              (0x0u<<3)
#define OTG_FS_OTG_GOTGCTL_VBVALOVAL_B_0X1                              (0x1u<<3)
#define OTG_FS_OTG_GOTGCTL_VBVALOEN_B_0X0                               (0x0u<<2)
#define OTG_FS_OTG_GOTGCTL_VBVALOEN_B_0X1                               (0x1u<<2)

// OTG_GOTGINT Configuration

#define OTG_FS_OTG_GOTGINT_ADTOCHG                                      (0x1u<<18)
#define OTG_FS_OTG_GOTGINT_SEDET                                        (0x1u<<2)

// OTG_GAHBCFG Configuration

#define OTG_FS_OTG_GAHBCFG_PTXFELVL                                     (0x1u<<8)
#define OTG_FS_OTG_GAHBCFG_TXFELVL                                      (0x1u<<7)
#define OTG_FS_OTG_GAHBCFG_GINTMSK                                      (0x1u<<0)

#define OTG_FS_OTG_GAHBCFG_PTXFELVL_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_GAHBCFG_PTXFELVL_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_GAHBCFG_TXFELVL_B_0X0                                (0x0u<<7)
#define OTG_FS_OTG_GAHBCFG_TXFELVL_B_0X1                                (0x1u<<7)
#define OTG_FS_OTG_GAHBCFG_GINTMSK_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_GAHBCFG_GINTMSK_B_0X1                                (0x1u<<0)

// OTG_GUSBCFG Configuration

#define OTG_FS_OTG_GUSBCFG_FDMOD                                        (0x1u<<30)
#define OTG_FS_OTG_GUSBCFG_FHMOD                                        (0x1u<<29)
#define OTG_FS_OTG_GUSBCFG_TRDT                                         (0xFu<<10)
#define OTG_FS_OTG_GUSBCFG_TRDT_0                                       (0x1u<<10)
#define OTG_FS_OTG_GUSBCFG_PHYSEL                                       (0x1u<<6)
#define OTG_FS_OTG_GUSBCFG_TOCAL                                        (0x7u<<0)
#define OTG_FS_OTG_GUSBCFG_TOCAL_0                                      (0x1u<<0)

#define OTG_FS_OTG_GUSBCFG_FDMOD_B_0X0                                  (0x0u<<30)
#define OTG_FS_OTG_GUSBCFG_FDMOD_B_0X1                                  (0x1u<<30)
#define OTG_FS_OTG_GUSBCFG_FHMOD_B_0X0                                  (0x0u<<29)
#define OTG_FS_OTG_GUSBCFG_FHMOD_B_0X1                                  (0x1u<<29)

// OTG_GRSTCTL Configuration

#define OTG_FS_OTG_GRSTCTL_AHBIDL                                       (0x1u<<31)
#define OTG_FS_OTG_GRSTCTL_CSRSTDONE                                    (0x1u<<29)
#define OTG_FS_OTG_GRSTCTL_TXFNUM                                       (0x1Fu<<6)
#define OTG_FS_OTG_GRSTCTL_TXFNUM_0                                     (0x1u<<6)
#define OTG_FS_OTG_GRSTCTL_TXFFLSH                                      (0x1u<<5)
#define OTG_FS_OTG_GRSTCTL_RXFFLSH                                      (0x1u<<4)
#define OTG_FS_OTG_GRSTCTL_FCRST                                        (0x1u<<2)
#define OTG_FS_OTG_GRSTCTL_PSRST                                        (0x1u<<1)
#define OTG_FS_OTG_GRSTCTL_CSRST                                        (0x1u<<0)

#define OTG_FS_OTG_GRSTCTL_CSRSTDONE_B_0X0                              (0x0u<<29)
#define OTG_FS_OTG_GRSTCTL_CSRSTDONE_B_0X1                              (0x1u<<29)
#define OTG_FS_OTG_GRSTCTL_TXFNUM_B_0X0_HOST_MODE                       (0x0u<<6)
#define OTG_FS_OTG_GRSTCTL_TXFNUM_B_0X1_HOST_MODE                       (0x1u<<6)
#define OTG_FS_OTG_GRSTCTL_TXFNUM_B_0X10_HOST_MODE                      (0x10u<<6)
#define OTG_FS_OTG_GRSTCTL_TXFNUM_B_0X2_DEVICE_MODE                     (0x2u<<6)
#define OTG_FS_OTG_GRSTCTL_TXFNUM_B_0XF_DEVICE_MODE                     (0xFu<<6)

// OTG_GINTSTS Configuration

#define OTG_FS_OTG_GINTSTS_WKUPINT                                      (0x1u<<31)
#define OTG_FS_OTG_GINTSTS_SRQINT                                       (0x1u<<30)
#define OTG_FS_OTG_GINTSTS_DISCINT                                      (0x1u<<29)
#define OTG_FS_OTG_GINTSTS_CIDSCHG                                      (0x1u<<28)
#define OTG_FS_OTG_GINTSTS_LPMINT                                       (0x1u<<27)
#define OTG_FS_OTG_GINTSTS_PTXFE                                        (0x1u<<26)
#define OTG_FS_OTG_GINTSTS_HCINT                                        (0x1u<<25)
#define OTG_FS_OTG_GINTSTS_HPRTINT                                      (0x1u<<24)
#define OTG_FS_OTG_GINTSTS_RSTDET                                       (0x1u<<23)
#define OTG_FS_OTG_GINTSTS_IPXFR                                        (0x1u<<21)
#define OTG_FS_OTG_GINTSTS_IISOIXFR                                     (0x1u<<20)
#define OTG_FS_OTG_GINTSTS_OEPINT                                       (0x1u<<19)
#define OTG_FS_OTG_GINTSTS_IEPINT                                       (0x1u<<18)
#define OTG_FS_OTG_GINTSTS_EOPF                                         (0x1u<<15)
#define OTG_FS_OTG_GINTSTS_ISOODRP                                      (0x1u<<14)
#define OTG_FS_OTG_GINTSTS_ENUMDNE                                      (0x1u<<13)
#define OTG_FS_OTG_GINTSTS_USBRST                                       (0x1u<<12)
#define OTG_FS_OTG_GINTSTS_USBSUSP                                      (0x1u<<11)
#define OTG_FS_OTG_GINTSTS_ESUSP                                        (0x1u<<10)
#define OTG_FS_OTG_GINTSTS_GONAKEFF                                     (0x1u<<7)
#define OTG_FS_OTG_GINTSTS_GINAKEFF                                     (0x1u<<6)
#define OTG_FS_OTG_GINTSTS_NPTXFE                                       (0x1u<<5)
#define OTG_FS_OTG_GINTSTS_RXFLVL                                       (0x1u<<4)
#define OTG_FS_OTG_GINTSTS_SOF                                          (0x1u<<3)
#define OTG_FS_OTG_GINTSTS_OTGINT                                       (0x1u<<2)
#define OTG_FS_OTG_GINTSTS_MMIS                                         (0x1u<<1)
#define OTG_FS_OTG_GINTSTS_CMOD                                         (0x1u<<0)

#define OTG_FS_OTG_GINTSTS_CMOD_B_0X0                                   (0x0u<<0)
#define OTG_FS_OTG_GINTSTS_CMOD_B_0X1                                   (0x1u<<0)

// OTG_GINTMSK Configuration

#define OTG_FS_OTG_GINTMSK_WUIM                                         (0x1u<<31)
#define OTG_FS_OTG_GINTMSK_SRQIM                                        (0x1u<<30)
#define OTG_FS_OTG_GINTMSK_DISCINT                                      (0x1u<<29)
#define OTG_FS_OTG_GINTMSK_CIDSCHGM                                     (0x1u<<28)
#define OTG_FS_OTG_GINTMSK_LPMINTM                                      (0x1u<<27)
#define OTG_FS_OTG_GINTMSK_PTXFEM                                       (0x1u<<26)
#define OTG_FS_OTG_GINTMSK_HCIM                                         (0x1u<<25)
#define OTG_FS_OTG_GINTMSK_PRTIM                                        (0x1u<<24)
#define OTG_FS_OTG_GINTMSK_IPXFRM                                       (0x1u<<21)
#define OTG_FS_OTG_GINTMSK_NPTXFEM                                      (0x1u<<5)
#define OTG_FS_OTG_GINTMSK_RXFLVLM                                      (0x1u<<4)
#define OTG_FS_OTG_GINTMSK_SOFM                                         (0x1u<<3)
#define OTG_FS_OTG_GINTMSK_OTGINT                                       (0x1u<<2)
#define OTG_FS_OTG_GINTMSK_MMISM                                        (0x1u<<1)

#define OTG_FS_OTG_GINTMSK_WUIM_B_0X0                                   (0x0u<<31)
#define OTG_FS_OTG_GINTMSK_WUIM_B_0X1                                   (0x1u<<31)
#define OTG_FS_OTG_GINTMSK_SRQIM_B_0X0                                  (0x0u<<30)
#define OTG_FS_OTG_GINTMSK_SRQIM_B_0X1                                  (0x1u<<30)
#define OTG_FS_OTG_GINTMSK_DISCINT_B_0X0                                (0x0u<<29)
#define OTG_FS_OTG_GINTMSK_DISCINT_B_0X1                                (0x1u<<29)
#define OTG_FS_OTG_GINTMSK_CIDSCHGM_B_0X0                               (0x0u<<28)
#define OTG_FS_OTG_GINTMSK_CIDSCHGM_B_0X1                               (0x1u<<28)
#define OTG_FS_OTG_GINTMSK_LPMINTM_B_0X0                                (0x0u<<27)
#define OTG_FS_OTG_GINTMSK_LPMINTM_B_0X1                                (0x1u<<27)
#define OTG_FS_OTG_GINTMSK_PTXFEM_B_0X0                                 (0x0u<<26)
#define OTG_FS_OTG_GINTMSK_PTXFEM_B_0X1                                 (0x1u<<26)
#define OTG_FS_OTG_GINTMSK_HCIM_B_0X0                                   (0x0u<<25)
#define OTG_FS_OTG_GINTMSK_HCIM_B_0X1                                   (0x1u<<25)
#define OTG_FS_OTG_GINTMSK_PRTIM_B_0X0                                  (0x0u<<24)
#define OTG_FS_OTG_GINTMSK_PRTIM_B_0X1                                  (0x1u<<24)
#define OTG_FS_OTG_GINTMSK_IPXFRM_B_0X0                                 (0x0u<<21)
#define OTG_FS_OTG_GINTMSK_IPXFRM_B_0X1                                 (0x1u<<21)
#define OTG_FS_OTG_GINTMSK_NPTXFEM_B_0X0                                (0x0u<<5)
#define OTG_FS_OTG_GINTMSK_NPTXFEM_B_0X1                                (0x1u<<5)
#define OTG_FS_OTG_GINTMSK_RXFLVLM_B_0X0                                (0x0u<<4)
#define OTG_FS_OTG_GINTMSK_RXFLVLM_B_0X1                                (0x1u<<4)
#define OTG_FS_OTG_GINTMSK_SOFM_B_0X0                                   (0x0u<<3)
#define OTG_FS_OTG_GINTMSK_SOFM_B_0X1                                   (0x1u<<3)
#define OTG_FS_OTG_GINTMSK_OTGINT_B_0X0                                 (0x0u<<2)
#define OTG_FS_OTG_GINTMSK_OTGINT_B_0X1                                 (0x1u<<2)
#define OTG_FS_OTG_GINTMSK_MMISM_B_0X0                                  (0x0u<<1)
#define OTG_FS_OTG_GINTMSK_MMISM_B_0X1                                  (0x1u<<1)

// OTG_GRXSTSR Configuration

#define OTG_FS_OTG_GRXSTSR_PKTSTS                                       (0xFu<<17)
#define OTG_FS_OTG_GRXSTSR_PKTSTS_0                                     (0x1u<<17)
#define OTG_FS_OTG_GRXSTSR_DPID                                         (0x3u<<15)
#define OTG_FS_OTG_GRXSTSR_DPID_0                                       (0x1u<<15)
#define OTG_FS_OTG_GRXSTSR_BCNT                                         (0x7FFu<<4)
#define OTG_FS_OTG_GRXSTSR_BCNT_0                                       (0x1u<<4)
#define OTG_FS_OTG_GRXSTSR_CHNUM                                        (0xFu<<0)
#define OTG_FS_OTG_GRXSTSR_CHNUM_0                                      (0x1u<<0)

#define OTG_FS_OTG_GRXSTSR_PKTSTS_B_0X2                                 (0x2u<<17)
#define OTG_FS_OTG_GRXSTSR_PKTSTS_B_0X3                                 (0x3u<<17)
#define OTG_FS_OTG_GRXSTSR_PKTSTS_B_0X5                                 (0x5u<<17)
#define OTG_FS_OTG_GRXSTSR_PKTSTS_B_0X7                                 (0x7u<<17)
#define OTG_FS_OTG_GRXSTSR_DPID_B_0X0                                   (0x0u<<15)
#define OTG_FS_OTG_GRXSTSR_DPID_B_0X2                                   (0x2u<<15)

// OTG_GRXSTSP Configuration

#define OTG_FS_OTG_GRXSTSP_PKTSTS                                       (0xFu<<17)
#define OTG_FS_OTG_GRXSTSP_PKTSTS_0                                     (0x1u<<17)
#define OTG_FS_OTG_GRXSTSP_DPID                                         (0x3u<<15)
#define OTG_FS_OTG_GRXSTSP_DPID_0                                       (0x1u<<15)
#define OTG_FS_OTG_GRXSTSP_BCNT                                         (0x7FFu<<4)
#define OTG_FS_OTG_GRXSTSP_BCNT_0                                       (0x1u<<4)
#define OTG_FS_OTG_GRXSTSP_CHNUM                                        (0xFu<<0)
#define OTG_FS_OTG_GRXSTSP_CHNUM_0                                      (0x1u<<0)

#define OTG_FS_OTG_GRXSTSP_PKTSTS_B_0X2                                 (0x2u<<17)
#define OTG_FS_OTG_GRXSTSP_PKTSTS_B_0X3                                 (0x3u<<17)
#define OTG_FS_OTG_GRXSTSP_PKTSTS_B_0X5                                 (0x5u<<17)
#define OTG_FS_OTG_GRXSTSP_PKTSTS_B_0X7                                 (0x7u<<17)
#define OTG_FS_OTG_GRXSTSP_DPID_B_0X0                                   (0x0u<<15)
#define OTG_FS_OTG_GRXSTSP_DPID_B_0X2                                   (0x2u<<15)

// OTG_GRXFSIZ Configuration

#define OTG_FS_OTG_GRXFSIZ_RXFD                                         (0xFFFFu<<0)
#define OTG_FS_OTG_GRXFSIZ_RXFD_0                                       (0x1u<<0)

// OTG_HNPTXFSIZ Configuration

#define OTG_FS_OTG_HNPTXFSIZ_NPTXFD                                     (0xFFFFu<<16)
#define OTG_FS_OTG_HNPTXFSIZ_NPTXFD_0                                   (0x1u<<16)
#define OTG_FS_OTG_HNPTXFSIZ_NPTXFSA                                    (0xFFFFu<<0)
#define OTG_FS_OTG_HNPTXFSIZ_NPTXFSA_0                                  (0x1u<<0)

// OTG_DIEPTXF0 Configuration

#define OTG_FS_OTG_DIEPTXF0_TX0FD                                       (0xFFFFu<<16)
#define OTG_FS_OTG_DIEPTXF0_TX0FD_0                                     (0x1u<<16)
#define OTG_FS_OTG_DIEPTXF0_TX0FSA                                      (0xFFFFu<<0)
#define OTG_FS_OTG_DIEPTXF0_TX0FSA_0                                    (0x1u<<0)

// OTG_HNPTXSTS Configuration

#define OTG_FS_OTG_HNPTXSTS_NPTXQTOP                                    (0x7Fu<<24)
#define OTG_FS_OTG_HNPTXSTS_NPTXQTOP_0                                  (0x1u<<24)
#define OTG_FS_OTG_HNPTXSTS_NPTQXSAV                                    (0xFFu<<16)
#define OTG_FS_OTG_HNPTXSTS_NPTQXSAV_0                                  (0x1u<<16)
#define OTG_FS_OTG_HNPTXSTS_NPTXFSAV                                    (0xFFFFu<<0)
#define OTG_FS_OTG_HNPTXSTS_NPTXFSAV_0                                  (0x1u<<0)

#define OTG_FS_OTG_HNPTXSTS_NPTQXSAV_B_0X0                              (0x0u<<16)
#define OTG_FS_OTG_HNPTXSTS_NPTQXSAV_B_0X1                              (0x1u<<16)
#define OTG_FS_OTG_HNPTXSTS_NPTXFSAV_B_0X0                              (0x0u<<0)
#define OTG_FS_OTG_HNPTXSTS_NPTXFSAV_B_0X1                              (0x1u<<0)

// OTG_GCCFG Configuration

#define OTG_FS_OTG_GCCFG_FORCEHOSTPD                                    (0x1u<<25)
#define OTG_FS_OTG_GCCFG_COMPDIS                                        (0x1u<<24)
#define OTG_FS_OTG_GCCFG_VBDEN                                          (0x1u<<21)
#define OTG_FS_OTG_GCCFG_SDEN                                           (0x1u<<20)
#define OTG_FS_OTG_GCCFG_PDEN                                           (0x1u<<19)
#define OTG_FS_OTG_GCCFG_BCDEN                                          (0x1u<<17)
#define OTG_FS_OTG_GCCFG_PWRDWN                                         (0x1u<<16)
#define OTG_FS_OTG_GCCFG_SESSVLD                                        (0x1u<<4)
#define OTG_FS_OTG_GCCFG_PS2DET                                         (0x1u<<3)
#define OTG_FS_OTG_GCCFG_SDET                                           (0x1u<<2)
#define OTG_FS_OTG_GCCFG_PDET                                           (0x1u<<1)

#define OTG_FS_OTG_GCCFG_FORCEHOSTPD_B_0X0                              (0x0u<<25)
#define OTG_FS_OTG_GCCFG_FORCEHOSTPD_B_0X1                              (0x1u<<25)
#define OTG_FS_OTG_GCCFG_COMPDIS_B_0X0                                  (0x0u<<24)
#define OTG_FS_OTG_GCCFG_COMPDIS_B_0X1                                  (0x1u<<24)
#define OTG_FS_OTG_GCCFG_SESSVLD_B_0X0                                  (0x0u<<4)
#define OTG_FS_OTG_GCCFG_SESSVLD_B_0X1                                  (0x1u<<4)
#define OTG_FS_OTG_GCCFG_PS2DET_B_0X0                                   (0x0u<<3)
#define OTG_FS_OTG_GCCFG_PS2DET_B_0X1                                   (0x1u<<3)
#define OTG_FS_OTG_GCCFG_SDET_B_0X0                                     (0x0u<<2)
#define OTG_FS_OTG_GCCFG_SDET_B_0X1                                     (0x1u<<2)
#define OTG_FS_OTG_GCCFG_PDET_B_0X0                                     (0x0u<<1)
#define OTG_FS_OTG_GCCFG_PDET_B_0X1                                     (0x1u<<1)

// OTG_CID Configuration

#define OTG_FS_OTG_CID_PRODUCT_ID                                       (0xFFFFFFFFu<<0)
#define OTG_FS_OTG_CID_PRODUCT_ID_0                                     (0x1u<<0)

// OTG_GLPMCFG Configuration

#define OTG_FS_OTG_GLPMCFG_ENBESL                                       (0x1u<<28)
#define OTG_FS_OTG_GLPMCFG_LPMRCNTSTS                                   (0x7u<<25)
#define OTG_FS_OTG_GLPMCFG_LPMRCNTSTS_0                                 (0x1u<<25)
#define OTG_FS_OTG_GLPMCFG_SNDLPM                                       (0x1u<<24)
#define OTG_FS_OTG_GLPMCFG_LPMRCNT                                      (0x7u<<21)
#define OTG_FS_OTG_GLPMCFG_LPMRCNT_0                                    (0x1u<<21)
#define OTG_FS_OTG_GLPMCFG_LPMCHIDX                                     (0xFu<<17)
#define OTG_FS_OTG_GLPMCFG_LPMCHIDX_0                                   (0x1u<<17)
#define OTG_FS_OTG_GLPMCFG_L1RSMOK                                      (0x1u<<16)
#define OTG_FS_OTG_GLPMCFG_SLPSTS                                       (0x1u<<15)
#define OTG_FS_OTG_GLPMCFG_LPMRSP                                       (0x3u<<13)
#define OTG_FS_OTG_GLPMCFG_LPMRSP_0                                     (0x1u<<13)
#define OTG_FS_OTG_GLPMCFG_L1DSEN                                       (0x1u<<12)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS                                     (0xFu<<8)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS_0                                   (0x1u<<8)
#define OTG_FS_OTG_GLPMCFG_L1SSEN                                       (0x1u<<7)
#define OTG_FS_OTG_GLPMCFG_REMWAKE                                      (0x1u<<6)
#define OTG_FS_OTG_GLPMCFG_BESL                                         (0xFu<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_0                                       (0x1u<<2)
#define OTG_FS_OTG_GLPMCFG_LPMACK                                       (0x1u<<1)
#define OTG_FS_OTG_GLPMCFG_LPMEN                                        (0x1u<<0)

#define OTG_FS_OTG_GLPMCFG_ENBESL_B_0X0                                 (0x0u<<28)
#define OTG_FS_OTG_GLPMCFG_ENBESL_B_0X1                                 (0x1u<<28)
#define OTG_FS_OTG_GLPMCFG_L1RSMOK_B_0X1                                (0x1u<<16)
#define OTG_FS_OTG_GLPMCFG_L1RSMOK_B_0X0                                (0x0u<<16)
#define OTG_FS_OTG_GLPMCFG_SLPSTS_B_0X0                                 (0x0u<<15)
#define OTG_FS_OTG_GLPMCFG_SLPSTS_B_0X1                                 (0x1u<<15)
#define OTG_FS_OTG_GLPMCFG_LPMRSP_B_0X3                                 (0x3u<<13)
#define OTG_FS_OTG_GLPMCFG_LPMRSP_B_0X2                                 (0x2u<<13)
#define OTG_FS_OTG_GLPMCFG_LPMRSP_B_0X1                                 (0x1u<<13)
#define OTG_FS_OTG_GLPMCFG_LPMRSP_B_0X0                                 (0x0u<<13)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS_B_0X2                               (0x2u<<8)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS_B_0X3                               (0x3u<<8)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS_B_0X4                               (0x4u<<8)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS_B_0X5                               (0x5u<<8)
#define OTG_FS_OTG_GLPMCFG_BESLTHRS_B_0X6                               (0x6u<<8)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X0                                   (0x0u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X1                                   (0x1u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X2                                   (0x2u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X3                                   (0x3u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X4                                   (0x4u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X5                                   (0x5u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X6                                   (0x6u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X7                                   (0x7u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X8                                   (0x8u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0X9                                   (0x9u<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0XA                                   (0xAu<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0XB                                   (0xBu<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0XC                                   (0xCu<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0XD                                   (0xDu<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0XE                                   (0xEu<<2)
#define OTG_FS_OTG_GLPMCFG_BESL_B_0XF                                   (0xFu<<2)
#define OTG_FS_OTG_GLPMCFG_LPMACK_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_GLPMCFG_LPMACK_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_GLPMCFG_LPMEN_B_0X0                                  (0x0u<<0)
#define OTG_FS_OTG_GLPMCFG_LPMEN_B_0X1                                  (0x1u<<0)

// OTG_HPTXFSIZ Configuration

#define OTG_FS_OTG_HPTXFSIZ_PTXFSIZ                                     (0xFFFFu<<16)
#define OTG_FS_OTG_HPTXFSIZ_PTXFSIZ_0                                   (0x1u<<16)
#define OTG_FS_OTG_HPTXFSIZ_PTXSA                                       (0xFFFFu<<0)
#define OTG_FS_OTG_HPTXFSIZ_PTXSA_0                                     (0x1u<<0)

// OTG_DIEPTXF1 Configuration

#define OTG_FS_OTG_DIEPTXF1_INEPTXFD                                    (0xFFFFu<<16)
#define OTG_FS_OTG_DIEPTXF1_INEPTXFD_0                                  (0x1u<<16)
#define OTG_FS_OTG_DIEPTXF1_INEPTXSA                                    (0xFFFFu<<0)
#define OTG_FS_OTG_DIEPTXF1_INEPTXSA_0                                  (0x1u<<0)

// OTG_DIEPTXF2 Configuration

#define OTG_FS_OTG_DIEPTXF2_INEPTXFD                                    (0xFFFFu<<16)
#define OTG_FS_OTG_DIEPTXF2_INEPTXFD_0                                  (0x1u<<16)
#define OTG_FS_OTG_DIEPTXF2_INEPTXSA                                    (0xFFFFu<<0)
#define OTG_FS_OTG_DIEPTXF2_INEPTXSA_0                                  (0x1u<<0)

// OTG_DIEPTXF3 Configuration

#define OTG_FS_OTG_DIEPTXF3_INEPTXFD                                    (0xFFFFu<<16)
#define OTG_FS_OTG_DIEPTXF3_INEPTXFD_0                                  (0x1u<<16)
#define OTG_FS_OTG_DIEPTXF3_INEPTXSA                                    (0xFFFFu<<0)
#define OTG_FS_OTG_DIEPTXF3_INEPTXSA_0                                  (0x1u<<0)

// OTG_DIEPTXF4 Configuration

#define OTG_FS_OTG_DIEPTXF4_INEPTXFD                                    (0xFFFFu<<16)
#define OTG_FS_OTG_DIEPTXF4_INEPTXFD_0                                  (0x1u<<16)
#define OTG_FS_OTG_DIEPTXF4_INEPTXSA                                    (0xFFFFu<<0)
#define OTG_FS_OTG_DIEPTXF4_INEPTXSA_0                                  (0x1u<<0)

// OTG_DIEPTXF5 Configuration

#define OTG_FS_OTG_DIEPTXF5_INEPTXFD                                    (0xFFFFu<<16)
#define OTG_FS_OTG_DIEPTXF5_INEPTXFD_0                                  (0x1u<<16)
#define OTG_FS_OTG_DIEPTXF5_INEPTXSA                                    (0xFFFFu<<0)
#define OTG_FS_OTG_DIEPTXF5_INEPTXSA_0                                  (0x1u<<0)

// OTG_HCFG Configuration

#define OTG_FS_OTG_HCFG_FSLSS                                           (0x1u<<2)
#define OTG_FS_OTG_HCFG_FSLSPCS                                         (0x3u<<0)
#define OTG_FS_OTG_HCFG_FSLSPCS_0                                       (0x1u<<0)

#define OTG_FS_OTG_HCFG_FSLSS_B_0X1                                     (0x1u<<2)
#define OTG_FS_OTG_HCFG_FSLSPCS_B_0X1_FS_HOST_MODE                      (0x1u<<0)
#define OTG_FS_OTG_HCFG_FSLSPCS_B_0X2_LS_HOST_MODE                      (0x2u<<0)

// OTG_HFIR Configuration

#define OTG_FS_OTG_HFIR_RLDCTRL                                         (0x1u<<16)
#define OTG_FS_OTG_HFIR_FRIVL                                           (0xFFFFu<<0)
#define OTG_FS_OTG_HFIR_FRIVL_0                                         (0x1u<<0)

#define OTG_FS_OTG_HFIR_RLDCTRL_B_0X0                                   (0x0u<<16)
#define OTG_FS_OTG_HFIR_RLDCTRL_B_0X1                                   (0x1u<<16)

// OTG_HFNUM Configuration

#define OTG_FS_OTG_HFNUM_FTREM                                          (0xFFFFu<<16)
#define OTG_FS_OTG_HFNUM_FTREM_0                                        (0x1u<<16)
#define OTG_FS_OTG_HFNUM_FRNUM                                          (0xFFFFu<<0)
#define OTG_FS_OTG_HFNUM_FRNUM_0                                        (0x1u<<0)

// OTG_HPTXSTS Configuration

#define OTG_FS_OTG_HPTXSTS_PTXQTOP                                      (0xFFu<<24)
#define OTG_FS_OTG_HPTXSTS_PTXQTOP_0                                    (0x1u<<24)
#define OTG_FS_OTG_HPTXSTS_PTXQSAV                                      (0xFFu<<16)
#define OTG_FS_OTG_HPTXSTS_PTXQSAV_0                                    (0x1u<<16)
#define OTG_FS_OTG_HPTXSTS_PTXFSAVL                                     (0xFFFFu<<0)
#define OTG_FS_OTG_HPTXSTS_PTXFSAVL_0                                   (0x1u<<0)

#define OTG_FS_OTG_HPTXSTS_PTXQSAV_B_0X0                                (0x0u<<16)
#define OTG_FS_OTG_HPTXSTS_PTXQSAV_B_0X1                                (0x1u<<16)
#define OTG_FS_OTG_HPTXSTS_PTXQSAV_B_0X2                                (0x2u<<16)
#define OTG_FS_OTG_HPTXSTS_PTXFSAVL_B_0X0                               (0x0u<<0)
#define OTG_FS_OTG_HPTXSTS_PTXFSAVL_B_0X1                               (0x1u<<0)
#define OTG_FS_OTG_HPTXSTS_PTXFSAVL_B_0X2                               (0x2u<<0)

// OTG_HAINT Configuration

#define OTG_FS_OTG_HAINT_HAINT                                          (0xFFFFu<<0)
#define OTG_FS_OTG_HAINT_HAINT_0                                        (0x1u<<0)

// OTG_HAINTMSK Configuration

#define OTG_FS_OTG_HAINTMSK_HAINTM                                      (0xFFFFu<<0)
#define OTG_FS_OTG_HAINTMSK_HAINTM_0                                    (0x1u<<0)

#define OTG_FS_OTG_HAINTMSK_HAINTM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HAINTMSK_HAINTM_B_0X1                                (0x1u<<0)

// OTG_HPRT Configuration

#define OTG_FS_OTG_HPRT_PSPD                                            (0x3u<<17)
#define OTG_FS_OTG_HPRT_PSPD_0                                          (0x1u<<17)
#define OTG_FS_OTG_HPRT_PTCTL                                           (0xFu<<13)
#define OTG_FS_OTG_HPRT_PTCTL_0                                         (0x1u<<13)
#define OTG_FS_OTG_HPRT_PPWR                                            (0x1u<<12)
#define OTG_FS_OTG_HPRT_PLSTS                                           (0x3u<<10)
#define OTG_FS_OTG_HPRT_PLSTS_0                                         (0x1u<<10)
#define OTG_FS_OTG_HPRT_PRST                                            (0x1u<<8)
#define OTG_FS_OTG_HPRT_PSUSP                                           (0x1u<<7)
#define OTG_FS_OTG_HPRT_PRES                                            (0x1u<<6)
#define OTG_FS_OTG_HPRT_POCCHNG                                         (0x1u<<5)
#define OTG_FS_OTG_HPRT_POCA                                            (0x1u<<4)
#define OTG_FS_OTG_HPRT_PENCHNG                                         (0x1u<<3)
#define OTG_FS_OTG_HPRT_PENA                                            (0x1u<<2)
#define OTG_FS_OTG_HPRT_PCDET                                           (0x1u<<1)
#define OTG_FS_OTG_HPRT_PCSTS                                           (0x1u<<0)

#define OTG_FS_OTG_HPRT_PSPD_B_0X1                                      (0x1u<<17)
#define OTG_FS_OTG_HPRT_PSPD_B_0X2                                      (0x2u<<17)
#define OTG_FS_OTG_HPRT_PTCTL_B_0X0                                     (0x0u<<13)
#define OTG_FS_OTG_HPRT_PTCTL_B_0X1                                     (0x1u<<13)
#define OTG_FS_OTG_HPRT_PTCTL_B_0X2                                     (0x2u<<13)
#define OTG_FS_OTG_HPRT_PTCTL_B_0X3                                     (0x3u<<13)
#define OTG_FS_OTG_HPRT_PTCTL_B_0X4                                     (0x4u<<13)
#define OTG_FS_OTG_HPRT_PTCTL_B_0X5                                     (0x5u<<13)
#define OTG_FS_OTG_HPRT_PPWR_B_0X0                                      (0x0u<<12)
#define OTG_FS_OTG_HPRT_PPWR_B_0X1                                      (0x1u<<12)
#define OTG_FS_OTG_HPRT_PRST_B_0X0                                      (0x0u<<8)
#define OTG_FS_OTG_HPRT_PRST_B_0X1                                      (0x1u<<8)
#define OTG_FS_OTG_HPRT_PSUSP_B_0X0                                     (0x0u<<7)
#define OTG_FS_OTG_HPRT_PSUSP_B_0X1                                     (0x1u<<7)
#define OTG_FS_OTG_HPRT_PRES_B_0X0                                      (0x0u<<6)
#define OTG_FS_OTG_HPRT_PRES_B_0X1                                      (0x1u<<6)
#define OTG_FS_OTG_HPRT_POCA_B_0X0                                      (0x0u<<4)
#define OTG_FS_OTG_HPRT_POCA_B_0X1                                      (0x1u<<4)
#define OTG_FS_OTG_HPRT_PENA_B_0X0                                      (0x0u<<2)
#define OTG_FS_OTG_HPRT_PENA_B_0X1                                      (0x1u<<2)
#define OTG_FS_OTG_HPRT_PCSTS_B_0X0                                     (0x0u<<0)
#define OTG_FS_OTG_HPRT_PCSTS_B_0X1                                     (0x1u<<0)

// OTG_HCCHAR0 Configuration

#define OTG_FS_OTG_HCCHAR0_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR0_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR0_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR0_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR0_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR0_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR0_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR0_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR0_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR0_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR0_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR0_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR0_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR0_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR0_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR0_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR0_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR0_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR0_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR0_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR0_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR0_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR0_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR0_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR0_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR0_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR0_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR0_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR0_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT0 Configuration

#define OTG_FS_OTG_HCINT0_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT0_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT0_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT0_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT0_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT0_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT0_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT0_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT0_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK0 Configuration

#define OTG_FS_OTG_HCINTMSK0_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK0_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK0_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK0_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK0_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK0_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK0_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK0_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK0_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK0_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK0_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK0_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK0_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK0_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK0_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK0_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK0_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK0_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK0_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK0_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK0_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK0_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK0_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK0_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK0_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK0_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK0_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ0 Configuration

#define OTG_FS_OTG_HCTSIZ0_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ0_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ0_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ0_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ0_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ0_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ0_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ0_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ0_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ0_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR1 Configuration

#define OTG_FS_OTG_HCCHAR1_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR1_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR1_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR1_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR1_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR1_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR1_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR1_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR1_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR1_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR1_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR1_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR1_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR1_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR1_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR1_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR1_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR1_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR1_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR1_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR1_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR1_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR1_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR1_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR1_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR1_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR1_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR1_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR1_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT1 Configuration

#define OTG_FS_OTG_HCINT1_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT1_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT1_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT1_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT1_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT1_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT1_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT1_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT1_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK1 Configuration

#define OTG_FS_OTG_HCINTMSK1_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK1_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK1_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK1_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK1_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK1_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK1_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK1_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK1_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK1_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK1_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK1_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK1_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK1_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK1_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK1_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK1_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK1_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK1_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK1_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK1_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK1_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK1_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK1_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK1_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK1_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK1_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ1 Configuration

#define OTG_FS_OTG_HCTSIZ1_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ1_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ1_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ1_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ1_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ1_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ1_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ1_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ1_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ1_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR2 Configuration

#define OTG_FS_OTG_HCCHAR2_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR2_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR2_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR2_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR2_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR2_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR2_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR2_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR2_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR2_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR2_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR2_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR2_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR2_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR2_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR2_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR2_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR2_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR2_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR2_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR2_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR2_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR2_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR2_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR2_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR2_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR2_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR2_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR2_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT2 Configuration

#define OTG_FS_OTG_HCINT2_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT2_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT2_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT2_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT2_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT2_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT2_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT2_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT2_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK2 Configuration

#define OTG_FS_OTG_HCINTMSK2_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK2_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK2_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK2_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK2_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK2_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK2_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK2_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK2_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK2_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK2_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK2_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK2_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK2_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK2_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK2_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK2_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK2_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK2_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK2_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK2_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK2_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK2_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK2_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK2_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK2_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK2_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ2 Configuration

#define OTG_FS_OTG_HCTSIZ2_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ2_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ2_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ2_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ2_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ2_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ2_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ2_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ2_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ2_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR3 Configuration

#define OTG_FS_OTG_HCCHAR3_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR3_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR3_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR3_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR3_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR3_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR3_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR3_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR3_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR3_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR3_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR3_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR3_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR3_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR3_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR3_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR3_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR3_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR3_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR3_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR3_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR3_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR3_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR3_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR3_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR3_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR3_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR3_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR3_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT3 Configuration

#define OTG_FS_OTG_HCINT3_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT3_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT3_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT3_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT3_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT3_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT3_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT3_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT3_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK3 Configuration

#define OTG_FS_OTG_HCINTMSK3_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK3_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK3_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK3_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK3_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK3_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK3_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK3_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK3_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK3_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK3_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK3_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK3_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK3_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK3_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK3_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK3_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK3_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK3_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK3_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK3_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK3_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK3_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK3_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK3_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK3_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK3_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ3 Configuration

#define OTG_FS_OTG_HCTSIZ3_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ3_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ3_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ3_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ3_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ3_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ3_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ3_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ3_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ3_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR4 Configuration

#define OTG_FS_OTG_HCCHAR4_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR4_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR4_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR4_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR4_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR4_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR4_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR4_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR4_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR4_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR4_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR4_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR4_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR4_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR4_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR4_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR4_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR4_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR4_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR4_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR4_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR4_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR4_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR4_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR4_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR4_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR4_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR4_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR4_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT4 Configuration

#define OTG_FS_OTG_HCINT4_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT4_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT4_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT4_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT4_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT4_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT4_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT4_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT4_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK4 Configuration

#define OTG_FS_OTG_HCINTMSK4_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK4_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK4_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK4_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK4_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK4_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK4_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK4_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK4_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK4_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK4_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK4_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK4_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK4_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK4_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK4_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK4_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK4_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK4_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK4_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK4_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK4_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK4_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK4_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK4_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK4_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK4_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ4 Configuration

#define OTG_FS_OTG_HCTSIZ4_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ4_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ4_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ4_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ4_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ4_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ4_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ4_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ4_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ4_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR5 Configuration

#define OTG_FS_OTG_HCCHAR5_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR5_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR5_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR5_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR5_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR5_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR5_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR5_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR5_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR5_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR5_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR5_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR5_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR5_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR5_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR5_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR5_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR5_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR5_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR5_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR5_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR5_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR5_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR5_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR5_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR5_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR5_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR5_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR5_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT5 Configuration

#define OTG_FS_OTG_HCINT5_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT5_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT5_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT5_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT5_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT5_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT5_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT5_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT5_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK5 Configuration

#define OTG_FS_OTG_HCINTMSK5_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK5_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK5_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK5_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK5_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK5_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK5_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK5_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK5_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK5_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK5_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK5_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK5_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK5_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK5_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK5_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK5_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK5_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK5_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK5_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK5_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK5_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK5_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK5_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK5_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK5_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK5_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ5 Configuration

#define OTG_FS_OTG_HCTSIZ5_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ5_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ5_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ5_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ5_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ5_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ5_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ5_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ5_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ5_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR6 Configuration

#define OTG_FS_OTG_HCCHAR6_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR6_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR6_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR6_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR6_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR6_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR6_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR6_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR6_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR6_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR6_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR6_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR6_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR6_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR6_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR6_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR6_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR6_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR6_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR6_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR6_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR6_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR6_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR6_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR6_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR6_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR6_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR6_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR6_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT6 Configuration

#define OTG_FS_OTG_HCINT6_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT6_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT6_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT6_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT6_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT6_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT6_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT6_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT6_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK6 Configuration

#define OTG_FS_OTG_HCINTMSK6_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK6_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK6_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK6_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK6_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK6_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK6_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK6_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK6_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK6_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK6_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK6_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK6_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK6_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK6_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK6_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK6_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK6_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK6_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK6_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK6_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK6_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK6_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK6_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK6_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK6_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK6_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ6 Configuration

#define OTG_FS_OTG_HCTSIZ6_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ6_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ6_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ6_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ6_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ6_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ6_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ6_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ6_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ6_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR7 Configuration

#define OTG_FS_OTG_HCCHAR7_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR7_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR7_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR7_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR7_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR7_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR7_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR7_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR7_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR7_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR7_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR7_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR7_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR7_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR7_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR7_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR7_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR7_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR7_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR7_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR7_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR7_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR7_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR7_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR7_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR7_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR7_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR7_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR7_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT7 Configuration

#define OTG_FS_OTG_HCINT7_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT7_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT7_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT7_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT7_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT7_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT7_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT7_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT7_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK7 Configuration

#define OTG_FS_OTG_HCINTMSK7_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK7_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK7_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK7_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK7_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK7_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK7_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK7_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK7_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK7_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK7_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK7_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK7_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK7_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK7_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK7_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK7_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK7_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK7_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK7_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK7_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK7_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK7_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK7_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK7_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK7_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK7_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ7 Configuration

#define OTG_FS_OTG_HCTSIZ7_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ7_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ7_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ7_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ7_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ7_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ7_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ7_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ7_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ7_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR8 Configuration

#define OTG_FS_OTG_HCCHAR8_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR8_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR8_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR8_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR8_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR8_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR8_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR8_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR8_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR8_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR8_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR8_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR8_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR8_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR8_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR8_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR8_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR8_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR8_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR8_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR8_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR8_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR8_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR8_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR8_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR8_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR8_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR8_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR8_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT8 Configuration

#define OTG_FS_OTG_HCINT8_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT8_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT8_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT8_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT8_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT8_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT8_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT8_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT8_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK8 Configuration

#define OTG_FS_OTG_HCINTMSK8_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK8_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK8_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK8_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK8_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK8_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK8_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK8_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK8_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK8_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK8_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK8_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK8_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK8_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK8_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK8_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK8_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK8_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK8_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK8_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK8_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK8_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK8_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK8_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK8_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK8_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK8_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ8 Configuration

#define OTG_FS_OTG_HCTSIZ8_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ8_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ8_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ8_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ8_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ8_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ8_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ8_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ8_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ8_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR9 Configuration

#define OTG_FS_OTG_HCCHAR9_CHENA                                        (0x1u<<31)
#define OTG_FS_OTG_HCCHAR9_CHDIS                                        (0x1u<<30)
#define OTG_FS_OTG_HCCHAR9_ODDFRM                                       (0x1u<<29)
#define OTG_FS_OTG_HCCHAR9_DAD                                          (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR9_DAD_0                                        (0x1u<<22)
#define OTG_FS_OTG_HCCHAR9_MCNT                                         (0x3u<<20)
#define OTG_FS_OTG_HCCHAR9_MCNT_0                                       (0x1u<<20)
#define OTG_FS_OTG_HCCHAR9_EPTYP                                        (0x3u<<18)
#define OTG_FS_OTG_HCCHAR9_EPTYP_0                                      (0x1u<<18)
#define OTG_FS_OTG_HCCHAR9_LSDEV                                        (0x1u<<17)
#define OTG_FS_OTG_HCCHAR9_EPDIR                                        (0x1u<<15)
#define OTG_FS_OTG_HCCHAR9_EPNUM                                        (0xFu<<11)
#define OTG_FS_OTG_HCCHAR9_EPNUM_0                                      (0x1u<<11)
#define OTG_FS_OTG_HCCHAR9_MPSIZ                                        (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR9_MPSIZ_0                                      (0x1u<<0)

#define OTG_FS_OTG_HCCHAR9_CHENA_B_0X0                                  (0x0u<<31)
#define OTG_FS_OTG_HCCHAR9_CHENA_B_0X1                                  (0x1u<<31)
#define OTG_FS_OTG_HCCHAR9_ODDFRM_B_0X0                                 (0x0u<<29)
#define OTG_FS_OTG_HCCHAR9_ODDFRM_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_HCCHAR9_MCNT_B_0X0                                   (0x0u<<20)
#define OTG_FS_OTG_HCCHAR9_MCNT_B_0X1                                   (0x1u<<20)
#define OTG_FS_OTG_HCCHAR9_MCNT_B_0X2                                   (0x2u<<20)
#define OTG_FS_OTG_HCCHAR9_MCNT_B_0X3                                   (0x3u<<20)
#define OTG_FS_OTG_HCCHAR9_EPTYP_B_0X0                                  (0x0u<<18)
#define OTG_FS_OTG_HCCHAR9_EPTYP_B_0X1                                  (0x1u<<18)
#define OTG_FS_OTG_HCCHAR9_EPTYP_B_0X2                                  (0x2u<<18)
#define OTG_FS_OTG_HCCHAR9_EPTYP_B_0X3                                  (0x3u<<18)
#define OTG_FS_OTG_HCCHAR9_EPDIR_B_0X0                                  (0x0u<<15)
#define OTG_FS_OTG_HCCHAR9_EPDIR_B_0X1                                  (0x1u<<15)

// OTG_HCINT9 Configuration

#define OTG_FS_OTG_HCINT9_DTERR                                         (0x1u<<10)
#define OTG_FS_OTG_HCINT9_FRMOR                                         (0x1u<<9)
#define OTG_FS_OTG_HCINT9_BBERR                                         (0x1u<<8)
#define OTG_FS_OTG_HCINT9_TXERR                                         (0x1u<<7)
#define OTG_FS_OTG_HCINT9_ACK                                           (0x1u<<5)
#define OTG_FS_OTG_HCINT9_NAK                                           (0x1u<<4)
#define OTG_FS_OTG_HCINT9_STALL                                         (0x1u<<3)
#define OTG_FS_OTG_HCINT9_CHH                                           (0x1u<<1)
#define OTG_FS_OTG_HCINT9_XFRC                                          (0x1u<<0)

// OTG_HCINTMSK9 Configuration

#define OTG_FS_OTG_HCINTMSK9_DTERRM                                     (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK9_FRMORM                                     (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK9_BBERRM                                     (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK9_TXERRM                                     (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK9_ACKM                                       (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK9_NAKM                                       (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK9_STALLM                                     (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK9_CHHM                                       (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK9_XFRCM                                      (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK9_DTERRM_B_0X0                               (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK9_DTERRM_B_0X1                               (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK9_FRMORM_B_0X0                               (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK9_FRMORM_B_0X1                               (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK9_BBERRM_B_0X0                               (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK9_BBERRM_B_0X1                               (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK9_TXERRM_B_0X0                               (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK9_TXERRM_B_0X1                               (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK9_ACKM_B_0X0                                 (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK9_ACKM_B_0X1                                 (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK9_NAKM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK9_NAKM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK9_STALLM_B_0X0                               (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK9_STALLM_B_0X1                               (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK9_CHHM_B_0X0                                 (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK9_CHHM_B_0X1                                 (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK9_XFRCM_B_0X0                                (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK9_XFRCM_B_0X1                                (0x1u<<0)

// OTG_HCTSIZ9 Configuration

#define OTG_FS_OTG_HCTSIZ9_DOPNG                                        (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ9_DPID                                         (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ9_DPID_0                                       (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ9_PKTCNT                                       (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ9_PKTCNT_0                                     (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ9_XFRSIZ                                       (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ9_XFRSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ9_DPID_B_0X0                                   (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ9_DPID_B_0X2                                   (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ9_DPID_B_0X3                                   (0x3u<<29)

// OTG_HCCHAR10 Configuration

#define OTG_FS_OTG_HCCHAR10_CHENA                                       (0x1u<<31)
#define OTG_FS_OTG_HCCHAR10_CHDIS                                       (0x1u<<30)
#define OTG_FS_OTG_HCCHAR10_ODDFRM                                      (0x1u<<29)
#define OTG_FS_OTG_HCCHAR10_DAD                                         (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR10_DAD_0                                       (0x1u<<22)
#define OTG_FS_OTG_HCCHAR10_MCNT                                        (0x3u<<20)
#define OTG_FS_OTG_HCCHAR10_MCNT_0                                      (0x1u<<20)
#define OTG_FS_OTG_HCCHAR10_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_HCCHAR10_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_HCCHAR10_LSDEV                                       (0x1u<<17)
#define OTG_FS_OTG_HCCHAR10_EPDIR                                       (0x1u<<15)
#define OTG_FS_OTG_HCCHAR10_EPNUM                                       (0xFu<<11)
#define OTG_FS_OTG_HCCHAR10_EPNUM_0                                     (0x1u<<11)
#define OTG_FS_OTG_HCCHAR10_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR10_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCCHAR10_CHENA_B_0X0                                 (0x0u<<31)
#define OTG_FS_OTG_HCCHAR10_CHENA_B_0X1                                 (0x1u<<31)
#define OTG_FS_OTG_HCCHAR10_ODDFRM_B_0X0                                (0x0u<<29)
#define OTG_FS_OTG_HCCHAR10_ODDFRM_B_0X1                                (0x1u<<29)
#define OTG_FS_OTG_HCCHAR10_MCNT_B_0X0                                  (0x0u<<20)
#define OTG_FS_OTG_HCCHAR10_MCNT_B_0X1                                  (0x1u<<20)
#define OTG_FS_OTG_HCCHAR10_MCNT_B_0X2                                  (0x2u<<20)
#define OTG_FS_OTG_HCCHAR10_MCNT_B_0X3                                  (0x3u<<20)
#define OTG_FS_OTG_HCCHAR10_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_HCCHAR10_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_HCCHAR10_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_HCCHAR10_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_HCCHAR10_EPDIR_B_0X0                                 (0x0u<<15)
#define OTG_FS_OTG_HCCHAR10_EPDIR_B_0X1                                 (0x1u<<15)

// OTG_HCINT10 Configuration

#define OTG_FS_OTG_HCINT10_DTERR                                        (0x1u<<10)
#define OTG_FS_OTG_HCINT10_FRMOR                                        (0x1u<<9)
#define OTG_FS_OTG_HCINT10_BBERR                                        (0x1u<<8)
#define OTG_FS_OTG_HCINT10_TXERR                                        (0x1u<<7)
#define OTG_FS_OTG_HCINT10_ACK                                          (0x1u<<5)
#define OTG_FS_OTG_HCINT10_NAK                                          (0x1u<<4)
#define OTG_FS_OTG_HCINT10_STALL                                        (0x1u<<3)
#define OTG_FS_OTG_HCINT10_CHH                                          (0x1u<<1)
#define OTG_FS_OTG_HCINT10_XFRC                                         (0x1u<<0)

// OTG_HCINTMSK10 Configuration

#define OTG_FS_OTG_HCINTMSK10_DTERRM                                    (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK10_FRMORM                                    (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK10_BBERRM                                    (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK10_TXERRM                                    (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK10_ACKM                                      (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK10_NAKM                                      (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK10_STALLM                                    (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK10_CHHM                                      (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK10_XFRCM                                     (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK10_DTERRM_B_0X0                              (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK10_DTERRM_B_0X1                              (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK10_FRMORM_B_0X0                              (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK10_FRMORM_B_0X1                              (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK10_BBERRM_B_0X0                              (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK10_BBERRM_B_0X1                              (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK10_TXERRM_B_0X0                              (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK10_TXERRM_B_0X1                              (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK10_ACKM_B_0X0                                (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK10_ACKM_B_0X1                                (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK10_NAKM_B_0X0                                (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK10_NAKM_B_0X1                                (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK10_STALLM_B_0X0                              (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK10_STALLM_B_0X1                              (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK10_CHHM_B_0X0                                (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK10_CHHM_B_0X1                                (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK10_XFRCM_B_0X0                               (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK10_XFRCM_B_0X1                               (0x1u<<0)

// OTG_HCTSIZ10 Configuration

#define OTG_FS_OTG_HCTSIZ10_DOPNG                                       (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ10_DPID                                        (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ10_DPID_0                                      (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ10_PKTCNT                                      (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ10_PKTCNT_0                                    (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ10_XFRSIZ                                      (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ10_XFRSIZ_0                                    (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ10_DPID_B_0X0                                  (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ10_DPID_B_0X2                                  (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ10_DPID_B_0X3                                  (0x3u<<29)

// OTG_HCCHAR11 Configuration

#define OTG_FS_OTG_HCCHAR11_CHENA                                       (0x1u<<31)
#define OTG_FS_OTG_HCCHAR11_CHDIS                                       (0x1u<<30)
#define OTG_FS_OTG_HCCHAR11_ODDFRM                                      (0x1u<<29)
#define OTG_FS_OTG_HCCHAR11_DAD                                         (0x7Fu<<22)
#define OTG_FS_OTG_HCCHAR11_DAD_0                                       (0x1u<<22)
#define OTG_FS_OTG_HCCHAR11_MCNT                                        (0x3u<<20)
#define OTG_FS_OTG_HCCHAR11_MCNT_0                                      (0x1u<<20)
#define OTG_FS_OTG_HCCHAR11_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_HCCHAR11_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_HCCHAR11_LSDEV                                       (0x1u<<17)
#define OTG_FS_OTG_HCCHAR11_EPDIR                                       (0x1u<<15)
#define OTG_FS_OTG_HCCHAR11_EPNUM                                       (0xFu<<11)
#define OTG_FS_OTG_HCCHAR11_EPNUM_0                                     (0x1u<<11)
#define OTG_FS_OTG_HCCHAR11_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_HCCHAR11_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_HCCHAR11_CHENA_B_0X0                                 (0x0u<<31)
#define OTG_FS_OTG_HCCHAR11_CHENA_B_0X1                                 (0x1u<<31)
#define OTG_FS_OTG_HCCHAR11_ODDFRM_B_0X0                                (0x0u<<29)
#define OTG_FS_OTG_HCCHAR11_ODDFRM_B_0X1                                (0x1u<<29)
#define OTG_FS_OTG_HCCHAR11_MCNT_B_0X0                                  (0x0u<<20)
#define OTG_FS_OTG_HCCHAR11_MCNT_B_0X1                                  (0x1u<<20)
#define OTG_FS_OTG_HCCHAR11_MCNT_B_0X2                                  (0x2u<<20)
#define OTG_FS_OTG_HCCHAR11_MCNT_B_0X3                                  (0x3u<<20)
#define OTG_FS_OTG_HCCHAR11_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_HCCHAR11_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_HCCHAR11_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_HCCHAR11_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_HCCHAR11_EPDIR_B_0X0                                 (0x0u<<15)
#define OTG_FS_OTG_HCCHAR11_EPDIR_B_0X1                                 (0x1u<<15)

// OTG_HCINT11 Configuration

#define OTG_FS_OTG_HCINT11_DTERR                                        (0x1u<<10)
#define OTG_FS_OTG_HCINT11_FRMOR                                        (0x1u<<9)
#define OTG_FS_OTG_HCINT11_BBERR                                        (0x1u<<8)
#define OTG_FS_OTG_HCINT11_TXERR                                        (0x1u<<7)
#define OTG_FS_OTG_HCINT11_ACK                                          (0x1u<<5)
#define OTG_FS_OTG_HCINT11_NAK                                          (0x1u<<4)
#define OTG_FS_OTG_HCINT11_STALL                                        (0x1u<<3)
#define OTG_FS_OTG_HCINT11_CHH                                          (0x1u<<1)
#define OTG_FS_OTG_HCINT11_XFRC                                         (0x1u<<0)

// OTG_HCINTMSK11 Configuration

#define OTG_FS_OTG_HCINTMSK11_DTERRM                                    (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK11_FRMORM                                    (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK11_BBERRM                                    (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK11_TXERRM                                    (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK11_ACKM                                      (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK11_NAKM                                      (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK11_STALLM                                    (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK11_CHHM                                      (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK11_XFRCM                                     (0x1u<<0)

#define OTG_FS_OTG_HCINTMSK11_DTERRM_B_0X0                              (0x0u<<10)
#define OTG_FS_OTG_HCINTMSK11_DTERRM_B_0X1                              (0x1u<<10)
#define OTG_FS_OTG_HCINTMSK11_FRMORM_B_0X0                              (0x0u<<9)
#define OTG_FS_OTG_HCINTMSK11_FRMORM_B_0X1                              (0x1u<<9)
#define OTG_FS_OTG_HCINTMSK11_BBERRM_B_0X0                              (0x0u<<8)
#define OTG_FS_OTG_HCINTMSK11_BBERRM_B_0X1                              (0x1u<<8)
#define OTG_FS_OTG_HCINTMSK11_TXERRM_B_0X0                              (0x0u<<7)
#define OTG_FS_OTG_HCINTMSK11_TXERRM_B_0X1                              (0x1u<<7)
#define OTG_FS_OTG_HCINTMSK11_ACKM_B_0X0                                (0x0u<<5)
#define OTG_FS_OTG_HCINTMSK11_ACKM_B_0X1                                (0x1u<<5)
#define OTG_FS_OTG_HCINTMSK11_NAKM_B_0X0                                (0x0u<<4)
#define OTG_FS_OTG_HCINTMSK11_NAKM_B_0X1                                (0x1u<<4)
#define OTG_FS_OTG_HCINTMSK11_STALLM_B_0X0                              (0x0u<<3)
#define OTG_FS_OTG_HCINTMSK11_STALLM_B_0X1                              (0x1u<<3)
#define OTG_FS_OTG_HCINTMSK11_CHHM_B_0X0                                (0x0u<<1)
#define OTG_FS_OTG_HCINTMSK11_CHHM_B_0X1                                (0x1u<<1)
#define OTG_FS_OTG_HCINTMSK11_XFRCM_B_0X0                               (0x0u<<0)
#define OTG_FS_OTG_HCINTMSK11_XFRCM_B_0X1                               (0x1u<<0)

// OTG_HCTSIZ11 Configuration

#define OTG_FS_OTG_HCTSIZ11_DOPNG                                       (0x1u<<31)
#define OTG_FS_OTG_HCTSIZ11_DPID                                        (0x3u<<29)
#define OTG_FS_OTG_HCTSIZ11_DPID_0                                      (0x1u<<29)
#define OTG_FS_OTG_HCTSIZ11_PKTCNT                                      (0x3FFu<<19)
#define OTG_FS_OTG_HCTSIZ11_PKTCNT_0                                    (0x1u<<19)
#define OTG_FS_OTG_HCTSIZ11_XFRSIZ                                      (0x7FFFFu<<0)
#define OTG_FS_OTG_HCTSIZ11_XFRSIZ_0                                    (0x1u<<0)

#define OTG_FS_OTG_HCTSIZ11_DPID_B_0X0                                  (0x0u<<29)
#define OTG_FS_OTG_HCTSIZ11_DPID_B_0X2                                  (0x2u<<29)
#define OTG_FS_OTG_HCTSIZ11_DPID_B_0X3                                  (0x3u<<29)

// OTG_DCFG Configuration

#define OTG_FS_OTG_DCFG_ERRATIM                                         (0x1u<<15)
#define OTG_FS_OTG_DCFG_PFIVL                                           (0x3u<<11)
#define OTG_FS_OTG_DCFG_PFIVL_0                                         (0x1u<<11)
#define OTG_FS_OTG_DCFG_DAD                                             (0x7Fu<<4)
#define OTG_FS_OTG_DCFG_DAD_0                                           (0x1u<<4)
#define OTG_FS_OTG_DCFG_NZLSOHSK                                        (0x1u<<2)
#define OTG_FS_OTG_DCFG_DSPD                                            (0x3u<<0)
#define OTG_FS_OTG_DCFG_DSPD_0                                          (0x1u<<0)

#define OTG_FS_OTG_DCFG_ERRATIM_B_0X1                                   (0x1u<<15)
#define OTG_FS_OTG_DCFG_ERRATIM_B_0X0                                   (0x0u<<15)
#define OTG_FS_OTG_DCFG_PFIVL_B_0X0                                     (0x0u<<11)
#define OTG_FS_OTG_DCFG_PFIVL_B_0X1                                     (0x1u<<11)
#define OTG_FS_OTG_DCFG_PFIVL_B_0X2                                     (0x2u<<11)
#define OTG_FS_OTG_DCFG_PFIVL_B_0X3                                     (0x3u<<11)
#define OTG_FS_OTG_DCFG_NZLSOHSK_B_0X1                                  (0x1u<<2)
#define OTG_FS_OTG_DCFG_NZLSOHSK_B_0X0                                  (0x0u<<2)
#define OTG_FS_OTG_DCFG_DSPD_B_0X3                                      (0x3u<<0)

// OTG_DCTL Configuration

#define OTG_FS_OTG_DCTL_DSBESLRJCT                                      (0x1u<<18)
#define OTG_FS_OTG_DCTL_POPRGDNE                                        (0x1u<<11)
#define OTG_FS_OTG_DCTL_CGONAK                                          (0x1u<<10)
#define OTG_FS_OTG_DCTL_SGONAK                                          (0x1u<<9)
#define OTG_FS_OTG_DCTL_CGINAK                                          (0x1u<<8)
#define OTG_FS_OTG_DCTL_SGINAK                                          (0x1u<<7)
#define OTG_FS_OTG_DCTL_TCTL                                            (0x7u<<4)
#define OTG_FS_OTG_DCTL_TCTL_0                                          (0x1u<<4)
#define OTG_FS_OTG_DCTL_GONSTS                                          (0x1u<<3)
#define OTG_FS_OTG_DCTL_GINSTS                                          (0x1u<<2)
#define OTG_FS_OTG_DCTL_SDIS                                            (0x1u<<1)
#define OTG_FS_OTG_DCTL_RWUSIG                                          (0x1u<<0)

#define OTG_FS_OTG_DCTL_TCTL_B_0X0                                      (0x0u<<4)
#define OTG_FS_OTG_DCTL_TCTL_B_0X1                                      (0x1u<<4)
#define OTG_FS_OTG_DCTL_TCTL_B_0X2                                      (0x2u<<4)
#define OTG_FS_OTG_DCTL_TCTL_B_0X3                                      (0x3u<<4)
#define OTG_FS_OTG_DCTL_TCTL_B_0X4                                      (0x4u<<4)
#define OTG_FS_OTG_DCTL_TCTL_B_0X5                                      (0x5u<<4)
#define OTG_FS_OTG_DCTL_GONSTS_B_0X0                                    (0x0u<<3)
#define OTG_FS_OTG_DCTL_GONSTS_B_0X1                                    (0x1u<<3)
#define OTG_FS_OTG_DCTL_GINSTS_B_0X0                                    (0x0u<<2)
#define OTG_FS_OTG_DCTL_GINSTS_B_0X1                                    (0x1u<<2)
#define OTG_FS_OTG_DCTL_SDIS_B_0X0                                      (0x0u<<1)
#define OTG_FS_OTG_DCTL_SDIS_B_0X1                                      (0x1u<<1)

// OTG_DSTS Configuration

#define OTG_FS_OTG_DSTS_DEVLNSTS                                        (0x3u<<22)
#define OTG_FS_OTG_DSTS_DEVLNSTS_0                                      (0x1u<<22)
#define OTG_FS_OTG_DSTS_FNSOF                                           (0x3FFFu<<8)
#define OTG_FS_OTG_DSTS_FNSOF_0                                         (0x1u<<8)
#define OTG_FS_OTG_DSTS_EERR                                            (0x1u<<3)
#define OTG_FS_OTG_DSTS_ENUMSPD                                         (0x3u<<1)
#define OTG_FS_OTG_DSTS_ENUMSPD_0                                       (0x1u<<1)
#define OTG_FS_OTG_DSTS_SUSPSTS                                         (0x1u<<0)

#define OTG_FS_OTG_DSTS_ENUMSPD_B_0X3                                   (0x3u<<1)

// OTG_DIEPMSK Configuration

#define OTG_FS_OTG_DIEPMSK_NAKM                                         (0x1u<<13)
#define OTG_FS_OTG_DIEPMSK_INEPNEM                                      (0x1u<<6)
#define OTG_FS_OTG_DIEPMSK_INEPNMM                                      (0x1u<<5)
#define OTG_FS_OTG_DIEPMSK_ITTXFEMSK                                    (0x1u<<4)
#define OTG_FS_OTG_DIEPMSK_TOM                                          (0x1u<<3)
#define OTG_FS_OTG_DIEPMSK_EPDM                                         (0x1u<<1)
#define OTG_FS_OTG_DIEPMSK_XFRCM                                        (0x1u<<0)

#define OTG_FS_OTG_DIEPMSK_NAKM_B_0X0                                   (0x0u<<13)
#define OTG_FS_OTG_DIEPMSK_NAKM_B_0X1                                   (0x1u<<13)
#define OTG_FS_OTG_DIEPMSK_INEPNEM_B_0X0                                (0x0u<<6)
#define OTG_FS_OTG_DIEPMSK_INEPNEM_B_0X1                                (0x1u<<6)
#define OTG_FS_OTG_DIEPMSK_INEPNMM_B_0X0                                (0x0u<<5)
#define OTG_FS_OTG_DIEPMSK_INEPNMM_B_0X1                                (0x1u<<5)
#define OTG_FS_OTG_DIEPMSK_ITTXFEMSK_B_0X0                              (0x0u<<4)
#define OTG_FS_OTG_DIEPMSK_ITTXFEMSK_B_0X1                              (0x1u<<4)
#define OTG_FS_OTG_DIEPMSK_TOM_B_0X0                                    (0x0u<<3)
#define OTG_FS_OTG_DIEPMSK_TOM_B_0X1                                    (0x1u<<3)
#define OTG_FS_OTG_DIEPMSK_EPDM_B_0X0                                   (0x0u<<1)
#define OTG_FS_OTG_DIEPMSK_EPDM_B_0X1                                   (0x1u<<1)
#define OTG_FS_OTG_DIEPMSK_XFRCM_B_0X0                                  (0x0u<<0)
#define OTG_FS_OTG_DIEPMSK_XFRCM_B_0X1                                  (0x1u<<0)

// OTG_DOEPMSK Configuration

#define OTG_FS_OTG_DOEPMSK_NAKMSK                                       (0x1u<<13)
#define OTG_FS_OTG_DOEPMSK_BERRM                                        (0x1u<<12)
#define OTG_FS_OTG_DOEPMSK_OUTPKTERRM                                   (0x1u<<8)
#define OTG_FS_OTG_DOEPMSK_STSPHSRXM                                    (0x1u<<5)
#define OTG_FS_OTG_DOEPMSK_OTEPDM                                       (0x1u<<4)
#define OTG_FS_OTG_DOEPMSK_STUPM                                        (0x1u<<3)
#define OTG_FS_OTG_DOEPMSK_EPDM                                         (0x1u<<1)
#define OTG_FS_OTG_DOEPMSK_XFRCM                                        (0x1u<<0)

#define OTG_FS_OTG_DOEPMSK_NAKMSK_B_0X0                                 (0x0u<<13)
#define OTG_FS_OTG_DOEPMSK_NAKMSK_B_0X1                                 (0x1u<<13)
#define OTG_FS_OTG_DOEPMSK_BERRM_B_0X0                                  (0x0u<<12)
#define OTG_FS_OTG_DOEPMSK_BERRM_B_0X1                                  (0x1u<<12)
#define OTG_FS_OTG_DOEPMSK_OUTPKTERRM_B_0X0                             (0x0u<<8)
#define OTG_FS_OTG_DOEPMSK_OUTPKTERRM_B_0X1                             (0x1u<<8)
#define OTG_FS_OTG_DOEPMSK_STSPHSRXM_B_0X0                              (0x0u<<5)
#define OTG_FS_OTG_DOEPMSK_STSPHSRXM_B_0X1                              (0x1u<<5)
#define OTG_FS_OTG_DOEPMSK_OTEPDM_B_0X0                                 (0x0u<<4)
#define OTG_FS_OTG_DOEPMSK_OTEPDM_B_0X1                                 (0x1u<<4)
#define OTG_FS_OTG_DOEPMSK_STUPM_B_0X0                                  (0x0u<<3)
#define OTG_FS_OTG_DOEPMSK_STUPM_B_0X1                                  (0x1u<<3)
#define OTG_FS_OTG_DOEPMSK_EPDM_B_0X0                                   (0x0u<<1)
#define OTG_FS_OTG_DOEPMSK_EPDM_B_0X1                                   (0x1u<<1)
#define OTG_FS_OTG_DOEPMSK_XFRCM_B_0X0                                  (0x0u<<0)
#define OTG_FS_OTG_DOEPMSK_XFRCM_B_0X1                                  (0x1u<<0)

// OTG_DAINT Configuration

#define OTG_FS_OTG_DAINT_OEPINT                                         (0xFFFFu<<16)
#define OTG_FS_OTG_DAINT_OEPINT_0                                       (0x1u<<16)
#define OTG_FS_OTG_DAINT_IEPINT                                         (0xFFFFu<<0)
#define OTG_FS_OTG_DAINT_IEPINT_0                                       (0x1u<<0)

// OTG_DAINTMSK Configuration

#define OTG_FS_OTG_DAINTMSK_OEPM                                        (0xFFFFu<<16)
#define OTG_FS_OTG_DAINTMSK_OEPM_0                                      (0x1u<<16)
#define OTG_FS_OTG_DAINTMSK_IEPM                                        (0xFFFFu<<0)
#define OTG_FS_OTG_DAINTMSK_IEPM_0                                      (0x1u<<0)

#define OTG_FS_OTG_DAINTMSK_OEPM_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DAINTMSK_OEPM_B_0X1                                  (0x1u<<16)
#define OTG_FS_OTG_DAINTMSK_IEPM_B_0X0                                  (0x0u<<0)
#define OTG_FS_OTG_DAINTMSK_IEPM_B_0X1                                  (0x1u<<0)

// OTG_DIEPEMPMSK Configuration

#define OTG_FS_OTG_DIEPEMPMSK_INEPTXFEM                                 (0xFFFFu<<0)
#define OTG_FS_OTG_DIEPEMPMSK_INEPTXFEM_0                               (0x1u<<0)

#define OTG_FS_OTG_DIEPEMPMSK_INEPTXFEM_B_0X0                           (0x0u<<0)
#define OTG_FS_OTG_DIEPEMPMSK_INEPTXFEM_B_0X1                           (0x1u<<0)

// OTG_DEACHINT Configuration

#define OTG_FS_OTG_DEACHINT_OEP1INT                                     (0x1u<<17)
#define OTG_FS_OTG_DEACHINT_IEP1INT                                     (0x1u<<1)

// OTG_DEACHINTMSK Configuration

#define OTG_FS_OTG_DEACHINTMSK_OEP1INTM                                 (0x1u<<17)
#define OTG_FS_OTG_DEACHINTMSK_IEP1INTM                                 (0x1u<<1)

// OTG_HS_DIEPEACHMSK1 Configuration

#define OTG_FS_OTG_HS_DIEPEACHMSK1_NAKM                                 (0x1u<<13)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_TXFURM                               (0x1u<<8)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_INEPNEM                              (0x1u<<6)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_ITTXFEMSK                            (0x1u<<4)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_TOM                                  (0x1u<<3)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_AHBERRM                              (0x1u<<2)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_EPDM                                 (0x1u<<1)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_XFRCM                                (0x1u<<0)

#define OTG_FS_OTG_HS_DIEPEACHMSK1_NAKM_B_0X0                           (0x0u<<13)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_NAKM_B_0X1                           (0x1u<<13)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_TXFURM_B_0X0                         (0x0u<<8)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_TXFURM_B_0X1                         (0x1u<<8)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_INEPNEM_B_0X0                        (0x0u<<6)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_INEPNEM_B_0X1                        (0x1u<<6)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_ITTXFEMSK_B_0X0                      (0x0u<<4)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_ITTXFEMSK_B_0X1                      (0x1u<<4)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_TOM_B_0X0                            (0x0u<<3)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_TOM_B_0X1                            (0x1u<<3)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_AHBERRM_B_0X0                        (0x0u<<2)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_AHBERRM_B_0X1                        (0x1u<<2)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_EPDM_B_0X0                           (0x0u<<1)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_EPDM_B_0X1                           (0x1u<<1)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_XFRCM_B_0X0                          (0x0u<<0)
#define OTG_FS_OTG_HS_DIEPEACHMSK1_XFRCM_B_0X1                          (0x1u<<0)

// OTG_HS_DOEPEACHMSK1 Configuration

#define OTG_FS_OTG_HS_DOEPEACHMSK1_NYETMSK                              (0x1u<<14)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_NAKMSK                               (0x1u<<13)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_BERRM                                (0x1u<<12)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_OUTPKTERRM                           (0x1u<<8)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_B2BSTUPM                             (0x1u<<6)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_OTEPDM                               (0x1u<<4)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_STUPM                                (0x1u<<3)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_AHBERRM                              (0x1u<<2)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_EPDM                                 (0x1u<<1)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_XFRCM                                (0x1u<<0)

#define OTG_FS_OTG_HS_DOEPEACHMSK1_NYETMSK_B_0X0                        (0x0u<<14)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_NYETMSK_B_0X1                        (0x1u<<14)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_NAKMSK_B_0X0                         (0x0u<<13)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_NAKMSK_B_0X1                         (0x1u<<13)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_BERRM_B_0X0                          (0x0u<<12)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_BERRM_B_0X1                          (0x1u<<12)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_OUTPKTERRM_B_0X0                     (0x0u<<8)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_OUTPKTERRM_B_0X1                     (0x1u<<8)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_B2BSTUPM_B_0X0                       (0x0u<<6)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_B2BSTUPM_B_0X1                       (0x1u<<6)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_OTEPDM_B_0X0                         (0x0u<<4)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_OTEPDM_B_0X1                         (0x1u<<4)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_STUPM_B_0X0                          (0x0u<<3)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_STUPM_B_0X1                          (0x1u<<3)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_AHBERRM_B_0X0                        (0x0u<<2)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_AHBERRM_B_0X1                        (0x1u<<2)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_EPDM_B_0X0                           (0x0u<<1)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_EPDM_B_0X1                           (0x1u<<1)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_XFRCM_B_0X0                          (0x0u<<0)
#define OTG_FS_OTG_HS_DOEPEACHMSK1_XFRCM_B_0X1                          (0x1u<<0)

// OTG_DIEPCTL0 Configuration

#define OTG_FS_OTG_DIEPCTL0_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL0_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL0_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL0_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL0_TXFNUM                                      (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL0_TXFNUM_0                                    (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL0_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL0_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL0_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL0_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL0_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL0_MPSIZ                                       (0x3u<<0)
#define OTG_FS_OTG_DIEPCTL0_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL0_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL0_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL0_MPSIZ_B_0X0                                 (0x0u<<0)
#define OTG_FS_OTG_DIEPCTL0_MPSIZ_B_0X1                                 (0x1u<<0)
#define OTG_FS_OTG_DIEPCTL0_MPSIZ_B_0X2                                 (0x2u<<0)
#define OTG_FS_OTG_DIEPCTL0_MPSIZ_B_0X3                                 (0x3u<<0)

// OTG_DIEPINT0 Configuration

#define OTG_FS_OTG_DIEPINT0_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DIEPINT0_PKTDRPSTS                                   (0x1u<<11)
#define OTG_FS_OTG_DIEPINT0_TXFE                                        (0x1u<<7)
#define OTG_FS_OTG_DIEPINT0_INEPNE                                      (0x1u<<6)
#define OTG_FS_OTG_DIEPINT0_INEPNM                                      (0x1u<<5)
#define OTG_FS_OTG_DIEPINT0_ITTXFE                                      (0x1u<<4)
#define OTG_FS_OTG_DIEPINT0_TOC                                         (0x1u<<3)
#define OTG_FS_OTG_DIEPINT0_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DIEPINT0_XFRC                                        (0x1u<<0)

// OTG_DIEPTSIZ0 Configuration

#define OTG_FS_OTG_DIEPTSIZ0_PKTCNT                                     (0x3u<<19)
#define OTG_FS_OTG_DIEPTSIZ0_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DIEPTSIZ0_XFRSIZ                                     (0x7Fu<<0)
#define OTG_FS_OTG_DIEPTSIZ0_XFRSIZ_0                                   (0x1u<<0)

// OTG_DTXFSTS0 Configuration

#define OTG_FS_OTG_DTXFSTS0_INEPTFSAV                                   (0xFFFFu<<0)
#define OTG_FS_OTG_DTXFSTS0_INEPTFSAV_0                                 (0x1u<<0)

#define OTG_FS_OTG_DTXFSTS0_INEPTFSAV_B_0X0                             (0x0u<<0)
#define OTG_FS_OTG_DTXFSTS0_INEPTFSAV_B_0X1                             (0x1u<<0)

// OTG_DIEPCTL1 Configuration

#define OTG_FS_OTG_DIEPCTL1_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL1_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL1_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL1_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL1_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL1_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL1_TXFNUM                                      (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL1_TXFNUM_0                                    (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL1_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL1_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL1_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL1_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL1_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL1_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL1_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL1_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL1_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL1_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL1_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL1_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL1_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL1_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL1_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL1_DPID_B_0X1                                  (0x1u<<16)

// OTG_DIEPCTL1_ALTERNATE1 Configuration

#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_TXFNUM                           (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_TXFNUM_0                         (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL1_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DIEPINT1 Configuration

#define OTG_FS_OTG_DIEPINT1_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DIEPINT1_PKTDRPSTS                                   (0x1u<<11)
#define OTG_FS_OTG_DIEPINT1_TXFE                                        (0x1u<<7)
#define OTG_FS_OTG_DIEPINT1_INEPNE                                      (0x1u<<6)
#define OTG_FS_OTG_DIEPINT1_INEPNM                                      (0x1u<<5)
#define OTG_FS_OTG_DIEPINT1_ITTXFE                                      (0x1u<<4)
#define OTG_FS_OTG_DIEPINT1_TOC                                         (0x1u<<3)
#define OTG_FS_OTG_DIEPINT1_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DIEPINT1_XFRC                                        (0x1u<<0)

// OTG_DIEPTSIZ1 Configuration

#define OTG_FS_OTG_DIEPTSIZ1_MCNT                                       (0x3u<<29)
#define OTG_FS_OTG_DIEPTSIZ1_MCNT_0                                     (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ1_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DIEPTSIZ1_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DIEPTSIZ1_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DIEPTSIZ1_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DIEPTSIZ1_MCNT_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ1_MCNT_B_0X2                                 (0x2u<<29)
#define OTG_FS_OTG_DIEPTSIZ1_MCNT_B_0X3                                 (0x3u<<29)

// OTG_DTXFSTS1 Configuration

#define OTG_FS_OTG_DTXFSTS1_INEPTFSAV                                   (0xFFFFu<<0)
#define OTG_FS_OTG_DTXFSTS1_INEPTFSAV_0                                 (0x1u<<0)

#define OTG_FS_OTG_DTXFSTS1_INEPTFSAV_B_0X0                             (0x0u<<0)
#define OTG_FS_OTG_DTXFSTS1_INEPTFSAV_B_0X1                             (0x1u<<0)

// OTG_DIEPCTL2 Configuration

#define OTG_FS_OTG_DIEPCTL2_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL2_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL2_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL2_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL2_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL2_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL2_TXFNUM                                      (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL2_TXFNUM_0                                    (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL2_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL2_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL2_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL2_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL2_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL2_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL2_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL2_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL2_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL2_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL2_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL2_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL2_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL2_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL2_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL2_DPID_B_0X1                                  (0x1u<<16)

// OTG_DIEPCTL2_ALTERNATE1 Configuration

#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_TXFNUM                           (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_TXFNUM_0                         (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL2_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DIEPINT2 Configuration

#define OTG_FS_OTG_DIEPINT2_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DIEPINT2_PKTDRPSTS                                   (0x1u<<11)
#define OTG_FS_OTG_DIEPINT2_TXFE                                        (0x1u<<7)
#define OTG_FS_OTG_DIEPINT2_INEPNE                                      (0x1u<<6)
#define OTG_FS_OTG_DIEPINT2_INEPNM                                      (0x1u<<5)
#define OTG_FS_OTG_DIEPINT2_ITTXFE                                      (0x1u<<4)
#define OTG_FS_OTG_DIEPINT2_TOC                                         (0x1u<<3)
#define OTG_FS_OTG_DIEPINT2_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DIEPINT2_XFRC                                        (0x1u<<0)

// OTG_DIEPTSIZ2 Configuration

#define OTG_FS_OTG_DIEPTSIZ2_MCNT                                       (0x3u<<29)
#define OTG_FS_OTG_DIEPTSIZ2_MCNT_0                                     (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ2_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DIEPTSIZ2_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DIEPTSIZ2_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DIEPTSIZ2_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DIEPTSIZ2_MCNT_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ2_MCNT_B_0X2                                 (0x2u<<29)
#define OTG_FS_OTG_DIEPTSIZ2_MCNT_B_0X3                                 (0x3u<<29)

// OTG_DTXFSTS2 Configuration

#define OTG_FS_OTG_DTXFSTS2_INEPTFSAV                                   (0xFFFFu<<0)
#define OTG_FS_OTG_DTXFSTS2_INEPTFSAV_0                                 (0x1u<<0)

#define OTG_FS_OTG_DTXFSTS2_INEPTFSAV_B_0X0                             (0x0u<<0)
#define OTG_FS_OTG_DTXFSTS2_INEPTFSAV_B_0X1                             (0x1u<<0)

// OTG_DIEPCTL3 Configuration

#define OTG_FS_OTG_DIEPCTL3_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL3_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL3_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL3_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL3_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL3_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL3_TXFNUM                                      (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL3_TXFNUM_0                                    (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL3_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL3_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL3_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL3_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL3_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL3_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL3_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL3_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL3_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL3_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL3_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL3_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL3_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL3_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL3_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL3_DPID_B_0X1                                  (0x1u<<16)

// OTG_DIEPCTL3_ALTERNATE1 Configuration

#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_TXFNUM                           (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_TXFNUM_0                         (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL3_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DIEPINT3 Configuration

#define OTG_FS_OTG_DIEPINT3_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DIEPINT3_PKTDRPSTS                                   (0x1u<<11)
#define OTG_FS_OTG_DIEPINT3_TXFE                                        (0x1u<<7)
#define OTG_FS_OTG_DIEPINT3_INEPNE                                      (0x1u<<6)
#define OTG_FS_OTG_DIEPINT3_INEPNM                                      (0x1u<<5)
#define OTG_FS_OTG_DIEPINT3_ITTXFE                                      (0x1u<<4)
#define OTG_FS_OTG_DIEPINT3_TOC                                         (0x1u<<3)
#define OTG_FS_OTG_DIEPINT3_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DIEPINT3_XFRC                                        (0x1u<<0)

// OTG_DIEPTSIZ3 Configuration

#define OTG_FS_OTG_DIEPTSIZ3_MCNT                                       (0x3u<<29)
#define OTG_FS_OTG_DIEPTSIZ3_MCNT_0                                     (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ3_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DIEPTSIZ3_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DIEPTSIZ3_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DIEPTSIZ3_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DIEPTSIZ3_MCNT_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ3_MCNT_B_0X2                                 (0x2u<<29)
#define OTG_FS_OTG_DIEPTSIZ3_MCNT_B_0X3                                 (0x3u<<29)

// OTG_DTXFSTS3 Configuration

#define OTG_FS_OTG_DTXFSTS3_INEPTFSAV                                   (0xFFFFu<<0)
#define OTG_FS_OTG_DTXFSTS3_INEPTFSAV_0                                 (0x1u<<0)

#define OTG_FS_OTG_DTXFSTS3_INEPTFSAV_B_0X0                             (0x0u<<0)
#define OTG_FS_OTG_DTXFSTS3_INEPTFSAV_B_0X1                             (0x1u<<0)

// OTG_DIEPCTL4 Configuration

#define OTG_FS_OTG_DIEPCTL4_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL4_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL4_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL4_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL4_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL4_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL4_TXFNUM                                      (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL4_TXFNUM_0                                    (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL4_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL4_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL4_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL4_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL4_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL4_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL4_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL4_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL4_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL4_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL4_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL4_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL4_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL4_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL4_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL4_DPID_B_0X1                                  (0x1u<<16)

// OTG_DIEPCTL4_ALTERNATE1 Configuration

#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_TXFNUM                           (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_TXFNUM_0                         (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL4_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DIEPINT4 Configuration

#define OTG_FS_OTG_DIEPINT4_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DIEPINT4_PKTDRPSTS                                   (0x1u<<11)
#define OTG_FS_OTG_DIEPINT4_TXFE                                        (0x1u<<7)
#define OTG_FS_OTG_DIEPINT4_INEPNE                                      (0x1u<<6)
#define OTG_FS_OTG_DIEPINT4_INEPNM                                      (0x1u<<5)
#define OTG_FS_OTG_DIEPINT4_ITTXFE                                      (0x1u<<4)
#define OTG_FS_OTG_DIEPINT4_TOC                                         (0x1u<<3)
#define OTG_FS_OTG_DIEPINT4_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DIEPINT4_XFRC                                        (0x1u<<0)

// OTG_DIEPTSIZ4 Configuration

#define OTG_FS_OTG_DIEPTSIZ4_MCNT                                       (0x3u<<29)
#define OTG_FS_OTG_DIEPTSIZ4_MCNT_0                                     (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ4_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DIEPTSIZ4_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DIEPTSIZ4_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DIEPTSIZ4_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DIEPTSIZ4_MCNT_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ4_MCNT_B_0X2                                 (0x2u<<29)
#define OTG_FS_OTG_DIEPTSIZ4_MCNT_B_0X3                                 (0x3u<<29)

// OTG_DTXFSTS4 Configuration

#define OTG_FS_OTG_DTXFSTS4_INEPTFSAV                                   (0xFFFFu<<0)
#define OTG_FS_OTG_DTXFSTS4_INEPTFSAV_0                                 (0x1u<<0)

#define OTG_FS_OTG_DTXFSTS4_INEPTFSAV_B_0X0                             (0x0u<<0)
#define OTG_FS_OTG_DTXFSTS4_INEPTFSAV_B_0X1                             (0x1u<<0)

// OTG_DIEPCTL5 Configuration

#define OTG_FS_OTG_DIEPCTL5_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL5_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL5_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL5_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL5_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL5_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL5_TXFNUM                                      (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL5_TXFNUM_0                                    (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL5_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL5_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL5_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL5_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL5_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL5_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL5_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL5_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL5_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL5_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL5_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL5_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL5_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL5_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL5_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL5_DPID_B_0X1                                  (0x1u<<16)

// OTG_DIEPCTL5_ALTERNATE1 Configuration

#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_TXFNUM                           (0xFu<<22)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_TXFNUM_0                         (0x1u<<22)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DIEPCTL5_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DIEPINT5 Configuration

#define OTG_FS_OTG_DIEPINT5_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DIEPINT5_PKTDRPSTS                                   (0x1u<<11)
#define OTG_FS_OTG_DIEPINT5_TXFE                                        (0x1u<<7)
#define OTG_FS_OTG_DIEPINT5_INEPNE                                      (0x1u<<6)
#define OTG_FS_OTG_DIEPINT5_INEPNM                                      (0x1u<<5)
#define OTG_FS_OTG_DIEPINT5_ITTXFE                                      (0x1u<<4)
#define OTG_FS_OTG_DIEPINT5_TOC                                         (0x1u<<3)
#define OTG_FS_OTG_DIEPINT5_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DIEPINT5_XFRC                                        (0x1u<<0)

// OTG_DIEPTSIZ5 Configuration

#define OTG_FS_OTG_DIEPTSIZ5_MCNT                                       (0x3u<<29)
#define OTG_FS_OTG_DIEPTSIZ5_MCNT_0                                     (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ5_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DIEPTSIZ5_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DIEPTSIZ5_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DIEPTSIZ5_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DIEPTSIZ5_MCNT_B_0X1                                 (0x1u<<29)
#define OTG_FS_OTG_DIEPTSIZ5_MCNT_B_0X2                                 (0x2u<<29)
#define OTG_FS_OTG_DIEPTSIZ5_MCNT_B_0X3                                 (0x3u<<29)

// OTG_DTXFSTS5 Configuration

#define OTG_FS_OTG_DTXFSTS5_INEPTFSAV                                   (0xFFFFu<<0)
#define OTG_FS_OTG_DTXFSTS5_INEPTFSAV_0                                 (0x1u<<0)

#define OTG_FS_OTG_DTXFSTS5_INEPTFSAV_B_0X0                             (0x0u<<0)
#define OTG_FS_OTG_DTXFSTS5_INEPTFSAV_B_0X1                             (0x1u<<0)

// OTG_DOEPCTL0 Configuration

#define OTG_FS_OTG_DOEPCTL0_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL0_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL0_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL0_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL0_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL0_SNPM                                        (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL0_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL0_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL0_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL0_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL0_MPSIZ                                       (0x3u<<0)
#define OTG_FS_OTG_DOEPCTL0_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL0_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL0_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL0_MPSIZ_B_0X0                                 (0x0u<<0)
#define OTG_FS_OTG_DOEPCTL0_MPSIZ_B_0X1                                 (0x1u<<0)
#define OTG_FS_OTG_DOEPCTL0_MPSIZ_B_0X2                                 (0x2u<<0)
#define OTG_FS_OTG_DOEPCTL0_MPSIZ_B_0X3                                 (0x3u<<0)

// OTG_DOEPINT0 Configuration

#define OTG_FS_OTG_DOEPINT0_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DOEPINT0_BERR                                        (0x1u<<12)
#define OTG_FS_OTG_DOEPINT0_STSPHSRX                                    (0x1u<<5)
#define OTG_FS_OTG_DOEPINT0_OTEPDIS                                     (0x1u<<4)
#define OTG_FS_OTG_DOEPINT0_STUP                                        (0x1u<<3)
#define OTG_FS_OTG_DOEPINT0_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DOEPINT0_XFRC                                        (0x1u<<0)

// OTG_DOEPTSIZ0 Configuration

#define OTG_FS_OTG_DOEPTSIZ0_STUPCNT                                    (0x3u<<29)
#define OTG_FS_OTG_DOEPTSIZ0_STUPCNT_0                                  (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ0_PKTCNT                                     (0x1u<<19)
#define OTG_FS_OTG_DOEPTSIZ0_XFRSIZ                                     (0x7Fu<<0)
#define OTG_FS_OTG_DOEPTSIZ0_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DOEPTSIZ0_STUPCNT_B_0X1                              (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ0_STUPCNT_B_0X2                              (0x2u<<29)
#define OTG_FS_OTG_DOEPTSIZ0_STUPCNT_B_0X3                              (0x3u<<29)

// OTG_DOEPCTL1 Configuration

#define OTG_FS_OTG_DOEPCTL1_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL1_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL1_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL1_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL1_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL1_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL1_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL1_SNPM                                        (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL1_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL1_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL1_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL1_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL1_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL1_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL1_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL1_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL1_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL1_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL1_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL1_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL1_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL1_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL1_DPID_B_0X1                                  (0x1u<<16)

// OTG_DOEPCTL1_ALTERNATE1 Configuration

#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_SNPM                             (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL1_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DOEPINT1 Configuration

#define OTG_FS_OTG_DOEPINT1_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DOEPINT1_BERR                                        (0x1u<<12)
#define OTG_FS_OTG_DOEPINT1_STSPHSRX                                    (0x1u<<5)
#define OTG_FS_OTG_DOEPINT1_OTEPDIS                                     (0x1u<<4)
#define OTG_FS_OTG_DOEPINT1_STUP                                        (0x1u<<3)
#define OTG_FS_OTG_DOEPINT1_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DOEPINT1_XFRC                                        (0x1u<<0)

// OTG_DOEPTSIZ1 Configuration

#define OTG_FS_OTG_DOEPTSIZ1_RXDPID                                     (0x3u<<29)
#define OTG_FS_OTG_DOEPTSIZ1_RXDPID_0                                   (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ1_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DOEPTSIZ1_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DOEPTSIZ1_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DOEPTSIZ1_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DOEPTSIZ1_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS     (0x0u<<29)
#define OTG_FS_OTG_DOEPTSIZ1_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS     (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ1_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS     (0x2u<<29)
#define OTG_FS_OTG_DOEPTSIZ1_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS     (0x3u<<29)

// OTG_DOEPCTL2 Configuration

#define OTG_FS_OTG_DOEPCTL2_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL2_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL2_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL2_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL2_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL2_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL2_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL2_SNPM                                        (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL2_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL2_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL2_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL2_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL2_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL2_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL2_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL2_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL2_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL2_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL2_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL2_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL2_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL2_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL2_DPID_B_0X1                                  (0x1u<<16)

// OTG_DOEPCTL2_ALTERNATE1 Configuration

#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_SNPM                             (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL2_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DOEPINT2 Configuration

#define OTG_FS_OTG_DOEPINT2_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DOEPINT2_BERR                                        (0x1u<<12)
#define OTG_FS_OTG_DOEPINT2_STSPHSRX                                    (0x1u<<5)
#define OTG_FS_OTG_DOEPINT2_OTEPDIS                                     (0x1u<<4)
#define OTG_FS_OTG_DOEPINT2_STUP                                        (0x1u<<3)
#define OTG_FS_OTG_DOEPINT2_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DOEPINT2_XFRC                                        (0x1u<<0)

// OTG_DOEPTSIZ2 Configuration

#define OTG_FS_OTG_DOEPTSIZ2_RXDPID                                     (0x3u<<29)
#define OTG_FS_OTG_DOEPTSIZ2_RXDPID_0                                   (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ2_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DOEPTSIZ2_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DOEPTSIZ2_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DOEPTSIZ2_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DOEPTSIZ2_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS     (0x0u<<29)
#define OTG_FS_OTG_DOEPTSIZ2_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS     (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ2_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS     (0x2u<<29)
#define OTG_FS_OTG_DOEPTSIZ2_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS     (0x3u<<29)

// OTG_DOEPCTL3 Configuration

#define OTG_FS_OTG_DOEPCTL3_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL3_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL3_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL3_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL3_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL3_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL3_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL3_SNPM                                        (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL3_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL3_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL3_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL3_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL3_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL3_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL3_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL3_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL3_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL3_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL3_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL3_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL3_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL3_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL3_DPID_B_0X1                                  (0x1u<<16)

// OTG_DOEPCTL3_ALTERNATE1 Configuration

#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_SNPM                             (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL3_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DOEPINT3 Configuration

#define OTG_FS_OTG_DOEPINT3_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DOEPINT3_BERR                                        (0x1u<<12)
#define OTG_FS_OTG_DOEPINT3_STSPHSRX                                    (0x1u<<5)
#define OTG_FS_OTG_DOEPINT3_OTEPDIS                                     (0x1u<<4)
#define OTG_FS_OTG_DOEPINT3_STUP                                        (0x1u<<3)
#define OTG_FS_OTG_DOEPINT3_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DOEPINT3_XFRC                                        (0x1u<<0)

// OTG_DOEPTSIZ3 Configuration

#define OTG_FS_OTG_DOEPTSIZ3_RXDPID                                     (0x3u<<29)
#define OTG_FS_OTG_DOEPTSIZ3_RXDPID_0                                   (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ3_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DOEPTSIZ3_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DOEPTSIZ3_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DOEPTSIZ3_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DOEPTSIZ3_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS     (0x0u<<29)
#define OTG_FS_OTG_DOEPTSIZ3_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS     (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ3_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS     (0x2u<<29)
#define OTG_FS_OTG_DOEPTSIZ3_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS     (0x3u<<29)

// OTG_DOEPCTL4 Configuration

#define OTG_FS_OTG_DOEPCTL4_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL4_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL4_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL4_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL4_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL4_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL4_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL4_SNPM                                        (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL4_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL4_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL4_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL4_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL4_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL4_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL4_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL4_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL4_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL4_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL4_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL4_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL4_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL4_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL4_DPID_B_0X1                                  (0x1u<<16)

// OTG_DOEPCTL4_ALTERNATE1 Configuration

#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_SNPM                             (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL4_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DOEPINT4 Configuration

#define OTG_FS_OTG_DOEPINT4_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DOEPINT4_BERR                                        (0x1u<<12)
#define OTG_FS_OTG_DOEPINT4_STSPHSRX                                    (0x1u<<5)
#define OTG_FS_OTG_DOEPINT4_OTEPDIS                                     (0x1u<<4)
#define OTG_FS_OTG_DOEPINT4_STUP                                        (0x1u<<3)
#define OTG_FS_OTG_DOEPINT4_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DOEPINT4_XFRC                                        (0x1u<<0)

// OTG_DOEPTSIZ4 Configuration

#define OTG_FS_OTG_DOEPTSIZ4_RXDPID                                     (0x3u<<29)
#define OTG_FS_OTG_DOEPTSIZ4_RXDPID_0                                   (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ4_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DOEPTSIZ4_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DOEPTSIZ4_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DOEPTSIZ4_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DOEPTSIZ4_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS     (0x0u<<29)
#define OTG_FS_OTG_DOEPTSIZ4_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS     (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ4_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS     (0x2u<<29)
#define OTG_FS_OTG_DOEPTSIZ4_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS     (0x3u<<29)

// OTG_DOEPCTL5 Configuration

#define OTG_FS_OTG_DOEPCTL5_EPENA                                       (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL5_EPDIS                                       (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL5_SD1PID                                      (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL5_SD0PID                                      (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL5_SNAK                                        (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL5_CNAK                                        (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL5_STALL                                       (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL5_SNPM                                        (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL5_EPTYP                                       (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL5_EPTYP_0                                     (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL5_NAKSTS                                      (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL5_DPID                                        (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL5_USBAEP                                      (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL5_MPSIZ                                       (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL5_MPSIZ_0                                     (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL5_EPTYP_B_0X0                                 (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL5_EPTYP_B_0X1                                 (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL5_EPTYP_B_0X2                                 (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL5_EPTYP_B_0X3                                 (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL5_NAKSTS_B_0X0                                (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL5_NAKSTS_B_0X1                                (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL5_DPID_B_0X0                                  (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL5_DPID_B_0X1                                  (0x1u<<16)

// OTG_DOEPCTL5_ALTERNATE1 Configuration

#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EPENA                            (0x1u<<31)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EPDIS                            (0x1u<<30)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_SODDFRM                          (0x1u<<29)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_SEVNFRM                          (0x1u<<28)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_SNAK                             (0x1u<<27)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_CNAK                             (0x1u<<26)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_STALL                            (0x1u<<21)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_SNPM                             (0x1u<<20)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EPTYP                            (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EPTYP_0                          (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_NAKSTS                           (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EONUM                            (0x1u<<16)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_USBAEP                           (0x1u<<15)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_MPSIZ                            (0x7FFu<<0)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_MPSIZ_0                          (0x1u<<0)

#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EPTYP_B_0X0                      (0x0u<<18)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EPTYP_B_0X1                      (0x1u<<18)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EPTYP_B_0X2                      (0x2u<<18)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EPTYP_B_0X3                      (0x3u<<18)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_NAKSTS_B_0X0                     (0x0u<<17)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_NAKSTS_B_0X1                     (0x1u<<17)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EONUM_B_0X0                      (0x0u<<16)
#define OTG_FS_OTG_DOEPCTL5_ALTERNATE1_EONUM_B_0X1                      (0x1u<<16)

// OTG_DOEPINT5 Configuration

#define OTG_FS_OTG_DOEPINT5_NAK                                         (0x1u<<13)
#define OTG_FS_OTG_DOEPINT5_BERR                                        (0x1u<<12)
#define OTG_FS_OTG_DOEPINT5_STSPHSRX                                    (0x1u<<5)
#define OTG_FS_OTG_DOEPINT5_OTEPDIS                                     (0x1u<<4)
#define OTG_FS_OTG_DOEPINT5_STUP                                        (0x1u<<3)
#define OTG_FS_OTG_DOEPINT5_EPDISD                                      (0x1u<<1)
#define OTG_FS_OTG_DOEPINT5_XFRC                                        (0x1u<<0)

// OTG_DOEPTSIZ5 Configuration

#define OTG_FS_OTG_DOEPTSIZ5_RXDPID                                     (0x3u<<29)
#define OTG_FS_OTG_DOEPTSIZ5_RXDPID_0                                   (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ5_PKTCNT                                     (0x3FFu<<19)
#define OTG_FS_OTG_DOEPTSIZ5_PKTCNT_0                                   (0x1u<<19)
#define OTG_FS_OTG_DOEPTSIZ5_XFRSIZ                                     (0x7FFFFu<<0)
#define OTG_FS_OTG_DOEPTSIZ5_XFRSIZ_0                                   (0x1u<<0)

#define OTG_FS_OTG_DOEPTSIZ5_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS     (0x0u<<29)
#define OTG_FS_OTG_DOEPTSIZ5_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS     (0x1u<<29)
#define OTG_FS_OTG_DOEPTSIZ5_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS     (0x2u<<29)
#define OTG_FS_OTG_DOEPTSIZ5_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS     (0x3u<<29)

// OTG_PCGCCTL Configuration

#define OTG_FS_OTG_PCGCCTL_SUSP                                         (0x1u<<7)
#define OTG_FS_OTG_PCGCCTL_PHYSLEEP                                     (0x1u<<6)
#define OTG_FS_OTG_PCGCCTL_ENL1GTG                                      (0x1u<<5)
#define OTG_FS_OTG_PCGCCTL_PHYSUSP                                      (0x1u<<4)
#define OTG_FS_OTG_PCGCCTL_GATEHCLK                                     (0x1u<<1)
#define OTG_FS_OTG_PCGCCTL_STPPCLK                                      (0x1u<<0)

// OTG_PCGCCTL1 Configuration

#define OTG_FS_OTG_PCGCCTL1_RAMGATEEN                                   (0x1u<<3)
#define OTG_FS_OTG_PCGCCTL1_CNTGATECLK                                  (0x3u<<1)
#define OTG_FS_OTG_PCGCCTL1_CNTGATECLK_0                                (0x1u<<1)
#define OTG_FS_OTG_PCGCCTL1_GATEEN                                      (0x1u<<0)

#define OTG_FS_OTG_PCGCCTL1_CNTGATECLK_B_0X0                            (0x0u<<1)
#define OTG_FS_OTG_PCGCCTL1_CNTGATECLK_B_0X1                            (0x1u<<1)
