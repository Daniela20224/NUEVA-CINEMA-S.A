#include "Schedule.h"
#include <iostream>

Schedule::Schedule(int day, int month, int year, int startTime, int finalTime)
    : day(day), month(month), year(year), startTime(startTime), finalTime(finalTime) {}

int Schedule::getDay() const { return day; }
void Schedule::setDay(int day) { this->day = day; }

int Schedule::getMonth() const { return month; }
void Schedule::setMonth(int month) { this->month = month; }

int Schedule::getYear() const { return year; }
void Schedule::setYear(int year) { this->year = year; }

int Schedule::getStartTime() const { return startTime; }
void Schedule::setStartTime(int startTime) { this->startTime = startTime; }

int Schedule::getFinalTime() const { return finalTime; }
void Schedule::setFinalTime(int finalTime) { this->finalTime = finalTime; }

void Schedule::showInformationOfSchedule() const {
    std::cout << "Fecha: " << day << "/" << month << "/" << year << std::endl;
    std::cout << "Hora de inicio de la película: " << startTime << std::endl;
    std::cout << "Hora de finalización de la película: " << finalTime << std::endl;
}

// Verificador de año bisiesto para comprobar la fecha
bool Schedule::verifyLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

// Verificador de fecha
bool Schedule::verifyDate(int day, int month, int year) {
    if (year < 2000 || year > 2025) return false;
    if (month < 1 || month > 12) return false;

    int daysOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (verifyLeapYear(year) && month == 2) {
        daysOfMonth[1] = 29;
    }

    if (day < 1 || day > daysOfMonth[month - 1])
        return false;
    return true;
}
