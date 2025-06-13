#pragma once
#include "Train.h"

class Station
{
	char* name;
	int availablePlatform;
	Train** trains;
	size_t trainsCount;

	void copyFrom(const Station& other);
	void moveFrom(Station&& other);
	void free();

	void setName(const char* name);
	void setAvailablePlatform(); // TODO

public:
	Station(const char* name);
	Station(const Station& other);
	Station& operator=(const Station& other);

	Station(Station&& other) noexcept;
	Station& operator=(Station&& other) noexcept;

	const char* getName() const;
	const int getAvailablePlatform() const;

	void addTrain(Train& train);

	void printDeparturedTrains(); //TODO
	void printArrivalTrains(); //TODO

	~Station();
};