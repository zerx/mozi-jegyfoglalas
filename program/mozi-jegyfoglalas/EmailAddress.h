#ifndef EmailAddress_H
#define EmailAddress_H

#include <string>
using namespace std;

class EmailAddress
{
private:
    string username;
    string domain;
    
public:
    EmailAddress(const string& username, const string& domain)
    {
        this->username=username;
        this->domain=domain;
    }

    EmailAddress(){}
    ~EmailAddress(){}
    
    string getUsername() const;
    void setUsername(const string &value);
    
    string getDomain() const;
    void setDomain(const string &value);
};

#endif // EmailAddress_H