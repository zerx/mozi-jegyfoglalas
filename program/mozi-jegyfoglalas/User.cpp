#include "User.h"

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

void User::setPassword(const string &value)
{
    password = value;
}

EmailAddress User::getEmailAddress() const
{
    return emailAddress;
}

void User::setEmailAddress(const EmailAddress &value)
{
    emailAddress = value;
}

string User::getFirstName() const
{
    return firstName;
}

void User::setFirstName(const string &value)
{
    firstName = value;
}

string User::getLastName() const
{
    return lastName;
}

void User::setLastName(const string &value)
{
    lastName = value;
}

Address User::getAddress() const
{
    return address;
}

void User::setAddress(const Address &value)
{
    address = value;
}

int User::getId() const
{
    return id;
}
