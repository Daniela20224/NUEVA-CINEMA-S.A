#pragma once
#ifndef RESERVATION_H
#define RESERVATION_H
#include "Maintenance.h"
#include <vector>

class Reservation {
public:
    void showMenu(const Maintenance& maintenance);
    void makeReservation();

private:
    Maintenance maintenance;
};

#endif 
