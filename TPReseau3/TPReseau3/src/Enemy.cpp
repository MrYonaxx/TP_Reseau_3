#include "Enemy.h"
#include <stdlib.h>  
#include <time.h>   
#include "SerialCompil/include/IntCompressor.h"  

Enemy::Enemy()
{
	srand(time(NULL));
	position = Vector3(rand() % 1000 - 500, rand() % 1000 - 500, rand() % 100);
	//rotation = Quat(rand(), rand(), rand());
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

void Player::Display()
{
	std::cout << "\nPosition : " << position.x << " " << position.y << " " << position.z;
	std::cout << "\nRotation : " << rotation.x << " " << rotation.y << " " << rotation.z << " " << rotation.w;
	std::cout << "\nLife : " << life;
	

}

void Enemy::Write(Serializer& s)
{
	IntCompressor lifeCompressor(0, 300);
	lifeCompressor.Compressor(s, life);

}

void Enemy::Read(Deserializer& s)
{
	IntCompressor lifeCompressor(0, 300);
	life = lifeCompressor.UnCompressor(s);

}