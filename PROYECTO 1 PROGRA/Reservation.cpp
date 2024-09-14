#include "Reservation.h"
#include <iostream>

void Reservation::showMenu(const Maintenance& maintenance) {
    this->maintenance = maintenance;   
    int option;
    std::cout << "1. Reservar Pel�cula\n";
    std::cout << "Seleccione una opci�n: ";
    std::cin >> option;

    if (option == 1) {
        makeReservation();
    }
    else {
        std::cout << "Opci�n inv�lida\n";
    }
}

void Reservation::makeReservation() {
    std::cout << "Lista de pel�culas" << std::endl;
    int size = this->maintenance.movies.size(); 
    int idMovie;

    for (int i = 0; i < size; i++) {
        std::cout << "ID de Pelicula: " << i + 1 << std::endl;
        this->maintenance.movies[i].showInformationOfMovies();
    }
    std::cout << "Ingrese el ID de la pelicula: ";
    std::cin >> idMovie;

    if (idMovie < 1 || idMovie > size) {
        std::cout << "ID de pel�cula no v�lido." << std::endl;
        return;
    }

    std::cout << "Esta pelicula se exhibe en las siguientes salas\n";
    int idRoom;
    int index = 1;
    for (const auto& room : this->maintenance.movies[idMovie - 1].rooms) {
        std::cout << "ID: " << index << std::endl;
        room.showInformationOfRooms();
        index++;
    }
    std::cout << "Ingrese el ID de la sala: ";
    std::cin >> idRoom;

    if (idRoom < 1 || idRoom > this->maintenance.movies[idMovie - 1].rooms.size()) {
        std::cout << "ID de sala no v�lido." << std::endl;
        return;
    }

    int idCalendar;
    index = 1;
    for (const auto& schedule : this->maintenance.movies[idMovie - 1].rooms[idRoom - 1].schedules) {
        std::cout << "ID: " << index << std::endl;
        schedule.showInformationOfSchedule();
        index++;
    }
    std::cout << "Ingrese el ID del calendario: ";
    std::cin >> idCalendar;

    if (idCalendar < 1 || idCalendar > this->maintenance.movies[idMovie - 1].rooms[idRoom - 1].schedules.size()) {
        std::cout << "ID de calendario no v�lido." << std::endl;
        return;
    }

    this->maintenance.movies[idMovie - 1].rooms[idRoom - 1].showRoom();

    int positionX, positionY;
    std::cout << "Ingrese la fila: ";
    std::cin >> positionX;

    std::cout << "Ingrese la columna: ";
    std::cin >> positionY;

    // Validar que la posici�n est� dentro de los l�mites (matriz 8x8)
    if (positionX < 0 || positionX >= 8 || positionY < 0 || positionY >= 8) {
        std::cout << "Posici�n no v�lida." << std::endl;
        return;
    }

    // Marcar el asiento como reservado
    this->maintenance.movies[idMovie - 1].rooms[idRoom - 1].seating[positionX][positionY] = 'X';
}