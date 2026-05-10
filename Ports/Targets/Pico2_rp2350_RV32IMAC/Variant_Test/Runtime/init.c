/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Common low-level init (PLL, clocks, core-1 launch).
 *
 *          !!! This code HAS not to contain static data.
 *          !!! It is called before to copy and to initialise
 *          !!! the variable into the RAM.
 */

#include    <stdint.h>

#include    "clockTree.h"
#include    "cmns.h"
#include    "init.h"
#include    "macros_core.h"
#include    "soc_reg.h"

// RISC-V specific runtime
// =======================

// static   inline  void    wfi(void) { __asm volatile ("wfi"); }
static  inline  void    fence(void) { __asm volatile ("fence" ::: "memory"); }
static  inline  void    sev(void) { __asm volatile ("slt x0, x0, x1" ::: "memory"); }

// Prototypes

static  void        local_PLL_Configuration(void);
static  void        local_USB_Configuration(void);
static  void        local_emptyRxFifo(void);
static  void        local_writeRTxFifo(uint32_t data);
static  uint32_t    local_readRxFifo(void);

extern  void        first_handle_trap(void);
extern  void        Reset_C1_Handler(void);
extern  uint8_t     linker_topStackFirst_C1[];

/*
 * \brief init_init
 *
 * - Configure PLLs and clocks (common to both cores, run by core 0 only).
 *   GPIO and pad configuration is core-0-specific and lives in init_C0.c.
 *
 * \note This function does not return a value (None).
 *
 */
void    init_init(void) {

    local_PLL_Configuration();

    if (GET_RUNNING_CORE == KCORE_0) {
        local_USB_Configuration();
        init_launchCore_1(Reset_C1_Handler);
    }
}

/*
 * \brief local_PLL_Configuration
 *
 * - Configure PLLs and clocks for 150 MHz system
 * - Same configuration as ARM version (registers are identical)
 *
 */
