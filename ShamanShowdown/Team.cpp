#include "Team.h"
#include "Controls.h"
#include "GameState.h"
#include "Map.h"
#include "InputComponent.h"
#include "RenderComponent.h"

WPARAM moveChars[16] = { 'T', 'F', 'G', 'H', VK_UP, VK_LEFT, VK_DOWN, VK_RIGHT, 'W', 'A', 'S', 'D', 'I', 'J', 'K', 'L', };

Team::Team()
{
}


Team::~Team()
{
}


GameObject * Team::BuildWarrior(int teamNumber)
{
	GameObject * object = new GameObject();
	characters[1] = object;

	int teamOffset = teamNumber * 8;
	int typeOffset = 0;
	characters[1]->attachComponent(new InputComponent(moveChars[teamOffset + typeOffset + 0], moveChars[teamOffset + typeOffset + 1], moveChars[teamOffset + typeOffset + 2], moveChars[teamOffset + typeOffset + 3]));
	characters[1]->attachComponent(new RenderComponent(0));

	return object;
}

GameObject * Team::BuildShaman(int teamNumber)
{
	GameObject * object = new GameObject();
	characters[0] = object;

	int teamOffset = teamNumber * 8;
	int typeOffset = 4;
	characters[0]->attachComponent(new InputComponent(moveChars[teamOffset + typeOffset + 0], moveChars[teamOffset + typeOffset + 1], moveChars[teamOffset + typeOffset + 2], moveChars[teamOffset + typeOffset + 3]));
	characters[0]->attachComponent(new RenderComponent(0));

	return object;
}