#pragma once
#include "Station.h"

class User
{
	char* name;
	int age;

	void printStations() const;
	void printSchedule(Station* station) const;
	void printScheduleDestination(Station* station, const char* destination) const;
	void printScheduleTime(Station* station, struct tm dateTime) const;
	void printTrain(int trainId) const;
	void printWagon(int trainId, int wagonId) const;
	void buyTicket(int trainId, int wagonId, int seat, const char* fileName); // and extra params which depends of the type of wagon
	void buyTicketDiscount(int trainId, int wagonId, int seat, const char* fileName, const char* cardFile); // and extra params which depends of the type of wagon)


	// G6
};

