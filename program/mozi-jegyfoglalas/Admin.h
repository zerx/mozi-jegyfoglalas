#ifndef Admin_H
#define Admin_H

#include "User.h"

class Admin : public User
{
public:
    Admin(const string& username, const string& password, const EmailAddress& emailAddress, const string& firstName, const string& lastName, const Address& address)
        :User(username, password, emailAddress, firstName, lastName, address)
    {
        type=_admin;
    }
    
    Admin(){}
    ~Admin(){}
    
    virtual void abstract(){}
};

#endif // Admin_H