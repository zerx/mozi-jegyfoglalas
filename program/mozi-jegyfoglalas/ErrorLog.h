#ifndef ErrorLog_H
#define ErrorLog_H

#include <vector>
#include "ErrorEntry.h"

class ErrorLog
{
private:
	vector<ErrorEntry> errors;

public:
    ErrorLog(){}
    ~ErrorLog(){}
    
    void printErrors()
    {
        if(errors.size()==0)
        {
            cout << "There are no recorded errors." << endl;
            return;
        }
        else
        {
            cout << "[ID]\t[Error type]\t\t\t\t[Date & Time]" << endl;
            for(unsigned int i= 0; i<errors.size(); i++)
            {
                cout << errors[i].getId() << "\t" << errors[i].getErrorType() << " (";
                errors[i].getTime().print();
                cout << ")" << endl;
            };
            cout << endl;
        }
    }
    
    void addError(const ErrorEntry& error)
    {
        errors.push_back(error);
    }
    
	int findError(int id)
    {
        for(unsigned int i= 0; i<errors.size(); i++)
        {
            if(errors[i].getId() == id)
                return i;
        };
        throw "ErrorEntry with this ID doesn't exist.";
    }
    
    ErrorEntry& getError(int id)
    {
        int errorIndex=findError(id);
        return errors[errorIndex];
    }
};

#endif // ErrorLog_H