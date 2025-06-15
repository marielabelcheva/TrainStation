#include "Train.h"
#include <iostream>
#include "Resources.h"

namespace constants
{
	const int ID_CHARECTERS_COUNT = 4;
	const int MINUTES_IN_AN_HOUR = 60;
	const size_t MAX_DATETIME_SIZE = (size_t)"hh:mm dd.MM.yyyy" + 1;
}

void Train::copyFrom(const Train& other)
{
	this->departureStation = other.departureStation;
	this->arrivalStation = other.arrivalStation;
	this->departureDateAndTime = other.departureDateAndTime;
	this->arrivalDateAndTime = other.arrivalDateAndTime;
	this->departurePlatform = other.departurePlatform;
	this->arrivalPlatform = other.arrivalPlatform;
	this->distanceBetweenStationsInKM = other.distanceBetweenStationsInKM;
	this->id = other.id;
	this->speed = other.speed;
	this->wagons = other.wagons;
	this->wagonsCount = other.wagonsCount;
}

void Train::moveFrom(Train&& other)
{
	this->departureStation = other.departureStation;
	other.departureStation = nullptr;
	this->arrivalStation = other.arrivalStation;
	other.arrivalStation = nullptr;
	this->departureDateAndTime = other.departureDateAndTime;
	other.departureDateAndTime = *localtime(NULL);
	this->arrivalDateAndTime = other.arrivalDateAndTime;
	other.arrivalDateAndTime = *localtime(NULL);
	this->departurePlatform = other.departurePlatform;
	other.departurePlatform = 0;
	this->arrivalPlatform = other.arrivalPlatform;
	other.arrivalPlatform = 0;
	this->distanceBetweenStationsInKM = other.distanceBetweenStationsInKM;
	other.distanceBetweenStationsInKM = 0;
	this->id = other.id;
	other.id = 0;
	this->speed = other.speed;
	other.speed = 0;
	this->wagons = other.wagons;
	other.wagons = nullptr;
	this->wagonsCount = other.wagonsCount;
	other.wagonsCount = 0;
}

void Train::free()
{
	delete this->departureStation;
	this->departureStation = nullptr;
	delete this->arrivalStation;
	this->arrivalStation = nullptr;
	this->departureDateAndTime = *localtime(NULL);
	this->arrivalDateAndTime = *localtime(NULL);
	this->departurePlatform = 0;
	this->arrivalPlatform = 0;
	this->distanceBetweenStationsInKM = 0;
	this->id = 0;
	this->speed = 0;
	delete[] this->wagons;
	this->wagons = nullptr;
	this->wagonsCount = 0;
}

void Train::setStation(Station& station, Station* field)
{
	if (!&station)
	{
		field = nullptr;
		throw std::invalid_argument("Invalid station!");
	}

	field = &station;
}

void Train::solveTheArrivalTimeInHoursAndMinutes()
{
	int timeInMinutes = this->distanceBetweenStationsInKM / this->speed * constants::MINUTES_IN_AN_HOUR;

	this->arrivalDateAndTime = this->departureDateAndTime;

	this->arrivalDateAndTime.tm_hour += timeInMinutes / constants::MINUTES_IN_AN_HOUR;
	this->arrivalDateAndTime.tm_min += timeInMinutes % constants::MINUTES_IN_AN_HOUR;
}

void Train::setTime(struct tm departureTime)
{
	this->departureDateAndTime = departureTime;

	solveTheArrivalTimeInHoursAndMinutes();
}

void Train::setPlatforms()
{
	this->arrivalPlatform = this->arrivalStation->getAvailablePlatform();
	this->departurePlatform = this->departureStation->getAvailablePlatform();
}

void Train::setDistance(int distance)
{
	if (distance < 0)
	{
		this->distanceBetweenStationsInKM = 0;
		throw std::invalid_argument("Invalid distance!");
	}

	this->distanceBetweenStationsInKM = distance;
}

void Train::setSpeed(int speed)
{
	if (speed < 0)
	{
		this->speed = 0;
		throw std::invalid_argument("Invalid speed!");
	}

	this->speed = speed;
}

