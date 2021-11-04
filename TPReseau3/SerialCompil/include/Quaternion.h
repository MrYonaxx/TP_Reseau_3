#pragma once

struct Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

	Quaternion()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}

	Quaternion(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
};