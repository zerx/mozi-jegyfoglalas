#include "Room.h"

int Room::nextId=0;

unsigned int Room::getNumOfSeats() const
{
    return numOfSeats;
}

void Room::setNumOfSeats(unsigned int value)
{
    numOfSeats = value;
}

int Room::getId() const
{
    return id;
}

const string& Room::getName() const
{
    return name;
}

void Room::setName(const string &value)
{
    name = value;
}
