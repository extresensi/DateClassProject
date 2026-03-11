#include "Date.h"
#include <string>
#include <sstream>
#include <iomanip>

using std::string;
using std::ostringstream;

// Default date constants
static const int DEFAULT_MONTH = 1;
static const int DEFAULT_DAY   = 1;
static const int DEFAULT_YEAR  = 1900;

// Helper: month name lookup
static string monthName(int m)
{
    static const string names[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    if (m < 1 || m > 12)
        return "InvalidMonth";

    return names[m - 1];
}

// Constructor
Date::Date(int m, int d, int y)
{
    if (isValidDate(m, d, y))
    {
        month = m;
        day   = d;
        year  = y;
    }
    else
    {
        month = DEFAULT_MONTH;
        day   = DEFAULT_DAY;
        year  = DEFAULT_YEAR;
    }
}

// Mutator
void Date::setDate(int m, int d, int y)
{
    if (isValidDate(m, d, y))
    {
        month = m;
        day   = d;
        year  = y;
    }
    else
    {
        month = DEFAULT_MONTH;
        day   = DEFAULT_DAY;
        year  = DEFAULT_YEAR;
    }
}

// Validation helper
bool Date::isValidDate(int m, int d, int y) const
{
    // Basic month and year checks (you can refine year rules if desired)
    if (m < 1 || m > 12)
        return false;
    if (d < 1)
        return false;

    int last = lastDay(m, y);
    if (d > last)
        return false;

    return true;
}

// Leap year (no-arg) – uses stored year
bool Date::isLeapYear() const
{
    return isLeapYear(year);
}

// Leap year (explicit year)
bool Date::isLeapYear(int y) const
{
    // Gregorian rules:
    // divisible by 4 → leap
    // divisible by 100 → not leap
    // divisible by 400 → leap
    if (y % 400 == 0)
        return true;
    if (y % 100 == 0)
        return false;
    if (y % 4 == 0)
        return true;
    return false;
}

// Last day of current month/year
int Date::lastDay() const
{
    return lastDay(month, year);
}

// Last day of given month/year
int Date::lastDay(int m, int y) const
{
    switch (m)
    {
    case 1:  // Jan
    case 3:  // Mar
    case 5:  // May
    case 7:  // Jul
    case 8:  // Aug
    case 10: // Oct
    case 12: // Dec
        return 31;

    case 4:  // Apr
    case 6:  // Jun
    case 9:  // Sep
    case 11: // Nov
        return 30;

    case 2:  // Feb
        return isLeapYear(y) ? 29 : 28;

    default:
        // Invalid month; you could also throw or handle differently
        return 31;
    }
}

// MM/DD/YYYY
std::string Date::toNumericString() const
{
    ostringstream out;
    out << std::setw(2) << std::setfill('0') << month
        << "/"
        << std::setw(2) << std::setfill('0') << day
        << "/"
        << year;
    return out.str();
}

// MonthName DD, YYYY
std::string Date::toLongString() const
{
    ostringstream out;
    out << monthName(month) << " " << day << ", " << year;
    return out.str();
}

// DD MonthName YYYY
std::string Date::toInternationalString() const
{
    ostringstream out;
    out << day << " " << monthName(month) << " " << year;
    return out.str();
}
