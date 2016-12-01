#ifndef DateTime_H
#define DateTime_H

#include <iostream>
using namespace std;

class DateTime
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;

public:
    DateTime(int year, int month, int day, int hour, int minute)
    {
        this->year=year;
        this->month=month;
        this->day=day;
        this->hour=hour;
        this->minute=minute;
    }
    
    DateTime(){}
    ~DateTime(){}
    
	void print()
    {
        string monthNames[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        cout << year << " " << monthNames[month-1] << " ";
        if(day<10)
            cout << " ";
        cout << day << " ";
        if(hour<10)
            cout << " ";
        cout << hour << ":";
        if(minute<10)
            cout << "0";
        cout << minute;
    }

	bool operator<(DateTime const& d)
    {
        if(year < d.year)
            return true;
        else if(year == d.year)
        {
            if(month < d.month)
                return true;
            else if(month == d.month)
            {
                if(day < d.day)
                    return true;
                else if(day == d.day)
                {
                    if(hour < d.hour)
                        return true;
                    if(hour == d.hour)
                    {
                        if(minute < d.minute)
                            return true;
                        else return false;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    
    int getYear() const;
    void setYear(int value);
    int getMonth() const;
    void setMonth(int value);
    int getDay() const;
    void setDay(int value);
    int getHour() const;
    void setHour(int value);
    int getMinute() const;
    void setMinute(int value);
};

#endif // DateTime_H