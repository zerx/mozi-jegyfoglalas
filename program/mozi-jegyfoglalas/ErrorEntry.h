#ifndef ErrorEntry_H
#define ErrorEntry_H

#include <string>
#include "DateTime.h"
#include "currenttime.h"

class ErrorEntry
{
private:
	static int nextId;
    int id;
	string errorType;
	DateTime time;

public:
    ErrorEntry(const string& errorType)
    {
        id=nextId;
        nextId++;
        this->errorType=errorType;
        currentTime(time);
    }
    
    ErrorEntry(){}
    ~ErrorEntry(){}
    
	bool operator<(ErrorEntry& e)
    {
        if(time < e.time)
            return true;
        else return false;
    }
    
    int getId() const;
    const string& getErrorType() const;
    DateTime getTime() const;
};

#endif // ErrorEntry_H