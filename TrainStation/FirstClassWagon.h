#pragma once
#include "Wagon.h"

class FirstClassWagon : public Wagon
{
	bool includeFood;
	double comfortFactor;

	void setComfortFactor(double factor);

	Wagon* clone() const override;

public:
	FirstClassWagon(double basePrice, double comfortFactor, bool includeFood);

	double ticketPrice() override;
};
