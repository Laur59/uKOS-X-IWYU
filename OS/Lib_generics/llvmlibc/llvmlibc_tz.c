/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * POSIX timezone support for the LLVM libc build.
 *
 * Baremetal LLVM libc has no timezone support: localtime_r() and localtime()
 * return UTC (libc/src/time/time_utils.h, "TODO: timezone support"),
 * get_timezone_offset() is a constant stub, and mktime() reads the struct tm as
 * UTC while forcing tm_isdst = 0. It also declares setenv, getenv and unsetenv
 * without implementing them, and has no tzset() at all.
 *
 * This file supplies the missing half, so that the calendar manager behaves as
 * it does under newlib and picolibc:
 * - a TZ-only environment (setenv / getenv / unsetenv),
 * - a POSIX TZ parser and tzset(), for the full form
 *   std offset [dst [offset] [,start[/time],end[/time]]], as in
 *   CET-1CEST,M3.5.0/2,M10.5.0/2,
 * - localtime_r(), localtime() and mktime() honouring the result.
 *
 * The three time functions are strong symbols living in their own libc.a
 * members (localtime.cpp.obj, localtime_r.cpp.obj, mktime.cpp.obj) that nothing
 * else in the library references, so the definitions below win the link and
 * those members are never pulled in -- the same mechanism the dprintf shim
 * already relies on. gmtime_r() is deliberately NOT overridden: it is the
 * library's own UTC conversion, and what localtime_r() builds on.
 *
 * Remaining gap: ctime() and ctime_r() call the internal helper
 * update_from_seconds() directly (libc/src/time/ctime.cpp) instead of
 * localtime_r(), so they stay in UTC. LLVM libc's struct tm has no tm_gmtoff /
 * tm_zone to populate either, and the library declares neither tzname[] nor
 * timezone / daylight, so those are not provided.
 *
 * Everything is kept per core, as the calendar manager keeps its own TZ strings
 * per core. On the single-core SoCs GET_RUNNING_CORE is the constant 0U and the
 * indexing costs nothing.
 *
 * A target with no flash left for the support builds with LLVMLIBC_TIMEZONE=OFF
 * and keeps only the setenv() / tzset() stubs; see KLLVMLIBC_WITH_TIMEZONE_S
 * below.
 */

#include    <errno.h>
#include    <stdint.h>
#include    <string.h>      // also for size_t
#include    <time.h>

#include    "macros_soc.h"  // for GET_RUNNING_CORE and KNB_CORES
#include    "types.h"

#ifdef CONFIG_MAN_LLVMLIBC_S

// Library specific
// ================

// POSIX timezone support costs about 2.4 KB of flash and 180 B of RAM. A target
// with no room left for it sets LLVMLIBC_TIMEZONE to OFF in its CMakeLists.txt,
// which reduces this file to the setenv() and tzset() stubs the calendar
// manager needs to link, and leaves local time equal to UTC as it was before.

#ifndef KLLVMLIBC_WITH_TIMEZONE_S
#define KLLVMLIBC_WITH_TIMEZONE_S   true
#endif

#if (KLLVMLIBC_WITH_TIMEZONE_S == true)

// Longest TZ string accepted. The calendar manager composes at most
// KSZ_TZ_UTC_SHIFT + KSZ_TZ_DST_SPEC = 17 + 33 characters
// (OS/Lib_generics/calendar/calendar.c).

#define KSZ_TZ_STRING       64U
#define KSZ_TZ_NAME         8U

#define KSEC_PER_MIN        60
#define KSEC_PER_HOUR       3600
#define KSEC_PER_DAY        86400

// Transition rule forms of a POSIX TZ string

typedef enum {
            KRULE_NONE = 0,                                     // No transition rule
            KRULE_JULIAN,                                       // Jn,  1..365, 29 February never counted
            KRULE_DAY,                                          // n,   0..365, 29 February counted
            KRULE_MONTH                                         // Mm.w.d, the d'th day of week w of month m
} tzRuleType_t;

typedef struct {
            tzRuleType_t    oType;                              // Rule form
            int32_t         oDay;                               // Jn / n day number
            int32_t         oMonth;                             // 1..12
            int32_t         oWeek;                              // 1..5, 5 = last
            int32_t         oWday;                              // 0..6, 0 = Sunday
            int32_t         oTime;                              // Seconds after local midnight
} tzRule_t;

