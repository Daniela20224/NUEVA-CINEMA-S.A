#include "Reservation.h"
#include "Reservation.h"
#include <iostream>

void Reservation::showMenu() {
    int option;
    std::cout << "1. Reservar Película\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> option;

    if (option == 1) {
        makeReservation();
    }
    else {
        std::cout << "Opción inválida\n";
    }
}

void Reservation::makeReservation() {
    
}