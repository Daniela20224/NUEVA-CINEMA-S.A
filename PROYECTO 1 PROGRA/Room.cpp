#include "Room.h"
#include <iostream>

// Getters y Setters
char Room::getNumber() const { return number; }
void Room::setNumber(char number) { this->number = number; }

int Room::getSeats() const { return seats; }
void Room::setSeats(int seats) { this->seats = seats; }

int Room::getPrice() const { return price; }
void Room::setPrice(int price) { this->price = price; }


Room::Room(char number, int seats, int price)
    : number(number), seats(seats), price(price) {

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            this->seating[i][j] = 'O';
        }
    }
}


void Room::showInformationOfRooms() const {
    std::cout << "Numero identificador de la sala: " << number << std::endl;
    std::cout << "Cantidad de butacas de la sala: " << seats << std::endl;
    std::cout << "Precio: " << price << " colones (por ticket)" << std::endl;
}


void Room::showRoom() const {
    std::cout << "\n--- Estado de la sala ---\n";


    std::cout << "Reservado: X" << std::endl;
    std::cout << "Dispobible: O" << std::endl << std::endl;

    std::cout << "   ";
    for (int col = 0; col < 8; ++col) {
        std::cout << col << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i < 8; ++i) {
        std::cout << static_cast<char>('A' + i) << "  ";
        for (int j = 0; j < 8; ++j) {
            std::cout << this->seating[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

bool Room::setSpace(int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {

        if (this->seating[x][y] == 'X') {
            return false;
        }
        else {
            this->seating[x][y] = 'X';
            std::cout << "Butaca en (" << x << "," << y << ") marcada como 'X'\n";
            return true;
        }

    }
    else {
        std::cout << "Indice fuera de rango: (" << x << "," << y << ")\n";
        return false;
    }
}