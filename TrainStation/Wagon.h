#pragma once

class Wagon
{
	bool* seats;
	int seatsCount;
	int id;
	double basePrice;

	void setID();
	void setSeats(int count);
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
	bool* getSeats() const;

	virtual double ticketPrice() = 0;

	void printWagon() const;

	void buyTicket(int seat);

	virtual ~Wagon();
};