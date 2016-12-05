#include "Address.h"

const string& Address::getProvince() const
{
    return province;
}

void Address::setProvince(const string &value)
{
    province = value;
}

const string& Address::getTown() const
{
    return town;
}

void Address::setTown(const string &value)
{
    town = value;
}

const string& Address::getPostCode() const
{
    return postCode;
}

void Address::setPostCode(const string &value)
{
    postCode = value;
}

const string& Address::getAddressLine() const
{
    return addressLine;
}

void Address::setAddressLine(const string &value)
{
    addressLine = value;
}

const string& Address::getCountry() const
{
    return country;
}

void Address::setCountry(const string &value)
{
    country = value;
}
