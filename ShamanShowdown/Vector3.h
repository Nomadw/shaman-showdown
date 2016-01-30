#pragma once
#pragma once
//STL Includes

//Custom Includes

using namespace std;
class Vector3
{
#pragma region Variables
public:

private:
	float x;
	float y;
	float z;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	Vector3();
	Vector3(int x, int y);
	Vector3(float x, float y);
	~Vector3();
#pragma endregion

#pragma region Mutators
public:
	float& getX();
	void setX(float value);

	float& getY();
	void setY(float value);
private:
#pragma endregion

#pragma region Functions
public:

private:
#pragma endregion

#pragma region Operators
public:
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

	Vector3& Vector3::operator+=(const Vector3& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Vector3& Vector3::operator-=(const Vector3& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	Vector3& Vector3::operator*=(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		return *this;
	}
	Vector3& Vector3::operator/=(float scalar)
	{
		this->x /= scalar;
		this->y /= scalar;
		return *this;
	}
	friend Vector3 operator+(Vector3 first, const Vector3& second)
	{
		first += second;
		return first;
	}
	friend Vector3 operator-(Vector3 first, const Vector3& second)
	{
		first -= second;
		return first;
	}
	friend Vector3 operator*(Vector3 first, const float& second)
	{
		first *= second;
		return first;
	}
	friend Vector3 operator*(const float& scalar, Vector3 first)
	{
		first *= scalar;
		return first;
	}
	friend Vector3 operator/(Vector3 first, const float& second)
	{
		first /= second;
		return first;
	}
	friend Vector3 operator*(const float& scalar, Vector3& first) 
	{ 
		first /= scalar;
		return first;
	}
#pragma endregion
};
