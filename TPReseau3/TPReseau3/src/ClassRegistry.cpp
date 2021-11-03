#include "ClassRegistry.h"

namespace uqac::replication 
{

	GameObject* ClassRegistry::Create(ClassID id)
	{
		return classDatabase.at(id)();
	}



    ClassRegistry* ClassRegistry::GetInstance()
    {
        if (Instance == 0)
        {
            Instance = std::make_unique<ClassRegistry>();
        }
        return Instance.get();
    }

    void ClassRegistry::DestroyInstance()
    {
        Instance.reset();
    }
}
