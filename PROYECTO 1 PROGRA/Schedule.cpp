#include "Schedule.h"
#include <iostream>

Schedule::Schedule(int date, int startTime, int finalTime)
	:date(date), startTime(startTime), finalTime(finalTime) {}


void Schedule::showInformationOfSchedule()const {
	std::cout << "fecha: " << date << std::endl;
	std::cout << "Hora de inicio de la pelicula: " << startTime << std::endl;
	std::cout << "Hora de finalización de la pelicula: " << finalTime << std::endl;
}
int Schedule::getDate()const { return date; }
void Schedule::setDate(int date) { this->date = date; }

int Schedule::getStartTime() const{ return startTime; }
void Schedule::setStartTime(int startTime) { this->startTime = startTime; }

int Schedule::getFinalTime() const { return finalTime; }
void Schedule::setFinalTime(int finalTime) { this->finalTime = finalTime; }



