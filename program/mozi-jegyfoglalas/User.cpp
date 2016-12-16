#include "User.h"

int User::nextId=0;

const string& User::getUsername() const
{
    return username;
}

const string& User::getPassword() const
{
    return password;
}

void User::setPassword(const string &value)
{
    password = value;
}

const EmailAddress& User::getEmailAddress() const
{
    return emailAddress;
}

void User::setEmailAddress(const EmailAddress &value)
{
    emailAddress = value;
}

const string& User::getFirstName() const
{
    return firstName;
}

void User::setFirstName(const string &value)
{
    firstName = value;
}

const string& User::getLastName() const
{
    return lastName;
}

void User::setLastName(const string &value)
{
    lastName = value;
}

const Address& User::getAddress() const
{
    return address;
}

void User::setAddress(const Address &value)
{
    address = value;
}

usertype User::getType() const
{
    return type;
}

int User::getId() const
{
    return id;
}
