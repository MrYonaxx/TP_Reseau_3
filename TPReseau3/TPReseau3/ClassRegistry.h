#pragma once
#include <functional>
#include "GameObject.h"

namespace uqac::replication
{

	class ClassRegistry
	{
	public:

		ClassRegistry() = default;
		~ClassRegistry() = default;

		template <typename T>
		void RegisterClass(T id, std::function<void()> creationMethod);



		GameObject* Create(ClassID id);

	private:
		std::map<ClassID, std::function<void()>> classDatabase;


	};

	template<typename T>
	inline void ClassRegistry::RegisterClass(T id, std::function<> creationMethod)
	{

	}

}