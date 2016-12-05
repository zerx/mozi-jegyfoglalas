#include "EmailAddress.h"

const string& EmailAddress::getUsername() const
{
    return username;
}

void EmailAddress::setUsername(const string &value)
{
    username = value;
}

const string& EmailAddress::getDomain() const
{
    return domain;
}

void EmailAddress::setDomain(const string &value)
{
    domain = value;
}
