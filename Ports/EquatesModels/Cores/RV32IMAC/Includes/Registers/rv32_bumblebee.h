/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     rv32_bumblebee equates.
 */

#pragma once

#define RVBB_CSR_MTVT           0x307U                  //
#define RVBB_CSR_MNVEC          0x7C3U                  //
#define RVBB_CSR_MSUBM          0x7C4U                  //
#define RVBB_CSR_MMISC_CTL      0x7D0U                  //
#define RVBB_CSR_MSAVESTATUS    0x7D6U                  //
#define RVBB_CSR_MSAVEEPC1      0x7D7U                  //
#define RVBB_CSR_MSAVECAUSE1    0x7D8U                  //
#define RVBB_CSR_MSAVEEPC2      0x7D9U                  //
#define RVBB_CSR_MSAVECAUSE2    0x7DAU                  //
#define RVBB_CSR_PUSHMSUBM      0x7EBU                  //
#define RVBB_CSR_MTVT2          0x7ECU                  //
#define RVBB_CSR_JALMNXTI       0x7EDU                  //
#define RVBB_CSR_PUSHMCAUSE     0x7EEU                  //
#define RVBB_CSR_PUSHMEPC       0x7EFU                  //
#define RVBB_CSR_WFE            0x810U                  //
#define RVBB_CSR_SLEEPVALUE     0x811U                  //
#define RVBB_CSR_TXEVT          0x812U                  //

#define RVBB_MCAUSE_MINHV       (1U<<30U)                //
#define RVBB_MCAUSE_MPP(m)      ((((m) & 0x3U)<<28U))    //
#define RVBB_MCAUSE_MPIE        (1U<<27U)                //
