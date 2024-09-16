#ifndef RESERVATION_H
#define RESERVATION_H
#include "Maintenance.h"
#include <vector>

class Reservation {
public:
    void showMenu(Maintenance& maintenance);  
    void makeReservation();
    std::string generateCode(int l);

    //codigos de las reservas
    std::vector<std::string> reservations;

     
    private:
    Maintenance* maintenance;  
};

#endif