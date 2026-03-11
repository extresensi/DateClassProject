#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
    int month;
    int day;
    int year;

    // Helper validation functions
    bool isValidDate(int m, int d, int y) const;

public:
    // Constructor with defaults
    Date(int m = 1, int d = 1, int y = 1900);

    // Mutator
    void setDate(int m, int d, int y);

    // Accessors
    int getMonth() const { return month; }
    int getDay()   const { return day; }
    int getYear()  const { return year; }

    // Leap year (overloaded)
    bool isLeapYear() const;
    bool isLeapYear(int year) const;

    // Last day of month (overloaded)
    int lastDay() const;
    int lastDay(int month, int year) const;

    // Output formats
    std::string toNumericString() const;      // MM/DD/YYYY
    std::string toLongString() const;         // MonthName DD, YYYY
    std::string toInternationalString() const;// DD MonthName YYYY
};

#endif
