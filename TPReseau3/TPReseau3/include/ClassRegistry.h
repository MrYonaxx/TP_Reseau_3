#pragma once

#include <functional>
#include <map>
#include "GameObject.h"

namespace uqac::replication
{

	class ClassRegistry
	{
	public:

		ClassRegistry() = default;
		~ClassRegistry() = default;

		static std::unique_ptr<ClassRegistry> Instance;
		static ClassRegistry* GetInstance();
		static void DestroyInstance();

		template <typename T>
		void RegisterClass(T id, std::function<GameObject*()> creationMethod);
		GameObject* Create(ClassID id);

	private:
		std::map<ClassID, std::function<GameObject*()>> classDatabase;


	};

	template<typename T>
	inline void ClassRegistry::RegisterClass(T id, std::function<GameObject*()> creationMethod)
	{
		ClassID c = static_cast<GameObject>(id).classID;
		classDatabase.insert(std::pair<ClassID, std::function<GameObject* ()>>(c, creationMethod));
	}

}