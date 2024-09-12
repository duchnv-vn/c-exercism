#include "leap.h"

bool leap_year(int year)
{
    bool isLeapYear = false;
    const bool isDivisible100 = year % 100 == 0;

    if (isDivisible100)
    {
        const bool isDivisible400 = year % 400 == 0;
        isLeapYear = isDivisible400;
    }
    else
    {
        const bool isDivisible4 = year % 4 == 0;
        isLeapYear = isDivisible4;
    }

    return isLeapYear;
}