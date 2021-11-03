#pragma once
#include <string>

#include "SerialCompil/include/Deserializer.h"
#include "SerialCompil/include/Serializer.h"
#include "SerialCompil/include/Vector3.h"
#include "SerialCompil/include/Quaternion.h"



using namespace uqac::replication;

enum type
{
	Boss = 1;
	Sbire = 2;
};

class Enemy
{

public:

	Vector3 position; // 3 de précision et -500 500 ; -500 500 ; 0 100
	Quaternion rotation;

	int life;

};