/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Stub for the "asmp" manager.
 *
 *           Inter-core messaging via SIO doorbell.
 *           Ported from the ARM Pico2_rp2350 version;
 *           the SIO registers and IRQ dispatch are identical on Hazard3.
 *
 *           Core references reflect the Hazard3 RV32IMAC core name.
 */

#include    "asmp/asmp.h"

#include    <stdint.h>

#include    "Registers/RP2350_sio.h"
#include    "Registers/nvic.h"
#include    "Registers/soc_vectors.h"
#include    "kern/kern.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "os_errors.h"
#include    "types.h"

#define KMESSAGE_SENT   (1U<<0U)
#define KMESSAGE_ACK    (1U<<1U)

static  const           char_t      *tableCoreReference[KNB_CORES] = {
                                    "hazard3_rv32imac_C0",
                                    "hazard3_rv32imac_C1"
                                };

// Prototypes

static  void    local_initInterCore(uint32_t core);
static  void    local_doorBell_IRQHandler(void);

/*
 * \brief stub_asmp_init
 *
 */
int32_t stub_asmp_init(void) {
            uint32_t    core;
            sema_t      *semaphore_RX, *semaphore_TX;
    const   char_t      *identifier_RX, *identifier_TX;

    stub_asmp_getRunningCore(&core);
    identifier_RX = (core == KCORE_0) ? (KASMP_SEMA_RX_CORE_0_FULL)  : (KASMP_SEMA_RX_CORE_1_FULL);
    identifier_TX = (core == KCORE_0) ? (KASMP_SEMA_TX_CORE_0_EMPTY) : (KASMP_SEMA_TX_CORE_1_EMPTY);

    INTERRUPT_VECTOR(SIO_IRQ_BELL_C0_IRQn, local_doorBell_IRQHandler);
    NVIC_SetPriority(SIO_IRQ_BELL_C0_IRQn, KINT_LEVEL_PERIPHERALS);
    NVIC_EnableIRQ(SIO_IRQ_BELL_C0_IRQn);

    local_initInterCore(core);

    kern_createSemaphore(identifier_RX, 0, 1, &semaphore_RX);
    kern_createSemaphore(identifier_TX, 0, 1, &semaphore_TX);

    kern_signalSemaphore(semaphore_TX);

    INTERRUPTION_OFF;
    vAsmp_InterCore->oASMPReady |= (core == KASMP_CORE_0) ? (1U<<(uint8_t)KASMP_CORE_0) : (1U<<(uint8_t)KASMP_CORE_1);
    RETURN_INT_RESTORE(KERR_ASMP_NOERR);
}

/*
 * \brief stub_asmp_getRunningCore
 *
 */
int32_t stub_asmp_getRunningCore(uint32_t *core) {

    *core = (GET_RUNNING_CORE == KCORE_0) ? ((uint32_t)KASMP_CORE_0) : ((uint32_t)KASMP_CORE_1);
    return KERR_ASMP_NOERR;
}

/*
 * \brief stub_asmp_getNumberOfCore
 *
 */
int32_t stub_asmp_getNumberOfCore(uint8_t *nbCore) {

    *nbCore = ((uint8_t)KASMP_CORE_1 + 1U);
    return KERR_ASMP_NOERR;
}

/*
 * \brief stub_asmp_getReferenceCore
 *
 */
int32_t stub_asmp_getReferenceCore(uint32_t core, const char_t **coreReference) {

    switch (core) {
        case KASMP_CORE_0: { *coreReference = tableCoreReference[KASMP_CORE_0]; break; }
        case KASMP_CORE_1: { *coreReference = tableCoreReference[KASMP_CORE_1]; break; }
        default:           { *coreReference = nullptr;                          break; }
    }
    return KERR_ASMP_NOERR;
}

/*
 * \brief stub_asmp_signal
 *
 */
