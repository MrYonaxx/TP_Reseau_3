#pragma once
#include <string>

#include "Serializer.h"
#include "Deserializer.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "GameObject.h"

namespace uqac::networkGame 
{

	class Player : public uqac::replication::GameObject
	{

	public:

		Vector3 position; // 3 de pr�cision et -500 500 ; -500 500 ; 0 100
		Quaternion rotation;
		Vector3 scale; // 3 de pr�cision
		int life; // 0 � 300
		int armor; // 0 � 50
		float money; // -99 999,99 � 99 999,99
		char name[128] = "";

	public:
		Player();

		void Reset();
		void Display();

		void Write(uqac::serializer::Serializer& s) override;
		void Read(Deserializer& s) override;

	};
}