#pragma once
#include "Serializer.h"
#include "Deserializer.h"

using namespace uqac::serializer;

namespace uqac::replication
{
	enum class ClassID : uint8_t
	{
		PlayerID = 1,
		EnemyID = 2,
	};

	// Ou network object
	class GameObject
	{
	public:

		GameObject() = default;
		~GameObject() = default;

		ClassID classID;

		virtual void Randomize();
		virtual void Display();

		virtual void Write(Serializer&);
		virtual void Read(Deserializer&);
		virtual void Destroy();

	};

}