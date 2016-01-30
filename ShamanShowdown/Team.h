#pragma once
//STL Includes
#include <list>

//Custom Includes
#include "GameObject.h"
class GameState;
class Controls;

using namespace std;
class Team
{

#pragma region Variables
public:
	
private:
	GameObject* characters[2];
#pragma endregion

#pragma region Constructors/Destuctors
public:
	Team();
	~Team();
#pragma endregion

#pragma region Mutators
public:
	inline GameObject* GetShaman() { return characters[0]; }
	inline GameObject* GetWarrior() { return characters[1]; }
private:
#pragma endregion

#pragma region Functions
public:
	GameObject * BuildWarrior(int teamNumber);
	GameObject * BuildShaman();
private:
#pragma endregion
};
