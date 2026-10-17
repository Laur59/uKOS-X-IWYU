/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * STM32H753 – CRYP (cryptographic processor) register equates, generated from STM32H753.svd.
 */

#pragma once

#include    <stdint.h>

// CRYP address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    DIN;
    volatile    uint32_t    DOUT;
    volatile    uint32_t    DMACR;
    volatile    uint32_t    IMSCR;
    volatile    uint32_t    RISR;
    volatile    uint32_t    MISR;
    volatile    uint32_t    K0LR;
    volatile    uint32_t    K0RR;
    volatile    uint32_t    K1LR;
    volatile    uint32_t    K1RR;
    volatile    uint32_t    K2LR;
    volatile    uint32_t    K2RR;
    volatile    uint32_t    K3LR;
    volatile    uint32_t    K3RR;
    volatile    uint32_t    IV0LR;
    volatile    uint32_t    IV0RR;
    volatile    uint32_t    IV1LR;
    volatile    uint32_t    IV1RR;
    volatile    uint32_t    CSGCMCCM0R;
    volatile    uint32_t    CSGCMCCM1R;
    volatile    uint32_t    CSGCMCCM2R;
    volatile    uint32_t    CSGCMCCM3R;
    volatile    uint32_t    CSGCMCCM4R;
    volatile    uint32_t    CSGCMCCM5R;
    volatile    uint32_t    CSGCMCCM6R;
    volatile    uint32_t    CSGCMCCM7R;
    volatile    uint32_t    CSGCM0R;
    volatile    uint32_t    CSGCM1R;
    volatile    uint32_t    CSGCM2R;
    volatile    uint32_t    CSGCM3R;
    volatile    uint32_t    CSGCM4R;
    volatile    uint32_t    CSGCM5R;
    volatile    uint32_t    CSGCM6R;
    volatile    uint32_t    CSGCM7R;
} CRYP_TypeDef;

#ifdef __cplusplus
#define CRYP    reinterpret_cast<CRYP_TypeDef *>(0x48021000U)

#else
#define CRYP    ((CRYP_TypeDef *)0x48021000U)
#endif

// CR Configuration

#define CRYP_CR_ALGOMODE3           (0x1U<<19U)
#define CRYP_CR_GCM_CCMPH           (0x3U<<16U)
#define CRYP_CR_GCM_CCMPH_0         (0x1U<<16U)
#define CRYP_CR_CRYPEN              (0x1U<<15U)
#define CRYP_CR_FFLUSH              (0x1U<<14U)
#define CRYP_CR_KEYSIZE             (0x3U<<8U)
#define CRYP_CR_KEYSIZE_0           (0x1U<<8U)
#define CRYP_CR_DATATYPE            (0x3U<<6U)
#define CRYP_CR_DATATYPE_0          (0x1U<<6U)
#define CRYP_CR_ALGOMODE0           (0x7U<<3U)
#define CRYP_CR_ALGOMODE0_0         (0x1U<<3U)
#define CRYP_CR_ALGODIR             (0x1U<<2U)

// SR Configuration

#define CRYP_SR_IFEM                (0x1U<<0U)
#define CRYP_SR_IFNF                (0x1U<<1U)
#define CRYP_SR_OFNE                (0x1U<<2U)
#define CRYP_SR_OFFU                (0x1U<<3U)
#define CRYP_SR_BUSY                (0x1U<<4U)

// DIN Configuration

#define CRYP_DIN_DATAIN             (0xFFFFFFFFU<<0U)
#define CRYP_DIN_DATAIN_0           (0x1U<<0U)

// DOUT Configuration

#define CRYP_DOUT_DATAOUT           (0xFFFFFFFFU<<0U)
#define CRYP_DOUT_DATAOUT_0         (0x1U<<0U)

// DMACR Configuration

#define CRYP_DMACR_DIEN             (0x1U<<0U)
#define CRYP_DMACR_DOEN             (0x1U<<1U)

// IMSCR Configuration

#define CRYP_IMSCR_INIM             (0x1U<<0U)
#define CRYP_IMSCR_OUTIM            (0x1U<<1U)

// RISR Configuration

