#include "ClassRegistry.h"

namespace uqac::replication 
{
    std::unique_ptr<ClassRegistry> ClassRegistry::Instance = 0;

	GameObject* ClassRegistry::Create(ClassID id)
	{
        if(classDatabase.count(id))
		    return classDatabase[id]();
        return nullptr;
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
