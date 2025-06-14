#pragma once
#include "DiscountCard.h"

class AgeDiscountCard : public DiscountCard
{
	int cardHoldersAge;

	void setAge(int age);
	void setDiscount() override;

	const char* getFieldInfo() const;
public:
	AgeDiscountCard(const char* name, int age);

	const int getCardHoldersAge() const;
};

