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

void Wagon::setSeats(int count)
{
	this->seatsCount = count;
	this->seats = new bool[this->seatsCount] {false};
}

void Wagon::setBasePrice(double basePrice)
{
	if (basePrice <= 0)
	{
		throw std::invalid_argument("Base price of must be bigger than 0!");
	}

	this->basePrice = basePrice;
}

void Wagon::buyTicket(int seat)
{
	if (seat < 0 || seat > this->seatsCount)
	{
		throw std::invalid_argument("Invalid seat!");
	}

	this->seats[seat - 1] ? throw std::invalid_argument("The seat has already been taken!") : this->seats[seat - 1] = true;
}

void printFirstRow(int charsCount)
{
	for (size_t i = 1; i < charsCount; i++)
	{
		std::cout << "_";
	}
}

void printMiddleRow(int cols, bool value, int& index, int row)
{
	std::cout << "|";

	for (size_t j = 0; j < cols; j++)
	{
		if (row % 2 == 0)
		{
			if (value)
			{
				std::cout << "xx";
			}
			else
			{
				if (index + 1 < 10)
				{
					std::cout << "0";
				}
				std::cout << index + 1;
			}
			index++;
		}
		else
		{
			std::cout << "  ";
		}

		std::cout << " ";
	}

	std::cout << "|\n";
}

void Wagon::printWagon() const
{
	int cols = this->seatsCount / 5;
	int index = 0;

	int charsOnRow = 3 * cols + 1;

	std::cout << " ";
	printFirstRow(charsOnRow);
	std::cout << "\n";

	for (size_t i = 0; i < 9; i++)
	{
		printMiddleRow(cols, this->seats[index], index, i);
	}
	std::cout << "|";
	printFirstRow(charsOnRow);
	std::cout << "|";
}

const int Wagon::getID() const
{
	return this->id;
}

bool* Wagon::getSeats() const
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
