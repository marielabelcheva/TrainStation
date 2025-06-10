#pragma once
#include "Wagon.h"

class SleepingWagon : public Wagon
{
	double pricePer100km;
	int distanceInKm;

	void setPricePer100km(double price);
	void setDistanceInKm(int kilometres);

	Wagon* clone() const override;

public:
	SleepingWagon(double basePrice, double pricePer100km, int distance);

	double ticketPrice() override;
};

