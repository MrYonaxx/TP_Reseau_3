#pragma once

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

		virtual void Write();
		virtual void Read();
		virtual void Destroy();

	};

}