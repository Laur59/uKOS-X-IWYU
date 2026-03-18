# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Define directory paths required to build the applications

# Get the application directory
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH APP_DIR)

# Compute path to project root directory from current path
cmake_path(GET APP_DIR PARENT_PATH SECTION_DIR)
cmake_path(GET SECTION_DIR PARENT_PATH UKOS_APPLS_DIR)
cmake_path(GET UKOS_APPLS_DIR PARENT_PATH APPLICATIONS_DIR)
cmake_path(GET APPLICATIONS_DIR PARENT_PATH PATH_UKOS)