void Train::setID()
{
	this->id = ID_Resources::generateID(constants::ID_CHARECTERS_COUNT);
}

Train::Train(Station& departure, Station& arrival, int distance, int speed, struct tm departureTime)
{
	setStation(departure, this->departureStation);
	setStation(arrival, this->arrivalStation);
	setDistance(distance);
	setSpeed(speed);
	setTime(departureTime);
	setPlatforms();
	setID();
	this->wagons = nullptr;
	this->wagonsCount = 0;
}

Train::Train(const Train& other)
{
	copyFrom(other);
}

Train& Train::operator=(const Train& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Train::Train(Train&& other)
{
	moveFrom(std::move(other));
}

Train& Train::operator=(Train&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

size_t Train::findWagon(int wagonId)
{
	for (size_t i = 0; i < this->wagonsCount; i++)
	{
		if (this->wagons[i]->getID() == wagonId)
		{
			return i;
		}
	}

	throw std::invalid_argument("Invalid id!");
}

void Train::addWagon(Wagon& wagon)
{
	if (!this->wagons)
	{
		this->wagons = new Wagon * [20];
	}

	this->wagons[this->wagonsCount] = &wagon;

	this->wagonsCount++;
}

void Train::removeWagon(int wagonId)
{
	try
	{
		size_t index = findWagon(wagonId);

		for (int i = index; i < this->wagonsCount - 1; i++)
		{
			this->wagons[i] = this->wagons[i + 1];
		}

		this->wagonsCount--;
	}
	catch (std::invalid_argument e)
	{
		std::cout << e.what();
	}
}

const int Train::getDeparturePlatform() const
{
	return this->departurePlatform;
}

const int Train::getArrivalPlatform() const
{
	return this->arrivalPlatform;
}

const int Train::getTrainId() const
{
	return this->id;
}

Wagon** Train::getWagons() const
{
	return this->wagons;
}

const char* Train::printDepartureTime() const
{
	char* date = new char[constants::MAX_DATETIME_SIZE];
	strftime(date, constants::MAX_DATETIME_SIZE, "%H:%M %d.%m.%Y", &this->departureDateAndTime);

	return date;
}

const char* Train::printArrivalTime() const
{
	char* date = new char[constants::MAX_DATETIME_SIZE];
	strftime(date, constants::MAX_DATETIME_SIZE, "%H:%M %d.%m.%Y", &this->arrivalDateAndTime);

	return date;
}

void Train::printWagons()
{
	std::cout << "Wagons\n";

	for (size_t i = 0; i < this->wagonsCount; i++)
	{
		std::cout << (i + 1) << " - " << this->wagons[i]->getWagonType() << "\n";
	}
}

void Train::printTrainInfo()
{
	std::cout << "===Train ID: " << this->getTrainId() << " ===\n";
	std::cout << "Strarting station: " << this->departureStation->getName() << "\n";
	std::cout << "Destination: " << this->arrivalStation->getName() << "\n";
	std::cout << "Distance:" << this->distanceBetweenStationsInKM << "km\n";
	std::cout << "Speed: " << this->speed << "km/h\n";
	std::cout << "Departure Time: " << this->printDepartureTime() << "\n";
	std::cout << "Arrival Time: " << this->printArrivalTime() << "\n";
	std::cout << "Departure Platform: " << this->getDeparturePlatform() << "\n\n";

	this->printWagons();
}

bool isBigger(const char* str1, const char* str2)
{
	while (*str1)
	{
		if (*str1 <= *str2)
		{
			return false;
		}

		str1++;
		str2++;
	}

	return true;
}

bool Train::isTrainDepartured() const
{
	time_t timestamp = time(NULL);
	struct tm now = *localtime(&timestamp);

	char* date = new char[constants::MAX_DATETIME_SIZE];
	strftime(date, constants::MAX_DATETIME_SIZE, "%H:%M %d.%m.%Y", &now);

	return isBigger(this->printDepartureTime(), date);
}

Train::~Train()
{
	free();
}