#include "LinkingContext.h"


namespace uqac::replication
{
	void LinkingContext::AddGameObject(int val, GameObject* object)
	{
		GameObject1.insert(val, object);
		GameObject2.insert(object, val);
	};

	void LinkingContext::DeleteGameObject(GameObject* object)
	{
		it = GameObject2.find(object);
		GameObject1.erase(it);
		GameObject2.erase(object);
	};

	void LinkingContext::AddGameObject(GameObject* object)
	{
		it = GameObject2.end() + 1;
		GameObject1.insert(it, object);
		GameObject.insert(object, it);
	};

	std::optional<int> LinkingContext::getObject1(GameObject* object)
	{
		it = GameObject2.find(object);

		return it;
	};

	std::optional<GameObject*> LinkingContext::getObject1(int val)
	{
		it = GameObject1.find(val);

		return it;
	}
}