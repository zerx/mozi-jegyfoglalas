#ifndef CURRENTTIME
#define CURRENTTIME

#include "DateTime.h"

inline void CurrentTime(DateTime& time)
{
    time.setYear(2016);
    time.setMonth(12);
    time.setDay(1);
    time.setHour(15);
    time.setMinute(38);
}

#endif // CURRENTTIME

