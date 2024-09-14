#include "Menu.h"
#include <iostream>

void Menu::showMainMenu() {
    int option;
    do {

        std::cout << "1. Archivo\n2. Mantenimiento\n3. Reserva\n4. Venta\n5. Salir\n";
        std::cout << "Seleccione una opci�n: ";
        std::cin >> option;

        switch (option) {
        case 1:
            showArchiveMenu();
            break;
        case 2:
            showMaintenanceMenu();
            break;
        case 3:
            showReservationMenu();
            break;
        case 4:
            showSaleMenu(this->maintenance);
            break;
        case 5:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opci�n inv�lida\n";
        }
    } while (option != 5);
}

void Menu::showArchiveMenu() {
    Archive archive;
    archive.showMenu();
}

void Menu::showMaintenanceMenu() {
    maintenance.showMenu();
}

void Menu::showReservationMenu() {
    Reservation reservation;
    reservation.showMenu();
}

void Menu::showSaleMenu(const Maintenance& maintenance) {
    Sale sale;
    sale.showMenu();
}
