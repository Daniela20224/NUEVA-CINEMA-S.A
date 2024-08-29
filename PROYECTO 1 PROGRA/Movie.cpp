#include "Movie.h"
#include <iostream>

Movie::Movie(const std::string& name, int year, int duration, const std::string& country, const std::string& review)
    : name(name), year(year), duration(duration), country(country), review(review) {}

void Movie::showInformationOfMovies() const {
    std::cout << "Nombre: " << name << std::endl;
    std::cout << "Año: " << year << std::endl;
    std::cout << "Duración: " << duration << " minutos" << std::endl;
    std::cout << "Pais: " << country << std::endl;
    std::cout << "Reseña: " << review << std::endl;
}

std::string Movie::getName() const { return name; }
void Movie::setName(const std::string& name) { this->name = name; }

int Movie::getYear() const { return year; }
void Movie::setYear(int year) { this->year = year; }

int Movie::getDuration() const { return duration; }
void Movie::setDuration(int duration) { this->duration = duration; }

std::string Movie::getCountry() const { return country; }
void Movie::setCountry(const std::string& country) { this->country = country; }

std::string Movie::getReview() const { return review; }
void Movie::setReview(const std::string& review) { this->review = review; }