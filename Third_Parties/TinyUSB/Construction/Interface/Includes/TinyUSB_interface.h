/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Interface of the system to the TinyUSB device classes (cdc, msc, video).
 *
 * The functions are defined by the models of Interface/Models, which the
 * TinyUSB stub of a board compiles into the system image. Their users - the
 * cdc managers, the viewer, the downloadable applications - have to take
 * the declarations from here: a downloadable application is linked against
 * the system by symbol name only, so a prototype written by hand that has
 * drifted from the definition is caught neither by the compiler nor by the
 * linker.
 */

#pragma once

#include    <stdint.h>

#if (defined(__cplusplus))
extern  "C" {
#endif

// cdc
// ---

extern  void    TinyUSB_cdc_init(void);
extern  void    TinyUSB_cdc_clean(void);
extern  void    TinyUSB_cdc_write(uint8_t itf, const uint8_t *buffer, uint32_t size);
extern  void    TinyUSB_cdc_read(uint8_t itf, uint8_t *buffer, uint32_t *size);
extern  bool    TinyUSB_cdc_isConnected(uint8_t itf);

// msc
// ---

extern  void    TinyUSB_msc_init(void);
extern  void    TinyUSB_msc_clean(void);

// video
// -----

extern  void    TinyUSB_video_init(void);
extern  void    TinyUSB_video_clean(void);
extern  void    TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);

// Return true when a host took the picture: without a host that streams,
// nothing is sent and the call only waits 10-ms

extern  bool    TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h, void (*callBack)(const void *argument), const void *argument);

#if (defined(__cplusplus))
}
#endif