static  void    local_PLL_Configuration(void) {

#define PLL_USB_PWR_PD              PLL_SYS_PWR_PD
#define PLL_USB_PWR_VCOPD           PLL_SYS_PWR_VCOPD
#define PLL_USB_PWR_POSTDIVPD       PLL_SYS_PWR_POSTDIVPD
#define PLL_USB_CS_LOCK             PLL_SYS_CS_LOCK
#define PLL_USB_PRIM_POSTDIV1_0     PLL_SYS_PRIM_POSTDIV1_0
#define PLL_USB_PRIM_POSTDIV2_0     PLL_SYS_PRIM_POSTDIV2_0

// Disable clock resuscitation (may have been enabled by bootrom)

    REG(CLOCKS)->CLK_SYS_RESUS_CTRL = 0x0u;

// Before touching PLLs or XOSC, switch clk_sys and clk_ref to safe
// default sources (ROSC). This prevents killing the clock if the
// bootrom left clk_sys running from PLL or clk_ref running from XOSC.

    REG(CLOCKS)->CLK_SYS_CTRL &= ~CLOCKS_CLK_SYS_CTRL_SRC;
    while ((REG(CLOCKS)->CLK_SYS_SELECTED & 0x1u) == 0x0u) { }

    REG(CLOCKS)->CLK_REF_CTRL &= ~CLOCKS_CLK_REF_CTRL_SRC;
    while ((REG(CLOCKS)->CLK_REF_SELECTED & 0x1u) == 0x0u) { }

// Turn on the 12-MHz crystal oscillator

    REG(XOSC)->CTRL    = XOSC_CTRL_FREQ_RANGE_1_15MHZ;
    REG(XOSC)->STARTUP = 0x00C4u;
    REG(XOSC)->CTRL   |= XOSC_CTRL_ENABLE_ENABLE;
    while ((REG(XOSC)->STATUS & XOSC_STATUS_STABLE) == 0x0u) { }

// Switch clk_ref to XOSC (glitchless)

    REG(CLOCKS)->CLK_REF_DIV  = 1u * CLOCKS_CLK_REF_DIV_INT_0;
    REG(CLOCKS)->CLK_REF_CTRL = (REG(CLOCKS)->CLK_REF_CTRL & ~0x3u) | 0x2u;
    while ((REG(CLOCKS)->CLK_REF_SELECTED & (1u<<0x2u)) == 0x0u) { }

// Reset PLL_SYS
    REG(RESETS)->RESET |= RESETS_RESET_PLL_SYS;
    cmns_wait(10);
    REG(RESETS)->RESET &= ~RESETS_RESET_PLL_SYS;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_DONE_PLL_SYS) == 0x0u) { }

    REG(PLL_SYS)->PWR |= (PLL_SYS_PWR_PD | PLL_SYS_PWR_VCOPD | PLL_SYS_PWR_POSTDIVPD);

    // Configure PLL_SYS for 150 MHz
    // VCO = 1500 MHz, REFDIV = 1, FBDIV = 125 (12 * 125 = 1500)
    // postdiv1 = 5, postdiv2 = 2 => 1500 / (5 * 2) = 150 MHz
    REG(PLL_SYS)->CS        = 0x1u;
    REG(PLL_SYS)->FBDIV_INT = 125u;

    // Turn on the VCO
    REG(PLL_SYS)->PWR &= ~(PLL_SYS_PWR_PD | PLL_SYS_PWR_VCOPD);
    while ((REG(PLL_SYS)->CS & PLL_SYS_CS_LOCK) == 0u) { }

    REG(PLL_SYS)->PRIM = (5u * PLL_SYS_PRIM_POSTDIV1_0) | (2u * PLL_SYS_PRIM_POSTDIV2_0);
    REG(PLL_SYS)->PWR &= ~PLL_SYS_PWR_POSTDIVPD;

    // Switch clk_sys to PLL_SYS (glitchless via SRC/AUXSRC)
    REG(CLOCKS)->CLK_SYS_DIV  = 1u * CLOCKS_CLK_SYS_DIV_INT_0;
    REG(CLOCKS)->CLK_SYS_CTRL = (REG(CLOCKS)->CLK_SYS_CTRL & ~(0x7u<<5u)) | (0x0u<<5u);
    REG(CLOCKS)->CLK_SYS_CTRL = (REG(CLOCKS)->CLK_SYS_CTRL & ~0x1u) | 0x1u;
    while ((REG(CLOCKS)->CLK_SYS_SELECTED & (1u<<0x1u)) == 0x0u) { }

    // Configure clk_peri = clk_sys (for UART, etc.)
    REG(CLOCKS)->CLK_PERI_CTRL = (0x0u<<5u) | (1u<<0x0Bu);

// The USB PLL
// -----------

// Reset the PLL_USB

    REG(RESETS)->RESET |= RESETS_RESET_PLL_USB;
    cmns_wait(10u);
    REG(RESETS)->RESET &= ~RESETS_RESET_PLL_USB;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_DONE_PLL_USB) == 0x0u) { }

    REG(PLL_USB)->PWR |= (PLL_USB_PWR_PD | PLL_USB_PWR_VCOPD | PLL_USB_PWR_POSTDIVPD);

// Configure PLL_USB for 48-MHz
// - VCO = 480-MHz, REFDIV = 1, FBDIV = 40 (12 * 40 = 480)
// - postdiv1 = 5, postdiv2 = 2  => 480 / (5 * 2) = 48-MHz

    REG(PLL_USB)->CS        = 0x1u;
    REG(PLL_USB)->FBDIV_INT = 40u;

// Turn on the VCO

    REG(PLL_USB)->PWR &= ~(PLL_USB_PWR_PD | PLL_USB_PWR_VCOPD);
    while ((REG(PLL_USB)->CS & PLL_USB_CS_LOCK) == 0u) { }

    REG(PLL_USB)->PRIM = (5u * PLL_USB_PRIM_POSTDIV1_0) | (2u * PLL_USB_PRIM_POSTDIV2_0);
    REG(PLL_USB)->PWR &= ~PLL_USB_PWR_POSTDIVPD;

