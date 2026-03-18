/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Implementation file for the TestClass process manager.
 */

#include    "demo_class.hpp"

#include    <stdio.h>

#include    "serial/serial.h"


// Constructor implementation
TestClass::TestClass() {
    (void)dprintf(KSYST, "Construction\n");
}

// Destructor implementation
TestClass::~TestClass() {
    (void)dprintf(KSYST, "Destruction\n");
}

// doit method implementation
void TestClass::doit() const {
    (void)dprintf(KSYST, "in the middle\n");
}
