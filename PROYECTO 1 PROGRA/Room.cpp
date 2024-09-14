#include "Room.h"
#include <iostream>

// Getters y Setters
int Room::getNumber() const { return number; }
void Room::setNumber(int number) { this->number = number; }

int Room::getSeats() const { return seats; }
void Room::setSeats(int seats) { this->seats = seats; }

int Room::getPrice() const { return price; }
void Room::setPrice(int price) { this->price = price; }


Room::Room(int number, int seats, int price)
    : number(number), seats(seats), price(price) {
    char seating[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            seating[i][j] = 'O';  
        }
    }
}


void Room::showInformationOfRooms() const {
    std::cout << "Numero identificador de la sala: " << number << std::endl;
    std::cout << "Cantidad de butacas de la sala: " << seats << std::endl;
    std::cout << "Precio: " << price << " colones (por ticket)" << std::endl;
}


void Room::showRoom() const {
    std::cout << "\n--- Estado de la taquilla (8x8) ---\n";

    char seating[8][8];
    std::cout << "   ";
    for (int col = 0; col < 8; ++col) {
        std::cout << col << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i < 8; ++i) {
        std::cout << static_cast<char>('A' + i) << "  ";
        for (int j = 0; j < 8; ++j) {
            std::cout << seating[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};