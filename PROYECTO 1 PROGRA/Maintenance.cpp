#include "Maintenance.h"
#include <iostream>
#include <string>
#include <vector>  

void Maintenance::showMenu() {
    int option;
    std::cout << "1. Peliculas\n2. Salas\n3. Horarios\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> option;

    switch (option) {
    case 1:
        manageMovies();
        break;
    case 2:
        manageRooms();
        break;
    case 3:
        manageSchedules();
        break;
    default:
        std::cout << "Opcion invalida\n";
        break;
    }
}

void Maintenance::addMovie() {
    std::string name;
    int year;
    int duration;
    std::string country;
    std::string review;

    std::cin.ignore();

    std::cout << "Ingrese el nombre de la pelicula: ";
    std::getline(std::cin, name);

    std::cout << "Ingrese el anio de la pelicula: ";
    std::cin >> year;
    std::cin.ignore();

    std::cout << "Ingrese la duracion de la pelicula (en minutos): ";
    std::cin >> duration;
    std::cin.ignore();

    std::cout << "Ingrese el pais de origen de la pelicula: ";
    std::getline(std::cin, country);

    std::cout << "Adjunte la critica de la pelicula: ";
    std::getline(std::cin, review);

    Movie myMovie(name, year, duration, country, review);
    movies.push_back(myMovie);

    std::cout << "La pelicula " << name << " ha sido agregada exitosamente " << std::endl;
}

void Maintenance::showMovies() {
    std::cout << "\n--- Catalogo de Peliculas ---\n";
    for (const auto& movie : movies) {
        movie.showInformationOfMovies();
        std::cout << "----------------------------\n";
    }
}

void Maintenance::manageMovies() {
    int option;
    std::cout << "1. Agregar Peliculas\n2. Mostrar Peliculas\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addMovie();
        break;
    case 2:
        showMovies();
        break;
    default:
        std::cout << "Opcion invalida\n";
        break;
    }
}

void Maintenance::addRooms() {
    int number;
    int seats;
    int price;

    std::cin.ignore();

    std::cout << "Numero identificador de la sala: ";
    std::cin >> number;
    std::cin.ignore();

    std::cout << "Ingrese la cantidad de butacas de la sala: ";
    std::cin >> seats;
    std::cin.ignore();

    std::cout << "Ingrese el valor de cada entrada (colones): ";
    std::cin >> price;
    std::cin.ignore();

    Room myRoom(number, seats, price);
    rooms.push_back(myRoom);
    std::cout << "La sala " << number << " ha sido incluida exitosamente" << std::endl;
}

void Maintenance::showRoom() {
    std::cout << "\n--- Salas disponibles ---\n";
    for (const auto& room : rooms) {
        room.showInformationOfRooms();
        std::cout << "----------------------------\n";
    }
}

void Maintenance::manageRooms() {
    int option;
    std::cout << "1. Incluir Sala\n2. Mostrar Sala\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addRooms();
        break;
    case 2:
        showRoom();
        break;
    default:
        std::cout << "Opcion invalida\n";
        break;
    }
}



void Maintenance::addSchedules() {
    int startTime;
    int finalTime;
    int day, month, year;

    std::cin.ignore();

    std::cout << "Introduce el dia: ";
    std::cin >> day;
    std::cout << "Introduce el mes: ";
    std::cin >> month;
    std::cout << "Introduce el anio (2000-2025): ";
    std::cin >> year;

    Schedule tempSchedule(day, month, year, 0, 0);

    if (tempSchedule.verifyDate(day, month, year)) {
        std::cout << "La fecha es valida." << std::endl;
    }
    else {
        std::cout << "La fecha no es valida, no se incluira en los horarios." << std::endl;
        return;
    }

    std::cout << "Ingrese la hora de inicio de la pelicula (formato 24 horas): ";
    std::cin >> startTime;
    std::cin.ignore();

    std::cout << "Ingrese la hora de finalizacion de la pelicula (formato 24 horas): ";
    std::cin >> finalTime;
    std::cin.ignore();

    Schedule mySchedule(day, month, year, startTime, finalTime);
    schedules.push_back(mySchedule);

    std::cout << "El horario ha sido incorporado exitosamente a la lista." << std::endl;
}

void Maintenance::showSchedule() {
    std::cout << "\n--- Horarios ---\n";
    for (const auto& schedule : schedules) {
        schedule.showInformationOfSchedule();
        std::cout << "----------------------------\n";
    }
}

void Maintenance::manageSchedules() {
    int option;
    std::cout << "1. Insertar Horario\n2. Mostrar Horario\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addSchedules();
        break;
    case 2:
        showSchedule();
        break;
    default:
        std::cout << "Opcion invalida\n";
        break;
    }
}

void Maintenance::conectMovieRoom() {
    int index = 1;
    int idMovie;
    int idRoom;

    for (const auto& movie : movies) {
        std::cout << "ID: " << index;
        movie.showInformationOfMovies();
        index++;
    }
    std::cout << "Ingrese el ID de la pelicula: ";
    std::cin >> idMovie;

    //reiniciar index en 1
    index = 1;
    for (const auto& room : rooms) {
        std::cout << "ID: " << index;
        room.showInformationOfRooms();
        index++;
    }
    std::cout << "Ingrese el ID de la sala: ";
    std::cin >> idRoom;

    //conectar la sala a las peliculas
    this->movies[idMovie - 1].rooms.push_back(this->rooms[idRoom - 1]);
}

void Maintenance::conectRoomSchedule() {
    int index = 1;
    int idSchedule;
    int idRoom;

    for (const auto& room : rooms) {
        std::cout << "ID: " << index;
        room.showInformationOfRooms();
        index++;
    }
    std::cout << "Ingrese el ID de la sala: ";
    std::cin >> idRoom;

    index = 1;
    for (const auto& schedule : schedules) {
        std::cout << "ID: " << index;
        schedule.showInformationOfSchedule();
        index++;
    }
    std::cout << "Ingrese el ID de los horarios: ";
    std::cin >> idSchedule;




    //conectar horarios con salas
    this->rooms[idRoom - 1].schedules.push_back (this->schedules[idSchedule - 1]);
}

void Maintenance::addMovieToList(Movie m) {
    this->movies.push_back(m);
}
void Maintenance::addRoomToList(Room r) {
    this->rooms.push_back(r);
}
void Maintenance::addScheduleToList(Schedule s) {
    this->schedules.push_back(s);
}



void Maintenance::conectMovieRoom(Movie &m, Room &r) {
    m.rooms.push_back(r);
}
void Maintenance::conectRoomSchedule(Room &r, Schedule &s) {
    r.schedules.push_back(s);
}