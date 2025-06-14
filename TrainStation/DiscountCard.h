#pragma once

class DiscountCard
{
	int id;
	int discountPercents;
	char* cardHolder;

	virtual void copyFrom(const DiscountCard& other);
	virtual void moveFrom(DiscountCard&& other);
	virtual void free();

	void setCardHolder(const char* name);
	void setId();
	virtual void setDiscount() = 0;

public:
	DiscountCard(const char* name);
	DiscountCard(const DiscountCard& other);
	DiscountCard& operator=(const DiscountCard& other);

	DiscountCard(DiscountCard&& other) noexcept;
	DiscountCard& operator=(DiscountCard&& other) noexcept;

	const char* getCardHolder() const;
	const int getID() const;
	const int getDiscountPercents() const;

	virtual ~DiscountCard();
};