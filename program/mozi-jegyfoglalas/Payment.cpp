#include "Payment.h"

Reservation Payment::getReservation() const
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
