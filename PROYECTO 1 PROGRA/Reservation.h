#pragma once
#ifndef RESERVATION_H
#define RESERVATION_H
#include "Maintenance.h"
#include <vector>

class Reservation {
public:
    void showMenu();
    void makeReservation();

private:
    Maintenance maintenance;
};

#endif 
