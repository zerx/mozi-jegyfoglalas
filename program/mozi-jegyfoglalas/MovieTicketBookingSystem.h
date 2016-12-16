#ifndef MovieTicketBookingSystem_H
#define MovieTicketBookingSystem_H

#include "ErrorLog.h"
#include "Customer.h"
#include "StaffMember.h"
#include "Admin.h"
#include "getline.h"
#include "exception"

class MovieTicketBookingSystem
{
private:
	vector<Room> rooms;
	vector<Screening> screenings;
    ErrorLog errorLog;
	vector<User*> users;
    User* currentUser;
    
public:
    MovieTicketBookingSystem(const ErrorLog& errorLog)
    {
        this->errorLog=errorLog;
        currentUser=NULL;
    }
    
    ~MovieTicketBookingSystem()
    {
        currentUser=NULL;
    }
    
    ///////////////////////////////////////////////////////
    /// \brief MENUS
    ///////////////////////////////////////////////////////
    
    void printWelcomeScreen()
    {
        bool finished=false;
        int selection=0;
        while(finished==false)
        {
            cout << "Welcome to SuperGolden CineMather!" << endl
                << "What would you like to do?" << endl
                << "1 - View upcoming screenings" << endl
                << "2 - Log into your account" << endl
                << "3 - Register" << endl
                << "9 - Exit" << endl;
            cin >> selection;
            switch(selection)
            {
            case 1:
                viewScreenings();
                break;
            case 2:
                logIn();
                break;
            case 3:
                registerAccount();
                break;
            case 9:
                finished=true;
                break;
            default:
                break;
            }
        }
    }
    
    void printCustomerMenu()
    {
        bool finished=false;
        int selection=0;
        while(finished==false)
        {
            cout << "What would you like to do?" << endl
                << "1 - View upcoming screenings" << endl
                << "2 - Book a ticket" << endl
                << "3 - View bookings" << endl
                << "4 - Cancel a booking" << endl
                << "5 - Pay a reservation" << endl
                << "6 - View payments" << endl
                << "8 - Edit account data" << endl
                << "9 - Log out" << endl;
            cin >> selection;
            switch(selection)
            {
            case 1:
                viewScreenings();
                break;
            case 2:
                reserve();
                break;
            case 3:
                viewReservations();
                break;
            case 4:
                cancelReservation();
                break;
            case 5:
                pay();
                break;
            case 6:
                viewPayments();
                break;
            case 8:
                changeAccountData();
                break;
            case 9:
                finished=true;
                currentUser=NULL;
                cout << "You have successfully logged out." << endl <<endl;
                break;
            default:
                break;
            }
        }
    }
    
    void printStaffMemberMenu()
    {
        bool finished=false;
        int selection=0;
        while(finished==false)
        {
            cout << "What would you like to do?" << endl
                << "1 - View upcoming screenings" << endl
                << "2 - Add a new screening" << endl
                << "3 - Change a screening" << endl
                << "4 - Cancel a screening" << endl
                << "5 - Change the number of seats in a room" << endl
                << "8 - Edit account Data" << endl
                << "9 - Log out" << endl;
            cin >> selection;
            switch(selection)
            {
            case 1:
                viewScreenings();
                break;
            case 2:
                addScreening();
                break;
            case 3:
                editScreening();
                break;
            case 4:
                removeScreening();
                break;
            case 5:
                manageRoom();
                break;
            case 8:
                changeAccountData();
                break;
            case 9:
                finished=true;
                currentUser=NULL;
                cout << "You have successfully logged out." << endl <<endl;
                break;
            default:
                break;
            }
        }
    }
        
    void printAdminMenu()
    {
        bool finished=false;
        int selection=0;
        while(finished==false)
        {
            cout << "What would you like to do?" << endl
                << "1 - Register a new staff member" << endl
                << "2 - Delete a staff member's account" << endl
                << "3 - View error log" << endl
                << "8 - Edit account data" << endl
                << "9 - Log out" << endl;
            cin >> selection;
            switch(selection)
            {
            case 1:
                addStaffMember();
                break;
            case 2:
                removeStaffMember();
                break;
            case 3:
                viewErrorLog();
                break;
            case 8:
                changeAccountData();
                break;
            case 9:
                finished=true;
                currentUser=NULL;
                cout << "You have successfully logged out." << endl <<endl;
                break;
            default:
                break;
            }
        }
    }
    
