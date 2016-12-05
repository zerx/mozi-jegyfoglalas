#ifndef MovieTicketBookingSystem_H
#define MovieTicketBookingSystem_H

#include <vector>
#include "Guest.h"
#include "ErrorLog.h"
#include "User.h"
#include "Room.h"
#include "Screening.h"
#include "Customer.h"
#include "StaffMember.h"
#include "Admin.h"
using namespace std;

class MovieTicketBookingSystem
{
private:
	vector<Room> rooms;
	vector<Screening> screenings;
    ErrorLog errorLog;
	vector<Guest> guests;
	vector<User*> users;

public:
    MovieTicketBookingSystem(const ErrorLog& errorLog)
    {
        this->errorLog=errorLog;
    }
    
    ~MovieTicketBookingSystem(){}
    
	void printWelcomeScreen();

	void quit();

	bool checkRoomAvailability(Room& room, DateTime& date)
    {
        bool unavailable=false;
        for(unsigned int i=0; i<screenings.size() && unavailable==false; i++)
        {
            DateTime time=screenings[i].getTime();
            if(time==date)
            {
                if(screenings[i].getRoom()==room)
                    unavailable=true;
            }
            else
            {
                for(int h=0; h<4 && unavailable==true; h++)
                {
                    time.setHour(+h);
                    for(int m=0; m<60 && unavailable==true; m++)
                    {
                        time.setMinute(m);
                        if(time==date)
                            if(screenings[i].getRoom()==room)
                                unavailable=true;
                    }
                }
            }
        };
        return unavailable;
    }

	bool checkIfSeatsEnough(Screening& screening, Room& room)
    {
        if(screening.getRoom().getNumOfSeats() >= room.getNumOfSeats())
            return true;
        else return false;
    }

	void printRooms()
    {
        if(rooms.size()==0)
        {
            cout << "There are no rooms." << endl;
            return;
        }
        else
        {
            cout << "[ID]\t[Name] [Number of seats]" << endl;
            for(unsigned int i=0; i<rooms.size(); i++)
            {
                cout << rooms[i].getId() << "\t" << rooms[i].getName() << " " << rooms[i].getNumOfSeats() << endl;
            };
            cout << endl;
        }
    }

	void printScreenings()
    {
        if(screenings.size()==0)
        {
            cout << "There are no scheduled screenings." << endl;
            return;
        }
        else
        {
            cout << "[ID]\t[Date & time] [Movie title] [Room name] [Price]" << endl;
            for(unsigned int i=0; i<screenings.size(); i++)
            {
                if(screenings[i].getIsCancelled()==false)
                {
                    cout << screenings[i].getId() << "\t";
                    screenings[i].getTime().print();
                    cout << " " << screenings[i].getMovieName() << " <Room: " << screenings[i].getRoom().getName() << " > " << screenings[i].getPrice() << endl;
                }
            }
        }
    }

	void printStaffMembers()
    {
        if(users.size()==0)
        {
            cout << "There are no registered users." << endl;
            return;
        }
        else
        {
            int numOfAdmins=0;
            for(unsigned int i=0; i<users.size(); i++)
            {
                if(Admin* user = dynamic_cast<Admin*>(users[i]))
                {
                    numOfAdmins++;
                    user=user;
                }
            };
            if(numOfAdmins==0)
            {
                cout << "There are no registered staff members." << endl;
                return;
            }
            else if(numOfAdmins>0)
            {
                cout << "[User ID]\t[Username] [First name] [Last name]" << endl;
                for(unsigned int i=0; i<users.size(); i++)
                {
                    if(Admin* user = dynamic_cast<Admin*>(users[i]))
                        cout << user->getId() << "\t" << user->getUsername() << " " << user->getFirstName() << " " << user->getLastName() << endl;
                };
            }
        }
    }

	int findRoom(int id)
    {
        for(unsigned int i= 0; i<rooms.size(); i++)
        {
            if(rooms[i].getId() == id)
                return i;
        };
        throw "Room with this ID doesn't exist.";
    }

    int findScreening(int id)
    {
        for(unsigned int i=0; i<screenings.size(); i++)
        {
            if(screenings[i].getId() == id)
                return i;
        };
        throw "Screening with this ID doesn't exist.";
    }
    
    int findGuest(int id)
    {
        for(unsigned int i= 0; i<guests.size(); i++)
        {
            if(guests[i].getId() == id)
                return i;
        };
        throw "Guest with this ID doesn't exist.";
    }

    int findUser(int id)
    {
        for(unsigned int i= 0; i<users.size(); i++)
        {
            if(users[i]->getId() == id)
                return i;
        };
        throw "User with this ID doesn't exist.";
    }
    
    Room& getRoom(int id)
    {
        int roomIndex=findRoom(id);
        return rooms[roomIndex];
    }
    
    Screening& getScreening(int id)
    {
        int screeningIndex=findScreening(id);
        return screenings[screeningIndex];
    }
    
    Guest& getGuest(int id)
    {
        int guestIndex=findGuest(id);
        return guests[guestIndex];
    }
    
    User& getUser(int id)
    {
        int userIndex=findUser(id);
        return *users[userIndex];
    }
    
    const ErrorLog& getErrorLog() const;
};

#endif // MovieTicketBookingSystem_H