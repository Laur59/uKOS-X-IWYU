/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     System errors.
 */

#pragma once

#include    <stdint.h>

#include    "modules.h"

// Lib_kernels managers
// ====================

// kern manager errors
// -------------------

// Coding
//                  0x80 ff mm ee
//                  0x80    Negative, error flag
//                  ff      Family Lib
//                  mm      Manager
//                  ee      error code
//
//                          Negative                Family Lib Id                      Manager Id
#define KKERN_ERR           ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_KERNELS<<16U) | ((uint32_t)KNUM_KERN<<8U))

enum : int32_t {
    KERR_KERN_NOERR = 0,                                        // No error
    KERR_KERN_SYCNA = (int32_t)(KKERN_ERR + 1U),                // System call not available
    KERR_KERN_GEERR = (int32_t)(KKERN_ERR + 2U),                // General error
    KERR_KERN_TIMEO = (int32_t)(KKERN_ERR + 3U),                // Timeout error
    KERR_KERN_FRISR = (int32_t)(KKERN_ERR + 4U),                // Execution from ISR
    KERR_KERN_BADCO = (int32_t)(KKERN_ERR + 5U),                // Bad core

    KERR_KERN_LIFUL = (int32_t)(KKERN_ERR + 6U),                // No more process
    KERR_KERN_NOPRO = (int32_t)(KKERN_ERR + 7U),                // The process does not exist
    KERR_KERN_IDPRO = (int32_t)(KKERN_ERR + 8U),                // The process identifier is already used
    KERR_KERN_REFRS = (int32_t)(KKERN_ERR + 9U),                // The first cannot be removed
    KERR_KERN_RESDE = (int32_t)(KKERN_ERR + 10U),                // The system daemons cannot be removed
    KERR_KERN_NOSTK = (int32_t)(KKERN_ERR + 11U),                // No memory for the stack
    KERR_KERN_PRIVI = (int32_t)(KKERN_ERR + 12U),                // Privilege violation

    KERR_KERN_SEFUL = (int32_t)(KKERN_ERR + 13U),                // No more semaphore
    KERR_KERN_NOSEM = (int32_t)(KKERN_ERR + 14U),                // The semaphore does not exist
    KERR_KERN_IDSEM = (int32_t)(KKERN_ERR + 15U),                // The semaphore identifier is already used
    KERR_KERN_SETME = (int32_t)(KKERN_ERR + 16U),                // The semaphore counts too many events
    KERR_KERN_SEKIL = (int32_t)(KKERN_ERR + 17U),                // The semaphore has been killed (with processes in its list)
    KERR_KERN_SENOW = (int32_t)(KKERN_ERR + 18U),                // The process is not the owner of the semaphore

    KERR_KERN_MUFUL = (int32_t)(KKERN_ERR + 19U),                // No more mutex
    KERR_KERN_NOMUT = (int32_t)(KKERN_ERR + 20U),                // The mutex does not exist
    KERR_KERN_IDMUT = (int32_t)(KKERN_ERR + 21U),                // The mutex identifier is already used
    KERR_KERN_MUTME = (int32_t)(KKERN_ERR + 22U),                // The mutex counts too many events
    KERR_KERN_MUKIL = (int32_t)(KKERN_ERR + 23U),                // The mutex has been killed (with processes in its list)
    KERR_KERN_MUNOW = (int32_t)(KKERN_ERR + 24U),                // The process is not the owner of the mutex

    KERR_KERN_MBFUL = (int32_t)(KKERN_ERR + 25U),                // No more mailbox
    KERR_KERN_NOMBO = (int32_t)(KKERN_ERR + 26U),                // The mailbox does not exist
    KERR_KERN_IDMBO = (int32_t)(KKERN_ERR + 27U),                // The mailbox identifier is already used
    KERR_KERN_MBNCF = (int32_t)(KKERN_ERR + 28U),                // The mailbox is not configured
    KERR_KERN_MBCNF = (int32_t)(KKERN_ERR + 29U),                // The mailbox configuration is not possible
    KERR_KERN_MBKIL = (int32_t)(KKERN_ERR + 30U),                // The mailbox has been killed (with processes in its list)
    KERR_KERN_MBSIZ = (int32_t)(KKERN_ERR + 31U),                // The mailbox write in copy mode is larger than the configured data size

