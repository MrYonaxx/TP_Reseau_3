#include "ClassRegistry.h"

namespace uqac::replication 
{

	GameObject* ClassRegistry::Create(ClassID id)
	{
		return classDatabase.at(id)();
	}
}
