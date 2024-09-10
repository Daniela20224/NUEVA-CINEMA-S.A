#include "Room.h"
#include <iostream>

// Constructor que inicializa el número de la sala, los asientos y el precio
Room::Room(int number, int seats, int price)
    : number(number), seats(seats), price(price) {
    // Inicializar la matriz de 8x8 con 'O' (asiento disponible)
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            seating[i][j] = 'O';  // 'O' representa asiento disponible
        }
    }
}

// Mostrar la información básica de la sala
void Room::showInformationOfRooms() const {
    std::cout << "Numero identificador de la sala: " << number << std::endl;
    std::cout << "Cantidad de butacas de la sala: " << seats << std::endl;
    std::cout << "Precio: " << price << " colones (por ticket)" << std::endl;
}

// Mostrar la matriz de asientos con identificadores de fila y columna
void Room::showRoom() const {
    std::cout << "\n--- Estado de la taquilla (8x8) ---\n";

    // Imprimir las cabeceras de las columnas (números)
    std::cout << "   ";  // Espacio para la cabecera de las filas
    for (int col = 0; col < 8; ++col) {
        std::cout << col << " ";
    }
    std::cout << std::endl;

    // Imprimir cada fila con la letra correspondiente
    for (int i = 0; i < 8; ++i) {
        std::cout << static_cast<char>('A' + i) << "  ";  // Letra de la fila
        for (int j = 0; j < 8; ++j) {
            std::cout << seating[i][j] << " ";  // Mostrar estado del asiento
        }
        std::cout << std::endl;  // Salto de línea después de cada fila
    }
    std::cout << std::endl;
}

// Getters y Setters
int Room::getNumber() const { return number; }
void Room::setNumber(int number) { this->number = number; }

int Room::getSeats() const { return seats; }
void Room::setSeats(int seats) { this->seats = seats; }

int Room::getPrice() const { return price; }
void Room::setPrice(int price) { this->price = price; }