#include "Team.h"
#include "Controls.h"
#include "GameState.h"
#include "MapComponent.h"
#include "InputComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "MeleeComponent.h"
#include "TeamMemberComponent.h"
#include "HealthComponent.h"

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
	characters[1]->attachComponent(new InputComponent(moveChars[teamOffset + typeOffset + 0], moveChars[teamOffset + typeOffset + 1], moveChars[teamOffset + typeOffset + 2], moveChars[teamOffset + typeOffset + 3], 1.0f));
	characters[1]->attachComponent(new RenderComponent(teamNumber == 0 ? 18 : 19));
	characters[1]->attachComponent(new MeleeComponent());
	characters[1]->attachComponent(new TeamMemberComponent(teamNumber));
	characters[1]->attachComponent(new HealthComponent());
	characters[1]->transform->Translation() = Vector3(teamNumber == 0 ? 18 : 2, 2);

	return object;
}

GameObject * Team::BuildShaman(int teamNumber)
{
	GameObject * object = new GameObject();
	characters[0] = object;

	int teamOffset = teamNumber * 8;
	int typeOffset = 4;
	characters[0]->attachComponent(new InputComponent(moveChars[teamOffset + typeOffset + 0], moveChars[teamOffset + typeOffset + 1], moveChars[teamOffset + typeOffset + 2], moveChars[teamOffset + typeOffset + 3], 2.0f));
	characters[0]->attachComponent(new TeamMemberComponent(teamNumber));
	characters[0]->attachComponent(new HealthComponent());
	characters[0]->attachComponent(new RenderComponent(teamNumber == 0 ? 18 : 19));
	characters[0]->transform->Translation() = Vector3(teamNumber == 0 ? 18 : 2, 9);

	return object;
}