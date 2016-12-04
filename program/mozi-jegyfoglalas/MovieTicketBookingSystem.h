#ifndef MovieTicketBookingSystem_H
#define MovieTicketBookingSystem_H

#include <vector>
#include "Guest.h"
#include "ErrorLog.h"
#include "User.h"
#include "Room.h"
#include "Screening.h"
using namespace std;

class MovieTicketBookingSystem
{
private:
	vector<Room> rooms;
	vector<Screening> screenings;
    vector<ErrorLog> errorLogs;
	vector<Guest> guests;
	vector<User*> users;

public:
    MovieTicketBookingSystem(){}
    ~MovieTicketBookingSystem(){}
    
	void printWelcomeScreen();

	void quit();

	bool checkRoomAvailability(Room& room, DateTime& date);

	bool checkIfSeatsEnough(Screening& screening, Room& room);

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

	void printStaffMembers();

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
    
    int findErrorLog(int id)
    {
        for(unsigned int i=0; i<errorLogs.size(); i++)
        {
            if(errorLogs[i].getId() == id)
                return i;
        };
        throw "ErrorLog with this ID doesn't exist.";
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
    
    ErrorLog& getErrorLog(int id)
    {
        int errorLogIndex=findErrorLog(id);
        return errorLogs[errorLogIndex];
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
};

#endif // MovieTicketBookingSystem_H