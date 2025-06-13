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
	if (!this->trains)
	{
		this->availablePlatform = 1;
	}

	else
	{
		this->availablePlatform++;
		/*int i = 0;
		while (*this->trains)
		{
			if (this->trains[i]->printTime()
		}*/
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

void Station::printDeparturedTrains()
{
	/*for (size_t i = 0; i < this->trainsCount; i++)
	{
		this->trains[i].
	}*/
}

void Station::printArrivalTrains()
{
	/*for (size_t i = 0; i < this->trainsCount; i++)
	{
		this->trains[i].
	}*/
}

Station::~Station()
{
	free();
}