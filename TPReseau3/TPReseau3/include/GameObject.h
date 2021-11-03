#pragma once
#include "Serializer.h"
#include "Deserializer.h"

using namespace uqac::serializer;

namespace uqac::replication
{
	enum ClassID
	{
		Player = 1,
		Enemy = 2,
	};

	// Ou network object
	class GameObject
	{
	public:

		GameObject() = default;
		~GameObject() = default;

		static ClassID classID;

		virtual void Write(Serializer&);
		virtual void Read(Deserializer&);
		virtual void Destroy();

	};

}