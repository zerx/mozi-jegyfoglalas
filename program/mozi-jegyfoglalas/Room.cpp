#include "Room.h"

int Room::nextId=0;

int Room::getNumOfSeats() const
{
    return numOfSeats;
}

void Room::setNumOfSeats(int value)
{
    numOfSeats = value;
}

int Room::getId() const
{
    return id;
}

string Room::getName() const
{
    return name;
}

void Room::setName(const string &value)
{
    name = value;
}
