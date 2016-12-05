#ifndef Payment_H
#define Payment_H

#include "Reservation.h"
#include "DateTime.h"
#include "currenttime.h"

class Payment {

private:
	static int nextId;
	int id;
	Reservation reservation;
	DateTime time;
	bool isSuccessful;

public:
    Payment(const Reservation& reservation, bool isSuccessful)
    {
        id=nextId;
        nextId++;
        this->reservation=reservation;
        currentTime(time);
        this->isSuccessful=isSuccessful;
    }
    
    Payment(){}
    ~Payment(){}
    
	bool operator<(Payment& p)
    {
        if(time < p.time)
            return true;
        else return false;
    }
    
    int getId() const;
    const Reservation& getReservation() const;
    DateTime getTime() const;
    bool getIsSuccessful() const;
};

#endif // Payment_H