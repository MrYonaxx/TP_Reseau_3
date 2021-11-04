#include "ReplicationManager.h"

namespace uqac::replication {

	ReplicationManager::ReplicationManager() {
		this->serializer = uqac::serializer::Serializer();
		linkingContext = LinkingContext();
	}

	// Write
	void ReplicationManager::Update()
	{
		for (auto elem : objectsReplicated) 
		{
			// Serialiser identifiant protocol
			// Serialiser identifiant paquet

			// Serialiser identifiant objet (le int de linking context)
			// Serialiser identifiant de classe (classID)

			// Serialiser l'objet
			elem->Write(serializer);
		}
	}

	void ReplicationManager::Read()
	{
		//Deserializer deserializer(buffer, buffer);
		// 
		// Serialiser identifiant protocol
		// Serialiser identifiant paquet

		// Serialiser identifiant objet (le int de linking context)
		// Serialiser identifiant de classe (classID)

		// Check si l'id de l'objet est déjà dans le linking context
			// Si oui on l'update
			// Si non on le rajoute avec classID et class Registry
	}
}
