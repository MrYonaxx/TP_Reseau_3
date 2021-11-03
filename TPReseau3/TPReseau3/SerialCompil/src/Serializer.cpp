#include "Serializer.h"
#include <iostream>
#include <cstring>

namespace uqac::serializer 
{
	Serializer::Serializer()
	{
		buffer.reserve(0);
		index = 0;
	}

	Serializer::Serializer(int size)
	{
		buffer.reserve(size);
		index = 0;
	}




	std::vector<char> Serializer::GetBuffer()
	{
		return buffer;
	}

	int Serializer::GetBufferSize()
	{
		return buffer.size();
	}


	void Serializer::Write(const char* buff, size_t size)
	{
		// On resize le buffe si pas assez grand
		if (index + size > buffer.size())
			buffer.resize(index + size);

		std::memcpy(buffer.data() + index, &buff, size);
		index += size;
	}

	void Serializer::WriteString(const char* buff, size_t size)
	{
		// On resize le buffe si pas assez grand
		if (index + size > buffer.size())
			buffer.resize(index + size);

		std::memcpy(buffer.data() + index, buff, size);
		index += size;
	}
}


