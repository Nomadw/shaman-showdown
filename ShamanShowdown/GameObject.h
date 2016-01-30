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

