#ifndef StaffMember_H
#define StaffMember_H

#include "User.h"

class StaffMember : public User
{
public:
    StaffMember(const string& username, const string& password, const EmailAddress& emailAddress, const string& firstName, const string& lastName, const Address& address)
        :User(username, password, emailAddress, firstName, lastName, address)
    {
        type=staff;
    }
    
    StaffMember(){}
    ~StaffMember(){}
    
    virtual void abstract(){}
};

#endif // StaffMember_H