    ///////////////////////////////////////////////////////
    /// \brief GUEST & CUSTOMER & STAFF MEMBER
    ///////////////////////////////////////////////////////
    
    void viewScreenings()
    {
        if(screenings.size()==0)
        {
            cout << "There are no scheduled screenings." << endl << endl;
            return;
        }
        else
        {
            cout << "[ID]\t[Date & time]\t  [Movie title]\t\t[Room name] [Free seats] [Price]" << endl;
            for(unsigned int i=0; i<screenings.size(); i++)
            {
                if(screenings[i].getIsCancelled()==false)
                {
                    cout << screenings[i].getId() << "\t";
                    screenings[i].getTime().print();
                    cout << " " << screenings[i].getMovieName() << "\t\t<Room: " << screenings[i].getRoom().getName() << " >  ";
                    unsigned int seats=screenings[i].checkNumOfFreeSeats();
                    if(seats<10)
                    {
                        cout << " ";
                    }
                    cout << seats << "\t\t " << screenings[i].getPrice() << endl;
                }
            }
            cout << endl;
        }
    }    
    
    ///////////////////////////////////////////////////////
    /// \brief GUEST
    ///////////////////////////////////////////////////////
    
    void registerAccount()
    {
        cout << "Please enter your account's details or 'Q' to exit anytime." << endl;
        cout << "Please enter your desired username - must be at least 6 characters long." << endl;
        string username;
        cin >> username;
        if(username=="Q" || username=="q")
        {
            return;
        }
        bool accepted=false;
        while(username.length()<6 || accepted==false)
        {
            if(username.length()<6)
            {
                cout << "Your username must be at least 6 characters long. Please choose a different username." << endl;
                cin >> username;
            }
            accepted=false;
            
            if(username=="Q" || username=="q")
            {
                return;
            }
            if(username.length()>=6)
            {
                bool valid=true;
                for(unsigned int i=0; i<users.size() && valid==true; i++)
                {
                    if(username==users[i]->getUsername())
                    {
                        valid=false;
                        cout << "This username is already in use. Please choose a different username." << endl;
                        cin >> username;
                    }
                }
                if(valid==true)
                {
                    accepted=true;
                }
            }
        }
        
        cout << "Please enter your password - must be at least 6 characters long." << endl;
        string password;
        cin >> password;
        if(password=="Q" || password=="q")
        {
            return;
        }
        while(password.length()<6)
        {
            cout << "Your password must be at least 6 characters long. Please enter a different password." << endl;
            cin >> password;
            if(password=="Q" || password=="q")
            {
                return;
            }
        }
        
        cout << "Please enter your e-mail address' user and domain name separated by a space." << endl;
        string email1;
        cin >> email1;
        if(email1=="Q" || email1=="q")
        {
            return;
        }
        string email2;
        cin >> email2;
        if(email2=="Q" || email2=="q")
        {
            return;
        }
        
        cout << "Please enter your first name." << endl;
        string name1;
        name1=getLine(true);
        if(name1=="Q" || name1=="q")
        {
            return;
        }
        cout << "Please enter your surname." << endl;
        string name2;
        name2=getLine(false);
        if(name2=="Q" || name2=="q")
        {
            return;
        }
        
        cout << "Please enter the name of your country." << endl;
        string country;
        country=getLine(false);
        if(country=="Q" || country=="q")
        {
            return;
        }
        cout << "Please enter the name of your province/state/county." << endl;
        string province;
        province=getLine(false);
        if(province=="Q" || province=="q")
        {
            return;
        }
        cout << "Please enter the name of your town." << endl;
        string town;
        town=getLine(false);
        if(town=="Q" || town=="q")
        {
            return;
        }
        cout << "Please enter the postcode of your town." << endl;
        string postCode;
        cin >> postCode;
        if(postCode=="Q" || postCode=="q")
        {
            return;
        }
        cout << "Please enter your address." << endl;
        string addressLine;
        addressLine=getLine(true);
        if(addressLine=="Q" || addressLine=="q")
        {
            return;
        }
        
        EmailAddress email(email1, email2);
        Address address(country, province, town, postCode, addressLine);
        User* user= new Customer(username, password, email, name1, name2, address);
        users.push_back(user);
        
        cout << "Registration successful. A notification will be send to your e-mail address ending with " << user->getEmailAddress().getDomain() << "." << endl << endl;
    }
    
