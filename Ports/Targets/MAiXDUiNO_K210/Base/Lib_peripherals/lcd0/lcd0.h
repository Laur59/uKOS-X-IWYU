/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; lcd0.
; =====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     lcd0 manager.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup lcd0 Lcd0
 *
 * \brief Lcd0
 *
 * Lcd0 management
 *
 * @{
 */

#include    <stdint.h>

#include    "modules.h"
#include    "types.h"

#define KLCD0_NUM   (((uint32_t)'_'<<8U) + (uint32_t)'2')
#define KLCD0MAN    (KLCD0_NUM<<8U)

// Semaphores
// ----------

#define KLCD0_MUTEX_RESERVE     "Reserve_lcd0"

// NT35310 TFT controller commands

// LCD dimensions

#define KLCD_X_MAX      240U
#define KLCD_Y_MAX      320U

// LCD colors

#define KBLACK          0x0000U
#define KNAVY           0x000FU
#define KDARKGREEN      0x03E0U
#define KDARKCYAN       0x03EFU
#define KMAROON         0x7800U
#define KPURPLE         0x780FU
#define KOLIVE          0x7BE0U
#define KLIGHTGREY      0xC618U
#define KDARKGREY       0x7BEFU
#define KBLUE           0x001FU
#define KGREEN          0x07E0U
#define KCYAN           0x07FFU
#define KRED            0xF800U
#define KMAGENTA        0xF81FU
#define KYELLOW         0xFFE0U
#define KWHITE          0xFFFFU
#define KORANGE         0xFD20U
#define KGREENYELLOW    0xAFE5U
#define KPINK           0xF81FU
#define KUSER_COLOR     0xAA55U

// LCD directions

#define KDIR_XY_RLUD    0x00U
#define KDIR_YX_RLUD    0x20U
#define KDIR_XY_LRUD    0x40U
#define KDIR_YX_LRUD    0x60U
#define KDIR_XY_RLDU    0x80U
#define KDIR_YX_RLDU    0xA0U
#define KDIR_XY_LRDU    0xC0U
#define KDIR_YX_LRDU    0xE0U
#define KDIR_XY_MASK    0x20U
#define KDIR_MASK       0xE0U

// LCD control structure
// ---------------------

typedef struct  lcdCtl {
    uint8_t     mode;
    uint8_t     direction;
    uint16_t    width;
    uint16_t    height;
} lcdCtl_t;

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

#define LCD0_reserve    lcd0_reserve
#define LCD0_release    lcd0_release

/*!
 * \brief Reserve the lcd0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = lcd0_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    lcd0_xyz();
 *    ....
 *    status = lcd0_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode     Any mode
 * \param[in]   timeout         Timeout (1-ms of resolution)
 * \return      KERR_LCD0_NOERR The manager is reserved
 * \return      KERR_LCD0_GEERR General error
 * \return      KERR_LCD0_CHBSY The manager is busy
 *
 */
extern  int32_t lcd0_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the lcd0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = lcd0_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode     Any mode
 * \return      KERR_LCD0_NOERR OK
 * \return      KERR_LCD0_GEERR General error
 * \return      KERR_LCD0_CAREL Cannot release the manager
 *
 */
extern  int32_t lcd0_release(reserveMode_t reserveMode);

/*!
 * \brief Set the writing direction
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_setDirection(DIR_XY_RLUD);
 * \endcode
 *
 * \param[in]   direction       Writing direction
 * \return      KERR_LCD0_NOERR OK
 * \return      KERR_LCD0_GEERR General error
 *
 */
extern  int32_t lcd0_setDirection(uint8_t direction);

/*!
 * \brief Set the draw point
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawPoint(0, 0, 10, 10, MAGENTA);
 * \endcode
 *
 * \param[in]   x               X0 coordinate
 * \param[in]   y               y0 coordinate
 * \param[in]   color           Pixel color
 * \return      KERR_LCD0_NOERR OK
 * \return      KERR_LCD0_GEERR General error
 *
 */
extern  int32_t lcd0_drawPoint(uint16_t x, uint16_t y, uint16_t color);

/*!
 * \brief Draw a string
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawString(0, 0, 'a', MAGENTA);
 * \endcode
 *
 * \param[in]   x               X coordinate
 * \param[in]   y               Y coordinate
 * \param[in]   *s              Ptr on the string
 * \param[in]   color           Pixel color
 * \return      KERR_LCD0_NOERR OK
 * \return      KERR_LCD0_GEERR General error
 *
 */
extern  int32_t lcd0_drawString(uint16_t x, uint16_t y, const char *s, uint16_t color);

/*!
 * \brief Draw a RAM string
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawRamString(0, 0, 'a', MAGENTA);
 * \endcode
 *
 * \param[in]   *s              Ptr on the string
 * \param[in]   *area           Ptr on the RAM area
 * \param[in]   fntColor        Font color
 * \param[in]   bgdColor        Background color
 * \return      KERR_LCD0_NOERR OK
 * \return      KERR_LCD0_GEERR General error
 *
 */
extern  int32_t lcd0_drawRamString(const char *s, uint32_t *area, uint16_t fntColor, uint16_t bgdColor);

/*!
 * \brief Clear the lcd (fill with a color)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_clear(0, 0, 'a', MAGENTA);
 * \endcode
 *
 * \param[in]   color           Color
 * \return      KERR_LCD0_NOERR OK
 * \return      KERR_LCD0_GEERR General error
 *
 */
extern  int32_t lcd0_clear(uint16_t color);

/*!
 * \brief Draw a rectangle
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawRectangle(0, 0, 10, 10, MAGENTA);
 * \endcode
 *
 * \param[in]   x0              X0 coordinate
 * \param[in]   y0              y0 coordinate
 * \param[in]   x1              X1 coordinate
 * \param[in]   y1              y1 coordinate
 * \param[in]   width           Rectangle with
 * \param[in]   color           Pixel color
 * \return      KERR_LCD0_NOERR OK
 * \return      KERR_LCD0_GEERR General error
 *
 */
extern  int32_t lcd0_drawRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t width, uint16_t color);

/*!
 * \brief Draw a picture
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawPicture(0, 0, 10, 10, MAGENTA);
 * \endcode
 *
 * \param[in]   x               X coordinate
 * \param[in]   y               y coordinate
 * \param[in]   width           Width
 * \param[in]   height          Height
 * \param[in]   *area           Ptr on the area
 * \return      KERR_LCD0_NOERR OK
 * \return      KERR_LCD0_GEERR General error
 *
 */
extern  int32_t lcd0_drawPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint16_t *area);

#ifdef __cplusplus
}
#endif

// lcd0 manager errors
// -------------------

//                  Negative                 Family Lib Id                          Lib Id xx (error)
#define KLCD0ERR    ((uint32_t)0x80000000U | ((uint32_t)KID_FAM_PERIPHERALS<<24U) | KLCD0MAN)

enum : int32_t {
    KERR_LCD0_NOERR = 0,                            // No error
    KERR_LCD0_SYCNA = (int32_t)(KLCD0ERR + 1U),     // System call not available
    KERR_LCD0_GEERR,                                // General error
    KERR_LCD0_CHBSY,                                // The manager is busy
    KERR_LCD0_CAREL                                 // Cannot release the manager
};

/**@}*/
/**@}*/