    KERR_KERN_SIFUL = (int32_t)(KKERN_ERR + 32U),                // No more signal group
    KERR_KERN_NOSIG = (int32_t)(KKERN_ERR + 33U),                // No more bitSignal
    KERR_KERN_NOGRO = (int32_t)(KKERN_ERR + 34U),                // The signal group does not exist
    KERR_KERN_IDSIO = (int32_t)(KKERN_ERR + 35U),                // The signal group identifier is already used
    KERR_KERN_SIKIL = (int32_t)(KKERN_ERR + 36U),                // The signal group has been killed (with processes in its list)

    KERR_KERN_FLFUL = (int32_t)(KKERN_ERR + 37U),                // No more flag group
    KERR_KERN_NOFLG = (int32_t)(KKERN_ERR + 38U),                // The flag group does not exist
    KERR_KERN_IDFLO = (int32_t)(KKERN_ERR + 39U),                // The flag group identifier is already used
    KERR_KERN_FLKIL = (int32_t)(KKERN_ERR + 40U),                // The signal group has been killed (with processes in its list)

    KERR_KERN_TIFMT = (int32_t)(KKERN_ERR + 41U),                // The absolute time has a wrong format

    KERR_KERN_DBGER = (int32_t)(KKERN_ERR + 42U),                // The process is not (or already) in the debug list
    KERR_KERN_DBNOS = (int32_t)(KKERN_ERR + 43U),                // The process is attached to a sensitive list and cannot be stopped

    KERR_KERN_STFUL = (int32_t)(KKERN_ERR + 44U),                // No more software timer
    KERR_KERN_NOSTI = (int32_t)(KKERN_ERR + 45U),                // The software timer does not exist
    KERR_KERN_IDSTI = (int32_t)(KKERN_ERR + 46U),                // The software timer identifier is already used
    KERR_KERN_CFSTI = (int32_t)(KKERN_ERR + 47U),                // The software timer cannot be configured

    KERR_KERN_POFUL = (int32_t)(KKERN_ERR + 48U),                // No more memory pool
    KERR_KERN_BKFUL = (int32_t)(KKERN_ERR + 49U),                // No more block
    KERR_KERN_NOPOI = (int32_t)(KKERN_ERR + 50U),                // The memory pool does not exist
    KERR_KERN_IDPOI = (int32_t)(KKERN_ERR + 51U),                // The memory pool identifier is already used
    KERR_KERN_PONCF = (int32_t)(KKERN_ERR + 52U),                // The memory pool is not configured
    KERR_KERN_POCNF = (int32_t)(KKERN_ERR + 53U),                // The memory pool configuration is not possible
    KERR_KERN_NOBKI = (int32_t)(KKERN_ERR + 54U),                // The block does not exist

    KERR_KERN_PRFUL = (int32_t)(KKERN_ERR + 55U),                // No more precise signal
    KERR_KERN_NOPRC = (int32_t)(KKERN_ERR + 56U),                // The precise signal does not exist
    KERR_KERN_IDPRC = (int32_t)(KKERN_ERR + 57U)                 // The precise signal identifier is already used
};

// Lib_serials managers
// ====================

// serial manager errors
// ---------------------

//                          Negative                 Family Lib Id                      Manager Id
#define KSERIAL_ERR         ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_SERIALS<<16U) | ((uint32_t)KNUM_SERIAL<<8U))

