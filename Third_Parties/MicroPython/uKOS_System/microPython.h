/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; microPython.
; ============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     microPython library.
;           uKOS-X interface for MicroPython (www.micropython.com).
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

#include    "types.h"

/*!
 * \addtogroup Third_Parties
 */
/**@{*/

/*!
 * \defgroup microPython MicroPython
 *
 * \brief MicroPython
 *
 * MicroPython management
 *
 * @{
 */

// mpyt access macros
// ------------------

#define MICROPYTHON_CMDLINE     microPython_exchangeData(nullptr);
#define MICROPYTHON_COMPUTE(x)  microPython_exchangeData(x);

// Configuration structure
// -----------------------

typedef struct  microPythonCnf      microPythonCnf_t;

struct microPythonCnf {
            uint32_t    oSize;                                  // Size of the memory
            uint8_t     *oMemory;                               // Ptr on the memory location
};

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

/*!
 * \brief Configure the microPython manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t              status;
 * microPythonCnf_t    configure;
 *
 *    configure.oSize = 90000;
 *    configure.oMemory = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, configure.oSize, "mpyt");
 *    if (configure.oMemory == 0) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 *
 *    status = microPython_configure(&configure);
 * \endcode
 *
 * \param[in]   *configure              Ptr on the configuration buffer
 * \return      KERR_MICROPYTHON_NOERR  OK
 *
 */
extern  int32_t microPython_configure(microPythonCnf_t *configure);

/*!
 * \brief Exchange data with the microPython manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 * const    char_t     myRoutine [] = "def plus(a,b):\n"
 *                                    "    return a + b\n";
 *
 *    status = microPython_exchangeData(nullptr);
 *    status = microPython_exchangeData(myRoutine);
 * \endcode
 *
 * \param[in]   *pyProgram              nullptr = Command line interpreter mode
 * \param[in]   -                       Ptr on the ascii script / program
 * \return      KERR_MICROPYTHON_NOERR  OK
 *
 */
extern  int32_t microPython_exchangeData(const char_t *pyProgram);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
