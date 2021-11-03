#include "QuaternionCompressor.h"


namespace uqac::serializer
{
	QuaternionCompressor::QuaternionCompressor() 
	{
		this->vectComp = Vector3Compressor(Vector3(-1, -1, -1),Vector3(1, 1, 1), 3);
		this->intComp = IntCompressor(0, 4);
	}

	void QuaternionCompressor::Compressor(Serializer& s, Quaternion quaternion) 
	{
		float index = 0;
		float x = std::abs(quaternion.x);
		float y = std::abs(quaternion.y);
		float z = std::abs(quaternion.z);
		float w = std::abs(quaternion.w);

		// On cherche la plus grande valeure du quaternion
		// Et on stock le signe de la plus grande valeure
		if (x > y) 
			index = 0; 
		else 
			index = 1; 
		float max = std::max(x, y);
		if (z > max) 
			index = 2; 
		max = std::max(max, z);
		if (w > max) 
			index = 3;
		max = std::max(max, w);

		// On encode les 3 autres valeurs du quaternion (celle pas absolu)
		float a, b, c;
		if (index == 0)
		{
			a = quaternion.y;
			b = quaternion.z;
			c = quaternion.w;
		}
		else if (index == 1)
		{
			a = quaternion.x;
			b = quaternion.z;
			c = quaternion.w;
		}
		else if (index == 2)
		{
			a = quaternion.x;
			b = quaternion.y;
			c = quaternion.w;
		}
		else 
		{
			a = quaternion.x;
			b = quaternion.y;
			c = quaternion.z;
		}

		intComp.Compressor(s, index);
		vectComp.Compressor(s, Vector3(a, b, c));
	}

	Quaternion QuaternionCompressor::UnCompressor(Deserializer& s) 
	{
		int index = intComp.UnCompressor(s);
		Vector3 vector = vectComp.UnCompressor(s);

		// On calcul le dernier élément et on les replace en fonction de index
		float x = vector.x;
		float y = vector.y;
		float z = vector.z;
		float w = sqrt(1 - (pow(x, 2) + pow(y, 2) + pow(z, 2)));

		// On replace bien les valeurs x y z grâce à index
		if(index == 0)
			return Quaternion(w, x, y, z);
		else if (index == 1)
			return Quaternion(x, w, y, z);
		else if (index == 2)
			return Quaternion(x, y, w, z);
		return Quaternion(x, y, z, w);
	}
}