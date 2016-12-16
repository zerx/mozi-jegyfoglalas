#ifndef User_H
#define User_H

#include <string>
#include <vector>
#include "EmailAddress.h"
#include "Address.h"
#include "Payment.h"
#include "ErrorEntry.h"
#include <algorithm>

enum usertype{_admin,staff,customer};

class User
{
protected:
	static int nextId;
	int id;
	string username;
	string password;
	EmailAddress emailAddress;
	string firstName;
	string lastName;
	Address address;
    usertype type;
    vector<Reservation> reservations;
	vector<Payment> payments;

public:
    User(const string& username, const string& password, const EmailAddress& emailAddress, const string& firstName, const string& lastName, const Address& address)
    {
        id=nextId;
        nextId++;
        this->username=username;
        this->password=password;
        this->emailAddress=emailAddress;
        this->firstName=firstName;
        this->lastName=lastName;
        this->address=address;
    }
    
    User(){}
    ~User(){}
    
    virtual void abstract()=0;
    
    void printReservations()
    {
        if(reservations.size()==0)
        {
            cout << "You don't have any bookings." << endl << endl;
            return;
        }
        else
        {
            cout << "[ID]\t[Date & time]\t  [Movie title]\t\t[Room name] [Number of tickets] [Price]\t[Total price]" << endl;
            for(unsigned int i=0; i<reservations.size(); i++)
            {
                cout << reservations[i].getId() << "\t";
                reservations[i].getScreening().getTime().print();
                cout << " " << reservations[i].getScreening().getMovieName() << "\t\t<Room: " << reservations[i].getScreening().getRoom().getName() << ">\t" << reservations[i].getNumOfTickets() << "\t\t" << reservations[i].getScreening().getPrice() << "\t" << reservations[i].getTotalPrice();
                if(reservations[i].getIsPaid()==true)
                    cout << "\tpaid" << endl;
                else cout << "\tUNPAID" << endl;
            };
            cout << endl;
        }
    }

	void printUnpaidReservations()
    {
        if(reservations.size()==0)
        {
            cout << "You don't have any unpaid bookings." << endl << endl;
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
                cout << "[ID]\t[Date & time]\t  [Movie title]\t\t[Room name] [Number of tickets] [Price]\t[Total price]" << endl;
                for(unsigned int i=0; i<reservations.size(); i++)
                {
                    if(reservations[i].getIsPaid()==false)
                    {
                        cout << reservations[i].getId() << "\t";
                        reservations[i].getScreening().getTime().print();
                        cout << " " << reservations[i].getScreening().getMovieName() << "\t\t<Room: " << reservations[i].getScreening().getRoom().getName() << ">\t" << reservations[i].getNumOfTickets() << "\t\t" << reservations[i].getScreening().getPrice() << "\t" << reservations[i].getTotalPrice() << endl;
                    }
                };
                cout << endl;
            }
        }
    }

	void printPayments()
    {
        if(payments.size()==0)
        {
            cout << "You don't have any payments in your purchase history." << endl << endl;
            return;
        }
        else
        {
            cout << "[Payment ID] [Booking ID] [Time of screening] [Movie title]\t[Room name] [Number of tickets] [Price]\t[Total price]\t[Time of payment]" << endl;
            for(unsigned int i=0; i<payments.size(); i++)
            {
                cout << payments[i].getId() << "\t\t" << payments[i].getReservation().getId() << "\t  ";
                payments[i].getReservation().getScreening().getTime().print();
                cout << "   " << payments[i].getReservation().getScreening().getMovieName() << "\t\t<Room: " << payments[i].getReservation().getScreening().getRoom().getName() << " >\t";
                cout << payments[i].getReservation().getNumOfTickets() << "\t\t" << payments[i].getReservation().getScreening().getPrice() << "\t" << payments[i].getReservation().getTotalPrice() << "\t\t";
                payments[i].getTime().print();
                if(payments[i].getIsSuccessful()==true)
                    cout << " successful" << endl;
                else cout << " UNSUCCESSFUL" << endl;
            };
            cout << endl;
        }
    }
    
    void addReservation(const Reservation& reservation)
    {
        reservations.push_back(reservation);
        sort(reservations.begin(), reservations.end());
    }
    
    void deleteReservation(int index)
    {
        reservations.erase(reservations.begin()+index);
    }
    
    void addPayment(const Payment& payment)
    {
        payments.push_back(payment);
        sort(payments.begin(), payments.end());
    }

	int findReservation(int id)
    {
        for(unsigned int i= 0; i<reservations.size(); i++)
        {
            if(reservations[i].getId() == id)
                return i;
        };
        return -1;
    }

	int findPayment(int id)
    {
        for(unsigned int i= 0; i<payments.size(); i++)
        {
            if(payments[i].getId() == id)
                return i;
        };
        return -1;
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
    
    
    vector<Reservation>& getReservations()
    {
        return reservations;
    }
    
    vector<Payment>& getPayments()
    {
        return payments;
    }
    
    int getId() const;
    const string& getUsername() const;
    const string& getPassword() const;
    void setPassword(const string &value);
    const EmailAddress& getEmailAddress() const;
    void setEmailAddress(const EmailAddress &value);
    const string& getFirstName() const;
    void setFirstName(const string &value);
    const string& getLastName() const;
    void setLastName(const string &value);
    const Address& getAddress() const;
    void setAddress(const Address &value);
    usertype getType() const;
};

#endif // User_H