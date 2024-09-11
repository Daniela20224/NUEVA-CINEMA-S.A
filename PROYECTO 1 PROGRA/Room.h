#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <array>

class Room {
public:
    Room(int number, int seats, int price);

    void showInformationOfRooms() const;


    void showRoom() const;

    // getters y setters
    int getNumber() const;
    void setNumber(int number);

    int getSeats() const;
    void setSeats(int seats);

    int getPrice() const;
    void setPrice(int price);


private:
    int number;
    int seats;
    int price;
};



#endif