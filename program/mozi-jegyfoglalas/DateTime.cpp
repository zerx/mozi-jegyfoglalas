#include "DateTime.h"

int DateTime::getYear() const
{
    return year;
}

void DateTime::setYear(int value)
{
    year = value;
}

int DateTime::getMonth() const
{
    return month;
}

void DateTime::setMonth(int value)
{
    month = value;
}

int DateTime::getDay() const
{
    return day;
}

void DateTime::setDay(int value)
{
    day = value;
}

int DateTime::getHour() const
{
    return hour;
}

void DateTime::setHour(int value)
{
    hour = value;
}

int DateTime::getMinute() const
{
    return minute;
}

void DateTime::setMinute(int value)
{
    minute = value;
}
