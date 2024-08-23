#ifndef SCHEDULE_H
#define SCHEDULE_H

class Schedule {
public:
	Schedule(int date, int startTime, int finalTime);

	void showInformationOfSchedule()const;

	int getDate()const;
	void setDate(int date);

	int setStartTime()const;
	void getStartTime(int startTime);

	int setFinalTime()const;
	void getFinalTime(int finalTime);

private:
	int date;
	int startTime;
	int finalTime;

};
#endif