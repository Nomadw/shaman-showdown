#include "GameState.h"
#include "TransformComponent.h"

GameState::GameState()
{
	Initialize();
}


GameState::~GameState()
{
}

Team GameState::getTeam(int index)
{
	return teams[index % 2];
}

void GameState::Initialize()
{
	teams.emplace_back();
	gameObjects.push_back(teams[0].BuildShaman(0));
	gameObjects.push_back(teams[0].BuildWarrior(0));
	teams.emplace_back();
	gameObjects.push_back(teams[1].BuildShaman(1));
	gameObjects.push_back(teams[1].BuildWarrior(1));
}


void GameState::update(float deltaTime, Controls* controls)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->update(this, deltaTime, controls);
	}
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->requestedRemoval)
		{
			for (int t = 0; t < 2; t++)
			{
				for (int c = 0; c < 2; c++)
				{
					if (teams[t].characters[c] == gameObjects[i])
					{
						teams[t].characters[c] = NULL;
						teams[t].respawnDelay = 5.0f;
					}
				}
			}
			gameObjects.erase(gameObjects.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		teams[i].respawnDelay -= deltaTime;
		if (teams[i].respawnDelay <= 0 && teams[i].GetWarrior() == NULL)
		{
			GameObject * wario = teams[i].BuildWarrior(i);
			addGameObject(wario);
			wario->transform->Translation().setX((rand() % 2) == 0 ? 18 : 2);
			wario->transform->Translation().setY((rand() % 2) == 0 ? 2 : 9);
		}
	}
}

void GameState::render(Renderer* renderer)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->render(renderer);
	}
}

void GameState::addGameObject(GameObject* object)
{
	gameObjects.push_back(object);
}

vector<GameObject*> GameState::getGameObjects()
{
	return gameObjects;
}