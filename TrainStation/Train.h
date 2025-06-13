#pragma once
#include "Wagon.h"
#include <ctime>
#include "Station.h"

class Train
{
	Station* departureStation;
	Station* arrivalStation;
	struct tm departureDateAndTime;
	struct tm arrivalDateAndTime;
	int departurePlatform;
	int arrivalPlatform;
	int distanceBetweenStationsInKM;
	int id;
	int speed;
	Wagon** wagons;
	size_t wagonsCount;

	void copyFrom(const Train& other);
	void moveFrom(Train&& other);
	void free();

	void setStation(Station& station, Station* field);

	void solveTheArrivalTimeInHoursAndMinutes();
	void setTime(struct tm departureTime);

	void setPlatforms();

	void setDistance(int distance);
	void setSpeed(int speed);
	void setID();

public:
	Train(Station& departure, Station& arrival, int distance, int speed, struct tm departureTime);
	Train(const Train& other);
	Train& operator=(const Train& other);

	Train(Train&& other) noexcept;
	Train& operator=(Train&& other) noexcept;

	void addWagon(Wagon& wagon);

	const int getDeparturePlatform() const;
	const int getArrivalPlatform() const;

	const int getTrainId() const;

	const char* printTime(struct tm field) const;

	void printWagons(); // TODO
	void printTrainInfo(); // TODO

	~Train();
};