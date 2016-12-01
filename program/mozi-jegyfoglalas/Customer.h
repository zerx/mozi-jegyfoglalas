#ifndef Customer_H
#define Customer_H

#include <string>
#include <vector>
#include "User.h"
#include "Payment.h"
using namespace std;

class Customer : public User
{
private:
	vector<Reservation> reservations;
	vector<Payment> payments;

public:
    Customer(const string& username, const string& password, const EmailAddress& emailAddress, const string& firstName, const string& lastName, const Address& address)
        :User(username, password, emailAddress, firstName, lastName, address){}
    
    Customer(){}
    ~Customer(){}
    
	virtual void printMenu() = 0;

	void viewScreenings();

	void reserve();

	void viewReservations();

	void pay();

	void viewPayments();

	void printReservations();

	void printUnpaidReservations();

	void printPayments();

	int findReservation(int id)
    {
        for(unsigned int i= 0; i<reservations.size(); i++)
        {
            if(reservations[i].getId() == id)
                return i;
        };
        throw "Reservation with this ID doesn't exist.";
    }

	int findPayment(int id)
    {
        for(unsigned int i= 0; i<payments.size(); i++)
        {
            if(payments[i].getId() == id)
                return i;
        };
        throw "Payment with this ID doesn't exist.";
    }
    
    Reservation& getReservation(int id)
    {
        int reservationIndex=findReservation(id);
        return reservations[reservationIndex];
    }
    
    Payment& getPayment(int id)
    {
        int paymentIndex=findPayment(id);
        return payments[paymentIndex];
    }
};

#endif // Customer_H