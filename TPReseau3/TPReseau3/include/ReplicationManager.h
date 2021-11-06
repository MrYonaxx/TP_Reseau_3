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

		std::vector<char> Update(int protocol);
		void Read(std::string buffer);
		void AddObject(GameObject* obj);
		void RemoveObject(GameObject* obj);


		// à bouger dans un vrai projet
		void RandomizeAll();
		void DisplayAll();

	private:
		int replicationID = 0;
		std::unordered_set<GameObject*> objectsReplicated;
		LinkingContext linkingContext;

		uqac::serializer::Serializer serializer;



	};

}