    ///////////////////////////////////////////////////////
    /// \brief USER
    ///////////////////////////////////////////////////////
    
    void logIn()
    {
        cout << "Enter your username or 'Q' to exit." << endl;
        string input;
        cin >> input;
        if(input=="Q" || input=="q")
        {
            return;
        }
        bool exists=false;
        int userIndex;
        for(unsigned int i=0; i<users.size() && exists==false; i++)
        {
            if(users[i]->getUsername()==input)
            {
                exists=true;
                userIndex=i;
            }
        }
        if(exists==true)
        {
            cout << "Enter your password." << endl;
            cin >> input;
            if(users[userIndex]->getPassword()==input)
            {
                cout << "Login successful. Welcome, " << users[userIndex]->getFirstName() << "!" << endl << endl;
                currentUser=users[userIndex];

                if(currentUser->getType()==_admin)
                {
                    printAdminMenu();
                }
                else if(currentUser->getType()==staff)
                {
                    printStaffMemberMenu();
                }
                else if(currentUser->getType()==customer)
                {
                    printCustomerMenu();
                }
                else return;
            }
            else
            {
                ErrorEntry error("Incorrect login: password mismatch <to: " + users[userIndex]->getPassword() + ">");
                errorLog.addError(error);
                cout << "Incorrect password." << endl << endl;
            }
        }
        else
        {
            cout << "There's no such registered user." << endl << endl;
        }
    }
    
    void changeAccountData()
    {
        cout << "Your account's current data:" << endl
            << "Username: " << currentUser->getUsername() << endl
            << "E-mail address: " << currentUser->getEmailAddress().getUsername() << "@" << currentUser->getEmailAddress().getDomain() << endl
            << "Name: " << currentUser->getFirstName() << " " << currentUser->getLastName() << endl
            << "Address: " << currentUser->getAddress().getAddressLine() << endl
            << "         " << currentUser->getAddress().getTown() << ", " << currentUser->getAddress().getPostCode() << endl
            << "         " << currentUser->getAddress().getProvince() << ", " << currentUser->getAddress().getCountry() << endl << endl;
        int selection=0;
        cout << "What would you like to change?" << endl
            << "1 - Change name" << endl
            << "2 - Change address" << endl
            << "3 - Change e-mail address" << endl
            << "4 - Change password" << endl
            << "9 - Return to main menu" << endl;
        cin >> selection;
        switch(selection)
        {
        case 1:
            changeName();
            break;
        case 2:
            changeAddress();
            break;
        case 3:
            changeEmailAddress();
            break;
        case 4:
            changePassword();
            break;
        default:
            break;
        }
    }
    
    void changeName()
    {
        cout << "Not yet implemented." << endl;
    }
    
    void changeAddress()
    {
        cout << "Not yet implemented." << endl;
    }
    
    void changeEmailAddress()
    {
        cout << "Not yet implemented." << endl;
    }
    
    void changePassword()
    {
        cout << "Not yet implemented." << endl;
    }
    
    ///////////////////////////////////////////////////////
    /// \brief CUSTOMER
    ///////////////////////////////////////////////////////

    void reserve()
    {
        viewScreenings();
        cout << "Please enter the ID of the screening you would like to book a ticket for or 'Q' to cancel." << endl;
        string input;
        cin >> input;
        if(input=="Q" || input=="q")
        {
            return;
        }
        int id=stoi(input);
        int screeningIndex=findScreening(id);
        if(screeningIndex<0)
        {
            cout << "There's no such screening." << endl << endl;
            return;
        }
        unsigned int freeSeats=screenings[screeningIndex].checkNumOfFreeSeats();
        if(freeSeats<1)
        {
            cout << "There are no free seats for this screening." << endl << endl;
            return;
        }
        else
        {
            cout << "There are " << freeSeats << " free seats for this screening. How many tickets would you like to book? Enter '0' to ancel." << endl;
            unsigned int tickets;
            cin >> tickets;
            if(tickets==0)
            {
                return;
            }
            unsigned int seats=screenings[screeningIndex].getRoom().getNumOfSeats();
            if(freeSeats-tickets<=seats)
            {
                Reservation reservation(screenings[screeningIndex], tickets);
                unsigned int reservationNum=screenings[screeningIndex].getNumOfReservations();
                screenings[screeningIndex].setNumOfReservations(reservationNum+tickets);
                currentUser->addReservation(reservation);
                sort(currentUser->getReservations().begin(), currentUser->getReservations().end());
                cout << tickets << " tickets booked successfully." << endl << endl;
            }
            else
            {
                cout << "There aren't enough free seats for this screening." << endl << endl;
            }
        }
    }
    
