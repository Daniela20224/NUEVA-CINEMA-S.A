#include "Archive.h"
#include <iostream>

void Archive::showMenu() {
    int option;
    std::cout << "1. Acerca de\n2. Salir\n";
    std::cout << "Seleccione una opci�n: ";
    std::cin >> option;

    switch (option) {
    case 1:
        showAbout();
        break;
    case 2:
        exit();
        break;
    default:
        std::cout << "Opci�n inv�lida\n";
    }
}

void Archive::showAbout() {
    std::cout << "Sistema desarrollado por Alison.\n";
}

void Archive::exit() {
    std::cout << "Saliendo...\n";
}