enum : int32_t {
    KERR_SERIAL_NOERR = 0,                                      // No error
    KERR_SERIAL_SYCNA = (int32_t)(KSERIAL_ERR + 1U),            // System call not available
    KERR_SERIAL_GEERR = (int32_t)(KSERIAL_ERR + 2U),            // General error
    KERR_SERIAL_NODEV = (int32_t)(KSERIAL_ERR + 3U),            // The device does not exist
    KERR_SERIAL_NOCHA = (int32_t)(KSERIAL_ERR + 4U),            // The channel does not exist
    KERR_SERIAL_CHBSY = (int32_t)(KSERIAL_ERR + 5U),            // The manager is busy

    KERR_SERIAL_LNBU0 = (int32_t)(KSERIAL_ERR + 6U),            // The buffer length is = 0
    KERR_SERIAL_LNBUB = (int32_t)(KSERIAL_ERR + 7U),            // The buffer length is too big
    KERR_SERIAL_SBUEM = (int32_t)(KSERIAL_ERR + 8U),            // The sender buffer is empty
    KERR_SERIAL_SBUNE = (int32_t)(KSERIAL_ERR + 9U),            // The sender buffer is not empty
    KERR_SERIAL_SBFUL = (int32_t)(KSERIAL_ERR + 10U),           // The sender buffer is full
    KERR_SERIAL_SEPRO = (int32_t)(KSERIAL_ERR + 11U),           // the sender is busy

    KERR_SERIAL_RBUEM = (int32_t)(KSERIAL_ERR + 12U),           // The receiver buffer is empty
    KERR_SERIAL_RBFUL = (int32_t)(KSERIAL_ERR + 13U),           // The receiver buffer is full
    KERR_SERIAL_EROVR = (int32_t)(KSERIAL_ERR + 14U),           // Overrun error
    KERR_SERIAL_ERNOI = (int32_t)(KSERIAL_ERR + 15U),           // Noise error
    KERR_SERIAL_ERFRA = (int32_t)(KSERIAL_ERR + 16U),           // Framing error
    KERR_SERIAL_ERPAR = (int32_t)(KSERIAL_ERR + 17U),           // Parity error

    KERR_SERIAL_NOCNF = (int32_t)(KSERIAL_ERR + 18U),           // The configuration does not exist
    KERR_SERIAL_NOHAR = (int32_t)(KSERIAL_ERR + 19U),           // Hardware problem
    KERR_SERIAL_TIMEO = (int32_t)(KSERIAL_ERR + 20U),           // Timeout error
    KERR_SERIAL_SENOE = (int32_t)(KSERIAL_ERR + 21U),           // The semaphore does not exist
    KERR_SERIAL_CAREL = (int32_t)(KSERIAL_ERR + 22U)            // Cannot release the manager
};

// Lib_generics managers
// =====================

// asmp manager errors
// -------------------

//                          Negative                 Family Lib Id                       Manager Id
#define KASMP_ERR           ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_GENERICS<<16U) | ((uint32_t)KNUM_ASMP<<8U))

enum : int32_t {
    KERR_ASMP_NOERR = 0,                                        // No error
    KERR_ASMP_SYCNA = (int32_t)(KASMP_ERR + 1U),                // System call not available
    KERR_ASMP_GEERR = (int32_t)(KASMP_ERR + 2U),                // General error
    KERR_ASMP_SBFUL = (int32_t)(KASMP_ERR + 3U),                // The sender buffer is full
    KERR_ASMP_RBUEM = (int32_t)(KASMP_ERR + 4U),                // The receiver buffer is empty
    KERR_ASMP_CORNA = (int32_t)(KASMP_ERR + 5U),                // The core number is not not allowed
    KERR_ASMP_NORDY = (int32_t)(KASMP_ERR + 6U),                // The ASMP is not ready
    KERR_ASMP_LNBUB = (int32_t)(KASMP_ERR + 7U)                 // The buffer length is too big
};

