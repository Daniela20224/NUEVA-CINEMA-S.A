#include "Maintenance.h"
#include <iostream>
#include <string>
#include <vector>  


void Maintenance::showMenu() {
    int option;
    std::cout << "1. Películas\n2. Salas\n3. Horarios\n";
    std::cout << "Seleccione una opción: ";
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
        std::cout << "Opción inválida\n";
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

    std::cout << "Ingrese el año de la película: ";
    std::cin >> year;
    std::cin.ignore();  

    std::cout << "Ingrese la duración de la pelicula (en minutos): ";
    std::cin >> duration;
    std::cin.ignore();

    std::cout << "Ingrese el país de origen de la película: ";
    std::getline(std::cin, country);

    std::cout << "Ingrese la reseña de la película: ";
    std::getline(std::cin, review);

    Movie myMovie(name, year, duration, country, review);
    movies.push_back(myMovie);


    std::cout << "La película " << name << "ha sido agregada exitosamente "<<std::endl;
    
}

void Maintenance::showMovies(){
    std::cout << "\n--- Catálogo de Películas ---\n";
    for (const auto& movie : movies) {
        movie.showInformationOfMovies();
        std::cout << "----------------------------\n";
    }
}

void Maintenance::manageMovies() {
    int option;
    std::cout << "1. Agregar Peliculas\n2. Mostrar Peliculas\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addMovie();
        break;
    case 2:
        showMovies();
        break;
    default:
        std::cout << "Opción inválida\n";
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
    std::cout << "La sala" << number <<" ha sido añadida exitosamente"<< std::endl;

}

void Maintenance::showRoom() {
    std::cout << "\n--- Salas añadidas ---\n";
    for (const auto& room: rooms) {
        room.showInformationOfRooms(); 
        std::cout << "----------------------------\n";
    }
}

void Maintenance::manageRooms() {
 
    int option;
    std::cout << "1. Añadir Sala\n2. Mostrar Sala\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addRooms();
        break;
    case 2:
        showRoom();
        break;
    default:
        std::cout << "Opción inválida\n";
        break;
    }
}



void Maintenance::addSchedules() {
   
    int day, month, year;
    int startTime;
    int finalTime;

    std::cin.ignore();
 
    std::cout << "Introduce el dia: ";
    std::cin >> day;
    std::cout << "Introduce el mes: ";
    std::cin >> month;
    std::cout << "Introduce el año: ";
    std::cin >> year;

   bool Maintenance::verifyDate(int day, int month, int year) {
        if (get.verifyDate(day, month, year)) {
            std::cout << "La fecha es válida." << std::endl;
        }
        else {
            std::cout << "La fecha no es válida." << std::endl;
        }
        return true; 
    }


    std::cout << "Ingrese la hora de inicio de la película: ";
    std::cin >> startTime;
    std::cin.ignore();

    std::cout << "Ingrese la hora de finalización de la pelicula: ";
    std::cin >> finalTime;
    std::cin.ignore();

    Schedule mySchedule(day,month, year, startTime, finalTime);
    schedules.push_back(mySchedule);


    std::cout << "El horario ha sido añadido existosamente: " << std::endl;
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
    std::cout << "1. Añadir Horario\n2. Mostrar Horario\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addSchedules();
        break;
    case 2:
        showSchedule();
        break;
    default:
        std::cout << "Opción inválida\n";
        break;
    }
    
    }