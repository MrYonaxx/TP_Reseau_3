#include "Deserializer.h"

namespace uqac::serializer 
{
	Deserializer::Deserializer(char buffer[], int sizebuffer)
	{
		index = 0;
	}

	Deserializer::Deserializer(std::vector<char> buffer, int sizebuffer)
	{
		index = 0;	
		this->buffer = buffer;
	}

}

