#ifndef ErrorLog_H
#define ErrorLog_H

#include <string>
#include <vector>
#include "ErrorEntry.h"
using namespace std;

class ErrorLog
{
private:
    static int nextId;
    int id;
	vector<ErrorEntry> errors;

public:
    ErrorLog()
    {
        id=nextId;
        nextId++;
    }
    
    ~ErrorLog(){}
    
    void printErrors()
    {
        for(unsigned int i= 0; i<errors.size(); i++)
        {
            cout << errors[i].getId() << " " << errors[i].getErrorType() << " ";
            errors[i].getTime().print();
            cout << endl;
        };
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
    
    int getId() const;
};

#endif // ErrorLog_H