#define CRYP_RISR_INRIS             (0x1U<<0U)
#define CRYP_RISR_OUTRIS            (0x1U<<1U)

// MISR Configuration

#define CRYP_MISR_INMIS             (0x1U<<0U)
#define CRYP_MISR_OUTMIS            (0x1U<<1U)

// K0LR Configuration

#define CRYP_K0LR_K255              (0x1U<<31U)
#define CRYP_K0LR_K254              (0x1U<<30U)
#define CRYP_K0LR_K253              (0x1U<<29U)
#define CRYP_K0LR_K252              (0x1U<<28U)
#define CRYP_K0LR_K251              (0x1U<<27U)
#define CRYP_K0LR_K250              (0x1U<<26U)
#define CRYP_K0LR_K249              (0x1U<<25U)
#define CRYP_K0LR_K248              (0x1U<<24U)
#define CRYP_K0LR_K247              (0x1U<<23U)
#define CRYP_K0LR_K246              (0x1U<<22U)
#define CRYP_K0LR_K245              (0x1U<<21U)
#define CRYP_K0LR_K244              (0x1U<<20U)
#define CRYP_K0LR_K243              (0x1U<<19U)
#define CRYP_K0LR_K242              (0x1U<<18U)
#define CRYP_K0LR_K241              (0x1U<<17U)
#define CRYP_K0LR_K240              (0x1U<<16U)
#define CRYP_K0LR_K239              (0x1U<<15U)
#define CRYP_K0LR_K238              (0x1U<<14U)
#define CRYP_K0LR_K237              (0x1U<<13U)
#define CRYP_K0LR_K236              (0x1U<<12U)
#define CRYP_K0LR_K235              (0x1U<<11U)
#define CRYP_K0LR_K234              (0x1U<<10U)
#define CRYP_K0LR_K233              (0x1U<<9U)
#define CRYP_K0LR_K232              (0x1U<<8U)
#define CRYP_K0LR_K231              (0x1U<<7U)
#define CRYP_K0LR_K230              (0x1U<<6U)
#define CRYP_K0LR_K229              (0x1U<<5U)
#define CRYP_K0LR_K228              (0x1U<<4U)
#define CRYP_K0LR_K227              (0x1U<<3U)
#define CRYP_K0LR_K226              (0x1U<<2U)
#define CRYP_K0LR_K225              (0x1U<<1U)
#define CRYP_K0LR_K224              (0x1U<<0U)

// K0RR Configuration

#define CRYP_K0RR_K223              (0x1U<<31U)
#define CRYP_K0RR_K222              (0x1U<<30U)
#define CRYP_K0RR_K221              (0x1U<<29U)
#define CRYP_K0RR_K220              (0x1U<<28U)
#define CRYP_K0RR_K219              (0x1U<<27U)
#define CRYP_K0RR_K218              (0x1U<<26U)
#define CRYP_K0RR_K217              (0x1U<<25U)
#define CRYP_K0RR_K216              (0x1U<<24U)
#define CRYP_K0RR_K215              (0x1U<<23U)
#define CRYP_K0RR_K214              (0x1U<<22U)
#define CRYP_K0RR_K213              (0x1U<<21U)
#define CRYP_K0RR_K212              (0x1U<<20U)
#define CRYP_K0RR_K211              (0x1U<<19U)
#define CRYP_K0RR_K210              (0x1U<<18U)
#define CRYP_K0RR_K209              (0x1U<<17U)
#define CRYP_K0RR_K208              (0x1U<<16U)
#define CRYP_K0RR_K207              (0x1U<<15U)
#define CRYP_K0RR_K206              (0x1U<<14U)
#define CRYP_K0RR_K205              (0x1U<<13U)
#define CRYP_K0RR_K204              (0x1U<<12U)
#define CRYP_K0RR_K203              (0x1U<<11U)
#define CRYP_K0RR_K202              (0x1U<<10U)
#define CRYP_K0RR_K201              (0x1U<<9U)
#define CRYP_K0RR_K200              (0x1U<<8U)
#define CRYP_K0RR_K199              (0x1U<<7U)
#define CRYP_K0RR_K198              (0x1U<<6U)
#define CRYP_K0RR_K197              (0x1U<<5U)
#define CRYP_K0RR_K196              (0x1U<<4U)
#define CRYP_K0RR_K195              (0x1U<<3U)
#define CRYP_K0RR_K194              (0x1U<<2U)
#define CRYP_K0RR_K193              (0x1U<<1U)
#define CRYP_K0RR_K192              (0x1U<<0U)

