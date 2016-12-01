#include "EmailAddress.h"

string EmailAddress::getUsername() const
{
    return username;
}

void EmailAddress::setUsername(const string &value)
{
    username = value;
}

string EmailAddress::getDomain() const
{
    return domain;
}

void EmailAddress::setDomain(const string &value)
{
    domain = value;
}
