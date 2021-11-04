#pragma once
#include <map>
#include <optional>
#include "GameObject.h"

namespace uqac::replication 
{
	class LinkingContext
	{
	public:

		 std::map<int, GameObject*> GameObjectsID;
		 std::map<GameObject*, int> GameObjects;

		 int networkID = 0; // Si y'a cafouillage sur les ID � cause du r�seau � changer

		 void AddGameObject(int val, GameObject* object);
		 void DeleteGameObject(GameObject* object);
		 void AddGameObject(GameObject* object);

		 std::optional<int> GetObject(GameObject* object);
		 std::optional<GameObject*> GetObject(int val);

	private:
		

	};

	

}