// K1LR Configuration

#define CRYP_K1LR_K191              (0x1U<<31U)
#define CRYP_K1LR_K190              (0x1U<<30U)
#define CRYP_K1LR_K189              (0x1U<<29U)
#define CRYP_K1LR_K188              (0x1U<<28U)
#define CRYP_K1LR_K187              (0x1U<<27U)
#define CRYP_K1LR_K186              (0x1U<<26U)
#define CRYP_K1LR_K185              (0x1U<<25U)
#define CRYP_K1LR_K184              (0x1U<<24U)
#define CRYP_K1LR_K183              (0x1U<<23U)
#define CRYP_K1LR_K182              (0x1U<<22U)
#define CRYP_K1LR_K181              (0x1U<<21U)
#define CRYP_K1LR_K180              (0x1U<<20U)
#define CRYP_K1LR_K179              (0x1U<<19U)
#define CRYP_K1LR_K178              (0x1U<<18U)
#define CRYP_K1LR_K177              (0x1U<<17U)
#define CRYP_K1LR_K176              (0x1U<<16U)
#define CRYP_K1LR_K175              (0x1U<<15U)
#define CRYP_K1LR_K174              (0x1U<<14U)
#define CRYP_K1LR_K173              (0x1U<<13U)
#define CRYP_K1LR_K172              (0x1U<<12U)
#define CRYP_K1LR_K171              (0x1U<<11U)
#define CRYP_K1LR_K170              (0x1U<<10U)
#define CRYP_K1LR_K169              (0x1U<<9U)
#define CRYP_K1LR_K168              (0x1U<<8U)
#define CRYP_K1LR_K167              (0x1U<<7U)
#define CRYP_K1LR_K166              (0x1U<<6U)
#define CRYP_K1LR_K165              (0x1U<<5U)
#define CRYP_K1LR_K164              (0x1U<<4U)
#define CRYP_K1LR_K163              (0x1U<<3U)
#define CRYP_K1LR_K162              (0x1U<<2U)
#define CRYP_K1LR_K161              (0x1U<<1U)
#define CRYP_K1LR_K160              (0x1U<<0U)

// K1RR Configuration

#define CRYP_K1RR_K159              (0x1U<<31U)
#define CRYP_K1RR_K158              (0x1U<<30U)
#define CRYP_K1RR_K157              (0x1U<<29U)
#define CRYP_K1RR_K156              (0x1U<<28U)
#define CRYP_K1RR_K155              (0x1U<<27U)
#define CRYP_K1RR_K154              (0x1U<<26U)
#define CRYP_K1RR_K153              (0x1U<<25U)
#define CRYP_K1RR_K152              (0x1U<<24U)
#define CRYP_K1RR_K151              (0x1U<<23U)
#define CRYP_K1RR_K150              (0x1U<<22U)
#define CRYP_K1RR_K149              (0x1U<<21U)
#define CRYP_K1RR_K148              (0x1U<<20U)
#define CRYP_K1RR_K147              (0x1U<<19U)
#define CRYP_K1RR_K146              (0x1U<<18U)
#define CRYP_K1RR_K145              (0x1U<<17U)
#define CRYP_K1RR_K144              (0x1U<<16U)
#define CRYP_K1RR_K143              (0x1U<<15U)
#define CRYP_K1RR_K142              (0x1U<<14U)
#define CRYP_K1RR_K141              (0x1U<<13U)
#define CRYP_K1RR_K140              (0x1U<<12U)
#define CRYP_K1RR_K139              (0x1U<<11U)
#define CRYP_K1RR_K138              (0x1U<<10U)
#define CRYP_K1RR_K137              (0x1U<<9U)
#define CRYP_K1RR_K136              (0x1U<<8U)
#define CRYP_K1RR_K135              (0x1U<<7U)
#define CRYP_K1RR_K134              (0x1U<<6U)
#define CRYP_K1RR_K133              (0x1U<<5U)
#define CRYP_K1RR_K132              (0x1U<<4U)
#define CRYP_K1RR_K131              (0x1U<<3U)
#define CRYP_K1RR_K130              (0x1U<<2U)
#define CRYP_K1RR_K129              (0x1U<<1U)
#define CRYP_K1RR_K128              (0x1U<<0U)

