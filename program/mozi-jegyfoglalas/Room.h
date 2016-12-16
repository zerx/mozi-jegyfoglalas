#ifndef Room_H
#define Room_H

#include <string>
using namespace std;

class Room
{
private:
	static int nextId;
	int id;
	string name;
	unsigned int numOfSeats;
    
public:
    Room(const string& name, int numOfSeats)
    {
        id=nextId;
        nextId++;
        this->name=name;
        this->numOfSeats=numOfSeats;
    }
    
    Room(){}
    ~Room(){}
    
    bool operator==(Room const& r) const
    {
        if(id==r.id)
        {
            return true;
        }
        else return false;
    }
    
    const string& getName() const;
    void setName(const string &value);
    unsigned int getNumOfSeats() const;
    void setNumOfSeats(unsigned int value);
    int getId() const;
};

#endif // Room_H