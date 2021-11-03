#pragma once

#include "Serializer.h"
#include "Deserializer.h"

namespace uqac::serializer
{
	class IntCompressor
	{

	private:

		int min;
		int max;
		int maxRange;

	public:

		IntCompressor() = default;
		IntCompressor(int min, int max);

		void Compressor(Serializer& s, int val);
		int UnCompressor(Deserializer& s);
		


	};
}