// K2LR Configuration

#define CRYP_K2LR_K127              (0x1U<<31U)
#define CRYP_K2LR_K126              (0x1U<<30U)
#define CRYP_K2LR_K125              (0x1U<<29U)
#define CRYP_K2LR_K124              (0x1U<<28U)
#define CRYP_K2LR_K123              (0x1U<<27U)
#define CRYP_K2LR_K122              (0x1U<<26U)
#define CRYP_K2LR_K121              (0x1U<<25U)
#define CRYP_K2LR_K120              (0x1U<<24U)
#define CRYP_K2LR_K119              (0x1U<<23U)
#define CRYP_K2LR_K118              (0x1U<<22U)
#define CRYP_K2LR_K117              (0x1U<<21U)
#define CRYP_K2LR_K116              (0x1U<<20U)
#define CRYP_K2LR_K115              (0x1U<<19U)
#define CRYP_K2LR_K114              (0x1U<<18U)
#define CRYP_K2LR_K113              (0x1U<<17U)
#define CRYP_K2LR_K112              (0x1U<<16U)
#define CRYP_K2LR_K111              (0x1U<<15U)
#define CRYP_K2LR_K110              (0x1U<<14U)
#define CRYP_K2LR_K109              (0x1U<<13U)
#define CRYP_K2LR_K108              (0x1U<<12U)
#define CRYP_K2LR_K107              (0x1U<<11U)
#define CRYP_K2LR_K106              (0x1U<<10U)
#define CRYP_K2LR_K105              (0x1U<<9U)
#define CRYP_K2LR_K104              (0x1U<<8U)
#define CRYP_K2LR_K103              (0x1U<<7U)
#define CRYP_K2LR_K102              (0x1U<<6U)
#define CRYP_K2LR_K101              (0x1U<<5U)
#define CRYP_K2LR_K100              (0x1U<<4U)
#define CRYP_K2LR_K99               (0x1U<<3U)
#define CRYP_K2LR_K98               (0x1U<<2U)
#define CRYP_K2LR_K97               (0x1U<<1U)
#define CRYP_K2LR_K96               (0x1U<<0U)

// K2RR Configuration

#define CRYP_K2RR_K95               (0x1U<<31U)
#define CRYP_K2RR_K94               (0x1U<<30U)
#define CRYP_K2RR_K93               (0x1U<<29U)
#define CRYP_K2RR_K92               (0x1U<<28U)
#define CRYP_K2RR_K91               (0x1U<<27U)
#define CRYP_K2RR_K90               (0x1U<<26U)
#define CRYP_K2RR_K89               (0x1U<<25U)
#define CRYP_K2RR_K88               (0x1U<<24U)
#define CRYP_K2RR_K87               (0x1U<<23U)
#define CRYP_K2RR_K86               (0x1U<<22U)
#define CRYP_K2RR_K85               (0x1U<<21U)
#define CRYP_K2RR_K84               (0x1U<<20U)
#define CRYP_K2RR_K83               (0x1U<<19U)
#define CRYP_K2RR_K82               (0x1U<<18U)
#define CRYP_K2RR_K81               (0x1U<<17U)
#define CRYP_K2RR_K80               (0x1U<<16U)
#define CRYP_K2RR_K79               (0x1U<<15U)
#define CRYP_K2RR_K78               (0x1U<<14U)
#define CRYP_K2RR_K77               (0x1U<<13U)
#define CRYP_K2RR_K76               (0x1U<<12U)
#define CRYP_K2RR_K75               (0x1U<<11U)
#define CRYP_K2RR_K74               (0x1U<<10U)
#define CRYP_K2RR_K73               (0x1U<<9U)
#define CRYP_K2RR_K72               (0x1U<<8U)
#define CRYP_K2RR_K71               (0x1U<<7U)
#define CRYP_K2RR_K70               (0x1U<<6U)
#define CRYP_K2RR_K69               (0x1U<<5U)
#define CRYP_K2RR_K68               (0x1U<<4U)
#define CRYP_K2RR_K67               (0x1U<<3U)
#define CRYP_K2RR_K66               (0x1U<<2U)
#define CRYP_K2RR_K65               (0x1U<<1U)
#define CRYP_K2RR_K64               (0x1U<<0U)

