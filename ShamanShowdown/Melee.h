#pragma once
//STL Includes
#include <list>

//Custom Includes
#include "GameObject.h"
using namespace std;
class MeleeComponent
{
#pragma region Variables
public:

private:
	int strength;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	MeleeComponent();
	~MeleeComponent();
#pragma endregion

#pragma region Mutators
public:
	int GetStrength();
	void SetStrength(int value);
private:
#pragma endregion

#pragma region Functions
public:

private:
#pragma endregion

private:
};
