/*
; uKOSversion.
; ============

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Universal h file for uKOS-X systems.
;
;   (c) 2025-2026, Laurent von Allmen
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

#pragma	once

// uKOS-X main constants
// -----------------------

#define	uKOS_VERSION_OS			10
#define	uKOS_VERSION_NUMBER		"0.1.219"
#define	uKOS_VERSION_MAJOR		0
#define	uKOS_VERSION_MINOR		1
#define	uKOS_VERSION_REVISION	219
#define	uKOS_VERSION			uKOS_VERSION_NUMBER " " STRG(uKOS_NAME) "\n" STRG(uKOS_OWNER)
