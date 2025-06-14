#pragma once

class DiscountCard
{
	int id;
	char* cardHolder;
	char* classType;
	char* fieldInfo;

	virtual void copyFrom(const DiscountCard& other);
	virtual void moveFrom(DiscountCard&& other);
	virtual void free();

	void setCardHolder(const char* name);

	void setId();

protected:
	int discountPercents;
	virtual void setDiscount() = 0;

	void setClassType(const char* type);
	void setFieldInfo(const char* info);

public:
	DiscountCard(const char* name);
	DiscountCard(const DiscountCard& other);
	DiscountCard& operator=(const DiscountCard& other);

	DiscountCard(DiscountCard&& other) noexcept;
	DiscountCard& operator=(DiscountCard&& other) noexcept;

	const char* getCardHolder() const;
	const int getID() const;
	const int getDiscountPercents() const;

	void printCard() const;

	virtual ~DiscountCard();
};