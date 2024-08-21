#include "Maintenance.h"
#include <iostream>
#include <string>
#include <vector>  // Asegúrate de incluir la librería para std::vector

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
        break;  // Agregamos break para evitar la caída a través de casos
    }
}

void Maintenance::addMovie() {
    std::string name;
    int year;
    int duration;
    std::string country;
    std::string review;

    std::cin.ignore();  // Ignorar el salto de línea pendiente

    std::cout << "Ingrese el nombre de la película: ";
    std::getline(std::cin, name);

    std::cout << "Ingrese el año de la película: ";
    std::cin >> year;
    std::cin.ignore();  // Ignorar el salto de línea pendiente

    std::cout << "Ingrese la duración de la película (en minutos): ";
    std::cin >> duration;
    std::cin.ignore();  // Ignorar el salto de línea pendiente

    std::cout << "Ingrese el país de origen de la película: ";
    std::getline(std::cin, country);

    std::cout << "Ingrese la reseña de la película: ";
    std::getline(std::cin, review);

    Movie myMovie(name, year, duration, country, review);
    movies.push_back(myMovie);

    // Mensaje de depuración
    std::cout << "Película añadida: " << name << std::endl;
    
}

void Maintenance::showMovies() const {
    std::cout << "\n--- Catálogo de Películas ---\n";
    for (const auto& movie : movies) {
        movie.showInformation();
        std::cout << "----------------------------\n";
    }
}

void Maintenance::manageMovies() {
    int option;
    std::cout << "1. Añadir Películas\n2. Mostrar Películas\n";
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
        break;  // Agregamos break para evitar la caída a través de casos
    }
}

void Maintenance::manageRooms() {
    // Implementar la gestión de salas aquí
}

void Maintenance::manageSchedules() {
    // Implementar la gestión de horarios aquí
}