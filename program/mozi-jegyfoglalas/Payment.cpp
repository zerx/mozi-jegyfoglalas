#include "Payment.h"

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
