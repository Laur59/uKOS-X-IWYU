/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     nrf5340 equates.
 */

#pragma once

// IWYU pragma: begin_exports

#ifdef CPU_APPLICATION_S
#include    "soc_vectors_application.h"
#else
#include    "soc_vectors_network.h"
#endif

// IWYU pragma: end_exports
