#ifndef Reservation_H
#define Reservation_H

#include "Screening.h"

class Reservation
{
private:
	static int nextId;
	int id;
	Screening screening;
	int numOfTickets;
	int totalPrice;
	bool isPaid;

public:
    Reservation(const Screening& screening, int numOfTickets)
    {
        id=nextId;
        nextId++;
        this->screening=screening;
        this->numOfTickets=numOfTickets;
        totalPrice=numOfTickets*screening.getPrice();
        isPaid=false;
    }

    Reservation(){}
    ~Reservation(){}
    
	bool operator<(Reservation& r)
    {
        if(screening.getTime() < r.screening.getTime())
            return true;
        else return false;
    }
    
    int getId() const;
    Screening getScreening() const;
    int getNumOfTickets() const;
    int getTotalPrice() const;
    bool getIsPaid() const;
    void setIsPaid(bool value);
};

#endif // Reservation_H