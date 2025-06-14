#include "FirstClassWagon.h"
#include <iostream>

namespace constants
{
	const int FOOD_PRICE_AND_SEATS_COUNT = 10;
}

FirstClassWagon::FirstClassWagon(double basePrice, double comfortFactor, bool includeFood)
	: Wagon(constants::FOOD_PRICE_AND_SEATS_COUNT, basePrice)
{
	this->includeFood = includeFood;
	setComfortFactor(comfortFactor);
	setWagonType("First Class");
}

void FirstClassWagon::setComfortFactor(double factor)
{
	if (factor < 0 || factor > 1)
	{
		this->comfortFactor = 0;
		throw std::invalid_argument("Comfort factor must be between 0 and 1!");
	}

	this->comfortFactor = factor;
}

Wagon* FirstClassWagon::clone() const
{
	return new FirstClassWagon(*this);
}

double FirstClassWagon::ticketPrice()
{
	return (this->getBasePrice() * this->comfortFactor + this->includeFood * constants::FOOD_PRICE_AND_SEATS_COUNT);
}
