#include "PassengerClassWagon.h"
#include <iostream>

namespace constants
{
	const int SEATS_COUNT = 20;
}

PassengerClassWagon::PassengerClassWagon(double basePrice, double pricePerKilo, double luggageWeight)
	: Wagon(constants::SEATS_COUNT, basePrice)
{
	setPricePerKiloOfLuggage(pricePerKilo);
	setWeightOfLuggage(luggageWeight);
	setWagonType("Passenger Class");
}

void PassengerClassWagon::setPricePerKiloOfLuggage(double price)
{
	if (price <= 0)
	{
		this->pricePerKiloOfLuggage = 0;
		throw std::invalid_argument("The price per kilo of luggage must be bigger than 0!");
	}

	this->pricePerKiloOfLuggage = price;
}

void PassengerClassWagon::setWeightOfLuggage(double weight)
{
	if (weight <= 0)
	{
		this->weightOfLuggage = 0;
		throw std::invalid_argument("The weight of the luggage must be bigger than 0!");
	}

	this->weightOfLuggage = weight;
}

Wagon* PassengerClassWagon::clone() const
{
	return new PassengerClassWagon(*this);
}

double PassengerClassWagon::ticketPrice()
{
	return this->getBasePrice() + this->pricePerKiloOfLuggage * this->weightOfLuggage;
}