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

namespace string
{
	size_t strLen(const char* str)
	{
		if (!str)
		{
			throw - 1;
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
			throw - 1;
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