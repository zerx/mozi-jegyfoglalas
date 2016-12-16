#include "Payment.h"

int Payment::nextId=0;

const Reservation& Payment::getReservation() const
{
    return reservation;
}

DateTime Payment::getTime() const
{
    return time;
}

bool Payment::getIsSuccessful() const
{
    return isSuccessful;
}

int Payment::getId() const
{
    return id;
}
