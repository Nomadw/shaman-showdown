#include "GameState.h"

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