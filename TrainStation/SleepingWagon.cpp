#include "SleepingWagon.h"
#include <iostream>

namespace constants
{
	const int BEDS_COUNT = 5;
}

SleepingWagon::SleepingWagon(double basePrice, double pricePer100km, int distance)
	: Wagon(constants::BEDS_COUNT, basePrice)
{
	setDistanceInKm(distance);
	setPricePer100km(pricePer100km);
}

void SleepingWagon::setDistanceInKm(int kilometres)
{
	if (kilometres <= 0)
	{
		this->distanceInKm = 0;
		throw std::invalid_argument("Distance must be bigger than 0!");
	}

	this->distanceInKm = kilometres;
}

void SleepingWagon::setPricePer100km(double price)
{
	if (price <= 0)
	{
		this->pricePer100km = 0;
		throw std::invalid_argument("Price per 100 km must be bigger than 0!");
	}

	this->pricePer100km = price;
}

Wagon* SleepingWagon::clone() const
{
	return new SleepingWagon(*this);
}

double SleepingWagon::ticketPrice()
{
	return this->getBasePrice() + (this->pricePer100km / 100) * this->distanceInKm;
}