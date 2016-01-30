#pragma once
//STL Includes
#include <vector>

//Custom Includes
#include "Team.h"
using namespace std;
class GameState
{
#pragma region Variables
public:
private:
	vector<Team> teams;
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
	void update(float deltaTime);
	void render();
private:
#pragma endregion
	void Initialize();
private:
};
