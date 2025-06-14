#pragma once

namespace ID_Resources
{
	int generateID(int idLenght);
}

namespace string
{
	size_t strLen(const char* str);

	void strCopy(const char* source, char* destination);

	void strConcat(char* first, const char* second);
}