#ifndef Address_H
#define Address_H

#include <string>
using namespace std;

class Address
{
private:
	string country;
	string province;
	string town;
	string postCode;
	string addressLine;
    
public:
    Address(const string& country, const string& province, const string& town, const string& postCode, const string& addressLine)
    {
        this->country=country;
        this->province=province;
        this->town=town;
        this->postCode=postCode;
        this->addressLine=addressLine;
    }

    Address(){}
    ~Address(){}
    
    string getCountry() const;
    void setCountry(const string &value);
    string getProvince() const;
    void setProvince(const string &value);
    string getTown() const;
    void setTown(const string &value);
    string getPostCode() const;
    void setPostCode(const string &value);
    string getAddressLine() const;
    void setAddressLine(const string &value);
};

#endif // Address