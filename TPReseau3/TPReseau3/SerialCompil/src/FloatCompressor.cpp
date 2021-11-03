#include "FloatCompressor.h"
#include "IntCompressor.h"

namespace uqac::serializer
{
	FloatCompressor::FloatCompressor(int min, int max, int precision)
	{
		this->precision = precision;
		min = (int)min * pow(10, precision);
		max = (int)max * pow(10, precision);
		this->intComp = IntCompressor(min, max);
	}

	void FloatCompressor::Compressor(Serializer& s, float val)
	{
		// On transforme le float en int en fonction de la precision 
		int valInt = (int)(val * pow(10, precision)); 

		intComp.Compressor(s, valInt);
	}

	float FloatCompressor::UnCompressor(Deserializer& s)
	{
		return intComp.UnCompressor(s) / (pow(10, precision));
	}
}