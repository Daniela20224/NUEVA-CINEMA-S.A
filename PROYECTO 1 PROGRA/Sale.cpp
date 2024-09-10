#include "Sale.h"
#include "Sale.h"
#include <iostream>


Sale::Sale() {}

void Sale::showMenu() {
    int option;
    std::cout << "1. Comprar Película\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> option;

    if (option == 1) {
        makeSale();
    }
    else {
        std::cout << "Opción inválida\n";
    }
}

void Sale::makeSale() 
{
   
}