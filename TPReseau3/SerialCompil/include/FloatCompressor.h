#pragma once

#include "Serializer.h"
#include "Deserializer.h"
#include "IntCompressor.h"

namespace uqac::serializer {

	class FloatCompressor {

	private:
		int precision;
		IntCompressor intComp;

	public:

		FloatCompressor(int min, int max, int precision);

		void Compressor(Serializer& s, float val);
		float UnCompressor(Deserializer& s);
	};
}