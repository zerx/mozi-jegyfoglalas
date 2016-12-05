#ifndef CURRENTTIME
#define CURRENTTIME

#include <ctime>
#include "DateTime.h"

inline void currentTime(DateTime& datetime)
{
    time_t t= time(0);
    struct tm* now= localtime(&t);
    datetime.setYear(now->tm_year + 1900);
    datetime.setMonth(now->tm_mon + 1);
    datetime.setDay(now->tm_mday);
    datetime.setHour(now->tm_hour);
    datetime.setMinute(now->tm_min);
}

#endif // CURRENTTIME

