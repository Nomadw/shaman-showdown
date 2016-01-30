#include "Team.h"
#include "Controls.h"
#include "GameState.h"
#include "Map.h"
#include "InputComponent.h"
#include "RenderComponent.h"

Team::Team()
{
}


Team::~Team()
{
}


GameObject * Team::BuildWarrior()
{
	GameObject * object = new GameObject();
	characters[1] = object;
	characters[1]->attachComponent(new InputComponent());
	characters[1]->attachComponent(new RenderComponent(0));

	return object;
}

GameObject * Team::BuildShaman()
{
	GameObject * object = new GameObject();
	characters[0] = object;
	Map * map = new Map();
	map->loadMap("fuck");
	object->attachComponent(map);
	return object;
}