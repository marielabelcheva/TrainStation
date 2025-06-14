#include "RouteDiscountCard.h"

namespace constants
{
	const int FULL_DISCOUNT = 100;
}

void RouteDiscountCard::setDiscount()
{
	this->discountPercents = constants::FULL_DISCOUNT;
}

RouteDiscountCard::RouteDiscountCard(const char* name, const char* destination) : DiscountCard(name)
{
	setClassType("Route");
	setFieldInfo(destination);
}