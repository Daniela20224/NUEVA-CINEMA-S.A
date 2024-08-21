#include "Maintenance.h"
#include <iostream>

void Maintenance::showMenu() {
    int option;
    std::cout << "1. Películas\n2. Salas\n3. Horarios\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> option;

    switch (option) {
    case 1:
        manageMovies();
        break;
    case 2:
        manageRooms();
        break;
    case 3:
        manageSchedules();
        break;
    default:
        std::cout << "Opción inválida\n";
    }
}

void Maintenance::manageMovies() {
    std::cout << "";
 }

void Maintenance::manageRooms() {
  }

void Maintenance::manageSchedules() {
}