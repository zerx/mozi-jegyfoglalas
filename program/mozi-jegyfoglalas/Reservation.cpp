#include "Reservation.h"

Screening Reservation::getScreening() const
{
    return screening;
}

int Reservation::getNumOfTickets() const
{
    return numOfTickets;
}

int Reservation::getTotalPrice() const
{
    return totalPrice;
}

bool Reservation::getIsPaid() const
{
    return isPaid;
}

void Reservation::setIsPaid(bool value)
{
    isPaid = value;
}

int Reservation::getId() const
{
    return id;
}
