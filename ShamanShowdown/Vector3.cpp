#include "Vector3.h"
#include "Maths.h"

Vector3::Vector3()
{
	this->x = 2;
	this->y = 2;
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

float& Vector3::getX()
{
	return this->x;
}
void Vector3::setX(float value)
{
	this->x = value;
}
float& Vector3::getY()
{
	return this->y;
}
void Vector3::setY(float value)
{
	this->y = value;
}

float Vector3::Magnitude(Vector3 other)
{
	float distX = other.getX() - this->x;
	float distY = other.getY() - this->y;
	float magnitude = sqrt(pow(distX, 2) + pow(distY, 2));
	return magnitude;
}

float Vector3::Magnitude(Vector3 first, Vector3 second)
{
	return first.Magnitude(second);
}