#pragma once
#include <stdlib.h>
#include <ctime>

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