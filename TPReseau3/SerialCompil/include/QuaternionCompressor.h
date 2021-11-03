#pragma once

#include "Serializer.h"
#include "Deserializer.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "IntCompressor.h"

namespace uqac::serializer {

	class QuaternionCompressor {

	private:
		Vector3Compressor vectComp;
		IntCompressor intComp;

	public:

		QuaternionCompressor();

		void Compressor(Serializer& s, Quaternion quaternion);
		Quaternion UnCompressor(Deserializer& s);
	};
}