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
	gameObjects.push_back(teams[0].BuildShaman());
	gameObjects.push_back(teams[0].BuildWarrior());
	teams.emplace_back();
	gameObjects.push_back(teams[1].BuildShaman());
	gameObjects.push_back(teams[1].BuildWarrior());
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