#include "Player.h"
#include <stdlib.h>  
#include <time.h>   
#include "IntCompressor.h"  
#include "FloatCompressor.h"  
#include "QuaternionCompressor.h"

namespace uqac::networkGame
{
	Player::Player()
	{
		char* n = "Schnell";
		std::copy(n, n + 7, name);

		srand(time(NULL));
		Randomize();

		classID = uqac::replication::ClassID::PlayerID;
	}

	void Player::Randomize()
	{

		float r = (float)rand() / RAND_MAX;
		position = Vector3((rand() % 1000 - 500) + r, (rand() % 1000 - 500) + r, (rand() % 100) + r);

		// Rotation 20 / 60 / 50
		//rotation = Quaternion(0.3443928, 0.3827146, 0.2817484, 0.8096548);

		// Rotation -80 / 90 / 0
		rotation = Quaternion(-0.4545195, 0.5416753, 0.4545195, 0.5416753);

		scale = Vector3(rand() % 10, rand() % 10, rand() % 10);

		life = rand() % 300;
		armor = rand() % 50;
		money = (rand() % 200000 - 100000) + r;
	}

	void Player::Reset()
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;

		rotation.x = 0;
		rotation.y = 0;
		rotation.z = 0;
		rotation.w = 0;

		scale.x = 0;
		scale.y = 0;
		scale.z = 0;

		life = 0;
		armor = 0;
		money = 0;

		char n[128] = " ";
		std::copy(n, n + 128, name);

	}

	void Player::Display()
	{
		std::cout << '\n';
		std::cout << "=============================\n";
		std::cout << name;
		std::cout << "\nPosition : " << position.x << " " << position.y << " " << position.z;
		std::cout << "\nRotation : " << rotation.x << " " << rotation.y << " " << rotation.z << " " << rotation.w;
		std::cout << "\nScale : " << scale.x << " " << scale.y << " " << scale.z;
		std::cout << '\n';
		std::cout << "\nLife : " << life;
		std::cout << "\nArmor : " << armor;
		std::cout << "\nMoney : " << money;

	}

	void Player::Write(Serializer& s)
	{
		Vector3Compressor posCompressor(Vector3(-500, -500, 0), Vector3(500, 500, 100), 3);
		posCompressor.Compressor(s, position);

		Vector3Compressor scaleCompressor(Vector3(-500, -500, 0), Vector3(500, 500, 100), 3);
		scaleCompressor.Compressor(s, scale);

		IntCompressor lifeCompressor(0, 300);
		lifeCompressor.Compressor(s, life);

		IntCompressor armorCompressor(0, 50);
		armorCompressor.Compressor(s, armor);

		FloatCompressor moneyCompressor(-99999.99, 99999.99, 3);
		moneyCompressor.Compressor(s, money);

		QuaternionCompressor rotationCompressor;
		rotationCompressor.Compressor(s, rotation);


		s.Serialize(name);

	}

	void Player::Read(Deserializer& s)
	{
		Vector3Compressor posCompressor(Vector3(-500, -500, 0), Vector3(500, 500, 100), 3);
		position = posCompressor.UnCompressor(s);

		Vector3Compressor scaleCompressor(Vector3(-500, -500, 0), Vector3(500, 500, 100), 3);
		scale = scaleCompressor.UnCompressor(s);

		IntCompressor lifeCompressor(0, 300);
		life = lifeCompressor.UnCompressor(s);

		IntCompressor armorCompressor(0, 50);
		armor = armorCompressor.UnCompressor(s);

		FloatCompressor moneyCompressor(-99999.99f, 99999.99f, 3);
		money = moneyCompressor.UnCompressor(s);

		QuaternionCompressor rotationCompressor;
		rotation = rotationCompressor.UnCompressor(s);

		char* n = s.Read(128);
		std::copy(n, n + 128, name);
		free(n);

		Display();
	}
}
