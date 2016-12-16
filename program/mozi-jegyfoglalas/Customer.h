#ifndef Customer_H
#define Customer_H

#include "User.h"

class Customer : public User
{
public:
    Customer(const string& username, const string& password, const EmailAddress& emailAddress, const string& firstName, const string& lastName, const Address& address)
        :User(username, password, emailAddress, firstName, lastName, address)
    {
        type=customer;
    }
    
    Customer(){}
    ~Customer(){}
    
    virtual void abstract(){}
};

#endif // Customer_H