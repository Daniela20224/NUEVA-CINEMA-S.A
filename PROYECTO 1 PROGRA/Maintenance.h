#pragma once

#include "Movie.h"
#include "Room.h"
#include "Schedule.h"
#include <vector>

class Maintenance {
private:
    
public:
    std::vector<Movie> movies;
    std::vector<Room> rooms;
    std::vector<Schedule> schedules;
   
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
    void conectMovieRoom();
    void conectRoomSchedule();
    void addMovieToList(Movie m);
    void addRoomToList(Room r);
    void addScheduleToList(Schedule s);

    void conectMovieRoom(Movie &m, Room &r);
    void conectRoomSchedule(Room &r, Schedule &s);
   

};

