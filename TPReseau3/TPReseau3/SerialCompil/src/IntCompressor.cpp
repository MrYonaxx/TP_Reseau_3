#include "IntCompressor.h"

namespace uqac::serializer
{
    IntCompressor::IntCompressor(int min, int max)
    {
        this->min = min;
        this->max = max;
        maxRange = 0;
    }

    void IntCompressor::Compressor(Serializer& s, int val)
	{
        maxRange = max - min;
        
        // En fonction de la max Range on serialize un uint correspondant
        if (maxRange <= 255) {
            uint8_t newval = val - min;
            s.Serialize(newval);
        }
        else if(maxRange <= 65535) {
            uint16_t newval = val - min;
            s.Serialize(newval);
        }
        else if (maxRange <= 4294967295) {
            uint32_t newval = val - min;
            s.Serialize(newval);
        }
            
	}


    int IntCompressor::UnCompressor(Deserializer& s)
    {
        maxRange = max - min;

        // En fonction de la max Range on deserialize un uint correspondant
        int res;
        if (maxRange <= 255)
            res = (int) s.Read<uint8_t>() + min;
        else if (maxRange <= 65535) 
            res = (int) s.Read<uint16_t>() + min;
        else if (maxRange <= 4294967295) 
            res = (int) s.Read<uint32_t>() + min;

        return res;

    }

}