typedef struct {
            char_t          oStdName[KSZ_TZ_NAME];              // Standard time designation
            char_t          oDstName[KSZ_TZ_NAME];              // Daylight time designation
            int32_t         oStdOffset;                         // Seconds to add to UTC (east positive)
            int32_t         oDstOffset;                         // Idem, while DST is in effect
            bool            oHasDst;                            // A daylight designation was given
            tzRule_t        oStart;                             // Start of DST
            tzRule_t        oEnd;                               // End of DST
} tz_t;

// The TZ string as set through setenv(), and its parsed form as produced by
// tzset(). All-zero means UTC with no DST, which is the state before the
// calendar manager configures anything.

static  char_t      vTzString[KNB_CORES][KSZ_TZ_STRING];
static  tz_t        vTz[KNB_CORES];

// Default transition rules, used when the TZ string names a daylight time but
// gives no rule (e.g. "EST5EDT"). POSIX leaves this implementation defined;
// these are the United States rules, as in newlib and musl.

static  const tzRule_t  KDEFAULT_START = { KRULE_MONTH, 0,  3, 2, 0, 2 * KSEC_PER_HOUR };
static  const tzRule_t  KDEFAULT_END   = { KRULE_MONTH, 0, 11, 1, 0, 2 * KSEC_PER_HOUR };

// Prototypes

static  const char_t    *local_parseNumber(const char_t *string, int32_t *value);
static  const char_t    *local_parseName(const char_t *string, char_t *name);
static  const char_t    *local_parseOffset(const char_t *string, int32_t *seconds);
static  const char_t    *local_parseRule(const char_t *string, tzRule_t *rule);
static  void            local_parseTimeZone(const char_t *string, tz_t *timeZone);
static  int64_t         local_daysFromCivil(int32_t year, int32_t month, int32_t day);
static  int64_t         local_ruleToLocal(const tzRule_t *rule, int32_t year);
static  bool            local_isDst(const tz_t *timeZone, int64_t utc);
static  const tz_t      *local_getTimeZone(void);

/*
 * ============================================================================
 * TZ-only environment
 * ============================================================================
 *
 * Baremetal LLVM libc has no process environment. The calendar manager needs
 * exactly one variable, so only TZ is modelled: any other name is accepted and
 * discarded by setenv(), and reported as absent by getenv().
 */

/*
 * \brief setenv
 *
 * - Store the TZ string; ignore every other variable.
 *
 */
int setenv(const char *name, const char *value, int overwrite) {
    uint32_t    core;
    size_t      length;

    core = GET_RUNNING_CORE;

    if ((name == nullptr) || (name[0] == '\0') || (strchr(name, '=') != nullptr) || (value == nullptr)) {
        errno = EINVAL;
        return (-1);
    }
    if (strcmp(name, "TZ") != 0) {
        return (0);
    }
    if ((overwrite == 0) && (vTzString[core][0] != '\0')) {
        return (0);
    }

    length = strlen(value);
    if (length >= KSZ_TZ_STRING) {
        errno = EINVAL;
        return (-1);
    }
    (void)memcpy(&vTzString[core][0], value, length + 1U);
    return (0);
}

/*
 * \brief getenv
 *
 * - Return the TZ string, or nullptr for any other variable.
 *
 */
char *getenv(const char *name) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if ((name == nullptr) || (strcmp(name, "TZ") != 0) || (vTzString[core][0] == '\0')) {
        return (nullptr);
    }
    return (&vTzString[core][0]);
}

/*
 * \brief unsetenv
 *
 * - Clear the TZ string; ignore every other variable.
 *
 */
int unsetenv(const char *name) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if ((name == nullptr) || (name[0] == '\0') || (strchr(name, '=') != nullptr)) {
        errno = EINVAL;
        return (-1);
    }
    if (strcmp(name, "TZ") == 0) {
        vTzString[core][0] = '\0';
    }
    return (0);
}

/*
 * ============================================================================
 * POSIX TZ parsing
 * ============================================================================
 */

/*
 * \brief tzset
 *
 * - Parse the TZ string into the per core timezone descriptor.
 *
 */
void tzset(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    local_parseTimeZone(&vTzString[core][0], &vTz[core]);
}

/*
 * ============================================================================
 * Local time
 * ============================================================================
 */

/*
 * \brief localtime_r
 *
 * - Convert a Unix time into the broken down local time of the current TZ.
 *
 */
struct tm *localtime_r(const time_t *timer, struct tm *result) {
    const tz_t  *timeZone;
    bool        isDst;
    time_t      shifted;

