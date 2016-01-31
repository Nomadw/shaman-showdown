#include "ItemSpawner.h"
#include "GameObject.h"
#include "ItemSpawner.h"
#include "ItemComponent.h"
#include "GameState.h"
#include "TransformComponent.h"

ItemSpawner::ItemSpawner(float delayIn)
{
	delay = delayIn;
	timeOut = delayIn;
}

ItemSpawner::~ItemSpawner()
{
}

void ItemSpawner::render(Renderer * renderer)
{
}

void ItemSpawner::update(GameState * state, float deltaTime, Controls * controls, GameObject * object)
{
	int rnd = rand() % 3;
	int clr;
	Items itemType;

	switch (rnd)
	{
	case 0:
		itemType = MISSLE;
		clr = 21;
		break;
	case 1:
		itemType = SUPER_SPEED;
		clr = 57;
		break;
	case 2:
		itemType = SLOW_DOWN;
		clr = 58;
		break;
	}

	if (timeOut < 0)  
	{
		timeOut = delay;
		GameObject * item = new GameObject();
		item->attachComponent(new ItemComponent(clr, itemType));
		state->addGameObject(item);
		item->transform->Translation().setX((rand() % 27) + 2);
		item->transform->Translation().setY((rand() % 14) + 2);
	}
	timeOut -= deltaTime;
}
