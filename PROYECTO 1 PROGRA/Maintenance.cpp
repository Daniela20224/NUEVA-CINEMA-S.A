#include "Maintenance.h"
#include <iostream>
#include <string>
#include <vector>  


void Maintenance::showMenu() {
    int option;
    std::cout << "1. Pel�culas\n2. Salas\n3. Horarios\n";
    std::cout << "Seleccione una opci�n: ";
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
        std::cout << "Opci�n inv�lida\n";
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

    std::cout << "Ingrese el nombre de la pel�cula: ";
    std::getline(std::cin, name);

    std::cout << "Ingrese el a�o de la pel�cula: ";
    std::cin >> year;
    std::cin.ignore();  

    std::cout << "Ingrese la duraci�n de la pel�cula (en minutos): ";
    std::cin >> duration;
    std::cin.ignore();

    std::cout << "Ingrese el pa�s de origen de la pel�cula: ";
    std::getline(std::cin, country);

    std::cout << "Ingrese la rese�a de la pel�cula: ";
    std::getline(std::cin, review);

    Movie myMovie(name, year, duration, country, review);
    movies.push_back(myMovie);


    std::cout << "La pel�cula " << name << "ha sido agregada exitosamente "<<std::endl;
    
}

void Maintenance::showMovies(){
    std::cout << "\n--- Cat�logo de Pel�culas ---\n";
    for (const auto& movie : movies) {
        movie.showInformationOfMovies();
        std::cout << "----------------------------\n";
    }
}

void Maintenance::manageMovies() {
    int option;
    std::cout << "1. A�adir Pel�culas\n2. Mostrar Pel�culas\n";
    std::cout << "Seleccione una opci�n: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addMovie();
        break;
    case 2:
        showMovies();
        break;
    default:
        std::cout << "Opci�n inv�lida\n";
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
    std::cout << "La sala" << number <<" ha sido a�adida exitosamente"<< std::endl;

}

void Maintenance::showRoom() {
    std::cout << "\n--- Salas a�adidas ---\n";
    for (const auto& room: rooms) {
        room.showInformationOfRooms(); 
        std::cout << "----------------------------\n";
    }
}

void Maintenance::manageRooms() {
 
    int option;
    std::cout << "1. A�adir Sala\n2. Mostrar Sala\n";
    std::cout << "Seleccione una opci�n: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addRooms();
        break;
    case 2:
        showRoom();
        break;
    default:
        std::cout << "Opci�n inv�lida\n";
        break;
    }
}



void Maintenance::addSchedules() {
    std::string name;
    int date;
    int startTime;
    int finalTime;

    std::cin.ignore();

    std::cout << "Ingrese la fecha de la pel�cula (**/**/****): ";
    std::cin >> date;
    std::cin.ignore();

    std::cout << "Ingrese la hora de inicio de la pel�cula: ";
    std::cin >> startTime;
    std::cin.ignore();

    std::cout << "Ingrese la hora de finalizaci�n de la pelicula: ";
    std::cin >> finalTime;
    std::cin.ignore();

    Schedule mySchedule(date, startTime, finalTime);
    schedule.push_back(mySchedule);


    std::cout << "El horario ha sido a�adido existosamente: " << std::endl;
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
    std::cout << "1. A�adir Horario\n2. Mostrar Horario\n";
    std::cout << "Seleccione una opci�n: ";
    std::cin >> option;

    switch (option) {
    case 1:
        addSchedules();
        break;
    case 2:
        showSchedule();
        break;
    default:
        std::cout << "Opci�n inv�lida\n";
        break;

    
    
    }