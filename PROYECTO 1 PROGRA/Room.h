#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <array>

class Room {
public:
    Room(int number, int seats, int price);

     // getters y setters
    int getNumber() const;
    void setNumber(int number);

    int getSeats() const;
    void setSeats(int seats);

    int getPrice() const;
    void setPrice(int price);

    void showInformationOfRooms() const;

    std::vector<Schedule> schedules;

    std::array<std::array<char, 8>, 8> seating;

    void showRoom() const;

private:
    int number;
    int seats;
    int price;
};



#endif