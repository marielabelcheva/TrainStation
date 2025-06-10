#pragma once

class Wagon
{
	int* seats;
	int id;
	double basePrice;

	void setID();
	void setSeats(int seatsCount);
	void setBasePrice(double basePrice);

protected:
	virtual void copyFrom(const Wagon& other);
	virtual void free();
	virtual void moveFrom(Wagon&& other);

	const double getBasePrice() const;

	virtual Wagon* clone() const = 0;

public:
	Wagon(int seatsCount, double basePrice);
	Wagon(const Wagon& other);
	Wagon& operator=(const Wagon& other);

	Wagon(Wagon&& other) noexcept;
	Wagon& operator=(Wagon&& other) noexcept;

	const int getID() const;
	int* getSeats() const;

	virtual double ticketPrice() = 0;

	virtual ~Wagon();
};