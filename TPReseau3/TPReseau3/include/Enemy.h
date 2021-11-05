#pragma once
#include <string>

#include "GameObject.h"
#include "Deserializer.h"
#include "Serializer.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "IntCompressor.h"
#include "QuaternionCompressor.h"

using namespace uqac::replication;

namespace uqac::networkGame 
{
	enum class EnemyTpe : uint8_t
	{
		Boss = 1,
		Sbire = 2,
	};

	class Enemy : public uqac::replication::GameObject
	{

	public:
		Enemy();

		void Reset();
		void Display();

		void Write(Serializer&) override;
		void Read(Deserializer&) override;
		//void Destroy() override;


	// Variable
	public:

		Vector3 position; // 3 de précision et -500 500 ; -500 500 ; 0 100
		Quaternion rotation;

		EnemyTpe enemyType; // int entre 1 et 2
		int life;

	};
}