#include "AgeDiscountCard.h"
#include <iostream>
#include "Resources.h"

namespace constants
{
	const int CHILD_DISCOUNT = 100;
	const int TEEN_DISCOUNT = 50;
	const int ADULT_DISCOUNT = 20;
	const int MAX_ARRAY_SIZE = 15;
}

void AgeDiscountCard::setAge(int age)
{
	if (age < 1)
	{
		this->cardHoldersAge = 0;
		throw std::invalid_argument("Invalid age!");
	}

	this->cardHoldersAge = age;
}

void AgeDiscountCard::setDiscount()
{
	if (this->cardHoldersAge >= 1 && this->cardHoldersAge < 11)
	{
		this->discountPercents = constants::CHILD_DISCOUNT;
	}
	else if (this->cardHoldersAge >= 11 && this->cardHoldersAge < 19)
	{
		this->discountPercents = constants::TEEN_DISCOUNT;
	}
	else
	{
		this->discountPercents = constants::ADULT_DISCOUNT;
	}
}

void ageToString(int age, char* str)
{
	if (age >= 10)
	{
		*str = (char)('0' + age / 10);
		str++;
	}

	*str = (char)('0' + age % 10);
	str++;
	*str = '\0';
}

const char* AgeDiscountCard::getFieldInfo() const
{
	char* result = new char[constants::MAX_ARRAY_SIZE];
	
	ageToString(this->cardHoldersAge, result);
	string::strConcat(result, " years old");

	return result;
}

AgeDiscountCard::AgeDiscountCard(const char* name, int age) : DiscountCard(name)
{
	setAge(age);
	setDiscount();
	setClassType("Age");
	setFieldInfo(getFieldInfo());
}

const int AgeDiscountCard::getCardHoldersAge() const
{
	return this->cardHoldersAge;
}