// memo manager errors
// -------------------

//                          Negative                 Family Lib Id                       Manager Id
#define KMEMO_ERR           ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_GENERICS<<16U) | ((uint32_t)KNUM_MEMO<<8U))

enum : int32_t {
    KERR_MEMO_NOERR = 0,                                        // No error
    KERR_MEMO_SYCNA = (int32_t)(KMEMO_ERR + 1U),                // System call not available
    KERR_MEMO_GEERR = (int32_t)(KMEMO_ERR + 2U),                // General error
    KERR_MEMO_NOBKI = (int32_t)(KMEMO_ERR + 3U)                 // The block does not exist
};

// record manager errors
// ---------------------

//                          Negative                 Family Lib Id                       Manager Id
#define KRECORD_ERR         ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_GENERICS<<16U) | ((uint32_t)KNUM_RECORD<<8U))

enum : int32_t {
    KERR_RECORD_NOERR = 0,                                      // No error
    KERR_RECORD_SYCNA = (int32_t)(KRECORD_ERR + 1U),            // System call not available
    KERR_RECORD_GEERR = (int32_t)(KRECORD_ERR + 2U)             // General error
};

// system manager errors
// ---------------------

//                          Negative                 Family Lib Id                       Manager Id
#define KSYSTEM_ERR         ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_GENERICS<<16U) | ((uint32_t)KNUM_SYSTEM<<8U))

enum : int32_t {
    KERR_SYSTEM_NOERR = 0,                                      // No error
    KERR_SYSTEM_SYCNA = (int32_t)(KSYSTEM_ERR + 1U),            // System call not available
    KERR_SYSTEM_GEERR = (int32_t)(KSYSTEM_ERR + 2U),            // General error
    KERR_SYSTEM_NOMOD = (int32_t)(KSYSTEM_ERR + 3U),            // The module does not exist
    KERR_SYSTEM_NOFAM = (int32_t)(KSYSTEM_ERR + 4U),            // The family does not exist
    KERR_SYSTEM_NOMEM = (int32_t)(KSYSTEM_ERR + 5U),            // The memory unit does not exist
    KERR_SYSTEM_NOBLK = (int32_t)(KSYSTEM_ERR + 6U),            // The memory block does not exist
    KERR_SYSTEM_SZBLK = (int32_t)(KSYSTEM_ERR + 7U),            // The size of the block is too small
    KERR_SYSTEM_CHBSY = (int32_t)(KSYSTEM_ERR + 8U),            // The manager is busy
    KERR_SYSTEM_CAREL = (int32_t)(KSYSTEM_ERR + 9U)             // Cannot release the manager
};

// machine manager errors
// ---------------------

//                          Negative                 Family Lib Id                       Manager Id
#define KMACHINE_ERR        ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_GENERICS<<16U) | ((uint32_t)KNUM_MACHINE<<8U))

enum : int32_t {
    KERR_MACHINE_NOERR = 0,                                     // No error
    KERR_MACHINE_SYCNA = (int32_t)(KMACHINE_ERR + 1U),          // System call not available
    KERR_MACHINE_GEERR = (int32_t)(KMACHINE_ERR + 2U)           // General error
};

// text manager errors
// -------------------

//                          Negative                 Family Lib Id                       Manager Id
#define KTEXT_ERR           ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_GENERICS<<16U) | ((uint32_t)KNUM_TEXT<<8U))

enum : int32_t {
    KERR_TEXT_NOERR = 0,                                        // No error
    KERR_TEXT_SYCNA = (int32_t)(KTEXT_ERR + 1U),                // System call not available
    KERR_TEXT_GEERR = (int32_t)(KTEXT_ERR + 2U)                 // General error
};

// calendar manager errors
// -----------------------

//                          Negative                 Family Lib Id                       Manager Id
#define KCALENDAR_ERR       ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_GENERICS<<16U) | ((uint32_t)KNUM_CALENDAR<<8U))

