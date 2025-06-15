#include "User.h"
#include <fstream>
#include <iostream>
#include "Resources.h"

void User::copyFrom(const User& other)
{
	this->name = other.name;
	this->age = other.age;
}

void User::moveFrom(User&& other)
{
	this->name = other.name;
	other.name = nullptr;
	this->age = other.age;
	other.age = 0;
}

void User::free()
{
	delete[] this->name;
	this->name = nullptr;
	this->age = 0;
}

void User::setName(const char* name)
{
	this->name = new char[string::strLen(name) + 1];
	string::strCopy(name, this->name);
}

void User::setAge(int age)
{
	if (age < 1)
	{
		this->age = 0;
		throw std::invalid_argument("Invalid age!");
	}

	this->age = age;
}

void User::printStations() const
{
	std::ifstream file("Stations.txt");

	if (!file.is_open())
	{
		throw std::invalid_argument("File can't be opened!");
	}

	while (!file.eof())
	{
		char* buffer = new char[1024];
		file.getline(buffer, 1024);
		std::cout << buffer << "\n";
	}

	file.clear();
	file.close();
}

User::User(const char* name, Train** trains, Station** stations, Wagon** wagons, DiscountCard** cards)
{
	setName(name);
	this->age = 0;
	this->trains = trains;
	this->discountCards = cards;
	this->wagons = wagons;
	this->stations = stations;
}

User::User(const char* name, int age, Train** trains, Station** stations, Wagon** wagons, DiscountCard** cards) 
	: User(name, trains, stations, wagons, cards)
{
	setAge(age);
}

User::User(const User& other)
{
	copyFrom(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

User::User(User&& other) noexcept
{
	moveFrom(std::move(other));
}

User& User::operator=(User&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
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

void User::printSchedule(const char* stationName) const
{
	int i = 0;
	while (*(this->stations[i]->getName()))
	{
		if (isEqual(this->stations[i]->getName(), stationName))
		{
			std::cout << "=== Schedule for station " << this->stations[i]->getName() << " ===";
			this->stations[i]->printArrivalTrains();
			std::cout << "\n";
			this->stations[i]->printDeparturedTrains();

			return;
		}

		i++;
	}

	throw std::invalid_argument("Invalid station!");
}

void User::printScheduleDestination(const char* stationName, const char* destination) const
{
	/*int i = 0;
	while (*(this->stations[i]->getName()))
	{
		if (isEqual(this->stations[i]->getName(), stationName) && isEqual(this->stations[i].))
		{
			std::cout << "=== Schedule for station " << this->stations[i]->getName() << " ===";
			this->stations[i]->printArrivalTrains();
			std::cout << "\n";
			this->stations[i]->printDeparturedTrains();

			return;
		}

		i++;
	}*/
}

void User::printScheduleTime(Station* station, struct tm dateTime) const
{

}

void User::printTrain(int trainId) const
{
	int i = 0;
	while (!this->trains[i]->getTrainId())
	{
		if (this->trains[i]->getTrainId() == trainId)
		{
			this->trains[i]->printTrainInfo();
			return;
		}

		i++;
	}

	throw std::invalid_argument("Invalid trainId");
}

void User::printWagon(int trainId, int wagonId) const
{
	int i = 0;
	while (!this->trains[i]->getTrainId())
	{
		if (this->trains[i]->getTrainId() == trainId)
		{
			try
			{
				this->trains[i]->getWagons()[this->trains[i]->findWagon(wagonId)]->printWagon();
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what();
			}
		}

		i++;
	}

	throw std::invalid_argument("Invalid trainId");
}

void User::buyTicket(int trainId, int wagonId, int seat, const char* fileName)
{
	int i = 0;
	while (!this->trains[i]->getTrainId())
	{
		if (this->trains[i]->getTrainId() == trainId)
		{
			try
			{
				this->trains[i]->getWagons()[this->trains[i]->findWagon(wagonId)]->buyTicket(seat);
			}
			catch (std::invalid_argument e)
			{
				std::cout << e.what();
			}
		}

		i++;
	}

	throw std::invalid_argument("Invalid trainId");
}// and extra params which depends of the type of wagon

void User::buyTicketDiscount(int trainId, int wagonId, int seat, const char* fileName, const char* cardFile)
{
	try
	{

	}
	catch (std::invalid_argument e)
	{
		std::cout << e.what();
	}
}

User::~User()
{
	free();
}