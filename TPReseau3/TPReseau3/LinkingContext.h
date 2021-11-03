#pragma once
#include<map>
#include "GameObject.h"

namespace uqac::replication 
{
	class LinkingContext
	{
	public:

		 std::map<int, *GameObject> GameObject1;
		 std::map<*GameObject, int> GameObject2;
		 std::map<char, int>::iterator it;

		 void AddGameObject(int val, GameObject* object);
		 void DeleteGameObject(GameObject* object);
		 void AddGameObject(GameObject* object);

		 std::optional<int val> getObject1(GameObject* object);
		 std::optional<GameObject* object> getObject1(int val);

	private:
		

	};

	

}
