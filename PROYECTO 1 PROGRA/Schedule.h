#ifndef SCHEDULE_H
#define SCHEDULE_H

class Schedule {
public:
    Schedule(int date, int startTime, int finalTime);

    void showInformationOfSchedule() const;

    int getDate() const;
    void setDate(int date);

    int getStartTime() const;
    void setStartTime(int startTime);

    int getFinalTime() const;
    void setFinalTime(int finalTime);

private:
    int date;
    int startTime;
    int finalTime;

};
#endif