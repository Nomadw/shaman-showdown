#include "Vector3.h"


Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
}

Vector3::Vector3(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector3::Vector3(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector3::~Vector3()
{
}


float Vector3::getX()
{
	return this->x;
}
void Vector3::setX(float value)
{
	this->x = value;
}
float Vector3::getY()
{
	return this->y;
}
void Vector3::setY(float value)
{
	this->y = value;
}

float& Vector3::operator[](int index)
{
	switch (index)
	{
	case 0:
		return this->x;
		break;
	default:
		return this->y;
		break;
	}
};

Vector3 Vector3::operator+=(Vector3 other)
{
	return Vector3(this->x + other.x, this->y + other.y);
}
Vector3 Vector3::operator-=(Vector3 other)
{
	return Vector3(this->x + other.x, this->y + other.y);
}
Vector3 Vector3::operator*=(float scalar)
{
	return Vector3(this->x * scalar, this->y * scalar);
}
Vector3 Vector3::operator/=(float scalar)
{
	return Vector3(this->x / scalar, this->y / scalar);
}