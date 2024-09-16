#include <iostream>
#include "Menu.h"


int main() {


    std::cout << "Sea bienvenido a la pagina de ventas de NUEVA CINEMA S.A\n\n MENU PRINCIPAL\n";

    Menu menu;

    std::vector<Movie> movies = {
    Movie("Frozen", 2023, 120, "Estados Unidos", "6/10"),
    Movie("Inside Out", 2024, 135, "Canada", "8/10"),
    Movie("Venom", 2018, 143, "Inglaterra", "9/10"),
    Movie("Black Panter", 2020, 200, "Estados Unidos", "10/10")

    };
    for (const auto& movie : movies) {
        menu.maintenance.addMovieToList(movie);
    }

    std::vector<Room> rooms = {
   Room('A', 64, 3000),
   Room('A', 64, 5000),
   Room('B',64,3500),
   Room('B',64,5000)

    };
    for (const auto& room : rooms) {
        menu.maintenance.addRoomToList(room);
    }

    std::vector<Schedule> schedules = {
      Schedule(01, 04, 2024,12,14),
      Schedule(01, 04, 2024,14,16),
      Schedule(02,04,2024,12,14),
      Schedule(02,04,2024,14,17)

    };
    for (const auto& schedule : schedules) {
        menu.maintenance.addScheduleToList(schedule);
    }

    //enlazar la primera pelicula con la primera sala(consecutivamente)
    menu.maintenance.conectMovieRoom(menu.maintenance.movies[0], menu.maintenance.rooms[0]);
    menu.maintenance.conectMovieRoom(menu.maintenance.movies[1], menu.maintenance.rooms[1]);
    menu.maintenance.conectMovieRoom(menu.maintenance.movies[2], menu.maintenance.rooms[2]);
    menu.maintenance.conectMovieRoom(menu.maintenance.movies[3], menu.maintenance.rooms[3]);

    //enlazar la primera sala con el primer horario(consecutivamente)
    menu.maintenance.conectRoomSchedule(menu.maintenance.rooms[0], menu.maintenance.schedules[0]);
    menu.maintenance.conectRoomSchedule(menu.maintenance.rooms[1], menu.maintenance.schedules[1]);
    menu.maintenance.conectRoomSchedule(menu.maintenance.rooms[2], menu.maintenance.schedules[2]);
    menu.maintenance.conectRoomSchedule(menu.maintenance.rooms[3], menu.maintenance.schedules[3]);

        menu.showMainMenu();
        return 0;
    }


