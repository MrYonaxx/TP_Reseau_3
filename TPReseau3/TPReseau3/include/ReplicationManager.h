#pragma once
#include "LinkingContext.h"
#include "GameObject.h"
#include <unordered_set>
#include "Serializer.h"

namespace uqac::replication
{
	class ReplicationManager
	{
	public:

		ReplicationManager();
		~ReplicationManager() = default;

	private:
		std::unordered_set<GameObject*> objectsReplicated;
		LinkingContext linkingContext;

		uqac::serializer::Serializer serializer;

		std::vector<char> Update(int protocol);
		void Read(std::string buffer);

	};

}