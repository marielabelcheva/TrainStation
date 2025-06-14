#pragma once
#include "DiscountCard.h"

class RouteDiscountCard : public DiscountCard
{
	void setDiscount() override;

public:
	RouteDiscountCard(const char* name, const char* destination);
};

