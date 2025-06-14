#include "Station.h"
#include "Resources.h"
#include <iostream>

void Station::copyFrom(const Station& other)
{
	this->name = other.name;
	this->availablePlatform = other.availablePlatform;
	this->trains = other.trains;
	this->trainsCount = other.trainsCount;
}

void Station::moveFrom(Station&& other)
{
	this->name = other.name;
	other.name = nullptr;
	this->availablePlatform = other.availablePlatform;
	other.availablePlatform = 0;
	this->trains = other.trains;
	other.trains = nullptr;
	this->trainsCount = other.trainsCount;
	other.trainsCount = 0;
}

void Station::free()
{
	delete[] this->name;
	this->name = nullptr;
	this->availablePlatform = 0;
	delete[] this->trains;
	this->trains = nullptr;
	this->trainsCount = 0;
}

void Station::setName(const char* name)
{
	this->name = new char[string::strLen(name) + 1];
	string::strCopy(name, this->name);
}

void Station::setAvailablePlatform()
{
	this->availablePlatform++;

	for (size_t i = 0; i < trainsCount; i++)
	{
		if (this->trains[i]->isTrainDepartured())
		{
			this->availablePlatform = this->trains[i]->getDeparturePlatform();
			break;
		}
	}
}

Station::Station(const char* name)
{
	setName(name);
	this->trains = nullptr;
	setAvailablePlatform();
	this->trainsCount = 0;
}

Station::Station(const Station& other)
{
	copyFrom(other);
}

Station& Station::operator=(const Station& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Station::Station(Station&& other) noexcept
{
	moveFrom(std::move(other));
}

Station& Station::operator=(Station&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

const char* Station::getName() const
{
	return this->name;
}

const int Station::getAvailablePlatform() const
{
	return this->availablePlatform;
}

void Station::addTrain(Train& train)
{
	if (!this->trains)
	{
		this->trains = new Train * [20];
	}

	this->trains[this->trainsCount] = &train;

	this->trainsCount++;
}

void printLine()
{
	for (size_t i = 0; i < 128; i++)
	{
		std::cout << "-";
	}
	std::cout << "\n";
}

bool isEqual(const char* str1, const char* str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
		{
			return false;
		}

		str1++;
		str2++;
	}
	return true;
}

void Station::printDeparturedTrains()
{
	std::cout << "Departures:\n";
	printLine();
	std::cout << "| Departure Time   | Arrival Time    | Destination   | Departure Platform | Train ID | Status   |";
	printLine();
	for (size_t i = 0; i < this->trainsCount; i++)
	{
		if (isEqual(this->trains[i]->departureStation->getName(), this->name))
		{
			std::cout << "| " << this->trains[i]->printDepartureTime() << "  | " << this->trains[i]->printArrivalTime();
			std::cout << "  | " << this->trains[i]->arrivalStation->getName() << "  | " << this->trains[i]->getDeparturePlatform();
			std::cout << "      | " << this->trains[i]->getTrainId() << "    | ";
			std::cout << (this->trains[i]->isTrainDepartured() ? "Departed" : "To depart") << "   |\n";
		}
	}
}

void Station::printArrivalTrains()
{
	std::cout << "Arrivals:\n";
	printLine();
	std::cout << "| Arrival Time   | Arrival Platform | Train ID | Starting Station |";
	printLine();
	for (size_t i = 0; i < this->trainsCount; i++)
	{
		if (isEqual(this->trains[i]->arrivalStation->getName(), this->name))
		{
			std::cout << "| " << this->trains[i]->printArrivalTime() << "  | " << this->trains[i]->getArrivalPlatform();
			std::cout << "    | " << this->trains[i]->getTrainId() << " | ";
			std::cout << this->trains[i]->departureStation->getName() << " |\n";
		}
	}
}

Station::~Station()
{
	free();
}