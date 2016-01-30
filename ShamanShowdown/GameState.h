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
private:
#pragma endregion

#pragma region Functions
public:
	void update(float deltaTime, Controls* controls);
	void render(Renderer* renderer);
private:
#pragma endregion
	void Initialize();
private:
};
