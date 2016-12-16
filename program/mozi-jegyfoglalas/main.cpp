#include "MovieTicketBookingSystem.h"
#include "demodb.h"

int main()
{   
    ErrorLog history;
    MovieTicketBookingSystem system(history);
    initDemoDB(system);
    system.printWelcomeScreen();
    
    return 0;
}

