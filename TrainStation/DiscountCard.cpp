#include "DiscountCard.h"
#include "Resources.h"
#include <iostream>

namespace constants
{
	const int ID_CHARECTERS_COUNT = 6;
}

void DiscountCard::copyFrom(const DiscountCard& other)
{
	this->id = other.id;
	this->discountPercents = other.discountPercents;
	this->cardHolder = other.cardHolder;
	this->classType = other.classType;
	this->fieldInfo = other.fieldInfo;
}

void DiscountCard::moveFrom(DiscountCard&& other)
{
	this->id = other.id;
	other.id = 0;
	this->discountPercents = other.discountPercents;
	other.discountPercents = 0;
	this->cardHolder = other.cardHolder;
	other.cardHolder = nullptr;
	this->classType = other.classType;
	other.classType = nullptr;
	this->fieldInfo = other.fieldInfo;
	other.fieldInfo = nullptr;
}

void DiscountCard::free()
{
	this->id = 0;
	this->discountPercents = 0;
	delete[] this->cardHolder;
	this->cardHolder = nullptr;
	delete[] this->classType;
	this->classType = nullptr;
	delete[] this->fieldInfo;
	this->fieldInfo = nullptr;
}

void DiscountCard::setCardHolder(const char* name)
{
	this->cardHolder = new char[string::strLen(name) + 1];
	string::strCopy(name, this->cardHolder);
}

void DiscountCard::setClassType(const char* type)
{
	this->classType = new char[string::strLen(type) + 1];
	string::strCopy(type, this->classType);
}

void DiscountCard::setFieldInfo(const char* info)
{
	this->fieldInfo = new char[string::strLen(info) + 1];
	string::strCopy(info, this->fieldInfo);
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
	this->classType = nullptr;
	this->fieldInfo = nullptr;
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

DiscountCard::DiscountCard(DiscountCard&& other) noexcept
{
	moveFrom(std::move(other));
}

DiscountCard& DiscountCard::operator=(DiscountCard&& other) noexcept
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

void printSymbols(size_t lettersOnTheRow, size_t charsOnRow, char symbol)
{
	size_t spacesCount = charsOnRow - lettersOnTheRow;

	for (size_t i = 0; i < spacesCount; i++)
	{
		std::cout << symbol;
	}
	std::cout << "|\n";
}

void printRow(size_t charsOnRow, const char* text)
{
	size_t nameLen = string::strLen(text);

	if (nameLen > charsOnRow)
	{
		for (size_t i = 0; i < charsOnRow; i++)
		{
			std::cout << text[i];
		}
		std::cout << "|\n|";
		for (size_t i = charsOnRow; i < nameLen; i++)
		{
			std::cout << text[i];
		}

		nameLen -= charsOnRow;
	}
	else
	{
		std::cout << text;
	}

	printSymbols(nameLen, charsOnRow, ' ');

	std::cout << "|";
}

void DiscountCard::printCard() const
{
	size_t charsCount = string::strLen(this->classType) + string::strLen("===") + string::strLen(" card===");

	std::cout << "|===" << this->classType << " card===|\n|";

	printRow(charsCount, getCardHolder());
	printRow(charsCount, this->fieldInfo);
	
	std::cout << getID();

	printSymbols(constants::ID_CHARECTERS_COUNT, charsCount, ' ');
	std::cout << "|";
	printSymbols(0, charsCount, '=');
}

DiscountCard::~DiscountCard()
{
	free();
}