enum : int32_t {
    KERR_CALENDAR_NOERR = 0,                                    // No error
    KERR_CALENDAR_SYCNA = (int32_t)(KCALENDAR_ERR + 1U),        // System call not available
    KERR_CALENDAR_GEERR = (int32_t)(KCALENDAR_ERR + 2U)         // General error
};

// newlib manager errors
// ---------------------

//                          Negative                 Family Lib Id                       Manager Id
#define KNEWLIB_ERR         ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_GENERICS<<16U) | ((uint32_t)KNUM_NEWLIB<<8U))

enum : int32_t {
    KERR_NEWLIB_NOERR = 0                                       // No error
};

// Lib_neurals managers
// ====================

// mlpn manager errors
// -------------------

//                          Negative                 Family Lib Id                      Manager Id
#define KMLPN_ERR           ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_NEURALS<<16U) | ((uint32_t)KNUM_MLPN<<8U))

enum : int32_t {
    KERR_MLPN_NOERR = 0,                                        // No error
    KERR_MLPN_SYCNA = (int32_t)(KMLPN_ERR + 1U),                // System call not available
    KERR_MLPN_GEERR = (int32_t)(KMLPN_ERR + 2U),                // General error
    KERR_MLPN_CNERR = (int32_t)(KMLPN_ERR + 3U),                // Configuration error
    KERR_MLPN_TIMEO = (int32_t)(KMLPN_ERR + 4U),                // Timeout error
    KERR_MLPN_CHBSY = (int32_t)(KMLPN_ERR + 5U),                // The manager is busy
    KERR_MLPN_NOMEM = (int32_t)(KMLPN_ERR + 6U),                // Not enough memory
    KERR_MLPN_CAREL = (int32_t)(KMLPN_ERR + 7U)                 // Cannot release the manager
};

// Lib_peripherals managers
// ========================

// adc manager errors
// ------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KADC_ERR            ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_ADC<<8U))

enum : int32_t {
    KERR_ADC_NOERR = 0,                                         // No error
    KERR_ADC_SYCNA = (int32_t)(KADC_ERR + 1U),                  // System call not available
    KERR_ADC_GEERR = (int32_t)(KADC_ERR + 2U),                  // General error
    KERR_ADC_CHBSY = (int32_t)(KADC_ERR + 3U),                  // The manager is busy
    KERR_ADC_NODEV = (int32_t)(KADC_ERR + 4U),                  // The device does not exist
    KERR_ADC_CAREL = (int32_t)(KADC_ERR + 5U)                   // Cannot release the manager
};

// battery manager errors
// ----------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KBATTERY_ERR        ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_BATTERY<<8U))

enum : int32_t {
    KERR_BATTERY_NOERR = 0,                                     // No error
    KERR_BATTERY_SYCNA = (int32_t)(KBATTERY_ERR + 1U),          // System call not available
    KERR_BATTERY_GEERR = (int32_t)(KBATTERY_ERR + 2U),          // General error
    KERR_BATTERY_CHBSY = (int32_t)(KBATTERY_ERR + 3U),          // The manager is busy
    KERR_BATTERY_CAREL = (int32_t)(KBATTERY_ERR + 4U)           // Cannot release the manager
};

// i2c manager errors
// ------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KI2C_ERR            ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_I2C<<8U))

enum : int32_t {
    KERR_I2C_NOERR = 0,                                         // No error
    KERR_I2C_SYCNA = (int32_t)(KI2C_ERR + 1U),                  // System call not available
    KERR_I2C_GEERR = (int32_t)(KI2C_ERR + 2U),                  // General error
    KERR_I2C_NODEV = (int32_t)(KI2C_ERR + 3U),                  // The device does not exist
    KERR_I2C_CHBSY = (int32_t)(KI2C_ERR + 4U),                  // The manager is busy
    KERR_I2C_TIMEO = (int32_t)(KI2C_ERR + 5U),                  // Timeout error
    KERR_I2C_SENOE = (int32_t)(KI2C_ERR + 6U),                  // The semaphore does not exist
    KERR_I2C_CAREL = (int32_t)(KI2C_ERR + 7U)                   // Cannot release the manager
};

