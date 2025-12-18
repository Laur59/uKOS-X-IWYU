/*
; demo_class.
; ===========

;------------------------------------------------------------------------
; Author:	Laurent von Allmen		The 2025-07-05
; Modifs:
;
; Project:	uKOS-X
; Goal:		Header file for the TestClass process manager.
;
;   (c) 2025-20xx, Laurent von Allmen
;   ---------------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Licensed to the Apache Software Foundation (ASF) under one or more
;   contributor license agreements. See the NOTICE file distributed with
;   this work for additional information regarding copyright ownership.
;   The ASF licenses this file to you under the Apache License, Version 2.0
;   (the "License"); you may not use this file except in compliance with
;   the License. You may obtain a copy of the License at
;
;     http://www.apache.org/licenses/LICENSE-2.0
;
;   Unless required by applicable law or agreed to in writing, software
;   distributed under the License is distributed on an "AS IS" BASIS,
;   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;   See the License for the specific language governing permissions and
;   limitations under the License.
;
;------------------------------------------------------------------------
*/

#pragma once

// uKOS-X specific headers for dprintf and other functions
#include	"types.h"
#include	"os_errors.h"
#include	"macros.h"
#include	"kern/kern.h"
#include	"lib_generics.h"
#include	"serial/serial.h"

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
	void doit();
}; 
