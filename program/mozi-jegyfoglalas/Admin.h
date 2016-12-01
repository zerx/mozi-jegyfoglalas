#ifndef Admin_H
#define Admin_H

#include "User.h"

class Admin : public User
{
public:
    Admin(const string& username, const string& password, const EmailAddress& emailAddress, const string& firstName, const string& lastName, const Address& address)
        :User(username, password, emailAddress, firstName, lastName, address){}
    
    Admin(){}
    ~Admin(){}
    
	virtual void printMenu() = 0;

	void addStaffMember();

	void removeStaffMember();

	void viewErrorLog();
};

#endif // Admin_H