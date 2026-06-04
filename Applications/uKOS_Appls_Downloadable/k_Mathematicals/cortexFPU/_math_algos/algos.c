/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Demo of a C application.
 * This application shows how to operate with the uKOS-X uKernel.
 *
 *           Compute Pi with the Lambert & Spigot series:
 *
 *           - Lambert algorithm:
 *           - Pi = sqrt(6 * (1/1^2 + 1/2^2 + 1/3^2 +...)
 *
 *           - Spigot algorithm:
 *           - Pi = Sum 1/16^^n * (4/(8n + 1) - 2/(8n + 4) - 1/(8n + 5) - 1/(8n + 6))
 *     - Pi = Sum 1/16^^n * (4/(8n + 1) - 2/(8n + 4) - 1/(8n + 5) - 1/(8n + 6))
 *
 */

#include    <math.h>

#include    "types.h"
#include    "os_errors.h"
#include    "macros.h"

/*
 * \brief pi_lambert
 *
 * - Lambert algorithm:
 *  - Pi = sqrt(6 * (1/1^2 + 1/2^2 + 1/3^2 +...)
 *
 */
float64_t   pi_lambert(float64_t index, float64_t oldPi) {
    UNUSED(oldPi);

            float64_t   pi;
    static  float64_t   v = 0.0;

    v = v + (1.0 / pow(index, 2));
    pi = sqrt(v * 6);
    return pi;
}

/*
 * \brief pi_spigot
 *
 * - Spigot algorithm:
 *  - Pi = Sum 1/16^^n * (4/(8n + 1) - 2/(8n + 4) - 1/(8n + 5) - 1/(8n + 6))
 *
 */
float64_t   pi_spigot(float64_t index, float64_t oldPi) {
    float64_t   pi;

    pi = oldPi + ((1.0 / pow(16.0, index)) *
               ((4.0 / ((8.0 * index) + 1.0))
               - (2.0 / ((8.0 * index) + 4.0))
               - (1.0 / ((8.0 * index) + 5.0))
               - (1.0 / ((8.0 * index) + 6.0))));

    return pi;
}
