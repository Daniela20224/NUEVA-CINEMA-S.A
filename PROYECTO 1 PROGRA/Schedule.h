#ifndef SCHEDULE_H
#define SCHEDULE_H

class Schedule {
public:
    Schedule(int day, int month, int year, int startTime, int finalTime);

    void showInformationOfSchedule() const;

    // Métodos de verificación si son relevantes para la instancia
    bool verifyLeapYear(int year);
    bool verifyDate(int day, int month, int year);

    int getDay() const;
    void setDay(int day);

    int getMonth() const;
    void setMonth(int month);

    int getYear() const;
    void setYear(int year);

    int getStartTime() const;
    void setStartTime(int startTime);

    int getFinalTime() const;
    void setFinalTime(int finalTime);

private:
    int day;
    int month;
    int year;
    int startTime;
    int finalTime;

};
#endif 

