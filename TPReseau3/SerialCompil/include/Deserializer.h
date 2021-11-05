#pragma once
#include <iostream>
#include <vector>

namespace uqac::serializer
{
	class Deserializer
	{

	private:
		int index;
		std::vector<char> buffer;

	public:

		Deserializer(char buffer[], int size);
		Deserializer(std::vector<char> buffer, int sizebuffer);

		template <typename T>
		T Read();
		char* Read(size_t size);

		inline int GetIndex() { return index; }

	};

	template<typename T>
	inline T Deserializer::Read()
	{
		const size_t size = sizeof(T);

		unsigned char buf[size];
		std::memcpy(buf, buffer.data() + index, size);
		index += size;

		return *(T*)buf;
	}

	// Pour read les string
	inline char* Deserializer::Read(size_t size)
	{
		char* buf = new char[size];
		std::memcpy(buf, buffer.data() + index, size);
		index += size;

		return buf;
	}

}
