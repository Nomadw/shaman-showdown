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
	teams.emplace_back();
}


void GameState::update(float deltaTime, Controls* controls)
{
	for (int i = 0; i < 2; i++)
	{
		teams[i].update(this, deltaTime, controls);
	}
}

void GameState::render(Renderer* renderer)
{
	for (int i = 0; i < 2; i++)
	{

	}
}