#include "Sale.h"
#include "Sale.h"
#include <iostream>


Sale::Sale() {}

void Sale::showMenu() {
    int option;
    std::cout << "1. Comprar Pel�cula\n";
    std::cout << "Seleccione una opci�n: ";
    std::cin >> option;

    if (option == 1) {
        makeSale();
    }
    else {
        std::cout << "Opci�n inv�lida\n";
    }
}

void Sale::makeSale() 
{
   
}