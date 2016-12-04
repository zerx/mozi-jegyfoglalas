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

	void printUnpaidReservations()
    {
        if(reservations.size()==0)
        {
            cout << "You don't have any unpaid reservations." << endl;
            return;
        }
        else
        {
            int numOfUnpaid=0;
            for(unsigned int i=0; i<reservations.size(); i++)
            {
                if(reservations[i].getIsPaid()==false)
                {
                    numOfUnpaid++;
                }
            };
            if(numOfUnpaid>0)
            {
                cout << "[ID]\t[Date & time] [Movie title] [Room name] [Number of tickets] [Price] [Total price]" << endl;
                for(unsigned int i=0; i<reservations.size(); i++)
                {
                    if(reservations[i].getIsPaid()==false)
                    {
                        cout << reservations[i].getId() << "\t";
                        reservations[i].getScreening().getTime().print();
                        cout << reservations[i].getScreening().getMovieName() << " <Room: " << reservations[i].getScreening().getRoom().getName() << "> " << reservations[i].getNumOfTickets() << " " << reservations[i].getScreening().getPrice() << " " << reservations[i].getTotalPrice() << endl;
                    }
                };
            }
        }
    }

	void printPayments()
    {
        if(payments.size()==0)
        {
            cout << "You don't have any payments in your purchase history." << endl;
            return;
        }
        else
        {
            cout << "[ID]\t[Time of purchase] [Movie title] [Room name] [Number of tickets] [Price] [Total price]" << endl;
            for(unsigned int i=0; i<payments.size(); i++)
            {
                cout << payments[i].getId() << "\t";
                payments[i].getTime().print();
                cout << " " << payments[i].getReservation().getScreening().getMovieName() << " " << payments[i].getReservation().getScreening().getRoom().getName() << " ";
                cout << payments[i].getReservation().getNumOfTickets() << " " << payments[i].getReservation().getScreening().getPrice() << " " << payments[i].getReservation().getTotalPrice() << endl;
            };
        }
    }

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