#pragma once
#include "Station.h"
#include "DiscountCard.h"

class User
{
	char* name;
	int age;

protected:
	Train** trains;
	Station** stations;
	Wagon** wagons;
	DiscountCard** discountCards;

private:
	void setName(const char* name);
	void setAge(int age);

	void copyFrom(const User& other);
	void moveFrom(User&& other);
	void free();
	
public:

	User(const char* name, Train** trains, Station** stations, Wagon** wagons, DiscountCard** cards);
	User(const char* name, int age, Train** trains, Station** stations, Wagon** wagons, DiscountCard** cards);
	User(const User& other);
	User& operator=(const User& other);

	User(User&& other) noexcept;
	User& operator=(User&& other) noexcept;

	void printStations() const;
	void printSchedule(const char* station) const;
	void printScheduleDestination(const char*, const char* destination) const;
	void printScheduleTime(Station* station, struct tm dateTime) const;
	void printTrain(int trainId) const;
	void printWagon(int trainId, int wagonId) const;
	void buyTicket(int trainId, int wagonId, int seat, const char* fileName); // and extra params which depends of the type of wagon
	void buyTicketDiscount(int trainId, int wagonId, int seat, const char* fileName, const char* cardFile); // and extra params which depends of the type of wagon)

	~User();
};

