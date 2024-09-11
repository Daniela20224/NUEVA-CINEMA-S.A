#pragma once

#include "Movie.h"
#include "Room.h"
#include "Schedule.h"
#include <vector>

class Maintenance {
private:
    std::vector<Movie> movies;
    std::vector<Room> rooms;
    std::vector<Schedule> schedules;

public:
   
    void showMenu();
    void addMovie();
    void showMovies();
    void manageMovies();
    void addRooms();
    void showRoom();
    void manageRooms();
    void addSchedules();
    void showSchedule();
    void manageSchedules();
  
   

};

