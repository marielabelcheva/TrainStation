#pragma once
#include "User.h"

class Admin : public User
{
	char* pass;

	void login(const char* userName, const char* pass);
	void addStation(const char* name);
	void addTrain(Station* departure, Station* arrival, int distance, int speed, struct tm departureTime);
	void removeTrain(int trainId);
	void addWagon(int trainId, const char* wagonType, double basePrice); // and extra params depending on wagonType
	void removeWagon(int trainId, int wagonId);

	void moveWagon(int sourceTrainId, int wagonId, int destinationTrainId);
	// only if the 2 trains are not departured and in the wagon there's no bought seats

	void createDiscountCard(const char* cardType, const char* userName, const char* fileName); // // and extra params depending on cardType
	bool validateDiscountCard(int cardId);
};

