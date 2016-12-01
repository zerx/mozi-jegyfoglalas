#ifndef Guest_H
#define Guest_H

#include <string>
using namespace std;

class Guest
{
    static int nextId;
    int id;
public:
    Guest()
    {
        id=nextId;
        nextId++;
    }
    
    ~Guest(){}
    
	void printMenu();

	void registerAccount();

	void backToWelcomeScreen();
    
    int getId() const;
};

#endif // Guest_H