    void viewReservations()
    {
        currentUser->printReservations();
    }
    
    void cancelReservation()
    {
        currentUser->printUnpaidReservations();
        cout << "Enter the ID of the booking you would like to cancel or 'Q' to return to the main menu." << endl;
        string input;
        cin >> input;
        if(input=="Q" || input=="q")
        {
            return;
        }
        int id=stoi(input);
        int reservationIndex=currentUser->findReservation(id);
        if(reservationIndex<0)
        {
            cout << "There's no such booking." << endl << endl;
            return;
        }
        if(currentUser->getReservation(id).getIsPaid()==true)
        {
            cout << "You can't cancel a booking that's already paid." << endl << endl;
            return;
        }
        cout << "Are you sure you want to cancel this booking? This can not be undone. Enter 'Y' to confirm or anything else to cancel." << endl;
        cin >> input;
        if(input=="Y" || input=="y")
        {
            currentUser->getReservations().erase(currentUser->getReservations().begin()+reservationIndex);
            sort(currentUser->getReservations().begin(), currentUser->getReservations().end());
            cout << "Booking cancellation successful." << endl << endl;
            return;
        }
        cout << "Booking cancellation cancelled." << endl << endl;
    }
    
    void pay()
    {
        currentUser->printUnpaidReservations();
        cout << "Enter the ID of the booking you would like to pay for or 'Q' to return to the main menu" << endl;
        string input;
        cin >> input;
        if(input=="Q" || input=="q")
        {
            return;
        }
        int id=stoi(input);
        int reservationIndex=currentUser->findReservation(id);
        if(reservationIndex<0)
        {
            cout << "There's no such booking." << endl << endl;
            return;
        }
        if(currentUser->getReservation(id).getIsPaid()==true)
        {
            cout << "You've already paid for that booking." << endl << endl;
            return;
        }
        cout << "This is your last chance to review your purchase." << endl
            << "Billing address:" << "\t\t\t" << "Order:" << endl
            << currentUser->getFirstName() << " " << currentUser->getLastName() << "\t\t\t\t" << "cinema ticket" << endl
            << currentUser->getAddress().getAddressLine() << "\t\t\t" <<  "price: " << currentUser->getReservation(id).getScreening().getPrice() << endl
            << currentUser->getAddress().getTown() << ", " << currentUser->getAddress().getPostCode() << "\t\t\t" << "amount: " << currentUser->getReservation(id).getNumOfTickets() << endl
            << currentUser->getAddress().getCountry() << "\t\t" << "total: " << currentUser->getReservation(id).getTotalPrice() << endl << endl
            << "Are you sure you want to pay for this booking? By continuing you expressivly waive your right of withdrawal" << endl
            <<"therefore NO REFUNDS are possible - the purchase is FINAL. Enter 'Y' to confirm or anything else to cancel." << endl;
        cin >> input;
        if(input=="Y" || input=="y")
        {
            currentUser->getReservation(id).setIsPaid(true);
            Payment payment(currentUser->getReservation(id), true);
            currentUser->getPayments().push_back(payment);
            cout << "Payment successful." << endl << "\t\t\tRECEIPT" << endl
                << "Billing address:" << "\t\t\t" << "Order:" << endl
                << currentUser->getFirstName() << " " << currentUser->getLastName() << "\t\t\t\t" << "cinema ticket" << endl
                << currentUser->getAddress().getAddressLine() << "\t\t\t" <<  "price: " << currentUser->getReservation(id).getScreening().getPrice() << endl
                << currentUser->getAddress().getTown() << ", " << currentUser->getAddress().getPostCode() << "\t\t\t" << "amount: " << currentUser->getReservation(id).getNumOfTickets() << endl
                << currentUser->getAddress().getCountry() << "\t\t" << "total: " << currentUser->getReservation(id).getTotalPrice() << endl
                << "A copy of this receipt will be sent to your e-mail address ending with " << currentUser->getEmailAddress().getDomain() << "." << endl << endl;
            return;
        }
        Payment payment(currentUser->getReservation(id), false);
        currentUser->getPayments().push_back(payment);
        ErrorEntry error("Invalid payment: user cancellation <by: " + currentUser->getUsername() + ">");
        errorLog.addError(error);
        cout << "Booking payment cancelled." << endl << endl;
    }
    
