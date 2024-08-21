#pragma once
#ifndef MENU_H
#define MENU_H

#include "Archive.h"
#include "Maintenance.h"
#include "Reservation.h"
#include "Sale.h"

class Menu {
private:
    Maintenance maintenance;  
public:
    void showMainMenu();
    void showArchiveMenu();
    void showMaintenanceMenu();
    void showReservationMenu();
    void showSaleMenu();
};

#endif 