    if ((timer == nullptr) || (result == nullptr)) {
        errno = EINVAL;
        return (nullptr);
    }

    timeZone = local_getTimeZone();
    isDst    = local_isDst(timeZone, (int64_t)*timer);
    shifted  = (time_t)(*timer + (isDst ? timeZone->oDstOffset : timeZone->oStdOffset));

    if (gmtime_r(&shifted, result) == nullptr) {
        return (nullptr);
    }
    result->tm_isdst = (isDst ? 1 : 0);
    return (result);
}

/*
 * \brief localtime
 *
 * - As localtime_r(), into a per core static buffer.
 *
 */
struct tm *localtime(const time_t *timer) {
    static  tm_t    vResult[KNB_CORES];

    return (localtime_r(timer, &vResult[GET_RUNNING_CORE]));
}

/*
 * \brief mktime
 *
 * - Convert a broken down local time into a Unix time, and normalise the
 *   caller's struct tm.
 *
 * A tm_isdst of -1 means "unknown": the local time is first read as standard
 * time, and re-read as daylight time when the rules say DST was in effect.
 * Times that fall in the gap or the overlap of a transition are inherently
 * ambiguous; the second reading is then kept only if it is self consistent.
 *
 */
time_t mktime(struct tm *timeptr) {
    const tz_t  *timeZone;
    int64_t     year, month, local, utc;
    bool        isDst;
    time_t      result;

    if (timeptr == nullptr) {
        errno = EINVAL;
        return ((time_t)(-1));
    }

    timeZone = local_getTimeZone();

// Carry an out of range month into the year; the day, hour, minute and second
// fields need no normalisation, as they enter the sum linearly

    year  = (int64_t)timeptr->tm_year + 1900;
    month = (int64_t)timeptr->tm_mon;
    year += month / 12;
    month = month % 12;
    if (month < 0) { month += 12; year -= 1; }

    local = (local_daysFromCivil((int32_t)year, (int32_t)month + 1, 1) + (int64_t)timeptr->tm_mday - 1) * KSEC_PER_DAY
          + (int64_t)timeptr->tm_hour * KSEC_PER_HOUR
          + (int64_t)timeptr->tm_min  * KSEC_PER_MIN
          + (int64_t)timeptr->tm_sec;

    if (timeptr->tm_isdst > 0) {
        utc = local - timeZone->oDstOffset;
    }
    else if (timeptr->tm_isdst == 0) {
        utc = local - timeZone->oStdOffset;
    }
    else {
        utc   = local - timeZone->oStdOffset;
        isDst = local_isDst(timeZone, utc);
        if (isDst) {
            utc = local - timeZone->oDstOffset;
            if (!local_isDst(timeZone, utc)) {
                utc = local - timeZone->oStdOffset;
            }
        }
    }

    result = (time_t)utc;
    if (localtime_r(&result, timeptr) == nullptr) {
        return ((time_t)(-1));
    }
    return (result);
}

// Local routines
// ==============

/*
 * \brief local_parseNumber
 *
 * - Read a decimal number and return the position past it
 *
 */
static  const char_t    *local_parseNumber(const char_t *string, int32_t *value) {
    int32_t     number = 0;

    while ((*string >= '0') && (*string <= '9')) {
        number = (number * 10) + (int32_t)(*string - '0');
        string++;
    }
    *value = number;
    return (string);
}

/*
 * \brief local_parseName
 *
 * - Read a time designation, either three or more letters or a <...> quoted
 *   form, and return the position past it
 *
 */
static  const char_t    *local_parseName(const char_t *string, char_t *name) {
    uint32_t    index = 0U;
    char_t      character;

    if (*string == '<') {
        string++;
        while ((*string != '\0') && (*string != '>')) {
            if (index < (KSZ_TZ_NAME - 1U)) { name[index] = *string; index++; }
            string++;
        }
        if (*string == '>') { string++; }
    }
    else {
        while (true) {
            character = (char_t)(*string | 0x20);
            if ((character < 'a') || (character > 'z')) { break; }
            if (index < (KSZ_TZ_NAME - 1U)) { name[index] = *string; index++; }
            string++;
        }
    }
    name[index] = '\0';
    return (string);
}

/*
 * \brief local_parseOffset
 *
 * - Read a [+|-]hh[:mm[:ss]] offset and return the position past it
 *
 * The result keeps the POSIX sign convention: the value is what has to be
 * added to the local time to obtain UTC. The caller negates it to obtain an
 * east positive offset.
 *
 */
