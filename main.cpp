#include <iostream>
#include "Date.h"

using std::cout;
using std::endl;

void printDateInfo(const Date& d, const char* label)
{
    cout << "=== " << label << " ===" << endl;
    cout << "Stored: " << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << endl;
    cout << "Numeric:        " << d.toNumericString() << endl;
    cout << "Long:           " << d.toLongString() << endl;
    cout << "International:  " << d.toInternationalString() << endl;
    cout << "Leap year?      " << (d.isLeapYear() ? "Yes" : "No") << endl;
    cout << "Last day month: " << d.lastDay() << endl;
    cout << endl;
}

int main()
{
    // Default constructor
    Date d1;
    printDateInfo(d1, "Default constructor (should be 1/1/1900)");

    // Valid constructor
    Date d2(12, 25, 2021);
    printDateInfo(d2, "Valid constructor (12/25/2021)");

    // Invalid constructor (month 13 → default)
    Date d3(13, 10, 2020);
    printDateInfo(d3, "Invalid constructor (13/10/2020 → default)");

    // setDate valid
    Date d4;
    d4.setDate(2, 29, 2024); // leap year
    printDateInfo(d4, "setDate valid (2/29/2024)");

    // setDate invalid (April 31 → default)
    Date d5(4, 30, 2023);
    printDateInfo(d5, "Before invalid setDate (4/30/2023)");
    d5.setDate(4, 31, 2023);
    printDateInfo(d5, "After invalid setDate (4/31/2023 → default)");

    // Leap year explicit tests
    cout << "Leap year 2024? " << (d1.isLeapYear(2024) ? "Yes" : "No") << endl;
    cout << "Leap year 2023? " << (d1.isLeapYear(2023) ? "No" : "Yes") << endl;
    cout << "Leap year 1900? " << (d1.isLeapYear(1900) ? "Yes" : "No") << endl;
    cout << "Leap year 2000? " << (d1.isLeapYear(2000) ? "Yes" : "No") << endl;

    cout << endl;
    return 0;
}
