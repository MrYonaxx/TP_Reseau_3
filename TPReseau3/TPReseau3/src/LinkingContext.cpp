#include "LinkingContext.h"


namespace uqac::replication
{
	// Ajoute un gameobject et un networkID
	void LinkingContext::AddGameObject(int val, GameObject* object)
	{
		GameObjectsID.insert(std::pair<int, GameObject*>(val, object));
		GameObjects.insert(std::pair<GameObject*, int>(object, val));
	};

	void LinkingContext::DeleteGameObject(GameObject* object)
	{
		int id = GameObjects[object];
		GameObjectsID.erase(id);
		GameObjects.erase(object);
	};

	// Ajoute un gameobject sans NetworkID
	void LinkingContext::AddGameObject(GameObject* object)
	{
		// Crée un network ID
		networkID++;
		AddGameObject(networkID, object);
	};



	std::optional<int> LinkingContext::GetObject(GameObject* object)
	{
		if (GameObjects.count(object)) 
		{
			return GameObjects[object];
		}
		return {};
	};

	std::optional<GameObject*> LinkingContext::GetObject(int val)
	{
		if (GameObjectsID.count(val))
		{
			return GameObjectsID[val];
		}
		return{};
	}
}