static  const char_t    *local_parseOffset(const char_t *string, int32_t *seconds) {
    int32_t     sign = 1;
    int32_t     hours = 0, minutes = 0, secs = 0;

    if      (*string == '+') { string++; }
    else if (*string == '-') { sign = -1; string++; }

    string = local_parseNumber(string, &hours);
    if (*string == ':') {
        string = local_parseNumber(string + 1, &minutes);
        if (*string == ':') {
            string = local_parseNumber(string + 1, &secs);
        }
    }
    *seconds = sign * ((hours * KSEC_PER_HOUR) + (minutes * KSEC_PER_MIN) + secs);
    return (string);
}

/*
 * \brief local_parseRule
 *
 * - Read a Jn / n / Mm.w.d transition rule with its optional /time, and
 *   return the position past it
 *
 */
static  const char_t    *local_parseRule(const char_t *string, tzRule_t *rule) {

    rule->oDay   = 0;
    rule->oMonth = 0;
    rule->oWeek  = 0;
    rule->oWday  = 0;
    rule->oTime  = 2 * KSEC_PER_HOUR;

    if (*string == 'M') {
        rule->oType = KRULE_MONTH;
        string = local_parseNumber(string + 1, &rule->oMonth);
        if (*string == '.') { string = local_parseNumber(string + 1, &rule->oWeek); }
        if (*string == '.') { string = local_parseNumber(string + 1, &rule->oWday); }
    }
    else if (*string == 'J') {
        rule->oType = KRULE_JULIAN;
        string = local_parseNumber(string + 1, &rule->oDay);
    }
    else {
        rule->oType = KRULE_DAY;
        string = local_parseNumber(string, &rule->oDay);
    }

    if (*string == '/') {
        string = local_parseOffset(string + 1, &rule->oTime);
    }
    return (string);
}

/*
 * \brief local_parseTimeZone
 *
 * - Parse a complete POSIX TZ string
 *
 *   std offset [dst [offset] [,start[/time],end[/time]]]
 *
 * Anything that does not parse leaves the descriptor on UTC without DST,
 * which is the behaviour of an unset TZ.
 *
 */
static  void    local_parseTimeZone(const char_t *string, tz_t *timeZone) {
    int32_t     offset = 0;

    (void)memset(timeZone, 0, sizeof(tz_t));

    if ((string == nullptr) || (*string == '\0')) { return; }

    string = local_parseName(string, &timeZone->oStdName[0]);
    if (timeZone->oStdName[0] == '\0') { return; }

    string = local_parseOffset(string, &offset);
    timeZone->oStdOffset = -offset;

// No daylight designation: standard time all year

    string = local_parseName(string, &timeZone->oDstName[0]);
    if (timeZone->oDstName[0] == '\0') { return; }

    timeZone->oHasDst = true;

    if ((*string != ',') && (*string != '\0')) {
        string = local_parseOffset(string, &offset);
        timeZone->oDstOffset = -offset;
    }
    else {
        timeZone->oDstOffset = timeZone->oStdOffset + KSEC_PER_HOUR;
    }

// No explicit rules: fall back on the POSIX implementation defined default

    if (*string != ',') {
        timeZone->oStart = KDEFAULT_START;
        timeZone->oEnd   = KDEFAULT_END;
        return;
    }

    string = local_parseRule(string + 1, &timeZone->oStart);
    if (*string != ',') {
        timeZone->oStart = KDEFAULT_START;
        timeZone->oEnd   = KDEFAULT_END;
        return;
    }
    (void)local_parseRule(string + 1, &timeZone->oEnd);
}

/*
 * \brief local_daysFromCivil
 *
 * - Return the number of days between 1970-01-01 and the given date
 *
 * Month is 1..12 and day 1..31; a day beyond the end of the month simply
 * carries into the next one, which is what mktime() relies on. The algorithm
 * shifts the year to start in March so that the leap day falls last (Howard
 * Hinnant, "chrono-Compatible Low-Level Date Algorithms").
 *
 */
