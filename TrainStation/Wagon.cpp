#include "Wagon.h"
#include <iostream>
#include "Resources.h"

namespace constants
{
	const int ID_CHARECTERS_COUNT = 4;
}

void Wagon::copyFrom(const Wagon& other)
{
	this->seats = other.seats;
	this->id = other.id;
	this->basePrice = other.basePrice;
}

void Wagon::free()
{
	delete[] seats;
	seats = nullptr;
	id = 0;
	basePrice = 0;
}

void Wagon::moveFrom(Wagon&& other)
{
	this->seats = other.seats;
	other.seats = nullptr;
	this->id = other.id;
	other.id = 0;
	this->basePrice = other.basePrice;
	other.basePrice = 0;
}

Wagon::Wagon(int seatsCount, double basePrice)
{
	setID();
	setSeats(seatsCount);
	setBasePrice(basePrice);
}

Wagon::Wagon(const Wagon& other)
{
	copyFrom(other);
}

Wagon& Wagon::operator=(const Wagon& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Wagon::Wagon(Wagon&& other) noexcept
{
	moveFrom(std::move(other));
}

Wagon& Wagon::operator=(Wagon&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void Wagon::setID()
{
	this->id = ID_Resources::generateID(constants::ID_CHARECTERS_COUNT);
}

void Wagon::setSeats(int seatsCount)
{
	if (seatsCount <= 0)
	{
		this->seats = nullptr;
		throw std::invalid_argument("Count of the seats must be bigger than 0!");
	}

	this->seats = new int[seatsCount];
}

void Wagon::setBasePrice(double basePrice)
{
	if (basePrice <= 0)
	{
		throw std::invalid_argument("Base price of must be bigger than 0!");
	}

	this->basePrice = basePrice;
}

const int Wagon::getID() const
{
	return this->id;
}

int* Wagon::getSeats() const
{
	return this->seats;
}

const double Wagon::getBasePrice() const
{
	return this->basePrice;
}

Wagon::~Wagon()
{
	free();
}
