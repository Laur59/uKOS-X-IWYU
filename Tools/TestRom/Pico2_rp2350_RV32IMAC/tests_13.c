/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Test of cross-core access to UART0 protected by a spin lock.
 *
 * Both cores hammer UART0 concurrently with distinguishable
 * payloads. Without protection (#undef USE_SPINLOCK), characters
 * from the two cores interleave at the byte level — the shared TX
 * FIFO has no notion of "message boundary". With the spin lock
 * around the call, each message is transmitted atomically from the
 * UART's point of view and the lines stay readable.
 *
 * Implementation note: cmns_send routes by running core (core 0 to
 * UART0, core 1 to UART1) which means it would NOT create UART0
 * contention. The test bypasses cmns_send and writes directly to
 * UART0 from both cores (local_uart0_send) so the contention is real.
 *
 * cmns_send is for debug / panic output only — it is intentionally
 * blocking and uses no IRQs. Production logging uses per-core queues
 * with a single-owner UART writer, not this kind of coarse lock. The
 * test exists to validate that the spin-lock primitive serialises
 * cross-core access in the debug path.
 *
 * Lock-hold time = message length / baud rate. At 460800 baud and
 * ~36 chars per message, ~800 µs per call. The losing core busy-waits
 * that whole time — fine here (high CPU burn is exactly what we want
 * to make visible), unacceptable for production.
 *
 * Expected on hardware (USE_SPINLOCK defined):
 *   Hello from C0: BBBBBBBBBBBBBBBBBBBB
 *   Hello from C1: AAAAAAAAAAAAAAAAAAAA
 *   Hello from C0: BBBBBBBBBBBBBBBBBBBB
 *   ...
 *   - RED   (GPIO13) toggles each core-0 send (~50 ms cadence)
 *   - GREEN (GPIO12) toggles each core-1 send (~50 ms cadence)
 *
 * Expected on hardware (USE_SPINLOCK undefined):
 *   Garbled output — characters from "Hello from C0:..." and
 *   "Hello from C1:..." interleave per byte. Exact pattern depends
 *   on timing, but lines are not readable.
 */

#include    <stdint.h>

#include    "board.h"
#include    "cmns.h"
#include    "init.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "soc_reg.h"
#include    "spin.h"
#include    "types.h"

#define USE_SPINLOCK    // comment out to observe garbled UART output

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

extern  uint8_t         linker_topStackFirst_C1[];
static  spinlock_t      vUartLock = SPIN_LOCK_INIT;

/*
 * \brief local_uart0_send
 *
 * - Direct UART0 byte writer, bypassing cmns_send's per-core dispatch
 *
 */
static  void    local_uart0_send(const char_t *msg) {

    while (*msg != '\0') {
        while ((REG(UART0)->UARTFR & UART_UARTFR_TXFF) != 0u) { }

        REG(UART0)->UARTDR = (uint32_t)*msg;
        msg++;
    }
}

/*
 * \brief local_send
 *
 * - UART0 send wrapper, optionally protected by vUartLock
 *
 */
static  void    local_send(const char_t *msg) {
#ifdef  USE_SPINLOCK
    SPIN_LOCK(vUartLock);
    local_uart0_send(msg);
    SPIN_UNLOCK(vUartLock);
#else
    local_uart0_send(msg);
#endif
}

// CORE 1
// ======

/*
 * \brief local_codeCore_1
 *
 * - Stream "Hello from C1" to UART0 every 50 ms
 *
 */
static  void    local_codeCore_1(void) {

    __asm volatile ("la sp,linker_topStackFirst_C1");
    __asm volatile (
        ".option push            \n"
        ".option norelax         \n"
        "la     gp,__global_pointer$  \n"
        ".option pop             \n"
    );

    while (true) {
        local_send("Hello from C1: AAAAAAAAAAAAAAAAAAAA\n");
        cmns_wait(50000);
        LED_GREEN_TOGGLE;
    }
}

// CORE 0
// ======

/*
 * \brief test_13
 *
 * - Initialise UART0 and launch core 1
 * - Stream "Hello from C0" to UART0 every 50 ms
 *
 */
static  void    test_13(void) {

    cmns_init();
    init_launchCore_1(local_codeCore_1);

    while (true) {
        local_send("Hello from C0: BBBBBBBBBBBBBBBBBBBB\n");
        cmns_wait(50000);
        LED_RED_TOGGLE;
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_13();
}
