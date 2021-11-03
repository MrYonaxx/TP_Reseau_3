#include "Vector3.h"
#include "FloatCompressor.h"

namespace uqac::serializer
{
	Vector3Compressor::Vector3Compressor(Vector3 min, Vector3 max, int precision)
	{
		 this->min = min;
		 this->max = max;
		 this->precision = precision;
	}

	void Vector3Compressor::Compressor(Serializer& s, Vector3 val)
	{
		// On compresse les 3 float du vecteur avec un float compresseur
		FloatCompressor floatCompX(min.x, max.x, precision);
		floatCompX.Compressor(s, val.x);

		FloatCompressor floatCompY(min.y, max.y, precision);
		floatCompY.Compressor(s, val.y);

		FloatCompressor floatCompZ(min.z, max.z, precision);
		floatCompZ.Compressor(s, val.z);
		
	}

	Vector3 Vector3Compressor::UnCompressor(Deserializer& s)
	{
		Vector3 res;

		FloatCompressor floatCompX(min.x, max.x, precision);
		res.x = floatCompX.UnCompressor(s);

		FloatCompressor floatCompY(min.y, max.y, precision);
		res.y = floatCompY.UnCompressor(s);

		FloatCompressor floatCompZ(min.z, max.z, precision);
		res.z = floatCompZ.UnCompressor(s);

		return res;
	}

	

	
}