int32_t stub_asmp_signal(uint32_t message) {

    switch (message) {
        case KASMP_MESSAGE_VALID_FOR_CORE_0:
        case KASMP_MESSAGE_VALID_FOR_CORE_1:       { REG(SIO)->DOORBELL_OUT_SET = KMESSAGE_SENT; break; }
        case KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0:
        case KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1: { REG(SIO)->DOORBELL_OUT_SET = KMESSAGE_ACK;  break; }
        default: {
            break;
        }
    }
    return KERR_ASMP_NOERR;
}

/*
 * \brief stub_asmp_waitingForReady
 *
 */
int32_t stub_asmp_waitingForReady(void) {
    uint8_t     maskNbCore;
    int32_t     status;

    maskNbCore = (1U<<(uint8_t)KASMP_CORE_1) | (1U<<(uint8_t)KASMP_CORE_0);

    status = ((vAsmp_InterCore->oASMPReady & maskNbCore) == maskNbCore) ? KERR_ASMP_NOERR : KERR_ASMP_NORDY;
    return status;
}

// Local routines
// ==============

/*
 * \brief local_initInterCore
 *
 */
static  void    local_initInterCore(uint32_t core) {
    uint32_t    i;

    INTERRUPTION_OFF;
    vAsmp_InterCore->oStatusRX[core] = KASMP_FREE;
    vAsmp_InterCore->oStatusTX[core] = KASMP_FREE;
    vAsmp_InterCore->oSender[core]   = 0U;
    vAsmp_InterCore->oOrder[core]    = 0U;
    vAsmp_InterCore->oSize[core]     = 0U;
    for (i = 0U; i < KASMP_SZ_BUFFER; i++) { vAsmp_InterCore->oBuffer[core][i] = 0U; }
    INTERRUPTION_RESTORE;
}

/*
 * \brief local_doorBell_IRQHandler
 *
 */
static  void    local_doorBell_IRQHandler(void) {
            uint32_t    core;
            sema_t      *semaphore_RX, *semaphore_TX;
    const   char_t      *identifier_RX, *identifier_TX;

    stub_asmp_getRunningCore(&core);
    identifier_RX = (core == KASMP_CORE_0) ? (KASMP_SEMA_RX_CORE_0_FULL)  : (KASMP_SEMA_RX_CORE_1_FULL);
    identifier_TX = (core == KASMP_CORE_0) ? (KASMP_SEMA_TX_CORE_0_EMPTY) : (KASMP_SEMA_TX_CORE_1_EMPTY);

    kern_getSemaphoreById(identifier_RX, &semaphore_RX);
    kern_getSemaphoreById(identifier_TX, &semaphore_TX);

    if (core == KASMP_CORE_0) {
        if ((REG(SIO)->DOORBELL_IN_CLR & KMESSAGE_SENT) != 0U) { REG(SIO)->DOORBELL_IN_CLR = KMESSAGE_SENT; vAsmp_InterCore->oStatusRX[KASMP_CORE_0] = KASMP_LOCK; kern_signalSemaphore(semaphore_RX); }
        if ((REG(SIO)->DOORBELL_IN_CLR & KMESSAGE_ACK)  != 0U) { REG(SIO)->DOORBELL_IN_CLR = KMESSAGE_ACK;  vAsmp_InterCore->oStatusTX[KASMP_CORE_1] = KASMP_FREE; kern_signalSemaphore(semaphore_TX); }
    }
    else {
        if ((REG(SIO)->DOORBELL_IN_CLR & KMESSAGE_SENT) != 0U) { REG(SIO)->DOORBELL_IN_CLR = KMESSAGE_SENT; vAsmp_InterCore->oStatusRX[KASMP_CORE_1] = KASMP_LOCK; kern_signalSemaphore(semaphore_RX); }
        if ((REG(SIO)->DOORBELL_IN_CLR & KMESSAGE_ACK)  != 0U) { REG(SIO)->DOORBELL_IN_CLR = KMESSAGE_ACK;  vAsmp_InterCore->oStatusTX[KASMP_CORE_0] = KASMP_FREE; kern_signalSemaphore(semaphore_TX); }
    }

    PREEMPTION_THRESHOLD(core);
}
