/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; PF1550.
; =======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     NXP PF1550 equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// I2c interface

#define KI2C_ADD_PF1550                     0x08U                           // I2C PF1550 address

// PF1550 initialisation table

typedef struct  pf1550  pf1550_t;

struct  pf1550 {
            uint8_t     oRegister;                                          // I2C register
            uint8_t     oData;                                              // I2C data
            uint32_t    oDelay;                                             // Delay
        };

#define KPF1550_NB_MONO                     2U                              //

// I2c interface


// PF1550 registers

#define PF1550_DEVICE_ID                    0x00U                           //
#define PF1550_OTP_FLAVOR                   0x01U                           //
#define PF1550_SILICON_REV                  0x02U                           //
#define PF1550_INT_CATEGORY                 0x06U                           //
#define PF1550_SW_INT_STAT0                 0x08U                           //
#define PF1550_SW_INT_MASK0                 0x09U                           //
#define PF1550_SW_INT_SENSE0                0x0AU                           //
#define PF1550_SW_INT_STAT1                 0x0BU                           //
#define PF1550_SW_INT_MASK1                 0x0CU                           //
#define PF1550_SW_INT_SENSE1                0x0DU                           //
#define PF1550_SW_INT_STAT2                 0x0EU                           //
#define PF1550_SW_INT_MASK2                 0x0FU                           //
#define PF1550_SW_INT_SENSE2                0x10U                           //
#define PF1550_LDO_INT_STAT0                0x18U                           //
#define PF1550_LDO_INT_MASK0                0x19U                           //
#define PF1550_LDO_INT_SENSE0               0x1AU                           //
#define PF1550_TEMP_INT_STAT0               0x20U                           //
#define PF1550_TEMP_INT_MASK0               0x21U                           //
#define PF1550_TEMP_INT_SENSE0              0x22U                           //
#define PF1550_ONKEY_INT_STAT0              0x24U                           //
#define PF1550_ONKEY_INT_MASK0              0x25U                           //
#define PF1550_ONKEY_INT_SENSE0             0x26U                           //
#define PF1550_MISC_INT_STAT0               0x28U                           //
#define PF1550_MISC_INT_MASK0               0x29U                           //
#define PF1550_MISC_INT_SENSE0              0x2AU                           //
#define PF1550_COINCELL_CONTROL             0x30U                           //
#define PF1550_SW1_VOLT                     0x32U                           //
#define PF1550_SW1_STBY_VOLT                0x33U                           //
#define PF1550_SW1_SLP_VOLT                 0x34U                           //
#define PF1550_SW1_CTRL                     0x35U                           //
#define PF1550_SW1_CTRL1                    0x36U                           //
#define PF1550_SW2_VOLT                     0x38U                           //
#define PF1550_SW2_STBY_VOLT                0x39U                           //
#define PF1550_SW2_SLP_VOLT                 0x3AU                           //
#define PF1550_SW2_CTRL                     0x3BU                           //
#define PF1550_SW2_CTRL1                    0x3CU                           //
#define PF1550_SW3_VOLT                     0x3EU                           //
#define PF1550_SW3_STBY_VOLT                0x3FU                           //
#define PF1550_SW3_SLP_VOLT                 0x40U                           //
#define PF1550_SW3_CTRL                     0x41U                           //
#define PF1550_SW3_CTRL1                    0x42U                           //
#define PF1550_VSNVS_CTRL                   0x48U                           //
#define PF1550_VREFDDR_CTRL                 0x4AU                           //
#define PF1550_LDO1_VOLT                    0x4CU                           //
#define PF1550_LDO1_CTRL                    0x4DU                           //
#define PF1550_LDO2_VOLT                    0x4FU                           //
#define PF1550_LDO2_CTRL                    0x50U                           //
#define PF1550_LDO3_VOLT                    0x52U                           //
#define PF1550_LDO3_CTRL                    0x53U                           //
#define PF1550_PWRCTRL0                     0x58U                           //
#define PF1550_PWRCTRL1                     0x59U                           //
#define PF1550_PWRCTRL2                     0x5AU                           //
#define PF1550_PWRCTRL3                     0x5BU                           //
#define PF1550_SW1_PWRDN_SEQ                0x5FU                           //
#define PF1550_SW2_PWRDN_SEQ                0x60U                           //
#define PF1550_LDO1_PWRDN_SEQ               0x62U                           //
#define PF1550_LDO2_PWRDN_SEQ               0x63U                           //
#define PF1550_LDO3_PWRDN_SEQ               0x64U                           //
#define PF1550_VREFDDR_PWRDN_SEQ            0x65U                           //
#define PF1550_STATE_INFO                   0x67U                           //
#define PF1550_I2C_ADDR                     0x68U                           //
#define PF1550_RC_16MHZ                     0x6BU                           //
#define PF1550_KEY1                         0x6BU                           //
#define PF1550_CHG_INT                      (0x80U + 0x00U)                 //
#define PF1550_CHG_INT_MASK                 (0x80U + 0x02U)                 //
#define PF1550_CHG_INT_OK                   (0x80U + 0x04U)                 //
#define PF1550_VBUS_SNS                     (0x80U + 0x06U)                 //
#define PF1550_CHG_SNS                      (0x80U + 0x07U)                 //
#define PF1550_BATT_SNS                     (0x80U + 0x08U)                 //
#define PF1550_CHG_OPER                     (0x80U + 0x09U)                 //
#define PF1550_CHG_TMR                      (0x80U + 0x0AU)                 //
#define PF1550_CHG_EOC_CNFG                 (0x80U + 0x0DU)                 //
#define PF1550_CHG_CURR_CNFG                (0x80U + 0x0EU)                 //
#define PF1550_BATT_REG                     (0x80U + 0x0FU)                 //
#define PF1550_BATFET_CNFG                  (0x80U + 0x11U)                 //
#define PF1550_THM_REG_CNFG                 (0x80U + 0x12U)                 //
#define PF1550_VBUS_INLIM_CNFG              (0x80U + 0x14U)                 //
#define PF1550_VBUS_LIN_DPM                 (0x80U + 0x15U)                 //
#define PF1550_USB_PHY_LDO_CNFG             (0x80U + 0x16U)                 //
#define PF1550_DBNC_DELAY_TIME              (0x80U + 0x18U)                 //
#define PF1550_CHG_INT_CNFG                 (0x80U + 0x19U)                 //
#define PF1550_THM_ADJ_SETTING              (0x80U + 0x1AU)                 //
#define PF1550_VBUS2SYS_CNFG                (0x80U + 0x1BU)                 //
#define PF1550_LED_PWM                      (0x80U + 0x1CU)                 //
#define PF1550_FAULT_BATFET_CNFG            (0x80U + 0x1DU)                 //
#define PF1550_LED_CNFG                     (0x80U + 0x1EU)                 //
#define PF1550_LED_CNFG2                    (0x80U + 0x1FU)                 //
