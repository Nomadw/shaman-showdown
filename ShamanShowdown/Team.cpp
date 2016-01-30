#include "Team.h"
#include "Controls.h"
#include "GameState.h"
#include "Map.h"
#include "InputComponent.h"
#include "RenderComponent.h"

WPARAM chars[8] = { 'W', 'A', 'S', 'D', VK_UP, VK_LEFT, VK_DOWN, VK_RIGHT };

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
	characters[1]->attachComponent(new InputComponent(chars[teamNumber * 4 + 0], chars[teamNumber * 4 + 1], chars[teamNumber * 4 + 2], chars[teamNumber * 4 + 3]));
	characters[1]->attachComponent(new RenderComponent(0));

	return object;
}

GameObject * Team::BuildShaman()
{
	GameObject * object = new GameObject();
	characters[0] = object;
	return object;
}