// K3LR Configuration

#define CRYP_K3LR_K63               (0x1U<<31U)
#define CRYP_K3LR_K62               (0x1U<<30U)
#define CRYP_K3LR_K61               (0x1U<<29U)
#define CRYP_K3LR_K60               (0x1U<<28U)
#define CRYP_K3LR_K59               (0x1U<<27U)
#define CRYP_K3LR_K58               (0x1U<<26U)
#define CRYP_K3LR_K57               (0x1U<<25U)
#define CRYP_K3LR_K56               (0x1U<<24U)
#define CRYP_K3LR_K55               (0x1U<<23U)
#define CRYP_K3LR_K54               (0x1U<<22U)
#define CRYP_K3LR_K53               (0x1U<<21U)
#define CRYP_K3LR_K52               (0x1U<<20U)
#define CRYP_K3LR_K51               (0x1U<<19U)
#define CRYP_K3LR_K50               (0x1U<<18U)
#define CRYP_K3LR_K49               (0x1U<<17U)
#define CRYP_K3LR_K48               (0x1U<<16U)
#define CRYP_K3LR_K47               (0x1U<<15U)
#define CRYP_K3LR_K46               (0x1U<<14U)
#define CRYP_K3LR_K45               (0x1U<<13U)
#define CRYP_K3LR_K44               (0x1U<<12U)
#define CRYP_K3LR_K43               (0x1U<<11U)
#define CRYP_K3LR_K42               (0x1U<<10U)
#define CRYP_K3LR_K41               (0x1U<<9U)
#define CRYP_K3LR_K40               (0x1U<<8U)
#define CRYP_K3LR_K39               (0x1U<<7U)
#define CRYP_K3LR_K38               (0x1U<<6U)
#define CRYP_K3LR_K37               (0x1U<<5U)
#define CRYP_K3LR_K36               (0x1U<<4U)
#define CRYP_K3LR_K35               (0x1U<<3U)
#define CRYP_K3LR_K34               (0x1U<<2U)
#define CRYP_K3LR_K33               (0x1U<<1U)
#define CRYP_K3LR_K32               (0x1U<<0U)

// K3RR Configuration

#define CRYP_K3RR_K31               (0x1U<<31U)
#define CRYP_K3RR_K30               (0x1U<<30U)
#define CRYP_K3RR_K29               (0x1U<<29U)
#define CRYP_K3RR_K28               (0x1U<<28U)
#define CRYP_K3RR_K27               (0x1U<<27U)
#define CRYP_K3RR_K26               (0x1U<<26U)
#define CRYP_K3RR_K25               (0x1U<<25U)
#define CRYP_K3RR_K24               (0x1U<<24U)
#define CRYP_K3RR_K23               (0x1U<<23U)
#define CRYP_K3RR_K22               (0x1U<<22U)
#define CRYP_K3RR_K21               (0x1U<<21U)
#define CRYP_K3RR_K20               (0x1U<<20U)
#define CRYP_K3RR_K19               (0x1U<<19U)
#define CRYP_K3RR_K18               (0x1U<<18U)
#define CRYP_K3RR_K17               (0x1U<<17U)
#define CRYP_K3RR_K16               (0x1U<<16U)
#define CRYP_K3RR_K15               (0x1U<<15U)
#define CRYP_K3RR_K14               (0x1U<<14U)
#define CRYP_K3RR_K13               (0x1U<<13U)
#define CRYP_K3RR_K12               (0x1U<<12U)
#define CRYP_K3RR_K11               (0x1U<<11U)
#define CRYP_K3RR_K10               (0x1U<<10U)
#define CRYP_K3RR_K9                (0x1U<<9U)
#define CRYP_K3RR_K8                (0x1U<<8U)
#define CRYP_K3RR_K7                (0x1U<<7U)
#define CRYP_K3RR_K6                (0x1U<<6U)
#define CRYP_K3RR_K5                (0x1U<<5U)
#define CRYP_K3RR_K4                (0x1U<<4U)
#define CRYP_K3RR_K3                (0x1U<<3U)
#define CRYP_K3RR_K2                (0x1U<<2U)
#define CRYP_K3RR_K1                (0x1U<<1U)
#define CRYP_K3RR_K0                (0x1U<<0U)

