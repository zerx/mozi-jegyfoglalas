#include "Address.h"

string Address::getProvince() const
{
    return province;
}

void Address::setProvince(const string &value)
{
    province = value;
}

string Address::getTown() const
{
    return town;
}

void Address::setTown(const string &value)
{
    town = value;
}

string Address::getPostCode() const
{
    return postCode;
}

void Address::setPostCode(const string &value)
{
    postCode = value;
}

string Address::getAddressLine() const
{
    return addressLine;
}

void Address::setAddressLine(const string &value)
{
    addressLine = value;
}

string Address::getCountry() const
{
    return country;
}

void Address::setCountry(const string &value)
{
    country = value;
}
