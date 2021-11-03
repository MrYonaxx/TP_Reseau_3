#pragma once
#include <string>

#include "Serializer.h"
#include "Deserializer.h"
#include "Vector3.h"
#include "Quaternion.h"

using namespace uqac::serializer;

class Player
{

public:
	
	Vector3 position; // 3 de précision et -500 500 ; -500 500 ; 0 100
	Quaternion rotation;
	Vector3 scale; // 3 de précision
	int life; // 0 à 300
	int armor; // 0 à 50
	float money; // -99 999,99 à 99 999,99
	char name[128] = "";

public:
	Player();

	void Reset();
	void Display();

	void Write(Serializer& s);
	void Read(Deserializer& s);

};