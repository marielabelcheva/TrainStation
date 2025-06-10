#pragma once
#include "Wagon.h"

class PassengerClassWagon : public Wagon
{
	double pricePerKiloOfLuggage;
	double weightOfLuggage;

	void setPricePerKiloOfLuggage(double price);
	void setWeightOfLuggage(double weight);

	Wagon* clone() const override;

public:
	PassengerClassWagon(double basePrice, double pricePerKilo, double luggageWeight);

	double ticketPrice() override;
};

