# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-12-22
# Modifs:
#
# Project:	uKOS-X
# Goal:		Umbrella CMake file to fetch upstream IntelRDFPMath and build all libraries
#
# Description:
#			This umbrella CMakeLists.txt performs two main tasks:
#			1. Fetches the upstream IntelRDFPMath repository from GitHub
#			2. Builds all IntelRDFPMath static libraries for supported architectures
#
#			It replaces the functionality of build.sh lines 91-97 using
#			CMake's FetchContent module to download and prepare the IntelRDFPMath
#			source code.
#
#			Usage:
#				cd Third_Parties/IntelRDFPMath
#				cmake -S . -B build
#				cmake --build build
#
#			This will:
#				- Clone/fetch IntelRDFPMath from https://github.com/xmake-mirror/IntelRDFPMathLib
#				- Checkout specific commit hash
#				- Build all libraries for supported architectures
#
#	Copyright 2025-2026, Laurent von Allmen
#	---------------------------------------
#											   __ ______  _____
#	Edo. Franzi							__	__/ //_/ __ \/ ___/
#	5-Route de Cheseaux				   / / / / ,< / / / /\__ \
#	CH 1400 Cheseaux-Noréaz			  / /_/ / /| / /_/ /___/ /
#									  \__,_/_/ |_\____//____/
#	edo.franzi@ukos.ch
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.26)

project(IntelRDFPMath_Package
	VERSION 2.3
	DESCRIPTION "Intel RDFP Math package with upstream source fetch"
	LANGUAGES NONE
)

# Include FetchContent module for downloading upstream IntelRDFPMath
include(FetchContent)

message("╔════════════════════════════════════════════════════════════╗")
message("║         Intel RDFP Math Package Build System               ║")
message("║      Fetching upstream + Building all architectures        ║")
message("╚════════════════════════════════════════════════════════════╝")
message("")

#------------------------------------------------------------------------
# Step 1: Fetch upstream IntelRDFPMath repository
#------------------------------------------------------------------------

# Package version and commit hash (matching build.sh)
set(INTELRDFPMATH_VERSION "2.3")
set(INTELRDFPMATH_HASH "ffca6d2")

message(STATUS "Fetching IntelRDFPMath version ${INTELRDFPMATH_VERSION} (commit ${INTELRDFPMATH_HASH})")

FetchContent_Declare(
	IntelRDFPMath_Upstream
	GIT_REPOSITORY https://github.com/xmake-mirror/IntelRDFPMathLib
	GIT_TAG        ${INTELRDFPMATH_HASH}
	SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/IntelRDFPMath-current
	GIT_SHALLOW    OFF  # We need full history to checkout specific commit
	GIT_PROGRESS   TRUE
)

# Make the content available
FetchContent_MakeAvailable(IntelRDFPMath_Upstream)

message(STATUS "IntelRDFPMath source fetched to: ${CMAKE_CURRENT_SOURCE_DIR}/IntelRDFPMath-current")

# Create a custom target to track IntelRDFPMath fetch completion
# This allows other targets to depend on the fetch being complete
add_custom_target(IntelRDFPMath_Fetch_Complete
	COMMENT "IntelRDFPMath upstream source fetched and ready"
)

#------------------------------------------------------------------------
# Step 2: Build all IntelRDFPMath libraries for supported architectures
#------------------------------------------------------------------------

# Include ExternalProject module for building libraries
include(ExternalProject)

message("")
message("──────────────────────────────────────────────────────────────")
message("Building IntelRDFPMath libraries for all architectures...")
message("──────────────────────────────────────────────────────────────")

# List of all supported cores
set(SUPPORTED_CORES
	CORTEX_M3
	CORTEX_M33
	CORTEX_M4
	CORTEX_M55
	CORTEX_M7
	RV32IMAC
	RV64IMAFDC
)

# Determine build type to pass to ExternalProjects
# Default to MinSizeRel for optimal firmware size (adds -Os -DNDEBUG)
if(CMAKE_BUILD_TYPE)
	set(SUBPROJECT_BUILD_TYPE ${CMAKE_BUILD_TYPE})
else()
	set(SUBPROJECT_BUILD_TYPE "MinSizeRel")
endif()

# Create an ExternalProject for each core
foreach(CORE ${SUPPORTED_CORES})
	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}/CMakeLists.txt")
		message(STATUS "Configuring build for core: ${CORE}")

		ExternalProject_Add(IntelRDFPMath_${CORE}
			# Prefix - this sets up unique directories for each external project
			PREFIX            "${CMAKE_CURRENT_BINARY_DIR}/ep-${CORE}"

			# Source configuration
			SOURCE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}"
			BINARY_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}/build"

			# Configure step - pass build type explicitly for optimization
			CMAKE_ARGS        -DCMAKE_BUILD_TYPE=${SUBPROJECT_BUILD_TYPE}
			                  -G ${CMAKE_GENERATOR}
			CMAKE_CACHE_ARGS  ""

			# Build step
			BUILD_COMMAND     ${CMAKE_COMMAND} --build <BINARY_DIR>
			BUILD_ALWAYS      OFF
			BUILD_BYPRODUCTS  "${CMAKE_CURRENT_SOURCE_DIR}/Library/${CORE}/libIntelRDFPMath.a"

			# Install step - libraries stay in-place
			INSTALL_COMMAND   ""

			# Download/Update steps - we use local source
			DOWNLOAD_COMMAND  ""
			UPDATE_COMMAND    ""

			# Logging
			LOG_CONFIGURE     ON
			LOG_BUILD         ON
			LOG_OUTPUT_ON_FAILURE ON

			# Use terminal for better output
			USES_TERMINAL_BUILD ON
		)

		list(APPEND ALL_CORE_PROJECTS IntelRDFPMath_${CORE})
	else()
		message(WARNING "Skipping ${CORE}: CMakeLists.txt not found at Library/${CORE}")
	endif()
endforeach()

#------------------------------------------------------------------------
# Step 3: Create convenience targets
#------------------------------------------------------------------------

# Create a custom target that depends on all external projects
add_custom_target(build_all_intelrdfpmath ALL
	DEPENDS ${ALL_CORE_PROJECTS}
	COMMENT "Building IntelRDFPMath for all architectures"
)

# Add dependency to ensure IntelRDFPMath is fetched before building
add_dependencies(build_all_intelrdfpmath IntelRDFPMath_Fetch_Complete)

#------------------------------------------------------------------------
# Summary
#------------------------------------------------------------------------

message("")
message("══════════════════════════════════════════════════════════════")
message("Configuration complete.")
message("")
message("IntelRDFPMath version:   ${INTELRDFPMATH_VERSION}")
message("Git commit:      ${INTELRDFPMATH_HASH}")
message("Source location: ${CMAKE_CURRENT_SOURCE_DIR}/IntelRDFPMath-current")
message("")
message("To build all IntelRDFPMath libraries, run:")
message("  cmake --build build")
message("")
message("Individual architecture targets:")
foreach(CORE ${SUPPORTED_CORES})
	message("  - IntelRDFPMath_${CORE}")
endforeach()
message("")
message("Output libraries will be in:")
message("  Library/<CORE>/libIntelRDFPMath.a")
message("══════════════════════════════════════════════════════════════")
