#pragma once

/*template<typename T>
struct Vector3<T>
{
	public T x;
	public T y;
	public T z;
};*/
#include "Serializer.h"
#include "Deserializer.h"

namespace uqac::serializer
{
	struct Vector3
	{
	public:
		float x;
		float y;
		float z;

		Vector3()
		{
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

		Vector3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

	};

	class Vector3Compressor
	{

	private:

		Vector3 min;
		Vector3 max;
		int precision;

	public:

		Vector3Compressor() = default;
		Vector3Compressor(Vector3 min, Vector3 max, int precision);

		void Compressor(Serializer& s, Vector3 val);
		Vector3 UnCompressor(Deserializer& s);


	};
}