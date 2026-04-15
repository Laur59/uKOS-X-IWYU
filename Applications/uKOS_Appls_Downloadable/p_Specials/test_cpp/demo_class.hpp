/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Header file for the TestClass process manager.
 */

#pragma once

#include	<cstdint>
#include	<cinttypes>

/**
 * \brief TestClass - A simple test class for demonstrating C++ in uKOS-X
 *
 * This class demonstrates basic C++ functionality within the uKOS-X environment,
 * including constructor/destructor calls and debug output via dprintf.
 */
class TestClass {
public:
	/**
	 * \brief Constructor - outputs construction message
	 */
	TestClass();

	/**
	 * \brief Destructor - outputs destruction message
	 */
	~TestClass();

	/**
	 * \brief Test method - outputs a message
	 */
	void doit() const;

private:
	uint32_t	counter_;
};
