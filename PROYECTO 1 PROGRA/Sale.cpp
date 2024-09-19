#include "Sale.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

Sale::Sale() {}

void Sale::showMenu(Reservation& r) {
    this->reservation = r;
    int option;
    std::cout << "1. Comprar Pelicula\n" << "2. Mostrar ventas\n";
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

bool isValidCedula(const std::string& id) {
    return id.length() == 6 && std::all_of(id.begin(), id.end(), ::isdigit);
}

bool isValidCard(const std::string& card) {
    return card.length() == 5 && std::all_of(card.begin(), card.end(), ::isdigit);
}

void Sale::makeSale() {
    std::string code;
    std::cout << "Ingrese el codigo de 5 caracteres: ";
    std::cin >> code;

    if (code.size() != 5) {
        std::cout << "Solo se aceptan codigos de 5 caracteres\n";
        return;
    }

    for (const auto& c : this->reservation.reservations) {
        if (c == code) {
            std::string id, card;

            std::cout << "Ingrese su numero de cedula (6 digitos): ";
            std::cin >> id;
            if (!isValidCedula(id)) {
                std::cout << "Numero de cedula invalido. Debe tener 6 digitos.\n";
                return;
            }

            std::cout << "Ingrese su numero de tarjeta (5 digitos): ";
            std::cin >> card;
            if (!isValidCard(card)) {
                std::cout << "Numero de tarjeta invalido. Debe tener 5 digitos.\n";
                return;
            }

            mySale m = mySale(std::stoi(id), code, std::stoi(card));
            sales.push_back(m);

            std::cout << "La venta ha sido realizada con exito.\n";
            std::cout << "               Ticket de compra   \n";
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "| Numero de cedula    | " << m.id << std::endl;
            std::cout << "| Codigo de venta     | " << m.code << std::endl;
            std::cout << "| Numero de tarjeta   | " << m.card << std::endl;
            std::cout << "-----------------------------------------" << std::endl;

            // Para que no se repita el codigo de venta
            auto it = std::find(this->reservation.reservations.begin(), this->reservation.reservations.end(), code);
            if (it != this->reservation.reservations.end()) {
                this->reservation.reservations.erase(it);
            }
        }
    }
}
       
void Sale::showSales() {
    for (const auto& sale : sales) {
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "| Numero de cedula    | " << sale.id << std::endl;
        std::cout << "| Codigo de venta     | " << sale.code << std::endl;
        std::cout << "| Numero de tarjeta   | " << sale.card << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }
}