#pragma once
//STL Includes
#include <list>

//Custom Includes
#include "GameComponent.h"

using namespace std;

class GameObject
{
#pragma region Variables
public:
	std::list<GameComponent*> gameComponents;
private:

#pragma endregion

#pragma region Constructors/Destuctors
	GameObject();
	~GameObject();
#pragma endregion

#pragma region Mutators
public:

private:
#pragma endregion

#pragma region Functions
public:

private:
#pragma endregion

private:
};

