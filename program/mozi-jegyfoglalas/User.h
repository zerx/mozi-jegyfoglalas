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
};

#endif // User_H