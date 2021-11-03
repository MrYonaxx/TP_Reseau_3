#include "ReplicationManager.h"

namespace uqac::replication {
	ReplicationManager::ReplicationManager() {
		this->serializer = uqac::serializer::Serializer();
	}

	void ReplicationManager::Update()
	{
		for (auto elem : objectsReplicated) {
			elem->Write(serializer);
		}
	}
}
