#pragma once
//STL Includes
#include <list>

//Custom Includes
#include "GameObject.h"
using namespace std;
class Team
{

#pragma region Variables
public:
	
private:
	GameObject characters[2];
#pragma endregion

#pragma region Constructors/Destuctors
public:
	Team();
	~Team();
#pragma endregion

#pragma region Mutators
public:
	GameObject* GetShaman();
	GameObject* GetWarrior();
private:
#pragma endregion

#pragma region Functions
public:

private:
#pragma endregion

private:
};