// IV0LR Configuration

#define CRYP_IV0LR_IV0              (0x1U<<31U)
#define CRYP_IV0LR_IV1              (0x1U<<30U)
#define CRYP_IV0LR_IV2              (0x1U<<29U)
#define CRYP_IV0LR_IV3              (0x1U<<28U)
#define CRYP_IV0LR_IV4              (0x1U<<27U)
#define CRYP_IV0LR_IV5              (0x1U<<26U)
#define CRYP_IV0LR_IV6              (0x1U<<25U)
#define CRYP_IV0LR_IV7              (0x1U<<24U)
#define CRYP_IV0LR_IV8              (0x1U<<23U)
#define CRYP_IV0LR_IV9              (0x1U<<22U)
#define CRYP_IV0LR_IV10             (0x1U<<21U)
#define CRYP_IV0LR_IV11             (0x1U<<20U)
#define CRYP_IV0LR_IV12             (0x1U<<19U)
#define CRYP_IV0LR_IV13             (0x1U<<18U)
#define CRYP_IV0LR_IV14             (0x1U<<17U)
#define CRYP_IV0LR_IV15             (0x1U<<16U)
#define CRYP_IV0LR_IV16             (0x1U<<15U)
#define CRYP_IV0LR_IV17             (0x1U<<14U)
#define CRYP_IV0LR_IV18             (0x1U<<13U)
#define CRYP_IV0LR_IV19             (0x1U<<12U)
#define CRYP_IV0LR_IV20             (0x1U<<11U)
#define CRYP_IV0LR_IV21             (0x1U<<10U)
#define CRYP_IV0LR_IV22             (0x1U<<9U)
#define CRYP_IV0LR_IV23             (0x1U<<8U)
#define CRYP_IV0LR_IV24             (0x1U<<7U)
#define CRYP_IV0LR_IV25             (0x1U<<6U)
#define CRYP_IV0LR_IV26             (0x1U<<5U)
#define CRYP_IV0LR_IV27             (0x1U<<4U)
#define CRYP_IV0LR_IV28             (0x1U<<3U)
#define CRYP_IV0LR_IV29             (0x1U<<2U)
#define CRYP_IV0LR_IV30             (0x1U<<1U)
#define CRYP_IV0LR_IV31             (0x1U<<0U)

// IV0RR Configuration

#define CRYP_IV0RR_IV32             (0x1U<<31U)
#define CRYP_IV0RR_IV33             (0x1U<<30U)
#define CRYP_IV0RR_IV34             (0x1U<<29U)
#define CRYP_IV0RR_IV35             (0x1U<<28U)
#define CRYP_IV0RR_IV36             (0x1U<<27U)
#define CRYP_IV0RR_IV37             (0x1U<<26U)
#define CRYP_IV0RR_IV38             (0x1U<<25U)
#define CRYP_IV0RR_IV39             (0x1U<<24U)
#define CRYP_IV0RR_IV40             (0x1U<<23U)
#define CRYP_IV0RR_IV41             (0x1U<<22U)
#define CRYP_IV0RR_IV42             (0x1U<<21U)
#define CRYP_IV0RR_IV43             (0x1U<<20U)
#define CRYP_IV0RR_IV44             (0x1U<<19U)
#define CRYP_IV0RR_IV45             (0x1U<<18U)
#define CRYP_IV0RR_IV46             (0x1U<<17U)
#define CRYP_IV0RR_IV47             (0x1U<<16U)
#define CRYP_IV0RR_IV48             (0x1U<<15U)
#define CRYP_IV0RR_IV49             (0x1U<<14U)
#define CRYP_IV0RR_IV50             (0x1U<<13U)
#define CRYP_IV0RR_IV51             (0x1U<<12U)
#define CRYP_IV0RR_IV52             (0x1U<<11U)
#define CRYP_IV0RR_IV53             (0x1U<<10U)
#define CRYP_IV0RR_IV54             (0x1U<<9U)
#define CRYP_IV0RR_IV55             (0x1U<<8U)
#define CRYP_IV0RR_IV56             (0x1U<<7U)
#define CRYP_IV0RR_IV57             (0x1U<<6U)
#define CRYP_IV0RR_IV58             (0x1U<<5U)
#define CRYP_IV0RR_IV59             (0x1U<<4U)
#define CRYP_IV0RR_IV60             (0x1U<<3U)
#define CRYP_IV0RR_IV61             (0x1U<<2U)
#define CRYP_IV0RR_IV62             (0x1U<<1U)
#define CRYP_IV0RR_IV63             (0x1U<<0U)