// imager manager errors
// ---------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KIMAGER_ERR         ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_IMAGER<<8U))

enum : int32_t {
    KERR_IMAGER_NOERR = 0,                                      // No error
    KERR_IMAGER_SYCNA = (int32_t)(KIMAGER_ERR + 1U),            // System call not available
    KERR_IMAGER_GEERR = (int32_t)(KIMAGER_ERR + 2U),            // General error
    KERR_IMAGER_CNERR = (int32_t)(KIMAGER_ERR + 3U),            // Configuration error
    KERR_IMAGER_TIMEO = (int32_t)(KIMAGER_ERR + 4U),            // Timeout error
    KERR_IMAGER_CHBSY = (int32_t)(KIMAGER_ERR + 5U),            // The manager is busy
    KERR_IMAGER_PGNOE = (int32_t)(KIMAGER_ERR + 6U),            // The image page does not exist
    KERR_IMAGER_BDMOD = (int32_t)(KIMAGER_ERR + 7U),            // Bad mode for called function
    KERR_IMAGER_NOMEM = (int32_t)(KIMAGER_ERR + 8U),            // Not enough memory
    KERR_IMAGER_CAREL = (int32_t)(KIMAGER_ERR + 9U)             // Cannot release the manager
};

// imu manager errors
// ------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KIMU_ERR            ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_IMU<<8U))

enum : int32_t {
    KERR_IMU_NOERR = 0,                                         // No error
    KERR_IMU_SYCNA = (int32_t)(KIMU_ERR + 1U),                  // System call not available
    KERR_IMU_GEERR = (int32_t)(KIMU_ERR + 2U),                  // General error
    KERR_IMU_CHBSY = (int32_t)(KIMU_ERR + 3U),                  // The manager is busy
    KERR_IMU_CAREL = (int32_t)(KIMU_ERR + 4U)                   // Cannot release the manager
};

// spi manager errors
// ------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KSPI_ERR            ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_SPI<<8U))

enum : int32_t {
    KERR_SPI_NOERR = 0,                                         // No error
    KERR_SPI_SYCNA = (int32_t)(KSPI_ERR + 1U),                  // System call not available
    KERR_SPI_GEERR = (int32_t)(KSPI_ERR + 2U),                  // General error
    KERR_SPI_NODEV = (int32_t)(KSPI_ERR + 3U),                  // The device does not exist
    KERR_SPI_CHBSY = (int32_t)(KSPI_ERR + 4U),                  // The manager is busy
    KERR_SPI_TIMEO = (int32_t)(KSPI_ERR + 5U),                  // Timeout error
    KERR_SPI_SENOE = (int32_t)(KSPI_ERR + 6U),                  // The semaphore does not exist
    KERR_SPI_CAREL = (int32_t)(KSPI_ERR + 7U)                   // Cannot release the manager
};

// temperature manager errors
// --------------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KTEMPERATURE_ERR    ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_TEMPERATURE<<8U))

enum : int32_t {
    KERR_TEMPERATURE_NOERR = 0,                                 // No error
    KERR_TEMPERATURE_SYCNA = (int32_t)(KTEMPERATURE_ERR + 1U),  // System call not available
    KERR_TEMPERATURE_GEERR = (int32_t)(KTEMPERATURE_ERR + 2U),  // General error
    KERR_TEMPERATURE_CHBSY = (int32_t)(KTEMPERATURE_ERR + 3U),  // The manager is busy
    KERR_TEMPERATURE_CAREL = (int32_t)(KTEMPERATURE_ERR + 4U)   // Cannot release the manager
};

