#pragma once
#include <string>

#include "GameObject.h"
#include "Deserializer.h"
#include "Serializer.h"
#include "Vector3.h"
#include "Quaternion.h"

using namespace uqac::replication;

namespace uqac::networkGame 
{
	enum class EnemyTpe
	{
		Boss = 1,
		Sbire = 2,
	};

	class Enemy : public GameObject
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