// IV1LR Configuration

#define CRYP_IV1LR_IV64             (0x1U<<31U)
#define CRYP_IV1LR_IV65             (0x1U<<30U)
#define CRYP_IV1LR_IV66             (0x1U<<29U)
#define CRYP_IV1LR_IV67             (0x1U<<28U)
#define CRYP_IV1LR_IV68             (0x1U<<27U)
#define CRYP_IV1LR_IV69             (0x1U<<26U)
#define CRYP_IV1LR_IV70             (0x1U<<25U)
#define CRYP_IV1LR_IV71             (0x1U<<24U)
#define CRYP_IV1LR_IV72             (0x1U<<23U)
#define CRYP_IV1LR_IV73             (0x1U<<22U)
#define CRYP_IV1LR_IV74             (0x1U<<21U)
#define CRYP_IV1LR_IV75             (0x1U<<20U)
#define CRYP_IV1LR_IV76             (0x1U<<19U)
#define CRYP_IV1LR_IV77             (0x1U<<18U)
#define CRYP_IV1LR_IV78             (0x1U<<17U)
#define CRYP_IV1LR_IV79             (0x1U<<16U)
#define CRYP_IV1LR_IV80             (0x1U<<15U)
#define CRYP_IV1LR_IV81             (0x1U<<14U)
#define CRYP_IV1LR_IV82             (0x1U<<13U)
#define CRYP_IV1LR_IV83             (0x1U<<12U)
#define CRYP_IV1LR_IV84             (0x1U<<11U)
#define CRYP_IV1LR_IV85             (0x1U<<10U)
#define CRYP_IV1LR_IV86             (0x1U<<9U)
#define CRYP_IV1LR_IV87             (0x1U<<8U)
#define CRYP_IV1LR_IV88             (0x1U<<7U)
#define CRYP_IV1LR_IV89             (0x1U<<6U)
#define CRYP_IV1LR_IV90             (0x1U<<5U)
#define CRYP_IV1LR_IV91             (0x1U<<4U)
#define CRYP_IV1LR_IV92             (0x1U<<3U)
#define CRYP_IV1LR_IV93             (0x1U<<2U)
#define CRYP_IV1LR_IV94             (0x1U<<1U)
#define CRYP_IV1LR_IV95             (0x1U<<0U)

// IV1RR Configuration

