#include "Screening.h"

int Screening::nextId=0;

const string& Screening::getMovieName() const
{
    return movieName;
}

void Screening::setMovieName(const string &value)
{
    movieName = value;
}

int Screening::getPrice() const
{
    return price;
}

void Screening::setPrice(int value)
{
    price = value;
}

DateTime Screening::getTime() const
{
    return time;
}

void Screening::setTime(const DateTime &value)
{
    time = value;
}

const Room& Screening::getRoom() const
{
    return room;
}

void Screening::setRoom(const Room &value)
{
    room = value;
}

int Screening::getNumOfReservations() const
{
    return numOfReservations;
}

void Screening::setNumOfReservations(int value)
{
    numOfReservations = value;
}

bool Screening::getIsCancelled() const
{
    return isCancelled;
}

void Screening::setIsCancelled(bool value)
{
    isCancelled = value;
}

int Screening::getId() const
{
    return id;
}
