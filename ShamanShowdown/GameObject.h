#pragma once
//STL Includes
#include <vector>

//Custom Includes
#include "GameComponent.h"

using namespace std;

class GameState;
class Controls;

class GameObject
{
#pragma region Variables
public:
	vector<GameComponent*> gameComponents;
private:

#pragma endregion

#pragma region Constructors/Destuctors
public:
	GameObject();
	~GameObject();
#pragma endregion

#pragma region Mutators
public:

private:
#pragma endregion

#pragma region Functions
public:
	void attachComponent(GameComponent* gameComponent);

	void update(GameState * state, float deltaTime, Controls* controls);

	template<typename T> GameComponent& getComponent()
	{
		int i = 0;
		for each(GameComponent* comp in gameComponents)
		{
			if (dynamic_cast<T*>(comp) != NULL)
			{
				return *comp;
			}
			i++;
		}
		return (*reinterpret_cast<GameComponent*>(NULL));
	}

private:
#pragma endregion

private:
};

