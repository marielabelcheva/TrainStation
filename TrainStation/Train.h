#pragma once
#include "Wagon.h"
#include <ctime>
#include "Station.h"

class Train
{
public:
	Station* departureStation;
	Station* arrivalStation;

private:
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

	size_t findWagon(int wagonId);

	void addWagon(Wagon& wagon);
	void removeWagon(int wagonID);

	const int getDeparturePlatform() const;
	const int getArrivalPlatform() const;
	Wagon** getWagons() const;

	const int getTrainId() const;

	const char* printDepartureTime() const;
	const char* printArrivalTime() const;

	bool isTrainDepartured() const;

	void printWagons();
	void printTrainInfo();

	~Train();
};