    void viewPayments()
    {
        currentUser->printPayments();
    }
    
    ///////////////////////////////////////////////////////
    /// \brief STAFF MEMBER
    ///////////////////////////////////////////////////////
    
    void addScreening()
    {
        cout << "Not yet implemented." << endl;
    }
    
    void editScreening()
    {
        viewScreenings();
        cout << "Please enter the ID of the screening you would like to change or 'Q' to cancel." << endl;
        string input;
        cin >> input;
        if(input=="Q" || input=="q")
        {
            return;
        }
        int id=stoi(input);
        int screeningIndex=findScreening(id);
        if(screeningIndex<0)
        {
            cout << "There's no such screening." << endl << endl;
            return;
        }
        cout << "What would you like to change?" << endl
            << "1 - Change date and time" << endl
            << "2 - Change room" << endl
            << "9 - Return to main menu" << endl;
        int selection;
        cin >> selection;
        switch(selection)
        {
        case 1:
            changeScreeningTime(screenings[screeningIndex]);
            break;
        case 2:
            changeScreeningRoom(screenings[screeningIndex]);
            break;
        default:
            break;
        }
    }
    
    void changeScreeningTime(Screening& screening)
    {
        cout << "Not yet implemented." << endl;
    }
    
    void changeScreeningRoom(Screening& screening)
    {
        cout << "Not yet implemented." << endl;
    }
    
    void removeScreening()
    {
        cout << "Not yet implemented." << endl;
    }
    
    void manageRoom()
    {
        cout << "Not yet implemented." << endl;
    }
    
    ///////////////////////////////////////////////////////
    /// \brief ADMINISTRATOR
    ///////////////////////////////////////////////////////
    
    void addStaffMember()
    {
        cout << "Please enter the details of the staff member's account or 'Q' to exit anytime." << endl;
        cout << "Please enter the staff member's desired username - must be at least 6 characters long." << endl;
        string username;
        cin >> username;
        if(username=="Q" || username=="q")
        {
            return;
        }
        bool accepted=false;
        while(username.length()<6 || accepted==false)
        {
            if(username.length()<6)
            {
                cout << "The username must be at least 6 characters long. Please choose a different username." << endl;
                cin >> username;
            }
            accepted=false;
            
            if(username=="Q" || username=="q")
            {
                return;
            }
            if(username.length()>=6)
            {
                bool valid=true;
                for(unsigned int i=0; i<users.size() && valid==true; i++)
                {
                    if(username==users[i]->getUsername())
                    {
                        valid=false;
                        cout << "This username is already in use. Please choose a different username." << endl;
                        cin >> username;
                    }
                }
                if(valid==true)
                {
                    accepted=true;
                }
            }
        }
        
        cout << "Please enter the staff member's temporary password - must be at least 6 characters long." << endl;
        string password;
        cin >> password;
        if(password=="Q" || password=="q")
        {
            return;
        }
        while(password.length()<6)
        {
            cout << "The password must be at least 6 characters long. Please enter a different password." << endl;
            cin >> password;
            if(password=="Q" || password=="q")
            {
                return;
            }
        }
        
        cout << "Please enter the staff member's e-mail address' user and domain name separated by a space." << endl;
        string email1;
        cin >> email1;
        if(email1=="Q" || email1=="q")
        {
            return;
        }
        string email2;
        cin >> email2;
        if(email2=="Q" || email2=="q")
        {
            return;
        }
        
        cout << "Please enter the staff member's first name." << endl;
        string name1;
        name1=getLine(true);
        if(name1=="Q" || name1=="q")
        {
            return;
        }
        cout << "Please enter the staff member's surname." << endl;
        string name2;
        name2=getLine(false);
        if(name2=="Q" || name2=="q")
        {
            return;
        }
        
        cout << "Please enter the name of the staff member's country." << endl;
        string country;
        country=getLine(false);
        if(country=="Q" || country=="q")
        {
            return;
        }
        cout << "Please enter the name of the staff member's province/state/county." << endl;
        string province;
        province=getLine(false);
        if(province=="Q" || province=="q")
        {
            return;
        }
        cout << "Please enter the name of the staff member's town." << endl;
        string town;
        town=getLine(false);
        if(town=="Q" || town=="q")
        {
            return;
        }
        cout << "Please enter the postcode of the staff member's town." << endl;
        string postCode;
        cin >> postCode;
        if(postCode=="Q" || postCode=="q")
        {
            return;
        }
        cout << "Please enter the staff member's address." << endl;
        string addressLine;
        addressLine=getLine(true);
        if(addressLine=="Q" || addressLine=="q")
        {
            return;
        }
        
        EmailAddress email(email1, email2);
        Address address(country, province, town, postCode, addressLine);
        User* user= new StaffMember(username, password, email, name1, name2, address);
        users.push_back(user);
        
        cout << "Registration successful. A notification will be send to the staff member's e-mail address ending with " << user->getEmailAddress().getDomain() << "." << endl << endl;
    }
    