static  int64_t local_daysFromCivil(int32_t year, int32_t month, int32_t day) {
    int64_t     shifted, era, yearOfEra, dayOfYear, dayOfEra;

    shifted   = (int64_t)year - ((month <= 2) ? 1 : 0);
    era       = ((shifted >= 0) ? shifted : (shifted - 399)) / 400;
    yearOfEra = shifted - (era * 400);                                          // [0, 399]
    dayOfYear = (((153 * (int64_t)(month + ((month > 2) ? -3 : 9))) + 2) / 5) + (int64_t)day - 1;
    dayOfEra  = (yearOfEra * 365) + (yearOfEra / 4) - (yearOfEra / 100) + dayOfYear;
    return ((era * 146097) + dayOfEra - 719468);
}

/*
 * \brief local_ruleToLocal
 *
 * - Return the local time, in seconds since the epoch, at which a transition
 *   rule fires in the given year
 *
 */
static  int64_t local_ruleToLocal(const tzRule_t *rule, int32_t year) {
    int64_t     days, first, last;
    int32_t     nextMonth, nextYear, weekday;
    bool        isLeap;

    switch (rule->oType) {
        case KRULE_JULIAN: {
            isLeap = (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0)));
            days   = local_daysFromCivil(year, 1, 1) + (int64_t)rule->oDay - 1;
            if (isLeap && (rule->oDay >= 60)) { days += 1; }
            break;
        }
        case KRULE_DAY: {
            days = local_daysFromCivil(year, 1, 1) + (int64_t)rule->oDay;
            break;
        }
        case KRULE_MONTH: {
            if (rule->oWeek >= 5) {

// Last matching weekday of the month: walk back from its last day

                nextMonth = rule->oMonth + 1;
                nextYear  = year;
                if (nextMonth > 12) { nextMonth = 1; nextYear += 1; }

                last    = local_daysFromCivil(nextYear, nextMonth, 1) - 1;
                weekday = (int32_t)(((last + 4) % 7 + 7) % 7);                  // 1970-01-01 was a Thursday
                days    = last - (int64_t)((weekday - rule->oWday + 7) % 7);
            }
            else {
                first   = local_daysFromCivil(year, rule->oMonth, 1);
                weekday = (int32_t)(((first + 4) % 7 + 7) % 7);
                days    = first + (int64_t)((rule->oWday - weekday + 7) % 7)
                        + ((int64_t)rule->oWeek - 1) * 7;
            }
            break;
        }
        default: {
            days = 0;
            break;
        }
    }
    return ((days * KSEC_PER_DAY) + (int64_t)rule->oTime);
}

/*
 * \brief local_isDst
 *
 * - Tell whether daylight saving time is in effect at the given UTC time
 *
 * The transition rules are expressed in local time: the start fires while
 * standard time is still in force, the end while daylight time is. Comparing
 * in UTC therefore needs each bound shifted by its own offset. A start later
 * than the end is the southern hemisphere case, where the daylight period
 * straddles the end of the year.
 *
 */
static  bool    local_isDst(const tz_t *timeZone, int64_t utc) {
    tm_t        broken;
    time_t      standard;
    int64_t     start, end;
    int32_t     year;

    if (!timeZone->oHasDst) { return (false); }

    standard = (time_t)(utc + timeZone->oStdOffset);
    if (gmtime_r(&standard, &broken) == nullptr) { return (false); }
    year = broken.tm_year + 1900;

    start = local_ruleToLocal(&timeZone->oStart, year) - timeZone->oStdOffset;
    end   = local_ruleToLocal(&timeZone->oEnd,   year) - timeZone->oDstOffset;

    if (start <= end) { return ((utc >= start) && (utc < end)); }
    return ((utc >= start) || (utc < end));
}

/*
 * \brief local_getTimeZone
 *
 * - Return the timezone descriptor of the running core
 *
 */
static  const tz_t  *local_getTimeZone(void) {

    return (&vTz[GET_RUNNING_CORE]);
}

#else

/*
 * ============================================================================
 * Timezone support disabled
 * ============================================================================
 *
 * Only the two entry points the calendar manager calls are kept, as the stubs
 * they were before the support existed. LLVM libc's own localtime_r(),
 * localtime() and mktime() are then linked, and all three work in UTC.
 */

/*
 * \brief setenv
 *
 * - No environment on baremetal; accept and ignore.
 *
 */
int setenv(const char *name, const char *value, int overwrite) {
    (void)name;
    (void)value;
    (void)overwrite;
    return (0);
}

/*
 * \brief tzset
 *
 * - No timezone support in this build; no action.
 *
 */
void tzset(void) {
    // No action: see KLLVMLIBC_WITH_TIMEZONE_S above
}

#endif  // KLLVMLIBC_WITH_TIMEZONE_S

#endif
