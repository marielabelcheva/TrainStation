#include "Resources.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>


int ID_Resources::generateID(int idLenght)
{
	int id = 0;

	srand(time(0));

	for (int i = 0; i < idLenght; i++)
	{
		id = id * 10 + rand() % 10;
	}

	return id;
}

size_t string::strLen(const char* str)
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

void string::strCopy(const char* source, char* destination)
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

void string::strConcat(char* first, const char* second)
{
	if (!first || !second)
	{
		throw std::invalid_argument("Invalid data!");
	}

	size_t firstLen = strLen(first);
	first += firstLen;
	strCopy(second, first);
}