    void removeStaffMember()
    {
        printStaffMembers();
        cout << "Enter the ID of the staff member whose account would like to delete or 'Q' to return to the main menu." << endl;
        string input;
        cin >> input;
        if(input=="Q" || input=="q")
        {
            return;
        }
        int id=stoi(input);
        int userIndex=findUser(id);
        if(userIndex<0)
        {
            cout << "There's no such user." << endl << endl;
            return;
        }
        if(getUser(id).getType()!=staff)
        {
            cout << "This user is not a staff member." << endl << endl;
            return;
        }
        cout << "Are you sure you want to delete " << getUser(id).getUsername() << "'s account? This can not be undone. Enter 'Y' to confirm or anything else to cancel." << endl;
        cin >> input;
        if(input=="Y" || input=="y")
        {
            users.erase(users.begin()+userIndex);
            cout << "Staff member's account deletion successful." << endl << endl;
            return;
        }
        ErrorEntry error("Invalid account deletion: admin cancellation <by: " + currentUser->getUsername() + ">");
        errorLog.addError(error);
        cout << "Staff member's account deletion cancelled." << endl << endl;
    }
    
    void viewErrorLog()
    {
        errorLog.printErrors();
    }
    
    ///////////////////////////////////////////////////////
    /// \brief MISC
    ///////////////////////////////////////////////////////
    
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
            cout << "There are no rooms." << endl << endl;
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

	void printStaffMembers()
    {
        if(users.size()==0)
        {
            cout << "There are no registered users." << endl << endl;
            return;
        }
        else
        {
            int numOfAdmins=0;
            for(unsigned int i=0; i<users.size(); i++)
            {
                if(users[i]->getType()==staff)
                {
                    numOfAdmins++;
                }
            };
            if(numOfAdmins==0)
            {
                cout << "There are no registered staff members." << endl << endl;
                return;
            }
            else if(numOfAdmins>0)
            {
                cout << "[ID]\t[Username]\t[First name] [Last name]" << endl;
                for(unsigned int i=0; i<users.size(); i++)
                {
                    if(users[i]->getType()==staff)
                        cout << users[i]->getId() << "\t" << users[i]->getUsername() << "\t" << users[i]->getFirstName() << "\t" << users[i]->getLastName() << endl;
                };
                cout << endl;
            }
        }
    }
    
    void addRoom(const Room& room)
    {
        rooms.push_back(room);
    }
    
    void addScreening(const Screening& screening)
    {
        screenings.push_back(screening);
        sort(screenings.begin(), screenings.end());
    }
    
    void addUser(User* user)
    {
        users.push_back(user);
    }
    
    void deleteUser(int index)
    {
        users.erase(users.begin()+index);
    }

	int findRoom(int id)
    {
        for(unsigned int i= 0; i<rooms.size(); i++)
        {
            if(rooms[i].getId() == id)
                return i;
        };
        return -1;
    }

    int findScreening(int id)
    {
        for(unsigned int i=0; i<screenings.size(); i++)
        {
            if(screenings[i].getId() == id)
                return i;
        };
        return -1;
    }
    
    int findUser(int id)
    {
        for(unsigned int i= 0; i<users.size(); i++)
        {
            if(users[i]->getId() == id)
                return i;
        };
        return -1;
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
      
    User& getUser(int id)
    {
        int userIndex=findUser(id);
        return *users[userIndex];
    }
    
    ErrorLog& getErrorLog();
};

#endif // MovieTicketBookingSystem_H