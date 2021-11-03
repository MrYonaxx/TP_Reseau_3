#pragma once
#include "Serializer.h"
#include "Deserializer.h"

namespace uqac::replication
{
	enum ClassID
	{
		Player = 1,
		Enemy = 2,
	};

	class GameObject
	{
	public:

		GameObject() = default;
		~GameObject() = default;

		ClassID classID;

		virtual void Write(uqac::serializer::Serializer);
		virtual void Read(uqac::serializer::Deserializer);
		virtual void Destroy();

	};

}