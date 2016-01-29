#pragma once
//STL Includes
#define _USE_MATH_DEFINES
#include <cmath>
//Custom Includes

using namespace std;
class Maths
{
#pragma region Variables
public:

private:
	static const float conversionValues[2];
#pragma endregion

#pragma region ENUMS
public:
	enum ANGLE_TYPE : int
	{
		ANGLE_TYPE_DEGREES = 0,
		ANGLE_TYPE_RADIANS = 1
	};
#pragma endregion


#pragma region Functions
public:
	static inline float ConvertAngleTo(ANGLE_TYPE type, float angle) { return angle * conversionValues[type]; }
private:
#pragma endregion

private:
};
