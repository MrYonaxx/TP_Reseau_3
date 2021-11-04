#include "ReplicationManager.h"

namespace uqac::replication {

	ReplicationManager::ReplicationManager() {
		this->serializer = uqac::serializer::Serializer();
	}

	// Write
	void ReplicationManager::Update()
	{
		for (auto elem : objectsReplicated) {
			elem->Write(serializer);
		}
	}

	void ReplicationManager::Read()
	{
		for (auto elem : objectsReplicated) {
			elem->Write(serializer);
		}
	}
}