#define CRYP_IV1RR_IV96             (0x1U<<31U)
#define CRYP_IV1RR_IV97             (0x1U<<30U)
#define CRYP_IV1RR_IV98             (0x1U<<29U)
#define CRYP_IV1RR_IV99             (0x1U<<28U)
#define CRYP_IV1RR_IV100            (0x1U<<27U)
#define CRYP_IV1RR_IV101            (0x1U<<26U)
#define CRYP_IV1RR_IV102            (0x1U<<25U)
#define CRYP_IV1RR_IV103            (0x1U<<24U)
#define CRYP_IV1RR_IV104            (0x1U<<23U)
#define CRYP_IV1RR_IV105            (0x1U<<22U)
#define CRYP_IV1RR_IV106            (0x1U<<21U)
#define CRYP_IV1RR_IV107            (0x1U<<20U)
#define CRYP_IV1RR_IV108            (0x1U<<19U)
#define CRYP_IV1RR_IV109            (0x1U<<18U)
#define CRYP_IV1RR_IV110            (0x1U<<17U)
#define CRYP_IV1RR_IV111            (0x1U<<16U)
#define CRYP_IV1RR_IV112            (0x1U<<15U)
#define CRYP_IV1RR_IV113            (0x1U<<14U)
#define CRYP_IV1RR_IV114            (0x1U<<13U)
#define CRYP_IV1RR_IV115            (0x1U<<12U)
#define CRYP_IV1RR_IV116            (0x1U<<11U)
#define CRYP_IV1RR_IV117            (0x1U<<10U)
#define CRYP_IV1RR_IV118            (0x1U<<9U)
#define CRYP_IV1RR_IV119            (0x1U<<8U)
#define CRYP_IV1RR_IV120            (0x1U<<7U)
#define CRYP_IV1RR_IV121            (0x1U<<6U)
#define CRYP_IV1RR_IV122            (0x1U<<5U)
#define CRYP_IV1RR_IV123            (0x1U<<4U)
#define CRYP_IV1RR_IV124            (0x1U<<3U)
#define CRYP_IV1RR_IV125            (0x1U<<2U)
#define CRYP_IV1RR_IV126            (0x1U<<1U)
#define CRYP_IV1RR_IV127            (0x1U<<0U)

// CSGCMCCM0R Configuration

#define CRYP_CSGCMCCM0R_CSGCMCCM0   (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM0R_CSGCMCCM0_0 (0x1U<<0U)

// CSGCMCCM1R Configuration

#define CRYP_CSGCMCCM1R_CSGCMCCM1   (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM1R_CSGCMCCM1_0 (0x1U<<0U)

// CSGCMCCM2R Configuration

#define CRYP_CSGCMCCM2R_CSGCMCCM2   (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM2R_CSGCMCCM2_0 (0x1U<<0U)

// CSGCMCCM3R Configuration

#define CRYP_CSGCMCCM3R_CSGCMCCM3   (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM3R_CSGCMCCM3_0 (0x1U<<0U)

// CSGCMCCM4R Configuration

#define CRYP_CSGCMCCM4R_CSGCMCCM4   (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM4R_CSGCMCCM4_0 (0x1U<<0U)

// CSGCMCCM5R Configuration

#define CRYP_CSGCMCCM5R_CSGCMCCM5   (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM5R_CSGCMCCM5_0 (0x1U<<0U)

// CSGCMCCM6R Configuration

#define CRYP_CSGCMCCM6R_CSGCMCCM6   (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM6R_CSGCMCCM6_0 (0x1U<<0U)

// CSGCMCCM7R Configuration

#define CRYP_CSGCMCCM7R_CSGCMCCM7   (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM7R_CSGCMCCM7_0 (0x1U<<0U)

// CSGCM0R Configuration

#define CRYP_CSGCM0R_CSGCM0         (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM0R_CSGCM0_0       (0x1U<<0U)

// CSGCM1R Configuration

#define CRYP_CSGCM1R_CSGCM1         (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM1R_CSGCM1_0       (0x1U<<0U)

// CSGCM2R Configuration

#define CRYP_CSGCM2R_CSGCM2         (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM2R_CSGCM2_0       (0x1U<<0U)

// CSGCM3R Configuration

#define CRYP_CSGCM3R_CSGCM3         (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM3R_CSGCM3_0       (0x1U<<0U)

// CSGCM4R Configuration

#define CRYP_CSGCM4R_CSGCM4         (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM4R_CSGCM4_0       (0x1U<<0U)

// CSGCM5R Configuration

#define CRYP_CSGCM5R_CSGCM5         (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM5R_CSGCM5_0       (0x1U<<0U)

// CSGCM6R Configuration

#define CRYP_CSGCM6R_CSGCM6         (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM6R_CSGCM6_0       (0x1U<<0U)

// CSGCM7R Configuration

#define CRYP_CSGCM7R_CSGCM7         (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM7R_CSGCM7_0       (0x1U<<0U)
