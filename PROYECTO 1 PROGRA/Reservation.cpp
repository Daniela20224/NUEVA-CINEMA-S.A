#include "Reservation.h"
#include "Reservation.h"
#include <iostream>

void Reservation::showMenu() {
    int option;
    std::cout << "1. Reservar Pel�cula\n";
    std::cout << "Seleccione una opci�n: ";
    std::cin >> option;

    if (option == 1) {
        makeReservation();
    }
    else {
        std::cout << "Opci�n inv�lida\n";
    }
}

void Reservation::makeReservation() {
    
}