/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        Demo of a C application.
 *          Database structure.
 *
 *          Database structure:
 */

#pragma once

#include    "ulvgl.h"
#include    "types.h"

extern  const   char_t  *aClass[];

// Database table
// --------------

#define FILTER_NOT_WELL_CLASSIFIED_S                    // Filter-out the bad recognitions
#undef  PRINT_THE_RESULTS_S                             // Print the results

#ifdef FILTER_NOT_WELL_CLASSIFIED_S
#define KNB_ENTRY       (280U - 24U)

#else
#define KNB_ENTRY       280U
#endif

#define KNB_COLUMNS     11U

typedef struct  dataBase    dataBase_t;

struct  dataBase {
        const   float32_t       oDataSet[KNB_COLUMNS];  // The data
        const   char_t          *oClassLabel;           // The class labels
        const   lv_image_dsc_t  *oClassImage;           // The class image
        };

