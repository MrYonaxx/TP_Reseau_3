#include "ReplicationManager.h"
#include "ClassRegistry.h"

namespace uqac::replication {

	ReplicationManager::ReplicationManager() {
		this->serializer = uqac::serializer::Serializer();
		linkingContext = LinkingContext();
	}

	// Write
	std::vector<char> ReplicationManager::Update(int protocol)
	{
		// Clear serializer précédent 
		
		// Serialiser identifiant protocol
		serializer.Serialize(protocol);

		// Serialiser identifiant paquet
		//serializer.Serialize()

		for (auto elem : objectsReplicated) 
		{
			// Serialiser identifiant objet (le int de linking context)
			if (auto str = linkingContext.GetObject(elem)) {
				serializer.Serialize(str.value()); // à test
			}
			// Serialiser identifiant de classe (classID)
			uint8_t classID = static_cast<uint8_t>(elem->classID);
			serializer.Serialize(classID);

			// Serialiser l'objet
			elem->Write(serializer);
		}

		return serializer.GetBuffer();
	}

	void ReplicationManager::Read(std::string buffer)
	{
		Deserializer deserializer(, strlen(buffer.c_str()));
		
		// Serialiser identifiant protocol
		int protocol = deserializer.Read<int>();
		// Serialiser identifiant paquet



		// DeSerialiser identifiant objet (le int de linking context)
		int objectID = deserializer.Read<int>();

		// DeSerialiser identifiant de classe (classID)
		ClassID classID = static_cast<ClassID>(deserializer.Read<uint8_t>());

		// Check si l'id de l'objet est déjà dans le linking context
		if (auto obj = linkingContext.GetObject(objectID)) 
		{
			// Si oui on l'update
			obj.value()->Read(deserializer);
		}
		else
		{
			// Si non on le rajoute 
			GameObject* objReplica = ClassRegistry::GetInstance()->Create(classID);
			linkingContext.AddGameObject(objReplica);
			objectsReplicated.insert(objReplica);
		}
	}
}
