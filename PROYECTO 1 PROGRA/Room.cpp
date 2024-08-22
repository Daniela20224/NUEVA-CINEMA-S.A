#include "Room.h"
#include <iostream>

Room::Room(int number, int seats, int price)
    :number(number), seats(seats), price(price) {}

void Room::showInformationOfRooms() const {
    std::cout << "Numero identificador de la sala: " << number << std::endl;
    std::cout << "Cantidad de butacas de la sala: " << seats << std::endl;
    std::cout << "Precio: " << price << " colones (por ticket)" << std::endl;

}
int Room::getNumber() const { return number; }
void Room::setNumber(int number) { this->number = number; }

int Room::getSeats() const { return seats; }
void Room::setSeats(int seats) { this->seats = seats; }

int Room::getPrice() const { return price; }
void Room::setPrice(int price) { this->price = price; }