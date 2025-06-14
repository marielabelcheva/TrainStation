#pragma once
#include "DiscountCard.h"

class DistanceDiscountCard : public DiscountCard
{
	int distanceInKm;
	int travelledKm;

	void setDistanceInKm(int distance);
	void setTravelledKm(int travelled);

	void setDiscount() override;

	const char* getFieldInfo() const;

public:
	DistanceDiscountCard(const char* name, int distance, int travelledKm);
};

