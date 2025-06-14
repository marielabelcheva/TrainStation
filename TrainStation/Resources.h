#pragma once
#include <stdlib.h>
#include <ctime>
#include <iostream>

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

namespace string
{
	size_t strLen(const char* str)
	{
		if (!str)
		{
			throw std::invalid_argument("Invalid data!");
		}

		size_t result = 0;

		while (*str)
		{
			result++;
			str++;
		}

		return result;
	}

	void strCopy(const char* source, char* destination)
	{
		if (!source || !destination)
		{
			throw std::invalid_argument("Invalid data!");
		}

		while (*source)
		{
			*destination = *source;
			source++;
			destination++;
		}

		*destination = '\0';
	}
}