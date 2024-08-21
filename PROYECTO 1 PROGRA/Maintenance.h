#pragma once
#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include "Movie.h"
#include <vector>

class Maintenance {
private:
    std::vector<Movie> movies;

public:
    void showMenu();
    void addMovie();
    void showMovies() const;
    void manageMovies();
    void manageRooms();
    void manageSchedules();
};

#endif 