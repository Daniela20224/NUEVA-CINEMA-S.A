#include "Reservation.h"
#include <iostream>
#include <regex>
#include <sstream>
#include <random>  
#include <ctime> 

void Reservation::showMenu(Maintenance& maintenance) {
    this->maintenance = &maintenance;
    int option;
    std::cout << "1. Reservar Pelicula\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> option;

    if (option == 1) {
        makeReservation();
    }
    else {
        std::cout << "Opcion invalida\n";
    }
}

std::vector<std::string> split(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Reservation::makeReservation() {
    std::cout << "**Lista de peliculas**" << std::endl << std::endl;
    int size = this->maintenance->movies.size();
    int idMovie;

    for (int i = 0; i < size; i++) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "ID de Pelicula: " << i + 1 << std::endl;

        this->maintenance->movies[i].showInformationOfMovies();
    }

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Ingrese el ID de la pelicula que desea reservar: ";
    std::cin >> idMovie;

    if (idMovie < 1 || idMovie > size) {
        std::cout << "ID de película no valido." << std::endl;
        return;
    }

    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "**** Esta pelicula se exhibe en las siguientes salas ****\n\n";
    int idRoom;
    int index = 1;
    for (const auto& room : this->maintenance->movies[idMovie - 1].rooms) {
        std::cout << "ID de la sala: " << index << std::endl;
        room.showInformationOfRooms();
        index++;

    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Ingrese el ID de la sala: ";
    std::cin >> idRoom;

    if (idRoom < 1 || idRoom > this->maintenance->movies[idMovie - 1].rooms.size()) {
        std::cout << "ID de sala no valido." << std::endl;
        return;
    }

    this->maintenance->movies[idMovie - 1].rooms[idRoom - 1].showRoom();

    std::string input;
    std::cout << "            **********  Formas de realizar la reserva de asientos  **********              \n ";
    std::cout << "------------------------------------------------------------------------------------\n";
    std::cout << "|  Para reservar mas de un campo con una rango  | Separados por un guion: B2-B4     |\n";
    std::cout << "|  Para reserar solo un campo                   | Fila y Columna sin separar: B2    | \n";
    std::cout << "|  Para reservar dieferentes asientos           | Separados por comas: B2,B4        |\n";
    std::cout << "|-----------------------------------------------------------------------------------|\n" << std::endl;
    std::cout << "   Ingrese la fila y columna correspondiente el asiento deseado: ";
    std::cin >> input;
    

    std::regex singleSeatRegex(R"(([A-H][0-7]))");
    std::regex rangeSeatRegex(R"(([A-H][0-7])-([A-H][0-7]))");

    // Dividimos la entrada por comas
    std::vector<std::string> tokens = split(input, ',');

    // Variable para contar la cantidad de espacios reservados
    int totalSpaces = 0;

    if (tokens.size() > 5) {
        std::cout << "No se pueden reservar mas de 5 asientos " << std::endl;
        return;
    }

    for (const std::string& token : tokens) {
        // Caso: un solo asiento
        if (std::regex_match(token, singleSeatRegex)) {
            char fila = token[0];
            int columna = token[1] - '0';
            int positionX = fila - 'A';

            if (totalSpaces == 5) {
                std::cout << "Se ha alcanzado el limite de reservacion osea 5 asientos " << std::endl;
                return;
            }

            if (positionX >= 0 && positionX < 8 && columna >= 0 && columna < 8) {
                if (this->maintenance->movies[idMovie - 1].rooms[idRoom - 1].setSpace(positionX, columna)) {
                    std::cout << "Asiento " << fila << columna << " reservado correctamente." << std::endl;
                    totalSpaces++;
                }
                else {
                    std::cout << "No se puede reservar un campo que ya ha sido reservado" << std::endl;
                    return;
                }

            }
            else {
                std::cout << "Posicion no válida: " << token << std::endl;
            }
        }
        // Caso: un rango de asientos
        else if (std::regex_match(token, rangeSeatRegex)) {
            char filaInicio = token[0];
            int columnaInicio = token[1] - '0';
            char filaFin = token[3];
            int columnaFin = token[4] - '0';

            if (filaInicio != filaFin) {
                std::cout << "El rango debe estar en la misma fila: " << token << std::endl;
                continue;
            }

            int positionX = filaInicio - 'A';
            if (positionX >= 0 && positionX < 8 && columnaInicio >= 0 && columnaInicio < 8 && columnaFin >= 0 && columnaFin < 8) {
                if (columnaInicio > columnaFin) {
                    std::swap(columnaInicio, columnaFin);
                }

                int spacesToReserve = columnaFin - columnaInicio + 1;
                totalSpaces += spacesToReserve;

                if (totalSpaces > 5) {
                    std::cout << "No se pueden reservar mas de 5 asientos. Se reservaron solo los campos individuales" << token << std::endl;
                    return;
                }

                for (int i = columnaInicio; i <= columnaFin; ++i) {
                    if (this->maintenance->movies[idMovie - 1].rooms[idRoom - 1].setSpace(positionX, i)) {
                        std::cout << "Asiento " << positionX << i << " reservado correctamente." << std::endl;
                    }
                    else {
                        std::cout << "No se puede reservar un campo que ya ha sido reservado" << std::endl;
                        return;
                    }
                }

                std::cout << "Asientos desde " << filaInicio << columnaInicio << " hasta " << filaFin << columnaFin << " reservados correctamente." << std::endl;
            }
            else {
                std::cout << "Posicion no valida: " << token << std::endl;
            }
        }
        // Entrada inválida
        else {
            std::cout << "Entrada no valida: " << token << std::endl;
        }

        // Verificamos si hemos alcanzado el máximo de 5 espacios
        if (totalSpaces > 5) {
            std::cout << "No se pueden reservar mas de 5 asientos." << std::endl;
            return;
        }
    }

    if (totalSpaces == 0) {
        std::cout << "No se reservo ningun asiento." << std::endl;
    }
    else {
        std::cout << "Total de asientos reservados: " << totalSpaces << std::endl;
        this->reservations.push_back(this->generateCode(5));
    }
}

std::string Reservation::generateCode(int l) {

    const std::string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string code;

    // Inicializar el generador de números aleatorios
    std::mt19937 generador(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<> distribucion(0, caracteres.size() - 1);

    // Generar el código aleatorio
    for (int i = 0; i < l; ++i) {
        code += caracteres[distribucion(generador)];
    }
    std::cout << "--------------------------------\n";
    std::cout << "|codigo de reserva:" << code <<std::endl;
    std::cout << "--------------------------------\n";
    std::cout << "Copiar este codigo si desea realizar su compra.\n";
    return code;
}