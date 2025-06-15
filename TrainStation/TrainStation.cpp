#include <iostream>
#include "Train.h"
#include <fstream>

void readTrains(Train* trains)
{
	std::ifstream file("Trains.txt");

	if (!file.is_open())
	{
		throw std::invalid_argument("File can't be opened!");
	}

	while (!file.eof())
	{
		char* buffer = new char[1024];
		int id = 0;
		file >> id;
		/*if (id == trainId)
		{
			train->printTrainInfo();
		}*/
	}

	file.clear();
	file.close();
}

int main()
{
    return 0;
}