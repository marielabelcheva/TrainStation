#pragma once
#include <stdlib.h>
#include <ctime>

namespace constants
{
	namespace wagon
	{
		const int ID_CHARECTERS_COUNT = 4;

		namespace firstClass
		{
			const int FOOD_PRICE_AND_SEATS_COUNT = 10;
		}
	}

}

namespace ID_Resources
{
	int generateID(int idLenght)
	{
		int id = 0;

		srand(time(0));

		for (int i = 0; i < idLenght; i++)
		{
			id = id * 10 + rand() % 10;
		}

		return id;
	}
}