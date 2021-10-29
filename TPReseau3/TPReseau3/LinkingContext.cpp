#include"LinkingContext.h"


namespace uqac::replication
{

	void AddGameObject(int val, GameObject* object)
	{
		GameObject1.insert(val, object);
		GameObject2.insert(object, val);
	};

	void DeleteGameObject(GameObject* object)
	{
		it = GameObject2.find(object);
		GameObject1.erase(it);
		GameObject2.erase(object);
	};

	void AddGameObject(GameObject* object)
	{
		it = GameObject2.end() + 1;
		GameObject1.insert(it, object);
		GameObject.insert(object, it);
	};

	std::optional<int val> getObject1(GameObject* object)
	{
		it = GameObject2.find(object);

		return it;
	};

	std::optional<GameObject* object> getObject1(int val)
	{
		it = GameObject1.find(val);

		return it;
	}

}