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
		serializer.ClearBuffer();

		// Serialiser identifiant protocol
		serializer.Serialize(protocol);

		// Serialiser identifiant paquet
		replicationID++;
		serializer.Serialize(replicationID);


		for (auto elem : objectsReplicated) 
		{
			// Serialiser identifiant objet (le int de linking context)
			if (auto str = linkingContext.GetObject(elem)) {
				serializer.Serialize(str.value()); // à test
			}
			else {
				std::cout << "Houston on a un problème";
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
		size_t maxSize = strlen(buffer.c_str());
		std::vector<char> data(buffer.begin(), buffer.end()); // Modifié deserializer pour que le buffer soit un string
		Deserializer deserializer(data, maxSize);
		
		// Serialiser identifiant protocol
		int protocol = deserializer.Read<int>();
		// Serialiser identifiant paquet
		int id = deserializer.Read<int>();

		if (id < replicationID) // On ignore si le paquet est trop vieux
			return;

		replicationID = id;

		while (deserializer.GetIndex() < maxSize) 
		{
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
				objReplica->Read(deserializer);

				linkingContext.AddGameObject(objectID, objReplica);
				objectsReplicated.insert(objReplica);

			}
		}
	}


	void ReplicationManager::AddObject(GameObject* obj)
	{
		linkingContext.AddGameObject(obj);
		objectsReplicated.insert(obj);
	}
}
