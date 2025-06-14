#include "DiscountCard.h"
#include "Resources.h"

namespace constants
{
	const int ID_CHARECTERS_COUNT = 6;
}

void DiscountCard::copyFrom(const DiscountCard& other)
{
	this->id = other.id;
	this->discountPercents = other.discountPercents;
	this->cardHolder = other.cardHolder;
}

void DiscountCard::moveFrom(DiscountCard&& other)
{
	this->id = other.id;
	other.id = 0;
	this->discountPercents = other.discountPercents;
	other.discountPercents = 0;
	this->cardHolder = other.cardHolder;
	other.cardHolder = nullptr;
}

void DiscountCard::free()
{
	this->id = 0;
	this->discountPercents = 0;
	delete[] this->cardHolder;
	this->cardHolder = nullptr;
}

void DiscountCard::setCardHolder(const char* name)
{
	this->cardHolder = new char[string::strLen(name) + 1];
	string::strCopy(name, this->cardHolder);
}

void DiscountCard::setId()
{
	this->id = ID_Resources::generateID(constants::ID_CHARECTERS_COUNT);
}

DiscountCard::DiscountCard(const char* name)
{
	setCardHolder(name);
	setId();
	this->discountPercents = 0;
}

DiscountCard::DiscountCard(const DiscountCard& other)
{
	copyFrom(other);
}

DiscountCard& DiscountCard::operator=(const DiscountCard& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DiscountCard::DiscountCard(DiscountCard&& other)
{
	moveFrom(std::move(other));
}

DiscountCard& DiscountCard::operator=(DiscountCard&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

const char* DiscountCard::getCardHolder() const
{
	return this->cardHolder;
}

const int DiscountCard::getID() const
{
	return this->id;
}

const int DiscountCard::getDiscountPercents() const
{
	return this->discountPercents;
}

DiscountCard::~DiscountCard()
{
	free();
}