#include "Maintenance.h"
#include <iostream>
#include <string>
#include <vector>  // Aseg�rate de incluir la librer�a para std::vector

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
        break;  // Agregamos break para evitar la ca�da a trav�s de casos
    }
}

void Maintenance::addMovie() {
    std::string name;
    int year;
    int duration;
    std::string country;
    std::string review;

    std::cin.ignore();  // Ignorar el salto de l�nea pendiente

    std::cout << "Ingrese el nombre de la pel�cula: ";
    std::getline(std::cin, name);

    std::cout << "Ingrese el a�o de la pel�cula: ";
    std::cin >> year;
    std::cin.ignore();  // Ignorar el salto de l�nea pendiente

    std::cout << "Ingrese la duraci�n de la pel�cula (en minutos): ";
    std::cin >> duration;
    std::cin.ignore();  // Ignorar el salto de l�nea pendiente

    std::cout << "Ingrese el pa�s de origen de la pel�cula: ";
    std::getline(std::cin, country);

    std::cout << "Ingrese la rese�a de la pel�cula: ";
    std::getline(std::cin, review);

    Movie myMovie(name, year, duration, country, review);
    movies.push_back(myMovie);

    // Mensaje de depuraci�n
    std::cout << "Pel�cula a�adida: " << name << std::endl;
    
}

void Maintenance::showMovies() const {
    std::cout << "\n--- Cat�logo de Pel�culas ---\n";
    for (const auto& movie : movies) {
        movie.showInformation();
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
        break;  // Agregamos break para evitar la ca�da a trav�s de casos
    }
}

void Maintenance::manageRooms() {
    // Implementar la gesti�n de salas aqu�
}

void Maintenance::manageSchedules() {
    // Implementar la gesti�n de horarios aqu�
}