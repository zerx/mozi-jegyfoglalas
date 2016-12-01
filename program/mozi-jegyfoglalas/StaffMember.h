#ifndef StaffMember_H
#define StaffMember_H

#include <vector>
#include "User.h"
using namespace std;

class StaffMember : public User
{
public:
    StaffMember(const string& username, const string& password, const EmailAddress& emailAddress, const string& firstName, const string& lastName, const Address& address)
        :User(username, password, emailAddress, firstName, lastName, address){}
    
    StaffMember(){}
    ~StaffMember(){}
    
	virtual void printMenu() = 0;

	void viewScreenings();

	void addScreening();

	void editScreening();

	void removeScreening();

	void manageRoom();
};

#endif // StaffMember_H