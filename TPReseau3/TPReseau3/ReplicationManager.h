#pragma once
#include "LinkingContext.h"
#include "GameObject.h"
#include <set>

namespace uqac::replication
{
	class ReplicationManager
	{
	public:

		ReplicationManager() = default;
		~ReplicationManager() = default;

	private:
		std::unordered_set<GameObject*> objectsReplicated;
		LinkingContext linkingContext;

		void Update();

	};

}