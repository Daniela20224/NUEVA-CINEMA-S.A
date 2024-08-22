#pragma once
#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include "Movie.h"
#include "Room.h"
#include <vector>

class Maintenance {
private:
    std::vector<Movie> movies;
    std::vector<Room> rooms;
   // std::vector<Schedule> schedule;
public:
    void showMenu();
    void addMovie();
    void showMovies();
    void manageMovies();
    void addRooms();
    void showRoom();
    void manageRooms();
    void addSchedules();
    void showSchedules();
    void manageSchedules();
};

#endif 