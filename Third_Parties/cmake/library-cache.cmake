# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Purpose:
#   Stamp Third_Parties/<lib>/Library when a package is installed, and keep a
#   copy of it in the cache shared by every checkout, so that a later checkout
#   of the same sources restores the archives instead of rebuilding them.
#
# Build description:
#   The stamp (Library/.ukos-stamp) names the sources the archives were built
#   from and the compiler that built them; Tools/Developer/third-parties-cache
#   writes it, and the target and application builds compare it with their own
#   checkout before they link the archives.
#
#   The sources are identified when the build tree is first configured, not at
#   install time: the per-core projects are built once and not again when a
#   source changes, so a key taken at install time could name sources the
#   archives never saw. When the two differ the library is left unstamped,
#   which the consumers report, rather than stamped with a guess.
#
# Usage:
#   include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/library-cache.cmake)
#   ukos_library_cache_begin(<lib>)     # before the first install() rule
#   ...
#   ukos_library_cache_end(<lib>)       # after the last install() rule
#
#   <lib> is the directory name under Third_Parties/. Nothing happens when the
#   install prefix is not the package directory.

include_guard(GLOBAL)

get_filename_component(UKOS_LIBRARY_CACHE_TOOL
    "${CMAKE_CURRENT_LIST_DIR}/../../Tools/Developer/third-parties-cache.sh" ABSOLUTE)

function(ukos_library_cache_begin lib)
    set(_keyfile "${CMAKE_BINARY_DIR}/ukos-sources-key")
    if(NOT EXISTS "${_keyfile}")
        execute_process(
            COMMAND "${UKOS_LIBRARY_CACHE_TOOL}" sources-key ${lib}
            OUTPUT_VARIABLE _key
            OUTPUT_STRIP_TRAILING_WHITESPACE
            RESULT_VARIABLE _rc
        )
        if(NOT _rc EQUAL 0 OR _key STREQUAL "")
            message(STATUS "Library cache: no sources key for ${lib}, Library/ will not be stamped")
            return()
        endif()
        file(WRITE "${_keyfile}" "${_key}")
    endif()

    # The archives are about to be replaced: the stamp no longer describes them
    install(CODE "
        if(\"\${CMAKE_INSTALL_PREFIX}\" STREQUAL \"${CMAKE_CURRENT_SOURCE_DIR}\")
            execute_process(COMMAND \"${UKOS_LIBRARY_CACHE_TOOL}\" unstamp ${lib})
        endif()
    ")
endfunction()

function(ukos_library_cache_end lib)
    set(_keyfile "${CMAKE_BINARY_DIR}/ukos-sources-key")
    install(CODE "
        if(\"\${CMAKE_INSTALL_PREFIX}\" STREQUAL \"${CMAKE_CURRENT_SOURCE_DIR}\" AND EXISTS \"${_keyfile}\")
            file(READ \"${_keyfile}\" _ukos_built_from)
            execute_process(
                COMMAND \"${UKOS_LIBRARY_CACHE_TOOL}\" stamp ${lib}
                        --built-from \"\${_ukos_built_from}\" --save
            )
        endif()
    ")
endfunction()
