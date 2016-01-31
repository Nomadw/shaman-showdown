#pragma once
//STL Includes
#include <vector>

//Custom Includes
#include "Team.h"
#include "Controls.h"
class Renderer;

using namespace std;
class GameState
{
#pragma region Variables
public:


private:
	vector<Team> teams;
	vector<GameObject*> gameObjects;
#pragma endregion

#pragma region Constructors/Destuctors
public:
	GameState();
	~GameState();
#pragma endregion

#pragma region Mutators
public:
	Team getTeam(int index);
	vector<GameObject*> getGameObjects();
private:
#pragma endregion

#pragma region Functions
public:
	void update(float deltaTime, Controls* controls);
	void render(Renderer* renderer);
	void addGameObject(GameObject* object);
	template<typename T> GameComponent* FindComponentInObject()
	{
		for each(GameObject* obj in gameObjects)
		{
			GameComponent* comp = obj->getComponent<T>();
			if (comp != NULL)
			{
				return comp;
			}
		}
		return (reinterpret_cast<GameComponent*>(NULL));
	}

private:
#pragma endregion
	void Initialize();
private:
};
