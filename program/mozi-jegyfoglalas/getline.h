#ifndef GETLINE
#define GETLINE

#include <string>
using namespace std;

inline string getLine(bool usedAfterCin)
{
    string description;
    char end;
    bool finished = false;
    
    if(usedAfterCin==true)
    {
        getchar();
    }
    while(finished!=true)
    {
        end= getchar();
        if(end!='\n')
        {
            description+=end;
        }
        else
        {
            finished=true;
        }
    }
    return description;
}

#endif // GETLINE

