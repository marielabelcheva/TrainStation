#include "DistanceDiscountCard.h"
#include <iostream>
#include "Resources.h"

namespace constants
{
	const int UP_TO = 50;
	const int OVER = 30;
	const int MAX_ARRAY_SIZE = 5;
}

void DistanceDiscountCard::setDistanceInKm(int distance)
{
	if (distance < 1)
	{
		this->distanceInKm = 0;
		throw std::invalid_argument("Invalid distance!");
	}

	this->distanceInKm = distance;
}

void DistanceDiscountCard::setTravelledKm(int travelled)
{
	if (travelled < 1)
	{
		this->distanceInKm = 0;
		throw std::invalid_argument("Invalid travelled distance!");
	}

	this->travelledKm= travelled;
}

void DistanceDiscountCard::setDiscount()
{
	this->discountPercents = this->distanceInKm >= this->travelledKm ? constants::UP_TO : constants::OVER;
}

int reverseNumber(int num)
{
	int reversed = 0;

	while (num) 
	{
		reversed = reversed * 10 + num % 10;
		num /= 10;
	}

	return reversed;
}

void distanceToString(int distance, char* str)
{
	int rev = reverseNumber(distance);

	while (distance)
	{
		*str = (char)('0' + rev % 10);
		rev /= 10;
		distance /= 10;
		str++;
	}
	*str = '\0';
}

const char* DistanceDiscountCard::getFieldInfo() const
{
	char* result = new char[constants::MAX_ARRAY_SIZE];

	distanceToString(this->distanceInKm, result);
	string::strConcat(result, " km");

	return result;
}

DistanceDiscountCard::DistanceDiscountCard(const char* name, int distance, int travelledKm)
	: DiscountCard(name)
{
	setDistanceInKm(distance);
	setTravelledKm(travelledKm);
	setClassType("Distance");
	setFieldInfo(getFieldInfo());
}