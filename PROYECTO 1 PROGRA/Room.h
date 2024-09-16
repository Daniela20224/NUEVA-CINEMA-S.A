#ifndef ROOM_H
#define ROOM_H
#include "Schedule.h"
#include <vector>
#include <array>

class Room {
public:
    Room(char number, int seats, int price);

     // getters y setters
    char getNumber() const;
    void setNumber(char number);

    int getSeats() const;
    void setSeats(int seats);

    int getPrice() const;
    void setPrice(int price);

    void showInformationOfRooms() const;

    std::vector<Schedule> schedules;

    std::array<std::array<char, 8>, 8> seating;
    bool setSpace(int x, int y);

    void showRoom() const;

private:
    int number;
    int seats;
    int price;
};



#endif