#ifndef User_H
#define User_H

#include <string>
#include "EmailAddress.h"
#include "Address.h"
using namespace std;

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
    
	virtual void printMenu() = 0;
    
    int getId() const;
    string getUsername() const;
    string getPassword() const;
    void setPassword(const string &value);
    EmailAddress getEmailAddress() const;
    void setEmailAddress(const EmailAddress &value);
    string getFirstName() const;
    void setFirstName(const string &value);
    string getLastName() const;
    void setLastName(const string &value);
    Address getAddress() const;
    void setAddress(const Address &value);
};

#endif // User_H