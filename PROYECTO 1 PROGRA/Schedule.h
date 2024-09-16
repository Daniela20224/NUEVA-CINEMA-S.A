#ifndef SCHEDULE_H
#define SCHEDULE_H

class Schedule {
public:
    Schedule(int day, int month, int year, int startTime, int finalTime);


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


    void showInformationOfSchedule() const;

    bool verifyLeapYear(int year);
    bool verifyDate(int day, int month, int year);


private:

    int day;
    int month;
    int year;

    int startTime;
    int finalTime;

};
#endif 