// wdog manager errors
// -------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KWATCHDOG_ERR       ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_WATCHDOG<<8U))

enum : int32_t {
    KERR_WATCHDOG_NOERR = 0                                     // No error
};

// led manager errors
// ------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KLED_ERR            ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_LED<<8U))

enum : int32_t {
    KERR_LED_NOERR = 0,                                         // No error
    KERR_LED_SYCNA = (int32_t)(KLED_ERR + 1U),                  // System call not available
    KERR_LED_GEERR = (int32_t)(KLED_ERR + 2U),                  // General error
    KERR_LED_NODEV = (int32_t)(KLED_ERR + 3U)                   // The device does not exist
};

// switch manager errors
// ---------------------

//                          Negative                 Family Lib Id                          Manager Id
#define KSWITCH_ERR         ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<16U) | ((uint32_t)KNUM_SWITCH<<8U))

enum : int32_t {
    KERR_SWITCH_NOERR = 0,                                      // No error
    KERR_SWITCH_SYCNA = (int32_t)(KSWITCH_ERR + 1U),            // System call not available
    KERR_SWITCH_GEERR = (int32_t)(KSWITCH_ERR + 2U)             // General error
};

// Lib_cryptographics managers
// ===========================

// rand manager errors
// -------------------

//                          Negative                 Family Lib Id                             Manager Id
#define KRANDOM_ERR         ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_CRYPTOGRAPHICS<<16U) | ((uint32_t)KNUM_RANDOM<<8U))

enum : int32_t {
    KERR_RANDOM_NOERR = 0,                                      // No error
    KERR_RANDOM_SYCNA = (int32_t)(KRANDOM_ERR + 1U),            // System call not available
    KERR_RANDOM_GEERR = (int32_t)(KRANDOM_ERR + 2U)             // General error
};

// Lib_storages managers
// =====================

// storage manager errors
// ----------------------

//                          Negative                 Family Lib Id                      Manager Id
#define KSTORAGE_ERR        ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_STORAGE<<16U) | ((uint32_t)KNUM_STORAGE<<8U))

enum : int32_t {
    KERR_STORAGE_NOERR = 0,                                     // No error
    KERR_STORAGE_SYCNA = (int32_t)(KSTORAGE_ERR + 1U),          // System call not available
    KERR_STORAGE_GEERR = (int32_t)(KSTORAGE_ERR + 2U),          // General error
    KERR_STORAGE_CHBSY = (int32_t)(KSTORAGE_ERR + 3U),          // The manager is busy
    KERR_STORAGE_NODEV = (int32_t)(KSTORAGE_ERR + 4U),          // The device does not exist
    KERR_STORAGE_CANRE = (int32_t)(KSTORAGE_ERR + 5U),          // Device not recognised
    KERR_STORAGE_LNBU0 = (int32_t)(KSTORAGE_ERR + 6U),          // The number of sectors is = 0
    KERR_STORAGE_TRANT = (int32_t)(KSTORAGE_ERR + 7U),          // Transfer not terminated
    KERR_STORAGE_CAREL = (int32_t)(KSTORAGE_ERR + 8U),          // Cannot release the manager
    KERR_STORAGE_NOEMP = (int32_t)(KSTORAGE_ERR + 9U)           // the device is not empty
};

// Third parties libraries
// =======================

// micropython library errors
// --------------------------

//                          Negative                 Family Lib Id                            Manager Id
#define KMICROPYTHON_ERR    ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_THIRD_PARTIES<<16U) | ((uint32_t)KNUM_MICROPYTHON<<8U))

enum : int32_t {
    KERR_MICROPYTHON_NOERR = 0,                                 // No error
    KERR_MICROPYTHON_SYCNA = (int32_t)(KMICROPYTHON_ERR + 1U),  // System call not available
    KERR_MICROPYTHON_GEERR = (int32_t)(KMICROPYTHON_ERR + 2U)   // General error
};
