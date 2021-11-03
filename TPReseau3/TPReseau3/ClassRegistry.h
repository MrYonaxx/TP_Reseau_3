#pragma once
#include <functional>

namespace uqac::replication
{
	public enum ClassID
	{
		Player = 1,
		Enemy = 2;
	};

	class ClassRegistry
	{
	public:

		ClassRegistry() = default;
		~ClassRegistry() = default;

		void RegisterClass(std::function<> creationMethod);
		GameObject* Create(ClassID id);

	private:
		std::map<ClassID, std::function<>> classDatabase;


	};

}