#include "Enemy.h"
#include <stdlib.h>  
#include <time.h>   

namespace uqac::networkGame
{


	Enemy::Enemy()
	{
		srand(time(NULL));
		Randomize();
		classID = ClassID::EnemyID;
	}

	void Enemy::Randomize()
	{
		srand(time(NULL));
		position = Vector3(rand() % 1000 - 500, rand() % 1000 - 500, rand() % 100);
		rotation = Quaternion(-0.4545195, 0.5416753, 0.4545195, 0.5416753);

		enemyType = EnemyTpe::Sbire;
		life = rand() % 300;
	}

	void Enemy::Reset()
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;

		rotation.x = 0;
		rotation.y = 0;
		rotation.z = 0;

		life = 0;

	}

	void Enemy::Display()
	{
		std::cout << '\n';
		std::cout << "=============================\n";
		std::cout << "Ennemy : ";
		std::cout << '\n';
		std::cout << "\nPosition : " << position.x << " " << position.y << " " << position.z;
		std::cout << "\nRotation : " << rotation.x << " " << rotation.y << " " << rotation.z << " " << rotation.w;
		std::cout << '\n';
		std::cout << "\nLife : " << life;
	}



	void Enemy::Write(Serializer& s)
	{
		Vector3Compressor posCompressor(Vector3(-500, -500, 0), Vector3(500, 500, 100), 3);
		posCompressor.Compressor(s, position);

		QuaternionCompressor rotationCompressor;
		rotationCompressor.Compressor(s, rotation);

		IntCompressor lifeCompressor(0, 300);
		lifeCompressor.Compressor(s, life);
	}

	void Enemy::Read(Deserializer& s)
	{
		Vector3Compressor posCompressor(Vector3(-500, -500, 0), Vector3(500, 500, 100), 3);
		position = posCompressor.UnCompressor(s);

		QuaternionCompressor rotationCompressor;
		rotation = rotationCompressor.UnCompressor(s);

		IntCompressor lifeCompressor(0, 300);
		life = lifeCompressor.UnCompressor(s);

		Display();
	}
}