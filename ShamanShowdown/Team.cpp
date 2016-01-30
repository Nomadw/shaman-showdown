#include "Team.h"
#include "Controls.h"
#include "GameState.h"
#include "Map.h"
#include "InputComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"

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
	characters[1]->attachComponent(new RenderComponent(teamNumber == 1 ? 19 : 18));
	characters[1]->transform->Translation() = Vector3(teamNumber == 1 ? 2 : 18, 2);

	return object;
}

GameObject * Team::BuildShaman(int teamNumber)
{
	GameObject * object = new GameObject();
	characters[0] = object;

	int teamOffset = teamNumber * 8;
	int typeOffset = 4;
	characters[0]->attachComponent(new InputComponent(moveChars[teamOffset + typeOffset + 0], moveChars[teamOffset + typeOffset + 1], moveChars[teamOffset + typeOffset + 2], moveChars[teamOffset + typeOffset + 3]));

	characters[0]->attachComponent(new RenderComponent(teamNumber == 0 ? 19 : 18));
	characters[0]->transform->Translation() = Vector3(teamNumber == 0 ? 2 : 18, 9);

	return object;
}