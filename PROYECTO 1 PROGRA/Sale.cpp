#include "Sale.h"
#include "Sale.h"
#include <iostream>


Sale::Sale() {}


void Sale::showMenu(Reservation& r) {
    this->reservation = r;
    int option;
    std::cout << "1. Comprar Pelicula\n"<<"2. Mostrar ventas\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> option;

    if (option == 1) {
        makeSale();
    }
    else if (option == 2) {
        showSales();
    }
    else {
        std::cout << "Opcion invalida\n";
    }
}

void Sale::makeSale() 
{
    std::string code;
    std::cout << "ingrese el codigo de 5 caracteres: ";
    std::cin >> code;

    if (code.size() != 5) {
        std::cout << "solo se aceptan codigos de 5 caracteres";
        return;
    }
    for (const auto& c:this->reservation.reservations )
    {
        if (c == code) {
            int id, card;
            std::cout << "ingrese su numero de cedula(6 digitos): ";
            std::cin >> id;

            std::cout << "ingrese su numero de tarjeta(5 digitos): ";
            std::cin >> card;
            mySale m = mySale(id,code,card);
            sales.push_back(m);

            std::cout << "la venta ha sido realizada con exito ";

            //para que no se repita el codigo de venta
            auto it = std::find(this->reservation.reservations.begin(), this->reservation.reservations.end(), code);

            if (it != this->reservation.reservations.end()) {
                this->reservation.reservations.erase(it);


            }
            std::cout << "ticket de venta";
        }
    }

   }

void Sale::showSales() {
    for (const auto& sale : sales) {
        std::cout<<"--------------------------------------" << std::endl;
        std::cout << "| Numero de cedula    | " << sale.id << std::endl;
        std::cout << "| Codigo de venta     |" << sale.code << std::endl;
        std::cout << "| Numero de tarjeta   | " << sale.card << std::endl;
    }
}
