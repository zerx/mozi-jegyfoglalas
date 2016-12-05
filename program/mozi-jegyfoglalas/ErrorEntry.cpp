#include "ErrorEntry.h"

int ErrorEntry::nextId=0;

const string& ErrorEntry::getErrorType() const
{
    return errorType;
}

DateTime ErrorEntry::getTime() const
{
    return time;
}

int ErrorEntry::getId() const
{
    return id;
}
