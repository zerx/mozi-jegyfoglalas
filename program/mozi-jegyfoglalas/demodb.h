#ifndef DEMODB
#define DEMODB

#include "MovieTicketBookingSystem.h"

    EmailAddress adminEmail("admin", "cinemather.com");
    Address adminAddress("Matherland", "Anywhere", "Anywhere City", "A1000", "Sumwher st. 2/9");
    User* admin= new Admin("sysadmin", "123456", adminEmail, "System", "Admin", adminAddress);
    
    EmailAddress lordprotectorEmail("lordprotector", "cinemather.com");
    EmailAddress duceEmail("imduce", "cinemather.com");
    User* lordprotector= new StaffMember("lordprotector", "britainrulez", lordprotectorEmail, "L", "Lawliet", adminAddress);
    User* imduce= new StaffMember("imduce", "notadictator", duceEmail, "Roman", "King", adminAddress);
    
    Room roomA("A", 40);
    Room roomB("B", 100);
    Room roomC("C", 60);
    DateTime time1(2016, 12, 24, 20, 0);
    DateTime time2(2016, 12, 17, 16, 30);
    DateTime time3(2017, 1, 3, 16, 0);
    Screening movie1("Meme Wars", 1400, time1, roomC);
    Screening movie2("Scarface", 600, time2, roomA);
    Screening movie3("Avatar", 1000, time3, roomB);
    
    EmailAddress email1("vercetti", "forellis.com");
    EmailAddress email2("rosenberg", "forellis.com");
    Address address1("United States of America", "State of Liberty", "Libety City", "LC100", "St Mark's st. 4/2");
    Address address2("United States of America", "Florida", "Vice City", "FL800", "Washington st. 12/5");
    User* vercetti= new Customer("vercetti", "rememberthename", email1, "Tommy", "Vercetti", address1);
    User* rosenberg= new Customer("rosenberg", "cokeftw", email2, "Ken", "Rosenberg", address2);
    
    Reservation r1(movie1, 1);
    Reservation r2(movie2, 3);
    Reservation r3(movie3, 2);
    Payment p1(r1, false);
    ErrorEntry e1("Invalid payment: user cancellation <by: " + vercetti->getUsername() +">");
    Payment p2(r1, true);
    Payment p3(r2, false);
    ErrorEntry e2("Invalid payment: user cancellation <by: " + vercetti->getUsername() +">");
    
    ErrorEntry e3("Incorrect login: password mismatch <to: " + vercetti->getUsername() +">");
    
    void initCustomer(User* customer)
    {
        customer->addReservation(r1);
        r2.setIsPaid(true);
        customer->addReservation(r2);
        customer->addReservation(r3);
        customer->addPayment(p1);
        customer->addPayment(p2);
        customer->addPayment(p3);
    }
    
    void initDemoDB(MovieTicketBookingSystem& system)
    {
        movie1.setNumOfReservations(59);
        movie2.setNumOfReservations(38);
        movie3.setNumOfReservations(40);
        initCustomer(vercetti);
        system.addRoom(roomA);
        system.addRoom(roomB);
        system.addRoom(roomC);
        system.addScreening(movie1);
        system.addScreening(movie2);
        system.addScreening(movie3);
        system.addUser(admin);
        system.addUser(lordprotector);
        system.addUser(vercetti);
        system.addUser(imduce);
        system.addUser(rosenberg);
        system.getErrorLog().addError(e1);
        system.getErrorLog().addError(e2);
        system.getErrorLog().addError(e3);
    }

#endif // DEMODB