// Switch the clk_usb on the PLL_USB (via SRC/AUXSRC)

    REG(CLOCKS)->CLK_USB_DIV  = 1u * CLOCKS_CLK_USB_DIV_INT_0;
    REG(CLOCKS)->CLK_USB_CTRL = (REG(CLOCKS)->CLK_USB_CTRL & ~(0x7u<<5u)) | (0x0u<<5u);
    REG(CLOCKS)->CLK_USB_CTRL = (REG(CLOCKS)->CLK_USB_CTRL | CLOCKS_CLK_USB_CTRL_ENABLE);

// The timer clocks
// ----------------

// Timer 0 clocked to 1-MHz

    REG(TICKS)->TIMER0_CTRL   = TICKS_TIMER0_CTRL_ENABLE;
    REG(TICKS)->TIMER0_CYCLES = KCRYSTAL / KFREQUENCY_TIM;
    REG(TIMER0)->SOURCE       = 0u;

// Timer 1 clocked to 1-MHz

    REG(TICKS)->TIMER1_CTRL   = TICKS_TIMER1_CTRL_ENABLE;
    REG(TICKS)->TIMER1_CYCLES = KCRYSTAL / KFREQUENCY_TIM;
    REG(TIMER1)->SOURCE       = 0u;
}

/*
 * \brief local_USB_Configuration
 *
 * - Release the USB controller from reset and enable the PHY
 *
 */
static  void    local_USB_Configuration(void) {

    REG(RESETS)->RESET &= ~RESETS_RESET_USBCTRL;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_DONE_USBCTRL) == 0x0u) { }

    REG(USB)->MAIN_CTRL &= ~USB_MAIN_CTRL_PHY_ISO;
    REG(USB)->MAIN_CTRL |= USB_MAIN_CTRL_CONTROLLER_EN;
}

/*
 * \brief init_launchCore_1
 *
 * - Launch the core 1 using the RP2350 SIO FIFO mailbox protocol
 * - Sends {0, 0, 1, vtor, sp, pc} sequence and waits for echoes
 *
 */
void    init_launchCore_1(void (*entry)(void)) {
            uint32_t    i, cmd, echo;
    const   uint32_t    vtor   = (uint32_t)(uintptr_t)first_handle_trap;
    const   uint32_t    sp     = (uint32_t)(uintptr_t)linker_topStackFirst_C1;
    const   uint32_t    pc     = (uint32_t)(uintptr_t)entry;
    const   uint32_t    seq[6] = { 0U, 0U, 1U, vtor, sp, pc };

    i = 0U;
    do {
        cmd = seq[i];

// Before each 0 : empty RX + SEV

        if (cmd == 0U) { local_emptyRxFifo(); sev(); }

// Send and waiting for the echo

        local_writeRTxFifo(cmd);
        fence();

        echo = local_readRxFifo();
        i = (echo == cmd) ? (i + 1) : (0);
    } while (i < 6);
}

/*
 * \brief local_emptyRxFifo
 *
 * - Empty the Rx SIO fifo
 *
 */
static  void    local_emptyRxFifo(void) {
    uint8_t     i;

    for (i = 0; i < 8; i++) {
        if ((REG(SIO)->FIFO_ST & SIO_FIFO_ST_VLD) != 0u) {
            (void)REG(SIO)->FIFO_RD;
        }
        else { break; }
    }
}

/*
 * \brief local_writeRTxFifo
 *
 * - Send a word to the Tx SIO fifo
 *
 */
static  void    local_writeRTxFifo(uint32_t data) {

// Waiting for a room in the Tx fifo, and write
// Wake-up the core 1

    while ((REG(SIO)->FIFO_ST & SIO_FIFO_ST_RDY) == 0u) { }
    REG(SIO)->FIFO_WR = data;
    sev();
}

/*
 * \brief local_readRxFifo
 *
 * - Read a word from the Rx SIO fifo
 *
 */
static  uint32_t    local_readRxFifo(void) {

// Waiting for data in the Rx fifo, and read

    while ((REG(SIO)->FIFO_ST & SIO_FIFO_ST_VLD) == 0u) { }
    return (REG(SIO)->FIFO_RD);
}
