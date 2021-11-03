#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace uqac::serializer 
{
	class Serializer 
	{

	private:
		int index;
		std::vector<char> buffer;

	public:

		Serializer();
		Serializer(int size);

		template <typename T,
			std::enable_if_t<std::is_arithmetic_v<
			std::remove_reference_t<T>>>* = nullptr>
		void Serialize(T& data);

		template <typename T, size_t size>
		void Serialize(T(&data)[size]);

		std::vector<char> GetBuffer();
		int GetBufferSize();

	private:
		void Write(const char* buff, size_t size);
		void WriteString(const char* buff, size_t size);

	};

	template <typename T,
		std::enable_if_t<std::is_arithmetic_v<
		std::remove_reference_t<T>>>* = nullptr>
	inline void Serializer::Serialize(T& data)
	{
		Write((const char*)(data), sizeof(data));
	}

	// Ne serialize que les chaines de caractères, les autres tableaux ne fonctionne pas
	template <typename T, size_t size>
	inline void Serializer::Serialize(T(&data)[size])
	{
		WriteString((const char*)(data), sizeof(data));
	}


}