# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Purpose:
#   Tell whether a prebuilt third-party library is the one this checkout would
#   build, before it is linked.
#
# Build description:
#   Third_Parties/<lib>/Library is ignored by git, so it stays as it is when
#   the checkout moves to another commit: the archives of the previous commit
#   are then linked against the headers of this one, without a word. Each
#   Library/ carries a stamp naming the sources it was built from
#   (Tools/Developer/third-parties-cache); this compares it with the checkout.
#
#   A mismatch is a warning, not an error: the archive may well still be
#   compatible, and 'third-parties-cache restore' or a rebuild settles it. A
#   Library/ without a stamp was built before the stamp existed and is only
#   mentioned.
#
# Requires:
#   PATH_UKOS - Path to the uKOS-X repository root
#
# Usage:
#   ukos_check_third_party(FatFs)                 # directory name under Third_Parties/
#   ukos_check_third_party_archives(${MYLIB})     # every library the paths belong to
#
# Disable with -DTHIRD_PARTY_CHECK=OFF.

include_guard(GLOBAL)

option(THIRD_PARTY_CHECK "Compare the prebuilt third-party libraries with this checkout" ON)

function(ukos_check_third_party lib)
    if(NOT THIRD_PARTY_CHECK)
        return()
    endif()

    # Once per configure and per library
    get_property(_checked GLOBAL PROPERTY UKOS_THIRD_PARTY_CHECKED)
    if("${lib}" IN_LIST _checked)
        return()
    endif()
    set_property(GLOBAL APPEND PROPERTY UKOS_THIRD_PARTY_CHECKED "${lib}")

    set(_tool "${PATH_UKOS}/Tools/Developer/third-parties-cache.sh")
    if(NOT EXISTS "${_tool}" OR NOT EXISTS "${PATH_UKOS}/Third_Parties/${lib}/cache-inputs.txt")
        return()
    endif()

    execute_process(
        COMMAND "${_tool}" check ${lib}
        OUTPUT_VARIABLE _answer
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
        RESULT_VARIABLE _rc
    )
    if(_rc STREQUAL "3")
        message(WARNING
            "Third-party library ${_answer}.\n"
            "Run 'third-parties-cache restore ${lib}' to bring back a cached build, "
            "or rebuild it in Third_Parties/${lib}.")
    elseif(_rc STREQUAL "0" OR _rc STREQUAL "4")
        message(STATUS "Third-party library ${_answer}")
    endif()
endfunction()

# Check the library of every path that lies in a Third_Parties/<lib>/Library
function(ukos_check_third_party_archives)
    foreach(_path IN LISTS ARGN)
        if(_path MATCHES "/Third_Parties/([^/]+)/Library/")
            ukos_check_third_party(${CMAKE_MATCH_1})
        endif()
    endforeach()
endfunction()
